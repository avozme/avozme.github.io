#include <stdio.h>

int main(void)
{
    float r, a, c;
    
    printf("Introduce el radio: ");
    scanf("%f", &r);
    a = 3.1415 * r * r;
    c = 2 * 3.1415 * r;
    
    printf("El area es: %2.3f\n", a);
    printf("La circunferencia es: %2.3f\n\n", c);
    
    system("pause");
    return 0;
}
    
