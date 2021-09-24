---
layout: page
title: 3. Introducción a la programación
permalink: /introduccion-a-la-programacion/
nav_order: 3
has_children: true
parent: Introd. a la prog. y al diseño 3D
---

# 3. Introducción a la programación
{: .no_toc }

Lenguajes de programación. Tipos de lenguajes. Estructura de un programa informático. Tipos básicos de datos. Constantes y variables. Operadores y expresiones. Comentarios. Pseudocódigo y diagramas de flujo. Estructuras de control: secuencial, condicional e iterativa.

- TOC
{:toc}

## 3.1. ¿Qué es exactamente eso de "programar un ordenador"?

**Programar un ordenador** no es más que proporcionarle a la máquina un conjunto de instrucciones y datos para que realice una tarea. Esa tarea, generalmente, resuelve un problema concreto, que puede ir desde realizar complicados cálculos matemáticos hasta entretenernos con un videojuego en nuestros ratos de ocio.

El conjunto de las instrucciones que conforma el programa se denomina **código fuente**, y tiene que estar escrito en un lenguaje comprensible por la máquina, es decir, un **lenguaje de programación**.

Esas instrucciones se traducen a **código binario** (que, recuerda, es lo único que puede comprender el ordenador). La CPU de un ordenador está construida de manera que puede entender y ejecutar ciertas instrucciones binarias, por lo que nuestro programa acaba ejecutándose en las entrañas de la máquina.

Este es un fragmento de un programa informático real escrito en lenguaje PHP:

XXX fragmento PHP

### 3.1.2. Programas y algoritmos

Para realizar un programa es necesario idear previamente un algoritmo. Esto es importante hasta el extremo de que, sin algoritmo, no existiría el programa.

Un algoritmo, como hemos visto, es una **secuencia ordenada de acciones que conducen a la solución de un problema en un número finito de pasos simples**.

Por ejemplo, vamos a diseñar un algoritmo simple que determine si un número N es par o impar:

* Inicio del algoritmo
* Paso 1. Averiguar qué número es N.
* Paso 2. Si N es divisible entre 2, entonces la solución es "PAR".
* Paso 3. Si N no es divisible entre 2, entonces la solución es "IMPAR".
* Paso 4. Imprimir la solución.
* Fin del algoritmo

Este algoritmo resuelve el problema planteado en un número finito de pasos simples. Lógicamente, al ordenador no le podemos dar estas instrucciones tal y como las hemos escrito, sino que habrá que expresarlo en un lenguaje de programación, pero esto es algo que trataremos más adelante.

### 3.1.3. Formas de escribir los algoritmos

Los algoritmos se escriben con métodos independientes del lenguaje de programación que luego se vaya a utilizar. Así se podrán traducir más tarde a cualquier lenguaje. 

Tres posibles formas de escribir un algoritmo son:

* Lengua castellana (como el algoritmo anterior para calcular si un número es o no par).
* Diagramas de flujo
* Pseudocódigo

El **pseudocódigo** es un lenguaje de especificación de algoritmos basado en la lengua castellana que tiene dos propiedades que nos interesarán: facilita considerablemente el aprendizaje de las técnicas de programación y logra que la traducción a un lenguaje de programación real sea casi instantánea. 

Los **diagramas de flujo** son representaciones gráficas de los algoritmos que ayudan a comprender su funcionamiento.

A continuación, vamos a mostrar el algoritmo para determinar si un número es par como pseudocódigo y como diagrama de flujo.

```
Proceso par_impar
	Definir N como Entero;
	Definir solucion como Cadena;

	Escribir "Dime un número: ";
	Leer N;
	Si (N % 2 = 0) Entonces
		solucion <- "PAR";
	SiNo
		solucion <- "IMPAR";
	FinSi
	Escribir "El número ", N, " es ", solucion;
FinProceso
```

![Algoritmo en pseudocódigo](/docs/prog-y-3d/_sites/assets/images/03-par-impar.png)

XXX

Escritura inicial del algoritmo
Una vez superadas las fases de análisis y diseño, es decir, entendido bien el problema y sus datos y descompuesto en problemas más sencillos, llega el momento de resolver cada problema sencillo mediante un algoritmo.
Muchos autores recomiendan escribir una primera versión del algoritmo en lenguaje natural (en nuestro caso, en castellano), siempre que dicha primera version cumpla dos condiciones:
    • Primera: que la solución se exprese como una serie de instrucciones o pasos a seguir para obtener una solución al problema
    • Segunda: que las instrucciones haya que ejecutarlas de una en una, es decir, una instrucción cada vez
