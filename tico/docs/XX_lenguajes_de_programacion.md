---
layout: page
title: 6. Los lenguajes de programación
permalink: /lenguajes-de-programacion/
parent: XXXXTecnologías de la Información y la Comunicación 2º BACHILLERATO
nav_order: 6
has_children: false
---

# 6. Los lenguajes de programación
{: .no_toc }

- TOC
{:toc}


Los lenguajes de programación constituyen un ecosistema muy extenso y en constante evolución. Para orientarse un poco en esa jungla, nada mejor que clasificar los lenguajes igual que los biólogos clasifican a las criaturas vivas.

## 6.1. Tipos de lenguaje según el nivel de abstracción: alto y bajo nivel

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

## 6.2. Tipos de lenguaje según su generación

Los lenguajes de programación también se clasifican según la generación a la que pertenecen.

El lenguaje máquina fue el lenguaje de primera generación. Los ensambladores fueron los lenguajes de segunda generación. A partir de ahí, surgió una explosión de lenguajes diferentes que podemos clasificar como:

* **Lenguajes de tercera generación** (o **imperativos**), en los que el programador escribe una secuencia de instrucciones que el ordenador debe ejecutar en un orden preestablecido. Son los lenguajes más "clásicos": C, Basic, Cobol, Fortran, Pascal, etc.
* **Lenguajes de cuarta generación** (o **4GL**), dirigidos a facilitar la creación de interfaces con el usuario y con otras aplicaciones, como las bases de datos. Un ejemplo de estos lenguajes es SQL, universalmente utilizado para manipular bases de datos y omnipresente en muchas aplicaciones web actuales.
* **Lenguajes orientados a objetos**, que son una evolucuión de los lenguajes de tercera generación y que permiten construir con mayor facilidad y robustez programas modulares complejos. Ejemplos de lenguajes orientados a objetos son C++, C#, Java, Javascript, Python, PHP o Ruby. Algunos de ellos son multiparadigma, es decir, permiten programar con orientación a objetos pero también permiten hacer programación estructurada clásica, sin objetos.
* **Lenguajes declarativos** y **lenguajes funcionales**, propios de la inteligencia artificial, como Prolog o Lisp.
* **Otros** tipos aún más específicos: lenguajes concurrentes, paralelos, distribuidos, etc.

En general, podemos decir que un programador acostumbrado a trabajar con un lenguaje de tercera generación puede aprender con poco esfuerzo cualquier otro lenguaje de tercera generación y, con algo más de trabajo, un lenguaje orientado a objetos. Sin embargo, el "salto" a otros tipos de lenguajes, como los declarativos, cuesta más porque las fundamentos de estos lenguajes son muy diferentes.

## 6.3. Tipos de lenguaje según su forma de traducción 
 
Cuando programamos en un lenguaje distinto del lenguaje máquina, **nuestro código debe ser traducido a binario** para que el ordenador pueda entenderlo y ejecutarlo. Existe un programa específico encargado de hacer esa traducción y que, dependiendo del lenguaje en el que hayamos escrito nuestro programa, puede ser un *ensamblador*, un *compilador* o un *intérprete*.

#### Ensambladores

Se llaman **ensambladores** los programas encargados de **traducir los programas escritos en ensamblador a código binario**.

Sí, ya lo sé: se usa el mismo nombre para referirse al *lenguaje* de programación y al *traductor* de ese lenguaje a código máquina. Es un lío.

Como el lenguaje ensamblador es muy próximo al binario, estos traductores son programas relativamente sencillos.

#### Compiladores

El **compilador** es un programa que traduce el **código de alto nivel a código binario**. 

Es, por tanto, parecido al ensamblador, pero mucho más complejo, ya que las diferencias entre los lenguajes de alto nivel y el código binario son muy grandes.

El programa escrito en lenguaje de alto nivel se denomina programa fuente o **código fuente**. El programa traducido a código binario se llama programa objeto o **código objeto**. Por lo tanto, el compilador se encarga de convertir el programa fuente en un programa objeto.

Una vez que se ha obtenido el código objeto ya no es necesario volver a realizar la traducción (o compilación), a menos que se haga alguna modificación en el programa fuente, en cuyo caso habría que volver a compilarlo.

El código objeto, una vez generado, puede ejecutarse en la máquina en la que fue compilado, o en otra de similares características (procesador, sistema operativo, etc.). Cuando se usa programación modular, puede ser necesario un proceso previo de enlace de los diferentes módulos antes de poder construir el programa ejecutable.

#### Intérpretes

El **intérprete** es un programa que **traduce el código de alto nivel a código binario** pero, a diferencia del compilador, lo hace **en tiempo de ejecución**. 

Es decir, no existe un proceso previo de traducción de todo el código fuente a código binario, sino que se va traduciendo y ejecutando instrucción por instrucción.

#### Compiladores frente a intérpretes

El **intérprete** es notablemente **más lento** que el compilador, ya que realiza la traducción al mismo tiempo que la ejecución. Además, esa traducción se lleva a cabo siempre que se ejecuta el programa, mientras que el compilador sólo la hace una vez. Hay un evidente malgasto de recursos.

