// Calcula el mcm de dos números sin usar vectores
// ni el algoritmo de Euclides

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int factorizar(int *n, int factor);
int siguiente_primo(int n);


int main(void)
{
    
    int n1, n1aux, n2, n2aux;
    int factor, potencia1, potencia2;
    int mcm = 1;

    printf("Introduce dos números enteros:\n");
    scanf("%i", &n1); scanf("%i", &n2);
    n1aux = n1; n2aux = n2;

    factor = 2;

    while ((n1 != 1) || (n2 != 1))
    {
        potencia1 = factorizar(&n1, factor);
        potencia2 = factorizar(&n2, factor);
        printf("factor = %i / pot1 = %i, pot2 = %i\n", factor, potencia1, potencia2);
        if (potencia1 > potencia2)
            mcm = mcm * pow(factor, potencia1);
        else
            mcm = mcm * pow(factor, potencia2);

        factor = siguiente_primo(factor);
    }

    printf("mcm(%i, %i) = %i\n", n1aux, n2aux, mcm);
 
    system("pause");
    return 0;
}


int factorizar(int *n, int factor)
{
    int pot = 0;

    while (*n % factor == 0)
    {
        if (*n % factor == 0)
        {
            pot++;
            *n = *n / factor;
        }
    }
    return pot;
}



int siguiente_primo(int n)
{
    int esprimo, i;

    do
    {
        n++;
        esprimo = 1;
        for (i=2; i<n-1; i++)
        {
            if (n % i == 0)
            {
                esprimo = 0;
                break;
            }
        }
    }
    while (esprimo == 0);
    
    return n;
}       
