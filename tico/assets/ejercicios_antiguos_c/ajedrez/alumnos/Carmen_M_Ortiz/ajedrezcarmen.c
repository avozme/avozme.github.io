#include<stdio.h>
#include<ncurses.h>

#define PEON 'P'
#define CABALLO 'C'
#define TORRE 'T'
#define ALFIL 'A'
#define REY 'R'
#define DAMA 'D'
#define NINGUNA ' '
#define NEGRO 'N'
#define BLANCO 'B'
#define HUMANO 'H'
#define MAQUINA 'M'

//definir las estructuras
struct s_casilla
{
	char ocupada;
	char color_casilla;
	char tipo_pieza;
	char color_pieza;
};
struct s_estado
{
	char turno;
	int n_movim;
	char tipo_blancas;
	char tipo_negras;
};

//definir los protottpos de las funciones
void inicializar(struct s_casilla tablero[9][9], struct s_estado *estado);
void colocar_piezas(struct s_casilla tablero[9][9]);
void inicializar_estado(struct s_estado*estado);
int pintar_tablero(struct s_casilla tablero[9][9]);
void inicializar_ncurses(struct s_casilla tablero[9][9]);
void mover_humano(struct s_casilla tablero[9][9], struct s_estado estado);
int convertir(char c);
void elegir_origen(int *columna1, int *fila1);
void elegir_destino(int *columna2, int *fila2);
void mover(struct s_casilla tablero[9][9], int *columna1, int *fila1, int *columna2, int *fila2);
int comprobar_movimiento(struct s_estado estado, struct s_casilla tablero[9][9], int xo, int yo, int xd, int yd);
int comprobar_movimiento_peon(struct s_estado estado, struct s_casilla tablero[9][9], int xo, int yo, int xd, int yd);
int comprobar_movimiento_rey(struct s_estado estado, struct s_casilla tablero[9][9], int xo, int yo, int xd, int yd);
int comprobar_movimiento_caballo(struct s_estado estado,struct s_casilla tablero[9][9],int xo, int yo,int xd,int yd);
int comprobar_movimiento_torre(struct s_estado estado,struct s_casilla tablero[9][9],int xo, int yo,int xd,int yd);
int comprobar_movimiento_alfil(struct s_estado estado,struct s_casilla tablero[9][9],int xo, int yo,int xd,int yd);
int comprobar_movimiento_dama(struct s_estado estado,struct s_casilla tablero[9][9],int xo, int yo,int xd,int yd);



int main()
{
	struct s_casilla tablero[9][9];
	struct s_estado estado;
        inicializar_ncurses(tablero);
	inicializar(tablero,&estado);
	
	do 
	{
	   pintar_tablero(tablero);
	   mover_humano(tablero, estado);
 	   if (estado.turno == BLANCO)
		{
			estado.turno=NEGRO;
		}
	   else
		{
			estado.turno=BLANCO;
		}
	}
	while (1==1);
	
	getchar();
	endwin();
	
	
return 0;
}

void inicializar(struct s_casilla tablero[9][9], struct s_estado *estado)
{
	colocar_piezas(tablero);
	inicializar_estado(estado);
}

