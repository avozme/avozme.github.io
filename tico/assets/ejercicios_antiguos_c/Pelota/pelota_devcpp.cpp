// PELOTA
// Fundamentos de Programación 1º ASI
// Ejercicio obligatorio del Tema 2 (curso 0809)

#include <conio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_OBST 200
#define ESPERA 80

void esperar(int miliseg);
int comprobar_obstaculos(int f, int c, int inc_f, int inc_c, struct s_coord obstaculos[NUM_OBST]) ;
    

struct s_coord { int x, y; };


int main(void)
{
    int f, c, af, ac, inc_f, inc_c;
    int i, obst;
    struct s_coord obstaculos[NUM_OBST];
    srand(time(NULL));

    textcolor(LIGHTRED);
    textbackground(WHITE);
    clrscr();
    
    textbackground(BLUE);
    for (i = 0; i < NUM_OBST; i++) {
        obstaculos[i].x = rand() % 60 + 10;
        obstaculos[i].y = rand() % 19 + 3;
        gotoxy(obstaculos[i].x, obstaculos[i].y);
        printf(" ");
    }
    textbackground(WHITE);    
    
    
    f = 1; c = 1; af = 1; ac = 1;
    inc_f = 1; inc_c = 1;

    while (1==1)
    {
          gotoxy(ac,af); cprintf(" ");
          gotoxy(c,f); cprintf("O");
          af = f; ac = c;
          f = f + inc_f; c = c + inc_c;

          obst = comprobar_obstaculos(f, c, inc_f, inc_c, obstaculos);
          
          if ((f >= 25) || (f <= 1))
             inc_f = -inc_f;
          if ((c >= 79) || (c <= 1))
             inc_c = -inc_c;
          if ((obst == 1) || (obst == 3))
             inc_c = -inc_c;
          if ((obst == 2) || (obst == 4))
             inc_f = -inc_f;

          esperar(ESPERA);
          gotoxy(1,25); printf("(%2i, %2i)", c, f);
    }
    return 0;
}



void esperar(int miliseg)
{
     int t;
     
     t = clock() + miliseg;
     while (t > clock());
} 



int comprobar_obstaculos(int f, int c, int inc_f, int inc_c, struct s_coord obstaculos[NUM_OBST]) 
{
    int i, obst = 0;
    
    for (i = 0; i < NUM_OBST; i++)
    {
        if ((obstaculos[i].y - f == 0) && (obstaculos[i].x - (c+inc_c) == 0))
           obst = 1;    // Rebotar en la columna
        if ((obstaculos[i].x - c == 0) && (obstaculos[i].y - (f+inc_f) == 0))
           obst = 4;    // Rebotar en la fila
        if ((obstaculos[i].x - (c+inc_c) == 0) && (obstaculos[i].y - (f+inc_f) == 0))
           obst = (rand()%4 + 1);   // Rebotar aleatoriamente
    }
    return obst;
}
 
