Algoritmo contar_de_a_a_b
	Definir a, b, i Como Entero
	Definir menor, mayor como Entero
	
	// Pedimos los dos n�meros por teclado
	Escribir 'Dime el primer n�mero'
	Leer a
	Escribir 'Dime el segundo n�mero'
	Leer b
	
	// Miramos cu�l es el menor y cu�l el mayor
	Si a < b Entonces
		menor <- a
	    mayor <- b
	SiNo
		menor <- b
		mayor <- a
	FinSi
	
	// Si el menor es un n�mero PAR, le sumamos uno para empezar
	// por el siguiente IMPAR
	Si menor mod 2 = 0 Entonces
		menor <- menor + 1
	FinSi
	
	// Por fin, mostramos los impares que hay entre el n�mero menor y el mayor
	i <- menor
	Mientras i <= mayor Hacer
		Escribir i
		i <- i + 2
	FinMientras
	
FinAlgoritmo
