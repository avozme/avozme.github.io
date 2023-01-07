#include <stdio.h>
#include <ncurses.h>
#include "ajedrez.h"
#include "piezas.h"





int main(void)
{
struct casilla tablero[8][8];
struct s_estado estado;
struct posicion posicion;
int opcion, especial;

	initscr();
	cbreak();
	keypad(stdscr, 1);
	if (has_colors())
		start_color();
	init_pair(1, COLOR_BLUE, COLOR_RED);
	init_pair(2, COLOR_WHITE, COLOR_YELLOW);
	init_pair(3, COLOR_WHITE, COLOR_BLACK);
	init_pair(4, COLOR_RED, COLOR_YELLOW);
	init_pair(5, COLOR_RED, COLOR_BLACK);
	init_pair(6, COLOR_YELLOW, COLOR_RED);
	init_pair(7, COLOR_BLACK, COLOR_RED);
	init_pair(8, COLOR_WHITE, COLOR_RED);
	init_pair(9, COLOR_RED, COLOR_BLUE);
	bkgd(COLOR_PAIR(1));
	inicializar(tablero, &estado);
	especial = -1;
	
	do
	{
  	   if (especial == -1) {
	   	dibujar_menu();
	        opcion=menu(tablero, &estado, &posicion);
	        switch(opcion)
	      {
		case '1':
			remove("archivo.dat");
			inicializar(tablero, &estado);
			break;
		case '2':
      	remove("archivo.dat");
			inicializar(tablero, &estado);
			cargar(tablero, &estado, &posicion);
			break;
		case '3':
			guardar();
			break;
		case '4':
			break;
	      }
	   }
	   int borrar_menu();
	   especial = principal(tablero, &estado, &posicion);
	}
	while (1==1);


return 0;
}
int borrar_menu()
{
	attron(COLOR_PAIR(1));
	 move(5,15);printw("                                                     ");
	 move(6,15);printw("                                                     ");
	 move(7,15);printw("                                                     ");
	 move(8,15);printw("                                                     ");
	 move(9,15);printw("                                                     ");
	move(10,15);printw("                                                     ");
	move(11,15);printw("                                                     ");
	move(12,15);printw("                                                     ");
	move(13,15);printw("                                                     ");
	move(14,15);printw("                                                     ");
	move(15,15);printw("                                                     ");
	move(16,15);printw("                                                     ");
	move(17,15);printw("                                                     ");
	move(18,15);printw("                                                     ");
return 0;
}

int dibujar_menu()
{
	attron(COLOR_PAIR(9));
	 move(5,15);printw("                                                     ");
	 move(6,15);printw("                                                     ");
	 move(7,15);printw("                                                     ");
	 move(8,15);printw("                                                     ");
	 move(9,15);printw("                                                     ");
	move(10,15);printw("                                                     ");
	move(11,15);printw("                                                     ");
	move(12,15);printw("                                                     ");
	move(13,15);printw("                                                     ");
	move(14,15);printw("                                                     ");
	move(15,15);printw("                                                     ");
	move(16,15);printw("                                                     ");
	move(17,15);printw("                                                     ");
	move(18,15);printw("                                                     ");
return 0;
}

int menu(struct casilla tablero[8][8], struct s_estado *estado, struct posicion *posicion)
{
int opcion;
	dibujar_menu();
	attron(COLOR_PAIR(9));
	move(6,30); printw("MENU:");
	move(8,30); printw("1. Nueva partida");
	move(10,30); printw("2, Cargar partida");
	if(estado->n_mov != 0){
		move(12,30); printw("3. Guardar partida");
		move(14,30); printw("4. Volver a la partida");
	}
	move(17,30); printw("Introduzca una opcion:");
	move(17,52); opcion = getch();
	while((opcion!='1') && (opcion!='2') && (opcion!='3') && (opcion!='4'))
	{
		move(17,52); printw("Opcion incorrecta");
		opcion = getch();
	}
	if(estado->n_mov ==0)
	{
		while((opcion=='3') || (opcion=='4'))
		{
			move(17,52); printw("Opcion incorrecta");
			opcion = getch();
		}
	}
	clear();

return opcion;
}

int principal(struct casilla tablero[8][8], struct s_estado *estado, struct posicion *posicion)
{
int especial;

	dibujar_tablero(tablero);
	do
	{
		especial = tirar_humano(tablero, estado, posicion);
		dibujar_tablero(tablero);
	}while(especial != -1);

return especial;
}

