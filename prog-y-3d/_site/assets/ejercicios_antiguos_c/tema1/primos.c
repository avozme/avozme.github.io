// Fundamentos de programacion 1º ASI
// Muestra los primeros N números primos

#include "stdio.h"
#include "math.h"

int main()
{
    int i, j, N, es_primo;

	printf("1 ASI - Fund. Prog.\n");
	printf("Mostrar los primeros N números primos\n\n");
	printf("Introduce N: ");
	scanf("%i",&N);

    for (i = 1; i <= N; i++)
    {
        es_primo = 1;
        j = 2;
        while (j <= (i-1) && (es_primo))
        {
              if (i % j == 0) es_primo = 0;
              j++;
        }
        if (es_primo) printf("%i\n", i);
    }
    printf("\n\n");
    system("PAUSE");
}
