/*
PROGRAMA:  Ajedrez 1.0
ARCHIVO:   ia.c
CONTENIDO: Funciones de inteligencia artificial
AUTOR:     Alfredo Moreno
*/

#include "ia.h"
#include "movs.h"

int val_poda1, val_poda2;     // Para la poda del minimax

// Realiza una valoraciï¿½ numï¿½ica del estado del juego y del tablero pasados como argumento
int valorar_estado(Tcasilla tablero[9][9], Testado* estado, char jugador)
{
   int x, y, i, j;
   int total, puntos;

   total = 0;
   if (comprobar_jaque(tablero, estado) == VERDADERO)
      total = 9999;
   else
   {
     for (x=1; x<=8; x++)
     for (y=1; y<=8; y++)
     {
	   puntos = 0;
	   switch (tablero[x][y].pieza)
	   {
	      case PEON:    puntos = 100;   // 100 puntos por cada peï¿½
	            if (((x==4) || (x==5)) && ((y==4) || (y==5))) {
			       puntos = puntos + 50;  // 50 puntos mï¿½ por tener un peï¿½ en el centro
			       if (estado->movimientos < 10) 
			          puntos = puntos + 300;   // 300 más si estamos al principio de la partida
                }
	            if (((x==3) || (x==6)) && ((y==4) || (y==5))) {
			       puntos = puntos + 25;  // 25 puntos mï¿½ por tener un peï¿½ cerca del centro
			       if (estado->movimientos < 10) 
			          puntos = puntos + 100;   // 100 más si estamos al principio de la partida
                }
   			    if (tablero[x][y].color_pieza == BLANCO)
			       puntos = puntos + (y-2)*2;   // Mï¿½ puntos cuanto mï¿½ adelantado estï¿½el peï¿½
			    if (tablero[x][y].color_pieza == NEGRO)
			       puntos = puntos + (8-(y+1))*2;
                if (esta_protegido(tablero, estado, x, y) == 1)
                   puntos = puntos + 100;       // 100 puntos más si el peón está protegido por otra pieza
			    break;
	      case CABALLO: puntos = 315;   // 315 puntos por cada caballo
	            if (((x==4) || (x==5)) && ((y==4) || (y==5)))
			       puntos = 15;  // 15 puntos mï¿½ por tener un caballo en el centro
			    if (((x==6) || (x==3)) && ((y>=3) && (y<=6)))
			       puntos = 5;   // 5 puntos mï¿½ por tener un caballo cerca del centro
			    if (((y==6) || (y==3)) && ((x>=3) && (x<=6)))
			       puntos = 5;   // 5 puntos mï¿½ por tener un caballo cerca del centro
			    if (((x==2) || (x==7)) && ((y>=2) && (y<=7)))
			       puntos = -5;   // 5 puntos menos por tener un caballo lejos del centro
			    if (((y==2) || (y==7)) && ((x>=2) && (x<=7)))
			       puntos = -5;   // 5 puntos menos por tener un caballo lejos del centro
			    if (((x==1) || (x==8) || (y==1) || (y==2)))
			       puntos = -15;  // 15 puntos menos por tener un caballo en los laterales
	                    break;
	      case ALFIL:   puntos = 330;   // 330 puntos por cada alfil
                            // Vamos a contar a cuï¿½tas casillas puede moverse el alfil (serï¿½ mï¿½ puntos positivos)
			    i = x+1; j = y+1;
			    while ((i<=8) && (y<=8)) {
			       if (tablero[i][j].pieza != NINGUNA) break; else puntos++;
			       i++; j++;
			    }
			    i = x+1; j = y-1;
			    while ((i<=8) && (y>=1)) {
			       if (tablero[i][j].pieza != NINGUNA) break; else puntos++;
			       i++; j--;
			    }
			    i = x-1; j = y+1;
			    while ((i>=1) && (y<=8)) {
			       if (tablero[i][j].pieza != NINGUNA) break; else puntos++;
			       i--; j++;
			    }
			    i = x-1; j = y-1;
			    while ((i>=1) && (y>=1)) {
			       if (tablero[i][j].pieza != NINGUNA) break; else puntos++;
			       i--; j--;
			    }
	                    break;
	      case TORRE:   puntos = 500;   // 500 puntos por cada torre
                            // Vamos a contar a cuï¿½tas casillas puede moverse la torre (serï¿½ mï¿½ puntos positivos)
			    for (i = x+1; i <= 8; i++)
			       if (tablero[i][y].pieza != NINGUNA) break; else puntos++;
			    for (i = x-1; i >= 1; i--)
			       if (tablero[i][y].pieza != NINGUNA) break; else puntos++;
			    for (j = y+1; j <= 8; j++)
			       if (tablero[x][j].pieza != NINGUNA) break; else puntos++;
			    for (i = y-1; j >= 1; j--)
			       if (tablero[x][j].pieza != NINGUNA) break; else puntos++;
	                    break;
	      case DAMA:    puntos = 940;   // 940 puntos por la dama
	                    if (((x==5) || (x==6)) && ((y==5) || (y==6)))
			       puntos = 4;   // 4 puntos mï¿½ por tener la dama en el centro
			    if (((x==6) || (x==3)) && ((y>=3) && (y<=6)))
			       puntos = 2;   // 2 puntos mï¿½ por tener la dama cerca del centro
			    if (((y==6) || (y==3)) && ((x>=3) && (x<=6)))
			       puntos = 2;   // 2 puntos mï¿½ por tener la dama cerca del centro
			    if (((x==2) || (x==7)) && ((y>=2) && (y<=7)))
			       puntos = -2;   // 2 puntos menos por tener la dama lejos del centro
			    if (((y==2) || (y==7)) && ((x>=2) && (x<=7)))
			       puntos = -2;   // 2 puntos menos por tener la dama lejos del centro
			    if (((x==1) || (x==8) || (y==1) || (y==2)))
			       puntos = -4;  // 4 puntos menos por tener la dama en los laterales
			    break;
	   }
	   if (tablero[x][y].color_pieza == estado->turno)
	     total = total - puntos;
	   else
	     total = total + puntos;
     }
  } // else

  return total;
}

