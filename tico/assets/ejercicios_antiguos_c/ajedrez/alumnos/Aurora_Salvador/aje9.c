#include <ncurses.h>

#define peon 'p'
#define torre 'T'
#define caballo 'C'
#define alfil 'A'
#define dama 'D'
#define rey 'R'
#define blancas 'b'
#define negras 'n'
#define nada 'o'
#define humano 'h'
#define maquina 'm'

struct s_casilla
{
  char color_casilla;
  char tipo_pieza;
  char color_pieza;
};

struct s_estado
{
  int n_movi;
  char turno;
  char tipo_jug_blanco;
  char tipo_jug_negro;
};


void inicializar (struct s_casilla tablero[9][9], struct s_estado *estado);
void dibujar_tablero (struct s_casilla tablero[9][9], struct s_estado estado);
void colocar_piezas (struct s_casilla tablero[9][9]);
void inicializar_estado (struct s_estado *estado);
void inicializar_ncurses(void);
int hacer_movimiento (struct s_casilla tablero[9][9], struct s_estado *estado);
int elegir_casilla_origen (struct s_casilla tablero[9][9],int *num_o,int *num_d);
int elegir_casilla_destino (struct s_casilla tablero[9][9],int *num_o,int *num_d);
int convertir (char c);
void mover_pieza (struct s_casilla tablero[9][9],int num_ox,int num_oy,int num_dx,int num_dy);
int comprobar_movimiento(struct s_casilla tablero[9][9], struct s_estado *estado,int num_ox,int num_oy,int num_dx,int num_dy);
int comprobar_movim_peon(struct s_casilla tablero[9][9], struct s_estado *estado,int num_ox,int num_oy,int num_dx,int num_dy);
int comprobar_movim_caballo(struct s_casilla tablero[9][9], struct s_estado *estado,int num_ox,int num_oy,int num_dx,int num_dy);
int comprobar_movim_rey(struct s_casilla tablero[9][9], struct s_estado *estado,int num_ox,int num_oy,int num_dx,int num_dy);
int comprobar_movim_torre(struct s_casilla tablero[9][9], struct s_estado *estado,int num_ox,int num_oy,int num_dx,int num_dy);
int comprobar_movim_alfil(struct s_casilla tablero[9][9], struct s_estado *estado,int num_ox,int num_oy,int num_dx,int num_dy);
int comprobar_movim_dama(struct s_casilla tablero[9][9], struct s_estado *estado,int num_ox,int num_oy,int num_dx,int num_dy);
int menu (struct s_casilla tablero[9][9], struct s_estado *estado);
void guardar_partida (struct s_casilla tablero[9][9], struct s_estado *estado);
void cargar_partida (struct s_casilla tablero[9][9], struct s_estado *estado);

int main (void)
{
        int result, opc,cmpr;
	struct s_casilla tablero [9][9];
	struct s_estado estado;

	inicializar_ncurses();

	inicializar (tablero,&estado);
	attron(COLOR_PAIR(7));
	move(2, 60);
	printw (" Turno de las BLANCAS");//para q aparezca al empezar

	do {
	  dibujar_tablero (tablero, estado);
	  result = hacer_movimiento(tablero, &estado);
	  if (result == 1)
			opc = menu(tablero, &estado);
	  }
	while(opc != 5);
	endwin();//finalizar ncurses
	return 0;
}
void inicializar_ncurses()
{
		  initscr ();//iniciar ncurses
	start_color ();//activar colores
	init_pair (1, COLOR_YELLOW, COLOR_WHITE);//crea color piez-amarill fondo-blanc
	init_pair (2, COLOR_RED, COLOR_BLACK);//crea color piez-roja fondo-negr
	init_pair (3, COLOR_RED, COLOR_WHITE);// crea color pieza-roja fondo-blanco
	init_pair (4, COLOR_YELLOW, COLOR_BLACK);// crea color pieza-amarill fondo-negro
	init_pair (5, COLOR_WHITE, COLOR_BLUE);// crea color blanco fondo-azul
	init_pair (6, COLOR_MAGENTA, COLOR_BLUE);// crea color magenta de letras fondo-azul
	init_pair (7, COLOR_GREEN, COLOR_BLUE);//para los mensajes
	init_pair (8, COLOR_BLACK, COLOR_MAGENTA);//para el menu
	init_pair (9, COLOR_YELLOW, COLOR_MAGENTA);// letra amarilla fondo-magenta,tb para el menu
	bkgd(COLOR_PAIR(5));// tipo de color fondo de pantalla
	attron (A_BOLD);//brillante a partir de aqui todo lo q se haga
}


