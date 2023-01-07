#include <string.h>
#include <stdlib.h>
#include <menu.h>

#include "ajedrez.h"
#include "caguvi.h"
#include "movimientos.h"

int main (void)
{
	struct s_casilla tablero[9][9];
	struct s_estado estado;
	struct s_mov *moves;
	char caracter;
	
	initscr();
	keypad(stdscr,1);
	cbreak();
	
	if (has_colors())
	{
		start_color();
	}
	attron(A_BOLD);			//Iniciamos los pares de colores necesarios.
	init_pair(1,COLOR_WHITE,COLOR_BLACK);
	init_pair(2,COLOR_BLACK,COLOR_WHITE);
	init_pair(3,COLOR_WHITE,COLOR_WHITE);
	init_pair(4,COLOR_BLACK,COLOR_BLACK);
	
	srand(time(NULL));
	
	clear();
	printw("BIENVENIDO A AJEDREZ 0.0.1½\n");
	printw("Pulse una tecla para continuar ");
	getch();
	clear();
	
	pintar_tablero();
	inicializar_tablero(tablero, estado);
	menu(tablero, estado, moves);
	
	keypad(stdscr,0);	
	endwin();
	return 0;
}

int pintar_tablero()
{

	int i,j,x=2,y=1,aux;
	
	move(1,1);
	printw("    A      B      C      D      E      F      G      H");
	move(3,1);
	printw("1");
	move(6,1);
	printw("2");
	move(9,1);
	printw("3");
	move(12,1);
	printw("4");
	move(15,1);
	printw("5");
	move(18,1);
	printw("6");
	move(21,1);
	printw("7");
	move(24,1);
	printw("8");
	
	move(2,1);
	for(i=0;i<8;i++)
	{
		move(2+(i*3), 2);    //para recalcular la poscion y pintar el tablero.
		for (j=0;j<4;j++)             //Bucle para pintar una linea de 4 pares de dos colores (4*2=8 casillas).
		{
			attron(COLOR_PAIR(x));
			printw("       ");
			attron(COLOR_PAIR(y));
			printw("       ");
		}
		move(3+(i*3), 2);
		for (j=0;j<4;j++)		//Siguiente linea.
		{
			attron(COLOR_PAIR(x));
			printw("       ");
			attron(COLOR_PAIR(y));
			printw("       ");
		}
		
		move(4+(i*3), 2);             //Ultima linea de la casilla (Cada casilla tiene tres lineas de alto.
		for (j=0;j<4;j++)
		{
			attron(COLOR_PAIR(x));
			printw("       ");
			attron(COLOR_PAIR(y));
			printw("       ");
		}
		aux=x;
		x=y;
		y=aux;
	}
	move(1,80);
	attron(A_BOLD);
	attron(COLOR_PAIR(1));
	printw("AJEDREZ 0.0.1½");
	move(2,72);
	printw("Héctor Raúl Díaz Navarro '05.");
	move(3,71);  
	printw("===============================");
	move(27, 3);
	printw("MOVIMIENTOS:\n");
	printw("____________________________________________________________________________________________________");
	
	return 0;
}