int inicializar(struct casilla tablero[8][8], struct s_estado *estado)
{

	iniciar_tablero(tablero);
	iniciar_estado(estado);

return 0;
}

int iniciar_tablero(struct casilla tablero[8][8])
{

int i, j;

	for(i=0; i<8; i++)
	{
		for(j=0; j<8; j++)
		{
			tablero[i][j].ficha=' ';
			tablero[i][j].color_ficha=2;
			if(i%2==0)			// Columna par
			{
				if(j%2==0)			// Fila par
				{
					tablero[i][j].color_casilla=0;
				}
				else				// Fila impar
				{
					tablero[i][j].color_casilla=1;
				}
			}
			else					// Columna impar
			{
				if(j%2==1)			// Fila impar
				{
					tablero[i][j].color_casilla=0;
				}
				else				// Fila par
				{
					tablero[i][j].color_casilla=1;
				}
			}
		}
	}
	
	tablero[0][0].ficha='T';
	tablero[0][1].ficha='C';
	tablero[0][2].ficha='A';
	tablero[0][3].ficha='D';
	tablero[0][4].ficha='R';
	tablero[0][5].ficha='A';
	tablero[0][6].ficha='C';
	tablero[0][7].ficha='T';
	for(j=0; j<8; j++)
	{
		tablero[1][j].ficha='P';
		tablero[0][j].color_ficha=1;
		tablero[1][j].color_ficha=1;
		tablero[6][j].ficha='P';
		tablero[6][j].color_ficha=0;
		tablero[7][j].color_ficha=0;
	}
	tablero[7][0].ficha='T';
	tablero[7][1].ficha='C';
	tablero[7][2].ficha='A';
	tablero[7][3].ficha='D';
	tablero[7][4].ficha='R';
	tablero[7][5].ficha='A';
	tablero[7][6].ficha='C';
	tablero[7][7].ficha='T';

return 0;
}

int iniciar_estado(struct s_estado *estado)
{

	estado->n_mov=0;
	estado->turno=0;

return 0;
}

// Dibuja el tablero en su estado actual
int dibujar_tablero(struct casilla tablero[8][8])
{

int i, j;

	attron(COLOR_PAIR(1));
	
	move(1,5);			// Imprimir letra columna
		printw("a");
	move(1,10);
		printw("b");
	move(1,15);
		printw("c");
	move(1,20);
		printw("d");
	move(1,25);
		printw("e");
	move(1,30);
		printw("f");
	move(1,35);
		printw("g");
	move(1,40);
		printw("h");

	for(j=0; j<8; j++)		// Imprimir número fila
	{
		move((j*3)+4,1);
			printw("%d", j+1);
	}
	
	for(i=0; i<8; i++)		
	{
		for(j=0; j<8; j++)
		{
			if(tablero[i][j].color_casilla==0)		// Color casilla blanco 
			{
				if(tablero[i][j].color_ficha==2)	// No hay ficha
				{
					attron(COLOR_PAIR(2));
					move((i*3)+3,(j*5)+3); printw("     ");
					move((i*3)+4,(j*5)+3); printw("     ");
					move((i*3)+5,(j*5)+3); printw("     ");
				}
				else
				{
					if(tablero[i][j].color_ficha==0)	// Ficha blanca 
					{
						attron(COLOR_PAIR(2));
						move((i*3)+3,(j*5)+3); printw("     ");
						move((i*3)+4,(j*5)+3); printw("  %c  ", tablero[i][j].ficha);
						move((i*3)+5,(j*5)+3); printw("     ");
					}
					else					// Ficha negra 
					{
						attron(COLOR_PAIR(4));
						move((i*3)+3,(j*5)+3); printw("     ");
						move((i*3)+4,(j*5)+3); printw("  %c  ", tablero[i][j].ficha);
						move((i*3)+5,(j*5)+3); printw("     ");
					}
				}
			}
			else						// Color casilla negro 
			{
				if(tablero[i][j].color_ficha==2)	// No hay ficha
				{
					attron(COLOR_PAIR(3));
					move((i*3)+3,(j*5)+3); printw("     ");
					move((i*3)+4,(j*5)+3); printw("     ");
					move((i*3)+5,(j*5)+3); printw("     ");
				}
				else
				{
					if(tablero[i][j].color_ficha==0)	// Ficha blanca
					{
						attron(COLOR_PAIR(3));
						move((i*3)+3,(j*5)+3); printw("     ");
						move((i*3)+4,(j*5)+3); printw("  %c  ", tablero[i][j].ficha);
						move((i*3)+5,(j*5)+3); printw("     ");
					}
					else					// Ficha negra
					{
						attron(COLOR_PAIR(5));
						move((i*3)+3,(j*5)+3); printw("     ");
						move((i*3)+4,(j*5)+3); printw("  %c  ", tablero[i][j].ficha);
						move((i*3)+5,(j*5)+3); printw("     ");
					}
				}
			}
		}
	}
	refresh();
return 0;
}

