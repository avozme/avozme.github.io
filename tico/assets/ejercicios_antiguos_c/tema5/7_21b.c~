
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_NODOS 1000000L
#define TIPO long	// cambiando esto podemos modificar el tipo de los datos de la lista

struct s_nodo
{
   TIPO dato;
   struct s_nodo *siguiente;
};

void insertar(struct s_nodo **primero, TIPO dato);
int buscar_por_contenido(struct s_nodo *primero, TIPO dato);
void borrar_todos(struct s_nodo **primero);

int main(void)
{
  long int i,v,t;
  char aux[50];
  int n;
  struct s_nodo* lista;
  
  lista = NULL;	// Lista vacia
  
  printf("Generando una lista abierta de %li de nodos...\n", NUM_NODOS);
  t = time(NULL);
  srand(t);
  for (i=1; i<=NUM_NODOS; i++)
  {
     v = rand()%100000000L;
     insertar(&lista, v);
  }
  if (lista == NULL) printf("Error al crear la lista\n");
  
  do
  {
     printf("Introduzca nº que quiere buscar: ");
     gets(aux); n = atoi(aux);
  
     if (n >= 0) buscar_por_contenido(lista, n);
  }
  while (n>=0);
  
  printf("Destruyendo la lista...\n");
  borrar_todos(&lista);
  return 0;
}
	 
	   




void insertar(struct s_nodo **primero, TIPO dato)
{
   struct s_nodo *nuevo;
   
   nuevo = (TIPO*) malloc (sizeof(TIPO));
   nuevo->dato = dato;
   nuevo->siguiente = *primero;
   *primero = nuevo;
}


int buscar_por_contenido(struct s_nodo *primero, TIPO dato)
{
   struct s_nodo *nodo;
   long pos = 0, encontrado = 0;
   
   nodo = primero;
   while ((nodo != NULL) && (encontrado == 0))
   {
      pos++;
      printf("buscando en nodo %li\n", nodo->dato);
      if (nodo->dato == dato)
         encontrado = 1;
      nodo = nodo->siguiente;
   }
   
   if (encontrado == 0)
      printf("Nodo no encontrado\n");
   else
      printf("Dato encontrado. Nodos visitados durante la búsqueda: %li\n", pos);
      

}


void borrar_todos(struct s_nodo **primero)
{
   struct s_nodo *nodo, *sig;
   
   nodo = *primero;
   while (nodo != NULL)
   {
      sig = nodo->siguiente;
      free(nodo);
      nodo = sig;
   }

   *primero = NULL;
}
   


