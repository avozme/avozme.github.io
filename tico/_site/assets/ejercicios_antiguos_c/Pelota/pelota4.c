#include <stdio.h>
#include <conio.h>

void retardo(void);

int main(void)
{
	int x, y;				// Posicion ACTUAL de la pelota
	int ax[5], ay[5];		// Posiciones ANTERIORES de la pelota
	int inc_x, inc_y;		// Incrementos en horizontal (x) y vertical (y) para mover la pelota
	int cont;

	x = 1; y = 1;  		// Al principio, las posiciones anteriores y la actual coinciden
	ax[0] = 1; ay[0] = 1;
	ax[1] = 1; ay[1] = 1;
	ax[2] = 1; ay[2] = 1;
	ax[3] = 1; ay[3] = 1;
	ax[4] = 1; ay[4] = 1;
	inc_x = -1; inc_y = -1;
	cont = 0;

	while (cont < 500)					// La pelota realizara 500 movimientos
	{
		gotoxy(x,y);						// Dibuja la pelota en la posicion actual (x,y)
		printf("%c",219);
		gotoxy(ax[0], ay[0]);			// Dibuja la estela en las posiciones anteriores
		printf("%c",178);
		gotoxy(ax[1], ay[1]);
		printf("%c",177);
		gotoxy(ax[2], ay[2]);
		printf("%c",176);
		gotoxy(ax[3], ay[3]);
		printf("%c",176);
		gotoxy(ax[4], ay[4]); 			// Borra la estela de la ultima posicion anterior
		printf(" ");

		if ((x == 1) || (x == 80))		// Comprueba si se ha alcanzado algun limite horizontal
			inc_x = -inc_x;				// Si es asi, se cambia el sentido del movimiento horizontal
		if ((y == 1) || (y == 25))		// Se hace lo mismo en vertical
			inc_y = -inc_y;

		ax[4] = ax[3]; ay[4] = ay[3];	// Actualiza posiciones anteriores antes de cambiar la actual
		ax[3] = ax[2]; ay[3] = ay[2];
		ax[2] = ax[1]; ay[2] = ay[1];
		ax[1] = ax[0]; ay[1] = ay[0];
		ax[0] = x;     ay[0] = y;
		x = x + inc_x;						// Actualiza la posicion actual de la pelota
		y = y + inc_y;

		retardo();
		cont++;
	}
	return 0;
}


void retardo(void)
/* Introduce un pequeño retardo en el movimiento de la pelota para que no
	vaya muy rapida. El retardo se realiza con dos bucles vacios anidados */
{
	int i,j;
	for (i=1; i<=10000; i++)
		for (j=1; j<=10000; j++);
}
