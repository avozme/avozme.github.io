Algoritmo piscina
	Definir largo,ancho,alto Como Real
	Definir preciom3 Como Real
	Definir costeTotal Como Real
	Escribir '¿Cuál es el largo de la piscina (en cm)?'
	Leer largo
	Escribir '¿Cuál es el ancho de la piscina (en cm)?'
	Leer ancho
	Escribir '¿Cuál es el alto de la piscina (en cm)?'
	Leer alto
	Escribir '¿Cuál es el precio del metro cúbico de agua (en euros)?'
	Leer preciom3
	coste <- largo/100*ancho/100*alto/100*preciom3
	Escribir 'El coste de llenar la piscina es: ',coste,' euros'
FinAlgoritmo
