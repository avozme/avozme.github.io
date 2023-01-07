// EJERCICIOS DE FUNDAMENTOS DE PROGRAMACION
// TEMA 4: FICHEROS
// GENERAR DOCUMENTO HTML

#include <stdio.h>

#define ARCHIVO "página_web.html"

int main(void)
{
   FILE* f;
   char cad[200], cad2[200], c;
   int terminar;

   printf("Programa para generar un documento HTML sencillo\n\n\n");
   
   f = fopen(ARCHIVO, "wt");
   if (f == NULL)
   {
         printf("No puedo crear el archivo HTML\n");
         exit(-1);
   }        
   
   // Encabezado
   printf("ENCABEZADO:\n");
   // Atributos del encabezado
   printf("Introduzca los atributos del encabezado: \n");
   printf("Color: "); gets(cad2);
   fputs("<font color = '", f); fputs(cad2, f); fputs("'>", f);
   printf("Tamaño: "); gets(cad2);
   fputs("<font size = '", f); fputs(cad2, f); fputs("'>", f);
   printf("Tipo de letra: "); gets(cad2);
   fputs("<font face = '", f); fputs(cad2, f); fputs("'>", f);
   printf("Modificador (N = negrita, K = cursiva, S = subrayado): "); gets(cad2); c = cad2[0];
   if (c == 'N') fputs("<b>", f);
   if (c == 'K') fputs("<i>", f);
   if (c == 'S') fputs("<u>", f);

   // Texto del encabezado
   printf("Introduzca el texto del encabezado: ");
   gets(cad);
   fputs(cad, f);            // Envía el texto del encabezado al archivo
   fputs("<br>", f);         // Envía un salto de línea
   
   // Quitamos los atributos del encabezado
   if (c == 'N') fputs("</b>", f);
   if (c == 'K') fputs("</i>", f);
   if (c == 'S') fputs("</u>", f);
   fputs("</font>\n", f);
   
   // Repetimos la jugada con el cuerpo de la página
   printf("CUERPO:\n");
   // Atributos del cuerpo
   printf("Introduzca los atributos del cuerpo: \n");
   printf("Color: "); gets(cad2);
   fputs("<font color = '", f); fputs(cad2, f); fputs("'>", f);
   printf("Tamaño: "); gets(cad2);
   fputs("<font size = '", f); fputs(cad2, f); fputs("'>", f);
   printf("Tipo de letra: "); gets(cad2);
   fputs("<font face = '", f); fputs(cad2, f); fputs("'>", f);
   printf("Modificador (N = negrita, K = cursiva, S = subrayado): "); gets(cad2); c = cad2[0];
   if (c == 'N') fputs("<b>", f);
   if (c == 'K') fputs("<i>", f);
   if (c == 'S') fputs("<u>", f);

   // Texto del cuerpo. Puede tener varias líneas. Terminaremos al teclear "fin"
   printf("Introduzca el texto del cuerpo (teclee fin para terminar):\n");
   terminar = 0;
   while (terminar == 0)
   {
         gets(cad);
         if (strcmp(cad, "fin") != 0)
         {
            fputs (cad, f);     // Envío el texto al archivo
            fputs ("<br>", f);  // Envío un salto de línea
         }
         else
            terminar = 1;
   }
   
   // Quitamos los atributos del cuerpo
   if (c == 'N') fputs("</b>", f);
   if (c == 'K') fputs("</i>", f);
   if (c == 'S') fputs("</u>", f);
   fputs("</font>\n", f);

   fclose(f);
   
   printf("El documento HTML ha sido generado correctamente.\n");
   system("PAUSE");
   return 0;
}

