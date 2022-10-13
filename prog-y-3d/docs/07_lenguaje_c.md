---
layout: page
title: 9. El lenguaje C\/C++
permalink: /lenguaje-c/
nav_order: 9
has_children: true
parent: Introd. a la prog. y al diseño 3D
---

# 9. El lenguaje C/C++
{: .no_toc }

- TOC
{:toc}

El ordenador, como ya sabrás a estas alturas, solo puede manejar ceros y unos, es decir, código o **lenguaje binario**. Los seres humanos, por el contrario, utilizamos un lenguaje mucho más complejo, con montones de símbolos y reglas sintácticas y semánticas, que denominamos **lenguaje natural** (aunque de "natural" tiene poco).

Entre estos dos extremos (lenguaje binario y lenguaje natural) se encuentran los **lenguajes de programación**. Tienen cierto parecido con el lenguaje natural, pero son mucho más reducidos y estrictos en su sintaxis y semántica, para acercarse a las limitaciones del lenguaje binario.

En este capítulo vamos a aprender a escribir algoritmos con un lenguaje llamado **C** y, más adelante, con una variante de C llamada **C++**. Se trata, en realidad, de dos lenguajes de programación distintos, si bien C++ es un superconjunto de C, es decir, todo el lenguaje C está incluido en C++ y, además, tiene algunas cosas adicionales.

Se trata de dos lenguajes muy veteranos pero que siguen gozando de una gran popularidad en el mundo profesional de la programación, sobre todo de la programación de sistemas u otros programas que requieran gran velocidad de procesamiento, como los motores de videojuegos.

Lenguajes de programación hay muchos, así que también hablaremos de otros lenguajes y conoceremos los tipos y características de algunos de ellos.

## 9.1. Orientándose en la jungla de los lenguajes de programación

Los lenguajes de programación constituyen un ecosistema muy extenso y en constante evolución. Para orientarse un poco en esa jungla, nada mejor que clasificar los lenguajes igual que los biólogos clasifican a las criaturas vivas.

### 9.1.1. Tipos de lenguaje según el nivel de abstracción: alto y bajo nivel

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

### 9.1.2. Tipos de lenguaje según su generación

Los lenguajes de programación también se clasifican según la generación a la que pertenecen.

El lenguaje máquina fue el lenguaje de primera generación. Los ensambladores fueron los lenguajes de segunda generación. A partir de ahí, surgió una explosión de lenguajes diferentes que podemos clasificar como:

* **Lenguajes de tercera generación** (o **imperativos**), en los que el programador escribe una secuencia de instrucciones que el ordenador debe ejecutar en un orden preestablecido. Son los lenguajes más "clásicos": C, Basic, Cobol, Fortran, Pascal, etc.
* **Lenguajes de cuarta generación** (o **4GL**), dirigidos a facilitar la creación de interfaces con el usuario y con otras aplicaciones, como las bases de datos. Un ejemplo de estos lenguajes es SQL, universalmente utilizado para manipular bases de datos y omnipresente en muchas aplicaciones web actuales.
* **Lenguajes orientados a objetos**, que son una evolucuión de los lenguajes de tercera generación y que permiten construir con mayor facilidad y robustez programas modulares complejos. Ejemplos de lenguajes orientados a objetos son C++, C#, Java, Javascript, Python, PHP o Ruby. Algunos de ellos son multiparadigma, es decir, permiten programar con orientación a objetos pero también permiten hacer programación estructurada clásica, sin objetos.
* **Lenguajes declarativos** y **lenguajes funcionales**, propios de la inteligencia artificial, como Prolog o Lisp.
* **Otros** tipos aún más específicos: lenguajes concurrentes, paralelos, distribuidos, etc.

En general, podemos decir que un programador acostumbrado a trabajar con un lenguaje de tercera generación puede aprender con poco esfuerzo cualquier otro lenguaje de tercera generación y, con algo más de trabajo, un lenguaje orientado a objetos. Sin embargo, el "salto" a otros tipos de lenguajes, como los declarativos, cuesta más porque las fundamentos de estos lenguajes son muy diferentes.

### 9.1.3. Tipos de lenguaje según su forma de traducción 
 
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

### 9.1.4. Tipos de lenguaje según su tipado

Por *tipado* nos referimos a la forma en la que los lenguajes de programación usan los tipos de datos. Ya sabes: entero, carácter, lógico, etc. Es decir, las categorías a las que puede pertenecer una variable.

Pues bien, según su tipado, los lenguajes pueden ser:

* **De tipado fuerte**: los tipos de datos no pueden mezclarse. Por ejemplo, no puedes sumar un entero y un real, porque son números de distinto tipo. Y mucho menos sumar un entero con un carácter.
* **De tipado débil**: los tipos de datos pueden mezclarse y el lenguaje hace las conversiones de tipos implícitas que le parezca oportunas. Así, en estos lenguajes podrías sumar un entero con un real, o incluso un entero con un carácter. ¿Que cuál sería el resultado? Buena pregunta. Tendrás que probarlo, porque eso depende de las conversiones de tipo que haga el lenguaje.
* **De tipado estático**: los tipos de datos se asignan al escribir el código y no pueden cambiarse durante la ejecución. Esto es típico de los compiladores (aunque no de todos).
* **De tipado dinámico**: los tipos de datos pueden cambiarse alegremente durante la ejecución. Esto es típico de los intérpretes.

Las dos primeras categorías y las dos segundas no son excluyentes. Por ejemplo, pueden existir lenguajes de tipado débil y dinámico, o bien fuerte y estático. Las otras combinaciones (fuerte y dinámico, débil y estático) pueden darse pero son menos habituales. 

### 9.1.5. El *top ten* de los lenguajes de programación

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

## 9.2. ¡Bienvenidos a C!

### 9.2.1.  Características básicas de C

* C es un lenguaje de **alto nivel**, aunque a veces se le considera de **nivel intermedio**, porque permite manipular detalles del hardware que para otros lenguajes resultan innacesibles.
* Es **imperativo y estructurado**. Admite **orientación a objetos** (aunque entonces se llama C++).
* Su **tipado es estático y débil**. Eso significa que hay que indicar el tipo de datos de las variables antes de usarlas y que se pueden hacer mezclas de tipos.
* La **sintaxis** de sus estructuras de control se parece a las de Java, Javascript, PHP o Python, porque todos estos lenguajes son herederos naturales de C.
* Es un **lenguaje compilado**, pensado para producir código máquina rápido y eficiente. Si quieres velocidad de ejecución, C es tu lenguaje.
* Es **altamente portable** (para ser un lenguaje compilado). Existen compiladores de C para todos los sistemas y arquitecturas. Si respetas el estándar de C, no tendrás dificultad para migrar las aplicaciones a cualquier sistema.
* Es un lenguaje de programación **muy  popular** y **muy veterano**. Aunque se ha intentado reemplazar muchas veces, ningún lenguaje lo ha conseguido y tiene una base de programadores muy fieles.

### 9.2.2. Breve historia de C

A principios de la década de 1970, los laboratorios Bell necesitaban un nuevo sistema operativo. Hasta ese momento, la mayoría de los sistemas operativos estaban escritos en lenguaje ensamblador (muy parecido al lenguaje máquina) para que el resultado fuera un programa lo suficientemente rápido. 

Pero los programas escritos en ensamblador son difíciles de mantener y Bell quería que su nuevo sistema operativo se pudiera mantener y modificar con facilidad. Por lo tanto, se decidieron a inventar un lenguaje nuevo con el que programar su sistema operativo.

Tras varios intentos, Brian Kerningham y Dennis Ritchie, dos ingenieros de laboratorios Bell, terminaron de diseñar el lenguaje C en un ordenador DEC PDP-11 y, con él, desarrollaron el sistema operativo Unix. 

