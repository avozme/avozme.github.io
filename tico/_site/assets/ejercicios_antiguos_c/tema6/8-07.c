// Fundamentos de programación 1º ASI
// Ejercicios de RECURSIVIDAD del TEMA 8

// Convertir de decimal a binario

#include <stdio.h>
#include <stdlib.h>

int calcula_decimal(char nbin[100], int pos, int exponente);
int potencia(int base, int exponente);

int main(void)
{
    char nbin[100];
    int ndec;
    
    printf("Convertir de decimal a binario\n\n");
    
    printf("Introduce un número BINARIO (no se comprobará la entrada): ");
    gets(nbin);
    
    ndec = calcula_decimal(nbin, strlen(nbin)-1, 0);
    printf("El número decimal es: %i\n", ndec);

    system("PAUSE");
    
    return 0;
}


int calcula_decimal(char nbin[100], int pos, int exponente)
{
  int valor, resultado;

  if (pos < 0)
     resultado = 0;
  else
  {
     if (nbin[pos] == '1')
          valor = potencia(2, exponente);
     else
          valor = 0;+
     resultado = valor + calcula_decimal(nbin, pos-1, exponente+1);
  }
  
  return resultado;
}


int potencia(int base, int exponente)
{
    int i, r = 1;
    
    for (i=1; i<=exponente; i++) r = base * r;
    
    return r;
}

