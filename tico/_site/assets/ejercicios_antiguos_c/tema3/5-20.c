#include <string.h>
#include <stdio.h>

int main()
{
    char cad1[50], cad2[50], cad3[50];
    int i,j;
    
    puts("EJERCICIO 5-19 (a): Buscar una cadena dentro de otra");
    puts("Teclee el primer texto: ");
    gets(cad1);
    puts("Teclee el segundo texto: ");
    gets(cad2);
    // Comprobamos que la segunda cadena sea más corta que la primera
    if (strlen(cad2) > strlen(cad1)) {
       puts("El segundo texto debe ser más corto que el primero");
       exit(-1);
    }
    
    for (i=0; i<strlen(cad1); i++)         // recorremos todas las letras de cad1
    {
        if (cad1[i] == cad2[0])            // hemos encontrado una posible coincidencia
        {
            for (j=0; j<strlen(cad2); j++) // construimos cad3 copiando desde cad1 tantas letras como tenga cad2
            {
                 cad3[j] = cad1[i+j];
            }
            cad3[j] = '\0';                // Añadimos el nulo al final de cad3 
            if (strcmp(cad2, cad3) == 0)   // Si cad3 y cad2 son iguales, se ha encontrado una ocurrencia
            {                              // Sustituimos en cad1 por asteriscos
                 for (j=0; j<strlen(cad2); j++)
                      cad1[i+j] = '*';
            }
        }
    }
    
    puts("El resultado es:");
    puts(cad1);
    
    puts("Pulse Intro para terminar"); gets(cad3);
    return 0;
}