Por ejemplo, consideremos un problema sencillo: el cálculo del área y del perímetro de un rectángulo. Evidentemente, tenemos que conocer su base y su altura, que designaremos con dos variables de tipo real. Una primera aproximación, en lenguaje natural, podría ser:
1. Inicio
2. Preguntar al usuario los valores de base y altura
3. Calcular el área como área = base * altura
4. Calcular el perímetro como perímetro = 2 * base + 2 * altura
5. Fin
Describir un algoritmo de esta forma puede ser útil si el problema es complicado, ya que puede ayudarnos a entenderlo mejor y a diseñar una solución adecuada. Pero esto sólo es una primera versión que puede refinarse añadiendo cosas. Por ejemplo, ¿qué pasa si la base o la altura son negativas o cero? En tal caso, no tiene sentido averiguar el área o el perímetro. Podríamos considerar esta posibilidad en nuestro algoritmo para hacerlo más completo:
1. Inicio
2. Preguntar al usuario los valores de base y altura
3. Si base es mayor que cero y altura también, entonces:
   3.1. Calcular el área como área = base * altura
   3.2. Calcular el perímetro como perímetro = 2 * base + 2 * altura
4. Si no:
   4.1. No tiene sentido calcular el área ni el perímetro
5. Fin
Estos refinamientos son habituales en todos los algoritmos y tienen la finalidad de conseguir una solución lo más general posible, es decir, que pueda funcionar con cualquier valor de "base" y "altura".
Diagramas de flujo
El diagrama de flujo es una de las técnicas de representación de algoritmos más antigua y también más utilizada, al menos entre principiantes y para algoritmos sencillos. Con la práctica comprobaremos que, cuando se trata de problemas complejos, los diagramas de flujo se hacen demasiado grandes y complicados.
Un diagrama de flujo o flowchart es un gráfico en el que se utilizan símbolos (o cajas) para representar los pasos del algoritmo. Las cajas están unidas entre sí mediante flechas, llamadas líneas de flujo, que indican el orden en el que se deben ejecutar para alcanzar la solución.
Los símbolos de las cajas están estandarizados y son muy variados. En la tabla siguiente tienes los más habituales, aunque existen algunos otros que no vamos a utilizar.

Símbolo
Función

Terminal. Representa el comienzo o el fin de un programa.

Entrada / Salida. Indica una introducción de datos desde un dispositivo externo (por defecto, el teclado) o una salida de datos hacia algún dispositivo externo (por defecto, la pantalla)

Proceso. Representa cualquier operación que se lleve a cabo con los datos del problema.

Condición. Señala una bifurcación del flujo de instrucciones. La bifurcación está siempre controlada por una operación relacional llamada condición, cuyo resultado puede ser "verdadero" o "falso" (o también "sí" o "no"), dependiendo del valor de los datos de la expresión condicional. En función del resultado de dicha expresión, el flujo de ejecución continúa por una u otra rama (pero nunca por las dos a la vez)

Condición múltiple. Sirve para indicar una bifurcación del flujo en varias ramas, no sólo en una. En este caso, la condición no puede ser booleana, sino entera.


Conector. Para enlazar un fragmento del diagrama de flujo con otro fragmento situado en la misma página. Se usa cuando el diagrama es muy grande y no puede dibujarse entero de arriba a abajo.

Conector. Como el anterior, pero para conectar un fragmento del diagrama con otro fragmento situado en una página diferente.

Dirección del flujo. Indica el orden de ejecución de los pasos del algoritmo.

Subrutina. Llamada a un subproceso o módulo independiente (ver apartado de "Programación Modular")
Un ejemplo: vamos a representar el algoritmo que calcula el área y el perímetro de un rectángulo mediante un diagrama de flujo. Antes, tengamos en cuenta que:
    • los valores de "base" y "altura" los introducirá el usuario del programa a través del teclado; así, el programa servirá para cualquier rectángulo
    • después se realizarán los cálculos necesarios
    • los resultados, "área" y "perímetro", deben mostrarse en un dispositivo de salida (por defecto, la pantalla) para que el usuario del programa vea cuál es la solución
Esta estructura en 3 pasos es muy típica de todos los algoritmos: primero hay una entrada de datos, luego se hacen cálculos con esos datos, y por último se sacan los resultados.
El diagrama de flujo será más o menos así:

