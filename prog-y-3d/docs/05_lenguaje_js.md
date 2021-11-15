---
layout: page
title: 5. Lenguaje Javascript
permalink: /lenguaje-js/
nav_order: 5
has_children: true
parent: Introd. a la prog. y al diseño 3D
---

# 5. El lenguaje Javascript
{: .no_toc }

<p style='color:red'><strong>ATENCIÓN: este capítulo aún está en fase de redacción y su contenido es provisional. ¡No lo leas todavía!</strong></p>

Contenidos: Tipos de lenguajes según su nivel de abstracción y su modo de traducción. Historia de los lenguajes de programación. El lenguaje Javascript

- TOC
{:toc}

El ordenador, como ya sabes, solo puede manejar ceros y unos, es decir, código o **lenguaje binario**. Los seres humanos, por el contrario, utilizamos un lenguaje mucho más complejo, con montones de símbolos y reglas sintácticas y semánticas, que denominamos **lenguaje natural** (aunque de "natural" tiene poco).

Entre estos dos extremos (lenguaje binario y lenguaje natural) se encuentran los **lenguajes de programación**. Tienen cierto parecido con el lenguaje natural, pero son mucho más reducidos y estrictos en su sintaxis y semántica, para acercarse a las limitaciones del lenguaje binario.

En este capítulo vamos a aprender a escribir algoritmos con un lenguaje de alto nivel llamado **Javascript**. Se trata de un lenguaje que ha alcanzado una popularidad enorme gracias a que se encuentra incrustado en todas las páginas web que visitas a diario. Javascript es la piedra angular de cualquier web, pero también puede usarse como un lenguaje de programación convencional para escribir algoritmos de forma rápida, que es lo que vamos a hacer en este tema.

Lenguajes de programación hay muchos, así que también hablaremos de otros lenguajes y conoceremos los tipos y características de algunos de ellos.

## 5.1. Orientándose en la jungla de los lenguajes de programación

Los lenguajes de programación constituyen un ecosistema muy extenso y en constante evolución. Para orientarse un poco en esa jungla, nada mejor que clasificar los lenguajes igual que los biólogos clasifican a las criaturas vivas.

### 5.1.1. Tipos de lenguaje según el nivel de abstracción: alto y bajo nivel

Hay lenguajes de programación muy próximos al lenguaje binario: a éstos los llamamos **lenguajes de bajo nivel** de abstracción. Y los hay más próximos al lenguaje natural: son los **lenguajes de alto nivel** de abstracción.

#### Lenguajes de bajo nivel 

Son los lenguajes más cercanos a la máquina. Los programas directamente escritos en código binario se dice que están en **lenguaje máquina** que, por lo tanto, es el lenguaje de más bajo nivel que existe.

Las instrucciones del lenguaje máquina realizan tareas muy sencillas, como, por ejemplo, sumar dos números, detectar qué tecla se ha pulsado en el teclado o escribir algo en la pantalla del ordenador. Cuando se combinan adecuadamente muchas de estas instrucciones sencillas se obtiene un programa de ordenador que puede realizar tareas muy complejas.

Por ejemplo, este puede ser el aspecto de una instrucción en lenguaje máquina para sumar dos números:

```
0001 000100000101 110100110101
```

Incomprensible, ¿verdad?

A pesar de la simplicidad de las instrucciones del lenguaje máquina, la forma de escribirlas es muy complicada, ya que hay que hacerlo en binario. En los primeros años de la informática los ordenadores se programaban directamente en lenguaje máquina, lo cual convertía la tarea de programar en una verdadera pesadilla. Hoy en día nadie lo hace.

Cuando los ordenadores fueron haciéndose más potentes, surgió la idea de utilizar el propio ordenador como **traductor**: ¿por qué no escribir instrucciones en un lenguaje más parecido al natural y que un programa de ordenador se encargue de traducir esa instrucción a su correspondiente instrucción en lenguaje máquina?

Así apareció el **lenguaje ensamblador**, cuyas instrucciones son equivalentes a las del lenguaje máquina, pero se escriben con palabras similares a las del lenguaje humano. Por ejemplo, para sumar dos números, la instrucción en ensamblador puede tener un aspecto como este:

```
ADD D1 D2
```

#### Lenguajes de alto nivel 

Siguiendo el razonamiento anterior (utilizar el propio ordenador como traductor), en la década de 1960 y, sobre todo, de 1970, se empezaron a desarrollar lenguajes cada vez más complejos, en los que cada instrucción ya no se correspondía exactamente con una instrucción del lenguaje máquina, sino con varias. Estos son los **lenguajes de alto nivel**.

Lógicamente, la traducción desde un lenguaje de alto nivel a lenguaje máquina es mucho más compleja que desde lenguaje ensamblador, por lo que *los traductores se han hecho cada vez más complicados*. 

Una característica muy importante de los lenguajes de alto nivel es que **son independientes del hardware**, lo que implica que los programas desarrollados con estos lenguajes pueden ser ejecutados en ordenadores con hardware totalmente distinto. A esto se le llama **portabilidad**. 

Los programas encargados de traducir el código de alto nivel a código máquina se llaman **compiladores** e **intérpretes**. Son programas muy complejos que generan el código binario equivalente al código de alto nivel para una máquina concreta. Por lo tanto, el programa de alto nivel, que es portable de un hardware a otro, debe ser traducido a código máquina en cada tipo de máquina en la que se pretenda ejecutar. 

Los ejemplos de lenguajes de alto nivel son innumerables, y la lista incluye casi todos de los que has oído hablar alguna vez: Basic, Cobol, Fortran, Ada, C/C++, PHP, Python, Java, Perl, Ruby, Javascript, etc.

