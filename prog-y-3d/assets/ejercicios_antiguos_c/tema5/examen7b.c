#include <stdio.h>

struct s_nodo {
   int dato;
   struct s_nodo *siguiente;
};

void push(struct s_nodo **primero, int dato);
int pop(struct s_nodo **primero);


int main()
{
   struct s_nodo *pila = NULL;   
   char expr[50];
   int n1, n2, result, i;
   
   printf("Introduzca una expresión matemática en notación polaca inversa:\n");
   gets(expr);
   
   for (i=0; i<strlen(expr); i++)
   {
      if ((expr[i] >= '0') && (expr[i] <= '9'))
         push(&pila, expr[i]-48);	// Convertimos el carácter del número en un número restándole 48 (código ASCII del 0)

      if (expr[i] == '+') {		// Operación de SUMA
         n2 = pop(&pila);
	 n1 = pop(&pila);
	 result = n1 + n2;
	 push(&pila, result);
      }
   
      if (expr[i] == '-') {		// Operación de RESTA
         n2 = pop(&pila);
	 n1 = pop(&pila);
	 result = n1 - n2;
	 push(&pila, result);
      }
   
      if (expr[i] == '*') {		// Operación de MULTIPLICACIÓN
         n2 = pop(&pila);
	 n1 = pop(&pila); 
	 result = n1 * n2;
	 push(&pila, result);
      }
   
      if (expr[i] == '/') {		// Operación de DIVISIÓN
         n2 = pop(&pila);
	 n1 = pop(&pila);
	 result = n1 / n2;
	 push(&pila, result);
      }
      
   } // for  
   
   result = pop(&pila);
   printf("El resultado es: %i\n", result);
      
   return 0;
}
      

void push(struct s_nodo **primero, int dato)
{
   struct s_nodo *nuevo;
   
   nuevo = (struct s_nodo*) malloc(sizeof(struct s_nodo*));
   nuevo->dato = dato;
   nuevo->siguiente = *primero;
   *primero = nuevo;
}

int pop(struct s_nodo **primero)
{
   struct s_nodo *segundo;
   int n;
   
   if (*primero != NULL)
   {  
      n = (*primero)->dato;
      segundo = (*primero)->siguiente;   
      free(*primero);
      *primero = segundo;
   }
   else
      n = -1;
   
   return n;
}
