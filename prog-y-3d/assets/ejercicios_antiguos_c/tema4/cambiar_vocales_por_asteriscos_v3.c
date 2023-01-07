// EJERCICIOS DE FUNDAMENTOS DE PROGRAMACION
// TEMA 4: FICHEROS
// SUSTITUIR VOCALES POR ASTERISCOS EN UN FICHERO (VERSION DIRECTA CON BARRA DE PROGRESO)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(void)
{
	FILE *f;
	char nom_arch[100], c;
	long int tam, pos = 0;

	printf("1º ASI / Fundamentos de Programación / Tema 4\n");
	printf("SUSTITUIR VOCALES POR ASTERISCOS EN UN FICHERO (versión directa con barra de progreso)\n");
	printf("Introduce el nombre del fichero: ");
	gets(nom_arch);

	// Abrimos el archivo de origen
	f = fopen(nom_arch, "r+t");
	if ( f == NULL ) { printf("Error al abrir el archivo %s\n", nom_arch); exit(1); }

	// AVeriguamos el tamaño del archivo
	fseek(f, 0, SEEK_END);
	tam = ftell(f);
	fseek(f, 0, SEEK_SET);

	// Recorremos el archivo
	while (!feof(f))
	{
		c = fgetc(f);	// Leemos un carácter del archivo
		pos++;
		if (pos % 10 == 0) {
			printf("Procesando archivo: %i%%", pos * 100 / tam);
			printf("%c", 13);	
		}

		if (c != EOF)
		{
			if ((c == 'a') || (c == 'e') || (c == 'i') || (c == 'o') || (c == 'u') ||
			    (c == 'A') || (c == 'E') || (c == 'I') || (c == 'O') || (c == 'U'))
			{
				// Hemos leido una vocal. Vamos a retroceder y a sobreescribirla con un '*'
				fseek(f, -1, SEEK_CUR);
				fputc('*', f);
			}
		}
	}
	fclose(f);
	printf("Se han sustituido las vocales por asteriscos con éxito\n");

	return 0;
}

