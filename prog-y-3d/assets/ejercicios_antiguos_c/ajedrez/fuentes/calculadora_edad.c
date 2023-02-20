#include <stdio.h>
int main()
{
    int dia_nacimiento, mes_nacimiento, ano_nacimiento;
    int dia_actual, mes_actual, ano_actual;
    int anos, meses, dias; 

    /* Leemos la fecha de nacimiento */
    printf("Escribe el día en que naciste") ;
    scanf("%i", &dia_nacimiento) ;
    printf("Escribe el mes en que naciste") ;
    scanf("%i", &mes_nacimiento) ;
    printf("Escribe el año en que naciste") ;
    scanf("%i", &ano_nacimiento) ;

    /* Leemos la fecha actual */
    printf("Escribe el día de hoy") ;
    scanf("%i", &dia_actual) ;
    printf("Escribe el mes de hoy") ;
    scanf("%i", &mes_actual) ;
    printf("Escribe el año de hoy") ;
    scanf("%i", &ano_actual) ;

    int anos, meses, dias;
    if (mes_actual < mes_nacimiento) {
        anos = ano_actual - ano_nacimiento - 1 ; 
        meses = - (12 - mes_actual - mes_nacimiento) ;
        dias = (30 - dia_actual) + anos * dia_nacimiento ;
    }
    if (mes_actual > mes_nacimiento) {
        g = f - c ;
        h = e - b ;
        i = (12 - g - 1) * 30 + (30 - d)
    }
    if (mes_actual == mes_nacimiento) {
        h = 0 ;
        if (dia_actual > dia_nacimiento) {
            anos = ano_actual - ano_nacimiento;
            meses = mes_actual - mes_nacimiento;
            dias = dia_actual - dia_nacimiento;
        }
        if (dia_actual < dia_nacimiento) {
            anos = ano_actual - ano_nacimiento - 1 ;
            meses = -(12 - mes_actual - mes_nacimiento) ; 
            dias = -(dia_nacimiento - dia_actual);
        }
        if (dia_actual == dia_nacimiento) {
            anos = ano_actual - ano_nacimiento;
            meses = mes_actual - mes_nacimiento;
            dias = 0;
        }
    }
    printf("Tu edad es de %i años, %i meses y %i días.\n", anos, meses, dias);
    return 0;
}