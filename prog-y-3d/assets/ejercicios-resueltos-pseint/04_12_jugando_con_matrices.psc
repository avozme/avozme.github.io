Algoritmo jugando_con_matrices
	// Atención: en esta solución supondremos que los arrays comienzan en el índice 0.
	// Si se configura PseInt para que empiecen en 1, habría que modificar el código, como es lógico.
	Definir matriz, tam Como Entero
	Escribir sin saltar "Elige el tamaño de la matriz cuadrada: "
	Leer tam
	Dimension matriz[tam,tam]
	inicializar_matriz(matriz, tam)
	mostrar_matriz(matriz, tam)
	perimetro(matriz, tam)
	centro(matriz, tam)
	espiral(matriz, tam)
FinAlgoritmo

SubAlgoritmo inicializar_matriz(matriz, tam)
	Definir f, c como entero
	Para f desde 0 hasta tam-1 hacer
		Para c desde 0 hasta tam-1 hacer
			matriz[f,c] <- azar(10)
		FinPara
	FinPara
FinSubAlgoritmo

SubAlgoritmo mostrar_matriz(matriz, tam) 
	Definir f, c como entero
	Escribir "MATRIZ:"
	Para f desde 0 hasta tam-1 hacer
		Para c desde 0 hasta tam-1 hacer
			Escribir sin saltar matriz[f,c], " "
		FinPara
		Escribir ""
	FinPara
FinSubAlgoritmo

SubAlgoritmo perimetro(matriz, tam)
	Definir f, c como entero
	Escribir "PERÍMETRO:"
	Para c <- 0 hasta tam-1 Hacer
		Escribir sin saltar matriz[0, c], " "
	FinPara
	Para f <- 1 hasta tam-1 Hacer
		Escribir sin saltar matriz[f, tam-1], " "
	FinPara
	Para c <- tam-2 hasta 0 con paso -1 Hacer
		Escribir sin saltar matriz[tam-1, c], " "
	FinPara
	Para f <- tam-2 hasta 1 con paso -1 Hacer
		Escribir sin saltar matriz[f, 0], " "
	FinPara
	Escribir ""
FinSubAlgoritmo

SubAlgoritmo centro(matriz, tam)
	Definir c como entero
	Escribir "CENTRO:"
	Si tam % 2 = 0 entonces
		// Matriz de tamaño PAR. El centro consta de cuatro números
		c <- tam / 2
		Escribir sin saltar matriz[c-1, c-1], " "
		Escribir sin saltar matriz[c-1, c], " "
		Escribir sin saltar matriz[c, c-1], " "
		Escribir sin saltar matriz[c, c]
	SiNo
		// Matriz de tamaño IMPAR. El centro es un solo número
		c <- trunc(tam / 2)
		Escribir sin saltar matriz[c, c]
	FinSi
	Escribir ""
FinSubAlgoritmo

SubAlgoritmo espiral(matriz, tam)
	Definir f, c, inicio, final como entero
	Escribir "ESPIRAL:"
	inicio <- 0
	final <- tam-1
	Mientras inicio < final hacer
		Para c <- inicio hasta final Hacer
			Escribir sin saltar matriz[inicio, c], " "
		FinPara
		Para f <- inicio+1 hasta final Hacer
			Escribir sin saltar matriz[f, final], " "
		FinPara
		Para c <- final-1 hasta inicio con paso -1 Hacer
			Escribir sin saltar matriz[final, c], " "
		FinPara
		Para f <- final-1 hasta inicio+1 con paso -1 Hacer
			Escribir sin saltar matriz[f, inicio], " "
		FinPara
		inicio <- inicio + 1
		final <- final - 1
	FinMientras
	Escribir ""
FinSubAlgoritmo
