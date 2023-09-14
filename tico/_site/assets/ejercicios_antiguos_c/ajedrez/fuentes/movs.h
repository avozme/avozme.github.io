/*
PROGRAMA:  Ajedrez 1.0
ARCHIVO:   movs.h
CONTENIDO: Archivo de cabecera de las funciones de movimientos de las piezas
AUTOR:     Alfredo Moreno
*/

#include "tipos.h"
#include "lista.h"
#include <time.h>

// ---------------------------------------------------------------------------------------
// Funci�: realizar_movimiento()
// Determina a qu�jugador le toca mover y realiza el movimiento alterando el tablero
// y el estado del juego (si procede)
// ---------------------------------------------------------------------------------------
void realizar_movimiento(Tcasilla tablero[9][9], Testado* estado);

// ---------------------------------------------------------------------------------------
// Funci�: movimiento_humano()
// Gestiona el movimiento de una pieza por parte de un jugador humano
// ---------------------------------------------------------------------------------------
void movimiento_humano(Tcasilla tablero[9][9], Testado* estado);

// ---------------------------------------------------------------------------------------
// Funci�: movimiento_maquina()
// Gestiona el movimiento de una pieza por parte de un jugador m�uina
// ---------------------------------------------------------------------------------------
void movimiento_maquina(Tcasilla tablero[9][9], Testado* estado);

// ---------------------------------------------------------------------------------------
// Funci�: elegir_origen()
// Elegir la casilla de origen de la pieza que se va a mover.
// Devuelve las coordenadas de la casilla en (x,y)
// Devuelve 0 si las coordenadas son legales, -1 si no lo son y -2 si se ha pulsado ESC
// ---------------------------------------------------------------------------------------
int elegir_origen(int* x, int* y, Tcasilla tablero[9][9], Testado* estado);

// ---------------------------------------------------------------------------------------
// Funci�: elegir_destino()
// Selecciona la casilla de destino de un movimiento. Devuelve la casilla en (x,y)
// Devuelve 0 si las coordenadas son legales, -1 si no lo son y -2 si se ha pulsado ESC
// ---------------------------------------------------------------------------------------
int elegir_destino(int* x, int* y, int x_orig, int y_orig, Tcasilla tablero[9][9], Testado* estado);

// ---------------------------------------------------------------------------------------
// Funci�: comprobar_origen()
// Comprueba que la pieza que se pretende mover efectivamente SE PUEDE mover. Devuelve
// VERDADERO o FALSO, segn pueda o no pueda moverse.
// ---------------------------------------------------------------------------------------
int comprobar_origen(int x, int y, Tcasilla tablero[9][9], Testado* estado);

// ---------------------------------------------------------------------------------------
// Funci�: comprobar_destino()
// Comprueba que el lugar de destino de la pieza que se pretende mover es correcto. Devuelve
// VERDADERO o FALSO, segn pueda o no pueda moverse.
// ---------------------------------------------------------------------------------------
int comprobar_destino(int x, int y, int x_orig, int y_orig, Tcasilla tablero[9][9], Testado* estado);

// ---------------------------------------------------------------------------------------
// Funci�: actualizar_tablero()
// Hace efectivo un movimiento de piezas actualizando las casillas del tablero.
// Tambi� modifica el estado (si procede)
// ---------------------------------------------------------------------------------------
void actualizar_tablero(int x_orig, int y_orig, int x_dest, int y_dest, Tcasilla tablero[9][9], Testado* estado);

// ---------------------------------------------------------------------------------------
// Funci�: anotar_movimiento()
// Traduce el movimiento a notaci� algebraica y lo guarda en la lista din�ica
// de movimientos realizados
// ---------------------------------------------------------------------------------------
void anotar_movimiento(int col_orig, int fila_orig, int col_dest, int fila_dest, Tcasilla tablero[9][9], Testado* estado);

// ---------------------------------------------------------------------------------------
// Funci�: convertir_a_letra()
// Convierte un nmero de columna en su letra equivalente
// ---------------------------------------------------------------------------------------
char convertir_a_letra(int num);

// ---------------------------------------------------------------------------------------
// Funci�: convertir_a_numero()
// Convierte un identificador de columna en su nmero equivalente
// ---------------------------------------------------------------------------------------
int convertir_a_numero(char letra);

// ---------------------------------------------------------------------------------------
// Funci�: mostrar_movimientos()
// Muestra la lista de los ltimos movimientos realizados
// ---------------------------------------------------------------------------------------
void mostrar_movimientos(Testado* estado);

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

// ---------------------------------------------------------------------------------------
// Funci�: comprobar_jaque()
// Comprueba si el rey del jugador que tiene el turno est�en situaci� de jaque
// Devuelve 1 si lo est�y 0 si no lo est�// ---------------------------------------------------------------------------------------
int comprobar_jaque(Tcasilla tablero[9][9], Testado* estado);

// ---------------------------------------------------------------------------------------
// Funci�: comprobar_jaque_mate()
// Comprueba si el rey del jugador que tiene el turno está�en situación de JAQUE MATE
// Devuelve VERDADERO si lo está y FALSO si no lo está ---------------------------------------------------------------------------------------
int comprobar_jaque_mate(Tcasilla tablero[9][9], Testado* estado);

// ---------------------------------------------------------------------------------------
// Funciones: actualizar_tiempo()
// Controla el funcionamiento de los relojes
// ---------------------------------------------------------------------------------------
void actualizar_tiempo(Testado* estado);

// ---------------------------------------------------------------------------------------
// Reproduce la partida desde el principio. El tablero deber� estar en su posici� inicial.
// Se recorre la lista de movimientos, reproduci�dolos en el tablero con una pausa entre ellos.
// ---------------------------------------------------------------------------------------
void reproducir_partida(Tcasilla tablero[9][9], Testado* estado, int pausa);
