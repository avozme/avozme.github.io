---
layout: page
title: 3. Introducción a la programación
permalink: /introduccion-a-la-programacion/
nav_order: 3
has_children: true
parent: Tecnologías de la Información y la Comunicación 2º BACHILLERATO
---

# 3. Introducción a la programación
{: .no_toc }


- TOC
{:toc}

## 3.1. ¿Qué es exactamente eso de "programar un ordenador"?

**Programar un ordenador** no es más que proporcionarle a la máquina un conjunto de instrucciones y datos para que realice una tarea. Esa tarea, generalmente, resuelve un problema concreto, que puede ir desde realizar complicados cálculos matemáticos hasta entretenernos con un videojuego en nuestros ratos de ocio.

El conjunto de las instrucciones que conforma el programa se denomina **código fuente**, y tiene que estar escrito en un lenguaje comprensible por la máquina, es decir, un **lenguaje de programación**.

Esas instrucciones se traducen a **código binario** (que, recuerda, es lo único que puede comprender el ordenador). La CPU de un ordenador está construida de manera que puede entender y ejecutar ciertas instrucciones binarias, gracias a lo cual nuestro programa acaba ejecutándose en las entrañas de la máquina.

Este es un fragmento de un programa informático real escrito en lenguaje PHP. Implementa un algoritmo de ordenación de elementos llamado *Bubble Sort* o, en español, *método de la burbuja*. No es necesario, ni mucho menos, que lo entiendas de momento. Solo quiero que le eches un vistazo para que veas el aspecto que tiene un programa real (o un fragmento) escrito en un lenguaje real.

```php
function bubble_Sort($my_array )
{
	do
	{
		$swapped = false;
		for( $i = 0, $c = count( $my_array ) - 1; $i < $c; $i++ )
		{
			if( $my_array[$i] > $my_array[$i + 1] )
			{
				list( $my_array[$i + 1], $my_array[$i] ) =
						array( $my_array[$i], $my_array[$i + 1] );
				$swapped = true;
			}
		}
	}
	while( $swapped );
return $my_array;
}

$test_array = array(3, 0, 2, 5, -1, 4, 1);
echo "Original Array :";
echo implode(', ',$test_array );
echo "Sorted Array:";
echo implode(', ',bubble_Sort($test_array)). PHP_EOL;
```

(Fuente: php.net)

## 3.2. Programas y algoritmos

Para realizar un programa es necesario idear previamente un algoritmo. Esto es importante hasta el extremo de que, sin algoritmo, no existiría el programa.

Un algoritmo, como hemos visto, es una **secuencia ordenada de acciones que conducen a la solución de un problema en un número finito de pasos simples**.

Por ejemplo, vamos a escribir un algoritmo para determinar si un número entero cualquiera (que llamaremos N) es par o impar:

```
- Inicio del algoritmo
- Paso 1. Preguntar qué número concreto es N.
- Paso 2. Si N es divisible entre 2, entonces la solución es "PAR".
- Paso 3. Si N no es divisible entre 2, entonces la solución es "IMPAR".
- Paso 4. Imprimir la solución.
- Fin del algoritmo
```

Recuerda que este algoritmo está **escrito para que lo ejecute un ordenador**, no para que lo ejecute una persona. Por eso el Paso 1 es "Preguntar qué número es N": porque el ordenador tendrá que preguntarnos a nosotros, los humanos, el número. Y por eso el Paso 4 es "Imprimir la solución": porque el ordenador nos ofrecerá el resultado imprimiéndolo en la pantalla o en un papel.

Este algoritmo resuelve el problema planteado en un número finito de pasos simples. Lógicamente, al ordenador no le podemos dar estas instrucciones tal y como las hemos escrito, sino que habrá que expresarlo en un lenguaje de programación, pero esto es algo que trataremos más adelante.

### 3.3. Datos y tipos de datos

Los algoritmos, como hemos dicho, son colecciones de instrucciones que resuelven un problema.

Pero esas instrucciones **siempre trabajan con datos**, es decir, con información formalizada para su uso en un ordenador:

* **Los datos de entrada** son datos que el algoritmo necesita para trabajar. En el ejemplo anterior, el número "N" es un dato de entrada.
* **Los datos de salida** son datos que el algoritmo produce como resultado de sus cálculos. En el ejemplo anterior, "solución" es un dato de salida.

