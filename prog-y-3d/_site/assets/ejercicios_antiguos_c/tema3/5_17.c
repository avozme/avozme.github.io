#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    int orden, i;
    char cad[100];
    
    printf("Fundamentos de programaci�n 1� ASI - Curso 05/06\n");
    printf("Ejercicio 5.17 - Comprobar si en una cadena las letras est�n en orden alfab�tico\n\n");
    
    printf("Introduzca una cadena: ");
    gets(cad);
    
    orden = 1;        // Centinela. Valdr� 1 si las letras est�n en orden
    i = 1;            // Contador. Empezaremos en el car�cter 1, no en el 0
    while ((orden == 1) && (i < strlen(cad)))
    {
        if (cad[i] < cad[i-1])    // Comparamos cada letra con la anterior
        {                         // Si no est�n en orden, ponemos orden = 0
                orden = 0;
        }
        i++;
    }
    
    if (orden == 1)
        printf("Las letras de la cadena est�n en orden alfab�tico\n");
    else
        printf("Las letras de la cadena NO est�n en orden alfab�tico\n");
        
    system("PAUSE");
    return 0;
}
