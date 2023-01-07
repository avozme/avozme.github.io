/* Programa escribir_nmeros
   Tema 3 - Ejercicio 6 - Fundamentos de Programaci� 1 ASI
   Autor y fecha: Alfredo Moreno, Octubre 2004 
   Funci�: lee un nmero entero de hasta 5 cifras y lo escribe en forma de texto
   (Por ejemplo, el n 4950 producir�la salida: "cuatro mil novecientos cincuenta")
*/

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

/* Prototipos */
void extraer_digitos(int numero, int* U, int* D, int* C, int* UM, int* DM);
void escribir_dec_millar(int umill, int dmill);
void escribir_uni_millar(int umill, int dmill);
void escribir_centenas(int unid, int dec, int cent);
void escribir_decenas(int unid, int dec);
void escribir_unidades(int unid, int dec);


int main(void)
{
	unsigned int numero;
	int unid, dec, cent;   /* Unidades, decenas, centenas */
	int umill, dmill;      /* Unidades de millar y decenas de millar*/

	printf("Fund. Prog. 1 ASI. Tema 1 - Convertir numeros a letras");
	do
	{
	  printf("\n\nIntroduzca un nmero entero positivo (mximo 5 cifras)\n");
	  scanf("%d",&numero);
	  extraer_digitos(numero, &unid, &dec, &cent, &umill, &dmill);  /* Separar el n en d�itos */
	  escribir_dec_millar(umill, dmill);
	  escribir_uni_millar(umill, dmill);
	  escribir_centenas(unid, dec, cent);
	  escribir_decenas(unid, dec);
	  escribir_unidades(unid, dec);
	}
	while (numero > 0);
	return 0;
}

/* Extraer los d�itos del nmero mediante divisiones sucesivas */
void extraer_digitos(int numero, int* U, int* D, int* C, int* UM, int* DM)
{
	*DM = (numero / 10000);         /* Extraer decenas de millar */
	numero = numero - (*DM * 10000);
	*UM = (numero / 1000);
	numero = numero - (*UM * 1000);
	*C = (numero / 100);
	numero = numero - (*C * 100);
	*D = (numero / 10);
	numero = numero - (*D * 10);
	*U = numero;
}

/* printf las decenas de millar. Se escriben igual que las decenas convencionales */
void escribir_dec_millar(int umill, int dmill)
{
	escribir_decenas(umill, dmill);
}

/* printf unid. de millar. Se escriben como las unidades convencionales, seguidas de la palabra "mil". La nica excepci� es 1000, que no se escribe "uno mil", sino "mil" */
void escribir_uni_millar(int umill, int dmill)
{
	if (umill == 1)
	{
	   if (dmill > 1)
		printf("un mil ");
	   else
		printf(" mil ");
	}
	else
	{
		escribir_unidades(umill, dmill);
		if ((umill != 0) || (dmill != 0)) printf(" mil ");
	}
}

/* Escribe las centenas. La nica excepci� es 100 */
void escribir_centenas(int unid, int dec, int cent)
{
	if ((unid == 0) && (dec == 0) && (cent == 1))
		printf("cien");
	else
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

/* printf las decenas. Los nmeros del 10 al 19 se tratan como excepciones. Tambi� el 20 frente al caso general (2x = "veinti"). En el resto de decenas, se escribe una " y " si la unidad no es cero (ej: 3x = "treinta y ") */
void escribir_decenas(int unid, int dec)
{
	if (dec == 1)
		switch (unid)
		{
			case 0: printf("diez"); break;
			case 1: printf("once"); break;
			case 2: printf("doce"); break;
			case 3: printf("trece"); break;
			case 4: printf("catorce"); break;
			case 5: printf("quince"); break;
			case 6: printf("diecis�s"); break;
			case 7: printf("diecisiete"); break;
			case 8: printf("dieciocho"); break;
			case 9: printf("diecinueve"); break;
		}
	if (dec == 2)
	{
		if (unid == 0)
			printf ("veinte");
		else
			printf ("veinti");
	}
	if (dec >= 3)
	{
		switch (dec)
		{
			case 3: printf("treinta"); break;
			case 4: printf("cuarenta"); break;
			case 5: printf("cincuenta"); break;
			case 6: printf("sesenta"); break;
			case 7: printf("setenta"); break;
			case 8: printf("ochenta"); break;
			case 9: printf("noventa"); break;
		}
		if (unid != 0)
			printf (" y ");
	}
} /* procedimiento escribir_decenas */


/* Escribe las unidades. Excepci�: cuando la decena es 1 (10, 11, 12, etc). Estos casos
se escriben en el procedimiento escribir_decena */
void escribir_unidades(int unid, int dec)
{
	if (dec != 1)
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