Los datos siempre pertenecen a un **tipo de datos**, que es el rango de valores que ese dato puede tomar. Existen multitud de tipos de datos posibles, pero empezaremos trabajando solo con estos:

* **Enteros**. Los datos de este tipo solo pueden tomar como valores números enteros (positivos o negativos). Ejemplos: 3, 28, -15, 0, 4982...
* **Reales**. Números con decimales. Ejemplos: 18.25, -3.198887
* **Caracteres**. Letras, números, signos de puntuación... Ojo, si un dato es de tipo "carácter", solo puede contener en cada momento un único carácter. Ejemplos: 'a', 'Z', '&', '?'
* **Cadenas de caracteres**. O, simplemente, *cadenas*. Son colecciones de letras, números, signos de puntuación... Es decir, palabras y cualquier cosa que se le parezca. Ejemplos: "Hoy es lunes", "sgcv08 e98 ie7f83 ?so9&/". Suelen distinguirse de los caracteres individuales por la doble comilla, aunque esto depende del lenguaje de programación.
* **Lógicos o booleanos**. Estos datos solo pueden tener dos valores: *verdadero* o *falso*.

### 3.4. Variables y constantes

Las **variables** de un algoritmo son como las variables en una ecuación matemática: representaciones de un dato a las que asignamos un nombre o identificador.

En el algoritmo para averiguar si un número es par o impar, *N* es una variable y *solución* es otra variable.

Las variables pueden tomar un valor perteneciente a un tipo de datos. Ese valor puede cambiar a lo largo del algoritmo (por eso se denominan *variables*). Lo que no puede cambiar es el tipo de datos al que pertenecen. Es decir: si una variable es entera, no puede cambiar y pasar a ser real durante la ejecución del programa.

(Bueno, hay lenguajes que sí permiten hacer esto, pero esa es otra historia).

Por eso, la mayoría de los lenguajes de programación exigen que les indiquemos a qué tipo de datos pertenece cada variable antes de usarlas por primera vez. Es algo que también haremos en pseudocódigo. Eso se denomina **declarar una variable**. 

Así pues, podemos mejorar el algoritmo anterior con la declaración de las variables "N" y "solución":

```
- Inicio del algoritmo
- Declaración de variables:
   - N es un número entero.
   - solución es una cadena de caracteres.
- Paso 1. Averiguar qué número es N.
- Paso 2. Si N es divisible entre 2, entonces la solución es "PAR".
- Paso 3. Si N no es divisible entre 2, entonces la solución es "IMPAR".
- Paso 4. Imprimir la solución.
- Fin del algoritmo
```

Las **constantes** se parecen a las variables: tienen un nombre y un tipo, y se les asigna un valor. La única diferencia es que una constante *no puede cambiar de valor durante la ejecución del algoritmo* y una variable sí.

### 3.5. Subalgoritmos

Cuando un algoritmo es muy complejo, lo dividimos en trozos más simples que denominamos **subalgoritmos**. En programación, esos subalgoritmos se denominan **procedimientos** o **funciones**. Son casi la misma cosa, con una sutil diferencia que ya veremos cuando llegue el momento.

Los lenguajes de programación reales, además de las instrucciones básicas que enseguida vamos a ver, tienen unas colecciones de funciones predefinidas llamadas **bibliotecas**. Esas funciones se encargan de realizar tareas habituales y repetitivas, de modo que nos ahorran un montón de trabajo.

Por ejemplo, es posible escribir algoritmos para hacer cálculos matemáticos complejos, tales como logaritmos o raíces cuadradas. Para evitarnos ese trabajo, todos los lenguajes de programación disponen de una biblioteca de funciones matemáticas que incluye, entre otras muchas cosas, el cálculo de logaritmos y de raíces cuadradas para cuando los necesitemos. Así que vamos a suponer, cuando escribamos pseudocódigo, que también tenemos a nuestra disposición de esas bibliotecas de funciones.

Algunos subalgoritmos o funciones que existen en todos los lenguajes de programación y que podemos considerar que también existen en pseudocódigo son las siguientes:

* abs(x). Calcula el valor absoluto de x. Funciona con números reales y con enteros.
* sen(x). Calcula el seno de x. Devuelve valores reales.
* cos(x). Calcula el coseno de x. Devuelve valores reales.
* exp(x). Calcula e<sup>x</sup>. Devuelve un real.
* ln(x). Calcula el logaritmo neperiano de x. Devuelve un valor real.
* redon(x). Redondea el número x al valor entero más próximo. El valor x será real, y la función devolverá un entero.
* trunc(x). Trunca el número x, es decir, le elimina la parte decimal. El valor x será real, y la función devolverá un entero.
* rc(x). Calcula la raíz cuadrada de x. Devuelve un valor real
* azar(x). Genera un número al azar entre 0 y x. Supondremos que solo funciona con números enteros.

### 3.6. Expresiones y operadores

Una **expresión** es una combinación de constantes, variables, operadores y funciones.

Por ejemplo, esto es una expresión:

<p align='center'>rc((5 + x) / 2)</p>

En esta expresión, aparecen dos constantes literales (5 y 2), una variable (x), dos operadores aritméticos (+ y /) y una función (rc, para calcular la raíz cuadrada), además de los paréntesis, que sirven para manipular la prioridad de las operaciones.

Lógicamente, para resolver la expresión, es decir, para evaluar su resultado, debemos conocer cuál es el valor de la variable x.

Si suponemos que la variable x tiene el valor 7, el resultado de la expresión será 2,449.

La forma más habitual de encontrar una expresión es combinada con una **sentencia de asignación a una variable**. Por ejemplo:

<p align='center'>y <- raiz((5 + x) / 2)</p>

En estos casos, la expresión (lo que hay a la derecha del signo "<-") se evalúa y *su resultado es asignado a la variable* situada a la izquierda del "<-". 

En el ejemplo anterior, suponiendo que la variable x valiera 7, la expresión se evaluaría como 2,449, y, por lo tanto, ese es el valor que se asignaría a la variable y.

En las expresiones anteriores se han realizado algunas operaciones matemáticas (como sumas o divisiones). Los símbolos que se usan para ello se denominan **operadores**. En programación, existen distintos tipos de operadores:

* **Operadores aritméticos**: para hacer operaciones matemáticas convencionales. Los más habituales son + (suma), - (resta), * (producto), / (división) y MOD (resto de la división entera).
* **Operadores relacionales**: se utilizan para comparar números, aunque también pueden comparar caracteres o cadenas alfabéticamente. Los más habituales son < (menor que), > (mayor que), = (igual que), != (distinto de), <= (menor o igual que) y > (mayor o igual que). El resultado de estas comparaciones siempre es un valor lógico, es decir, verdadero o falso.
* **Operadoresl lógicos**: se utilizan para comparar otros datos lógicos y relacionarlos entre sí. Los más habituales son Y, O y NO. Estas palabras tienen el mismo significado que en la lengua natural.

Observa, por ejemplo, este fragmento de pseudocódigo muy fácil de entender:

```
puntos_carnet = <poner-aquí-un-número-entero>
edad = <poner-aquí-otro-número-entero>
Si edad >= 18 y puntos_carnet > 0 Entonces
   escribir "Puedes conducir"
FinSi
Si edad < 18 o puntos_carnet = 0 Entonces
   escribir "No puedes conducir"
FinSi
```

Aquí se usan dos variables, *puntos_carnet* y *edad* (que pueden tomar el valor que quieras ponerle) y luego se hacen dos comparaciones que implican operadores relacionales y lógicos.

* En la primera comparación, se tienen que cumplir a la vez las dos condiciones (que la edad sea mayor o igual que 18 años y que los puntos del carnet sean superiores a cero) para que el programa nos diga *"Puedes conducir"*.
* En la segunda comparación, basta con que una de las dos condiciones se cumpla para que el programa diga *"No puedes conducir"*.

Es habitual encontrar varias operaciones juntas en una misma línea. En estos casos es imprescindible conocer la **prioridad de los operadores**, porque las operaciones se calcularán en el orden de prioridad y el resultado puede ser muy distinto del esperado. 

En general, los operadores aritméticos tienen la máxima prioridad y, entre ellos, la multiplicación y la división son más prioritarias que la suma o la resta. Los siguientes operadores por prioridad son los relacionales y, por último, los lógicos. Sin embargo, esto puede variar según el lenguaje de programación concreto.

Lo más apropiado, si tenemos dudas sobre el orden en el que se van a ejecutar las operaciones, es usar paréntesis, exactamente igual que hacemos en matemáticas.