Pseudocódigo
El pseudocódigo es un lenguaje de descripción de algoritmos. El paso desde el pseudocódigo hasta el lenguaje de programación real (por ejemplo, C), es relativamente fácil. Además, la descripción de algoritmos en pseudocódigo ocupa mucho menos espacio que su equivalente con un diagrama de flujo, por lo que lo preferiremos a la hora de diseñar algoritmos complejos.
El pseudocódigo es bastante parecido a la mayoría de los lenguajes de programación reales, pero no tiene unas reglas tan estrictas, por lo que el programador puede trabajar en la estructura del algoritmo sin preocuparse de las limitaciones del lenguaje final que, como veremos al estudiar C, son muchas y variopintas.
El pseudocódigo utiliza ciertas palabras reservadas para representar las acciones del programa. Estas palabras originalmente están en inglés (y se parecen mucho a las que luego emplean los lenguajes de programación), pero por suerte para nosotros su traducción española está muy extendida entre la comunidad hispanohablante.
Lista de instrucciones del pseudocódigo
Las instrucciones del pseudocódigo son relativamente pocas, pero, como iremos aprendiendo a lo largo del libro, con un conjunto bastante reducido de instrucciones, correctamente combinadas, podemos construir programas muy complejos. 
A continuación presentamos una tabla-resumen con todas las palabras reservadas del pseudocódigo, y en los siguientes apartados iremos viéndolas una a una.
Instrucción
Significado
algoritmo nombre
Marca el comienzo de un algoritmo y le adjudica un nombre
inicio
Marca el comienzo de un bloque de instrucciones
fin
Marca el final de un bloque de instrucciones
variables
  nombre_var es tipo_de_datos
Declaración de variables. Indica el identificador y el tipo de las variables que se van a usar en el algoritmo
constantes
  nombre_const = expresión
Declaración de constantes. La expresión se evalúa y su resultado se asigna a la constante. Este valor no puede modificarse a lo largo del programa.
leer (variable)
Entrada de datos. El programa lee un dato desde un dispositivo de entrada (si no se indica otra cosa, el teclado), asignando ese dato a la variable
escribir (variable)
Salida de datos. Sirve para que el programa escriba un dato en un dispositivo de salida (si no se indica otra cosa, la pantalla).
variable = expresión
Asignación. La expresión se evalúa y su resultado es asignado a la variable
si (condición) entonces 
inicio
  acciones-1
fin
si_no
inicio
  acciones-2
fin
Instrucción condicional doble. El ordenador evaluará la condición, que debe ser una expresión lógica. Si es verdadera, realiza las acciones-1, y, si es falsa, las acciones-2. 
Instrucción condicional simple. Es igual pero carece de la rama "si_no", de modo que, si la expresión de falsa, no se realiza ninguna acción y la ejecución continúa por la siguiente instrucción
según (expresión) hacer
inicio
  valor1: acciones-1
  valor2: acciones-2
  ...
  valor3: acciones-N
  si_no: acciones-si_no
fin
Instrucción condicional múltiple. Se utiliza cuando hay más de dos condiciones posibles (verdadero o falso) . Se evalúa la expresión, que suele ser de tipo entero, y se busca un valor en la lista valor1, valor2,... valorN que coincida con ella, realizándose las acciones asociadas al valor coincidente.
Si ningún valor de la lista coincide con la expresión del "según", se realizan las acciones de la parte "si_no".
mientras (condición) hacer
inicio
   acciones
fin
Bucle mientras. Las acciones se repiten en tanto la condición, que debe ser una expresión lógica, sea verdadera. La condición se evalúa antes de entrar al bloque de acciones, de modo que pueden no ejecutarse ninguna vez.
repetir
inicio
   acciones
fin
mientras que (condición)
Bucle repetir. Las acciones se repiten en tanto que la condición, que debe ser una expresión lógica, sea verdadera. Se parece mucho al anterior, pero la condición se evalúa al final del bucle, por lo que éste se ejecuta, como mínimo, una vez.
para variable desde expr-ini hasta expr-fin hacer
inicio
  acciones
fin
Bucle para. Se evalúa la expresión expr-ini, que debe ser de tipo entero, y se asigna ese valor a la variable. Dicha variable se incrementa en una unidad en cada repetición de las acciones. Las acciones se repiten hasta que la variable alcanza el valor expr-fin.

Las instrucciones básicas del pseudocódigo
Hay varias instrucciones de pseudocódigo que son muy simples, así que las vamos a explicar ahora mismo, junto con un ejemplo para ir acostumbrándonos al aspecto de los algoritmos:
    • algoritmo: sirve para ponerle un nombre significativo al algoritmo
    • inicio: marca el principio de un proceso, de un módulo o, en general, de un conjunto de instrucciones
    • fin: marca el fin de un proceso, módulo o conjunto de instrucciones. "Inicio" y "fin" siempre van por parejas, es decir, cuando aparezca un "Inicio", debe existir un "fin" en algún sitio más abajo. Y al revés: todo "fin" se corresponde con algún "Inicio" que aparecerá más arriba.
    • = (asignación): se utiliza para asociar un valor a una variable, como vimos en el apartado anterior.
    • leer: sirve para leer un dato de un dispositivo de entrada (típicamente, el teclado)
    • escribir: sirve para enviar un dato a un dispositivo de salida (si no se indica otra cosa, la pantalla)
