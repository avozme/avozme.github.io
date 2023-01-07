/*
PROGRAMA:  Ajedrez 1.0
ARCHIVO:   io.h
CONTENIDO: Cabecera de las funciones de entrada/salida en modo texto
AUTOR:     Alfredo Moreno
*/

#include <signal.h>
#include "tipos.h"
#ifdef GRAF_LINUX
#include "bitmaps.h"
#endif


// Función: inicializar_interfaz()
// Inicializa el interfaz. Debe invocarse antes que cualquier otra
// función del interfaz
int inicializar_interfaz();

// Función: finalizar_interfaz()
// Finaliza el interfaz. Debe invocarse antes de finalizar el programa.
void finalizar_interfaz();

// Función: refrescar_pantalla()
// Dibuja en la pantalla el estado actual del tablero
void refrescar_pantalla(Tcasilla tablero[9][9]);

// Función: dibujar_casilla()
// Dibuja un escaque del tablero con la figura que contiene
void dibujar_casilla(int x, int y, char tipo, char color_pieza, char color_casilla);

// Función: seleccionar_casilla()
// Permite seleccionar una casilla del tablero usando las teclas del cursor. Devuelve
// las coordenadas de la casilla seleccionada en (col,fila). Serán (0,0) si se pulsa ESC
// (x_orig, y_orig) son coordenadas de origen, si es que ya se eligieron. Si no, serán (0,0)
void seleccionar_casilla(int* col, int* fila, int x_orig, int y_orig, Tcasilla tablero[9][9]);

// Función: escribir()
// Escribe una cadena en el lugar de la pantalla destinado a mensajes al usuario
void escribir(char* texto, int fila);

// Función: leer()
// Lee una cadena en el lugar de la pantalla destinado a mensajes al usuario
void leer(char* texto, int fila);

// Función: borrar()
// Limpia una línea de la zona de la pantalla dedicada a mensajes al usuario.
// Si fila = 0 limpia toda la zona.
void borrar(int fila);


// ---------------------------------------------------------------------------------------
// MODO TEXTO LINUX
// ---------------------------------------------------------------------------------------
// En modo texto de Linux hay que definir los pares de colores para la librería Ncurses
#ifdef TXT_LINUX
#define C_NEG_BLA 1	// Pieza negra sobre casilla blanca
#define C_NEG_NEG 2	// Pieza negra sobre casilla negra
#define C_BLA_BLA 3	// Pieza blanca sobre casilla blanca
#define C_BLA_NEG 4	// Pieza blanca sobre casilla negra
#define C_TXT 5		// Texto
#define C_SEL 6		// Selección
#endif



// ---------------------------------------------------------------------------------------
// MODO GRÁFICO LINUX
// ---------------------------------------------------------------------------------------

// En modo gráfico de Linux utilizaremos una variable global para acceder a la pantalla gráfica virtual
// y otra para acceder a los píxeles
#ifdef GRAF_LINUX
#define TAM_PANT_X 667		// Tamaño de la pantalla de juego en píxels
#define TAM_PANT_Y 500
#define TAM_CASILLA 55		// Tamaño en píxels de cada escaque (casilla) del tablero
#define DESPLZ_ORIG_X 33	// Desplazamiento en X del primer escaque desde el origen (0,0)
#define DESPLZ_ORIG_Y 35	// Desplazamiento en Y del primer escaque desde el origen (0,0)
SDL_Surface* scr;		// Puntero a la pantalla gráfica
Uint32* posicion;		// Puntero a los píxels
SDL_Surface *fondo;		// Imagen de fondo (tablero)
SDL_Surface *cuadro1;		// Imagen del recuadro de selección de casillas
SDL_Surface *cuadro2;		// Imagen del segundo recuadro de selección de casillas
SDL_Surface *peon_bl, *peon_ne;	// Imágenes de las piezas
SDL_Surface *torre_bl, *torre_ne;
SDL_Surface *dama_bl, *dama_ne;
SDL_Surface *alfil_bl, *alfil_ne;
SDL_Surface *caballo_bl, *caballo_ne;
SDL_Surface *rey_bl, *rey_ne;

// Función: cargar_imagenes()
// Carga las imágenes BMP del juego en las diferentes superficies
void cargar_imagenes();
// Función: error_imagen()
// Gestiona los errores durante la carga de las imágenes
void error_imagen(char* archivo);

// Macro: DIBUJAR_PIXEL()
// Dibuja un punto de color en la pantalla gráfica
#define DIBUJAR_PIXEL(px,py,color) posicion = scr->pixels + py * scr->pitch + px * scr->format->BytesPerPixel; *posicion = color;

#endif
