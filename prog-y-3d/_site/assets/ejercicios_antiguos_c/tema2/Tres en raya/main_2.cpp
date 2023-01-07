// TRES EN RAYA (versión básica - sin usar conio)
// Fundamentos de Programación 1º ASI
// Ejercicio obligatorio de Tema 4 (curso 05/06)

#include <conio.h>
#include <stdlib.h>
#include <time.h>

char elegir_turno();
void dibujar_tablero(char turno,int a1,int a2,int a3,int b1,int b2,int b3,int c1,int c2,int c3);
void elegir_casilla(char turno,int a1,int a2,int a3,int b1,int b2,int b3,int c1,int c2,int c3,int *fila, int *col);
char comprobar_final(char turno,int a1,int a2,int a3,int b1,int b2,int b3,int c1,int c2,int c3);
void poner_casilla(int col, int fila, char turno, int *a1,int *a2,int *a3,int *b1,int *b2,int *b3,int *c1,int *c2,int *c3);
int valor_casilla(int col, int fila,int a1,int a2,int a3,int b1,int b2,int b3,int c1,int c2,int c3);
void esperar(int seg);
void seleccionar_casilla(int* fila, int* columna);

int main(void)
{
    int a1=32, a2=32, a3=32;   // Casillas del tablero
    int b1=32, b2=32, b3=32;   // (no podemos usar arrays porque aún no los hemos dado)
    int c1=32, c2=32, c3=32;
    int fila, col;
    char turno, ganador;
    
    turno = elegir_turno();
    do
    {
        clrscr();
        dibujar_tablero(turno,a1,a2,a3,b1,b2,b3,c1,c2,c3);
        elegir_casilla(turno,a1,a2,a3,b1,b2,b3,c1,c2,c3,&fila,&col);
        poner_casilla(col, fila, turno,&a1,&a2,&a3,&b1,&b2,&b3,&c1,&c2,&c3);
        ganador = comprobar_final(turno,a1,a2,a3,b1,b2,b3,c1,c2,c3);
        if (turno == 'M') turno = 'H'; else turno = 'M';
        //printf("GANADOR = %c\n", ganador);
    }
    while (ganador == 'N');

    clrscr();
    dibujar_tablero(turno,a1,a2,a3,b1,b2,b3,c1,c2,c3);
    if (ganador == 'H') {
       gotoxy(16,22); textcolor(LIGHTCYAN);
       printf("Enhorabuena, humano, me has ganado en buena liz\n");
    }
    if (ganador == 'M') {
       gotoxy(19,22); textcolor(YELLOW);
       printf("Te he ganado. Deberias estar avergonzado...\n");
    }
    if (ganador == 'T') {
       gotoxy(25,22); textcolor(WHITE);
       printf("TABLAS. Prueba otra vez.\n");
    }
    gotoxy(22,23);
    system("PAUSE");
    return 0;
}

char elegir_turno()
{
    char turno;
    int aleat;
    long t;
    
    t = time(NULL);
    srand(t);
    aleat = rand() % 2;
    if (aleat == 0) turno = 'H'; else turno = 'M';
    return turno;
}
      
