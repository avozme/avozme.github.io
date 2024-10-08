/*
PROGRAMA:  Ajedrez 1.0
ARCHIVO:   io_txt.c
CONTENIDO: Funciones de entrada/salida
           Modos soportados:  - TXT_DOS: modo texto MS-DOS (usa librer�as DOS y CONIO)
	                      - TXT_LINUX: modo texto Linux (usa librer�a Ncurses)
                              - GRAF_LINUX: modo gr�fico Linux (usa librer�a SDL)
           En todas las funciones se encontrar� c�digo separado para cada uno de los modos soportados
	   mediante las directivas #ifdef ... #endif.
	   La constante que determina el modo actual del juego se declara en tipos.h
AUTOR:     Alfredo Moreno
*/

#include "io.h"


// ---------------------------------------------------------------------------------------
// Funci�n: inicializar_interfaz()
// Inicializa el interfaz. Invocar antes que cualquier otra funci�n de i/o
// ---------------------------------------------------------------------------------------
int inicializar_interfaz()
{
// --------------------------------------
// MODO TEXTO MS-DOS
// --------------------------------------
#ifdef TXT_DOS		// Modo de texto de MS-DOS
  textcolor(WHITE);	// Restaurar colores por defecto
  textbackground(BLUE);
  clrscr();		// Borrar pantalla
#endif

// --------------------------------------
// MODO TEXTO LINUX
// --------------------------------------
#ifdef TXT_LINUX		// Modo de texto en LINUX
  initscr();			// Inicializar Ncurses
  signal(SIGINT, finalizar_interfaz);	// Si hay CTRL-C o similar, se llama a finalizar_interfaz()
  keypad(stdscr, 1);		// Activamos recepci�n de teclas especiales
  if (has_colors()) start_color();
  init_pair(C_NEG_NEG, COLOR_BLACK, COLOR_BLACK);
  init_pair(C_NEG_BLA, COLOR_BLACK, COLOR_WHITE);
  init_pair(C_BLA_NEG, COLOR_WHITE, COLOR_BLACK);
  init_pair(C_BLA_BLA, COLOR_WHITE, COLOR_WHITE);
  init_pair(C_TXT, COLOR_YELLOW, COLOR_BLUE);
  init_pair(C_SEL, COLOR_WHITE, COLOR_RED);
  bkgd(COLOR_PAIR(C_TXT));	// Establecemos color de fondo
  attron(A_BOLD);		// Activa negrita para que los caracteres se lean mejor
  refresh();			// Limpia la pantalla
#endif

// --------------------------------------
// MODO GR�FICO MS-DOS
// --------------------------------------
#ifdef GRAF_LINUX
  if (SDL_Init(SDL_INIT_VIDEO) == -1) {
    puts("Error en la inicializaci�n del sistema de v�deo\n");
    SDL_Quit();
    exit(-1);
  }
  // Creamos la pantalla con doble buffer, para dibujar en el doble buffer y luego mandarlo a la memoria de v�deo
  scr = SDL_SetVideoMode(TAM_PANT_X,TAM_PANT_Y,16,SDL_ANYFORMAT | SDL_DOUBLEBUF);
  if (!scr) {
    puts("Fallo al establecer el modo de v�deo\n");
    SDL_Quit();
    exit(-1);
  }
  // Cargamos las im�genes del juego
  cargar_imagenes();
#endif

}

