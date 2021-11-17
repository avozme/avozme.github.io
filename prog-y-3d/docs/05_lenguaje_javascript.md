---
layout: page
title: 5. Lenguaje Javascript
permalink: /javascript/
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

El **intérprete** es notablemente **más lento** que el compilador, ya que realiza la traducción al mismo tiempo que la ejecución. 

Además, esa traducción se lleva a cabo siempre que se ejecuta el programa, mientras que el compilador sólo la hace una vez. Hay un evidente malgasto de recursos.

Sin embargo, muchos lenguajes muy populares en la actualidad, como Javascript, PHP o Python, suelen ser interpretados y no compilados. Alguna ventaja tendrá la interpretación frente a la compilación, ¿no crees?

Pues sí: la **gran ventaja de los intérpretes** es que hacen que **los programas sean más portables**. 

Así, un programa compilado en una máquina PC bajo Windows no funcionará en un Macintosh, o en un PC bajo Linux, a menos que se vuelva a compilar el programa fuente en el nuevo sistema. En cambio, un programa interpretado funcionará en todas las plataformas, siempre que dispongamos del intérprete en cada una de ellas.

**JavaScript** es un ejemplo de lenguaje interpretado tremendamente popular gracias al crecimiento de Internet. Los programas escritos con JavaScript (llamados comúnmente *scripts*) pueden funcionar en cualquier máquina que disponga de un intérperte Javascript, y resulta que todos los navegadores web tienen uno.

Por eso, cualquier programa escrito en Javascript puede ejecutarse prácticamente en cualquier ordenador del mundo sin tocarle ni una coma.

En cambio, **C/C++** es un lenguaje compilado, lo que hace que los programas desarrollados con estos lenguajes se ejecuten más rápido (¡pero mucho más rápido!) que sus equivalentes en JavaScript. Sin embargo, tendrás que volver a compilarlos si deseas ejecutarlos en una máquina con diferente hardware o diferente sistema operativo.

### 5.1.4. Tipos de lenguaje según su tipado

Por *tipado* nos referimos a la forma en la que los lenguajes de programación usan los tipos de datos. Ya sabes: entero, carácter, lógico, etc. Es decir, las categorías a las que puede pertenecer una variable.

Pues bien, según su tipado, los lenguajes pueden ser:

* **De tipado fuerte**: los tipos de datos no pueden mezclarse. Por ejemplo, no puedes sumar un entero y un real, porque son números de distinto tipo. Y mucho menos sumar un entero con un carácter.
* **De tipado débil**: los tipos de datos pueden mezclarse y el lenguaje hace las conversiones de tipos implícitas que le parezca oportunas. Así, en estos lenguajes podrías sumar un entero con un real, o incluso un entero con un carácter. ¿Que cuál sería el resultado? Buena pregunta. Tendrás que probarlo, porque eso depende de las conversiones de tipo que haga el lenguaje.
* **De tipado estático**: los tipos de datos se asignan al escribir el código y no pueden cambiarse durante la ejecución. Esto es típico de los compiladores (aunque no de todos).
* **De tipado dinámico**: los tipos de datos pueden cambiarse alegremente durante la ejecución. Esto es típico de los intérpretes.

Las dos primeras categorías y las dos segundas no son excluyentes. Por ejemplo, pueden existir lenguajes de tipado débil y dinámico, o bien fuerte y estático. Las otras combinaciones (fuerte y dinámico, débil y estático) pueden darse pero son menos habituales. 

### 5.1.5. El *top ten* de los lenguajes de programación

Es difícil saber cuales son los lenguajes más populares en un determinado momento porque no existen estadísticas fiables a nivel mundial. Además, las cosas pueden cambiar mucho de un territorio a otro.

Sin embargo, ciertos sitios de internet, como **GitHub**, almacenan enormes cantidades de proyectos de software. GitHub, de hecho, es el mayor almacén de código fuente conocido, de modo que sus estadísticas nos pueden dar una idea de cual es el grado de uso de cada lenguaje.

Pues bien, según Madnight, un proyecto que recopila y publica estadísticas de uso de lenguajes en GitHub, el *top ten* de lenguajes de programación más usados en GitHub es:

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

