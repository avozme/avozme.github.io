// Fundamentos de programacion 1� ASI
// Ejercicio del Tema 2 - N� 3
// Averigua si un numero tiene parte decimal o no

#include "stdio.h"
#include "math.h"

int main()
{
	float N;
	printf("Tema 2 - Ejercicio 3\n");
	printf("Averigua si un n�mero real tiene parte decimal\n\n");
	printf("Introduce el n�mero: ");
	scanf("%f",&N);
	if (N == ceil(N))
		printf("NO tiene parte decimal");
	else
		printf("SI tiene parte decimal");
}
