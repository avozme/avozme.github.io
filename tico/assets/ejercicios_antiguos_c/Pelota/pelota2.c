#include <stdio.h>
#include <conio.h>

void retardo(void);

int main(void)
{
	int x, y;				// Posicion ACTUAL de la pelota
	int ax, ay;				// Posicion ANTERIOR de la pelota
	int inc_x, inc_y;		// Incrementos en horizontal (x) y vertical (y) para mover la pelota
	int cont;

	x = 1; y = 1;  		// Al principio, la posicion anterior y la actual coinciden
	ax = 1; ay = 1;
	inc_x = -1; inc_y = -1;
	cont = 0;

	while (cont < 500)					// La pelota realizara 500 movimientos
	{
		gotoxy(x,y);						// Dibuja la pelota en la posicion actual (x,y)
		printf("O");
		gotoxy(ax,ay);						// Borra la pelota de la posicion anterior (ax, ay)
		printf(" ");
		if ((x == 1) || (x == 80))		// Comprueba si se ha alcanzado algun limite horizontal
			inc_x = -inc_x;				// Si es asi, se cambia el sentido del movimiento horizontal
		if ((y == 1) || (y == 25))		// Se hace lo mismo en vertical
			inc_y = -inc_y;
		ax = x;								// Guarda la posicion actual de la pelota
		ay = y;								// (en la siguiente iteracion, esta sera la posicion anterior)
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
		for (j=1; j<=500; j++);
}
