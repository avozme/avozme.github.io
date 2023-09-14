#include <stdio.h>
#include <stdlib.h>

#define IN 1
#define SF 2
#define BI 3
#define NT 4
#define SB 5

void calcular_medias();
void mostrar_datos(int nota);

struct s_alumno
{
	char nombre[20];
    char apellidos[50];
	char grupo[10];
    double nota1, nota2, nota3;
	double nota_final;
};

int main(void)
{
	calcular_medias();
	mostrar_datos(IN);	// Mostrar insuficientes
	mostrar_datos(SF);	// Mostrar suficientes
	mostrar_datos(BI);	// Mostrar bienes
	mostrar_datos(NT);	// Mostrar notables
	mostrar_datos(SB);	// Mostrar sobresalientes
	system("PAUSE");
	return 0;
}

void calcular_medias()
{
	FILE *f, *f_temp;
	struct s_alumno alumno;
	int n;

	// Abrimos el archivo de datos y creamos el archivo temporal
	f = fopen("datos.bin", "rb");
	if (f==NULL) {
		printf("No puedo abrir archivo de datos\n");
		return;
	}

	f_temp = fopen("temp", "wb");
	if (f_temp==NULL) {
		printf("No puedo crear archivo temporal\n");
		fclose(f);
		return;
	}

	// Recorremos el archivo de datos y vamos copiándolo todo al archivo temporal
	// calculando antes la nota media para guardarla también en el temporal
	while (!feof(f))
   {
		// Leemos un registro del archivo de datos
		n = fread(&alumno, sizeof(struct s_alumno), 1, f);

		if (n > 0)
		{
		  // Calculamos nota media
		  alumno.nota_final = (alumno.nota1 + alumno.nota2 + alumno.nota3) / (double)3;

		  // Escribimos el registro, con nota media incluida, en el archivo temporal
		  fwrite(&alumno, sizeof(struct s_alumno), 1, f_temp);
		}
	}
	fclose(f);
	fclose(f_temp);
   
    // Renombramos archivos e informamos al usuario
	printf("Notas finales calculadas con éxito\n");
	remove("datos.bin");
	rename("temp", "datos.bin");
}


// Muestra por la pantalla los alumnos que tengan una nota media correspondiente
// al valor del par�metro "nota", que puede ser IN, SF, BI, NT o SB.
void mostrar_datos(int nota)
{
	struct s_alumno alumno;
	int mostrar_alumno, n;
    FILE *f;
   
	// Abrimos el archivo de datos
	f = fopen("datos.bin","rb");
	if (f == NULL) {
      printf("No puedo abrir el archivo\n");   
		return;
    }
   
    // Escribe cabecera de la lista
	printf("---------------------------------------------------------------------\n");
	switch (nota) {
	  case IN: printf("  SUPENSOS\n"); break;
      case SF: printf("  SUFICIENTE\n"); break;
	  case BI: printf("  BIEN\n"); break;
      case NT: printf("  NOTABLE\n"); break;
      case SB: printf("  SOBRESALIENTE\n"); break;
    }
	printf("----------------------------------------------------------------------\n");

      
   // Recorremos el archivo leyendo los registros de uno en uno para mostrarlos por pantalla
   while (!feof(f))
   {
		n = fread(&alumno, sizeof(struct s_alumno), 1, f);

		if (n > 0)
		{
		  // Miramos la nota media del alumno para ver si hay que mostrarlo
		  mostrar_alumno = 0;
		  if ((nota == IN) && (alumno.nota_final < 5))
			 mostrar_alumno = 1;
		  if ((nota == SF) && (alumno.nota_final >= 5) && (alumno.nota_final < 6))
			 mostrar_alumno = 1;
		  if ((nota == BI) && (alumno.nota_final >= 6) && (alumno.nota_final < 7))
			 mostrar_alumno = 1;
		  if ((nota == NT) && (alumno.nota_final >= 7) && (alumno.nota_final < 8.5))
			 mostrar_alumno = 1;
		  if ((nota == SB) && (alumno.nota_final >= 8.5))
			 mostrar_alumno = 1;

		  if (mostrar_alumno == 1)
			 printf("%-20s, %-10s %2.2lf\n", alumno.apellidos, alumno.nombre, alumno.nota_final);
		}
	}
	fclose(f);
}

