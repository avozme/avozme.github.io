// Fundamentos de programacion 1º ASI
// Ejercicio del Tema 1: RELOJ CONTINUO
// Muestra un reloj continuo en la pantalla, actualizándose cada segundo

#include <stdio.h>
#include <math.h>
#include <time.h>


void actualizar_reloj(int *h, int *m, int *s);
void esperar(int seg);
void borrar_pantalla();

main(void)
{
    int h, m, s;
    
    do
    {
        printf("Escriba la hora actual: \n");
        printf("Horas: "); scanf("%i", &h);
        printf("Minutos: "); scanf("%i", &m);
        printf("Segundos: "); scanf("%i", &s);
    }
    while ((h < 0) || (h > 23) || (m < 0) || (m > 59) || (s < 0 ) || (s > 59));
    
    do
    {
        borrar_pantalla();
        printf("%02i:%02i:%02i\n", h, m, s);
        actualizar_reloj(&h, &m, &s);
        esperar(1);
    }
    while (0==0);
    
    return 0;     
}


void actualizar_reloj(int *h, int *m, int *s)
{
    (*s)++;
    if (*s == 60)
    {
        *s = 0;
        (*m)++;
        if (*m == 60)
        {
                *m = 0;
                (*h)++;
                if (*h == 24) *h = 0;
        }
    }
}

void esperar(int seg)
{
    long t1, t2;
    t1 = time(NULL);
    t2 = t1;
    while (t2 == t1)
    {
        t2 = time(NULL);
    }
}


void borrar_pantalla()
{
    int i;
    for (i=0; i<50; i++) printf("\n");
}
