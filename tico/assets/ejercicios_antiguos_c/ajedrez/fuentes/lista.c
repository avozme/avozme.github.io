/*
PROGRAMA:  Ajedrez 1.0
ARCHIVO:   ajedrez.c
CONTENIDO: Lista enlazada din�mica (para guardar los movimientos)
AUTOR:     Alfredo Moreno
*/

#include "lista.h"

struct s_nodo* primero; // Puntero al primer elemento de la lista
struct s_nodo* ultimo;   // Puntero al �ltimo elemento de la lista


// Inicializar la lista
void lst_inicializar(void)
{
   primero = NULL;
   ultimo = NULL;
}

// Finalizar la lista (liberar memoria)
void lst_finalizar(void)
{
   struct s_nodo *nodo, *siguiente;
   
   nodo = primero;
   while (nodo != NULL)
   {
      siguiente = nodo->sig;
      free(nodo);
      nodo = siguiente;
   }
}
      
// Insertar un nodo nuevo
void lst_insertar(char* mov, char color)
{
   struct s_nodo *nuevo;
   
   // Creamos un nodo nuevo
   nuevo = (struct s_nodo*) malloc(sizeof(struct s_nodo));
   if (!nuevo)
   {
      escribir("Error de asignaci�n",1,TXT_RESALTADO);
      escribir("de memoria",1,TXT_RESALTADO);
      pausa(2000);
   }
   else  
   {
      // Primero introducimos los datos en el nodo nuevo
      // Nos aseguramos de que la cadena no se vaya a desbordar
      if (strlen(mov) > 6) mov[6] = '\0';
      strcpy(nuevo->mov, mov);
      nuevo->color = color;
      nuevo->sig = NULL;
      if (ultimo == NULL)                   // Insertar n�mero de movimiento
         nuevo->n_mov = 1;
      else
         nuevo->n_mov = ultimo->n_mov + 1;
      // Ahora enlazamos el nodo nuevo al final de la lista
      if (ultimo == NULL) {   // La lista a�n est� vac�a
         primero = nuevo;
         ultimo = nuevo;
      }
      else {                  // La lista ya tiene elementos
         ultimo->sig = nuevo; // Enlazamos el �ltimo (que ahora ser� pen�ltimo)
         ultimo = nuevo;
      }
   }
}

// Buscar un nodo por el n�mero de turno. Devuelve el movimiento almacenado en el nodo
char* lst_buscar(int num)
{
   struct s_nodo *nodo;
   char *texto;
   
   texto = NULL;
   nodo = primero;
   while (nodo != NULL)
   {
      if (nodo->n_mov == num) {
         texto = nodo->mov;
         nodo = NULL;
      }
      else
         nodo = nodo->sig;
   }
   return texto;
}


// Devuelve VERDADERO si la lista est� vac�a
int lst_es_vacia(void)
{
   if (primero == NULL) return VERDADERO; 
   else return FALSO;
}


// Devuelve el n�mero de nodos de la lista
int lst_num_elementos(void)
{
   if (ultimo != NULL) return ultimo->n_mov;
   else return 0;
}
