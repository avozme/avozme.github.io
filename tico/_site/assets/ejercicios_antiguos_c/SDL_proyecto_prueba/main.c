#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL.h>

#define MAX_DISPAROS 100
#define NUM_ESTRELLAS 50
#define MAX_ENEMIGOS 200

#define INACTIVO 0      // Estados de los objetos (disparos, enemigos, etc)
#define ACTIVO 1
#define ESPERANDO 2
#define MUERTO 3
#define EXPLOTANDO 4

struct s_posicion
{
    int x, y;
    float fx, fy;
    int estado;
    int tiempo;
    float movimiento;
};

void iniciar_SDL();
void finalizar_SDL();
void inicializar_variables(struct s_posicion disparos[MAX_DISPAROS], struct s_posicion estrellas[NUM_ESTRELLAS], struct s_posicion enemigos[MAX_ENEMIGOS], struct s_posicion *posic_jugador);
void dibujar_fondo(void);
int mover_jugador(struct s_posicion *jugador, struct s_posicion disparos[MAX_DISPAROS]);
void mover_disparos(struct s_posicion disparos[MAX_DISPAROS], struct s_posicion enemigos[MAX_ENEMIGOS]);
void activar_disparo(struct s_posicion disparos[MAX_DISPAROS], int x, int y);
void mover_estrellas(struct s_posicion estrellas[NUM_ESTRELLAS]);
void mover_enemigos(struct s_posicion enemigos[MAX_ENEMIGOS], int tiempo);


SDL_Surface *pantalla;
SDL_Surface *fondo;
SDL_Surface *sprite;
SDL_Surface *laser;
SDL_Surface *estrella1, *estrella2;
SDL_Surface *enemigo1;
SDL_Surface *expl1, *expl2, *expl3;

Mix_Chunk *snd_disparo = NULL;
Mix_Chunk *snd_expl = NULL;


int main(int argc, char *argv[])
{
   struct s_posicion posic_jugador = (struct s_posicion) { 100, 100 };
   struct s_posicion disparos[MAX_DISPAROS];
   struct s_posicion estrellas[NUM_ESTRELLAS];
   struct s_posicion enemigos[MAX_ENEMIGOS];
   
   iniciar_SDL();
   inicializar_variables(disparos, estrellas, enemigos, &posic_jugador);
   
   int salir = 0, tiempo = 0;
   while (salir == 0)
   {
      tiempo++;
      dibujar_fondo();
      mover_estrellas(estrellas);
      mover_enemigos(enemigos,tiempo);
      salir = mover_jugador(&posic_jugador, disparos);
      mover_disparos(disparos, enemigos);
      SDL_Flip(pantalla);   // Refresca memoria de v�deo
   }
   finalizar_SDL();
   return 0;
}


void iniciar_SDL()
{
  // Inicializa el modo gr�fico
  if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) == -1) {
    puts("Error en la inicializaci�n del sistema de v�deo y/o audio\n");
    SDL_Quit();
  }
  pantalla = SDL_SetVideoMode(800, 600, 16, SDL_ANYFORMAT|SDL_DOUBLEBUF);
  if (pantalla == NULL) {
      puts("Fallo al establecer el modo de v�deo\n");
      SDL_Quit();
      exit(-1);
  }
  
  // Establece atributos del rat�n y del teclado
  SDL_ShowCursor(SDL_DISABLE);  // Oculta el rat�n
  SDL_EnableKeyRepeat(1, 1);    // Activa repetici�n de teclas
  // Carga las im�genes
  fondo = SDL_LoadBMP("fondo.bmp");
  if (fondo == NULL) 
  {
     printf("Error al cargar el archivo fondo.bmp");
     SDL_Quit();
     exit(-1);
  }
  
  sprite = SDL_LoadBMP("sprite.bmp");
  if (sprite == NULL) 
  {
     printf("Error al cargar el archivo sprite.bmp");
     SDL_Quit();
     exit(-1);
  }
  
  laser = SDL_LoadBMP("laser.bmp");
  if (sprite == NULL) 
  {
     printf("Error al cargar el archivo laser.bmp");
     SDL_Quit();
     exit(-1);
  }

  estrella1 = SDL_LoadBMP("estrella1.bmp");
  if (estrella1 == NULL) 
  {
     printf("Error al cargar el archivo estrella1.bmp");
     SDL_Quit();
     exit(-1);
  }

  estrella2 = SDL_LoadBMP("estrella2.bmp");
  if (estrella2 == NULL) 
  {
     printf("Error al cargar el archivo estrella2.bmp");
     SDL_Quit();
     exit(-1);
  }

  enemigo1 = SDL_LoadBMP("enemigo1.bmp");
  if (enemigo1 == NULL) 
  {
     printf("Error al cargar el archivo enemigo1.bmp");
     SDL_Quit();
     exit(-1);
  }

  expl1 = SDL_LoadBMP("expl1.bmp");
  expl2 = SDL_LoadBMP("expl2.bmp");
  expl3 = SDL_LoadBMP("expl3.bmp");
  if ((expl1 == NULL) || (expl2 == NULL) || (expl3 == NULL) )
  {
     printf("Error al cargar los archivos de explosiones");
     SDL_Quit();
     exit(-1);
  }

  // Define las transparencias
  Uint32 color;
  color = SDL_MapRGB(sprite->format, 0, 0, 0);
  SDL_SetColorKey(sprite, SDL_SRCCOLORKEY | SDL_RLEACCEL, color);
  color = SDL_MapRGB(laser->format, 0, 0, 0);
  SDL_SetColorKey(laser, SDL_SRCCOLORKEY | SDL_RLEACCEL, color);
  color = SDL_MapRGB(enemigo1->format, 255, 0, 0);
  SDL_SetColorKey(enemigo1, SDL_SRCCOLORKEY | SDL_RLEACCEL, color);
  color = SDL_MapRGB(expl1->format, 255, 255, 255);
  SDL_SetColorKey(expl1, SDL_SRCCOLORKEY | SDL_RLEACCEL, color);
  SDL_SetColorKey(expl2, SDL_SRCCOLORKEY | SDL_RLEACCEL, color);
  SDL_SetColorKey(expl3, SDL_SRCCOLORKEY | SDL_RLEACCEL, color);


  // Inicializamos el mezclador de sonido
  Mix_OpenAudio (22050, MIX_DEFAULT_FORMAT, 2, 1024);
  
  // Cargamos los sonidos
  snd_disparo = Mix_LoadWAV ("disparo.wav");
  snd_expl = Mix_LoadWAV("explosion.wav");
}


