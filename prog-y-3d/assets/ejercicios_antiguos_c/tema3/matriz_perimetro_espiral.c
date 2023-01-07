#include <stdio.h>
#include <stdlib.h>

/* Tamaño de la matriz cuadrada */
#define N 4

/* Prototipos de funciones */
void mostrar_matriz(int m[N][N]);
void mostrar_perimetro(int m[N][N]);
void mostrar_espiral(int m[N][N]);

int main(void)
{
	int opc, f, c;
	int m[N][N];

	/* Rellenamos la matriz con números al azar */
	for (f = 0; f < N; f++)
		for (c = 0; c < N; c++)
			m[c][f] = rand() % 10;

	do
	{
		printf("1. Mostrar matriz\n");
		printf("2. Perímetro\n");
		printf("3. Espiral\n");
		printf("4. Salir\n");
	
		printf("Introduzca opción (1-4): ");
		scanf("%i", &opc);
	
		switch(opc) 
		{
			case 1: mostrar_matriz(m); break;
			case 2: mostrar_perimetro(m); break;
			case 3: mostrar_espiral(m); break;
		}
	}
	while (opc != 4);

	return 0;
}


void mostrar_matriz(int m[N][N])
{
	int f, c;

	for (f = 0; f < N; f++)
	{
		for (c = 0; c < N; c++)
		{
			printf("%i ", m[c][f]);
		}
		printf("\n");
	}

}



void mostrar_perimetro(int m[N][N])
{
	int f, c;

	printf("El perímetro es:\n");

	for (c = 0; c < N; c++)
		printf("%i ", m[c][0]);
	for (f = 1; f < N; f++)
		printf("%i ", m[N-1][f]);
	for (c = N-2; c >= 0; c--)
		printf("%i ", m[c][N-1]);
	for (f = N-2; f >= 1; f--)
		printf("%i ", m[0][f]);

	printf("\n");
}


void mostrar_espiral(int m[N][N])
{
	int f, c, cont, izq, der, arr, aba;

	printf("La espiral es:\n");

	izq = 0;
	der = N;
	arr = 0;
	aba = N;

	for (cont = 0; cont <= N/2; cont++)
	{
		for (c = izq; c < der; c++)
			printf("%i ", m[c][arr]);
		for (f = arr + 1; f < aba; f++)
			printf("%i ", m[der-1][f]);
		for (c = der-2; c >= izq; c--)
			printf("%i ", m[c][aba-1]);
		for (f = aba-2; f >= arr+1; f--)
			printf("%i ", m[izq][f]);

		izq++;
		der--;
		arr++;
		aba--;
	}













	printf("\n");
}








