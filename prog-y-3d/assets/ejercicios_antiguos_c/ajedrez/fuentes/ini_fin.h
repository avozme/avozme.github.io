/*
PROGRAMA:  Ajedrez 1.0
ARCHIVO:   ini_fin.h
CONTENIDO: Archivo de cabecera de las funciones de inicialización y finalización
AUTOR:     Alfredo Moreno
*/

#include "tipos.h"
#include "lista.h"

// Establece los valores iniciales del tablero y del estado del juego
void valores_iniciales(Tcasilla tablero[9][9], Testado* estado);

// Selección de los jugadores
void elegir_jugadores(Testado* estado);

// Liberación de memoria y mensajes de despedida
void terminar(Testado* estado);
