// EJERCICIOS DE FUNDAMENTOS DE PROGRAMACION
// TEMA 6: FICHEROS
// AGENDA DE CONTACTOS

#include <stdio.h>

#define ARCHIVO_DATOS "agenda.dat"

struct s_contacto
{
   char nombre[100];
   char telef[10];
   char direc[100];
   char email[100];
   char borrado;
};

void borrar_pantalla(void);
void pulsar_tecla(void);
int menu(void);
void insertar_datos_final(void);
void insertar_datos_hueco(void);
void listar_datos(void);
void borrar_registro(void);
void modificar_registro(void);
void buscar_por_nombre(void);
void buscar_por_numero(void);
void ordenar(void);
void compactar(void);
void introducir_datos_contacto(struct s_contacto* contacto);


int main(void)
{
   int opc;
   
   do
   {
      borrar_pantalla();
      opc = menu();
      switch (opc)
      {
        case 1: insertar_datos_final(); break;
        case 2: insertar_datos_hueco(); break;
        case 3: listar_datos(); break;
        case 4: modificar_registro(); break;
        case 5: borrar_registro(); break;
   	    case 6: buscar_por_nombre(); break;
	    case 7: buscar_por_numero(); break;
 	    case 8: ordenar(); break;
      }
   }
   while (opc != 0);     // 0 es salir
   
   // Antes de salir del programa, compactamos el archivo de datos
   printf("Compactando... Esta operación puede tardar unos segundos.\n");
   compactar();
   
   system("PAUSE");
   return 0;
}

// Borra la pantalla de texto
void borrar_pantalla(void)
{
   int i;
   for (i=0; i<50; i++)
      printf("\n\n");
}

// Muestra el texto "pulse una tecla para continuar" y espera a que el usuario pulse una tecla
void pulsar_tecla(void)
{
   printf("Pulse Intro para continuar...\n");
   getchar();
}


// Muestra el men y lee la opciï¿½ del usuario. Devuelve el cï¿½igo de la opciï¿½ elegida.
int menu(void)
{
   int opc;
   char aux[50];
   
   // Muestra el men
   printf("+----------------------------------+\n");
   printf("|   AGENDA DE CONTACTOS - MENÚ     |\n");
   printf("+----------------------------------+\n");
   printf("|      1. Insertar al final        |\n");
   printf("|      2. Insertar en un hueco     |\n");
   printf("|      3. Listar agenda            |\n");
   printf("|      4. Modificar contacto       |\n");
   printf("|      5. Borrar contacto          |\n");
   printf("|      6. Buscar por nombre        |\n");
   printf("|      7. Buscar por número        |\n");
   printf("|      8. Ordenar                  |\n");
   printf("|      0. Salir                    |\n");
   printf("+----------------------------------+\n");
   
   // Leer y devolver la selecciï¿½ del usuario
   do
   {
      printf("       Elija una opción (0-8): ");
      gets(aux);
      opc = atoi(aux);
   }
   while ((opc < 0) && (opc > 7));
   
   return opc;
}

// Añade un contacto al final del archivo de datos
void insertar_datos_final(void)
{
   FILE *f;
   struct s_contacto nuevo;
   
   // Introducir por teclado los datos del nuevo contacto
   borrar_pantalla();
   printf("INSERTAR NUEVO CONTACTO\n");
   printf("Introduzca los datos del contacto.\n");
   introducir_datos_contacto(&nuevo);
   
   // Abrir el archivo para añadir datos en él (modo secuencial, para agregar al final)
   f = fopen(ARCHIVO_DATOS, "ab");
   if (f == NULL) 
   {
      printf("Error al abrir el archivo de datos!");
      pulsar_tecla();
   }
   else 
   {
      // Escribe el registro en el archivo y lo cierra
      fwrite(&nuevo, sizeof(struct s_contacto), 1, f);
      fclose(f);
      printf("Contacto insertado con ï¿½ito\n");
      pulsar_tecla();
   }
}


