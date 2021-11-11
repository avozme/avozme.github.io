Algoritmo tres_en_raya
	Definir tablero Como Caracter
	Dimension tablero[10]
	Definir ganador como Cadena
	Definir tablas como Logico
	
	inicializar(tablero)
	Repetir
		mostrar(tablero)
		colocar_pieza_humano(tablero)
		ganador <- comprobar_ganador(tablero)
		tablas <- comprobar_tablas(tablero)
		Si ganador = "Ninguno" y tablas = Falso Entonces
			colocar_pieza_ordenador(tablero)
			ganador <- comprobar_ganador(tablero)
			tablas <- comprobar_tablas(tablero)
		FinSi
	Hasta Que ganador <> "Ninguno" o tablas = Verdadero
	
	mostrar(tablero)
	Si ganador = "Ninguno" Entonces
		Escribir "El juego ha terminado en tablas"
	SiNo
		Escribir "El juego ha terminado. El ganador es: ", ganador
	FinSi
FinAlgoritmo

// --------------------------------------------
// Inicializa el tablero con espacios en blanco
// --------------------------------------------
SubAlgoritmo inicializar(tablero por referencia) 
	Definir i como entero
	Para i <- 1 hasta 9 Hacer
		tablero[i] <- " "
	FinPara
FinSubAlgoritmo

// --------------------------------------------
// Muestra el estado actual del tablero
// --------------------------------------------
SubAlgoritmo mostrar(tablero)
	Escribir "ESTADO ACTUAL DEL TABLERO"
	Escribir "+---+---+---+"
	Escribir "| ",tablero[1]," | ",tablero[2]," | ",tablero[3]," |"
	Escribir "+---+---+---+"
	Escribir "| ",tablero[4]," | ",tablero[5]," | ",tablero[6]," |"
	Escribir "+---+---+---+"
	Escribir "| ",tablero[7]," | ",tablero[8]," | ",tablero[9]," |"
	Escribir "+---+---+---+"	
FinSubAlgoritmo

// ---------------------------------------------------
// Coloca una pieza del jugador humano en el tablero
// ---------------------------------------------------
SubAlgoritmo colocar_pieza_humano(tablero por referencia)
	Definir casilla Como Entero
	Definir casilla_correcta como Logico
	Repetir
		Escribir "¿En qué casilla quieres poner una pieza? (1-9)"
		Leer casilla
		casilla_correcta <- falso
		Si tablero[casilla] = " " Entonces 
			tablero[casilla] <- "X"
			casilla_correcta <- verdadero
		SiNo
			Escribir "Error: Esa casilla ya está ocupada"
		FinSi
	Hasta Que casilla_correcta = Verdadero	
FinSubAlgoritmo

// ---------------------------------------------------
// Coloca una pieza del ordenador en el tablero
// ---------------------------------------------------
SubAlgoritmo colocar_pieza_ordenador(tablero por referencia)
	Definir casilla Como Entero
	Definir casilla_correcta como Logico
	Escribir "Es mi turno. Estoy pensando..."
	Esperar 2 Segundos
	casilla_correcta <- falso
	Repetir
		casilla <- azar(9)+1
		Escribir "Voy a colocar mi pieza en la casilla ", casilla
		Esperar 2 Segundos
		Si tablero[casilla] = " " Entonces 
			tablero[casilla] <- "O" 
			casilla_correcta <- verdadero  
		SiNo
			Escribir "¡Está ocupada!"
		FinSi
	Hasta Que casilla_correcta = Verdadero	
FinSubAlgoritmo

// ---------------------------------------------------
// Comprueba si hay un ganador según el estado del 
// tablero. Devuelve "Ninguno", "Humano" u "Ordenador"
// ---------------------------------------------------
SubAlgoritmo ganador <- comprobar_ganador(tablero)
	Definir ganador como cadena
	ganador <- "Ninguno"
	// Comprobamos primera fila
	Si tablero[1] = tablero[2] y tablero[1] = tablero[3] Entonces
		Si tablero[1] = "X" Entonces
			ganador <- "Humano"
		FinSi
		Si tablero[1] = "O" Entonces
			ganador <- "Ordenador"
		FinSi
	FinSi
	// Comprobamos segunda fila
	Si tablero[4] = tablero[5] y tablero[4] = tablero[6] Entonces
		Si tablero[4] = "X" Entonces
			ganador <- "Humano"
		FinSi
		Si tablero[4] = "O" Entonces
			ganador <- "Ordenador"
		FinSi
	FinSi
	// Comprobamos tercera fila
	Si tablero[7] = tablero[8] y tablero[7] = tablero[9] Entonces
		Si tablero[7] = "X" Entonces
			ganador <- "Humano"
		FinSi
		Si tablero[7] = "O" Entonces
			ganador <- "Ordenador"
		FinSi
	FinSi
	// Comprobamos primera columna
	Si tablero[1] = tablero[4] y tablero[1] = tablero[7] Entonces
		Si tablero[1] = "X" Entonces
			ganador <- "Humano"
		FinSi
		Si tablero[1] = "O" Entonces
			ganador <- "Ordenador"
		FinSi
	FinSi
	// Comprobamos segunda columna
	Si tablero[2] = tablero[5] y tablero[2] = tablero[8] Entonces
		Si tablero[2] = "X" Entonces
			ganador <- "Humano"
		FinSi
		Si tablero[2] = "O" Entonces
			ganador <- "Ordenador"
		FinSi
	FinSi
	// Comprobamos tercera columna
	Si tablero[3] = tablero[6] y tablero[3] = tablero[9] Entonces
		Si tablero[3] = "X" Entonces
			ganador <- "Humano"
		FinSi
		Si tablero[3] = "O" Entonces
			ganador <- "Ordenador"
		FinSi
	FinSi
	// Comprobamos una diagonal
	Si tablero[1] = tablero[5] y tablero[1] = tablero[9] Entonces
		Si tablero[1] = "X" Entonces
			ganador <- "Humano"
		FinSi
		Si tablero[1] = "O" Entonces
			ganador <- "Ordenador"
		FinSi
	FinSi
	// Comprobamos la otra diagonal
	Si tablero[3] = tablero[5] y tablero[3] = tablero[7] Entonces
		Si tablero[3] = "X" Entonces
			ganador <- "Humano"
		FinSi
		Si tablero[3] = "O" Entonces
			ganador <- "Ordenador"
		FinSi
	FinSi
FinSubAlgoritmo

// -------------------------------------------
// Comprueba si hay una situación de tablas
// según el estado actual del tablero. Devuelve
// verdadero si hay tablas o falso en otro caso.
// -------------------------------------------
SubAlgoritmo tablas <- comprobar_tablas(tablero)
	Definir tablas Como Logico
	Definir i, contador Como Entero
	
	contador <- 0
	Para i <- 1 hasta 9 Hacer
		Si (tablero[i] <> " ") Entonces
			contador <- contador + 1
		FinSi
	FinPara
	
	// Si todas las casillas están ya ocupadas y no hay ganador,
	// entonces estamos en tablas.
	Si contador = 9 Entonces
		tablas <- Verdadero
	SiNo
		tablas <- Falso
	FinSi
FinSubAlgoritmo

	