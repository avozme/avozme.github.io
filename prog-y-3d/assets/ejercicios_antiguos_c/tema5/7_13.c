#include <stdio.h>
#include <stdlib.h>

struct s_nodo
{
   int dato;
   struct s_nodo* siguiente;
};
typedef struct s_nodo t_nodo;

void insertar(t_nodo **primero, int v) ;
int borrar(t_nodo **primero, int v) ;
int buscar (t_nodo* primero, int pos);

int main(void)
{
   t_nodo *lista;
   int v;
   
   insertar(&lista, 5);
   insertar(&lista, 7);
   insertar(&lista, 9);
   
   v = buscar(lista, 2);
   printf("I = 2, valor = %i\n", v);
   borrar(&lista, 7);
   v = buscar(lista, 2);
   printf("I = 2, valor = %i\n", v);

   getchar();
}

void insertar(t_nodo **primero, int v) 
{
   t_nodo* nuevo;
 
   nuevo = (t_nodo*)malloc(sizeof(t_nodo));	// Creamos nodo nuevo
   nuevo->dato = v;		// Le asignamos el dato
   nuevo->siguiente = *primero;               // El primero pasará a ser el segundo
   *primero = nuevo;		// Y el nuevo pasará a ser el primero
}

int borrar(t_nodo **primero, int v) 
{
   t_nodo *anterior, *aux;
   int borrado = -1;	// Marca de "no borrado"
   
   // Primera parte: buscar el nodo anterior al que vamos a borrar
   // El que vamos a borrar se distingue porque contiene el dato "v"
   anterior = *primero;
   while (anterior != NULL)
   {
      aux = anterior->siguiente;
      if ((aux != NULL) && (aux->dato == v))
         break;			// aux es el nodo que queremos eliminar
      anterior = anterior->siguiente;
   }

   // Segunda parte: borrar el nodo siguiente y reasignar los punteros
   // Comprobamos que hemos encontrado el nodo que deseamos eliminar (aux)
   if ((anterior != NULL) && (aux != NULL)) 
   {
      anterior->siguiente = aux->siguiente;      // Reasignamos los enlaces
      free(aux);                                 // Eliminamos el nodo
      borrado = 1;		            // Marca de "borrado realizado"	
   }

   return borrado;
}

int buscar (t_nodo* primero, int pos)
{
   int cont, valor;
   t_nodo* nodo;

   nodo = primero;	// Nos situamos en el primer elemento
   cont = 1;	// Ponemos el contador a su valor inicial
   while ((cont<pos) && (nodo != NULL))	// Repetir hasta encontrar nodo o terminar lista
   {
      nodo = nodo->siguiente;	// Pasamos al nodo siguiente
      cont++;	// Actualizamos el contador de nodos
   }

   if (cont == pos)	// Hemos encontrado el elemento buscado
       valor = nodo->dato;
   else	// No hemos encontrado el elemento
       valor = -1;

   return valor;
} 

