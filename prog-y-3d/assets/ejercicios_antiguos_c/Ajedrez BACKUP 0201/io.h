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


// Funci�n: inicializar_interfaz()
// Inicializa el interfaz. Debe invocarse antes que cualquier otra
// funci�n del interfaz
int inicializar_interfaz();

// Funci�n: finalizar_interfaz()
// Finaliza el interfaz. Debe invocarse antes de finalizar el programa.
void finalizar_interfaz();

// Funci�n: refrescar_pantalla()
// Dibuja en la pantalla el estado actual del tablero
void refrescar_pantalla(Tcasilla tablero[9][9]);

// Funci�n: dibujar_casilla()
// Dibuja un escaque del tablero con la figura que contiene
void dibujar_casilla(int x, int y, char tipo, char color_pieza, char color_casilla);

// Funci�n: seleccionar_casilla()
// Permite seleccionar una casilla del tablero usando las teclas del cursor. Devuelve
// las coordenadas de la casilla seleccionada en (col,fila). Ser�n (0,0) si se pulsa ESC
// (x_orig, y_orig) son coordenadas de origen, si es que ya se eligieron. Si no, ser�n (0,0)
void seleccionar_casilla(int* col, int* fila, int x_orig, int y_orig, Tcasilla tablero[9][9]);

// Funci�n: escribir()
// Escribe una cadena en el lugar de la pantalla destinado a mensajes al usuario
void escribir(char* texto, int fila);

// Funci�n: leer()
// Lee una cadena en el lugar de la pantalla destinado a mensajes al usuario
void leer(char* texto, int fila);

// Funci�n: borrar()
// Limpia una l�nea de la zona de la pantalla dedicada a mensajes al usuario.
// Si fila = 0 limpia toda la zona.
void borrar(int fila);


// ---------------------------------------------------------------------------------------
// MODO TEXTO LINUX
// ---------------------------------------------------------------------------------------
// En modo texto de Linux hay que definir los pares de colores para la librer�a Ncurses
#ifdef TXT_LINUX
#define C_NEG_BLA 1	// Pieza negra sobre casilla blanca
#define C_NEG_NEG 2	// Pieza negra sobre casilla negra
#define C_BLA_BLA 3	// Pieza blanca sobre casilla blanca
#define C_BLA_NEG 4	// Pieza blanca sobre casilla negra
#define C_TXT 5		// Texto
#define C_SEL 6		// Selecci�n
#endif



// ---------------------------------------------------------------------------------------
// MODO GR�FICO LINUX
// ---------------------------------------------------------------------------------------

// En modo gr�fico de Linux utilizaremos una variable global para acceder a la pantalla gr�fica virtual
// y otra para acceder a los p�xeles
#ifdef GRAF_LINUX
#define TAM_PANT_X 667		// Tama�o de la pantalla de juego en p�xels
#define TAM_PANT_Y 500
#define TAM_CASILLA 55		// Tama�o en p�xels de cada escaque (casilla) del tablero
#define DESPLZ_ORIG_X 33	// Desplazamiento en X del primer escaque desde el origen (0,0)
#define DESPLZ_ORIG_Y 35	// Desplazamiento en Y del primer escaque desde el origen (0,0)
SDL_Surface* scr;		// Puntero a la pantalla gr�fica
Uint32* posicion;		// Puntero a los p�xels
SDL_Surface *fondo;		// Imagen de fondo (tablero)
SDL_Surface *cuadro1;		// Imagen del recuadro de selecci�n de casillas
SDL_Surface *cuadro2;		// Imagen del segundo recuadro de selecci�n de casillas
SDL_Surface *peon_bl, *peon_ne;	// Im�genes de las piezas
SDL_Surface *torre_bl, *torre_ne;
SDL_Surface *dama_bl, *dama_ne;
SDL_Surface *alfil_bl, *alfil_ne;
SDL_Surface *caballo_bl, *caballo_ne;
SDL_Surface *rey_bl, *rey_ne;

// Funci�n: cargar_imagenes()
// Carga las im�genes BMP del juego en las diferentes superficies
void cargar_imagenes();
// Funci�n: error_imagen()
// Gestiona los errores durante la carga de las im�genes
void error_imagen(char* archivo);

// Macro: DIBUJAR_PIXEL()
// Dibuja un punto de color en la pantalla gr�fica
#define DIBUJAR_PIXEL(px,py,color) posicion = scr->pixels + py * scr->pitch + px * scr->format->BytesPerPixel; *posicion = color;

#endif
