void origen(struct s_casillas tab[8][8],int *fila , int *columna ,char color,struct s_estado *esta);
void tirar (struct s_casillas tab[8][8], struct s_estado *esta);
void destino (struct s_casillas tab[8][8], int *filad, int *columnad,char color,struct s_estado *esta );
int movimientos(struct s_casillas tab[8][8],int *columna,int *fila, int *columnad, int *filad,char color,struct s_estado *esta);
void selec_casilla(struct s_casillas tab[8][8], int *fila,int *columna,char color,char toca,struct s_estado *esta);
void dibujar_cuadro(struct s_casillas tab[8][8],char color,int *fila,int *columna,char toca);