void colocar_piezas(struct s_casilla tablero[9][9])
{
	int x,y;

	//colocar color casilla
	for(x=1; x<=8; x++)
		for(y=1; y<=8; y++)
			tablero[x][y].color_casilla=NEGRO;

	for (x=2; x<=8; x=x+2)
		for(y=2; y<=8; y=y+2)
			tablero[x][y].color_casilla=BLANCO;

	for(x=1; x<=8; x=x+2)
		for(y=1; y<=8; y=y+2)
			tablero[x][y].color_casilla=BLANCO;


	//colocar piezas en un lado
	tablero[1][1].tipo_pieza=TORRE;
	tablero[2][1].tipo_pieza=CABALLO;
	tablero[3][1].tipo_pieza=ALFIL;
	tablero[4][1].tipo_pieza=DAMA;
	tablero[5][1].tipo_pieza=REY;
	tablero[6][1].tipo_pieza=ALFIL;
	tablero[7][1].tipo_pieza=CABALLO;
	tablero[8][1].tipo_pieza=TORRE;

	for(x=1; x<=8; x++) {
		tablero[x][2].tipo_pieza=PEON;
		tablero[x][7].tipo_pieza=PEON;
        }
	
	//colocar piezas en otro lado
	tablero[1][8].tipo_pieza=TORRE;
	tablero[2][8].tipo_pieza=CABALLO;
	tablero[3][8].tipo_pieza=ALFIL;
	tablero[4][8].tipo_pieza=DAMA;
	tablero[5][8].tipo_pieza=REY;
	tablero[6][8].tipo_pieza=ALFIL;
	tablero[7][8].tipo_pieza=CABALLO;
	tablero[8][8].tipo_pieza=TORRE;

	for (x=1; x<= 8; x++) {
		tablero[x][3].tipo_pieza=NINGUNA;
		tablero[x][4].tipo_pieza=NINGUNA;
		tablero[x][5].tipo_pieza=NINGUNA;
		tablero[x][6].tipo_pieza=NINGUNA;
	}
	
	//color piezas
	for(x=1; x<=8; x++)
	{
		tablero[x][1].color_pieza=NEGRO;
		tablero[x][2].color_pieza=NEGRO;
		tablero[x][7].color_pieza=BLANCO;
		tablero[x][8].color_pieza=BLANCO;
	}

}


void inicializar_estado(struct s_estado *estado)
{
	estado->n_movim=0;
	estado->tipo_blancas=HUMANO;
	estado->tipo_negras=HUMANO;
	estado->turno=BLANCO;
}

void inicializar_ncurses(struct s_casilla tablero[9][9])
{
	initscr();
	keypad(stdscr,1);
	cbreak();
	if (has_colors())
		{
		start_color();
		}
	echo();
	//definimos los colores que utizaremos en el porgrama
	init_pair(1,COLOR_WHITE,COLOR_BLACK);
	init_pair(2,COLOR_BLACK,COLOR_WHITE);
	init_pair(3,COLOR_WHITE,COLOR_WHITE);
	init_pair(4,COLOR_BLACK,COLOR_BLACK);
	init_pair(5,COLOR_BLACK,COLOR_YELLOW);
	init_pair(6,COLOR_YELLOW,COLOR_WHITE);
	init_pair(7,COLOR_BLUE,COLOR_BLUE);
	init_pair(8,COLOR_GREEN,COLOR_BLUE);
	bkgd(COLOR_PAIR(5));
}
	