void inicializar(struct s_casilla tablero [9][9],struct s_estado *estado)
{
	colocar_piezas (tablero);
	inicializar_estado(estado);
}

void colocar_piezas(struct s_casilla tablero[9][9])
{
  int x, y;
  for(x=1;x<=8;x++)
	  for(y=1;y<=8;y++)
			tablero[x][y].color_casilla=negras; //todo el tablero negro
  for(x=1; x<=8; x=x+2)
	  for(y=1;y<=8;y=y+2)
			tablero[x][y].color_casilla= blancas;//blanco filas y columnas impares
  for (x=2;x<=8; x=x+2)
	  for (y=2;y<=8;y=y+2)
			tablero[x][y].color_casilla=blancas;//blanco filas y columnas pares

  for(x=1;x<=8;x++)// colocar piezas
	  for(y=1;y<=8;y++)
			 tablero[x][y].tipo_pieza= nada;
  tablero[1][1].tipo_pieza= torre;//negras
  tablero[2][1].tipo_pieza= caballo;
  tablero[3][1].tipo_pieza= alfil;
  tablero[4][1].tipo_pieza= dama;
  tablero[5][1].tipo_pieza= rey;
  tablero[6][1].tipo_pieza= alfil;
  tablero[7][1].tipo_pieza= caballo;
  tablero[8][1].tipo_pieza= torre;

  for(x=1;x<=8;x++) {
		  tablero[x][2].tipo_pieza= peon;
		  tablero[x][7].tipo_pieza= peon;
  }
  tablero[1][8].tipo_pieza= torre;//blancas
  tablero[2][8].tipo_pieza= caballo;
  tablero[3][8].tipo_pieza= alfil;
  tablero[4][8].tipo_pieza= dama;
  tablero[5][8].tipo_pieza= rey;
  tablero[6][8].tipo_pieza= alfil;
  tablero[7][8].tipo_pieza= caballo;
  tablero[8][8].tipo_pieza= torre;

  for(x=1;x<=8;x++) //colocar color piezas
	{
		tablero[x][1].color_pieza= negras;
		tablero[x][2].color_pieza= negras;
		tablero[x][7].color_pieza= blancas;
		tablero[x][8].color_pieza= blancas;

	}
}

void inicializar_estado(struct s_estado *estado)
 {
	 estado -> n_movi = 0;
	 estado -> tipo_jug_blanco = humano;//en pricipio jugaran dos humanos
	 estado -> tipo_jug_negro = humano;
	 estado -> turno = blancas;
 }

