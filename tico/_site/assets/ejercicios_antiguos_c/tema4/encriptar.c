// EJERCICIOS DE FUNDAMENTOS DE PROGRAMACION
// TEMA 4: FICHEROS
// ENCRIPTADOR DE ARCHIVOS DE TEXTO MEDIANTE EL MÉTODO CÉSAR

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char encriptar(char c, int clave);


int main(void)
{
   FILE *f, *fd;
   char arch[50], arch_dest[50], aux[50];
   int clave;
   char c, c_enc;
   
   // Leemos los nombres de los archivos
   printf("\nEste programa encripta archivos de texto mediante el Método César\n\n");
   printf("Nombre del archivo a encriptar: ");
   gets(arch);
   strcpy(arch_dest, arch);	// El archivo de destino tendrá el mismo nombre que el original...
   strcat(arch_dest, ".cfr");	// ...añadiendo la extensión ".cfr"

   // Leemos la clave de encriptación
   printf("Clave de encriptación: ");
   gets(aux);
   clave = atoi(aux);

   // Abrimos el archivo de entrada en modo lectura
   // y el de salida en modo escritura
   f = fopen(arch, "rt");
   fd = fopen(arch_dest, "wt");
   if ((f == NULL) || (fd == NULL))
   {
         if (f == NULL) printf("Error al abrir el archivo %s\n", arch);
	 if (fd == NULL) printf("Error al abrir el archivo %s\n", arch_dest);
         exit(1);
   }
   
   printf("Encriptando el archivo...\n");
   
   // Recorremos el archivo de origen carácter por carácter
   while (!feof(f))
   {
      c = fgetc(f);                       // Leemos un carácter
      c_enc = encriptar(c, clave);	  // Encriptamos ese carácter
      fputc(c_enc, fd);			  // Escribimos el carácter encriptado
   }
   
   printf("El archivo %s ha sido generado correctamente\n", arch_dest);

   return 0;
}


// Esta función recibe un carácter y una clave de encriptación, y devuelve el carácter
// encriptado según el método César. Para variar el método de encriptación, basta con
// modificar esta función (el resto del programa puede seguir igual)
char encriptar(char c, int clave)
{
	char cifr;
	int n;

	// Primero comprobaremos que el carácter es alfabético. Sólo encriptaremos
 	// caracteres alfabéticos (aunque esto se puede cambiar si se quiere)
	if ((c >= 'A') && (c <= 'Z'))	// Mayúsculas (hay que encriptar)
	{
		n = c + clave;
		if (n > 'Z') {
			n = n - 'A';
			n = (n % 26) + 'A';
		}
		cifr = n;
	}
	else if  ((c >= 'a') && (c <= 'z'))	// Minúsculas (encriptar)
	{
		n = c + clave;
		if (n > 'z') {
			n = n - 'a';
			n = (n % 26) + 'a';
		}
		cifr = n;
	}
	else	// Otros caracteres (no hay que encriptar)
	{
		cifr = c;	// Lo dejamos igual
	}

	return cifr;
}




