Algoritmo factorial
	Definir f,n,i Como Entero
	Escribir 'Dime un número'
	Leer n
	f <- n
	Para i<-n-1 Hasta 1 Con Paso -1 Hacer
		f <- f*i
	FinPara
	Escribir 'El factorial de ',n,' es ',f
FinAlgoritmo
