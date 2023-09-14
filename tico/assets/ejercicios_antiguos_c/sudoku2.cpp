// Generador de Sudokus
// Versión completa: genera las matrices de 9x9

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define COMPLETA_Y_CORRECTA 1      // Estados posibles de la matriz del sudoku
#define INCOMPLETA 2
#define INCORRECTA 3
#define SIN_SOLUCION -1

void inicializar_matriz(int m[9][9]);
int comprobar_matriz_9x9(int m[9][9]);
int comprobar_submatriz_3x3(int m[9][9], int i_ini, int j_ini);
int generar_matriz(int m[9][9]);
void copiar_matriz(int orig[9][9], int dest[9][9]);
void mostrar_matriz(int m[9][9]);

long exploraciones = 0;
long soluciones = 0;

int main(void)
{
    int estado;
    long t1, t2;
    // Vamos a inicializar la matriz del sudoku con algunos números como punto de partida.
    // Estos números se pueden cambiar para generar otros sudokus distintos
    // Cuantos más números iniciales se inserten, más rápido se hallará la solución,
    // pero también aumenta la probabilidad de que no exista ninguna solución.
    int m[9][9] = { 0, 0, 4,   7, 0, 0,   8, 2, 0,
                    0, 0, 0,   0, 4, 0,   0, 0, 0,
                    0, 7, 0,   9, 0, 6,   0, 0, 0,
                    
                    0, 5, 6,   0, 0, 0,   7, 8, 0,
                    0, 0, 7,   6, 0, 4,   1, 0, 0,
                    0, 9, 3,   0, 0, 0,   2, 5, 0,
                    
                    0, 0, 0,   5, 0, 7,   0, 4, 0,
                    0, 4, 0,   0, 1, 0,   9, 0, 0,
                    0, 3, 9,   0, 0, 8,   0, 0, 0    };

    printf("GENERADOR DE SUDOKUS\n");
    printf("Parte 2: generador de matrices de 9x9\n\n");
    printf("Matriz inicial:\n");
    inicializar_matriz(m);           
    printf("\nBuscando soluciones...\n");
    t1 = time(NULL);
    generar_matriz(m);               // Genera matriz 9x9
    t2 = time(NULL);
    printf("Posibilidades exploradas: %li\nSoluciones encontradas: %li.\nTiempo invertido: %li segundos\n", exploraciones, soluciones, t2-t1);
    system("PAUSE");
    return 0;
}


void inicializar_matriz(int m[9][9])
{
    int i, j;
    int aux[9][9];
    
//    for (i=0; i<9; i++)     // Inicializar a cero
//    for (j=0; j<9; j++)
//        m[i][j] = 0;

    // Permutamos filas por columnas
    // Esto es debido a que estamos considerando que el primer índice es la columna y segundo la fila
    // pero al inicializar la matriz, C lo interpreta al revés
    copiar_matriz(m, aux);
    for (i=0; i<9; i++)
    for (j=0; j<9; j++)
        m[i][j] = aux[j][i];
        
    mostrar_matriz(m);
        
}


// Comprueba si la matriz completa de 9x9 es válida para el Sudoku
int comprobar_matriz_9x9(int m[9][9])
{
    int i, j, pos;
    int i_ini, j_ini;
    int v[10];
    int estado = COMPLETA_Y_CORRECTA;
    
    // PASO 1: comprobar que cada submatriz de 3x3 es válida en sí misma
    i_ini = 0;
    while ((estado == COMPLETA_Y_CORRECTA) && (i_ini < 9))
    {
       j_ini = 0;
       while ((estado == COMPLETA_Y_CORRECTA) && (j_ini < 9))
       {
           estado = comprobar_submatriz_3x3(m, i_ini, j_ini);
           j_ini = j_ini + 3;
       }
       i_ini = i_ini + 3;
    }
    
    // PASO 2: comprobar que en cada fila de la matriz 9x9 no se repite ningún número
    if (estado != INCORRECTA)
    {
       j = 0;
       while ((estado != INCORRECTA) && (j < 9))
       {
          for (i=0; i<10; i++) v[i] = 0;       // Ponemos a 0 el vector de comprobación
          i = 0;                               // Vamos a recorrer la fila j buscando números repetidos
          while ((estado != INCORRECTA) && (i < 9))
          {
              pos = m[i][j];
              if (v[pos] == 1) {
                 if ((pos == 0) && (estado != INCORRECTA)) estado = INCOMPLETA;  // Si el nº repetido es el cero
                 if (pos != 0) estado = INCORRECTA;           // Si el nº repetido es cualquier otro
              }
              v[pos] = 1;
              i++;
          }
          j++;
       }
    }
    if ((v[0] != 0) && (estado != INCORRECTA)) estado = INCOMPLETA;
    
    // PASO 3: comprobar que en cada columna de la matriz 9x9 no se repite ningún número
    if (estado != INCORRECTA)
    {
       i = 0;
       while ((estado != INCORRECTA) && (i < 9))
       {
          for (j=0; j<10; j++) v[j] = 0;       // Ponemos a 0 el vector de comprobación
          j = 0;                               // Vamos a recorrer la columna i buscando números repetidos
          while ((estado != INCORRECTA) && (j < 9))
          {
              pos = m[i][j];
              if (v[pos] == 1) {
                 if ((pos == 0) && (estado != INCORRECTA)) estado = INCOMPLETA;  // Si el nº repetido es el cero
                 if (pos != 0) estado = INCORRECTA;           // Si el nº repetido es cualquier otro
              }
              v[pos] = 1;
              j++;
          }
          i++;
       }
    }
    if ((v[0] != 0) && (estado != INCORRECTA)) estado = INCOMPLETA;

    return estado;
}


