---
layout: page
title: 2. Programación con diagramas de flujo
permalink: /diagramas-de-flujo/
nav_order: 2
has_children: true
parent: Tecnologías de la Información y la Comunicación 2º BACHILLERATO
---

# 2. Programación con diagramas de flujo
{: .no_toc }


- TOC
{:toc}

El diagrama de flujo es una de las herramientas más poderosas para describir algoritmos.

El diagrama de flujo permite **escribir gráficamente un algoritmo**, de manera que podemos comprobar de un golpe de vista si hemos cubierto todos los caminos que ese algoritmo puede tomar. Es una forma **intuitiva** y **muy sencilla** de escribir programas.

Una vez creado el diagrama de flujo, es sencillísimo transformarlo algoritmo a cualquier lenguaje de programación.

Los diagramas de flujo son herramientas descriptivas tan potentes que se utilizan con asiduidad en la vida diaria para entender mejor la lógica de un problema o su solución. Por ejemplo, en este diagrama de flujo se propone gráficamente un proceso de toma de decisiones para determinar si se realiza o no una intervención quirúrjica a un paciente en el contexto de la pandemia del COVID-19 (fuente: [Patient Safety in Surgery Journal](https://pssjournal.biomedcentral.com/articles/10.1186/s13037-020-00235-9)):

![Diagrama de flujo COVID-19](/docs/tico/_site/assets/images/03-diagrama-de-flujo-covid-19.png)

## 2.1. Simbología de los diagramas de flujo

En los diagramas de flujo, cada **símbolo** representa una operación específica. Las operaciones se conectan entre ellas con **flechas**, que indican el orden de ejecución.

Los símbolos de los diagramas de flujo orientados a programación están estandarizados, aunque puedes encontrar pequeñas diferencias según qué fuente consultes. Nosotros vamos a usar los de **PSeInt**, igual que haremos con el pseudocódigo, para luego no tener problemas cuando usemos esa herramienta para resolver nuestros ejercicios prácticos.

Los símbolos más importantes (pero no todos) de un diagrama de flujo, junto con su equivalencia en pseudocódigo, son estos:

<table>
<tr>
  <td style='background-color: lightgrey' width='30%'><strong>Símbolo</strong></td>
  <td style='background-color: lightgrey'><strong>Equivalencia en pseudocódigo</strong></td>
  <td style='background-color: lightgrey'><strong>Significado</strong></td>
</tr>
<tr>
  <td><img src='/docs/tico/_site/assets/images/simbolos-diagrama-flujo/03-simbolo-algoritmo.png'></td>
  <td><strong>Algoritmo</strong> nombre</td>
  <td>Marca el comienzo de un algoritmo y le adjudica un nombre</td>
</tr>
<tr>
  <td><img src='/docs/tico/_site/assets/images/simbolos-diagrama-flujo/03-simbolo-fin-algoritmo.png'></td>
  <td><strong>FinAlgoritmo</strong></td>
  <td>Marca el final del algoritmo</td>
</tr>
<tr>
  <td><img src='/docs/tico/_site/assets/images/simbolos-diagrama-flujo/03-simbolo-definir.png'></td>
  <td><strong>Definir</strong> variable <strong>Como</strong> tipo</td>
  <td>Declara una variable y le asigna un tipo.</td>
</tr>
<tr>
  <td><img src='/docs/tico/_site/assets/images/simbolos-diagrama-flujo/03-simbolo-leer.png'></td>
  <td><strong>Leer</strong> variable</td>
  <td>Entrada de datos.</td>
</tr>
<tr>
  <td><img src='/docs/tico/_site/assets/images/simbolos-diagrama-flujo/03-simbolo-escribir.png'></td>
  <td><strong>Escribir</strong> expresión</td>
  <td>Salida de datos.</td>
</tr>
<tr>
  <td><img src='/docs/tico/_site/assets/images/simbolos-diagrama-flujo/03-simbolo-asignacion.png'></td>
  <td>variable = expresion<br>variable <- expresion</td>
  <td>Asignación.</td>
</tr>
<tr>
  <td><img src='/docs/tico/_site/assets/images/simbolos-diagrama-flujo/03-simbolo-condicion.png'></td>
  <td><strong>Si</strong> condición <strong>Entonces</strong>
	&nbsp;&nbsp;&nbsp;&nbsp;acciones-1<br>
	<strong>SiNo</strong><br>
	&nbsp;&nbsp;&nbsp;&nbsp;acciones-2<br>
	<strong>FinSi</strong></td>
  <td>Estructura condicional.</td>
</tr>
<tr>
  <td><img src='/docs/tico/_site/assets/images/simbolos-diagrama-flujo/03-simbolo-mientras.png'></td>
  <td><strong>Mientras</strong> Condición<br>
   &nbsp;&nbsp;&nbsp;&nbsp;acciones<br>
  <strong>FinMientras</strong></td>
  <td>Bucle con condición al princio.</td>
</tr>
<tr>
  <td><img src='/docs/tico/_site/assets/images/simbolos-diagrama-flujo/03-simbolo-repetir.png'></td>
  <td><strong>Repetir<br></strong>
   &nbsp;&nbsp;&nbsp;&nbsp;acciones<br>
  <strong>Hasta Que</strong> Condición</td>
  <td>Bucle con condición al final.</td>
</tr>
<tr>
  <td><img src='/docs/tico/_site/assets/images/simbolos-diagrama-flujo/03-simbolo-para.png'></td>
  <td><strong>Para</strong> variable <strong><-</strong> valor_inicial <strong>Hasta</strong> valor_final <strong>Hacer</strong><br>
   &nbsp;&nbsp;&nbsp;&nbsp;acciones<br>
  <strong>FinPara</strong></td>
  <td>Bucle con iterador.</td>
</tr>
</table>

Recuerda que también existen símbolos para definir y utilizar **subalgoritmos**, destinados a dividir el algoritmo en trozos cuando resolvemos problemas complejos. Por ahora, nuestros problemas serán simples y no usaremos subalgoritmos. Cuando llegue el momento, explicaremos cómo se utilizan.

Para terminar, te muestro el algoritmo para contar números enteros entre dos números cualesquiera, A y B, escrito como un diagrama de flujo. No dejes de comparar esta solución con la que planteamos en pseudocódigo un poco más arriba. Ambas son exactamente iguales, pero están descritas con una herramienta diferente. Es como si hubiéramos escrito la misma frase en dos idiomas distintos.

![Diagrama de flujo contar-numeros](/docs/tico/_site/assets/images/03-contar-numeros.png)

## 2.2. Normas de escritura de diagramas de flujo

Los diagramas de flujo son herramientas intuitivas de leer y utilizar, pero, no obstante, conviene tener presentes algunas relgas básicas a la hora de hacerlo:

1. Los diagramas de flujo se escriben (y se leen) **de arriba a abajo y de izquierda a derecha**.
2. Los símbolos deben **unirse entre sí por flechas** (líneas de flujo) que indican el orden de ejecución.
3. Los símbolos deben **llevar en el interior información** que indiquen su función exacta.
4. Cada símbolo debe tener **un único flujo de entrada y un único flujo de salida**, excepto el **rombo**, que tiene **dos flujos de salida** (verdadero y falso).
5. Es conveniente **no cruzar las líneas** de flujo.

## 2.3. Programando con PseInt

PSeInt es una herramienta para el **aprendizaje de la programación** de gran éxito en el mundo hispano (ha sido desarrollada en Argentina). Permite escribir programas en varios dialectos de **pseudocódigo** y convertirlos a diagrama de flujo, o bien dibujar el **diagrama de flujo** y obtener de forma automática el pseudocódigo correspondiente.

Además, lo más alucinante es que, con PseInt, puedes **ejecutar tu programa** como si de un lenguaje de programación real se tratase.

PseInt es software libre y gratuito, y soporta múltiples plataformas (Windows, Linux y Mac), así que es perfecta para practicar con diagramas de flujo y pseudocódigo y ver tus programas en funcionamiento en el ordenador.

![Ejemplo de diagrama de flujo con PseInt](/docs/tico/_site/assets/images/03-pseint-ejemplo.jpg)

### 2.3.1. Instalación de PseInt

#### Si tu sistema operativo es Educandos/Guadalinex:

Si estás usando un sistema operativo Educandos o Guadalinex de la Junta de Andalucía, lo más conveniente es instalar PseInt desde el repositorio oficial.

Solo tienes que seguir estos pasos:

1. **Haz clic en el botón "eos"** (ver imagen más abajo).
2. **Busca "Centro de software"**.
3. **Busca "PseInt"**.
4. **Haz clic en "Instalar"**.

![Botón eos Educandos](/docs/tico/_site/assets/images/03-pseint-instalacion-1.jpg)

Ya tienes PseInt instalado en tu sistema. Puedes lanzar el programa desde el propio Centro de software (haciendo clic en "Lanzar") o bien desde el buscador de aplicaciones (botón "eos").

#### Si tu sistema operativo es otro:

Para cualquier otro sistema operativo (Windows, Linux o Mac) distinto de Educandos/Guadalinex, tendrás que descargar PseInt de la web del desarrollador e instalarlo manualmente siguiendo las instrucciones. Es posible que, dependiendo del sistema operativo, necesites permisos de administrador para hacerlo.

* **Para descargar PSeInt**: [http://pseint.sourceforge.net/](http://pseint.sourceforge.net/)
* **Para leer el manual de usuario**: [http://pseint.sourceforge.net/index.php?page=documentacion.php](http://pseint.sourceforge.net/index.php?page=documentacion.php)

#### ¡OJO! Primera ejecución de PseInt

En la primera ejecución del PseInt, el programa te hará algunas preguntas para configurar tus preferencias. Es importante que respondas adecuadamente a estas preguntas. Si te equivocas, se puede reconfigurar más tarde, pero resulta más complicado.

1. Cuando te pregunte si quieres crear un icono en el escritorio o una entrada en el menú de aplicaciones, elige como mínimo **"Crear icono en el escritorio"**. Así podrás iniciar PseInt con rapidez la próxima vez que lo necesites.
2. Cuando te pregunte por tu perfil, elige **"Opción 3: no seleccionar perfil"**. Los perfiles se refieren al dialecto de pseudocódigo que PseInt entenderá. De momento, te interesa usar la Opción 3, que es la más flexible y con menos complicaciones.

### 2.3.2. Dibujar y ejecutar diagramas de flujo con PseInt

**1)** Haz clic en el **botón "Dibujar diagrama de flujo"**.

![Botón dibujar diagrama de flujo](/docs/tico/_site/assets/images/03-pseint-dibujar-diagrama-1.jpg)

**2)** **Arrastra los símbolos** y colócalos en el lugar correcto del diagrama.

**3)** Haz **doble clic** para escribir dentro de cada símbolo.

![Creando un diagrama de flujo](/docs/tico/_site/assets/images/03-pseint-dibujar-diagrama-2.jpg)

**4)** Haz clic en el **botón "Ejecutar"** para probar tu programa.

