---
layout: page
title: 9.7. Ejercicios resueltos
permalink: /ejercicios-resueltos-c/
nav_order: 7
has_children: true
parent: 9. El lenguaje C
grand_parent: Introd. a la prog. y al diseño 3D
---

## 9.7. Ejercicios resueltos
{: .no_toc }

- TOC
{:toc}


Aquí iremos poniendo los ejercicios que resolvamos en clase.

#### Contar números

Este programa cuenta números desde 1 hasta n, siendo n un número introducido por el usuario.

Puedes usarlo como modelo para escribir el programa de la tabla de multiplicar.

```c
#include <stdio.h>

int main(void) {
    int n, i;

    printf("Dime un número: \n");
    scanf("%d", &n);

    printf("Los números entre 1 y %d son:\n", n);

    for (i = 1; i <= n; i++) {
        printf("%d\n", i);
    }

    return 0;
}
```

#### Factorial

Este programa calcula el factorial de un número n introducido por teclado. Ten en cuenta que el factorial crece exponencialmente con el valor de n, de modo que, si escribes un número muy grando, el cálculo se desboradará y obtendrás un resultado erróneo.

Este es otro ejemplo de uso de los bucles que puedes usar como modelo para resolver los ejercicios propuestos.

```c
#include <stdio.h>

int main(void) {
    int n, i, acumulador;

    do {
        printf("Dime un número mayor que 0: \n");
        scanf("%d", &n);
    } while (n <= 0);

    acumulador = n;       

    for (i = n-1; i >= 1; i--) {
        acumulador = acumulador * i;
    }

    printf("El factorial de %d es %d\n", n, acumulador);

    return 0;
}
```

#### Calcular media y mediana

El siguiente programa crea un array de 5000 números enteros y les asigna valores al azar entre 1 y 1000.

Después, recorre el array para calcular el valor medio y la mediana de todos los números generados. Recuerda que la mediana es el valor de la serie que más se aproxima al promedio.

Si la serie es lo suficientemente grande, el promedio debería ser muy cercano a 500 y la mediana coincidir con el promedio. En cambio, si disminuyes la longitud del array, el promedio se alejará más de 500 y la mediana solo coincidirá con la media a veces.

```c
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
```


