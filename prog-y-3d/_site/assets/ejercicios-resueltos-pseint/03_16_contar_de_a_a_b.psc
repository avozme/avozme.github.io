Algoritmo contar_de_a_a_b
	Definir a, b, i Como Entero
	Definir menor, mayor como Entero
	
	// Pedimos los dos números por teclado
	Escribir 'Dime el primer número'
	Leer a
	Escribir 'Dime el segundo número'
	Leer b
	
	// Miramos cuál es el menor y cuál el mayor
	Si a < b Entonces
		menor <- a
	    mayor <- b
	SiNo
		menor <- b
		mayor <- a
	FinSi
	
	// Si el menor es un número PAR, le sumamos uno para empezar
	// por el siguiente IMPAR
	Si menor mod 2 = 0 Entonces
		menor <- menor + 1
	FinSi
	
	// Por fin, mostramos los impares que hay entre el número menor y el mayor
	i <- menor
	Mientras i <= mayor Hacer
		Escribir i
		i <- i + 2
	FinMientras
	
FinAlgoritmo
