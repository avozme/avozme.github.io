// FUNDAMENTOS DE PROGRAMACIÓN 1º ASI
// TEMA 6 (FICHEROS) - EJERCICIO DEL VIDEOCLUB
// (c) 2006 A. Moreno 

// XXX faltan las operaciones de borrar y modificar

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "conio.h"

#define ARCHIVO_DATOS "video.dat"
#define ARCHIVO_INDICE "video.idx"
#define TAM_SEG 10  // Tamaño del segmento

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

struct s_indice
{
    long int num_segmento;
    long int direccion_primero;
    int clave_ultimo;
};



void borrar_pantalla(void);
void pulsar_tecla(void);
int comprobar_archivo(void);
int menu(void);
void insertar_datos_final(int *n_regs);
void listar_datos(void);
void importar_datos(int *n_regs);
void buscar_por_codigo(void);
void reconstruir_indice(void);
void mostrar_indice(void);
void introducir_datos_pelicula(struct s_pelicula* peli);


int main(void)
{
   int opc, n_regs;
   
   n_regs = comprobar_archivo();
   do
   {
      borrar_pantalla();
      opc = menu();
      switch (opc)
      {
        case 1: insertar_datos_final(&n_regs); break;
        case 2: importar_datos(&n_regs); break;
        case 3: listar_datos(); break;
        case 4: buscar_por_codigo(); break;
        case 7: mostrar_indice(); break;
        case 8: reconstruir_indice(); break;
      }
   }
   while (opc != 9);     // 9 es "salir"
   
   return 0;
}

// Borra la pantalla de texto
void borrar_pantalla(void)
{
   textbackground(RED); textcolor(YELLOW);
   clrscr();
   gotoxy(1,1);
}

// Muestra el texto "pulse una tecla para continuar" y espera a que el usuario pulse una tecla
void pulsar_tecla(void)
{
   printf("Pulse Intro para continuar...\n");
   getchar();
}


// Muestra el menú y lee la opción del usuario. Devuelve el código de la opción elegida.
int menu(void)
{
   int opc = 1;
   char tecla, aux[50];
   
   textcolor(WHITE); textbackground(RED);
   gotoxy(21,1); printf("Fundamentos de programacion - 1ASI");
   gotoxy(26,2); printf("EJERCICIO DEL VIDEOCLUB");

   do
   {
     // Muestra el menú
     textcolor(YELLOW); textbackground(GREEN);
     gotoxy(22,5);  printf("+-------------------------------+\n");
     gotoxy(22,6);  printf("|             MENU              |\n");
     gotoxy(22,7);  printf("+-------------------------------+\n");
     gotoxy(22,8);  printf("|      Insertar película        |\n");
     gotoxy(22,9);  printf("|      Importar datos           |\n");
     gotoxy(22,10); printf("|      Listar películas         |\n");
     gotoxy(22,11); printf("|      Buscar                   |\n");     
     gotoxy(22,12); printf("|                               |\n");     
     gotoxy(22,13); printf("|                               |\n");     
     gotoxy(22,14); printf("|      Mostrar índice           |\n");
     gotoxy(22,15); printf("|      Reconstruir índice       |\n");
     gotoxy(22,16); printf("|      Salir                    |\n");
     gotoxy(22,17); printf("+-------------------------------+\n");
   
     // Resalta la opción actualmente seleccionada
     gotoxy(22, 7 + opc); textcolor(WHITE); textbackground(BLUE);
     switch(opc)
     {
       case 1:   printf("|      Insertar película        |\n"); break;
       case 2:   printf("|      Importar datos           |\n"); break;
       case 3:   printf("|      Listar películas         |\n"); break;
       case 4:   printf("|      Buscar                   |\n"); break;
       case 5:   printf("|                               |\n"); break;
       case 6:   printf("|                               |\n"); break;
       case 7:   printf("|      Mostrar índice           |\n"); break;
       case 8:   printf("|      Reconstruir índice       |\n"); break;
       case 9:   printf("|      Salir                    |\n"); break;
     }
   
     // Leer el teclado y actualiza la opción activada
     tecla = getch();
     if (tecla == '+') { opc++; if (opc == 10) opc = 1; }   
     if (tecla == '-') { opc--; if (opc == 0) opc = 9; }
   }
   while (tecla != 13);     // Sale con "RETURN" 
   
   return opc;
}