Sin embargo, los intérpretes tienen una gran ventaja sobre los compiladores, y es que logran que **los programas sean más portables**, es decir, que puedan ejecutarse en diferentes máquinas con diferentes sistemas operativos sin apenas cambios.

Así, un programa *compilado* en una máquina PC bajo Windows no funcionará en un Mac o en un PC bajo Linux, a menos que se vuelva a compilar el programa fuente en el nuevo sistema. En cambio, un programa *interpretado* funcionará en todas las plataformas, siempre que dispongamos del intérprete en cada una de ellas.

**C/C++ es un ejemplo de lenguaje compilado. Python es un ejemplo de lenguaje interpretado.**

Eso significa que un programa escrito, por ejemplo, con **Python**, puede funcionar en cualquier máquina que disponga de un intérperte Python, que, hoy en día, es casi cualquiera. Por eso, **cualquier programa escrito en Python puede ejecutarse prácticamente en cualquier ordenador del mundo** sin tocarle ni una coma.

En cambio, los programas desarrollados con C/C++ se ejecuten **más rápido** (¡pero mucho más rápido!) que sus equivalentes en Python. Sin embargo, **tendrás que volver a compilarlos** si deseas ejecutarlos en una máquina con diferente hardware o diferente sistema operativo.

## 6.4. Tipos de lenguaje según su tipado

Por *tipado* nos referimos a la forma en la que los lenguajes de programación usan los tipos de datos. Ya sabes: entero, carácter, lógico, etc. Es decir, las categorías a las que puede pertenecer una variable.

Pues bien, según su tipado, los lenguajes pueden ser:

* **De tipado fuerte**: los tipos de datos no pueden mezclarse. Por ejemplo, no puedes sumar un entero y un real, porque son números de distinto tipo. Y mucho menos sumar un entero con un carácter.
* **De tipado débil**: los tipos de datos pueden mezclarse y el lenguaje hace las conversiones de tipos implícitas que le parezca oportunas. Así, en estos lenguajes podrías sumar un entero con un real, o incluso un entero con un carácter. ¿Que cuál sería el resultado? Buena pregunta. Tendrás que probarlo, porque eso depende de las conversiones de tipo que haga el lenguaje.
* **De tipado estático**: los tipos de datos se asignan al escribir el código y no pueden cambiarse durante la ejecución. Esto es típico de los compiladores (aunque no de todos).
* **De tipado dinámico**: los tipos de datos pueden cambiarse alegremente durante la ejecución. Esto es típico de los intérpretes.

Las dos primeras categorías y las dos segundas no son excluyentes. Por ejemplo, pueden existir lenguajes de tipado débil y dinámico, o bien fuerte y estático. Las otras combinaciones (fuerte y dinámico, débil y estático) pueden darse pero son menos habituales. 

## 6.5. El *top ten* de los lenguajes de programación

Es difícil saber cuales son los lenguajes más populares en un determinado momento porque no existen estadísticas fiables a nivel mundial. Además, las cosas pueden cambiar mucho de un territorio a otro.

Sin embargo, ciertos sitios de internet, como **GitHub**, almacenan enormes cantidades de proyectos de software. GitHub, de hecho, es el mayor almacén de código fuente conocido, de modo que sus estadísticas nos pueden dar una idea bastante exacta de cuál es el grado de uso de cada lenguaje.

Según [Madnight](https://madnight.github.io/githut), un proyecto que recopila y publica estadísticas de uso de lenguajes en GitHub, el *top ten* de lenguajes de programación más usados en GitHub es:

Puesto|Lenguaje|Porcentaje de uso|Variación de uso en 12 meses
-|-|-|-
1|JavaScript|17.955%|-2.192%
2|Python|15.943%|+0.071%
3|Java|12.977%|+1.573%
4|Go|8.203%|-0.612%
5|TypeScript|7.212%|-0.276%
6|C++|6.683%|-0.251%
7|Ruby|6.488%|+0.303%
8|PHP|4.937%|-0.093%
9|C#|3.366%|-0.350%
10|C|2.958%|+0.068%

El porcentaje de uso indica la proporción de proyectos en GitHub que usan ese lenguaje de programación sobre el total de proyectos. La última cifra señala la variación interanual del porcentaje de uso.

Estos datos son de tercer cuatrimestre de 2021. Para obtener datos de otras fechas, puedes visitar la web [https://madnight.github.io/](https://madnight.github.io/)

Ten en cuenta de nuevo que esto no son cifras de uso absoluto de los lenguajes a nivel mundial. Solo se trata de una pista de cuál es la situación. De hecho, si consultas otras estadísticas como el [TIOBE index](https://tiobe.com/tiobe-index/), encontrarás datos diferentes.

Según estas cifras, el conjunto de proyectos que usan lenguaje C o cualquiera de sus variantes (C++ o C#) es muy significativo, sobre todo teniendo en cuenta que C es un lenguaje de la década de 1970, lo cual constituye una eternidad en informática. Que un lenguaje mantenga su vigencia durante tanto tiempo indica lo robusto y confiable que es. Seguramente seguirá con nosotros dentro de muchos años, cuando otros competidores de esta lista ya hayan caído en el olvido.
