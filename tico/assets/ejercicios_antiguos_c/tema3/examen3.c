#include <stdio.h>
#include <string.h>

#define NUM_AL 20			// Numero de alumnos por grupo

struct s_alumno         // Estructura de datos para cada alumno
{
	char nombre[50];
	char apell[50];
	long int telef;
	float nota;
	char grupo;
};
typedef struct s_alumno t_alumno;

void leer_datos(t_alumno lista[NUM_AL], char grupo);
void unir_datos(t_alumno lista1[NUM_AL], t_alumno lista2[NUM_AL], t_alumno lista3[NUM_AL*2]);
void ordenar_datos(t_alumno lista[NUM_AL*2]);
void mostrar_datos(t_alumno lista[NUM_AL*2]);

int main(void)
{
	t_alumno grupoA[NUM_AL]; 		// Lista de alumnos del grupo A
	t_alumno grupoB[NUM_AL];		// Lista de alumnos del grupo B
	t_alumno todos[NUM_AL*2];		// Lista de todos los alumnos (A+B)

	leer_datos(grupoA, 'A'); 		// Leer datos del array grupoA
	leer_datos(grupoB, 'B'); 		// Leer datos del array grupoB

	unir_datos(grupoA, grupoB, todos);	// Juntar dos dos arrays en un tercero
	ordenar_datos(todos);			// Ordenar el tercer array (contiene todos los datos)
	mostrar_datos(todos);			// Mostrar en la pantalla el array ordenado

	return 0;
}

// Lee por teclado los datos de un array de alumnos
void leer_datos(t_alumno lista[NUM_AL], char grupo)
{
	int i;
	printf("Introduzca los datos del grupo %c\n", grupo);
	for (i=0; i<NUM_AL; i++)
	{
		printf("Alumno n� %i\n", i+1);
		printf("  Introduzca nombre: "); flushall();
		gets(lista[i].nombre);
		printf("  Introduzca apellidos: ");
		gets(lista[i].apell);
		printf("  Introduzca telefono: ");
		scanf("%li", &lista[i].telef);
		printf("  Introduzca nota media: ");
		scanf("%f", &lista[i].nota);
		lista[i].grupo = grupo;
	}
}

// Junta dos vectores de NUM_AL alumnos en un tercer vector del doble de alumnos
void unir_datos(t_alumno lista1[NUM_AL], t_alumno lista2[NUM_AL], t_alumno lista3[NUM_AL*2])
{
	int i;
	for (i=0; i<NUM_AL; i++)
	{
		lista3[i] = lista1[i];
		lista3[NUM_AL + i] = lista2[i];
	}
}

// Ordena el vector que contiene a todos los alumnos
// El orden se hace por el campo "nota media", pero se intercambian de posicion
// las estructuras completas, no solo la nota media
void ordenar_datos(t_alumno lista[NUM_AL*2])
{
	int i,j;
	t_alumno aux;		// Elemento auxiliar para hacer los intercambios

	for (i=0; i<NUM_AL*2; i++)
	  for (j=1; j<NUM_AL*2; j++)
	  {
		  if (lista[j].nota < lista[j-1].nota)		// Comparamos las notas medias
		  {
				aux = lista[j];							// Pero intercambiamos los elementos
				lista[j] = lista[j-1];					// enteros (estructuras)
				lista[j-1] = aux;
		  }
	  }
}

// Muestra en la pantalla los datos del array ordenado
void mostrar_datos(t_alumno lista[NUM_AL*2])
{
	int i;

	printf("NOMBRE     APELLIDOS      GRUPO     NOTA MEDIA\n");
	for (i=0; i<NUM_AL*2; i++)
	{
		printf("%-10s %-10s   %c     %2.2f\n", lista[i].nombre, lista[i].apell, lista[i].grupo, lista[i].nota);
	}
}