// Comprueba si el archivo de datos existe. Si no existe, lo crea.
// Devuelve el código del último registro almacenado en el archivo.
int comprobar_archivo(void)
{
    FILE *f;
    struct s_pelicula peli;
    int n_regs;
    
    f = fopen(ARCHIVO_DATOS, "r+");
    if (f == NULL)        // El archivo no existe: se crea y se pone el nº de registros a 0
    {
        f = fopen(ARCHIVO_DATOS, "a");
        if (f == NULL)
        {
                printf("Error al crear el archivo de datos\n");
                return 0;
        }
        n_regs = 0;
        fclose(f);
    }
    else                // El archivo sí existe: mirar cuál es el código del último registro
    {
        fseek (f, -sizeof(struct s_pelicula), SEEK_END);
        fread(&peli, sizeof(struct s_pelicula), 1, f);
        n_regs = peli.codigo;
        fclose(f);
    }
    
    return n_regs;
}


// Añade un registro al final del archivo de datos.
void insertar_datos_final(int *n_regs)
{
   FILE *f, *f_ind;
   struct s_pelicula nuevo, peli;
   struct s_indice entrada_indice;
   int n, terminado = 0;
   
   // Introducir por teclado los datos del nuevo registro
   borrar_pantalla();
   printf("INSERTAR MANUALMENTE NUEVA PELICULA\n");
   printf("Introduzca los datos de la película\n");
   introducir_datos_pelicula(&nuevo);
   
   // Abrir el archivo para añadir datos en él (modo secuencial, para agregar al final)
   f = fopen(ARCHIVO_DATOS, "r+b");
   if (f == NULL) 
   {
      printf("Error al abrir el archivo de datos");
      pulsar_tecla();
   }
   else 
   {
      // Buscamos un hueco donde insertar la película
      while ((!feof(f)) && (terminado == 0))
      {
         n = fread(&peli, sizeof(struct s_pelicula), 1, f);
         if ((n > 0) && (peli.borrado == '*'))         // Hemos encontrado un hueco
         {
             fseek(f, -sizeof(struct s_pelicula), SEEK_CUR);         // Retrocedemos
             nuevo.codigo = peli.codigo;                             // Reaprovechamos el código antiguo
             fwrite(&nuevo, sizeof(struct s_pelicula), 1, f);
             terminado = 1;
         }
      }

      if (terminado == 0)             // No se encontró ningún hueco
      {                               
         fseek(f, 0, SEEK_END);            // Escribiremos el registro AL FINAL del archivo
         nuevo.codigo = (*n_regs) + 1;     // El código es el siguiente del último asignado
         fwrite(&nuevo, sizeof(struct s_pelicula), 1, f);
         // Al insertar al final, tenemos que actualizar el índice
         if (nuevo.codigo % TAM_SEG == 0)
         {                  // Crear nueva entrada en el índice
              f = fopen(ARCHIVO_INDICE, "ab");
              if (f == NULL) { printf("Contacto insertado, pero no puedo actualizar el indice\n"); return; }
              entrada_indice.clave_ultimo = nuevo.codigo;
              entrada_indice.direccion_primero = ftell(f);
              entrada_indice.num_segmento = 0;
              fwrite(&entrada_indice, sizeof(struct s_indice), 1, f_ind);
              fclose(f_ind);
         }
         else
         {                  // Modificar última entrada del índice
              f_ind = fopen(ARCHIVO_INDICE, "r+b");
              if (f == NULL) { printf("Contacto insertado, pero no puedo actualizar el indice\n"); return; }
              fseek(f_ind, -sizeof(struct s_indice), SEEK_END);
              fread(&entrada_indice, sizeof(struct s_indice), 1, f_ind);
              entrada_indice.clave_ultimo = nuevo.codigo;
              fseek(f_ind, -sizeof(struct s_indice), SEEK_END);
              fwrite(&entrada_indice, sizeof(struct s_indice), 1, f_ind);
              fclose(f_ind);
         }
      }
      
      fclose(f);
      printf("Contacto insertado con éxito\n");
      (*n_regs)++;
      pulsar_tecla();
   }
}


// Lee por teclado los datos de una película y los devuelve en el parámetro pasado por variable.
// Asigna todos los campos EXCEPTO EL CODIGO.
void introducir_datos_pelicula(struct s_pelicula* peli)
{
   char aux[50];
   
   printf("  Título: ");
   gets(peli->titulo);
   printf("  Director: ");
   gets(peli->director);
   printf("  Reparto: ");
   gets(peli->reparto);
   printf("  Género: ");
   gets(peli->genero);
   printf("  Nacionalidad: ");
   gets(peli->nacionalidad);
   printf("  Duración (minutos): ");
   gets(aux);
   peli->duracion = atoi(aux);
   // Ponemos la marca de "no borrado"
   peli->borrado = '-';
}


