// EJERCICIOS DE FUNDAMENTOS DE PROGRAMACION
// TEMA 4: FICHEROS
// DESENCRIPTADOR DE ARCHIVOS DE TEXTO MEDIANTE EL MÉTODO CÉSAR

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char desencriptar(char c, int clave);


int main(void)
{
   FILE *f, *fd;
   char arch[50], aux[50];
   int clave;
   char c, c_des;
   
   // Leemos los nombres de los archivos
   printf("\nEste programa desencripta archivos de texto mediante el Método César\n\n");
   printf("Nombre del archivo encriptado: ");
   gets(arch);

   // Leemos la clave de encriptación
   printf("Clave de desencriptación: ");
   gets(aux);
   clave = atoi(aux);

   // Abrimos el archivo en modo lectura
   f = fopen(arch, "rt");
   if (f == NULL)
   {
         printf("Error al abrir el archivo %s\n", arch);
         exit(1);
   }
   
   printf("Desencriptando el archivo...\n");
   
   // Recorremos el archivo carácter por carácter
   while (!feof(f))
   {
      c = fgetc(f);                       // Leemos un carácter
      c_des = desencriptar(c, clave);	  // Desencriptamos ese carácter
      printf("%c", c_des);		  // Mostramos en la pantalla el carácter desencriptado
   }
   
   printf("\n\nFin del archivo\n\n");
   system("pause");
   return 0;
}


// Esta función recibe un carácter encriptado y una clave de desencriptación, y devuelve el carácter
// desencriptado según el método César. Para variar el método de desencriptación, basta con
// modificar esta función (el resto del programa puede seguir igual)
char desencriptar(char c, int clave)
{
	char cifr;
	int n;

	// Primero comprobaremos que el carácter es alfabético. Sólo desencriptaremos
 	// caracteres alfabéticos (aunque esto se puede cambiar si se quiere)
	if ((c >= 'A') && (c <= 'Z'))	// Mayúsculas (hay que desencriptar)
	{
		n = c - clave;
		if (n < 'A') {
			n = n - 'Z';
			n = (n % 26) + 'Z';
		}
		cifr = n;
	}
	else if  ((c >= 'a') && (c <= 'z'))	// Minúsculas (desencriptar)
	{
		n = c - clave;
		if (n < 'a') {
			n = n - 'z';
			n = (n % 26) + 'z';
		}
		cifr = n;
	}
	else	// Otros caracteres (no hay que desencriptar)
	{
		cifr = c;	// Lo dejamos igual
	}

	return cifr;
}