El tándem C - Unix ha sido una referencia fundamental en el mundo de la programación en el último medio siglo, y C se ha convertido en uno de los lenguajes de programación más populares y longevos de la historia de la informática. C creció en popularidad muy rápidamente y sigue siendo uno de los lenguajes fundamentales tanto en el mundo educativo como en el mundo profesional.

El primer estándar de C (ANSI C) no apareció hasta 1990, por lo que es posible encontrar diferentes dialectos de C ligeramente incompatibles entre sí.

XXX

Una evolución de C fue el lenguaje C++ que, a parte de todas las características del ANSI C, incluye la posibilidad de orientación a objetos, una técnica de programación ligeramente diferente de la programación estructurada. Algo más tarde, en el año 2000, Microsoft patentó el lenguaje C#, otra evolución de C++ orientada al desarrollo de aplicaciones en red para la plataforma .NET de esta compañía.

Otros lenguajes han sido diseñados para permitir que los no programadores puedan leer y comprender los programas y, presumiblemente, aprender a escribir los suyos propios para resolver problemas sencillos. Por el contrario, C fue creado, influenciado y probado en vivo por programadores profesionales. El resultado es que C da al programador lo que muchos programadores piden: unas pocas y bien escogidas palabras clave, una biblioteca poderosa y estandarizada, unas mínimas restricciones y un máximo control sobre lo que sucede en el interior de la máquina.

Si a esto unimos que el código objeto generado por C es casi tan eficiente como el ensamblador, se entenderá por qué lleva medio siglo siendo uno de los lenguajes más populares entre los programadores profesionales.

Ahora bien, C también tiene sus detractores que lo acusan de ser confuso, críptico y demasiado flexible. En efecto, con C se pueden desarrollar las técnicas de programación estructurada, pero también se puede programar "código espagueti". Esto, sin embargo, ocurre con todos los lenguajes: incluso los que tienen una sintaxis más estilizada y elegante, como Python o Ruby, pueden generar código absolutamente ininteligible en manos de un programador manazas.

### 9.2.3. Sintaxis básica de C

En este apartado vamos a aprender cómo se escriben en C las estructuras de control y el resto de instrucciones básicas.
 
#### Generalidades sintácticas

Hay algunas normas básicas de la sintaxis de C que tienes que conocer:

* **Los bloques de código se marcan con las llaves** ( **{** y **}** ). Por ejemplo, después de una sentencia *while* (equivalente al *mientras* de pseudocódigo) hay que abrir una llave. El cuerpo de bucle comprenderá desde esa llave de apertura hasta la siguiente llave de cierre, así:

   ```c
   while (condicion) {
      Instrucción 1 del bucle
      Instrucción 2 del bulce
      ...
      Instrucción N del bucle
   }
   ```

   La llave de cierre, por tanto, sería el equivalente al *FinMientras* de pseudocódigo.

* Todas las instrucciones **terminan con un punto y coma** ( **;** ). Excepción: si una instrucción contiene un bloque marcado con llaves ( { ... } ), se considera que esa instrucción termina al cerrar el bloque, y en ese caso no hace falta poner punto y coma.

   ```c
   a = 10;                     /* La instrucción de asignación termina con ; */
   while (condicion) {
      /* Cuerpo del bucle */
   }                           /* El bucle termina con }, así que no necesita ; */
   ```

* Los **identificadores** de variables, funciones, etc., no pueden empezar con un número ni contener espacios o símbolos especiales, salvo el de subrayado ( _ )

   ```c
   a5 = 1;     /* Identificador de variable válido */
   5a = 1;     /* Identificador de variable NO válido */
   ```

* Las **cadenas de caracteres** deben encerrarse entre **comillas dobles** ( "..." ). Los **caracteres** individuales se encierran entre **comillas simples**.

   ```c
   "Soy una cadena";   /* Cadena de caracteres */
   'C';                /* Carácter individual */
   ```

* El lenguaje es **sensitivo a las mayúsculas**. Es decir, no es lo mismo que una variable se llame *edad* que *Edad* o *EDAD*.

#### Tipos de datos simples

C utiliza varios tipos de datos **simples** porque solo pueden contener un valor en cada momento (como en pseudocódigo). Los más importantes son: 

* **int**: números enteros. Admite modificadores como **long** (para enteros largos) o **short** (para enteros cortos). Por ejemplo, el tipo *int* permite usar números entre –32768 a 32767, mientras que el tipo *long int* admite números entre –2147483648 a 2147483647.
* **float**: número reales. El tipo **double** se usa para lo mismo, pero tiene más precisión y admite números mayores.
* **char**: caracteres.
* **void**: vacío. Se usa en funciones que no devuelven nada o que tienen una lista de parámetros vacía.

Observa que en C no existe el tipo de dato **lógico o booleano**. Se utiliza en su lugar el tipo *int*, representando el 0 el valor falso y cualquier otra cantidad (normalmente 1) el valor verdadero.

#### Declaración de variables

Todas las variables tienen que **declararse** antes de su primer uso. Esto se hace así: 

```c
int a;   /* Declaración de la variable a, de tipo entero */
char b;  /* Declaración de la variable b, de tipo carácter */
a = 10;  /* Uso de la variable a */
b = 'z'; /* Uso de la variable b */
```

Observa que, al declarar una variable, hay que especificar su tipo.

Todas las variables son **locales** a la función o bloque de código donde estén definidas, salvo que se indique otra cosa, dejando de existir al finalizar el bloque actual. Aunque pueden crearse variables globales, su uso está tan desaconsejado que ni siquiera te voy a explicar cómo se hace.

### 9.2.4. Conversiones de tipo

C es un lenguaje **débilmente tipado**, es decir, no hace comprobaciones estrictas de tipos a la hora de asignar un valor a una variable o de comparar dos expresiones.

Por ejemplo, estas instrucciones son correctas:

```c
float a;
int b;
b = 5;
a = b;
```

¡Hemos asignado un valor entero a la variable *a*, que es de tipo *float*! 

En otros lenguajes esto no está permitido, pero en C se realizan conversiones automáticas de tipo cuando en una misma expresión aparecen datos de tipos diferentes. Esto, que en principio es una ventaja, pues elimina algunas limitaciones engorrosas, otras veces es peligroso porque algunos datos pueden cambiar extrañamente de valor al hacerse esa conversión automática.

La conversión puede ser de dos clases:

* **Asignación de un valor a una variable que permita más precisión**. Por ejemplo, asignar un número entero a una variable *float*. En este caso, el número se convierte a real añadiendo ".0" a la parte decimal. No hay pérdida de información.

* **Asignación de un valor a una variable que permita menos precisión**. Por ejemplo, asignar un número *long int* a una variable de tipo *int*. En este caso, el número se recorta, perdiendo sus bits más significativos, es decir, los dígitos binarios que estén más a la izquierda. Por lo tanto, hay pérdida de información. Hay que tener mucho cuidado con este tipo de conversiones.

Además de las conversiones automáticas de tipo, el programador puede **forzar la conversión de tipos** a voluntad utilizando **moldes**. 

Un molde es una expresión de un tipo de datos entre paréntesis que aparece delante de un dato. Entonces, antes de evaluar la expresión, el dato es convertido al tipo especificado en el molde. Por ejemplo:

```c
float a;
int b;
a = 5;
b = (float)a/2;
```

Sin el molde ```(float)```, la división ```a/2``` sería entera, ya que a es una variable de tipo *int*, y se perdería la parte decimal. Al aplicar el molde, se convierte momentáneamente el valor entero 5 al valor real 5.0 y se evalúa la expresión, que ahora sí se realiza como división real, conservando sus decimales.

### 9.2.5. Asignación

La **asignación** de valores a variables en C es fácil de explicar: se hace con el **símbolo igual (=)**, no con el símbolo <= que usábamos en pseudocódigo:

```c
int a;      /* Declaración de la variable a */
int b = 1;  /* Declaración y asignación de valor a la variable b */
a = b + 5;  /* Asignación de valor a la variable a */
```