void dibujar_tablero(struct s_casilla tablero[9][9], struct s_estado estado)
{
  int px,py,x,y,i;

  for(x=1;x<=8;x++)
	  for(y=1;y<=8;y++)
		 {
			if (tablero[x][y].color_casilla== blancas) {
					if (tablero[x][y].color_pieza == blancas)
						attron (COLOR_PAIR(1));	// Fondo blanco , pieza blanca
					else
						 attron (COLOR_PAIR(3));	// Fondo blanco, pieza negra
			}

			if (tablero[x][y].color_casilla== negras ){
					if (tablero[x][y].color_pieza == negras)
						  attron (COLOR_PAIR(2));
					else
						  attron (COLOR_PAIR(4));
			}

			px = ((x-1)*5)+2;
			py = ((y-1)*3)+2;
			for(i=0;i<=2;i++){
				move(py+i,px);
				printw("     ");
			}
			if (tablero[x][y].tipo_pieza != nada) {
					px = ((x-1)*5)+4;
					py = ((y-1)*3)+3;
					move(py, px);
					printw ("%c",tablero [x][y].tipo_pieza);
			}
		}
	refresh();
}
int hacer_movimiento (struct s_casilla tablero[9][9], struct s_estado *estado)
{
  char result;
  int num_ox, num_oy, cmpr;
  num_ox = 1;
  num_oy = 1;
  int num_dx, num_dy;
  num_dx = 1;
  num_dy = 1;

  attron(COLOR_PAIR(6));
  move(2, 50);
  printw (" JUGEMOS:");
  move(4, 50);
  printw ("Seleccione origen:  ");
  move(6, 50);
  printw (" . Columna (A-H):  ");
  move(7, 50);
  printw (" . Fila (1-8):  ");
  move(9, 50);
  printw ("Seleccione destino:  ");
  move(11, 50);
  printw (" . Columna (A-H):  ");
  move(12, 50);
  printw (" . Fila (1-8):  ");
  attron(COLOR_PAIR(7));
  move(1, 4);
  printw ("A    B    C    D    E    F    G    H  ");
  move(3, 43); printw ("1");
  move(6, 43); printw ("2");
  move(9, 43); printw ("3");
  move(12, 43); printw ("4");
  move(15, 43); printw ("5");
  move(18, 43); printw ("6");
  move(21, 43); printw ("7");
  move(24, 43); printw ("8");
  result = elegir_casilla_origen(tablero,&num_ox, &num_oy);
  result = elegir_casilla_destino(tablero, &num_dx, &num_dy);
 //move(20,45);
 //printw("Haciendo movimiento: (%i,%i) --> (%i,%i)", num_ox, num_oy, num_dx, num_dy);
 if (result == 0)
 {
	 refresh();
	 getchar();
	 cmpr= comprobar_movimiento(tablero,estado,num_ox, num_oy, num_dx, num_dy);
	 if (cmpr==1)
	 {
		mover_pieza (tablero, num_ox, num_oy, num_dx, num_dy);//para luego estado ya es un puntero no hace falta el &
		if (estado->turno == blancas)
			{
					estado->turno = negras;
			 attron(COLOR_PAIR(7));
			 move(2, 60);
			 printw (" Turno de las NEGRAS  ");

				  }
		 else
			{
					estado->turno = blancas;
			 attron(COLOR_PAIR(7));
			 move(2, 60);
			 printw (" Turno de las BLANCAS");
				  }
		 }
	  else {
		  cmpr=0;
		  attron(COLOR_PAIR(7));
		  move(14 ,50);
		  printw ("Movimiento no válido, pulse una tecla para continuar");
		  getch();
		  move(14,50);
		  printw("                                                         "); // Borra mensaje anterior
	 }
  } // if (result == 0)

	return result;
 }

 int elegir_casilla_origen(struct s_casilla tablero[9][9], int *num_ox, int *num_oy)
 {
  char car, result;
  attron(COLOR_PAIR(7));
		do
	{
			move(6, 68);
	 car = getch();//leemos solo un caracter y no tenemos q estar dando al enter pq getstr nos obliga
	 *num_ox = convertir(car);
	 }
		while((*num_ox<1)||(*num_ox>8));

		do
	{
	 move(7, 65);
	 car = getch();
	 *num_oy = (car-48);//el 48 es el valor del cero en codigo ascii,como nos devuelve el valor del num en ascii,por eso le restamosel del cero y tenemos el del num en realidad
	}
	  while ((*num_oy<1)||(*num_oy>8));
	  do
		  {
			 car = getch();//leemos solo un caracter y no tenemos q estar dando al enter pq getstr nos obli
		  }
	  while ((car!='m')&&(car!='n')&&(car!='M')&&(car!='N'));
	  if ((car=='m')||(car=='n')||(car=='M')||(car=='N')){
			 result = 1;
			 return result;
		  }

 }

 int elegir_casilla_destino(struct s_casilla tablero[9][9],int *num_dx,int *num_dy)
 {
  char car, car1, result = 0;
  attron(COLOR_PAIR(7));
  do
	{
	  move(11, 68);
	  car = getch();
	  *num_dx = convertir(car);
	}
  while ((*num_dx<1)||(*num_dx>8));
  do
	{
	  move(12, 65);
	  car = getch();
	  *num_dy = (car-48);
	}
  while ((*num_dy<1)||(*num_dy>8));
	do
		  {
			 car1 = getch();//leemos solo un caracter y no tenemos q estar dando al enter pq getstr nos obli
		  }
	  while ((car1!='m')&&(car1!='n')&&(car1!='M')&&(car1!='N'));
	  if ((car1=='m')||(car1=='n')||(car1=='M')||(car1=='N'))
	  {
			 result = 1;
	  }

	return result;
 }

 int convertir(char c)
 {
		  int num;
	if ((c == 'A' )||(c == 'a'))
			num = 1;
	if (( c == 'B')||(c == 'b'))
			num = 2;
	if ((c == 'C' )||(c == 'c'))
			num = 3;
	if ((c == 'D' )||(c == 'd'))
			num = 4;
	if ((c == 'E' )||(c == 'e'))
			num = 5;
	if ((c == 'F' )||(c == 'f'))
			num = 6;
	if ((c == 'G' )||(c == 'g'))
			num = 7;
	if ((c == 'H' )||(c == 'h'))
			num = 8;
	return num;
 }
 void mover_pieza (struct s_casilla tablero[9][9],int num_ox,int num_oy,int num_dx,int num_dy)
 {
	tablero[num_dx][num_dy].tipo_pieza = tablero[num_ox][num_oy].tipo_pieza;
	tablero[num_dx][num_dy].color_pieza = tablero[num_ox][num_oy].color_pieza;
		  tablero[num_ox][num_oy].tipo_pieza = nada;
	tablero[num_ox][num_oy].color_pieza = nada;
 }
 int comprobar_movimiento(struct s_casilla tablero[9][9], struct s_estado *estado,int num_ox,int num_oy,int num_dx,int num_dy)
 {

	int cmpr=0;
	switch (tablero[num_ox][num_oy].tipo_pieza)
	{

		case 'p':cmpr = comprobar_movim_peon(tablero, estado,num_ox, num_oy, num_dx, num_dy);break;
		case 'C':cmpr = comprobar_movim_caballo(tablero, estado,num_ox, num_oy, num_dx, num_dy);break;
		case 'R':cmpr = comprobar_movim_rey(tablero, estado,num_ox, num_oy, num_dx, num_dy);break;
		case 'T':cmpr = comprobar_movim_torre(tablero, estado,num_ox, num_oy, num_dx, num_dy);break;
		case 'A':cmpr = comprobar_movim_alfil(tablero, estado,num_ox, num_oy, num_dx, num_dy);break;
		case 'D':cmpr = comprobar_movim_dama(tablero, estado,num_ox, num_oy, num_dx, num_dy);break;

	 }
	return cmpr;
 }

 int comprobar_movim_peon(struct s_casilla tablero[9][9], struct s_estado *estado,int num_ox,int num_oy,int num_dx,int num_dy)
 {
	int cmpr;
	cmpr=0;
	if (estado->turno == blancas)
	 {

		 if ((num_dx == num_ox)&&(num_dy == num_oy-1)&&(tablero[num_dx][num_dy].tipo_pieza == nada))
						cmpr = 1;
				if ((num_dx == num_ox)&&(num_dy == num_oy-2)&&(num_oy == 7)&&(tablero[num_dx][num_dy].tipo_pieza == nada)&&(tablero[num_ox][num_oy-1].tipo_pieza == nada))
						cmpr = 1;
				if ((num_dx == num_ox+1)&&(num_dy == num_oy-1)&&(tablero[num_dx][num_dy].color_pieza == negras)&&(tablero[num_dx][num_dy].tipo_pieza != nada))
						cmpr = 1;
				if ((num_dx == num_ox-1)&&(num_dy == num_oy-1)&&(tablero[num_dx][num_dy].color_pieza == negras)&&(tablero[num_ox][num_oy].tipo_pieza != nada))
						cmpr = 1;

	  }
	 if (estado->turno == negras)
	  {

		 if ((num_dx == num_ox)&&(num_dy == num_oy+1)&&(tablero[num_dx][num_dy].tipo_pieza == nada))
						cmpr = 1;
				if ((num_dx == num_ox)&&(num_dy == num_oy+2)&&(num_oy = 2)&&(tablero[num_dx][num_dy].tipo_pieza == nada)&&(tablero[num_ox][num_oy+1].tipo_pieza == nada))
						cmpr = 1;
				if ((num_dx == num_ox-1)&&(num_dy == num_oy+1)&&(tablero[num_dx][num_dy].color_pieza == blancas)&&(tablero[num_dx][num_dy].tipo_pieza != nada))
						cmpr = 1;
				if ((num_dx == num_ox+1)&&(num_dy == num_oy+1)&&(tablero[num_dx][num_dy].color_pieza == blancas)&&(tablero[num_dx][num_dy].tipo_pieza != nada))
						cmpr = 1;


	  }

  return cmpr;
 }
