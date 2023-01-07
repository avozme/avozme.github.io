#include <stdio.h>

int main(void)
{
    int n;
        
    printf("Introduce un numero entero: ");
    scanf("%i", &n);

    if (n > 0)
       printf("El numero introducido es POSITIVO\n");
    if (n < 0)
       printf("El numero introducido es NEGATIVO\n");
    else
       printf("El numero introducido es no es positivo ni negativo\n");
    
    system("pause");
    return 0;
}
    
