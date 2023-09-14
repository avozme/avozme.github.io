// Fundamentos de programación 1º ASI
// Ejercicios de RECURSIVIDAD del TEMA 8

// Secuencia de Fibonacci

#include <stdio.h>
#include <stdlib.h>

void fibonacci(int n, int n2);

int main(void)
{
    int b,e;
    long pot;
    
    printf("Cálculo recursivo de la secuencia de Fibonacci hasta 5 cifras:\n\n");
    
    printf("0 - 1 - ");
    fibonacci(0,1);
    
    printf("\n\n");
    system("PAUSE");
    
    return 0;
}


void fibonacci(int n, int n2)
{
    int r;
    
    r = n + n2;
    if (r < 99999)
    {
        printf("%i - ", r);
        fibonacci(n2, r);
    }
}
    
