// Fundamentos de programación 1º ASI
// Ejercicios de RECURSIVIDAD del TEMA 8

// Mergesort

#include <stdio.h>
#include <stdlib.h>

#define TAM 10

void ordenar(int v[TAM], int inf, int sup);
void mezclar(int v[TAM], int inf, int med, int sup);

int main(void)
{
    int i,b,e;
    long t;
    int v[TAM];
    int maximo, minimo, suma;
    float media;
    
    printf("Ordenación por métodos recursivos: MERGESORT\n\n");
    
    printf("Generando un vector aleatorio de %i elementos...\n", TAM);
    t = time(NULL);
    srand(t);
    for (i=0; i<TAM; i++)
    {
        v[i] = rand()%20;
        printf("%i - ", v[i]);
    }
    printf("\n");
    
    printf("\nOrdenando...");
    ordenar(v, 0, TAM-1);
    
    printf("\n\nVector ordenado. Ha quedado así:\n");
    for (i=0; i<TAM; i++)
        printf("%i - ", v[i]);
    printf("\n");

    system("PAUSE");
    
    return 0;
}


void ordenar(int v[TAM], int inf, int sup)
{
    int aux, med;
    
    if (sup == inf)
        return;
        
    if (sup - inf == 1)
        return;
        
    if (sup - inf == 2)
    {
        if (v[sup] < v[inf])
        {
                aux = v[sup];
                v[sup] = v[inf];
                v[inf] = aux;
        }
    }
    else
    {
        med = (inf + sup) / 2;
        ordenar(v, inf, med);
        ordenar(v, med, sup);
        mezclar(v, inf, med, sup);
    }
}
    
    
void mezclar(int v[TAM], int inf, int med, int sup)
{
    int salir = 0;
    int aux, i = 0;
    
    while (!salir)
    {
        if ((inf+i >= med) || (med+i >= sup))
           salir = 1;
        else if (v[inf+i] > v[med+i])
        {
           aux = v[inf+i];
           v[inf+i] = v[med+i];
           v[med+i] = aux;
        }
        i++;
    }
}


