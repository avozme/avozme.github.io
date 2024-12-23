
#define PEONB P
#define TORREB T
#define CABALLOB C
#define ALFILB A
#define REYB R
#define REINAB D
#define PEON p
#define TORRE t
#define CABALLO c
#define ALFIL a
#define REY r
#define REINA d

struct s_casilla
{
	char color;
	char figura;
	char color_ficha;
};

int pintar_tablero();
int inicializar_tablero(struct s_casilla tablero[9][9]);
int pintar_fichas();
int convertir(int n);
int refrescar_matriz(struct s_casilla tablero[9][9]);
int codificar(int n);
void ejemplo(struct s_casilla tablero[9][9]);
void ejemplo2(struct s_casilla tablero[9][9]);

