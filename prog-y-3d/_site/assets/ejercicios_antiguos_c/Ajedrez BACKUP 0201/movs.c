/*
PROGRAMA:  Ajedrez 1.0
ARCHIVO:   movs.c
CONTENIDO: Funciones de movimientos de las piezas
AUTOR:     Alfredo Moreno
*/

#include "movs.h"


// ---------------------------------------------------------------------------------------
// Función: realizar_movimiento()
// Determina a qué jugador le toca mover y realiza el movimiento alterando el tablero
// y el estado del juego (si procede)
// ---------------------------------------------------------------------------------------
void realizar_movimiento(Tcasilla tablero[9][9], Testado* estado, char jug_blanco, char jug_negro)
{
  char txt[100];

  borrar(0);		// Borrar área de mensajes
  if (estado->turno == BLANCAS) sprintf(txt, "\nTurno: BLANCAS\0"); else sprintf(txt, "\nTurno: NEGRAS\0");
  escribir(txt,1);	// Mostramos de quién es el turno

  if (estado->turno == BLANCAS)
  {
    if (jug_blanco == HUMANO)
      movimiento_humano(tablero, estado);
    else
      movimiento_maquina(tablero, estado);
  }
  else	// turno == NEGRAS
  {
    if (jug_negro == HUMANO)
      movimiento_humano(tablero, estado);
    else
      movimiento_maquina(tablero, estado);
  }
}


// ---------------------------------------------------------------------------------------
// Función: movimiento_humano()
// Gestiona el movimiento de una pieza por parte de un jugador humano
// ---------------------------------------------------------------------------------------
void movimiento_humano(Tcasilla tablero[9][9], Testado* estado)
{
  int fila_orig, col_orig, fila_dest, col_dest;
  int result_orig, result_dest;
  int movimiento_realizado;

  movimiento_realizado = FALSO;
  do
  {
     do
       result_orig = elegir_origen(&col_orig, &fila_orig, tablero, estado);
     while (result_orig == -1);
     if (result_orig == 0)
     {
        do
          result_dest = elegir_destino(&col_dest, &fila_dest, col_orig, fila_orig, tablero, estado);
        while  (result_dest == -1);
        if (result_dest == 0) {
           actualizar_tablero(col_orig, fila_orig, col_dest, fila_dest, tablero, estado);
	   movimiento_realizado = VERDADERO;
        }
     }
  }
  while (movimiento_realizado == FALSO);
}


// ---------------------------------------------------------------------------------------
// Función: movimiento_maquina()
// Gestiona el movimiento de una pieza por parte de un jugador máquina
// ---------------------------------------------------------------------------------------
void movimiento_maquina(Tcasilla tablero[9][9], Testado* estado)
{
	// FUNCION SIN IMPLEMENTAR
	// por ahora sólo pueden jugar dos jugadores humanos
}


// ---------------------------------------------------------------------------------------
// Función: elegir_origen()
// Elegir la casilla de origen de la pieza que se va a mover.
// Devuelve las coordenadas de la casilla en (x,y)
// Devuelve 0 si todo va bien, -1 si las coordenadas son ilegales y -2 si se pulsa ESC
// ---------------------------------------------------------------------------------------
int elegir_origen(int* x, int* y, Tcasilla tablero[9][9], Testado* estado)
{
  int correcto;
  char txt[100];
  char col;
  int result;

    escribir("Seleccione ORIGEN del movimiento", 1);
    escribir("(pulse ESPACIO para confirmar)", 2);
    seleccionar_casilla(x,y,0,0,tablero);  // Devuelve origen en (x,y)
    switch (*x) {
      case 1: col = 'a'; break;
      case 2: col = 'b'; break;
      case 3: col = 'c'; break;
      case 4: col = 'd'; break;
      case 5: col = 'e'; break;
      case 6: col = 'f'; break;
      case 7: col = 'g'; break;
      case 8: col = 'h'; break;
      default:col = '0'; break;
    }
    sprintf(txt, "Origen: %c%i\0", col, *y);
    escribir(txt, 3);

    if ((*x == 0) && (*y == 0))		// Se ha pulsado ESC al elegir la casilla
       result = -2;
    else
    {
      correcto = comprobar_origen(*x, *y, tablero, estado);
      if (correcto == FALSO)
      {
         result = -1;
         escribir("Movimiento ilegal !!", 1);
         sleep(2);
      }
      else
         result = 0;
    }

    return result;
}


