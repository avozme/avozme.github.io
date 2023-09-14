#include<ncurses.h>
#include "tablero_en_curso2.h"
#include "tirada_humano.h"
#include "tirada.h"



int tirada(struct s_casilla tablero[9][9])
{
	int n,cont=0;
	int y,x,xo,yo;
	char turno='B';

do
	{
	if(turno=='B')
		{
			move(1,65);
			attron(COLOR_PAIR(1));
			printw("TURNO de las BLANCAS");
			turno='N';
		}
	else
		{
			move(1,65);
			attron(COLOR_PAIR(2));
			printw("TURNO de  las NEGRAS");
			turno='B';
		}
	tirada_humano(tablero,xo,yo,x,y,turno);
	}
	while(cont!=10);
return 0;
}


int cambiar_columna(char c)
{
	int y;
				// Esta funcion cambia el caracter de las columnas por numeros
switch (c)
	{
	case 'a':
		{
		y=1;
		break;
		}
	case 'b':
		{
		y=2;
		break;
		}
	case 'c':
		{
		y=3;
		break;
		}
	case 'd':
		{
		y=4;
		break;
		}
	case 'e':
		{
		y=5;
		break;
		}
	case 'f':
		{
		y=6;
		break;
		}
	case 'g':
		{
		y=7;
		break;
		}
	case 'h':
		{
		y=8;
		break;
		}
	}
return(y);
}

int cambiar_filas(int c)
{
	int x;

switch (c)			//Esta funcion cambia el orden de la matriz para su gestion.
	{
	case '1':
		{
		x=8;
		break;
		}
	case '2':
		{
		x=7;
		break;
		}
	case '3':
		{
		x=6;
		break;
		}
	case '4':
		{
		x=5;
		break;
		}
	case '5':
		{
		x=4;
		break;
		}
	case '6':
		{
		x=3;
		break;
		}
	case '7':
		{
		x=2;
		break;
		}
	case '8':
		{
		x=1;
		break;
		}
	}
return(x);
}


