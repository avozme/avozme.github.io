// ORDENACION DE VECTORES
// M�todo: Selecci�n directa

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define LONGITUD_VECTOR 20000

void genera_vector(int v[LONGITUD_VECTOR]);
void ordena_vector(int v[LONGITUD_VECTOR]);


int main(void)
{
  int v[LONGITUD_VECTOR];
  //time_t t_ini, t_fin;
  clock_t tiempo;

  printf("\nORDENACI�N DE UN VECTOR DE %i ELEMENTOS\n", LONGITUD_VECTOR);
  printf("M�TODO DE SELECCI�N DIRECTA\n");
  printf("Generando el vector...\n");
  genera_vector(v);
  printf("Ordenando el vector...\n");
  //time(&t_ini);
  ordena_vector(v);
  //time(&t_fin);
  tiempo = clock();
  tiempo = tiempo * 1000 / CLOCKS_PER_SEC;
  printf("Vector ordenado\nTiempo empleado: %i,%i segundos\n\n", tiempo/1000, tiempo%1000/100);
  return 0;
}

void genera_vector(int v[LONGITUD_VECTOR])
{
  int i;
  for (i = 0; i < LONGITUD_VECTOR; i++)
     v[i] = rand()%50000;
}

void ordena_vector(int v[LONGITUD_VECTOR])
{
  int i, j, k, elem;
  for (i = 0; i < LONGITUD_VECTOR; i++)
  {
     elem = v[i];
     k = i;
     for (j=i+1; j < LONGITUD_VECTOR; j++)
     {
       if (v[j] < elem)
       {
          k = j;
	  elem = v[j];
       }
       v[k] = v[i];
       v[i] = elem;
     }
   }
}