// ---------------------------------------------------------------------------------------
// Función: elegir_destino()
// Selecciona la casilla de destino de un movimiento. Devuelve la casilla en (x,y)
// Devuelve 0 si todo va bien, -1 si las coordenadas son ilegales y -2 si se pulsa ESC
// ---------------------------------------------------------------------------------------
int elegir_destino(int* x, int* y, int x_orig, int y_orig, Tcasilla tablero[9][9], Testado* estado)
{
  int correcto;
  char txt[100];
  char col;
  int result;

    escribir("Seleccione DESTINO del movimiento", 1);
    escribir("(pulse ESPACIO para confirmar)", 2);
    seleccionar_casilla(x,y,x_orig,y_orig,tablero);  // Devuelve destino en (x,y)
    switch (*x) {
      case 1: col = 'a'; break;
      case 2: col = 'b'; break;
      case 3: col = 'c'; break;
      case 4: col = 'd'; break;
      case 5: col = 'e'; break;
      case 6: col = 'f'; break;
      case 7: col = 'g'; break;
      case 8: col = 'h'; break;
      default:col = '-'; break;
    }
    sprintf(txt, "Destino: %c%i\0", col, *y);
    escribir(txt, 4);

    if ((*x == 0) && (*y == 0))		// Se ha pulsado ESC al elegir la casilla
       result = -2;
    else
    {
      correcto = comprobar_destino(*x, *y, x_orig, y_orig, tablero, estado);
      if (correcto == FALSO)
      {
         result = -1;
         escribir("Movimiento ilegal !!", 1);
         sleep(2);
      }
      else
         result = 0;
    }

   return result;
}


// ---------------------------------------------------------------------------------------
// Función: comprobar_origen()
// Comprueba que la pieza que se pretende mover efectivamente SE PUEDE mover. Devuelve
// VERDADERO o FALSO, según pueda o no pueda moverse.
// ---------------------------------------------------------------------------------------
int comprobar_origen(int x, int y, Tcasilla tablero[9][9], Testado* estado)
{
  int respuesta;

  respuesta = FALSO;		// Por defecto, el movimiento es ilegal
  // Comprobemos si en (x,y) hay una pieza del jugador que está moviendo
  if ((estado->turno == BLANCAS) && (tablero[x][y].color_pieza == BLANCO))
     respuesta = VERDADERO;
  if ((estado->turno == NEGRAS) && (tablero[x][y].color_pieza == NEGRO))
     respuesta = VERDADERO;
     
  return respuesta;

}


// ---------------------------------------------------------------------------------------
// Función: comprobar_destino()
// Comprueba que el lugar de destino de la pieza que se pretende mover es correcto. Devuelve
// VERDADERO o FALSO, según pueda o no pueda moverse.
// ---------------------------------------------------------------------------------------
int comprobar_destino(int x, int y, int x_orig, int y_orig, Tcasilla tablero[9][9], Testado* estado)
{
  int correcto;
  
  correcto = FALSO;
  switch (tablero[x_orig][y_orig].pieza) {
     case PEON:    correcto = comprobar_mov_peon(x, y, x_orig, y_orig, tablero, estado); break;
     case CABALLO: correcto = comprobar_mov_caballo(x, y, x_orig, y_orig, tablero, estado); break;
     case ALFIL:   correcto = comprobar_mov_alfil(x, y, x_orig, y_orig, tablero, estado); break;
     case TORRE:   correcto = comprobar_mov_torre(x, y, x_orig, y_orig, tablero, estado); break;
     case REY:     correcto = comprobar_mov_rey(x, y, x_orig, y_orig, tablero, estado); break;
     case DAMA:    correcto = comprobar_mov_dama(x, y, x_orig, y_orig, tablero, estado); break;
  }
  return correcto;
}