int comprobar_movim_caballo(struct s_casilla tablero[9][9], struct s_estado *estado,int num_ox,int num_oy,int num_dx,int num_dy)
{
	 int cmpr;
	 if ((estado->turno == blancas)||(estado->turno == negras))
	 {
		 if ((num_dx == num_ox+1)&&(num_dy == num_oy-2)&&(tablero[num_dx][num_dy].color_pieza != estado->turno))
						cmpr = 1;
		 if ((num_dx == num_ox+1)&&(num_dy == num_oy+2)&&(tablero[num_dx][num_dy].color_pieza != estado->turno))
						cmpr = 1;
		 if ((num_dx == num_ox-1)&&(num_dy == num_oy-2)&&(tablero[num_dx][num_dy].color_pieza != estado->turno))
						cmpr = 1;
		 if ((num_dx == num_ox-1)&&(num_dy == num_oy+2)&&(tablero[num_dx][num_dy].color_pieza != estado->turno))
						cmpr = 1;
		 if ((num_dx == num_ox-2)&&(num_dy == num_oy-1)&&(tablero[num_dx][num_dy].color_pieza != estado->turno))
						cmpr = 1;
		 if ((num_dx == num_ox-2)&&(num_dy == num_oy+1)&&(tablero[num_dx][num_dy].color_pieza != estado->turno))
						cmpr = 1;
		 if ((num_dx == num_ox+2)&&(num_dy == num_oy+1)&&(tablero[num_dx][num_dy].color_pieza != estado->turno))
						cmpr = 1;
		 if ((num_dx == num_ox+2)&&(num_dy == num_oy-1)&&(tablero[num_dx][num_dy].color_pieza != estado->turno))
						cmpr = 1;

		}
		return cmpr;
 }
