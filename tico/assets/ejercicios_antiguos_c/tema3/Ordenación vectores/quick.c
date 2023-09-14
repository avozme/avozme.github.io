// ORDENACION DE VECTORES
// Método: Selección directa

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define LONGITUD_VECTOR 50

void genera_vector();
void ordena_vector(int iz, int de);

int v[LONGITUD_VECTOR];


int main(void)
{
  //time_t t_ini, t_fin;
  clock_t tiempo;

  printf("\nORDENACIÓN DE UN VECTOR DE %i ELEMENTOS\n", LONGITUD_VECTOR);
  printf("MÉTODO QUICKSORT\n");
  printf("Generando el vector...\n");
  genera_vector();
  printf("Ordenando el vector...\n");
  //time(&t_ini);
  ordena_vector(0, LONGITUD_VECTOR-1);
  //time(&t_fin);
  tiempo = clock();
  tiempo = tiempo * 1000 / CLOCKS_PER_SEC;
  printf("Vector ordenado\nTiempo empleado: %i,%i segundos\n\n", tiempo/1000, tiempo%1000/10);

  system("pause");
  return 0;
}

void genera_vector()
{
  int i;
  for (i = 0; i < LONGITUD_VECTOR; i++)
     v[i] = rand()%50000;
}

void ordena_vector(int iz, int de)
{
  int i, j, x, w;
  
  i = iz;
  j = de;
  x = v[(iz+de) / 2];
  do
  {
     while (v[i] < x) i++;
     while (x < v[j]) j--;
     
     if (i <= j)
     {
        w = v[i];
	v[i] = v[j];
	v[j] = w;
	i++;
	j--;
      }
   }
   while (i <= j);
   
   if (iz < j) ordena_vector(iz, j);
   if (i < de) ordena_vector(i, de);
}


