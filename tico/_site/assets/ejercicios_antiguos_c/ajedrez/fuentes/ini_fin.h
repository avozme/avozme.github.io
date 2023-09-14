/*
PROGRAMA:  Ajedrez 1.0
ARCHIVO:   ini_fin.h
CONTENIDO: Archivo de cabecera de las funciones de inicializaci�n y finalizaci�n
AUTOR:     Alfredo Moreno
*/

#include "tipos.h"
#include "lista.h"

// Establece los valores iniciales del tablero y del estado del juego
void valores_iniciales(Tcasilla tablero[9][9], Testado* estado);

// Selecci�n de los jugadores
void elegir_jugadores(Testado* estado);

// Liberaci�n de memoria y mensajes de despedida
void terminar(Testado* estado);
