// Fundamentos de programacion 1� ASI
// Ejercicio del Tema 2 - N� 4
// Cuenta en n� de cifras de un n�mero entero

#include <stdio.h>
#include <stdlib.h>

main(void)
{
	long N;
	printf("Tema 2 - Ejercicio 4\n");
	printf("Cuenta el n� de cifras de un n�mero entero\n\n");
	printf("Introduce el n�mero: ");
	scanf("%d",&N);
	N = labs(N);

	if ((N >= 0) & (N <=9))
		printf("El n�mero tiene 1 d�gito");
	else if (N <=99)
		printf("El n�mero tiene 2 d�gitos");
	else if (N <=999)
		printf("El n�mero tiene 3 d�gitos");
	else if (N <=9999)
		printf("El n�mero tiene 4 d�gitos");
	else if (N <=99999)
		printf("El n�mero tiene 5 d�gitos");
	else
		printf("El n�mero tiene m�s de 5 d�gitos");
}
