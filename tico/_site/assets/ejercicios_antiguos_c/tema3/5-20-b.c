#include <string.h>
#include <stdio.h>

int main()
{
    char cad1[50], cad2[50], *cad3;
    int i,j;
    
    puts("EJERCICIO 5-19 (b): Buscar una cadena dentro de otra");
    puts("Teclee el primer texto: ");
    gets(cad1);
    puts("Teclee el segundo texto: ");
    gets(cad2);

    cad3 = strstr(cad1, cad2);           // Busca cad2 dentro de cad1
    if (cad3 != NULL)                    // Se ha encontrado una ocurrencia. cad3 apunta a ella
      for (i=0; i<strlen(cad2); i++)
      {
        cad3[i] = '*';                   // Sustituimos por * tantas veces como letras tenga cad2
      }      
    puts("El resultado es:");
    puts(cad1);
    
    puts("Pulse Intro para terminar"); gets(cad3);
    return 0;
}