// Añade un contacto al final del archivo de datos
void insertar_datos_hueco(void)
{
   FILE *f;
   struct s_contacto nuevo, contacto;
   int n, hueco_encontrado;
   
   // Introducir por teclado los datos del nuevo contacto
   borrar_pantalla();
   printf("INSERTAR NUEVO CONTACTO\n");
   printf("Introduzca los datos del contacto.\n");
   introducir_datos_contacto(&nuevo);
   
   // Abrir el archivo para añadir datos en él (modo directo)
   f = fopen(ARCHIVO_DATOS, "r+b");
   if (f == NULL) 
   {
      printf("Error al abrir el archivo de datos!");
      pulsar_tecla();
      return;
   }

   // Buscar un hueco donde insertar el dato
   hueco_encontrado = 0;
   while ((!feof(f)) && (hueco_encontrado == 0))
   {
      n = fread(&contacto, sizeof(struct s_contacto), 1, f);
      if ((n > 0) && (contacto.borrado == 'S'))      // Hemos encontrado un hueco
            hueco_encontrado = 1;
   }
   
   if (hueco_encontrado == 1)
   {  // Si se encontró un hueco, insertamos el dato en él
      fseek(f, -sizeof(struct s_contacto), SEEK_CUR);      // Hacemos retroceder el cursor
      fwrite(&nuevo, sizeof(struct s_contacto), 1, f);     // Escribimos el registro
   }
   else                                                   
   {   // Si no se han encontrado huecos, insertamos el dato al final del archivo
      printf("\n¡NO EXISTEN HUECOS!.\n");
      printf("El registro se insertará al final del archivo...\n");
      fseek(f, 0, SEEK_END);                               // Nos desplazamos al final
      fwrite(&nuevo, sizeof(struct s_contacto), 1, f);      // Escribimos el registro
   }

   printf("Contacto insertado con éxito\n");
   fclose(f);
   pulsar_tecla();
}


   
void listar_datos(void)
{
   FILE *f;
   struct s_contacto contacto;
   int n;
   
   // Abre el archivo en modo de lectura secuencial
   f = fopen(ARCHIVO_DATOS, "rb");
   if (f == NULL)
   {
      printf("Error al abrir el archivo de datos");
      pulsar_tecla();
   }
   else
   {
       // Escribe en la pantalla la cabecera de la lista
       borrar_pantalla();
       printf("NOMBRE               DIRECCIï¿½            TELï¿½ONO    E-MAIL\n");
       printf("-------------------------------------------------------------------------\n");
       while (!feof(f))
       {
           // Lee un registro del archivo
           n = fread(&contacto, sizeof(struct s_contacto), 1, f);
           // Muestra por la pantalla el contenido del registro (si no está marcado como borrado)
           if ((n>0) && (contacto.borrado == 'N'))
               printf("%-20s %-20s %-11s %-15s\n", contacto.nombre, contacto.direc, contacto.telef, contacto.email);
       } // while
       fclose(f);
       pulsar_tecla();
   } // else
}
               


void borrar_registro(void)
{
   FILE *f;
   struct s_contacto contacto;
   int encontrado, num_reg, n;
   char nombre[100];
   
   // Leer por teclado el nombre que se quiere borrar
   borrar_pantalla();
   printf("BORRAR REGISTRO\n");
   printf("Introduzca el nombre del contacto que desea borrar: ");
   gets(nombre);
   
   // Abrimos el archivo en modo directo
   f = fopen(ARCHIVO_DATOS, "r+b");
   if (f == NULL)
   {
      printf("Error al abrir el archivo de datos\n");
      pulsar_tecla();
   }
   else
   {
      // Recorre el archivo de forma secuencial buscando el registro que se quiere borrar
      encontrado = 0;
      num_reg = 0;
      while (!feof(f))
      {
         n = fread(&contacto, sizeof(struct s_contacto), 1, f);
         if (n>0) num_reg++;                                    // Contador del n de registros leidos    
         if ((n>0) && (strcmp(contacto.nombre, nombre) == 0))   // Hemos encontado el registro
         {
            // Hemos encontrado el registro que hay que borrar.
            encontrado++;
            // Lo marcamos como borrado
            contacto.borrado = 'S';
            // Colocamos el cursor justo al principio del registro actual
            fseek(f, (num_reg - 1) * sizeof(struct s_contacto), SEEK_SET);
            // Escribimos el registro (ya marcado como borrado) en el archivo
            fwrite(&contacto, sizeof(struct s_contacto), 1, f);
            // Volvemos a dejar el cursor al final del registro
            fseek(f, num_reg * sizeof(struct s_contacto), SEEK_SET);
         }  
      }
      fclose(f);
      printf("Se econtraron y borraron %i registros\n", encontrado);
      pulsar_tecla();
   } //else
}