#### Ventajas e inconvenientes de los lenguajes de alto y bajo nivel

**LENGUAJES DE BAJO NIVEL**|**LENGUAJES DE ALTO NIVEL**
-|-
**Ventajas**|**Inconvenientes**
Son comprensibles directamente por la máquina (aunque el ensamblador necesita una pequeña traducción)|Necesitan ser traducidos por medio de complicados programas (compiladores e intérpretes)
Los programas se ejecutan muy rápidamente (si están bien escritos, claro)|La traducción automática del código de alto nivel al código máquina siempre genera programas menos eficientes que si se escribieran directamente en binario
Ocupan menos espacio en memoria|Ocupan más espacio en memoria
Permiten controlar directamente el hardware, por lo que son apropiados para la programación de sistemas|En general, solo pueden acceder al hardware utilizando al sistema operativo como intermediario. Pero, entonces, ¿cómo programar el sistema operativo, que necesita controlar directamente el hardware?
**Inconvenientes**|**Ventajas**
Son completamente dependientes del hardware. Un programa escrito para determinado tipo de máquina no funcionará en un ordenador con diferente arquitectura.|Son portables, es decir, independientes del hardware. Un programa escrito en una máquina puede funcionar en otra con hardware distinto, siempre que se vuelva a traducir a binario en la máquina nueva.
Incluso los programas más sencillos son largos y farragosos|Los programas son más sencillos, ya que una sola instrucción puede equivaler a varias instrucciones binarias.
Los programas son difíciles de escribir, depurar y mantener|Los programas son más fáciles de escribir, depurar y mantener
Es imposible resolver problemas muy complejos|Es posible, aunque difícil, enfrentarse a problemas muy complejos

Si echas un vistazo a la tabla anterior comprenderás que, en general, **es preferible usar lenguajes de alto nivel** la gran mayoría de las veces, reservando los de bajo nivel para casos muy concretos, como el desarrollo de ciertas partes de los sistemas operativos.

También hay que destacar que no todos los lenguajes de alto nivel son iguales. Los hay de más alto nivel que otros. El lenguaje C, por ejemplo, tiene menor nivel de abstracción que, por ejemplo, Java. Esto hace que los programas escritos en C sean más rápidos y eficientes que los escritos en Java, aunque también pueden llegar a ser más difíciles de escribir y depurar.

### 5.1.2. Tipos de lenguaje según su generación

Los lenguajes de programación también se clasifican según la generación a la que pertenecen.

El lenguaje máquina fue el lenguaje de primera generación. Los ensambladores fueron los lenguajes de segunda generación. A partir de ahí, surgió una explosión de lenguajes diferentes que podemos clasificar como:

* **Lenguajes de tercera generación** (o **imperativos**), en los que el programador escribe una secuencia de instrucciones que el ordenador debe ejecutar en un orden preestablecido. Son los lenguajes más "clásicos": C, Basic, Cobol, Fortran, Pascal, etc.
* **Lenguajes de cuarta generación** (o **4GL**), dirigidos a facilitar la creación de interfaces con el usuario y con otras aplicaciones, como las bases de datos. Un ejemplo de estos lenguajes es SQL, universalmente utilizado para manipular bases de datos y omnipresente en muchas aplicaciones web actuales.
* **Lenguajes orientados a objetos**, que son una evolucuión de los lenguajes de tercera generación y que permiten construir con mayor facilidad y robustez programas modulares complejos. Ejemplos de lenguajes orientados a objetos son C++, C#, Java, Javascript, Python, PHP o Ruby. Algunos de ellos son multiparadigma, es decir, permiten programar con orientación a objetos pero también permiten hacer programación estructurada clásica, sin objetos.
* **Lenguajes declarativos** y **lenguajes funcionales**, propios de la inteligencia artificial, como Prolog o Lisp.
* **Otros** tipos aún más específicos: lenguajes concurrentes, paralelos, distribuidos, etc.

En general, podemos decir que un programador acostumbrado a trabajar con un lenguaje de tercera generación puede aprender con poco esfuerzo cualquier otro lenguaje de tercera generación y, con algo más de trabajo, un lenguaje orientado a objetos. Sin embargo, el "salto" a otros tipos de lenguajes, como los declarativos, cuesta más porque las fundamentos de estos lenguajes son muy diferentes.

### 5.1.3. Tipos de lenguaje según su forma de traducción 
 
Cuando programamos en un lenguaje distinto del lenguaje máquina, **nuestro código debe ser traducido a binario** para que el ordenador pueda entenderlo y ejecutarlo. Existe un programa específico encargado de hacer esa traducción y que, dependiendo del lenguaje en el que hayamos escrito nuestro programa, puede ser un *ensamblador*, un *compilador* o un *intérprete*.

#### Ensambladores
XXX
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

XXX añadir gráfica con estadísitca de uso de lenguajes en GitHub

Cada uno de estos lenguajes tiene un grado de complejidad diferente y, por lo tanto, algunos serán más fáciles de aprender que otros.
Como aprender a programar desde cero es una tarea compleja, en esta unidad comenzaremos acercarnos a la programación por bloques.

Este tipo de programación permite una presentación visual del paradigma y metodología de la programación informática permitiendo centrarse en la lógica de la programación dejando a un lado la sintaxis propia de los lenguajes de programación (puntos y comas, paréntesis, etc).

	
Universidades líderes en tecnología como Berkeley o el MIT, enseñan este tipo de programación por bloques en sus primeros cursos.


