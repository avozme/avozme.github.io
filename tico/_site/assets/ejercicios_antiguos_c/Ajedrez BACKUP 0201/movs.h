/*
PROGRAMA:  Ajedrez 1.0
ARCHIVO:   movs.h
CONTENIDO: Archivo de cabecera de las funciones de movimientos de las piezas
AUTOR:     Alfredo Moreno
*/

#include "tipos.h"

// ---------------------------------------------------------------------------------------
// Función: realizar_movimiento()
// Determina a qué jugador le toca mover y realiza el movimiento alterando el tablero
// y el estado del juego (si procede)
// ---------------------------------------------------------------------------------------
void realizar_movimiento(Tcasilla tablero[9][9], Testado* estado, char jug_blanco, char jug_negro);

// ---------------------------------------------------------------------------------------
// Función: movimiento_humano()
// Gestiona el movimiento de una pieza por parte de un jugador humano
// ---------------------------------------------------------------------------------------
void movimiento_humano(Tcasilla tablero[9][9], Testado* estado);

// ---------------------------------------------------------------------------------------
// Función: movimiento_maquina()
// Gestiona el movimiento de una pieza por parte de un jugador máquina
// ---------------------------------------------------------------------------------------
void movimiento_maquina(Tcasilla tablero[9][9], Testado* estado);

// ---------------------------------------------------------------------------------------
// Función: elegir_origen()
// Elegir la casilla de origen de la pieza que se va a mover.
// Devuelve las coordenadas de la casilla en (x,y)
// Devuelve 0 si las coordenadas son legales, -1 si no lo son y -2 si se ha pulsado ESC
// ---------------------------------------------------------------------------------------
int elegir_origen(int* x, int* y, Tcasilla tablero[9][9], Testado* estado);

// ---------------------------------------------------------------------------------------
// Función: elegir_destino()
// Selecciona la casilla de destino de un movimiento. Devuelve la casilla en (x,y)
// Devuelve 0 si las coordenadas son legales, -1 si no lo son y -2 si se ha pulsado ESC
// ---------------------------------------------------------------------------------------
int elegir_destino(int* x, int* y, int x_orig, int y_orig, Tcasilla tablero[9][9], Testado* estado);

// ---------------------------------------------------------------------------------------
// Función: comprobar_origen()
// Comprueba que la pieza que se pretende mover efectivamente SE PUEDE mover. Devuelve
// VERDADERO o FALSO, según pueda o no pueda moverse.
// ---------------------------------------------------------------------------------------
int comprobar_origen(int x, int y, Tcasilla tablero[9][9], Testado* estado);

// ---------------------------------------------------------------------------------------
// Función: comprobar_destino()
// Comprueba que el lugar de destino de la pieza que se pretende mover es correcto. Devuelve
// VERDADERO o FALSO, según pueda o no pueda moverse.
// ---------------------------------------------------------------------------------------
int comprobar_destino(int x, int y, int x_orig, int y_orig, Tcasilla tablero[9][9], Testado* estado);

// ---------------------------------------------------------------------------------------
// Función: actualizar_tablero()
// Hace efectivo un movimiento de piezas actualizando las casillas del tablero.
// También modifica el estado (si procede)
// ---------------------------------------------------------------------------------------
void actualizar_tablero(int x_orig, int y_orig, int x_dest, int y_dest, Tcasilla tablero[9][9], Testado* estado);

// ---------------------------------------------------------------------------------------
// Funciones: comprobar_mov_XXX()
// Comprueba si el movimiento de una pieza es legal. Devuelve VERDADERO si lo es, o FALSO si es ilegal
// ---------------------------------------------------------------------------------------
int comprobar_mov_peon(int x, int y, int x_orig, int y_orig, Tcasilla tablero[9][9], Testado* estado);
int comprobar_mov_caballo(int x, int y, int x_orig, int y_orig, Tcasilla tablero[9][9], Testado* estado);
int comprobar_mov_alfil(int x, int y, int x_orig, int y_orig, Tcasilla tablero[9][9], Testado* estado);
int comprobar_mov_torre(int x, int y, int x_orig, int y_orig, Tcasilla tablero[9][9], Testado* estado);
int comprobar_mov_rey(int x, int y, int x_orig, int y_orig, Tcasilla tablero[9][9], Testado* estado);
int comprobar_mov_dama(int x, int y, int x_orig, int y_orig, Tcasilla tablero[9][9], Testado* estado);
