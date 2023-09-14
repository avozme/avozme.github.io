// nos traemos las cabeceras q necesitamos

#include "ajedrez.h"
#include "movs.h"

// esta es una de las funciones mas complicadas, se trata del movimiento de la pieza..

int mover_humano(struct s_casilla tablero[9][9],struct s_estado estado)
{
	int ox,oy,dx,dy,n,p,cont, t = 0;
	ox=0;oy=0;dx=0;dy=0;

	// 1 pintamos en pantalla de quien es el turno, como mera informacion

	if(estado.turno==BLANCO)
	{
		move(30,1);
		printw("TURNO_DE_LAS_BLANCAS");
	}
	else
	{
		move(30,1);
		printw("TURNO_DE_LAS_NEGRAS");
	}

	t=casilla_origen(tablero,&ox,&oy);// 2 preguntamos por la casilla origen

	if(t!=2) // si es 2, es q le ha dado a la m de menu y no entra en todo lo demas
	{
		n=comprobar_origen(tablero,estado,ox,oy); // 3 comprobamos q hay una pieza y q el color de la pieza coincida con el turno
		if (n==1) // si devuelve un 1 es correcto
		{
			t=casilla_destino(tablero,&dx,&dy); // 4 preguntamos por la casilla destino
			if(t!=2) // si es distinto de 2, se mete en el bucle pq no le ha dado a la m
			{
				p=comprobar_movimiento(tablero,estado,ox,oy,dx,dy); // aqui comprueban q el movimiento de esa pieza sea correcto
				if (p==1) // si devuelve un 1, es correcto..
					mover(tablero,ox,oy,dx,dy); //5 se mueve la pieza
				else
				{
					printw("No_se_puede_realizar_ese_movimiento"); // si no es correcto el movimiento, devuelve un 0 y da un mensaje de error y no se mueve la pieza
					t = 1; // devuelve al algoritmo principal un 1, para q tb de un mensaje de error
				}
			}
		}
		else
			t=1; // si n es distinto de 1, es q hay un error en comprobar origen
	}

	return t;

}

// esta funcion convierte la letra introducida en las columnas en un numero, para poder operar internamente

int convertir(char c)
{
	int n;

	if ((c == 'A')|| (c == 'a'))
		n = 1;
	if ((c == 'B')|| (c == 'b'))
		n = 2;
	if ((c == 'C')|| (c == 'c'))
		n = 3;
	if ((c == 'D')|| (c == 'd'))
		n = 4;
	if ((c == 'E')|| (c == 'e'))
		n = 5;
	if ((c == 'F')|| (c == 'f'))
		n = 6;
	if ((c == 'G')|| (c == 'g'))
		n = 7;
	if ((c == 'H')|| (c == 'h'))
		n = 8;

	return n;
}

// esta es la funcion por la q pregunta la casilla origen

char casilla_origen( struct s_casilla tablero[9][9],int *ox,int *oy)
{
	char c,cont=0;

	move(5,60);
	attron(COLOR_PAIR(5));
	printw("SELECCIONE_ORIGEN\n");

	do  // aqui se pide las columnas del origen
	{
		move(7,60);
		printw("Columna(A-H)\n");
		move(8,60);
		c = getch();
		if((c=='m')||(c=='M')) cont=2;
		else
			*oy=convertir(c); // aqui convierte la letra en numero
	}
	while (((*oy<=0)&&(*oy>=9)) && ((c!='m') && (c!='M')));// se repite el bulce mientras el numero no este entre 1 y 8 o sea distinto de m o M

	// aqui se pide la fila del origen
	do
	{
		move(9,60);
		printw("Fila(1-8)\n");
		move(10,60);
		c = getch();
		if((c=='m')||(c=='M')) cont=2;
		else
			*ox=c - 48; // la conversion es automatica si le restas 48 
	}
	while (((*ox<=0)&&(*ox>=9)) && ((c!='m') && (c!='M')));

	return cont;
}

// con esta funcion comprueba q hay una pieza en el origen y q el color de la pieza coincide con el color del turno, para q sea correcto el origen.

int comprobar_origen( struct s_casilla tablero[9][9], struct s_estado estado, int ox, int oy)
{
	int n;

	n=0;
	if ((tablero[ox][oy].tipo_pieza!=NINGUNA) && (estado.turno==tablero[ox][oy].color_pieza))
		n=1;

	return n;
}

// esta funcion es similar a casilla_origen. Nos pide la columna y la fila de destino

