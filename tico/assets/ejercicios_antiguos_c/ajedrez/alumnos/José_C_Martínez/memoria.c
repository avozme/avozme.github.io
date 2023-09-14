#include "ajedrez.h"
#include "memoria.h"


int cargar_partida(struct s_casillas tablero[9][9], struct s_estado* estado){
FILE *f, *g, *h;
struct s_estado eaux;
int i, j, valido=0;
int x, y, xa, ya, opc, tecla;
	
	dibujar_cuadro(1);
	move(17, 58);
	attron(COLOR_PAIR(10));
	printw("CARGAR PARTIDA");
	
	move(21, 51);						////////////////RANURA 1//////////////
	f=fopen("aje1.pgn", "r");
	if(f==NULL){
		attron(COLOR_PAIR(9));
		printw("VACIO");
	}
	else{
		fread(&eaux, sizeof(struct s_estado), 1, f);
		attron(COLOR_PAIR(6));
		printw("PARTIDA 1: %c", eaux.turno);
		fclose(f);
	}

	move(23, 51);						/////////////////RANURA 2/////////////////
	g=fopen("aje2.pgn", "r");
	if(g==NULL){
		attron(COLOR_PAIR(9));
		printw("VACIO");
	}
	else{
		fread(&eaux, sizeof(struct s_estado), 1, g);
		attron(COLOR_PAIR(6));
		printw("PARTIDA 2: %c", eaux.turno);
		fclose(g);
	}

	move(25, 51);						//////////////////RANURA 3//////////////////
	h=fopen("aje3.pgn", "r");
	if(h==NULL){
		attron(COLOR_PAIR(9));
		printw("VACIO");
	}
	else{
		fread(&eaux, sizeof(struct s_estado), 1, h);
		attron(COLOR_PAIR(6));
		printw("PARTIDA 3: %c", eaux.turno);
		fclose(h);
	}
	
	move(27, 51);
	attron(COLOR_PAIR(10));
	printw("VOLVER");
	
	opc=1;
	y=21, x=48; ya=y; xa=x;
	do{
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
			case KEY_UP: if(y>21){ y=y-2; opc=opc-1; }	break;
			case KEY_DOWN: if(y<27){ y=y+2; opc=opc+1; }	break;
			case 10: switch(opc){
					case 1: f=fopen("aje1.pgn", "r");
						if(f!=NULL){
							fread(estado, sizeof(struct s_estado), 1, f);
							for(i=0; i<=8; i++){
								for(j=0; j<=8; j++){
								     fread(&tablero[i][j], sizeof(struct s_casillas), 1, f);
								}
							}
							fclose(f);
							valido=1;
						}
						else valido=0;
						break;
					case 2: g=fopen("aje2.pgn", "r");
						if(g!=NULL){
							fread(estado, sizeof(struct s_estado), 1, g);
							for(i=0; i<=8; i++){
								for(j=0; j<=8; j++){
								     fread(&tablero[i][j], sizeof(struct s_casillas), 1, g);
								}
							}
							fclose(g);
							valido=1;
						}
						else valido=0;
						break;
					case 3: h=fopen("aje2.pgn", "r");
						if(h!=NULL){
							fread(estado, sizeof(struct s_estado), 1, h);
							for(i=0; i<=8; i++){
								for(j=0; j<=8; j++){
								     fread(&tablero[i][j], sizeof(struct s_casillas), 1, h);
								}
							}
							fclose(h);
							valido=1;
						}
						else valido=0;
						break;
					case 4: return 0;
				}
		}
	} while(valido==0);
	return valido;	
}


int guardar_partida(struct s_casillas tablero[9][9], struct s_estado estado){
FILE *f, *g, *h;
struct s_estado eaux;
int i, j;
int x, y, xa, ya, opc, tecla;

	dibujar_cuadro(1);
	
	move(17, 58);
	attron(COLOR_PAIR(10));
	printw("GUARDAR PARTIDA");
	
	move(21, 51);						///////////////RANURA 1//////////////
	f=fopen("aje1.pgn", "r");
	if(f==NULL){
		attron(COLOR_PAIR(9));
		printw("VACIO");
	}
	else{
		fread(&eaux, sizeof(struct s_estado), 1, f);
		attron(COLOR_PAIR(6));
		printw("PARTIDA 1: %c", eaux.turno);
		fclose(f);
	}

	move(23, 51);						//////////////RANURA 2//////////////////
	g=fopen("aje2.pgn", "r");
	if(g==NULL){
		attron(COLOR_PAIR(9));
		printw("VACIO");
	}
	else{
		fread(&eaux, sizeof(struct s_estado), 1, g);
		attron(COLOR_PAIR(6));
		printw("PARTIDA 2: %c", eaux.turno);
		fclose(g);
	}
	
	move(25, 51);						///////////////RANURA 3////////////////
	h=fopen("aje3.pgn", "r");
	if(h==NULL){
		attron(COLOR_PAIR(9));
		printw("VACIO");
	}
	else{
		fread(&eaux, sizeof(struct s_estado), 1, h);
		attron(COLOR_PAIR(6));
		printw("PARTIDA 3: %c", eaux.turno);
		fclose(h);
	}

	move(27, 51);
	attron(COLOR_PAIR(10));
	printw("VOLVER");
	
	opc=1;
	y=21, x=48; ya=y; xa=x;
	do{
		attron(COLOR_PAIR(10));
		move(ya, xa);
		printw("  ");
		move(y, x);
		printw(">>");
		move(40, 122);
		ya = y; xa = x;

		refresh();
		tecla=getch();
		switch(tecla){
			case KEY_UP: if(y>21){ y=y-2; opc=opc-1; }	break;
			case KEY_DOWN: if(y<27){ y=y+2; opc=opc+1; }	break;
			case 10:
				switch(opc){
					case 1: f=fopen("aje1.pgn", "w");
						fwrite(&estado, sizeof(struct s_estado), 1, f);
						for(i=0; i<=8; i++){
							for(j=0; j<=8; j++){
								fwrite(&tablero[i][j], sizeof(struct s_casillas), 1, f);
							}
						}
						fclose(f);
						clear();
						return 1;
						break;
					case 2: g=fopen("aje2.pgn", "w");
						fwrite(&estado, sizeof(struct s_estado), 1, g);
						for(i=0; i<=8; i++){
							for(j=0; j<=8; j++){
								fwrite(&tablero[i][j], sizeof(struct s_casillas), 1, g);
							}
						}
						fclose(g);
						clear();
						return 1;
						break;
					case 3: h=fopen("aje2.pgn", "w");
						fwrite(&estado, sizeof(struct s_estado), 1, h);
						for(i=0; i<=8; i++){
							for(j=0; j<=8; j++){
								fwrite(&tablero[i][j], sizeof(struct s_casillas), 1, h);
							}
						}
						fclose(h);
						clear();
						return 1;
						break;
					case 4: return 0;
				}
		}
	}while(tecla!=10);
}