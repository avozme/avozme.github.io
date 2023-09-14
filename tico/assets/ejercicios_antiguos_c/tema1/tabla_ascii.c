// Fundamentos de programacion 1º ASI
// Ejercicio del Tema 1
// Conversor de código ASCII

#include <stdio.h>
#include <stdlib.h>

main(void)
{
	int i, N;
	printf("Introduce un número: ");
	scanf("%d",&N);

    if ((N < 0) || (N > 255))
       for (i=32; i<255; i++)
           printf("%i = %c\n", i, i);
    if ((N > 31) && (N < 255))
       printf("El carácter %i es %c\n", N, N);
    if ((N >= 0) && (N <=31))
       printf("Error, el carácter %i es no imprimible\n", N);
       
    system("pause");
    return 0;
}