Ejemplo: Volvemos al algoritmo del área y el perímetro de un rectángulo:
algoritmo rectángulo
inicio
  leer (base)
  leer (altura)
  área = base * altura
  perímetro = 2 * base + 2 * altura
  escribir (área)
  escribir (perímetro)
fin
Recuerda que los programas se ejecutan de arriba a abajo, una instrucción cada vez.
Cuando este programa se haya introducido en un ordenador y le pidamos que lo ejecute, la máquina irá mirando las instrucciones en el orden en que el programador las introdujo y las irá ejecutando. Veamos, instrucción por instrucción, qué acciones provocan en el ordenador:
    • algoritmo rectángulo: simplemente, le pone título al algoritmo y marca su principio (esta instrucción no hace nada "útil")
    • Inicio: marca el comienzo de las instrucciones (por lo tanto, ni esta instrucción ni la anterior realizan ninguna tarea: sólo son marcas)
    • leer(base): el ordenador se queda a la espera de que el usuario del programa introduzca algún dato a través del teclado. Cuando el usuario lo hace, ese dato queda almacenado en la variable "base". Supongamos que el usuario teclea un 7: será como haber hecho la asignación base = 7.
    • leer(altura): vuelve a ocurrir lo mismo, pero ahora el dato tecleado se guarda en la variable "altura". Supongamos que se teclea un 2. Por lo tanto, altura = 2.
    • área = base * altura: según vimos en el apartado anterior, se evalúa la expresión situada a la derecha del símbolo "=". El resultado de la misma será 7 * 2, es decir, 14. Ese valor se asigna a la variable situada a la izquierda del "=". Por lo tanto, área = 14.
    • perímetro = 2 * base + 2 * altura: en esta ocasión, la evaluación de la expresión da como resultado 18, que se asigna a la variable perímetro, o sea, perímetro = 18.
    • escribir(área): el ordenador muestra en la pantalla el valor de la variable área, que es 14.
    • escribir(perímetro): el ordenador muestra en la pantalla el valor de la variable perímetro, es decir, 18.
    • Fin: marca el punto final del algoritmo
Podemos concluir que el algoritmo presentado resuelve el problema de calcular el área y el perímetro de un rectángulo y posee las tres cualidades básicas de todo algoritmo: precisión, definición y finitud.
Declaración de variables y constantes
Como regla general, diremos que todas las variables deben ser declaradas ANTES de usarse por primera vez. Recuerda que la declaración se usa para comunicar al ordenador el tipo y el identificador de cada variable.
La sintaxis de estas declaraciones es como sigue:
variables
   nombre_de_variable  es  tipo_de_datos
Ejemplo: Si te fijas en el ejemplo anterior, no hemos declarado ninguna de las variables del algoritmo y, por lo tanto, éste no es del todo correcto. Vamos a completarlo:
algoritmo rectángulo
variables
  base es real
  altura es real
  área es real
  perímetro es real
inicio
  leer (base)
  leer (altura)
  área = base * altura
  perímetro = 2 * base + 2 * altura
  escribir (área)
  escribir (perímetro)
fin
Fíjate que hemos definido las variables antes del inicio de las instrucciones del algoritmo.
A veces, también es útil declarar ciertas constantes para usar valores que no van a cambiar en todo el transcurso del programa. Las constantes se deben declarar también antes del inicio de las instrucciones del programa. 
Ejemplo de declaración de constantes:
algoritmo ejemplo
constantes
  pi = 3.141592
  g = 9.8
  txt = "En un lugar de La Mancha"
inicio
  ...instrucciones...
fin

### 3.1.2. Orientándose en la jungla de los lenguajes de programación 

