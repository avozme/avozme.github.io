#### Ejercicios con estructura secuencial

**Ejercicio 1**. Calcular el área y la circunferencia de un círculo cuyo radio será proporcionado a través del teclado. Recuerda que área = 3.14 x r x r y circunferencia = 2 x 3.14 x r

*Solución en pseudocódigo:*

```
Algoritmo area_circulo
   Definir radio, area, circunferencia Como Real
   Escribir "Dime el radio"
   Leer radio
   area <- PI * radio ^ 2
   circunferencia <- 2 * PI * radio
   Escribir "El área es: ", area
   Escribir "La circunferencia mide: ", circunferencia
FinAlgoritmo
```
*Solución en diagrama de flujo:*

![Diagrama de flujo area_circulo](/docs/prog-y-3d/_site/assets/ejercicios-resueltos-pseint/03_01_area_perimetro.png)

**Ejercicio 2**. Pedir las cuatro notas de los exámenes del primer trimestre de un alumno y mostrar la nota media obtenida.

*Solución en pseudocódigo:*

```
 Algoritmo media_examenes
   Definir nota1, nota2, nota3, nota4 como entero
   Definir media como real
   Escribir "Dime las cuatro notas"
   Leer nota1, nota2, nota3, nota4
   media <- (nota1 + nota2 + nota3 + nota4) / 4
   Escribir "La nota media es: ", media
  Si media >= 5 Entonces
     escribir "Has aprobado, enhorabuena"
   SiNo
     escribir "Has suspendido, sigue jugando"
   FinSi
 FinAlgoritmo
 ```
 *Solución en diagrama de flujo:*
 
 ![Diagrama de flujo media_examenes](/docs/prog-y-3d/_site/assets/ejercicios-resueltos-pseint/03_02_media_examenes.png)

**Ejercicio 3**. Calcular el precio de llenar una piscina de agua. Para ello se tienen que pedir al usuario las medidas de la piscina (largo, ancho y alto) y el precio del m​<sup>3</sup>​ del agua. Se mostrará el precio total. Supondremos que la piscina es de forma regular.

 *Solución en pseudocódigo:*
 
 ```
 Algoritmo piscina
   Definir largo, ancho, alto como real
   Definir preciom3 como real
   Definir costeTotal Como Real
  
   Escribir "¿Cuál es el largo de la piscina (en cm)?"
   Leer largo
   Escribir "¿Cuál es el ancho de la piscina (en cm)?"
   Leer ancho
   Escribir "¿Cuál es el alto de la piscina (en cm)?"
   Leer alto
   Escribir "¿Cuál es el precio del metro cúbico de agua (en euros)?"
   Leer preciom3
      
   coste <- largo/100 * ancho/100 * alto/100 * preciom3
   Escribir "El coste de llenar la piscina es: ", coste, " euros"
 FinAlgoritmo
 ```
 *Solución en diagrama de flujo:*
 
 ![Diagrama de flujo piscina](/docs/prog-y-3d/_site/assets/ejercicios-resueltos-pseint/03_03_piscina.png)

**Ejercicio 4**. Determinar si un número leído del teclado es positivo, negativo o cero.

 *Solución en pseudocódigo:*

```  
 Algoritmo positivo_negativo
   Definir n como entero
 	
 	Escribir "Dime un número"
 	Leer n
 	
 	si n > 0 Entonces
 		escribir "El número es POSITIVO"
 	FinSi
 	
 	si n < 0 Entonces
 		escribir "El número es NEGATIVO"
 	FinSi
 	
 	si n = 0 Entonces
     escribir "El número no es ni positivo ni negativo"
 	FinSi
 FinAlgoritmo
```
 
 *Solución en diagrama de flujo:*
 
 ![Diagrama de flujo positivo-negativo](/docs/prog-y-3d/_site/assets/ejercicios-resueltos-pseint/03_04_positivo_negativo.png)

**Ejercicio 8**. Leer un número real y un tipo de moneda, que puede ser “euro” o “peseta”. Convertir la cantidad al tipo de moneda indicado, suponiendo que está expresada en la otra. Por ejemplo, si la cantidad es 15 y la moneda es “peseta”, se supondrá que se trata de 15 € y que hay que convertirlos a pesetas y, por lo tanto, el resultado debe ser 2495.

 *Solución en pseudocódigo:*

``` 
 Algoritmo euros_pesetas
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
 FinAlgoritmo
``` 
 *Solución en diagrama de flujo:*
 
 ![Diagrama de flujo euros-pesetas](/docs/prog-y-3d/_site/assets/ejercicios-resueltos-pseint/03_08_euros_pesetas.png)


