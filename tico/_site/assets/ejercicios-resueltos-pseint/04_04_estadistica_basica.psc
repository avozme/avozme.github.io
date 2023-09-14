Algoritmo estadistica_basica
	Definir n, i, acum como Entero
	Definir vector Como Entero
	Definir media como Real
	
	// Dimensionamos el array
	Escribir "¿Cuántos números vas a escribir?"
	Leer n
	Dimension vector[n]
	
	// Leemos los valores del array
	Escribir "Por favor, teclea los ", n, " valores (pulsa Intro después de cada uno):"
	Para i <- 0 hasta n-1 hacer
		Leer vector[i]
	FinPara
	
	// Calculamos la media
	acum <- vector[0]
	Para i <- 1 hasta n-1 hacer
		acum <- acum + vector[i]
	FinPara
	media <- acum / n
	Escribir "El promedio es: ", media
	
	// Mostramos los valores que están por debajo de la media
	Escribir "Valores por debajo de la media:"
	Para i <- 1 hasta n-1 Hacer
		Si vector[i] < media Entonces
			Escribir vector[i]
		FinSi
	FinPara
	
	// Mostramos los valores que están por encima de la media
	Escribir "Valores por encima de la media:"
	Para i <- 1 hasta n-1 Hacer
		Si vector[i] > media Entonces
			Escribir vector[i]
		FinSi
	FinPara
	
FinAlgoritmo