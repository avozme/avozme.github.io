#include <stdio.h>
#include <stdlib.h>

struct s_nodo 
{
   int dato;
   struct s_nodo *siguiente;
};
typedef struct s_nodo t_nodo;


void insertar(t_nodo **primero, t_nodo **ultimo, int v) ;
int leer(t_nodo **primero, t_nodo **ultimo) ;

int main(void)
{
   t_nodo *cabeza, *cola;
   cabeza = NULL; cola = NULL;
   int v;
   
   insertar(&cabeza, &cola, 5);
   insertar(&cabeza, &cola, 7);
   insertar(&cabeza, &cola, 9);
   v = leer(&cabeza, &cola);
   printf("Leido %i\n", v);
   v = leer(&cabeza, &cola);
   printf("Leido %i\n", v);
   v = leer(&cabeza, &cola);
   printf("Leido %i\n", v);
   v = leer(&cabeza, &cola);
   printf("Leido %i\n", v);
   getchar();
   return 0;
}


void insertar(t_nodo **primero, t_nodo **ultimo, int v) 
{
   t_nodo* nuevo;
 
   nuevo = (t_nodo*)malloc(sizeof(t_nodo));	// Creamos el nuevo nodo
   nuevo->dato = v;	// Le asignamos el dato
   nuevo->siguiente = NULL;	// El nuevo nodo apuntará a NULL
   if (*ultimo != NULL) 	// Si la cola no estaba vacía...
       (*ultimo)->siguiente = nuevo;	// ...enganchamos el nuevo al final
   *ultimo = nuevo;	// A partir de ahora, el nuevo será el último
   if (*primero == NULL) 	// Si la cola estaba vacía...
       *primero = nuevo;	// ...el último también será el primero
}

int leer(t_nodo **primero, t_nodo **ultimo) 
{
   t_nodo *aux;	// Puntero auxiliar
   int v;	// Para almacenar el valor del dato y devolverlo
   
   aux = *primero;	// El auxiliar apunta a la cabeza
   if(aux == NULL) 	// La cola está vacía: devolver valor especial
      return -1; 
   *primero = aux->siguiente;	// El primero apunta al segundo
   v = aux->dato; 	// Recoger valor del primero
   free(aux);	// Eliminar el nodo primero
   if (*primero==NULL) 	// Si la cola se ha quedado vacía...
      *ultimo = NULL;	// ...hacer que el último también apunte a NULL
   return v;	// Devolver el dato que había en el primero
}

