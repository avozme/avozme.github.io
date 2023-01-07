#include <ncurses.h>
#include "ajedrez6.h"
#include "movs.h"


void comprobar_jaque(struct s_casilla tablero[9][9]);


void mover(struct s_casilla tablero[9][9],struct s_estado *estado)
{
	char color,pieza; int i=0; int Fo,Fd,Cd,Co,C,F ; int txt; int V;
	attron(COLOR_PAIR(7));
		
	do
     	{
		do
		{	
		
			do
			{
				attron(COLOR_PAIR(7));
				move(4,70);
				printw("Seleccione ficha origen");
				move(5,70);
				printw("Columna(A-H): ");
				txt=getch();
				Co=convertir_columna(tablero,txt);
				if(Co==12) menu(tablero,2,estado);
			}
			while((Co!=1)&&(Co!=2)&&(Co!=3)&&(Co!=4)&&(Co!=5)&&(Co!=6)&&(Co!=7)&&(Co!=8)); //comprueba que no sale del tablero
	
			do
			{	
				attron(COLOR_PAIR(7));
				move(6,70);
				printw("Fila(1-8): ");
				txt=getch();
				Fo=convertir_fila(txt);
			}
			while((Fo!=1)&&(Fo!=2)&&(Fo!=3)&&(Fo!=4)&&(Fo!=5)&&(Fo!=6)&&(Fo!=7)&&(Fo!=8)); //comprueba que no sale del tablero
				
			if(tablero[Fo][Co].pieza==' ') 
			{
				attron(COLOR_PAIR(2));
				move(28+i,50);
				printw(" NO HAY NINGUNA PIEZA EN ESA CASILLA, INTENTELO DE NUEV0");refresh;
				i++;
			}
			else
			{	
				if(estado->turno!=tablero[Fo][Co].color_pieza)
				{
					attron(COLOR_PAIR(2));
					move(28+i,50);
					printw(" NO ES TU TURNO            ");refresh;
					i++; 
				
				}	
			}
		}
		while ((tablero[Fo][Co].pieza==' ')||(estado->turno!=tablero[Fo][Co].color_pieza));	//comprueba que haya alguna pieza en la casilla seleccionada y que sea del jugador al que le toke turno
	
			
	
	
		do
		{
			move(8,70);
			printw("Selecciones casilla destino");
			move(9,70);
			printw("Columna(A-H): ");
			txt=getch();
			Cd=convertir_columna(tablero,txt);
		}
		while((Cd!=1)&&(Cd!=2)&&(Cd!=3)&&(Cd!=4)&&(Cd!=5)&&(Cd!=6)&&(Cd!=7)&&(Cd!=8));; //igual que en origen
	
		do
		{
			move(10,70);
			printw("Fila(1-8): ");
			txt=getch();
			Fd=convertir_fila(txt);
		}
		while((Fd!=1)&&(Fd!=2)&&(Fd!=3)&&(Fd!=4)&&(Fd!=5)&&(Fd!=6)&&(Fd!=7)&&(Fd!=8));//igual que en origen
		V=comprobar_movimiento(tablero,Fo,Co,Fd,Cd);
     		 	
		if(V!=1)
		{
			attron(COLOR_PAIR(2));
			move(28+i,50);
			printw("EL MOVIMIENTO REALIZADO NO ES CORRECTO");
		 	i++;
		}
	}
      	while (V!=1); //comprueba que el movimiento sea valido, si lo es sale
	
	
	pieza=tablero[Fo][Co].pieza;		//guardamos la pieza oigen en una variable
	color=tablero[Fo][Co].color_pieza;	// y su color
	tablero[Fo][Co].color_pieza='V';	// y ponemos la pieza origne como vacia
	tablero[Fo][Co].pieza=' ';
	tablero[Fd][Cd].color_pieza=color;	// copiamos el color y puieza orgien alamcenado antes en destino
	tablero[Fd][Cd].pieza=pieza;
	
	if (estado->turno=='B') estado->turno='N'; //intercambio de turno
	else estado->turno = 'B';
	dibujar_tablero(tablero);
	refresh();
	
	
}

int convertir_columna(struct s_casilla tablero[9][9],int txt)
{int C;
	switch (txt)
	{
		case 'A': C=1; break;
		case 'C': C=3; break;
		case 'B': C=2; break;
		case 'D': C=4; break;
		case 'E': C=5; break; 
		case 'F': C=6; break;
		case 'G': C=7; break;
		case 'H': C=8; break;
		case 'Q': C=12;break;
	}
	return C;
}

int convertir_fila(int txt)
{ int F;
	switch (txt)
	{
		case '1': F=1; break;
		case '3': F=3; break;
		case '2': F=2; break;
		case '4': F=4; break;
		case '5': F=5; break; 
		case '6': F=6; break;
		case '7': F=7; break;
		case '8': F=8; break;
	}
	return F;
}

