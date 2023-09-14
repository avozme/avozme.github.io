#include <ncurses.h>
#include "tablero.h"
#include "mov.h"



int main (void)
{
	struct s_casillas tablero[8][8];
	struct s_estado esta;
	char caracter;
	int na, pass,columna_menu,fila_menu,columna_men,fila_men,c;
	
	initscr();
	keypad(stdscr,1);
	cbreak();
	if (has_colors())
		{
		start_color();
		}
	
	init_pair(1,COLOR_WHITE,COLOR_BLACK);// inicializacion d colores
	init_pair(2,COLOR_BLACK,COLOR_WHITE);
	init_pair(3,COLOR_WHITE, COLOR_WHITE);
	init_pair(4,COLOR_BLACK, COLOR_BLACK);
	init_pair(5,COLOR_BLUE,COLOR_YELLOW);
	init_pair(6,COLOR_WHITE, COLOR_RED);
	init_pair(7,COLOR_RED,COLOR_BLUE);
	init_pair(8,COLOR_RED,COLOR_BLACK);
	
	bkgd(COLOR_PAIR(6));
	esta.cont=0;
	attron(A_BOLD);
	
	
	columna_menu=0;
	fila_menu=0;
	
	pass=0;
	
 	while(pass==0)
	{
		cuadro_menu();
		
		columna_men=(columna_menu)+49;
		fila_men=(fila_menu)+15;
		move(fila_men, columna_men);
		attron(COLOR_PAIR(8));
		printw(" ");
		c=getch();
		switch(c)// control de lo q si y no s epuede seleccionar en el menu 
		{
			case KEY_UP:
			{
				if ((fila_menu>0))
					fila_menu=fila_menu-1;
					
				if (fila_menu==3)
					{
						attron(COLOR_PAIR(8));
						fila_menu=fila_menu-2;
					
					}
			};break;
		
			case KEY_DOWN:
			{
				if(fila_menu<4)
					fila_menu= fila_menu+1;
					if(fila_menu==2)
						fila_menu=fila_menu+1;
					if (fila_menu==3)
					{
						attron(COLOR_PAIR(8));
						fila_menu=fila_menu+1;
						
					}
			};break;
				
 			case 10:
 			{
				pass=1;
				
 			};break;
		}
 		
 			
	}

			
 		switch(fila_menu)
		{
			case 0://partida nueva
 			{
				
				esta.salir=0;
				inicializar_tablero(tablero,&esta);
				while((esta.hake==0)&&(esta.salir==0))
				{
					
					pintar_tablero(tablero);
					tirar(tablero, &esta);
					esta.cont++;
				}
				
			};break;
		
			case 1:// cargar partida
			{
  				FILE *f;
 				
  				f=fopen("partida.bin","r+b");
 				if (f==NULL)
  				{	
  					
 					move(30,35);
 					printw("EL ARCHIVO NO SE PUEDE ABRIR EL PROGRAMA SE CANCELARA");
					na=getch();
  				}
  				else
				{
 					fread(tablero,sizeof(struct s_casillas),64,f);
					fread(&esta,sizeof(struct s_estado),1,f);
					move(25,25);
					printw(" esta.salir%i  esta.hake%i  esta.cont%i  ",esta.salir,esta.hake,esta.cont);
					na=getch();
					esta.salir=0;
					esta.hake=0;
						
  					while((esta.hake==0)&&(esta.salir==0))
  					{
  						pintar_tablero(tablero);
 						tirar(tablero,&esta);
  						esta.cont=esta.cont+1;
					}
						
					fclose (f);
					
				}	
				
			
			}break;
			case 4:// salir del juego
			{
				
			};break;
		}
	

	endwin();
	return 0;
}