// Comprueba si una submatriz de 3x3 es válida para el Sudoku
int comprobar_submatriz_3x3(int m[9][9], int i_ini, int j_ini)
{
    int estado = COMPLETA_Y_CORRECTA;
    int v[10], i, j, n;
    
    // Cada submatriz de 3x3 será válida si en sus 9 posiciones están los 9 números, es decir,
    // si no hay ninguno repetido. Pondremos a 1 una posición del vector v[]
    // para cada número encontrado en la matriz.
    for (i=0; i<10; i++) v[i] = 0;
    
    for (i=i_ini; i<i_ini+3; i++)
    for (j=j_ini; j<j_ini+3; j++)
    {
        n = m[i][j];
        if (v[n] == 1)    // Hemos encontrado un número repetido (v[i] ya valía 1)
        {
           if ((n == 0) && (estado != INCORRECTA)) estado = INCOMPLETA;
           if (n!=0) estado = INCORRECTA;
        }
        v[n] = 1;
    }
    
    return estado;
}


// Copia el contenido de la matriz "orig" en la matriz "dest"   
void copiar_matriz(int orig[9][9], int dest[9][9])
{
    int i,j;
    for (i=0; i<9; i++)
    for (j=0; j<9; j++)
        dest[i][j] = orig[i][j];
}

// Muestra por pantalla el contenido de la matriz m
void mostrar_matriz(int m[9][9])
{
    int i,j;
 
    printf("\n");
    printf(" +-----------+-----------+-----------+\n");
    for (j=0; j<9; j++)
    {
      printf(" | ");
      for (i=0; i<9; i++)
      {
        printf("%3i", m[i][j]);
        if ((i+1)%3 == 0) printf(" | ");
      }
      printf("\n");
      if ((j+1)%3 == 0) printf(" +-----------+-----------+-----------+\n");
    }
}


// Genera recursivamente una matriz 9x9 válida para el sudoku, partiendo de la matriz m,
// que puede contener o no algunos números
int generar_matriz(int m[9][9])
{
    int i, j, x;
    int estado_matriz;
    int nueva[9][9];
    int incorrectos;                           // Cuenta estados incorrectos
    
    estado_matriz = comprobar_matriz_9x9(m);
    exploraciones++;                           // Contamos en nº de exploraciones realizadas
    
    if (estado_matriz == COMPLETA_Y_CORRECTA)  // Caso base 1: la matriz está completa y es correcta
    {
        soluciones++;
        printf("\nSolucion n. %li\n", soluciones);
        mostrar_matriz(m);
    }
    if (estado_matriz == INCORRECTA)           // Caso base 2: matriz incorrecta (no seguir por esta rama)
    {
        // mostrar_matriz(m);                  // Sólo para depuración
    }
    if (estado_matriz == INCOMPLETA)           // Caso general: la matriz aún es correcta y 
    {                                          // hay que completarla (faltan números)
        for (i=0; i<9; i++)
        for (j=0; j<9; j++)
        {
                if (m[i][j] == 0)        // Localizada una posición desocupada
                {                        // Vamos a probar todos los números        
                     incorrectos = 0;
                     for (x=1; x<=9; x++)
                     {
                          copiar_matriz(m, nueva);
                          nueva[i][j] = x;
                          estado_matriz = generar_matriz(nueva);
                          if (estado_matriz == INCORRECTA)
                              incorrectos++;
                     }
                     if (incorrectos == 9)
                        return INCORRECTA;
                }
        }
    }
    
    return estado_matriz;
}   
    
    

