#include<stdio.h>
#include<ncurses.h>

#define PEON 'P'
#define TORRE 'T'
#define CABALLO 'C'
#define ALFIL 'A'
#define REY 'R'
#define DAMA 'D'

#define NADA ' '
#define BLANCA 'B'
#define NEGRA 'N'
#define AZUL 'A'

struct s_casillas{
	char color;
	char pieza;
	char color_pieza;
};

struct s_estado{
	char turno;
	char rey_negro_movido;
	char torre_i_negra_movida;
	char torre_d_negra_movida;
	char rey_blanco_movido;
	char torre_i_blanca_movida;
	char torre_d_blanca_movida;
};

struct s_nodo{
	char mov[8];
	struct s_nodo *siguiente;
};

//int A=0;

void inic_tablero(struct s_casillas tab[9][9]);
void inic_estado(struct s_estado* estado);
void menu(struct s_estado *estado, struct s_casillas tablero[9][9]);
void dibujar_cuadro();
void retardo(int tiempo);
 

