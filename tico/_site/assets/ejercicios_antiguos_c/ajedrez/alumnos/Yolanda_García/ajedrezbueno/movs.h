// aqui ponemos todas las cabeceras de archivo movs.c para poder trabajar con ellas e incluirlas en ajedrez.c, ...

int mover_humano(struct s_casilla tablero[9][9],struct s_estado estado);
int convertir(char c);
char casilla_origen( struct s_casilla tablero[9][9],int *xo,int *yo);
char casilla_destino(struct s_casilla tablero[9][9],int *xd,int *yd);
void mover(struct s_casilla tablero[9][9],int xo,int yo,int xd,int yd);
int comprobar_origen( struct s_casilla tablero[9][9], struct s_estado estado, int ox, int oy);
int comprobar_movimiento(struct s_casilla tablero[9][9],struct s_estado estado, int ox, int oy,int dx,int dy);
int compr_movi_peon(struct s_casilla tablero[9][9], struct s_estado estado, int ox, int oy, int dx, int dy);
int compr_movi_caballo (struct s_casilla tablero[9][9], struct s_estado estado, int ox, int oy, int dx, int dy);
int compr_movi_rey(struct s_casilla tablero[9][9], struct s_estado estado, int ox, int oy, int dx, int dy);
int compr_movi_torre(struct s_casilla tablero[9][9],struct s_estado estado,int ox,int oy,int dx,int dy);
int compr_movi_alfil(struct s_casilla tablero[9][9],struct s_estado estado,int ox,int oy,int dx,int dy);
int compr_movi_dama(struct s_casilla tablero[9][9],struct s_estado estado,int ox,int oy,int dx,int dy);
