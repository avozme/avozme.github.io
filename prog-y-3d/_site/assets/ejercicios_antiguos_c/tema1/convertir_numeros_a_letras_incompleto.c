/* Programa escribir_n�meros --> **INCOMPLETO**
   Tema 3 - Ejercicio 6 - Fundamentos de Programaci�n 1� ASI
   Autor y fecha: Alfredo Moreno, Octubre 2004 
   Funci�n: lee un n�mero entero de hasta 5 cifras y lo escribe en forma de texto
   (Por ejemplo, el n� 4950 producir� la salida: "cuatro mil novecientos cincuenta")
*/

#include <stdio.h>
#include <math.h>

/* Prototipos */
void extraer_digitos(int numero, int* U, int* D, int* C, int* UM, int* DM);
void escribir_dec_millar(int dmill);
void escribir_uni_millar(int umill);
void escribir_centenas(int cent);
void escribir_decenas(int dec);
void escribir_unidades(int unid);


int main(void)
{
	unsigned int numero;
	int unid, dec, cent;   /* Unidades, decenas, centenas */
	int umill, dmill;      /* Unidades de millar y decenas de millar*/

	//clrscr();
	printf("Fund. Prog. 1� ASI. Ejercicio 3.6 - **INCOMPLETO**");
	do
	{
	  printf("\n\nIntroduzca un n�mero entero positivo (m�ximo 5 cifras)\n");
	  scanf("%d",&numero);
	  extraer_digitos(numero, &unid, &dec, &cent, &umill, &dmill);  /* Separar el n� en d�gitos */
	  escribir_dec_millar(dmill);
	  escribir_uni_millar(umill);
	  escribir_centenas(cent);
	  escribir_decenas(dec);
	  escribir_unidades(dec);
	}
	while (numero > 0);
	return 0;
}

/* Extraer los d�gitos del n�mero mediante divisiones sucesivas */
void extraer_digitos(int numero, int* U, int* D, int* C, int* UM, int* DM)
{
	*DM = floor(numero / 10000);         /* Extraer decenas de millar */
	numero = numero - (*DM * 10000);
	*UM = floor(numero / 1000);
	numero = numero - (*UM * 1000);
	*C = floor(numero / 100);
	numero = numero - (*C * 100);
	*D = floor(numero / 10);
	numero = numero - (*D * 10);
	*U = numero;
}

/* printf las decenas de millar. Se escriben igual que las decenas convencionales */
void escribir_dec_millar(int dmill)
{
	escribir_decenas(dmill);
}

/* printf unid. de millar. Se escriben como las unidades convencionales, seguidas de la palabra "mil". La �nica excepci�n es 1000, que no se escribe "uno mil", sino "mil" */
void escribir_uni_millar(int umill)
{
	escribir_unidades(umill);
	if (umill > 0) printf(" mil ");
}

/* Escribe las centenas. La �nica excepci�n es 100 */
void escribir_centenas(int cent)
{
	switch (cent)
		{
			case 1: printf("ciento "); break;
			case 2: printf("doscientos "); break;
			case 3: printf("trescientos "); break;
			case 4: printf("cuatrocientos "); break;
			case 5: printf("quinientos "); break;
			case 6: printf("seiscientos "); break;
			case 7: printf("setecientos "); break;
			case 8: printf("ochocientos "); break;
			case 9: printf("novecientos "); break;
		}
}

/* printf las decenas. Los n�meros del 10 al 19 se tratan como excepciones. Tambi�n el 20 frente al caso general (2x = "veinti�"). En el resto de decenas, se escribe una " y " si la unidad no es cero (ej: 3x = "treinta y �") */
void escribir_decenas(int dec)
{
		switch (dec)
		{
			case 1: printf("diez"); break;
			case 2: printf("veinte"); break;
			case 3: printf("treinta"); break;
			case 4: printf("cuarenta"); break;
			case 5: printf("cincuenta"); break;
			case 6: printf("sesenta"); break;
			case 7: printf("setenta"); break;
			case 8: printf("ochenta"); break;
			case 9: printf("noventa"); break;
		}
} /* procedimiento escribir_decenas */


/* Escribe las unidades. Excepci�n: cuando la decena es 1 (10, 11, 12, etc). Estos casos
se escriben en el procedimiento escribir_decena */
void escribir_unidades(int unid)
{
	switch (unid)
		{
			case 1: printf("uno"); break;
			case 2: printf("dos"); break;
			case 3: printf("tres"); break;
			case 4: printf("cuatro"); break;
			case 5: printf("cinco"); break;
			case 6: printf("seis"); break;
			case 7: printf("siete"); break;
			case 8: printf("ocho"); break;
			case 9: printf("nueve"); break;
		}
}

