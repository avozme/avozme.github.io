#ifndef _TIPOS_H
#define _TIPOS_H
#endif

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <curses.h>

void finalizar_interfaz()
{
  endwin();	// En LINUX llamamos a la funci� de librer� de Ncurses
  exit(0);
}


int inicializar_interfaz()
{
  initscr();			                    // Inicializar Ncurses
  signal(SIGINT, finalizar_interfaz);	// Si hay CTRL-C o similar, se llama a finalizar_interfaz()
  keypad(stdscr, 1);		              // Activamos recepción de teclas especiales, como flechas del cursor
  nodelay(stdscr, 1);	                // No esperar a que se pulse una tecla
  if (has_colors()) start_color();
  init_pair(1, COLOR_GREEN, COLOR_GREEN);
  init_pair(2, COLOR_WHITE, COLOR_GREEN);
  bkgd(COLOR_PAIR(1));	              // Establecemos color de fondo
  attron(COLOR_PAIR(2));
  attron(A_BOLD);		                  // Activa negrita para que los caracteres se lean mejor
}

void dibujar_contorno(int max_x, int max_y) {
  int i;
  for (i = 0; i < max_x; i++) {
    move(0, i);
    printw("*");
    move(max_y, i);
    printw("*");
  }
  for (i = 0; i < max_y; i++) {
    move(i, 0);
    printw("*");
    move(i, max_x);
    printw("*");
  }
  refresh();
}


int main(void) {
  int max_x = 40, max_y = 20;     // Dimensiones de la ventana
  int x = max_x/2, y = max_y/2;   // Coordenadas iniciales de la pelota
  int ax = x, ay = y;             // Coordenadas anteriores de la pelota
  int dx = 1, dy = 1;             // Dirección de la pelota
  inicializar_interfaz();
  dibujar_contorno(max_x, max_y);

  // Bucle principal (movimiento de la pelota)
  do {
      move(ay, ax);   // Borramos la pelota de la posición anterior
      printw(" ");
      move(y, x);     // Dibujamos la pelota en la nueva posición
      printw("O");
      refresh();      // Actualizamos la pantalla
      usleep(100000); // Esperamos un poco (100.000 microsegundos = 0,1 segundos)
      ax = x;         // Guardamos las coordenadas anteriores
      ay = y;
      x += dx;        // Calculamos las nuevas coordenadas
      y += dy;
      // Comprobamos si la pelota ha chocado con el borde
      if (x == 1 || x == max_x - 1) dx = -dx;
      if (y == 1 || y == max_y - 1) dy = -dy;
  } while (getch() != 27);   // Repetimos mientras no se pulse ESCAPE

  finalizar_interfaz();
}