char casilla_destino(struct s_casilla tablero[9][9],int *dx,int *dy)
{
	int cont=0;
	char c;

	move(11,60);
	printw("SELECCIONE DESTINO\n");
	
	do
	{
		move(13,60);
		printw("Columna(A-H)\n");
		move(14,60);
		c = getch();
		if((c=='m')||(c=='M')) cont=2;
		else
			*dy=convertir(c);
	}
	while ((*dy<=0)&&(*dy>=9)&& (c!='m') && (c!='M'));
	
	do
	{
		move(15,60);
		printw("Fila(1-8)\n");
		move(16,60);
		c = getch();
		if((c=='m')||(c=='M')) cont=2;
		else
			*dx = c - 48;   
	}
	while((*dx<=0)&&(*dx>=9) && (c!='m') && (c!='M'));
	
	return cont;
}

// si es correcto el movimiento ( se comprueba con la funcion de comprobar movimiento, se mueve

void mover(struct s_casilla tablero[9][9],int ox,int oy,int dx,int dy)
{
	tablero[dx][dy].tipo_pieza=tablero[ox][oy].tipo_pieza;
	tablero[dx][dy].color_pieza=tablero[ox][oy].color_pieza;
	tablero[ox][oy].tipo_pieza=NINGUNA;
	tablero[ox][oy].color_pieza=' ';
}

// esta funcion llama a todas las funciones de comprobar el movimiento, segun sea la pieza de origen

int comprobar_movimiento(struct s_casilla tablero[9][9],struct s_estado estado, int ox, int oy,int dx,int dy)
{
	int n;

	n = 0;
	switch (tablero[ox][oy].tipo_pieza)
	{
		case PEON: n=compr_movi_peon(tablero,estado,ox,oy,dx,dy); break;
		case CABALLO: n=compr_movi_caballo(tablero,estado,ox,oy,dx,dy); break;
		case TORRE: n=compr_movi_torre(tablero,estado,ox,oy,dx,dy); break;
		case ALFIL: n=compr_movi_alfil(tablero,estado,ox,oy,dx,dy); break;
		case REY: n=compr_movi_rey(tablero,estado,ox,oy,dx,dy); break;
		case DAMA: n=compr_movi_dama(tablero,estado,ox,oy,dx,dy); break;
	}

	return n; // si es un 1, el movimiento es correcto
}

// este es el procedimiento de comprobar el movimiento del peon. se tienen q comprobar tres cosas:

int compr_movi_peon(struct s_casilla tablero[9][9], struct s_estado estado, int ox, int oy, int dx, int dy)
{
	int correcto=0;

	// hay q hacerlo segun de quien sea el turno

	if(estado.turno == 'B')
	{

		if((dy == oy) && (dx == ox-1) && (tablero [dx][dy].tipo_pieza == NINGUNA))
			correcto=1; // cuando el peon mueve una casilla hacia delante
		if((ox == 7) && (dy == oy) && (dx == ox-2) && (tablero [ox-1][dy].tipo_pieza == NINGUNA) && (tablero[ox-2][dy].tipo_pieza == NINGUNA))
			correcto=1;  // cuando el peon esta en la posicion inicial q puede mover 2 hacia delante y es correcto
		if((dx == ox-1) && (dy == oy+1) && (tablero[dx][dy].color_pieza == NEGRO))
			correcto=1; // y cuando el peon come, q siempre lo hace en diagonal, hacia un lado o hacia otro
		if((dx == ox-1)&&(dy == oy-1) && (tablero[dx][dy].color_pieza == NEGRO))
			correcto=1;
	}
	if(estado.turno == 'N')
	{
		if((dy == oy) && (dx == ox+1) && (tablero [dx][dy].tipo_pieza == NINGUNA))
			correcto=1;
		if((ox == 2) && (dy == oy) && (dx == ox+2) && (tablero [ox+1][dy].tipo_pieza == NINGUNA) && (tablero[ox+2][dy].tipo_pieza == NINGUNA))
			correcto=1;
		if((dx == ox+1) && (dy == oy+1) && (tablero[dx][dy].color_pieza == BLANCO))
			correcto=1;
		if((dx == ox+1) && (dy == oy-1) && (tablero[dx][dy].color_pieza == BLANCO))
			correcto=1;
	}
	return correcto;
}

// este es el procedimiento de comprobar el movimiento del caballo

