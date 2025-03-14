#include "ajedrez.h"


int pintar_cursor (int *x, int *y,int *xp,int *yp,struct s_casilla tablero [9][9],int px,int py,struct s_estado estado)
{
	int tecla;
	int terminar = 0;
	*x = (*xp/5+1);
	*y = (*yp/3+1);
	do
	{
		pintar_pantalla(tablero,estado);
		//pintar_ventana(estado);
		move (*yp,*xp);
		attron(COLOR_PAIR (6));
		printw ("     ");
		move (*yp+1,*xp);
		printw (" ");
		move (*yp+1,*xp+4);
		printw (" ");
		move (*yp+2,*xp);
		printw ("     ");
		move (px,py);
		printw("%i.%c%i",estado.cont,*x+64,9-*y);
		
		refresh();
		tecla = getch();
		switch (tecla)
		{
			case KEY_UP:
					if(*y>1){
						*yp=*yp-3;
						*y=*y-1;
					}
					break;
			case KEY_DOWN: 
					if(*y<8){
						*yp=*yp+3;
						*y=*y+1;
					}
					break;
			case KEY_LEFT:
					if (*x>1){
						*xp=*xp-5;
						*x=*x-1;
					}
					break;
			case KEY_RIGHT: 
					if(*x<8){
						*xp=*xp+5;
						*x=*x+1;
					}
					break;
			case 'm':{
					*x=0;
					*y=0;
					terminar = 1;
				}break;
			case 10: terminar = 1;
				
		}
		
	}
	while (terminar == 0);
	
}

int tirada_origen (int *xo, int *yo,struct s_casilla tablero [9][9], struct s_estado *estado)
{
	int n,px,py;
	px = 6;
	py =86;
	
	//move (6,79);
	//printw ("ORIGEN");
	pintar_cursor(xo, yo, &estado->xp, &estado->yp,tablero,px,py,*estado);
	return 0;
}

int tirada_destino (int *x, int *y,struct s_casilla tablero [9][9], struct s_estado *estado)
{
	int n,px,py; 
	px = 11;
	py = 87;
	
	//move (11,79);
	//printw ("DESTINO");
	pintar_cursor(x, y, &estado->xp, &estado->yp,tablero,px,py,*estado);
	return 0;
}

/*/////////////////////////////////////////////////////////*/
/*////// Comprobamos que la casilla de origen para/////////*/
/*//////  evitar que el usuario siga moviendo     /////////*/
/*/////////////////////////////////////////////////////////*/

int comprobar_origen(int xo, int yo,struct s_casilla tablero[9][9], struct s_estado estado)
{
	int comp;
	comp=1;
	if (tablero[xo][yo].color_pieza != estado.turno)
	{
		attron (COLOR_PAIR(10));
		move (18,83);
		printw ("Elija una pieza valida"); 
		retardo (20);
		comp = 0;
	}
	return comp;
}

/*/////////////////////////////////////////////////////////////*/
/*////// Controlamos todos los tipos de movimiento ////////////*/
/*/////////////////////////////////////////////////////////////*/

int comprobar(int x,int y, int xo, int yo,struct s_casilla tablero[9][9], struct s_estado *estado,int *repetir)
{
	int com1,com2,comp;
	comp=0;
	com1=0;
	com2=0;
	*repetir = 1;
	if ((xo==x)&&(yo==y))
	{
		*repetir = 0;
		comp=1;
	}
	else
	{
		if (tablero[xo][yo].pieza == PEON) comp = comprobar_peon(x,y,xo,yo,tablero,estado);
		if (tablero[xo][yo].pieza == CABALLO) comp = comprobar_caballo(x,y,xo,yo,tablero,estado);
		if (tablero[xo][yo].pieza == TORRE) comp = comprobar_torre(x,y,xo,yo,tablero,estado);
		if (tablero[xo][yo].pieza == ALFIL) comp = comprobar_alfil(x,y,xo,yo,tablero,estado);
		if (tablero[xo][yo].pieza == REY) comp = comprobar_rey (x,y,xo,yo,tablero,estado);
		if (tablero[xo][yo].pieza == REINA) 
		{
		   com1 = comprobar_torre(x,y,xo,yo,tablero,estado);
		   com2 = comprobar_alfil(x,y,xo,yo,tablero,estado);
		   if ((com1 == 1) || (com2 == 1)) comp = 1;
		}
	}
	if (comp == 0)
	{
		move (15,86);
		printw ("Movimiento incorrecto"); retardo(5);
		move (15,86);
		printw ("                     ");
	}
	return comp;
}

