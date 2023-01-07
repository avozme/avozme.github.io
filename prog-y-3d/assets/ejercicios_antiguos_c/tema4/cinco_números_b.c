#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int i, suma, n[5];
	float media;
	FILE *fich;
	char txt[50];

	printf("Este programa lee los números almacenados en un archivo de texto y los muestra por pantalla\n\n");
	printf("El archivo de texto debe ser el generado por el ejercicio anterior\n\n");

	// Parte 1: abrir el archivo para lectura
	printf("Abriendo el archivo cinco_números.txt...\n");
	fich = fopen("cinco_números.txt", "r");
		if (fich == NULL) {
		printf("Error al abrir el archivo para lectura");
		exit(1);
	}
	
	// Parte 2: leer los datos del archivo
	fgets(txt, 49, fich);			// Lee el texto "Los números son"
	for (i=0; i<5; i++) {
		fscanf(fich, "%i\n", &n[i]);	// Lee los números
	}
	fgets(txt, 12, fich);			// Lee el texto "La suma es" (12 caracteres)
	fscanf(fich, "%i\n", &suma);		// Lee el valor de la suma
	fgets(txt, 13, fich);			// Lee el texto "La media es" (13 caracteres)
	fscanf(fich, "%f", &media);		// Lee el valor de la media
	fclose(fich);

	// Parte 3: mostrar los datos en la pantalla
	printf("Los datos leíos del archivo son:\n");
	for (i=0; i<4; i++) {
		printf("%i - ", n[i]);
	}
	printf("%i - %f\n", suma, media);

	return 0;
}

