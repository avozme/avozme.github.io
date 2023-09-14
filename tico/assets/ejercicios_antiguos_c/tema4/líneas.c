// Fundamentos de programación
// Problemas del tema 4 (ficheros)
// MOSTRAR POR PANTALLA LAS LÍNEAS DE UN FICHERO QUE CONTENGAN UNA CADENA DADA

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
	FILE *f;
	char arch[50], palabra[50], linea[1000], *aux;
	int cont = 0, cont_lin = 0;

	printf("\nEste programa abre un archivo de texto y muestra por la pantalla\n");
	printf("sólo las líneas que contengan una palabra introducida por el usuario\n\n");

	// Leemos los nombres de los archivos
	printf("Introduzca el nombre del archivo: ");
	gets(arch);
	printf("Introduzca la palabra buscada: ");
	gets(palabra);

	// Abrimos el archivo de origen (modo lectura)
	f = fopen(arch, "rt");
	if (f == NULL)
	{
		printf("Error al abrir el archivo %s\n", arch);
		exit(1);
	}
	
	// Recorremos el archivo línea por línea
	printf("Procesando el archivo...\n\n");
	while (!feof(f))
	{
		fgets(linea, 999, f);	// Leemos una línea
		cont_lin++;
		aux = strstr(linea, palabra);	// Comprobamos si "palabra" está contenida en "línea"
		if (aux != NULL) {		// ¡Sí que lo está!
			// Mostramos la línea en la pantalla
			printf("Línea %i ---> %s", cont_lin, linea);	
			cont++;
		}
	}
	fclose(f);

	// Abrimos el segundo archivo de origen (lectura) SIN CERRAR el archivo de destino

	printf("\n\nFin del archivo\nLa palabra '%s' se ha encontrado %i veces.\n\n", palabra, cont);

	return 0;
}