int comprobar_movimiento(struct s_casilla tablero[9][9],int Fo, int Co, int Fd, int Cd)
{
	int valido=0;
	switch(tablero[Fo][Co].pieza)
	{
		case 'C':	//movimientos caballo
			if(tablero[Fo][Co].color_pieza!=tablero[Fd][Cd].color_pieza) //si el color de la pieza origen es ditinto 
			{	if((Cd==Co-1) && (Fd==Fo+2)) valido=1; 			//de la de destino
				if((Cd==Co-1) && (Fd==Fo-2)) valido=1; 
				if((Cd==Co+1) && (Fd==Fo+2)) valido=1; 
				if((Cd==Co+1) && (Fd==Fo-2)) valido=1; 
				if((Cd==Co+2) && (Fd==Fo-1)) valido=1; 	
				if((Cd==Co+2) && (Fd==Fo+1)) valido=1; 
				if((Cd==Co-2) && (Fd==Fo+1)) valido=1; 
				if((Cd==Co-2) && (Fd==Fo-1)) valido=1; 
			}break;
		case 'P':		//movimientos peon
			if (tablero[Fo][Co].color_pieza=='B')
			{
				if((Cd==Co) && (Fd==Fo+1)&&(tablero[Fd][Cd].color_pieza=='V')) valido=1;
				if((Cd==Co) && (Fd==Fo+2) && (Fo==2)&&(tablero[Fd][Cd].color_pieza=='V')&&(tablero[Fd-1][Cd].color_pieza=='V')) valido=1;
				if((Cd==Co-1) && (Fd==Fo+1)&&(tablero[Fd][Cd].color_pieza=='N')) valido=1;
				if((Cd==Co+1) && (Fd==Fo+1)&&(tablero[Fd][Cd].color_pieza=='N')) valido=1;
			}
			if (tablero[Fo][Co].color_pieza=='N')
			{
				
				if ((Cd==Co) && (Fd==Fo-1)) valido=1;
				if ((Cd==Co+1) && (Fd==Fo-1) && (tablero[Fd][Cd].color_pieza=='B')) valido=1;
				if ((Cd==Co-1) && (Fd==Fo-1) && (tablero[Fd][Cd].color_pieza=='B')) valido=1;	
				if((Cd==Co) && (Fd==Fo-2) && (Fo==7)&&(tablero[Fd][Cd].color_pieza=='V')) valido=1;
				
			}break;
		case 'R':		//movimientos rey
			if(tablero[Fo][Co].color_pieza=='B')
			{	
				 if(tablero[Fd][Cd].color_pieza!='B')
				 {
				  	if((Cd==Co)&&(Fd==Fo+1)) valido=1;	
					if((Cd==Co)&&(Fd=Fo-1)) valido=1;
					if((Cd==Co+1)&&(Fd==Fo+1)) valido=1;
					if((Cd==Co+1)&&(Fd==Fo-1)) valido=1;
					if((Cd==Co+1)&&(Fd==Fo)) valido=1;
					if((Cd==Co-1)&&(Fd==Fo-1)) valido=1;
					if((Cd==Co-1)&&(Fd==Fo+1)) valido=1;
					if((Cd==Co-1)&&(Fd==Fo)) valido=1;
					
					
				}
			}
			if(tablero[Fo][Co].color_pieza=='N')
			{	
				 if(tablero[Fd][Cd].color_pieza!='N')
				 {
				 	
				  	if((Cd==Co) && (Fd==Fo+1)) valido=1;	
					if((Cd==Co) && (Fd==Fo-1)) valido=1;
					if((Cd==Co+1)&&(Fd==Fo+1)) valido=1;
					if((Cd==Co+1)&&(Fd==Fo-1)) valido=1;
					if((Cd==Co+1)&&(Fd==Fo)) valido=1;
					if((Cd==Co-1) &&(Fd==Fo-1)) valido=1;
					if((Cd==Co-1) &&(Fd==Fo+1)) valido=1;
					if((Cd==Co-1) &&(Fd==Fo)) valido=1;
					
				}
			}break;
		case 'T':	//movimientos torre
			if(tablero[Fo][Co].color_pieza!=tablero[Fd][Cd].color_pieza) 
			{
				if((Cd==Co+1)&&(Fd==Fo)) valido=1;
				if((Cd==Co+2)&&(Fd==Fo)&&(tablero[Fd][Cd-1].pieza==' ')) valido=1; 
				if((Cd==Co+3)&&(Fd==Fo)&&(tablero[Fd][Cd-2].pieza==' ')&&(tablero[Fd][Cd-1].pieza==' ')) valido=1;
				if((Cd==Co+4)&&(Fd==Fo)&&(tablero[Fd][Cd-3].pieza==' ')&&(tablero[Fd][Cd-2].pieza==' ')&&(tablero[Fd][Cd-1].pieza==' ')) valido=1;
				if((Cd==Co+5)&&(Fd==Fo)&&(tablero[Fd][Cd-4].pieza==' ')&&(tablero[Fd][Cd-3].pieza==' ')&&(tablero[Fd][Cd-2].pieza==' ')&&(tablero[Fd][Cd-1].pieza==' ')) valido=1;
				if((Cd==Co+6)&&(Fd==Fo)&&(tablero[Fd][Cd-5].pieza==' ')&&(tablero[Fd][Cd-4].pieza==' ')&&(tablero[Fd][Cd-3].pieza==' ')&&(tablero[Fd][Cd-2].pieza==' ')&&(tablero[Fd][Cd-1].pieza==' ')) valido=1;
				if((Cd==Co+7)&&(Fd==Fo)&&(tablero[Fd][Cd-6].pieza==' ')&&(tablero[Fd][Cd-5].pieza==' ')&&(tablero[Fd][Cd-4].pieza==' ')&&(tablero[Fd][Cd-3].pieza==' ')&&(tablero[Fd][Cd-2].pieza==' ')&&(tablero[Fd][Cd-1].pieza==' ')) valido=1;
				if((Cd==Co+8)&&(Fd==Fo)&&(tablero[Fd][Cd-7].pieza==' ')&&(tablero[Fd][Cd-6].pieza==' ')&&(tablero[Fd][Cd-5].pieza==' ')&&(tablero[Fd][Cd-4].pieza==' ')&&(tablero[Fd][Cd-3].pieza==' ')&&(tablero[Fd][Cd-2].pieza==' ')&&(tablero[Fd][Cd-1].pieza==' ')) valido=1;
					
				if((Cd==Co-1)&&(Fd==Fo)) valido=1;
				if((Cd==Co-2)&&(Fd==Fo)&&(tablero[Fd][Cd+1].pieza==' ')) valido=1; 
				if((Cd==Co-3)&&(Fd==Fo)&&(tablero[Fd][Cd+2].pieza==' ')&&(tablero[Fd][Cd+1].pieza==' ')) valido=1;
				if((Cd==Co-4)&&(Fd==Fo)&&(tablero[Fd][Cd+3].pieza==' ')&&(tablero[Fd][Cd+2].pieza==' ')&&(tablero[Fd][Cd+1].pieza==' ')) valido=1;
				if((Cd==Co-5)&&(Fd==Fo)&&(tablero[Fd][Cd+4].pieza==' ')&&(tablero[Fd][Cd+3].pieza==' ')&&(tablero[Fd][Cd+2].pieza==' ')&&(tablero[Fd][Cd+1].pieza==' ')) valido=1;
				if((Cd==Co-6)&&(Fd==Fo)&&(tablero[Fd][Cd+5].pieza==' ')&&(tablero[Fd][Cd+4].pieza==' ')&&(tablero[Fd][Cd+3].pieza==' ')&&(tablero[Fd][Cd+2].pieza==' ')&&(tablero[Fd][Cd+1].pieza==' ')) valido=1;
				if((Cd==Co-7)&&(Fd==Fo)&&(tablero[Fd][Cd+6].pieza==' ')&&(tablero[Fd][Cd+5].pieza==' ')&&(tablero[Fd][Cd+4].pieza==' ')&&(tablero[Fd][Cd+3].pieza==' ')&&(tablero[Fd][Cd+2].pieza==' ')&&(tablero[Fd][Cd+1].pieza==' ')) valido=1;
				if((Cd==Co-8)&&(Fd==Fo)&&(tablero[Fd][Cd+7].pieza==' ')&&(tablero[Fd][Cd+6].pieza==' ')&&(tablero[Fd][Cd+5].pieza==' ')&&(tablero[Fd][Cd+4].pieza==' ')&&(tablero[Fd][Cd+3].pieza==' ')&&(tablero[Fd][Cd+2].pieza==' ')&&(tablero[Fd][Cd+1].pieza==' ')) valido=1;
			
			
				if((Fd==Fo+1)&&(Cd==Co)) valido=1;
				if((Fd==Fo+2)&&(Cd==Co)&&(tablero[Fd-1][Cd].pieza==' ')) valido=1; 
				if((Fd==Fo+3)&&(Cd==Co)&&(tablero[Fd-2][Cd].pieza==' ')&&(tablero[Fd-1][Cd].pieza==' ')) valido=1;
				if((Fd==Fo+4)&&(Cd==Co)&&(tablero[Fd-3][Cd].pieza==' ')&&(tablero[Fd-2][Cd].pieza==' ')&&(tablero[Fd-1][Cd].pieza==' ')) valido=1;
				if((Fd==Fo+5)&&(Cd==Co)&&(tablero[Fd-4][Cd].pieza==' ')&&(tablero[Fd-3][Cd].pieza==' ')&&(tablero[Fd-2][Cd].pieza==' ')&&(tablero[Fd-1][Cd].pieza==' ')) valido=1;
				if((Fd==Fo+6)&&(Cd==Co)&&(tablero[Fd-5][Cd].pieza==' ')&&(tablero[Fd-4][Cd].pieza==' ')&&(tablero[Fd-3][Cd].pieza==' ')&&(tablero[Fd-2][Cd].pieza==' ')&&(tablero[Fd-1][Cd].pieza==' ')) valido=1;
				if((Fd==Fo+7)&&(Cd==Co)&&(tablero[Fd-6][Cd].pieza==' ')&&(tablero[Fd-5][Cd].pieza==' ')&&(tablero[Fd-4][Cd].pieza==' ')&&(tablero[Fd-3][Cd].pieza==' ')&&(tablero[Fd-2][Cd].pieza==' ')&&(tablero[Fd-1][Cd].pieza==' ')) valido=1;
				if((Fd==Fo+8)&&(Cd==Co)&&(tablero[Fd-7][Cd].pieza==' ')&&(tablero[Fd-6][Cd].pieza==' ')&&(tablero[Fd-5][Cd].pieza==' ')&&(tablero[Fd-4][Cd].pieza==' ')&&(tablero[Fd-3][Cd].pieza==' ')&&(tablero[Fd-2][Cd].pieza==' ')&&(tablero[Fd+1][Cd].pieza==' ')) valido=1;
			
				if((Fd==Fo-1)&&(Cd==Co)) valido=1;
				if((Fd==Fo-2)&&(Cd==Co)&&(tablero[Fd+1][Cd].pieza==' ')) valido=1; 
				if((Fd==Fo-3)&&(Cd==Co)&&(tablero[Fd+2][Cd].pieza==' ')&&(tablero[Fd+1][Cd].pieza==' ')) valido=1;
				if((Fd==Fo-4)&&(Cd==Co)&&(tablero[Fd+3][Cd].pieza==' ')&&(tablero[Fd+2][Cd].pieza==' ')&&(tablero[Fd+1][Cd].pieza==' ')) valido=1;
				if((Fd==Fo-5)&&(Cd==Co)&&(tablero[Fd+4][Cd].pieza==' ')&&(tablero[Fd+3][Cd].pieza==' ')&&(tablero[Fd+2][Cd].pieza==' ')&&(tablero[Fd+1][Cd].pieza==' ')) valido=1;
				if((Fd==Fo-6)&&(Cd==Co)&&(tablero[Fd+5][Cd].pieza==' ')&&(tablero[Fd+4][Cd].pieza==' ')&&(tablero[Fd+3][Cd].pieza==' ')&&(tablero[Fd+2][Cd].pieza==' ')&&(tablero[Fd+1][Cd].pieza==' ')) valido=1;
				if((Fd==Fo-7)&&(Cd==Co)&&(tablero[Fd+6][Cd].pieza==' ')&&(tablero[Fd+5][Cd].pieza==' ')&&(tablero[Fd+4][Cd].pieza==' ')&&(tablero[Fd+3][Cd].pieza==' ')&&(tablero[Fd+2][Cd].pieza==' ')&&(tablero[Fd+1][Cd].pieza==' ')) valido=1;
				if((Fd==Fo-8)&&(Cd==Co)&&(tablero[Fd+7][Cd].pieza==' ')&&(tablero[Fd+6][Cd].pieza==' ')&&(tablero[Fd+5][Cd].pieza==' ')&&(tablero[Fd+4][Cd].pieza==' ')&&(tablero[Fd+3][Cd].pieza==' ')&&(tablero[Fd+2][Cd].pieza==' ')&&(tablero[Fd+1][Cd].pieza==' ')) valido=1;
			
			}break;
			case 'A': 	//movimientos alfil
				if(tablero[Fo][Co].color_pieza!=tablero[Fd][Cd].color_pieza) 
			{
				if((Cd==Co+1)&&(Fd==Fo+1)) valido=1;
				if((Cd==Co+2)&&(Fd==Fo+2)&&(tablero[Fd-1][Cd-1].pieza==' ')) valido=1; 
				if((Cd==Co+3)&&(Fd==Fo+3)&&(tablero[Fd-2][Cd-2].pieza==' ')&&(tablero[Fd][Cd-1].pieza==' ')) valido=1;
				if((Cd==Co+4)&&(Fd==Fo+4)&&(tablero[Fd-3][Cd-3].pieza==' ')&&(tablero[Fd][Cd-2].pieza==' ')&&(tablero[Fd-1][Cd-1].pieza==' ')) valido=1;
				if((Cd==Co+5)&&(Fd==Fo+5)&&(tablero[Fd-4][Cd-4].pieza==' ')&&(tablero[Fd][Cd-3].pieza==' ')&&(tablero[Fd-2][Cd-2].pieza==' ')&&(tablero[Fd][Cd-1].pieza==' ')) valido=1;
				if((Cd==Co+6)&&(Fd==Fo+6)&&(tablero[Fd-5][Cd-5].pieza==' ')&&(tablero[Fd][Cd-4].pieza==' ')&&(tablero[Fd-3][Cd-3].pieza==' ')&&(tablero[Fd][Cd-2].pieza==' ')&&(tablero[Fd][Cd-1].pieza==' ')) valido=1;
				if((Cd==Co+7)&&(Fd==Fo+7)&&(tablero[Fd-6][Cd-6].pieza==' ')&&(tablero[Fd][Cd-5].pieza==' ')&&(tablero[Fd-4][Cd-4].pieza==' ')&&(tablero[Fd][Cd-3].pieza==' ')&&(tablero[Fd][Cd-2].pieza==' ')&&(tablero[Fd-1][Cd-1].pieza==' ')) valido=1;
				if((Cd==Co+8)&&(Fd==Fo+8)&&(tablero[Fd-7][Cd-7].pieza==' ')&&(tablero[Fd][Cd-6].pieza==' ')&&(tablero[Fd-5][Cd-5].pieza==' ')&&(tablero[Fd][Cd-4].pieza==' ')&&(tablero[Fd][Cd-3].pieza==' ')&&(tablero[Fd-5][Cd-2].pieza==' ')&&(tablero[Fd][Cd-1].pieza==' ')) valido=1;
			
				if((Cd==Co-1)&&(Fd==Fo-1)) valido=1;//faltan comprobar qnosea mismo color//
				if((Cd==Co-2)&&(Fd==Fo-2)&&(tablero[Fd+1][Cd+1].pieza==' ')) valido=1; 
				if((Cd==Co-3)&&(Fd==Fo-3)&&(tablero[Fd+2][Cd+2].pieza==' ')&&(tablero[Fd+1][Cd+1].pieza==' ')) valido=1;
				if((Cd==Co-4)&&(Fd==Fo-4)&&(tablero[Fd+3][Cd+3].pieza==' ')&&(tablero[Fd+2][Cd+2].pieza==' ')&&(tablero[Fd][Cd+1].pieza==' ')) valido=1;
				if((Cd==Co-5)&&(Fd==Fo-5)&&(tablero[Fd+4][Cd+4].pieza==' ')&&(tablero[Fd+3][Cd+3].pieza==' ')&&(tablero[Fd+2][Cd+2].pieza==' ')&&(tablero[Fd+1][Cd+1].pieza==' ')) valido=1;
				if((Cd==Co-6)&&(Fd==Fo-6)&&(tablero[Fd+5][Cd+5].pieza==' ')&&(tablero[Fd+4][Cd+4].pieza==' ')&&(tablero[Fd+3][Cd+3].pieza==' ')&&(tablero[Fd+2][Cd+2].pieza==' ')&&(tablero[Fd+1][Cd+1].pieza==' ')) valido=1;
				if((Cd==Co-7)&&(Fd==Fo-7)&&(tablero[Fd+6][Cd+6].pieza==' ')&&(tablero[Fd+5][Cd+5].pieza==' ')&&(tablero[Fd+4][Cd+4].pieza==' ')&&(tablero[Fd+3][Cd+3].pieza==' ')&&(tablero[Fd+2][Cd+2].pieza==' ')&&(tablero[Fd+1][Cd+1].pieza==' ')) valido=1;
				if((Cd==Co-8)&&(Fd==Fo-8)&&(tablero[Fd+7][Cd+7].pieza==' ')&&(tablero[Fd+6][Cd+6].pieza==' ')&&(tablero[Fd+5][Cd+5].pieza==' ')&&(tablero[Fd+4][Cd+4].pieza==' ')&&(tablero[Fd+3][Cd+3].pieza==' ')&&(tablero[Fd+2][Cd+2].pieza==' ')&&(tablero[Fd+1][Cd+1].pieza==' ')) valido=1;
			
			
				if((Fd==Fo+1)&&(Cd==Co-1)) valido=1;
				if((Fd==Fo+2)&&(Cd==Co-2)&&(tablero[Fd-1][Cd+1].pieza==' ')) valido=1; 
				if((Fd==Fo+3)&&(Cd==Co-3)&&(tablero[Fd-2][Cd+2].pieza==' ')&&(tablero[Fd-1][Cd+1].pieza==' ')) valido=1;
				if((Fd==Fo+4)&&(Cd==Co-4)&&(tablero[Fd-3][Cd+3].pieza==' ')&&(tablero[Fd-2][Cd+2].pieza==' ')&&(tablero[Fd-1][Cd+1].pieza==' ')) valido=1;
				if((Fd==Fo+5)&&(Cd==Co-5)&&(tablero[Fd-4][Cd+4].pieza==' ')&&(tablero[Fd-3][Cd+3].pieza==' ')&&(tablero[Fd-2][Cd+2].pieza==' ')&&(tablero[Fd-1][Cd+1].pieza==' ')) valido=1;
				if((Fd==Fo+6)&&(Cd==Co-6)&&(tablero[Fd-5][Cd+5].pieza==' ')&&(tablero[Fd-4][Cd+4].pieza==' ')&&(tablero[Fd-3][Cd+3].pieza==' ')&&(tablero[Fd-2][Cd+2].pieza==' ')&&(tablero[Fd-1][Cd+1].pieza==' ')) valido=1;
				if((Fd==Fo+7)&&(Cd==Co-7)&&(tablero[Fd-6][Cd+6].pieza==' ')&&(tablero[Fd-5][Cd+5].pieza==' ')&&(tablero[Fd-4][Cd+4].pieza==' ')&&(tablero[Fd-3][Cd+3].pieza==' ')&&(tablero[Fd-2][Cd+2].pieza==' ')&&(tablero[Fd-1][Cd+1].pieza==' ')) valido=1;
				if((Fd==Fo+8)&&(Cd==Co-8)&&(tablero[Fd-7][Cd+7].pieza==' ')&&(tablero[Fd-6][Cd+6].pieza==' ')&&(tablero[Fd-5][Cd+5].pieza==' ')&&(tablero[Fd-4][Cd+4].pieza==' ')&&(tablero[Fd-3][Cd+3].pieza==' ')&&(tablero[Fd-2][Cd+2].pieza==' ')&&(tablero[Fd-1][Cd+1].pieza==' ')) valido=1;
			
				if((Fd==Fo-1)&&(Cd==Co+1)) valido=1;
				if((Fd==Fo-2)&&(Cd==Co+2)&&(tablero[Fd+1][Cd-1].pieza==' ')) valido=1; 
				if((Fd==Fo-3)&&(Cd==Co+3)&&(tablero[Fd+2][Cd-2].pieza==' ')&&(tablero[Fd+1][Cd-1].pieza==' ')) valido=1;
				if((Fd==Fo-4)&&(Cd==Co+4)&&(tablero[Fd+3][Cd-3].pieza==' ')&&(tablero[Fd+2][Cd-2].pieza==' ')&&(tablero[Fd+1][Cd-1].pieza==' ')) valido=1;
				if((Fd==Fo-5)&&(Cd==Co+5)&&(tablero[Fd+4][Cd-4].pieza==' ')&&(tablero[Fd+3][Cd-3].pieza==' ')&&(tablero[Fd+2][Cd-2].pieza==' ')&&(tablero[Fd+1][Cd-1].pieza==' ')) valido=1;
				if((Fd==Fo-6)&&(Cd==Co+6)&&(tablero[Fd+5][Cd-5].pieza==' ')&&(tablero[Fd+4][Cd-4].pieza==' ')&&(tablero[Fd+3][Cd-3].pieza==' ')&&(tablero[Fd+2][Cd-2].pieza==' ')&&(tablero[Fd+1][Cd-1].pieza==' ')) valido=1;
				if((Fd==Fo-7)&&(Cd==Co+7)&&(tablero[Fd+6][Cd-6].pieza==' ')&&(tablero[Fd+5][Cd-5].pieza==' ')&&(tablero[Fd+4][Cd-4].pieza==' ')&&(tablero[Fd+3][Cd-3].pieza==' ')&&(tablero[Fd+2][Cd-2].pieza==' ')&&(tablero[Fd+1][Cd-1].pieza==' ')) valido=1;
				if((Fd==Fo-8)&&(Cd==Co+8)&&(tablero[Fd+7][Cd-7].pieza==' ')&&(tablero[Fd+6][Cd-6].pieza==' ')&&(tablero[Fd+5][Cd-5].pieza==' ')&&(tablero[Fd+4][Cd-4].pieza==' ')&&(tablero[Fd+3][Cd-3].pieza==' ')&&(tablero[Fd+2][Cd-2].pieza==' ')&&(tablero[Fd+1][Cd-1].pieza==' ')) valido=1;
				
			
			}break;
		case 'D':			//movimientos dama
			if(tablero[Fo][Co].color_pieza!=tablero[Fd][Cd].color_pieza) 
			{
				if((Cd==Co+1)&&(Fd==Fo)) valido=1;
				if((Cd==Co+2)&&(Fd==Fo)&&(tablero[Fd][Cd-1].pieza==' ')) valido=1; 
				if((Cd==Co+3)&&(Fd==Fo)&&(tablero[Fd][Cd-2].pieza==' ')&&(tablero[Fd][Cd-1].pieza==' ')) valido=1;
				if((Cd==Co+4)&&(Fd==Fo)&&(tablero[Fd][Cd-3].pieza==' ')&&(tablero[Fd][Cd-2].pieza==' ')&&(tablero[Fd][Cd-1].pieza==' ')) valido=1;
				if((Cd==Co+5)&&(Fd==Fo)&&(tablero[Fd][Cd-4].pieza==' ')&&(tablero[Fd][Cd-3].pieza==' ')&&(tablero[Fd][Cd-2].pieza==' ')&&(tablero[Fd][Cd-1].pieza==' ')) valido=1;
				if((Cd==Co+6)&&(Fd==Fo)&&(tablero[Fd][Cd-5].pieza==' ')&&(tablero[Fd][Cd-4].pieza==' ')&&(tablero[Fd][Cd-3].pieza==' ')&&(tablero[Fd][Cd-2].pieza==' ')&&(tablero[Fd][Cd-1].pieza==' ')) valido=1;
				if((Cd==Co+7)&&(Fd==Fo)&&(tablero[Fd][Cd-6].pieza==' ')&&(tablero[Fd][Cd-5].pieza==' ')&&(tablero[Fd][Cd-4].pieza==' ')&&(tablero[Fd][Cd-3].pieza==' ')&&(tablero[Fd][Cd-2].pieza==' ')&&(tablero[Fd][Cd-1].pieza==' ')) valido=1;
				if((Cd==Co+8)&&(Fd==Fo)&&(tablero[Fd][Cd-7].pieza==' ')&&(tablero[Fd][Cd-6].pieza==' ')&&(tablero[Fd][Cd-5].pieza==' ')&&(tablero[Fd][Cd-4].pieza==' ')&&(tablero[Fd][Cd-3].pieza==' ')&&(tablero[Fd][Cd-2].pieza==' ')&&(tablero[Fd][Cd-1].pieza==' ')) valido=1;
					
				if((Cd==Co-1)&&(Fd==Fo)) valido=1;
				if((Cd==Co-2)&&(Fd==Fo)&&(tablero[Fd][Cd+1].pieza==' ')) valido=1; 
				if((Cd==Co-3)&&(Fd==Fo)&&(tablero[Fd][Cd+2].pieza==' ')&&(tablero[Fd][Cd+1].pieza==' ')) valido=1;
				if((Cd==Co-4)&&(Fd==Fo)&&(tablero[Fd][Cd+3].pieza==' ')&&(tablero[Fd][Cd+2].pieza==' ')&&(tablero[Fd][Cd+1].pieza==' ')) valido=1;
				if((Cd==Co-5)&&(Fd==Fo)&&(tablero[Fd][Cd+4].pieza==' ')&&(tablero[Fd][Cd+3].pieza==' ')&&(tablero[Fd][Cd+2].pieza==' ')&&(tablero[Fd][Cd+1].pieza==' ')) valido=1;
				if((Cd==Co-6)&&(Fd==Fo)&&(tablero[Fd][Cd+5].pieza==' ')&&(tablero[Fd][Cd+4].pieza==' ')&&(tablero[Fd][Cd+3].pieza==' ')&&(tablero[Fd][Cd+2].pieza==' ')&&(tablero[Fd][Cd+1].pieza==' ')) valido=1;
				if((Cd==Co-7)&&(Fd==Fo)&&(tablero[Fd][Cd+6].pieza==' ')&&(tablero[Fd][Cd+5].pieza==' ')&&(tablero[Fd][Cd+4].pieza==' ')&&(tablero[Fd][Cd+3].pieza==' ')&&(tablero[Fd][Cd+2].pieza==' ')&&(tablero[Fd][Cd+1].pieza==' ')) valido=1;
				if((Cd==Co-8)&&(Fd==Fo)&&(tablero[Fd][Cd+7].pieza==' ')&&(tablero[Fd][Cd+6].pieza==' ')&&(tablero[Fd][Cd+5].pieza==' ')&&(tablero[Fd][Cd+4].pieza==' ')&&(tablero[Fd][Cd+3].pieza==' ')&&(tablero[Fd][Cd+2].pieza==' ')&&(tablero[Fd][Cd+1].pieza==' ')) valido=1;
			
			
				if((Fd==Fo+1)&&(Cd==Co)) valido=1;
				if((Fd==Fo+2)&&(Cd==Co)&&(tablero[Fd-1][Cd].pieza==' ')) valido=1; 
				if((Fd==Fo+3)&&(Cd==Co)&&(tablero[Fd-2][Cd].pieza==' ')&&(tablero[Fd-1][Cd].pieza==' ')) valido=1;
				if((Fd==Fo+4)&&(Cd==Co)&&(tablero[Fd-3][Cd].pieza==' ')&&(tablero[Fd-2][Cd].pieza==' ')&&(tablero[Fd-1][Cd].pieza==' ')) valido=1;
				if((Fd==Fo+5)&&(Cd==Co)&&(tablero[Fd-4][Cd].pieza==' ')&&(tablero[Fd-3][Cd].pieza==' ')&&(tablero[Fd-2][Cd].pieza==' ')&&(tablero[Fd-1][Cd].pieza==' ')) valido=1;
				if((Fd==Fo+6)&&(Cd==Co)&&(tablero[Fd-5][Cd].pieza==' ')&&(tablero[Fd-4][Cd].pieza==' ')&&(tablero[Fd-3][Cd].pieza==' ')&&(tablero[Fd-2][Cd].pieza==' ')&&(tablero[Fd-1][Cd].pieza==' ')) valido=1;
				if((Fd==Fo+7)&&(Cd==Co)&&(tablero[Fd-6][Cd].pieza==' ')&&(tablero[Fd-5][Cd].pieza==' ')&&(tablero[Fd-4][Cd].pieza==' ')&&(tablero[Fd-3][Cd].pieza==' ')&&(tablero[Fd-2][Cd].pieza==' ')&&(tablero[Fd-1][Cd].pieza==' ')) valido=1;
				if((Fd==Fo+8)&&(Cd==Co)&&(tablero[Fd-7][Cd].pieza==' ')&&(tablero[Fd-6][Cd].pieza==' ')&&(tablero[Fd-5][Cd].pieza==' ')&&(tablero[Fd-4][Cd].pieza==' ')&&(tablero[Fd-3][Cd].pieza==' ')&&(tablero[Fd-2][Cd].pieza==' ')&&(tablero[Fd+1][Cd].pieza==' ')) valido=1;
			
				if((Fd==Fo-1)&&(Cd==Co)) valido=1;
				if((Fd==Fo-2)&&(Cd==Co)&&(tablero[Fd+1][Cd].pieza==' ')) valido=1; 
				if((Fd==Fo-3)&&(Cd==Co)&&(tablero[Fd+2][Cd].pieza==' ')&&(tablero[Fd+1][Cd].pieza==' ')) valido=1;
				if((Fd==Fo-4)&&(Cd==Co)&&(tablero[Fd+3][Cd].pieza==' ')&&(tablero[Fd+2][Cd].pieza==' ')&&(tablero[Fd+1][Cd].pieza==' ')) valido=1;
				if((Fd==Fo-5)&&(Cd==Co)&&(tablero[Fd+4][Cd].pieza==' ')&&(tablero[Fd+3][Cd].pieza==' ')&&(tablero[Fd+2][Cd].pieza==' ')&&(tablero[Fd+1][Cd].pieza==' ')) valido=1;
				if((Fd==Fo-6)&&(Cd==Co)&&(tablero[Fd+5][Cd].pieza==' ')&&(tablero[Fd+4][Cd].pieza==' ')&&(tablero[Fd+3][Cd].pieza==' ')&&(tablero[Fd+2][Cd].pieza==' ')&&(tablero[Fd+1][Cd].pieza==' ')) valido=1;
				if((Fd==Fo-7)&&(Cd==Co)&&(tablero[Fd+6][Cd].pieza==' ')&&(tablero[Fd+5][Cd].pieza==' ')&&(tablero[Fd+4][Cd].pieza==' ')&&(tablero[Fd+3][Cd].pieza==' ')&&(tablero[Fd+2][Cd].pieza==' ')&&(tablero[Fd+1][Cd].pieza==' ')) valido=1;
				if((Fd==Fo-8)&&(Cd==Co)&&(tablero[Fd+7][Cd].pieza==' ')&&(tablero[Fd+6][Cd].pieza==' ')&&(tablero[Fd+5][Cd].pieza==' ')&&(tablero[Fd+4][Cd].pieza==' ')&&(tablero[Fd+3][Cd].pieza==' ')&&(tablero[Fd+2][Cd].pieza==' ')&&(tablero[Fd+1][Cd].pieza==' ')) valido=1;
			
				
				
				
				
				if((Cd==Co+1)&&(Fd==Fo+1)) valido=1;
				if((Cd==Co+2)&&(Fd==Fo+2)&&(tablero[Fd-1][Cd-1].pieza==' ')) valido=1; 
				if((Cd==Co+3)&&(Fd==Fo+3)&&(tablero[Fd-2][Cd-2].pieza==' ')&&(tablero[Fd][Cd-1].pieza==' ')) valido=1;
				if((Cd==Co+4)&&(Fd==Fo+4)&&(tablero[Fd-3][Cd-3].pieza==' ')&&(tablero[Fd][Cd-2].pieza==' ')&&(tablero[Fd-1][Cd-1].pieza==' ')) valido=1;
				if((Cd==Co+5)&&(Fd==Fo+5)&&(tablero[Fd-4][Cd-4].pieza==' ')&&(tablero[Fd][Cd-3].pieza==' ')&&(tablero[Fd-2][Cd-2].pieza==' ')&&(tablero[Fd][Cd-1].pieza==' ')) valido=1;
				if((Cd==Co+6)&&(Fd==Fo+6)&&(tablero[Fd-5][Cd-5].pieza==' ')&&(tablero[Fd][Cd-4].pieza==' ')&&(tablero[Fd-3][Cd-3].pieza==' ')&&(tablero[Fd][Cd-2].pieza==' ')&&(tablero[Fd][Cd-1].pieza==' ')) valido=1;
				if((Cd==Co+7)&&(Fd==Fo+7)&&(tablero[Fd-6][Cd-6].pieza==' ')&&(tablero[Fd][Cd-5].pieza==' ')&&(tablero[Fd-4][Cd-4].pieza==' ')&&(tablero[Fd][Cd-3].pieza==' ')&&(tablero[Fd][Cd-2].pieza==' ')&&(tablero[Fd-1][Cd-1].pieza==' ')) valido=1;
				if((Cd==Co+8)&&(Fd==Fo+8)&&(tablero[Fd-7][Cd-7].pieza==' ')&&(tablero[Fd][Cd-6].pieza==' ')&&(tablero[Fd-5][Cd-5].pieza==' ')&&(tablero[Fd][Cd-4].pieza==' ')&&(tablero[Fd][Cd-3].pieza==' ')&&(tablero[Fd-5][Cd-2].pieza==' ')&&(tablero[Fd][Cd-1].pieza==' ')) valido=1;
			
				if((Cd==Co-1)&&(Fd==Fo-1)) valido=1;
				if((Cd==Co-2)&&(Fd==Fo-2)&&(tablero[Fd+1][Cd+1].pieza==' ')) valido=1; 
				if((Cd==Co-3)&&(Fd==Fo-3)&&(tablero[Fd+2][Cd+2].pieza==' ')&&(tablero[Fd+1][Cd+1].pieza==' ')) valido=1;
				if((Cd==Co-4)&&(Fd==Fo-4)&&(tablero[Fd+3][Cd+3].pieza==' ')&&(tablero[Fd+2][Cd+2].pieza==' ')&&(tablero[Fd+1][Cd+1].pieza==' ')) valido=1;
				if((Cd==Co-5)&&(Fd==Fo-5)&&(tablero[Fd+4][Cd+4].pieza==' ')&&(tablero[Fd+3][Cd+3].pieza==' ')&&(tablero[Fd+2][Cd+2].pieza==' ')&&(tablero[Fd+1][Cd+1].pieza==' ')) valido=1;
				if((Cd==Co-6)&&(Fd==Fo-6)&&(tablero[Fd+5][Cd+5].pieza==' ')&&(tablero[Fd+4][Cd+4].pieza==' ')&&(tablero[Fd+3][Cd+3].pieza==' ')&&(tablero[Fd+2][Cd+2].pieza==' ')&&(tablero[Fd+1][Cd+1].pieza==' ')) valido=1;
				if((Cd==Co-7)&&(Fd==Fo-7)&&(tablero[Fd+6][Cd+6].pieza==' ')&&(tablero[Fd+5][Cd+5].pieza==' ')&&(tablero[Fd+4][Cd+4].pieza==' ')&&(tablero[Fd+3][Cd+3].pieza==' ')&&(tablero[Fd+2][Cd+2].pieza==' ')&&(tablero[Fd+1][Cd+1].pieza==' ')) valido=1;
				if((Cd==Co-8)&&(Fd==Fo-8)&&(tablero[Fd+7][Cd+7].pieza==' ')&&(tablero[Fd+6][Cd+6].pieza==' ')&&(tablero[Fd+5][Cd+5].pieza==' ')&&(tablero[Fd+4][Cd+4].pieza==' ')&&(tablero[Fd+3][Cd+3].pieza==' ')&&(tablero[Fd+2][Cd+2].pieza==' ')&&(tablero[Fd+1][Cd+1].pieza==' ')) valido=1;
			
			
				if((Fd==Fo+1)&&(Cd==Co-1)) valido=1;
				if((Fd==Fo+2)&&(Cd==Co-2)&&(tablero[Fd-1][Cd+1].pieza==' ')) valido=1; 
				if((Fd==Fo+3)&&(Cd==Co-3)&&(tablero[Fd-2][Cd+2].pieza==' ')&&(tablero[Fd-1][Cd+1].pieza==' ')) valido=1;
				if((Fd==Fo+4)&&(Cd==Co-4)&&(tablero[Fd-3][Cd+3].pieza==' ')&&(tablero[Fd-2][Cd+2].pieza==' ')&&(tablero[Fd-1][Cd+1].pieza==' ')) valido=1;
				if((Fd==Fo+5)&&(Cd==Co-5)&&(tablero[Fd-4][Cd+4].pieza==' ')&&(tablero[Fd-3][Cd+3].pieza==' ')&&(tablero[Fd-2][Cd+2].pieza==' ')&&(tablero[Fd-1][Cd+1].pieza==' ')) valido=1;
				if((Fd==Fo+6)&&(Cd==Co-6)&&(tablero[Fd-5][Cd+5].pieza==' ')&&(tablero[Fd-4][Cd+4].pieza==' ')&&(tablero[Fd-3][Cd+3].pieza==' ')&&(tablero[Fd-2][Cd+2].pieza==' ')&&(tablero[Fd-1][Cd+1].pieza==' ')) valido=1;
				if((Fd==Fo+7)&&(Cd==Co-7)&&(tablero[Fd-6][Cd+6].pieza==' ')&&(tablero[Fd-5][Cd+5].pieza==' ')&&(tablero[Fd-4][Cd+4].pieza==' ')&&(tablero[Fd-3][Cd+3].pieza==' ')&&(tablero[Fd-2][Cd+2].pieza==' ')&&(tablero[Fd-1][Cd+1].pieza==' ')) valido=1;
				if((Fd==Fo+8)&&(Cd==Co-8)&&(tablero[Fd-7][Cd+7].pieza==' ')&&(tablero[Fd-6][Cd+6].pieza==' ')&&(tablero[Fd-5][Cd+5].pieza==' ')&&(tablero[Fd-4][Cd+4].pieza==' ')&&(tablero[Fd-3][Cd+3].pieza==' ')&&(tablero[Fd-2][Cd+2].pieza==' ')&&(tablero[Fd-1][Cd+1].pieza==' ')) valido=1;
			
				if((Fd==Fo-1)&&(Cd==Co+1)) valido=1;
				if((Fd==Fo-2)&&(Cd==Co+2)&&(tablero[Fd+1][Cd-1].pieza==' ')) valido=1; 
				if((Fd==Fo-3)&&(Cd==Co+3)&&(tablero[Fd+2][Cd-2].pieza==' ')&&(tablero[Fd+1][Cd-1].pieza==' ')) valido=1;
				if((Fd==Fo-4)&&(Cd==Co+4)&&(tablero[Fd+3][Cd-3].pieza==' ')&&(tablero[Fd+2][Cd-2].pieza==' ')&&(tablero[Fd+1][Cd-1].pieza==' ')) valido=1;
				if((Fd==Fo-5)&&(Cd==Co+5)&&(tablero[Fd+4][Cd-4].pieza==' ')&&(tablero[Fd+3][Cd-3].pieza==' ')&&(tablero[Fd+2][Cd-2].pieza==' ')&&(tablero[Fd+1][Cd-1].pieza==' ')) valido=1;
				if((Fd==Fo-6)&&(Cd==Co+6)&&(tablero[Fd+5][Cd-5].pieza==' ')&&(tablero[Fd+4][Cd-4].pieza==' ')&&(tablero[Fd+3][Cd-3].pieza==' ')&&(tablero[Fd+2][Cd-2].pieza==' ')&&(tablero[Fd+1][Cd-1].pieza==' ')) valido=1;
				if((Fd==Fo-7)&&(Cd==Co+7)&&(tablero[Fd+6][Cd-6].pieza==' ')&&(tablero[Fd+5][Cd-5].pieza==' ')&&(tablero[Fd+4][Cd-4].pieza==' ')&&(tablero[Fd+3][Cd-3].pieza==' ')&&(tablero[Fd+2][Cd-2].pieza==' ')&&(tablero[Fd+1][Cd-1].pieza==' ')) valido=1;
				if((Fd==Fo-8)&&(Cd==Co+8)&&(tablero[Fd+7][Cd-7].pieza==' ')&&(tablero[Fd+6][Cd-6].pieza==' ')&&(tablero[Fd+5][Cd-5].pieza==' ')&&(tablero[Fd+4][Cd-4].pieza==' ')&&(tablero[Fd+3][Cd-3].pieza==' ')&&(tablero[Fd+2][Cd-2].pieza==' ')&&(tablero[Fd+1][Cd-1].pieza==' ')) valido=1;
				
			
			}break;
				
			
			
			
	}	
	
	
	return valido;
}


