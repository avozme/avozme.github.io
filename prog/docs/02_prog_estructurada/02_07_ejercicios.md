---
layout: page
title: 2.7. Ejercicios
permalink: /programacion-estructurada/ejercicios/
nav_order: 7
has_children: true
parent: 2. Programación estructurada
grandparent: Programación
---
## EJERCICIOS PROPUESTOS

Verás que esta relación de ejercicios de este tema es bastante  más larga que la del anterior. Vamos a estar por aquí un buen rato, así que ponte cómodo/a. Ahora tenemos los elementos suficientes en la mano como para empezar a escribir programas que empiecen a hacer cosas de verdad.

Los ejercicios están colocados en orden de dificultad creciente. Más o menos, porque hay excepciones. Esto quiere decir que, cuanto más avances, más difíciles serán... y mayor será la satisfacción de hacerlos funcionar.

En cada ejercicio, tendrás que desarrollar un programa Java completo. Eso incluye escribir al menos una clase con el método main() necesario para resolver el problema, pero, en algunos casos, pueden ser necesarios métodos adicionales o incluso alguna clase extra. No te agobies si aún no sabes hacer nada de esto: lo mejor es aprender con la práctica.

## **BLOQUE I: condicionales y operaciones básicas**

**Ejercicio 2.1: Positivo y negativo**

Leer un número por teclado mediante un método, y decir si es positivo o negativo con otro método. La salida por consola puede ser algo así como: "el número X es positivo"

**Ejercicio 2.2: Doble o mitad**

Pide un número real. Si es mayor o igual a 100, muestra su mitad; si es menor, muestra su doble.

**Ejercicio 2.3: Resta flexible**

Leídos dos números por teclado, llamémosles a y b, calcular y mostrar la resta del mayor menos el menor. Por ejemplo, si a \= 8 y b \= 3, el resultado debe ser a – b, es decir, 5\. Pero si a \= 4 y b \= 7, el resultado debe ser b – a, es decir, 3\.

Además, el programa debe decir si el resultado es múltiplo de 3 o no.

**Ejercicio 2.4: Año bisiesto**

Determinar si un año es bisiesto o no. Los años bisiestos son múltiplos de 4; utilícese el operador módulo. ¡Pero hay más excepciones\! Los múltiplos de 100 no son bisiestos, aunque sean múltiplos de 4\. Pero los múltiplos de 400 sí, aunque sean múltiplos de 100\. Qué follón. La Tierra es muy maleducada al no ajustarse a los patrones de tiempo humanos.

Resumiendo: un año es bisiesto si es divisible entre 4, a menos que sea divisible entre 100\. Sin embargo, si un año es divisible entre 100 y además es divisible entre 400, también resulta bisiesto.

Ahora, prográmalo, a ver qué sale.

**Ejercicio 2.5: Redondeo caprichoso**

Leer un número decimal y mostrar tres cosas: su redondeo al entero más cercano, su suelo (redondeo al entero inferior) y su techo (redondeo al entero superior).

Por ejemplo, si el número es 25,7 el resultado sería:

  * Redondeo al entero más cercano: 26  
  * Suelo: 25  
  * Techo: 26

**Ejercicio 2.6: Números ordenados y diferencia constante**

Leer tres números por teclado, a, b y c, y decidir si están ordenados de menor a mayor.

Cuando funcione, mejora el programa para que te diga si la diferencia entre ellos es constante, es decir, si hay una distancia de 1 entre uno y otro, o si hay una distancia de 2 entre uno y otro, etc.

Por ejemplo, los números 4, 6 y 8 están ordenados de menor a mayor y su diferencia es constante, puesto que están a distancia de 2 unos de otros.

En cambio, los números 4, 6 y 11 están ordenados pero su diferencia no es constante.

**Ejercicio 2.7: Mostrar cifras**

Trocea un número entero mostrando de una en una sus cifras, empezando por las unidades. Debe funcionar para números de hasta 5 cifras, incluyendo los negativos.

Por ejemplo, si se introduce el número 1893, la respuesta del programa debe ser algo así:

```
Las cifras del número 1893 son:
Unidades: 3
Decenas: 9
Centenas: 8
Unidades de millar: 1
```

**Ejercicio 2.8: Calculadora de descuentos simple**

Pide por teclado un precio y una edad. Si la edad es menor que 18, aplica un 10% de descuento al precio. Si es mayor que 65, aplica un 20% de descuento. Muestra el precio final.

**Ejercicio 2.9: Mayor, menor, mediano**

Dados tres números enteros, a, b, c, determina cuál es el mayor, cuál el menor y cuál el mediano. Y da gracias a que no lo hemos hecho con 4 variables. Prohibido usar arrays, suponiendo que sepas lo que son. Es un ejercicio de lógica, no de bucles.

