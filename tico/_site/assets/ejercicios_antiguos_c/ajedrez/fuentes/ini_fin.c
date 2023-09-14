/*
PROGRAMA:  Ajedrez 1.0
ARCHIVO:   ini_fin.c
CONTENIDO: Funciones de inicialización y terminación del juego
AUTOR:     Alfredo Moreno
*/

#include "ini_fin.h"

// ---------------------------------------------------------------------------------------
// Función: valores_iniciales()
// Establece los valores iniciales del tablero y del estado
// ---------------------------------------------------------------------------------------
void valores_iniciales(Tcasilla tablero[9][9], Testado* estado)
{
  int x, y;

  // Situamos las piezas (excepto peones) en sus posiciones en el tablero
  tablero[1][1].pieza = TORRE;		// Piezas blancas (fila 1)
  tablero[2][1].pieza = CABALLO;
  tablero[3][1].pieza = ALFIL;
  tablero[4][1].pieza = DAMA;
  tablero[5][1].pieza = REY;
  tablero[6][1].pieza = ALFIL;
  tablero[7][1].pieza = CABALLO;
  tablero[8][1].pieza = TORRE;
  tablero[1][8].pieza = TORRE;		// Piezas negras (fila 8)
  tablero[2][8].pieza = CABALLO;
  tablero[3][8].pieza = ALFIL;
  tablero[4][8].pieza = DAMA;
  tablero[5][8].pieza = REY;
  tablero[6][8].pieza = ALFIL;
  tablero[7][8].pieza = CABALLO;
  tablero[8][8].pieza = TORRE;

  // Situamos los peones
  for (x = 1; x <= 8; x++)
  {
    tablero[x][2].pieza = PEON;		// Peones blancos (fila 2)
    tablero[x][7].pieza = PEON;		// Peones negros (fila 7)
  }

  // Asignamos los colores a las piezas
  for (x = 1; x <= 8; x++)
  {
    tablero[x][1].color_pieza = BLANCO;		// Filas 1 y 2: piezas blancas
    tablero[x][2].color_pieza = BLANCO;
    tablero[x][7].color_pieza = NEGRO;		// Filas 7 y 8: piezas negras
    tablero[x][8].color_pieza = NEGRO;
  }

  // Inicializamos el resto de casillas (las que no están ocupadas por ninguna pieza)
  for (x = 1; x <= 8; x++)
    for (y = 3; y <= 6; y++)		// Filas de la 3 a la 6
    {
       tablero[x][y].pieza = NINGUNA;
       tablero[x][y].color_pieza = NINGUNO;
    }

  // Establecemos el color de las casillas del tablero (no el de las piezas)
  // Primero hacemos todas las casillas BLANCAS
  for (x = 1; x <= 8; x++)
    for (y = 1; y <= 8; y++)
       tablero[x][y].color_casilla = BLANCO;

  // Ahora cambiamos algunas para que sean casillas NEGRAS
  for (x = 1; x <= 8; x++)
    for (y = 1; y <= 8; y++)
    {
       if ((x % 2 == 0) && (y % 2 == 0))
         tablero[x][y].color_casilla = NEGRO;
       if ((x % 2 != 0) && (y % 2 != 0))
         tablero[x][y].color_casilla = NEGRO;
    }

  // Inicializamos el estado del juego
  estado->terminar = FALSO;
  estado->movimientos = 0;
  estado->jaque_al_rey_blanco = FALSO;
  estado->jaque_al_rey_negro = FALSO;
  estado->enroque_blanco_realizado = FALSO;
  estado->enroque_negro_realizado = FALSO;
  estado->torre_blanca_a_movida = FALSO;
  estado->torre_blanca_h_movida = FALSO;
  estado->torre_negra_a_movida = FALSO;
  estado->torre_negra_h_movida = FALSO;
  estado->rey_blanco_movido = FALSO;
  estado->rey_negro_movido = FALSO;
  estado->turno = BLANCAS;
  estado->t_blancas = 0;
  estado->t_negras = 0;
  estado->t_turno = time(NULL);
  estado->t_anterior = time(NULL);
  
  // Inicializar lista de movimientos
  lst_inicializar();
}


// ---------------------------------------------------------------------------------------
// Función: elegir_jugadores()
// El usuario selecciona el tipo de cada jugador
// ---------------------------------------------------------------------------------------
void elegir_jugadores(Testado* estado)
{
  estado->jug_blanco = HUMANO;
  estado->jug_negro = MAQUINA;
  menu_inicial(estado);  // Con este menú se pueden cambiar los tipos de los jugadores
  
}


// ---------------------------------------------------------------------------------------
// Función: terminar()
// Libera memoria y muestra mensajes de despedida
// ---------------------------------------------------------------------------------------
void terminar(Testado* estado)
{
   lst_finalizar();     // Finalizar lista de movimientos
}
