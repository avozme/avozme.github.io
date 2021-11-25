Algoritmo inicializar_matriz_complejo
	Definir fila, columna como entero
	Definir matriz como entero
	Dimension matriz(10,10)
	
	// Primero inicializamos la matriz
	Para fila <- 0 hasta 9 Hacer
		Para columna <- 0 hasta 9 Hacer
			Si fila MOD 2 = 0 Entonces
				matriz[fila, columna] <- 0
			SiNo
				matriz[fila, columna] <- -1
			FinSi
		FinPara
	FinPara
	
	// Después mostramos la matriz por pantalla
	Para fila <- 0 hasta 9 Hacer
		Para columna <- 0 hasta 9 Hacer
			Si fila MOD 2 = 0 Entonces
			    Escribir sin saltar " ", matriz[fila, columna], "  "
			SiNo
				Escribir sin saltar matriz[fila, columna], "  "
			FinSi
		FinPara
		Escribir " "  // Hace el salto de línea al final de cada columna
	FinPara
	
	
FinAlgoritmo
	