// ---------------------------------------------------------------------------------------
// Funci�n: finalizar_interfaz()
// Finaliza el interfaz. Invocar antes de terminar el programa.
// ---------------------------------------------------------------------------------------
void finalizar_interfaz()
{
#ifdef TXT_DOS
  exit(0);
#endif

#ifdef TXT_LINUX
  endwin();	// En LINUX llamamos a la funci�n de librer�a de Ncurses
  exit(0);
#endif

#ifdef GRAF_LINUX
  SDL_FreeSurface(fondo);	// Liberamos todas las superficies que contienen a los sprites del juego
  SDL_FreeSurface(cuadro1); SDL_FreeSurface(cuadro2);
  SDL_FreeSurface(peon_bl); SDL_FreeSurface(peon_ne);
  SDL_FreeSurface(alfil_bl); SDL_FreeSurface(alfil_ne);
  SDL_FreeSurface(torre_bl); SDL_FreeSurface(torre_ne);
  SDL_FreeSurface(caballo_bl); SDL_FreeSurface(caballo_ne);
  SDL_FreeSurface(dama_bl); SDL_FreeSurface(dama_ne);
  SDL_FreeSurface(rey_bl); SDL_FreeSurface(rey_ne);
  SDL_Quit();
  exit(0);
#endif
}


// ---------------------------------------------------------------------------------------
// Funci�n: refrescar_pantalla()
// Dibuja en la pantalla el estado actual del tablero
// ---------------------------------------------------------------------------------------
void refrescar_pantalla(Tcasilla tablero[9][9])
{
  int x,y;

#ifdef GRAF_LINUX
  // Mostramos imagen del tablero
  SDL_Rect rect;
  rect = (SDL_Rect) {0,0,TAM_PANT_X,TAM_PANT_Y};
  SDL_BlitSurface(fondo, NULL, scr, &rect);
#endif

  // Dibujamos todas las casillas con sus piezas
  for (x=1; x<=8; x++)
    for (y=1; y<=8; y++)
    {
        dibujar_casilla(x, y, tablero[x][y].pieza, tablero[x][y].color_pieza, tablero[x][y].color_casilla);
    }
#ifdef TXT_LINUX
  refresh();			// Actualizamos la pantalla
#endif
#ifdef GRAF_LINUX
  SDL_Flip(scr);		// Enviamos el buffer de pantalla a memoria de v�deo para visualizarlo
#endif
}


