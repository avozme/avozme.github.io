/*
EJERCICIO 6-09
SOLUCIÓN 1: Operar con los datos en memoria secundaria
-------------------------------------------------
Completar el ejercicio de la liga de fútbol. 
Programar un sencillo menú de opciones que tenga este aspecto en pantalla:
  PROGRAMA DE LA LIGA DE FÚTBOL
  MENÚ DE OPCIONES
  1. Introducir datos 
  2. Mostrar datos 
  3. Ordenar datos
  4. Buscar un equipo
  5. Borrar un equipo
  6. Modificar un equipo
  7. Salir del programa
Después, y según la opción elegida por el usuario, se debe llamar a una función por cada opción. 
 - Introducir datos: esta función permitirá al usuario introducir por teclado nuevos datos, 
   que serán añadidos al fichero de datos (6-09.dat)
 - Mostrar datos: leerá el archivo de datos (6-09.dat) y mostrará su contenido en la pantalla.
 - Ordenar datos: sirve para ordenar el archivo de datos por orden decreciente de puntuación.
 - Buscar un equipo: pide al usuario un nombre de equipo y lo busca en el archivo. Si lo encuentra, 
   muestra sus datos por la pantalla.
 - Borrar un equipo: pide al usuario un nombre de equipo y, si existe, lo borra del archivo.
 - Modificar un equipo: pide al usuario un nombre de equipo y, si existe, muestra por la pantalla 
   sus datos actuales y pide al usuario unos datos nuevos. Después, sustituye los datos del equipo 
   por los nuevos y lo guarda todo en el archivo.
*/

#include <stdio.h>
#define ARCHIVO_DATOS "liga.dat"	// Nombre del archivo de datos

// Prototipos de funciones
void introducir_datos();
void mostrar_datos();
void ordenar_datos();
int contar_equipos();
void buscar_equipo();
void borrar_equipo();
void modificar_equipo();

// Estructura de datos de cada equipo
struct s_equipo
{
   char nombre[50];
   int jug, gan, per, emp;
   int puntos;
};

int main(void)
{
   int opc;
   char txt[50];

   do
   {
      // Mostrar el menú de opciones
      printf("\n\nPROGRAMA DE LA LIGA DE FUTBOL\n\n");
      printf("MENU DE OPCIONES\n\n");
      printf("1 - Introducir datos\n");
      printf("2 - Mostrar datos\n");
      printf("3 - Ordenar datos\n");
      printf("4 - Buscar un equipo\n");
      printf("5 - Borrar un equipo\n");
      printf("6 - Modificar un equipo\n");
      printf("7 - Salir del programa\n");
   
      // Leer la opción seleccionada por el usuario
      do
      {
         printf("\nElija una opción (1-7): ");
         gets(txt);
         opc = atoi(txt);
      }
      while ((opc < 1) || (opc > 7));
   
      // Llamar a la función correspondiente según la opción elegida
      switch (opc)
      {
         case 1: introducir_datos(); break;
         case 2: mostrar_datos(); break;
         case 3: ordenar_datos(); break;
         case 4: buscar_equipo(); break;
         case 5: borrar_equipo(); break;
         case 6: modificar_equipo(); break;
      }
   }
   while (opc != 7);
   
   return 0;
}


// Leer por teclado los datos de un equipo y añadirlo al archivo de datos
void introducir_datos()
{
   FILE *f;
   struct s_equipo equipo;
   char aux[50];
   
   
   // Leer datos del equipo por teclado
   printf("Introduzca los datos del equipo.\n");
   printf("  Nombre: ");
   gets(equipo.nombre);
   printf("  Jugados: ");
   gets(aux);
   equipo.jug = atoi(aux);
   printf("  Ganados: ");
   gets(aux);
   equipo.gan = atoi(aux);
   printf("  Perdidos: ");
   gets(aux);
   equipo.per = atoi(aux);
   equipo.emp = equipo.jug - equipo.gan - equipo.per;
   equipo.puntos = equipo.gan * 3 + equipo.per;
   
   // Abrir el archivo en modo "ab" (añadir/binario) y grabar los datos del equipo
   f = fopen(ARCHIVO_DATOS, "ab");
   if (f == NULL) 
      printf("Error al abrir el archivo %s. No se pueden guardar los datos\n", ARCHIVO_DATOS);
   else {
      fwrite(&equipo, sizeof(struct s_equipo), 1, f);
      fclose(f);
   }
}