void finalizar_SDL()
{
    // Liberamos sonidos
    Mix_FreeChunk(snd_disparo);
    Mix_FreeChunk(snd_expl);
    Mix_CloseAudio();
    
    // Liberamos im�genes
    SDL_FreeSurface(fondo);
    SDL_FreeSurface(sprite);
    SDL_FreeSurface(laser);
    SDL_FreeSurface(estrella1);
    SDL_FreeSurface(estrella2);
    SDL_FreeSurface(enemigo1);
    SDL_FreeSurface(expl1);
    SDL_FreeSurface(expl2);
    SDL_FreeSurface(expl3);

    // Cerramos SDL
    SDL_Quit();
}


void inicializar_variables(struct s_posicion disparos[MAX_DISPAROS], struct s_posicion estrellas[NUM_ESTRELLAS], struct s_posicion enemigos[MAX_ENEMIGOS], struct s_posicion *posic_jugador)
{
    int i;
    
    // Inicializa los disparos
    for (i = 0; i<=1; i++)
    {
        disparos[i].x = 0;
        disparos[i].y = 0;
        disparos[i].estado = INACTIVO;
    }
    
    // Inicializa nave del jugador
    posic_jugador->x = 380;
    posic_jugador->y = 450;
    
    // Inicializa estrellas    
    for (i = 0; i<NUM_ESTRELLAS; i++)
    {
        estrellas[i].fx = rand()%800;
        estrellas[i].fy = rand()%600;
        estrellas[i].movimiento = rand()%2 + 1;
    }
    
    // Inicializa enemigos
    for (i = 0; i<100; i++)  // S�lo ponemos 100 (por ahora)
    {
        enemigos[i].x = rand()%600+100;
        enemigos[i].y = -50;
        enemigos[i].tiempo = rand()%5000;
        if (enemigos[i].tiempo == 0)
            enemigos[i].estado = ACTIVO;
        else
            enemigos[i].estado = ESPERANDO;
    }
    for (i = 10; i<MAX_ENEMIGOS; i++)    // El resto los deshabilitamos
        enemigos[i].estado = INACTIVO;
}


void dibujar_fondo(void)
{
    
    // Repintamos el fondo
    SDL_Rect rect = (SDL_Rect) {0,0, 800, 600};
    SDL_BlitSurface(fondo, NULL, pantalla, &rect);
}


int mover_jugador(struct s_posicion *jugador, struct s_posicion disparos[MAX_DISPAROS])
{
    SDL_Event ev;
    SDL_Rect rect;
    Uint8 *keys;
    int salir = 0;
    
    // Captura los eventos
    SDL_PollEvent(&ev);
    switch(ev.type)
    {
        case SDL_QUIT:  salir = 1;
                        break;
        case SDL_MOUSEMOTION:    // Se ha movido el rat�n
                        jugador->x = ev.motion.x;
                        jugador->y = ev.motion.y;
                        break;
        case SDL_MOUSEBUTTONDOWN: // Se ha hecho clic con el rat�n
                        activar_disparo(disparos, ev.button.x, ev.button.y);
                        break;
        case SDL_KEYDOWN:        // Se ha pulsado una tecla
                        switch (ev.key.keysym.sym)
                        {
                          case SDLK_ESCAPE: salir = 1; break;
/*
                          case SDLK_UP: jugador->y -= 10; break;
                          case SDLK_DOWN: jugador->y += 10; break;
                          case SDLK_RIGHT: jugador->x += 10; break;
                          case SDLK_LEFT: jugador->x -= 10; break;
                          case SDLK_SPACE: activar_disparo(disparos, jugador->x, jugador->y); break;
*/                          
                        }
                        break;
    } // switch

    keys=SDL_GetKeyState(NULL);
    if (keys[SDLK_UP] == 1) {jugador->y -= 10; }
    if (keys[SDLK_DOWN] == 1) {jugador->y += 10;}
    if (keys[SDLK_LEFT] == 1) {jugador->x -= 10;}
    if (keys[SDLK_RIGHT] == 1) {jugador->x += 10;}
    if (keys[SDLK_SPACE] == 1) {activar_disparo(disparos, jugador->x, jugador->y);}                          
    
    // Dibujamos el sprite del jugador
    rect = (SDL_Rect) {jugador->x, jugador->y, 50, 50};
    SDL_BlitSurface(sprite, NULL, pantalla, &rect);

    return salir;
}


