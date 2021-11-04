Algoritmo tres_en_raya
	Definir p1, p2, p3, p4, p5, p6, p7, p8, p9 Como Caracter
	Definir casilla como Entero
	Definir fin_de_juego como Lógico
	
	p1 <- " "
	p2 <- " "
	p3 <- " "
	p4 <- " "
	p5 <- " "
	p6 <- " "
	p7 <- " "
	p8 <- " "
	p9 <- " "
	
	Repetir
		// PASO 1. Mostrar el estado actual del tablero
		Escribir "ESTADO ACTUAL DEL TABLERO"
		Escribir "+---+---+---+"
		Escribir "| ",p1," | ",p2," | ",p3," |"
		Escribir "+---+---+---+"
		Escribir "| ",p4," | ",p5," | ",p6," |"
		Escribir "+---+---+---+"
		Escribir "| ",p7," | ",p8," | ",p9," |"
		Escribir "+---+---+---+"
		
		// PASO 2. Colocar pieza del jugador humano
		Escribir "¿En qué casilla quieres poner una pieza? (1-9)"
		Leer casilla
		Si casilla = 1 Entonces p1 <- "X"
		FinSi
		Si casilla = 2 Entonces p2 <- "X"
		FinSi
		Si casilla = 3 Entonces p3 <- "X" 
		FinSi
		Si casilla = 4 Entonces p4 <- "X" 
		FinSi
		Si casilla = 5 Entonces p5 <- "X" 
		FinSi
		Si casilla = 6 Entonces p6 <- "X" 
		FinSi
		Si casilla = 7 Entonces p7 <- "X"  
		FinSi
		Si casilla = 8 Entonces p8 <- "X"  
		FinSi
		Si casilla = 9 Entonces p9 <- "X"  
		FinSi
		
		// PASO 3. El ordenador coloca una pieza
		Escribir "Es mi turno. Estoy pensando..."
		Esperar 2 Segundos
		casilla <- azar(9)
		Escribir "Voy a colocar mi pieza en la casilla ", casilla
		Esperar 2 Segundos
		Si casilla = 1 Entonces p1 <- "O" 
		FinSi
		Si casilla = 2 Entonces p2 <- "O" 
		FinSi
		Si casilla = 3 Entonces p3 <- "O"  
		FinSi
		Si casilla = 4 Entonces p4 <- "O"  
		FinSi
		Si casilla = 5 Entonces p5 <- "O"  
		FinSi
		Si casilla = 6 Entonces p6 <- "O"  
		FinSi
		Si casilla = 7 Entonces p7 <- "O"  
		FinSi
		Si casilla = 8 Entonces p8 <- "O"  
		FinSi
		Si casilla = 9 Entonces p9 <- "O"  
		FinSi
		
		// PASO 4. Comprobar si el juego ha terminado
		fin_de_juego <- falso
		
	Hasta Que fin_de_juego = verdadero
	
FinAlgoritmo