// ---------------------------------------------------------------------------------------
// Función: actualizar_tablero()
// Hace efectivo un movimiento de piezas actualizando las casillas del tablero.
// También modifica el estado (si procede)
// ---------------------------------------------------------------------------------------
void actualizar_tablero(int x_orig, int y_orig, int x_dest, int y_dest, Tcasilla tablero[9][9], Testado* estado)
{
  // Coloca la pieza en su nueva casilla
  tablero[x_dest][y_dest].pieza = tablero[x_orig][y_orig].pieza;
  tablero[x_dest][y_dest].color_pieza = tablero[x_orig][y_orig].color_pieza;

  // Elimina la pieza de su ubicación original
  tablero[x_orig][y_orig].pieza = NINGUNA;
  tablero[x_orig][y_orig].color_pieza = NINGUNO;
}


// ---------------------------------------------------------------------------------------
// Función: comprobar_mov_peon()
// Comprueba si el movimiento del peon es legal. Devuelve VERDADERO si lo es, o FALSO si es ilegal
// ---------------------------------------------------------------------------------------
int comprobar_mov_peon(int x, int y, int x_orig, int y_orig, Tcasilla tablero[9][9], Testado* estado)
{
   int correcto = FALSO;	// Por defecto el movimiento es ILEGAL
   int y_dest;			// Fila a la que debería haber ido a parar el peón
   char color;

   // PARTE 1: COMPROBAR MOVIMIENTO DE UN ESCAQUE
   if (estado->turno == BLANCAS)  // Establecemos el color del jugador que está moviendo
   {
     color = BLANCO;
     y_dest = y_orig+1;		// El blanco solo puede mover su peón hacia delante en el tablero
   }
   else
   {
     color = NEGRO;
     y_dest = y_orig-1;		// El negro sólo puede mover su peón hacia detrás en el tablero
   }

   if (y == y_dest) 		// MOVIMIENTO DE UN ESCAQUE. Puede ser correcto. Vamos a comprobarlo
   {
     if  (x == x_orig) 		// Se ha movido de frente. Es válido si no hay nadie en esa casilla
     {
       if (tablero[x][y].pieza == NINGUNA)
          correcto = VERDADERO;
     }
     if ((x == x_orig-1) || (x == x_orig+1))
     {				// Se ha movido en diagonal. Es válido si toma una pieza enemiga
       if ((tablero[x][y].color_pieza != color) && (tablero[x][y].pieza != NINGUNA))
          correcto = VERDADERO;
     }
   }

   // PARTE 2: COMPROBAR MOVIMIENTO DE DOS ESCAQUES (solo en la salida)
   if ((estado->turno == BLANCAS) && (y == y_orig+2) && (y_orig == 2))
      correcto = VERDADERO;
   if ((estado->turno == NEGRAS) && (y == y_orig-2) && (y_orig == 7))
      correcto = VERDADERO;

   // El resultado será FALSO a menos que haya entrado por alguno de los condicionales
   return correcto;
}

