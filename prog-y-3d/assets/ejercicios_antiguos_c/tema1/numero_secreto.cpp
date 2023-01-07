// Fundamentos de programacion 1º ASI
// Ejercicio del Tema 1
// Juego del número secreto

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

main(void)
{
	int num_secreto, n, intentos = 0;
    srand(time(NULL));
	printf("El juego del numero secreto\n\n");
    num_secreto = rand() % 100 + 1;
    
    do
    {
          printf("Intenta adivinar mi numero: ");
          scanf("%i", &n);
          intentos = intentos + 1;
          if (num_secreto > n)
             printf("Mi numero es MAYOR\n");
          if (num_secreto < n)
             printf("Mi numero es MENOR\n");
          if (num_secreto == n) 
             printf("ENHORABUENA, has acertado. Has necesitado %i intentos\n\n", intentos);
    }                             
    while (n != num_secreto);
    system("PAUSE");
}
