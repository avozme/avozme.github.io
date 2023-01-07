// Fundamentos de programaci�n 1� ASI
// Ejercicios de RECURSIVIDAD del TEMA 8

// Calcular sumas que resultan en otro n�mero dado

#include <stdio.h>
#include <stdlib.h>

int calcula_sumas(int n, int a, int b);

int main(void)
{
    int n;
    
    printf("Calcular todas las sumas que dan lugar a otro n�mero\n\n");
    
    printf("Introduce un n�mero entero positivo: ");
    scanf("%i", &n);
    
    calcula_sumas(n, 1, n-1);

    system("PAUSE");
    
    return 0;
}


int calcula_sumas(int n, int a, int b)
{
  if (a <= b)
  {
    if (a + b == n)
        printf("%i + %i = %i\n", a, b, n);

    calcula_sumas(n, a+1, b-1);        
  }
}

