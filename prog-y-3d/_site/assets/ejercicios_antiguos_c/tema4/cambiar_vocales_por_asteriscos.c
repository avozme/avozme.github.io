// EJERCICIOS DE FUNDAMENTOS DE PROGRAMACION
// TEMA 4: FICHEROS
// SUSTITUIR VOCALES POR ASTERISCOS EN UN FICHERO (VERSION SECUENCIAL)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(void)
{
	FILE *f, *f_dest;
	char nom_arch[100], c;

	printf("1º ASI / Fundamentos de Programación / Tema 4\n");
	printf("SUSTITUIR VOCALES POR ASTERISCOS EN UN FICHERO (versión secuencial)\n");
	printf("Introduce el nombre del fichero: ");
	gets(nom_arch);

	// Abrimos el archivo de origen
	f = fopen(nom_arch, "rt");
	if ( f == NULL ) { printf("Error al abrir el archivo %s\n", nom_arch); exit(1); }
	// Creamos un archivo temporal donde iremos construyendo el archivo de destino
	f_dest = fopen("temporal", "wt");
	if ( f_dest == NULL ) { printf("Error al crear archivo temporal\n"); exit(1); }

	// Recorremos el archivo
	while (!feof(f))
	{
		c = fgetc(f);	// Leemos un carácter del archivo
		if (c != EOF)
		{
			if ((c == 'a') || (c == 'e') || (c == 'i') || (c == 'o') || (c == 'u') ||
			    (c == 'A') || (c == 'E') || (c == 'I') || (c == 'O') || (c == 'U'))
				// Si en el archivo original hay una vocal, escribimos '*' en el archivo nuevo
				fputc('*', f_dest);
			else
				// Si hay cualquier otro carácter, lo copiamos igual al archivo nuevo
				fputc(c, f_dest);
		}
	}
	fclose(f); fclose(f_dest);
	
	// Borramos el archivo de origen y renombramos el temporal
	remove(nom_arch);
	rename("temporal", nom_arch);
	printf("Se han sustituido las vocales por asteriscos con éxito\n");

	return 0;
}

