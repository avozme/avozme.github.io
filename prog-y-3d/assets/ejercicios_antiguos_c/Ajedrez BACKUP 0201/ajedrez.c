/*
PROGRAMA:  Ajedrez 1.0
ARCHIVO:   ajedrez.c
CONTENIDO: Función main()
AUTOR:     Alfredo Moreno
*/

#include "tipos.h"

int main()
{
  Tcasilla tablero[9][9];	// Tablero de juego
  Testado estado;		// Estado del juego
  char jug_blanco;		// HUMANO o MAQUINA
  char jug_negro;		// HUMANO o MAQUINA

  inicializar_interfaz();
  valores_iniciales(tablero, &estado);
  elegir_jugadores(&jug_blanco, &jug_negro);
  refrescar_pantalla(tablero);
  do
  {
    realizar_movimiento(tablero, &estado, jug_blanco, jug_negro);
    refrescar_pantalla(tablero);
    estado.movimientos++;
    if (estado.turno == BLANCAS) estado.turno = NEGRAS; else estado.turno = BLANCAS;
  }
  while (estado.terminar == FALSO);
  terminar(estado);
  finalizar_interfaz();
  return 0;
}
    