(¿Se te ocurre cómo hacerlo con 4 números: a, b, c, d?)

(¿Y si fueran cadenas de caracteres en lugar de números?)

## **BLOQUE II: Bucles y pequeños cálculos**

**Ejercicio 2.10: Sumar rango**

Lee dos números a y b (ojo, porque podría ser que a \> b). Suma todos los enteros comprendidos entre ellos, ambos inclusive, y muestra el resultado.

**Ejercicio 2.11: Impares**

Muestra todos los números impares, ordenados de menor a mayor, entre dos números a y b introducidos por teclado.

Cualquiera de ellos puede ser el mayor, así que no sabes si debes empezar por a y avanzar hacia b o a la inversa.

**Ejercicio 2.12: Pares o impares**

Escribe un programa que pregunte dos números, a y b, y luego pregunte si se desean ver los números pares o impares.

Dependiendo de la respuesta, mostrará en la pantalla los números pares o impares entre a y b. Cualquiera de ellos puede ser el mayor.

**Ejercicio 2.13: Escalera de números**

Escribe un programa que pida un número de 1 a 9 (otras cantidades deben ser rechazadas con un mensaje de error) y que dibuje una escalera así:

```
1
12
123
...
123...N
```

**Ejercicio 2.14: Acumulador de pares**

Calcula la suma de todos los números pares entre a y b, siendo a y b dos números introducidos por teclado. No hace falta que te diga que podrían no estar ordenados, ¿verdad?

**Ejercicio 2.15: Promedio interactivo**

Calcula el valor medio de una serie de valores enteros positivos introducidos por teclado. Para terminar de introducir valores, el usuario debe teclear un número negativo.

**Ejercicio 2.16: Máximo y mínimo en flujo**

Lee números enteros positivos hasta que el usuario introduzca \-1 (si se introduce otro número negativo, se dará un mensaje de error y se ignorará). Muestra, antes de terminar, el valor máximo y el valor mínimo de todos los que se hayan introducido.

No uses arrays, suponiendo que sepas lo que son.

**Ejercicio 2.17: Factorial paso a paso**

Calcula el factorial de un número introducido por teclado, pero mostrando cada multiplicación intermedia.

Recuerda que el factorial de un número es el producto de ese número por todos los enteros menores que él. Por ejemplo, el factorial de 5 (simbolizado 5\!) se calcula como: 5\! \= 5 x 4 x 3 x 2 x 1\.

El programa, entonces, si se introduce el número 5, debería mostrar esta salida:

```
5 x 4 = 20
5 x 4 x 3 = 60
5 x 4 x 3 x 2 = 120
5 x 4 x 3 x 2 x 1 = 120
SOLUCIÓN: El factorial de 5 es 120
```

**Ejercicio 2.18: Serie alterna**

Pide un número n por teclado e imprime la serie: 1, \-2, 3, \-4, 5, … hasta llegar a n términos. Calcula además la suma de todos los números que forman la serie y muestra el resultado.

**Ejercicio 2.19: Contar divisores**

Lee un número por teclado y muestra cuántos divisores enteros tiene y cuales son.

Por ejemplo, si el número que se introduce es el 20, la salida del programa sería algo así:

El número 20 tiene 6 divisores, que son: 1, 2, 4, 5, 10 y 20\.

(Recuerda que un divisor de 20 es un número que divide de forma exacta a 20\)

**Ejercicio 2.20: Número primo**

Vamos con otro clásico de los cursos de programación.

Escribe un programa que lea un número entero por teclado y determine si es o no un número primo. Te recuerdo que un número primo es aquel que solo tiene dos divisores: 1 y el mismo número.

Por ejemplo, 20 no es un número primo, porque tiene 6 divisores, como hemos visto en el ejercicio anterior.

En cambio, 23 sí es un número primo, porque solo tiene 2 divisores: 1 y el propio 23\.

**Ejercicio 2.21: Criba de Eratóstenes**

Generalizar el algoritmo anterior para averiguar todos los números primos que existen entre 2 y n, siendo n un número introducido por teclado.

A este proceso se le conoce como criba de Eratóstenes. O, más bien, la criba de Eratóstenes es una forma de llegar a la misma lista de números a la que llegaremos nosotros con nuestro programa. No es que este detalle tenga mayor importancia, pero sirve de culturilla popular y para ponerle un título interesante a este ejercicio.

**Ejercicio 2.22: Sucesión de Fibonacci**

La famosa sucesión de Fibonacci es una sucesión no convergente de números enteros que comienza así:

0, 1, 1, 2, 3, 5, 8, 13, 21, 34, …

Cada número de la sucesión se calcula sumando los dos números anteriores (excepto los dos primeros, que son, por definición, 0 y 1).