int comprobar_movim_rey(struct s_casilla tablero[9][9], struct s_estado *estado,int num_ox,int num_oy,int num_dx,int num_dy)
{
	 int cmpr;
	 if ((estado->turno == blancas)||(estado->turno == negras))
	 {
		 if ((num_dx == num_ox+1)&&(num_dy == num_oy-1)&&(tablero[num_dx][num_dy].color_pieza != estado->turno))
						cmpr = 1;
		 if ((num_dx == num_ox+1)&&(num_dy == num_oy+1)&&(tablero[num_dx][num_dy].color_pieza != estado->turno))
						cmpr = 1;
		 if ((num_dx == num_ox-1)&&(num_dy == num_oy-1)&&(tablero[num_dx][num_dy].color_pieza != estado->turno))
						cmpr = 1;
		 if ((num_dx == num_ox-1)&&(num_dy == num_oy+1)&&(tablero[num_dx][num_dy].color_pieza != estado->turno))
						cmpr = 1;
		 if ((num_dx == num_ox)&&(num_dy == num_oy-1)&&(tablero[num_dx][num_dy].color_pieza != estado->turno))
						cmpr = 1;
		 if ((num_dx == num_ox)&&(num_dy == num_oy+1)&&(tablero[num_dx][num_dy].color_pieza != estado->turno))
						cmpr = 1;
		 if ((num_dx == num_ox-1)&&(num_dy == num_oy)&&(tablero[num_dx][num_dy].color_pieza != estado->turno))
						cmpr = 1;
		 if ((num_dx == num_ox+1)&&(num_dy == num_oy)&&(tablero[num_dx][num_dy].color_pieza != estado->turno))
						cmpr = 1;

		}
		return cmpr;
 }
 int comprobar_movim_torre(struct s_casilla tablero[9][9], struct s_estado *estado,int num_ox,int num_oy,int num_dx,int num_dy)
 {
	 int i, cmpr;
	 cmpr = 1;
	 if ((num_dy > num_oy)&&(num_dx == num_ox))//movimiento abajo
	 {
		for(i=1;i<(num_dy - num_oy);i++)//saber cuantos movimiento
		{
		  if (tablero[num_ox][num_oy + i].tipo_pieza != nada)
		  cmpr = 0;
		}
	 }

	 if ((num_dy < num_oy)&&(num_dx == num_ox))//movimiento arriba
	 {
		for(i=1;i<(num_oy - num_dy);i++)//saber cuantos movimientos
		{
			if (tablero[num_ox][num_oy - i].tipo_pieza != nada)
	  cmpr = 0;
		}
	 }

	 if ((num_dx > num_ox)&&(num_dy == num_oy))//movimiento derecha
	 {
		 for(i=1;i<(num_dx - num_ox);i++)//saber cuantos movimientos
		 {
			 if (tablero[num_ox + i][num_oy].tipo_pieza != nada)
			cmpr = 0;
		 }
	 }

	 if ((num_dx < num_ox)&&(num_dy == num_oy))//movimiento izquierda
	 {
		for(i=1;i<(num_ox - num_dx);i++)//saber cuantos movimientos
		{
		  if (tablero[num_ox - i][num_oy].tipo_pieza != nada)
		 cmpr = 0;
		}
	 }

	  if ((tablero[num_dx][num_dy].tipo_pieza != nada)&&(tablero[num_dx][num_dy].color_pieza == estado->turno))
			 cmpr = 0;


	 if ((num_dx == num_ox)&&(num_dy == num_oy))
			cmpr = 0;
	return cmpr;
 }

 int comprobar_movim_alfil(struct s_casilla tablero[9][9], struct s_estado *estado,int num_ox,int num_oy,int num_dx,int num_dy)
  {
	 int i, cmpr;
	 cmpr = 1;
	 if ((num_dy < num_oy)&&(num_dx > num_ox))//movimiento derecho arriba
	 {
	  for(i=1;i<(num_oy - num_dy);i++)//saber cuantos movimiento
	  {
		if (tablero[num_ox + i][num_oy - i].tipo_pieza != nada)
			cmpr = 0;
	  }
	 }

	if ((num_dy > num_oy)&&(num_dx < num_ox))//movimiento izquierdo abajo
	{
	  for(i=1;i<(num_dy - num_oy);i++)//saber cuantos movimientos
	  {
		 if (tablero[num_ox - i][num_oy + i].tipo_pieza != nada)
			 cmpr = 0;
	  }
	}

	 if ((num_dy > num_oy)&&(num_dx > num_ox))//movimiento derecho abajo
	 {
		 for(i=1;i<(num_dx - num_ox);i++)//saber cuantos movimientos
		  {
		if (tablero[num_ox + i][num_oy + i].tipo_pieza != nada)
			 cmpr = 0;
	}
	 }

	 if ((num_dy < num_oy)&&(num_dx < num_ox))//movimiento izquierdo arriba
	 {
		 for(i=1;i<(num_ox - num_dx);i++)//saber cuantos movimientos
		 {
			if (tablero[num_ox - i][num_oy - i].tipo_pieza != nada)
		 cmpr = 0;
		 }
	 }

	if ((tablero[num_dx][num_dy].tipo_pieza != nada)&&(tablero[num_dx][num_dy].color_pieza == estado->turno))
		 cmpr = 0;

	if ((num_dx == num_ox)&&(num_dy == num_oy))
		  cmpr = 0;
  return cmpr;
 }
 int comprobar_movim_dama(struct s_casilla tablero[9][9], struct s_estado *estado,int num_ox,int num_oy,int num_dx,int num_dy)
 {
  int cmpr, cmpr1, cmpr2;

  cmpr1 = comprobar_movim_torre(tablero, estado,num_ox, num_oy, num_dx, num_dy);
  cmpr2 = comprobar_movim_alfil(tablero, estado,num_ox, num_oy, num_dx, num_dy);
  if ((cmpr1 == 1)&&(cmpr2 == 1))
		 cmpr=1;

  return cmpr;
 }