// Localiza una película por su código
void buscar_por_codigo(void)
{
    FILE *f, *f_ind;
    struct s_pelicula peli;
    struct s_indice entrada_indice;
    int cod_buscado, n, cont;
    char aux[50];
    
    f = fopen(ARCHIVO_DATOS, "r+b");
    if (f == NULL) { printf("Error al abrir archivo de datos\n"); return; }
    f_ind = fopen(ARCHIVO_INDICE, "rb");
    if (f_ind == NULL) { printf("Error al abrir archivo de índices\n"); return; }
    
    borrar_pantalla();
    printf("BUSCAR UNA PELÍCULA POR CÓDIGO\n");
    printf("Introduzca el código buscado\n");
    gets(aux);
    cod_buscado = atoi(aux);
    
    // Buscamos entrada del indice
    entrada_indice.clave_ultimo = -9999;
    while ((!feof(f_ind)) && (entrada_indice.clave_ultimo < cod_buscado))
        fread(&entrada_indice, sizeof(struct s_indice), 1, f_ind);
    
    if (cod_buscado <= entrada_indice.clave_ultimo)
    {
        // Buscamos película
        fseek(f, entrada_indice.direccion_primero, SEEK_SET);
        cont = 0;
        do
        {
                fread(&peli, sizeof(struct s_pelicula), 1, f);
                cont++;
        }
        while ((cont < TAM_SEG) && (peli.codigo != cod_buscado));
        
        // Película encontrada: mostrar
        if (peli.codigo == cod_buscado)
        {
               printf("DATOS DEL REGISTRO:\n");
               printf("%-3i %s (%s), %s, %s, %i min\n", peli.codigo, peli.titulo, peli.director, peli.nacionalidad, peli.genero, peli.duracion);
               printf("Reparto: %s\n", peli.reparto);
        }
        else
               printf("Película no encontrada en su segmento\n");
    } // if
    else
       printf("Película no encontrada en el índice\n");

    pulsar_tecla();
    fclose(f);
    fclose(f_ind);        
}


// Importa datos de un archivo de texto al archivo de datos.
// Los campos deben estar separados por el carácter ";"
void importar_datos(int *n_regs)
{
    FILE *f, *f_import;
    struct s_pelicula peli;
    int n, i, j, elemento, longitud;
    char cad[100];
    char linea[2000];
    
    // Pedimos el nombre del archivo donde están los datos para importar
    borrar_pantalla();
    printf("Introduzca el nombre del archivo donde están los datos para importar:\n");
    gets(cad);
    
    // Abrimos los archivos de datos
    f_import = fopen(cad, "rt");
    if (f_import == NULL)
    {
        printf("Error. No se puede abrir el archivo %s\n", cad);
        pulsar_tecla();
        return;
    }
    f = fopen(ARCHIVO_DATOS, "ab");
    if (f == NULL)
    {
        printf("Error: no se puede abrir el archivo de datos del programa\n");
        pulsar_tecla();
        return;
    }
    
    // Pedimos confirmación
    printf("ATENCIÓN: Se va a proceder a la importación de datos.\n");
    printf("Si el archivo de datos de importación no tiene el formato correcto\n");
    printf("el archivo de datos del programa puede corromperse.\n");
    printf("Asegúrese de tener una copia de seguridad del archivo de datos del programa\n\n");
    printf("¿Desea continuar el proceso (S/N)");
    gets(cad);
    if (strcmp (cad, "N") == 0)
    {
        printf("Proceso cancelado.\n"); pulsar_tecla();
        fclose(f); fclose(f_import);
        return;
    }
    
    // Realizamos la importación
    while (!feof(f_import))
    {
        // Leemos una línea de texto del archivo
        fgets(linea, 1999, f_import);
        // Procesamos la línea
        j = 0;
        elemento = 1;
        longitud = strlen(linea);
        for (i=0; i<longitud; i++)
        {
              if ((linea[i] == ';') || (linea[i] == '\n'))
              {
                  linea[i] = '\0';
              }
              switch (elemento)
              {
                     case 1: peli.titulo[j] = linea[i]; break;
                     case 2: peli.director[j] = linea[i]; break;
                     case 3: peli.reparto[j] = linea[i]; break;
                     case 4: peli.genero[j] = linea[i]; break;
                     case 5: peli.nacionalidad[j] = linea[i]; break;
                     case 6: cad[j] = linea[i]; break;                     // Duración
              }
              j++;
              if (linea[i] == '\0')
              {
                  if (elemento == 6)
                       peli.duracion = atoi(cad);
                  elemento++;
                  j = 0;
              }
        }
        // Completa el registro añadiendo el código y el campo "borrado"
        peli.borrado = '-';
        (*n_regs)++;
        peli.codigo = (*n_regs);
        // Escribe el registro en el archivo de datos
        fwrite(&peli, sizeof(struct s_pelicula), 1, f);
    } // while
    
    fclose(f_import);
    fclose(f);
    
    printf("Fin del proceso de importación\n");
    pulsar_tecla();
}          

    
// Muestra el contenido del archivo de datos por la pantalla
void listar_datos(void)
{
   FILE *f;
   struct s_pelicula peli;
   int n;
   
   // Abre el archivo en modo de lectura secuencial
   borrar_pantalla();
   f = fopen(ARCHIVO_DATOS, "rb");
   if (f == NULL)
   {
      printf("Error al abrir el archivo de datos");
      pulsar_tecla();
   }
   else
   {
       // Escribe en la pantalla la cabecera de la lista
       while (!feof(f))
       {
           // Lee un registro del archivo
           n = fread(&peli, sizeof(struct s_pelicula), 1, f);
           // Muestra por la pantalla el contenido del registro (si no está marcado como borrado)
           if ((n>0) && (peli.borrado == '-'))
           {
               printf("------------------------------------------------------------------------------\n");
               printf("%-3i %s (%s), %s, %s, %i min\n", peli.codigo, peli.titulo, peli.director, peli.nacionalidad, peli.genero, peli.duracion);
               printf("Reparto: %s\n", peli.reparto);
           }
       } // while
       fclose(f);
       printf("------------------------------------------------------------------------------\n");
       pulsar_tecla();
   } // else

}

