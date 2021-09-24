Proceso par_impar
	Definir N Como Entero;
	Definir solucion Como Caracter;
	
	Escribir 'Dime un número: ';
	Leer N;
	Si (N MOD 2=0) Entonces
		solucion <- 'PAR';
	SiNo
		solucion <- 'IMPAR';
	FinSi
	Escribir 'El número ',N,' es ',solucion;
FinProceso
