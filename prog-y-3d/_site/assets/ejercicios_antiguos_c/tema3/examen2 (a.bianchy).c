#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
	int m[10][10];
	int i,j;
	int mayor, menor, mayor_x, mayor_y, menor_x, menor_y;
	int cont = 0, pass = 0;

	randomize();
	for (i=0; i<10; i++)
	  for (j=0; j<10; j++)
		  m[i][j] = random(100)+1;

	// Busqueda secuencial convencional
	/*
	mayor = 0; menor = 100;
	for (i=0; i<10; i++)
	  for (j=0; j<10; j++)
	  {
		  if (m[i][j] > mayor) {
			  mayor_x = i;
			  mayor_y = j;
			  mayor = m[i][j];
		  }
		  if (m[i][j] < menor) {
			  menor_x = i;
			  menor_y = j;
			  menor = m[i][j];
		  }
	  }
	*/

	// Busqueda secuencial de Anthony Bianchi

	while (pass == 0)
	{
	  for (i=0; i<10; i++)
	  {
		 for (j=0; j<10; j++)
		 {
			if (m[cont][i] > m[i][j]) {
			  mayor_x = cont;
			  mayor_y = i;
			  mayor = m[cont][i];
			}
			if (m[cont][i] < m[i][j]) {
			  menor_x = cont;
			  menor_y = i;
			  menor = m[cont][i];
			}
		 } // for j
	  } // for i
	  if (cont == 9) pass = 1;
	  cont++;
	} // while

	printf("El maximo es %i y esta en la posicion (%i,%i)\n", mayor, mayor_x, mayor_y);
	printf("El minimo es %i y esta en la posicion (%i,%i)\n\n", menor, menor_x, menor_y);
	for (i=0; i<10; i++)
	{
	  for (j=0; j<10; j++)
	  {
		  printf("%4i", m[i][j]);
	  }
	  printf("\n");
	}

	return 0;
}
