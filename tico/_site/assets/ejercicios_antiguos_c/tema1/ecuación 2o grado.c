// Fundamentos de programacion 1º ASI
// Ejercicio del Tema 2 - Nº 5
// Calcula las dos soluciones de una ecuacion de segundo grado

#include <stdio.h>
#include <math.h>

main(void)
{
	float a, b, c;		// Coeficientes
	float x1, x2;		// Soluciones
	printf("Tema 2 - Ejercicio 5\n");
	printf("Calcula las dos soluciones de una ecuación de 2º grado\n\n");
	printf("La ecuación es de la forma ax2 + bx + c = 0\n");

	printf("Introduce el valor de 'a': ");
	scanf("%f",&a);
	printf("Introduce el valor de 'b': ");
	scanf("%f",&b);
	printf("Introduce el valor de 'c': ");
	scanf("%f",&c);

	if ( (b*b-4*a*c) >= 0 )    // La raiz cuadrada debe ser positiva
	{
		x1 = (-b + sqrt(b*b-4*a*c)) / (2*a);
		x2 = (-b - sqrt(b*b-4*a*c)) / (2*a);
		printf("\nLas soluciones son:\n");
		printf("x1 = %f\n", x1);
		printf("x2 = %f\n", x2);
	}
	else
		printf("La ecuación no tiene solución");
}
