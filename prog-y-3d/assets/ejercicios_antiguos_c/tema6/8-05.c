// Fundamentos de programación 1º ASI
// Ejercicios de RECURSIVIDAD del TEMA 8

// Operaciones con vectores

#include <stdio.h>
#include <stdlib.h>

#define TAM 10

int calcula_maximo(int v[TAM], int max, int pos);
int calcula_minimo(int v[TAM], int min, int pos);
int calcula_suma(int v[TAM], int pos);
float calcula_media(int v[TAM], int pos);

int main(void)
{
    int i,b,e;
    long t;
    int v[TAM];
    int maximo, minimo, suma;
    float media;
    
    printf("Cálculos recursivo con un vector\n\n");
    
    printf("Generando un vector aleatorio de %i elementos...\n", TAM);
    t = time(NULL);
    srand(t);
    for (i=0; i<TAM; i++)
    {
        v[i] = rand()%20;
        printf("%i - ", v[i]);
    }
    printf("\n");
    
    maximo = calcula_maximo(v, -99999, 0);
    minimo = calcula_minimo(v, 99999, 0);
    suma = calcula_suma(v, 0);
    media = calcula_media(v, 0);
    
    printf("Máximo = %i, Mínimo = %i\n", maximo, minimo);
    printf("Suma = %i, Media = %.2f\n", suma, media);
    system("PAUSE");
    
    return 0;
}


int calcula_maximo(int v[TAM], int max, int pos)
{
    int r;
    
    if (v[pos] > max) max = v[pos];
    if (pos == TAM-1)
        r = max;
    else
        r = calcula_maximo(v, max, pos+1);
    
    return r;
}

int calcula_minimo(int v[TAM], int min, int pos)
{
    int r;
    
    if (v[pos] < min) min = v[pos];
    if (pos == TAM-1)
        r = min;
    else
        r = calcula_minimo(v, min, pos+1);
    
    return r;
}


int calcula_suma(int v[TAM], int pos)
{
    int r;
    
    if (pos == TAM-1)
        r = v[pos];
    else
        r = v[pos] + calcula_suma(v, pos+1);

    return r;
}


float calcula_media(int v[TAM], int pos)
{
    float r;
    
    if (pos == TAM-1)
        r = (float)v[pos]/TAM;
    else
        r = ((float)v[pos]/TAM) + calcula_media(v, pos+1);

    return r;
}


