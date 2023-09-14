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
   
   // Calcula el número de líneas que contiene el archivo
   num_lineas = contar_lineas(nom_arch);
   if (num_lineas > 0)
   {
      // Pregunta al usuario la línea inicial
      do
      {
         printf("Introduzca línea inicial (1 - %i): ", num_lineas);
         gets(aux);
         linea_ini = atoi(aux);
      } 
      while ((linea_ini < 1) || (linea_ini > num_lineas));
      
      // Pregunta al usuario la línea final
      do
      {
         printf("Introduzca línea final (%i - %i): ", linea_ini, num_lineas);
         gets(aux);
         linea_fin = atoi(aux);
      } 
      while ((linea_fin < linea_ini) || (linea_ini > num_lineas));
      
      // Muestra por pantalla las líneas seleccionadas
      mostrar_archivo(nom_arch, linea_ini, linea_fin);
   }
   system("PAUSE");
   return 0;
}

// Cuenta y devuelve el número de líneas de texto que tiene un archivo
int contar_lineas(char* nom_arch)
{
   char linea[81];  // Las líneas tienen como máximo 80 caracteres
   FILE *f;
   int num_lineas = 0;
   
   f = fopen(nom_arch, "r");
   if (f == NULL)
      printf("Error al abrir el archivo\n");
   else
   {
      while (!feof(f))
      {
         fgets(linea, 80, f);      // Leemos una línea del archivo
         num_lineas++;             // Contador del número de líneas;
      }
      fclose(f);
   }
   return num_lineas;
}

void mostrar_archivo(char* nom_arch, int linea_ini, int linea_fin)
{
   char linea[81];  // Las líneas tienen como máximo 80 caracteres
   FILE *f;
   int num_linea = 0;
   
   f = fopen(nom_arch, "r");
   if (f == NULL)
      printf("Error al abrir el archivo\n");
   else
   {
      while (!feof(f))
      {
         fgets(linea, 80, f);             // Leemos una línea del archivo
         num_linea++;                     // Contador del número de líneas
         if ((num_linea >= linea_ini) && (num_linea <= linea_fin))
            printf(linea);                // Mostramos la línea en la pantalla
      }
      fclose(f);
   }
}