int inicializar_tablero(struct s_casilla tablero[9][9], struct s_estado estado)
{

	int x,y;
	estado.torre_B1=0;
	estado.torre_B2=0;
	estado.torre_N1=0;
	estado.torre_N2=0;
	estado.reyN=0;
	estado.reyB=0;
	estado.num_mov=0;
	estado.turno=BLANCO;
	for (x=1;x<9;x++)
	{
		for (y=1;y<9;y++)		//Inicializaamos todo el tablero a vacio, añadiendo los colores de las casillas.
		{
			tablero[x][y].pieza=NADA;
			tablero[x][y].color=NADA;
			if((y==1)||(y==3)||(y==5)||(y==7))
			{
				if(x%2==0)
					tablero[x][y].colorcas=NEGRO;
				else
					tablero[x][y].colorcas=BLANCO;
			}
			if((y==2)||(y==4)||(y==6)||(y==8))
			{
				if(x%2==0)
					tablero[x][y].colorcas=BLANCO;
				else
					tablero[x][y].colorcas=NEGRO;
			}
		}
	}

	
	for (x=1;x<=8;x++)
	{
		for (y=1;y<=8;y++)
		{
			if (x==1)                                       
			{
				if ((y==1)||(y==8))				//Inicializamos las piezas negras.
				{
					tablero[x][y].pieza=TORRE;
					tablero[x][y].color=NEGRO;
				}
		
				if ((y==2)||(y==7))
				{
					tablero[x][y].pieza=CABALLO;
					tablero[x][y].color=NEGRO;
				}
				if ((y==3)||(y==6))
				{
					tablero[x][y].pieza=ALFIL;
					tablero[x][y].color=NEGRO;
				}
				if (y==4)
				{
					tablero[x][y].pieza=REINA;
					tablero[x][y].color=NEGRO;
				}
				if (y==5)
				{
					tablero[x][y].pieza=REY;
					tablero[x][y].color=NEGRO;
				}
			}


			if (x==2)
			{
				tablero[x][y].pieza=PEON;
				tablero[x][y].color=NEGRO;
			}
			if (x==7)
			{
				tablero[x][y].pieza=PEON;              //Inicializamos las piezas blancas.
				tablero[x][y].color=BLANCO;
			}



			if (x==8)					
			{			  
				if ((y==1)||(y==8))
				{
					tablero[x][y].pieza=TORRE;
					tablero[x][y].color=BLANCO;
				}
		
				if ((y==2)||(y==7))
				{
					tablero[x][y].pieza=CABALLO;
					tablero[x][y].color=BLANCO;
				}
				if ((y==3)||(y==6))
				{
					tablero[x][y].pieza=ALFIL;
					tablero[x][y].color=BLANCO;
				}
				if (y==4)
				{
					tablero[x][y].pieza=REINA;
					tablero[x][y].color=BLANCO;
				}
				if (y==5)
				{
					tablero[x][y].pieza=REY;
					tablero[x][y].color=BLANCO;
				}
			}
		
		}
	}
	return 0;
}

int pintar_fichas(struct s_casilla tablero[9][9]) //tambien nos vale para el refresco de las piezas.
{
	int x,y,newx,newy;
	
	for (y=1;y<=8;y++)
	{
		for (x=1;x<=8;x++)
		{
			newy=(y*7)-7/2;  //Calculamos las posiciones con respecto al tablero.
			newx=(x*3)-3/2;
			
			move(newx+1,newy+1);
			if (tablero[x][y].color==NEGRO)				//PIEZA NEGRA.
			{
				if(tablero[x][y].colorcas==NEGRO)                //Casilla negra.
				{
					attron(A_BOLD);
					attron(COLOR_PAIR(4));
					printw("%c",tablero[x][y].pieza);
				}
				else					  	//Casilla blanca.
				{
					attron(A_BOLD);
					attron(COLOR_PAIR(2));
					printw("%c",tablero[x][y].pieza);
				}
			}
			else							//PIEZA BLANCA.
			{
				if (tablero[x][y].colorcas==NEGRO)                //Casilla negra.
				{
					attron(A_BOLD);
					attron(COLOR_PAIR(1));
					printw("%c",tablero[x][y].pieza);
				}
				else						//Casilla blanca.
				{
					attron(A_BOLD);
					attron(COLOR_PAIR(3));
					printw("%c",tablero[x][y].pieza);
				}
			}	
		}
	}
	return 0;
}

