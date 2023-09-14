#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*El siguiente programa crea un array de 100 números enteros y les asigna valores al azar entre 1 y 1000.
Después, recorre el array para calcular el valor medio de todos los números generados. */

int main(void) {
    int i, array[5000];
    int minima_diferencia;
    long int suma = 0;
    float media, mediana;

    srand(time(NULL));    // Inicializa el generador de números aleatorios

    // Genera el array al azar
    for (i = 0; i < 5000; i++) {
        array[i] = rand() % 1000 + 1;
        suma = suma + array[i];
    }

    // Muestra el array
    for (i = 0; i < 5000; i++) {
        printf("%d - ", array[i]);
    }

    // Calcula el promedio 
    media = suma / 5000;
    // Calcula la mediana (el valor más cercano al promedio)
    minima_diferencia = media;
    for (i = 0; i < 5000; i++) {
        if (abs(array[i] - media) < minima_diferencia) {
            minima_diferencia = abs(array[i] - media);
            mediana = array[i];
        }
    }
    // Muestra los resultados
    printf("\n\n");
    printf("La suma de los 5000 números es: %ld\n", suma);
    printf("La media de los 5000 números es: %f\n", media);
    printf("La mediana de los 5000 números es: %f\n", mediana);

    return 0;
}
