// Fundamentos de programacion 1º ASI
// Ejercicio del Tema 2 - Nº 4
// Cuenta en nº de cifras de un número entero

#include <stdio.h>
#include <stdlib.h>

main(void)
{
	long N;
	printf("Tema 2 - Ejercicio 4\n");
	printf("Cuenta el nº de cifras de un número entero\n\n");
	printf("Introduce el número: ");
	scanf("%d",&N);
	N = labs(N);

	if ((N >= 0) & (N <=9))
		printf("El número tiene 1 dígito");
	else if (N <=99)
		printf("El número tiene 2 dígitos");
	else if (N <=999)
		printf("El número tiene 3 dígitos");
	else if (N <=9999)
		printf("El número tiene 4 dígitos");
	else if (N <=99999)
		printf("El número tiene 5 dígitos");
	else
		printf("El número tiene más de 5 dígitos");
}