int compr_movi_caballo (struct s_casilla tablero[9][9], struct s_estado estado, int ox, int oy, int dx, int dy)
{
	int correcto=0;

	// si las piezas de origen son distintas de las piezas de destino se hace la comprobacion, sino error

	if(tablero[ox][oy].color_pieza=='B')
	{
		if (tablero[dx][dy].color_pieza!='B')
		{
			//el caballo mueve en forma de L, asi q hay q hacer todas las combinaciones posibles.
			// tb hay q comprobar q la pieza q se quiere comer, sea de distinto color q la pieza con la q queremos comernosla
			// con el caballo no importa si hay piezas por delante

			if((dx==ox-2)&&(dy==oy-1)&&(tablero[dx][dy].color_pieza!=estado.turno))
			correcto=1;
			if((dx==ox-2)&&(dy==oy+1)&&(tablero[dx][dy].color_pieza!=estado.turno))
			correcto=1;
			if((dx==ox-1)&&(dy==oy+2)&&(tablero[dx][dy].color_pieza!=estado.turno))
			correcto=1;
			if((dx==ox-1)&&(dy==oy-2)&&(tablero[dx][dy].color_pieza!=estado.turno))
			correcto=1;
			if((dx==ox+2)&&(dy==oy-1)&&(tablero[dx][dy].color_pieza!=estado.turno))
			correcto=1;
			if((dx==ox+2)&&(dy==oy+1)&&(tablero[dx][dy].color_pieza!=estado.turno))
			correcto=1;
			if((dx==ox+1)&&(dy==oy+2)&&(tablero[dx][dy].color_pieza!=estado.turno))
			correcto=1;
			if((dx==ox+1)&&(dy==oy-2)&&(tablero[dx][dy].color_pieza!=estado.turno))
			correcto=1;
		}
	}

	// hace igual con el caballo negro..

	if(tablero[ox][oy].color_pieza=='N')
	{
		if (tablero[dx][dy].color_pieza!='N')
		{
			if((dx==ox-2)&&(dy==oy-1)&&(tablero[dx][dy].color_pieza!=estado.turno))
			correcto=1;
			if((dx==ox-2)&&(dy==oy+1)&&(tablero[dx][dy].color_pieza!=estado.turno))
			correcto=1;
			if((dx==ox-1)&&(dy==oy+2)&&(tablero[dx][dy].color_pieza!=estado.turno))
			correcto=1;
			if((dx==ox-1)&&(dy==oy-2)&&(tablero[dx][dy].color_pieza!=estado.turno))
			correcto=1;
			if((dx==ox+2)&&(dy==oy-1)&&(tablero[dx][dy].color_pieza!=estado.turno))
			correcto=1;
			if((dx==ox+2)&&(dy==oy+1)&&(tablero[dx][dy].color_pieza!=estado.turno))
			correcto=1;
			if((dx==ox+1)&&(dy==oy+2)&&(tablero[dx][dy].color_pieza!=estado.turno))
			correcto=1;
			if((dx==ox+1)&&(dy==oy-2)&&(tablero[dx][dy].color_pieza!=estado.turno))
			correcto=1;
		}
	}
	return correcto;
}

// este es el procedimiento de comprobar el movimiento del rey: se puede mover en cualquier direccion, pero solo una casilla a la vez

int compr_movi_rey(struct s_casilla tablero[9][9], struct s_estado estado, int ox, int oy, int dx, int dy)
{
	int correcto=0;

	// como siempre, comprobamos q el color de la pieza de origen sea distinto del de la pieza de destino
	if(tablero[ox][oy].color_pieza=='B')
	{
		if (tablero[dx][dy].color_pieza!='B')
		{
			if((dx==ox-1)&&(dy==oy)) correcto=1;
			if((dx==ox+1)&&(dy==oy)) correcto=1;
			if((dx==ox-1)&&(dy==oy-1)) correcto=1;
			if((dx==ox+1)&&(dy==oy-1)) correcto=1;
			if((dx==ox+1)&&(dy==oy+1)) correcto=1;
			if((dx==ox-1)&&(dy==oy+1)) correcto=1;
			if((dx==ox)&&(dy==oy+1)) correcto=1;
			if((dx==ox)&&(dy==oy-1)) correcto=1;
		}
	}
	if(tablero[ox][oy].color_pieza=='N')
	{
		if(tablero[dx][dy].color_pieza!='N')
		{
			if((dx==ox-1)&&(dy==oy)) correcto=1;
			if((dx==ox+1)&&(dy==oy)) correcto=1;
			if((dx==ox-1)&&(dy==oy-1)) correcto=1;
			if((dx==ox+1)&&(dy==oy-1)) correcto=1;
			if((dx==ox+1)&&(dy==oy+1)) correcto=1;
			if((dx==ox-1)&&(dy==oy+1)) correcto=1;
			if((dx==ox)&&(dy==oy+1)) correcto=1;
			if((dx==ox)&&(dy==oy-1)) correcto=1;
		}
	}
	return correcto;
}

// este es el procedimiento de comprobar el movimiento de la torre: puede moverse a lo largo de la fila o de la columna q ocupa, pero no puede pasar por encima de otras piezas.