**Ejercicio 12**. Determinar el número de cifras de un número entero. El algoritmo debe funcionar para números de hasta 5 cifras, considerando los negativos. Por ejemplo, si se introduce el número 5342, la respuesta del programa debe ser 4. Si se introduce –250, la respuesta debe ser 3.

 *Solución en pseudocódigo:*
 
 ```
 Algoritmo contar_cifras
 	Definir n como entero
 	Definir numCifras como entero
 	
 	Escribir "Dime una número entero de hasta 5 cifras"
 	Leer n
 	
 	si n > -10 y n < 10 Entonces
 		numCifras <- 1
 	FinSi
 	
 	si (n <= -10 y n > -100) o (n >= 10 y n < 100) Entonces
 		numCifras <- 2
 	FinSi
 	
 	si (n <= -100 y n > -1000) o (n >= 100 y n < 1000) Entonces
 		numCifras <- 3
 	FinSi
 	
 	si (n <= -1000 y n > -10000) o (n >= 1000 y n < 10000) Entonces
 		numCifras <- 4
 	FinSi
 	
 	si (n <= -10000 y n > -100000) o (n >= 10000 y n < 100000) Entonces
 		numCifras <- 5
 	FinSi
 	
 	si n <= -100000  o n >= 100000 Entonces
 		Escribir "Error, ese número tiene más de 5 cifras"
 	SiNo
 		Escribir "El número de cifras del número ", n, " es ", numCifras
 	FinSi
 FinAlgoritmo
 ```
 
 *Solución en diagrama de flujo:*
 
 ![Diagrama de flujo contar-cifras](/docs/prog-y-3d/_site/assets/ejercicios-resueltos-pseint/03_12_contar_cifras.png)

**Ejercicio 14**. Escribir todos los números entre 1 y n, siendo n un entero introducido por teclado.

*Solución en pseudocódigo:*

```
Algoritmo contar_de_uno_a_n
	Definir n,i Como Entero
	Escribir 'Dime un número'
	Leer n
	i <- 1
	Mientras i<=n Hacer
		Escribir i
		i <- i+1
	FinMientras
FinAlgoritmo
```

*Solución en diagrama de flujo:*
 
 ![Diagrama de flujo contar-de-uno-a-n](/docs/prog-y-3d/_site/assets/ejercicios-resueltos-pseint/03_14_contar_de_uno_a_n.png)

**Ejercicio 15**. Escribir todos los números pares entre 1 y n.

*Solución en pseudocódigo:*

```
Algoritmo contar_pares
	Definir n,i Como Entero
	Escribir 'Dime un número'
	Leer n
	i <- 2
	Mientras i<=n Hacer
		Escribir i
		i <- i+2
	FinMientras
FinAlgoritmo
```

*Solución en diagrama de flujo:*
 
 ![Diagrama de flujo contar-pares](/docs/prog-y-3d/_site/assets/ejercicios-resueltos-pseint/03_15_contar_pares.png)

**Ejercicio 16**. Escribir todos los números impares entre dos números a y b introducidos por teclado. Antes habrá que comprobar cuál de los dos números (a o b) es mayor.

*Solución en pseudocódigo:*

```
Algoritmo contar_de_a_a_b
	Definir a, b, i Como Entero
	Definir menor, mayor como Entero
	
	// Pedimos los dos números por teclado
	Escribir 'Dime el primer número'
	Leer a
	Escribir 'Dime el segundo número'
	Leer b
	
	// Miramos cuál es el menor y cuál el mayor
	Si a < b Entonces
		menor <- a
	    mayor <- b
	SiNo
		menor <- b
		mayor <- a
	FinSi
	
	// Si el menor es un número PAR, le sumamos uno para empezar
	// por el siguiente IMPAR
	Si menor mod 2 = 0 Entonces
		menor <- menor + 1
	FinSi
	
	// Por fin, mostramos los impares que hay entre el número menor y el mayor
	i <- menor
	Mientras i <= mayor Hacer
		Escribir i
		i <- i + 2
	FinMientras
	
FinAlgoritmo
```

*Solución en diagrama de flujo:*

![Diagrama de flujo contar-de-a-a-b](/docs/prog-y-3d/_site/assets/ejercicios-resueltos-pseint/03_16_contar_de_a_a_b.png)

