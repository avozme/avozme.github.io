Algoritmo inicializar_matriz_simple
	Definir fila, columna como entero
	Definir matriz como entero
	Dimension matriz(10,10)
	
	// Primero inicializamos la matriz
	Para fila <- 0 hasta 9 Hacer
		Para columna <- 0 hasta 9 Hacer
			matriz[fila, columna] <- -1
		FinPara
	FinPara
	
	// Despu�s mostramos la matriz por pantalla
	Para fila <- 0 hasta 9 Hacer
		Para columna <- 0 hasta 9 Hacer
			Escribir sin saltar matriz[fila, columna], "  "
		FinPara
		Escribir " "  // Hace el salto de l�nea al final de cada columna
	FinPara
	
	
FinAlgoritmo
	