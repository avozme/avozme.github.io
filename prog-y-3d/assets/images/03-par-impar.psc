Proceso par_impar
	Definir N Como Entero;
	Definir solucion Como Caracter;
	
	Escribir 'Dime un n�mero: ';
	Leer N;
	Si (N MOD 2=0) Entonces
		solucion <- 'PAR';
	SiNo
		solucion <- 'IMPAR';
	FinSi
	Escribir 'El n�mero ',N,' es ',solucion;
FinProceso
