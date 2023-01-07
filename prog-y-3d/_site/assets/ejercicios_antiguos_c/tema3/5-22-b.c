#include <stdio.h>

#define NUM_EQUIPOS 3


struct s_equipo  		// Estructura equipo
{
  char nombre[50];  	// Nombre del equipo
  int jug;				// Partidos jugados
  int per;				// Partidos perdidos
  int emp;				// Partidos empatados
  int gan;				// Partidos ganados
  int punt;				// Puntos
};

void leer_datos(struct s_equipo eq[NUM_EQUIPOS]);
void mostrar_datos(struct s_equipo eq[NUM_EQUIPOS]);


int main(void)
{
	 struct s_equipo lista_equipos[NUM_EQUIPOS];

	 // Leemos los datos de los equipos por teclado
	 leer_datos(lista_equipos);

	 // Mostramos en la pantalla los datos ordenados
	 mostrar_datos(lista_equipos);

	 return 0;
}


void leer_datos(struct s_equipo eq[NUM_EQUIPOS])
{
  int i;
  for (i = 0; i<NUM_EQUIPOS; i++)
  {
      printf("\nINTRODUZCA LOS DATOS DEL EQUIPO N� %i\n", i+1);
		eq[i].jug = 20;
		printf("Nombre: ");
		flushall(); gets(eq[i].nombre);
		printf("Partidos ganados: ");
		scanf("%i", &eq[i].gan);
		printf("Partidos empatados: ");
		scanf("%i", &eq[i].emp);
		eq[i].per = (eq[i].jug) - (eq[i].emp) - (eq[i].gan);
		eq[i].punt = eq[i].gan*3 + eq[i].emp;
  }
}


void mostrar_datos(struct s_equipo eq[NUM_EQUIPOS])
{
  int i;
  printf("\nEQUIPO              JUG GAN EMP PER PUNTOS\n------------------------------------------\n");
  for (i = 0; i<NUM_EQUIPOS; i++)
  {
		printf("%-20s %2i  %2i  %2i  %2i   %2i\n", eq[i].nombre, eq[i].jug, eq[i].gan, eq[i].emp, eq[i].per, eq[i].punt);
  }
}
