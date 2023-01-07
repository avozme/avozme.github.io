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
//#define TXT_LINUX
//#define GRAF_WIN
#define GRAF_LINUX


// ---------------------------------------------------------------------------------------
// Archivos de cabecera generales de la aplicación
// ---------------------------------------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>

#ifdef TXT_DOS		// Archivos de cabecera para el modo texto de MS-DOS
#include <conio.h>
#include <dos.h>
#endif

#ifdef TXT_LINUX	// Archivos de cabecera para el modo texto de LINUX
#include <curses.h>
#endif

#ifdef GRAF_LINUX	// Archivos de cabecera para el modo gráfico de LINUX
#include <SDL/SDL.h>
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
  int terminar;			// Centinela para terminar el juego
  int jaque_al_rey_negro;
  int jaque_al_rey_blanco;
  int enroque_blanco_realizado;
  int enroque_negro_realizado;
  int torre_blanca_movida, torre_negra_movida;
  int rey_blanco_movido, rey_negro_movido;
  int movimientos;		// Contador de movimientos
  char turno;			// BLANCAS o NEGRAS
}
Testado;

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

