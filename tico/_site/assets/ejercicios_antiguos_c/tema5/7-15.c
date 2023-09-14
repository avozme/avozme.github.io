/* IMPLEMENTACION DE UNA LISTA ENLAZADA SIMPLE (ABIERTA) */
#include <stdio.h>

#define TIPO char	// cambiando esto podemos modificar el tipo de los datos de la lista

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



int main(void)
{
   struct s_nodo *lista = NULL;
   FILE *f;
   char c;
   int i;

   // Leemos los caracteres y los insertamos en la lista
   printf("Introduzca un texto (pulse # para terminar)");
   do {
      c = getchar();
      if (c != '#') insertar(&lista, c);
   }
   while (c != '#');

   // Guardamos la lista en un archivo de texto
   f = fopen("7-15.txt", "rw");
   if (f == NULL) { printf("No puedo crear el archivo"); exit(-1); }
   
   for (i=1; i <= contar_nodos(lista); i++) {
      buscar_por_posicion(lista, i, &c);
      fputc(c, f);
   }
   fclose(f);

   // Destruimos la lista para liberar la memoria
   borrar_todos(&lista);

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