// ---------------------------------------------------------------------------------------
// Funci�n: dibujar_casilla()
// Dibuja un escaque del tablero con la figura que contiene
// ---------------------------------------------------------------------------------------
void dibujar_casilla(int x, int y, char tipo, char color_pieza, char color_casilla)
{
// --------------------------------------
// MODO TEXTO MS-DOS
// --------------------------------------
#ifdef TXT_DOS
  gotoxy(x*2, y*2);
  if (color_casilla == BLANCO) textbackground(WHITE); else textbackground(BLACK);
  if (color_pieza == BLANCO) textcolor(WHITE); else textcolor(WHITE);

  switch (tipo)
  {
    case PEON: cprintf("P"); break;
    case CABALLO: cprintf("C"); break;
    case ALFIL: cprintf("A"); break;
    case DAMA: cprintf("D"); break;
    case REY: cprintf("R"); break;
    case TORRE: cprintf("T"); break;
    default: cprintf(" ");		// No hay figura en la casilla
  }
#endif

// --------------------------------------
// MODO TEXTO LINUX
// --------------------------------------
#ifdef TXT_LINUX
  // Establecemos los colores
  if ((color_pieza == BLANCO) && (color_casilla == BLANCO)) attron(COLOR_PAIR(C_BLA_BLA));
  if ((color_pieza == NEGRO)  && (color_casilla == BLANCO)) attron(COLOR_PAIR(C_NEG_BLA));
  if ((color_pieza == BLANCO) && (color_casilla == NEGRO)) attron(COLOR_PAIR(C_BLA_NEG));
  if ((color_pieza == NEGRO)  && (color_casilla == NEGRO)) attron(COLOR_PAIR(C_NEG_NEG));
  if ((color_pieza == NINGUNO) && (color_casilla == BLANCO)) attron(COLOR_PAIR(C_NEG_BLA));
  if ((color_pieza == NINGUNO) && (color_casilla == NEGRO)) attron(COLOR_PAIR(C_NEG_NEG));

  // Dibujamos el escaque
  int i, j;
  y = 9-y;	// Le damos la vuelta a la fila porque en la pantalla est�n al rev�s (la 1 abajo)
  for (j = y*3 - 1; j <= y*3 + 1; j++)
    for (i = x*5 - 2; i <= x*5 + 2; i++)
    {
      move(j, i); printw(" ");
    }

  // Dibujamos la pieza
  move(y*3, x*5);
  switch (tipo)
  {
    case PEON: printw("P"); break;
    case CABALLO: printw("C"); break;
    case ALFIL: printw("A"); break;
    case DAMA: printw("D"); break;
    case REY: printw("R"); break;
    case TORRE: printw("T"); break;
    default: printw(" ");		// No hay figura en la casilla
  }
#endif

// --------------------------------------
// MODO GR�FICO LINUX
// --------------------------------------
#ifdef GRAF_LINUX
  SDL_Rect rect;
  int px, py;

  // No hay que pintar la casilla (ya viene dibujada en la imagen de fondo), s�lo la pieza.

  y = 9-y;	// Le damos la vuelta a la y porque en la pantalla las filas est�n al rev�s (fila 1 abajo)
  // Generamos el rect�ngulo adecuado para enviar el sprite a esa posici�n de la pantalla
  px =((x-1)*TAM_CASILLA) + DESPLZ_ORIG_X;
  py = ((y-1)*TAM_CASILLA) + DESPLZ_ORIG_Y;
  rect = (SDL_Rect) { px, py, TAM_CASILLA, TAM_CASILLA };

  // Seleccionamos el sprite adecuado seg�n el tipo y el color de la pieza
  switch (tipo)
  {
     case PEON:   if (color_pieza == BLANCO) SDL_BlitSurface(peon_bl, NULL, scr, &rect);
                  else SDL_BlitSurface(peon_ne, NULL, scr, &rect);
		  break;
     case TORRE:  if (color_pieza == BLANCO) SDL_BlitSurface(torre_bl, NULL, scr, &rect);
                  else SDL_BlitSurface(torre_ne, NULL, scr, &rect);
		  break;
     case ALFIL:  if (color_pieza == BLANCO) SDL_BlitSurface(alfil_bl, NULL, scr, &rect);
                  else SDL_BlitSurface(alfil_ne, NULL, scr, &rect);
		  break;
     case CABALLO:if (color_pieza == BLANCO) SDL_BlitSurface(caballo_bl, NULL, scr, &rect);
                  else SDL_BlitSurface(caballo_ne, NULL, scr, &rect);
		  break;
     case DAMA:   if (color_pieza == BLANCO) SDL_BlitSurface(dama_bl, NULL, scr, &rect);
                  else SDL_BlitSurface(dama_ne, NULL, scr, &rect);
		  break;
     case REY:    if (color_pieza == BLANCO) SDL_BlitSurface(rey_bl, NULL, scr, &rect);
                  else SDL_BlitSurface(rey_ne, NULL, scr, &rect);
		  break;
  }

#endif

}