![Ejecutando un diagrama de flujo](/docs/tico/_site/assets/images/03-pseint-ejecutar-diagrama.jpg)

## 2.4. Ejercicios propuestos

A partir de este punto, necesitarás **instalar PSeInt** en tu ordenador.

En todos los ejercicios que vienen a continuación se te pide escribir un programa que resuelva un determinado problema. Puedes escribirlo en pseudocódigo o con un diagrama de flujo, como prefieras, ya que, con PSeInt, ambas herramientas son intercambiables. No dejes de comprobar que tu solución funciona antes de pasar al siguiente.

No es necesario que hagas *todos* los ejercicios. Están ordenados en un grado de dificultad creciente, de modo que, si los primeros te resultan muy sencillos, puedes saltar a otro un poco más complicado. Céntrate solo en los que te parezcan más interesantes, o incluso puedes inventarte tus propios programas.

En realidad, esto último es lo más adecuado. Recuerda que para aprender a programar necesitarás practicar, practicar y practicar. Y para lograr practicar tanto, es imprescindible que te guste lo que estás haciendo.

**Ejercicio 0**. **Instala PseInt en tu ordenador** siguiendo las instrucciones que [hemos dado antes](/docs/tico/_site/diagramas-de-flujo/#231-instalación-de-pseint).

Comprueba que el programa arranca con normalidad y sin errores.

No olvides configurar adecuadamente PseInt durante la primera ejecución. Si te equivocas, se puede reconfigurar más tarde, pero es más engorroso.

Si el programa ya está instalado en tu ordenador, puedes pasar al siguiente ejercicio.

#### Ejercicios con estructura secuencial

**Ejercicio 1**. 
<div style='background: #eee'>Calcular el área y la circunferencia de un círculo cuyo radio será proporcionado a través del teclado. Recuerda que área = 3.14 x r x r y circunferencia = 2 x 3.14 x r</div>

**Ejercicio 2**. 
<div style='background: #eee'>Pedir las cuatro notas de los exámenes del primer trimestre de un alumno y mostrar la nota media obtenida.</div>

**Ejercicio 3**. 
<div style='background: #eee'>Calcular el precio de llenar una piscina de agua. Para ello se tienen que pedir al usuario las medidas de la piscina (largo, ancho y alto) y el precio del m​<sup>3</sup>​ del agua. Se mostrará el precio total. Supondremos que la piscina es de forma regular.</div>

#### Ejercicios con estructuras condicionales

**Ejercicio 4**. 
<div style='background: #eee'>Determinar si un número leído del teclado es positivo, negativo o cero.</div>

**Ejercicio 5**. Calcular la raíz cuadrada de un número introducido por teclado. Hay que tener la precaución de comprobar que el número sea positivo.

**Ejercicio 6**. Leídos dos números por teclado, A y B, calcular la resta del mayor menos el menor. Por ejemplo, si A = 8 y B = 3, el resultado debe ser A – B, es decir, 5. Pero si A = 4 y B = 7, el resultado debe ser B – A, es decir, 3.

**Ejercicio 7**. Averiguar si un número real introducido  por teclado tiene o no parte fraccionaria (utilícese la función trunc() que aparece descrita en los apuntes)

**Ejercicio 8**. 
<div style='background: #eee'>Leer un número real y un tipo de moneda, que puede ser "euro" o "peseta". Convertir la cantidad al tipo de moneda indicado, suponiendo que está expresada en la otra. Por ejemplo, si la cantidad es 15 y la moneda es "peseta", se supondrá que se trata de 15 € y que hay que convertirlos a pesetas y, por lo tanto, el resultado debe ser 2495.</div>

**Ejercicio 9**. Leer tres números por teclado, X, Y y Z, y decidir si están ordenados de menor a mayor.

**Ejercicio 10**. Como el anterior, pero para averiguar si los números son consecutivos.

**Ejercicio 11**. Determinar si un año es bisiesto o no (los años bisiestos son múltiplos de 4; utilícese el operador módulo)

**Ejercicio 12**. 
<div style='background: #eee'>Determinar el número de cifras de un número entero. El algoritmo debe funcionar para números de hasta 5 cifras, considerando los negativos. Por ejemplo, si se introduce el número 5342, la respuesta del programa debe ser 4. Si se introduce –250, la respuesta debe ser 3.</div>

**Ejercicio 13**. Calcular las dos soluciones de una ecuación de segundo grado, del tipo ax<sup>2</sup> + bx + c = 0. Los coeficientes a, b y c deberá introducirlos el usuario a través del teclado.

#### Ejercicios con estructuras condicionales e iterativas

**Ejercicio 14**. 
<div style='background: #eee'>Escribir todos los números entre 1 y n, siendo n un entero introducido por teclado.</div>

**Ejercicio 15**. 
<div style='background: #eee'>Escribir todos los números pares entre 1 y n.</div>

**Ejercicio 16**. 
<div style='background: #eee'>Escribir todos los números impares entre dos números a y b introducidos por teclado. Antes habrá que comprobar cuál de los dos números (a o b) es mayor.</div>

**Ejercicio 17**. Calcular la suma de todos los números pares entre 1 y n, siendo n un entero introducido por teclado. Es decir, hay que calcular 2 + 4 + 6 + ... hasta n (o n-1, si n es un número impar).

**Ejercicio 18**. 
<div style='background: #eee'>Realiza un programa que calcule la suma de los n primeros números, donde n es un número introducido por teclado. Al terminar, el programa nos mostrará el mensaje "¿Desea terminar? (S/N)". Si el usuario escribe "S", el programa terminará, pero, si escribe "N", volverá a comenzar.</div>

**Ejercicio 19**. Calcular la nota media de un alumno a partir de las notas de todos sus exámenes a lo largo del curso. El programa nos irá pidiendo notas, pero no sabemos cuántas son. Para terminar de introducir valores, el usuario debe teclear un número negativo. Entonces, el programa calculará el promedio de todas las notas introducidas.

**Ejercicio 20**. El usuario de este programa será un profesor, que introducirá las notas de sus 30 alumnos de una en una. El algoritmo debe decirle cuántos suspensos y cuántos aprobados hay.

**Ejercicio 21**. Calcular el valor máximo de una serie de 10 números introducidos por teclado. 

**Ejercicio 22**. 
<div style='background: #eee'>Generalizar el ejercicio anterior para que también se averigüe el valor mínimo y el medio.</div>

**Ejercicio 23**. 
<div style='background: #eee'>Calcular el factorial de un número entero N. Recuerda que el factorial de un número es el producto de ese número por todos los enteros menores que él. Por ejemplo, el factorial de 5 (simbolizado 5!) se calcula como: 5! = 5 x 4 x 3 x 2 x 1.</div>

**Ejercicio 24**. 
<div style='background: #eee'>Generar combinaciones al azar para la lotería primitiva (6 números entre 1 y 49). Debes utilizar la función azar(x) que vimos en los apuntes. Por ahora, no te preocupes porque los números puedan repetirse.</div>

**Ejercicio 25**. 
<div style='background: #eee'>Generar combinaciones al azar para la quiniela (14 valores dentro del conjunto 1, X o 2).</div>

#### Ejercicios más avanzados

**Ejercicio 26**. 
<div style='background: #eee'>Determinar si un número N introducido por teclado es o no primo. Recuerda que un número primo es aquél que sólo es divisible por sí mismo y por la unidad.</div>

**Ejercicio 27**. Generalizar el algoritmo anterior para averiguar todos los números primos que existen entre 2 y N, siendo N un número introducido por teclado.

**Ejercicio 28**. Introducida una hora por teclado (horas, minutos y segundos), se pretende sumar un segundo a ese tiempo e imprimir en la pantalla la hora que resulta (también en forma de horas, minutos y segundos).

**Ejercicio 29**. La calculadora. Diseñar un algoritmo que lea dos números, A y B, y un operador (mediante una variable de tipo carácter), y calcule el resultado de operar A y B con esa operación. Por ejemplo, si A = 5 y B = 2, y operación = "+", el resultado debe ser 7. El algoritmo debe seguir pidiendo números y operaciones indefinidamente, hasta que el usuario decida terminar (utilizar un valor centinela para ello)



#### Algunos juegos sencillos


**Ejercicio 30. Juego del número secreto**. El ordenador elegirá un número al azar entre 1 y 100. El usuario irá introduciendo números por teclado, y el ordenador le irá dando pistas: "mi número es mayor" o "mi número es menor", hasta que el usuario acierte. Entonces el ordenador le felicitará y le comunicará el número de intentos que necesitó para acertar el número secreto**.

**Ejercicio 31. Número de la suerte**

El número de la suerte o *lucky number* es una tontuna que se han inventado los numerólogos y que se obtiene sumando todas las cifras de la fecha de nacimiento de un modo azaroso. Por ejemplo, como yo nací el 15 de octubre de 1974 (15-10-1974), se supone que mi número de la suerte es 15+10+1974 = 1999. Ahora sumo todas las cifras de 1999 así: 1+9+9+9 = 28. Como aún tengo dos dígitos, vuelvo a sumarlos. 2 + 8 = 10. Y, por último, 1 + 0 = 1.

Por lo tanto, 1 es mi número de la suerte. Si alguna vez me toca la lotería y llevo un número acabado en 1, os aviso.

Por ahora, nos conformamos con escribir un programa que, dada una fecha de nacimiento (día, mes y año), calcule el número de la suerte de esa persona.

**Ejercicio 32. El juego de la ruleta**

<div style='background: #eee'>Escribe un programa que permita jugar a la ruleta con el ordenador. 

Supondremos que la ruleta tiene 20 números rojos y 20 negros. El jugador, que tendrá una suma de dinero inicial, apostará una cantidad (siempre menor que el dinero que le quede) a un número y un color.

La ruleta, que puedes simular con el método azar(), la manejará el ordenador y comunicará al jugador el resultado. 

Si el jugador acierta, multiplicará por 10 el dinero apostado. Si falla, perderá el dinero apostado. El proceso se repetirá hasta que el jugador decida abandonar el juego, o bien se quede sin dinero.

Por favor, abstenerse ludópatas.</div>

**Ejercicio 33. Juego de dados**

Escribe un programa para jugar a los dados con el ordenador. Las reglas del juego son las siguientes:

* El jugador humano dispondrá de una cantidad inicial de dinero que se introducirá por teclado.
* El jugador apostará una cantidad de dinero (siempre igual o menor del que le queda)
* Después, se tirarán tres dados (lo cual se puede simular con el método azar())
* Si en los tres dados sale la misma cantidad, el dinero apostado por el jugador:
   * Se multiplica por 5 si en los dados ha salido un 6
   * Se multiplica por 3 si sale cualquier otra cantidad
* Si en dos dados de los tres sale la misma cantidad, el dinero apostado se multiplica por 2
* En cualquier otro caso, el dinero apostado se pierde
* El proceso se repite hasta que el jugador se queda sin dinero o hasta que decide dejar de jugar.

**Ejercicio 34. Juego de las Tres en Raya**

Vamos a hacer una versión del popular juego de las Tres en Raya para jugar contra el ordenador. No será un juego con inteligencia artificial pero te permitirá pasar un buen rato programando, que es de lo que se trata.</p>

El juego se desarrolla en un tablero de 3 x 3 casillas en el que los jugadores van disponiendo sus fichas tratando de formar una línea vertical, horizontal o diagonal.

Las fichas del jugador humano tendrán forma de aspa (X) y, las del ordenador, forma de círculo (O)

Al principio, el tablero está en blanco. Comenzará jugando el jugador humano, que colocará una ficha en el tablero. Después, será el turno del ordenador.

El proceso se repite hasta que uno de los dos consigue colocar tres fichas formando una línea, o hasta que ya no es posible colocar más fichas (situación de “tablas”)

*Aviso: este juego es más difícil de programar que los anteriores.*

**Ejercicio 35. Cajero automático**

En este ejercicio, vamos a simular el funcionamiento de un **cajero automático** cuando sacas dinero de él.

Cuando el programa comience, le asignaremos al cajero una cantidad limitada de billetes de 10, 20 y 50 euros (por ejemplo, puedes hacer que tenga 50 billetes de cada tipo).

Después, el programa nos preguntará cuánto dinero queremos sacar, y nos lo "entregará" (figuradamente) como una colección de billetes. Por ejemplo, si le pedimos 90 euros, nos lo puede entregar como 1 billete de 50 y 2 billetes de 20, o como 1 billete de 50 y 4 billetes de 10.

¡El programa debería elegir la mejor manera de entregarnos los billetes para no quedarse sin dinero demasiado pronto!

Después de "entregarnos" el dinero, el programa nos informará de cuántos billetes le quedan aún de 50, de 20 y de 10 (esto no lo hacen los cajeros reales, pero nos servirá para comprobar si el programa está funcionando correctamente)

Llegará un momento en el que el cajero no pueda entregarnos la cantidad solicitada porque no le queden billetes suficientes. En ese caso, debe pedirnos disculpas y solicitarnos otra cantidad.

El programa terminará cuando el usuario así lo decida o cuando el cajero se quede sin billetes de ningún tipo.

**Ejercicio 36. Máquina tragaperras**

Vamos a escribir ahora un programa que simule el funcionamiento de una máquina tragaperras. No es que yo tenga ningún problema con los juegos de azar, ¿eh?, es solo que son simples y adecuados para simular con un ordenador en el momento del curso en el que nos encontramos. Además, puedo dejarlos cuando quiera. 

El programa debe tener el siguiente comportamiento:
   
a) Preguntará al usuario con cuánto dinero inicial desea jugar (en euros). Esta cantidad no puede ser menor que 1 euro ni mayor que 50. 