int pintar_tablero(struct s_casilla tablero[9][9])
{

	int i,j,x=2,y=1,aux,z;
	int px,py;
	char letra;
	int n;
	
	attron(A_BOLD);
	move(1,0);
	
	   
	//pintamos el tablero
	for(i=0;i<8;i++)
		{
		for (j=0;j<4;j++)
			{
			attron(COLOR_PAIR(x));
			printw("       ");
			attron(COLOR_PAIR(y));
			printw("       ");
			}
			printw("\n");
		for (z=0;z<4;z++)
			{
			attron(COLOR_PAIR(x));
			printw("       ");
			attron(COLOR_PAIR(y));
			printw("       ");
			}
			printw("\n");
		for (z=0;z<4;z++)
			{
			attron(COLOR_PAIR(x));
			printw("       ");
			attron(COLOR_PAIR(y));
			printw("       ");
			}
			printw("\n");

		aux=x;
		x=y;
		y=aux;
		}
		
		
	for (i=1; i<=8; i++)
	  for (j=1; j<=8; j++)
	  {
	     if ((tablero[i][j].color_pieza == BLANCO) && (tablero[i][j].color_casilla == BLANCO))
	        attron(COLOR_PAIR(3));
	     if ((tablero[i][j].color_pieza == BLANCO) && (tablero[i][j].color_casilla == NEGRO))
	        attron(COLOR_PAIR(1));
	     if ((tablero[i][j].color_pieza == NEGRO) && (tablero[i][j].color_casilla == BLANCO))
	     	attron(COLOR_PAIR(2));
	     if ((tablero[i][j].color_pieza == NEGRO) && (tablero[i][j].color_casilla == NEGRO))
	     	attron(COLOR_PAIR(4));
	     if (tablero[i][j].tipo_pieza == NINGUNA)
	     {
	         if (tablero[i][j].color_casilla == BLANCO) attron(COLOR_PAIR(3));
	         if (tablero[i][j].color_casilla == NEGRO) attron(COLOR_PAIR(4));
	     }
	     px=((i-1)*7)+3;
	     py=((j-1)*3)+2;
	     move(py,px);
	     printw("%c", tablero[i][j].tipo_pieza);
	}
	//colocamos en el tablero las letras
	letra = 'A';
	for (i=0; i<56; i=i+7)
	{
	    move(26,i);
	    attron(COLOR_PAIR(6));
	    printw("   %c   ", letra);
	    letra++;
	}
	
	n=1;
	//colocamos en el tablero los numeros
	for (i=2; i<24; i=i+3)
	{
		move(i,58);
		attron(COLOR_PAIR(6));
		printw("  %i  ", n);
		n++;
	}
	//pintamos el recuadro de seleccionar el origen y destino
	attron(COLOR_PAIR(7));
	move(3,70);
	printw("                                                 ");
	move(4,70);
	printw("                                                 ");
	move(5,70);
	printw("                                                 ");
	move(6,70);
	printw("                                                 ");
	move(7,70);
	printw("                                                 ");	
	move(8,70);
	printw("                                                 ");
	move(9,70);
	printw("                                                 ");
	move(10,70);
	printw("                                                 ");
	move(11,70);
	printw("                                                 ");
	move(12,70);
	printw("                                                 ");
	move(13,70);
	printw("                                                 ");
	move(14,70);
	printw("                                                 ");
	move(15,70);
	printw("                                                 ");
	move(16,70);
	printw("                                                 ");
	
	
	refresh();
	
return 0;
}

void mover_humano(struct s_casilla tablero[9][9], struct s_estado estado)
{
	int fila1, columna1;
	int fila2, columna2;
	int c;
	
	//cambiamos el turno
	move(3,79);
	if (estado.turno == BLANCO)
	{	
		attron(COLOR_PAIR(8));
		printw("TURNO BLANCAS");
	}
	
	else
	{
		attron(COLOR_PAIR(8));
		printw("TURNO NEGRAS");
	}
	
	refresh();
	 
	do
	{
	   elegir_origen(&columna1, &fila1);
	   elegir_destino(&columna2, &fila2);
	   c = comprobar_movimiento(estado, tablero, columna1, fila1, columna2, fila2);
	   if (c == 1)
	       mover(tablero,&columna1, &fila1, &columna2, &fila2);
	   else
	   {
		move(15,70);
    		printw("Cuidado movimiento erroneo, sigue el mismo turno");
		refresh();
		getch();
		move (15,70);
		attron(COLOR_PAIR(7));
		printw("                                                 ");
	   }
	}
	while (c == 0);

}

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


void elegir_origen(int *xo, int *yo)
{
	char c;
	
	
	move(5,79);
	attron(COLOR_PAIR(8));
	printw("SELECCIONE ORIGEN");
	move(6,79);
	printw("Columna (A-H):");
	c = getch();
	*xo=convertir(c);
	move(7,79);
	printw("Fila (1-8):");
	c = getch();
	*yo=c - 48;
}