// Lee los datos del archivo de datos y los muestra por la pantalla
void mostrar_datos()
{
   FILE *f;
   struct s_equipo equipo;
   int result;
   
   // Abrir el archivo para lectura
   f = fopen(ARCHIVO_DATOS, "rb");
   if (f == NULL) {
     printf("Error al abrir el archivo %s\n", ARCHIVO_DATOS);
     return;
   }
   
   // Leer datos y mostrarlos en la pantalla, hasta que se alcance el EOF
   printf("\nEQUIPO              JUG GAN EMP PER PUNTOS\n\n");
   while (!feof(f))
   {
      fread(&equipo, sizeof(struct s_equipo), 1, f);
      printf("%-20s %2i  %2i  %2i  %2i   %2i\n", equipo.nombre, equipo.jug, equipo.gan,
               equipo.emp, equipo.per, equipo.puntos);
   }
   fclose(f);  
}


// Ordena el archivo de datos por puntuación. Usaremos el método de la burbuja
// Habrá que recorrer el archivo N veces intercambiando los equipos adyacentes que
// estén desordenados, siendo N el nº de equipos que hay en el archivo.
void ordenar_datos()
{
    FILE *f, *f_temp;
    int N, i;
    struct s_equipo eq1, eq2;
    
    printf("Ordenando el archivo...\n");
    N = contar_equipos();    			 // Cuenta en nº de equipos que hay en el archivo
    
    for (i=0; i<N; i++)                     // Repetiremos el proceso N veces
    {
        // Abrir archivo de datos para lectura
        f = fopen(ARCHIVO_DATOS, "rb");
        if (f == NULL) {
          printf("No se puede abrir el archivo de datos %s\n", ARCHIVO_DATOS);
          return;
        }
   
        // Crear archivo auxiliar para realizar el intercambio de elementos
        f_temp = fopen("temporal", "wb");
        if (f_temp == NULL) {
          printf("Error al crear archivo temporal\n");
          fclose(f);
          return;
        }      
        
        // Recorrer el archivo intercambiando elementos adyacentes (si están desordenados)
        fread(&eq1, sizeof(struct s_equipo), 1, f);
        while (!feof(f))
        {
           // Leemos el siguiente registro (eq2) para compararlo con el anterior (eq1)
           fread(&eq2, sizeof(struct s_equipo), 1, f);
           
           if (eq1.puntos > eq2.puntos)           // Están ordenados.
           {                                      // Copiamos el equipo eq1 al archivo temporal
               fwrite(&eq1, sizeof(struct s_equipo), 1, f_temp);      
               eq1 = eq2;                         // Preparamos la próxima iteración
           }
           else       // Están desordenados. Hay que intercambiarlos
           {          // Escribimos eq2 en lugar de eq1 en el archivo temporal
               fwrite(&eq2, sizeof(struct s_equipo), 1, f_temp);
           }
        }
        fwrite(&eq2, sizeof(struct s_equipo), 1, f_temp);
        fclose(f);
        fclose(f_temp);
        
        // Convertimos el archivo temporal en el nuevo archivo de datos
        remove(ARCHIVO_DATOS);
        rename("temporal", ARCHIVO_DATOS);
   } // Fin del "for" (se repite N veces)
   
   printf("Ordenación terminada.\n");
}

// Devuelve el número de equipos que hay en el archivo de datos
int contar_equipos()
{
   int cont;
   FILE* f;
   struct s_equipo eq;

   // Abrir archivo de datos para lectura
   f = fopen(ARCHIVO_DATOS, "rb");
   if (f == NULL) {
      printf("No se puede abrir el archivo de datos %s\n", ARCHIVO_DATOS);
      return -1;
   }

   cont = 0;
   while (!feof(f))  
   {
       fread(&eq, sizeof(struct s_equipo), 1, f);
       cont++;
   }
   
   return cont;
}

// Pide por teclado un nombre de equipo y lo busca en el archivo de datos
// Si lo encuentra, muestra sus datos en la pantalla
void buscar_equipo()
{
   FILE *f;
   struct s_equipo equipo;
   char nom_eq[50];
   int encontrado;
   
   // Leer nombre del equipo que se pretende buscar
   printf("Introduzca nombre del equipo: ");
   gets(nom_eq);
   
   // Abrir archivo de datos para lectura
   f = fopen(ARCHIVO_DATOS, "rb");
   if (f == NULL) {
      printf("No se puede abrir el archivo de datos %s\n", ARCHIVO_DATOS);
      return;
   }
   
   // Recorrer el archivo buscando el equipo
   encontrado = 0;
   while (!feof(f))
   {
      fread(&equipo, sizeof(struct s_equipo), 1, f);
      if (strcmp(equipo.nombre, nom_eq) == 0)      // Hemos encontrado el equipo
      {
         encontrado = 1;
         break;
      }
   }
   fclose(f);
   
   // Mostrar resultado en la pantalla
   if (encontrado == 1)
   {
      printf("Nombre: %s\n", equipo.nombre);
      printf("Puntos: %i\n", equipo.puntos);
      printf("Ganados: %i - Empatados: %i - Perdidos: %i\n", equipo.gan, equipo.emp, equipo.per);
   }
   else
      printf("Equipo no encontrado");   
}