Observa cómo, en la segunda instrucción, hemos declarado y asignado valor a una variable en la misma línea.

### 9.2.6. Operadores y expresiones

Los **operadores y expresiones en C** son iguales que los que hemos empleado en pseudocódigo:

* Operadores **aritméticos**: +, -, \*, /, % (este último significa *módulo de la división*).
* Operadores **relacionales**: >, <, >=, <=...

Sin embargo, hay algunas **diferencias** importantes entre el pseudocódigo de PseInt y C. Son estas:

* La **asignación**, como ya hemos visto más arriba, se hace con el **símbolo igual (=)**, no con <=.
   
   ```c
   a = 5;        /* A la variable a se le asigna el valor 5 */
   b = a + 1;    /* A la variable b se le asigna el valor a + 1 */
   ```

* La **comparación de igualdad** se hace con un **doble igual (==)**, no con un solo igual (=). Esto es así para distinguir la comparación de la asignación.
   
   ```c
   if (a == 5) {    /* Comparación: ¿es a igual a 5? */
       b = a + 1;   /* Asignación: b toma el valor a + 1 */
   }
   ```
   
* Existe el **operador incremento (++)**. Se utiliza para sumar una unidad a una variable.
   
   ```c
   while (i < 10) {
       i++;         /* Esto es equivalente a: i = i + 1 */
   }
   ```
   
* También existe el **operador decremento (- -)**, para restar una unidad a una variable.
   
   ```c
   while (i > 0) {
       i--;     /* Equivalente a: i = i - 1 */
   }
   ```
   
* Los **operadores lógicos** (Y, O, NO) se escriben de forma distinta:
   * **Y** se escribe **&&**. 
   * **O** se escribe **\|\|**. 
   * **NO** se escribe **!** (sí, sí, es una admiración).
   
   ```c
   if (a > 0) && (b > 0) {   /* Operador Y: tienen que darse las dos condiciones a la vez */
       ...
   }
   ```
   
Hay algunas otras diferencias, desde luego, pero con esto ya tienes para hacer un buen montón de programas.

### 9.2.7. Estructuras de control

Las **estructuras de control** en C son muy similares a las que hemos utilizado en pseudocódigo, cambiando ligeramente la notación empleada. 

XXX

A continuación te muestro una tabla con las más habituales y su equivalente en pseudocódigo, sin entrar en explicaciones, porque supondremos que ya sabes manejarlas. Si no recuerdas para qué servía alguna de ellas, quizá sería buena idea que le dieras un repaso al capítulo dedicado al pseudocódigo.

<table>
    <tr>
      <th>Instrucción</th>
      <th>Pseudocódigo</th>
      <th>Javascript</th>
    </tr>
    <tr>
      <td>Condicional simple</td>
      <td>
         <code>
         Si condición entonces<br>
         &nbsp;&nbsp;&nbsp;acciones<br>
         FinSi
         </code>
      </td>
      <td>
         <code>
         if (condicion) {<br>
         &nbsp;&nbsp;&nbsp;acciones<br>
         }
         </code>
      </td>
    </tr>
    <tr>
      <td>Condicional doble</td>
      <td>
         <code>
         Si condicion entonces<br>
         &nbsp;&nbsp;&nbsp;acciones<br>
         SiNo<br>
         &nbsp;&nbsp;&nbsp;acciones<br>
         FinSi
         </code>
      </td>
      <td>
         <code>
         if (condicion) {<br>
         &nbsp;&nbsp;&nbsp;acciones<br>
         }<br>
         else {<br>
         &nbsp;&nbsp;&nbsp;acciones<br>
         }
         </code>
      </td>
    </tr>
    <tr>
      <td>Bucle tipo mientras</td>
      <td>
         <code>
         Mientras condicion hacer<br>
         &nbsp;&nbsp;&nbsp;acciones<br>
         FinMientras
         </code>
      </td>
      <td>
         <code>
         while (condicion) {<br>
         &nbsp;&nbsp;&nbsp;acciones<br>
         }
         </code>
      </td>
    </tr>
    <tr>
      <td>Bucle tipo repetir</td>
      <td>
         <code>
         Repetir<br>
         &nbsp;&nbsp;&nbsp;acciones<br>
         Hasta Que condicion
         </code>
      </td>
      <td>
         <code>
         do {<br>
         &nbsp;&nbsp;&nbsp;acciones<br>
         } while (condicion)
         </code>
      </td>
    </tr>
    <tr>
      <td>Bucle tipo para</td>
      <td>
         <code>
         Para variable <- valor_inicial hasta valor_final con paso incremento hacer<br>
         &nbsp;&nbsp;&nbsp;acciones<br>
         FinPara
         </code>
      </td>
      <td>
         <code>
         for (variable = valor_inicial; variable != valor_final; variable = variable + incremento) {<br>
         &nbsp;&nbsp;&nbsp;acciones<br>
         }
         </code>
      </td>
    </tr>
</table>

Fíjate en que casi todo se escribe del mismo modo que en pseudocódigo con un par de diferencias notables:

* **DIFERENCIA 1: En el bucle tipo *repetir***, la condición de salida se expresa al revés ("repetir mientras.." en lugar de "repetir hasta que...". Lo verás mejor en este ejemplo que muestra los números del 1 al 100. Observa la condición del final del bucle:

   En pseudocódigo:
   ```
   i <- 1
   Repetir
      Escribir i
      i <- i + 1
   Hasta que i >= 100
   ```

   En Javascript:
   ```javascript
   i = 1;
   do {
      document.write(i);
      i++;
   }
   while (i < 100);
   ```

* **DIFERENCIA 2: En el bucle tipo *para*** hay que indicar la asignación a la variable que controla el bucle, la condición de salida y la forma en la que esa variable cambiará en cada iteración. Observa este ejemplo:

   En pseudocódigo:
   ```
   Para i <- 1 hasta 10 hacer
      Escribir i
   FinPara
   ```

   En Javascript:
   ```javascript
   for (i = 1; i <= 10; i = i + 1)
      document.write(i);
   }
   ```

   Si el **paso** del bucle no es +1 (es decir, si la variable que controla el bucle no incrementa su valor de 1 en 1 en cada iteración), hay que indicarlo de este modo:

   En pseudocódigo:
   ```
   Para i <- 1 hasta 10 con paso 2 hacer
      Escribir i
   FinPara
   ```

   En Javascript:
   ```javascript
   for (i = 1; i <= 10; i = i + 2)
      document.write(i);
   }
   ```

   Por último, recuerda que en Javascript existe una abreviatura para ```i = i + 1```, que se escribe ```i++```, por lo que lo más habitual es encontrar los bucles de tipo *para* escritos así:

   ```javascript
   for (i = 1; i <=10; i++)
      document.write(i);
   }
   ```   

### 9.2.8. Algoritmo principal y Subalgoritmos

XXX hablar aquí de main()

#### Las funciones de Javascript

Javascript es un lenguaje **modular**, es decir, permite la escritura de subalgoritmos.

Todos los subalgoritmos en Javascript se llaman **funciones**, independientemente de si devuelven algo o no.

Esta es la forma de declarar una función:

```javascript
function nombre_funcion(parámetros) {
   Instrucciones de la función;
   return expresión;
}
```

El **return** es optativo. Una función de Javascript puede no tener **return** y, por lo tanto, ser en la práctica un procedimiento (aunque se siga declarando con la palabra *function*).

Los **parámetros** también son optativos, claro: puede haber funciones sin ningún parámetro y funciones con decenas de ellos (aunque esto último no sea demasiado recomendable).

La **invocación** de la función se hace como en pseudocódigo: poniendo el nombre de la función y su lista de parámetros (si los tiene).

Por ejemplo:

```javascript
// Definición de la función
function potencia(base, exponente) {
   var i;
   var resultado = 1;
   for (i = 1; i <= exponente; i++) {
      resultado = resultado * base;
   }
   return resultado;
}

// Invocación de la función
var b = 9;
var e = 4;
var p = potencia(9, 4);
document.write("9 elevado a 4 es " + p);
```
#### Paso de parámetros: ¿por valor o por referencia?

Recuerda que, cuando se invoca un subalgoritmo, hay dos modos de enviarle los parámetros y que es muy importante distinguirlos.

Observa el ejemplo anterior de la función *potencia()*. Los **parámetros formales** son *base* y *exponente*. Los **parámetros actuales** son *b* y *e*.

* **Paso de parámetros por valor**: el *valor* de los parámetros actuales (*b* y *e*) se asigna a los parámetros formales del subalgoritmo. Así, *base* y *exponente* adquieren los mismos valores que tenían *b* y *e*, pero ahí termina toda su relación: a partir de entonces, se comportan como variables independientes de *base* y *exponente*.
* **Paso de parámetros por referencia**: los parámetros actuales (*b* y *e*) quedan *ligados* a los parámetros formales (*base* y *exponente*). Si el valor de *base* o de *exponente* cambia dentro de la función, también cambiarán *b* y *e* fuera de la función, porque en realidad son las mismas variables.

Pues bien, en Javascript:

* el paso de parámetros de **tipos primitivos** (ya sabes, *number*, *string*, *boolean*, etc) **siempre se hace por valor**.
* el paso de parámetros de **tipos complejos** (llamados *objetos*), **siempre se hace por referencia**.

¿Que qué son los famosos *objetos*, preguntas? Tal vez hayas oído hablar de la *programación orientada a objetos*. Le dedicaremos a ese tema un capítulo más adelante, pero, de momento, quédate con la idea de que un objeto es *cualquier variable que no sea de un tipo primitivo*. Por ejemplo, los **arrays** son objetos en Javascript.

Así que la conclusión es que **los arrays siempre se pasan por referencia** en Javascript, mientras que **las variables simples siempre se pasan por valor**.

### 9.2.9. Entrada y salida

Hay varias formas de hacer la entrada y salida de datos con Javascript, es decir, hay varios equivalentes a la instrucciones **Leer** y **Escribir** de pseudocódigo.

Para nuestros primeros programas, usaremos la función **prompt()** para hacer la entrada y la propiedad **innerHTML** para hacer la salida. A veces, sustituiremos esta última por la función **document.write()** o por la función **alert()**.

<table>
    <tr>
      <th>Instrucción</th>
      <th>Pseudocódigo</th>
      <th>Javascript</th>
    </tr>
    <tr>
      <td>Entrada</td>
      <td>
         <code>
         Leer variable
         </code>
      </td>
      <td>
         <code>
         variable = prompt();
         </code>
      </td>
    </tr>
    <tr>
      <td>Salida</td>
      <td>
         <code>
         Escribir expresión
         </code>
      </td>
      <td>
         <code>document.getElementById('selector').innerHTML = expresión;</code>
         <br>O bien:<br>
         <code>document.write(expresión);</code>
         <br>O bien:<br>
         <code>alert(expresión);</code>
      </td>
    </tr>
</table>

Vamos a ver un poco más despacio cómo se usa cada una de estas funciones:

#### Entrada de datos con prompt()

La **entrada de datos** en Javascript puede hacerse de diversas maneras. En particular, usando **formularios HTML**, pero de momento no vamos a pelearnos con eso.

En esta primera toma de contacto con el lenguaje, vamos a conformarnos con la función **prompt()**. Esta función muestra un mensaje en forma de ventana emergente y permite escribir un texto, asignándolo a una variable.

Observa cómo se usa *prompt()* con este ejemplo escrito primero en pseudocódigo y luego en Javascript:

Pseudocódigo:
```
Escribir("Dime un número")
Leer n
```

Javascript:
```javascript
document.write("Dime un número");
n = prompt();
```

Si pruebas este código, verás que sucede algo raro: el mensaje "Dime un número" sale escrito en la ventana del navegador web, pero el número nos lo pide en una ventana emergente que se sitúa *por encima* del mensaje. ¡Y, en algunos navegadores, el mensaje "Dime un número" ni siquiera llega a verse!

![Prompt sin texto](/docs/prog-y-3d/_site/assets/images/05-prompt-sin-texto.png)

Esto hace un efecto muy raro. ¿verdad? Para evitarlo, puedes **unir las dos instrucciones** en una sola, puesto que *prompt()* te permite incluir un mensaje en la caja de texto. Así:

```javascript
n = prompt("Dime un número");
```

Al ejecutar este código, verás que el resultado es mucho más natural:

![Prompt con texto](/docs/prog-y-3d/_site/assets/images/05-prompt-con-texto.png)

(Nota: la forma exacta en la que veas estas pantallas dependerá de tu navegador web, puesto que cada uno hace el *prompt* de manera ligeramente distinta)

#### Salida de datos con innerHTML, document.write() y alert()

La forma más sencilla de hacer la salida de datos con Javascript es usar **document.write()** o su hermana melliza, **document.writeln()**.

Mira cómo se usa en este ejemplo y el resultado que produce en la ventana del navegador:

Código:
```javascript
<script>
document.write("Hola, mundo");
</script>
```

Resultado:
![Salida de datos con document.write()](/docs/prog-y-3d/_site/assets/images/05-salida-de-datos-con-document-write.png)

La diferencia entre *write()* y *writeln()* es que la segunda insertará automáticamente un salto de línea tras la salida, y la primera no.

Sin embargo, estas funciones tiene un grave problema: puede que el texto de salida *no se muestre inmediatamente*. La decisión de cuándo se muestra la salida la toma el navegador y hay poco que puedas hacer al respecto. Por eso, la usaremos en contadas ocasiones.

Otra manera muy sencilla de hacer salida de datos es con **alert()**. Esta función muestra un texto en forma de ventana emergente. Parecido a *prompt()*, pero sin caja de texto para escribir. Observa a *alert()* en acción en el siguiente ejemplo:

Código:
```javascript
<script>
alert("Hola, mundo");
</script>
```

Resultado:
![Salida de datos con alert()](/docs/prog-y-3d/_site/assets/images/05-salida-de-datos-con-alert.png)

La salida con *alert()* es simple y efectiva, pero resulta muy invasiva. Si haces todo tu programa con *alert()*, el usuario se sentirá enseguida apabullado por esa cantidad de ventanas emergentes que le saltan a la cara.

De modo que nos queda la tercera vía. Es la más enrevesada, pero también la mejor. Y, en fin, tampoco es tan complicado.

Consiste en preparar una zona de la pantalla del navegador para hacer en ella la salida de datos, y luego acceder a la misma con **document.getElementById().innerHTML**.

Si sabes un poco de **HTML**, el lenguaje de marcado con el que se codifican las páginas web, enseguida comprenderás lo que estamos haciendo. Si no tienes ni idea de HTML, no te preocupes. Basta con que sigas los pasos que proponemos aquí para que puedas ejecutar tus programas Javascript. Ya tendrás tiempo de aprender HTML más adelante.

**Paso 1. Prepara la caja donde se hará la salida**. La caja se crea un la etiqueta **<div>** de HTML, a la que puedes asignar un estilo de visualización. La primeras veces, puedes limitarte copiar y pegar este código en todos los programas Javascript que vayas a hacer:

```html
<div id='salida' style='text-align: center; border-style: solid; border-color: black'></div>
<script>
   // Escribe aquí tu programa Javascript
</script>
```

**Paso 2. Dentro de tu programa Javascript, utiliza *document.getElementById('salida').innerHTML = expresión* para hacer la salida**. Sí, lo sé, es un poco largo, pero Javascript es así. Por ejemplo, este código:

```html
<div id='salida' style='text-align: center; border-style: solid; border-color: black'></div>
<script>
   document.getElementById('salida').innerHTML = "Hola, mundo";
</script>
```

...producirá este resultado:

![Salida de datos con innerHTML](/docs/prog-y-3d/_site/assets/images/05-salida-de-datos-con-innerhtml.png)

**Paso 3. Utiliza *document.getElementById('salida').innerHTML += expresión* si no quieres perder la salida anterior**. Es decir, si usas un **igual** (=), cada salida de datos borrará la pantalla. Si usas **más igual** (+=), la salida de datos se añadirá a la anterior, sin borrarla:

```html
<div id='salida' style='text-align: center; border-style: solid; border-color: black'></div>
<script>
   document.getElementById('salida').innerHTML += "Hola, mundo";
</script>
```

**Paso 4 (OPTATIVO). Cambia las propiedades de tu caja de salida**. Intenta juguetear con las propiedades ***text-align***, ***border-style*** o ***border-color*** del *div* de salida. Además, hay muchas otras propiedades que puedes asignarle a esa caja. Si te atreves, investiga un poco cómo cambiar el color del texto o la tipografía.

### 9.2.10. Cadenas de caracteres

XXX

### 9.2.11. Arrays

Los **arrays en Javascript** son mucho más que simples arrays: se trata de elementos muy complejos y flexibles que se adaptan a multitud de soluciones.

Aquí solo vamos a ver una introducción a los mismos. Conforme vayas profundizando en tu conocimiento de Javascript, descubrirás cosas nuevas sobre estas asombrosas estructuras y les sacarás más y más partido.

#### Declaración de arrays

Los arrays en Javascript se pueden **declarar** de diversas formas:

```javascript
// Una forma de declarar un array:
var ciudades = ['Almería', 'Granada', 'Málaga'];
// Otra forma de declarar un array:
var ciudades = new Array('Almería', 'Granada', 'Málaga');
// Esta es otra forma:
var ciudades = new Array(3);
ciudades[0] = 'Almería';
ciudades[1] = 'Granada';
ciudades[2] = 'Málaga';
// Y otra forma más:
var ciudades = [];
ciudades[0] = 'Almería';
ciudades[1] = 'Granada';
ciudades[2] = 'Málaga';
```

Realmente, no todas estas formas son equivalentes, porque Javascript a veces tratará a la variable *ciudades* como un **Array** y a veces como un **objeto**. La diferencia entre una y otra cosa es tan sutil que, de momento, puedes desentenderte de ello. Si algún día te vuelves un experto en Javascript, ya entenderás esa diferencia.

Por ahora, quédate con la idea de que todas estas formas son válidas para declarar un array.

#### Características de los arrays en Javascript

Como puedes observar por los ejemplos anteriores, los arrays de Javascript tienen dos características importantes:

* **No es necesario indicar su tamaño al declararlos**, aunque se puede hacer. Esto se debe a que los arrays en Javascript son dinámicos: pueden crecer o decrecer durante la ejecución del programa.
* **El índice empieza en 0**. Es decir, el primer elemento es el 0, el segundo es el 1, etc.
* El **acceso a los elementos** del array se hace como en pseudocódigo: indicando el índice del elemento entre corchetes.

Los arrays NO son variables primitivas (simples). Recuerda que esto significa que **siempre se pasan por referencia** a las funciones, mientras que las variables primitivas se pasan por valor. Repasa el paso de parámetros a funciones del que hablamos un poco más arriba si no recuerdas bien todo esto.

Una cosa muy peculiar de los arrays de Javascript es que **sus elementos pueden ser de diferente tipo**. Por ejemplo:

```javascript
// Este array tiene elementos del mismo tipo (strings):
var ciudades = ['Almería', 'Granada', 'Málaga'];
// Este array tiene elementos de diferente tipo:
var miArray = ['Lunes', 5, ciudades];
```

En el ejemplo anterior, el array *ciudades* solo contiene elementos de tipo *string*, mientras que el array *miArray* contiene elementos de tipo dispares: un *string*, un *number* y un *array*.

Como ves, nada impide que un elemento de un array sea otro array. De hecho, un elemento de un array puede ser cualquier cosa.

#### Propiedades y métodos

Los arrays de Javascript, como cualquier objeto, tienen una serie de **propiedades y métodos**. Ya veremos exactamente qué son las propiedades y los métodos, pero de momento te basta saber que se trata de funciones y variables que *están dentro* del objeto de tipo array y que permiten usarlo.

Algunas propiedades y métodos útiles de los arrays son:

* **nombreArray.length**: devuelve el número de elementos del array.
* **nombreArray.sort()**: ordena el array.
* **nombreArray.push(valor)**: añade un elemento al array (a continuación de la última posición usada). Como consecuencia, el tamaño del array crecerá.
* **nombreArray.pop()**: elimina el último elemento del array. Como consecuencia, el tamaño del array decrecerá.
* **nombreArray.indexOf(valor)**: busca el elemento *valor* en el array y devuelve su posición (si lo encuentra) o -1 (si no lo encuentra).

Hay muchas otras propiedades y métodos que puedes consultar en la [referencia oficial del lenguaje](https://developer.mozilla.org/en-US/docs/Learn/JavaScript/First_steps/Arrays).

#### Recorrido de un array

El **recorrido** de un array puede hacerse igual que en pseudocódigo, con la salvedad de que tendremos que averiguar la longitud del array antes de recorrerlo, puesto que el tamaño del array puede variar a lo largo del programa:

```javascript
var ciudades = ['Almería', 'Granada', 'Málaga'];
var longArray = ciudades.length;
for (i = 0; i < longArray; i++) {
   document.write(ciudades[i]);
}
```

Existen formas alternativas de hacer esto mismo sin necesidad de averiguar la longitud del array ni usar variables índice. Por ejemplo, así:

```javascript
var ciudades = ['Almería', 'Granada', 'Málaga'];
var ciudad;
for (ciudad of ciudades) {
   document.write(ciudad);
}
```

### 9.2.12. Funciones de la librería estándar

XXX

## 9.3. Escribiendo programas con Javascript

Ya conocemos cómo se manejan los principales componentes de un programa con Javascript: variables, instrucciones de control, asignaciones, funciones, etc.

Ahora nos queda saber cómo juntamos todo eso para escribir nuestros programas, ¿no te parece?

Por fortuna, en esto Javascript también se parece mucho a pseudocódigo. 

### 9.3.1. Caja de herramientas

¿Qué necesitamos para comenzar a escribir programas en Javascript? ¿Tendrás que instalar un montón de programas de desarrollo en tu ordenador?

La verdad es que no. Para desarrollar con Javascript basta con que tengas instalado:

* **Un editor de texto**. No te sirve Microsoft Word ni Libreoffice Writer. Tiene que ser un editor de texto *plano*, es decir, que no introduzca información de formato en el archivo. Solo el texto.

   Existen muchísimos editores de estas características, porque son programas muy simples y livianos. El **bloc de notas** de Windows es uno de ellos, aunque resulta poco recomendable porque no colorea el código fuente ni te ayuda a corregir errores.

   Un editor de texto para programación que ha tenido un crecimiento espectacular en los últimos años a nivel aficionado y profesional es **[Visual Studio Code](https://code.visualstudio.com/)**. Es multiplataforma (tiene versiones para Windows, Linux y Mac) y de código abierto. Y es una auténtica maravilla, así que te recomiendo que lo descargues (¡siempre de la web oficial, por favor!) y lo instales.

   Si trabajas con Linux, seguramente lo encuentres en los repositorios oficiales de tu distribución. Esa, por supuesto, también es una fuente confiable desde donde instalarlo.

* **Un navegador web**. Todos los navegadores web llevan en sus tripas un intérprete de Javascript, puesto que todas las páginas web actuales utilizan Javascript para funcionar. Puedes usar el navegador web que más te guste: Google Chrome, Mozilla Firefox, Microsoft Edge, el Safari de Apple, Opera, etc.

### 9.3.2. Flujo de trabajo

Lo habitual cuando estés escribiendo y depurando programas en Javascript es que **tengas abiertos a la vez** los dos programas:

* El editor de texto, para ir escribiendo y modificando tu código.
* El navegador web, para ir probando tu código.

El flujo de trabajo, al menos al principio, será este:

1. Comprender bien el problema que se pretende resolver.
2. Pensar un rato en el algoritmo que vas a escribir. Si es necesario, hacer un boceto en papel y/o en pseudocódigo.
3. Abrir el editor de texto y escribir una primera versión del programa. Si es muy largo, dividirlo en trozos más pequeños y escribir solo el primero de ellos.
4. Comprobar que el programa o fragmento de programa funciona en el navegador web. No pasar al siguiente fragmento hasta que este no funcione correctamente.
5. Repetir los pasos 3 y 4 hasta que el programa esté completo.

Ten en cuenta que, cuando los programas empiecen a volverse complejos, no podrás resolverlos de una sentada. Escribir un programa muy complejo puede llevarte días, semanas o meses.

### 9.3.3. Dónde y cómo escribir el código fuente

Los programas en Javascript pueden guardarse en dos tipos de archivo:

* **Archivos con extensión .js**. Estos archivos suelen contener bibliotecas de funciones Javascript usadas por otros programas. No se ejecutan directamente.
* **Archivos con extensión .html o .htm**. El navegador web los interpretará como páginas web y, por lo tanto, los ejecutará. *Aquí es donde colocaremos nuestro código*, al menos al principio.

Dentro del archivo .html, el código Javascript debe ir incrustado entre las etiquetas ```<script>``` y ```</script>```, que marcan el comienzo y el fin del programa:

```html
<script>
   Aquí va el código Javascript
</script>
```

Escribiremos el **algoritmo principal** de un programa en Javascript sin ninguna palabra especial que lo identifique como tal. Es decir, el código estará sin más en el archivo fuente, entre las etiquetas ```<script>``` y ```</script>```.

(Insisto: hay otras formas de hacer esto, pero, de momento, esta es más que suficiente para nosotros).

Los subalgoritmos sí que deben identificarse con la palabra **function** seguida del nombre del subalgoritmo, como hemos visto más arriba.

**El orden en el que escribas los algoritmos es indiferente**. En el archivo, puede aparecer primero el algoritmo principal y luego los subalgoritmos, o al revés. Utiliza el orden que te parezca más lógico y con el que te sientas cómodo.

## 9.4. Punteros y estructuras de datos

XXX

## 9.5. Un ejemplo completo: las tres en raya

Llegó la hora de poner manos a la obra.

Si hay una sección de este capítulo que tienes que leer con atención, es esta. Así que es un mal momento para tener prisa.

Vamos a escribir un **programa completo en Javascript**. Te puede servir de plantilla para desarrollar tus propios programas a partir de aquí.

El programa en cuestión será una versión del juego de **las tres en raya** que resolvimos en el tema de introducción a la programación. No dudes en repasar aquel ejercicio resuelto para ver el pseudocódigo, puesto que nuestro programa será una traducción literal de ese pseudocódigo a Javascript.

Aquí tienes el código fuente completo. Estúdialo con atención y asegúrate de entenderlo todo (o un gran porcentaje) antes de continuar. Ah, y no dejes de compararlo línea a línea con el mismo código en pseudocódigo.

### 9.5.1. El código fuente

```html
<div id='salida' style='text-align: center; border-style: solid; border-color: black; font-family: mono'></div>
<script>
//-------------------------
//   ALGORITMO PRINCIPAL
//-------------------------
var tablero = new Array(10);
var ganador;
var tablas;

inicializar(tablero)   // Esto es un subalgoritmo. Está escrito más abajo
do {
   mostrar(tablero);
   colocar_pieza_humano(tablero);
   ganador = comprobar_ganador(tablero);
   tablas = comprobar_tablas(tablero);
   if ((ganador == "Ninguno") && (tablas == false)) {
      colocar_pieza_ordenador(tablero);
      ganador = comprobar_ganador(tablero);
      tablas = comprobar_tablas(tablero);
   }
}
while ((ganador == "Ninguno") && (tablas == false));
	
mostrar(tablero);
if (ganador == "Ninguno") {
   document.getElementById('salida').innerHTML += "EL JUEGO HA TERMINADO EN TABLAS";
}
else {
   document.getElementById('salida').innerHTML += "EL JUEGO HA TERMINADO. EL GANADOR ES: " + ganador;
}

// --------------------------------------------
// Inicializa el tablero con espacios en blanco
// --------------------------------------------
function inicializar(tablero) {
   //let i;
   for (i = 1; i <= 9; i++) {
      // Como tablero es un array, se pasa por referencia y los cambios que
      // hagamos aquí se reflejarán en el algoritmo principal
      tablero[i] = " ";
   }
}

// --------------------------------------------
// Muestra el estado actual del tablero
// --------------------------------------------
function mostrar(tablero) {
   document.getElementById('salida').innerHTML = "ESTADO ACTUAL DEL TABLERO<br>";
   document.getElementById('salida').innerHTML += "+-+-+-+<br>";
   document.getElementById('salida').innerHTML += "|" + tablero[1] + "|" + tablero[2] + "|" + tablero[3] + "|<br>";
   document.getElementById('salida').innerHTML += "+-+-+-+<br>";
   document.getElementById('salida').innerHTML += "|" + tablero[4] + "|" + tablero[5] + "|" + tablero[6] + "|<br>";
   document.getElementById('salida').innerHTML += "+-+-+-+<br>";
   document.getElementById('salida').innerHTML += "|" + tablero[7] + "|" + tablero[8] + "|" + tablero[9] + "|<br>";
   document.getElementById('salida').innerHTML += "+-+-+-+<br>";
}

// ---------------------------------------------------
// Coloca una pieza del jugador humano en el tablero
// ---------------------------------------------------
function colocar_pieza_humano(tablero) {
   var casilla, casilla_correcta;
   do {
      casilla = prompt("¿En qué casilla quieres poner una pieza? (1-9)");
      casilla_correcta = false;
      if (tablero[casilla] == " ") {
         tablero[casilla] = "X";
         casilla_correcta = true;
      }
      else {
         document.getElementById('salida').innerHTML += "Error: Esa casilla ya está ocupada<br>";
      }
   }
   while (casilla_correcta == false);
}

// ---------------------------------------------------
// Coloca una pieza del ordenador en el tablero
// ---------------------------------------------------
function colocar_pieza_ordenador(tablero) {
   var casilla, casilla_correcta;
   casilla_correcta = false;
   do {
      casilla = Math.round(Math.random()*9);
      alert("Voy a colocar mi pieza en la casilla " + casilla);
      if (tablero[casilla] == " ") {
         tablero[casilla] = "O";
         casilla_correcta = true;
      }
      else {
         alert("¡Está ocupada! Voy a elegir otra");
      }
   }
   while (casilla_correcta == false);
}

// ---------------------------------------------------
// Comprueba si hay un ganador según el estado del 
// tablero. Devuelve "Ninguno", "Humano" u "Ordenador"
// ---------------------------------------------------
function comprobar_ganador(tablero) {
   var ganador = "Ninguno";
   // Comprobamos primera fila
   if ((tablero[1] == tablero[2]) && (tablero[1] == tablero[3])) {
      if (tablero[1] == "X") {
         ganador = "Humano";
      }
      if (tablero[1] == "O") {
         ganador = "Ordenador";
      }
   }
   // Comprobamos segunda fila
   if ((tablero[4] == tablero[5]) && (tablero[4] == tablero[6])) {
      if (tablero[4] == "X") {
         ganador = "Humano";
      }
      if (tablero[4] == "O") {
         ganador = "Ordenador";
      }
   }
   // Comprobamos tercera fila
   if ((tablero[7] == tablero[8]) && (tablero[7] == tablero[9])) {
      if (tablero[7] == "X") {
         ganador = "Humano";
      }
      if (tablero[7] == "O") {
         ganador = "Ordenador";
      }
   }
   // Comprobamos primera columna
   if ((tablero[1] == tablero[4]) && (tablero[1] == tablero[7])) {
      if (tablero[1] == "X") {
         ganador = "Humano";
      }
      if (tablero[1] == "O") {
         ganador = "Ordenador";
      }
   }
   // Comprobamos segunda columna
   if ((tablero[2] == tablero[2]) && (tablero[2] == tablero[8])) {
      if (tablero[2] == "X") {
         ganador = "Humano";
      }
      if (tablero[2] == "O") {
         ganador = "Ordenador";
      }
   }
   // Comprobamos tercera columna
   if ((tablero[3] == tablero[6]) && (tablero[3] == tablero[9])) {
      if (tablero[3] == "X") {
         ganador = "Humano";
      }
      if (tablero[3] == "O") {
         ganador = "Ordenador";
      }
   }
   // Comprobamos una diagonal
   if ((tablero[1] == tablero[5]) && (tablero[1] == tablero[9])) {
      if (tablero[1] == "X") {
         ganador = "Humano";
      }
      if (tablero[1] == "O") {
         ganador = "Ordenador";
      }
   }
   // Comprobamos la otra diagonal
   if ((tablero[3] == tablero[5]) && (tablero[3] == tablero[7])) {
      if (tablero[3] == "X") {
         ganador = "Humano";
      }
      if (tablero[3] == "O") {
         ganador = "Ordenador";
      }
   }
   return ganador;
}

// -------------------------------------------
// Comprueba si hay una situación de tablas
// según el estado actual del tablero. Devuelve
// verdadero si hay tablas o falso en otro caso.
// -------------------------------------------
function comprobar_tablas(tablero) {
   var tablas;
   var i, contador = 0;
   for (i = 1; i <= 9; i++) {
      if (tablero[i] != " ") {
         contador++;
      }
   }
	
	// Si todas las casillas están ya ocupadas y no hay ganador,
	// entonces estamos en tablas.
   if (contador == 9) {
      tablas = true;
   }
   else {
      tablas = false;
   }
   return tablas;
}
</script>
```

### 9.5.2. ¿Cómo ejecutar y depurar este programa?

Guarda el programa anterior en un archivo de texto con extensión .html (por ejemplo, *3-en-raya.html*).

Luego, sencillamente, haz doble clic sobre él para abrirlo. El sistema operativo usará el navegador web predeterminado de tu sistema para abrir el archivo y la ejecución comenzará.

#### ¡Socorro! El programa no funciona

¿El resultado no es el esperado? Es lo habitual. Habrá algún error en el código y te tocará depurarlo.

Las páginas web (con Javascript incluido) son extraordinariamente resistentes a los errores. No te mostrarán mensajes de error cada vez que haya algo mal escrito.

Al contrario, permanecerán en silencio para no asustar al usuario de la web y provocar que salga corriendo de allí.

Por ese motivo, los errores de Javascript solo se dejan ver en la "sala de máquinas" del navegador. Por supuesto, los programadores/as tienen una manera de acceder a esa "sala de máquinas".

Pulsa **F12** en tu navegador para abrir la **consola de errores** de Javascript. Asegúrate de seleccionar la pestaña etiquetada como ***Console***. Verás algo como esto:

![Consola de errores de Javascript](/docs/prog-y-3d/_site/assets/images/05-consola-errores-javascript.png)

En la consola de errores aparecen, en rojo, los mensajes de error que haya lanzado el intérprete de Javascript, indicándote el tipo de error y la línea en la que se ha detectado. Los mensajes estarán en inglés, por supuesto, pero ¿qué esperabas? Si quieres aprender a programar, tienes que acostumbrarte a manejar el inglés técnico.

¡Atención! Dependiendo del navegador que uses, puede que esa consola de errores se abra con otra combinación de teclas. Tendrás que bichear un poco por internet para averiguarlo. Lo habitual, sin embargo, es F12.

Cuando hayas localizado el error, **regresa a tu editor de texto, haz los cambios necesarios, guarda las modificaciones y recarga la página** (pulsando **F5** en la mayoría de los navegadores).

Si el navegador se había quedado colgado, tendrás que cerrarlo, esperar unos segundos y volver a abrirlo.

Y así hasta que funcione.

¡Mucha paciencia y sangre fría! Recuerda siempre que la mayor parte del tiempo de programación se va en depurar programas, no en escribirlos.

## 9.6. Ejercicios propuestos

#### Ejercicio 1. Tabla de multiplicar

Vamos a empezar por algo sencillito.

Escribe un programa en Javascript que pida un número y muestre la tabla de multiplicar de ese número.

Puedes utilizar esta plantilla para tu primer programa:

```html
<div id='salida' style='text-align: center; border-style: solid; border-color: black'></div>
<script>
   // Escribe aquí el programa de la tabla de multiplicar
</script>
```

Recuerda que la salida la puedes enviar al <div> 'salida' con la expresión: *document.getElementById('salida').innerHTML*

#### Ejercicio 2. Juego del número secreto

Ahora algo solo un poquito más complicado: una versión en Javascript del juego del número secreto.

(Puedes encontrarlo resuelto en el capítulo "Introducción a la programación")

#### Ejercicio 3. Botón saltarín

Aquí empezamos a divertirnos.

**Vamos a hacer una página web con un botón. Al pulsar ese botón, Javascript hará que ¡el botón cambie de sitio!**

Para eso, capturaremos el **evento *click*** del botón.

El botón lo tienes que crear antes mediante HTML. No importa que no sepas HTML. Solo echa un vistazo a este código:

```html
<body>
   <button id='boton' onclick='mover_boton()' style='position: absolute; top: 100px; left: 200px'>Púlsame</button>
   <script>
      function mover_boton() {
          // Escribe aquí tu código javascript
      }
   </script>
</body>
```

Ahora solo te queda programar la función *mover_boton()*.

Para lograr que el botón se mueva, tendrás que fijarte primero en cómo está el botón creado: tiene un **id**, un evento **onclick** y un **style**. Dentro del este último se definen dos propiedades:

* **top** es la distancia desde la parte superior de la ventana del navegador hasta el botón. Lo hemos establecido en 100 píxeles (100px).
* **left** es la distancia desde la parte izquierda de la ventana del navegador hasta el botón. Le hemos dado 200 píxeles.

Pues bien, debes hacer que Javascript modifique esas dos propiedades. Por ejemplo, así:

```javascript
function mover_boton() {
   document.getElementById('boton').style.top = '150px';
   document.getElementById('boton').style.left = '250px';
}
```

Con eso, el botón se moverá al hacer clic sobre él, pero solo la primera vez. Quedará emplazado en la posición top = 150px y left = 250px y ya no se desplazará más.

**¿Y si quisiéramos que se moviera *siempre* que hagamos clic sobre él?** Es es lo que tienes que conseguir en este ejercicio.

#### Ejercicio 4. Ventana nerviosa y botones evanescentes

**Ahora vamos a conseguir que una ventana entera del navegador se mueva al pulsar un botón. Y a hacer aparecer y desaparecer botones.**

De hecho, vamos a crear cuatro botones:

* **Botón "Saltar"**: al pulsarlo, la ventana dará un salto. Es decir, cambiará de posición..
* **Botón "Temblar"**: al pulsarlo, la ventana se pondrá a "temblar", como si tuviera frío o se hubiera puesto nerviosa, durante un rato.
* **Botón "Ocultar"**: al pulsarlo, los dos botones anteriores desaparecerán de la vista.
* **Botón "Mostrar"**: al pulsarlo, los botones desaparecidos volverán a aparecer.

Esos cuatro botones puedes crearlos con este código HTML. También crearemos una segunda ventana del navegador, que será la que cambiará de posición:

```html
<body>
   <h1>Ventana nerviosa</h1>
   <button id='btn_saltar' onclick='btn_saltar()'>Saltar</button>
   <button id='btn_temblar' onclick='btn_temblar()'>Temblar</button>
   <button id='btn_ocultar' onclick='btn_ocultar()'>Ocultar</button>
   <button id='btn_mostrar' onclick='btn_mostrar()'>Mostrar</button>
   <script>
      myWindow = window.open('', '', 'width=300, height=200'); 
      function btn_saltar() {
          // Escribe aquí tu código javascript para cuando se pulse el botón "Saltar"
      }
      function btn_temblar() {
          // Escribe aquí tu código javascript para cuando se pulse el botón "Temblar"
      }
      function btn_ocultar() {
          // Escribe aquí tu código javascript para cuando se pulse el botón "Ocultar"
      }
      function btn_mostrar() {
          // Escribe aquí tu código javascript para cuando se pulse el botón "Mostrar"
      }
   </script>
</body>
```

Lo siguiente es programar el código de cada una de las cuatro funciones Javascript, que se ejecutarán al pulsar cada botón.

No te voy a decir lo que tienes que escribir en ellas, pero sí te voy a dar un par de pistas:

* **Pista nº 1**. Hay un objeto en Javascript llamado ***window***, que nos permite alterar las propiedades de la ventana del navegador. Por ejemplo, nos permite cambiar su posición y su tamaño. En el apartado 5.2.11, sobre *Objetos predefinidos de Javascript*, hablamos de qué modo se puede cambiar eso.

   Observa que, en el fragmento de código anterior, hemos creado un objeto *window* llamado ***myWindow***. Es sobre ese objeto sobre el que tienes que actuar.

* **Pista nº 2**. En el ejercicio anterior cambiábamos las propiedades *top* y *left* de un botón, pero los botones (y cualquier cosa que haya en una página web) tienen muchas otras propiedades (¡pero MUCHAS!). Una de ellas se llama ***visibility***, y puede tomar dos valores: *visible* o *hidden*.

#### Ejercicio 5. Colorines

Vamos a juguetear más con las propiedades de la página web cargada desde Javascript.

En esta ocasión, construiremos una página con un cuadro de texto, un botón y un recuadro de color negro.

Si escribimos en la caja de texto otro color (por ejemplo, "orange") y hacemos click en el botón, **el recuadro negro tiene que cambiar de color** y volverse naranja.

El código HTML que puedes usar como base es este:

```html
<html>
<head>
   <title>Colorines</title>
</head>
<body>
   <h1>Colorines</h1>
   <div id='caja_color' style='position: absolute; top: 5%; left: 70%; width: 25%; height: 20%; background-color: black'></div>
   <input type='text' id='color' value='yellow'>
   <button id='boton' onclick='cambiar_color()'>Cambiar color</button>
   <script>
      function cambiar_color() {
         // Escribe aquí el código Javascript
      }
   </script>
</body>
</html>
```

Observa que, además de preparar los tres elementos que necesitamos (el recuadro de color negro, la caja de texto y el botón), hemos añadido más elementos HTML como *head* o *title*. Esos elementos son necesarios para que la página web se considere bien formada. Si no sabes lo que significan (aunque es bastante evidente), puedes repasarlos en el capítulo dedicado a HTML.

(El navegador se tragará la página web aunque no esté bien formada, pero lo correcto es hacerla bien dentro de lo posible).

Ahora solo te falta escribir el código de la función Javascript para cambiar el color del recuadro.

#### Ejercicio 6. Pelota de goma

Busca en internet una imagen de una pelota que te guste y descárgala. En esa imagen no debe aparecer nada más, excepto la pelota. 

Luego insértala en una página web, así:

```html
<body>
   <img  id='pelota' src='nombre-del-archivo-de-la-imagen' style='position: absolute; width: 100px; height: 100px'>
</body>  
```

En *'nombre-del-archivo-de-la-imagen'*, como es lógico, tendrás que escribir el nombre del archivo que contiene tu pelota. Le hemos asignado 100 píxeles de ancho y 100 de alto, pero si es demasiado pequeña o demasiado grande, siéntete libre de cambiar esas cantidades.

**Ahora escribe en Javascript un programa para que la pelota rebote por la pantalla como si fuera una pelota de verdad.**

Para conseguirlo, tendrás que:

* Alterar de nuevo las propiedades *top* y *left* de la pelota
* Usar las propiedades el objeto ***window*** para evitar que la pelota se salga de los márgenes de la pantalla.
* Utilizar un **temporizador** para mover la pelota cada x milisegundos. Según el valor de x, la pelota se moverá más deprisa o más despacio.

**Mejora para los más valientes**: trata de añadir un botón a este programa. Al pulsarlo, la pelota se detendrá. Al volver a pulsarlo, la pelota se pondrá en marcha de nuevo.

#### Ejercicio 7. Tres en raya improved

**Modifica el juego de las tres en raya para que sea más atractivo al usuario y más cómodo de jugar.** Encontrarás el código fuente del juego más arriba, en este mismo capítulo.

Tienes que eliminar todas las entradas de datos mediante *prompt()* y sustituirlas por cajas de texto HTML, como esta:

```html
¿En qué casilla quieres poner tu pieza? (1-9)
<input type='text' id='casilla'>
<button onclick='colocar_pieza()'>Aceptar</button>

<script>
   function colocar_pieza() {
      var casilla = document.getElementById('casilla').value;
      // A partir de aquí, iría el código para colocar la pieza del jugador en esa casilla
   }
</script>
```

Al hacer clic en el botón, se ejecutará la función *colocar_pieza()*. Observa cómo se extrae el texto escrito en el cuadro de texto para llevárnoslo a una variable de Javascript (llamada *casilla*).

También puedes mejorar la apariencia del juego alterando sus colores, tipografías, etc. Tendrás que investigar un poco en internet sobre cómo puede hacerse eso.

#### Ejercicio 8. Tenis

(Aviso: este ejercicio es de dificultad elevada)

Ya sabes hacer que una pelota rebote (ejercicio 5). **Vamos a mejorar ese programa haciendo una versión del clásico juego de tenis *"Pong"***, el primer videojuego comercial de la historia.

Si no conoces el *Pong*, bichea un poco por Internet para averiguar cómo es.

¡Y ahora trata de programar una versión actualizada en Javascript!

#### Ejercicio 9. Carretera al infierno

(Aviso: este ejercicio es de dificultad elevada)

En esta ocasión, vamos a programar **un juego que llamaremos "Carretera al infierno"**.

En el juego, manejaremos un coche (busca en internet la imagen de un coche visto desde arriba). El coche aparecerá en la parte inferior de la pantalla, centrado y mirando hacia arriba.

Una carretera irá desplazándose de arriba a abajo. La carretera no será recta, sino que tendrá irregularidades aleatorias hacia la izquierda y hacia la derecha. Nuestro objetivo es mover el coche hacia la izquierda y hacia la derecha para evitar que se salga de la carretera.

La carreterá se moverá cada vez más deprisa. **El objetivo del juego es aguantar la mayor cantidad posible de tiempo sin salirnos.**

## 9.7. Ejercicios resueltos

Aquí iremos poniendo los ejercicios que resolvamos en clase.

#### Ejercicio 1. Tabla de multiplicar

```html
<h1>Tabla de multiplicar</h1>
<div id='salida' style='text-align: center; border-style: solid; border-color: black'></div>
<script>
   var n = prompt("Dime un número");
   for (i = 1; i <= 10; i++) {
      document.getElementById('salida').innerHTML += n + " x " + i + " = " + n*i + "<br>";
   }
</script>
```