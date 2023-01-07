/* IMPLEMENTACION DE UNA LISTA ENLAZADA SIMPLE (ABIERTA) */
#include <stdio.h>

#define TIPO int	// cambiando esto podemos modificar el tipo de los datos de la lista

// Definción de la estructura básica de la lista
struct s_nodo
{
   TIPO dato;
   struct s_nodo *siguiente;
};

// Prototipos de funciones
void inicializar(struct s_nodo **primero);
int esta_vacia(struct s_nodo *primero);
int contar_nodos(struct s_nodo *primero);
void insertar(struct s_nodo **primero, TIPO dato);
int buscar_por_contenido(struct s_nodo *primero, TIPO dato);
int buscar_por_posicion(struct s_nodo *primero, int posic, TIPO *result);
void borrar_primero(struct s_nodo **primero);
void borrar_todos(struct s_nodo **primero);
int borrar_por_posicion(struct s_nodo **primero, int posic);
int borrar_por_contenido(struct s_nodo **primero, TIPO dato);
void mostrar_lista(struct s_nodo *primero);

// Programa de prueba. Este programa sólo sirve para comprobar que las funciones son correctas.
// Sustituyendo este programa por cuaquier otro, las funciones deben ser igualmente correctas.
int main(void)
{
   struct s_nodo *lista;
   int n, r, dato;
   
   printf("\nPROGRAMA DE PRUEBA DE LAS FUNCIONES DE LISTA ENLAZADA\n\n");
   inicializar(&lista);
   
   printf("1. PRUEBA DE LA INSERCION DE DATOS\n");
   printf("Introduzca números enteros (negativo para terminar)\n");
   do
   {
     scanf("%i", &n);
     if (n>0) insertar(&lista, n);
   }
   while (n>=0);
   
   printf("2. PRUEBA DE FUNCIONES GENERALES\n");
   printf("El contenido de la lista es:\n");
   mostrar_lista(lista);
   if (esta_vacia(lista)) 
     printf("La lista está vacía\n");
   else
     printf("La lista tiene %i elementos\n", contar_nodos(lista));
   
   printf("3. PRUEBA DE LAS FUNCIONES DE BÚSQUEDA\n");
   printf("Introduzca un dato para buscarlo: ");
   scanf("%i", &dato);
   r = buscar_por_contenido(lista, dato);
   if (r == 0) 
         printf("No se pudo encontrar el dato %i\n", dato);
   else
         printf("El dato %i está en la posición %i\n", dato, r);
   
   printf("Introduzca una posición: ");
   scanf("%i", &n);
   r = buscar_por_posicion(lista, n, &dato);
   if (r == 0) 
         printf("La posición %i no existe en la lista\n", n);
   else
         printf("En la posición %i se encuenta en número %i\n", n, dato);

   printf("4. PRUEBA DE LAS FUNCIONES DE BORRADO\n");
   printf("Introduzca un dato para borrarlo: ");
   scanf("%i", &dato);
   r = borrar_por_contenido(&lista, dato);
   if (r == 0) 
         printf("No se pudo encontrar el número %i\n", dato);
   else {
         printf("Número borrado. La lista queda así:\n");
         mostrar_lista(lista);
   }
   
   printf("Introduzca una posición para borrarla: ");
   scanf("%i", &n);
   r = borrar_por_posicion(&lista, n);
   if (r == 0) 
         printf("La posición %i no existe en la lista\n", n);
   else {
         printf("Elemento borrado. La lista queda así:\n", n, dato);
         mostrar_lista(lista);
   }
   
   printf("5. PRUEBA DE BORRADO DE TODA LA LISTA\n");
   printf("Borrando toda la lista...\n");
   borrar_todos(&lista);
   printf("Borrado terminado. La lista queda así:\n");
   printf("Número de elementos: %i\n", contar_nodos(lista));
   mostrar_lista(lista);
   
   return 0;
}
	 
	   





void inicializar(struct s_nodo **primero)
{
   *primero = NULL;
}


int esta_vacia(struct s_nodo *primero)
{
   if (primero == NULL)
     return 1;
   else
     return 0;
}


int contar_nodos(struct s_nodo *primero)
{
   int cont = 0;
   struct s_nodo *nodo;
   
   nodo = primero;
   while (nodo != NULL)
   { 
      cont++;
      nodo = nodo->siguiente;
   }
   
   return cont;
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
   int pos = 0, encontrado = 0;
   
   nodo = primero;
   while ((nodo != NULL) && (encontrado == 0))
   {
      pos++;
      if (nodo->dato == dato)
         encontrado = 1;
      nodo = nodo->siguiente;
   }
   
   if (encontrado == 0)
      pos = -1;
      
   return pos;
}


int buscar_por_posicion(struct s_nodo *primero, int posic, TIPO *result)
{
   struct s_nodo *nodo;
   int i = 0, encontrado = 0;
   
   nodo = primero;
   while ((nodo != NULL) && (encontrado == 0))
   {
      i++;
      if (i == posic) {
         encontrado = 1;
	 *result = nodo->dato;
      }
      nodo = nodo->siguiente;
   }
   
   return encontrado;
}


void borrar_primero(struct s_nodo **primero)
{
   struct s_nodo *segundo;
   
   segundo = (*primero)->siguiente;   
   free(primero);
   *primero = segundo;
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
   


int borrar_por_posicion(struct s_nodo **primero, int posic)
{
   struct s_nodo *nodo, *anterior;
   int cont = 0, encontrado = 0;
   
   nodo = *primero;
   anterior = *primero;
   while ((nodo != NULL) && (encontrado == 0))
   {
      cont++;
      if (cont == posic)
      {
         if (nodo == *primero)
	    *primero = (*primero)->siguiente;
	 else
	    anterior->siguiente = nodo->siguiente;
	 free(nodo);
	 encontrado = 1;
      }
      else
      {
         anterior = nodo;
         nodo = nodo->siguiente;
      }
    }
   
   return encontrado;
}



int borrar_por_contenido(struct s_nodo **primero, TIPO dato)
{
   struct s_nodo *nodo, *anterior;
   int encontrado = 0;
   
   nodo = *primero;
   anterior = *primero;
   while ((nodo != NULL) && (encontrado == 0))
   {
      if (nodo->dato == dato)
      {
         if (nodo == *primero)
	    *primero = (*primero)->siguiente;
	 else
	    anterior->siguiente = nodo->siguiente;
	 free(nodo);
	 encontrado = 1;
      }
      else
      {
         anterior = nodo;
         nodo = nodo->siguiente;
      }
   }
   
   return encontrado;
}
   

void mostrar_lista(struct s_nodo *primero)
{
  struct s_nodo *nodo;
  
  nodo = primero;
  while (nodo != NULL)
  {
     printf("%i\n", nodo->dato);		// ESTO HAY QUE CAMBIARLO dependiendo del tipo de los datos
     nodo = nodo->siguiente;
  }
}