b) Cada jugada costará 0,50 euros, que se descontarán automáticamente del saldo que el jugador tenga en cada momento.

c) Cada jugada consiste en una combinación de tres frutas elegidas al azar entre estas seis:
* Manzana
* Naranja
* Fresa
* Cereza
* Limón
* Sandía

d) El jugador no gana nada si las tres frutas que salen son distintas.

e) En cambio, si varias frutas coinciden, el jugador gana un premio, que pasa a incrementar su saldo. El premio será:

* Si dos frutas cualesquiera son iguales:

   * 1) Si son dos cerezas, 3 euros
   * 2) Si son dos sandías, 2 euros
   * 3) Si no son ni sandías ni cerezas, 1 euro

* Si las tres frutas son iguales:

   * 1) Si son tres cerezas, 30 euros
   * 2) Si son tres sandías, 20 euros
   * 3) Si son tres fresas, 10 euros
   * 4) Si no son ni cerezas, ni sandías, ni fresas, 5 euros

f) Después de cada jugada, la máquina comunicará al jugador la combinación que ha salido y le dirá si ha ganado algún premio.

g) Después de eso, la máquina le dirá al jugador cuál es su saldo actual y le preguntará si desea seguir jugando. Si el jugador se queda sin dinero, el juego terminará automáticamente sin preguntar nada.
       