// ---------------------------------------------------------------------------------------
// Funci�n: seleccionar_casilla()
// Permite seleccionar una casilla del tablero usando las teclas del cursor. Devuelve
// las coordenadas de la casilla seleccionada en (col,fila). Ser�n (0,0) si se pulsa ESC
// (x_orig, y_orig) son corrdenadas de origen, si es que ya se eligieron. Si no, ser�n (0,0)
// ---------------------------------------------------------------------------------------
void seleccionar_casilla(int* col, int* fila, int x_orig, int y_orig, Tcasilla tablero[9][9])
{

// --------------------------------------
// MODO TEXTO DOS
// --------------------------------------
#ifdef TXT_DOS
  int x,y;
  puts("Introduzca FILA (1-8) ");
  do { scanf("%i", &y); } while ((y < 1) || (y > 8));
  puts("Introduzca COLUMNA (1-8 ");
  do { scanf("%i", &x); } while ((x < 1) || (x > 8));
#endif

// --------------------------------------
// MODO TEXTO LINUX
// --------------------------------------
#ifdef TXT_LINUX
  int x, y;		// Coordenadas de la casilla seleccionada
  int ax= 1, ay= 1;	// Coordenadas de la anterior casilla seleccionada
  int terminar = 0;
  int i, j, tecla;

  // Si ya se eligi� casilla de origen, empezamos la selecci�n del destino en esas coordenadas
  if (x_orig > 0) { y_orig = 9-y_orig; x = x_orig; y = y_orig; }
  else {x = 1; y = 1; }

  cbreak();		// Para leer las teclas pulsadas inmediatamente
  noecho();		// Desactivar eco
  do
  {
    // Borrar contorno de la casilla anterior
    dibujar_casilla(ax, 9-ay, tablero[ax][9-ay].pieza, tablero[ax][9-ay].color_pieza, tablero[ax][9-ay].color_casilla);
    attron(COLOR_PAIR(C_SEL));

    // Si ya se eligi� casilla de origen (y ahora estamos eligiendo el destino), primero mostramos el
    // recuadro de casilla de origen
    if (x_orig > 0) {
      for (i = x_orig * 5 - 2; i <= x_orig * 5 + 2; i++)
      {
        move(y_orig*3-1, i); printw(" ");
        move(y_orig*3+1, i); printw(" ");
      }
      move (y_orig*3, x_orig*5-2); printw(" ");
      move (y_orig*3, x_orig*5+2); printw(" ");
    }

    // Ahora dibujamos el contorno de la casilla actual
    for (i = x * 5 - 2; i <= x * 5 + 2; i++)
    {
      move(y*3-1, i); printw(" ");
      move(y*3+1, i); printw(" ");
    }
    move (y*3, x*5-2); printw(" ");
    move (y*3, x*5+2); printw(" ");
    refresh();

    // Leer teclado
    tecla = getch();
    switch (tecla)
    {
       case KEY_UP:   if (y > 1) { ay = y; ax = x; y--; } break;
       case KEY_DOWN: if (y < 8) { ay = y; ax = x; y++; } break;
       case KEY_LEFT: if (x > 1) { ax = x; ay = y; x--; } break;
       case KEY_RIGHT:if (x < 8) { ax = x; ay = y; x++; } break;
       case 27:terminar = -1; break;		// ESC (abortar)
       case 32:terminar = 1; break;		// Espacio (aceptar)
    }
  }
  while (terminar == 0);
  echo();		// Volver a activar el eco
  nocbreak();		// Volver a activar el env�o habitual de teclas

  // Guardar el resultado de la selecci�n en los par�metros pasados por referencia
  if (terminar == 1)	// Se puls� Intro = aceptar selecci�n
  {
    *col = x;
    *fila = 9-y;	// Recuerda: en la pantala las filas est�n al rev�s (abajo el 1)
  }
  else			// Se puls� Esc = cancelar selecci�n
  {
    *col = 0;
    *fila = 0;
  }
#endif

// --------------------------------------
// MODO GRAFICO LINUX
// --------------------------------------
#ifdef GRAF_LINUX
  int x, y;		// Coordenadas de la casilla seleccionada
  int px, py;		// Coordenadas de la casilla en la pantalla (coordenadas gr�ficas)
  int ax= 1, ay= 1;	// Coordenadas de la anterior casilla seleccionada
  int terminar = 0;
  int tecla;
  SDL_Event evento;	// Para leer el teclado
  SDL_Rect rect;

  // Si ya se eligi� casilla de origen, empezamos la selecci�n del destino en esas coordenadas
  if (x_orig > 0) { y_orig = 9-y_orig; x = x_orig; y = y_orig; }
  else {x = 1; y = 1; }

  do
  {
    // Borramos el recuadro de su posici�n anterior redibujando toda la pantalla
    refrescar_pantalla(tablero);

    // Si ya se ha seleccionado casilla de origen del movimiento, le dibujamos un recuadro de tipo "cuadro1"
    if (x_orig > 0) {
       px = ((x_orig-1)*TAM_CASILLA) + DESPLZ_ORIG_X;
       py = ((y_orig-1)*TAM_CASILLA) + DESPLZ_ORIG_Y;
       rect = (SDL_Rect) { px, py, TAM_CASILLA, TAM_CASILLA };
       SDL_BlitSurface(cuadro1, NULL, scr, &rect);	// El sprite "cuadro1.bmp" es para marcar la casilla origen
    }

    // Mostramos el recuadro de selecci�n actual. Las coordenadas son (x,y)
    px = ((x-1)*TAM_CASILLA) + DESPLZ_ORIG_X;
    py = ((y-1)*TAM_CASILLA) + DESPLZ_ORIG_Y;
    rect = (SDL_Rect) { px, py, TAM_CASILLA, TAM_CASILLA };
    if (x_orig==0)	// Usamos un sprite distinto seg�n se est� eligiendo casilla origen o destino
       SDL_BlitSurface(cuadro1, NULL, scr, &rect);	// Sprite "cuadro1.bmp" (para seleccionar origen)
    else
       SDL_BlitSurface(cuadro2, NULL, scr, &rect);	// Sprite "cuadro2.bmp (para seleccionar destino)

    // Enviamos la imagen del recuadro a la memoria de v�deo para que se vea
    SDL_Flip(scr);

    // Leer teclado --> esperar evento
    SDL_WaitEvent(&evento);
    if (evento.type == SDL_KEYDOWN)			// Se ha pulsado una tecla
    {
       switch (evento.key.keysym.sym)			// Vamos a mirar qu� tecla es
       {
         case SDLK_UP:   if (y > 1) { ay = y; ax = x; y--; } break;	// Flecha arriba
         case SDLK_DOWN: if (y < 8) { ay = y; ax = x; y++; } break;	// Flecha abajo
         case SDLK_LEFT: if (x > 1) { ax = x; ay = y; x--; } break;	// Felcha izquierda
         case SDLK_RIGHT:if (x < 8) { ax = x; ay = y; x++; } break;	// Flecha derecha
         case SDLK_ESCAPE: terminar = -1; break;			// ESC (abortar)
         case SDLK_q:      finalizar_interfaz(); exit(0);		// XXX QUITAR ESTO !!!!
         case SDLK_RETURN: terminar = 1; break;				// Intro (aceptar)
       }
    }
  }
  while (terminar == 0);

  // Guardar el resultado de la selecci�n en los par�metros pasados por referencia
  if (terminar == 1)	// Se puls� Intro = aceptar selecci�n
  {
    *col = x;
    *fila = 9-y;	// Recuerda: en la pantala las filas est�n al rev�s (abajo el 1)
  }
  else			// Se puls� Esc = cancelar selecci�n
  {
    *col = 0;
    *fila = 0;
  }
#endif

}

