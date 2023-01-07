#include <stdio.h>

struct s_pelicula		// Estructura para cada pelÃ­cula de la lista
{
   char titulo[50];
   char director[30];
   int duracion;
   char genero[20];
};

struct s_nodo			// Estructura para cada nodo de la lista
{
   struct s_pelicula dato;
   struct s_nodo *siguiente;
};

void cargar_archivo(struct s_nodo **primero);
void escribir_archivo(struct s_nodo **primero);
void anadir_pelicula(struct s_nodo **primero);
void listar_peliculas(struct s_nodo *primero);
void borrar_pelicula(struct s_nodo **primero);
void buscar_pelicula(struct s_nodo *primero);

void insertar(struct s_nodo **primero, struct s_pelicula dato);
void borrar_primero(struct s_nodo **primero);
int borrar_por_contenido(struct s_nodo **primero, char tit_buscado[50])
struct s_pelicula buscar_por_contenido(struct s_nodo *primero, char tit_buscado[50])

int main(void)
{
   struct s_nodo *primero = NULL;
   char cad[10];
   int opc;
   
   // Abrimos el archivo e insertamos todas las pelÃ­culas en la lista
   cargar_archivo(&primero);
   
   // MenÃº de opciones
   do {
     printf("\nMENÚ DE OPCIONES\n\n");
     printf("1 - Añadir una película\n");
     printf("2 - Borrar una película\n");
     printf("3 - Buscar una película\n");
     printf("4 - Listar todas las películas\n");
     printf("9 - Salir\n");
     gets(cad); opc = atoi(cad);
     switch(opc) { 
       case 1: anadir_pelicula(&primero); break;
       case 2: borrar_pelicula(&primero); break;
       case 3: buscar_pelicula(primero); break;
       case 4: listar_peliculas(primero); break;
     }
   }
   while (opc != 9);
   
   // Antes de terminar, escribimos la lista en el archivo
   escribir_archivo(&primero);
   
   return 0;
}

// Abre el archivo de datos y carga todas las películas en una lista enlazada
// Debe ejecutarse al principio del programa
void cargar_archivo(struct s_nodo **primero)
{
    FILE *f;
    struct s_pelicula pelicula;
    int n;
    
    // Abrimos archivo de datos
    f = fopen("video.dat", "ab");     
    if (f==NULL) 
    {
       printf("Error al abrir el archivo de datos\n");
       return;
    }
    
    // Recorremos el archivo secuencialmente, leyendo todas las películas
    n = 1;
    while ((n != 0) && (!feof(f)))
    {
        n = fread(&pelicula, sizeof(struct s_pelicula), 1, f);
        if (n > 0)        // Cada película leída se inserta en la lista
           insertar(primero, pelicula);
    }
    fclose(f);
}

// Escribe la lista en el archivo de datos, eliminando lo que contuviera antes
// Debe llamarse justo antes de terminar el programa
void escribir_archivo(struct s_nodo **primero)
{
    FILE *f;
    struct s_pelicula pelicula;
    
    // Abrimos el archivo para escritura (borrando lo que contuviera antes)
    f = fopen("video.dat", "wb");
    if (f==NULL)
    {
        printf("Error al abrir el archivo de datos\n");
        return;
    }
    
    // Recorremos la lista. Cada película encontrada se escribe en el archivo
    // y luego se borra de la lista. Se repite el proceso hasta que no queden
    // películas en la lista
    while (*primero != NULL)
    {
        pelicula = (*primero)->dato;
        fwrite(&pelicula, sizeof(struct s_pelicula), 1, f);
        borrar_primero(primero);
    }
    fclose(f);
}


// Lee los datos de una película por teclado y los inserta en la lista
// (no en el archivo)
void anadir_pelicula(struct s_nodo **primero)
{
   struct s_pelicula pelicula;
   char aux[50];
   
   // Leemos por teclado los datos de la película
   printf("Introduzca los datos de la nueva película:\n");
   printf("Título: ");
   gets(pelicula.titulo);
   printf("Director: ");
   gets(pelicula.director);
   printf("Duración: ");
   gets(aux); pelicula.duracion = atoi(aux);
   printf("Género: ");
   gets(pelicula.genero);
   
   // Añadimos la película a la lista
   insertar(primero, pelicula);
}
    
