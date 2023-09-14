// Aqui defino las constantes..

# define PEON 'P'
# define CABALLO 'C'
# define  TORRE 'T'
# define ALFIL 'A'
# define DAMA 'D'
# define REY 'R'
# define NINGUNA 'X'
# define BLANCO 'B'
# define NEGRO 'N'
# define HUMANO 'H'
# define MAQUINA 'M'

// Aqui defino las estructuras q necesitare durante el programa(2: el estado y el tablero)

struct s_casilla {

	char ocupada;  //nos dice si la casilla esta ocupada o no
	char color_casilla; // nos dice el color de la casilla, si blanca o negra
	char tipo_pieza; // nos informa del tipo de la figura
	char color_pieza; //nos dice si la figura es blanca o negra

};
struct s_estado {

	char turno; // nos dice quien tiene el turno
	int n_movim;
	char tipo_blancas;
	char tipo_negras;
	char jaque_rey_negro;
	char jaque_rey_blanco;
	char ficha_hace_jaque;

};

// Aqui ponemos las cabeceras de todos los procedimientos del ajedrez.c

void iniciar_ncurses(void);
void inicializar(struct s_casilla tablero[9][9],struct s_estado *estado);
void inicializar_estado(struct s_estado *estado);

void dibujar_tablero(struct s_casilla tablero[9][9],struct s_estado estado);
void colocar_piezas(struct s_casilla tablero[9][9]);

int menu(void);
void guardar_partida(struct s_casilla tablero[9][9], struct s_estado estado);
void cargar_partida(struct s_casilla tablero[9][9], struct s_estado *estado);