// Reconstruye el archivo índice
void reconstruir_indice(void)
{
    FILE *f, *f_ind;
    struct s_pelicula peli;
    struct s_indice ind;
    int registro, segmento, dir_inicial, n;
    

    borrar_pantalla();
    printf("Reconstruyendo el índice...\n");
    
    // Abrimos el archivo de datos en modo secuencial
    f = fopen(ARCHIVO_DATOS, "rb");
    if (f == NULL)
    {
        printf("No se puede abrir el archivo de datos. Operación cancelada.\n");
        pulsar_tecla(); return;
    }
    
    // Creamos un nuevo archivo de índices
    f_ind = fopen("temp", "wb");
    if (f_ind == NULL)
    {
        printf("No se puede crear el nuevo archivo de índices. Operación cancelada.\n");
        pulsar_tecla(); return;
    }
    
    // Recorremos secuencialmente el archivo de datos
    segmento = 1;       // Contador de segmentos
    registro = 0;       // Contador de registros en el segmento
    dir_inicial = 0;    // Dirección inicial del segmento
    while (!feof(f))
    {
        n = fread(&peli, sizeof(struct s_pelicula), 1, f);
        if (n > 0)
        {
           registro++;
           if (registro % TAM_SEG == 0)        // Cambiar de segmento
           {
                // Creamos una entrada en el índice y la grabamos
                ind.num_segmento = segmento;
                ind.direccion_primero = dir_inicial;
                ind.clave_ultimo = peli.codigo;
                fwrite(&ind, sizeof(struct s_indice), 1, f_ind);
                
                // Iniciamos el nuevo segmento
                segmento++;
                dir_inicial = ftell(f);
           }
        } // if
    } // while
    
    // Si el último segmento no está completo, no se habrá grabado
    // su entrada en el archivo de índices, así que lo haremos ahora
    if (registro % TAM_SEG != 0)
    {
        // Creamos una entrada en el índice y la grabamos
        ind.num_segmento = segmento;
        ind.direccion_primero = dir_inicial;
        ind.clave_ultimo = peli.codigo;
        fwrite(&ind, sizeof(struct s_indice), 1, f_ind);
    }
 
    // Cerramos y renombramos el índice
    fclose(f);
    fclose(f_ind);
    remove(ARCHIVO_INDICE);
    rename("temp", ARCHIVO_INDICE);
    printf("Proceso concluido con éxito.\n");
    pulsar_tecla();       
}


// Muestra el contenido del archivo de índices
// (SOLO CON PROPÓSITOS DE DEPURACIÓN)
void mostrar_indice(void)
{
   FILE *f;
   struct s_indice entrada_indice;
   int n;
   
   // Abre el archivo en modo de lectura secuencial
   borrar_pantalla();
   f = fopen(ARCHIVO_INDICE, "rb");
   if (f == NULL)
   {
      printf("Error al abrir el archivo de índices");
      pulsar_tecla();
   }
   else
   {
       printf("SEG.  DIR.  CLAVE\n");
       printf("-----------------\n");
       while (!feof(f))
       {
           // Lee un registro del archivo
           n = fread(&entrada_indice, sizeof(struct s_indice), 1, f);
           // Muestra por la pantalla el contenido del registro
           if (n>0)
           {
               printf("%-3i   %-5i  %-4i\n", entrada_indice.num_segmento, entrada_indice.direccion_primero, entrada_indice.clave_ultimo);
           }
       } // while
       fclose(f);
       pulsar_tecla();
   } // else
    
}
