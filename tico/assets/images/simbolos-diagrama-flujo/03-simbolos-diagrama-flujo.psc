Algoritmo nombre
	Definir variable Como Entero
	Definir condicion Como Logico
	Definir a,b,expresion,valor_inicial,valor_final Como Entero
	Escribir 'Texto'
	Leer variable
	expresion <- variable*5
	variable <- expresion
	b <- a*2
	condicion <- b>100
	Si (condicion) Entonces
		Escribir 'Blanco'
	SiNo
		Escribir 'Negro'
	FinSi
	Segun condicion  Hacer
		1:
			Escribir 'Blanco'
		2:
			Escribir 'Negro'
		De Otro Modo:
			Escribir 'Gris'
	FinSegun
	Mientras (condicion) Hacer
		b <- b+1
	FinMientras
	Repetir
		b <- b+1
	Hasta Que (condicion)
	Para variable<-valor_inicial Hasta valor_final Hacer
		b <- a*2
	FinPara
FinAlgoritmo