void modificar_registro(void)
{
   FILE *f;
   struct s_contacto contacto;
   int encontrado, num_reg, n;
   char nombre[100];
   
   // Leer por teclado el nombre que se quiere borrar
   borrar_pantalla();
   printf("MODIFICAR REGISTRO\n");
   printf("Introduzca el nombre del contacto que desea modificar: ");
   gets(nombre);
   
   // Abrimos el archivo en modo directo
   f = fopen(ARCHIVO_DATOS, "r+b");
   if (f == NULL)
   {
      printf("Error al abrir el archivo de datos\n");
      pulsar_tecla();
   }
   else
   {
      // Recorre el archivo de forma secuencial buscando el registro que se quiere modificar
      encontrado = 0;
      num_reg = 0;
      while (!feof(f))
      {
         n = fread(&contacto, sizeof(struct s_contacto), 1, f);
         if (n>0) num_reg++;                                    // Contador del n de registros leidos    
         if ((n>0) && (strcmp(contacto.nombre, nombre) == 0))   // Hemos encontado el registro
         {
            // Hemos encontrado el registro que hay que modificar.
            encontrado++;
            // Le pedimos al usuario que vuelva a introducir los datos por teclado
            printf("Registro encontrado. Introduzca los nuevos datos:\n");
            introducir_datos_contacto(&contacto);
            // Colocamos el cursor justo al principio del registro actual
            fseek(f, (num_reg - 1) * sizeof(struct s_contacto), SEEK_SET);
            // Escribimos la estructura (que ya contiene los datos nuevos) en el archivo
            fwrite(&contacto, sizeof(struct s_contacto), 1, f);
            // Volvemos a dejar el cursor al final del registro
            fseek(f, num_reg * sizeof(struct s_contacto), SEEK_SET);
         }  
      }
      fclose(f);
      printf("Se modificaron %i registros\n", encontrado);
      pulsar_tecla();
   } //else
}


// Busca un registro por nombre (bsqueda secuencial)
void buscar_por_nombre(void)
{
   char nombre[100];
   struct s_contacto contacto;
   FILE *f;
   int encontrado, n;
   
   // Lee el nombre buscado por teclado
   printf("Bï¿½QUEDA POR NOMBRE\n");
   printf("Introduzca el nombre que quiere buscar: ");
   gets(nombre);
   
   // Abre el archivo para lectura secuencial
   f = fopen(ARCHIVO_DATOS, "rb");
   if (f == NULL) 
   {
      printf("Error al abrir el archivo\n");
      pulsar_tecla();
   }
   else
   {
       encontrado = 0;
       while (!feof(f))
       {
          n = fread(&contacto, sizeof(struct s_contacto), 1, f);
          if ((n>0) && (strcmp(contacto.nombre, nombre) == 0) && (contacto.borrado == 'N'))  // Hemos encontrado el registro
          {
             // Mostrar datos del registro por la pantalla
	     encontrado = 1;
	     printf("REGISTRO ENCONTRADO:\n");
             printf("Nombre: %s\n", contacto.nombre);
             printf("Direcciï¿½: %s\n", contacto.direc);
             printf("Telï¿½ono: %s\n", contacto.telef);
             printf("e-mail: %s\n", contacto.email);
	     pulsar_tecla();
	  }
       }
       fclose(f);
       if (encontrado == 0)
       {
          printf("Registro no encontrado.\n");
	  pulsar_tecla();
       }
    }
}


// Busca un registro por nÃºmero (bÃºsqueda directa)
void buscar_por_numero(void)
{
   int numero;
   char aux[50];
   struct s_contacto contacto;
   FILE *f;
   int encontrado, n;
   
   // Lee el nombre buscado por teclado
   printf("Bï¿½QUEDA POR NOMBRE\n");
   printf("Introduzca el nÃºmero del registro que quiere buscar: ");
   gets(aux);
   numero = atoi(aux);
   
   // Abre el archivo para acceso directo
   f = fopen(ARCHIVO_DATOS, "r+b");
   if (f == NULL) 
   {
      printf("Error al abrir el archivo\n");
      pulsar_tecla();
   }
   else
   {
       encontrado = 0;
       // Coloca el cursor en la posiciÃ³n del registro solicitado
       fseek(f, (numero - 1) * sizeof(struct s_contacto), SEEK_SET);
       // Lee el registro situado en esa posiciÃ³n
       n = fread(&contacto, sizeof(struct s_contacto), 1, f);
       // Comprueba que se haya leÃ­do algo
       if ((n>0) && (contacto.borrado == 'N'))
       {
             // Mostrar datos del registro por la pantalla
	     encontrado = 1;
	     printf("REGISTRO ENCONTRADO:\n");
             printf("Nombre: %s\n", contacto.nombre);
             printf("Direcciï¿½: %s\n", contacto.direc);
             printf("Telï¿½ono: %s\n", contacto.telef);
             printf("e-mail: %s\n", contacto.email);
	     pulsar_tecla();
       }
       fclose(f);
       if (encontrado == 0)
       {
          printf("Registro no encontrado.\n");
	  pulsar_tecla();
       }
    }
}

