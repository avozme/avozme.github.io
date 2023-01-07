#include "ajedrez.h"
#include "e_s.h"
#include "movimiento.h"

int main (void)
{
	struct s_casilla tablero [9][9];
	struct s_estado estado;
	int x,y,yo,xo,comp,xp,yp,salir,repetir;
	xp=2;
	salir = 0;
	yp=23;
	inicializar_tablero(tablero);
	inicializar_estado(&estado);
	presentacion();
	getch();
	while (salir==0)
	{
		borrar_pantalla();
		pintar_pantalla(tablero,estado);
		//pintar_ventana(estado);
		do {
			tirada_origen (&xo,&yo,tablero,&estado);
			if ((xo==0)&&(yo==0))
				comp =lanzar_menu(tablero, &estado, &salir);
			else
				comp = comprobar_origen(xo,yo,tablero,estado);
		}
		while (comp == 0);
		if (salir == 0)
		{
			do {
			   	tirada_destino (&x,&y,tablero,&estado);
				if ((x==0)&&(y==0))
					comp =lanzar_menu(tablero, &estado, &salir);
				else
			   		comp = comprobar (x,y,xo,yo,tablero,&estado,&repetir);
			}
			while (comp == 0);
			if ((salir == 0)&&(repetir==1))
			{
				mover (x,y,xo,yo, tablero);
				if (estado.turno == BLANCAS) //CONTORLAR K EL MOVIMIENTO SEA CORRECTO
					estado.turno=NEGRAS;
				else
				{
					estado.cont++;
					estado.turno=BLANCAS;
				}
			}
		}
	}
	//getch();
	endwin();
	return 0;
}

/*//////////////////////////////////////////////////////*/
/*////// Inicializar las piezas del tablero ////////////*/
/*///////////////////////////////////////////////////////*/

int inicializar_tablero(struct s_casilla tablero[9][9])
{
	int i,j;
	char col;
	for (i=1; i<=8; i++)
  	   for (j=1; j<=8; j++)
	      tablero[i][j].pieza = ' ';
	
	tablero[1][1].pieza= TORRE;
	tablero[2][1].pieza= CABALLO;
	tablero[3][1].pieza= ALFIL;
	tablero[4][1].pieza= REINA;
	tablero[5][1].pieza= REY;
	tablero[6][1].pieza= ALFIL;
	tablero[7][1].pieza= CABALLO;
	tablero[8][1].pieza= TORRE;
	tablero[1][8].pieza= TORRE;
	tablero[2][8].pieza= CABALLO;
	tablero[3][8].pieza= ALFIL;
	tablero[4][8].pieza= REINA;
	tablero[5][8].pieza= REY;
	tablero[6][8].pieza= ALFIL;
	tablero[7][8].pieza= CABALLO;
	tablero[8][8].pieza= TORRE;
	
	for(i=1;i<=8;i++)
	{
		tablero[i][2].pieza= PEON;
		tablero[i][8].color_pieza= BLANCAS;
		tablero[i][7].color_pieza= BLANCAS;
		tablero[i][7].pieza= PEON;
		tablero[i][1].color_pieza= NEGRAS;
		tablero[i][2].color_pieza= NEGRAS;
	}
	for (i=1;i<=8;i++)
	{
		tablero[0][i].pieza=64+i;
		tablero[i][0].pieza=(57-i);
	}
	col=BLANCAS;
	for(j=0; j<9; j++){
		for(i=0; i<9; i++){
			if(col==BLANCAS){
				tablero[i][j].color_casilla=BLANCAS;
				col=NEGRAS;
			}
			else 
			{
				tablero[i][j].color_casilla=NEGRAS;
				col=BLANCAS;
			}
		}
	}
        return 0;
}

/*//////////////////////////////////////////*/
/*////// Inicializar el estado ////////////*/
/*////////////////////////////////////////*/

void inicializar_estado (struct s_estado *estado)
{
	estado->turno = BLANCAS;
	estado->cont =1;
	estado->jaque_al_blanco='N';
	estado->jaque_al_negro='N';
	estado->xp = 2;
	estado->yp = 23;
}

void retardo(int tiempo)
{
int i;
	for(i=0; i<10000000*tiempo; i++)
	{ ;
	}
}