int compr_movi_torre(struct s_casilla tablero[9][9],struct s_estado estado,int ox,int oy,int dx,int dy)
{
	int correcto=0;

	if(tablero[ox][oy].color_pieza!=tablero[dx][dy].color_pieza)
	{
		// lo he hecho asi, pq me liaba con los bucles

		// aqui se mueve a lo largo de la columna hacia abajo
		if((dy==oy)&&(dx==ox+1)) correcto=1;
		if((dy==oy)&&(dx==ox+2)&&(tablero[dx-1][dy].tipo_pieza==NINGUNA)) correcto=1;
		if((dy==oy)&&(dx==ox+3)&&(tablero[dx-1][dy].tipo_pieza==NINGUNA)&&(tablero[dx-2][dy].tipo_pieza==NINGUNA)) correcto=1;
		if((dy==oy)&&(dx==ox+4)&&(tablero[dx-1][dy].tipo_pieza==NINGUNA)&&(tablero[dx-2][dy].tipo_pieza==NINGUNA)&&(tablero[dx-3][dy].tipo_pieza==NINGUNA)) correcto=1;
		if((dy==oy)&&(dx==ox+5)&&(tablero[dx-1][dy].tipo_pieza==NINGUNA)&&(tablero[dx-2][dy].tipo_pieza==NINGUNA)&&(tablero[dx-3][dy].tipo_pieza==NINGUNA)&&(tablero[dx-4][dy].tipo_pieza==NINGUNA)) correcto=1;
		if((dy==oy)&&(dx==ox+6)&&(tablero[dx-1][dy].tipo_pieza==NINGUNA)&&(tablero[dx-2][dy].tipo_pieza==NINGUNA)&&(tablero[dx-3][dy].tipo_pieza==NINGUNA)&&(tablero[dx-4][dy].tipo_pieza==NINGUNA)&&(tablero[dx-5][dy].tipo_pieza==NINGUNA)) correcto=1;
		if((dy==oy)&&(dx==ox+7)&&(tablero[dx-1][dy].tipo_pieza==NINGUNA)&&(tablero[dx-2][dy].tipo_pieza==NINGUNA)&&(tablero[dx-3][dy].tipo_pieza==NINGUNA)&&(tablero[dx-4][dy].tipo_pieza==NINGUNA)&&(tablero[dx-5][dy].tipo_pieza==NINGUNA)&& (tablero[dx-6][dy].tipo_pieza==NINGUNA)) correcto=1;
		if((dy==oy)&&(dx==ox+8)&&(tablero[dx-1][dy].tipo_pieza==NINGUNA)&&(tablero[dx-2][dy].tipo_pieza==NINGUNA)&&(tablero[dx-3][dy].tipo_pieza==NINGUNA)&&(tablero[dx-4][dy].tipo_pieza==NINGUNA)&&(tablero[dx-5][dy].tipo_pieza==NINGUNA)&&(tablero[dx-6][dy].tipo_pieza==NINGUNA)&&(tablero[dx-7][dy].tipo_pieza==NINGUNA)) correcto=1;

		// aqui se mueve a lo largo de la columna hacia arriba
		if((dy==oy)&&(dx==ox-1)) correcto=1;
		if((dy==oy)&&(dx==ox-2)&&(tablero[dx+1][dy].tipo_pieza==NINGUNA)) correcto=1;
		if((dy==oy)&&(dx==ox-3)&&(tablero[dx+1][dy].tipo_pieza==NINGUNA)&&(tablero[dx+2][dy].tipo_pieza==NINGUNA)) correcto=1;
		if((dy==oy)&&(dx==ox-4)&&(tablero[dx+1][dy].tipo_pieza==NINGUNA)&&(tablero[dx+2][dy].tipo_pieza==NINGUNA)&&(tablero[dx+3][dy].tipo_pieza==NINGUNA)) correcto=1;
		if((dy==oy)&&(dx==ox-5)&&(tablero[dx+1][dy].tipo_pieza==NINGUNA)&&(tablero[dx+2][dy].tipo_pieza==NINGUNA)&&(tablero[dx+3][dy].tipo_pieza==NINGUNA)&&(tablero[dx+4][dy].tipo_pieza==NINGUNA)) correcto=1;
		if((dy==oy)&&(dx==ox-6)&&(tablero[dx+1][dy].tipo_pieza==NINGUNA)&&(tablero[dx+2][dy].tipo_pieza==NINGUNA)&&(tablero[dx+3][dy].tipo_pieza==NINGUNA)&&(tablero[dx+4][dy].tipo_pieza==NINGUNA)&&(tablero[dx+5][dy].tipo_pieza==NINGUNA)) correcto=1;
		if((dy==oy)&&(dx==ox-7)&&(tablero[dx+1][dy].tipo_pieza==NINGUNA)&&(tablero[dx+2][dy].tipo_pieza==NINGUNA)&&(tablero[dx+3][dy].tipo_pieza==NINGUNA)&&(tablero[dx+4][dy].tipo_pieza==NINGUNA)&&(tablero[dx+5][dy].tipo_pieza==NINGUNA)&& (tablero[dx+6][dy].tipo_pieza==NINGUNA)) correcto=1;
		if((dy==oy)&&(dx==ox-8)&&(tablero[dx+1][dy].tipo_pieza==NINGUNA)&&(tablero[dx+2][dy].tipo_pieza==NINGUNA)&&(tablero[dx+3][dy].tipo_pieza==NINGUNA)&&(tablero[dx+4][dy].tipo_pieza==NINGUNA)&&(tablero[dx+5][dy].tipo_pieza==NINGUNA)&&(tablero[dx+6][dy].tipo_pieza==NINGUNA)&&(tablero[dx+7][dy].tipo_pieza==NINGUNA)) correcto=1;

		// aqui se mueve a lo largo de la fila hacia la izquierda
		if((dx==ox)&&(dy==oy-1)) correcto=1;
		if((dx==ox)&&(dy==oy-2)&& (tablero[dx][dy+1].tipo_pieza==NINGUNA)) correcto=1;
		if((dx==ox)&&(dy==oy-3)&&(tablero[dx][dy+1].tipo_pieza==NINGUNA)&&(tablero[dx][dy+2].tipo_pieza==NINGUNA)) correcto=1;
		if((dx==ox)&&(dy==oy-4)&&(tablero[dx][dy+1].tipo_pieza==NINGUNA)&&(tablero[dx][dy+2].tipo_pieza==NINGUNA)&& (tablero[dx][dy+3].tipo_pieza== NINGUNA)) correcto=1;
		if((dx==ox)&&(dy==oy-5)&&(tablero[dx][dy+1].tipo_pieza==NINGUNA)&&(tablero[dx][dy+2].tipo_pieza==NINGUNA)&&(tablero[dx][dy+3].tipo_pieza)&&(tablero[dx][dy+4].tipo_pieza== NINGUNA)) correcto=1;
		if((dx==ox)&&(dy==oy-6)&&(tablero[dx][dy+1].tipo_pieza==NINGUNA)&&(tablero[dx][dy+2].tipo_pieza==NINGUNA)&&(tablero[dx][dy+3].tipo_pieza)&&(tablero[dx][dy+4].tipo_pieza== NINGUNA)&&(tablero[dx][dy+5].tipo_pieza== NINGUNA)) correcto=1;
		if((dx==ox)&&(dy==oy-7)&&(tablero[dx][dy+1].tipo_pieza==NINGUNA)&&(tablero[dx][dy+2].tipo_pieza==NINGUNA)&&(tablero[dx][dy+3].tipo_pieza)&&(tablero[dx][dy+4].tipo_pieza== NINGUNA)&&(tablero[dx][dy+5].tipo_pieza== NINGUNA)&&(tablero[dx][dy+6].tipo_pieza==NINGUNA)) correcto=1;
		if((dx==ox)&&(dy==oy-8)&&(tablero[dx][dy+1].tipo_pieza==NINGUNA)&&(tablero[dx][dy+2].tipo_pieza==NINGUNA)&&(tablero[dx][dy+3].tipo_pieza)&&(tablero[dx][dy+4].tipo_pieza== NINGUNA)&&(tablero[dx][dy+5].tipo_pieza== NINGUNA)&&(tablero[dx][dy+6].tipo_pieza==NINGUNA)&&(tablero[dx][dy+7].tipo_pieza==NINGUNA)) correcto=1;

		// aqui se mueve a lo largo de la fila a la derecha
		if((dx==ox)&&(dy==oy+1)) correcto=1;
		if((dx==ox)&&(dy==oy+2)&& (tablero[dx][dy-1].tipo_pieza==NINGUNA)) correcto=1;
		if((dx==ox)&&(dy==oy+3)&&(tablero[dx][dy-1].tipo_pieza==NINGUNA)&&(tablero[dx][dy-2].tipo_pieza==NINGUNA)) correcto=1;
		if((dx==ox)&&(dy==oy+4)&&(tablero[dx][dy-1].tipo_pieza==NINGUNA)&&(tablero[dx][dy-2].tipo_pieza==NINGUNA)&&(tablero[dx][dy-3].tipo_pieza)) correcto=1;
		if((dx==ox)&&(dy==oy+5)&&(tablero[dx][dy-1].tipo_pieza==NINGUNA)&&(tablero[dx][dy-2].tipo_pieza==NINGUNA)&&(tablero[dx][dy-3].tipo_pieza)&&(tablero[dx][dy-4].tipo_pieza== NINGUNA)) correcto=1;
		if((dx==ox)&&(dy==oy+6)&&(tablero[dx][dy-1].tipo_pieza==NINGUNA)&&(tablero[dx][dy-2].tipo_pieza==NINGUNA)&&(tablero[dx][dy-3].tipo_pieza)&&(tablero[dx][dy-4].tipo_pieza== NINGUNA)&&(tablero[dx][dy-5].tipo_pieza== NINGUNA)) correcto=1;
		if((dx==ox)&&(dy==oy+7)&&(tablero[dx][dy-1].tipo_pieza==NINGUNA)&&(tablero[dx][dy-2].tipo_pieza==NINGUNA)&&(tablero[dx][dy-3].tipo_pieza)&&(tablero[dx][dy-4].tipo_pieza== NINGUNA)&&(tablero[dx][dy-5].tipo_pieza== NINGUNA)&&(tablero[dx][dy-6].tipo_pieza==NINGUNA)) correcto=1;
		if((dx==ox)&&(dy==oy+8)&&(tablero[dx][dy-1].tipo_pieza==NINGUNA)&&(tablero[dx][dy-2].tipo_pieza==NINGUNA)&&(tablero[dx][dy-3].tipo_pieza)&&(tablero[dx][dy-4].tipo_pieza== NINGUNA)&&(tablero[dx][dy-5].tipo_pieza== NINGUNA)&&(tablero[dx][dy-6].tipo_pieza==NINGUNA)&&(tablero[dx][dy-7].tipo_pieza==NINGUNA)) correcto=1;
	}
	return correcto;

}