// Inicia el recorrido en el ï¿½bol de bsqueda MINIMAX.
// Devuelve la valoraciï¿½ del mejor nodo-hoja encontrado y el movimiento que hay que realizar
// y que representa el primer paso del camino hacia ese nodo-hoja.
Tmovimiento buscar_mejor_movimiento(Tcasilla tablero[9][9], Testado* estado, char jugador)
{
   int x1, x2, y1, y2, maximo, valoracion;
   Tcasilla nuevo_tablero[9][9];
   Testado nuevo_estado;
   Tmovimiento mejor;

   maximo = -9999;
   val_poda1 = 0;   // Para la poda del minimax en el nivel 3
   val_poda2 = 0;   // Lo mismo en el nivel 5
   // Recorremos el tablero buscando el mejor de todos los posibles movimientos.
   // Primero localizaremos las piezas del color del jugador actual.
   for (x1=1; x1<=8; x1++)
     for (y1=1; y1<=8; y1++)
     {
	   if (tablero[x1][y1].color_pieza == estado->turno)
	   {
	        // Iniciamos otro recorrido del tablero mirando a dï¿½de puede mover esta pieza
		for (x2=1; x2<=8; x2++)
		  for (y2=1; y2<=8; y2++)
		  {
		     if (comprobar_destino(x2, y2, x1, y1, tablero, estado) == VERDADERO)
		     {
		         // El movimiento de (x1,y1) a (x2,y2) es posible. Vamos a iniciar una rama de bsqueda por ahï¿½
			 copiar_tablero(tablero, nuevo_tablero);	// Creamos copias del tablero y del estado
			 copiar_estado(estado, &nuevo_estado);
			 // Realizamos el movimiento sobre los nuevos tablero y estado
			 actualizar_tablero(x1, y1, x2, y2, nuevo_tablero, &nuevo_estado);
			 if (nuevo_estado.turno == BLANCAS) nuevo_estado.turno == NEGRAS;
			 else nuevo_estado.turno = BLANCAS;
			 // Lanzamos la bsqueda por esa rama
			 valoracion = jugador_contrario(1, 0L, nuevo_tablero, &nuevo_estado, jugador);
			 // Comprobamos si esa rama nos lleva al mejor estado posible
			 if (valoracion > maximo)
			 {
			     maximo = valoracion;
			     mejor.valoracion = maximo;
			     mejor.x_orig = x1; mejor.y_orig = y1;
			     mejor.x_dest = x2; mejor.y_dest = y2;
			 }
		     } // if
		  } // for
           } // if
   } // for
   
   //imprimir_result("MAX", profundidad, maximo);
   return mejor;
}


