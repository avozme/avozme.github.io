// Generador de Sudokus
// Versión básica: genera sólo las matrices de 3x3

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TRUE 1
#define FALSE 0
#define FIJOS 2     // Cantidad de números fijos en la matriz inicial
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
    printf("MATRIZ INICIAL (con %i números fijados):\n", FIJOS);
    inicializar_matriz(m, FIJOS);   // Inicializa a 0 e inserta FIJOS números al azar
    printf("\nSOLUCIONES:\n");
    generar_matriz(m);               // Genera matriz 3x3
    
    system("PAUSE");
    return 0;
}


// Inicializa una matriz de 3x3 a cero e inserta N números al azar
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
    while (k < n)               // Insertar n números al azar en posiciones también al azar
    {
        do {
           x = rand() % 9 + 1;  // Número al azar, pero que no haya salido antes
        } while (v[x] == 1);
        v[x] = 1;
        do
        {
          i = rand() % 3 + 1;     // Posición al azar
          j = rand() % 3 + 1;
        }
        while (m[i][j] != 0);    // Esa posición ya está ocupada, buscar otra

        m[i][j] = x;             // Insertar nº en la posición    
        k++;
    }
    
    mostrar_matriz(m);
        
}

// Comprueba si una matriz de 3x3 es válida para el Sudoku
logico comprobar_matriz(int m[3][3])
{
    logico correcto = TRUE;
    int v[10], i, j, n;
    
    for (i=0; i<10; i++) v[i] = 0;
    
    // La matriz será válida si en sus 9 posiciones están los 9 números, es decir,
    // si no hay ninguno repetido. Pondremos a 1 una posición del vector v[]
    // para cada número encontrado en la matriz.
    for (i=0; i<3; i++)
    for (j=0; j<3; j++)
    {
        n = m[i][j];
        if (v[n] == 1)    // Hemos encontrado un número repetido (v[i] ya valía 1)
           correcto = FALSE;
        v[n] = 1;
    }
    
    return correcto;
}


// Devuelve TRUE si la matriz está completa, es decir, si tiene números en sus 9 posiciones
logico matriz_completa(int m[3][3])
{
    logico correcto = TRUE;
    int i, j;
    
    // La matriz estará completa si en sus 9 posiciones hay algún número
    for (i=0; i<3; i++)
    for (j=0; j<3; j++)
        if (m[i][j] == 0)    // En esta posición no hay ningún número aún
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


// Genera recursivamente una matriz 3x3 válida para el sudoku, partiendo de la matriz m,
// que puede contener o no algunos números. Devuelve TRUE si encuentra alguna matriz válida,
// pero no devuelve la matriz, sino que se limita a mostrarla en la pantalla
logico generar_matriz(int m[3][3])
{
    int i, j, x;
    logico correcto;
    int nueva[3][3];
    
    if (matriz_completa(m))         // Caso base: la matriz está completa
    {
        correcto = comprobar_matriz(m);
        if (correcto == TRUE) mostrar_matriz(m);
    }
    else                            // Caso general: hay que completarla (faltan números)
    {
        correcto = FALSE;
        // Buscamos primera posición aún no ocupada
        for (i=0; i<3; i++)
        for (j=0; j<3; j++)
        {
                if (m[i][j] == 0)        // Posición libre
                {                        // Vamos a probar todos los números        
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
    
    

