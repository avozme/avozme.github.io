#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void introducir_datos(int m[10][10]);		// Prototipo

int main(void)
{
	int m[10][10];
	int i,j;
	int mayor, menor, mayor_x, mayor_y, menor_x, menor_y;

	randomize();				// Inicializa el generador de numeros aleatorios
	introducir_datos(m);		// Introduce numeros al azar en la matriz

	// Busqueda secuencial de los elementos maximo y minimo de la matriz
	mayor = 0;		// Por ahora, el maximo es 0 (aun no hemos empezado a buscar)
	menor = 101;	// Y el minimo es 101 (cualquier numero de la matriz sera menor)
	for (i=0; i<10; i++)             // Recorrido secuencial por la matriz
	  for (j=0; j<10; j++)				// (dos bucles anidados)
	  {
		  if (m[i][j] > mayor) {		// Hemos encontrado uno mayor que el maximo
			  mayor = m[i][j];			// Este elemento sera el maximo a partir de ahora
			  mayor_x = i;					// Guardamos tambien la posicion que ocupa en m
			  mayor_y = j;
		  }
		  if (m[i][j] < menor) {		// Hemos encontrado un elemento menor que el minimo
			  menor_x = i;					// A partir de ahora, el minimo sera este elemento
			  menor_y = j;					// Guardamos tambien su posicion
			  menor = m[i][j];
		  }
	  }

	// Mostrar resultados
	printf("El maximo es %i y esta en la posicion (%i,%i)\n", mayor, mayor_x, mayor_y);
	printf("El minimo es %i y esta en la posicion (%i,%i)\n\n", menor, menor_x, menor_y);

	return 0;
}

// Esta funcion introduce numeros al azar entre 1 y 100 en la matriz
void introducir_datos(int m[10][10])
{
	int i,j;
	for (i=0; i<10; i++)
	  for (j=0; j<10; j++)
		  m[i][j] = random(100)+1;
}

