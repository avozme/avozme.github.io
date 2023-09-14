// Fundamentos de programación 1º ASI
// Ejercicios de RECURSIVIDAD del TEMA 8

// Sumatorio

#include <stdio.h>
#include <stdlib.h>

int sumatorio(int n);

int main(void)
{
    int n, suma;
    
    printf("Sumar números desde 1 hasta...");
    scanf("%i", &n);
    
    suma = sumatorio(n);
    
    printf("La suma desde 1 hasta %i es %i\n", n, suma);
    system("PAUSE");
    
    return 0;
}


int sumatorio(int n)
{
    int r;
    
    if (n == 0) r = 0;
    else r = n + sumatorio(n-1);
    
    return r;
}
    