Se da la curiosa circunstancia de que los números de la sucesión de Fibonacci aparecen con sorprendente precisión en muchas estructuras naturales, como los ángulos de crecimiento de las ramas de árboles cuando son iluminados verticalmente, la disposición de los pétalos de los girasoles o de las piñas en los pinos, la forma de las cochas de los caracoles, y cosas así. Si lo piensas, es un poco inquietante que un producto de la imaginación humana como son las matemáticas tenga una relación tan estrecha con la naturaleza. ¿O era al revés? Bueno, al diablo.

A lo que íbamos: escribe un programa que muestre en la pantalla los N primeros términos de la sucesión de Fibonacci, siendo N un número entero introducido por el usuario.

**Ejercicio 2.23: Número de la suerte**

El número de la suerte o lucky number, por si hay alguien de Cuenca, es una tontuna de los numerólogos y otros charlatanes que se obtiene sumando todas las cifras de la fecha de nacimiento de un modo azaroso. Por ejemplo, como yo nací el 15 de octubre de 1974 (15-10-1974), se supone que mi número de la suerte es 15+10+1974 \= 1999\. Ahora sumo todas las cifras de 1999 así: 1+9+9+9 \= 28\. Como aún tengo dos dígitos, vuelvo a sumarlos. 2 \+ 8 \= 10\. Y aún tengo dos dígitos que tengo que volver a sumar: 1 \+ 0 \= 1\.

Por lo tanto, 1 es mi número de la suerte. Si alguna vez me toca la lotería y llevo un número acabado en 1, os aviso.

Escribe un programa que, dada una fecha de nacimiento, calcule el número de la suerte de esa persona.

**Ejercicio 2.24: Omirps**

Un omirp es una de esas cosas que nos hace dudar sobre la estabilidad mental de los matemáticos. Se trata de un número primo que, al invertirlo, también da como resultado un número primo. Por ejemplo, el número 7951 es primo y, si le damos la vuelta, obtenemos 1597, que también es primo. Por lo tanto, 7951 es un omirp.

Se trataría, pues, de introducir un número y que el programa determine si es un omirp o no. O más difícil todavía (redoble de tambores): hacer un programa que muestre la lista de omirps entre 0 y N, siendo N un número introducido por el usuario.

(Este último programa es el tipo de cosas que te puedes encontrar en una entrevista de trabajo. Lo digo por experiencia).

## **BLOQUE III: Juegos y desafíos de lógica**

**Ejercicio 2.25: Juego del número secreto**

El ordenador elegirá un número al azar entre 1 y 100\. El usuario irá introduciendo números por teclado, y el ordenador le irá dando pistas: "mi número es mayor" o "mi número es menor", hasta que el usuario acierte. Entonces el ordenador le felicitará y le comunicará el número de intentos que necesitó para acertar el número secreto, sin humillarlo en caso de que hayan sido más de cinco.

**Ejercicio 2.26: Cuenta atrás**

Pide por teclado un número de segundos y muestra una cuenta atrás en la consola (PISTA: usa Thread.sleep(1000) para detener la ejecución del programa 1 segundo).

Cuando funcione, intenta mejorar la presentación mostrando no solo los segundos de la cuenta atrás, sino también las horas y los minutos que quedan.

**Ejercicio 2.27: Carrera de tortugas**

El ordenador manejará tres tortugas.

Las tortugas tienen que avanzar 10 pasos por turnos. En cada turno, solo pueden avanzar 0, 1 o 2 pasos (el número se elegirá al azar). Gana la primera tortuga que llegue a 10 pasos.

El usuario apostará por una de las tres tortugas antes de empezar la carrera. Al finalizar, el programa le dirá si ha ganado la apuesta o no.

**Ejercicio 2.28: Juego de dados**

El ordenador elige un número al azar entre 1 y 20\. El objetivo es acercarse lo máximo posible a ese número sin pasarse.

Después, el jugador y el ordenador “tiran” un dado (con valores de 1 a 6\) en turnos alternos, y van acumulando el número que les sale.

Cualquiera de los jugadores puede plantarse en cualquier momento. Gana quien más se acerca al número objetivo sin pasarse. Si un jugador se pasa, el otro gana automáticamente.

**Ejercicio 2.29: Doble o nada**

El jugador comienza con un saldo elegido por él.

El programa lanzará una moneda al azar. El jugador debe apostar una cantidad de dinero a si va a salir "cara" o "cruz".

Si acierta, duplica su apuesta. Si falla, pierde el doble de lo que apostó.

El juego continúa mientras el jugador quiera y aún tenga dinero. Es decir, después de cada ronda, habrá que preguntar al jugador si desea continuar o no.

**Ejercicio 2.30: Adivina la operación**

El ordenador muestra un número al azar entre 25 y 100 (será nuestro número objetivo) y 6 números al azar entre 1 y 10\.

El jugador debe conseguir encontrar una sucesión de operaciones aritméticas básicas (sumas, restas, multiplicaciones y divisiones) para combinar todos o algunos de los 6 números, de manera que el resultado sea el número objetivo.

