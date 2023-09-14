Algoritmo ruleta
	Definir dinero, numero_apuesta, color_apuesta, cantidad_apuesta, numero_ruleta, color_ruleta como entero
	Definir seguir_jugando Como Caracter
	
	dinero <- 500
	
	Repetir
	
		Repetir
			Escribir "¿A qué número apuestas? (1-20)"
			Leer numero_apuesta
		Hasta Que numero_apuesta >= 1 y numero_apuesta <= 20
		
		Repetir
			Escribir "¿A qué color apuestas? (1 = negro o 2 = rojo)"
			Leer color_apuesta
		Hasta Que color_apuesta = 1 o color_apuesta = 2
		
		Repetir
			Escribir "¿Cuánta cantidad apuestas? (1 - ", dinero, ")"
			Leer cantidad_apuesta	
		Hasta Que cantidad_apuesta > 0 y cantidad_apuesta <= dinero
		
		numero_ruleta <- azar(20)
		color_ruleta <- azar(2)
		
		Si numero_ruleta = numero_apuesta y color_ruleta = color_apuesta Entonces
			dinero <- dinero + cantidad_apuesta * 10
			Escribir "¡Enhorabuena! Has ganado ", cantidad_apuesta * 10
		SiNo
			dinero <- dinero - cantidad_apuesta
			Escribir "Oooh, has perdido"
		FinSi
		
		Escribir "Ahora mismo tienes ", dinero, " euros"
		Escribir "¿Quieres seguir jugando? (S/N)"
		Leer seguir_jugando
		
	Hasta Que dinero <= 0 o seguir_jugando = "N"
	
	Escribir "Espero volver a verte pronto"
	
FinAlgoritmo
