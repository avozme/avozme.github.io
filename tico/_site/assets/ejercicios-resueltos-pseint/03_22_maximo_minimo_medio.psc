Algoritmo maximo_minimo_medio
	Definir maximo,minimo Como Entero
	Definir medio Como Real
	Definir suma,n,i Como Entero
	Escribir 'Dime un número'
	Leer n
	maximo <- n
	minimo <- n
	suma <- 0
	Para i<-1 Hasta 9 Hacer
		Escribir 'Dime otro número'
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