Estos datos son de tercer cuatrimestre de 2021. Para obtener datos actualizados, puedes visitar la web [https://madnight.github.io/](https://madnight.github.io/)

Como puede verse, Javascript continúa siendo el lenguaje preferido por la mayoría de los programadores (aunque está lejos de sus tiempos memorables, donde llegó a utilizarse en casi el 30% de los nuevos proyectos). Viejas glorias como Java, C++, PHP y C aguantan muy bien el tipo, con unos números muy estables, porque tienen una base de programadores muy fieles a sus espaldas, mientras que algunos lenguajes recientes como Go y Typescript se han hecho un hueco en el ránking de los 10 más usados.

En concreto, **Typescript** podría llegar a ser el sucesor de Javascript, puesto que es un superconjunto de este. Es decir, todo el código escrito en Javascript es también Typescript, solo que este último posee nuevas características que no existen en Javascript.

Eso significa una cosa: que **aprender a programar con Javascript es una inversión para el presente y para el futuro**.

## 5.2. Javascript

### 5.2.1.  Características básicas de Javascript

Javascript es un lenguaje interpretado de alto nivel cuyas propiedades fundamentales son:

* Es un lenguaje imperativo y estructurado. Admite orientación a objetos basada en prototipos, no en clases (puede que no entiendas lo que significa esto, pero de momento no importa).
* Su tipado es débil y dinámico.
XXX
    • Los operadores de C son más numerosos que en la mayoría de los lenguajes de programación anteriores y contemporáneos suyos.
    • Muchas de las sentencias de decisión y de bucles han servido de referencia para el diseño de todos los lenguajes creados en estos últimos años, de modo especial los populares Java y Visual Basic (no confundir Java con JavaScript: son dos lenguajes muy diferentes. Tampoco se debe confundir Visual Basic con el antiguo Basic)
    • C es un lenguaje muy eficiente, casi tanto como el ensamblador, por lo que es adecuado para desarrollar software en el que la velocidad de ejecución sea importante: sistemas operativos, sistemas en tiempo real, compiladores, software de comunicaciones, etc.
    • C es altamente portable, más que otros lenguajes de alto nivel, ya que existen compiladores para lenguaje C estándar en todas las plataformas imaginables
    • Es un lenguaje muy popular y, por lo tanto, existen multitud de librerías de funciones ya programadas que se pueden reutilizar, así como documentación abundante.
    • C es más críptico que la mayoría de los otros lenguajes de programación de alto nivel. Su naturaleza críptica proviene de la enorme cantidad de operadores y un número pequeño de palabras clave o palabras reservadas. El lenguaje C estándar (ANSI C) tiene solamente 32 palabras reservadas, un número extremadamente pequeño comparado a otros lenguajes como Visual Basic.
 2.2  Breve historia de C
En 1972, los laboratorios Bell necesitaban un nuevo sistema operativo. Hasta ese momento, la mayoría de los sistemas operativos estaban escritos en lenguaje ensamblador ya que los lenguajes de alto nivel no generaban programas lo suficientemente rápidos. Pero los programas escritos en ensamblador son difíciles de mantener y Bell quería que su nuevo sistema operativo se pudiera mantener y modificar con facilidad. Por lo tanto, se decidieron a inventar un lenguaje de alto nivel nuevo con el que programar su sistema operativo. Este lenguaje debía cumplir dos requisitos: ser tan manejable como cualquier otro lenguaje de alto nivel (para que los programas fueran fáciles de mantener) y generar un código binario tan rápido como el escrito directamente en ensamblador.
Brian Kerningham y Dennis Ritchie, dos ingenieros de laboratorios Bell, tras varios intentos (C procede de otro lenguaje llamado B, que a su vez procede de otro anterior), terminaron de diseñar el lenguaje C en un ordenador DEC PDP-11. El lenguaje C pasó a convertirse y conocerse como "un lenguaje de programación de alto-bajo nivel". Eso significa que soporta todas las construcciones de programación de cualquier lenguaje de alto nivel, incluyendo construcciones de programación estructurada, y al mismo tiempo se compila en un código eficiente que corre casi tan rápidamente como un lenguaje ensamblador.
Los laboratorios Bell terminaron de construir su sistema operativo Unix y su lenguaje de programación por excelencia, C. El tándem C – Unix ha sido la referencia fundamental en el mundo de la programación en el último medio siglo, y C se ha convertido en uno de los lenguajes de programación más populares y longevos de la historia de la informática. C creció en popularidad muy rápidamente y sigue siendo uno de los lenguajes fundamentales tanto en el mundo educativo como en el mundo profesional.
El lenguaje C como tal aparece descrito por primera vez en el libro "The C Programming Language" (Prentice-Hall, 1978), auténtica biblia de la programación escrita por Kerningham y Ritchie. Todavía se pueden encontrar ediciones recientes de ese texto, y existe incluso una edición digital oficial. El lenguaje se extendió rápidamente y surgieron diferentes implementaciones con ligeras diferencias entre sí hasta que el instituto de estándares americano (ANSI) formó un comité en 1983 para definir un estándar del lenguaje.
El primer estándar ANSI C apareció en 1990 y fue revisado en 1999. Una evolución de C fue el lenguaje C++ que, a parte de todas las características del ANSI C, incluye la posibilidad de orientación a objetos, una técnica de programación ligeramente diferente de la programación estructurada. En el año 2000, Microsoft patentó el lenguaje C#, otra evolución de C++ orientada al desarrollo de aplicaciones para la plataforma .NET de esta compañía.
En la actualidad son muchos los fabricantes de compiladores C, y todos cumplen con la norma ANSI C, por lo que el código escrito para un compilador es altamente portable a otros. Algunos de ellos son Visual C++ (o C#) de Microsoft, Embarcadero C++ Builder (antiguo Borland C++), el Intel C++ Compiler y, por supuesto, el legendario compilador gcc con licencia GNU en sus diferentes versiones.
 2.3  Un lenguaje para programadores
H. Schildt, en su "Manual de referencia de Turbo C/C++" editado por McGraw-Hill, se hace una interesante reflexión que al principio puede resultar sorprendente: "pero... ¿no son todos los lenguajes para programadores? La respuesta es sencillamente: no."
Analizando un poco más las razones del autor para tan rotunda negativa, se llega a la conclusión de que existen determinados lenguajes (algunos clásicos, como Basic, Cobol o Fortran, y otros más actuales, como Visual Basic, Python o PHP) que han sido diseñados para permitir que los no programadores puedan leer y comprender los programas y, presumiblemente, aprender a escribir los suyos propios para resolver problemas sencillos.
Por el contrario, C fue creado, influenciado y probado en vivo por programadores profesionales. El resultado es que C da al programador lo que muchos programadores piden: unas pocas y bien escogidas palabras clave, una biblioteca poderosa y estandarizada, unas mínimas restricciones y un máximo control sobre lo que sucede en el interior de la máquina. Si a esto unimos que el código objeto generado por C es casi tan eficiente como el ensamblador, se entenderá por qué lleva medio siglo siendo uno de los lenguajes más populares entre los programadores profesionales.
Ahora bien, C también tiene sus detractores que lo acusan de ser confuso, críptico y demasiado flexible. En efecto, con C se pueden desarrollar las técnicas de programación estructurada, pero también se puede programar "código espagueti". Esto, sin embargo, ocurre con todos los lenguajes: incluso los que tienen una sintaxis más estilizada y elegante, como Python o Ruby, pueden generar código absolutamente ininteligible en manos de un programador manazas. 
 2.4  Un lenguaje estructurado y modular
C es un lenguaje estructurado porque contiene las estructuras de control básicas que hemos estudiado con anterioridad. También permite romper las estructuras y escribir programas no estructurados, pero nosotros evitaremos hacerlo.
C es un lenguaje estrictamente modular. Todos los algoritmos se escriben en forma de funciones, incluido el algoritmo principal (cuya función siembre recibe el mismo nombre: main() ). En C no existen los procedimientos, pero se pueden escribir funciones que no devuelvan ningún valor, es decir, funciones que en realidad son procedimientos.
 3  Variables, operadores y expresiones en C
 3.1  Generalidades sintácticas de C
Antes de profundizar en la programación en C, debemos conocer algunas normas básicas del lenguaje:
    • Los bloques de código se marcan con las llaves {...}. Son equivalentes al inicio y fin que usábamos en pseudocódigo.
    • Todas las instrucciones terminan con un punto y coma ( ; )
    • Los identificadores de variables, funciones, etc., no pueden empezar con un número ni contener espacios o símbolos especiales, salvo el de subrayado ( _ )
    • Los caracteres se encierran entre comillas simples ( '…' )
    • Las cadenas de caracteres se encierran entre comillas dobles ( "..." )
    • El lenguaje es sensitivo a las mayúsculas. Es decir, no es lo mismo escribir main() que MAIN() o Main()
 3.2  Tipos de datos simples
Los tipos fundamentales o simples de datos admitidos por C son los siguientes:
Denominación
Tipo de datos
Tamaño en bits
Rango de valores
char
Carácter
8
de 0 a 255
int
Número entero
16
de –32768 a 32767
float
Número real de precisión simple
32
de 3.4 x 10-38 a 3.4 x 1038
double
Número real de precisión doble
64
de 1.7 x 10-308 a 1.7 x 10308
void
Tipo vacío
0
sin valor

Esta tabla es sólo una orientación, ya que pueden existir variaciones entre compiladores. Por ejemplo, el viejo compilador Borland C++ para Windows utilizaba enteros de 16 bits, pero el compilador mingw integrado con el Dev-C++ utiliza enteros de 32 bits (en realidad, interpreta que todos los “int” son “long int”; véase el modificador “long” más abajo).
El programador debe estar al tanto de los límites que utiliza el compilador que esté usando para evitar los overflows. Una forma sencilla de hacerlo es utilizando el operador sizeof(tipo). Por ejemplo, sizeof(int) nos devuelve la cantidad de bytes que ocupa un dato de tipo int.
El tipo char se usa normalmente para variables que guardan un único carácter, aunque lo que en realidad guardan es un código ASCII, es decir, un número entero de 8 bits sin signo (de 0 a 255). Los caracteres se escriben siempre entre comillas simples ( '…' ). Por lo tanto, si suponemos que x es una variable de tipo char, estas dos asignaciones tienen exactamente el mismo efecto, ya que 65 es el código ASCII de la letra A:
x = 'A';
x = 65;
Mucho cuidado con esto, porque las cadenas de caracteres se escriben con comillas dobles ("…") a diferencia de las comillas simples de los caracteres sueltos.
El tipo int se usa para números enteros, mientras que los tipos float y double sirven para números reales. El segundo permite representar números mayores, a costa de consumir más espacio en memoria.
El tipo void tiene tres usos. El primero es para declarar funciones que no devuelven ningún valor (procedimientos); el segundo, para declarar funciones sin argumentos; el tercero, para crear punteros genéricos. En posteriores epígrafes se discutirán los tres usos.
Observa que en C no existe el tipo de dato lógico. Se utiliza en su lugar el tipo int, representando el 0 el valor falso y cualquier otra cantidad (normalmente 1) el valor verdadero.
Modificadores de tipo
Existen, además, unos modificadores de tipo que pueden preceder a los tipos de datos char e int. Dichos modificadores son:
    • signed: obliga a que los datos se almacenen con signo
    • unsigned: los datos se almacenan sin signo
    • long: los datos ocuparán el doble de espacio en bits del habitual, y, por lo tanto, aumentará su rango de valores
    • short: los datos ocuparán la mitad del espacio habitual, y, por lo tanto, disminuirá su rango de valores
De este modo, nos podemos encontrar, por ejemplo, con estos tipos de datos (suponiendo que un “int” normal ocupe 16 bits):
    • unsigned int: Número entero de 16 bits sin signo. Rango: de 0 a 65535.
    • signed int: Número entero de 16 bits con signo. No tiene sentido, porque el tipo int ya es con signo por definición, pero es sintácticamente correcto.
    • signed char: Carácter (8 bits) con signo. Rango: de –128 a 127
    • long int: Número entero de 32 bits. Rango: de –2147483648 a 2147483647
Incluso podemos encontrar combinaciones de varios modificadores. Por ejemplo:
    • unsigned long int: Número entero de 32 bits sin signo. Rango: de 0 a 4294967295
 3.3  Variables: ámbito y asignación
Todas las variables deben declararse antes de ser usadas. La sintaxis de la declaración incluye su tipo y su nombre (identificador):
tipo_de_datos lista_de_variables;
Por ejemplo:
int cont;
char respuesta;
float x, y, resultado;
En C no está delimitado el lugar del algoritmo donde deben declararse las variables, siendo la única condición que se declaren antes de ser usadas por primera vez. Sin embargo, nosotros recomendamos, al menos al principio, hacer la declaración inmediatamente después de abrir el bloque algorítmico, antes de la primera instrucción.
Todas las variables son, salvo que se indique otra cosa, locales a la función donde estén definidas, dejando de existir al finalizar la función. Las variables globales se declaran fuera del cuerpo de todas las funciones y antes de la función main(), que es el algoritmo principal. Recuerda que debes evitar el uso de variables globales a menos que sea estrictamente necesario.
Se pueden aplicar ciertos modificadores a las variables que modifican la forma en la que almacenan y/o su ámbito. Estos modificadores puedes consultarlos en la sexta parte del libro. Por ahora, no te van a hacer falta.
Para asignar un valor a una variable se utiliza la sentencia de asignación, exactamente igual que en pseudocódigo. Por ejemplo:
cont = cont + 1;
respuesta = 'S';
x = 5.33;
 3.4  Constantes
Recuerda que también se pueden usar identificadores para asociarlos a valores constantes, es decir, valores que no cambiarán nunca durante la ejecución del programa.
Para declarar una constante y asignarle un valor se utiliza el modificador const delante de la declaración:
const tipo_de_datos nombre_constante = valor;
Por ejemplo:
const float pi = 3.141592;
El valor de la constante pi no podrá ser modificado a lo largo del programa.
Otra forma de definir constantes es mediante una directiva del compilador:
#define PI = 3.141592
Las directivas no son instrucciones de C, sino consignas comunicadas al compilador para que sepa que, si encuentra el símbolo PI en el código fuente, debe sustituirlo por 3.141592. Puedes leer más detalles sobre las directivas en los apéndices de este libro. Por ahora nos basta saber que existen estas dos formas de declarar constantes.
 3.5  Conversiones de tipo
C es un lenguaje débilmente tipado, es decir, no hace comprobaciones estrictas de tipos a la hora de asignar un valor a una variable o de comparar dos expresiones.
Por ejemplo, estas instrucciones son correctas:
float a;
int b;
b = 5;
a = b;
Se ha asignado un valor entero a la variable "a", que es de tipo float. En otros lenguajes esto no está permitido, pero en C se realizan conversiones automáticas de tipo cuando en una misma expresión aparecen datos de tipos diferentes. Esto, que en principio es una ventaja, pues elimina algunas limitaciones engorrosas, otras veces es peligroso porque algunos datos pueden cambiar extrañamente de valor al hacerse esa conversión automática.
La conversión puede ser de dos clases:
    • Asignación de un valor a una variable que permita más precisión. Por ejemplo, asignar un número entero a una variable float. En este caso, el número se convierte a real añadiendo ".0" a la parte decimal. No hay pérdida de información.
    • Asignación de un valor a una variable que permita menos precisión. Por ejemplo, asignar un número long int a una variable de tipo int. En este caso, el número se recorta, perdiendo sus bits más significativos, es decir, los que están a la izquierda, y por lo tanto hay pérdida de información. Hay que tener mucho cuidado con este tipo de conversiones porque pueden producir resultados imprevisibles
Además de las conversiones automáticas de tipo, el programador puede forzar la conversión de tipos a voluntad utilizando moldes. Un molde es una expresión de un tipo de datos entre paréntesis que aparece delante de un dato. Entonces, antes de evaluar la expresión, el dato es convertido al tipo especificado en el molde. Por ejemplo:
float a;
int b;
a = 5;
b = (float)a/2;
Sin el molde (float), la división a/2 sería entera, ya que a es una variable de tipo int, y se perdería la parte decimal. Al aplicar el molde, se convierte momentáneamente el valor entero 5 al valor real 5.0 y se evalúa la expresión, que ahora sí se realiza como división real, conservando sus decimales.
 3.6  Operadores y expresiones
C es un lenguaje muy rico en operadores, por lo que ahora solo hablaremos de los más habituales, dejando otros muy específicos para temas posteriores.
Operadores aritméticos
Igual que en pseudocódigo, en C existen los operadores aritméticos típicos, y alguno más que más abajo comentaremos:
Operador
Operación
+
Suma
-
Resta
*
Multiplicación
/
División
%
Módulo
++
Incremento
--
Decremento
Se pueden utilizar paréntesis ( ) para cambiar el orden de las operaciones, pero no corchetes [ ], que C se reserva para otros usos.
Observa que no existe el operador potencia. En C, las potencias se calculan con funciones de librería.
Tampoco existe el operador de división entera. En C se utiliza el mismo símbolo para la división entera y la real: la barra ( / ). Simplemente, si los operandos son de tipo entero, C realiza una división entera, y si son de tipo real, la división será con decimales.
Los operadores incremento y decremento no suelen existir en otros lenguajes, pero son muy prácticos. Sirven para abreviar las expresiones típicas de los contadores:
cont++;
es equivalente a
cont = cont + 1;
cont--;
es equivalente a
cont = cont – 1;
Los operadores de incremento y decremento pueden escribirse antes o después de la variable. Es decir, que estas dos expresiones son correctas y realizan la misma operación:
cont++;
++cont;
Ahora bien, no son exactamente iguales cuando aparecen como parte de una expresión, ya que la primera se realiza después de evaluar la expresión, y, la segunda, antes.
Esto quiere decir que, en este caso, tanto la variable x como la variable y tomarán el valor 11:
x = 10;
y = ++x;
Pero, escrito de esta otra forma, la variable x toma el valor 11, pero y se queda con 10, ya que el incremento (x++) se realiza después de evaluar la expresión y asignarla a la variable y:
x = 10;
y = x++;
Operadores relacionales
Los operadores relacionales no ofrecen ninguna dificultad porque son exactamente iguales a los que hemos utilizado en pseudocódigo. Sólo hay que hacer una salvedad: el C, como se ha dicho, no existe el tipo de dato lógico, sino que se emplean números enteros. Falso se representa con el valor 0. Verdadero se representa con cualquier valor distinto de cero, aunque preferentemente se usa el 1.
    • Falso = 0
    • Verdadero = 1 (o cualquier número distinto de 0)
Los operadores relacionales en C son:
Operador
Operación
>
Mayor que
>=
Mayor o igual que
<
Menor que
<=
Menor o igual que
==
Igual que
!=
Distinto de
Operadores lógicos
Los operadores lógicos de C también son los mismos que usamos en pseudocódigo, aunque se escriben de manera diferente. Recuerda que el resultado de las operaciones lógicas, en C, no es verdadero o falso, sino 1 ó 0.
Operador
Operación
&&
Y
||
O
!
No
Otros operadores de C
C dispone de otros operadores sobre los que el lector puede obtener información en cualquier manual de programación en C. Aquí nos limitaremos a mencionarlos, apuntando que algunos de ellos los estudiaremos en temas posteriores, cuando nos sean necesarios.
    • Operadores a nivel de bits:  & (and), | (or), ^ (xor), ~ (complemento a uno), >> (desplazamiento a la derecha) y << (desplazamiento a la izquierda). Actúan directamente sobre los bits de la representación binaria de un dato.
    • Operador condicional: ? (puede sustituir a condicionales simples y dobles)
    • Operadores puntero: & (dirección) y * (contenido). Los estudiaremos detenidamente en el tema de estructuras dinámicas, aunque empezaremos a manejarlos antes.
    • Operador en tiempo de compilación: sizeof (longitud en bytes de un identificador). También los estudiaremos en el tema de estructuras dinámicas.
    • Operadores de acceso a elementos de estructuras: . (acceso directo) y -> (acceso por puntero). Estos los veremos en dos temas posteriores: el dedicado a las estructuras de datos estáticas y el de estructuras dinámicas.
Precedencia de operadores y conversión de tipos en expresiones
Las expresiones en C son similares a las que hemos estado usando en pseudocódigo: combinaciones de variables, constantes y operadores. Las expresiones se evalúan, es decir, se calcula su resultado, aplicando las reglas de precedencia de operadores, que pueden alterarse mediante el uso de paréntesis. Las reglas de precedencia son las mismas que aplicamos en pseudocódigo.
En una expresión es posible que aparezcan variables y/o constantes de diferentes tipos de datos. Cuando esto ocurre, C convierte todos los datos al tipo más grande. Por ejemplo, si aparecen datos de tipo short int, int y long int, todos ellos se convertirán a long int antes de realizar las operaciones. 

 4  Estructuras de control
Las estructuras de control en C son muy similares a las que hemos utilizado en pseudocódigo, cambiando ligeramente la notación empleada. Pasamos a continuación a presentarlas todas, con su equivalente en pseudocódigo. Para una explicación más extensa de cada una de ellas, puedes volver a leer la primera parte de este libro.
 4.1  Condicional simple
Pseudocódigo
Lenguaje C
si condición entonces 
inicio
   acciones
fin
if (condición)
{
   acciones
}
Observa que, en C, la condición debe escribirse entre paréntesis y que no se emplea la palabra "entonces".
 4.2  Condicional doble
Pseudocódigo
Lenguaje C
si condición entonces
  inicio
    acciones-1
  fin
si_no
  inicio
    acciones-2
  fin
if (condición)
{
   acciones-1
}
else
{
   acciones-2
}

 4.3  Condicional múltiple
Pseudocódigo
Lenguaje C
según expresión hacer
inicio
  valor1: acciones-1
  valor2: acciones-2
  valor3: acciones-3
    ...
  valorN: acciones-N
  si_no: acciones-si_no
fin
switch (expresión)
{
  case valor1: acciones-1;
               break;
  case valor2: acciones-2;
               break;
  case valor3: acciones-3;
               break;
    ...
  case valorN: acciones-N;
               break;
  default: acciones-si_no;
}
Esta estructura presenta algunas peculiaridades, a saber:
    • La expresión discriminante debe escribirse entre paréntesis y ser de un tipo ordinal (int, char o similar). No pueden usarse cadenas ni números reales.
    • Los valores no pueden ser expresiones, sino constantes, es decir, números o caracteres fijos.
    • ¡Cuidado! Las acciones no son bloques de instrucciones, es decir, no van encerradas entre { y }. Eso quiere decir que, si se ejecutan las acciones-2, después se ejecutarán automáticamente las acciones-3, luego las acciones-4, etc. La forma de evitar esto es insertar la instrucción break al final de cada bloque de instrucciones.
 4.4  Bucle mientras
Pseudocódigo
Lenguaje C
mientras condición hacer
inicio
  acciones
fin
while (condición)
{
  acciones
}
 4.5  Bucle repetir
Pseudocódigo
Lenguaje C
repetir
inicio
   acciones
fin
mientras que condición
do
{
   acciones
}
while (condición)
 4.6  Bucle para
Pseudocódigo
Lenguaje C
para cont desde valor_inicial hasta valor_final 
inicio
   acciones
fin
for (inicialización; condición; incremento)
{
   acciones
}
Cuidado con este tipo de bucle porque es algo diferente a como lo hemos visto en pseudocódigo. Ya se ha dicho en varias ocasiones que C es a veces un poco críptico. El bucle para (o bucle for) es un ejemplo típico de ello ya que:
    • La variable contador debe ser inicializada con una asignación dentro de la instrucción for.
    • El valor final debe ser expresado en forma de condición, como haríamos en un bucle mientras.
    • El incremento del contador hay que indicarlo explícitamente.
Por ejemplo, el siguiente bucle en pseudocódigo:
para cont desde 1 hasta 100 inc 2 hacer
inicio
    acciones
fin
Tendría esta traducción en C:
for (cont = 1; cont <= 100; cont = cont + 2)
{
    acciones
}
 5  Funciones. La función main()
Como se ha dicho anteriormente, C es un lenguaje modular hasta el extremo de que todas las líneas de código deben pertenecer a alguna función, incluyendo las instrucciones del algoritmo principal, que se escriben en una función llamada principal (main en inglés)
 5.1  Funciones
La declaración de funciones se hace de forma similar a la empleada en pseudocódigo:
tipo_devuelto nombre_función (parámetros_formales)
{
   ...instrucciones...
   return expresión;
}
Observa que las únicas diferencias con el pseudocódigo son que no se usa la palabra "función", que las llaves { y } sustituyen a inicio y fin, y que se emplea la palabra return en lugar de devolver.
 5.2  Procedimientos
Si el tipo_devuelto es void, se considera que la función no devuelve ningún valor y que, por lo tanto, es un procedimiento. Entonces, un procedimiento se declara así:
void nombre_procedimiento (parámetros_formales)
{
   ...instrucciones...
}
 5.3  Paso de parámetros
Los parámetros formales son, como en pseudocódigo, una lista de tipos e identificadores que se sustituirán por los parámetros actuales y se usarán como variables dentro de la función. 
Los parámetros se pasan normalmente por valor, pero también se pueden pasar por referencia. El paso de parámetros por referencia admite dos sitaxis ligeramente diferentes en C: anteponiendo el operador * (asterisco) al nombre del parámetro (como hemos hecho en pseudocódigo) o anteponiendo el operador &. 
Paso de parámetros por valor
Por ejemplo, en esta función el paso de parámetros es por valor:
int funcion1 (int x, int y)
Esto quiere decir que la función1 recibirá únicamente el valor de los dos parámetros, x e y. Podrá utilizar esos valores a lo largo de su código, e incluso podrá cambiarlos. Pero cualquier cambio en x e y no afectará a los parámetros actuales, es decir, a los parámetros del programa que llamó a función1.
Paso de parámetros por referencia con el operador *
En la siguiente función, el paso del parámetro "x" es por valor y el del parámetro "y", por referencia:
int funcion2 (int x, int *y)
¡OJO! Recuerda que cada vez que se vaya a usar el parámetro "y" dentro del código de la función, será necesario acompañarlo del asterisco. Por ejemplo:
*y = 5;
x = 17 + *y;
(Hay algunas excepciones a esta regla, pero ya las veremos cuando surjan más adelante)
Por último, también en la llamada a la función hay que indicar explícitamente si alguno de los parámetros se está pasando por referencia, utilizando el operador &, como en pseudocódigo. Por lo tanto, para llamar a la funcion2 del ejemplo anterior con los parámetros A y B habrá que escribir:
resultado = funcion2 (A, &B);
Observa que el segundo parámetro (el que se pasa por referencia), lleva delante el operador &.
Una última observación: en realidad, en C no existe en paso por referencia propiamente dicho, sino que se pasa a la función la dirección de memoria del parámetro actual  por valor. Es decir, se pasa un puntero por valor (véanse los punteros más adelante en este mismo texto). Como la función accede directamente a esa posición de memoria, puede cambiar la variable del programa principal. En la práctica, el resultado es el mismo que si se pasase por referencia, y para el programador no apreciará diferencia alguna.
Paso de parámetros por referencia con el operador &
Otra forma de pasar un argumento por referencia es usar el operador & en los parámetros formales, así:
int funcion3 (int x, int &y)
En esta función, el parámetro x se pasa por valor y el parámetro “y” se pasa por referencia. Utilizando esta sintaxis no es necesario añadir asteriscos cada vez que se usa la “y” en el cuerpo de la función, ni tampoco usar “&” en la llamada a la función.
Esta tercera forma de paso por referencia no es estándar en C, sino que es propia de C++, por lo que evitaremos utilizarla.
Juntándolo todo en un ejemplo
En el siguiente ejemplo se ilustra los dos tipos de paso de parámetros y, en el paso por referencia, las dos sintaxis alternativas de que dispone C.
El ejemplo muestra tres funciones muy similares que reciben dos parámetros, a y b. Las tres intentan intercambiar el valor de a y b mediante una tercera variable, tmp. Sin embargo, en la primera de ellas el intercambio no tiene ningún efecto en el programa main(), ya que los parámetros están pasados por valor. En las otras dos funciones sí que se consigue el intercambio, ya que los parámetros está pasados por referencia.
Lo más interesante de este ejemplo es mostrar cuál es la sintaxis correcta en cada tipo de paso de parámetros.
#include <stdio.h>

// Paso de parámetros por valor.
// En este ejemplo, esta función no tendrá el efecto deseado, porque las variables
// del programa principal no se verán afectadas.
void intercambiar1(int a, int b)
{
     int tmp = a;
     a = b;
     b = tmp;
}

// Paso de parámetros por referencia, sintaxis 1.
// Esta función sí que consigue intercambiar los valores de las variables
// del programa principal.
void intercambiar2(int *a, int *b)
{
     int tmp = *a;
     *a = *b;
     *b = tmp;
}

// Paso de parámetros por referencia, sintaxis 2.
// Esta función también consigue su objetivo. A todos los efectos,
// es idéntica a la función anterior.
void intercambiar3(int &a, int &b)
{
     int tmp = a;
     a = b;
     b = tmp;
}


// Programa principal
int main()
{
    int dato1 = 30, dato2 = 90;
    
    printf("Antes de la llamada a las funcioens: dato1 = %i, dato2 = %i\n", dato1, dato2);
    intercambiar1(dato1, dato2);
    printf("Después de intercambiar1: dato1 = %i, dato2 = %i\n", dato1, dato2);
    intercambiar2(&dato1, &dato2);
    printf("Después de intercambiar2: dato1 = %i, dato2 = %i\n", dato1, dato2);
    intercambiar3(dato1, dato2);
    printf("Después de intercambiar3: dato1 = %i, dato2 = %i\n", dato1, dato2);
    
    return 0;
}
 5.4  La función main()
La función main() contiene el algoritmo o módulo principal del programa. La ejecución de un programa siempre empieza por la primera línea de la función main()
La función main(), como todas las funciones de C, puede devolver un valor. El valor devuelto por main() debe ser de tipo entero. Esto se utiliza para pasar algún valor al programa que haya llamado al nuestro, que suele ser el sistema operativo. Si main() no devuelve un número entero al sistema operativo mediante una sentencia return, entonces nuestro programa devolverá un número desconocido. Moraleja: es una buena idea incluir un return al final de la función main(). Generalmente, la devolución de un 0 indica al sistema operativo que el programa a finalizado sin problemas, mientras que cualquier otro valor señala que se ha producido algún error.
Por lo tanto, la forma habitual de la función main() será:
int main(void)
{
   ...instrucciones del algoritmo principal...
   return 0;
}
Observa que main() no tiene argumentos, por lo que aparece el identificador void entre paréntesis en la declaración. También se pueden utilizar argumentos en main(), pero eso es algo que trataremos en otro momento.
 5.5  Prototipos de funciones
En C no es necesario escribir las funciones (subalgoritmos) antes de su primera invocación. El mecanismo de compilación y enlace de C permite, de hecho, que las funciones puedan estar físicamente en un archivo distinto del lugar desde el que se invocan.
En la práctica, esto plantea un problema: C no tiene forma de saber si la llamada a una función se hace correctamente, es decir, si se le pasan los argumentos debidos y con el tipo correcto, ni si el resutado devuelto es asignado a una variable del tipo adecuado. 
Para conseguir que C realice esas comprobaciones se utilizan los prototipos de función. Un prototipo de función es la declaración de una función. Consiste, simplemente, en la primera línea del código la función. El prototipo debe aparecer antes de que la función se invoque por primera vez, aunque el código completo de la función esté en otra parte. Los prototipos permiten al compilador comprobar que los argumentos de la función coinciden en tipo y número con los de la invocación de la misma, y que el tipo devuelto es el correcto.
Los prototipos suelen aparecer al principio del programa, antes de la función main(). Observa, en el siguiente ejemplo, que el prototipo de la función calcular_area() se coloca delante de main(). Sin embargo, el código concreto de esta función no aparece hasta después (incluso podría estar situado en otro archivo diferente):
float calcular_area (float base, float altura);	// Prototipo de la función

int main()				// Algoritmo principal
{
   ...instrucciones...
   area = calcular_area (x,y);
   ...más instrucciones...
   return 0;
}

float calcular_area(float base, float altura)	// Código de la función
{
   ... instrucciones...
}
Cuando se vayan a usar funciones de librería, como fabs() (valor absoluto), sqrt() (raíz cuadrada) o cualquier otra, hay que escribir sus prototipos antes de la función main(). Sin embargo, como estas funciones no las hemos escrito nosotros, desconocemos cuales son sus prototipos.
En C se soluciona este problema con los archivos de cabecera, que son archivos proporcionados con el compilador de C que incluyen en su interior los prototipos de las funciones de librería, entre otras cosas. Como funciones de librería hay muchas, también hay muchos archivos de cabecera. Por ejemplo, el archivo math.h tiene los prototipos de todas las funciones matemáticas. Todos los archivos de cabecera tienen la extensión .h en su nombre (h de "header").
Para incluir un archivo de cabecera en nuestro programa se utiliza #include, que no es exactamente una instrucción de C, sino una directiva de compilación. Más adelante veremos qué significa eso. Ya hemos visto otra directiva de compilación: #define, que usábamos para definir constantes. Las directivas de compilación se detallan en uno de los apéndices de este libro, y puedes ir ahora allí si quieres ampliar esta información.
Por ejemplo, esta línea de código sirve para incluir todos los prototipos de las funciones de librería matemática en nuestro programa:
#include <math.h>
Al final del tema, en el apéndice dedicada a las funciones ANSI, encontrarás una lista con las funciones utilizadas más habitualmente y sus correspondientes archivos de cabecera. Cada vez que necesites usar una de esas funciones en un programa, debes escribir al principio del mismo el #include del archivo de cabecera para disponer así del prototipo.
 5.6  Estructura general de un programa en C
Visto todo esto, ya estamos en condiciones de echar un vistazo a cual será el aspecto de (casi) todos los programas que escribamos en C.
Todo programa C, desde el más pequeño hasta el más complejo, tiene un programa principal ubicado en la función main(). Además, por encima de main() deben aparecer los prototipos de funciones (y esto implica a los archivos de cabecera, si se utilizan funciones de librería) y las variables y constantes globales. Por debajo de main() encontraremos el código de las funciones de usuario.
Por lo tanto, la estructura habitual de nuestros programas en C debería ser esta: 
/* Comentario inicial: nombre del programa, del programador, fecha, etc */

/* Archivos de cabecera (prototipos de funciones de librería) */
#include <archivo_cabecera.h>
#include <archivo_cabecera.h>

/* Prototipos de funciones escritas por nosotros */
float función1 (argumentos);
float función2 (argumentos);

/* Variables globales */
int variable_global1;
char variable_global2;

/* Algoritmo principal */
int main(void)
{
   /* Variables locales del algoritmo principal */
   int a, b;
   float x, y;
   ...
   ...
   /* Instrucciones del algoritmo principal */
   ...
   función1(argumentos);
   ...
   función2(argumentos);
   ...
   return 0;
}

/* Código completo de las funciones escritas por nosotros */
float función1 (argumentos)
{
   /* Variables locales e instrucciones de este subalgoritmo */
}
float función2 (argumentos)
{
   /* Variables locales e instrucciones de este subalgoritmo */
}

 6  Entrada y salida estándar
La entrada y salida de datos en C, es decir, la traducción de las instrucciones leer() y escribir() de pseudocódigo, es uno de los aspectos más difíciles (y criticables) de C.
El estándar ANSI C dispone de muchas funciones para hacer las entradas y salidas de datos. En concreto, dispone de un subconjunto de ellas para hacer la entrada y salida por consola, es decir, por teclado y pantalla.
Podemos clasificar estas funciones de E/S en dos grupos:
    • Funciones de E/S simples: getchar(), putchar(), gets(), puts()
    • Funciones de E/S con formato: printf(), scanf()
Las más utilizadas y versátiles son sin duda las segundas, así que nos detendremos más en ellas.
 6.1  E/S con formato
Salida de datos: printf()
La función printf() (de "print" = imprimir y "f" = formato) sirve para escribir datos en el dispositivo de salida estándar (generalmente la pantalla) con un formato determinado por el programador. La forma general de utilizarla es la siguiente:
printf(cadena_de_formato, datos);
El prototipo de printf() se encuentra en el archivo de cabecera stdio.h (de "std" = standard e "io" = input/output, es decir, entrada/salida; por lo tanto, "stdio" es un acrónimo de "entrada/salida estándar")
El primer argumento, la cadena_de_formato, especifica el modo en el que se deben mostrar los datos que aparecen a continuación. Esta cadena se compone de una serie de códigos de formato que indican a C qué tipo de datos son los que se desean imprimir. Todos los códigos están precedidos del símbolo de porcentaje ("%"). Por ejemplo, el código "%i" indica a la función que se desea escribir un número de tipo int, y el código "%f", que se desea escribir un número real de tipo float.
La forma más simple de utilizar printf() es:
int a;
a = 5;
printf("%i", a);
Esto escribirá el valor de la variable entera a en la pantalla, es decir, 5. Fíjate que el primer argumento de printf() es una cadena (y, por lo tanto, se escribe entre comillas) cuyo contenido es el código del tipo de dato que se pretende escribir. El segundo argumento es el dato mismo.
En una sola instrucción printf() pueden escribirse varios datos. Por ejemplo:
int a;
float x;
a = 5;
x = 10.33;
printf("%i%f", a, x);
Observa detenidamente la cadena de formato: primero aparece "%i" y luego "%f". Esto indica que el primer dato que debe imprimirse es un entero, y el segundo, un real. Después, aparecen esos datos separados por comas y exactamente en el mismo orden que en la cadena de formato: primero a (la variable entera) y luego x (la variable real). El resultado será que en la pantalla se escribirán los números 5 y 10.33.
Los códigos de formato que se pueden utilizar en printf() son:
Código
Tipo del dato que se escribe
%c
Carácter
%d
Número entero
%i
Número entero
%e
Número real con notación científica
%f
Número real
%g
Usar %e o %f, el más corto
%o
Número octal
%s
Cadena de caracteres
%u
Entero sin signo
%x
Número hexadecimal
%p
Puntero
Algunos de estos códigos sirven para imprimir tipos de datos que aún no conocemos, pero que iremos viendo en las siguientes páginas.
Hay códigos que admiten modificadores. Por ejemplo:
    • Los códigos numéricos "%i", "%d", "%u" (para números enteros) y "%f", "%e" y "%g" (para números reales), permiten insertar modificadores de longitud "l" (longitud doble) y "h" (longitud corta). Así, por ejemplo, "%ld" indica que se va a imprimir un entero de longitud doble (long int); "%hu" sirve para enteros cortos sin signo (unsigned short int); "%lf" indica que se imprimirá un número real de longitud doble (double), etc.
    • El código "%f" (números reales) se pueden usar con un modificador de posiciones decimales que se desean mostrar. Por ejemplo, con "%10.4f" obligamos a que se impriman diez dígitos a la izquierda de la coma decimal y cuatro a la derecha. La escritura se ajusta a la derecha. Para ajustarla a la izquierda se utiliza el modificador "-", de esta forma: "%-10.4f"
    • El código "%s" (cadenas de caracteres) se puede combinar con un especificador de longitud máxima y mínima de la cadena. Por ejemplo, "%4.8s" escribe una cadena de al menos cuatro caracteres y no más de ocho. Si la cadena tiene más, se pierden los que excedan de ocho. También se puede utilizar el modificador "-" para alinear el texto a la izquierda.
Además de los códigos de formato, en la cadena de formato puede aparecer cualquier texto entremezclado con los códigos. A la hora de escribir en la pantalla, los códigos serán sustituidos por los datos correspondientes. Por ejemplo:
int a;
float x;
a = 5;
x = 10.33;
printf("El número entero es %i y el real es %f", a, x);
Lo que aparecerá en la pantalla al ejecutar este fragmento de código será: 
El número entero es 5 y el real es 10.33
Una última observación sobre printf(). Hay ciertos caracteres que no son directamente imprimibles desde el teclado. Uno de ellos es el salto de línea. Para poder ordenar a printf() que escriba un salto de línea (o cualquier otro carácter no imprimible) se utilizan los códigos de barra invertida, que con códigos especiales precedidos del carácter "\".
En concreto, el carácter "salto de línea" se indica con el código "\n". Observa las diferencias entre estos dos bloques de instrucciones para intentar comprender la importancia del salto de línea:
int a;
a = 5;
printf("La variable a vale %i", a);
a = 14;
printf("La variable a vale %i", a);
El resultado en la pantalla de la ejecución de estas instrucciones es: 
La variable a vale 5La variable a vale 14
Veamos el mismo ejemplo usando el código del salto de línea (\n):
int a;
a = 5;
printf("La variable a vale %i\n", a);
a = 14;
printf("La variable a vale %i", a);
El resultado en la pantalla será:
La variable a vale 5
La variable a vale 14
Entrada de datos: scanf()
La función scanf() es, en muchos sentidos, la inversa de printf(). Puede leer desde el dispositivo de entrada estándar (normalmente el teclado) datos de cualquier tipo de los manejados por el compilador, convirtiéndolos al formato interno apropiado. Funciona de manera análoga a printf(), por lo que su sintaxis es:
scanf(cadena_de_formato, datos);
El prototipo de scanf() se encuentra en el archivo de cabecera stdio.h (de "std" = standard e "io" = input/output, es decir, entrada/salida)
La cadena_de_formato tiene la misma composición que la de printf(). Los datos son las variables donde se desea almacenar el dato o datos leidos desde el teclado. ¡Cuidado! Con los tipos simples, es necesario utilizar el operador & delante del nombre de la variable, porque esa variable se pasa por referencia a scanf() para que ésta pueda modificarla.
Por ejemplo:
int a, b;
float x;
scanf("%d", &a);
scanf("%d%f", &b, &x);
La primera llamada a scanf() sirve para leer un número entero desde teclado y almacenarlo en la variable a. La segunda llamada lee dos números: el primero, entero, que se almacena en b; y, el segundo, real, que se almacena en x.
La función scanf() tiene alguna otra funcionalidad añadida para el manejo de cadenas de caracteres que ya veremos en su momento.
Ejemplo de uso de scanf() y  printf()
Debido a la relativa complejidad de estas funciones de entrada y salida, vamos a presentar un pequeño ejemplo de traducción de pseudocódigo a C. Se trata de un algoritmo que lee dos números enteros, A y B. Si A es mayor que B los resta, y en otro caso los suma.
Observa detenidamente la correspondencia entre cada pareja de instrucciones, especialmente las de entrada y salida.
Pseudocódigo
Traducción a C
algoritmo suma_y_resta

variables
   a y b son enteros
inicio
   escribir ("Introduzca dos números enteros")
   leer(a, b)
   si (a < b) entonces
       escribir("La suma de a y b es:", a+b)
   si_no
       escribir("La resta de a menos b es:", a–b)
fin
/* Programa suma y resta */
#include <stdio.h>
int main()
{   
  int a, b;
  printf ("Introduzca dos números enteros\n");
  scanf("%d%d", &a, &b);
  if (a < b) 
     printf("La suma de %d y %d es: %d", a, b, a+b);
  else
     printf("La resta de %d menos %d es: %d", a, b, a–b);
  return 0;
}
 6.2  E/S simple por consola
Técnicamente, con printf() y scanf() es posible escribir y leer cualquier tipo de datos desde cualquier dispositivo de salida o entrada, no solo la pantalla y el teclado, como de hecho comprobaremos cuando estudiemos los ficheros.
En la práctica, aunque printf() resulta bastante efectiva y versátil, scanf() puede darte muchos dolores de cabeza. Para hacerte una idea, sólo tienes que probar a hacer un scanf() de un número entero e inmediatamente después otro scanf() de una cadena de caracteres. El segundo scanf() fallará. La razón es bastante rocambolesca: el flujo de entrada no consumirá el carácter de retorno de carro al leer el número entero, por lo que dicho carácter se adjudicará al segundo scanf() automáticamente.
Por suerte, existe otro grupo de funciones en ANSI C específicamente diseñadas para hacer la E/S por consola, es decir, por teclado y pantalla, de manera más simple. Las resumimos en el siguiente cuadro.
Los prototipos de estas funciones se encuentran en el archivo de cabecera stdio.h (de "std" = standard e "io" = input/output, es decir, "entrada/salida")
Función
Utilidad
Ejemplo
getchar()
Espera a que se pulse una tecla seguida de INTRO y devuelve su valor. Muestra el eco en la pantalla, es decir, la tecla pulsada aparece en la pantalla.
putchar(carácter)
Escribe un carácter en la pantalla
char car;
car = getchar();
printf("Tecla pulsada:\n");
putchar(car);
gets(cadena)
Lee del teclado una cadena de caracteres seguida de INTRO.
puts(cadena)
Escribe una cadena de caracteres en la pantalla
char cadena[50];
gets(cadena);
printf("Cadena tecleada:\n");
puts(cadena);
Para evitar los problemas que a menudo causa scanf(), podemos recurrir a gets() para leer las cadenas de caracteres. Si necesitamos leer un número, podemos usar gets() y luego convertir la cadena a un tipo de dato numérico con las funciones de conversión atoi() y atof(), como se muestra en el siguiente ejemplo:
char cadena[50];
int a;
float x;

gets(cadena);		// Leemos una cadena de caracteres
a = atoi(cadena);		// Convertimos la cadena en un número entero
x = atof(cadena);		// Convertimos la cadena en un número real
Las funciones de conversión atoi() y atof() tratarán de convertir la cadena en un número, si ello es posible (es decir, si la cadena realmente contiene números). Estas funciones, junto con muchas otras, se describen en el apéndice I de este capítulo.
Usar la combinación de gets() con atoi() o atof() es más costoso que utilizar scanf(). Primero, porque necesitamos una variable auxiliar de tipo cadena. Y, segundo, porque gets() es una función peligrosa: si se teclean más caracteres de los que caben en la cadena, el resultado es imprevisible (a menudo el programa se cuelga). Esto también tiene solución utilizando en su lugar la función fgets().
Tal vez pienses que resulta demasiado complicado hacer algo muy simple como una entrada de datos por teclado. Tienes razón. Pero ten en cuenta dos cosas: las entradas de datos nunca son simples (son el punto donde el usuario interacciona con más libertad con el programa, y los usuarios humanos tendemos a hacer cosas impredecibles y complicadas), y C es un lenguaje de nivel intermedio, por lo que muchas tareas de alto nivel, simplemente, no las resolverá por nosotros. En ese sentido, C requiere del programador prestar atención a ciertos detalles que podría obviar en otros lenguajes. Es por esto, entre otras cosas, por las que C tiene exaltados detractores pero también incondicionales entusiastas.
Por último, mencionaremos que los compiladores de Borland tienen dos variaciones muy útiles de la función getchar() llamadas getche() y getch(). Estas funciones, no definidas en el estándar ANSI de C, son como getchar() pero sin necesidad de pulsar INTRO detrás del carácter. La primera muestra el eco, es decir, escribe en la pantalla la tecla pulsada, y la segunda no. Los prototipos de estas funciones se encuentran en conio.h (de "con" = consola e "io" = input/output)
 7  Flujo de trabajo programando con lenguaje C
Como vimos más arriba, el ciclo de vida de desarrollo del software consta de una serie de etapas. En esta parte del libro nos estamos centrando a la etapa de implementación o codificación del software, ya que estamos aprendiendo un lenguaje de programación concreto.
Antes de continuar profundizando en el lenguaje, vamos a hacer un pequeño paréntesis para especificar cuál suele ser el flujo de trabajo en el desarrollo de programas con lenguaje C. 
Cuando se trabaja con C, la implementación de un programa suele dividirse en varias subfases: edición, compilación, enlace y depuración. Pasamos a describirlas brevemente a continuación.
 7.1  Edición del código fuente
Editar consiste en escribir el código fuente del programa en el lenguaje seleccionado, en nuestro caso C.
Para escribir el código nos puede servir cualquier procesador de textos que permita guardar el documento en forma de texto ASCII plano (sin códigos de control y formato propios de los procesadores avanzados, como MS Word). 
Existen multitud de procesadores de texto plano para programar en lenguaje C. Solo tienes que hacer una pequeña búsqueda en internet para encontrar una pléyade de candidatos. La ventaja de estos procesadores es que resaltan, en diferentes colores y tipografías, las palabras clave, las funciones, las cadenas, los comentarios, etc, haciendo de este modo mucho más legible el código fuente. Necesitarás probar unos cuantos antes de decidir cuál es el que más te gusta.
Además, es habitual que los compiladores de C incluyan también un editor. Por ejemplo, los compiladores de Borland (como Turbo C/C++, Borland C/C++ o C++ Builder) poseen un entorno integrado de desarrollo, que es un programa que une al editor de texto, al compilador y al depurador en una sola aplicación controlada por un único interfaz, lo cual facilita mucho el trabajo. Estos editores con funcionalidades añadidas suelen denominarse IDEs (Integrated Development Environment, entorno integrado de desarrollo), y nos referiremos a ellos con más detalle en los apéndices de este libro. 
Mi recomendación es que, al menos al principio, intentes usar un editor simple, que no incluya el compilador. Esto te obligará a hacer un trabajo adicional al tener que compilar y enlazar manualmente tu programa, pero es la mejor forma de comprender realmente en qué consiste la compilación y el enlace. En el futuro, esta comprensión te puede ayudar a resolver muchos errores de compilación y enlace.
En cualquier caso, las recomendaciones que hemos de seguir durante la edición del código fuente son:
    • No empezar a teclear código sin haber entendido bien el problema que se nos plantea. Si éste es complejo, es imprescindible plantear antes su descomposición modular en papel, resolviendo los módulos con pseudocódigo.
    • Recuerda: comenzar a teclear a lo loco y sin pensar antes la solución detenidamente es la manera más segura de tardar el mayor tiempo posible en desarrollar un programa que, además, no funcione bien.
    • Realizar un diseño modular previo del programa. Recuerda que un módulo de más de 30 ó 40 líneas (aproximadamente) empieza a ser demasiado largo.
    • Evitar las variables globales.
    • Elegir bien el nombre de los identificadores (variables, constantes, funciones...). Que sean significativos y no excesivamente largos.
    • Identar el texto, es decir, dejar las sangrías necesarias para facilitar su comprensión.
    • Usar espacios y líneas en blanco siempre que se considere que facilita la lectura.
    • Ser generosos documentando el código fuente. Mejor que sobren comentarios que no que falten.
    • Guardar el código fuente en archivos de texto cuya extensión sea ".c" (por ejemplo: "ejercicio.c")
 7.2  Compilación
El proceso de compilación, como sabes, consiste en que un programa, llamado compilador, traduzca el código fuente en lenguaje C a código binario. La compilación, por lo tanto, no es más que una traducción.
El resultado de la compilación es el mismo programa traducido a código binario. Como el programa fuente estaba almacenado en un archivo con extensión .C, el compilador suele guardar el programa objeto en otro archivo con el mismo nombre y extensión .OBJ.
Los programas cortos se guardan en un único archivo fuente que se traducirá a un único archivo objeto. Pero cuando los programas crecen, es habitual distribuir el código fuente en varios archivos con el objetivo de manipularlo mejor.
Los compiladores de C usan compilación separada. Esto significa que, si un programa largo está escrito en varios archivos fuente, no es necesario compilarlos todos cada vez que se modifica algo. Basta con volver a compilar el archivo modificado. Por eso, dividir un programa fuente largo en varios archivos más cortos también sirve para mejorar los tiempos de compilación.

Cuando tenemos varios archivos fuente es normal que existan dependencias entre ellos. Por ejemplo, cuando en un archivo A1 se utiliza (con la directiva #include) un archivo de cabecera A2. Si modificamos el archivo A2 es necesario volver a compilar el archivo A1, aunque A1 no haya sido modificado en absoluto. Se dice entonces que existe una dependencia entre los archivos A1 y A2.
Controlar las dependencias es un trabajo tedioso y propenso a errores. Por fortuna, los compiladores se encargan de controlarlas por sí mismos. Así que no te extrañes si, al volver a compilar un archivo fuente después de modificarlo, se compilan automáticamente algunos otros archivos, aunque no los hayas tocado. El control de las dependencias lo puede realizar el compilador de manera automática o semiautomática (mediante archivos de dependencias o makefiles escritos por el programador), como veremos en los apéndices.
Los compiladores, en fin, son programas muy complejos que, además, tienen multitud de opciones de compilación. Algunas de esas opciones también las veremos en los apéndices del libro. Allí encontrarás información sobre cómo compilar tus programas con Mingw, un compilador de C/C++ para Windows, y con gcc, el compilador nativo de Linux.
 7.3  Enlace (link)
Cuando existen varios programas objeto es necesario combinarlos todos para dar lugar al programa ejecutable definitivo. Este proceso se denomina enlace.
El código objeto de las funciones de librería de C se encuentra almacenado en varios archivos (cuya extensión es .LIB) situados en ubicaciones conocidas por el enlazador. De este modo, el código objeto de las funciones de librería que hayamos utilizado en nuestro programa puede unirse con el código objeto del programa durante en enlace, generándose el programa ejecutable.
Por lo tanto, es necesario hacer el enlace cuando el programa se encuentra distribuido en varios archivos, o cuando dentro del programa se utilizan funciones de librería. Esto quiere decir que, en la práctica, el enlace hay que hacerlo siempre.
El enlazador o linker, es decir, el programa encargado de hacer el enlace, es en realidad diferente del compilador, que sólo hace la traducción. Sin embargo, la mayoría de los compiladores de C lanzan automáticamente el enlazador al finalizar la compilación para que el programador no tenga que hacerlo.

El enlace de nuestro código objeto con las funciones de librería puede hacerse de dos maneras:
    • Enlace estático. Consiste en unir durante el enlace el código objeto de las librerías con el código del programa, generando así el ejecutable. El programa ejecutable crece notablemente de tamaño respecto de los archivos objeto, ya que incorpora el código de todas las funciones de las librerías. El enlace estático es el que normalmente se utiliza a menos que indiquemos otra cosa.
    • Enlace dinámico. El código de las librerías no se une al del programa, sino que se busca durante la ejecución, únicamente cuando es requerido. El enlace dinámico produce, por lo tanto, ejecuciones más lentas, ya que cada vez que se use una función de librería dinámica es necesario buscar el archivo en el que se encuentra y ejecutar su código. Además, pueden producirse errores de enlace durante la ejecución del programa. Sin embargo, el enlace dinámico tiene las ventajas de reducir el tamaño del archivo ejecutable y permitir la compartición de librerías entre diferentes aplicaciones.
 7.4  Depuración
La depuración del programa consiste en localizar y corregir los errores que se hayan podido producir durante el desarrollo. El objetivo es conseguir un programa que funcione lo más correctamente posible, aunque hay que tener presente que ningún programa complejo está libre de errores al 100%
Los errores pueden ser de tres tipos:
    • Errores en tiempo de compilación. Se producen al traducir el código fuente a código objeto. El compilador los detecta y marca en qué línea se han producido, y de qué tipo son, por lo que son relativamente fáciles de corregir. Los errores de compilación más frecuentes son:
    • Errores sintácticos: escribir mal alguna instrucción o algún identificador, u olvidarnos del punto y coma que debe terminar cada instrucción.
    • Errores de tipos: intentar asignar a una variable de cierto tipo un valor de otro tipo incompatible, o invocar a una función con argumentos de tipo equivocado. Recuerda que C puede hacer conversiones de tipo automáticas, por lo que estos errores pueden quedar enmascarados.
    • Errores de identificadores no reconocidos: ocurren cuando se intenta utilizar una variable o una constante que no ha sido declarada, o cuyo ámbito no llega al lugar donde se intenta utilizar.
    • Avisos. Además de los errores, el compilador puede dar avisos (warnings) en lugares donde potencialmente puede existir un error de compilación. Es conveniente revisar todos los avisos y tratar de corregirlos antes de continuar con la ejecución.
    • Errores en tiempo de enlace. Cuando el compilador termina la traducción se produce el enlace de todos los archivos objeto. En este momento se resuelven todas las llamadas a funciones, de modo que si alguna función no está presente en el conjunto de archivos objeto, el enlazador fallará y explicará la causa del error.
    • Errores en tiempo de ejecución. Si la compilación y el enlace terminan sin novedad, se genera un archivo ejecutable (con extensión .EXE en sistemas Windows). Es el momento de comprobar que el programa realmente hace lo que se espera que haga. Para ello hay que probarlo con diversos conjuntos de datos de entrada; la elaboración de estos juegos de pruebas es una técnica que excede nuestras pretensiones.
Los errores que surgen en tiempo de ejecución son los más complicados de corregir, ya que muchas veces no está clara la causa del error. En el peor de los casos, puede ser necesario rediseñar la aplicación por completo.
Simplificando mucho, podemos encontrarnos con estos errores en tiempo de ejecución:
    • Errores lógicos. Se producen cuando alguna condición lógica está mal planteada. Entonces, el flujo del programa puede ir por la rama "si_no" cuando debería ir por la rama "si", o puede salirse de un bucle cuando debería repetir una vez más, o entrar en un bucle infinito, etc.
    • Errores aritméticos. Ocurren cuando una variable se desborda (overflow), o se intenta una operación de división entre cero, o alguna operación aritmética está mal planteada.
    • Errores de punteros. Los punteros son herramientas muy potentes que permiten la manipulación dinámica de la memoria, pero también conllevan grandes riesgos porque un puntero "descontrolado" puede hacer auténticas locuras en la memoria del ordenador, hasta el punto de colgar sistemas poco fiables (Windows 9x)
    • Errores de conversión automática de tipos. Se producen cuando C realiza una conversión automática que no teníamos prevista. Entonces el dato puede cambiar y dar al traste con la lógica del programa.
    • Errores de diseño. Ocurren cuando el programa no está bien diseñado y realiza tareas diferentes de las que se pretendían. Son los peores errores, porque obligarán a modificar una parte (o la totalidad) del trabajo realizado, debiendo, en ocasiones, volver a las primeras fases del ciclo de vida para repetir todo el proceso.
Estos y otros errores en tiempo de ejecución pueden manifestarse con distintas frecuencias:
    • Siempre que se ejecuta el programa: son los más fáciles de localizar y corregir.
    • Solo cuando se introducen determinados datos de entrada: puede ser complicado dar con la secuencia de datos de entrada que provocan el error, pero una vez que la encontramos, puede localizarse con facilidad.
    • Al azar: algunas veces, los programas fallan sin motivo aparente, cuando han estado funcionando en el pasado con el mismo conjunto de datos. Son los errores más difíciles de localizar, porque ni siquiera se sabe bajo qué circunstancias ocurren.
El depurador
El depurador es un programa independiente del editor, el compilador y el enlazador. La mayoría de los compiladores disponen de uno y, además, suele estar integrado con los otros tres, de modo que desde el editor se puede lanzar cualquiera de los otros. 
El depurador es una herramienta fundamental para localizar y corregir errores en tiempo de ejecución. Para que la depuración sea cómoda, hay que activar una opción específica del compilador que permita hacer la depuración sobre el código fuente. Si no se activa, la depuración se hará sobre el código binario o, como mínimo, será imposible acceder a los identificadores de variables, lo cual complica mucho la depuración. Muchos compiladores tienen esta opción activada por defecto. 
Cada depurador tiene sus propias opciones y características, pero todos suelen coincidir en varios aspectos:
    • Permiten ejecutar paso a paso cada instrucción del programa, deteniéndose antes de ejecutar la siguiente para permitirnos ver el estado de las variables o de los dispositivos de E/S.
    • Permiten ver y manipular el contenido de las variables en cualquier punto del programa.
    • Permiten ver y manipular la estructura de la memoria asignada al programa y de los registros del microprocesador.
    • Permiten insertar puntos de ruptura (breakpoints), es decir, puntos donde la ejecución se detendrá momentáneamente para que hagamos alguna comprobación de las anteriormente expuestas.
Haciendo correcto uso de estas posibilidades, podemos localizar rápidamente cualquier error en tiempo de ejecución y afrontar la tarea de corregirlo.
Si quieres ver ejemplos concretos de depuradores para Windows y para Linux, puedes consultar los apéndices del libro en este momento.