// este es el procedimiento de comprobar el movimiento del afil: puede moverse a lo largo de la diagonal de la casilla q ocupa, pero no puede saltar por encima de otras piezas

int compr_movi_alfil(struct s_casilla tablero[9][9],struct s_estado estado,int ox,int oy,int dx,int dy)
{
	int correcto=0;

	// como siempre comprueba q el color de la pieza de origen sea distinto q el de destino
	if(tablero[ox][oy].color_pieza!=tablero[dx][dy].color_pieza)
	{
		// mueve en la diagonal de la derecha abajo
		if((dy==oy+1)&&(dx==ox+1)) correcto=1;
		if((dy==oy+2)&&(dx==ox+2)&&(tablero[dx-1][dy-1].tipo_pieza==NINGUNA)) correcto=1;
		if((dy==oy+3)&&(dx==ox+3)&&(tablero[dx-2][dy-2].tipo_pieza==NINGUNA)&&(tablero[dx-1][dy-1].tipo_pieza==NINGUNA)) correcto=1;
		if((dy==oy+4)&&(dx==ox+4)&&(tablero[dx-3][dy-3].tipo_pieza==NINGUNA)&&(tablero[dx-2][dy-2].tipo_pieza==NINGUNA)&&(tablero[dx-1][dy-1].tipo_pieza==NINGUNA)) correcto=1;
		if((dy==oy+5)&&(dx==ox+5)&&(tablero[dx-4][dy-4].tipo_pieza==NINGUNA)&&(tablero[dx-3][dy-3].tipo_pieza==NINGUNA)&&(tablero[dx-2][dy-2].tipo_pieza==NINGUNA)&&(tablero[dx-1][dy-1].tipo_pieza==NINGUNA)) correcto=1;
		if((dy==oy+6)&&(dx==ox+6)&&(tablero[dx-5][dy-5].tipo_pieza==NINGUNA)&&(tablero[dx-4][dy-4].tipo_pieza==NINGUNA)&&(tablero[dx-3][dy-3].tipo_pieza==NINGUNA)&&(tablero[dx-2][dy-2].tipo_pieza==NINGUNA)&&(tablero[dx-1][dy-1].tipo_pieza==NINGUNA)) correcto=1;
		if((dy==oy+7)&&(dx==ox+7)&&(tablero[dx-6][dy-6].tipo_pieza==NINGUNA)&&(tablero[dx-5][dy-5].tipo_pieza==NINGUNA)&&(tablero[dx-4][dy-4].tipo_pieza==NINGUNA)&&(tablero[dx-3][dy-3].tipo_pieza==NINGUNA)&&(tablero[dx-2][dy-2].tipo_pieza==NINGUNA)&&(tablero[dx-1][dy-1].tipo_pieza==NINGUNA)) correcto=1;
		if((dy==oy+8)&&(dx==ox+8)&&(tablero[dx-7][dy-7].tipo_pieza==NINGUNA)&&(tablero[dx-6][dy-6].tipo_pieza==NINGUNA)&&(tablero[dx-5][dy-5].tipo_pieza==NINGUNA)&&(tablero[dx-4][dy-4].tipo_pieza==NINGUNA)&&(tablero[dx-3][dy-3].tipo_pieza==NINGUNA)&&(tablero[dx-2][dy-2].tipo_pieza==NINGUNA)&&(tablero[dx-1][dy-1].tipo_pieza==NINGUNA)) correcto=1;

		// mueve en la diagonal de la izquierda arriba
		if((dy==oy-1)&&(dx==ox-1)) correcto=1;
		if((dy==oy-2)&&(dx==ox-2)&&(tablero[dx+1][dy+1].tipo_pieza==NINGUNA)) correcto=1;
		if((dy==oy-3)&&(dx==ox-3)&&(tablero[dx+2][dy+2].tipo_pieza==NINGUNA)&&(tablero[dx+1][dy+1].tipo_pieza==NINGUNA)) correcto=1;
		if((dy==oy-4)&&(dx==ox-4)&&(tablero[dx+3][dy+3].tipo_pieza==NINGUNA)&&(tablero[dx+2][dy+2].tipo_pieza==NINGUNA)&&(tablero[dx+1][dy+1].tipo_pieza==NINGUNA)) correcto=1;
		if((dy==oy-5)&&(dx==ox-5)&&(tablero[dx+4][dy+4].tipo_pieza==NINGUNA)&&(tablero[dx+3][dy+3].tipo_pieza==NINGUNA)&&(tablero[dx+2][dy+2].tipo_pieza==NINGUNA)&&(tablero[dx+1][dy+1].tipo_pieza==NINGUNA)) correcto=1;
		if((dy==oy-6)&&(dx==ox-6)&&(tablero[dx+5][dy+5].tipo_pieza==NINGUNA)&&(tablero[dx+4][dy+4].tipo_pieza==NINGUNA)&&(tablero[dx+3][dy+3].tipo_pieza==NINGUNA)&&(tablero[dx+2][dy+2].tipo_pieza==NINGUNA)&&(tablero[dx+1][dy+1].tipo_pieza==NINGUNA)) correcto=1;
		if((dy==oy-7)&&(dx==ox-7)&&(tablero[dx+6][dy+6].tipo_pieza==NINGUNA)&&(tablero[dx+5][dy+5].tipo_pieza==NINGUNA)&&(tablero[dx+4][dy+4].tipo_pieza==NINGUNA)&&(tablero[dx+3][dy+3].tipo_pieza==NINGUNA)&&(tablero[dx+2][dy+2].tipo_pieza==NINGUNA)&&(tablero[dx+1][dy+1].tipo_pieza==NINGUNA)) correcto=1;
		if((dy==oy-8)&&(dx==ox-8)&&(tablero[dx+7][dy+7].tipo_pieza==NINGUNA)&&(tablero[dx+6][dy+6].tipo_pieza==NINGUNA)&&(tablero[dx+5][dy+5].tipo_pieza==NINGUNA)&&(tablero[dx+4][dy+4].tipo_pieza==NINGUNA)&&(tablero[dx+3][dy+3].tipo_pieza==NINGUNA)&&(tablero[dx+2][dy+2].tipo_pieza==NINGUNA)&&(tablero[dx+1][dy+1].tipo_pieza==NINGUNA)) correcto=1;

		// mueve en la diagonal de la izquierda abajo
		if((dy==oy-1)&&(dx==ox+1)) correcto=1;
		if((dy==oy-2)&&(dx==ox+2)&&(tablero[dx-1][dy+1].tipo_pieza==NINGUNA)) correcto=1;
		if((dy==oy-3)&&(dx==ox+3)&&(tablero[dx-2][dy+2].tipo_pieza==NINGUNA)&&(tablero[dx-1][dy+1].tipo_pieza==NINGUNA)) correcto=1;
		if((dy==oy-4)&&(dx==ox+4)&&(tablero[dx-3][dy+3].tipo_pieza==NINGUNA)&&(tablero[dx-2][dy+2].tipo_pieza==NINGUNA)&&(tablero[dx-1][dy+1].tipo_pieza==NINGUNA)) correcto=1;
		if((dy==oy-5)&&(dx==ox+5)&&(tablero[dx-4][dy+4].tipo_pieza==NINGUNA)&&(tablero[dx-3][dy+3].tipo_pieza==NINGUNA)&&(tablero[dx-2][dy+2].tipo_pieza==NINGUNA)&&(tablero[dx-1][dy+1].tipo_pieza==NINGUNA)) correcto=1;
		if((dy==oy-6)&&(dx==ox+6)&&(tablero[dx-5][dy+5].tipo_pieza==NINGUNA)&&(tablero[dx-4][dy+4].tipo_pieza==NINGUNA)&&(tablero[dx-3][dy+3].tipo_pieza==NINGUNA)&&(tablero[dx-2][dy+2].tipo_pieza==NINGUNA)&&(tablero[dx-1][dy+1].tipo_pieza==NINGUNA)) correcto=1;
		if((dy==oy-7)&&(dx==ox+7)&&(tablero[dx-6][dy+6].tipo_pieza==NINGUNA)&&(tablero[dx-5][dy+5].tipo_pieza==NINGUNA)&&(tablero[dx-4][dy+4].tipo_pieza==NINGUNA)&&(tablero[dx-3][dy+3].tipo_pieza==NINGUNA)&&(tablero[dx-2][dy+2].tipo_pieza==NINGUNA)&&(tablero[dx-1][dy+1].tipo_pieza==NINGUNA)) correcto=1;
		if((dy==oy-8)&&(dx==ox+8)&&(tablero[dx-7][dy+7].tipo_pieza==NINGUNA)&&(tablero[dx-6][dy+6].tipo_pieza==NINGUNA)&&(tablero[dx-5][dy+5].tipo_pieza==NINGUNA)&&(tablero[dx-4][dy+4].tipo_pieza==NINGUNA)&&(tablero[dx-3][dy+3].tipo_pieza==NINGUNA)&&(tablero[dx-2][dy+2].tipo_pieza==NINGUNA)&&(tablero[dx-1][dy+1].tipo_pieza==NINGUNA)) correcto=1;

		// mueve en la diagonal de la derecha arriba
		if((dy==oy+1)&&(dx==ox-1)) correcto=1;
		if((dy==oy+2)&&(dx==ox-2)&&(tablero[dx+1][dy-1].tipo_pieza==NINGUNA)) correcto=1;
		if((dy==oy+3)&&(dx==ox-3)&&(tablero[dx+2][dy-2].tipo_pieza==NINGUNA)&&(tablero[dx+1][dy-1].tipo_pieza==NINGUNA)) correcto=1;
		if((dy==oy+4)&&(dx==ox-4)&&(tablero[dx+3][dy-3].tipo_pieza==NINGUNA)&&(tablero[dx+2][dy-2].tipo_pieza==NINGUNA)&&(tablero[dx+1][dy-1].tipo_pieza==NINGUNA)) correcto=1;
		if((dy==oy+5)&&(dx==ox-5)&&(tablero[dx+4][dy-4].tipo_pieza==NINGUNA)&&(tablero[dx+3][dy-3].tipo_pieza==NINGUNA)&&(tablero[dx+2][dy-2].tipo_pieza==NINGUNA)&&(tablero[dx+1][dy-1].tipo_pieza==NINGUNA)) correcto=1;
		if((dy==oy+6)&&(dx==ox-6)&&(tablero[dx+5][dy-5].tipo_pieza==NINGUNA)&&(tablero[dx+4][dy-4].tipo_pieza==NINGUNA)&&(tablero[dx+3][dy-3].tipo_pieza==NINGUNA)&&(tablero[dx+2][dy-2].tipo_pieza==NINGUNA)&&(tablero[dx+1][dy-1].tipo_pieza==NINGUNA)) correcto=1;
		if((dy==oy+7)&&(dx==ox-7)&&(tablero[dx+6][dy-6].tipo_pieza==NINGUNA)&&(tablero[dx+5][dy-5].tipo_pieza==NINGUNA)&&(tablero[dx+4][dy-4].tipo_pieza==NINGUNA)&&(tablero[dx+3][dy-3].tipo_pieza==NINGUNA)&&(tablero[dx+2][dy-2].tipo_pieza==NINGUNA)&&(tablero[dx+1][dy-1].tipo_pieza==NINGUNA)) correcto=1;
		if((dy==oy+8)&&(dx==ox-8)&&(tablero[dx+7][dy-7].tipo_pieza==NINGUNA)&&(tablero[dx+6][dy-6].tipo_pieza==NINGUNA)&&(tablero[dx+5][dy-5].tipo_pieza==NINGUNA)&&(tablero[dx+4][dy-4].tipo_pieza==NINGUNA)&&(tablero[dx+3][dy-3].tipo_pieza==NINGUNA)&&(tablero[dx+2][dy-2].tipo_pieza==NINGUNA)&&(tablero[dx+1][dy-1].tipo_pieza==NINGUNA)) correcto=1;
	}
	return correcto;
}
// este es el procedimiento de comprobar el movimiento de la dama: puede moverse a cualquier casilla de la fila, columna, diagonal q ocupe. No puede saltar por encima(como todos, salvo el caballo)

int compr_movi_dama(struct s_casilla tablero[9][9],struct s_estado estado,int ox,int oy,int dx,int dy)
{
	int n, correcto=0;

	if(tablero[ox][oy].color_pieza!=tablero[dx][dy].color_pieza)
	{
		// como hace los movimientos del alfil y la torre juntos, pues comprobamos primero el alfil.
		//si nos devuelve un 1 es q el movimiento es correcto y mueve hacia ese lado.
		n=compr_movi_alfil(tablero,estado,ox,oy,dx,dy);
		if(n==1)
			correcto=1;
		else // si no es correcto, comprueba el movimiento de la torre y si es correcto mueve hacia ese lado.
		{
			n=compr_movi_torre(tablero,estado,ox,oy,dx,dy);
			if(n==1)
				correcto=1;
		}
	}
   // si ninguno de los dos es correcto, devuelve un 0 y no da error
	return correcto;
}