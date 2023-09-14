/*
PROGRAMA:  Ajedrez 1.0
ARCHIVO:   ajedrez.c
CONTENIDO: Función main()
AUTOR:     Alfredo Moreno
*/

#include "tipos.h"
#include "io.h"
#include "ini_fin.h"
#include "movs.h"

int main(int argc, char *argv[])
{
  Tcasilla tablero[9][9];	// Tablero de juego
  Testado estado;		// Estado del juego

  inicializar_interfaz();
  valores_iniciales(tablero, &estado);
  elegir_jugadores(&estado);
  refrescar_pantalla(tablero);
  do
  {
    realizar_movimiento(tablero, &estado);
    refrescar_pantalla(tablero);
    estado.movimientos++;
    if (estado.turno == BLANCAS) estado.turno = NEGRAS; else estado.turno = BLANCAS;
  }
  while (estado.terminar == FALSO);
  terminar(&estado);
  finalizar_interfaz();
  return 0;
}
    
