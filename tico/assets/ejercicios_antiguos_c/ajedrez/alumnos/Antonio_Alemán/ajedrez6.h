struct s_casilla{
char ocupada;
char color_casilla;
char pieza;
char color_pieza;
};
struct s_estado{
char turno;

};

void menu(struct s_casilla tablero[9][9],int con, struct s_estado *estado);
void principal(struct s_casilla tablero[9][9],struct s_estado *estado);
void nueva_partida(struct s_casilla tablero[9][9], struct s_estado *estado);
void guardar_partida(struct s_casilla tablero[9][9], struct s_estado *estado);
void cargar_partida(struct s_casilla tablero[9][9], struct s_estado *estado);
void inicializar_tablero(struct s_casilla tablero[9][9], struct s_estado *estado);
void ini_estado(struct s_estado *estado);
void dibujar_tablero(struct s_casilla tablero[9][9]);
void retardo(int r);
