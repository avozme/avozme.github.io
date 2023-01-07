struct casilla
{
	int color_casilla;
	char ficha;
	int color_ficha;
};

struct s_estado
{
	int n_mov;
	int turno;
};

struct posicion
{
	int fila_origen;
	int columna_origen;
	int fila_destino;
	int columna_destino;
};

int menu(struct casilla tablero[8][8], struct s_estado *estado, struct posicion *posicion);
int principal(struct casilla tablero[8][8], struct s_estado *estado, struct posicion *posicion);
int inicializar(struct casilla tablero[8][8], struct s_estado *estado);
int iniciar_tablero(struct casilla tablero[8][8]);
int iniciar_estado(struct s_estado *estado);
int dibujar_tablero(struct casilla tablero[8][8]);
int tirar_humano(struct casilla tablero[8][8], struct s_estado *estado, struct posicion *posicion);
int convertir_fila(int fila);
int convertir_columna(int columna);
int elegir_origen(struct casilla tablero[8][8], struct posicion *posicion, struct s_estado *estado);
int comprobar_origen(struct casilla tablero[8][8], struct s_estado *estado, struct posicion *posicion);
int elegir_destino(struct casilla tablero[8][8], struct posicion *posicion, struct s_estado *estado);
int comprobar_destino(struct casilla tablero[8][8], struct s_estado *estado, struct posicion *posicion);
int mover(struct casilla tablero[8][8], struct s_estado *estado, struct posicion *posicion);
int guardar();
int cargar(struct casilla tablero[8][8], struct s_estado *estado, struct posicion *posicion);