int tirar_humano(struct casilla tablero[8][8], struct s_estado *estado, struct posicion *posicion)
{
int valido;
long int i;
int especial=0;

	do{
		especial=elegir_origen(tablero, posicion, estado);
		if (especial == -1) break;
		valido=comprobar_origen(tablero, estado, posicion);
		if(valido==0)
		{
			attron(COLOR_PAIR(6));
			move(12, 64);
			printw("NO PUEDES ELEGIR ESTA POSICION ORIGEN..."); refresh();
			for(i=0; i<=1000000000L; i++);
			move(12, 64);
			printw("                                        ");
			printw(" ");
			move(10,92);
			printw(" ");
		}
	}while(valido==0);
	if (especial != -1)
	{
	   do{
		especial = elegir_destino(tablero, posicion, estado);
		if (especial == -1) break;
		valido=comprobar_destino(tablero, estado, posicion);
		if(valido==0)
		{
			attron(COLOR_PAIR(6));
			move(22, 64);
			printw("NO PUEDES ELEGIR ESTA POSICION DESTINO..."); refresh();
			for(i=0; i<=1000000000L; i++);
			move(22, 64);
			printw("                                         ");
			move(18,90);
			printw(" ");
			move(20,93);
			printw(" ");
		}
	   }while(valido==0);
	}
	
	if (especial != -1) 
	{
		mover(tablero, estado, posicion);

		for(i=0; i<=1000000000L; i++);
		attron(COLOR_PAIR(6));
		move(5,64);
		printw("                         ");
		move(8,65);
		printw("                          ");
		move(10,65);
		printw("                             ");
		move(15,64);
		printw("                         ");
		move(18,65);
		printw("                           ");
		move(20,65);
		printw("                              ");
		move(3, 64);
		printw("                    ");
		move(3, 88);
		printw("                       ");
	}

return especial;
}

int convertir_fila(int fila)
{
int n;

	switch(fila)
	{
		    case '1': n=1 ; break;
		    case '2': n=2 ; break;
		    case '3': n=3 ; break;
		    case '4': n=4 ; break;
		    case '5': n=5 ; break;
		    case '6': n=6 ; break;
		    case '7': n=7 ; break;
		    case '8': n=8 ; break;
	}
return n;
}

int convertir_columna(int columna)
{
char n;
	switch(columna)
	{
		    case 0: n='A' ; break;
		    case 1: n='B' ; break;
		    case 2: n='C' ; break;
		    case 3: n='D' ; break;
		    case 4: n='E' ; break;
		    case 5: n='F' ; break;
		    case 6: n='G' ; break;
		    case 7: n='H' ; break;
		    
	}
return n;
}

