// Fundamentos de programacion 1� ASI
// Ejercicio del Tema 2 - N� 8
// Muestra todos los n�meros impares entre A y B

#include <stdio.h>

main(void)
{
	int A, B, i, inicio, fin;
	printf("Tema 2 - Ejercicio 8\n");
	printf("Muestra los n�meros impares entre A y B\n\n");

	printf("Introduce el valor de A: ");
	scanf("%d",&A);
	printf("Introduce el valor de B: ");
	scanf("%d",&B);

	// Comprobamos cual es mayor, A o B. El menor sera el inicio del intervalo
	if (A<B)
	{
		inicio = A;
		fin = B;
	}
	else
	{
		inicio = B;
		fin = A;
	}

	// Nos aseguramos de que el inicio sea un n�mero impar
	if (inicio%2 == 0) inicio++;

	// Contamos desde inicio hasta fin
	printf("Los n�meros impares entre %d y %d son:\n", A, B);
	for (i=inicio; i<=fin; i=i+2)
		printf("%d - ",i);

}