Por ejemplo, si el número objetivo es 42 y los 6 números al azar son: 1, 3, 4, 5, 5 y 9, una posible solución sería:

5 \+ 5 \= 10

10 x 4 \= 40

40 \+ 3 \= 43

43 \- 1 \= 42

No es imprescindible usar todos los números (en esta solución no hemos usado el 9). Habrá combinaciones que tengan varias soluciones, y otras que no tengan ninguna.

El programa debe comprobar si nuestra solución es o no correcta.

**Ejercicio 2.31: Juego de memoria**

Vamos a hacer una versión del clásico juego "Simón dice", pero con números en lugar de palabras o colores.

Reglas del juego:

  * El juego comenzará preguntando el nivel de dificultad, que puede ser fácil, medio o difícil.  
  * El ordenador elegirá al azar una serie de números. La serie consistirá al principio en un solo número. Luego serán dos números, luego tres, luego cuatro... y así hasta diez. Los números de la serie solo pueden ser tres: 1, 2 y 3\.  
  * El ordenador mostrará su serie de números durante un tiempo en la pantalla. Ese tiempo será tanto menor cuanto más alto sea el nivel de dificultad. Recuerda que con Thread.sleep(n) puedes "detener" la ejecución del programa n milisegundos.  
  * Después, la serie se borrará y el jugador debe demostrar su memoria y sus reflejos repitiéndola. Más tarde esto no te hará ninguna gracia, cuando tengas que ponerte a averiguar como se hace eso de borrar la consola. Qué fácil es decirlo.  
  * Si el jugador acierta en todos los números de la serie, el ordenador pasará a su siguiente serie (que tendrá un número más). Si el jugador falla, el juego termina.  
  * Si el jugador es capaz de repetir con éxito todas las series (desde la que solo tiene un número hasta la que tiene 10), el jugador gana.

**Ejercicio 2.32: Tragaperras**

Vamos a escribir ahora un programa que simule el funcionamiento de una máquina tragaperras. Recuerda que la ludopatía es un problema serio, pero los juegos de azar como este son relativamente simples y adecuados para simular con un ordenador en el momento del curso en el que nos encontramos.

El programa debe tener el siguiente comportamiento:

a) Preguntará al usuario con cuánto dinero inicial desea jugar (en euros). Esta cantidad no puede ser menor que 1 euro ni mayor que 100\.

b) En cada jugada, el jugador decidirá cuánto dinero apostar (mínimo 1, máximo su saldo actual), que se descontará automáticamente del saldo que el jugador tenga en ese momento.

c) La máquina tiene tres rodillos con cinco símbolos dibujados en cada uno de ellos. En cada jugada, se obtendra una combinación de tres símbolos. Los cinco símbolos posibles son: Cereza, Campana, Diamante, Limón y Sol.

d) El jugador no gana nada si los tres símbolos que salen son distintos.

e) En cambio, si varios símbolos coinciden, el jugador gana un premio, que pasa a incrementar su saldo. El premio será:

  * Si dos símbolos cualesquiera son iguales, gana el doble de lo que apostó.

  * Si los tres símbolos son iguales, gana el doble de lo que apostó más un multiplicador según el símbolo: Cereza (x2), Campana (x3), Diamante (x5), Limón (x0), Naranja (x1).

f) Después de cada jugada, la máquina comunicará al jugador la combinación que ha salido y le dirá si ha ganado algún premio.

g) Después de eso, la máquina le dirá al jugador cuál es su saldo actual y le preguntará si desea seguir jugando. Si el jugador se queda sin dinero, el juego terminará automáticamente sin preguntar nada.

Este es un ejemplo de ejecución del programa:

```
*** BIENVENIDO AL JUEGO DE LA TRAGAPERRAS ***
¿Con cuánto dinero desea empezar (de 1 a 100 euros) ? 160
Cantidad incorrecta
¿Con cuánto dinero desea empezar (de 1 a 100 euros) ? 20
COMIENZA EL JUEGO...
Tu saldo actual es de 20€
¿Cuánto quieres apostar (1-20)? 3
Rodillos: CEREZA | DIAMANTE | CEREZA
¡Han salido 2 iguales! Ganas 6 €
Tu saldo ahora es de 23€
¿Quieres seguir jugando? (S/N) S
Tu saldo actual es de 23€
¿Cuánto quieres apostar (1-23)? 50
No puedes apostar más dinero del que tienes
¿Cuánto quieres apostar (1-23)? 5
Rodillos: CAMPANA | CAMPANA | CAMPANA
¡¡Han salido 3 iguales!! Premio: 30 €
Tu saldo ahora es de 48€.
¿Quieres seguir jugando? (S/N) N
Juego terminado. Saldo final: 48€
```