int jugar_h(struct s_casilla tablero[9][9], struct s_estado estado, struct s_mov *moves)
{
	int fila;  
	int filad;
	int columna; 
	int columnd;
	char aux1, aux2;
	int permitido=0;
	int correcto;
	
	
	echo();
	attron(A_BOLD);
	attron(COLOR_PAIR(1));
	
 	move(4,72);
 	printw("Movimientos: %i.  ", estado.num_mov);
	move(5,71);
	printw("--------------------------------");
	
	do
	{	
		do
		{
			move(18,80);
			if(estado.turno==BLANCO)
				printw("TURNO BLANCAS.      ");
			else
				printw("TURNO NEGRAS.      ");
			move(19,71);
			printw("===============================");
			move(20,72);
			printw("Introduce la casilla origen: ");
			move(25,77);
			printw("ESC Vuelve al menu.");
			do
			{
				move(22,72);
				printw("                               ");
				move(23,72);
				printw("                               ");
				move(22,72);
				printw("Columna: ");
				aux1=getch();
				//scanw("%c", &aux1);
				//tolower(aux1);
				switch (aux1)
				{
					case 'a': columna=1;break;
					case 'b': columna=2;break;
					case 'c': columna=3;break;
					case 'd': columna=4;break;
					case 'e': columna=5;break;
					case 'f': columna=6;break;
					case 'g': columna=7;break;
					case 'h': columna=8;break;
					case  27: menu(tablero, estado, moves);break;
					default: columna=0;
				}
			}while(columna==0);
		
			do
			{
				move(26,72);
				printw("                           ");
				move(23,72);
				printw("Fila: ");
				scanw("%i", &fila);
			}while((fila<1) || (fila>8));
	
		}while(tablero[fila][columna].pieza==NADA);
	
		if(tablero[fila][columna].color==estado.turno)
		{
			move(20,72);
			printw("Introduce la casilla destino: ");
			move(25,77);
			printw("ESC Vuelve al menu.");
		
			do
			{
				move(22,72);
				printw("                     ");
				move(23,72);
				printw("                                ");
				move(22,72);
				printw("Columna: ");
				aux2=getch();
				//scanw("%c", &aux2);
				//tolower(aux2);
				switch (aux2)
				{
					case 'a': columnd=1;break;
					case 'b': columnd=2;break;
					case 'c': columnd=3;break;
					case 'd': columnd=4;break;
					case 'e': columnd=5;break;
					case 'f': columnd=6;break;
					case 'g': columnd=7;break;
					case 'h': columnd=8;break;
					case  27: menu(tablero, estado, moves);break;
					default: columnd=0;
				}
			}while(columnd==0);
		
			do
			{
				move(25,72);
				printw("                           ");
				move(23,72);
				printw("Fila: ");
				scanw("%i", &filad);
			}while((filad<1) || (filad>8));
	
			permitido=comprobar_mov(columna, fila, columnd, filad, tablero, estado, moves);
			if(permitido==1)
			{
				estado.num_mov++; //Sumamos el movimiento.
				mover_pieza(columna, fila, columnd, filad, tablero, estado, &moves); //movemos.
				if((estado.num_mov%2)!=0)           //Cambianos turno.
					estado.turno=NEGRO;
				else
					estado.turno=BLANCO;
			}
			else 
				mov_inc(tablero, estado, moves);
		}
		
		else
		{
			move(20,72);
			printw("                                   ");
			move(22,72);
			printw("ESA PIEZA NO ES TUYA!!!.");
			move(23,72);
			printw("Pulsa una tecla para continuar.");
			move(25,72);
			printw("                                   ");
			getch();
			move(24,72);
			printw("                               ");
		}
	}while(permitido==0);
	
	if((estado.tipo_jug_n=='O')&&(estado.turno==NEGRO))	//Dependiendo del turno y tipo de jugador2 llamamos a una u otra función.
		jugar_o(tablero, estado, moves);
	else
		jugar_h(tablero, estado, moves);
}

int jugar_o(struct s_casilla tablero[9][9], struct s_estado estado, struct s_mov *moves)
{
		int fila, filad, columna, columnd, permitido=0;
		echo();
		attron(A_BOLD);
		attron(COLOR_PAIR(1));
		move(4,72);
		printw("Movimientos: %i.", estado.num_mov);
		move(5,71);
		printw("--------------------------------");
		attron(A_BOLD);
		attron(COLOR_PAIR(1));
		move(4,72);
		printw("Movimientos: %i.", estado.num_mov);
		move(18,80);
		printw("  MI TURNO.      ");
		
		do
		{
			do
			{
				fila=rand()%8+1;
				columna=rand()%8+1;
			}while((tablero[fila][columna].pieza==' ')||(tablero[fila][columna].color!=NEGRO));
			
			do
			{
				filad=rand()%8+1;
				columnd=rand()%8+1;
			}while((fila==filad)&&(columna==columnd));//para que origen y destino no sea el mismo.
			permitido=comprobar_mov(columna, fila, columnd, filad, tablero, estado, moves);
		}while(permitido==0);//Si el movimiento esta permitido.
		
		mover_pieza(columna, fila, columnd, filad, tablero, estado, &moves); //mueve.
		estado.num_mov++;   //Sumamos el movimiento.
		estado.turno=BLANCO; //Cambiamos el turno.
		jugar_h(tablero, estado, moves);  //Juegan blancas(humano siempre).
}

