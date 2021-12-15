Algoritmo vector_creciente
	Definir i, n, posicion como entero
	Definir v Como Entero
	Dimension v[10]
	
	// Inicializamos el vector con números crecientes, para que ya salga ordenado
	Para i <- 0 hasta 9 Hacer
		v[i] <- i*10 + azar(10)
	FinPara
	
	// Mostramos el vector
	mostrar_vector(v)
	
	// Pedimos al usuario un número
	Repetir
		Escribir "Introduce un número entre 1 y ", v[9]
		Leer n
	Hasta que n >= 1 y n <= v[9]
	
	// Localizamos la posición de inserción
	posicion <- 0
	Mientras n > v[posicion]
		posicion <- posicion + 1
	FinMientras
	
	// Desplazamos el contenido del vector hacia la derecha desde esa posición
	Para i <- 8 hasta posicion con paso -1 hacer
		v[i+1] <- v[i]
	FinPara
	
	// Insertamos por fin el número y volvemos a mostrar el vector
	v[posicion] <- n
	mostrar_vector(v)
FinAlgoritmo

SubAlgoritmo mostrar_vector(v) 
	Definir i como entero
	Para i desde 0 hasta 9 Hacer
		escribir sin saltar v[i], " - "
	FinPara
	Escribir ""	
FinSubAlgoritmo