int mover (int x,int y, int xo, int yo,struct s_casilla tablero[9][9])
{
	tablero[x][y].pieza = tablero[xo][yo].pieza;
	tablero[x][y].color_pieza = tablero [xo][yo].color_pieza;
	tablero[xo][yo].pieza = ' ';
	tablero [xo][yo].color_pieza = ' ';
}

int comprobar_peon (int x,int y, int xo, int yo,struct s_casilla tablero[9][9], struct s_estado *estado)
{
	int comp = 0;
	if (estado->turno == BLANCAS)
	{
		if ((xo==x)&&(y==yo-1)&&(tablero[x][y].pieza == ' '))
			comp = 1;
		if ((xo==x)&&(yo==7)&&(y==yo-2)&&(tablero[xo][yo-1].pieza == ' ') && (tablero[x][y].pieza == ' '))
			comp = 1;
		if ((x==xo-1)&&(y==yo-1)&&(tablero[x][y].color_pieza ==  NEGRAS)&&(tablero[x][y].pieza != ' '))   //comer a la izquierda
			comp = 1;
		if ((x==xo+1)&&(y==yo-1)&&(tablero[x][y].color_pieza ==  NEGRAS)&&(tablero[x][y].pieza != ' ')) // comer a la derecha
			comp = 1;
	}
	if (estado->turno == NEGRAS)
	{
		if ((xo==x)&&(y==yo+1)&&(tablero[x][y].pieza == ' '))
			comp = 1;
		if ((xo==x)&&(yo==2)&&(y==yo+2)&&(tablero[xo][yo+1].pieza == ' ') && (tablero[x][y].pieza == ' '))
			comp = 1;
		if ((x==xo-1)&&(y==yo+1)&&(tablero[x][y].color_pieza ==  NEGRAS)&&(tablero[x][y].pieza != ' '))   //comer a la izquierda
			comp = 1;
		if ((x==xo+1)&&(y==yo+1)&&(tablero[x][y].color_pieza ==  NEGRAS)&&(tablero[x][y].pieza != ' ')) // comer a la derecha
			comp = 1;
	}
	return comp;
}

int comprobar_caballo (int x,int y, int xo, int yo,struct s_casilla tablero[9][9], struct s_estado *estado)
{
	int comp=0;
	if ((tablero [x][y].pieza ==' ') || (tablero[x][y].color_pieza != estado->turno))
	{
		if ((x==xo-1)&&(y==yo-2))
			comp =1;
		if ((x==xo+1)&&(y==yo+2))
			comp = 1;
		if ((x==xo-1)&&(y==yo+2))
			comp =1;
		if ((x==xo+1)&&(y==yo-2))
			comp = 1;
		if ((x==xo-2)&&(y==yo-1))
			comp = 1;
		if ((x==xo+2)&&(y==yo-1))
			comp =1;
		if ((x==xo+2)&&(y==yo+1))
			comp = 1;
		if ((x==xo-2)&&(y==yo+1))
			comp = 1;
	}
	return comp;	
}

