#include <stdio.h>

struct s_nodo 
{
   int dato;
   struct s_nodo *siguiente;
};
typedef struct s_nodo t_nodo;



void push(t_nodo** primero, int v) ;
int pop(t_nodo** primero) ;



int main(void)
{
   t_nodo* primero;
   int v;
   
   primero = NULL;
   push(&primero,5);
   push(&primero,6);
   push(&primero,7);
   push(&primero,8);
   
   v = pop(&primero);
   printf("Valor = %i\n", v);
   v = pop(&primero);
   printf("Valor = %i\n", v);
   v = pop(&primero);
   printf("Valor = %i\n", v);
   v = pop(&primero);
   printf("Valor = %i\n", v);
   v = pop(&primero);
   printf("Valor = %i\n", v);
getchar();
   return 0;
}   


void push(t_nodo **primero, int v) 
{
   t_nodo *nuevo;
 
   nuevo = (t_nodo*)malloc(sizeof(t_nodo));  // Creamos nodo nuevo
   nuevo->dato = v;                          // Insertamos el dato en el nodo
   
   nuevo->siguiente = *primero;               // La cima a partir de ahora será "nuevo"
   *primero = nuevo;
}



int pop(t_nodo **primero) 
{
   t_nodo *aux;  // Variable auxiliar para manipular el nodo
   int v;        // Variable auxiliar para devolver el valor del dato
   
   aux = *primero;
   if(aux == NULL)    // Si no hay elementos en la pila devolvemos algún valor especial
      return -1;
   
   *primero = aux->siguiente;   // La pila empezará ahora a partir del siguiente elemento
   v = aux->dato;              // Este es el dato que ocupaba la cima hasta ahora
   free(aux);                  // Liberamos la memoria ocupada por el nodo que estaba en la cima
   return v;                   // Devolvemos el dato
}

