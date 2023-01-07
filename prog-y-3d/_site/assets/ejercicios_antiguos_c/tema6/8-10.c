// FUNDAMENTOS DE PROGRAMACI�N 1� ASI
// EJERCICIOS DEL TEMA 8

#include <stdio.h>
#include <stdlib.h>



struct s_pelicula
{
   char titulo[50];
   char director[20];
   char reparto[200];
   char genero[20];
   char nacionalidad[10];
   int duracion;
   char borrado;
   int codigo;
};

void listar_datos(void);

FILE *f;

int main(void)
{
   printf("EJERCICIOS DE FUNDAMENTOS DE PROGRAMACI�N - TEMA 8\n");
   printf("Recorrer un archivo secuencial hacia atr�s recursivamente\n\n");
   
   f = fopen("video.dat", "rb");
   if (f == NULL)
   {
      printf("Error al abrir el archivo de datos\n");
      system("PAUSE");
      return -1;
   }
   printf("El contenido del archivo video.dat le�do al rev�s es:\n\n");

   printf("------------------------------------------------------------------------------\n");
   listar_datos();
   printf("------------------------------------------------------------------------------\n");
   fclose(f);
      
   system("PAUSE");
   return 0;
}

    
// Muestra el contenido del archivo secuencial de datos por la pantalla
// El recorrido se hace HACIA ATRAS y RECURSIVAMENTE
void listar_datos(void)
{
   struct s_pelicula peli;
   int n;
   
   n = fread(&peli, sizeof(struct s_pelicula), 1, f);   // Leemos un registro
   if ((n > 0) && (peli.borrado == '-'))
   {
      if (feof(f))     // Hemos le�do el �ltimo registro, as� que lo mostramos
          printf("%-3i %s (%s), %s, %s, %i min\n", peli.codigo, peli.titulo, peli.director, peli.nacionalidad, peli.genero, peli.duracion);
      else
      {
          listar_datos();   // No hemos le�do el �ltimo: leemos los dem�s antes de mostrarlo
          printf("%-3i %s (%s), %s, %s, %i min\n", peli.codigo, peli.titulo, peli.director, peli.nacionalidad, peli.genero, peli.duracion);
      }          
   } 
}