void elegir_destino(int *xd, int *yd)
{
	
	char c;
	
	move(10,79);
	attron(COLOR_PAIR(8));
	printw("SELECCIONE DESTINO:");
	move(11,79);
	printw("Columna (A-H):");
	c = getch();
	*xd=convertir(c);
	move(12,79);
	printw("Fila (1-8):");
	c= getch();
	*yd=c - 48;
}

void mover(struct s_casilla tablero[9][9], int *columna1, int *fila1, int *columna2, int *fila2)
{
	tablero[*columna2][*fila2].tipo_pieza = tablero[*columna1][*fila1].tipo_pieza;
	tablero[*columna2][*fila2].color_pieza = tablero[*columna1][*fila1].color_pieza;
	tablero[*columna1][*fila1].tipo_pieza = NINGUNA;
	tablero[*columna1][*fila1].color_pieza = NINGUNA;
}

int comprobar_movimiento(struct s_estado estado, struct s_casilla tablero[9][9], int xo, int yo, int xd, int yd)
{
        int n = 0;

	switch (tablero[xo][yo].tipo_pieza)
	{
	    case 'P': n = comprobar_movimiento_peon(estado, tablero, xo, yo, xd, yd); break;
	    case 'R': n = comprobar_movimiento_rey(estado, tablero, xo, yo, xd, yd); break;
	    case 'C': n = comprobar_movimiento_caballo(estado, tablero, xo, yo, xd, yd);break;
	    case 'T': n = comprobar_movimiento_torre(estado, tablero, xo, yo, xd, yd); break;
	    case 'A': n = comprobar_movimiento_alfil(estado, tablero, xo, yo, xd, yd); break;
	    case 'D': n = comprobar_movimiento_dama(estado, tablero, xo, yo, xd, yd); break;
	}
return n;

}

int comprobar_movimiento_peon(struct s_estado estado, struct s_casilla tablero[9][9], int xo, int yo, int xd, int yd)
{
	int correcto = 0;	

	//definimos la tirada del peon blanco
	if(estado.turno == 'B')
	{
		//se mueve una casilla
		if((xd == xo) && (yd == yo-1) && (tablero [xd][yd].tipo_pieza == NINGUNA))
			correcto=1;
		//se mueve dos casillas en la primera tirada
		if((yo == 7) && (xd == xo) && (yd == yo-2) && (tablero [xd][yo-1].tipo_pieza == NINGUNA) && (tablero[xo][yo-2].tipo_pieza == NINGUNA))
			correcto=1;
		//come hacia la izquierda
		if((yd == yo-1) && (xd == xo-1) && (tablero[xd][yd].color_pieza == NINGUNA))
			correcto=1;
		//come hacia la izquierda
		if((yd == yo-1) && (xd == xo+1) && (tablero[xd][yd].color_pieza == NINGUNA))
			correcto=1;
	}
	
	//definimos la tirada del peon negro
	if(estado.turno == 'N')
	{
		//se mueve una casilla
		if((xd == xo) && (yd == yo+1) && (tablero [xd][yd].tipo_pieza == NINGUNA))
			correcto=1;
		//se mueve dos casillas en la priemra tirada
		if((yo == 2) && (xd == xo) && (yd == yo+2) && (tablero [xd][yo+1].tipo_pieza == NINGUNA) && (tablero[xo][yo+2].tipo_pieza == NINGUNA))
			correcto=1;
		//come hacia la izquierda
		if((yd == yo+1) && (xd == xo+1) && (tablero[xd][yd].color_pieza == NINGUNA))
			correcto=1;
		//come hacia la izquierda
		if((yd == yo+1) && (xd == xo-1) && (tablero[xd][yd].color_pieza == NINGUNA))
			correcto=1;
	}
return correcto;
}

