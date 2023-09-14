#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
	FILE *fich;
	char car;

	printf("\nEste programa lee un archivo de texto y lo muestra en la pantalla\n");
	printf("sustituyendo los saltos de línea por espacios.\n\n");

	// Abrir el archivo para lectura
	printf("Mostrando el contenido del archivo quitar_espacios.txt:\n\n");
	fich = fopen("quitar_espacios.txt", "rt");
	if (fich == NULL) {
		printf("Error al abrir el archivo");
		exit(1);
	}
	
	// Recorremos el archivo carácter por carácter
	while (!feof(fich))
	{
		car = fgetc(fich);		// Leemos un carácter del archivo
		if (car == '\n')		// Si el carácter es un salto de línea...
			printf(" ");		// ... escribimos un espacio en la pantalla
		else				// Si es cualquier otro carácter...
			printf("%c", car);	// ... escribimos ese carácter en la pantalla
	}
	fclose(fich);

	printf("\n\nSe ha terminado de procesar el archivo\n\n");

	return 0;
}