El ordenador, como es sabido, solo puede manejar ceros y unos, es decir, código o lenguaje binario. Los seres humanos, por el contrario, utilizamos un lenguaje mucho más complejo, con montones de símbolos y reglas sintácticas y semánticas, que denominaremos lenguaje natural.
Entre estos dos extremos (lenguaje binario y lenguaje natural) se encuentran los lenguajes de programación. Tienen cierto parecido con el lenguaje natural, pero son mucho más reducidos y estrictos en su sintaxis y semántica, para acercarse a las limitaciones del lenguaje binario.
Hay lenguajes de programación muy próximos al lenguaje binario: a éstos los llamamos lenguajes de bajo nivel de abstracción. Y los hay más próximos al lenguaje natural: son los lenguajes de alto nivel de abstracción.
Lenguajes de bajo nivel 
Son los lenguajes más cercanos a la máquina. Los programas directamente escritos en código binario se dice que están en lenguaje máquina que, por lo tanto, es el lenguaje de más bajo nivel que existe.
Las instrucciones del lenguaje máquina realizan tareas muy sencillas, como, por ejemplo, sumar dos números, detectar qué tecla se ha pulsado en el teclado o escribir algo en la pantalla del ordenador. Cuando se combinan adecuadamente muchas de estas instrucciones sencillas se obtiene un programa de ordenador que puede realizar tareas muy complejas. 
A pesar de la simplicidad de las instrucciones del lenguaje máquina, la forma de escribirlas es muy complicada, ya que hay que hacerlo en binario. En los primeros años de la informática los ordenadores se programaban directamente en lenguaje máquina, lo cual convertía la tarea de programar en una verdadera pesadilla. Por ejemplo, una instrucción para sumar dos números en lenguaje máquina puede tener este aspecto:
110100100101110010100010001001111010010110110
Cuando los ordenadores fueron haciéndose más potentes, pronto se vio que con el lenguaje máquina no se podrían crear programas que aprovechasen esa potencia por la sencilla razón de que era demasiado difícil programar así: no se podía hacer nada demasiado complicado porque el cerebro humano no está “diseñado” para pensar en binario. 
Surgió entonces la idea de utilizar el propio ordenador como traductor: ¿por qué no escribir una instrucción como la anterior, que suma dos números, de una forma más parecida al lenguaje humano y que luego un pequeño programa de ordenador se encargue de traducir esa instrucción a su correspondiente ristra de ceros y unos? Así apareció el lenguaje ensamblador, cuyas instrucciones son equivalentes a las del lenguaje máquina, pero se escriben con palabras similares a las del lenguaje humano. Por ejemplo, para sumar dos números, la instrucción en ensamblador puede ser algo como:
ADD  D1, D2
Los lenguajes de bajo nivel se caracterizan por ser dependientes del hardware de la máquina. Es decir: un programa escrito en lenguaje máquina o en ensamblador para un procesador con arquitectura x86 no funcionará, por ejemplo, en un smartphone con arquitectura ARM, a menos que sea modificado sustancialmente. Incluso puede tener serios problemas para funcionar en máquinas de la misma familia pero con el resto del hardware diferente, o con un sistema operativo distinto.
Lenguajes de alto nivel 
Siguiendo el razonamiento anterior (utilizar el propio ordenador como traductor), en los años sesenta se empezaron a desarrollar lenguajes cada vez más complejos, en los que cada instrucción ya no se correspondía exactamente con una instrucción del lenguaje máquina, sino con varias. Estos son los lenguajes de alto nivel o, simplemente, L.A.N. (no confundir con "red de área local")
Lógicamente, la traducción desde un lenguaje de alto nivel a lenguaje máquina es mucho más compleja que desde lenguaje ensamblador, por lo que los traductores se han hecho cada vez más complicados. 
Una característica muy importante de los lenguajes de alto nivel es que son independientes del hardware, lo que implica que los programas desarrollados con estos lenguajes pueden ser ejecutados en ordenadores con hardware totalmente distinto. A esto se le llama portabilidad. 
Los programas encargados de traducir el código de alto nivel a código máquina se llaman compiladores e intérpretes. Son programas muy complejos que generan el código binario equivalente al código de alto nivel para una máquina concreta. Por lo tanto, el programa de alto nivel, que es portable de un hardware a otro, debe ser traducido a código máquina en cada tipo de máquina en la que se pretenda ejecutar. 
Los ejemplos de lenguajes de alto nivel son innumerables, y la lista incluye casi todos de los que has oído hablar alguna vez: Basic, Cobol, Fortran, Ada, C, PHP, Python, Java, Perl, etc.
Comparación entre los lenguajes de alto y bajo nivel
LENGUAJES DE BAJO NIVEL
LENGUAJES DE ALTO NIVEL
Ventajas
Inconvenientes
Son comprensibles directamente por la máquina (aunque el ensamblador necesita una pequeña traducción)
Necesitan ser traducidos por medio de complicados programas (compiladores e intérpretes)
Los programas se ejecutan muy rápidamente (si están bien escritos, claro)
La traducción automática del código de alto nivel al código máquina siempre genera programas menos eficientes que si se escribieran directamente en binario
Ocupan menos espacio en memoria
Ocupan más espacio en memoria
Permiten controlar directamente el hardware, por lo que son apropiados para la programación de sistemas
En general, solo pueden acceder al hardware utilizando al sistema operativo como intermediario. Pero, entonces, ¿cómo programar el sistema operativo, que necesita controlar directamente el hardware?
Inconvenientes
Ventajas
Son completamente dependientes del hardware. Un programa escrito para determinado tipo de máquina no funcionará en un ordenador con diferente arquitectura.
Son portables, es decir, independientes del hardware. Un programa escrito en una máquina puede funcionar en otra con hardware distinto, siempre que se vuelva a traducir a binario en la máquina nueva.
Incluso los programas más sencillos son largos y farragosos
Los programas son más sencillos, ya que una sola instrucción puede equivaler a varias instrucciones binarias.
Los programas son difíciles de escribir, depurar y mantener
Los programas son más fáciles de escribir, depurar y mantener
Es imposible resolver problemas muy complejos
Es posible, aunque difícil, enfrentarse a problemas muy complejos

