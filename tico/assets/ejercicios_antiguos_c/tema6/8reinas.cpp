// Algoritmo de las 8 reinas
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int ocho_reinas(int damas[8], int i);
int posicion_valida(int damas[8], int i);

int main(void)
{
    int damas[8], solucion, i;
    
    printf("Algoritmo de las 8 reinas\n");
    printf("Voy a colocar 8 reinas en un tablero de ajedrez\n");
    for (i=0; i<8; i++)        // Inicializamos las posiciones a -1
           damas[i] = -1;
    
    solucion = ocho_reinas(damas, 0);
    
    if (solucion == 1)        // Mostramos la solución encontrada
    {
        for (i=0; i<8; i++)
                printf("Reina nº %i - Fila %i - Columna %i\n", i, i, damas[i]);
    }
    else
        printf("No se encontró ninguna solución!!!\n");                
    
    system("PAUSE");
    return 0;
}


int ocho_reinas(int damas[8], int i)
{
    int solucion;
    
    if (i == 8)
        solucion = 1;
    else
    {
        solucion = 0;
        do
        {
                damas[i] = damas[i] + 1;
                //printf("Probando dama %i en columna %i - ", i, damas[i]);
                if (posicion_valida(damas, i) == 1)
                {
                    // Hemos dado con una solución parcial válida. Vamos a continuar
                    //printf("OK\n");
                    solucion = ocho_reinas(damas, i+1);
                }
                //else
                    //printf("fallo\n");
        } while ((solucion == 0) && (damas[i] < 7));
        if (solucion == 0) damas[i] = -1;
    }
    return solucion;
}


// Comprueba si una solución parcial es válida
// Sólo hay que comprobar la columna y las diagonales
int posicion_valida(int damas[8], int i)
{
    int j, valida;
    
    valida = 1;
    for (j = 0; j < i; j++)
    {
        // No es atacada en la columna
        valida = valida && (damas[i] != damas[j]);
        // No es atacada en una diagonal
        valida = valida && ((abs(i-j)) != (abs(damas[i]-damas[j])));
    }
    return valida;
}
