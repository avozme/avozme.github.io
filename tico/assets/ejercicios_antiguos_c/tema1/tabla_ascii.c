// Fundamentos de programacion 1� ASI
// Ejercicio del Tema 1
// Conversor de c�digo ASCII

#include <stdio.h>
#include <stdlib.h>

main(void)
{
	int i, N;
	printf("Introduce un n�mero: ");
	scanf("%d",&N);

    if ((N < 0) || (N > 255))
       for (i=32; i<255; i++)
           printf("%i = %c\n", i, i);
    if ((N > 31) && (N < 255))
       printf("El car�cter %i es %c\n", N, N);
    if ((N >= 0) && (N <=31))
       printf("Error, el car�cter %i es no imprimible\n", N);
       
    system("pause");
    return 0;
}
