#include "tablero_en_curso2.h"
#include "tirada.h"
#include "tirada_humano.h"
#include "movimientos.h"

char controlar_mov_alfil(struct s_casilla tablero[9][9],int xo,int yo,int x,int y)
{
	int i,j;
	int decr_x,decr_y,incr_x,incr_y;
	char permitido='S';

	if ((xo!=x)&&(yo!=y))
		{
		if((yo<y)&&(xo<x))			//Abajo-derecha
			{
			for(i=yo+1;i<y-1;i++)
				{
				for(j=xo+1;j=x-1;j++)
					{
					if (tablero[i][j].figura!=' ')
						{
						//move (20,65);
						//printw("Movimento Ilegal");
						permitido='N';
						}
					}
				}
			}
		if((yo<y)&&(xo>x))			//Abajo-Izquierda
			{
			for(i=yo-1;i<y+1;i--)
				{
				for(j=xo+1;j=x-1;j--)
					{
					if (tablero[i][j].figura!=' ')
						{
						move (20,65);
						//printw("Movimento Ilegal");
						permitido='N';
						}
					}
				}
			}
		if((yo>y)&&(xo<x))			//Arriba-Derecha
			{
			for(i=yo-1;i<y+1;i--)
				{
				for(j=xo+1;j=x-1;j++)
					{
					if (tablero[i][j].figura!=' ')
						{
						//move (20,65);
						//printw("Movimento Ilegal");
						permitido='N';
						}
					}
				}
			}
		if((yo>y)&&(xo>x))			//Arriba-Izquierda
			{
			for(i=yo-1;i<y+1;i--)
				{
				for(j=xo-1;j=x+1;j--)
					{
					if (tablero[i][j].figura!=' ')
						{
						//move (20,65);
						//printw("Movimento Ilegal");
						permitido='N';
						}
					}
				}
			}
		}
	incr_x=x-xo;
	decr_x=xo-x;
	incr_y=y-yo;
	decr_y=yo-y;
	if((incr_x!=incr_y)||(decr_x!=decr_y))		//Obliga que el mov. sea oblicuo
		{
		//move (20,65);
		//printw("Movimento Ilegal");
		permitido='N';
		}

	return(permitido);
}
char controlar_mov_torre(struct s_casilla tablero[9][9],int xo,int yo,int x,int y)
{
	char permitido='S';
	int i;

	if ((xo==x)&&(yo==y))			// Obliga a cambiar de casilla
		{
		permitido='N';
		//break;
		}
	if((xo!=x)&&(yo!=y))			// Obliga a que el mov. sea vertical u horizontal
		{
		permitido='N';
		//break;
		}

	if ((xo!=x)&&(yo==y))			// Movimiento Vertical.
		{
		if(xo>x)			// Arriba.
			{
			for(i=xo-1;i=x+1;i++)
				{
				if (tablero[i][yo].figura!=' ')
					permitido='N';
				}
			}

		if (xo<x)			// Abajo.
			{
			for(i=xo+1;i=x-1;i++)
				{
				if (tablero[i][yo].figura!=' ')
					permitido='N';
				}
			}
		}
	if ((yo!=y)&&(xo==x))			// Movimiento Horizontal
		{
		if (yo>y)			// Izquierda
			{
			for(i=y-1;i=yo+1;i--)
				{
				if (tablero[y][i].figura!=' ')
					{
					permitido='N';
					}
				}
			}

		if (yo<y)			// Derecha
			{
			for(i=y+1;i=yo-1;i--)
				{
				if (tablero[y][i].figura!=' ')
					{
					permitido='N';
					}
				}
			}

		}


	return(permitido);
}

char controlar_mov_rey(struct s_casilla tablero[9][9],int xo,int yo,int x,int y)
{
	char permitido='N';

	if((x==xo-1)&&(y==yo-1))
		{
		permitido='S';
		//break;
		}
	if((x==xo-1)&&(y==yo+1))
		{
		permitido='S';
		//break;
		}
	if((x==xo-1)&&(y==yo))
		{
		permitido='S';
		//break;
		}
	if((x==xo+1)&&(y==yo-1))
		{
		permitido='S';
		//break;
		}
	if((x==xo+1)&&(y==yo+1))
		{
		permitido='S';
		//break;
		}
	if((x==xo+1)&&(y==yo))
		{
		permitido='S';
		//break;
		}
	if((x==xo)&&(y==yo-1))
		{
		permitido='S';
		//break;
		}
	if((x==xo)&&(y==yo+1))
		{
		permitido='S';
		//break;
		}
	if ((yo==y)&&(xo==x))
		{
		permitido='N';
		}

	return(permitido);
}

