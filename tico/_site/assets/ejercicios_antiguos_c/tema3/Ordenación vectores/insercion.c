// ORDENACION DE VECTORES
// Método: Inserción directa (burbuja)

#include <stdio.h>
#include <time.h>

#define LONGITUD_VECTOR 20000

void genera_vector(int v[LONGITUD_VECTOR]);
void ordena_vector(int v[LONGITUD_VECTOR]);


int main(void)
{
  int v[LONGITUD_VECTOR];
  //time_t t_ini, t_fin;
  clock_t tiempo;

  printf("\nORDENACIÓN DE UN VECTOR DE %i ELEMENTOS\n", LONGITUD_VECTOR);
  printf("MÉTODO DE INSERCIÓN DIRECTA\n");
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
     v[i] = random(50000);
}

void ordena_vector(int v[LONGITUD_VECTOR])
{
  int i, j, elem, colocado;
  for (i = 1; i < LONGITUD_VECTOR; i++)
  {
     elem = v[i];
     j = i - 1;
     colocado = (v[j] <= elem);
     while (!colocado)
     {
       v[j+1] = v[j];
       j = j - 1;
       if (j = 0) colocado = 1;
       else colocado = (v[j] <= elem);
     }
     v[j+1] = elem;
   }
}

