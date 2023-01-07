#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int main()
{
    int x, y, i;
    int cochex = 40;
    int vidas = 5;
    char c;

    x = 35; y = 1;
    
    while (1 == 1)
    {
        // Dibujar Carretera
        gotoxy(x,y);
        cprintf("|          |");

        y++;
        if (y > 25) {
            y = 25;
            gotoxy(1,1);
            delline();

        }

        // Vidas
        gotoxy(1,1);
        cprintf("Vidas: %i", vidas);

        // Mover y dibujar Coche
        gotoxy(cochex, 25); printf("H");
        if (kbhit()) 
        {
            c = getch();
            if (c == 'z') cochex--; 
            if (c == 'x') cochex++;   
        }

        // Mover carretera
        for (i=1; i<=50000000; i++);
        i = rand()%3;
        if (i == 0) x++;
        if (i == 1) x--;

    }

	return 0;
}