Enfrentando las ventajas e inconvenientes de unos y otros, se concluye que, en general, es preferible usar lenguajes de alto nivel para el desarrollo de aplicaciones, reservando los de bajo nivel para casos muy concretos en los que la velocidad de ejecución o el control del hardware sean vitales. Por ejemplo, los sistemas operativos más conocidos, como Windows, MacOS o Linux, están programados casi en su totalidad con lenguajes de alto nivel (generalmente C o C++), reservando un pequeño porcentaje del código a rutinas en ensamblador.
También hay que destacar que no todos los lenguajes de alto nivel son iguales. Los hay de "más alto nivel" que otros. C tiene sin duda menor nivel de abstracción que, por ejemplo, Visual Basic; pero, por eso mismo, los programas en C son más rápidos y eficientes que los escritos en Visual Basic, aunque también pueden llegar a ser más difíciles de escribir y depurar.
Categorías dentro de los lenguajes de alto nivel
Para terminar con esta vista preliminar sobre el mundo de los lenguajes de programación, mencionaremos que los lenguajes de alto nivel se suelen subdividir en categorías tales como: 
    • Lenguajes de tercera generación (o imperativos), en los que el programador escribe una secuencia de instrucciones que el ordenador debe ejecutar en un orden preestablecido. Son los lenguajes que nosotros vamos a manejar. Todos los lenguajes "clásicos" pertenecen a esta categoría: C, Basic, Cobol, Fortran, etc.
    • Lenguajes de cuarta generación (o 4GL), dirigidos a facilitar la creación de interfaces con el usuario y con otras aplicaciones, como las bases de datos. Un ejemplo de estos lenguajes es SQL.
    • Lenguajes orientados a objetos, que son una evolucuión de los lenguajes de tercera generación y que permiten construir con mayor facilidad y robustez programas modulares complejos. Ejemplos de lenguajes orientados a objetos son C++, Java, Python, PHP o Ruby. Algunos de ellos son multiparadigma, es decir, permiten programar con orientación a objetos pero también permiten hacer programación estructurada clásica, sin objetos.
    • Lenguajes declarativos y funcionales, propios de la inteligencia artificial, como Prolog o Lisp.
    • Otos tipos más específicos: lenguajes concurrentes, paralelos, distribuidos, etc.
En general, podemos decir que un programador acostumbrado a trabajar con un lenguaje de tercera generación puede aprender con poco esfuerzo cualquier otro lenguaje de tercera generación, y, con algo más de trabajo, un lenguaje orientado a objetos. Sin embargo, el "salto" a otros tipos de lenguajes, como los declarativos, cuesta más porque la raíz misma de estos lenguajes es diferente.

 1.2  Ensambladores, compiladores e intérpretes
Cuando programamos en un lenguaje distinto del lenguaje máquina, nuestro código debe ser traducido a binario para que el ordenador pueda entenderlo y ejecutarlo. Existe un programa específico encargado de hacer esa traducción y que, dependiendo del lenguaje en el que hayamos escrito nuestro programa, puede ser un ensamblador, un compilador o un intérprete.
Ensambladores
Se llaman ensambladores los programas encargados de traducir los programas escritos en ensamblador a código binario.
Fíjate que tanto el programa traductor como el lenguaje se llaman del mismo modo: ensamblador.
Como el lenguaje ensamblador es muy próximo al binario, estos traductores son programas relativamente sencillos.

Compiladores
El compilador es un programa que traduce el código de alto nivel a código binario. Es, por tanto, parecido al ensamblador, pero mucho más complejo, ya que las diferencias entre los lenguajes de alto nivel y el código binario son muy grandes.
El programa escrito en lenguaje de alto nivel se denomina programa fuente o código fuente. El programa traducido a código binario se llama programa objeto o código objeto. Por lo tanto, el compilador se encarga de convertir el programa fuente en un programa objeto.
Una vez que se ha obtenido el programa objeto ya no es necesario volver a realizar la traducción (o compilación), a menos que se haga alguna modificación en el programa fuente, en cuyo caso habría que volver a compilarlo.
El programa objeto, una vez generado, puede ejecutarse en la máquina en la que fue compilado, o en otra de similares características (procesador, sistema operativo, etc.). Cuando se usa programación modular, puede ser necesario un proceso previo de enlace de los diferentes módulos, pero de esto ya hablaremos más adelante.

