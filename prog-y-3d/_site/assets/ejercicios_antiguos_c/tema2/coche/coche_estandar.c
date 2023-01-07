#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x, i;

    x = 34;
    
    while (1 == 1)
    {

        for (i=1; i<=x; i++) 
            printf(" ");

        printf("|          |\n");
        for (i=1; i<=50000000; i++);

        i = rand()%3;
        if (i == 0) x++;
        if (i == 1) x--;

    }

	return 0;
}
