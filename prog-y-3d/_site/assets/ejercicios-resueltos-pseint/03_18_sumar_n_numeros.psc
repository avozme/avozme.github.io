Algoritmo sumar_n_numeros
	Definir n, i, suma Como Entero
	Definir terminar Como Caracter
	Repetir
		Escribir 'Por favor, escribe un número entero positivo:'
		Leer n
		i <- 1
		suma <- 0
		Mientras i <= n  Hacer
			suma <- suma+i
			i <- i + 1
		FinMientras
		Escribir 'La suma de los ',n,' primeros números es: ',suma
		Escribir '¿Quieres terminar? (S/N)'
		Leer terminar
	Hasta Que terminar = 'S' O terminar = 's'
FinAlgoritmo