**Ejercicio 18**. Realiza un programa que calcule la suma de los n primeros números, donde n es un número introducido por teclado. Al terminar, el programa nos mostrará el mensaje "¿Desea terminar? (S/N)". Si el usuario escribe "S", el programa terminará, pero, si escribe "N", volverá a comenzar.

*Solución en pseudocódigo:*

```
Algoritmo sumar_n_numeros
	Definir n, i, suma Como Entero
	Definir terminar Como Caracter
	Repetir
		Escribir 'Por favor, escribe un número entero positivo:'
		Leer n
		i <- 1
		suma <- 0
		Mientras i <= n  Hacer
			suma <- suma+i
			i <- i + 1
		FinMientras
		Escribir 'La suma de los ',n,' primeros números es: ',suma
		Escribir '¿Quieres terminar? (S/N)'
		Leer terminar
	Hasta Que terminar = 'S' O terminar = 's'
FinAlgoritmo
```

*Solución en diagrama de flujo:*

![Diagrama de flujo sumar_n_enteros](/docs/prog-y-3d/_site/assets/ejercicios-resueltos-pseint/03_18_sumar_n_numeros.png)

**Ejercicio 22**. Calcular el valor máximo de una serie de 10 números introducidos por teclado. Generalizar la solución anterior para que también se averigüe el valor mínimo y el medio.

*Solución en pseudocódigo:*

```
Algoritmo maximo_minimo_medio
	Definir maximo,minimo Como Entero
	Definir medio Como Real
	Definir suma,n,i Como Entero
	Escribir 'Dime un número'
	Leer n
	maximo <- n
	minimo <- n
	suma <- 0
	Para i<-1 Hasta 9 Hacer
		Escribir 'Dime otro número'
		Leer n
		Si (n>maximo) Entonces
			maximo <- n
		FinSi
		Si (n<minimo) Entonces
			minimo <- n
		FinSi
		suma <- suma+n
	FinPara
	medio <- suma/10
	Escribir 'El valor máximo es: ',maximo
	Escribir 'El valor medio es: ',medio
	Escribir 'El valor mínimo es: ',minimo
FinAlgoritmo

```

*Solución en diagrama de flujo:*
 
 ![Diagrama de flujo maximo-minimo-medio](/docs/prog-y-3d/_site/assets/ejercicios-resueltos-pseint/03_22_maximo_minimo_medio.png)


**Ejercicio 23**. Calcular el factorial de un número entero N. Recuerda que el factorial de un número es el producto de ese número por todos los enteros menores que él. Por ejemplo, el factorial de 5 (simbolizado 5!) se calcula como: 5! = 5 x 4 x 3 x 2 x 1.

*Solución en pseudocódigo:*

```
Algoritmo factorial
	Definir f,n,i Como Entero
	Escribir 'Dime un número'
	Leer n
	f <- n
	Para i<-n-1 Hasta 1 Con Paso -1 Hacer
		f <- f*i
	FinPara
	Escribir 'El factorial de ',n,' es ',f
FinAlgoritmo

```

*Solución en diagrama de flujo:*
 
 ![Diagrama de flujo factorial](/docs/prog-y-3d/_site/assets/ejercicios-resueltos-pseint/03_23_factorial.png)


**Ejercicio 24 (Solución 1 - Los números pueden repetirse)**. Generar combinaciones al azar para la lotería primitiva (6 números entre 1 y 49). Debes utilizar la función azar(x) que vimos en los apuntes. Por ahora, no te preocupes porque los números puedan repetirse.

*Solución en pseudocódigo:*

```
Algoritmo loteria_primitiva_version_1
	Definir n, i Como Entero
	Escribir "Generador de combinaciones de la lotería primitiva"
	Escribir "(Versión 1 - Puede repetirse algún número)"
	Para i desde 1 hasta 6 hacer
		n <- azar(48)+1
		Escribir n
	FinPara
FinAlgoritmo

```

*Solución en diagrama de flujo:*
 
 ![Diagrama de flujo lotería primitiva con repetición](/docs/prog-y-3d/_site/assets/ejercicios-resueltos-pseint/03_24_loteria_primitiva_v1.png)

 **Ejercicio 24 (Solución 2 - Los números NO PUEDEN repetirse)**. Generar combinaciones al azar para la lotería primitiva (6 números entre 1 y 49). Debes utilizar la función azar(x) que vimos en los apuntes

*Solución en pseudocódigo:*

```
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

```

*Solución en diagrama de flujo:*
 
 ![Diagrama de flujo lotería primitiva sin repetición](/docs/prog-y-3d/_site/assets/ejercicios-resueltos-pseint/03_24_loteria_primitiva_v2.png)

