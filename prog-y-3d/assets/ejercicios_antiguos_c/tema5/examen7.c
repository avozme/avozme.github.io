#include <stdio.h>

struct s_nodo {
   int dato;
   struct s_nodo *siguiente;
};

void insertar(struct s_nodo **primero, int dato);
int contar_nodos(struct s_nodo *primero);
void borrar_todos(struct s_nodo **primero);
int borrar_penultimo(struct s_nodo **primero);
void copiar_al_reves(struct s_nodo *primero, struct s_nodo **copia);
void insertar_en_orden(struct s_nodo **primero, int dato);
void mostrar_lista(struct s_nodo *primero);


int main()
{
   struct s_nodo *lista = NULL, *copia = NULL;   
   int i;

   printf("EXAMEN DEL TEMA 7 - EJERCICIO 1\nPROGRAMA DE PRUEBA\n");
   
   printf("\n7.1. Insertar datos\n");
   for (i = 10; i >= 9; i--) insertar(&lista, i*2);
   printf("Contenido de la lista: "); mostrar_lista(lista);
   
   printf("\n7.2. Contar nodos\n");
   printf("Nº elementos: %i\n", contar_nodos(lista));
   
   printf("\n7.4. Eliminar penúltimo\n");
   borrar_penultimo(&lista);
   printf("Contenido de la lista: "); mostrar_lista(lista);
   
   printf("\n7.5. Copiar lista\n");
   copiar_al_reves(lista, &copia);
   printf("Lista original: "); mostrar_lista(lista);
   printf("Copia         : "); mostrar_lista(copia);

   printf("\n7.6. Añadir en orden\n");
   insertar_en_orden(&lista, 7);
   printf("Contenido de la lista: "); mostrar_lista(lista);

   printf("\n7.3. Borrar toda la lista\n");
   borrar_todos(&lista);
   printf("Contenido de la lista: "); mostrar_lista(lista);
   
   return 0;
}
      

void insertar(struct s_nodo **primero, int dato)
{
   struct s_nodo *nuevo;
   
   nuevo = (struct s_nodo*) malloc(sizeof(struct s_nodo*));
   nuevo->dato = dato;
   nuevo->siguiente = *primero;
   *primero = nuevo;
}

int contar_nodos(struct s_nodo *primero)
{
   int cont;
   struct s_nodo *nodo;
   
   nodo = primero;
   cont = 0;
   while (nodo != NULL) {
      cont++;
      nodo = nodo->siguiente;
   }
   
   return cont;
}


void borrar_todos(struct s_nodo **primero)
{
   struct s_nodo *aux;
   
   aux = *primero;
   while (aux != NULL) {
      *primero = aux->siguiente;
      free(aux);
      aux = *primero;
   }
}


int borrar_penultimo(struct s_nodo **primero)
{
   struct s_nodo *nodo, *penultimo;
   int n, cont, borrado;
   
   // Utilizaremos la función "contar_nodos()" para saber cuantos nodos tiene la lista (n)
   // Luego la recorreremos hasta N-2 y borraremos ese nodo, que debe ser el penúltimo
   n = contar_nodos(*primero);
   cont = 0;
   borrado = 0;
   nodo = *primero;
   while (nodo != NULL) {
      cont++;
      if (cont == n-2) 	// nodo->siguiente es el penúltimo. Vamos a borrarlo
      {
          penultimo = nodo->siguiente;
          nodo->siguiente = penultimo->siguiente;
	  free(penultimo);
	  borrado = 1;
      }
      nodo = nodo->siguiente;
   }
   
   return borrado;	// Devolvemos 1 si se ha borrado el penúltimo, 0 en otro caso
}


void copiar_al_reves(struct s_nodo *primero, struct s_nodo **copia)
{
    int n, i, cont;
    struct s_nodo *nodo;
    
    n = contar_nodos(primero);
    for (i = 1; i <= n; i++)	// Repetimos tantas veces como nodos tenga la lista
    {
       nodo = primero;
       cont = 0;
       while (nodo != NULL)	// Recorremos la lista buscando el nodo i-ésimo
       {
           cont++;
	   if (cont == i)	// Hemos encontrado el nodo que ocupa la posición i. Lo insertamos en la copia.
	      insertar(copia, nodo->dato);
	   
	   nodo = nodo->siguiente;
       }
    }
}


void insertar_en_orden(struct s_nodo **primero, int dato)
{
    struct s_nodo *nodo, *anterior, *nuevo;
    int insertado;
    
    insertado = 0;
    nodo = *primero;	// El nodo que estamos procesando
    anterior = NULL;	// El nodo ANTERIOR al que estamos procesando (al principio, ninguno)
    
    // Recorremos la lista buscando el lugar adecuado para la inserción
    while ((nodo != NULL) && (insertado == 0))
    {
       if (nodo->dato > dato)		// Hemos encontrado el punto de inserción
       {
           insertado = 1;
	   nuevo = (struct s_nodo*) malloc(sizeof(struct s_nodo));
	   nuevo->dato = dato;
	   nuevo->siguiente = nodo;
	   if (anterior == NULL)	// Vamos a insertar en la primera posición de la lista
	      *primero = nuevo;
	   else				// Vamos a insertar en cualquier otra posición
	      anterior->siguiente = nuevo;
       }	   
       // Continuamos el recorrido de la lista, guardando siempre el nodo anterior
       anterior = nodo;
       nodo = nodo->siguiente;
   }
}

void mostrar_lista(struct s_nodo *primero)
{
   struct s_nodo *nodo;
   
   nodo = primero;
   while (nodo != NULL) {
      printf("%i - ", nodo->dato);
      nodo = nodo->siguiente;
   }
   printf("\n");
}
   
       
