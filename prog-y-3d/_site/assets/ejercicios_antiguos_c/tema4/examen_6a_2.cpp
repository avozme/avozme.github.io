#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void introducir_datos();
void borrar_datos();

struct s_alumno
{
   char nombre[20];
   char apellidos[50];
   char grupo[10];
   double nota1, nota2, nota3;
   double nota_final;
};

int main(void)
{
   char aux[50];
   int opc;

   do
   {
     // Muestra el menú de opciones
     printf("¿Qué desea hacer?\n");
     printf("1. Añadir datos al archivo\n");
     printf("2. Borrar datos del archivo\n");
     printf("3. Salir\n");
     printf("Elija una opción (1-3): ");
     gets(aux);
     opc = atoi(aux);

     // Según la opción, llamamos a una función o a otra
     if (opc == 1)
        introducir_datos();
     if (opc == 2)
        borrar_datos();
   }
   while (opc != 3);	// La opción 3 es para terminar
       
   return 0;
}

// Añade registros al archivo de datos hasta que se teclee "SALIR" en el nombre
void introducir_datos()
{
   struct s_alumno nuevo;
   char aux[50], *p_fin;
   FILE *f;
   int salir;
   
   salir = 0;
   do
   {
      // Leemos datos del nuevo registro
      printf("Introduzca los datos de un nuevo registro...\n");
      printf("Nombre (teclee SALIR para terminar): ");
      gets(nuevo.nombre);
      if (strcmp(nuevo.nombre, "SALIR") == 0)
         salir = 1;
      else
      {
         printf("Apellidos: ");
         gets(nuevo.apellidos);
         printf("Grupo: ");
         gets(nuevo.grupo);
         printf("Nota evaluación 1: ");
         gets(aux); 
         nuevo.nota1 = strtod(aux, &p_fin);
         printf("Nota evaluación 2: ");
         gets(aux);
         nuevo.nota2 = strtod(aux, &p_fin);
         printf("Nota evaluación 3: ");
         gets(aux); 
         nuevo.nota3 = strtod(aux, &p_fin);
      
         // Añadimos el registro al archivo
         f = fopen("datos.bin","a");
         if (f == NULL) 
         {
            printf("No puedo abrir el archivo\n");   
            break;
         }
         fwrite(&nuevo, sizeof(struct s_alumno), 1, f);
         fclose(f);
      } // else
   } while (salir == 0);
}
         
// Elimina un registro del archivo de datos
void borrar_datos()
{
   char nom_buscado[20], ape_buscados[50];
   FILE *f, *f_temp;
   int encontrado, n;
   int comp_nombre, comp_apell;
   struct s_alumno alumno;
   
   // Leemos nombre y apellidos del alumno que se quiere borrar
   printf("Introduzca los datos del alumno que desea borrar:\n");
   printf("Nombre: ");
   gets(nom_buscado);
   printf("Apellidos: ");
   gets(ape_buscados);
   
   // Abrimos el archivo de datos y creamos archivo temporal
   f = fopen("datos.bin", "rb");
   if (f==NULL) {
      printf("No puedo abrir archivo de datos\n");
      return;
   }
   
   f_temp = fopen("temp", "wb");
   if (f_temp==NULL) {
      printf("No puedo crear archivo temporal\n");
      fclose(f);
      return;
   }
   
   // Recorremos el archivo de datos y vamos copiÃ¡ndolo todo al archivo temporal
   // (excepto el alumno que se quiere borrar)
   encontrado = 0;
   while (!feof(f))
   {
      // Leemos un registro del archivo de datos
      n = fread(&alumno, sizeof(struct s_alumno), 1, f);
      if (n > 0)
      {
         // Miramos a ver si es el que queremos borrar
         comp_nombre = strcmp(alumno.nombre, nom_buscado);
         comp_apell = strcmp(alumno.apellidos, ape_buscados);
         if ((comp_nombre == 0) && (comp_apell == 0))	// Es el que queremos borrar
            encontrado = 1;			// No lo copiamos al archivo temporal
         else			// En otro caso, lo copiamos al arch. temporal
            fwrite(&alumno, sizeof(struct s_alumno), 1, f_temp);
         
      }
      fclose(f);
      fclose(f_temp);
   
      // Comprobamos resultado, renombramos archivos e informamos al usuario
      if (encontrado == 1)
      {
         printf("Alumno borrado\n");
         remove("datos.bin");
         rename("temp", "datos.bin");
      }
      else
      {
         printf("Alumno no encontrado\n");
         remove("temp");
      }
  }
}

