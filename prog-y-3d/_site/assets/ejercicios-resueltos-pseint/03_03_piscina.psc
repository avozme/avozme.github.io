Algoritmo piscina
	Definir largo,ancho,alto Como Real
	Definir preciom3 Como Real
	Definir costeTotal Como Real
	Escribir '�Cu�l es el largo de la piscina (en cm)?'
	Leer largo
	Escribir '�Cu�l es el ancho de la piscina (en cm)?'
	Leer ancho
	Escribir '�Cu�l es el alto de la piscina (en cm)?'
	Leer alto
	Escribir '�Cu�l es el precio del metro c�bico de agua (en euros)?'
	Leer preciom3
	coste <- largo/100*ancho/100*alto/100*preciom3
	Escribir 'El coste de llenar la piscina es: ',coste,' euros'
FinAlgoritmo