void dibujar_tablero(char turno,int a1,int a2,int a3,int b1,int b2,int b3,int c1,int c2,int c3)
{
    int fila, columna, color, i, ficha;

    // Pinta encabezado de la pantalla de juego
    textbackground(BLUE);
    clrscr();
    textcolor(WHITE);
    textbackground(RED);
    gotoxy(1,1);
    printf("+----------------------------------------------------------------------------+\n");
    printf("| IES Celia Vinas (Almeria) - Fundamentos de programacion 1ASI - Curso 05/06 |\n");
    printf("|            EJERCICIO OBLIGATORIO DEL TEMA 4: LAS TRES EN RAYA              |\n");
    printf("+----------------------------------------------------------------------------+\n");

    // Pinta pie de la pantalla de juego
    textcolor(WHITE); textbackground(RED);
    gotoxy(60,14); printf("+-----------------+");
    gotoxy(60,15); printf("|                 |");
    gotoxy(60,16); printf("|                 |");
    gotoxy(60,17); printf("+-----------------+");
    textcolor(LIGHTCYAN);
    gotoxy(63,15); printf("O = humano");
    textcolor(YELLOW);
    gotoxy(63,16); printf("X = ordenador");

    // Pinta coordenadas del tablero
    textcolor(WHITE); textbackground(BLUE);
    gotoxy(32, 10); printf("A    B    C");
    gotoxy(28, 13); printf("1");
    gotoxy(28, 16); printf("2");
    gotoxy(28, 19); printf("3");
    
    
    
    // Pinta tablero
    textbackground(BLUE);
    color = BLACK;
    for (fila = 1; fila<=3; fila++)
      for (columna = 1; columna<=3; columna++)
      {
          textbackground(color);
          for (i=1; i<=3; i++)                 // Pinta una casilla
          {
              gotoxy(columna*5+25, fila*3+8+i);
              printf("     \n");
          }
          gotoxy(columna*5+27, fila*3+10);      // Pinta la ficha de la casilla        
          if ((fila==1) && (columna==1)) ficha = a1;
          if ((fila==1) && (columna==2)) ficha = b1;
          if ((fila==1) && (columna==3)) ficha = c1;
          if ((fila==2) && (columna==1)) ficha = a2;
          if ((fila==2) && (columna==2)) ficha = b2;
          if ((fila==2) && (columna==3)) ficha = c2;
          if ((fila==3) && (columna==1)) ficha = a3;
          if ((fila==3) && (columna==2)) ficha = b3;
          if ((fila==3) && (columna==3)) ficha = c3;
          if (ficha == 'O') textcolor(LIGHTCYAN); else textcolor(YELLOW);
          printf("%c",ficha);

          if (color==BLACK) color=RED; else color=BLACK;
      }
    textbackground(BLUE);
}

   
void elegir_casilla(char turno,int a1,int a2,int a3,int b1,int b2,int b3,int c1,int c2,int c3,int *fila, int *col)
{
    char cad[100];
    char c;
    int casilla;
    
    if (turno == 'H')       // Turno HUMANO
    {
        do
        {
             textcolor(LIGHTCYAN); 
             gotoxy(32,6);
             printf("ES TU TURNO"); 
             textcolor(LIGHTBLUE);
             gotoxy(5,7); 
             printf("Usa Q, A, O y P para moverte. Pulsa Intro para seleccionar una casilla.");
             seleccionar_casilla(fila, col);
              
             // Comprobar si esa casilla está ocupada
             casilla = valor_casilla(*col, *fila, a1, a2, a3, b1, b2, b3, c1, c2, c3);
             if (casilla != 32) {
                gotoxy(16,8);
                textcolor(LIGHTRED);
                printf("Esa casilla ya esta ocupada. Selecciona otra.\n");
                esperar(3);
                dibujar_tablero(turno,a1,a2,a3,b1,b2,b3,c1,c2,c3);
             }
        }
        while (casilla != 32);
   }

    if (turno == 'M')       // Turno MÁQUINA
    {
        textcolor(YELLOW); 
        gotoxy(32,6);
        printf("ES MI TURNO"); 
        textcolor(LIGHTBLUE);
        gotoxy(21,7); 
        printf("Espera un momento, estoy pensando...");
        esperar(3);
        do
        {
              // Elegir columna y fila aleatoriamente
              *col = rand() % 3 + 1;              
              *fila = rand() % 3 + 1;              
              // Comprobar si esa casilla está ocupada
              casilla = valor_casilla(*col, *fila, a1, a2, a3, b1, b2, b3, c1, c2, c3);
        }
        while (casilla != 32);
   }
        
}


char comprobar_final(char turno,int a1,int a2,int a3,int b1,int b2,int b3,int c1,int c2,int c3)
{
    char ganador;
    
    ganador = 'N';      // Por defecto, NADIE
    
    // Comprobar columnas
    if ((a1 == a2) && (a2 == a3) && (a1!=' ')) ganador = a1;
    if ((b1 == b2) && (b2 == b3) && (b1!=' ')) ganador = b1;
    if ((c1 == c2) && (c2 == c3) && (c1!=' ')) ganador = c1;
    //printf("Después de COLUMNAS: ganador = %c\n", ganador);

    // Comprobar filas
    if ((a1 == b1) && (b1 == c1) && (a1!=' ')) ganador = a1;
    if ((a2 == b2) && (b2 == c2) && (a2!=' ')) ganador = a2;
    if ((a3 == b3) && (b3 == c3) && (a3!=' ')) ganador = a3;
    //printf("Después de FILAS: ganador = %c\n", ganador);
    
    // Comprobar diagonales
    if ((a1 == b2) && (b2 == c3) && (a1!=' ')) ganador = a1;
    if ((a3 == b2) && (b2 == c1) && (a3!=' ')) ganador = a3;
    //printf("Después de DIAGONALES: ganador = %c\n", ganador);
    
    if (ganador == 'O') ganador = 'H';      // Gana el humano (sus fichas son Oes)
    if (ganador == 'X') ganador = 'M';      // Gana la máquina (sus fichas son equis)
    if (ganador == ' ') ganador = 'N';      // No hay ganador por ahora
    //printf("Después de TRANSFORMACIÓN: ganador = %c\n", ganador);
    
    // Comprobar tablas
    if ((a1 != ' ') && (a2 != ' ') && (a3 != ' ') &&
        (b1 != ' ') && (b2 != ' ') && (b3 != ' ') &&
        (c1 != ' ') && (c2 != ' ') && (c3 != ' ') && (ganador == 'N'))
        ganador = 'T';
    //printf("Después de TABLAS: ganador = %c\n", ganador);
    //system("PAUSE");
        
    return ganador;
}


