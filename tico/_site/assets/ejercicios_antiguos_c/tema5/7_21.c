#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_NODOS 1000000L

struct s_nodo
{
  long int dato;
  struct s_nodo *izq, *der;
};
typedef struct s_nodo t_nodo;


void insertar(t_nodo** nodo, t_nodo** padre, long int n);
void buscar(t_nodo* nodo, long int n, int prof);
void destruir_arbol(t_nodo* nodo);


int main(void)
{
  long int i,v,t;
  char aux[50];
  int n;
  t_nodo* raiz;
  
  raiz = NULL;	// Árbol vacío
  
  printf("Generando un árbol de %li de nodos...\n", NUM_NODOS);
  t = time(NULL);
  srand(t);
  for (i=1; i<=NUM_NODOS; i++)
  {
     v = rand()%100000000L;
     insertar(&raiz, NULL, v);
  }
  if (raiz == NULL) printf("Raiz NULL\n"); else printf("Raiz = %li\n", raiz->dato);
  
  do
  {
     printf("Introduzca nº que quiere buscar: ");
     gets(aux); n = atoi(aux);
  
     if (n >= 0) buscar(raiz, n, 0);
  }
  while (n>=0);
  
  printf("Destruyendo el árbol...\n");
  destruir_arbol(raiz);
  return 0;
}



void insertar(t_nodo** nodo, t_nodo** padre, long int n)
{
  if (*nodo == NULL)
  {
     *nodo = (t_nodo*) malloc(sizeof(t_nodo));
     if (!nodo) {
        printf("Error de asignación de memoria\n");
	    exit(-1);
     }
     (*nodo)->dato = n;
     (*nodo)->izq = NULL;
     (*nodo)->der = NULL;
     if (padre!=NULL)
     {
         if (n > (*padre)->dato) (*padre)->der = *nodo;
	     else (*padre)->izq = *nodo;
     }
  }
  else
  {
     if (n > (*nodo)->dato) insertar(&(*nodo)->der, nodo, n);
     else insertar(&(*nodo)->izq, nodo, n);
  }
}


void buscar(t_nodo* nodo, long int n, int prof)
{
   if (nodo == NULL) {
      printf("Nodo no encontado. prof = %i\n", prof);
      return;
   }
   printf("buscando en nodo %li\n", nodo->dato);
   if (nodo->dato == n) {
      printf("NODO ENCONTRADO. Nodos visitados durante la búsqueda = %i\n", prof);
      return;
   }
   if (nodo->dato > n)
      buscar(nodo->izq, n, prof+1);
   if (nodo->dato < n)
      buscar(nodo->der, n, prof+1);
}


void destruir_arbol(t_nodo* nodo)
{
   if (nodo == NULL) return;
   destruir_arbol(nodo->izq);
   destruir_arbol(nodo->der);
   free(nodo);
}
