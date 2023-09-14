void dibujar_tablero(struct s_casillas tablero[9][9]);
void mover(struct s_estado *estado, struct s_casillas tablero[9][9]);
void presentacion(); 
void convertir_a_caracter(int i, int j, char *col, char *fil);
void cambiar_pieza(struct s_casillas tablero[9][9], int jd, int id);