// ---------------------------------------------------------------------------------------
// Funci�n: escribir()
// Escribe una cadena en el lugar de la pantalla destinado a mensajes al usuario
// ---------------------------------------------------------------------------------------
void escribir(char* texto, int fila)
{
#ifdef TXT_DOS
  textbackground(BLUE);
  textcolor(WHITE);
  gotoxy(1,19+fila);
  cprintf(texto);
#endif

#ifdef TXT_LINUX
  attron(COLOR_PAIR(C_TXT));
  move(1+fila,50);
  printw("                                    ");
  move(1+fila,50);
  printw(texto);
  refresh();
#endif

#ifdef GRAF_LINUX
  puts(texto);
#endif
}


// ---------------------------------------------------------------------------------------
// Funci�n: leer()
// Lee una cadena en el lugar de la pantalla destinado a mensajes al usuario
// ---------------------------------------------------------------------------------------
void leer(char* texto, int fila)
{
#ifdef TXT_DOS
  textbackground(BLUE);
  textcolor(WHITE);
  gotoxy(1,20+fila);
  cscanf("%s",texto);
#endif

#ifdef TXT_LINUX
  attron(COLOR_PAIR(C_TXT));
  move(2+fila,50);
  printw("                                    ");
  move(2+fila,50);
  getstr(texto);
#endif

#ifdef GRAF_LINUX
  scanf("%s", texto);
#endif
}


