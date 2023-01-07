#include <stdio.h>
#include <string.h>

#define MAX_COCHES 3

struct s_coche
{
  char marca[20];
  char modelo[20];
  char matricula[10];
};

void introducir_datos(struct s_coche c[MAX_COCHES]);
void ordenar_datos(struct s_coche c[MAX_COCHES]);
void mostrar_datos(struct s_coche c[MAX_COCHES]);

int main(void)
{
  struct s_coche coches[MAX_COCHES];
  
  introducir_datos(coches);
  ordenar_datos(coches);
  mostrar_datos(coches);
  getch();
  
  return 0;
}

void introducir_datos(struct s_coche c[MAX_COCHES])
{
   int i;
   for (i=0; i<MAX_COCHES; i++)
   {
      printf("Introduzca los datos del coche nº %i\n", i+1);
      printf("Matrícula: "); gets(c[i].matricula);
      printf("Marca: "); gets(c[i].marca);
      printf("Modelo: "); gets(c[i].modelo);
   }
}

void ordenar_datos(struct s_coche c[MAX_COCHES])
{
   int i, j;
   int comparacion;
   struct s_coche aux;
   for (i=0; i<MAX_COCHES; i++)
     for (j=1; j<MAX_COCHES; j++)
     {
        comparacion = strcmp(c[j-1].marca, c[j].marca);
        if (comparacion > 0) 
        {
           aux = c[j-1];
           c[j-1] = c[j];
           c[j] = aux;
        }
     }
}

void mostrar_datos(struct s_coche c[MAX_COCHES])
{
   int i;
   printf("MARCA           MODELO          MATRICULA\n");
   printf("-----------------------------------------\n");
   for (i=0; i<MAX_COCHES; i++)
      printf("%-15s %-15s %-8s\n", c[i].marca, c[i].modelo, c[i].matricula);
}
