#include <ncurses.h>
#include "ajedrez.h"

// NOTA: acuerdate de q mis coordenadas van al reves

// algoritmo principal

int main()
{
	int x,y, contrey,opcion;
	struct s_casilla tablero[9][9];
	struct s_estado estado;
	int t;

	iniciar_ncurses();   // inicializo los colores
	inicializar(tablero,&estado); // inicializo el tablero y el estado

	contrey=0; // defino un contador para q cada vez q se meta en el bucle mire los reyes q hay y si hay uno, se salga del programa. Es lo mas aproximado q hemos podido hacer.
	do {
		for(x=1;x<=8;x++)
			for(y=1;y<=8;y++)
				if(tablero[x][y].tipo_pieza==REY)
					contrey++; // para comprobar q hay dos, como ya hemos dicho.
		dibujar_tablero(tablero,estado); // dibujo el tablero
		t = mover_humano(tablero,estado); // Llamo a la funcion mover_humano
		if (t==1) {       // si me devuelve un 1, es q el movimiento no se puede hacer

			move(30,60);
			printw("Error_en_el_movimiento");
			refresh();
			getchar();
		}
		if(t==0) // si me devuelve un 0, el movimiento es correcto y cambiamos de turno.
		{	if (estado.turno == BLANCO)
				estado.turno = NEGRO;
			else
				estado.turno = BLANCO;
			printw("El turno es %c:",estado.turno);
		}
		move(31,60);
		printw("%c%",estado.turno);
		if(t==2) {  // si me devuelve un 2, es q ha introducido una m para irse al menu.
			opcion = menu();
			switch(opcion) {
				// la opcion 1 es regresar a la partida, q lo hace directamente
				case 2: inicializar(tablero,&estado); break; // comienza una nueva partida
				case 3: guardar_partida(tablero, estado); break;// guarda la partida en curso
				case 4: cargar_partida(tablero, &estado); break; // carga la partida q se diga
				// la opcion 5 es acabar el programa y la ponemos de condicion junto con el contrey para finalizar el bucle.
			}
		}

	}
	while ((contrey!=1) && (opcion!=5));

	endwin();
	return 0;
}

// inicializamos los colores q luego vamos a utilizar

void iniciar_ncurses(void)
{
	initscr();
	keypad(stdscr, 1);
	echo();
	start_color();
	init_pair(1,COLOR_YELLOW,COLOR_WHITE);
	init_pair(2,COLOR_YELLOW,COLOR_BLACK);
	init_pair(3,COLOR_BLACK,COLOR_BLACK);
	init_pair(4,COLOR_BLACK,COLOR_WHITE);
	init_pair(5,COLOR_MAGENTA,COLOR_BLUE);
	bkgd(COLOR_PAIR(5));
	attron(A_BOLD);
}

// esta funcion llama a otras dos: colocar las piezas e inicializar estado

void inicializar(struct s_casilla tablero[9][9],struct s_estado *estado)
{
	colocar_piezas(tablero); // es por variable aunq no lleva el & pq es un array
	inicializar_estado(estado); // puede no ponerse el & pq ya viene pasada por variable de inicializar()
}

//le da el color al tablero y establece donde van las figuras y el color de estas.

void colocar_piezas(struct s_casilla tablero[9][9])
{
	int x,y;

	for (x=1;x<=8;x=x+2)
		for(y=1;y<=8;y=y+2)
			tablero[x][y].color_casilla=BLANCO; //pone en blanco las filas y columnas impares
	for (x=2;x<=8;x=x+2)
		for(y=2;y<=8;y=y+2)
			tablero[x][y].color_casilla=BLANCO; //pone en blanco las filas y columnas pares
	for (x=1;x<=8;x=x+2)
		for(y=2;y<=8;y=y+2)
			tablero[x][y].color_casilla=NEGRO; //pone en negro las filas y columnas impares
	for (x=2;x<=8;x=x+2)
		for(y=1;y<=8;y=y+2)
			tablero[x][y].color_casilla=NEGRO; //pone en negro las filas y columnas pares

// ahora colocamos las piezas en su sitio, para luego poder dibujarlas..

	for (x=1; x<=8; x++)
	  for (y=1; y<=8; y++)
		  tablero[x][y].tipo_pieza = NINGUNA;

	tablero[1][1].tipo_pieza=TORRE;
	tablero[1][2].tipo_pieza=CABALLO;
	tablero[1][3].tipo_pieza=ALFIL;
	tablero[1][4].tipo_pieza=DAMA;
	tablero[1][5].tipo_pieza=REY;
	tablero[1][6].tipo_pieza=ALFIL;
	tablero[1][7].tipo_pieza=CABALLO;
	tablero[1][8].tipo_pieza=TORRE;
	for(x=1;x<=8;x++)
		tablero[2][x].tipo_pieza=PEON;

	tablero[8][1].tipo_pieza=TORRE;
	tablero[8][2].tipo_pieza=CABALLO;
	tablero[8][3].tipo_pieza=ALFIL;
	tablero[8][4].tipo_pieza=REY;
	tablero[8][5].tipo_pieza=DAMA;
	tablero[8][6].tipo_pieza=ALFIL;
	tablero[8][7].tipo_pieza=CABALLO;
	tablero[8][8].tipo_pieza=TORRE;
	for(x=1;x<=8;x++)
		tablero[7][x].tipo_pieza=PEON;

// Ahora colocamos el color de las piezas para luego poder dibujarlas...

	for(x=1;x<=8;x++){
		tablero[1][x].color_pieza=NEGRO;
		tablero[2][x].color_pieza=NEGRO;
		tablero[7][x].color_pieza=BLANCO;
		tablero[8][x].color_pieza=BLANCO;
	}
}