void poner_casilla(int col, int fila, char turno, int *a1,int *a2,int *a3,int *b1,int *b2,int *b3,int *c1,int *c2,int *c3)
{
    char ficha;
    
    if (turno == 'H') ficha = 'O'; else ficha = 'X';
    
    switch(col)
    {
        case 1: if (fila == 1) *a1 = ficha;
                if (fila == 2) *a2 = ficha;
                if (fila == 3) *a3 = ficha;
                break;
        case 2: if (fila == 1) *b1 = ficha;
                if (fila == 2) *b2 = ficha;
                if (fila == 3) *b3 = ficha;
                break;
        case 3: if (fila == 1) *c1 = ficha;
                if (fila == 2) *c2 = ficha;
                if (fila == 3) *c3 = ficha;
                break;
    }
}


int valor_casilla(int col, int fila,int a1,int a2,int a3,int b1,int b2,int b3,int c1,int c2,int c3)
{
    int ficha;
    
    switch(col)
    {
        case 1: if (fila == 1) ficha = a1;
                if (fila == 2) ficha = a2;
                if (fila == 3) ficha = a3;
                break;
        case 2: if (fila == 1) ficha = b1;
                if (fila == 2) ficha = b2;
                if (fila == 3) ficha = b3;
                break;
        case 3: if (fila == 1) ficha = c1;
                if (fila == 2) ficha = c2;
                if (fila == 3) ficha = c3;
                break;
    }
    
    return ficha;
}

void esperar(int seg)
{
    long t, t_fin;
    t = time(NULL);
    t_fin = t + seg;
    
    while (t!=t_fin)
        t = time(NULL);
}

void seleccionar_casilla(int *fila, int *columna)
{
    int x = 1, y = 1;
    int ax= 1, ay= 1;
    int color;
    int c;
    
    do
    {
         textbackground(GREEN);             // Dibuja recuadro de selección en color verde
         gotoxy(x*5+25, y*3+9);
         printf("     ");
         gotoxy(x*5+25, y*3+10);
         printf(" ");
         gotoxy(x*5+29, y*3+10);
         printf(" ");
         gotoxy(x*5+25, y*3+11);
         printf("     ");
         
         c = getch();
         if (c == 'q') { ay=y; ax=x; y--; if (y<1) y=1; }
         if (c == 'a') { ay=y; ax=x; y++; if (y>3) y=3; }
         if (c == 'o') { ax=x; ay=y; x--; if (x<1) x=1; }
         if (c == 'p') { ax=x; ay=y; x++; if (x>3) x=3; }
         
         if ((ax != x) || (ay != y))         // Borra recuadro anterior
         {
            if ((ax==1) && (ay==1)) color = BLACK;         // Recuperamos color original
            if ((ax==1) && (ay==2)) color = RED;
            if ((ax==1) && (ay==3)) color = BLACK;
            if ((ax==2) && (ay==1)) color = RED;
            if ((ax==2) && (ay==2)) color = BLACK;
            if ((ax==2) && (ay==3)) color = RED;
            if ((ax==3) && (ay==1)) color = BLACK;
            if ((ax==3) && (ay==2)) color = RED;
            if ((ax==3) && (ay==3)) color = BLACK;
            textbackground(color);
            gotoxy(ax*5+25, ay*3+9);
            printf("     ");
            gotoxy(ax*5+25, ay*3+10);
            printf(" ");
            gotoxy(ax*5+29, ay*3+10);
            printf(" ");
            gotoxy(ax*5+25, ay*3+11);
            printf("     ");
         }
         
    }
    while (c!=13);
    textbackground(BLUE);
    *fila = y;
    *columna = x;
}

