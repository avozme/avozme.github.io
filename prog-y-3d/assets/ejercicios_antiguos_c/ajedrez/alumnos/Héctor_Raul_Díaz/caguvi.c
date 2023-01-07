#include <string.h>
#include <stdlib.h>
#include <menu.h>

#include "ajedrez.h"
#include "caguvi.h"
#include "movimientos.h"

void cargar(struct s_casilla tablero[9][9], struct s_mov **moves)
{
	struct s_mov *nuevo;
	struct s_movs mueve;
	struct s_estado estado;
	
	int columna, fila, columnd, filad, i, j;
	
	char archivo[50];
	int n;
	WINDOW	*win3;
	FILE *f;
	echo();
	
	attron(COLOR_PAIR(1));
	win3=subwin(stdscr, 5, 40, 10, 10);
	keypad(win3, TRUE);
	box(win3, 0, 0);
	poner_en_medio(win3, 1, 0, 40, "           Cargar partida:            ", COLOR_PAIR(1));
	mvwaddch(win3, 2, 0, ACS_LTEE);
	mvwhline(win3, 2, 1, ACS_HLINE, 38);
	mvwaddch(win3, 2, 39, ACS_RTEE);
	wrefresh(win3);
	move(13,11);
	printw(" Archivo:\\                            ");
	move(13,21);
	scanw("%s", archivo);
	
	f=fopen(archivo, "rb");
	if(f==NULL)
	{
		move(13,11);
		printw("    ERROR, al abrir el archivo.    ");
		getch();
		menu(tablero, estado, *moves);
	}
	n=fread(&estado, sizeof(struct s_estado), 1, f);
	n=fread(tablero, sizeof(struct s_casilla), 81, f);
	
	while(!feof(f))
	{
		init(moves);
		n=fread(&mueve, sizeof(struct s_movs), 1, f);
		if(n>0)
		{
			nuevo=(struct s_mov*)malloc(sizeof(struct s_mov));
			nuevo->movimiento=mueve;
			nuevo->siguiente=*moves;
			*moves=nuevo;
		}
	}			
	fclose(f);
	move(13, 11);
	printw("    Archivo cargado con exito.    ");
	getch();
	endwin();
	pintar_tablero();
	pintar_fichas(tablero);
	if((estado.tipo_jug_n=='O')&&(estado.turno==NEGRO))	//Dependiendo del turno y tipo de jugador2 llamamos a una u otra función.
		jugar_o(tablero, estado, *moves);
	else
		jugar_h(tablero, estado, *moves);
}

void guardar(struct s_casilla tablero[9][9], struct s_estado estado, struct s_mov *moves)
{
	struct s_mov *mov;
	char archivo[50];
	int n;
	WINDOW	*win4;
	FILE *f;
	echo();
	
	attron(COLOR_PAIR(1));
	win4=subwin(stdscr, 5, 40, 10, 10);
	keypad(win4, TRUE);
	box(win4, 0, 0);
	poner_en_medio(win4, 1, 0, 40, "          Guardar partida:            ", COLOR_PAIR(1));
	mvwaddch(win4, 2, 0, ACS_LTEE);
	mvwhline(win4, 2, 1, ACS_HLINE, 38);
	mvwaddch(win4, 2, 39, ACS_RTEE);
	wrefresh(win4);
	move(13,11);
	printw(" Archivo:\\                           ");
	move(13,21);
	scanw("%s", archivo);
	f=fopen(archivo, "wb");
	if(f==NULL)
	{
		move(13,11);
		printw("    ERROR, al abrir el archivo     ");
		getch();
		menu(tablero, estado, moves);
	}
	n=fwrite(&estado, sizeof(struct s_estado), 1, f);
	n=fwrite(tablero, sizeof(struct s_casilla), 81, f);
	
	mov=moves;
	while(mov!=NULL)
	{	
		n=fwrite(mov, sizeof(struct s_movs), 1, f);
		mov=mov->siguiente;		
	}	
	endwin();
	pintar_tablero();
	pintar_fichas(tablero);
	jugar_h(tablero, estado, moves);	
	
}

void visualizar(struct s_casilla tablero[9][9], struct s_estado estado, struct s_mov *moves)
{
	struct s_casilla tab[9][9];
	struct s_movs mueve;
	struct s_estado esta;
	char archivo[50];
	int n, fila , columna, filad, columnd;
	long int i, j;
	WINDOW	*win5;
	FILE *f;
	echo();
	
	attron(COLOR_PAIR(1));
	win5=subwin(stdscr, 5, 40, 10, 10);
	keypad(win5, TRUE);
	box(win5, 0, 0);
	poner_en_medio(win5, 1, 0, 40, "         Visualizar partida:          ", COLOR_PAIR(1));
	mvwaddch(win5, 2, 0, ACS_LTEE);
	mvwhline(win5, 2, 1, ACS_HLINE, 38);
	mvwaddch(win5, 2, 39, ACS_RTEE);
	wrefresh(win5);
	move(13,11);
	printw(" Archivo:\\                            ");
	move(13,21);
	scanw("%s", archivo);
	f=fopen(archivo, "r+b");
	if(f==NULL)
	{
		move(13,11);
		printw("    ERROR, al abrir el archivo.    ");
		getch();
		menu(tablero, estado, moves);
	}
	n=fread(&estado, sizeof(struct s_estado), 1, f);
	n=fread(&tab, sizeof(struct s_casilla), 81, f);
	inicializar_tablero(tablero, estado);
	pintar_tablero();
	endwin();
	//init(mueve);
	while(!feof(f))
	{	
		n=fread(&mueve, sizeof(struct s_movs), 1, f);
		columna=mueve.x;
		fila=mueve.y;
		columnd=mueve.xd;
		filad=mueve.yd;
		mover_pieza(columna, fila, columnd, filad, tablero, estado, &moves);
		//pausa(10000);
	}
	if((estado.tipo_jug_n=='O')&&(estado.turno==NEGRO))	//Dependiendo del turno y tipo de jugador2 llamamos a una u otra función.
		jugar_o(tablero, estado, moves);
	else
		jugar_h(tablero, estado, moves);
}
