#include <stdio.h>
#include <stdlib.h>

// Prototipos
int contar_lineas(char* nom_arch);
void mostrar_archivo(char* nom_arch, int linea_ini, int linea_fin);

int main(void)
{
   char nom_arch[50], aux[50];
   int num_lineas, linea_ini, linea_fin;
   
   // Lee nombre del archivo
   printf("Introduzca el nombre del archivo que quiere abrir:\n");
   gets(nom_arch);
   
   // Calcula el n�mero de l�neas que contiene el archivo
   num_lineas = contar_lineas(nom_arch);
   if (num_lineas > 0)
   {
      // Pregunta al usuario la l�nea inicial
      do
      {
         printf("Introduzca l�nea inicial (1 - %i): ", num_lineas);
         gets(aux);
         linea_ini = atoi(aux);
      } 
      while ((linea_ini < 1) || (linea_ini > num_lineas));
      
      // Pregunta al usuario la l�nea final
      do
      {
         printf("Introduzca l�nea final (%i - %i): ", linea_ini, num_lineas);
         gets(aux);
         linea_fin = atoi(aux);
      } 
      while ((linea_fin < linea_ini) || (linea_ini > num_lineas));
      
      // Muestra por pantalla las l�neas seleccionadas
      mostrar_archivo(nom_arch, linea_ini, linea_fin);
   }
   system("PAUSE");
   return 0;
}

// Cuenta y devuelve el n�mero de l�neas de texto que tiene un archivo
int contar_lineas(char* nom_arch)
{
   char linea[81];  // Las l�neas tienen como m�ximo 80 caracteres
   FILE *f;
   int num_lineas = 0;
   
   f = fopen(nom_arch, "r");
   if (f == NULL)
      printf("Error al abrir el archivo\n");
   else
   {
      while (!feof(f))
      {
         fgets(linea, 80, f);      // Leemos una l�nea del archivo
         num_lineas++;             // Contador del n�mero de l�neas;
      }
      fclose(f);
   }
   return num_lineas;
}

void mostrar_archivo(char* nom_arch, int linea_ini, int linea_fin)
{
   char linea[81];  // Las l�neas tienen como m�ximo 80 caracteres
   FILE *f;
   int num_linea = 0;
   
   f = fopen(nom_arch, "r");
   if (f == NULL)
      printf("Error al abrir el archivo\n");
   else
   {
      while (!feof(f))
      {
         fgets(linea, 80, f);             // Leemos una l�nea del archivo
         num_linea++;                     // Contador del n�mero de l�neas
         if ((num_linea >= linea_ini) && (num_linea <= linea_fin))
            printf(linea);                // Mostramos la l�nea en la pantalla
      }
      fclose(f);
   }
}