Intérpretes
El intérprete es un programa que traduce el código de alto nivel a código binario pero, a diferencia del compilador, lo hace en tiempo de ejecución. Es decir, no se hace un proceso previo de traducción de todo el programa fuente a binario, sino que se va traduciendo y ejecutando instrucción por instrucción.

Compiladores frente a intérpretes
El intérprete es notablemente más lento que el compilador, ya que realiza la traducción al mismo tiempo que la ejecución. Además, esa traducción se lleva a cabo siempre que se ejecuta el programa, mientras que el compilador sólo la hace una vez. Por estos motivos, un mismo programa interpretado y compilado se ejecuta mucho más despacio en el primer caso.
La ventaja de los intérpretes es que hacen que los programas sean más portables. Así, un programa compilado en una máquina PC bajo Windows no funcionará en un Macintosh, o en un PC bajo Linux, a menos que se vuelva a compilar el programa fuente en el nuevo sistema. En cambio, un programa interpretado funcionará en todas las plataformas, siempre que dispongamos del intérprete en cada una de ellas.
JavaScript es un ejemplo de lenguaje interpretado. Esto permite que los programas JavaScript (llamados comúnmente scripts) puedan funcionar en cualquier máquina que disponga de un navegador de Internet capaz de interpretarlos. En cambio, C/C++ es un lenguaje compilado, lo que hace que los programas desarrollados con estos lenguajes se ejecuten más rápido que sus equivalentes en JavaScript, aunque obliga a volver a compilarlos si se desea ejecutarlos en una máquina con diferente hardware o diferente sistema operativo.
Por último, hay ciertos lenguajes que pueden ejecutarse de forma interpretada o de forma compilada. No es el caso de C. El lenguaje C está orientado a obtener la velocidad de ejecución más alta posible, y por eso siempre se compila. Pero ya es hora de empezar a hablar del lenguaje C, ¿no es así?
Vamos a ello.

### 3.1.3. Tipos de lenguaje

En los comienzos de la programación informática, se  utilizaban lenguajes máquina muy básicos y limitados como el sistema binario (uso de los números 0 y 1 en distintas combinaciones); más tarde comenzaron a surgir lenguajes  que hacían uso de códigos de palabras, y luego, conjuntos de algoritmos mucho más complejos que se denominaron lenguajes de alto nivel.

Los lenguajes de programación más conocidos y usados:

        ◦ Java
        ◦ C, C++ y C#
        ◦ Scratch
        ◦ HTML / XML
        ◦ Python
        ◦ Visual Basic .NET
        ◦ PHP
        ◦ Java
        ◦ JavaScript
Cada uno de estos lenguajes tiene un grado de complejidad diferente y, por lo tanto, algunos serán más fáciles de aprender que otros.
Como aprender a programar desde cero es una tarea compleja, en esta unidad comenzaremos acercarnos a la programación por bloques.

Este tipo de programación permite una presentación visual del paradigma y metodología de la programación informática permitiendo centrarse en la lógica de la programación dejando a un lado la sintaxis propia de los lenguajes de programación (puntos y comas, paréntesis, etc).

	
Universidades líderes en tecnología como Berkeley o el MIT, enseñan este tipo de programación por bloques en sus primeros cursos.

## 3.2. Aprendiendo a programar con pseudocódigo

Cuando se trabaja en programación, antes de escribir nuestro programa, primero se aconseja escribirlo en pseudocódigo.

El pseudocódigo es una forma de escribir los pasos que va a realizar un programa de la forma más cercana al lenguaje de programación que vamos a utilizar posteriormente. Es como un falso lenguaje, pero en nuestro idioma.

Este pseudocódigo vale para pasarlo posteriormente a cualquier lenguaje de programación de forma sencilla, no importa el que tengas que usar.































Ejemplo de programa escrito en pseudocódigo



Ahora veamos varias explicaciones de pseudocódigo, pero sobre todo ejemplos de pseudocódigo para entender que son las variables y las estructuras de control como por ejemplo la condicional IF o el bucle FOR. Nosotros aquí no lo vamos a explicar.

Por ejemplo si queremos escribir algo en pantalla, en pseudocódigo podríamos poner:

Escribir "Hola" , Escribir 20 o Escribir Variable

OJO escribir 20 y escribir "20" son dos cosas diferentes. El texto siempre se pone entre comillas, los números NO. Entonces escribir 20, es mostrar en pantalla el número 20 y escribir "20" es mostrar en pantalla 20. Puede parecer lo mismo, pero no lo es, en una 20 es un texto y en otro un número.

Para especificar el principio y el fin del programa pondremos:

Inicio



Fin


Por ejemplo:

Inicio



Fin


Las 3 palabras más comunes que se usan en pseudocódigo son:

Escribir--> Escribe en pantalla del ordenador el texto que pongamos entre paréntesis o también puede escribir en pantalla el valor de una variable.