// inicializa el turno (blanco), y ponemos de momento a los dos jugadores humano..

void inicializar_estado(struct s_estado *estado)
{
	estado->n_movim=0;
	estado->tipo_blancas=HUMANO;
	estado->tipo_negras=HUMANO;
	estado->turno=BLANCO;
}
// Aqui dibujamos el tablero segun lo hemos descrito anterior y posteriormente

void dibujar_tablero(struct s_casilla tablero[9][9],struct s_estado estado)
{
	int x,y,i,px,py;

	clear();
	attron(COLOR_PAIR(2));
	move(0,0);
	printw("__A____B____C____D____E____F____G____H");
	for(x=1;x<=8;x++)
	{
		 move((x*3)-1, 41); printw("_%i", x);
	}
	for(x=1;x<=8;x++)
	{
		for(y=1;y<=8;y++)
		{

			if(tablero[x][y].color_casilla==BLANCO)
			{
					if (tablero[x][y].color_pieza == BLANCO)
					attron(COLOR_PAIR(1));
					else
						attron(COLOR_PAIR(4));
			}
			if(tablero[x][y].color_casilla==NEGRO)
			{
				if (tablero[x][y].color_pieza == BLANCO)
					attron(COLOR_PAIR(2));
				else
					attron(COLOR_PAIR(3));
			}
			px = ((x-1)*3)+1; // para hacer el tablero mas grande..
			py = ((y-1)*5)+1;
			move(px,py);printw("_____"); // ya sabemos q mis espacios no funcionan...
			px=px+1;
			move(px,py);printw("_____");
			px=px+1;
			move(px,py);printw("_____");

			px=((x-1)*3)+2;  // para colocar la piezas en el centro de cada casilla..
			py=((y-1)*5)+3;
			move(px,py);
			if(tablero[x][y].tipo_pieza==NINGUNA)
				printw("_");
			else
				printw("%c", tablero[x][y].tipo_pieza);
		}
	}
	refresh();
}

// Aqui pintamos el menu para volver a la partida, empezar una nueva, cargar otra partida, guardarla la q esta en uso y cerrar el programa

int menu(void)
{
	char c;
	int opcion;

	clear();
	do
	{
		move(15,44);
		printw("MENU_DE_OPCIONES\n\n");
		move(17,44);
		printw("1.-CONTINUAR_PARTIDA\n");
		move(18,44);
		printw("2.-EMPEZAR_OTRA_PARTIDA\n");
		move(19,44);
		printw("3.-GUARDAR_PARTIDA\n");
		move(20,44);
		printw("4.-CARGAR_PARTIDA\n");
		move(21,44);
		printw("5.-SALIR DEL PROGRAMA\n");
		move(23,44);
		printw("Introduzca_una_opcion...\n");
		c=getch();
		opcion=c - 48;
	}
	while((opcion<=0)||(opcion>=6));
	clear();
	return opcion;
}

// este es el procedimiento de guardar partida

void guardar_partida(struct s_casilla tablero[9][9], struct s_estado estado)
{
	FILE *f;
	char nombre[30];

	move(18,30);
	printw("INTRODUZCA_EL_NOMBRE_DEL_ARCHIVO_DONDE_DESEA_GUARDAR_LA_PARTIDA:_");
	getstr(nombre); // pedimos un nombre de archivo donde quiere guardarla

	f=fopen(nombre,"wb"); // abre ese archivo en modo escritura
	if(f==NULL)
	{
		printw("ERROR_AL_ABRIR_EL_ARCHIVO");
		return;
	}
	else
	{
		fwrite(tablero,sizeof(struct s_casilla),81,f); // va escribiendo en el archivo los 81 registros (9x9)
		fwrite(&estado,sizeof(struct s_estado),1,f);   // escribe tb el estado para luego continuar asi
		fclose(f);
		move(20,30);
		printw("PARTIDA_GUARDADA");
		move(21,30);
		printw("Pulse_una_tecla_para_continuar...");
		getch();
	}

}
// este es el procedimiento para cargar una partida..

void cargar_partida(struct s_casilla tablero[9][9], struct s_estado *estado)
{
	FILE *f;
	int n;
	char nombre[30];

	move(18,30);
	printw("INTRODUZCA_EL_NOMBRE_DEL_ARCHIVO_PARA_CARGAR_LA_PARTIDA:_");
	getstr(nombre); // nos pide el nombre del archivo donde esta la partida guardada..

	f= fopen(nombre,"rb"); // lo abrimos en modo lectura
	if(f==NULL)
	{
		printw("ERROR_AL_ABRIR_EL_ARCHIVO");
		return;
	}
	else
	{
		while(!feof(f)) // mientras sea distinto del ultimo caracter..
		{
			fread(tablero,sizeof(struct s_casilla),81,f); //... va leyendo los 81 registros..
			fread(&estado,sizeof(struct s_estado),1,f); // .. y el estado
			move(20,30);
			printw("PARTIDA_CARGADA");
			move(21,30);
			printw("Pulse_una_tecla_para_continuar..");
			getch();
		}
	}
}
