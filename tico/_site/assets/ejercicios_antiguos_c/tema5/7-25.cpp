#include <stdio.h>
#include <stdlib.h>

struct s_nodo
{
    long dato;
    struct s_nodo *hijo_izq, *hijo_der;
};


int main(void)
{
    struct s_nodo *raiz = NULL;
    
    long n, t1, t2;
    int i, prof;
    
    printf("Generando el árbol...\n");
    t1 = time(NULL);
    srand(t1);
    
    for (i=1; i<=100000; i++)
    {
        n = (rand() % 1000000)+1;
        insertar (&raiz, n);
    }
    
    printf("¿Qué número quieres buscar?\n");
    scanf("%li", &n);
    
    t1 = time(NULL);
    prof = buscar(raiz, n);
    t2 = time(NULL);
    
    if (prof == 0)
        printf("Ese número no está en el árbol\n");
    else
        printf("Número localizado en el nivel %i\n", prof);
    
    printf("Tiempo de búsqueda: %li\n", t2-t1);
    
    system("PAUSE");
    return 0;
    
}


void insertar(struct s_nodo **nodo, struct s_nodo **padre, long dato)
{
    struct s_nodo *nuevo;
    
    if (*nodo == NULL)
    {
        nuevo = (struct s_nodo*) malloc(sizeof(struct s_nodo));
        if (nuevo == NULL)
        {
                printf("ERROR DE ASIGNACIÓN DE MEMORIA\n");
                exit(-1);
        }
        nuevo->dato = dato;
        nuevo->hijo_izq = NULL;
        nuevo->hijo_der = NULL;
        if (dato > (*padre)->dato)
                (*padre)->hijo
}
