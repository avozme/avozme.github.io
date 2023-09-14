#include <ncurses.h>
#include "tablero_en_curso2.h"
#include "tirada.h"
#include "movimientos.h"
#include "tirada_humano.h"


void tirada_humano(struct s_casilla tablero[9][9],int xo,int yo,int x,int y,char turno)
{
	char permitido;

	seleccionar_origen(tablero,&xo,&yo,turno);
	permitido=seleccionar_destino(tablero,&x,&y,xo,yo,turno);
	if (permitido=='S')
		{
		hacer_movimiento(tablero,xo,yo,x,y);
		refrescar_matriz(tablero);
		}
	else
		{
		move(15,70);
		attron(COLOR_PAIR(2));
		printw(" Movmiento ILegal ");
		}
}

void seleccionar_origen(struct s_casilla tablero[9][9],int *xo, int *yo,char turno)
{
	int cont,me;
	char n;

	move(5,65);
	attron(COLOR_PAIR(1));
	printw("Casilla ORIGEN: ");
			//SELECCIONA LA CASILLA ORIGEN

	do
	{
		if (cont>=1)
		{
			move(20,65);
			attron(COLOR_PAIR(3));		//SI TURNO!=FICHA SELECCIONADA
			printw("MOVIMIENTO ILEGAL");
		}
		move(7,65);
		printw("Fila: ");					//Pide la fila
		refresh();
		n=getch();
		*xo=cambiar_filas(n);

		attron(COLOR_PAIR(1));
		move(8,65);
		printw("Columna: ");					//Pide la columna
		refresh();
		n=getch();
		*yo=cambiar_columna(n);
		cont++;
	}
	
	while(tablero[*xo][*yo].color_ficha==turno);		//cOMPRUBA EL TURNOO

	cont=0;
	move(20,65);
	printw("                  ");


	attron(COLOR_PAIR(1));
	move(7,73);					//Muestra la fila seleccionada
	printw("%i",*xo);

	attron(COLOR_PAIR(1));
	move(8,73);						//Muestra la columna
	printw("%i",*yo);

}

char seleccionar_destino(struct s_casilla tablero[9][9],int *x,int *y,int xo,int yo,char turno)
{
	char n,permitido;


do
	{
	move(11,65);
	attron(COLOR_PAIR(1));
	printw("Casilla DESTINO: ");		//SELECCIONA LA CASILLA DE DESTINO
	move(13,65);
	printw("Fila: ");					//Pide la fila
	refresh();
	n=getch();
	*x=cambiar_filas(n);

	attron(COLOR_PAIR(1));
	move(14,65);
	printw("Columna: ");					//Pide la Columna
	refresh();
	n=getch();
	*y=cambiar_columna(n);

	attron(COLOR_PAIR(1));
	move(13,73);
	printw("%i",*x);						//Muestra la Fila Seleccionada


	attron(COLOR_PAIR(1));
	move(14,73);
	printw("%i",*y);					//Muestra la Columna Seleccionada
	}
	while(tablero[*x][*y].color_ficha==turno);

	permitido=controlar_movimientos(tablero,xo,yo,*x,*y,turno);

	return (permitido);

}

char controlar_movimientos(struct s_casilla tablero[9][9],int xo,int yo,int x,int y, char turno)
{
	char permitido;

	switch (tablero[xo][yo].figura)
		{
		case 'A':
			{
			permitido=controlar_mov_alfil(tablero,xo,yo,x,y);
			break;
			}
		case 'C':
			{
			permitido=controlar_mov_caballo(tablero,xo,yo,x,y);
			break;
			}
		case 'D':
			{
			permitido=controlar_mov_dama(tablero,xo,yo,x,y);
			break;
			}
		case 'T':
			{
			permitido=controlar_mov_torre(tablero,xo,yo,x,y);
			break;
			}
		case 'R':
			{
			permitido=controlar_mov_rey(tablero,xo,yo,x,y);
			break;
			}
		case 'P':
			{
			permitido=controlar_mov_peon(tablero,xo,yo,x,y,turno);
			break;
			}

		}
	return (permitido);
}

void hacer_movimiento(struct s_casilla tablero[9][9],int xo,int yo,int x,int y)
{
	tablero[x][y].figura=tablero[xo][yo].figura;
	tablero[x][y].color_ficha=tablero[xo][yo].color_ficha;
	tablero[xo][yo].figura=' ';
}


