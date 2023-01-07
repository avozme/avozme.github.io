#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
	FILE *f1, *f2, *fdest;
	char arch1[50], arch2[50], arch_dest[50];
	char car;

	printf("\nEste programa concatena dos archivos de texto\n\n");
	printf("Versión 1: copiando carácter a carácter\n\n");

	// Leemos los nombres de los archivos
	printf("Archivos de ORIGEN:\n");
	printf("  Introduzca el nombre del primer archivo: ");
	gets(arch1);
	printf("  Introduzca el nombre del segundo archivo: ");
	gets(arch2);
	printf("Archivo de DESTINO:\n");
	printf("  Introduzca el nombre del archivo donde se realizará la concatenación: ");
	gets(arch_dest);

	// Abrimos el primer archivo de origen (lectura) y el de destino (escritura)
	f1 = fopen(arch1, "rt");
	fdest = fopen(arch_dest, "wt");
	if ((f1 == NULL) || (fdest == NULL))
	{
		if (f1 == NULL) printf("Error al abrir el archivo %s\n", arch1);
		if (fdest == NULL) printf("Error al abrir el archivo %s\n", arch_dest);
		exit(1);
	}
	
	// Recorremos el archivo 1 carácter por carácter, enviándolos todos al archivo de destino
	while (!feof(f1))
	{
		car = fgetc(f1);
		fputc(car, fdest);
	}
	// Cerramos el archivo 1
	fclose(f1);

	// Abrimos el segundo archivo de origen (lectura) SIN CERRAR el archivo de destino
	f2 = fopen(arch2, "rt");
	if (f2 == NULL)
	{
		printf("Error al abrir el archivo %s\n", arch2);
		exit(1);
	}
	
	// Recorremos el archivo 2 carácter por carácter, enviándolos todos al archivo de destino
	while (!feof(f2))
	{
		car = fgetc(f2);
		fputc(car, fdest);
	}
	// Cerramos el archivo 2 y el archivo de destino
	fclose(f1);
	fclose(fdest);

	printf("El archivo %s se ha generado correctamente\n\n", arch_dest);

	return 0;
}

