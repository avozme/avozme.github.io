#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int a, b, d;
    float c;
    c = 6.4;
    a = c;
    b = a*a;
    a++;
    c = a / 3;
    d = (a > c);
    printf("a = %i, b = %i, c = %f, d = %i\n", a, b, c, d);
    system("PAUSE");
    return 0;
}
    
