Algoritmo media_examenes
	Definir nota1, nota2, nota3, nota4 como entero
	Definir media como real
	Escribir "Dime las cuatro notas"
	Leer nota1, nota2, nota3, nota4
	media <- (nota1 + nota2 + nota3 + nota4) / 4
	Escribir "La nota media es: ", media
	si media >= 5 Entonces
		escribir "Has aprobado, enhorabuena"
	SiNo
		escribir "Has suspendido, sigue jugando"
	FinSi
FinAlgoritmo
