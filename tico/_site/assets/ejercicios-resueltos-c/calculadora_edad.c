#include <stdio.h>
int main()
{
    int dia_nacimiento, mes_nacimiento, ano_nacimiento;
    int dia_actual, mes_actual, ano_actual;
    int anos, meses, dias; 

    /* Leemos la fecha de nacimiento */
    printf("Escribe el día en que naciste: ") ;
    scanf("%i", &dia_nacimiento) ;
    printf("Escribe el mes en que naciste: ") ;
    scanf("%i", &mes_nacimiento) ;
    printf("Escribe el año en que naciste: ") ;
    scanf("%i", &ano_nacimiento) ;

    /* Leemos la fecha actual */
    printf("Escribe el día de hoy: ") ;
    scanf("%i", &dia_actual) ;
    printf("Escribe el mes de hoy: ") ;
    scanf("%i", &mes_actual) ;
    printf("Escribe el año de hoy: ") ;
    scanf("%i", &ano_actual) ;

    /* Calculamos los años */
    anos = ano_actual - ano_nacimiento;

    /* Calculamos los meses */
    if (mes_actual >= mes_nacimiento)
        meses = mes_actual - mes_nacimiento;
    else {
        meses = mes_actual + 12 - mes_nacimiento;
        anos = anos - 1;
    }

    /* Calculamos los días */
    if (dia_actual >= dia_nacimiento)
        dias = dia_actual - dia_nacimiento;
    else {
        dias = dia_actual + 30 - dia_nacimiento;
        mes_actual--;
    }

    printf("Tu edad es de %i años, %i meses y %i días.\n", anos, meses, dias);
    return 0;
}



