Algoritmo contar_cifras
	Definir n como entero
	Definir numCifras como entero
	
	Escribir "Dime una número entero de hasta 5 cifras"
	Leer n
	
	si n > -10 y n < 10 Entonces
		numCifras <- 1
	FinSi
	
	si (n <= -10 y n > -100) o (n >= 10 y n < 100) Entonces
		numCifras <- 2
	FinSi
	
	si (n <= -100 y n > -1000) o (n >= 100 y n < 1000) Entonces
		numCifras <- 3
	FinSi
	
	si (n <= -1000 y n > -10000) o (n >= 1000 y n < 10000) Entonces
		numCifras <- 4
	FinSi
	
	si (n <= -10000 y n > -100000) o (n >= 10000 y n < 100000) Entonces
		numCifras <- 5
	FinSi
	
	si n <= -100000  o n >= 100000 Entonces
		Escribir "Error, ese número tiene más de 5 cifras"
	SiNo
		Escribir "El número de cifras del número ", n, " es ", numCifras
	FinSi
FinAlgoritmo
