#include <stdio.h>
#include <string.h>

int main(void)
{
	char texto[100];
	int i;
	int num_palabras;				// Contador del numero de palabras

	printf("Introduzca un texto: ");
	gets(texto);

	if (strlen(texto) > 0) 		// Si el texto contiene caracteres...
	{
		printf("Palabra 1 - ");	// ...escribimos el primer rotulo de palabra
		num_palabras = 1;			// ...e inicializamos el contador de palabras
	}
	else								// Si el texto no contiene caracteres...
		num_palabras = 0;			// ...ponemos el contador de palabras a 0

	for (i=0; i<strlen(texto); i++)	// Recorremos los caracteres del texto
	{
		if (texto[i] != ' ')				// Si el caracter i no es un espacio...
			printf("%c", texto[i]);		//...lo reproducimos exactamente igual
		else
		{										// Si el caracter es un espacio...
			num_palabras++;				// Contamos una palabra mas
			printf("\nPalabra %i - ", num_palabras);
		}
	}
   // Al final, mostramos el numero total de palabras
	printf("\nTotal: %i palabras", num_palabras);

	return 0;
}

