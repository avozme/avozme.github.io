Algoritmo loteria_primitiva_version_2
	Definir n,i,j Como Entero
	Dimension n[6]
	Definir esta_repetido Como Logico
	Escribir 'Generador de combinaciones de la lotería primitiva'
	Escribir '(Versión 2 - No pueden repetirse números)'
	Para i<-1 Hasta 6 Hacer
		Repetir
			n[i] <- azar(48)+1
			esta_repetido <- falso
			Para j<-1 Hasta i-1 Hacer
				Si n[j]=n[i] Entonces
					esta_repetido <- verdadero
				FinSi
			FinPara
			Si esta_repetido=verdadero Entonces
				n[i] <- azar(48)+1
			FinSi
		Hasta Que esta_repetido=falso
		Escribir n[i]
	FinPara
FinAlgoritmo
