Algoritmo InicializarVector
	Definir repetido como Lógico
	Definir i, j, apuesta como Entero
	Dimension apuesta[6]
	
	// Genera la combinación al azar (sin números repetidos)
	Para i <- 0 hasta 5 hacer
		Repetir
			apuesta[i] <- azar(49)+1      // Saca un número al azar entre 1 y 49
			repetido <- falso             // Suponemos que NO está repetido...
			Para j <- 0 hasta i-1 con paso 1 hacer      // ...pero vamos a asegurarnos mirando todos los anteriores
				Si apuesta[j] = apuesta[i] entonces   // ¡Sí que estaba repetido!
					repetido <- verdadero              // Ponemos a "verdadero" la variable centinela
				FinSi
			FinPara
		Hasta Que repetido = falso       // Sacaremos otro número al azar hasta que no esté repetido
	FinPara
	
	// Mostramos la combinación
	Escribir "La combinación para la lotería es:"
	Para i <- 0 hasta 5 hacer
		Escribir sin saltar apuesta[i], "   "
	FinPara
FinAlgoritmo