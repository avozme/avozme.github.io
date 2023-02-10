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