// Recorrido por el Ã¡rbol de bÃºsqueda del juego. Nivel MIN del MINIMAX (correspondiente al jugador contrario)
// Se lleva un control del nivel de profundidad y de la memoria ocupada para no sobrepasar los lï¿½ites.
// Devuelve la valoraciÃ³n MINIMA de todos los nodos hijo.
int jugador_contrario(int profundidad, long int memoria_ocup, Tcasilla tablero[9][9], Testado* estado, char jugador)
{
   int x1, x2, y1, y2, minimo, valor_hijo;
   Tcasilla nuevo_tablero[9][9];
   Testado nuevo_estado;

   // Caso base de la recursión: cuando se alcanza la profundidad máxima (o la memoria máxima)
   if ((profundidad == PROFUNDIDAD_MAX) || (memoria_ocup >= MEMORIA_MAX))    
   {
      minimo = valorar_estado(tablero, estado, jugador);
      //imprimir_result("MIN", profundidad, minimo);
      return minimo;
   }
   
   if (profundidad == NIVEL_PODA1)            // Comprobamos si hay que podar esta rama
   {
      minimo = valorar_estado(tablero, estado, jugador);
      if (minimo < val_poda1)                 // No podamos esta rama
            val_poda1 = minimo;
      else {                                    // Sí podamos
            //imprimir_result("MIN", profundidad, minimo);
            return minimo;
      }
   }
   if (profundidad == NIVEL_PODA2)            // Comprobamos también la segunda poda
   {
      minimo = valorar_estado(tablero, estado, jugador);
      if (minimo < val_poda2)                 // No podamos esta rama
            val_poda2 = minimo;
      else                                    // Sí podamos
            return minimo;
   }
                                                                        
   // Hemos decidido no podar. Procedemos con el caso general MIN de la recursión minimax
   minimo = 9999;
   // Recorremos el tablero buscando el mejor de todos los posibles movimientos.
   // Primero localizaremos las piezas del color del jugador actual.
   for (x1=1; x1<=8; x1++)
     for (y1=1; y1<=8; y1++)
     {
	   if (tablero[x1][y1].color_pieza == estado->turno)
	   {
	        // Iniciamos otro recorrido del tablero mirando a dï¿½de puede mover esta pieza
		for (x2=1; x2<=8; x2++)
		  for (y2=1; y2<=8; y2++)
		  {
		     if (comprobar_destino(x2, y2, x1, y1, tablero, estado) == VERDADERO)
		     {
		         // El movimiento de (x1,y1) a (x2,y2) es posible. Vamos a iniciar una rama de bsqueda por ahï¿½
			 copiar_tablero(tablero, nuevo_tablero);	// Creamos copias del tablero y del estado
			 copiar_estado(estado, &nuevo_estado);
			 // Realizamos el movimiento sobre los nuevos tablero y estado
			 actualizar_tablero(x1, y1, x2, y2, nuevo_tablero, &nuevo_estado);
			 if (nuevo_estado.turno == BLANCAS) nuevo_estado.turno == NEGRAS;
			 else nuevo_estado.turno = BLANCAS;
			 // Lanzamos la bÃºsqueda por esa rama. El prÃ³ximo movimiento serÃ¡ MAX (del jugador activo)
			 memoria_ocup = memoria_ocup + sizeof(Tcasilla)*81 + sizeof(Testado) + sizeof(int) * 6;
			 valor_hijo = jugador_activo(profundidad+1, memoria_ocup, nuevo_tablero, &nuevo_estado, jugador);
			 if (valor_hijo < minimo)	// Nos quedamos con el menor valor encontrado
			     minimo = valor_hijo;
		     } // if
          } // for
       } // if
     } // for

   //imprimir_result("MIN", profundidad, minimo);
   return minimo;
}


