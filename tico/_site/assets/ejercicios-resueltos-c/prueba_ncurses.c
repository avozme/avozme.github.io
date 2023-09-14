#include <ncurses.h>
#include <stdlib.h>
int main(void)
{
  char caracter;
  initscr();         // Inicializa Ncurses
  keypad(stdscr, 1); // Activa teclas especiales (como las flechas)
  cbreak();          // Para no tener que pulsar Intro tras cada carácter 
  noecho();         // Para no ver los caracteres que se van tecleando
  nodelay(stdscr, 1); // Para que getch() no espere a que se pulse una tecla
  if (has_colors()) start_color();         // Inicializa colores
  init_pair(1, COLOR_RED, COLOR_BLUE);     // Pareja 1 = Texto rojo, fondo azul
  init_pair(2, COLOR_YELLOW, COLOR_GREEN); // Pareja 2 = Texto amarillo, fondo verde
  init_pair(3, COLOR_WHITE, COLOR_BLACK);  // Pareja 3 = Texto blanco, fondo negro
  attron(COLOR_PAIR(1));    // Activa pareja 1
  int f = 1, direccion = 1;
  move(f, 50);
  printw("HOLA");
  attron(COLOR_PAIR(2));    // Activa pareja 2
  move(12, 1);
  printw("MUNDO");
  do {
    caracter = getch();  // Lee un carácter desde el teclado
    move(f, 50);
    attron(COLOR_PAIR(3));    // Activa pareja 1
    printw("     ");

    if (direccion == 1) { // Vamos hacia abajo
      f = f + 1;
      if (f == 23) direccion = -1;
    }
    if (direccion == -1) { // Vamos hacia arriba
      f = f - 1;
      if (f == 1) direccion = 1;
    }

    move(f, 50);
    attron(COLOR_PAIR(1));    // Activa pareja 1
    printw("HOLA");
    napms(50); // Espera 200 milisegundos
  }
  while (caracter != 'x'); // Repite hasta que se pulse 'x'
  endwin();  // Finaliza Ncurses
  return 0;
}