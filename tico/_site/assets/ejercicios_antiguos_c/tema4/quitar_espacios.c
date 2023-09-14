#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
	int i;
	FILE *fich;
	char txt[500];

	printf("Este programa lee un texto por teclado y lo envía a un archivo de texto\n");
	printf("sustituyendo todos los espacios por saltos de línea.\n\n");

	printf("Introduzca un texto: ");
	gets(txt);

	// Abrir el archivo para escritura
	fich = fopen("quitar_espacios.txt", "wt");
	if (fich == NULL) {
		printf("Error al abrir el archivo");
		exit(1);
	}
	
	// Recorremos la cadena carácter por carácter
	for (i=0; i<strlen(txt); i++) 
	{
		if (txt[i] == ' ')		// Si el carácter es un espacio...
			fputc('\n', fich);	// ... escribimos un salto de línea
		else				// Si es cualquier otro carácter...
			fputc(txt[i], fich);	// ... escribimos ese carácter
	}
	fclose(fich);

	printf("Se ha generado el archivo quitar_espacios.txt\n\n");

	return 0;
}