int pintar_tablero(struct s_casillas tab[8][8])// pinta el tablero
{
	int i,j,aux,z,letra,x,y,p,l;
	
	x=2;
	y=1;		
	move(2,9);
	attron(COLOR_PAIR(5));
	printw("                                                                        \n");
	letra=1;
	move(3,9);
	attron(COLOR_PAIR(5));
	printw("                                                                        \n");
	move(4,9);
	attron(COLOR_PAIR(5));
	printw("    A        B        C        D        E        F        G        H    \n");
	move(5,9);attron(COLOR_PAIR(5));
		
	attron(COLOR_PAIR(5));
	printw("                                                                        \n");
	
			
	for(i=0;i<=7;i++)
		{
		
		attron(COLOR_PAIR(5));
		printw("         ");	
		
		for (j=0;j<4;j++)
			{
			
			attron(COLOR_PAIR(x));
			printw("         ");
			attron(COLOR_PAIR(y));
			printw("         ");
			}
		printw("\n");
		attron(COLOR_PAIR(5));
		printw("         ");	
			
		for (z=0;z<4;z++)
			{
			attron(COLOR_PAIR(x));
			printw("         ");
			attron(COLOR_PAIR(y));
			printw("         ");
			}
		printw("\n");
		attron(COLOR_PAIR(5));
		printw("    %i    ",letra);
			
		for (z=0;z<4;z++)
		{
			
			attron(COLOR_PAIR(x));
			printw("         ");
			attron(COLOR_PAIR(y));
			printw("         ");
		}		
		printw("\n");
		attron(COLOR_PAIR(5));
		printw("         ");	
			
		for (z=0;z<4;z++)        
		{
			attron(COLOR_PAIR(x));
			printw("         ");
			attron(COLOR_PAIR(y));
			printw("         ");
		}
		printw("\n");
				
			
		
		
		aux=x;
		x=y;
		y=aux;
		letra++;
	}
	
	for(i=0;i<=7;i++)// pinto las letras
	{
		for (j=0;j<=7;j++)
		{
			if (tab[i][j].pieza!=' ')
			{
				move(8+(i*4),13+(j*9));
				
				if ((tab[i][j].color==BLANCA)&&(tab[i][j].color_pieza==BLANCA))
				{
					attron(COLOR_PAIR(3));
					printw("%c",tab[i][j].pieza);
				}
				if ((tab[i][j].color==NEGRA)&&(tab[i][j].color_pieza==BLANCA))
				{
					attron(COLOR_PAIR(1));
					printw("%c",tab[i][j].pieza);
				}
				if ((tab[i][j].color==BLANCA)&&(tab[i][j].color_pieza==NEGRA))
				{
					attron(COLOR_PAIR(2));
					printw("%c",tab[i][j].pieza);
				}
				if ((tab[i][j].color==NEGRA)&&(tab[i][j].color_pieza==NEGRA))
				{
					attron(COLOR_PAIR(4));
					printw("%c",tab[i][j].pieza);
				}
				
			}
		}
	
	}
	refresh();
return 0;
}

int inicializar_tablero(struct s_casillas tab[8][8], struct s_estado *esta)// se inicialian las variables pa una nueva partida
{
	
	int i,j;
	esta->hake=0;
	esta->juga=BLANCA;
	esta->mov_rey=0;
	esta->mov_torre=0;
	esta->mov_reyn=0;
	esta->mov_torren=0;
	
	
	for(i=0;i<=7;i++)
	{
		for(j=0;j<=7;j++)
		{
			tab[i][j].pieza=' ';
			tab[i][j].color_pieza=' ';
		}
	}
	tab[0][0].pieza=TORRE;
	tab[0][1].pieza=CABALLO;
	tab[0][2].pieza=ALFIL;
	tab[0][3].pieza=DAMA;
	tab[0][4].pieza=REY;
	tab[0][5].pieza=ALFIL;
	tab[0][6].pieza=CABALLO;
	tab[0][7].pieza=TORRE;
	
	tab[7][0].pieza=TORRE;
	tab[7][1].pieza=CABALLO;
	tab[7][2].pieza=ALFIL;
	tab[7][3].pieza=DAMA;
	tab[7][4].pieza=REY;
	tab[7][5].pieza=ALFIL;
	tab[7][6].pieza=CABALLO;
	tab[7][7].pieza=TORRE;
	
	for(i=0; i<=7; i++)
	{
		tab[0][i].color_pieza=NEGRA;
		tab[1][i].color_pieza=NEGRA;
		tab[1][i].pieza=PEON;
		tab[6][i].pieza=PEON;
		tab[6][i].color_pieza=BLANCA;
		tab[7][i].color_pieza=BLANCA;
	}
	for (i=0;i<=7;i++)
	{
		for (j=0;j<=7;j++)
		{
			if (i%2==0)
			{
				if (j%2!=0)
					tab[i][j].color=NEGRA;
				else
					tab[i][j].color=BLANCA;
			}
			else
			{
				if (j%2!=0)
					tab[i][j].color=BLANCA;
				else
					tab[i][j].color=NEGRA;
			}
		}
	}


	
return 0;
}

void cuadro_menu()// cuadro del menu
{
	int i;
	for(i=0;i<=8;i++)
	{
		move(13+i,48);
		attron(COLOR_PAIR(8));
		printw("                                 ");
	}
	attron(COLOR_PAIR(8));
	
	move(15,50);
	printw("Inicializar partida");
	
	move(16,50);
	printw("Cargar partida");
			
	move(17,50);
	printw("Guardar partida");move(17,50);
	
	move(18,50);
	printw("Salir de menu");
	move(19,50);
	
	printw("Salir del juego");
}



