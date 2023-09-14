Proceso euros_pesetas
	Definir cantidad, euros, pesetas como real
	Definir moneda como cadena
	
	Escribir "Dime una cantidad"
	Leer cantidad
	
	Escribir "¿La quieres convertir a euros o a pesetas?"
	Leer moneda
	
	Si moneda = "euros" Entonces
		euros <- cantidad / 166
		Escribir cantidad, " pesetas son ", euros, " euros"
	SiNo
		pesetas <- cantidad * 166
		Escribir cantidad, " euros son ", pesetas, " pesetas"
	FinSi
	
FinProceso