char controlar_mov_dama(struct s_casilla tablero[9][9],int xo,int yo,int x,int y)
{

	char permitido='S';
	int i;
	int decr_x,decr_y,incr_x,incr_y;

	if ((yo==y)&&(xo==x))
			{
			//move (20,65);
			//printw("Movimento Ilegal");
			permitido='N';
			}
	if((yo==y)&&(xo!=x))		//Movimiento vertical
		{
		if(xo>x)		//arriba
			{
			for(i=xo-1;i=x+1;i--)
				{
				if (tablero[i][x].figura!=' ')
					{
					//move (20,65);
					//printw("Movimento Ilegal");
					permitido='N';
					}
				}
			}
		if(xo<x)		//abajo
			{
			for(i=x+1;i=xo-1;i++)
				{
				if (tablero[i][x].figura!=' ')
					{
					//move (20,65);
					//printw("Movimento Ilegal");
					permitido='N';
					}
				}
			}
		}

	if((yo!=y)&&(xo==x))		//Movimiento HORIZONTAL
		{
		if(yo>y)		//izquierda
			{
			for(i=yo-1;i=y+1;i--)
				{
				if (tablero[i][x].figura!=' ')
					{
					//move (20,65);
					//printw("Movimento Ilegal");
					permitido='N';
					}
				}
			}
		if(yo<y)		//derecha
			{
			for(i=yo+1;i=y-1;i++)
				{
				if (tablero[i][x].figura!=' ')
					{
					//move (20,65);
					//printw("Movimento Ilegal");
					permitido='N';
					}
				}
			}
		}

	if ((xo!=x)&&(yo!=y))		//Compruba el mov oblicuo
		{
		incr_x=x-xo;
		decr_x=xo-x;
		incr_y=y-yo;
		decr_y=yo-y;
		if((incr_x!=incr_y)||(decr_x!=decr_y))
			{
			//move (20,65);
			//printw("Movimento Ilegal");
			permitido='N';
			}
		}



	return(permitido);
}

char controlar_mov_peon(struct s_casilla tablero[9][9],int xo,int yo,int x,int y,char turno)
{
	char permitido='S';

	if (turno=='B')
		{
		if((xo!=x)&&(yo==y))		//Para no permitir el retroceso del peon BLANCO
			{
			if (xo<x)
				{
				//move (20,65);
				//printw("Movimento Ilegal");
				permitido='N';
				}
			}
		}
	if (turno=='N')
		{
		if((xo!=x)&&(yo==y))		//Para no permitir el retroceso del peon NEGRO
			{
			if (xo>x)
				{
				//move (20,65);
				//printw("Movimento Ilegal");
				permitido='N';
				}
			}
		}
	if (xo!=x)				//Controla el mov horitontal del peon
		{
		if((tablero[x][y].figura==' ')||(tablero[x][y].color_ficha==turno))
			{
			//move (20,65);
			//printw("Movimento Ilegal");
			permitido='N';
			}
		}


	return(permitido);
}

char controlar_mov_caballo(struct s_casilla tablero[9][9],int xo,int yo,int x,int y)
{
	char permitido='N';

	if ((x==xo-1)&&(y==yo-2))
		permitido='S';
	if ((x==xo-1)&&(y==yo+2))
		permitido='S';
	if ((x==xo+1)&&(y==yo-2))
		permitido='S';
	if ((x==xo+1)&&(y==yo+2))
		permitido='S';
	if ((x==xo-2)&&(y==yo-1))
		permitido='S';
	if ((x==xo-2)&&(y==yo+1))
		permitido='S';
	if ((x==xo+2)&&(y==yo-1))
		permitido='S';
	if ((x==xo+2)&&(y==yo+1))
		permitido='S';

	return permitido;
}


