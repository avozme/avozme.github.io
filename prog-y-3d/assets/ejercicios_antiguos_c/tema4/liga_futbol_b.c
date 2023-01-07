/*
EJERCICIO 6-09
SOLUCIÓN 2: Cargar los datos en memoria principal
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
#define MAX_EQUIPOS 20              // Nº máximo de equipos que puede manejar el programa

// Estructura de datos de cada equipo
struct s_equipo
{
   char nombre[50];
   int jug, gan, per, emp;
   int puntos;
   char borrado;
};

// Prototipos de funciones
int cargar_datos(struct s_equipo equipos[MAX_EQUIPOS]);
void grabar_datos(struct s_equipo equipos[MAX_EQUIPOS], int num_eq);
void introducir_datos(struct s_equipo equipos[MAX_EQUIPOS], int num_eq);
void mostrar_datos(struct s_equipo equipos[MAX_EQUIPOS], int num_eq);
void ordenar_datos(struct s_equipo equipos[MAX_EQUIPOS], int num_eq);
void buscar_equipo(struct s_equipo equipos[MAX_EQUIPOS], int num_eq);
void borrar_equipo(struct s_equipo equipos[MAX_EQUIPOS], int num_eq);
void modificar_equipo(struct s_equipo equipos[MAX_EQUIPOS], int num_eq);

int main(void)
{
   int opc;
   char txt[50];
   int num_eq;                              // Nº de equipos que hay almacenados
   struct s_equipo equipos[MAX_EQUIPOS];    // Array donde almacenaremos los datos

   num_eq = cargar_datos(equipos);          // Cargar datos desde archivo al array

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
         case 1: if (num_eq < MAX_EQUIPOS-1) {
                     introducir_datos(equipos, num_eq); 
                     num_eq++; 
                 }
                 else
                     printf("No hay memoria para añadir más equipos\n");
                 break;
         case 2: mostrar_datos(equipos, num_eq); 
                 break;
         case 3: ordenar_datos(equipos, num_eq); 
                 break;
         case 4: buscar_equipo(equipos, num_eq); 
                 break;
         case 5: borrar_equipo(equipos, num_eq); 
                 break;
         case 6: modificar_equipo(equipos, num_eq); 
                 break;
      }
   }
   while (opc != 7);
   
   grabar_datos(equipos, num_eq);         // Grabar datos del array en el archivo
   
   return 0;
}


// Lee los datos grabados en el archivo de disco y los carga en la memoria
// principal (en un array de estructuras). Devuelve el número de equipos leidos
// del archivo.
int cargar_datos(struct s_equipo equipos[MAX_EQUIPOS])
{
   int num_regs;
   FILE *f;

   // Abrimos el archivo para lectura
   f = fopen(ARCHIVO_DATOS, "rb");
   if (f == NULL) {
      // Si el archivo no existe, lo creamos
      printf("El archivo %s no existe. Se creará uno vacío.\n", ARCHIVO_DATOS);
      f = fopen(ARCHIVO_DATOS, "wb");
      if (f == NULL) {
          printf("Error al crear el archivo. El programa no puede continuar.\n");
          exit(1);
      }
   }

   // Leemos del archivo de datos un máximo de MAX_EQUIPOS equipos
   // fread() nos devolverá el número de registros leídos realmente
   // Si el archivo se acaba de crear, ese número será 0
   num_regs = fread(equipos, sizeof(struct s_equipo), MAX_EQUIPOS, f);
   fclose(f);
   
   return num_regs;   // Devolvemos el nº de registros leídos
}   
   
// Escribe los datos de la memoria principal (almacenados en un array de estructuras)
// en el archivo de datos
void grabar_datos(struct s_equipo equipos[MAX_EQUIPOS], int num_eq)
{
   FILE *f;
   
   // Abrir el archivo para escritura, sobreescribiendo lo que hubiera antes
   f = fopen(ARCHIVO_DATOS, "wb");
   if (f == NULL) 
      printf("Error al abrir el archivo %s. ¡No se pueden guardar los datos!\n", ARCHIVO_DATOS);
   else {
      // Escribimos "num_eq" registros
      fwrite(equipos, sizeof(struct s_equipo), num_eq, f);
      fclose(f);
   }
}

// Leer por teclado los datos de un equipo y añadirlo al array de datos
void introducir_datos(struct s_equipo equipos[MAX_EQUIPOS], int num_eq)
{
   char aux[50];
   
   // Leer datos del equipo por teclado y almacenarlos en la posición "num_eq" del array
   printf("Introduzca los datos del equipo.\n");
   printf("  Nombre: ");
   gets(equipos[num_eq].nombre);
   printf("  Jugados: ");
   gets(aux);
   equipos[num_eq].jug = atoi(aux);
   printf("  Ganados: ");
   gets(aux);
   equipos[num_eq].gan = atoi(aux);
   printf("  Perdidos: ");
   gets(aux);
   equipos[num_eq].per = atoi(aux);
   equipos[num_eq].emp = equipos[num_eq].jug - equipos[num_eq].gan - equipos[num_eq].per;
   equipos[num_eq].puntos = equipos[num_eq].gan * 3 + equipos[num_eq].emp * 1;
   
   // Ponemos el campo "borrado" a "N" = no
   equipos[num_eq].borrado = 'N';  
}

// Recorre los datos del array de datos y los muestra por la pantalla
void mostrar_datos(struct s_equipo equipos[MAX_EQUIPOS], int num_eq)
{
   int i;   
   
   printf("\nEQUIPO              JUG GAN EMP PER PUNTOS\n\n");
   // Recorremos el array de datos y los mostramos en la pantalla
   for (i = 0; i < num_eq; i++)
   {
      // Mostramos los datos del equipo sólo si no ha sido borrado
      if (equipos[i].borrado != 'S')
         printf("%-20s %2i  %2i  %2i  %2i   %2i\n", equipos[i].nombre, equipos[i].jug, equipos[i].gan,
               equipos[i].emp, equipos[i].per, equipos[i].puntos);
   }
}


// Ordena el array de datos por puntuación. Usaremos el método de la burbuja.
void ordenar_datos(struct s_equipo equipos[MAX_EQUIPOS], int num_eq)
{
    int i, j;
    struct s_equipo aux;
          
    for (i = 1; i < num_eq; i++)                     
    {
        for (j = num_eq - 1; j >= i; j--)
        {
           if (equipos[j-1].puntos < equipos[j].puntos)     // Intercambiar
           {      
               aux = equipos[j-1];
               equipos[j-1] = equipos[j];
               equipos[j] = aux;
           }
        }
    }
}


// Pide por teclado un nombre de equipo y lo busca en el array de datos
// Si lo encuentra, muestra sus datos en la pantalla
void buscar_equipo(struct s_equipo equipos[MAX_EQUIPOS], int num_eq)
{
   char nombre_buscado[50];
   int i, encontrado;
   
   // Leer nombre del equipo que se pretende buscar
   printf("Introduzca nombre del equipo: ");
   gets(nombre_buscado);
   
   // Recorrer el array buscando el equipo
   encontrado = 0;
   for (i=0; i<num_eq; i++)
   {
      if ((strcmp(equipos[i].nombre, nombre_buscado) == 0) &&     // Hemos encontrado el equipo
          (equipos[i].borrado != 'S'))                            // y no ha sido borrado   
      {
         encontrado = 1;
         break;
      }
   }
   
   // Mostrar resultado en la pantalla
   if (encontrado == 1)
   {
      printf("Nombre: %s\n", equipos[i].nombre);
      printf("Puntos: %i\n", equipos[i].puntos);
      printf("Ganados: %i - Empatados: %i - Perdidos: %i\n", equipos[i].gan, equipos[i].emp, equipos[i].per);
   }
   else
      printf("Equipo no encontrado\n");   
}


// Pide por teclado un nombre de equipo y lo busca en el array de datos
// Si lo encuentra, lo marca como borrado para luego no escribirlo en el archivo.
void borrar_equipo(struct s_equipo equipos[MAX_EQUIPOS], int num_eq)
{
   char nombre_buscado[50];
   int i, encontrado;
   
   // Leer nombre del equipo que se pretende borrar
   printf("Introduzca nombre del equipo que quiere borrar: ");
   gets(nombre_buscado);
   
   // Recorrer el array buscando el equipo que se quiere borrar
   encontrado = 0;
   for (i = 0; i < num_eq; i++)
   {
      if ((strcmp(equipos[i].nombre, nombre_buscado) == 0) &&      // Hemos encontrado el equipo
          (equipos[i].borrado != 'S'))                             // y no ha sido borrado   
      {
         encontrado = 1;
         equipos[i].borrado = 'S';                         // Lo marcamos como borrado
         printf("Equipo borrado\n");                       // Informamos al usuario  
         break;
      }     
   }
   
   if (encontrado == 0)
      printf("Equipo no encontrado\n");   
}


// Pide por teclado un nombre de equipo y lo busca en el array de datos
// Si lo encuentra, muestra sus datos en la pantalla y pide al usuario
// que los modifique. 
void modificar_equipo(struct s_equipo equipos[MAX_EQUIPOS], int num_eq)
{
   char nombre_buscado[50], aux[50];
   int i, encontrado;
   
   // Leer nombre del equipo que se pretende modificar
   printf("Introduzca nombre del equipo que quiere modificar: ");   
   gets(nombre_buscado);
   
   // Recorrer el array para localizar al equipo que se quiere modificar
   encontrado = 0;
   for (i=0; i < num_eq; i++)
   {
      if ((strcmp(equipos[i].nombre, nombre_buscado) == 0) &&   // Hemos encontrado el equipo
          (equipos[i].borrado != 'S'))                          // y no ha sido borrado
      {
        encontrado = 1;
        // Mostramos sus datos actuales
        printf("Equipo encontrado. Sus datos actuales son:\n");
        printf("Nombre: %s\n", equipos[i].nombre);
        printf("Jugados = %i, Puntos = %i\n", equipos[i].jug, equipos[i].puntos);
        printf("Ganados = %i, Empatados = %i, Perdidos = %i\n\n",
                equipos[i].gan, equipos[i].emp, equipos[i].per);
        // Pedimos al usuario que introduzca los datos nuevos
        printf("Introduzca los datos nuevos:\n");
        printf("Nombre: ");
        gets(equipos[i].nombre);
        printf("Partidos jugados: ");
        gets(aux); equipos[i].jug = atoi(aux);
        printf("Partidos ganados: ");
        gets(aux); equipos[i].gan = atoi(aux);
        printf("Partidos perdidos: ");
        gets(aux); equipos[i].per = atoi(aux);
        equipos[i].emp = equipos[i].jug - equipos[i].per - equipos[i].gan;
        equipos[i].puntos = equipos[i].gan * 3 + equipos[i].emp * 1;
        
        break;
      }
   }

   // Mostrar resultado al usuario
   if (encontrado == 1)
      printf("Equipo modificado\n");
   else
      printf("Equipo no encontrado");   

}
 