int comprobar_torre (int x,int y, int xo, int yo,struct s_casilla tablero[9][9], struct s_estado *estado)
{
	int comp,i;
	comp = 1;
	if ((x!=xo)&&(y!=yo))				// Si se mueve en las dos coordenadas es erróneo
		comp =0;
	
	if ((yo<y)&&(x==xo))				// La torre se mueve hacia ABAJO
	{
		for (i=yo+1; i<=y-1;i++)
		{
			if (tablero[x][i].pieza != ' ')
				comp = 0;
		}
	}
	if ((yo>y)&&(x==xo))				// La torre se mueve hacia ARRIBA
	{
		for (i=yo-1; i>=y+1;i--)
		{
			if (tablero[x][i].pieza != ' ')
				comp = 0;
		}
	}
	if ((xo<x)&&(y==yo))				// La torre se mueve hacia DERECHA
	{
		for (i=xo+1; i<=x-1;i++)
		{
			if (tablero[i][y].pieza != ' ')		
				comp = 0;
		}
	}
	if ((xo>x)&&(y==yo))				// La torre se mueve hacia IZQUIERDA
	{
		for (i=xo-1; i>=x+1;i--)
		{
			if (tablero[i][y].pieza != ' ')
				comp = 0;
		}
	}
	
	if (tablero [x][y].color_pieza == estado->turno)		// Comprobar si en el destino hay una pieza
		comp = 0;
	if ((comp==1)&&(estado->turno == BLANCAS)) //comprobar que no se mueva para realizar el enroque
		estado->enroque_blancas =1;
	if ((comp==1)&&(estado->turno == NEGRAS))
		estado->enroque_negras =1;
	return comp;
}

int comprobar_alfil (int x,int y, int xo, int yo,struct s_casilla tablero[9][9], struct s_estado *estado)
{
	int comp,i,j;
	comp = 1;
	if ((x<xo)&&(y<yo)) //se mueve en la diagonal izquierda hacia arriba
	{
		i=xo-1;
		j=yo-1;
		while ((i>x)&&(j>y))
		{
			if (tablero[i][j].pieza != ' ')
				comp = 0;
			i--;
			j--;
		}
		if ((i!=x) || (j!=y))
			comp = 0;
	}
	if ((x>xo)&&(y<yo)) //se mueve en la diagonal derecha hacia arriba
	{
		i=xo+1;
		j=yo-1;
		while ((i<x)&&(j<y))
		{
			if (tablero[i][j].pieza != ' ')
				comp = 0;
			i++;
			j--;
		}
		if ((i!=x) || (j!=y))
			comp = 0;
	}
	if ((x<xo)&&(y>yo)) //se mueve en la diagonal izquierda hacia abajo
	{
		i=xo-1;
		j=yo+1;
		while ((i>x)&&(j>y))
		{
			if (tablero[i][j].pieza != ' ')
				comp = 0;
			i--;
			j++;
		}
		if ((i!=x) || (j!=y))
			comp = 0;

	}
	if ((x>xo)&&(y>yo)) //se mueve en la diagonal derecha hacia abajo
	{
		i=xo+1;
		j=yo+1;
		while ((i<x)&&(j>y))
		{
			if (tablero[i][j].pieza != ' ')
				comp = 0;
			i++;
			j++;
		}
		if ((i!=x) || (j!=y))
			comp = 0;

	}
	if (tablero [x][y].color_pieza== estado->turno)
		comp =0;
		
		
	if ((xo==x) || (yo==y))
		comp = 0;

	return comp;
}