int menu (struct s_casilla tablero[9][9], struct s_estado *estado)
{
	int opc, i;
	char car;
	attron(COLOR_PAIR(8));
	for (i=10; i<=19; i++) {
		 move(i,40); printw("                                                ");//hace un cuadrado
	}
	move (11,42);
	printw ("QUE DESEA HACER?, ");
	move (12,42);
	printw ("PULSE EL NUMERO DE LA OPCION");
	move (13,42);
	printw ("1 : CONTINUAR PARTIDA");
	move (14,42);
	printw ("2 : GUARDAR PARTIDA");
	move (15,42);
	printw ("3 : CARGAR PARTIDA GUARDADA");
	move (16,42);
	printw ("4 : COMENZAR DE NUEVO LA PARTIDA");
	move (17,42);
	printw ("5 : SALIR DEL PROGRAMA");
	do
	{
			 move (18,68);
			 car = getch();
			 opc = (car-48);

	}
	while ((opc<1)||(opc>5));
	attron(COLOR_PAIR(8));
	move (18,42);
	printw ("SU OPCION ELEGIDA ES LA: %i",opc);
	switch (opc)
	{
	  case 2: guardar_partida(tablero, estado); break;
	  case 3: cargar_partida(tablero, estado); break;
	  case 4: inicializar(tablero, estado); break;
	}
  clear();
  return opc;
}
void guardar_partida (struct s_casilla tablero[9][9], struct s_estado *estado)
{

}
void cargar_partida (struct s_casilla tablero[9][9], struct s_estado *estado)
{

}
