Algoritmo InicializarVector
	Definir i, pares, impares Como Entero
	Dimension pares[100]
	Dimension impares[100]
	
	// Inicializa los arrays
	Para i <- 0 hasta 99 Hacer
		pares[i] <- (i+1)*2
		impares[i] <- (i*2)+1
	FinPara
	
	// Muestra el array de números pares
	Para i <- 0 hasta 99 Hacer
		Escribir "Pares[", i, "] = ", pares[i]
	FinPara
		
	// Muestra el array de números impares
	Para i <- 0 hasta 99 Hacer
		Escribir "Impares[", i, "] = ", impares[i]
	FinPara
FinAlgoritmo
