Algoritmo contar_numeros
	Escribir 'Dime un n�mero'
	Leer A
	Escribir 'Dime otro n�mero'
	Leer B
	Si (A<B) Entonces
		inicio <- A
		final <- B
	SiNo
		inicio <- B
		final <- A
	FinSi
	Escribir 'Estos son los n�meros desde ',inicio,' hasta ',final
	i <- inicio
	Mientras (i<=final) Hacer
		Escribir i
	FinMientras
FinAlgoritmo
