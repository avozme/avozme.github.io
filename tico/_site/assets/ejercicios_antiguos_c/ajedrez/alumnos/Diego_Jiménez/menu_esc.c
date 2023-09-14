#include "tablero_en_curso2.h"
#include "tablero.h"
#include "tirada.h"


/*   PARA UTILIZARLO TENDRË QUE INCLUIR "NOMBRE" A CADA TABLERO CUANDO COMIENCE LA PARTIDA    */

int menu_esc(struct s_casilla tablero[9][9])
{

	char n,selec[4];
	int i,cont=1,x=1,xo=26;
	long int opcion;

	move(25,65);
	printw("QUE DESEA REALIZAR?");
	move(27,65);
	printw("1.Nueva Partida  ");
	move(28,65);
	printw("2.Guardar Partida");
	move(29,65);
	printw("3.Cargar Partida ");
	move(30,65);
	printw("4.SALIR");
	n=getch();
	opcion=atoi(n);

	for(i=1;i<=4;i++)
		{
		selec[i]=i;
		}
	selec[1]='>';

		do
		{
		n=getch();
		if (n==KEY_UP)
			{
			move(xo-x,63);
			printw(">");
			}
		if (n==KEY_DOWN)
			{
			move((xo-x)+1,63);
			printw(">");
			}
		move(26+cont,63);
		printw("%c",selec[cont]);
		cont++;
		}
		while(n!=' ');			//como puede saber cuando se ha puï¿½ado enter?



	switch(opcion)
		{
		case 1:
			{
			printw("Presione CTRL+C, y rearranque el juego");
			}
		case 2:
			{
			guardar(tablero);
			}
		case 3:
			{
			cargar(tablero);
			}
		case 4:
			{
			exit(-1);
			}
		}
	return 0;
}

int guardar(struct s_casilla tablero[9][9])
{
FILE *fich;


	printw("Introduzca el nombre de la partida a guardar");
	gets(nombre);
	printw("Guardando Partida..........");
	fich=fopen ("Guardadas.dat","a+b");
	if(fich==NULL)
	{
		printf("Error al abrir el archivo para escritura");
		exit(-1);
	}
	fprintf("%s",nombre);
	fwrite(&tablero,sizeof(struct s_casilla),1,fich);
	printw("Partida guardada-..........");
fclose(fich);
}

int cargar(struct s_casilla tablero [9][9])
{
	char n;
	int opcion;
	FILE *fich;

	fich=fopen("Guardadas.dat","r+b");
	if(fich==NULL)
	{
		printw("Error al abrir el archivo para escritura");
		exit(-1);
	}

	printw("¿Que partida desea cargar?");
	while (!feof(fich))
	{
	fscanf("%s",&nombre);
	printw("%s",nombre);
	fseek(sizeof(struct s_casilla),SET_CUR+1);
	}
	n=getchar();
	opcion=atoi(n);
	do
	{
	fseek(sizeof(struct s_casilla)*opcion,SET_CUR+1);
	fread(&tablero,sizeof(struct s_casilla),1,fich);
	}
	while(!feof(fich));

	printw("  PARTIDA CARGADA   ");

	return 0;
}



