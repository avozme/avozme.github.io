/*AJEDREZ*/

#include "ajedrez.h"
#include "interfaz.h"
#include "memoria.h"

int A=0;					/// Variable global para la decoración del cuadro de menú ///

void main(){
initscr();					///
start_color();					///	Inicializamos la entrada/salida del programa
keypad(stdscr, 1);				///
cbreak();					///
						///
init_pair(1, COLOR_WHITE, COLOR_WHITE);		///	
init_pair(2, COLOR_BLACK, COLOR_WHITE);		///	Colores de las casillas y piezas
init_pair(3, COLOR_WHITE, COLOR_BLACK);		///
init_pair(4, COLOR_BLACK, COLOR_BLACK);		///
						///
init_pair(5, COLOR_RED, COLOR_CYAN);		///
init_pair(6, COLOR_WHITE, COLOR_GREEN);		///	Colores de interfaz
init_pair(7, COLOR_RED, COLOR_RED);		///
init_pair(8, COLOR_YELLOW, COLOR_YELLOW);	///
init_pair(9, COLOR_BLACK, COLOR_GREEN);		///
init_pair(10, COLOR_RED, COLOR_GREEN);		///
						///
bkgd(COLOR_PAIR(5));				///	Color de fondo
attron(A_BOLD);					///	Activamos la negrita

struct s_estado estado;
struct s_casillas tablero[9][9];

while(1!=0){
	menu(&estado, tablero);			///	Ponemos A a 1 para que la próxima vez que se entre al menú
	A=1;					///	aparezca la palabra "PAUSA" en lugar de "AJEDREZ", y se activen
	mover(&estado, tablero);		///	más opciones
}
}


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


