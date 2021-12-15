Algoritmo jugando_con_matrices
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
	Para f desde 0 hasta tam-1 hacer
		Para c desde 0 hasta tam-1 hacer
			Escribir sin saltar matriz[f,c], " "
		FinPara
		Escribir ""
	FinPara
	
FinSubAlgoritmo

SubAlgoritmo perimetro(matriz, tam)
	Definir f, c como entero
FinSubAlgoritmo

SubAlgoritmo centro(matriz, tam)
	Definir f, c como entero
FinSubAlgoritmo

SubAlgoritmo espiral(matriz, tam)
	Definir f, c, inicio, final como entero
FinSubAlgoritmo