int menu(struct s_casilla tablero[9][9], struct s_estado estado, struct s_mov *moves)
{
	WINDOW *win2;
	static const char *opciones[]={"1.- Jugar (1 jugador).        ", "2.- Jugar (2 jugadores).      ", "3.- Continuar.                ", "4.- Cargar partida.           ","5.- Grabar partida.           ", "6.- Visualizar partida.       ", "7.- Salir. (ESC)               ", NULL};	// Array de cadenas con los items
	const char **popciones;
	int cascii, *itemsel;
	int color;
	ITEM *items[sizeof(opciones)];
	ITEM **pitems=items;
	MENU *un_menu;
	
	noecho();               //Para que no salgan las letras que presionamos

	for (popciones=opciones; *popciones; popciones++) 
		*pitems++=new_item(*popciones, "");	
     	*pitems=NULL;
    	un_menu=new_menu(items);         	// Creo el menú. 
     	set_menu_format(un_menu, 7, 1);		// filas y columnas del menú. 
    	
	//creamos la ventana y activamos el contol de teclado.
	win2=newwin(11, 40, 6, 10);
	keypad(win2, TRUE);
	
	//definimos la ventana principal y la subventana.
	set_menu_win(un_menu, win2);
	set_menu_sub(un_menu, derwin(win2, 7, 38, 3, 1));
	
	set_menu_mark(un_menu, "  >>  ");
	
	//dibujamos el borde de la pantalla menu y le ponemos el titulo.
	box(win2, 0, 0);
	poner_en_medio(win2, 1, 0, 40, "MENú", COLOR_PAIR(1));
	mvwaddch(win2, 2, 0, ACS_LTEE);
	mvwhline(win2, 2, 1, ACS_HLINE, 38);
	mvwaddch(win2, 2, 39, ACS_RTEE);
	refresh();
	
     	post_menu(un_menu);		//Mostramos el menú.
    	estado.torre_B1=0;
	estado.torre_B2=0;
	estado.torre_N1=0;
	estado.torre_N2=0;
	estado.reyN=0;
	estado.reyB=0;
	while ((cascii=wgetch(win2))!=27) 
    	{
     		if ((cascii==KEY_DOWN) || (cascii==KEY_RIGHT)) 
			menu_driver(un_menu, REQ_DOWN_ITEM);                                                                   
    		else if ((cascii==KEY_UP) || (cascii==KEY_LEFT)) 
			menu_driver(un_menu, REQ_UP_ITEM);	
     		else if (cascii==10)  // Si se presiona enter.
        	{   
	   		itemsel=current_item(un_menu);
           		if (*itemsel=="1.- Jugar (1 jugador).        ") 
	   		{ 
	   			unpost_menu(un_menu);	//Quito el menú
       				free_menu(un_menu);	//Libero la memoria del menú 
       				for(pitems = items; *pitems; pitems++) 
       					free_item(*pitems) ; // Libero la memoria de cada item 
				inicializar_tablero(tablero,estado);
				init(&moves);
				estado.num_mov=0;
				estado.turno=BLANCO;
				
				pintar_tablero();
				pintar_fichas(tablero);
				estado.tipo_jug_b='H';
				estado.tipo_jug_n='O';
				jugar_h(tablero, estado, moves);
				
           		}
           		
			if (*itemsel=="2.- Jugar (2 jugadores).      ") 
	   		{	 
	   			unpost_menu(un_menu);	//Quito el menú
       				free_menu(un_menu);	//Libero la memoria del menú 
       				for(pitems = items; *pitems; pitems++) 
       					free_item(*pitems) ; // Libero la memoria de cada item 
				inicializar_tablero(tablero,estado);
				init(&moves);
				estado.num_mov=0;
				estado.turno=BLANCO;
				pintar_tablero();
				pintar_fichas(tablero); 
				estado.tipo_jug_b='H';
				estado.tipo_jug_n='H';
				jugar_h(tablero, estado, moves);
			}	 
            		
			if (*itemsel=="3.- Continuar.                ") 
	   		{ 
	   			unpost_menu(un_menu);	//Quito el menú
       				free_menu(un_menu);	//Libero la memoria del menú 
       				for(pitems = items; *pitems; pitems++) 
       					free_item(*pitems); // Libero la memoria de cada item 
				pintar_tablero();
				pintar_fichas(tablero);
				jugar_h(tablero, estado, moves); 
	   		}	 
             
	   		if (*itemsel=="4.- Cargar partida.           ") 
	   		{ 
	   			unpost_menu(un_menu);	//Quito el menú
       				free_menu(un_menu);	//Libero la memoria del menú 
       				for(pitems = items; *pitems; pitems++) 
       					free_item(*pitems); // Libero la memoria de cada item  
				pintar_tablero();
				keypad(stdscr, FALSE);
				endwin();
				cargar(tablero, &moves);
				
	   		}
			
			if (*itemsel=="5.- Grabar partida.           ") 
	   		{ 
	   			unpost_menu(un_menu);	//Quito el menú
       				free_menu(un_menu);	//Libero la memoria del menú 
       				for(pitems = items; *pitems; pitems++) 
       					free_item(*pitems); // Libero la memoria de cada item 
				pintar_tablero();
				keypad(stdscr, FALSE);
				endwin();
				guardar(tablero, estado, moves);	
	   		}	 
				 
           		if (*itemsel=="6.- Visualizar partida.       ") 
	   		{ 
	   			unpost_menu(un_menu);	//Quito el menú
       				free_menu(un_menu);	//Libero la memoria del menú 
       				for(pitems = items; *pitems; pitems++) 
       					free_item(*pitems); // Libero la memoria de cada item 
				inicializar_tablero(tablero, estado);
				estado.num_mov=0;
				pintar_tablero();
				keypad(stdscr, FALSE);
				endwin();
				visualizar(tablero, estado, moves);
	  		}
	   
	   		if (*itemsel=="7.- Salir. (ESC)               ") 
	   		{ 
	   			unpost_menu(un_menu);	//Quito el menú
       				free_menu(un_menu);	//Libero la memoria del menú 
       				for(pitems = items; *pitems; pitems++) 
       					free_item(*pitems) ; // Libero la memoria de cada item 
       				keypad(stdscr, FALSE);	// Desabilito las entradas de teclado y ratón 
       				endwin(); 		// Termino la ventana 
       				exit(0); 
	   		}
       		}
   	}
	unpost_menu(un_menu);	//Quito el menú
       	free_menu(un_menu);	//Libero la memoria del menú 
       	for(pitems = items; *pitems; pitems++) 
       		free_item(*pitems) ; // Libero la memoria de cada item 
       	keypad(stdscr, FALSE);	// Desabilito las entradas de teclado y ratón 
       	endwin(); 		// Termino la ventana 
       	exit(0); 
}