int comprobar_movimiento_rey(struct s_estado estado, struct s_casilla tablero[9][9], int xo, int yo, int xd, int yd)
{
	int correcto =0;
	
	if(tablero[xo][yo].color_pieza=='B')
	{
		if ((tablero[xd][yd].tipo_pieza == NINGUNA) || ((tablero[xd][yd].tipo_pieza != NINGUNA) && (tablero[xd][yd].color_pieza!='B')))
		{
			//se mueve en todas las direcciones de una casilla en una
			//tirada de las blancas
			if((xd==xo-1)&&(yd==yo-1)) correcto=1;
			if((xd==xo)&&(yd==yo-1)) correcto=1;
			if((xd==xo+1)&&(yd==yo-1)) correcto=1;
			if((xd==xo-1)&&(yd==yo)) correcto=1;
			if((xd==xo+1)&&(yd==yo)) correcto=1;
			if((xd==xo-1)&&(yd==yo+1)) correcto=1;
			if((xd==xo)&&(yd==yo+1)) correcto=1;
			if((xd==xo+1)&&(yd==yo+1)) correcto=1;
		}
	}
	if(tablero[xo][yo].color_pieza=='N')
	{
		//se mueve en todas las direcciones de una casilla en una
		//tirada de las negras
		if ((tablero[xd][yd].tipo_pieza == NINGUNA) || ((tablero[xd][yd].tipo_pieza != NINGUNA) && (tablero[xd][yd].color_pieza!='N')))
		{
			if((xd==xo-1)&&(yd==yo-1)) correcto=1;
			if((xd==xo)&&(yd==yo-1)) correcto=1;
			if((xd==xo+1)&&(yd==yo-1)) correcto=1;
			if((xd==xo-1)&&(yd==yo)) correcto=1;
			if((xd==xo+1)&&(yd==yo)) correcto=1;
			if((xd==xo-1)&&(yd==yo+1)) correcto=1;
			if((xd==xo)&&(yd==yo+1)) correcto=1;
			if((xd==xo+1)&&(yd==yo+1)) correcto=1;
		}
	}
	return correcto;
}
	
int comprobar_movimiento_caballo(struct s_estado estado,struct s_casilla tablero[9][9],int xo, int yo,int xd,int yd )
{
	int correcto=0;

	//se mueve dos horizontales izquierda y una vertical hacia arriba
	if((xd==xo-2)&&(yd==yo-1)&&(tablero[xd][yd].color_pieza!=estado.turno))
		correcto=1;
	//se mueve dos horizontales derecha y unda vertical hacia abajo
	if((xd==xo-2)&&(yd==yo+1)&&(tablero[xd][yd].color_pieza!=estado.turno))
		correcto=1;
	//se mueve una horizontal hacia la izquierda y dos verticales hacia abajo
	if((xd==xo-1)&&(yd==yo+2)&&(tablero[xd][yd].color_pieza!=estado.turno))
		correcto=1;
	//se mueve una horozontal hacia la izquierda y dos verticales hacia arriba
	if((xd==xo-1)&&(yd==yo-2)&&(tablero[xd][yd].color_pieza!=estado.turno))
		correcto=1;
	//se mueve dos horizontales hacia la derecha y una verical hacia arriba
	if((xd==xo+2)&&(yd==yo-1)&&(tablero[xd][yd].color_pieza!=estado.turno))
		correcto=1;
	//se mueve dos horizontales hacia la derecha y una vertical hacia abajo
	if((xd==xo+2)&&(yd==yo+1)&&(tablero[xd][yd].color_pieza!=estado.turno))
		correcto=1;
	//se mueve una horizontal hacia la derecha y dos verticales hacia abajo
	if((xd==xo+1)&&(yd==yo+2)&&(tablero[xd][yd].color_pieza!=estado.turno))
		correcto=1;
	//se mueve una horizontal hacia la derecha y dos verticales hacia arriba
	if((xd==xo+1)&&(yd==yo-2)&&(tablero[xd][yd].color_pieza!=estado.turno))
		correcto=1;
	

	return correcto;
}		

