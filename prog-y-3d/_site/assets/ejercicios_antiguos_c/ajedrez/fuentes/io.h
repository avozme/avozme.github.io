/*
PROGRAMA:  Ajedrez 1.0
ARCHIVO:   io.h
CONTENIDO: Cabecera de las funciones de entrada/salida en modo texto
AUTOR:     Alfredo Moreno
*/

#ifndef _IO_H
#define _IO_H

#include <signal.h>
#include <string.h>
#include "tipos.h"
#include "movs.h"
#include "menu.h"
#ifdef GRAF_LINUX
#include "bitmaps.h"
#endif


#define TXT_NORMAL 0        // Atributos del texto
#define TXT_RESALTADO 1
#define TXT_INVERSO 2

#define ESCAPE -2           // Códigos de teclas especiales
#define FLECHA_ARRIBA -3
#define FLECHA_ABAJO -4
#define FLECHA_IZQUIERDA -5
#define FLECHA_DERECHA -6
#define RETURN -7

// Funciï¿½: inicializar_interfaz()
// Inicializa el interfaz. Debe invocarse antes que cualquier otra
// funciï¿½ del interfaz
int inicializar_interfaz();

// Funciï¿½: finalizar_interfaz()
// Finaliza el interfaz. Debe invocarse antes de finalizar el programa.
void finalizar_interfaz();

// Funciï¿½: refrescar_pantalla()
// Dibuja en la pantalla el estado actual del tablero
void refrescar_pantalla(Tcasilla tablero[9][9]);

// Funciï¿½: dibujar_casilla()
// Dibuja un escaque del tablero con la figura que contiene
void dibujar_casilla(int x, int y, char tipo, char color_pieza, char color_casilla);

// Funciï¿½: seleccionar_casilla()
// Permite seleccionar una casilla del tablero usando las teclas del cursor. Devuelve
// las coordenadas de la casilla seleccionada en (col,fila). Serï¿½ (0,0) si se pulsa ESC
// (x_orig, y_orig) son coordenadas de origen, si es que ya se eligieron. Si no, serï¿½ (0,0)
void seleccionar_casilla(int* col, int* fila, int x_orig, int y_orig, Tcasilla tablero[9][9], Testado* estado);

// Funciï¿½: escribir()
// Escribe una cadena en el lugar de la pantalla destinado a mensajes al usuario
void escribir(char* texto, int fila, int atrib);

// Funciï¿½: leer()
// Lee una cadena en el lugar de la pantalla destinado a mensajes al usuario
void leer(char* texto, int fila);

// Función: leer_tecla()
// Lee el teclado y devuelve el código de la primera tecla pulsada
int leer_tecla(void);

// Funciï¿½: borrar()
// Limpia una lï¿½ea de la zona de la pantalla dedicada a mensajes al usuario.
// Si fila = 0 limpia toda la zona.
void borrar(int fila);

// Funciï¿½: pausa()
// Detiene la ejecución durante los milisegundos indicados
void pausa(int ms);


// ---------------------------------------------------------------------------------------
// MODO TEXTO LINUX
// ---------------------------------------------------------------------------------------
// En modo texto de Linux hay que definir los pares de colores para la librerï¿½ Ncurses
#ifdef TXT_LINUX
#define C_NEG_BLA 1	// Pieza negra sobre casilla blanca
#define C_NEG_NEG 2	// Pieza negra sobre casilla negra
#define C_BLA_BLA 3	// Pieza blanca sobre casilla blanca
#define C_BLA_NEG 4	// Pieza blanca sobre casilla negra
#define C_TXT 5		// Texto
#define C_SEL 6		// Selección
#define C_INV 7		// Texto inverso
#define C_RES 8		// Texto resaltado
#endif



// ---------------------------------------------------------------------------------------
// MODO GRï¿½ICO LINUX
// ---------------------------------------------------------------------------------------

// En modo grï¿½ico de Linux utilizaremos una variable global para acceder a la pantalla grï¿½ica virtual
// y otra para acceder a los pï¿½eles
#ifdef GRAF_LINUX
#define TAM_PANT_X 667		// Tamaï¿½ de la pantalla de juego en pï¿½els
#define TAM_PANT_Y 500
#define TAM_CASILLA 55		// Tamaï¿½ en pï¿½els de cada escaque (casilla) del tablero
#define DESPLZ_ORIG_X 33	// Desplazamiento en X del primer escaque desde el origen (0,0)
#define DESPLZ_ORIG_Y 35	// Desplazamiento en Y del primer escaque desde el origen (0,0)
#define ANCHO_TXT 150		// Anchura (en X) del Ã¡rea de texto a la derecha de la pantalla
#define DESPLZ_ORIG_TXT 80	// Desplazamiento el comienzo del texto en Y
#define ALTO_TXT 20		// Altura (Y) de cada lÃ­nea de texto


// Funciï¿½: cargar_imagenes()
// Carga las imï¿½enes BMP del juego en las diferentes superficies
void cargar_imagenes();
// Funciï¿½: error_imagen()
// Gestiona los errores durante la carga de las imï¿½enes
void error_imagen(char* archivo);

// Macro: DIBUJAR_PIXEL()
// Dibuja un punto de color en la pantalla grï¿½ica
#define DIBUJAR_PIXEL(px,py,color) posicion = scr->pixels + py * scr->pitch + px * scr->format->BytesPerPixel; *posicion = color;

#endif

#endif