void poner_en_medio(WINDOW *win, int starty, int startx, int width, char *string, chtype color)
{
	int largo, x, y;
	float temp;
	
	if (win==NULL)
		win=stdscr;
	getyx(win, x, y);
	
	if(startx!=0)
		x=startx;
	if(starty!=0)
		y=starty;
	if(width==0)
		width=80;
		
	largo=strlen(string);
	temp=(width-largo)/2;
	x=startx+(int)temp;
	wattron(win, color);
	mvwprintw(win, y, x, "%s", string);
	wattroff(win, color);
	refresh();
}

int escribir_mov(int columna, int fila, int columnd, int filad, struct s_casilla tablero[9][9], struct s_estado estado)
{
	char colo, cold, piezo, piezd, sig;
	int filass, i, columnass;
	attron(COLOR_PAIR(1));
	
	if(tablero[filad][columnd].pieza!=NADA)
		sig='X';
	else
		sig='-';
	
	switch(tablero[fila][columna].pieza)
	{
		case PEON: piezo='P';break;
		case TORRE: piezo='T';break;
		case ALFIL: piezo='A';break;
		case CABALLO: piezo='C';break;
		case REY: piezo='K';break;
		case REINA: piezo='Q';break;
		case NADA: piezo=' ';break;
	}
	
	switch(tablero[filad][columnd].pieza)
	{
		case PEON: piezd='P';break;
		case TORRE: piezd='T';break;
		case ALFIL: piezd='A';break;
		case CABALLO: piezd='C';break;
		case REY: piezd='K';break;
		case REINA: piezd='Q';break;
		case NADA: piezd=' ';break;
	}
		
	switch(columna)
	{
		case 1: colo='a';break;
		case 2: colo='b';break;
		case 3: colo='c';break;
		case 4: colo='d';break;
		case 5: colo='e';break;
		case 6: colo='f';break;
		case 7: colo='g';break;
		case 8: colo='h';break;
	}
	
	switch(columnd)
	{
		case 1: cold='a';break;
		case 2: cold='b';break;
		case 3: cold='c';break;
		case 4: cold='d';break;
		case 5: cold='e';break;
		case 6: cold='f';break;
		case 7: cold='g';break;
		case 8: cold='h';break;
	}
	filass=estado.num_mov/15;
	columnass=(estado.num_mov-1)*8;
		
	move(30+filass, 1+columnass);
	for(i=0; i<filass; i++)
	{
		printw("\n");
	}
	printw("%c%c%i%c%c%c%i/", piezo, colo, fila, sig, piezd, cold, filad);
	
}

void init(struct s_mov **move)
{
	*move=NULL;
}

void pausa(long int n)
{
	long int i, j;
	for(i=0; i<n; i++)
	{
		for(j=0; j<n; j++)
		{
		}
	}
}

