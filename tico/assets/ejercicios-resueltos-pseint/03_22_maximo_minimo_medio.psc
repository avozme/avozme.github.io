Algoritmo maximo_minimo_medio
	Definir maximo,minimo Como Entero
	Definir medio Como Real
	Definir suma,n,i Como Entero
	Escribir 'Dime un n�mero'
	Leer n
	maximo <- n
	minimo <- n
	suma <- 0
	Para i<-1 Hasta 9 Hacer
		Escribir 'Dime otro n�mero'
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
	Escribir 'El valor m�ximo es: ',maximo
	Escribir 'El valor medio es: ',medio
	Escribir 'El valor m�nimo es: ',minimo
FinAlgoritmo
