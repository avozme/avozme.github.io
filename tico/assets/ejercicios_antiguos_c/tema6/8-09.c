// Fundamentos de programaci�n 1� ASI
// Ejercicios de RECURSIVIDAD del TEMA 8

#include <stdio.h>
#include <stdlib.h>

#define TAM 100

struct s_nodo
{
    long dato;
    struct s_nodo *hijo_izq, *hijo_der;
};


void insertar(struct s_nodo **nodo, struct s_nodo **padre, long dato);
void inorden(struct s_nodo *nodo);
void mostrar_hojas(struct s_nodo *nodo);
long int sumar_nodos(struct s_nodo *nodo);
int completo(struct s_nodo *nodo);

int main(void)
{
    struct s_nodo *raiz = NULL;
    long n, t1, t2;
    int i, prof;

    printf("Varios ejemplos de funciones recursivas para �rboles\n\n");
    printf("Generando un �rbol aleatorio de %i elementos...\n", TAM);
    t1 = time(NULL);
    srand(t1);
    
    for (i=1; i<=TAM; i++)
    {
        n = (rand() % TAM*3)+1;
        insertar (&raiz, NULL, n);
    }

    printf("\n\nRecorrido IN-ORDEN del �rbol:\n");
    inorden(raiz);
    
    printf("\n\nLos nodos hoja son:\n");
    mostrar_hojas(raiz);
    
    printf("\n\nSuma de todos los nodos: %li\n", sumar_nodos(raiz));
    
    printf("\n\nProfundidad del �rbol: %i\n", profundidad(raiz, 0));
    
    if (completo(raiz))
        printf("\n\nEl �rbol est� COMPLETO\n\n");
    else
        printf("\n\nEl �rbol est� INCOMPLETO\n\n");
    
    
    system("PAUSE");
    
    return 0;
}


// Inserta un dato en el �rbol manteni�ndolo ordenado
void insertar(struct s_nodo** nodo, struct s_nodo** padre, long int n)
{
  if (*nodo == NULL)
  {
     *nodo = (struct s_nodo*) malloc(sizeof(struct s_nodo));
     if (!nodo) {
        printf("Error de asignaci� de memoria\n");
	    exit(-1);
     }
     (*nodo)->dato = n;
     (*nodo)->hijo_izq = NULL;
     (*nodo)->hijo_der = NULL;
     if (padre!=NULL)
     {
         if (n > (*padre)->dato) (*padre)->hijo_der = *nodo;
	     else (*padre)->hijo_izq = *nodo;
     }
  }
  else
  {
     if (n > (*nodo)->dato) insertar(&(*nodo)->hijo_der, nodo, n);
     else insertar(&(*nodo)->hijo_izq, nodo, n);
  }
}


// Recorre el �rbol en orden, mostrando el contenido de los nodos
void inorden(struct s_nodo *nodo)
{
    if (nodo != NULL)
    {
        inorden(nodo->hijo_izq);
        printf("%i - ", nodo->dato);
        inorden(nodo->hijo_der);
    }
}


// Recorre el �rbol mostrando s�lo el contenido de los nodos-hoja
void mostrar_hojas(struct s_nodo *nodo)
{
    if ((nodo->hijo_der == NULL) && (nodo->hijo_izq == NULL))  // Es una hoja
    {
        printf("%i - ", nodo->dato);
    }
    else    // No es una hoja: continuar el recorrido
    {   
        if (nodo->hijo_izq != NULL)
           mostrar_hojas(nodo->hijo_izq);
        if (nodo->hijo_der != NULL)
           mostrar_hojas(nodo->hijo_der);
    }    
}


// Suma el contenido de todos los nodos del �rbol
long int sumar_nodos(struct s_nodo *nodo)
{
    if (nodo != NULL)
        return nodo->dato + sumar_nodos(nodo->hijo_der) + sumar_nodos(nodo->hijo_izq);
    else
        return 0;
}


// Calcula la profundidad m�xima del �rbol (p)
int profundidad(struct s_nodo *nodo, int p)
{
    int p_izq, p_der, prof;
    
    if (nodo != NULL)
    {
        // Profundidad del sub�rbol izquierdo
        p_izq = profundidad(nodo->hijo_izq, p+1);
        // Profundidad del sub�rbol derecho
        p_der = profundidad(nodo->hijo_der, p+1);
        // La profundidad m�xima ser� la mayor entre p_izq y p_der
        if (p_izq > p_der)
                prof = p_izq;
        else
                prof = p_der;
    }
    else  // Si nodo == NULL, ya no hay m�s nodos, as� que la profundidad es p
        prof = p;
        
    return prof;
}


// Decide si el �rbol est� completo o no
int completo(struct s_nodo *nodo)
{
    int c;
    
    if (nodo != NULL)
    {
        if ((nodo->hijo_izq != NULL) && (nodo->hijo_der != NULL))
                // Nodo con DOS hijos. Estar� completo si sus dos sub�rboles tambi�n lo est�n
                c = 1 && completo(nodo->hijo_izq) && completo(nodo->hijo_der);
        else if ((nodo->hijo_izq == NULL) && (nodo->hijo_der == NULL))
                // Nodo con CERO hijos. Est� completo por definici�n
                c = 1;
        else    // Nodo con UN hijo. No est� completo por definici�n
                c = 0;
    }
    else        // Si nodo == NULL, este sub�rbol s� est� completo (porque est� vac�o)
        c = 1;
    
    return c;                
    
}