Este es un ejemplo de ejecución del programa:

```       
*** BIENVENIDO AL JUEGO DE LA TRAGAPERRAS ***
¿Con cuánto dinero desea empezar (de 1 a 50 euros) ? 60
Cantidad incorrecta
¿Con cuánto dinero desea empezar (de 1 a 50 euros) ? 20
COMIENZA EL JUEGO...
La combinación de esta jugada es: NARANJA – CEREZA – SANDÍA
Lo siento, no ha obtenido ningún premio
Su saldo actual es de 19,5 euros. 
¿Desea jugar otra vez (S/N) ? S
La combinación de esta jugada es: SANDÍA – SANDÍA - LIMÓN
¡Enhorabuena! Ha ganado 20 euros.
Su saldo actual es de 39,5 euros. 
¿Desea jugar otra vez (S/N) ? N
¡Hasta la próxima!
```

#### Desafíos matemáticos para personas valientes

**Ejercicio 37**. Mínimo común múltiplo. El programa nos pedirá dos números y calculará el mínimo común múltiplo de ambos. *Atención: este ejercicio es de dificultad elevada*.

**Ejercicio 38**. Máximo común divisor. Como el anterior, pero calculando el máximo común divisor. *Atención: este ejercicio es de dificultad elevada*.

**Ejercicio 39**. Escribe un programa que pregunte al usuario su fecha de nacimiento y la fecha del día de hoy, y calcule la edad del usuario en años.

(Aviso: no es tan fácil como parece)

Este programa se puede mejorar haciendo que calcule la edad en años, meses y días (¡incluso en horas, minutos y segundos!), pero es una labor por ahora solo apta para los más atrevidos/as.