int elegir_origen(struct casilla tablero[8][8], struct posicion *posicion, struct s_estado *estado)
{
long int i;
int opcion, especial = 0;
int columna;

	

	attron(COLOR_PAIR(1));
	move(3, 88);
	printw("Movimientos: ");
	attron(COLOR_PAIR(6));
	printw("%d", estado->n_mov);
	attron(COLOR_PAIR(1));
	move(3, 64);
	printw("Turno de las ");
	
	if(estado->turno==0){
		attron(COLOR_PAIR(8));
		printw("BLANCAS");
	}
	if(estado->turno==1){
		attron(COLOR_PAIR(7));
		printw("NEGRAS ");
	}
	move(5,64);
	printw("ELIJA LA POSICION ORIGEN:");
	attron(COLOR_PAIR(1));
	move(8,65);
	printw("Fila origen: ");
	move(10,65);
	printw("Columna origen: ");
	
	posicion->fila_origen=0;
	posicion->columna_origen=0;
	
	do{
  	  dibujar_tablero(tablero);
	  if(estado->turno==0){
		attron(COLOR_PAIR(8));
		move(8, 78); printw("%d", posicion->fila_origen+1);
		columna=convertir_columna(posicion->columna_origen);
		move(10,81); printw("%c", columna);
		 
	}
	   if(estado->turno==1){
		attron(COLOR_PAIR(7));
		move(8, 78); printw("%d", posicion->fila_origen+1);
		columna=convertir_columna(posicion->columna_origen);
		move(10,81); printw("%c", columna);
		
	}
	attron(COLOR_PAIR(9));
	move((posicion->fila_origen*3)+3, (posicion->columna_origen*5)+3); printw("     ");
	move((posicion->fila_origen*3)+4, (posicion->columna_origen*5)+3); printw("  ");
	move((posicion->fila_origen*3)+4, (posicion->columna_origen*5)+6); printw("  ");
	move((posicion->fila_origen*3)+5, (posicion->columna_origen*5)+3); printw("     ");
		refresh();
		opcion = getch();
		switch(opcion){
			
			case KEY_DOWN:
				if(posicion->fila_origen < 7)
				{
					posicion->fila_origen++;
				}
				break;
			case KEY_UP:
				if(posicion->fila_origen > 0)
				{
					posicion->fila_origen--;
				}
				break;
			
			case KEY_RIGHT:
				if(posicion->columna_origen < 7)
				{
					posicion->columna_origen++;
				}
				break;
			case KEY_LEFT:
				if(posicion->columna_origen > 0)
				{
					posicion->columna_origen--;
				}
				break;
			case 'm': especial=-1; break;
			case 'M': especial=-1; break;
			case 10: especial=1; break;
		}
	}while ((especial!=1) && (especial!=-1));
	
return especial;
}

int comprobar_origen(struct casilla tablero[8][8], struct s_estado *estado, struct posicion *posicion)
{
int valido=0;
	if(tablero[posicion->fila_origen][posicion->columna_origen].color_ficha == estado->turno)
	{
		valido=1;
	}

return valido;	
}

int elegir_destino(struct casilla tablero[8][8], struct posicion *posicion, struct s_estado *estado)
{
long int i;
char columna;
int especial=0;
int opcion;

	if(estado->turno==0){
		attron(COLOR_PAIR(8));
	}
	if(estado->turno==1){
		attron(COLOR_PAIR(7));
	}
	move(15,64);
	printw("ELIJA LA POSCION DESTINO:");
	attron(COLOR_PAIR(1));
	move(18,65);
	printw("Fila destino: ");
	attron(COLOR_PAIR(1));
	move(20,65);
	printw("Columna destino: ");
	posicion->fila_destino=0;
	posicion->columna_destino=0;
	do{
  	  dibujar_tablero(tablero);
	  if(estado->turno==0){
		attron(COLOR_PAIR(8));
		move(18, 79); printw("%d", posicion->fila_destino+1);
		columna=convertir_columna(posicion->columna_destino);
		move(20,82); printw("%c", columna);	 
	}
	   if(estado->turno==1){
		attron(COLOR_PAIR(7));
		move(8, 79); printw("%d", posicion->fila_destino+1);
		columna=convertir_columna(posicion->columna_destino);
		move(10,82); printw("%c", columna);
	}
	attron(COLOR_PAIR(9));
	move((posicion->fila_destino*3)+3, (posicion->columna_destino*5)+3); printw("     ");
	move((posicion->fila_destino*3)+4, (posicion->columna_destino*5)+3); printw("  ");
	move((posicion->fila_destino*3)+4, (posicion->columna_destino*5)+6); printw("  ");
	move((posicion->fila_destino*3)+5, (posicion->columna_destino*5)+3); printw("     ");
		opcion = getch();
		switch(opcion){
			
			case KEY_DOWN:
				if(posicion->fila_destino < 7)
				{
					posicion->fila_destino++;
				}
				break;
			case KEY_UP:
				if(posicion->fila_destino > 0)
				{
					posicion->fila_destino--;
				}
				break;
			
			case KEY_RIGHT:
				if(posicion->columna_destino < 7)
				{
					posicion->columna_destino++;
				}
				break;
			case KEY_LEFT:
				if(posicion->columna_destino > 0)
				{
					posicion->columna_destino--;
				}
				break;
			case 10: especial=1; break;
			case 'm': especial=-1; break;
			case 'M': especial=-1; break;
		}
	}while ((especial!=1) && (especial!=-1));
	
	
return especial;
}

