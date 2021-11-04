Algoritmo primo
	Definir n,i Como Entero
	Definir es_primo Como Logico
	Escribir 'Por favor, teclea un número entero positivo'
	Leer n
	es_primo <- verdadero
	Para i<-2 Hasta n/2 Hacer
		Si n MOD i=0 Entonces
			es_primo <- falso
		FinSi
	FinPara
	Si es_primo Entonces
		Escribir 'El número ',n,' ES PRIMO'
	SiNo
		Escribir 'El número ',n,' NO ES PRIMO'
	FinSi
FinAlgoritmo
