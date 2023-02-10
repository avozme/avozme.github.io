#include <stdio.h>


int main(void) {
    int n, i;

    printf("Dime un número: \n");
    scanf("%d", &n);

    for (i = 1; i <= n; i++) {
        printf("%d\n", i);
    }

    return 0;
}