int comprobar_rey (int x,int y, int xo, int yo,struct s_casilla tablero[9][9], struct s_estado *estado)
{
	int comp =0;
	if(tablero[xo][yo].color_pieza==BLANCAS)
	{	
		if ((tablero[x][y].color_pieza==NEGRAS)||(tablero[x][y].pieza == ' '))
		{
			if((x==xo)&&(y==yo+1))
				comp=1;	
			if((x==xo)&&(y=yo-1))
				comp=1;
			if((x==xo+1)&&(y==yo+1)) 
				comp=1;
			if((x==xo+1)&&(y==yo-1))
				comp=1;
			if((x==xo+1)&&(y==yo)) 
				comp=1;
			if((x==xo-1)&&(y==yo-1)) 
				comp=1;
			if((x==xo-1)&&(y==yo+1)) 
				comp=1;
			if((x==xo-1)&&(y==yo)) 
				comp=1;
		}
	}
	if(tablero[xo][yo].color_pieza==NEGRAS)
	{
		if((tablero[x][y].color_pieza==BLANCAS)||(tablero[x][y].pieza == ' '))
		{
			if((x==xo) && (y==yo+1)) 
				comp=1;	
			if((x==xo) && (y==yo-1)) 
				comp=1;
			if((x==xo+1)&&(y==yo+1)) 
				comp=1;
			if((x==xo+1)&&(y==yo-1)) 
				comp=1;
			if((x==xo+1)&&(y==yo)) 
				comp=1;
			if((x==xo-1) &&(y==yo-1)) 
				comp=1;
			if((x==xo-1) &&(y==yo+1)) 
				comp=1;
			if((x==xo-1) &&(y==yo)) 
				comp=1;
		}
	}
	if ((comp==1)&&(estado->turno == BLANCAS)) //comprobar que no se mueva para realizar el enroque
		estado->enroque_blancas =1;
	if ((comp==1)&&(estado->turno == NEGRAS))
		estado->enroque_negras =1;
	if ((y==yo)&&(x==xo+2)&&(estado->enroque_blancas == 0))	// El rey blanco intenta hacer el enroque corto
	{
	   comp = 1;
	   if (tablero [xo+1][y].pieza != ' ')
	   	comp =0;
	   if (tablero [xo+2][y].pieza != ' ')
	   	comp = 0;
	   if (comp ==1)
	   {
	   	tablero [6][8].pieza = tablero [8][8].pieza;  //forzamos el movimiento de la torre
		tablero [6][8].color_pieza = tablero [8][8].color_pieza;
	   }	
	 }
	if ((y==yo)&&(x==xo+2)&&(estado->enroque_negras == 0))	// El rey negro intenta hacer el enroque corto
	{
	   comp = 1;
	   if (tablero [xo+1][y].pieza != ' ')
	   	comp =0;
	   if (tablero [xo+2][y].pieza != ' ')
	   	comp = 0;
	   if (comp ==1)
	   {
	   	tablero [6][1].pieza = tablero [8][1].pieza;  //forzamos el movimiento de la torre
		tablero [6][1].color_pieza = tablero [8][1].color_pieza;
	   }
	 }
	if ((y==yo)&&(x==xo-2)&&(estado->enroque_blancas == 0))	// El rey blanco intenta hacer el enroque largo
	{
	   comp = 1;
	   if (tablero [xo-1][y].pieza != ' ')
	   	comp =0;
	   if (tablero [xo-2][y].pieza != ' ')
	   	comp = 0;
	   if (tablero [xo-3][y].pieza != ' ')
	   	comp =0;
	   if (comp ==1)
	   {
	   	tablero [4][8].pieza = tablero [1][8].pieza;  //forzamos el movimiento de la torre
		tablero [4][8].color_pieza = tablero [1][8].color_pieza;
	   }
	}
	if ((y==yo)&&(x==xo-2)&&(estado->enroque_negras == 0))	// El rey negro intenta hacer el enroque largo
	{
	   comp = 1;
	   if (tablero [xo-1][y].pieza != ' ')
	   	comp =0;
	   if (tablero [xo-2][y].pieza != ' ')
	   	comp = 0;
	   if (tablero [xo-3][y].pieza != ' ')
	   	comp =0;
	   if (comp ==1)
	   {
	   	tablero [4][1].pieza = tablero [1][1].pieza;  //forzamos el movimiento de la torre
		tablero [4][1].color_pieza = tablero [1][1].color_pieza;
	   }
	}
	
	return comp;
}
