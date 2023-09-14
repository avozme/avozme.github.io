#include <string.h>
#include <stdio.h>

int main()
{
    char gigante1[76], gigante2[76], gigante3[76];
    int n1, n2, n3, me_llevo, i1, i2, i3;
    
    /* Pedimos los datos de entrada. Los n�meros gigantes se guardar�n
       en cadenas de caracteres de 75 d�gitos como m�ximo (se puede
       cambiar para aceptar tama�os mayores) */
    puts("\n\nENTEROS GIGANTES\n\n");
    puts("Teclee el primer n�mero gigante: ");
    gets(gigante1);	
    puts("Teclee el segundo n�mero gigante: ");
    gets(gigante2);
    
    /* Establecemos los valores iniciales de los �ndices de cada cadena
       para recorrerlas hacia atr�s. La cadena resultado (gigante3) medir�
       tanto como la m�s larga m�s uno, por si hay un acarreo al final de la suma */
    i1 = strlen(gigante1) - 1;
    i2 = strlen(gigante2) - 1;
    if (i1 > i2)
	i3 = i1 + 1;
    else
	i3 = i2 + 1;


    gigante3[i3+1] = '\0';    /* Colocamos el nulo en la cadena resultado */
    me_llevo = 0;             /* Acarreo */

    /* Comienza el bucle de la suma. Iremos sumando d�gito a d�gito, desde el 
       �ltimo hacia atr�s, construyendo el resultado en otra cadena (gigante3) */
    while ((i1 >= 0) || (i2 >= 0))
    {
	if (i1 >= 0) 
		n1 = gigante1[i1] - 48;   /* Convertimos primer sumando a n�mero */
	else
		n1 = 0;
	if (i2 >= 0)
		n2 = gigante2[i2] - 48;   /* Convertimos segundo sumando a n�mero */
	else
		n2 = 0;

	n3 = (n1 + n2 + me_llevo) % 10;   /* Calculamos el resultado */
	gigante3[i3] = n3 + 48;           /* Lo almacenamos en gigante3 */
	me_llevo = (n1 + n2 + me_llevo) / 10;   /* Acarreo para la pr�xima suma */
 	i1--;                             /* Actualizamos los �ndices */
	i2--;
	i3--;
    }
    if (me_llevo == 0)                    /* Colocamos el �ltimo acarreo (si lo hay) */
	gigante3[i3] = ' ';
    else
	gigante3[i3] = me_llevo + 48;

    /* Mostramos el resultado (adaptado para n�meros de m�ximo 75 d�gitos) */
    printf("\n\n");
    printf("%+75s  +\n", gigante1);
    printf("%+75s\n", gigante2);
    printf("---------------------------------------------------------------------------\n");
    printf("%+75s\n\n\n", gigante3);

 

    return 0;
}
