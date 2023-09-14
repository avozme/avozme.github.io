void tirada_humano(struct s_casilla tablero[9][9],int xo,int yo,int x,int y,char turno);
void seleccionar_origen(struct s_casilla tablero[9][9],int *xo, int *yo,char turno);
char seleccionar_destino(struct s_casilla tablero[9][9],int *x, int *y,int xo,int yo,char turno);
char controlar_movimientos(struct s_casilla tablero[9][9],int xo,int yo,int x,int y, char turno);
void hacer_movimiento(struct s_casilla tablero[9][9],int xo,int yo,int x,int y);
