//defines necesarios para el juego.
#define PEON 'P'
#define TORRE 'T'
#define CABALLO 'C'
#define ALFIL 'A'
#define REY 'R'
#define REINA 'D'
#define NADA ' '
#define BLANCO 'B'
#define NEGRO 'N'



//definicion de las estructuras.
struct s_casilla
{
	char color;   //color de la pieza (blanco o negro).
	char pieza;  //piezas: peon, torre, etc.
	char colorcas; //color de la casilla(blanco o negro).
};

struct s_estado
{
	int num_mov; //contador del numero de movimientos.
	char turno;  // turno blanco o negro.
	char tipo_jug_b; //jugador humano o pc.
	char tipo_jug_n; //jugador humano o pc.
	
	
	int torre_B1; //Si las distintas piezas necesarias para un ennroque se han movido.
	int torre_B2;
	int torre_N1;
	int torre_N2;
	int reyN;       
	int reyB;
};

struct s_movs
{
	int mov_n;
	int x;
	int y;
	int xd;
	int yd;
	char pieza;
	char piezad;
};

struct s_mov
{
	struct s_movs movimiento;
	struct s_mov *siguiente;
};



//prototipo de las funciones.
int pintar_tablero();
int inicializar_tablero(struct s_casilla tablero[9][9], struct s_estado estado);
int pintar_fichas(struct s_casilla tablero[9][9]);
int jugar_h(struct s_casilla tablero [9][9], struct s_estado estado, struct s_mov *moves);
int jugar_o(struct s_casilla tablero [9][9], struct s_estado estado, struct s_mov *moves);
int menu(struct s_casilla tablero [9][9], struct s_estado estado, struct s_mov *moves);
void poner_en_medio(WINDOW *win, int starty, int startx, int width, char *string, chtype color);
int escribir_mov(int columna, int fila, int columnd, int filad, struct s_casilla tablero[9][9], struct s_estado estado);
void init(struct s_mov **move);
void pausa(long int n);
