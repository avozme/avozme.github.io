Algoritmo InicializarVector
	Definir repetido como L�gico
	Definir i, j, apuesta como Entero
	Dimension apuesta[6]
	
	// Genera la combinaci�n al azar (sin n�meros repetidos)
	Para i <- 0 hasta 5 hacer
		Repetir
			apuesta[i] <- azar(49)+1      // Saca un n�mero al azar entre 1 y 49
			repetido <- falso             // Suponemos que NO est� repetido...
			Para j <- 0 hasta i-1 con paso 1 hacer      // ...pero vamos a asegurarnos mirando todos los anteriores
				Si apuesta[j] = apuesta[i] entonces   // �S� que estaba repetido!
					repetido <- verdadero              // Ponemos a "verdadero" la variable centinela
				FinSi
			FinPara
		Hasta Que repetido = falso       // Sacaremos otro n�mero al azar hasta que no est� repetido
	FinPara
	
	// Mostramos la combinaci�n
	Escribir "La combinaci�n para la loter�a es:"
	Para i <- 0 hasta 5 hacer
		Escribir sin saltar apuesta[i], "   "
	FinPara
FinAlgoritmo