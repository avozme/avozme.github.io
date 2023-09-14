/*
PROGRAMA:  Ajedrez 1.0
ARCHIVO:   fich.c
CONTENIDO: Operaciones con ficheros
AUTOR:     Alfredo Moreno
*/

#include "fich.h"

// Guarda una partida en formato PGN
void grabar_partida(void)
{
    char cad[100];
    FILE* fich;
    int i, n_movs;

    escribir("Nombre de archivo:", 11, TXT_NORMAL);
    leer(cad, 12);
    if (!strstr(cad, ".pgn"))
        sprintf(cad, "%s.pgn", cad);    // Añadir extensión .PGN

    fich = fopen(cad, "wt");
    if (!fich) {
       escribir("Error al crear archivo", 12, TXT_RESALTADO);
       pausa(2000);
    }
    else {
       // Escribimos la cabecera del archivo
       fprintf(fich, "[Event \"?\"]\n");              // XXX modificar ?
       fprintf(fich, "[Site \"Almería\"]\n");       // XXX modificar ?
       fprintf(fich, "[Date \"2005.??.??\"]\n");       // XXX modificar
       fprintf(fich, "[Round \"?\"]\n");
       fprintf(fich, "[White \"?\"]\n");
       fprintf(fich, "[Black \"?\"]\n");          // XXX modificar (añadir a estado y consultarlo)
       fprintf(fich, "[Result \"*\"]\n\n");       // XXX modificar (mirar estado)
       
       // Escribimos el cuerpo del archivo (movimientos)
       n_movs = lst_num_elementos();
       for (i=1; i<=n_movs; i=i+2)	// cada turno consta de dos movimientos (blancas y negras)
       {
          if ((i+1) <= n_movs)
	      fprintf(fich, "%i. %s %s ", i/2+1, lst_buscar(i), lst_buscar(i+1));
	  else		// El último turno puede estar incompleto (si no han movido las negras)
	      fprintf(fich, "%i. %s ", i/2+1, lst_buscar(i));
       }
       fprintf(fich," *");       // Resultado de la partida (XXX cambiar)
       fclose(fich);
       escribir("Partida guardada", 13, TXT_RESALTADO);
       pausa(2000);
   }
}


// Carga una partida desde un archivo PGN
void cargar_partida(void)
{
   char cad[100];
   char mov[7];
   char aux;
   char turno;
   FILE *fich;
   int i;
   
   escribir("Nombre de archivo:", 11, TXT_NORMAL);
   leer(cad, 12);
   if (!strstr(cad, ".pgn"))
        sprintf(cad, "%s.pgn", cad);    // Añadir extensión .PGN

   fich = fopen(cad, "rt");
   if (!fich) {
       escribir("Error al abrir archivo", 12, TXT_RESALTADO);
       pausa(2000);
   }
   else {
       // Leer cabecera
       // XXX por ahora la ignoramos -> tendría que modificar el estado (sobre todo el tipo de los jugadores)
       do
       {
          fgets(cad, 99, fich);
       }
       while (cad[0] == '[');

       // Leer cuerpo (movimientos) e insertarlos en la lista de movimientos
       lst_finalizar();              // Limpiamos lo que hubiera en la lista
       lst_inicializar();
       i = 0;
       while (!feof(fich))
       {
           do {			    // Leer nº de turno
	      aux = fgetc(fich);
	   }
	   while ((aux!='.') && (!(feof(fich))));

           aux = fgetc(fich);       // Leer espacio en blanco
	   if (feof(fich)) break;

           // Leer movimiento BLANCAS ---------------------------------------
           i = -1;
           turno = BLANCAS;
           do {
	      i++;
              mov[i] = fgetc(fich);     // Leer movimiento
           }
           while ((mov[i]!=' ') && (i<7) && (!feof(fich)));

           if ((i>=7) || (feof(fich))) {
              escribir("Error 1 en archivo PGN", 12, TXT_RESALTADO);
              pausa(2000);
              break;
           }
           mov[i] = '\0';
           lst_insertar(mov, turno);

           // Leer movimiento NEGRAS -----------------------------------------
           turno = NEGRAS;
           i = -1;
           do
           {
	      i++;
              mov[i] = fgetc(fich);     // Leer movimiento
           }
           while ((mov[i]!=' ') && (i<7) && (!feof(fich)));

           if ((i>=7) || (feof(fich))) {
              escribir("Error 2 en archivo PGN", 12, TXT_RESALTADO);
              pausa(2000);
              break;
           }
           // Comprobar si se ha alcanzado el fin del archivo
           // (el último turno puede estar incompleto)
           if ((mov[0] != '*') && (mov[0] != '0') && (mov[0] != '1'))
           {
              mov[i] = '\0';
              lst_insertar(mov, turno);
           }
       }
       fclose(fich);

   }
}