int comprobar_movimiento_torre(struct s_estado estado,struct s_casilla tablero[9][9],int xo, int yo,int xd,int yd)
{
	int correcto=1, i;
	
	//la torre se mueve verticalmente
	if((xo == xd) && (yo != yd))
	{
		if( yo > yd)		// La torre se mueve hacia ARRIBA
		{
			for(i=yo-1; i>=yd+1; i--)
			{
				if(tablero[xo][i].tipo_pieza!= NINGUNA)
					correcto=0;
			}
		}
		else			// La torre se mueve hacia ABAJO
		{
			for(i=yo+1; i<=yd-1; i++)
			{
				if(tablero[xo][i].tipo_pieza!=NINGUNA)
					correcto=0;
			}
		}
	}
	
	//la torre se mueve horizontalmente
	if((xo!=xd) && (yo==yd))
	{
		if( xo > xd)		//la torre se mueve hacia la IZQUIERDA
		{
			for(i=xo-1; i>=xd+1; i--)
			{
				if(tablero[i][yo].tipo_pieza!=NINGUNA) 
					correcto=0;
				
			}
		}
		else			//la torre se mueve hacia la DERECHA
		{
			for(i=xo+1; i<=xd-1; i++)
			{
				if(tablero[i][yo].tipo_pieza!=NINGUNA) 
					correcto=0;
				
			}
		}
	}
	
	//aqui comprubo que no es de mi color
	if (tablero[xd][yd].color_pieza==estado.turno)
		correcto=0;
		
return correcto;
}

int comprobar_movimiento_alfil(struct s_estado estado,struct s_casilla tablero[9][9],int xo, int yo,int xd,int yd)
{
   int correcto=1, c, f;
   
   //el alfil se mueve hacia ARRIBA y hacia la DERECHA
	if((xd>xo) && (yd<yo))
   	{
   		c=xo+1;
		f=yo-1;
	
		while((c<= xd-1) && (f>= yd-1))
		{
			if(tablero[c][f].tipo_pieza != NINGUNA)
				correcto=0;
			c++;
			f--;
		}
	}
   //el alfil se muve hacia ARRIBA Y hacia IZQUIERDA
	if((xd<xo) && (yd<yo))
   	{
   		c=xo-1;
		f=yo-1;
	
		while((c>= xd-1) && (f>= yd-1))
		{
			if(tablero[c][f].tipo_pieza != NINGUNA)
				correcto=0;
			c--;
			f--;
		}
	}
    //el alfil se mueve hacia ABAJO y hacia la DERECHA
	if((xd>xo) && (yd>yo))
   	{
   		c=xo+1;
		f=yo+1;
	
		while((c<= xd-1) && (f<= yd-1))
		{
			if(tablero[c][f].tipo_pieza != NINGUNA)
				correcto=0;
			c++;
			f++;
		}
	}
    //el alfil se mueve hacia ABAJO y hacia la IZQUIERDA
	if((xd<xo) && (yd<yo))
   	{
   		c=xo-1;
		f=yo+1;
	
		while((c>= xd-1) && (f<= yd-1))
		{
			if(tablero[c][f].tipo_pieza != NINGUNA)
				correcto=0;
			c--;
			f++;
		}
	}
	
	//aqui comprubo que no es de mi color
	if (tablero[xd][yd].color_pieza==estado.turno)
		correcto=0;
		
return correcto;
 
}
int comprobar_movimiento_dama(struct s_estado estado,struct s_casilla tablero[9][9],int xo, int yo,int xd,int yd)
{
	int comp1, comp2, correcto;
	
	comp1=comprobar_movimiento_torre(estado, tablero, xo, yo, xd, yd);
	comp2=comprobar_movimiento_alfil(estado, tablero, xo, yo, xd, yd);
	
	//compruebo que lo que se devuelve de los movimientos de la torre y el alfil es un uno
	//con lo cual los movimietnos son correctos
	if(( comp1 == 1) || (comp2 ==1))
		correcto=1;
	else
		correcto=0;
return correcto;

}


		


	
	
	
	
	