Esta instrucción en casi todos los lenguajes de programación reales suele escribirse con la palabra write o document.write('Hola').


Leer Edad--> nos lee desde lo que el usuario marque desde el teclado y guarda el valor, por ejemplo, dentro de una variable, en este caso la variable Edad.

Por ejemplo:

Inicio

Escribir: "¿Cual es tu edad?

Leer Edad

Escribir "Tu edad es:" + Edad
Fin


¿Qué haría? Pues muy sencillo, primero nos mostraría un mensaje en pantalla preguntándonos la edad, luego escribiríamos la edad y el valor introducido lo recogería la variable Edad (imagina que introducimos 18). Por último, mostraría en pantalla la frase: Tu edad es 18. ¿Fácil no?

Realizar operaciones matemáticas dentro de nuestros programas será básico. Las más conocidas:



Y usaremos a menudo los comparadores matemáticos:



A veces, en algunos lenguajes, es necesario declarar el tipo de las variables que vamos a utilizar dentro del programa. No es nada más que decir de qué tipo son, numéricas, de texto booleanas, etc.

Se hace siempre al principio del programa y de la siguiente forma en pseudo-código:

numericas: nombreVariable; para las variables que sean de números o
texto:
nombreVariable; para las variables que contienen textos o cadenas de texto (string= cadena de texto)


Todo esto lo veremos mejor con los siguientes ejemplos:

    1. Pseudocódigo para un programa que nos sume dos números introducidos por el teclado:

Inicio

Escribir "Introduce el primer número";

Lee numero1;

Escribir "Introduce el segundo número";
Leer numero2;

resultado= numero1 + numero2;

Escribir resultado;




Nota: Cuando queremos escribir en pantalla una variable, como en este caso la variable resultado, no se pone entre

comillas.


    2. Pseudocódigo para un programa que nos diga la tabla de multiplicar del número que le digamos (introducido por el teclado).

Programa: TablaMultiplicar

numericas: t, num , total;



Fin

    3. Escribir un Pseudocódigo de un programa que permita leer la edad y peso de una persona y posteriormente imprimirla.

Inicio

VariablesNumericas: edad, peso.

Imprimir "Escribir los datos (Edad, Peso):";

Leer Edad, Leer Peso;

Escribir "Tu peso es: ", peso, " y tu edad es: ", edad.;

Fin.

Te has fijado que para imprimir algo en lugar de mostrarlo en la pantalla,la palabra es "imprimir", así de sencillo.

Además podemos mezclar en una frase texto fijo con variables. Esto se puede hacer con comas, como lo ves en el ejemplo anterior o poniendo el signo + entre el texto y las

variables, como vimos anteriormente. En el ejemplo anterior podríamos ser:

Escribir "Tu peso es: " + peso + " y tu edad es: " + edad.; Sería lo mismo.

    4. Escribir Pseudocódigo que calcule el área de un círculo.

Inicio

 Aquí definimos una constante por


VariablesNumericas: radio, area;









Fin



    5. Elaborar un algoritmo que obtenga e imprima el valor de Y a partir de la ecuación: Y= 3*X + 2 + 7X – 15, introduciendo el valor que queramos de X.

I


    6. Pseudocódigo para introducir un número por teclado y que nos diga si es positivo o negativo



FINPROGRAMA

Aquí hemos utilizado la estructura SI...(se cumple la condición)...Hacer (Esto). Esto es la condicional IF (en inglés). También usamos SINO para hacer algo si no se cumple la condición.



Existe un programa muy útil para escribir pseudocódigo en el ordenador Llamado PSeint que resulta genial para los primeros pasos en programación (complementado con un editor de diagramas de Flujo que veremos lo que es en el apartado siguiente). El programa es gratuito y está disponible para Linux, Mac OS y Windows.

3. DIAGRAMAS DE FLUJO
El diagrama de flujo es una de las herramientas más poderosas y sin embargo poco utilizadas a veces. Ayuda a solucionar un problema de forma estructurada. Nos va a permitir describir gráficamente un proceso, de manera que podemos comprobar de un golpe de vista si hemos cubierto todos los caminos que ese proceso puede tomar.


Un buen diseño de diagrama de flujo tendrá como resultado una buena automatización de un programa (más claro y eficiente).









Si usamos esta herramienta, nos ayudará fácilmente a la hora de desarrollar un programa con lógica y de forma natural ANTES de ponernos a programar.

De hecho, lo mejor es empezar a utilizar el diagrama de flujo representando rutinas de la vida diaria para entender mejor la lógica computacional.



Una vez descrito el diagrama de flujo es más fácil transformar el algoritmo programando por cualquiera de los lenguajes de programación que vayamos a usar.
Cada símbolo representa una operación específica y se conectan entre ellos mediante flechas que indican la secuencia de la operación.


