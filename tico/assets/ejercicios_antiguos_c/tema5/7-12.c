// FUNDAMENTOS DE PROGRAMACION 1º ASI / EJERCICIO 7-12
// LAS TORRES DE HANOI
#include <stdio.h>

struct s_nodo 
{
   int dato;
   struct s_nodo *siguiente;
};
typedef struct s_nodo t_nodo;


void hanoi(struct s_nodo **pila1, struct s_nodo **pila2, struct s_nodo **pila3, int num_discos, int pila_orig, int pila_dest);
void push(t_nodo **primero, int v) ;
int pop(t_nodo **primero) ;

int num_movs;


int main(void)
{
    struct s_nodo *pila1 = NULL, *pila2 = NULL, *pila3 = NULL;
    int v, n, i;
    
    printf("¿Cuántos discos desea utilizar? (un número muy alto requerirá mucho tiempo)\n");
    scanf("%i", &n);
    
    // Insertamos n discos en la pila 1 en orden de mayor a menor (guardamos en la pila el tamaño del disco)
    for (i=0; i<=n-1; i++)
       push(&pila1, n-i);
       
    // Iniciamos el proceso recursivo que colocará los discos en la tercera pila   
    num_movs = 0;
    hanoi(&pila1, &pila2, &pila3, n, 1, 3);	// Mover n discos de la pila 1 a la pila 3
    
    // Mostramos el resultado para asegurarnos
    printf("Contenido de la pila 3 después de la ejecución del algoritmo:\n");
    while (pila3 != NULL) {
         v = pop(&pila3); 
	 printf("%i\n", v);
    }
    printf("Número total de movimientos necesarios: %i\n", num_movs);
    
    return 0;
}
    
    
void hanoi(struct s_nodo **pila1, struct s_nodo **pila2, struct s_nodo **pila3, int num_discos, int pila_orig, int pila_dest)
{
   int v;
   // Caso base: num_discos == 0 (no hacer nada)
   if (num_discos > 0)		// Caso general
   {
	// Primera llamada recursiva
	hanoi(pila1, pila2, pila3, num_discos - 1, pila_orig, 6 - pila_orig - pila_dest);
	printf("%i --> %i\n", pila_orig, pila_dest);	// Mostramos el movimiento en la pantalla
	num_movs++;
	switch(pila_orig) {				// Sacamos un disco de la pila de origen
	   case 1: v = pop(pila1); break;
	   case 2: v = pop(pila2); break;
	   case 3: v = pop(pila3); break;
	}
	switch(pila_dest) {				// Introducimos el disco en la pila de destino
	   case 1: push(pila1, v); break;
	   case 2: push(pila2, v); break;
	   case 3: push(pila3, v); break;
	}
	// Segunda llamada recursiva
        hanoi(pila1, pila2, pila3, num_discos - 1, 6 - pila_orig - pila_dest, pila_dest);
   }
   
}
	

void push(t_nodo **primero, int v) 
{
   t_nodo *nuevo;
 
   nuevo = (t_nodo*)malloc(sizeof(t_nodo));  // Creamos nodo nuevo
   nuevo->dato = v;                          // Insertamos el dato en el nodo
   
   nuevo->siguiente = *primero;               // La cima a partir de ahora ser�"nuevo"
   *primero = nuevo;
}

int pop(t_nodo **primero) 
{
   t_nodo *aux;  // Variable auxiliar para manipular el nodo
   int v;        // Variable auxiliar para devolver el valor del dato
   
   aux = *primero;
   if(aux == NULL)    // Si no hay elementos en la pila devolvemos algn valor especial
      return -1;
   
   *primero = aux->siguiente;   // La pila empezar�ahora a partir del siguiente elemento
   v = aux->dato;              // Este es el dato que ocupaba la cima hasta ahora
   free(aux);                  // Liberamos la memoria ocupada por el nodo que estaba en la cima
   return v;                   // Devolvemos el dato
}
