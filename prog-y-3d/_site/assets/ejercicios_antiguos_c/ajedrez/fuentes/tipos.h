/*
PROGRAMA:  Ajedrez 1.0
ARCHIVO:   tipos.h
CONTENIDO: Definición de constantes y tipos de datos generales del juego
AUTOR:     Alfredo Moreno
*/

#ifndef _TIPOS_H
#define _TIPOS_H


// ---------------------------------------------------------------------------------------
// Tipo de sistema: *** IMPORTANTE *** Descomentar la línea que proceda antes de compilar
// ---------------------------------------------------------------------------------------
//#define TXT_DOS
#define TXT_LINUX
//#define GRAF_WIN
//#define GRAF_LINUX


// ---------------------------------------------------------------------------------------
// Archivos de cabecera generales de la aplicación
// ---------------------------------------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#ifdef TXT_DOS		// Archivos de cabecera para el modo texto de MS-DOS
#include <conio.h>
#include <dos.h>
#endif

#ifdef TXT_LINUX	// Archivos de cabecera para el modo texto de LINUX
#include <curses.h>
#endif

#ifdef GRAF_LINUX	// Archivos de cabecera para el modo gráfico de LINUX
#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>
#endif

// ---------------------------------------------------------------------------------------
// Definición de tipos
// ---------------------------------------------------------------------------------------
typedef struct			// Casilla (escaque) del tablero
{
  char pieza;			// Pieza situada en esta casilla
  char color_pieza;		// Color de la pieza
  char color_casilla;		// Color de la casilla
}
Tcasilla;

typedef struct			// Estado del juego
{
  char jug_blanco;		// HUMANO o MAQUINA
  char jug_negro;		// HUMANO o MAQUINA
  int terminar;			// Centinela para terminar el juego
  int jaque_al_rey_negro;
  int jaque_al_rey_blanco;
  int enroque_blanco_realizado;
  int enroque_negro_realizado;
  int rey_blanco_movido, rey_negro_movido;
  int torre_blanca_a_movida, torre_blanca_h_movida;
  int torre_negra_a_movida, torre_negra_h_movida;
  int movimientos;		// Contador de movimientos
  char turno;			// BLANCAS o NEGRAS
  time_t t_blancas;     // Reloj de las blancas (en segundos)
  time_t t_negras;      // Reloj de las negras (en segundos)
  time_t t_turno;       // Reloj auxiliar (instante en el que empieza el turno actual)
  time_t t_anterior;    // Reloj auxiliar (instante de la última medición de tiempo)
}
Testado;

typedef struct			// Movimiento calculado por las rutinas de I.A.
{
  int valoracion;		// Valoración final del estado al que conduce en última instancia
  int x_orig, y_orig;		// Casilla origen del movimiento
  int x_dest, y_dest;		// Casilla final del movimiento
}
Tmovimiento;
// ---------------------------------------------------------------------------------------
// Definición de constantes
// ---------------------------------------------------------------------------------------
#define PEON 'P'	// Figuras
#define CABALLO 'C'
#define ALFIL 'A'
#define TORRE 'T'
#define DAMA 'D'
#define REY 'R'
#define NINGUNA '0'

#define BLANCO 'B'	// Colores de las piezas
#define NEGRO 'N'
#define NINGUNO '0'

#define BLANCAS 'B'	// Jugadores
#define NEGRAS 'N'

#define HUMANO 'H'	// Tipos de jugadores
#define MAQUINA 'M'

#define ENTERO 'E'	// Tipos de entrada
#define CADENA 'S'
#define CARACTER 'C'

#define VERDADERO 1
#define FALSO 0

#endif