// ---------------------------------------------------------------------------------------
// Funci�n: borrar()
// Limpia una l�nea de la zona de la pantalla dedicada a mensajes al usuario.
// Si fila = 0 limpia toda la zona.
// ---------------------------------------------------------------------------------------
void borrar(int fila)
{
#ifdef TXT_LINUX
   attron(COLOR_PAIR(C_TXT));
   if (fila == 0)
   {
     int y;
     for (y = 1; y<=25; y++)
     {
       move(y, 50);
       printw("                                    ");
     }
   }
   else
   {
     move(fila, 50);
     printw("                                     ");
   }
   refresh();
#endif
}


#ifdef GRAF_LINUX
// ---------------------------------------------------------------------------------------
// Funci�n: cargar_imagenes()
// Carga las im�genes BMP del juego en las diferentes superficies
// ---------------------------------------------------------------------------------------
void cargar_imagenes()
{
  Uint32 color;		// Para definir el color de transparencia (donde proceda)
  
  // Cargamos la imagen de fondo (TABLERO)
  fondo = SDL_LoadBMP("tablero3.bmp");
  if (!fondo) error_imagen("tablero3.bmp");

  // Cargamos la imagen del RECUADRO de selecci�n 1
  cuadro1 = SDL_LoadBMP("cuadro1.bmp");
  if (!cuadro1) error_imagen("cuadro1.bmp");
  color = SDL_MapRGB(cuadro1->format, 0, 0, 0);	// Definimos la transparencia (color negro)
  SDL_SetColorKey(cuadro1, SDL_SRCCOLORKEY | SDL_RLEACCEL, color);

  // Cargamos la imagen del RECUADRO de selecci�n 1
  cuadro2 = SDL_LoadBMP("cuadro2.bmp");
  if (!cuadro2) error_imagen("cuadro2.bmp");
  color = SDL_MapRGB(cuadro2->format, 0, 0, 0);	// Definimos la transparencia (color negro)
  SDL_SetColorKey(cuadro2, SDL_SRCCOLORKEY | SDL_RLEACCEL, color);

  // Cargamos la imagen del PEON BLANCO
  peon_bl = SDL_LoadBMP("peon_bl.bmp");
  if (!peon_bl) error_imagen("peon_bl.bmp");
  color = SDL_MapRGB(peon_bl->format, 0, 0, 0);	// Definimos la transparencia (color negro)
  SDL_SetColorKey(peon_bl, SDL_SRCCOLORKEY | SDL_RLEACCEL, color);

  // Cargamos la imagen del PEON NEGRO
  peon_ne = SDL_LoadBMP("peon_ne.bmp");
  if (!peon_ne) error_imagen("peon_ne.bmp");
  color = SDL_MapRGB(peon_ne->format, 0, 0, 0);	// Definimos la transparencia (color negro)
  SDL_SetColorKey(peon_ne, SDL_SRCCOLORKEY | SDL_RLEACCEL, color);

  // Cargamos la imagen del TORRE BLANCA
  torre_bl = SDL_LoadBMP("torre_bl.bmp");
  if (!torre_bl) error_imagen("torre_bl.bmp");
  color = SDL_MapRGB(torre_bl->format, 0, 0, 0);	// Definimos la transparencia (color negro)
  SDL_SetColorKey(torre_bl, SDL_SRCCOLORKEY | SDL_RLEACCEL, color);

  // Cargamos la imagen del TORRE NEGRA
  torre_ne = SDL_LoadBMP("torre_ne.bmp");
  if (!torre_ne) error_imagen("torre_ne.bmp");
  color = SDL_MapRGB(torre_ne->format, 0, 0, 0);	// Definimos la transparencia (color negro)
  SDL_SetColorKey(torre_ne, SDL_SRCCOLORKEY | SDL_RLEACCEL, color);

  // Cargamos la imagen del CABALLO BLANCO
  caballo_bl = SDL_LoadBMP("caballo_bl.bmp");
  if (!caballo_bl) error_imagen("caballo_bl.bmp");
  color = SDL_MapRGB(caballo_bl->format, 0, 0, 0);	// Definimos la transparencia (color negro)
  SDL_SetColorKey(caballo_bl, SDL_SRCCOLORKEY | SDL_RLEACCEL, color);

  // Cargamos la imagen del CABALLO NEGRO
  caballo_ne = SDL_LoadBMP("caballo_ne.bmp");
  if (!caballo_ne) error_imagen("caballo_ne.bmp");
  color = SDL_MapRGB(caballo_ne->format, 0, 0, 0);	// Definimos la transparencia (color negro)
  SDL_SetColorKey(caballo_ne, SDL_SRCCOLORKEY | SDL_RLEACCEL, color);

  // Cargamos la imagen del ALFIL BLANCO
  alfil_bl = SDL_LoadBMP("alfil_bl.bmp");
  if (!alfil_bl) error_imagen("alfil_bl.bmp");
  color = SDL_MapRGB(alfil_bl->format, 0, 0, 0);	// Definimos la transparencia (color negro)
  SDL_SetColorKey(alfil_bl, SDL_SRCCOLORKEY | SDL_RLEACCEL, color);

  // Cargamos la imagen del ALFIL NEGRO
  alfil_ne = SDL_LoadBMP("alfil_ne.bmp");
  if (!alfil_ne) error_imagen("alfil_ne.bmp");
  color = SDL_MapRGB(alfil_ne->format, 0, 0, 0);	// Definimos la transparencia (color negro)
  SDL_SetColorKey(alfil_ne, SDL_SRCCOLORKEY | SDL_RLEACCEL, color);

  // Cargamos la imagen de la DAMA BLANCA
  dama_bl = SDL_LoadBMP("dama_bl.bmp");
  if (!dama_bl) error_imagen("dama_bl.bmp");
  color = SDL_MapRGB(dama_bl->format, 0, 0, 0);	// Definimos la transparencia (color negro)
  SDL_SetColorKey(dama_bl, SDL_SRCCOLORKEY | SDL_RLEACCEL, color);

  // Cargamos la imagen de la DAMA NEGRA
  dama_ne = SDL_LoadBMP("dama_ne.bmp");
  if (!dama_ne) error_imagen("dama_ne.bmp");
  color = SDL_MapRGB(dama_ne->format, 0, 0, 0);	// Definimos la transparencia (color negro)
  SDL_SetColorKey(dama_ne, SDL_SRCCOLORKEY | SDL_RLEACCEL, color);

  // Cargamos la imagen del REY BLANCO
  rey_bl = SDL_LoadBMP("rey_bl.bmp");
  if (!rey_bl) error_imagen("rey_bl.bmp");
  color = SDL_MapRGB(rey_bl->format, 0, 0, 0);	// Definimos la transparencia (color negro)
  SDL_SetColorKey(rey_bl, SDL_SRCCOLORKEY | SDL_RLEACCEL, color);

  // Cargamos la imagen del REY NEGRO
  rey_ne = SDL_LoadBMP("rey_ne.bmp");
  if (!rey_ne) error_imagen("rey_ne.bmp");
  color = SDL_MapRGB(rey_ne->format, 0, 0, 0);	// Definimos la transparencia (color negro)
  SDL_SetColorKey(rey_ne, SDL_SRCCOLORKEY | SDL_RLEACCEL, color);
}


// ---------------------------------------------------------------------------------------
// Funci�n: error_imagen()
// Gestiona los errores durante la carga de las im�genes
// ---------------------------------------------------------------------------------------
void error_imagen(char* archivo)
{
    printf("Fallo al cargar la imagen %s\n", archivo);
    SDL_Quit();
    exit(-1);
}


#endif