// Recorrido por el Ã¡rbol de bÃºsqueda del juego. Nivel MAX del MINIMAX (correspondiente al jugador activo)
// Se lleva un control del nivel de profundidad y de la memoria ocupada para no sobrepasar los lï¿½ites.
// Devuelve la valoraciÃ³n MINIMA de todos los nodos hijo.
int jugador_activo(int profundidad, long int memoria_ocup, Tcasilla tablero[9][9], Testado* estado, char jugador)
{
   int x1, x2, y1, y2, maximo, valor_hijo;
   Tcasilla nuevo_tablero[9][9];
   Testado nuevo_estado;

   // Caso base de la recursión: cuando se alcanza la profundidad máxima (o la memoria máxima)
   if ((profundidad == PROFUNDIDAD_MAX) || (memoria_ocup >= MEMORIA_MAX))    
   {
      maximo = valorar_estado(tablero, estado, jugador);
      //imprimir_result("MAX", profundidad, maximo);
      return maximo;
   }
   
   if (profundidad == NIVEL_PODA1)            // Comprobamos si hay que podar esta rama
   {
      maximo = valorar_estado(tablero, estado, jugador);
      if (maximo > val_poda1)                 // No podamos esta rama
            val_poda1 = maximo;
      else  {                                 // Sí podamos
          //imprimir_result("MAX", profundidad, maximo);
          return maximo; 
      }
   }
   
   if (profundidad == NIVEL_PODA2)            // Comprobamos también la segunda poda
   {
      maximo = valorar_estado(tablero, estado, jugador);
      if (maximo > val_poda2)                // No podamos esta rama
            val_poda2= maximo;
      else                                   // Sí podamos
            return maximo;
   }
   
   // Hemos decidido no podar. Procedemos con el caso general MAX de la recursión minimax
   maximo = -9999;
   // Recorremos el tablero buscando el mejor de todos los posibles movimientos.
   // Primero localizaremos las piezas del color del jugador actual.
   for (x1=1; x1<=8; x1++)
     for (y1=1; y1<=8; y1++)
     {
	   if (tablero[x1][y1].color_pieza == estado->turno)
	   {
	        // Iniciamos otro recorrido del tablero mirando a dï¿½de puede mover esta pieza
		for (x2=1; x2<=8; x2++)
		  for (y2=1; y2<=8; y2++)
		  {
		     if (comprobar_destino(x2, y2, x1, y1, tablero, estado) == VERDADERO)
		     {
		         // El movimiento de (x1,y1) a (x2,y2) es posible. Vamos a iniciar una rama de bsqueda por ahï¿½
			 copiar_tablero(tablero, nuevo_tablero);	// Creamos copias del tablero y del estado
			 copiar_estado(estado, &nuevo_estado);
			 // Realizamos el movimiento sobre los nuevos tablero y estado
			 actualizar_tablero(x1, y1, x2, y2, nuevo_tablero, &nuevo_estado);
			 if (nuevo_estado.turno == BLANCAS) nuevo_estado.turno == NEGRAS;
			 else nuevo_estado.turno = BLANCAS;
			 // Lanzamos la bÃºsqueda por esa rama. El prÃ³ximo movimiento serÃ¡ MAX (del jugador activo)
			 memoria_ocup = memoria_ocup + sizeof(Tcasilla)*81 + sizeof(Testado) + sizeof(int) * 6;
			 valor_hijo = jugador_contrario(profundidad+1, memoria_ocup, nuevo_tablero, &nuevo_estado, jugador);
			 if (valor_hijo > maximo)	// Nos quedamos con el mayor valor encontrado
			     maximo = valor_hijo;
		     } // if
		  } // for
        } // if
      } // for

   //imprimir_result("MAX", profundidad, maximo);
   return maximo;
}


// Hace una copia del tablero
void copiar_tablero(Tcasilla tab_orig[9][9], Tcasilla tab_dest[9][9])
{
   int x,y;
   for (x=1; x<=8; x++)
    for (y=1; y<=8; y++)
      tab_dest[x][y] = tab_orig[x][y];
}

// Hace una copia del estado
void copiar_estado(Testado* est_orig, Testado* est_dest)
{
   *est_dest = *est_orig;
}

// Escribe el árbol minimax en la salida estándar (usar sólo para depuración)
void imprimir_result(char* nivel, int prof, int valor)
{
   int i;
   for (i=1; i<=prof; i++) printf("  ");
   printf("%s - %i - %i\n", nivel, prof, valor);
}


// Devuelve 1 si la pieza que hay en (x,y) está protegida por otra pieza
// de su mismo color. Generalmente, la pieza de (x,y) será un peón y el "protector"
// será una pieza mayor (caballo, alfil, torre o dama)
int esta_protegido(Tcasilla tablero[9][9], Testado* estado, int dx, int dy)       
{
    int ox, oy;
    Tcasilla casilla;
    int protegido = 0;
    
    // Salvamos la casilla (dx, dy) y eliminamos lo que contiene. Si no lo hiciéramos,
    // ningún movimiento a esta casilla de una pieza del mismo color sería correcto
    casilla = tablero[dx][dy];
    tablero[dx][dy].pieza = NINGUNA;
    tablero[dx][dy].color_pieza = NINGUNO;
    
    // Recorremos el tablero buscando posibles "protectores"
    for (ox=1; ox<=8; ox++)
    for (oy=1; oy<=8; oy++)
    {
         if (tablero[ox][oy].color_pieza == estado->turno)
         {
             // Hemos encontrado una pieza del mismo color.
             // Comprobaremos si es un caballo, alfil, torre o dama, y si
             // se puede mover hasta (dx, dy)
             if (  (tablero[dx][dy].pieza == TORRE) || (tablero[dx][dy].pieza == ALFIL)
                || (tablero[dx][dy].pieza == DAMA)  || (tablero[dx][dy].pieza == CABALLO) )
             {
                  if (comprobar_destino(dx, dy, ox, oy, tablero, estado) == VERDADERO)
                  {
                     protegido = 1;
                     break;
                  }
             }
         }
    }
    // Restauramos el contenido original de la casilla
    tablero[dx][dy] = casilla;
       
    return protegido;
}
                  
    