// Pide por teclado un nombre de equipo y lo busca en el archivo de datos
// Si lo encuentra, lo borra del archivo.
void borrar_equipo()
{
   FILE *f, *f_temp;
   struct s_equipo equipo;
   char nom_eq[50];
   int encontrado;
   
   // Leer nombre del equipo que se pretende borrar
   printf("Introduzca nombre del equipo que quiere borrar: ");
   gets(nom_eq);
   
   // Abrir archivo de datos para lectura
   f = fopen(ARCHIVO_DATOS, "rb");
   if (f == NULL) {
      printf("No se puede abrir el archivo de datos %s\n", ARCHIVO_DATOS);
      return;
   }
   
   // Crear archivo auxiliar para realizar el borrado
   f_temp = fopen("temporal", "wb");
   if (f_temp == NULL) {
       printf("Error al crear archivo temporal\n");
       fclose(f);
       return;
   }
      
   // Recorrer el archivo copiando todos los registros, menos el que se quiere borrar
   encontrado = 0;
   while (!feof(f))
   {
      fread(&equipo, sizeof(struct s_equipo), 1, f);
      if (strcmp(equipo.nombre, nom_eq) == 0)      // Hemos encontrado el equipo
         encontrado = 1;
      else
         fwrite(&equipo, sizeof(struct s_equipo), 1, f_temp);
   }
   fclose(f);
   fclose(f_temp);
   
   // Mostrar resultado y eliminar archivo temporal
   if (encontrado == 1)
   {
      printf("Equipo borrado");
      remove(ARCHIVO_DATOS);
      rename("temporal", ARCHIVO_DATOS);
   }
   else
   {
      printf("Equipo no encontrado");   
      remove("temporal");
   }
}


// Pide por teclado un nombre de equipo y lo busca en el archivo de datos
// Si lo encuentra, muestra sus datos en la pantalla y pide al usuario
// que los modifique. Luego guarda los datos modificados en el archivo.
void modificar_equipo()
{
   FILE *f, *f_temp;
   struct s_equipo equipo, nuevo;
   char nom_eq[50], aux[50];
   int encontrado;
   
   // Leer nombre del equipo que se pretende modificar
   printf("Introduzca nombre del equipo que quiere modificar: ");   
   gets(nom_eq);
   
   // Abrir archivo de datos para lectura
   f = fopen(ARCHIVO_DATOS, "rb");
   if (f == NULL) {
      printf("No se puede abrir el archivo de datos %s\n", ARCHIVO_DATOS);
      return;
   }
   
   // Crear archivo auxiliar para realizar la modificación
   f_temp = fopen("temporal", "wb");
   if (f_temp == NULL) {
       printf("Error al crear archivo temporal\n");
       fclose(f);
       return;
   }
      
   // Recorrer el archivo copiando todos los registros, menos el que se quiere modificar
   encontrado = 0;
   while (!feof(f))
   {
      fread(&equipo, sizeof(struct s_equipo), 1, f);
      if (strcmp(equipo.nombre, nom_eq) == 0)      // Hemos encontrado el equipo
      {
        encontrado = 1;
        // Mostramos sus datos actuales
        printf("Equipo encontrado. Sus datos actuales son:");
        printf("Nombre: %s\n", equipo.nombre);
        printf("Jugados = %i, Puntos = %i\n", equipo.jug, equipo.puntos);
        printf("Ganados = %i, Empatados = %i, Perdidos = %i\n\n",
                                                           equipo.gan, equipo.emp, equipo.per);
        // Pedimos al usuario que introduzca los datos nuevos
        printf("Introduzca los datos nuevos:\n");
        printf("Nombre: ");
        gets(nuevo.nombre);
        printf("Partidos jugados: ");
        gets(aux); nuevo.jug = atoi(aux);
        printf("Partidos ganados: ");
        gets(aux); nuevo.gan = atoi(aux);
        printf("Partidos perdidos: ");
        gets(aux); nuevo.per = atoi(aux);
        nuevo.emp = nuevo.jug - nuevo.per - nuevo.gan;
        nuevo.puntos = nuevo.gan * 3 + nuevo.emp;
        // Grabamos los datos nuevos
        fwrite(&nuevo, sizeof(struct s_equipo), 1, f_temp);   
      }     
      else
        fwrite(&equipo, sizeof(struct s_equipo), 1, f_temp);
   }
   fclose(f);
   fclose(f_temp);
   
   // Mostrar resultado y eliminar archivo temporal
   if (encontrado == 1)
   {
      printf("Equipo modificado");
      remove(ARCHIVO_DATOS);
      rename("temporal", ARCHIVO_DATOS);
   }
   else
   {
      printf("Equipo no encontrado");   
      remove("temporal");
   }

}

