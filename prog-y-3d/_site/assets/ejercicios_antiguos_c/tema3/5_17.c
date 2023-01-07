#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    int orden, i;
    char cad[100];
    
    printf("Fundamentos de programación 1º ASI - Curso 05/06\n");
    printf("Ejercicio 5.17 - Comprobar si en una cadena las letras están en orden alfabético\n\n");
    
    printf("Introduzca una cadena: ");
    gets(cad);
    
    orden = 1;        // Centinela. Valdrá 1 si las letras están en orden
    i = 1;            // Contador. Empezaremos en el carácter 1, no en el 0
    while ((orden == 1) && (i < strlen(cad)))
    {
        if (cad[i] < cad[i-1])    // Comparamos cada letra con la anterior
        {                         // Si no están en orden, ponemos orden = 0
                orden = 0;
        }
        i++;
    }
    
    if (orden == 1)
        printf("Las letras de la cadena están en orden alfabético\n");
    else
        printf("Las letras de la cadena NO están en orden alfabético\n");
        
    system("PAUSE");
    return 0;
}
