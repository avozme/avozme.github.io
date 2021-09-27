Algoritmo contar_numeros
	Escribir 'Dime un número'
	Leer A
	Escribir 'Dime otro número'
	Leer B
	Si (A<B) Entonces
		inicio <- A
		final <- B
	SiNo
		inicio <- B
		final <- A
	FinSi
	Escribir 'Estos son los números desde ',inicio,' hasta ',final
	i <- inicio
	Mientras (i<=final) Hacer
		Escribir i
	FinMientras
FinAlgoritmo
