#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct s_reg
{
    char apellidos[100];
    char nombre[50];
    char titulo[100];
    char editorial[30];
    char cdu[15];
    char borrado;
    int id;
};

int main()
{
    FILE *fd, *fo;
    struct s_reg reg;
    char linea[500];
    char palabra[100];
    int i, j, numpal, cont, aleat;

    // Mensaje informativo de bienvenida
	printf("Fundamentos de programacion - 1º ASI\n\n");
	printf("Este programa convierte el archivo de texto libros.txt\n");
	printf("en un archivo binario libros.dat con el formato adecuado\n");
	printf("para el ejercicio obligatorio del tema 4.\n\n\n");
	
	printf("Va a comenzar la conversión. ");
	getchar();
	
    // Abrir archivos
	fo = fopen("libros.txt", "rt");
	fd = fopen("libros.dat", "wb");
	if ((fo == NULL) || (fd == NULL))  { printf("Error al abrir los archivos\n"); exit(1); }
	
	// Recorrer archivo de texto
	printf("\nConvirtiendo archivo...\n");
	cont = 1;
	while (!feof(fo))
	{ 
  	   // Leemos una l�ea completa
	   fgets(linea, 499, fo);
	   if (feof(fo)) break;
	   if (strlen(linea) < 5) break;
	   // Procesamos la línea. 
	   j = 0;
	   numpal = 1;
       strcpy(palabra, "");
	   for (i = 0; i<=strlen(linea); i++)
       {
           // Las palabras está separadas por el car�ter "*"   
           if ((linea[i] != '*') && (linea[i] != '\n') && (linea[i] != '\0')) { 
                      palabra[j] = linea[i];
                      j++;
           }
           else {                   // Fin de una palabra
                      palabra[j] = '\0';
                      //printf("numpal = %i, palabra = %s\n", numpal, palabra);
                      if (numpal == 1) strcpy(reg.apellidos, palabra);
                      if (numpal == 2) strcpy(reg.nombre, palabra);
                      if (numpal == 3) strcpy(reg.titulo, palabra);
                      if (numpal == 4) strcpy(reg.editorial, palabra);
                      if (numpal == 5) strcpy(reg.cdu, palabra);
                      reg.borrado = '-';
                      reg.id = cont;
                      numpal++;
                      j = 0;
           }                      
	   }
       // Escribimos el registro en el archivo binario
       fwrite(&reg, sizeof(struct s_reg), 1, fd);
        aleat = rand() % 10 + 1;
        cont = cont + aleat;
    }       	
	fclose(fd);
	fclose(fo);
	
	// Mostramos el contenido del archivo binario para ver si es correcto
	printf("\n\nConversión finalizada\n\n");
	printf("Mostraremos ahora el contenido del archivo binario. ");
	getchar();
	
	fd = fopen("libros.dat", "rb");
	if (fd == NULL) { printf("No puedo abrir el archivo\n"); exit(1); }
	while (!feof(fd))
	{
	   i = fread(&reg, sizeof(struct s_reg), 1, fd);
	   if (i != 0)
	      printf("%i: %s\n", reg.id, reg.titulo);
    }
    fclose(fd);
    
    printf("\n\n");
    getchar();
	return 0;
}