**Ejercicio 25.** Generar combinaciones al azar para la quiniela (14 valores dentro del conjunto 1, X o 2).

*Solución en pseudocódigo:*

(NOTA: supondremos que la función azar() devuelve un valor aleatorio entre 0 y n-1. Con PSeInt, esta función se puede configurar para que los devuelva entre 1 y n, y la solución sería ligeramente distinta)

```
Algoritmo quiniela
	Definir n,i Como Entero
	Escribir 'Tu combinación para la quiniela es:'
	Para i<-1 Hasta 14 Hacer
		n <- azar(3)
		Si n=0 Entonces
			Escribir 'X'
		SiNo
			Escribir n
		FinSi
	FinPara
FinAlgoritmo
```

*Solución en diagrama de flujo:*

![Diagrama de flujo quiniela](/docs/prog-y-3d/_site/assets/ejercicios-resueltos-pseint/03_25_quiniela.png)


**Ejercicio 26.** Determinar si un número N introducido por teclado es o no primo. Recuerda que un número primo es aquél que sólo es divisible por sí mismo y por la unidad.

*Solución en pseudocódigo:*

```
Algoritmo primo
	Definir n,i Como Entero
	Definir es_primo Como Logico
	Escribir 'Por favor, teclea un número entero positivo'
	Leer n
	es_primo <- verdadero
	Para i<-2 Hasta n/2 Hacer
		Si n MOD i=0 Entonces
			es_primo <- falso
		FinSi
	FinPara
	Si es_primo Entonces
		Escribir 'El número ',n,' ES PRIMO'
	SiNo
		Escribir 'El número ',n,' NO ES PRIMO'
	FinSi
FinAlgoritmo

```

*Solución en diagrama de flujo:*

![Diagrama de flujo primo](/docs/prog-y-3d/_site/assets/ejercicios-resueltos-pseint/03_26_primo.png)

**Ejercicio 32.** Escribe un programa que permita jugar a la ruleta con el ordenador. Supondremos que la ruleta tiene 20 números rojos y 20 negros. El jugador, que tendrá una suma de dinero inicial, apostará una cantidad (siempre menor que el dinero que le quede) a un número y un color. La ruleta, que puedes simular con el método azar(), la manejará el ordenador y comunicará al jugador el resultado. Si el jugador acierta, multiplicará por 10 el dinero apostado. Si falla, perderá el dinero apostado. El proceso se repetirá hasta que el jugador decida abandonar el juego, o bien se quede sin dinero. Por favor, abstenerse ludópatas.

*Solución en pseudocódigo:*

```
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
```

(No mostramos la solución en diagrama de flujo porque ocupa demasiado espacio. No obstante, si te interesa verla, solo tienes que escribir el programa en PSeInt y pedirle que te muestre el diagrama de flujo equivalente)

**Ejercicio 34. Juego de las 3 en raya**. El juego se desarrolla en un tablero de 3 x 3 casillas en el que los jugadores van disponiendo sus fichas tratando de formar una línea vertical, horizontal o diagonal. Las fichas del jugador humano tendrán forma de aspa (X) y, las del ordenador, forma de círculo (O). Al principio, el tablero está en blanco. Comenzará jugando el jugador humano, que colocará una ficha en el tablero. Después, será el turno del ordenador. El proceso se repite hasta que uno de los dos consigue colocar tres fichas formando una línea, o hasta que ya no es posible colocar más fichas (situación de “tablas”).

*Solución en pseudocódigo:*

En esta solución hemos utilizado arrays y subalgoritmos, dos elementos muy importantes en programación de lo que hablaremos en el próximo tema. Sin embargo, los introducimos ya aquí para que los vayas conociendo.

Trata de leer y comprender el código fuente, aunque aparezcan esos elementos desconocidos. Verás que, a pesar de su longitud, es más fácil de lo que parece y puedes entender gran parte de lo que está aquí escrito.

```
Algoritmo tres_en_raya
	Definir tablero Como Caracter
	Dimension tablero[10]
	Definir ganador como Cadena
	Definir tablas como Logico
	
	inicializar(tablero)   // Esto es un subalgoritmo. Está escrito más abajo
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
```

(No mostramos la solución en diagrama de flujo porque ocupa demasiado espacio. No obstante, si te interesa verla, solo tienes que escribir el programa en PSeInt y pedirle que te muestre el diagrama de flujo equivalente)