int comprobar_destino(struct casilla tablero[8][8], struct s_estado *estado, struct posicion *posicion)
{
int valido=0;
	if(tablero[posicion->fila_origen][posicion->columna_origen].ficha=='C')
	{
		valido=caballo(tablero, posicion, valido);
	}
	if(tablero[posicion->fila_origen][posicion->columna_origen].ficha=='P')
	{
		valido=peon(tablero, estado, posicion, valido);
	}
	if(tablero[posicion->fila_origen][posicion->columna_origen].ficha=='T')
	{
		valido=torre(tablero, posicion, valido);
	}
	if(tablero[posicion->fila_origen][posicion->columna_origen].ficha=='A')
	{
		valido=alfil(tablero, posicion, valido);
	}
	if(tablero[posicion->fila_origen][posicion->columna_origen].ficha=='R')
	{
		valido=rey(tablero, posicion, valido);
	}
	if(tablero[posicion->fila_origen][posicion->columna_origen].ficha=='D')
	{
		valido=alfil(tablero, posicion, valido);
		valido=torre(tablero, posicion, valido);
	}
	
	if(tablero[posicion->fila_destino][posicion->columna_destino].color_ficha == estado->turno)
	{
		valido=0;
	}
	if((posicion->fila_origen == posicion->fila_destino) && (posicion->columna_origen == posicion->columna_destino))
	{
		valido=0;
	}

return valido;
}

int mover(struct casilla tablero[8][8],struct s_estado *estado, struct posicion *posicion)
{
FILE *f;

	tablero[posicion->fila_destino][posicion->columna_destino].color_ficha=tablero[posicion->fila_origen][posicion->columna_origen].color_ficha;
	
	tablero[posicion->fila_destino][posicion->columna_destino].ficha=tablero[posicion->fila_origen][posicion->columna_origen].ficha;
	
	tablero[posicion->fila_origen][posicion->columna_origen].ficha=' ';
	tablero[posicion->fila_origen][posicion->columna_origen].color_ficha=2;
	
	if(estado->turno==0)
	{
		estado->turno=1;
	}
	else{
		estado->turno=0;
	}
	estado->n_mov++;
	
	f= fopen("archivo.dat", "ab");
	if (f == NULL)
	{ 
		move(3, 64);
		attron(COLOR_PAIR(9));
		printw("Error al abrir el archivo");
	}
	else
	{
		fwrite(posicion, sizeof(struct posicion), 1, f);
		fclose(f);
	}
	
return 0;
}
int guardar()
{
struct posicion posicion;
FILE *f;
FILE *nuevo;
char fichero[20];
int n;
long int i;

	dibujar_menu();
	attron(COLOR_PAIR(9));
	move(10,16); printw("Introduzca nombre con el que guardara la partida: ");
	move(11,16); getstr(fichero);
	int borrar_menu();
	f= fopen("archivo.dat", "rb");
	if (f == NULL)
	{
		move(3, 64);
		attron(COLOR_PAIR(9));
		printw("Error al abrir el archivo");
     		 for(i=0; i<=1000000000L; i++);
		move(3, 64);
		printw("                      ");
	}
	else{
		nuevo= fopen(fichero, "wb");
		if(nuevo == NULL)
		{
      			move(3, 64);
			attron(COLOR_PAIR(9));
			printw("Error al abrir el archivo");
		}
		else
		{
			while (!feof(f))
			{
				n = fread(&posicion, sizeof(struct posicion), 1, f);
				if (n>0) fwrite(&posicion, sizeof(struct posicion), 1, nuevo);
			}
			fclose(nuevo);
		}
		fclose(f);
	}
return 0;
}

int cargar(struct casilla tablero[8][8], struct s_estado *estado, struct posicion *posicion)
{
FILE *fich;
char fichero[20];
int n;
long int i;

	dibujar_menu();
	attron(COLOR_PAIR(9));
	move(10,16); printw("Introduzca nombre del fichero que quiere cargar: ");
	move(11,16); getstr(fichero);
	int borrar_menu();
	fich= fopen(fichero, "rb");
	if (fich == NULL)
	{
		move(3, 64);
		attron(COLOR_PAIR(9));
		printw("Error al abrir archivo");
		for(i=0; i<=1000000000L; i++);
		move(3, 64);
		printw("                      ");
	}
	else
	{
		while (!feof(fich))
		{
			n = fread(posicion, sizeof(struct posicion), 1, fich);
			if (n>0) mover(tablero, estado, posicion);
			dibujar_tablero(tablero);
			for(i=0; i<=1000000000L; i++);
		}
		fclose(fich);
	}
return 0;
}

