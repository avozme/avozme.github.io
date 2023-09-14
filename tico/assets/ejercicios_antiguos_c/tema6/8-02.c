// Fundamentos de programación 1º ASI
// Ejercicios de RECURSIVIDAD del TEMA 8

// Potencia

#include <stdio.h>
#include <stdlib.h>

long potencia(int b, int e);

int main(void)
{
    int b,e;
    long pot;
    
    printf("Cáculo recursivo de una potencia\n");
    printf("Introduzca base: "); scanf("%i", &b);
    printf("Introduzca exponente: "); scanf("%i", &e);
    
    pot = potencia(b,e);
    
    printf("%i elevado a %i es igual a %li\n", b, e, pot);
    system("PAUSE");
    
    return 0;
}


long potencia(int b, int e)
{
    long r;
    
    if (e == 0) r = 1;
    else r = b * potencia(b, e-1);
    
    return r;
}
    
