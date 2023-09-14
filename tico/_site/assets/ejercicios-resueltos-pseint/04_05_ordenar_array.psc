Algoritmo ordenar_array
	Definir n, i como Entero
	Definir vector Como Entero
	
	// Dimensionamos el array
	Escribir "¿De qué tamaño quieres el array?"
	Leer n
	Dimension vector[n]
	
	// Inicializamos el array con valores aleatorios
	Para i <- 0 hasta n-1 hacer
		vector[i] <- azar(n*2)
	FinPara
	
	// Ordenamos el array. Lo mostramos antes y después para comprobar la diferencia
	Escribir "Pulsa una tecla para ver el array desordenado"
	Esperar Tecla
	mostrar(vector, n)
	
	Escribir "Pulsa una tecla para iniciar la ordenación del array"
	Esperar Tecla
	ordenar(vector, n)
	
	Escribir "Ordenación terminada. Pulsa una tecla para ver el array ordenado"
	Esperar Tecla
	mostrar(vector, n)	
FinAlgoritmo

SubAlgoritmo mostrar(vector, n)
	Definir i Como Entero
	para i <- 0 hasta n-1 Hacer
		Escribir vector[i]
	FinPara
FinSubAlgoritmo

SubAlgoritmo ordenar(vector por referencia, n)
	Definir i, j, aux Como Entero
	para i <- 0 hasta n-2 Hacer
		para j <- 0 hasta n-2 Hacer
			si vector[j] > vector[j+1] Entonces
				aux <- vector[j]
				vector[j] <- vector[j+1]
				vector[j+1] <- aux
			FinSi
		FinPara
		Borrar Pantalla
		Escribir "Ordenando el array... ", redon(i*100/(n-2)), "%"
	FinPara
FinSubAlgoritmo
	