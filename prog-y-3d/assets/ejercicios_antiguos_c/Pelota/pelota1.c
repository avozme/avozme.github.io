#include <stdio.h>
#include <conio.h>

void retardo(void);

int main(void)
{
	int x, y;				// Posicion de la pelota
	int inc_x, inc_y;		// Incrementos en horizontal (x) y vertical (y) para mover la pelota
	int cont;

	x = 1; y = 1;
	inc_x = -1; inc_y = -1;
	cont = 0;

	while (cont < 500)					// La pelota realizara 500 movimientos 
	{
		gotoxy(x,y);						// Dibuja la pelota en la posicion (x,y)
		printf("O");
		if ((x == 1) || (x == 80))		// Comprueba si se ha alcanzado algun limite horizontal
			inc_x = -inc_x;				// Si es asi, se cambia el sentido del movimiento horizontal
		if ((y == 1) || (y == 25))		// Se hace lo mismo en vertical
			inc_y = -inc_y;
		x = x + inc_x;						// Actualiza la posicion de la pelota
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
		for (j=1; j<=100; j++);
}