void mover_disparos(struct s_posicion disparos[MAX_DISPAROS], struct s_posicion enemigos[MAX_ENEMIGOS])
{
    int i,j;
    SDL_Rect rect;
    
    for (i=0; i<MAX_DISPAROS; i++)
    {
        if (disparos[i].estado == ACTIVO)
        {
            disparos[i].y -= 20;
            if (disparos[i].y < 0)        // Se sale de la pantalla
            {
                   disparos[i].estado = INACTIVO;
            }
            else
            {
                   rect = (SDL_Rect) {disparos[i].x, disparos[i].y, 50, 50};
                   SDL_BlitSurface(laser, NULL, pantalla, &rect);
            }
            for (j=0; j<MAX_ENEMIGOS; j++) {
                 // Comprobar colisi�n
                 if ((abs(disparos[i].x - enemigos[j].x) < 40) && (abs(disparos[i].y - enemigos[j].y) < 60) && (enemigos[j].estado == ACTIVO))
                 {
                     disparos[i].estado = INACTIVO;
                     enemigos[j].estado = EXPLOTANDO;
                     enemigos[j].tiempo = 15;
                     // Lanzamos el sonido de la explosi�n
                     Mix_PlayChannel (-1, snd_expl, 0);
                 }
            }
        }
    }
}          


void activar_disparo(struct s_posicion disparos[MAX_DISPAROS], int x, int y)
{
    int i;
    
    // Buscamos primer slot libre
    for (i=0; i<MAX_DISPAROS; i++)
        if (disparos[i].estado == INACTIVO) break;
    
    // Activamos el disparo
    if (i<MAX_DISPAROS-1)
    {
        disparos[i].x = x+23;
        disparos[i].y = y-20;
        disparos[i].estado = ACTIVO;
    }
    
    // Producimos el sonido del disparo
    Mix_PlayChannel (-1, snd_disparo, 0);
}



void mover_estrellas(struct s_posicion estrellas[NUM_ESTRELLAS])
{
    int i;
    SDL_Rect rect;
    
    for (i=0; i<NUM_ESTRELLAS; i++)
    {
        estrellas[i].fy += estrellas[i].movimiento;
        if (estrellas[i].fy > 600) {
                estrellas[i].fy = 0;
                estrellas[i].movimiento = (rand()%18 + 2) / (float)10;
        }
        
        rect = (SDL_Rect) {(int)estrellas[i].fx, (int)estrellas[i].fy, 10, 10};
        if (estrellas[i].movimiento > 1.5)
            SDL_BlitSurface(estrella1, NULL, pantalla, &rect);
        else
            SDL_BlitSurface(estrella2, NULL, pantalla, &rect);
    }
   
}

void mover_enemigos(struct s_posicion enemigos[MAX_ENEMIGOS], int tiempo)
{
    int i;
    SDL_Rect rect;
    
    for (i=0; i<MAX_ENEMIGOS; i++)
    {
        // Enemigo en espera: comprobar si le toca ya salir a escena (activaci�n)
        if ((enemigos[i].estado == ESPERANDO) && (enemigos[i].tiempo < tiempo))
            enemigos[i].estado = ACTIVO;
            
        // Enemigo en movimiento    
        if (enemigos[i].estado == ACTIVO)
        {
            enemigos[i].x += rand() % 5 - 2;
            enemigos[i].y += 1;
            if (enemigos[i].y > 600) 
                enemigos[i].estado = INACTIVO;
        
            rect = (SDL_Rect) {enemigos[i].x, enemigos[i].y, 10, 10};
            SDL_BlitSurface(enemigo1, NULL, pantalla, &rect);
        }
        
        // Enemigo en plena explosi�n
        if (enemigos[i].estado == EXPLOTANDO)
        {
            enemigos[i].x += rand() % 5 - 2;
            enemigos[i].y += 1;
            rect = (SDL_Rect) {enemigos[i].x, enemigos[i].y, 10, 10};
            enemigos[i].tiempo--;
            if (enemigos[i].tiempo > 9)
                SDL_BlitSurface(expl1, NULL, pantalla, &rect);
            else if (enemigos[i].tiempo > 5)
                SDL_BlitSurface(expl2, NULL, pantalla, &rect);
            else if (enemigos[i].tiempo > 0)
                SDL_BlitSurface(expl3, NULL, pantalla, &rect);
            else enemigos[i].estado = MUERTO;
        }
    }
}
