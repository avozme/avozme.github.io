---
layout: page
title: 3. Programación con pseudocódigo
permalink: /pseudocodigoXXX/
nav_order: 3
has_children: true
parent: XXX Tecnologías de la Información y la Comunicación 2º BACHILLERATO
---


# 3. Programación con pseudocódigo
{: .no_toc }


- TOC
{:toc}

## 3.1. Qué es y qué no es el pseudocódigo

El pseudocódigo, ya lo hemos dicho, no es un lenguaje formal de programación, sino un *pseudolenguaje*.

Es decir, se asemeja a los lenguajes de programación, pero cada cual se lo monta un poco como quiere. No hay una única forma correcta y universalmente aceptada de escribir el pseudocódigo.

Nosotros vamos a usar una sintaxis concreta tomada de una utilidad llamada **[PSeInt](http://pseint.sourceforge.net/)**. Se trata de una herramienta aprender programación que permite escribir el pseudocódigo como si fuera un lenguaje de programación real, e incluso ejecutarlo para comprobar si funciona. Vamos a usar PSeInt para hacer las prácticas de esta sección y por eso aprenderemos su pseudocódigo y no otro cualquiera.

Hablaremos más de PSeInt en el apartado de ejercicios propuestos.

## 3.2. Instrucciones típicas en pseudocódigo (versión PSeInt)

La siguiente tabla muestra una lista de las instrucciones principales del pseudocódigo estándar de PSeInt.

<table>
<tr>
  <td style='background-color: lightgrey' width='30%'><strong>Instrucción</strong></td><td style='background-color: lightgrey'><strong>Significado</strong></td>
</tr>
<tr>
  <td><strong>Algoritmo</strong> nombre</td><td>Marca el comienzo de un algoritmo y le adjudica un nombre</td>
</tr>
<tr>
  <td><strong>FinAlgoritmo</strong></td><td>Marca el final del algoritmo</td>
</tr>
<tr>
  <td><strong>Definir</strong> variable <strong>Como</strong> tipo</td>
  <td>Declara una variable y le asigna un tipo. Los tipos válidos son Entero, Real, Carácter, Lógico y Cadena.</td>
</tr>
<tr>
  <td><strong>Leer</strong> variable</td>
  <td>Entrada de datos. El programa lee un dato desde un dispositivo de entrada (si no se indica otra cosa, el
teclado), asignando ese dato a la variable.</td>
</tr>
<tr>
  <td><strong>Escribir</strong> expresión</td>
  <td>Salida de datos. La expresión se calcula y su resultado se muestra en la pantalla.</td>
</tr>
<tr>
  <td>variable <- expresion</td>
  <td>Asignación. Se evalúa la expresión y el resultado se guarda en la variable.</td>
</tr>
<tr>
  <td><strong>Si</strong> condición <strong>Entonces</strong>
   &nbsp;&nbsp;&nbsp;&nbsp;acciones-1<br>
<strong>SiNo</strong><br>
   &nbsp;&nbsp;&nbsp;&nbsp;acciones-2<br>
<strong>FinSi</strong></td>
  <td>Estructura condicional. Se evalúa la condición. Si es verdadera, se ejecutan las "acciones-1". Si es falsa, se ejecutan las "acciones-2".</td>
</tr>
<tr>
  <td><strong>Segun</strong> expresión <strong>hacer</strong><br>
  &nbsp;&nbsp;&nbsp;&nbsp;valor-1: acciones-1;<br>
  &nbsp;&nbsp;&nbsp;&nbsp;valor-2: acciones-2;<br>
  &nbsp;&nbsp;&nbsp;&nbsp;...<br>
  &nbsp;&nbsp;&nbsp;&nbsp;valor-n: acciones-N;<br>
  &nbsp;&nbsp;&nbsp;&nbsp;<strong>De otro modo</strong>: acciones-por-defecto;<br>
<strong>FinSegun</strong></td>
  <td> Condicional múltiple. Si la expresión se evaúa como"valor-1", se ejecutan las acciones-1. Si vale "valor-2", se ejecutan las acciones-2, y así sucesivamente. Si la expresión no coincide con ningún valor, se ejecutan las acciones-por-defecto.</td>
</tr>
<tr>
  <td><strong>Mientras</strong> condición<br>
   &nbsp;&nbsp;&nbsp;&nbsp;acciones<br>
<strong>FinMientras</strong></td>
  <td>Bucle con condición al princio. Se realizan las acciones repetidamente mientras la condición siga siendo verdadera.</td>
</tr>
<tr>
  <td><strong>Repetir<br></strong>
   &nbsp;&nbsp;&nbsp;&nbsp;acciones<br>
<strong>Hasta Que</strong> condición</td>
  <td>Bucle con condición al final. Se realizan las acciones repetidamente mientras la condición siga siendo verdadera. Observa que el cuerpo de este bucle se ejecuta <i>al menos una vez</i>, mientras que el del bucle anterior podría no ejecutarse nunca (si la condición es falsa desde el principio).</td>
</tr>
<tr>
  <td><strong>Para</strong> variable <strong><-</strong> valor_inicial <strong>Hasta</strong> valor_final <strong>Hacer</strong><br>
   &nbsp;&nbsp;&nbsp;&nbsp;acciones<br>
<strong>FinPara</strong></td>
  <td>Bucle con iterador. Se asigna el valor_inicial a la variable. El bucle se repite hasta que la variable llega al valor_final. En cada iteración, la variable se incrementa en una unidad (se puede indicar otro incremento, pero, de momento, nos quedamos con ese).</td>
</tr>
</table>

También existen instrucciones para crear y manejar subalgoritmos. Como nuestros programas, de momento, van a ser muy simples, aún no vamos a verlas. Nos dedicaremos a ellas cuando llegue el momento.

## 3.3. Un ejemplo sencillo de algoritmo escrito en pseudocódigo

Vamos a terminar esta sección mostrando un ejemplo sencillo pero muy completo de algoritmo escrito en pseudocódigo.

Se trata de escribir un algoritmo tal que, dados dos números enteros (que llamaremos A y B), nos dirá cuáles son los números enteros que existen entre A y B ordenados de menor a mayor.

Lo primero que el algoritmo tendrá que hacer será pedirnos los valores de A y B. Después, tendrá que averiguar cuál de los dos es el menor (A o B), para poder luego meterse en un bucle que vaya desde el número menor hasta el número mayor, pasando por todos los valores intermedios e imprimiéndolos.

Las instrucciones de ese algoritmo serían estas:

```
Algoritmo contar_numeros
	Definir A,B,inicio,final,i Como Entero
	Escribir 'Dime un número'
	Leer A
	Escribir 'Dime otro número'
	Leer B
	Si (A<B) Entonces
		inicio <- A
		final <- B
	SiNo
		inicio <- B
		final <- A
	FinSi
	Escribir 'Estos son los números desde ',inicio,' hasta ',final
	i <- inicio
	Mientras (i<=final) Hacer
		Escribir i
		i <- i+1
	FinMientras
FinAlgoritmo
```

Léelo con atención y asegúrate de entenderlo antes de continuar. En la siguiente sección, veremos cómo representar este mismo algoritmo mediante un diagrama de flujo.

## 3.4. Errores frecuentes entre principiantes

En esta sección recopilo para ti algunas de las dudas, errores y pifias más frecuentes que, según mi experiencia como profesor de programación, suelen asaltar a los principantes.

#### No es lo mismo 20 que "20"

Así es. Cuando estás programando, no es lo mismo la instrucción ```Escribir 20``` (o cualquier otro número) que la instrucción ```Escribir "20"```, con el número entre comillas.

Las cadenas de caracteres siempre se ponen entre comillas. Los números NO.

Por eso, ```Escribir 20``` significa literalmente *mostrar en pantalla el número 20*, mientras que ```Escribir "20"``` significa *mostrar en pantalla la cadena de caracteres "20"*. 

Puede parecer lo mismo, pero no lo es. En una, 20 es un texto y, en otra, un número, y para el ordenador son cosas muy distintas (por ejemplo, no puedes sumar dos textos, pero sí dos números).

#### Escribir "a" no es lo mismo que Escribir a

Un caso particular de la confusión anterior, y muy frecuente cuando se empieza a programar, es confundir ```Escribir "a"``` (o cualquier otro carácter) con ```Escribir a```.

La primera instrucción pide al ordenador que escriba un texto (en este ejemplo, una letra "a").

La segunda instrucción pide al ordenador que escriba *el contenido* de una variable. Es decir, en ```Escribir a```, la a debe ser una variable preexistente. Y, como todas las variables, debe tener un valor. La instrucción ```Escribir a``` pide al ordenador que escriba ese valor, no una letra "a".

#### ¡Me hago un lío entre Escribir y Leer!

A menudo me he encontrado con que las personas que se inician en la programación de ordenadores confunden *escribir* y *leer*: ¡no tienen claro cuándo utilizar una y cuándo la otra!

Esta confusión se debe a un problema de punto de vista. El programador/a novato piensa los algoritmos *desde su punto de vista*, es decir, como si fuera él o ella quien debe ejecutar el algoritmo.

La solución pasa por cambiar el punto de vista. **El algoritmo lo ejecutará un ordenador**, no nosotros. Los algoritmos son colecciones de órdenes para el ordenador, no para nosotros. Podemos pensar en el ordenador como en un esclavo obediente que hará todo lo que le pidamos (siempre que se lo pidamos en un lenguaje que pueda entender).

Así, cuando le pedimos que ejecute una instrucción *escribir 'Hola'*, no somos nosotros los que vamos a escribir "Hola", sino que será la máquina la que lo hará. Y lo escribirá en su pantalla, que es la manera estandarizada en la que un ordenador escribe cosas.

Y cuando le pidamos que ejecute *leer n*, será el ordenador el que leerá el valor de la variable n. ¿Y cómo se las apaña un ordenador para leer cosas? A través de un dispositivo de entrada. Es decir, a través del teclado. La instrucción *leer n* hará que el programa se detenga hasta que tecleemos algo, y ese algo se almacenará en la variable n.

#### Errores lógicos: confundir Y con O

Este también es un problema frecuente, incluso entre programadores experimentados.

Recuerda que los operadores lógicos Y y O tienen exactamente el mismo significado que en español. A partir de ahí, solo te queda utilizar el sentido común.

Si, aún así, te enfrentas con una expresión que no acabas de comprender, trata de descomponerla en expresiones más simples para asimilar mejor la lógica del problema.

#### Confundir condición con iteración

Otro error recurrente entre principiantes consiste en confundir la estructura condicional con la iterativa. En concreto, confudir *Si... Entonces* con *Mientras... Hacer*.

Creo que se debe a que ambas instrucciones comparten la misma estructura: tienen una condición al principio y ejecutan una serie de acciones o no en función de esa condición.

Pero hay una diferencia fundamental: las acciones de un *Si... Entonces* solo se ejecutarán **una o ninguna vez**, y luego el programa continuará. Las acciones de un *Mientras... Hacer* se ejecutarán **cero, una o muchas veces**, dependiendo de la condición.

Por lo tanto, para saber si debes usar una u otra, pregúntate esto: "¿tiene sentido que estas acciones se ejecuten muchas veces o, como máximo, se ejecutarán una vez?". Si la respuesta es "muchas veces", necesitas un *Mientras... Hacer*. Si la respuesta es "una vez", necesitas un *Si... Entonces*.

Pongamos un ejemplo. Imagina que estás escribiendo un programa que pida un número y determine si es negativo. Puedes tener la tentación de escribir esto:

```
leer N
Mientras N < 0 Hacer    ---> ¡¡¡CUIDADO, ESTO ES UN ERROR!!!
   escribir "El número es negativo"
FinMientras
```

Si haces eso, habrás provocado involuntariamente un bucle infinito, ya que, cuando el programa entre en el bucle, no logrará salir jamás de él porque la condición siempre será verdadera.

Para no caer en este error, trata de responder a la pregunta que planteábamos antes. La única accion que hay dentro de este bucle es *Escribir "El número es negativo"*, así que debes preguntarte: "¿mi programa tiene que escribir *El número es negativo* muchas veces, o solo una (en caso de que el número, en efecto, sea negativo)?"

La respuesta, obviamente, es que basta con una. Así que la solución correcta a este problema es:

```
leer N
Si N < 0 Entonces
   escribir "El número es negativo"
FinSi
```

#### La plaga del Copy & Paste

A menudo sorprendo a mis estudiantes copiando y pegando fragmentos de su propio código para resolver un problema.

Cuando eso ocurre, siempre les digo: "¡Alto! Seguro que hay una forma mejor de hacerlo".

Y te aseguro que *siempre* la hay.

Copiar y pegar grandes trozos de código es una pésima práctica de programación. Y lo es por una razón muy sencilla de entender. Imagina que has copiado tu código en veinte sitios diferentes y, un buen día, descubres un error en él.

Te va a tocar corregir el error veinte veces.

No parece una estrategia muy eficiente.

Si estamos copiando y pegando código en varios lugares, seguro que hay otra manera más inteligente de organizar el código para evitar esas repeticiones. Normalmente, la solución pasa por usar subalgoritmos.

#### Funciona, pero ¿a qué precio?

Supongo que has oído la expresión "matar moscas a cañonazos".

A veces, un algoritmo funciona pero es tremendamente ineficiente. Cuando se lo hago notar a mis estudiantes, se rascan la cabeza, encojen los hombros y dicen: sí, pero funciona.

Es como si para ir de Almería a Madrid diésemos un rodeo por Nueva York y Calcuta. O por Júpiter y Saturno. Al final llegamos a Madrid. Dos semanas o dos milenios más tarde, pero llegamos. "Sí, pero funciona".

Bueno, pues no. No funciona. Si llego a Madrid con dos milenios de retraso, no funciona. Si una solución es extremadamente ineficiente, no funciona. Hay que buscar otra manera.

#### Soy un desordenado/a

¿Eres de esas personas que tiene su escritorio hecho un desastre? ¿Cuando abres el cajón de los calcetines parece que ha explotado una bomba nuclear en su interior? ¿Guardas comida caducada en el frigorífico durante meses antes de darte cuenta?

Entonces tienes todas las papeletas para ser el típico programador/a-desastre.

El programador/a-desastre escribe su código de cualquier manera, sin respetar las mínimas nociones de orden ni organización: sin sangrías, sin comentarios, sin estructura. Intentar bucear en su código es como entrar en la casa de un afectado por el síndrome de Diógenes.

En tu vida personal puedes se un poco desastre si quieres, pero en tu código fuente no. Tienes que escribir código fuente **pensando siempre que lo van a leer otras personas**.

#### Me da pereza poner nombres significativos a las variables

Las variables y constantes (así como los algoritmos y subalgoritmos) deberían tener nombres significativos, que den una idea de qué contiene esa variable.

Sin embargo, me he encontrado con muchos estudiantes que sienten una pereza congénita a la hora de inventar nombres para variables. O que no quieren escribir nombres muy largos, como si teclear un par de caracteres más les costase dinero.

Usar identificadores de variables tales como a, aa, aaa, a2, a3, a4 y otras variaciones sobre la letra a es una pésima idea. Usar identificadores como edad, coste_total, numero_de_vidas y cosas por el estilo es un síntoma de estabilidad mental y de buena educación hacia otros programadores que algún día puedan leer tu código.

#### Confudir variables y cadenas

Los identificadores de variables solo pueden contener letras, números y el símbolo "_" (subrayado). Nunca comillas.

Recuerda que las comillas se reservan *exclusivamente* para el contenido de las cadenas de caracteres.

Así que, si tienes una variable que se llama, por ejemplo, x, *nunca* aparecerá escrita como "x", porque esto último es una cadena de caracteres que contiene un único carácter (la equis).

#### Utilizar variables sin inicializar

Esto es un error común incluso entre programadores experimentados. Más que un error, se trata de un despiste habitual.

Todas las variables, antes de ser usadas, tienen que:

1. **Declararse**, esto eso, indicar su nombre y el tipo de datos al que pertenecen (entero, real, carácter, etc).
2. **Inicializarse**, es decir, asignarles un valor inicial antes de su primer uso.

Si te olvidas de inicializar una variable, ¿qué valor tiene?

Imagínate esta situación: declaras una variable llamada x de tipo entero, te olvidas de inicializarla y luego la usas en una operación aritmética como esta:

```
Definir x, y Como Entero
...
...
y = x * 2
```

¿Cuál será el valor que tomará la variable y? Es imposible determinarlo, ¿verdad?

Muchos lenguajes de programación impedirán hacer esto porque producirán un error durante la traducción o durante la ejecución. Otros, en cambio, no se preocupan de hacer este tipo de comprobaciones y te dejarán ejecutar ese código, pero el resultado será impredecible.

#### Utilizar variables sin declarar

Aún más grave que no inicializar una variable es no declararla. La mayoría de los lenguajes no permitirán usar una variable sin haberla declarado previamente, pero algunos sí.

#### Asignar de izquierda a derecha

Este es otro error frecuente entre principiantes. Por suerte, tiene fácil solución.

El error consiste en confundir los términos de una asignación.

Recuerda que, en las asignaciones:

* A la izquierda del símbolo <- tiene que aparecer una única variable.
* A la derecha del símobo <- puede aparecer una variable o una expresión compleja.

Una asignación válida es esta: ```x <- y * 2 + (rc(z)/8)```. Fíjate que a la izquierda aparece una variable solitaria (x) y a la derecha una expresión compleja.

El error consiste en hacer la asignación al revés, es decir, colocando la variable solitaria a la derecha y la expresión a la izquierda. Esto, por supuesto, no puede ejecutarse en ningún ordenador.

#### Usar palabras reservadas como identificadores

Otro despiste que todos cometemos a veces es usar una palabra reservada por el lenguaje de programación como identificador.

Por ejemplo, no es buena idea ponerle de nombre a una de mis variables cosas como *si*, *entonces*, *algoritmo* o *hacer*, puesto que son palabras reservadas de mi lenguaje (pseudocódigo). Cuando programes en un lenguaje de programación real, esto se hace extensible a cualquier palabra reservada de ese lenguaje.

Tampoco es buena idea usar tildes ni caracteres especiales (como vocales acentuadas) en los identificadores. La mayor parte de los lenguajes de programación reales no los aceptarán, así que mejor que nos acostumbremos a ello desde el principio, aunque infrinjamos algunas reglas ortográficas.

¡Ojo!, que solo seremos flexibles con la ortografía en el código fuente. El resto de nuestros textos no tienen permiso para vapulear la lengua.

#### La multiplicación se escribe *, no x

Recuerda que el símbolo para multiplicar, en informática, es el asterisco (*). Ni equis (x) ni punto (.)

#### Practicar, practicar y practicar

A programar se aprende programando. Esto es así de sencillo, y si alguien te dice lo contrario te está mintiendo.

No te creerías a nadie que te ofreciera un método mágico para aprender chino en solo un mes, practicando cinco minutos al día, ¿verdad? Pues a programar, lo mismo.

Ninguna cosa que merezca la pena aprender se aprende sin esfuerzo. Puede que no te guste esta idea, pero es lo que hay.

Así que, si estás dispuesto/a a aprender a programar, prepárate para pasar mucho tiempo peleando con tu ordenador (¡y con tu cabeza!) y a sudar tinta. Por eso es imprescindible disfrutar del proceso: si no, se vuelve una tarea tan ardua como escalar el Everest.

Así que mi principal consejo para todos los principiantes es: practica, practica y practica. Y si, mientras practicas, te das cuenta de que no estás disfrutando, plantéate si de verdad quieres aprender a programar. 

## 3.5. Ejercicios propuestos

A partir de este punto, necesitarás **instalar PSeInt** en tu ordenador.

En todos los ejercicios que vienen a continuación se te pide escribir un programa que resuelva un determinado problema. Puedes escribirlo en pseudocódigo o con un diagrama de flujo, como prefieras, ya que, con PSeInt, ambas herramientas son intercambiables. No dejes de comprobar que tu solución funciona antes de pasar al siguiente.

No es necesario que hagas *todos* los ejercicios. Están ordenados en un grado de dificultad creciente, de modo que, si los primeros te resultan muy sencillos, puedes saltar a otro un poco más complicado. Céntrate solo en los que te parezcan más interesantes, o incluso puedes inventarte tus propios programas.

En realidad, esto último es lo más adecuado. Recuerda que para aprender a programar necesitarás practicar, practicar y practicar. Y para lograr practicar tanto, es imprescindible que te guste lo que estás haciendo.

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

<div style='background: #eee'><p>Vamos a hacer una versión del popular juego de las Tres en Raya para jugar contra el ordenador. No será un juego con inteligencia artificial como el de la WOPR (si no sabes qué es la WOPR, bueno, ¿para qué sirve wikipedia?), pero te permitirá pasar un buen rato programando, que es de lo que se trata.</p>

<p>El juego se desarrolla en un tablero de 3 x 3 casillas en el que los jugadores van disponiendo sus fichas tratando de formar una línea vertical, horizontal o diagonal.</p>

<p>Las fichas del jugador humano tendrán forma de aspa (X) y, las del ordenador, forma de círculo (O)</p>

Al principio, el tablero está en blanco. Comenzará jugando el jugador humano, que colocará una ficha en el tablero. Después, será el turno del ordenador.

El proceso se repite hasta que uno de los dos consigue colocar tres fichas formando una línea, o hasta que ya no es posible colocar más fichas (situación de “tablas”)</div>

*Aviso: este juego es más difícil de programar que los anteriores.*

**Ejercicio 35**. Dibujar con asteriscos. Se trata de escribir un programa que sea capaz de dibujar en la pantalla, *mediante bucles*, estos bonitos diseños. Añade alguno de tu propia cosecha, por favor. (Por si queda alguna duda: el último se supone que es un árbol de navidad)

```
   *
  ***
 *****
*******


   *
  ***
 *****
*******
 *****
  ***
   *


   *
  * *
 *   *
*     *
 *   *
  * *
   *


      *
     ***
      *
     ***
    *****
   *******
      *
     ***
    *****
   *******
  *********
 ***********
*************
     ***
     ***
     ***
     ***
```

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



## 3.6. Ejercicios resueltos

A continuación, vamos a mostrar la solución de algunos de los ejercicios anteriores. No de todos, porque entonces este texto sería interminable, pero si de bastantes de ellos.

Ten en cuenta que, **en muchas ocasiones, hay más de una solución posible** igualmente válida. Si tú has logrado resolver el ejercicio por otra vía, puede que hayas dado con una de esas otras soluciones.

Sin embargo, también hay soluciones inaceptables por su poca eficiencia aunque, en apariencia, parezcan funcionar bien. Ten en cuenta que, para ir de Almería a Granada, se puede ir por la autovía A-92 o se puede dar un rodeo por Barcelona. O por Júpiter y Saturno. De todos esos modos conseguiremos llegar a Granada, pero las últimas soluciones son tan ineficientes que no resultan aceptables.

Lo mismo ocurre con los programas informáticos.

Cuando tu solución sea muy diferente de la mía, pregúntate si la tuya da un rodeo mucho mayor que la mía para llegar al mismo sitio, o si, por el contrario, es igual de eficiente (¡o incluso más!). En este caso, enhorabuena: has dado con una de esas soluciones alternativas de las que hablaba.

Por último, permíteme un consejo: **intenta resistir la tentación de mirar la solución a los ejercicios antes de hacerlos**. Es muy conveniente que pases un rato tratando de resolver los problemas por ti mismo/a antes de mirar la solución. Al menos, es muy conveniente si tu intención es aprender a programar.

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