### 3.7. Tipos de instrucciones

Hemos dicho varias veces que los algoritmos constan de dos elementos: un conjunto de datos (representados por constantes y variables) y un conjunto de instrucciones.

Son muy pocas, en realidad, las instrucciones que necesitamos para construir algoritmos que funcionen. Increíblemente pocas:

* **Instrucciones de entrada de datos**. Sirven para indicar que, en ese punto, hay que proporcionar un dato al algoritmo. En el *Paso 1* del algoritmo para determinar si un número es par o impar hay una instrucción de entrada.
* **Instrucciones de salida de datos**. Sirven para que el algoritmo nos facilite el resultado de sus cálculos. En el *Paso 4* del algoritmo par-impar hay una instrucción de salida.
* **Instrucciones de asignación**. Sirven para asignar un valor a una variable.
* **Instrucciones para crear subalgoritmos**. Sirven para declarar subalgoritmos y darles un nombre.
* **Instrucciones condicionales**. Sirven para bifurcar el posible flujo de ejecución del algoritmo. Las instrucciones condicionales contienen siempre una condición que puede ser verdadera o falsa. Si es verdadera, el algoritmo continúa por un camino. Si es falsa, continúa por otro. Antes o después, esa bifurcación finaliza y el flujo del algoritmo vuelve a reunirse.
* **Instrucciones iterativas**. Sirven para repetir una o varias instrucciones un número finito de veces. Son la estructura más difícil de manejar para los programadores principiantes.

### 3.8. Dos maneras formales de escribir los algoritmos: pseudocódigo y diagramas de flujo

Necesitamos un método de escritura de algoritmos que sea independiente del lenguaje de programación que luego se vaya a utilizar. Así se podrán traducir más tarde a cualquier lenguaje. 

Tres posibles maneras de escribir un algoritmo son:

* **Lenguaje natural** (como hicimos con el algoritmo para decidir si un número es o no par).
* **Diagramas de flujo**
* **Pseudocódigo**

Por supuesto, también podríamos escribir los algoritmos directamente con un lenguaje de programación real, pero, si eres principiante, es más fácil aprender a programar usando pseudocódigo o diagramas de flujo que hacerlo con un lenguaje de programación. No tengas prisa: el lenguaje de programación llegará muy pronto.

El lenguaje natural (castellano, en nuestro caso) no es apropiado porque, como todos los lenguajes naturales humanos, tiene muchas ambigüedades que provocarían que, a veces, no quedara claro lo que queremos decir.

El **pseudocódigo** es un lenguaje de codificación de algoritmos basado en la lengua castellana, pero donde solo se permite un conjunto reducido de palabras con un significado muy concreto. El pseudocódigo tiene dos propiedades que nos interesarán mucho: facilita considerablemente el aprendizaje de las técnicas de programación y logra que la traducción a un lenguaje de programación real sea casi instantánea. 

Los **diagramas de flujo** son representaciones gráficas de los algoritmos que ayudan a comprender de forma visual su funcionamiento. Tienen una correspondencia directa con los diagramas de flujo.

Son dos técnicas complementarias que vamos a trabajar indistintamente. Usar uno u otro es una cuestión de gustos y preferencias personales.

A continuación, vamos a mostrar el algoritmo que determina si un número es par escrito de los dos modos. Solo es un ejemplo, pero deberías echarle un vistazo con detenimiento para comprobar si lo entiendes o no. 

*"Con detenimiento"* significa que no lo leas deprisa y corriendo para marcharte a hacer otra cosa en dos minutos. Respira hondo y tómate tu tiempo.

Si no lo entiendes todo, no te agobies todavía. Aprenderás a escribir pseudocódigo y diagramas de flujo muy pronto.

**1. El algoritmo "Par-Impar" escrito como pseudocódigo:**

```
Algoritmo par_impar
	Definir N como Entero
	Definir solucion como Cadena

	Escribir "Dime un número:"
	Leer N
	Si N MOD 2 = 0 Entonces
		solucion <- "PAR"
	SiNo
		solucion <- "IMPAR"
	FinSi
	Escribir "El número ", N, " es ", solucion
FinAlgoritmo
```

**2. El algoritmo "Par-Impar" escrito como diagrama de flujo:**

![Diagrama de flujo par-impar](/docs/prog-y-3d/_site/assets/images/03-par-impar.png)