// Ordena el archivode datos alfabéticamente (por el campo nombre)
void ordenar(void)
{
   FILE *f;
   struct s_contacto cj, cj1;
   int n, i, j, n_regs;
   
   // Abre el archivo en modo directo
   f = fopen(ARCHIVO_DATOS, "r+b");
   if (f == NULL)
   {
      printf("Error al abrir el archivo de datos\n");
      pulsar_tecla();
      return;
   }

   // Contamos el número de registros del archivo
   fseek(f, 0, SEEK_END);
   n_regs = ftell(f) / sizeof(struct s_contacto);

   // Hacemos un doble bucle sobre el archivo para ejecutar una bubuja
   printf("Ordenando... Esta operación puede tardar unos segundos.\n");
   for (i = 0; i < n_regs; i++)
   {
      for (j = n_regs-1; j >= i; j--)
      {
          // Leemos el registro que ocupa la posición j del archivo
          fseek(f, j * sizeof(struct s_contacto), SEEK_SET);
          fread(&cj, sizeof(struct s_contacto), 1, f);
          // Leemos el registro que ocupa la posición (j-1) del archivo
          fseek(f, (j-1) * sizeof(struct s_contacto), SEEK_SET);
          fread(&cj1, sizeof(struct s_contacto), 1, f);

          // Comprobamos si están ordenados
          if ( strcmp(cj.nombre, cj1.nombre) < 0)
          {   // No están ordenados: hay que INTERCAMBIARLOS
              // Escibimos el registro que estaba en (j-1) en la posición j
              fseek(f, j * sizeof(struct s_contacto), SEEK_SET);
              fwrite(&cj1, sizeof(struct s_contacto), 1, f);
              // Escribimos el registro que estaba en j en la posición (j-1)
              fseek(f, (j-1) * sizeof(struct s_contacto), SEEK_SET);
              fwrite(&cj, sizeof(struct s_contacto), 1, f);
          } // if
       } // for j
   } // for i

   fclose(f);
   
   printf("El archivo ha quedado ordenado alfabéticamente.\n");
   pulsar_tecla();
}   

// Compacta el archivo de datos, eliminando los huecos que pudieran existir
// después de haber hecho varias operaciones de borrado
void compactar(void)
{
   FILE *f_orig, *f_nuevo;
   struct s_contacto contacto;
   int n;
   
   // Abre el archivo en modo de lectura secuencial
   f_orig = fopen(ARCHIVO_DATOS, "rb");
   if (f_orig == NULL)
   {
      printf("Error al abrir el archivo de datos\n");
      pulsar_tecla();
      return;
   }
   
   // Abre el archivo nuevo, en el que se creará una copia del archivo de datos
   // eliminando los huecos
   f_nuevo = fopen("temporal", "wb");
   if (f_nuevo == NULL)
   {
      printf("Error al crear el archivo temporal\n");
      pulsar_tecla();
      return;
   }
   
   // Recorre el archivo de datos, creando una copia en el archivo temporal.
   // (Se copiarán todos los registros excepto los marcados como borrados)
   while (!feof(f_orig))
   {
       // Lee un registro del archivo
       n = fread(&contacto, sizeof(struct s_contacto), 1, f_orig);
       // Si no está borrado, lo pasa al archivo temporal
       if ((n>0) && (contacto.borrado == 'N'))
           fwrite(&contacto, sizeof(struct s_contacto), 1, f_nuevo);
   } // while
   fclose(f_orig);
   fclose(f_nuevo);
   
   // Elimina el archivo original y renombra el temporal, que a partir de ahora
   // será el nuevo archivo de datos (compactado)
   remove(ARCHIVO_DATOS);
   rename("temporal", ARCHIVO_DATOS);
}

// Lee por teclado los datos de un contacto y los devuelve en el parï¿½etro pasado por variable
void introducir_datos_contacto(struct s_contacto* contacto)
{
   printf("  Nombre: ");
   gets(contacto->nombre);
   printf("  Direcciï¿½: ");
   gets(contacto->direc);
   printf("  Telï¿½ono: ");
   gets(contacto->telef);
   printf("  E-mail: ");
   gets(contacto->email);
   // Ponemos la marca de "no borrado"
   contacto->borrado = 'N';
}   
