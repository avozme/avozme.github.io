Algoritmo maximo_minimo_medio
	Definir maximo,minimo Como Entero
	Definir medio Como Real
	Definir suma,n,i Como Entero
	maximo <- -9999
	minimo <- 9999
	suma <- 0
	Para i<-1 Hasta 10 Hacer
		Escribir 'Dime un número'
		Leer n
		Si (n>maximo) Entonces
			maximo <- n
		FinSi
		Si (n<minimo) Entonces
			minimo <- n
		FinSi
		suma <- suma+n
	FinPara
	medio <- suma/10
	Escribir 'El valor máximo es: ',maximo
	Escribir 'El valor medio es: ',medio
	Escribir 'El valor mínimo es: ',minimo
FinAlgoritmo
