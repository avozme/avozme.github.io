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
    if (ganador == 'H') printf("Enhorabuena, humano, me has ganado en buena liz\n");
    if (ganador == 'M') printf("Te he ganado, deberias estar avergonzado\n");
    if (ganador == 'T') printf("TABLAS. Prueba otra vez.\n");
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
    printf("IES Celia Vinas (Almeria) - Fundamentos de programacion 1ASI - Curso 05/06\n");
    printf("EJERCICIO OBLIGATORIO DEL TEMA 4: LAS TRES EN RAYA\n\n\n");
    printf("     A     B     C    \n");
    printf("  +-----+-----+-----+ \n");
    printf("  |     |     |     | \n");
    printf("1 |  %c  |  %c  |  %c  | \n", a1, b1, c1);
    printf("  |     |     |     | \n");
    printf("  +-----+-----+-----+ \n");
    printf("  |     |     |     | \n");
    printf("2 |  %c  |  %c  |  %c  | \n", a2, b2, c2);
    printf("  |     |     |     | \n");
    printf("  +-----+-----+-----+ \n");
    printf("  |     |     |     | \n");
    printf("3 |  %c  |  %c  |  %c  | \n", a3, b3, c3);
    printf("  |     |     |     | \n");
    printf("  +-----+-----+-----+ \n");
    printf("\n");
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
              // Elegir la columna
              do {  
                printf("Es tu turno. Elige columna (a, b, c): ");
                scanf("%s", cad);
                c = cad[0];
              }
              while ((c < 'a') || (c > 'c'));
              
              if (c == 'a') *col = 1;
              if (c == 'b') *col = 2;
              if (c == 'c') *col = 3;
              
              // Elegir la fila
              do {  
                printf("Elige fila (1, 2, 3): ");
                scanf("%s", cad);
                *fila = atoi(cad);
              }
              while ((*fila < 1) || (*fila > 3));
              
              // Comprobar si esa casilla está ocupada
              casilla = valor_casilla(*col, *fila, a1, a2, a3, b1, b2, b3, c1, c2, c3);
              if (casilla != 32)
                 printf("Esa casilla ya está ocupada. Selecciona otra.\n");
        }
        while (casilla != 32);
   }

    if (turno == 'M')       // Turno MÁQUINA
    {
        printf("Es mi turno. Estoy pensando...\n"); esperar(3);
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