// Busca una película por nombre y la borra    
void borrar_pelicula(struct s_nodo **primero)
{
   char tit[50];
   int n;
   
   printf("Introduzca el título de la película que quiere borrar\n");
   gets(tit);
   
   // Llamamos a la función que ya teníamos hecha para borrar un nodo cualquiera
   n = borrar_por_contenido(primero, tit);
   if (n == -1)
      printf("Película no encontrada\");
   else
      printf("Película borrada con éxito\n");
}
   

// Busca una película por nombre y la muestra por pantalla    
void buscar_pelicula(struct s_nodo *primero)
{
   char tit[50];
   struct s_pelicula pelicula;
   
   printf("Introduzca el título de la película que quiere localizar\n");
   gets(tit);
   
   // Llamamos a la función que ya teníamos hecha para buscar un nodo cualquiera
   pelicula = buscar_por_contenido(primero, tit);
   printf("Datos de la película:\n");
   printf("Título: %s\n", pelicula.titulo);
   printf("Director: %s\n", pelicula.director);
   printf("Genero: %s\n", pelicula.genero);
   printf("Duracion: %i\n", pelicula.duracion);
}

// Recorre la lista de películas mostrando los datos por la pantalla
void listar_peliculas(struct s_nodo *primero)
{
   struct s_nodo *nodo;
   struct s_pelicula pelicula;
   
   printf("TITULO          DIRECTOR      DURACION  GENERO\n");
   nodo = primero;
   while (nodo != NULL)
   {
         pelicula = nodo->dato;
         printf("%-15s %-12s %5i %-10s\n", pelicula.titulo, pelicula.director, pelicula.duracion, pelicula.genero);
         nodo = nodo->siguiente;
   }
}


         
// La función de insertar es la misma de siempre, pero cambiando el
// tipo del parámetro "dato", que ahora es una película         
void insertar(struct s_nodo **primero, struct s_pelicula dato)
{
   struct s_nodo *nuevo;
   
   nuevo = (struct s_nodo*) malloc (sizeof(struct s_nodo));
   nuevo->dato = dato;
   nuevo->siguiente = *primero;
   *primero = nuevo;
}         
   
   
void borrar_primero(struct s_nodo **primero)
{
   struct s_nodo *segundo;
   
   segundo = (*primero)->siguiente;   
   free(primero);
   *primero = segundo;
}


int borrar_por_contenido(struct s_nodo **primero, char tit_buscado[50])
{
   struct s_nodo *nodo, *anterior;
   struct s_pelicula pelicula;
   int encontrado = 0;
   
   nodo = *primero;
   anterior = *primero;
   while ((nodo != NULL) && (encontrado == 0))
   {
      pelicula = nodo->dato;
      if (strcmp(pelicula.titulo, tit_buscado) == 0)    // Hemos encontrado el nodo
      {                                                 // Vamos a borrarlo
         if (nodo == *primero)
	        *primero = (*primero)->siguiente;
   	     else
	        anterior->siguiente = nodo->siguiente;
	     free(nodo);
	     encontrado = 1;
      }
      else
      {
         anterior = nodo;
         nodo = nodo->siguiente;
      }
   }
   
   return encontrado;
}


struct s_pelicula buscar_por_contenido(struct s_nodo *primero, char tit_buscado[50])
{
   struct s_nodo *nodo;
   struct s_pelicula pelicula;
   int encontrado = 0;
   
   nodo = primero;
   while ((nodo != NULL) && (encontrado == 0))
   {
      pelicula = nodo->dato;
      if (nodo->dato == dato)
         encontrado = 1;
      nodo = nodo->siguiente;
   }
      
   return pelicula;
}