void menu(struct s_estado* estado, struct s_casillas tablero[9][9]){
struct s_estado eaux;

int i, j, opc=1;
int tecla;
int x, y, xa, ya;
FILE *f, *g, *h;
int valido=0;

	opc=1;
	y=21; ya=y;
	x=47; xa=x;
	

	do{
		if(A==0){
			dibujar_cuadro();
			move(17, 61);
			attron(COLOR_PAIR(10));
			printw("AJEDREZ");
			refresh();
		}
	else{
		dibujar_cuadro();
		attron(COLOR_PAIR(10));
		move(17, 62);
		printw("PAUSA");		  //////////////////////////////////////////////////////////////////
	}					 //////////////////////// CUADRO Y TÍTULO /////////////////////////
						//////////////////////////////////////////////////////////////////
	
	
	move(21, 50);
	if(A==0) attron(COLOR_PAIR(9));
	else attron(COLOR_PAIR(6));
	printw("VOLVER A LA PARTIDA");						///////OPCIÓN 1
		
	attron(COLOR_PAIR(6));
	move(23, 50);
	printw("INICIAR NUEVA PARTIDA");					///////OPCIÓN 2
	
	move(25, 50);
	f=fopen("aje1.pgn", "r");
	g=fopen("aje2.pgn", "r");
	h=fopen("aje3.pgn", "r");
	if((f==NULL)&&(g==NULL)&&(h==NULL)) attron(COLOR_PAIR(9));
	else attron(COLOR_PAIR(6));
	printw("CARGAR PARTIDA GUARDADA");					///////OPCIÓN 3
	
	move(27, 50);
	if(A==0) attron(COLOR_PAIR(9));
	else attron(COLOR_PAIR(6));
	printw("GUARDAR PARTIDA ACTUAL");					///////OPCIÓN 4
	
	move(29, 50);
	attron(COLOR_PAIR(10));
	printw("SALIR");							///////OPCIÓN 5
	
	attron(COLOR_PAIR(9));
	

			  ///////////////////////////////////////////////////////////
			 /////////////////////OPCIONES//////////////////////////////
			///////////////////////////////////////////////////////////
	
		attron(COLOR_PAIR(10));
		move(ya, xa);
		printw("  ");
		move(y, x);
		printw(">>");
		move(40, 122);
		xa=x; ya=y;
		
		tecla=getch();
		refresh();
		switch(tecla){
			case KEY_UP: if(y>=22){ y=y-2; opc=opc-1; }	break;
			case KEY_DOWN: if(y<=28){ y=y+2; opc=opc+1; }	break;
			case 10:
				switch(opc){
					case 1: if(A==1) valido=1;
						else valido=0;
						break;
					case 2: inic_tablero(tablero);
						inic_estado(estado);
						valido=1;
						break;
					case 3: if((f==NULL)&&(g==NULL)&&(h==NULL)){
							valido=0;
						}
						else{
							valido=cargar_partida(tablero, estado);
						}
						break;
					case 4: if(A==0) valido=0;
						else{
							valido=guardar_partida(tablero, *estado);
						}
						break;
					case 5: dibujar_cuadro();
						move(25, 55);
						attron(COLOR_PAIR(10));
						printw("¡HASTA LA PROXIMA!");
						move(40, 122);
						refresh();
						retardo(30);
						//valido=1;
						endwin(); exit(1);
				}
		}
	} while(valido==0);
	return;	
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////

void dibujar_cuadro(){
int i;

	for(i=15; i<=35; i++){
		refresh();
		move(i, 40);
		if((i==15)||(i==35)){
			attron(COLOR_PAIR(4));
			printw("                                                  ");
		}
		else{
			printw(" ");
			attron(COLOR_PAIR(6));
			printw("                                                ");
			attron(COLOR_PAIR(4));
			printw(" ");
		}
	}
}


////////////////////////////////////////////////////////////////////////////////////////////////////////


void inic_tablero(struct s_casillas tab[9][9]){
int i, j;
char col;

	col=BLANCA;
	for(i=0; i<9; i++){
		for(j=0; j<9; j++){
			if(col==BLANCA){
				tab[i][j].color=BLANCA;
				col=NEGRA;
			}
			else if(col==NEGRA){
				tab[i][j].color=NEGRA;
				col=BLANCA;
			}
			tab[i][j].pieza=NADA;
		}
	}

	tab[1][1].pieza=TORRE;		tab[8][1].pieza=TORRE;
	tab[1][2].pieza=CABALLO;	tab[8][2].pieza=CABALLO;
	tab[1][3].pieza=ALFIL;		tab[8][3].pieza=ALFIL;
	tab[1][4].pieza=DAMA;		tab[8][4].pieza=DAMA;
	tab[1][5].pieza=REY;		tab[8][5].pieza=REY;
	tab[1][6].pieza=ALFIL;		tab[8][6].pieza=ALFIL;
	tab[1][7].pieza=CABALLO;	tab[8][7].pieza=CABALLO;
	tab[1][8].pieza=TORRE;		tab[8][8].pieza=TORRE;

	for(i=1; i<=8; i++){
		tab[1][i].color_pieza=NEGRA;
		tab[2][i].color_pieza=NEGRA;
		tab[2][i].pieza=PEON;
		tab[7][i].pieza=PEON;
		tab[7][i].color_pieza=BLANCA;
		tab[8][i].color_pieza=BLANCA;
	}

	tab[0][1].pieza='A';	tab[1][0].pieza='8';
	tab[0][2].pieza='B';	tab[2][0].pieza='7';
	tab[0][3].pieza='C';	tab[3][0].pieza='6';
	tab[0][4].pieza='D';	tab[4][0].pieza='5';
	tab[0][5].pieza='E';	tab[5][0].pieza='4';
	tab[0][6].pieza='F';	tab[6][0].pieza='3';
	tab[0][7].pieza='G';	tab[7][0].pieza='2';
	tab[0][8].pieza='H';	tab[8][0].pieza='1';
	
	for(i=0; i<=8; i++){
		tab[0][i].color=AZUL;
		tab[i][0].color=AZUL;
	}
}

void inic_estado(struct s_estado* estado){
	
	estado->turno=BLANCA;
	estado->rey_negro_movido='N';
	estado->rey_blanco_movido='N';
	estado->torre_i_negra_movida='N';
	estado->torre_i_blanca_movida='N';
	estado->torre_d_negra_movida='N';
	estado->torre_d_blanca_movida='N';
}



void retardo(int tiempo){
int i;
	for(i=0; i<10000000*tiempo; i++){ ; }
}