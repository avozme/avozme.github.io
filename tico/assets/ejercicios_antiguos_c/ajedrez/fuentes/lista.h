#ifndef __LISTA_H
#define __LISTA_H

#include <string.h>
#include "tipos.h"
#include "io.h"


struct s_nodo           // Cada nodo almacenará un turno de la partida
{
   char mov[7];         // Movimiento en notación algebraica
   char color;          // Color del jugador que hace el movimiento
   int n_mov;           // Número del movimiento en el total de la partida
   struct s_nodo *sig;  // Puntero al siguiente elemento de la lista
};

// Inicializar la lista
void lst_inicializar(void);
// Finalizar la lista (liberar memoria)
void lst_finalizar(void);
// Insertar un nodo nuevo
void lst_insertar(char* mov, char color);
// Buscar un nodo por el número de turno. Devuelve el movimiento almacenado en el nodo
char* lst_buscar(int num);
// Devuelve VERDADERO si la lista está vacía
int lst_es_vacia(void);
// Devuelve el número de nodos de la lista
int lst_num_elementos(void);


#endif
