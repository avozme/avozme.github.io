// Generador de Sudokus
// Versi�n b�sica: genera s�lo las matrices de 3x3

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TRUE 1
#define FALSE 0
#define FIJOS 2     // Cantidad de n�meros fijos en la matriz inicial
typedef int logico;

void inicializar_matriz(int m[3][3], int n);
logico comprobar_matriz(int m[3][3]);
logico generar_matriz(int m[3][3]);
logico matriz_completa(int m[3][3]);
void copiar_matriz(int orig[3][3], int dest[3][3]);
void mostrar_matriz(int m[3][3]);


int main(void)
{
    int m[3][3];

    printf("GENERADOR DE SUDOKUS\n");
    printf("Parte 1: generador de matrices de 3x3\n\n");
    printf("MATRIZ INICIAL (con %i n�meros fijados):\n", FIJOS);
    inicializar_matriz(m, FIJOS);   // Inicializa a 0 e inserta FIJOS n�meros al azar
    printf("\nSOLUCIONES:\n");
    generar_matriz(m);               // Genera matriz 3x3
    
    system("PAUSE");
    return 0;
}


// Inicializa una matriz de 3x3 a cero e inserta N n�meros al azar
void inicializar_matriz(int m[3][3], int n)
{
    int i, j, k, x;
    long t;
    int v[10];
    
    t = time(NULL);
    srand(t);
    
    for (i=0; i<3; i++)     // Inicializar a cero
    for (j=0; j<3; j++)
        m[i][j] = 0;
        
    for (i=0; i<10; i++) v[i] = 0;
    
    k = 0;
    while (k < n)               // Insertar n n�meros al azar en posiciones tambi�n al azar
    {
        do {
           x = rand() % 9 + 1;  // N�mero al azar, pero que no haya salido antes
        } while (v[x] == 1);
        v[x] = 1;
        do
        {
          i = rand() % 3 + 1;     // Posici�n al azar
          j = rand() % 3 + 1;
        }
        while (m[i][j] != 0);    // Esa posici�n ya est� ocupada, buscar otra

        m[i][j] = x;             // Insertar n� en la posici�n    
        k++;
    }
    
    mostrar_matriz(m);
        
}

// Comprueba si una matriz de 3x3 es v�lida para el Sudoku
logico comprobar_matriz(int m[3][3])
{
    logico correcto = TRUE;
    int v[10], i, j, n;
    
    for (i=0; i<10; i++) v[i] = 0;
    
    // La matriz ser� v�lida si en sus 9 posiciones est�n los 9 n�meros, es decir,
    // si no hay ninguno repetido. Pondremos a 1 una posici�n del vector v[]
    // para cada n�mero encontrado en la matriz.
    for (i=0; i<3; i++)
    for (j=0; j<3; j++)
    {
        n = m[i][j];
        if (v[n] == 1)    // Hemos encontrado un n�mero repetido (v[i] ya val�a 1)
           correcto = FALSE;
        v[n] = 1;
    }
    
    return correcto;
}


// Devuelve TRUE si la matriz est� completa, es decir, si tiene n�meros en sus 9 posiciones
logico matriz_completa(int m[3][3])
{
    logico correcto = TRUE;
    int i, j;
    
    // La matriz estar� completa si en sus 9 posiciones hay alg�n n�mero
    for (i=0; i<3; i++)
    for (j=0; j<3; j++)
        if (m[i][j] == 0)    // En esta posici�n no hay ning�n n�mero a�n
           correcto = FALSE;
    
    return correcto;
}
   
// Copia el contenido de la matriz "orig" en la matriz "dest"   
void copiar_matriz(int orig[3][3], int dest[3][3])
{
    int i,j;
    for (i=0; i<3; i++)
    for (j=0; j<3; j++)
        dest[i][j] = orig[i][j];
}

// Muestra por pantalla el contenido de la matriz m
void mostrar_matriz(int m[3][3])
{
    int i,j;
 
    printf("\n\n");
    for (j=0; j<3; j++)
    {
      for (i=0; i<3; i++)
      {
        printf("%3i", m[i][j]);
      }
      printf("\n");
    }
}


// Genera recursivamente una matriz 3x3 v�lida para el sudoku, partiendo de la matriz m,
// que puede contener o no algunos n�meros. Devuelve TRUE si encuentra alguna matriz v�lida,
// pero no devuelve la matriz, sino que se limita a mostrarla en la pantalla
logico generar_matriz(int m[3][3])
{
    int i, j, x;
    logico correcto;
    int nueva[3][3];
    
    if (matriz_completa(m))         // Caso base: la matriz est� completa
    {
        correcto = comprobar_matriz(m);
        if (correcto == TRUE) mostrar_matriz(m);
    }
    else                            // Caso general: hay que completarla (faltan n�meros)
    {
        correcto = FALSE;
        // Buscamos primera posici�n a�n no ocupada
        for (i=0; i<3; i++)
        for (j=0; j<3; j++)
        {
                if (m[i][j] == 0)        // Posici�n libre
                {                        // Vamos a probar todos los n�meros        
                     for (x=1; x<=9; x++)
                     {
                          copiar_matriz(m, nueva);
                          nueva[i][j] = x;
                          if (generar_matriz(nueva) == TRUE)
                          {
                             correcto = TRUE;
                             break;
                          }
                     }
                }
        }
    }
    
    return correcto;
}   
    
    