// ---------------------------------------------------------------------------------------
// Función: comprobar_mov_caballo()
// Comprueba si el movimiento del caballo es legal. Devuelve VERDADERO si lo es, o FALSO si es ilegal
// ---------------------------------------------------------------------------------------
int comprobar_mov_caballo(int x, int y, int x_orig, int y_orig, Tcasilla tablero[9][9], Testado* estado)
{
   int correcto;

   // Supondremos que el movimiento es ILEGAL
   correcto = FALSO;

   // El caballo solo puede mover a 8 casillas. Vamos a ver si el destino es una de ellas
   if ( ((x == x_orig + 1) && (y == y_orig + 2)) ||
        ((x == x_orig + 2) && (y == y_orig + 1)) ||
        ((x == x_orig - 1) && (y == y_orig + 2)) ||
        ((x == x_orig - 2) && (y == y_orig + 1)) ||
        ((x == x_orig + 1) && (y == y_orig - 2)) ||
        ((x == x_orig + 2) && (y == y_orig - 1)) ||
        ((x == x_orig - 1) && (y == y_orig - 2)) ||
        ((x == x_orig - 2) && (y == y_orig + 1)) )
    {
    	// La casilla de destino es correcta. Comprobemos que en ella no haya otra pieza de nuestro color
	if ((tablero[x][y].color_pieza != BLANCO) && (estado->turno == BLANCAS)) correcto = VERDADERO;
	if ((tablero[x][y].color_pieza != NEGRO) && (estado->turno == NEGRAS)) correcto = VERDADERO;
    }

  return correcto;
}
// ---------------------------------------------------------------------------------------
// Función: comprobar_mov_alfil()
// Comprueba si el movimiento del alfil es legal. Devuelve VERDADERO si lo es, o FALSO si es ilegal
// ---------------------------------------------------------------------------------------
int comprobar_mov_alfil(int x, int y, int x_orig, int y_orig, Tcasilla tablero[9][9], Testado* estado)
{
   int correcto, inc_x, inc_y, cx, cy;

   // Supondremos que el movimiento es LEGAL y vamos a buscar causas por las que no lo sea
   correcto = VERDADERO;

   // Comprobamos que el origen y el destino son distintos
   if ((x_orig == x) && (y_orig == y))
      correcto = FALSO;
   else
   {
      // Miramos en qué direcciones X e Y intenta mover el alfil
      if (x_orig < x) inc_x = 1; else inc_x = -1;
      if (y_orig < y) inc_y = 1; else inc_y = -1;
      cx = x_orig + inc_x;
      cy = y_orig + inc_y;

      // Recorremos el tablero siguiendo la diagonal en esa dirección, a ver si hay piezas en la trayectoria
      while ((cx != x) && (cy != y))
      {
         if (tablero[cx][cy].pieza != NINGUNA) correcto = FALSO;
	 cx += inc_x; cy += inc_y;
      }

      // Comprobamos que el destino está efectivamente en la diagonal trazada
      if ((x != cx) || (y != cy)) correcto = FALSO;

      // Comprobamos que el color de la pieza de la casilla de destino sea distinto del nuestro
      if ((tablero[x][y].color_pieza == BLANCO) && (estado->turno == BLANCAS))
         correcto = FALSO;
      if ((tablero[x][y].color_pieza == NEGRO) && (estado->turno == NEGRAS))
         correcto = FALSO;
   }
   
   return correcto;
}
// ---------------------------------------------------------------------------------------
// Función: comprobar_mov_torre()
// Comprueba si un movimiento de la torre es legal. Devuelve VERDADERO si lo es, o FALSO si es ilegal
// ---------------------------------------------------------------------------------------
int comprobar_mov_torre(int x, int y, int x_orig, int y_orig, Tcasilla tablero[9][9], Testado* estado)
{
   int correcto;
   int i;

   // Suponemos por defecto que el movimiento es LEGAL y vamos a buscar alguna causa por la que no lo sea
   correcto = VERDADERO;

   // PRIMERO: comprobar si el destino está en la misma fila o columna que el origen
   if ((x != x_orig) && (y != y_orig))
     correcto = FALSO;

   // SEGUNDO: comprobar que el origen y el destino sean distintos
   if ((x == x_orig) && (y == y_orig))
     correcto = FALSO;

   // TERCERO: comprobar que no hay obstáculos en la trayectoria
   // Hay cuatro posibles movimientos (derecha, izquierda, arriba y abajo)
   // Vamos a seguir la trayectoria del que corresponda al nuestro
   if ((x_orig == x) && (y_orig < y))		// Movimiento hacia la derecha
   {
      for (i = y_orig+1; i < y; i++)
         if (tablero[x_orig][i].pieza != NINGUNA) correcto = FALSO;
   }
   if ((x_orig == x) && (y_orig > y))		// Movimiento hacia la izquierda
   {
      for (i = y_orig-1; i > y; i--)
         if (tablero[x_orig][i].pieza != NINGUNA) correcto = FALSO;
   }
   if ((x_orig < x) && (y_orig == y))		// Movimiento hacia arriba
   {
      for (i = x_orig+1; i < x; i++)
         if (tablero[i][y_orig].pieza != NINGUNA) correcto = FALSO;
   }
   if ((x_orig > x) && (y_orig == y))		// Movimiento hacia abajo
   {
      for (i = x_orig-1; i > x; i--)
         if (tablero[i][y_orig].pieza != NINGUNA) correcto = FALSO;
   }
   
   // CUARTO: comprobar que en la casilla de destino no haya una pieza de nuestro color
   if ((tablero[x][y].color_pieza == BLANCO) && (estado->turno == BLANCAS))
      correcto = FALSO;
   if ((tablero[x][y].color_pieza == NEGRO) && (estado->turno == NEGRAS))
      correcto = FALSO;
      
   // Antes de terminar, si el movimiento se va a realizar ponemos a 1 el flag de movimiento
   // para impedir el enroque si más adelante se intenta realizar
   if (correcto == VERDADERO)
   {
      if (estado->turno == BLANCAS) estado->torre_blanca_movida = VERDADERO;
      if (estado->turno == NEGRAS) estado->torre_negra_movida = VERDADERO;
   }

   return correcto;
}
// ---------------------------------------------------------------------------------------
// Función: comprobar_mov_rey()
// Comprueba si el movimiento del rey es legal. Devuelve VERDADERO si lo es, o FALSO si es ilegal
// ---------------------------------------------------------------------------------------
int comprobar_mov_rey(int x, int y, int x_orig, int y_orig, Tcasilla tablero[9][9], Testado* estado)
{
   int correcto;

   // Supondremos que el movimiento es ILEGAL
   correcto = FALSO;

   // El rey puede mover a 9 casillas. Vamos a ver si el destino es una de ellas
   if ( ((x == x_orig + 1) && (y == y_orig + 1)) ||
        ((x == x_orig + 1) && (y == y_orig)    ) ||
        ((x == x_orig + 1) && (y == y_orig - 1)) ||
        ((x == x_orig)     && (y == y_orig + 1)) ||
        ((x == x_orig)     && (y == y_orig)    ) ||
        ((x == x_orig)     && (y == y_orig - 1)) ||
        ((x == x_orig - 1) && (y == y_orig + 1)) ||
        ((x == x_orig - 1) && (y == y_orig)    ) ||
        ((x == x_orig - 1) && (y == y_orig - 1)) )
    {
    	// La casilla de destino es correcta. Comprobemos que en ella no haya otra pieza de nuestro color
	if ((tablero[x][y].color_pieza != BLANCO) && (estado->turno == BLANCAS)) correcto = VERDADERO;
	if ((tablero[x][y].color_pieza != NEGRO) && (estado->turno == NEGRAS)) correcto = VERDADERO;
    }

  // Antes de terminar, si el movimiento se va a realizar ponemos a 1 el flag de movimiento
  // para impedir el enroque si más adelante se intenta realizar
  if (correcto == VERDADERO)
  {
      if (estado->turno == BLANCAS) estado->rey_blanco_movido = VERDADERO;
      if (estado->turno == NEGRAS) estado->rey_negro_movido = VERDADERO;
  }

  return correcto;
}
// ---------------------------------------------------------------------------------------
// Función: comprobar_mov_dama()
// Comprueba si el movimiento de la dama es legal. Devuelve VERDADERO si lo es, o FALSO si es ilegal
// ---------------------------------------------------------------------------------------
int comprobar_mov_dama(int x, int y, int x_orig, int y_orig, Tcasilla tablero[9][9], Testado* estado)
{
   int correcto, correcto_torre, correcto_alfil;

   // La dama puede mover como la torre y el alfil juntos, así que usamos el mismo código
   // que en aquéllos
   correcto_torre = comprobar_mov_torre(x,y,x_orig,y_orig,tablero,estado);
   correcto_alfil = comprobar_mov_alfil(x,y,x_orig,y_orig,tablero,estado);
   
   // Si cualquiera de los dos es correcto, el movimiento de la dama también lo será
   if ((correcto_torre == VERDADERO) || (correcto_alfil == VERDADERO))
      correcto = VERDADERO;
   else
      correcto = FALSO;
      
   return correcto;
}



