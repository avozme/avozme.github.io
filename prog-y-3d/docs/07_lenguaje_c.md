---
layout: page
title: 9. El lenguaje C
permalink: /lenguaje-c/
nav_order: 9
has_children: true
parent: Introd. a la prog. y al diseño 3D
---

# 9. El lenguaje C
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

C es un lenguaje muy antiguo pero plenamente vigente en muchos ámbitos de la **informática y diversas ingenierías**.

¡C tiene más de 50 años, lo que es una auténtica burrada en informática! 

Sin embargo, sigue usándose en la actualidad. **Por algo será.**

Por un lado, C genera código máquina tan eficiente que ningún otro lenguaje puede igualarlo. Y puedes acceder directamente al hardware de tu máquina desde C, o incluso incrustar código ensamblador.

Por si esto fuera poco, C (o su hermano mayor, C++, que veremos en el siguiente tema) se utiliza mucho en la actualidad en diversos ámbitos donde se necesita acceder al hardware o que los programas se ejecuten muy, muy rápido:

* Desarrollo de sistemas. Gran parte de Windows, Linux, iOS o Android están programados en C.
* Desarrollo de drivers para los sistemas operativos.
* Robótica y automática.
* Sistemas integrados en electrodomésticos: televisores, microondas, frigoríficos, routers, etc.
* Sistemas integrados en los automóviles: ABS, ESP, climatización, visualización de información en tiempo real, control de los sensores...
* Aprendizaje. Con C aprenderás a programar de verdad, sin que librerías enormes o *frameworks* te oculten lo que pasa en las entrañas de la máquina.

Por todas estas razones, C es un lenguaje estupendo para iniciarse en la programación, así que ¡vamos a ello!

### 9.2.1.  Características básicas de C

* C es un lenguaje de **nivel intermedio**. Tiene características de los lenguajes de alto nivel pero, al mismo tiempo, permite manipular detalles del hardware que para otros lenguajes resultan innacesibles y genera código máquina ultrarrápido.
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

Una evolución de C fue el lenguaje C++ que, a parte de todas las características del ANSI C, incluye la posibilidad de orientación a objetos, una técnica de programación ligeramente diferente de la programación estructurada. Algo más tarde, en el año 2000, Microsoft patentó el lenguaje C#, otra evolución de C++ orientada al desarrollo de aplicaciones en red para la plataforma .NET de esta compañía.

Otros lenguajes han sido diseñados para permitir que los no programadores puedan leer y comprender los programas y, presumiblemente, aprender a escribir los suyos propios para resolver problemas sencillos. Por el contrario, C fue creado, influenciado y probado en vivo por programadores profesionales. El resultado es que C da al programador lo que muchos programadores piden: unas pocas y bien escogidas palabras clave, una biblioteca poderosa y estandarizada, unas mínimas restricciones y un máximo control sobre lo que sucede en el interior de la máquina.

Si a esto unimos que el código objeto generado por C es casi tan eficiente como el ensamblador, se entenderá por qué lleva medio siglo siendo uno de los lenguajes más populares entre los programadores profesionales.

C también tiene sus detractores que lo acusan de ser confuso, críptico y demasiado flexible. En efecto, con C se pueden desarrollar las técnicas de programación estructurada, pero también se puede programar "código espagueti". Esto, sin embargo, ocurre con todos los lenguajes: incluso los que tienen una sintaxis más estilizada y elegante, como Python o Ruby, pueden generar código absolutamente ininteligible en manos de un programador manazas.

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

A continuación te muestro una tabla con las más habituales y su equivalente en pseudocódigo, sin entrar en explicaciones, porque supondremos que ya sabes manejarlas. Si no recuerdas para qué servía alguna de ellas, quizá sería buena idea que le dieras un repaso al capítulo dedicado al pseudocódigo.

<table>
    <tr>
      <th>Instrucción</th>
      <th>Pseudocódigo</th>
      <th>Lenguaje C</th>
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

   En C:

   ```c
   i = 1;
   do {
      printf("%i", i);
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

   En C:

   ```c
   for (i = 1; i <= 10; i = i + 1) {
      printf("%i", i);
   }
   ```

   Si el **paso** del bucle no es +1 (es decir, si la variable que controla el bucle no incrementa su valor de 1 en 1 en cada iteración), hay que indicarlo de este modo:

   En pseudocódigo:

   ```
   Para i <- 1 hasta 10 con paso 2 hacer
      Escribir i
   FinPara
   ```

   En C:

   ```c
   for (i = 1; i <= 10; i = i + 2) {
      printf("%i", i);
   }
   ```

   Por último, recuerda que en C existe una abreviatura para ```i = i + 1```, que se escribe ```i++```, por lo que lo más habitual es encontrar los bucles de tipo *para* escritos así:

   ```c
   for (i = 1; i <=10; i++) {
      printf("%i", i);
   }
   ```   

### 9.2.8. Algoritmo principal y Subalgoritmos

C es un **lenguaje modular** hasta el extremo de que todas las líneas de código deben pertenecer a alguna función, incluyendo las instrucciones del algoritmo principal, que se escriben en una función llamada *principal* (***main*** en inglés)

#### La función *main()*

La **función *main()*** contiene el algoritmo o módulo principal del programa. La ejecución de un programa siempre empieza por la primera línea de la función *main()*.

Esta función, como todas las funciones de C, puede devolver un valor. El valor devuelto por *main()* debe ser de tipo entero (*int*). Esto se utiliza para pasar algún valor al programa que haya llamado al nuestro, que suele ser el sistema operativo. Si *main()* no devuelve un número entero al sistema operativo mediante una sentencia return, entonces nuestro programa devolverá un número desconocido. 

(Moraleja: es una buena idea incluir un *return* al final de la función *main()*. Generalmente, la devolución de un 0 indica al sistema operativo que el programa a finalizado sin problemas, mientras que cualquier otro valor señala que se ha producido algún error).

Por lo tanto, la forma habitual de la función *main()* será:

```c
int main(void)
{
   ...instrucciones del algoritmo principal...
   return 0;
}
```

Observa que *main()* no tiene argumentos, por lo que aparece el identificador *void* entre paréntesis en la declaración. También se pueden utilizar argumentos en *main()*, pero eso es algo que no trataremos de momento.

#### Las funciones en C

La declaración de funciones se hace de forma similar a la empleada en pseudocódigo:

```c
tipo_devuelto nombre_función (parámetros_formales)
{
   ...instrucciones...
   return expresión;
}
```

Observa que las únicas diferencias con el pseudocódigo son que no se usa la palabra "función", que las llaves { y } sustituyen a *inicio* y *fin*, y que se emplea la palabra *return* en lugar de devolver.

Si el tipo_devuelto es *void*, se considera que la función no devuelve ningún valor y que, por lo tanto, es un procedimiento. Entonces, un procedimiento en C se declara así:

```c
void nombre_procedimiento (parámetros_formales)
{
   ...instrucciones...
}
```

#### Paso de parámetros

Los parámetros formales son, como en pseudocódigo, una lista de tipos e identificadores que se sustituirán por los parámetros actuales y se usarán como variables dentro de la función.

Los parámetros se pasan normalmente **por valor**, pero también se pueden pasar por referencia. El paso de parámetros por referencia admite dos sitaxis ligeramente diferentes en C: anteponiendo el **operador \*** (asterisco) al nombre del parámetro (equivalente a usar la expresión *por referencia* en pseudocódigo) o anteponiendo el **operador &**. 

**Paso de parámetros por valor**

Por ejemplo, en esta función el paso de parámetros es por valor:

```c
int funcion1 (int x, int y)
{
   ...código de la función
}
```

Esto quiere decir que *funcion1()* recibirá únicamente el valor de los dos parámetros, x e y. Podrá utilizar esos valores a lo largo de su código, e incluso podrá cambiarlos. Pero cualquier cambio en x e y no afectará a los parámetros actuales, es decir, a los parámetros del programa que llamó a *funcion1()*.

**Paso de parámetros por referencia con el operador \***

En la siguiente función, el paso del parámetro "x" es por valor y el del parámetro "y", por referencia:

```c
int funcion2 (int x, int *y)
{
   ...código de la función
}
```

En este caso, cada vez que se vaya a usar el parámetro "y" dentro del código de la función, será necesario acompañarlo del asterisco. Por ejemplo:

```c
*y = 5;
x = 17 + *y;
```

(Hay algunas excepciones a esta regla, pero ahora no vienen a cuento).

En la llamada a la función hay que indicar explícitamente qué parámetro se está pasando por referencia utilizando el operador &. Por lo tanto, para llamar a *funcion2()* con los parámetros a y b habrá que escribir:

```c
resultado = funcion2 (a, &b);
```

Observa que el segundo parámetro (el que se pasa por referencia), lleva delante el operador &.

Si dentro de la función se cambia el valor de y, también cambiará el valor de b fuera de la función, ya que ambas variables han quedado ligadas por el paso por referencia. En cambio, las variables x y a son independientes. (Si todo esto te suena a chino, repásate el apartado dedicado al paso de parámetros en el tema de introducción a la programación en pseudocódigo, donde se explicaba con más detalle).

**Paso de parámetros por referencia con el operador &**

Otra forma de pasar un parámetro por referencia es usar el operador & en los parámetros formales, así:

```c
int funcion3 (int x, int &y)
{
   ...código de la función
}
```

En esta función, el parámetro x se pasa por valor y el parámetro y se pasa por referencia. Utilizando esta sintaxis no es necesario añadir asteriscos cada vez que se usa la y en el cuerpo de la función, ni tampoco usar “&” en la llamada a la función.

Esta tercera forma de paso por referencia no es estándar en C, sino que es propia de C++, por lo que evitaremos utilizarla de momento.

#### Juntándolo todo en un ejemplo

En el siguiente ejemplo se ilustran los dos tipos de paso de parámetros y, en el paso por referencia, las dos sintaxis alternativas de que dispone C.

El ejemplo muestra tres funciones muy similares que reciben dos parámetros, a y b. Las tres intentan intercambiar el valor de a y b mediante una tercera variable llamada tmp. Sin embargo, en la primera de ellas el intercambio no tiene ningún efecto en el programa *main()*, ya que los parámetros están pasados por valor. En las otras dos funciones sí que se consigue el intercambio, ya que los parámetros está pasados por referencia.

No te preocupes si no entiendes toda la sintaxis de este ejemplo. Lo interesante ahora es que veas cuál es la forma correcta de escribir cada tipo de paso de parámetros.


```c
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
```

#### Prototipos de funciones

En C no es necesario escribir las funciones (subalgoritmos) antes de su primera invocación. El mecanismo de compilación y enlace de C permite, de hecho, que las funciones puedan estar físicamente en un archivo distinto del lugar desde el que se invocan.

En la práctica, esto plantea un problema: C no tiene forma de saber si la llamada a una función se hace correctamente, es decir, si se le pasan los argumentos debidos y con el tipo correcto, ni si el resutado devuelto es asignado a una variable del tipo adecuado.

Para conseguir que C realice esas comprobaciones durante la compilación se utilizan los **prototipos de función**. Un prototipo de función es, simplemente, *la declaración de una función*. Es decir, la primera línea del código la función.

El prototipo debe aparecer antes de que la función se invoque por primera vez, aunque el código completo de la función esté en otra parte. Los prototipos permiten al compilador comprobar que los argumentos de la función coinciden en tipo y número con los de la invocación de la misma, y que el tipo devuelto es el correcto.

Los prototipos suelen aparecer al principio del programa, antes de la función *main()*. Observa, en el siguiente ejemplo, que el prototipo de la función *calcular_area()* se coloca delante de *main()*. Sin embargo, el código concreto de esta función no aparece hasta después (incluso podría estar situado en otro archivo diferente):

```c
float calcular_area (float base, float altura);	// Prototipo de la función

int main()				// Algoritmo principal
{
   ...instrucciones...
   area = calcular_area (x,y);
   ...más instrucciones...
   return 0;
}

float calcular_area(float base, float altura)	// Código de la función (podría estar incluso en otro archivo)
{
   ... instrucciones...
}
```

Cuando se vayan a usar funciones de librería, como *fabs()* (valor absoluto), *sqrt()* (raíz cuadrada) o cualquier otra, hay que escribir sus prototipos antes de la función *main()*. Sin embargo, como estas funciones no las hemos escrito nosotros, desconocemos cuales son sus prototipos.

En C se soluciona este problema con los **archivos de cabecera**, que son archivos que incluyen en su interior los prototipos de las funciones, entre otras cosas. 

Hay muchos archivos de cabecera en la librería estándar de C. Por ejemplo, el archivo **math.h** tiene los prototipos de todas las funciones matemáticas. Todos los archivos de cabecera tienen la **extensión .h** en su nombre (h de "header").

Para incluir un archivo de cabecera en nuestro programa se utiliza **#include**, que no es exactamente una instrucción de C, sino una **directiva de compilación**. Ya hemos visto otra directiva de compilación: #define, que usábamos para definir constantes. Las directivas de compilación indican al compilador cómo se debe comportar y, aunque estrictamente hablando no son instrucciones de C, para nosotros es como si lo fueran.

Por ejemplo, esta línea de código sirve para incluir todos los prototipos de las funciones de librería matemática en nuestro programa:

```c
#include <math.h>
```

### 9.2.9. Entrada y salida en C

La entrada y salida de datos en C, es decir, la traducción de las instrucciones leer() y escribir() de pseudocódigo, es uno de los aspectos más difíciles de C para los principiantes.

El estándar ANSI C dispone de muchas funciones para hacer las entradas y salidas de datos. En concreto, dispone de un subconjunto de ellas para hacer la entrada y salida por consola, es decir, por teclado y pantalla.

Podemos clasificar estas funciones de E/S en dos grupos:

* **Funciones de E/S simples**: *getchar(), putchar(), gets(), puts()*
* **Funciones de E/S con formato**: *printf(), scanf()*

Las más utilizadas y versátiles son sin duda las segundas, así que nos detendremos en ellas.

#### Salida de datos con *printf()*

La función *printf()* (de "print" = imprimir y "f" = formato) sirve para escribir datos en el dispositivo de salida estándar (generalmente la pantalla) con un formato determinado por el programador. La forma general de utilizarla es la siguiente:

```c
printf(cadena_de_formato, datos);
```

El prototipo de *printf()* se encuentra en el archivo de cabecera **\<stdio.h\>** (de "std" = standard e "io" = input/output, es decir, "stdio" es un acrónimo de "entrada/salida estándar").

El primer argumento, la *cadena_de_formato*, especifica el modo en el que se deben mostrar los datos que aparecen a continuación. Esta cadena se compone de una serie de códigos de formato que indican a C qué tipo de datos son los que se desean imprimir. 

Todos los códigos están precedidos del símbolo de porcentaje ("%"). Por ejemplo, el código "%i" indica a la función que se desea escribir un número de tipo *int*, y el código "%f", que se desea escribir un número real de tipo *float*.

La forma más simple de utilizar *printf()* es:

```c
int a;
a = 5;
printf("%i", a);
```

Esto escribirá el valor de la variable entera a en la pantalla, es decir, 5. Fíjate que el primer argumento de printf() es una cadena (y, por lo tanto, se escribe entre comillas) cuyo contenido es el código del tipo de dato que se pretende escribir. El segundo argumento es el dato mismo.

En una sola instrucción *printf()* pueden escribirse varios datos. Por ejemplo:

```c
int a;
float x;
a = 5;
x = 10.33;
printf("%i%f", a, x);
```

Observa detenidamente la cadena de formato: primero aparece "%i" y luego "%f". Esto indica que el primer dato que debe imprimirse es un entero, y el segundo, un real. Después, aparecen esos datos separados por comas y exactamente en el mismo orden que en la cadena de formato: primero la variable entera y luego la variable real. El resultado será que en la pantalla se escribirán los números 5 y 10.33.

Algunos de los códigos de formato que se pueden utilizar en *printf()* son:

* **%c**: para imprimir caracteres individuales.
* **%i** o **%d**: para imprimir números enteros.
* **%u**: para imprimir números enteros sin signo.
* **%f**: para imprimir números reales.
* **%e**: para imprimir números reales en notación científica.
* **%s**: para imprimir cadenas de caracteres (strings).
* **%o** y **%x**: para imprimir números en octal y en hexadecimal, respectivamente.

Algunos de estos código admiten modificadores. Los más habituales son:

* **Los códigos numéricos como "%i" o "%f"** permiten insertar modificadores de longitud como "l" (longitud doble) o "h" (longitud corta). Así, por ejemplo, "%ld" indica que se va a imprimir un entero de longitud doble (long int); "%hu" sirve para enteros cortos sin signo (unsigned short int); "%lf" indica que se imprimirá un número real de longitud doble (double), etc.
* **El código "%f"** (números reales) se pueden usar con un modificador de posiciones decimales que se desean mostrar. Por ejemplo, con "%3.4f" obligamos a que se impriman tres dígitos a la izquierda de la coma decimal y cuatro a la derecha. La escritura se justifica a la derecha. Para justificarla a la izquierda se utiliza el modificador "-", de esta forma: "%-10.4f".
* **El código "%s"** (cadenas de caracteres) se puede combinar con un especificador de longitud máxima y mínima de la cadena. Por ejemplo, "%4.8s" escribe una cadena de al menos cuatro caracteres y no más de ocho. Si la cadena tiene más, se pierden los que excedan de ocho. También se puede utilizar el modificador "-" para alinear el texto a la izquierda.

Además de los códigos de formato, en la cadena de formato puede aparecer cualquier texto entremezclado con los códigos. A la hora de escribir en la pantalla, los códigos serán sustituidos por los datos correspondientes. Por ejemplo:

```c
int a;
float x;
a = 5;
x = 10.33;
printf("El número entero es %i y el real es %f", a, x);
```

Lo que aparecerá en la pantalla al ejecutar este fragmento de código será: 

```
El número entero es 5 y el real es 10.33
```

Una última observación sobre *printf()*: hay ciertos caracteres que no son directamente imprimibles desde el teclado. Uno de ellos es el **salto de línea**. Para poder ordenar a *printf()* que escriba un salto de línea (o cualquier otro carácter no imprimible) se utilizan los códigos de barra invertida, que con códigos especiales precedidos del carácter "\".

En concreto, el carácter "salto de línea" se indica con el código "\n". Observa las diferencias entre estos dos bloques de instrucciones para intentar comprender la importancia del salto de línea:

```c
int a;
a = 5;
printf("La variable a vale %i", a);
a = 14;
printf("La variable a vale %i", a);
```

El resultado en la pantalla de la ejecución de estas instrucciones es: 

```
La variable a vale 5La variable a vale 14
```

Veamos el mismo ejemplo usando el código del salto de línea (\n):

```c
int a;
a = 5;
printf("La variable a vale %i\n", a);
a = 14;
printf("La variable a vale %i", a);
```

El resultado en la pantalla será:

```
La variable a vale 5
La variable a vale 14

```

#### Entrada de datos con scanf()

La función *scanf()* es, en muchos sentidos, la inversa de *printf()*. Puede leer desde el dispositivo de entrada estándar (normalmente el teclado) datos de cualquier tipo de los manejados por el compilador, convirtiéndolos al formato interno apropiado. Funciona de manera análoga a *printf()*, por lo que su sintaxis es:

```c
scanf(cadena_de_formato, datos);
```

El prototipo de *scanf()* se encuentra en el archivo de cabecera **\<stdio.h\>**, como *printf()*.

La *cadena_de_formato* tiene la misma composición que la de printf(). Los datos son las variables donde se desea almacenar el dato o datos leidos desde el teclado. **¡Cuidado!** Con los tipos simples, es necesario utilizar el operador & delante del nombre de la variable, porque esa variable se pasa por referencia a *scanf()* para que ésta pueda modificarla.

Por ejemplo:

```c
int a, b;
float x;
char s[100];
printf("Escribe un número entero:");
scanf("%d", &a);
printf("Ahora escribe un número entero y un número real:");
scanf("%d%f", &b, &x);
printf("Escribe una cadena:");
scanf("%s", s);
```

La función *scanf()* tiene alguna otra funcionalidad añadida para el manejo de cadenas de caracteres que ya veremos en su momento.

#### Ejemplo de uso de scanf() y printf()

Debido a la relativa complejidad de estas funciones de entrada y salida, vamos a presentar un pequeño ejemplo de traducción de pseudocódigo a C. Se trata de un algoritmo que lee dos números enteros, A y B. Si A es mayor que B los resta, y en otro caso los suma.

Observa detenidamente la correspondencia entre cada pareja de instrucciones, especialmente las de entrada y salida.

**Pseudocódigo:**

```
algoritmo suma_y_resta
   definir a, b como entero
   escribir "Introduzca dos números enteros";
   leer a
   leer b
   si a < b entonces
       escribir "La suma de a y b es:", a+b
   sino
       escribir "La resta de a menos b es:", a–b
finAlgoritmo
```

**Lenguaje C:**

```c
/* Programa suma y resta */
#include stdio.h
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
```

#### Funciones para E/S simple por consola

Técnicamente, con *printf()* y *scanf()* es posible escribir y leer cualquier tipo de datos desde cualquier dispositivo de salida o entrada, no solo la pantalla y el teclado.

En la práctica, aunque *printf()* resulta bastante efectiva y versátil, *scanf()* puede darte muchos dolores de cabeza. Para hacerte una idea, sólo tienes que probar a hacer un *scanf()* de un número entero e inmediatamente después otro *scanf()* de una cadena de caracteres. El segundo *scanf()* fallará. La razón es bastante rocambolesca: el flujo de entrada no consumirá el carácter de retorno de carro al leer el número entero, por lo que dicho carácter se adjudicará al segundo *scanf()* automáticamente.

Por suerte, **existe otro grupo de funciones en ANSI C específicamente diseñadas para hacer la E/S por consola**, es decir, por teclado y pantalla, de manera más simple. Las resumimos en el siguiente cuadro.

Los prototipos de estas funciones, como el de *scanf()*, se encuentran en el archivo de cabecera ***stdio.h***, así que tendrás que incluirlo en tu código para poder usarlas.

* ***getchar()***: Espera a que se pulse una tecla seguida de INTRO y devuelve su valor. Muestra el eco en la pantalla, es decir, la tecla pulsada aparece en la pantalla.

   ```c
   char car;
   car = getchar();
   printf("Tecla pulsada:\n");
   ```

* ***putchar(c)***: Escribe el carácter *c* en la pantalla.
* ***gets(cadena)***: Lee del teclado una cadena de caracteres seguida de INTRO.

   ```c
   char cadena[50];
   gets(cadena);
   printf("Cadena tecleada:\n");
   puts(cadena);
   ```

* ***puts(cadena)***: Escribe una cadena de caracteres en la pantalla (ver ejemplo anterior).

Por lo tanto, **para evitar los problemas que a menudo causa *scanf()*, podemos recurrir a *gets()*** para leer las cadenas de caracteres. Si necesitamos leer un número, podemos usar *gets()* y luego **convertir la cadena** a un tipo de dato numérico con las funciones de conversión *atoi()* y *atof()*, como se muestra en el siguiente ejemplo:

```c
char cadena[50];
int a;
float x;

gets(cadena);      // Leemos una cadena de caracteres
a = atoi(cadena);  // Convertimos la cadena en un número entero
x = atof(cadena);  // Convertimos la cadena en un número real
```

Las funciones de conversión *atoi()* y *atof()* tratarán de convertir la cadena en un número, si ello es posible (es decir, si la cadena realmente contiene números).

Pero cuidado: si se teclean más caracteres de los que caben en la cadena, el resultado es imprevisible (a menudo el programa fallará durante la ejecución). Esto puede solucionarse utilizando *fgets()* en lugar de *gets()*, que es una función más compleja y no vamos a explicar aquí. Puedes buscar información en internet si te interesa el tema.

Tal vez pienses que resulta demasiado complicado hacer algo muy simple como una entrada de datos por teclado. Tienes razón. Pero ten en cuenta dos cosas: las entradas de datos nunca son simples (son el punto donde el usuario interacciona con más libertad con el programa, y los usuarios humanos tendemos a hacer cosas impredecibles y complicadas), y C es un lenguaje de nivel intermedio más que de alto nivel, por lo que muchas tareas de alto nivel, simplemente, no las resolverá por nosotros. En ese sentido, C requiere del programador prestar atención a ciertos detalles que podría obviar en otros lenguajes.

### 9.2.10. Cadenas de caracteres

Las **cadenas** de caracteres en C son, en realidad, **arrays de caracteres**. 

Aunque veremos los arrays en el próximo apartado, si ya sabes pseudocódigo quizá no te sorprenda saber que una cadena se declara así:

```c
char cadena[50];		/* Declaración de una cadena de 50 caracteres */
```

La cadenas tienen ciertas peculiaridades que comentaremos en este apartado, pero todo lo que digamos en el siguiente sobre arrays también será aplicable a las cadenas.

#### Declaración y manipulación de cadenas

Las cadenas pueden manipularse elemento por elemento, como cualquier array. Por ejemplo:

```c
char cadena[50];
cadena[0] = 'H';
cadena[1] = 'o';
cadena[2] = 'l';
cadena[3] = 'a';
```

Las cadenas deben tener, después de su último carácter válido, un carácter especial llamado **nulo**. Este carácter marca el final de la cadena. El carácter nulo se simboliza con **el código \0**. Por lo tanto, en el ejemplo anterior habría que agregar la siguiente línea para que la cadena estuviera completa:

```c
cadena[4] = '\0';
```

**Todas las cadenas deben terminar en un carácter nulo**. De lo contrario, podemos tener problemas al imprimirlas en la pantalla o al realizar con ellas cualquier otro proceso. En consecuencia, en una cadena definida como la anterior, de 50 caracteres, en realidad sólo tienen cabida 49, ya que siempre hay que reservar una posición para el carácter nulo.

La declaración de una cadena puede ir acompañada de una inicialización mediante una constante. En este caso, la constante debe ir encerrada entre comillas dobles, al tratarse de una cadena y no de caracteres sueltos. Por ejemplo:

```c
char cadena[50] = "Hola";
```

En inicializaciones de este tipo, el compilador se encarga de añadir el carácter nulo.
Por último, señalemos que no es necesario indicar el tamaño de la cadena si se inicializa al mismo tiempo que se declara. Por ejemplo, la declaración anterior puede sustituirse por esta otra:

```c
char cadena[] = "Hola";
```

Esto se denomina array de longitud indeterminada. El compilador, al encontrar una declaración así, crea una cadena del tamaño suficiente para contener todos los caracteres. Esto vale no sólo para las cadenas, sino que también es aplicable a cualquier otro tipo de array que se inicialice al mismo tiempo que se declare.

#### Funciones para manejo de cadenas

La mayor parte de las veces las cadenas son manipuladas mediante el uso de funciones de librería específicas. En este apartado comentaremos las más comunes.

**Funciones de lectura y escritura**

Para leer por teclado una cadena de caracteres se puede utilizar también la función *scanf()* con la cadena de formato "%s". Como las cadenas son arrays, no es preciso anteponer el símbolo & al nombre de la variable. Sin embargo, es preferible emplear la función ***gets()*** por estar específicamente diseñada para la lectura de cadenas. Por ejemplo:

```c
char cadena[50];
printf("Introduzca su nombre ");
gets(cadena);
```

Tanto *scanf()* como **gets()** insertan automáticamente el carácter "\0" al final de la cadena.

De manera análoga podemos emplear la función *printf()* para escribir el contenido de una cadena en la pantalla, pero preferiremos la función ***puts()***, específica de las cadenas. Por ejemplo:

```c
char cadena[50] = "Hola, mundo";
puts(cadena);
```

#### Funciones de tratamiento de cadenas

Las funciones de librería ANSI C para manejar cadenas suelen empezar por las letras "str" (de "string", que significa "cadena" en inglés) y utilizan el archivo de cabecera ***string.h***. 

Entre las funciones más habituales encontramos las siguientes:

* ***strcpy()***: Copia el contenido de una cadena en otra, incluyendo el carácter nulo. Su sintaxis es:

   El siguiente ejemplo es otra versión (artificialmente enrevesada) del "hola, mundo":
   
   ```c
   char cad1[50];
   char cad2[50] = "Hola";
   strcpy(cad1, cad2);
   strcpy(cad2, "mundo");
   printf("%s, %s", cad1, cad2);
   ```

* ***strlen()***: Devuelve la longitud de una cadena, es decir, el número de caracteres de que consta, sin contar el carácter nulo.
Por ejemplo, en este fragmento de código el resultado debe ser 11. Fíjate que la variable cadena tiene una longitud total de 50 caracteres, pero *strlen()* sólo cuenta los que efectivamente se están usando, es decir, los que hay hasta el carácter nulo:

   ```c
   char cadena[50] = "Hola, mundo";
   int longitud;
   longitud = strlen(cadena);
   printf("La longitud es %i", longitud);
   ```

* ***strcmp()***: Compara dos cadenas. Devuelve el valor 0 si son iguales, un valor mayor que 0 si la primera es alfabéticamente mayor que la segunda, o un valor menor que 0 en caso contrario. Por ejemplo:

   ```c
   char cad1[50], cad2[50];
   int comparacion;
   printf("Introduzca dos cadenas");
   scanf("%s %s", cad1, cad2);
   comparacion = strcmp(cad1, cad2);
   if (comparacion == 0)
      printf("Las dos cadenas son iguales");
   ```

* ***strcat()***: Concatena dos cadenas. Esta función añade la *cadena2* al final de la *cadena1*, incluyendo el carácter nulo. El resultado del siguiente ejemplo debe ser, otra vez, "hola, mundo":

   ```c
   char cad1[50] = "Hola, ";
   char cad2[50] = "mundo";
   strcat(cad1, cad2);
   prinft("%s", cad1);
   ```

#### Las cadenas y la validación de los datos de entrada

Una de las principales fuentes de error de los programas son los datos de entrada incorrectos. Por ejemplo, si un programa está preparado para leer un número entero pero el usuario, por error o por mala fe, introduce un carácter, la función *scanf()* fallará y el programa se detendrá.

En otros lenguajes de más alto nivel, el propio lenguaje tiene mecanismos para prevenir estos errores. Pero recuerda que C es un lenguaje de nivel intermedio, pensado para producir código máquina supereficiente y rápido. El precio a pagar por ello es que el lenguaje no hará ninguna comprobación de este tipo de errores: es responsabilidad del programador preverlos. 

Hay un modo bastante sencillo de hacer esto: **leer todos los datos de entrada como cadenas y, luego, convertirlos al tipo de dato adecuado**.

Observa el siguiente ejemplo. Sirve para leer un número entero por teclado, pero previniendo los errores provocados por el usuario que antes mencionábamos. Se utiliza la función *atoi()*, que convierte una cadena a un número entero:

```c
int n;		// El número entero que se pretende leer por teclado
char cad[50];	// La cadena que se usará para prevenir errores de lectura
printf("Introduzca un número entero");
gets(cad);		// No se lee un número entero, sino una cadena
n = atoi(cad);	// Se convierte la cadena a entero
```

### 9.2.11. Arrays

Un **array**, como ya vimos en pseudocódigo, es una agrupación de muchos datos individuales del mismo tipo bajo el mismo nombre. Cada dato individual de un array es accesible mediante un **índice**.

El caso más simple de array es el **array unidimensional**. Por ejemplo, un array unidimensional de números enteros es una colección de muchos números enteros a los que les adjudicamos un único identificador.

#### Declaración de arrays

La declaración de un array en C se hace así:

```c
tipo_de_datos nombre_array[número_de_elementos];
```

Por ejemplo:

```c
int serie[10];
```

La variable *serie* será un array que contendrá 10 números enteros. Los 10 números reciben el mismo nombre, es decir, *serie*. 
Se puede acceder a cada uno de los números que forman el array escribiendo a continuación del nombre un número entre corchetes. Ese número se denomina índice. Lo puedes ver en el siguiente ejemplo:

```c
int serie[10];
serie[2] = 20;
serie[3] = 15;
serie[4] = serie[2] + serie[3];
printf("%i", serie[4]);
```

El array *serie* puede almacenar hasta 10 números enteros. Las posiciones empiezan a numerarse en el 0, así que *serie[2]* se refiere, en realidad, a la tercera posición. En ella se almacena el número 20. En la cuarta posición (*serie[3]*) se almacena el número 15. Luego se suman ambos valores, y el resultado se almacena en la quinta posición (*serie[4]*). Finalmente, se imprime en la pantalla el resultado de la suma, es decir, 35.

<pre>
            +------------+----+----+----+----+----+
            | Posiciones |  0 |  1 |  2 |  3 |  4 |
    serie = +------------+----+----+----+----+----+
            | Valores    |  ? |  ? | 20 | 15 | 35 |
            +------------+----+----+----+----+----+
</pre>

C no realiza comprobación de los índices de los arrays, por lo que es perfectamente posible utilizar un índice fuera del rango válido (por ejemplo, *serie[17]*). Es responsabilidad del programador evitar que esto ocurra, porque los efectos serán desastrosos para el programa.

Como es lógico, se pueden construir arrays cuyos elementos sean de cualquier otro tipo simple, como *float* o *double*, con la única restricción de que todos los elementos sean del mismo tipo. Los arrays de caracteres se denominan **cadenas de caracteres**, y ya hablamos de ellos en el apartado anterior.

También es posible construir arrays cuyos elementos sean de un tipo complejo. Así, podemos tener arrays de arrays o de otros tipos que no vamos a estudiar en este curso de introducción.

#### Manipulación de los elementos individuales de un array

Los arrays en C deben manipularse elemento a elemento. No se pueden modificar todos los elementos a la vez.

Para asignar valores a los elementos de un array, por lo tanto, el mecanismo es este:

```c
int serie[5];
serie[0] = 5;
serie[1] = 3;
serie[2] = 7;
...etc...
```

La inicialización de los valores de un array también puede hacerse conjuntamente en el momento de declararlo, así:

```c
int serie[5] = {5, 3, 7, 9, 14};
```

El resultado de esta declaración será un array de 5 elementos de tipo entero a los que se les asigna los valores 5, 3, 7, 9 y 14.

Cada elemento del array es, a todos los efectos, una variable que puede usarse independientemente de los demás elementos. Así, por ejemplo, un elemento del array serie puede usarse en una instrucción de salida igual que cualquier variable simple de tipo *int*:

```c
int serie[5];
serie[0] = 21;
printf("%i", serie[0]);
```

Del mismo modo, pueden usarse elementos de array en una instrucción de entrada. Por ejemplo:

```c
int serie[5];
scanf("%i", &serie[0]);
serie[1] = serie[0] + 15;
printf("%i", serie[1]);
```

#### Recorrido de un array

Una forma habitual de manipular un array es **acceder secuencialmente** a todos sus elementos, uno tras otro. 

Para ello, **se utiliza un bucle con contador**, de modo que la variable contador nos sirve como índice para acceder a cada uno de los elementos del array.

Supongamos, por ejemplo, que tenemos un array de 10 números enteros declarado como ```int v[10]``` y una variable entera declarada como  ```int i```. Por medio de un bucle, con ligeras modificaciones, podemos realizar todas estas operaciones:

**1) Inicializar todos los elementos a un valor cualquiera** (por ejemplo, 0):

```c
for (i = 0; i <= 9; i++)
{
   v[i] = 0;
}
```

**2) Inicializar todos los elementos con valores introducidos por teclado**:

```c
for (i = 0; i <= 9; i++)
{
   printf("Escribe el valor del elemento nº %i: ", i);
   scanf("%i", &v[i]);
}
```

**3) Mostrar todos los elementos en la pantalla**:

```c
for (i = 0; i <= 9; i++)
{
   printf("El elemento nº %i vale %i\n", i, v[i]);
}
```

**4) Realizar alguna operación que implique a todos los elementos**. Por ejemplo, sumarlos:

```c
suma = 0;
for (i = 0; i <= 9; i++)
{
   suma = suma + v[i];
}
```

#### Arrays y funciones

Para **pasar un array como argumento** a una función, en la llamada a la función se escribe simplemente el nombre del array, sin índices.

Los arrays en C **siempre se pasan por referencia**, nunca por valor. Por lo tanto, si algún elemento del array se modifica en una función, también será modificado en la función desde la que fue invocada.

Como siempre se pasan por referencia, no es necesario utilizar el símbolo & delante del parámetro. 

Por ejemplo, supongamos que *serie* es un array de 15 números enteros. Para pasarlo como parámetro a una función llamada *funcion1()* escribiríamos simplemente esto:

```c
int serie[15];
funcion1(serie);
```

En cuanto a la declaración de la función, el parámetro de tipo array se especifica esta maneras:

```c
void funcion1 (int serie[15]) {
   ...código de la función...
}
```

Dentro de la función, el array *serie* puede usarse del mismo modo que en el programa que la llama, es decir, no es preciso utilizar el operador asterisco ni nada por el estilo.

#### Un programa de ejemplo que usa arrays y funciones

Para ilustrar todo esto, te muestro  programa que sirve para leer 50 números por teclado y calcular la suma, la media y la desviación típica de todos los valores.

Lee el código detenidamente, prestando sobre todo atención al uso de los arrays y a cómo se pasan como parámetros.

Los números de la serie se almacenarán en un array de tipo *float* de 50 posiciones llamado *valores*. La introducción de datos en el array se hace en la función *introducir_valores()*. Como los arrays siempre se pasan por referencia, al modificar el array *valores* dentro de la función, también se modificará en el algoritmo principal.

Después, se llama a 3 funciones que calculan las tres magnitudes (suma, media y desviación). El array también se pasa por referencia a estas funciones, ya que en C no hay modo de pasar un array por valor.

```c
#include <stdio.h>
#include <math.h>

int main(void)
{
	float valores[50];
	float suma, media, desviacion;
	
	introducir_valores(valores);
	suma = calcular_suma(valores);	
	media = calcular_media(valores, suma);
	desviacion = calcular_desviacion(valores, media);
	printf("La suma es %f, la media es %f y la desviación es %f", suma, media, desviacion);
	return 0;
}

/* Lee 50 números y los almacena en el array N pasado por referencia */
void introducir_valores(float n[50])
{
	int i;
	for (i=1; i<=49; i++)
	{
		printf("Introduzca el valor nº %d: ", i);
		scanf("%f", &n[i]);
	}
}

/* Devuelve la suma todos los elementos del array n */
float calcular_suma(float n[50])	
{
	int i;
	float suma;
	suma = 0;
	for (i=1; i<=49; i++)
		suma = suma + n[i];
	return suma;
}

/* Devuelve el valor medio de los elementos del array n. Necesita conocer la suma de los elementos para calcular la media */
float calcular_media(float n[50], float suma)	
{
	int i;
	float media;
	media = suma / 50;
	return media;
}

/* Calcula la desviación típica de los elementos del array n. Necesita conocer la media para hacer los cálculos */
float calcular_desviacion(float n[50], float media)
{
	int i;
	float diferencias;
	diferencias = 0;
	for (i=1; i<=49; i++)
		diferencias = diferencias + abs(n[i] – media) ;
	diferencias = diferencias / 50;
	return diferencias;
}
```

### 9.2.12. Funciones de la librería estándar

La siguiente lista resume algunas funciones de uso frecuente de ANSI C. Para cada función se muestra su prototipo y se explica brevemente cuál es su cometido y cuáles sus datos de entrada y salida. También se indica el archivo de cabecera donde se encuentra el prototipo.

Debes tener en cuenta que ANSI C dispone de muchas otras funciones. Si en algún momento las necesitas, una búsqueda rápida por internet te proporcionará información de sobra. Eso sí, asegúrate que la función que vayas a usar pertenezca al estándar ANSI C. Solo así tendrás la garantía de que tu compilador la reconocerá y de que tu programa será portable a otros sistemas.

**Funciones de entrada/salida**

Función|Prototipo|Utilidad|Archivo de cabecera
-|-|-|-
***getchar()***|```int getchar(void)```|Devuelve un carácter leido por teclado mostrando el eco. Es necesario pulsar INTRO|stdio.h
***gets()***|```char* gets(char* cadena)```|Lee una cadena de caracteres del dispositivo estándar de entrada y la sitúa en la posición apuntada por cadena|stdio.h
***printf()***|```int printf(const char* formato, lista_argumentos)```|Salida estándar con formato. Véase el texto del capítulo para más detalles|stdio.h
***putchar()***|```int putchar(int carácter)```|Escribe carácter en la pantalla|stdio.h
***puts()***|```int puts(const char* cadena)```|Escribe cadena en el dispositivo estándar de salidastdio.h
***scanf()***|```int scanf(const char* formato, lista_argumentos)```|Entrada estándar con formato. Véase el texto del capítulo para más detalles|stdio.h

**Funciones de caracteres**

Función|Prototipo|Utilidad|Archivo de cabecera
-|-|-|-
***isalnum()***|```int isalnum(int carácter)```|Devuelve 1 si el carácter es alfanumérico (letra o número), o 0 si no lo es|ctype.h
***isalpha()***|```int isalpha(int carácter)```|Devuelve 1 si el carácter es alfabético (una letra mayúscula o minúscula), o 0 si no lo es|ctype.h
***isdigit()***|```int isdigit(int carácter)```|Devuelve 1 si el carácter es numérico, o 0 si no lo es|ctype.h
***isupper()*** e ***islower()***|```int isupper(int carácter);  int islower(int carácter);```|La primera devuelve 1 si el carácter es una letra mayúscula y 0 en otro caso. La segunda, al revés|ctype.h

**Funciones matemáticas**

Función|Prototipo|Utilidad|Archivo de cabecera
-|-|-|-
***abs()***|```int abs(int número)```|Devuelve el valor absoluto de número|stdlib.h
***cos()***<br>***sin()***<br>***tan()***<br>***acos()***<br>***asin()***<br>***atan()***|```double acos(double argumento)```|Todas tienen un prototipo similar. Calculan y devuelven, respectivamente, el arcocoseno, el arcoseno, el arcotangente, el coseno, el seno y la tangente de argumento. Los ángulos se expresan en radianes|math.h
***ceil()***|```double ceil(double número)```|Redondea número por exceso. P. ej: ceil(3.2) devuelve 4|math.h
***exp()***|```double exp(double potencia)```|Calcula el exponencial epotencia|math.h
***fabs()***|```double fabs(double número)```|Devuelve el valor absoluto de número|math.h
***floor()***|```double floor(double número)```|Redondea número por defecto. P. ej: floor(3.8) devuelve 3|math.h
***log()***|```double log(double número)```|Devuelve el logaritmo natural de número|math.h
***log10()***|```double log10(double número)```|Devuelve el logaritmo decimal de número|math.h
***pow()***|```double log(double base, double exp)```|Devuelve la potencia de base elevado a exp|math.h
***sqrt()***|```double sqrt(double número)```|Devuelve la raiz cuadrada de número|math.h

**Funciones variadas**

Función|Prototipo|Utilidad|Archivo de cabecera
-|-|-|-
***atof()***|```double atof(char* cadena)```|Convierte la cadena en un número real. Si la cadena no contiene un número real válido, devuelve 0|stdlib.h
***atoi()***|```int atoi(char* cadena)```|Convierte la cadena en un número entero. Si la cadena no contiene un número entero válido, devuelve 0|stdlib.h
***atof()***|```double atof(char* cadena)```|Convierte la cadena en un número real. Si la cadena no contiene un número real válido, devuelve 0|stdlib.h
***itoa()***|```char* itoa(int número, int base)```|Convierte el número en una cadena. La base de la cadena resultante se determina en base|stdlib.h
***rand()***|```int rand(void)```|Devuelve un número entero al azar entre 0 y RAND_MAX (RAND_MAX es una constante definida en stdlib.h)|stdlib.h
***randomize()***|```void randomize(void)```|Inicializa el generador de números aleatorio. Es necesario invocar esta función si después se va a usar random()|stdlib.h
***random()***|```int random(int máximo)```|Devuelve un número al azar entre 0 y máximo – 1|stdlib.h

### 9.2.13. Librerías no estándar que molan: ncurses

Además de las librerías estándar ANSI, existen muchas (¡muchísimas!) librerías de terceros que se pueden usar en nuestros programas. Las que vamos a ver a continuación nos permitirán introducir colores, sonidos y movimientos en nuestros programas, pero debes tener presente una cosa: al no ser librerías estándar, los programas creados con estas librerías serán más difícilmente portables a otros sistemas.

#### Qué es Ncurses

**Ncurses** es una **librería para el manejo de interfaces basadas en texto**. 

Es decir, se trata de un conjunto de funciones ya programadas que podemos utilizar en nuestros programas de texto para mejorar su aspecto.

Como Ncurses no es una librería estándar de C, es necesario ordenar al compilador que la enlace con nuestro programa. 

Si compilas desde la consola, esto se hace añadiendo la opción –lncurses al comando *gcc*. Por ejemplo:

* ```gcc holamundo.c```: compila holamundo.c sin enlazarlo con la librería Ncurses
* ```gcc -lncurses holamundo.c```: compila holamundo.c enlazándolo con Ncurses

Si trabajas desde desde Visual Studio Code y tienes la librería Ncurses instalada en tu sistema, no es necesario que hagas nada en especial. Un simple ```#include <ncurses.h>``` bastará para poder usar la librería.

Ncurses tiene muchísimas funciones, pero nosotros sólo nos referiremos aquí a las más básicas, que nos permitirán añadir color a nuestros textos y controlar libremente la posición del cursor de escritura. Pero Ncurses va mucho más allá, permitiendo la creación de capas de texto superpuestas, menús desplegables y muchas otras cosas en la consola de texto.

#### Inicialización de Ncurses

Para utilizar las funciones de Ncurses en nuestro programa, basta con que incluyamos la siguiente llamada:

```c
initscr();
```

Esta función crea una ventana de texto. La ventana se llama *stdscr* (que significa "standard screen", es decir, "pantalla estándar"). A partir de aquí podremos utilizar cualquier función de Ncurses, pues todas actúan sobre esa ventana (se pueden crear varias ventanas sobre stdscr, pero nosotros no profundizaremos en esa posibilidad). Por ejemplo, una función que suele ir justo después es:

```c
keypad (stdscr, 1);
```

Esto sirve para activar la recepción de teclas especiales (como F1, F2, ESC, etc). Si no llamamos a keypad(), no podremos utilizar ese tipo de teclas en nuestro programa. El segundo parámetro sirve para activar (1) o desactivar (0) la recepción de teclas especiales.

A continuación te dejo una lista con las principales funciones de inicialización de Ncurses:

* **initscr()**. Inicializa Ncurses y crea la pantalla estándar. Debe ser invocada antes que cualquier otra función de la librería.
* **keypad()**. Activa / desactiva la recepción de teclas especiales, como F1, ESC, Intro, etc. Si activar = 1, se activa la recepción. Si activar = 0, se desactiva.
* **echo()** y **noecho()**. Activa / desactiva el eco de caracteres. Si el eco está activo, lo que se escriba en el teclado aparece en la pantalla. Si está inactivo, no.
* **cbreak()** y **nocbreak()**. Activa / desactiva el envío inmediato de teclas. Normalmente, cuando se teclea algo no es enviado al programa hasta que no se pulsa "intro". La función cbreak() hace que todo cuanto se teclee sea enviado al programa sin necesidad de "intro". La función nocbreak() desactiva este comportamiento
* **nodelay(stdscr)**. Activa / desactiva la espera para lectura de teclado. Las funciones para leer un solo carácter, como getch(), detienen la ejecución del programa hasta que se pulsa alguna tecla. Llamando a esta función con el parámetro activar = 1, conseguiremos que el programa no se detenga en getch() aunque no se pulse tecla alguna. Para desactivarlo, llamaremos a la función con activar = 0.

* **endwin()**. Finaliza Ncurses. Hay que llamar a esta función antes de terminar el programa para liberar la memoria ocupada y restaurar la consola al estado inicial.

#### Escribir y leer con ncurses

Cuando utilicemos Ncurses debemos olvidarnos de las funciones de entrada/salida estándar, como *scanf()*, *printf()*, *gets()* o *puts()*. En su lugar usaremos estas otras funciones:

* **printw()** y **putstr()**. Para escribir usaremos la función *printw()*, que funciona igual que *printf()* pero sobre una ventana de Ncurses. También podemos usar *putstr()*, que es como *puts()*, es decir, sirve para imprimir cadenas
* **getstr()** y **getch()**. Para leer disponemos de *getstr()*, que es como *gets()*, es decir, sirve para leer cadenas por teclado. De modo que, si queremos leer un número, debemos leerlo como cadena y luego convertirlo a número (con las funciones estándar *atoi()*, *atof()*, etc). También podemos usar *getch()*, que lee un único carácter.
* **move()**. Posiciona el cursor de texto en la columna x y la fila y de la pantalla. ¡Atención! Se indica primero la fila y luego la columna.
* **refresh()**. Actualiza la pantalla. Es el único modo de asegurarnos de que los cambios realizados se muestren instantáneamente. Si no, Ncurses decidirá cuándo actualizar la pantalla por su cuenta, y te aseguro que no lo hace continuamente.

#### Dar color a nuestro texto

Antes de utilizar los colores en la terminal de texto hay que inicializarlos llamando a la función *start_color()* sin argumentos, así:

```c
if (has_colors())
  start_color();
```

La llamada previa a *has_colors()* se realiza para asegurarnos de que nuestra consola soporta el uso de colores. Es raro encontrar una consola que no permita colores, pero existen, así que no está de más hacer la comprobación.

Una vez hecho esto, podemos utilizar los colores básicos definidos en *ncurses.h*, cuyas constantes son COLOR_BLACK, COLOR_WHITE, COLOR_YELLOW, etc.

Para utilizar esos colores se deben agrupar en parejas: un color para el texto junto con un color para el fondo. A cada pareja se le asigna un número a través de la función *init_pair()*. Por ejemplo:

```c
init_pair(1, COLOR_YELLOW, COLOR_BLUE);
```

Esto define a la *pareja de colores nº 1* como *texto amarillo sobre fondo azul*. De este modo podemos definir, por lo general, hasta 64 parejas.

Después, para **activar una pareja de color**, haremos esta llamada:

```c
attron(COLOR_PAIR(1));
```

Esto activa la pareja de colores nº 1, de manera que todo el texto que aparezca en la pantalla a partir de este momento se verá amarillo con el fondo azul.

La función *attron()*, además de para activar parejas de colores, sirve para cambiar otros atributos del texto. Por ejemplo, lo siguiente se utiliza para escribir en **negrita**:

```c
attron(A_BOLD);
```

Puedes obtener más información sobre attron() en las páginas de manual (escribiendo ```$ man attron``` en la consola) o en internet (por ejemplo, [aquí](https://linux.die.net/man/3/attron)).


#### Ejemplo de uso de Ncurses

Para terminar esta breve introducción a la librería Ncurses mostraremos un ejemplo ilustrativo del uso de algunas de las funciones que aquí se han visto.

El siguiente programa utiliza Ncurses para escribir el texto HOLA en color rojo sobre fondo azul y el texto MUNDO en color amarillo sobre fondo verde. El texto HOLA aparece en la línea 11, y MUNDO en la 12. Luego, el programa espera hasta que se pulsa la tecla "flecha arriba", y entonces termina.

```c
#include <ncurses.h>
int main(void)
{
  char carácter;
  initscr();         // Inicializa Ncurses
  keypad(stdscr, 1); // Activa teclas especiales (como las flechas)
  cbreak();          // Para no tener que pulsar Intro tras cada carácter 
  if (has_colors()) start_color();         // Inicializa colores
  init_pair(1, COLOR_RED, COLOR_BLUE);     // Pareja 1 = Texto rojo, fondo azul
  init_pair(2, COLOR_YELLOW, COLOR_GREEN); // Pareja 2 = Texto amarillo, fondo verde
  attron(COLOR_PAIR(1));    // Activa pareja 1
  move(11, 1);
  printw("HOLA");
  attron(COLOR_PAIR(2));    // Activa pareja 2
  move(12, 1);
  printw("MUNDO");
  do
  {  
       carácter = getch();  // Lee un carácter desde el teclado
  }
  while (carácter != KEY_UP);
  endwin();  // Finaliza Ncurses
  return 0;
}
```

### 9.2.14. Librerías no estándar que molan: SDL

**SDL** (iniciales de *Single DirectMedia Layer*) es una biblioteca de C libre y disponible para múltiples plataformas (entre ellas, Linux y Windows). Puedes bajarte la última versión de [http://www.libsdl.org](http://www.libsdl.org).

Esta biblioteca contiene un conjunto muy completo de funciones para manejar gráficos, además de sonidos y distintos dispositivos multimedia (ratón, CD-ROM, etc). Muchos programas escritos en C (en particular, videojuegos) se han desarrollado con SDL. Además, la librería es razonablemente sencilla de usar.

Nosotros sólo nos vamos a centrar en la parte de SDL dedicada a los gráficos. Si quieres más información, en la página web reseñada antes encontrarás una completa documentación.

#### Instalación de SDL

SDL no es una librería C estándar, es decir, no viene "de serie" con el compilador de C. En realidad, tampoco *ncurses* lo es, pero su uso está tan extendido en entornos Unix que viene incorporada a las librerías del compilador gcc.

En cambio, la librería SDL debe ser instalada antes de poder utilizarla. A continuación describimos el proceso de instalación en Linux y en Windows

**Instalación de SDL en Linux**

* Bájate la última versión de la librería de la web de SDL. Necesitarás el paquete de la librería propiamente dicho (denominado runtime) y el paquete de desarrollo.  El paquete runtime tiene un nombre similar a este: SDL-x.x.x-1.i386.rpm, donde "x.x.x" es la versión de la libería e "i386" indica para qué tipo de procesador está compilado. El paquete de desarrollo debe llamarse SDL-devel-x.x.x-i386.rpm o algo similar.
* Instala ambos paquetes en tu sistema. Con el paquete runtime es suficiente para ejecutar programas que usen la librería SDL, pero si además quieres escribir programas nuevos que usen esta librería (y es nuestro caso), también necesitarás el paquete de desarrollo.

**Instalación de SDL en Windows**

* Bájate la última versión de la librería de la web de SDL. Necesitarás la librería de vínculos dinámicos (denominada dll) y el paquete de desarrollo. La librería de vínculos dinámicos suele venir comprimida en un archivo cuyo nombre es similar a: SDL-x.x.x-win32.zip, donde "x.x.x" es la versión de la libería. Existirán varios paquetes de desarrollo para varios compiladores. Mi consejo es que bajes el que está preparado para el compilador de GNU, cuyo nombre es SDL-devel-x.x.x-mingw32.tar o algo similar. También encontrarás paquetes para Visual C++ y otros compiladores.
* Descomprime la librería de vínculos dinámicos. Debes obtener un archivo llamado sdl.dll. Copia este archivo al directorio /windows/system32, o bien ubícalo en la misma carpeta en la que vaya a estar el programa ejecutable del ajedrez. 
* Descomprime el paquete de desarrollo. Encontrarás varios directorios y, dentro de ellos, multitud de archivos. Copia los archivos en los directorios del mismo nombre de tu compilador. Por ejemplo, el copia el directorio "include" del paquete de desarrollo al directorio "include" de la carpeta donde esté instalado tu compilador. Repite la operación para todos los directorios cuyo nombre coincida.

#### Compilación y enlace

Al no ser SDL una librería estándar, el enlace entre nuestro programa y las funciones de SDL no se produce automáticamente. Hay que indicarle al enlazador (o linker) lo que debe hacer.

Si estás utilizando Visual Studio Code, la forma de hacer que SDL se enlace con tu programa es XXX.

Si utilizas otro entorno de desarrollo distinto de Visual Studio Code, el proceso debe ser muy parecido, pero tendrás que mirar la documentación de ese entorno de desarrollo para ver los detalles.

#### Inicialización y terminación de la pantalla gráfica

Una vez instalada la libería y preparado el compilador, podemos usar las funciones de SDL como cualquier otra función estándar de C. Su uso es exactamente igual en Windows y en Linux, por lo que el programa que obtendremos debería compilar sin necesidad de hacerle ningún cambio en ambos sistemas.

Para usar los gráficos, hay que hacer un ```#include <SDL/SDL.h>``` en el archivo fuente, como es natural. Aparece dos veces el nombre "SDL" porque el archivo SDL.h está dentro de una carpeta llamada SDL.

Lo siguiente que hay que hacer es **inicializar la pantalla gráfica**. Para eso disponemos de dos funciones: *SDL_Init()* y *SDL_SetVideoMode()*:

* ***SDL_Init()***. Debe ser la primera función en invocarse. No se puede usar ninguna otra función de SDL si antes no se ha llamado a esta. Hay que pasarle un parámetro que indica qué tipo de sistema multimedia queremos manejar (la tarjeta de vídeo, la de sonido, el CD-ROM, etc). En nuestro caso será la tarjeta de vídeo, ya que sólo nos interesa manipular gráficos. La constante para ello es SDL_INIT_VIDEO:

   ```c
   SDL_Init(SDL_INIT_VIDEO);
   ```

   La fución SDL_Init() devuelve –1 si ocurre algún error al iniciar el sistema de gráficos. En ese caso, el programa no podrá continuar, de modo que debemos comprobar el valor devuelto por SDL_Init().

* ***SDL_SetVideoMode()***. Esta debe ser la segunda función en invocarse, justo a continuación de SDL_Init(). Sirve para establecer el tipo de pantalla gráfica que queremos. Hay que indicarle el tamaño en píxels, el número de bits de color y los atributos de la pantalla. Por ejemplo:

   ```c
   SDL_SetVideoMode(1200, 960, 24, SDL_ANYFORMAT | SDL_DOUBLEBUFFER);
   ```
   
   Esto crea una ventana gráfica de 1200x960 píxeles, con 24 bits de profundidad de color. El último parámetro, *SDL_ANYFORMAT*, es una constante que indica a SDL que puede seleccionar otra profundidad de color si la elegida no está disponible. Este cuarto parámetro puede tomar otros muchos valores que no vamos a ver, pero sí señalaremos que es conveniente añadir la constante *SDL_DOUBLEBUFFER* por motivos de rendimiento (ver ejemplo más abajo).
   
   *SDL_SetVideoMode()* devuelve un puntero a una estructura llamada *SDL_Surface*, definida en *SDL.h*, o NULL si ocurre algún error. Este puntero nos será imprescidible para manejar la pantalla gráfica, así que **debes guardarlo en una variable**. 
   
   Esta variable, además, debe ser **global** si se va a usar en otras partes del programa, contraviniendo una de las buenas prácticas de programación más universales que existen. Sin embargo, si no lo haces así, la variable no funcionará correctamente.
   
   Aquí tienes un ejemplo de inicialización de la pantalla gráfica:
  
```c
  #include <SDL/SDL.h>  
  ...
  SDL_Surface *pantalla;	// Esta variable debe ser GLOBAL
  ...
  if (SDL_Init(SDL_INIT_VIDEO) == -1) {
    puts("Error en la inicialización del sistema de vídeo\n");
    SDL_Quit();
    exit(-1);
  }

  pantalla = SDL_SetVideoMode(1280, 960, 16, SDL_ANYFORMAT|SDL_DOUBLEBUF);
  if (pantalla == NULL) {
    puts("Fallo al establecer el modo de vídeo\n");
    SDL_Quit();
    exit(-1);
  }
  ...
  SDL_Quit();		// Esto se hace al final del programa
```

Tan importante como inicializar la pantalla gráfica es **finalizarla**. Ten en cuenta que la pantalla gráfica consume muchos recursos, y éstos deben ser liberados antes de que el programa termine su ejecución. Para eso tenemos la función *SDL_Quit()*, que se invoca sin argumentos (observa el ejemplo)

#### Dibujar gráficos en la pantalla

Ya tenemos nuestra pantalla gráfica inicializada y lista para empezar a dibujar en ella. Pero, ¿qué tipo de objetos se pueden dibujar?

Aunque las librerías gráficas permiten al programador **pintar píxels individuales** en cualquier punto de la pantalla, lo habitual es **trabajar con imágenes** previamente existentes llamadas ***sprites***. 

Un *sprite* es una imagen guardada en un archivo que puede ser cargada por el programa y mostrada en cualquier parte de la pantalla gráfica y tantas veces como sea necesario.

Por lo tanto, lo primero que necesitas es hacerte con una colección de sprites para tu programa. Si, por ejemplo, suponemos que estamos desarrollando un de ajedrez, necesitaríamos los siguientes:

* Una imagen del tablero.
* Una imagen de cada una de las piezas. 
* Opcionalmente, una imagen de fondo para decorar la pantalla.

Los archivos con las imágenes deben estar en formato BMP. SDL admite otros formatos, pero el BMP es fácil de manipular, así que es buena idea empezar por las imágenes BMP y luego, cuando ya las manejes bien, dar el salto a otros formatos con compresión, como JPG o PNG. Cualquier editor de imágenes te permitirá convertir tus *sprites* a BMP.

Para dibujar una imagen en cualquier punto de la pantalla, hay que hacer dos cosas que pasamos a describir con detalle:

* Cargar la imagen en la memoria (procedente de un archivo BMP)
* Mostrar la imagen en la pantalla

**1. Cargar imágenes en la memoria**

Sólo es necesario cargar las imágenes **una vez**. Normalmente, se hará **al principio del programa**, justo después de la inicialización de SDL. 

Una vez cargadas en la memoria, podremos utilizarlas tantas veces como las necesitemos, a menos que liberemos el espacio de memoria que ocupan. La liberación de espacio, por tanto, debería hacerse al final del programa, justo antes de terminar.

Para cargar una imagen BMP se usa la función *SDL_LoadBMP()*, de esta forma:

```c
  SDL_Surface *tablero;

  tablero = SDL_LoadBMP("tablero.bmp");
  if (tablero == NULL) {
     printf("Error al cargar el archivo tablero.bmp");
     SDL_Quit();
     exit(-1);
  }
```

Observa que *SDL_LoadBMP()* devuelve un puntero a *SDL_Surface*. Este puntero será necesario para luego mostrar la imagen en cualquier lugar de la pantalla. La variable "tablero" debe ser global si se va a usar en más de una función (si es local y la pasamos como parámetro a otra función, SDL fallará).

Las imágenes son rectangulares. En muchas ocasiones, necesitamos mostrar una imagen encima de otra. Es el caso de las piezas, que se mostrarán encima del tablero. Cuando esto ocurre, el color de fondo de la pieza (que decidimos que fuera negro) aparecerá encima del tablero como un desagradable recuadro de color negro. En estas situaciones, hay que avisar a SDL de que, para este *sprite* en concreto, el color negro (o el que decidamos) va a ser transparente, es decir, no debe ser mostrado. Esto se hace así:

```c
  SDL_Surface *peon_blanco;
  Uint32 color;	// Para definir el color de transparencia (donde proceda)

  // Cargamos la imagen del peón blanco
  peon_blanco = SDL_LoadBMP("peon_blanco.bmp");
  if (peon_blanco == NULL) {
     printf("Error al cargar el archivo peon_blanco.bmp");
     SDL_Quit();
     exit(-1);
  }
 
  // Definimos la transparencia (color negro = (0,0,0) )
  color = SDL_MapRGB(peon_blanco->format, 0, 0, 0);
  SDL_SetColorKey(cuadro1, SDL_SRCCOLORKEY | SDL_RLEACCEL, color);
```

Las imágenes cargadas en memoria deben ser liberadas antes de finalizar el programa con una llamada a SDL_FreeSurface(). Por ejemplo, para liberar la memoria ocupada por la imagen "tablero.bmp" que hemos cargado antes usaremos el puntero que obtuvimos al cargarla, así:

```c
SDL_FreeSurface(tablero);
```

**2. Mostrar imágenes en la pantalla**

Una vez cargada una imagen BMP en la memoria, podemos mostrarla en la pantalla a través del puntero *SDL_Surface* que obtuvimos al cargarla. Una imagen cargada puede ser mostrada todas las veces que queramos en cualquier posición de la pantalla.

Por ejemplo, para mostrar la imagen del tablero (que cargamos en un ejemplo del apartado anterior) haríamos lo siguiente (luego comentamos el código):

```c
  SDL_Rect rect;
  rect = (SDL_Rect) {10, 10, 400, 400};
  SDL_BlitSurface(tablero, NULL, pantalla, &rect);
  SDL_Flip(pantalla);
```

La variable *rect* es de tipo *SDL_Rect*, y define un área rectangular de la pantalla. El área rectangular empieza en las coordenadas (10, 10) (esquina superior izquierda de la pantalla) y mide 400 píxels de ancho y 400 de alto, es decir, termina en (410, 410).

*SDL_BlitSurface()* es la función que se encarga de mostrar en la pantalla un *sprite*. La variable *tablero* es de tipo *SDL_Surface*, y debe ser la que nos devolvió *SDL_LoadBMP()* al cargar la imagen del tablero. La variable *pantalla* también es una *SDL_Surface*, y debe ser la que nos devolvió *SDL_SetVideoMode()* al inicializar la pantalla gráfica. Ya dijimos que los punteros que nos devuelven estas funciones son imprescidibles y que debíamos definirlos como variables globales. La variable *rect* es el área rectangular que acabamos de definir.

Fíjate que *rect* es la que indica en qué lugar de la pantalla va a aparecer el *sprite*. En este ejemplo, aparecerá en (10,10). Se le han reservado 400x400 píxels para dibujarse, es decir, hasta la posición (410, 410). Si el *sprite* es más pequeño, no pasará nada (ocupará lo que mida realmente). Si es más grande, se truncará.

Por último, *SDL_Flip()* hace que lo que acabamos de dibujar se muestre realmente en la pantalla. Su efecto es parecido al de la función refresh() de ncurses. En realidad, todo lo que dibujamos se escribe en una zona de memoria específica y, al hacer *SDL_Flip()*, esa zona de memoria se vuelca sobre la memoria de vídeo, apareciendo todo en la pantalla. Esto representa el movimiento de gran cantidad de información entre distintas zonas de memoria, lo cual es un proceso relativamente lento. Por eso, si vamos a dibujar varios sprites consecutivos, es mejor hacer una sola vez *SDL_Flip()*, al final, cuando los hayamos dibujado todos. Llamar a *SDL_Flip()* después de dibujar cada sprite ralentizará notablemente el funcionamiento de nuestro programa.

#### Control del teclado

Para leer el teclado en una ventana gráfica creada con SDL *no* se pueden usar las funciones estándar (como *getchar()* o *gets()*), ni mucho menos las de *ncurses* (como *getstr()*). 

SDL solo permite **leer los caracteres de uno en uno**, y **no muestra eco** por la pantalla (si queremos eco, tenemos que mostrar los caracteres nosotros mismos después de leerlos).

Por lo demás, la forma de capturar un carácter tecleado es similar a la de *ncurses*, solo que un poco más complicada. A continuación se muestra un código de ejemplo:

```c
SDL_Event evento;	  	      // Para leer el teclado

// Leer teclado
if (SDL_PollEvent(&evento))            // Comprobar si se ha pulsado una tecla
{
   if (evento.type == SDL_KEYDOWN)     // Efectivamente, se ha pulsado una tecla
   {
       switch (evento.key.keysym.sym)  // Vamos a mirar qué ecla es
       {
           case SDLK_UP:     ...acciones...; break;	// Flecha arriba
           case SDLK_DOWN:   ...acciones...; break;	// Flecha abajo
           case SDLK_LEFT:   ...acciones...; break;	// Felcha izquierda
           case SDLK_RIGHT:  ...acciones...; break;	// Flecha derecha
           case SDLK_RETURN: ...acciones...; break;	// Intro 
           case SDLK_ESCAPE: ...acciones...; break;	// ESC
           case SDLK_m:      ...acciones...; break;	// Tecla "m" (menú)
        }
    }
}
```

Existen constantes para cualquiera de las otras teclas del teclado. Todas empiezan por *SDLK_*. Por ejemplo, la tecla "a" tendrá el código *SDLK_a*.

#### Definición de colores

Aunque a menudo trabajes con *sprites* basados en imágenes preexistentes, es posible que también necesites definir algún color para usarlo directamente sobre la pantalla gráfica (por ejemplo, para usar transparencias o para escribir un texto).

En SDL no hay colores predefinidos, como en *ncurses*. Los colores debemos definirlos nosotros mezclando los colores básicos RGB (rojo, verde y azul).

Hay dos formas de definir un color: con una variable de tipo *SDL_Color* o con una variable de tipo *Uint32*. El uso de una u otra dependerá de para qué queramos usar ese color:

**a) Con una variable de tipo SDL_Color**:

   ```c
   SDL_Color color;
   color = (SDL_Color) {50, 150, 200, 255};
   ```

   Los cuatro números definen el color. Deben ser números comprendidos entre 0 y 255. El primero es el nivel de rojo (R), el segundo el nivel de verde (G) y el tercero, el nivel de azul (B). El cuarto número es el brillo. El color definido en este ejemplo tiene mucho azul, bastante verde y poco rojo. El resultado debe ser un azul amarillento.

**b) Con una variable de tipo Uint32**:

   ```c
   Uint32 color;
   color = SDL_MapRGB(pantalla->format, 50, 150, 200);  
   ```
   
   En esta ocasión, *pantalla* debe ser un puntero a una imagen *SDL_Surface* que hayamos cargado previamente. Los tres valores siguientes son los niveles RGB. No hay nivel de brillo, porque éste se toma de la imagen apuntada por *pantalla*.

De las dos maneras se pueden definir colores para usarlos posteriormente. Si el color lo necesitamos para una transparencia, recurriremos al segundo método (de hecho, ya vimos un ejemplo de ello al estudiar cómo se cargaban y mostaban las imágenes en SDL; allí usamos el color negro como transparencia). Si el color lo necesitamos para escribir un texto en la pantalla gráfica, usaremos el primer método (como se podrá ver en el siguiente apartado)

#### Mostrar texto en la pantalla gráfica: instalación y uso de la librería SDL_TTF

La librería SDL no permite directamente la escritura de texto en la pantalla gráfica. Esto se debe a que la pantalla gráfica, por definición, no admite caracteres, sino únicamente imágenes.

Por fortuna, a la sombra de SDL se han creado multitud de librerías adicionales que, partiendo de SDL, complementan y mejoran sus prestaciones. Una de ellas es SDL_TTF.

La libería SDL_TTF permite cargar fuentes *true type* que estén guardadas en archivos .ttf y manejarlas como si fueran imágenes BMP en la pantalla gráfica generada por SDL. Necesitamos SDL_TTF, por lo tanto, para escribir los mensajes de usuario y las opciones del menú.

La **instalación** de la librería SDL_TTF es similar a la de SDL, tanto en Linux como en Windows, de modo que puedes remitirte al apartado correspondiente para recordar cómo se hacía. Lo mismo puede decirse en cuanto a la compilación y el enlace.

Igual que SDL, la librería SDL_TTF necesita ser **inicializada** antes de usarla, y **finalizada** antes de terminar el programa para liberar los recursos adquiridos.

Como SDL_TTF corre por debajo de SDL, debe ser inicializada después de SDL, y debe ser terminada antes que SDL. Observa cómo se hace en este ejemplo:

```c
  if(TTF_Init() == -1) {
    printf("Fallo al inicializar SDL_TTF");
    exit(-1);
  }  
```

Inmediatamente después, ya podemos cargar una fuente true type de un archivo TTF, así:

```c
  TTF_Font* fuente;
  ....
  fuente = TTF_OpenFont("arial.ttf", 14);
  if(fuente == NULL) {
    printf("Fallo al abrir la fuente");
    exit(-1);
  }
  TTF_SetFontStyle(fuente, TTF_STYLE_BOLD);
```

La variable *fuente* es un puntero a *TTF_Font*. Debe ser una variable global por el mismo motivo que las variables *SDL_Surface*. La función *TTF_OpenFont()* abre el archivo "arial.ttf" y carga el tipo de letra Arial en tamaño 14 para su uso en el programa. Después es conveniente comprobar que el puntero *fuente* contenga un valor válido y no NULL.

Por último, la función *TTF_SetFontStyle()* puede usarse para determinar el estilo de la fuente. Tenemos varias posibilidades: *TTF_STYLE_BOLD* (negrita), *TTF_STYLE_ITALIC* (cursiva), *TTF_STYLE_UNDERLINE* (subrayado) y *TTF_STYLE_NORMAL*. Si queremos combinar varios estilos, podemos separarlos por el operador "|". Por ejemplo, para poner la fuente en negrita y cursiva escribiríamos esto:

```c
  TTF_SetFontStyle(fuente, TTF_STYLE_BOLD | TTF_STYLE_ITALIC);
```

El proceso de **finalización** del SDL_TTF es inverso y complementario al de inicialización. Primero habrá que liberar todas las fuentes cargadas durante la inicialización, y luego hay que terminar el subsistema SDL_TTF:

```c
  TTF_CloseFont(fuente); 
  TTF_Quit();
```

La variable *fuente* será de tipo *TTF_Font*, y debe coincidir con la que nos devolvió la función *TTF_OpenFont()*. Esta operación la repetiremos con cada una de las fuentes que hayamos cargado.

Recuerda que todo esto debe hacerse ANTES de *SDL_Quit()*, ya que SDL_TTF depende de SDL.

#### Escribir texto con SDL_TTF

Todo esto lo hacemos con un objetivo: poder escribir texto en la pantalla gráfica y sustituir así todas las funciones *printw()* y similares.

Para escribir un texto hay que hacer dos cosas: **primero, convertirlo en una imagen; segundo, mostrar la imagen en la pantalla**.

La conversión de un texto en una imagen se hace con la función *TTF_Render()*:

```c
  SDL_Color color;
  SDL_Surface* txt_img;

  color = (SDL_Color) {255,100,100,255};
  txt_img = TTF_RenderText_Blended(fuente, "Hola mundo", color);
  if(txt_img == NULL) {
	printf("Fallo al renderizar el texto");
	exit(-1);
  }
```

Como ves, hay que hacer bastantes cosas para mostrar un texto en la pantalla gráfica, pero todo es acostumbrarse. Primero, hay que definir un color para el texto (cómo se definen los colores es algo que vimos en el epígrafe anterior). En este caso, hemos escogido un rojo brillante.

Después se invoca a *TTF_RenderText()*, pasándole como parámetros el puntero a la fuente que obtuvimos con *TTF_OpenFont()*, el texto que queremos mostrar y el color. La función nos devuelve un puntero de tipo *SDL_Surface* que, si recuerdas, es exactamente el mismo que usábamos con las imágenes cargadas desde un archivo BMP.

En realidad, la función *TTF_RenderText()* tiene tres formas:

* *TTF_RenderText_Solid()* - realiza una conversión del texto en imagen rápida pero de poca calidad.
* *TTF_RenderText_Shaded()* - la imagen resultante es de gran calidad pero tiene un recuadro negro alrededor
* *TTF_RenderText_Blended()* - la imagen resultante es de gran calidad y sin recuadro negro

En general preferiremos el modo *Blended*, que es el que proporciona mejores resultados. El modo *Shaded* se puede usar en determinados lugares (si no hay otra imagen debajo del texto). El modo *Solid* sólo debe usarse si hay que mostrar mucho texto y el modo *Blended* se revela demasiado lento.

Hasta aquí, sólo hemos convertido el texto "Hola mundo" en una imagen, pero aún no la hemos mostrado en la pantalla. Para hacerlo procederemos como con cualquier otra imagen:

```c
  // Mostramos el texto como si fuera una imagen
  rect = (SDL_Rect) { 500, 280, 100, 30 };
  SDL_BlitSurface(txt_img, NULL, pantalla, &rect);	
  SDL_Flip(scr);
```

Se supone que *rect* es de tipo *SDL_Rect* y que pantalla es el puntero a *SDL_Surface* que nos devolvió *SDL_SetVideoMode()* al inicializar SDL. Así, el texto "Hola mundo" se mostrará en la posición (500, 280) de la pantalla gráfica, reservándose para él 100 píxels de ancho y 30 de alto.

## 9.3. Escribiendo programas en C

Ya conocemos cómo se manejan los principales elementos de un programa con C: variables, instrucciones de control, asignaciones, funciones, etc.

Ahora nos queda saber cómo juntamos todo eso para escribir nuestros programas, ¿no te parece?

### 9.3.1. Estructura de un programa en C

Ya estamos en condiciones de echar un vistazo a cual será el aspecto de (casi) todos los programas que escribamos en C.

Todo programa C, desde el más pequeño hasta el más complejo, tiene un **programa principal** ubicado en la función ***main()***. 

Además, por encima de *main()* deben aparecer los **prototipos de funciones** (y esto implica a los archivos de cabecera, si se utilizan funciones de librería) y las variables y constantes globales, si las hay. Por debajo de *main()* encontraremos el código de las funciones de usuario.

Por lo tanto, la **estructura habitual de nuestros programas en C** debería ser esta: 

```c
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
```

### 9.3.2. Caja de herramientas

¿Qué necesitamos para comenzar a escribir programas en C? ¿Tendrás que instalar un montón de programas de desarrollo en tu ordenador?

La verdad es que no. Para desarrollar con Javascript basta con que tengas instalado:

* **Un editor de texto**. No te sirve Microsoft Word ni Libreoffice Writer. Tiene que ser un editor de texto *plano*, es decir, que no introduzca información de formato en el archivo. Solo el texto.

   Existen muchísimos editores de estas características, porque son programas muy simples y livianos. El **bloc de notas** de Windows o el editor **gedit** de los sistemas Linux con escritorio Gnome (como Educandos) son dos de ellos.

   Un editor de texto para programación que ha tenido un crecimiento espectacular en los últimos años a nivel aficionado y profesional es **[Visual Studio Code](https://code.visualstudio.com/)**. Es multiplataforma (tiene versiones para Windows, Linux y Mac) y de código abierto. Y es una auténtica maravilla, así que te recomiendo lo instales (¡siempre desde los repositorios de tu distribución Linux o desde la web oficial si trabajas con Windows, por favor!) y lo instales.

   Para programar en C con Visual Studio Code, tendrás que instalar las extensiones para C/C++, pero no te preocupes porque es muy fácil y no tardarás más de un minuto. En los ejercicios propuestos lo haremos.

* **Un compilador de C/C++**. Todos los sistemas Linux llevan instalador un compilador de C muy popular llamado **gcc**. Si trabajas en Windows, lo más recomendable es que instales **MinGW**, una versión de gcc para Windows. Descárgala de la [web del fabricante](https://www.mingw-w64.org/) y sigue las instrucciones de instalación. 

   Nota: en Windows tendrás agregar la ruta hasta el ejecutable de Mingw en el PATH del sistema. La forma exacta de conseguir esto puede diferir según tu versión de Windows, y deberías buscar ayuda si no sabes cómo hacerlo (obviamente, este no es libro sobre Windows). En los sistemas Linux, esto no será necesario.

### 9.3.3. Flujo de trabajo

Cuando se trabaja con C, la implementación de un programa suele dividirse en varias subfases: edición, compilación, enlace y depuración. Te las describo brevemente:

1. **Edición del código fuente**. Editar consiste en escribir el código fuente del programa en el lenguaje seleccionado, en nuestro caso C, con un editor de texto plano como **Visual Studio Code**.
2. **Compilación**. Una vez escrito el programa, debe traducirse a binario en un proceso llamado *compilación*. Esto puede hacerse desde la línea de comandos, aunque algunos editores de texto permiten hacerlo desde el propio editor. Es el caso de *Visual Studio Code*. Si has instalado las extensiones para C/C++, bastará con que vayas al menú **Run** o que pulses el **botón "Play"** que aparece arriba y a la derecha del editor.
3. **Enlace**. Si tu programa es muy complejo, tu código fuente ocupará varios archivos. En tal caso, hay que compilarlos de uno en uno y después *enlazarlos* entre sí para generar un único programa ejecutable. No te preocupes de momento por esto, porque tus primeros programas estarán en un solo archivo y, además, cuando llegue el momento, *Visual Studio Code* se encargará de hacer el enlace automáticamente por nosotros.de librerías entre diferentes aplicaciones.
4. **Depuración**. Ningún programa está bien escrito a la primera. Nunca. Lo normal es que el compilador te informe de que hay multitud de errores en tu código fuente. Tendrás que leer cuidadosamente los mensajes de error para corregirlos. Por fortuna, el compilador te informará de la línea exacta donde localizó el error, e incluso te dirá de qué tipo de error se trata.

   Una vez corregidos los errores de escritura, cuando el programa empiece a funcionar, es posible que no haga exactamente lo que tú pretendías que hiciera. También tendrás que corregir estos errores de ejecución.

   XXX *captura de pantalla de extensión C++ y botón "Play"* XXX

### 9.3.4. Dónde y cómo escribir el código fuente

Los programas escritos en C suelen guardarse en dos tipos de archivo:

* **Archivos con extensión .c**. Estos archivos contienen el grueso del código fuente. En particular, la función *main()*, que es necesaria en cualquier programa en C.
* **Archivos con extensión .h**. Estos archivos contienen los prototipos de funciones y otras definiciones necesarias para que el programa funcione bien. Al principio, no escribirás ningún archivo de este tipo, pero sí que tendrás que incluir (con *#include*) muchos de ellos.

## 9.4. C avanzado: punteros y estructuras de datos

XXX *Texto pendiente de revisar* XXX

 1  Punteros
Comprender y usar correctamente los punteros es con seguridad lo más complicado del lenguaje C, pero también se trata de un mecanismo muy poderoso. Tan poderoso que un simple puntero descontrolado (hay quien acertadamente los llama "punteros locos") puede provocar que el programa se cuelgue irremediablemente o incluso que falle todo el sistema.
Todos los programadores con cierta experiencia en C reconocerán que, a veces, programar con punteros es como quedarse atrapado en un ascensor con un montón de serpientes pitón enloquecidas. Pero, cuando se les coge el tranquillo y se les ata en corto, permiten hacer auténticas virguerías.
 1.1  Comprendiendo los punteros
Dentro de la memoria del ordenador, cada dato almacenado ocupa una o más celdas contiguas de memoria. El número de celdas de memoria requeridas para almacenar un dato depende de su tipo. Por ejemplo, un dato de tipo entero puede ocupar 16 bits (es decir, 2 bytes), mientras que un dato de tipo carácter ocupa 8 bits (es decir, 1 byte).
Un puntero no es más que una variable cuyo contenido no es un dato, sino la dirección de memoria donde está almacenado un dato.
Veámoslo a través de un ejemplo. Imaginemos que v es una variable de tipo carácter y que, por tanto, necesita 1 byte para ser almacenada. La declaración e inicialización de la variable será como la siguiente:
char v;
v = 'A';
Al ejecutar este código, el sistema operativo asigna automáticamente una celda de memoria para el dato. Supongamos que la celda asignada tiene la dirección 1200. Al hacer la asignación v = 'A', el sistema almacena en la celda 1200 el valor 65, que es el código ASCII de la letra 'A':
Dirección de memoria
Contenido
1198

1199

1200
65
1201

...
...
Cuando usamos la variable v a lo largo del programa, el sistema consulta el dato contenido en la celda de memoria asignada a la variable. Esa celda será siempre la misma a lo largo de la ejecución: la 1200. Por ejemplo, al encontrar esta instrucción:
printf("%c", v);
.. el compilador acude a la celda 1200 de la memoria, consulta el dato almacenado en ella en ese momento y sustituye la variable v por ese dato.
El programador no tiene modo de saber en qué posición de memoria se almacena cada dato, a menos que utilice punteros. Los punteros sirven, entonces, para conocer la dirección de memoria donde se almacena el dato, y no el dato en sí. 
La dirección ocupada por una variable v se determina escribiendo &v. Por lo tanto, & es un operador unario, llamado operador dirección, que proporciona la dirección de una variable. 
La dirección de v se le puede asignar a otra variable mediante esta instrucción:
char* p;
p = &v; 
Resultará que esta nueva variable es un puntero a v, es decir, una variable cuyo contenido es la dirección de memoria ocupada por la variable v. Representa la dirección de v y no su valor. Por lo tanto, el contenido de p será 1200, mientras que el contenido de v será 65.
El dato almacenado en la celda apuntada por la variable puntero puede ser accedido mediante el operador asterisco aplicado al puntero. Así pues, la expresión *p devuelve el valor 65, que es el contenido de la celda apuntada por p. El operador * es un operador unario, llamado operador indirección, que opera sólo sobre una variable puntero.
Los operadores monarios & y * son miembros del mismo grupo de precedencia que los otros operadores monarios: -,++,--,!,etc. Hay que recordar que este grupo de operadores tiene mayor precedencia que el de los operadores aritméticos y la asociatividad de los operadores monarios es de derecha a izquierda.
Resumiendo: podemos tener variables "normales" y utilizar el operador & para conocer su dirección de memoria. O podemos tener variables puntero, que ya son en sí mismas direcciones de memoria, y utilizar el operador * para acceder al dato que contienen. Así pues:
    • El operador dirección (&) sólo puede actuar sobre variables que no sean punteros. En el ejemplo anterior, la variable v vale 65 y la expresión &v vale 1200.
    • El operador indirección (*) sólo puede actuar sobre variables que sean punteros. En el ejemplo anterior, la expresión *p vale 65 y la variable p vale 1200.
Las variables puntero pueden apuntar a direcciones donde se almacene cualquier tipo de dato: enteros, flotantes, caracteres, cadenas, arrays, estructuras, etc. Esto es tremendamente útil y proporciona una enorme potencia al lenguaje C, pero también es una fuente inagotable de errores de programación difíciles de detectar y corregir, como iremos viendo en los siguientes temas  
 1.2  Declaración e inicialización de punteros
Las variables de tipo puntero, como cualquier otra variable, deben ser declaradas antes de ser usadas. Cuando una variable puntero es definida, el nombre de la variable debe ir precedido por un *. El tipo de dato que aparece en la declaración se refiere al tipo de dato que se almacena en la dirección representada por el puntero, en vez del puntero mismo. Así, una declaración de puntero general es:
tipo_dato *puntero;
donde puntero es la variable puntero y tipo_dato el tipo de dato apuntado por el puntero.
Por ejemplo:
int *numero;
char *letra;
La variable numero no contiene un número entero, sino la dirección de memoria donde se almacenará un número entero. La variable letra tampoco contiene un carácter, sino una dirección de memoria donde se almacenará un carácter.
Cuando un puntero ha sido declarado pero no inicializado, apunta a una dirección de memoria indeterminada. Si tratamos de usarlo en esas condiciones obtendremos resultados impredecibles (y casi siempre desagradables). Antes de usar cualquier puntero hay que asegurarse de que está apuntando a una dirección válida, es decir, a la dirección de alguna variable del tipo adecuado. Por ejemplo, así:
int *numero;
int a;
numero = &a;
El puntero numero ahora sí está en condiciones de ser usado, porque está apuntado a la dirección de la variable a, que es de tipo int, como el puntero.
Otra posibilidad es hacer que un puntero apunte a NULL. El identificador NULL es una constante definida en el lenguaje que indica que un puntero no está apuntando a ninguna dirección válida y que, por lo tanto, no se debe utilizar.
 1.3  Asignación de punteros
Se puede asignar una variable puntero a otra siempre que ambas apunten al mismo tipo de dato. Al realizar la asignación, ambos punteros quedarán apuntando a la misma dirección de memoria.
Observa este ejemplo y trata de determinar qué resultado se obtiene en la pantalla (antes de leer la solución que aparece más abajo):
int a, b, c;
int *p1, *p2;
a = 5;
p1 = &a;	/* p1 apunta a la dirección de memoria de la variable a */
p2 = p1;	/* a p2 se le asigna la misma dirección que tenga p1 */
b = *p1;
c = *p1 + 5;	/* Suma 5 a lo que contenga la dirección apuntada por p1 */
printf("%i %i %i %p %p", a, b, c, p1, p2);
En la pantalla se imprimirá “5 5 10”, que es el contenido de las variables a, b y c al terminar la ejecución de este bloque de instrucciones, y la dirección a la que apuntan p1 y p2, que debe ser la misma. Observa que con printf y la cadena de formato "%p" se puede mostrar la dirección de memoria de cualquier variable.
 1.4  Aritmética de punteros
Con las variables de tipo puntero sólo se pueden hacer dos operaciones aritméticas: sumar o restar a un puntero un número entero, y restar dos punteros. Pero el resultado de esas operaciones no es tan trivial como puede parecer. Por ejemplo, si sumamos un 1 a un puntero cuyo valor sea 1200, el resultado puede ser 1201… ¡pero también puede ser 1202 ó 1204! Esto se debe a que el resultado depende del tipo de dato al que apunte el puntero.
Sumar o restar un valor entero a un puntero
Al sumar un número entero a un puntero se incrementa la dirección de memoria a la que apunta. Ese incremento depende del tamaño del tipo de dato apuntado.
Si tenemos un puntero p y lo incrementamos en una cantidad entera N, la dirección a la que apuntará será: 
dirección_original + N * tamaño_del_tipo_de_dato
Por ejemplo, imaginemos un puntero p a carácter que se incrementa en 5 unidades, así:
char* p;
p = p + 5;
Supongamos que p apunta a la dirección de memoria 800. Como cada carácter ocupa 1 byte, al incrementarlo en 5 unidades, p apuntará a la dirección 805.
Veamos ahora que pasa si, por ejemplo, el puntero p apunta a un número entero:
int* p;
p = p + 5;
Si la dirección inicial de p es también la 800, al incrementarlo en 5 unidades pasará a apuntar a la dirección 810 (suponiendo que cada entero ocupe 2 bytes).
Todo esto también explica qué ocurre cuando se resta un número entero de un puntero, sólo que entonces las direcciones se decrementan en lugar de incrementarse.
A los punteros también se les puede aplicar las operaciones de incremento (++) y decremento (--) de C, debiendo tener el programador en cuenta que, según lo dicho hasta ahora, la dirección apuntada por el puntero se incrementará o decrementará más o menos dependiendo del tipo de dato apuntado.
Por ejemplo, si los datos de tipo int ocupan 2 bytes y el puntero p apunta a la dirección 800, tras la ejecución de este fragmento de código, el puntero p quedará apuntado a la dirección 802:
int *p;
p++;
Resta de dos punteros
La resta de punteros se usa para saber cuantos elementos del tipo de dato apuntado caben entre dos direcciones diferentes.
Por ejemplo, si tenemos un vector de números reales llamado serie podemos hacer algo así:
float serie[15];
int d;
float *p1, *p2;
p1 = &tabla[4];
p2 = &tabla[12];
d = p1 – p2;
El puntero p1 apunta al quinto elemento del vector, y el puntero p2, al decimotercero. La restar los dos punteros obtendremos el valor 8, que es el número de elementos de tipo float que pueden almacenarse entre las direcciones p1 y p2.
 1.5  Punteros y arrays
Punteros y arrays de una dimensión
Los punteros y los arrays tienen una relación muy estrecha, ya que el nombre de un array es en realidad un puntero al primer elemento de ese array. Si x es un array undimensional, la dirección del primer elemento puede ser expresada como &x[0] o simplemente como x. La dirección del elemento i-ésimo se puede expresar como &x[i] o como (x+i).
(En este caso, la expresión (x+i) no es una operación aritmética convencional, sino una operación con punteros, de cuyas peculiaridades ya hemos hablado en un epígrafe anterior)
Si &x[i] y (x+i) representan la dirección del i-ésimo elemento de x, podemos decir que x[i] y *(x+i) representan el contenido de esa dirección, es decir, el valor del i-ésimo elemento de x. Observa que la forma x[i] es la que hemos estado utilizando hasta ahora para acceder a los elementos de un vector.
Los arrays, por lo tanto, pueden utilizarse con índices o con punteros. Al programador suele resultarle mucho más cómodo utilizar la forma x[i] para acceder al elemento i-ésimo de un array. Sin embargo, hay que tener en cuenta que la forma *(x+i) es mucho más eficiente que x[i], por lo que suele preferirse cuando la velocidad del ejecución es un factor determinante.
Punteros y arrays multidimensionales
Un array multidimensional es en realidad una colección de varios arrays unidimensionales (vectores). Por tanto, se puede definir un array multidimensional como un puntero a un grupo contiguo de arrays unidimensionales. 
El caso más simple de array de varias dimensiones es el bidimiensional. La declaración de un array bidimensional la hemos escrito hasta ahora como:
tipo_dato variable [expresión1][expresión2]
Pero también puede expresarse así:
tipo_dato (*variable) [expresión2]
Los paréntesis que rodean al puntero deben estar presentes para que la sintaxis sea correcta.
Por ejemplo, supongamos que x es un array bidimensional de enteros con 10 filas y 20 columnas. Podemos declarar x como:
int x[10][20];
Y también como:
int (*x)[20];
En la segunda declaración, x se define como un puntero a un grupo de array unidimensionales de 20 elementos enteros. Así x apunta al primero de los arrays de 20 elementos, que es en realidad la primera fila (fila 0) del array bidimensional original. Del mismo modo (x+1) apunta al segundo array de 20 elementos, y así sucesivamente.
Por ejemplo, el elemento de la columna 2 y la fila 5 puede ser accedido así:
x[2][5];
Pero también así:
*(*(x+2)+5);
Esta instrucción parece muy complicada pero es fácil de desentrañar:
    • (x+2) es un puntero a la columna 2
    • *(x+2) es el objeto de ese puntero y refiere a toda la columna. Como la columna 2 es un array unidimensional,  *(x+2) es realmente un puntero al primer elemento de la columna 2.
    • (*(x+2)+5) es un puntero al elemento 5 de la columna 2.
    • El objeto de este puntero *(*(x+2)+5) refiere al elemento 5 de la columna 2.
 1.6  Arrays de punteros
Un array multidimensional puede ser expresado como un array de punteros en vez de como un puntero a un grupo contiguo de arrays. En términos generales un array bidimensional puede ser definido como un array unidimensional de punteros escribiendo
tipo_dato *variable[expresión1]
...en lugar de la definición habitual, que sería:
tipo_dato variable[expresión1][expresión2]
Observa que el nombre del array precedido por un asterisco no está cerrado entre paréntesis. Ese asterisco que precede al nombre de la variable establece que el array contendrá punteros.
Por ejemplo, supongamos que x es un array bidimensional de 10 columnas y 25 filas. Se puede definir x como un array unidimensional de punteros escribiendo:
int *x[25];
Aquí x[0] apunta al primer elemento de la primera columna, x[1] al primer elemento de la segunda columna, y así sucesivamente. Observa que el número de elementos dentro de cada fila no está especificado explícitamente. Un elemento individual del array, tal com x[2][5] puede ser accedido escribiendo:
*(x[2]+5)
En esta expresión, x[2] es un puntero al primer elemento en la columna 2, de modo que (x[2]+5) apunta al elemento 5 de la columna 2. El objeto de este puntero, *(x[2]+5), refiere, por tanto, a x[2][5].
Los arrays de punteros ofrecen un método conveniente para almacenar cadenas. En esta situación cada elemento del array es un puntero que indica dónde empieza cada cadena.
 1.7  Paso de punteros como parámetros
A menudo los punteros son pasados a las funciones como argumentos. Esto permite que datos de la porción de programa desde el que se llama a la función sean accedidos por la función, alterados dentro de ella y devueltos de forma alterada. Este uso de los punteros se conoce como paso de parámetros por variable o referencia y lo hemos estado utilizando hasta ahora sin saber muy bien lo que hacíamos.
Cuando los punteros son usados como argumento de una función, es necesario tener cuidado con la declaración y uso de los parámetros dentro de la función. Los argumentos formales que sean punteros deben ir precedidos por un asterisco. Observa detenidamente el siguiente ejemplo:
#include <stdio.h>
void funcion1(int, int);
void funcion2(int*, int*);

int main(void)
{
  int u, v;
  u = 1;
  v = 3;
  funcion1(u,v);
  printf("Después de la llamada a funcion1:  u=%d v=%d\n", u, v);
  funcion2(&u,&v);
  printf("Después de la llamada a funcion2:  u=%d v=%d\n", u, v);
}

void funcion1(int u, int v)	
{
   u=0;
   v=0;
}

void funcion2(int *pu, int *pv)
{
   *pu=0;
   *pv=0;
}
La función de nombre funcion1 utiliza paso de parámetros por valor. Cuando es invocada, los valores de las variables u y v del programa principal son copiados en los parámetros u y v de la función. Al modificar estos parámetros dentro de la función, el valor de u y v en el programa principal no cambia. 
En cambio, funcion2 utiliza paso de parámetros por variable (también llamado paso de parámetros por referencia o por dirección). Lo que se pasa a la función no es el valor de las variables u y v, sino su dirección de memoria, es decir, un puntero a las celdas de memoria donde u y v están almacenadas. Dentro de la función, se utiliza el operador asterisco para acceder al contenido de pu y pv y, en consecuencia, se altera el contenido de las posiciones de memoria apuntadas por pu y pv. El resultado es que las variables u y v del programa principal quedan modificadas. 
Por lo tanto, la salida del programa debe ser:
Después de la llamada a funcion1:  u=1 v=3
Después de la llamada a funcion2:  u=0 v=0
Recuerda que la función scanf() requiere que sus argumentos vayan precedidos por &, mientras que printf() no lo necesitaba. Hasta ahora no podíamos comprender por qué, pero ahora podemos dar una razón: scanf() necesita que sus argumentos vayan precedidos del símbolo & porque necesita las direcciones de los datos que van a ser leídos, para poder colocar en esas posiciones de memoria los datos introducidos por teclado. En cambio, printf() no necesita las direcciones, sino únicamente los valores de los datos para poder mostrarlos en la pantalla.
Al estudiar los arrays y las estructuras ya vimos en detalle cómo se deben pasar como parámetros a las funciones. Recuerda que los arrays siempre se pasan por variable y no es necesario usar el símbolo & en la llamada, ya que el propio nombre del array se refiere, en realidad, a la dirección del primer elemento.
 1.8  Devolución de punteros
Una función también puede devolver un puntero. Para hacer esto, la declaración de la función debe indicar que devolverá un puntero. Esto se realiza precediendo el nombre de la función con un asterisco. Por ejemplo:
double *funcion(argumentos);
Cuando esta función sea invocada, devolverá un puntero a un dato de tipo double, y por lo tanto debe ser asignada a una variable de ese tipo. Por ejemplo, así:
double *pf;
pf = funcion(argumentos);
printf("%lf", *pf);
 1.9  Punteros a funciones
Las funciones de C, como todo el código de todos los programas que se ejecutan en el ordenador, también ocupan unas posiciones concretas de la memoria principal. Por lo tanto, es posible disponer de un puntero a una función, es decir, de una variable que contenga la dirección de memoria en la que comienza el código de una función.
Aunque no vamos a usar esta avanzada posibilidad de C, se menciona aquí como información para el lector que desee ampliar sus conocimientos. La declaración de un puntero a función se realiza así:
tipo_de_dato (*nombre_puntero) (lista_de_parámetros);
No debe confundirse con la declaración de una función que devuelve un puntero:
tipo_de_dato* nombre_función (lista_de_parámetros);
Posteriormente, la dirección de la función puede asignarse al puntero para luego ser invocada a través del puntero, en lugar de usar una llamada convencional:
nombre_puntero = nombre_función;	/* Asignación al puntero de la dirección de la función */
(*nombre_puntero)(lista_de_parámetros);	/* Invocación de la función */
 1.10  Punteros a punteros
Un último aspecto (a la vez confuso y potente) de los punteros es la posibilidad de definir punteros que, a su vez, apunten a otros punteros. Esto no es un trabalenguas, sino que, técnicamente, se denomina indirección múltiple. La definición de un puntero a puntero se hace así:
tipo_de_dato **nombre_puntero;
Por ejemplo, el resultado del siguiente fragmento de código en C debe ser que se imprima el número 15 en la pantalla:
int n;
int* p1;
int** p2;
p1 = &n;	/* p1 contiene la dirección de n */
p2 = &p1;	/* p2 contiene la dirección de p1 */
**p2 = 15;
printf("%i", n);
 2  Gestión dinámica de la memoria
Según hemos visto hasta ahora, la memoria reservada para cada variable se define en el momento de escribir el código del programa. Por ejemplo, si declaramos una variable de tipo int, ésta tendrá asignados 2 bytes de memoria (aunque esa cantidad puede variar dependiendo del compilador y del sistema operativo). Entonces, si declaramos un array de 100 números enteros, el array tendrá reservados 200 bytes de memoria.
¿Pero qué ocurre si no sabemos de antemano cuántos elementos puede llegar a tener el array?
Por ejemplo, imaginemos un problema consistente en leer por teclado (u otro dispositivo de entrada) una cantidad indefinida de números para almacenarlos en un array y luego hacer ciertas operaciones con ellos. ¿De qué tamaño podemos definir el array? ¿De 100 elementos? ¿Y si el usuario introduce 101 elementos?
Podemos pensar, entonces, que será suficiente con definir el array muy grande: de 1000 elementos, o de 5000, o de 10000… pero siempre existe la posibilidad de que el programa no funcione correctamente por desbordamiento del espacio reservado a las variables. Y, por otra parte, si definimos un array de enormes dimensiones y luego la mayoría de sus posiciones no se utilizan, estaremos desperdiciando los recursos de la máquina.
Para evitar esto existe la asignación dinámica de memoria, que consiste en reservar memoria para las variables en tiempo de ejecución, es decir, mientras el programa está funcionando. Así, es posible "estirar" o "encoger" sobre la marcha el espacio reservado para el array, dependiendo de las necesidades de cada momento, y no limitarse a los 100, 1000 ó 10000 elementos que definió el programador al escribir el código.
Veremos enseguida que, para manejar la memoria dinámicamente, es imprescindible el uso de punteros. De hecho, este es el mejor fruto que vamos a obtener de ellos.
 2.1  Reserva dinámica de memoria. Arrays dinámicos.
Utilizaremos el ejemplo de los arrays por ser la estructura de datos más simple y fácil de entender, pero lo dicho aquí es extensible a otras estructuras de datos diferentes. De hecho, dedicaremos el resto del tema a estudiar otras estructuras de datos dinámicas más complejas.
Ya que un nombre de array es en realidad un puntero a su primer elemento, es posible definir un array como una variable puntero en vez de como un array convencional. Así, estas dos definiciones sirven para un vector de números enteros:
int vector1[100];
int* vector2;
El vector1 se define del modo convencional de un array. Esto produce la reserva de un bloque fijo de memoria al empezar la ejecución del programa lo suficientemente grande como para almacenar 100 números enteros.
El vector2 se define como puntero a entero. En este caso, no se reserva ninguna cantidad de memoria para almacenar los números enteros. 
Si intentamos acceder a los elementos de los vectores obtendremos resultados diferentes:
vector1[5] = 83;
vector2[5] = 27;	/* Esto es un error */
La primera asignación funcionará correctamente, ya que el quinto elemento del vector1 tiene un espacio de memoria asignado. La segunda asignación producirá un efecto impredecible, ya que vector2 no tiene ningún espacio de memoria asignado y, por lo tanto, el dato 27 se escribirá en una posición de memoria correspondiente a otro dato u otro programa. La consecuencia puede llegar a ser bastante desagradable.
Se necesita, pues, reservar un fragmento de memoria antes de que los elementos del array sean procesados. Tales tipos de reserva se realizan mediante la función malloc() o alguna de sus variedades. Observa bien su uso en este ejemplo:
int *x;
x = (int *) malloc (100 * sizeof(int));
La función malloc() reserva un especio de memoria consistente en 100 veces el tamaño de un número entero. Fíjate bien en el uso del sizeof(int): se trata de un operador unario que devuelve el tamaño de un tipo de dato cualquiera, tanto simple como complejo.
Suponiendo que sizeof(int) fuera 2 (es decir, que cada número de tipo int ocupase 2 bytes), lo que se le está pidiendo a malloc() es que reserve 100 * 2 bytes, es decir, 200 bytes de memoria.
Además, es necesario usar el molde (int *), ya que malloc() devuelve un puntero sin tipo (es decir, un puntero a void), así que hay que convertirlo a puntero a entero antes de asignarlo a la variable x, que efectivamente es un puntero a entero.
De esta manera, la variable vector2 pasa a ser lo que podemos denominar un array dinámico, en el sentido de que se comporta como un array y puede usarse como tal, pero su tamaño ha sido definido durante la ejecución del programa (más adelante, en el mismo programa, podemos redefinir el tamaño del array para acortarlo o alargarlo)
Si la función malloc() falla devolverá un puntero a NULL. Utilizar un puntero a NULL es la forma más segura de estrellar el programa, así que siempre debemos comprobar que el puntero devuelto es correcto. Una vez hecho esto, podemos utilizar x con toda tranquilidad como si fuera un array de 100 números enteros. Por ejemplo:
int *x, i;
x = (int *) malloc (100 * sizeof(int));
if (x == NULL)
  printf("Error en la asignación de memoria");
else
{
  printf("Se ha reservado con éxito espacio para 100 números");
  for (i=0; i<100; i++)
  {
	printf("Introduzca un número:");
	scanf("%i", &x[i]);
  }
}
 2.2  Liberación de memoria
El programador debe tener dos precauciones básicas a la hora de manejar la memoria dinámicamente:
    • Asignar memoria a un puntero antes de usarlo con malloc() u otra función similar
    • Liberar la memoria asignada, cuando ya no va a usarse más, con free() u otra función similar.
Si no se libera la memoria asignada a un puntero, teóricamente no ocurre nada grave, salvo que podemos terminar por agotar la memoria disponible si reservamos continuamente y nunca liberamos. Es, en cualquier caso, una costumbre muy saludable.
Para liberar la memoria reservada previamente con malloc() u otra función de su misma familia, se utiliza la función free(). Observa su uso en este ejemplo:
int *x, i;
x = (int *) malloc (100 * sizeof(int));
... instrucciones de manipulación de x ...
free(x);
Toda la memoria reservada con malloc() quedará liberada después de hacer free() y se podrá utilizar para guardar otros datos o programas. El puntero x quedará apuntado a NULL y no debe ser utilizado hasta que se le asigne alguna otra dirección válida.
 2.3  Funciones básicas para la gestión dinámica de la memoria
Además de malloc() y free() existen otras funciones similares pero con pequeñas diferencias. A continuación resumimos las más usuales y mostramos un ejemplo de su uso. 
Pero antes haremos una advertencia: todas las funciones de reserva de memoria devuelven un puntero a NULL si no tienen éxito. Por lo tanto, deben ir seguidas de un condicional que compruebe si el puntero apunta a NULL antes de utilizarlo: no nos cansaremos de repetir que utilizar un puntero a NULL es una manera segura de estrellar el programa.

calloc()
Reserva un bloque de memoria para almacenar num elementos de tam bytes y devuelve un puntero void al comienzo del bloque. La sintaxis es:
void* calloc(num, tam);
El siguiente ejemplo reserva espacio para 35 números enteros:
int* p;
p = (int*) calloc(35, sizeof(int));
free()
Libera el bloque de memoria apuntado por un puntero y que previamente había sido reservado.
free(puntero);
malloc()
Reserva un bloque de memoria de tam bytes y devuelve un puntero void al comienzo del mismo, según esta sintaxis:
void* malloc(tam);
Por ejemplo, para reservar espacio para una cadena de 100 caracteres:
char* texto;
texto = (char*) malloc(100 * sizeof(char));
realloc()
Cambia el tamaño de un bloque de memoria apuntado por puntero. Dicho bloque ha debido ser previamente asignado con malloc() u otra función similar. El nuevo tamaño será de tam bytes. Devuelve un puntero void al comienzo del bloque, y la sintaxis es:
void* realloc(puntero, tam);
En el siguiente ejemplo, se reserva espacio para 100 caracteres, pero luego se modifica el tamaño del bloque para dar cabida hasta 500 caracteres:
char* texto;
texto = (char*) malloc(100 * sizeof(char));
/* Aquí irían las instrucciones que utilicen el puntero texto
   con un tamaño de 100 caracteres */
texto = (char*) realloc(texto, 500 * sizeof(char));
/* A partir de aquí, el mismo puntero texto puede usarse para
   manejar hasta 500 caracteres */
 3  Introducción a las estructuras dinámicas
Las estructuras estáticas tienen una importante limitación: no pueden cambiar de tamaño durante la ejecución. Por ejemplo, los arrays están compuestos por un determinado número de elementos y ese número se decide durante la codificación del programa, no pudiendo cambiarse en tiempo de ejecución.
En muchas ocasiones se necesitan estructuras que puedan cambiar de tamaño durante la ejecución del programa. Esas son las estructuras dinámicas. 
C no dispone de estructuras dinámicas predefinidas, por lo que es tarea del programador construirlas basándose en estructuras estáticas y gestión dinámica de memoria. Además, habrá que programar una colección de funciones que manipulen esas estructuras.
Ya que el programador se toma la molestia de implementar las estructuras y sus funciones, lo más habitual es que se asegure de que todo sea reutilizable, de manera que pueda usarlo en otros programas. A lo largo del tema seguiremos este principio.
Como veremos, para desarrollar las estructuras dinámicas es imprescindible usar punteros y asignación dinámica de memoria, así que deberías tener bastante claros los dos primeros epígrafes de este tema antes de continuar. 
Nodos
El fundamento de las estructuras de datos dinámicas es una estructura estática a la que llamaremos nodo o elemento. Éste incluye los datos con los que trabajará nuestro programa y uno o más punteros al mismo tipo nodo.
Por ejemplo, si la estructura dinámica va a guardar números enteros, el nodo puede tener esta forma:
struct s_nodo {
   int dato;
   struct nodo *otro_nodo;
};
El campo otro_nodo apuntará a otro objeto del tipo nodo. De este modo, cada nodo puede usarse como un ladrillo para construir estructuras más complejas, y cada uno mantendrá una relación con otro u otros nodos (esto dependerá del tipo de estructura dinámica, como veremos). 
A lo largo del tema usaremos una representación gráfica para mostrar las estructuras de datos dinámicas. El nodo anterior se representará así:

En el rectángulo de la izquierda se representa el dato contenido en el nodo (en nuestro ejemplo, un número entero). En el rectángulo de la derecha se representa el puntero, que apuntará a otro nodo.
Tipos de estructuras dinámicas
Dependiendo del número de punteros que haya en cada nodo y de las relaciones entre ellos, podemos distinguir varios tipos de estructuras dinámicas. A lo largo del tema veremos sólo las estructuras básicas, pero aquí las vamos a enumerar todas:
    • Listas abiertas: cada elemento sólo dispone de un puntero, que apuntará al siguiente elemento de la lista. 
    • Pilas: son un tipo especial de lista, conocidas como listas LIFO (Last In, First Out: el último en entrar es el primero en salir). Los elementos se "amontonan" o apilan, de modo que sólo el elemento que está encima de la pila puede ser leído, y sólo pueden añadirse elementos encima de la pila. 
    • Colas: otro tipo de listas, conocidas como listas FIFO (First In, First Out: El primero en entrar es el primero en salir). Los elementos se almacenan en una lista, pero sólo pueden añadirse por un extremo y leerse por el otro. 
    • Listas circulares: o listas cerradas, son parecidas a las listas abiertas, pero el último elemento apunta al primero. De hecho, en las listas circulares no puede hablarse de "primero" ni de "último". 
    • Listas doblemente enlazadas: cada elemento dispone de dos punteros, uno apunta al siguiente elemento y el otro al elemento anterior. Al contrario que las listas abiertas, estas listas pueden recorrerse en los dos sentidos. 
    • Árboles: cada elemento dispone de dos o más punteros, pero las referencias nunca son a elementos anteriores, de modo que la estructura se ramifica y crece de modo jerárquico. 
    • Árboles binarios: son árboles donde cada nodo sólo puede apuntar a dos nodos. 
    • Árboles binarios de búsqueda (ABB): son árboles binarios ordenados, por lo que la búsqueda de información en ellos es menos costosa. Desde cada nodo todos los nodos de una rama serán mayores, según la norma que se haya seguido para ordenar el árbol, y los de la otra rama serán menores. 
    • Árboles AVL: son también árboles de búsqueda, pero su estructura está más optimizada para reducir los tiempos de búsqueda. 
    • Árboles B: son otro tipo de árboles de búsqueda más complejos y optimizados que los anteriores. 
    • Tablas HASH: son estructuras auxiliares para ordenar listas de gran tamaño. 
    • Grafos: son árboles no jerarquizados, es decir, en los que cada nodo puede apuntar a nodos de nivel inferior o de nivel superior. De hecho, no se puede hablar de nivel “superior” e “inferior”. Son las estructuras dinámicas más complejas.
Para terminar con esta introducción, señalar que pueden existir estructuras dinámicas en las que haya nodos de distinto tipo, aunque nosotros no las vamos a estudiar.

## 9.5. Un ejemplo completo: las tres en raya

Llegó la hora de poner manos a la obra.

Si hay una sección de este capítulo que tienes que leer con atención, es esta. Así que es un mal momento para tener prisa.

Vamos a escribir un **programa completo en C**. Te puede servir de plantilla para desarrollar tus propios programas a partir de este código fuente.

El programa en cuestión será una versión del juego de **las tres en raya** que encontrarás resuelta en pseudocódigo el tema de introducción a la programación. No dudes en repasar aquel ejercicio resuelto para ver el pseudocódigo, puesto que nuestro programa será una traducción literal de ese pseudocódigo a C.

Aquí tienes el código fuente completo. Estúdialo con atención y asegúrate de entenderlo todo (o un gran porcentaje) antes de continuar. Ah, y no dejes de compararlo línea a línea con el mismo código en pseudocódigo.

### 9.5.1. El código fuente

```c
#include <stdio.h>

//-------------------------
//   ALGORITMO PRINCIPAL
//-------------------------
int main(void) {
   char tablero[10];
   int ganador = 0;        // 0 = ninguno, 1 = humano, 2 = ordenador
   int tablas;             // 0 = no hay tablas, 1 = sí hay tablas

   inicializar(tablero);   // Esto es un subalgoritmo. Está escrito más abajo
   do {
      mostrar(tablero);
      colocar_pieza_humano(tablero);
      ganador = comprobar_ganador(tablero);
      tablas = comprobar_tablas(tablero);
      if ((ganador == 0) && (tablas == 0)) {
         colocar_pieza_ordenador(tablero);
         ganador = comprobar_ganador(tablero);
         tablas = comprobar_tablas(tablero);
      }
   }
   while ((ganador == 0) && (tablas == 0));
	
   mostrar(tablero);
   if (ganador == 0) {
      printf("EL JUEGO HA TERMINADO EN TABLAS\n");
   }
   else if (ganador == 1) {
      printf("EL JUEGO HA TERMINADO Y HAS GANADO TÚ\n");
   }
   else {
      printf("EL JUEGO HA TERMINADO Y HE GANADO YO\n");
   }
}

// --------------------------------------------
// Inicializa el tablero con espacios en blanco
// --------------------------------------------
void inicializar(char tablero[10]) {
   int i;
   for (i = 1; i <= 9; i++) {
      // Como tablero es un array, se pasa por referencia y los cambios que
      // hagamos aquí se reflejarán en el algoritmo principal
      tablero[i] = ' ';
   }
}

// --------------------------------------------
// Muestra el estado actual del tablero
// --------------------------------------------
void mostrar(char tablero[10]) {
   printf("ESTADO ACTUAL DEL TABLERO\n");
   printf("+-+-+-+\n");
   printf("|%c|%c|%c|\n", tablero[1], tablero[2], tablero[3]);
   printf("+-+-+-+\n");
   printf("|%c|%c|%c|\n", tablero[4], tablero[5], tablero[6]);
   printf("+-+-+-+\n");
   printf("|%c|%c|%c|\n", tablero[7], tablero[8], tablero[9]);
   printf("+-+-+-+\n");
}

// ---------------------------------------------------
// Coloca una pieza del jugador humano en el tablero
// ---------------------------------------------------
void colocar_pieza_humano(char tablero[10]) {
   int casilla;
   int casilla_correcta = 0;
   do {
      printf("¿En qué casilla quieres poner una pieza? (1-9)");
      scanf("%d", &casilla);
      if (tablero[casilla] == ' ') {
         tablero[casilla] = 'X';
         casilla_correcta = 1;
      }
      else {
         printf("Error: Esa casilla ya está ocupada\n");
      }
   }
   while (casilla_correcta == 0);
}

// ---------------------------------------------------
// Coloca una pieza del ordenador en el tablero
// ---------------------------------------------------
void colocar_pieza_ordenador(char tablero[10]) {
   int casilla;
   int casilla_correcta = 0;
   srand(time(NULL));
   do {
      casilla = rand() % 10;
      printf("Voy a colocar mi pieza en la casilla ", casilla);
      if (tablero[casilla] == ' ') {
         tablero[casilla] = 'O';
         casilla_correcta = 1;
      }
      else {
         printf("¡Está ocupada! Voy a elegir otra");
      }
   }
   while (casilla_correcta == 0);
}

// ---------------------------------------------------
// Comprueba si hay un ganador según el estado del 
// tablero. Devuelve "Ninguno", "Humano" u "Ordenador"
// ---------------------------------------------------
int comprobar_ganador(char tablero[10]) {
   int ganador = 0;
   // Comprobamos primera fila
   if ((tablero[1] == tablero[2]) && (tablero[1] == tablero[3])) {
      if (tablero[1] == 'X') {
         ganador = 1;
      }
      if (tablero[1] == 'O') {
         ganador = 2;
      }
   }
   // Comprobamos segunda fila
   if ((tablero[4] == tablero[5]) && (tablero[4] == tablero[6])) {
      if (tablero[4] == 'X') {
         ganador = 1;
      }
      if (tablero[4] == 'O') {
         ganador = 2;
      }
   }
   // Comprobamos tercera fila
   if ((tablero[7] == tablero[8]) && (tablero[7] == tablero[9])) {
      if (tablero[7] == 'X') {
         ganador = 1;
      }
      if (tablero[7] == 'O') {
         ganador = 2;
      }
   }
   // Comprobamos primera columna
   if ((tablero[1] == tablero[4]) && (tablero[1] == tablero[7])) {
      if (tablero[1] == 'X') {
         ganador = 1;
      }
      if (tablero[1] == 'O') {
         ganador = 2;
      }
   }
   // Comprobamos segunda columna
   if ((tablero[2] == tablero[2]) && (tablero[2] == tablero[8])) {
      if (tablero[2] == 'X') {
         ganador = 1;
      }
      if (tablero[2] == 'O') {
         ganador = 2;
      }
   }
   // Comprobamos tercera columna
   if ((tablero[3] == tablero[6]) && (tablero[3] == tablero[9])) {
      if (tablero[3] == 'X') {
         ganador = 1;
      }
      if (tablero[3] == 'O') {
         ganador = 2;
      }
   }
   // Comprobamos una diagonal
   if ((tablero[1] == tablero[5]) && (tablero[1] == tablero[9])) {
      if (tablero[1] == 'X') {
         ganador = 1;
      }
      if (tablero[1] == 'O') {
         ganador = 2;
      }
   }
   // Comprobamos la otra diagonal
   if ((tablero[3] == tablero[5]) && (tablero[3] == tablero[7])) {
      if (tablero[3] == 'X') {
         ganador = 1;
      }
      if (tablero[3] == 'O') {
         ganador = 2;
      }
   }
   return ganador;
}

// -------------------------------------------
// Comprueba si hay una situación de tablas
// según el estado actual del tablero. Devuelve
// verdadero si hay tablas o falso en otro caso.
// -------------------------------------------
int comprobar_tablas(char tablero[10]) {
   int tablas = 0;
   int i, contador = 0;
   for (i = 1; i <= 9; i++) {
      if (tablero[i] !=  ' ') {
         contador++;
      }
   }
	
	// Si todas las casillas están ya ocupadas y no hay ganador,
	// entonces estamos en tablas.
   if (contador == 9) {
      tablas = 1;
   }
   else {
      tablas = 0;
   }
   return tablas;
}
```

### 9.5.2. ¿Cómo ejecutar y depurar este programa?

Guarda el programa anterior en un archivo de texto con extensión .c (por ejemplo, *3enraya.c*).

Si estás trabajando con Visual Studio Code con las extensiones recomendadas para C/C++, puedes ejecutar tu programa directamente desde ahí. Basta con que pulses el botón "Play" de la esquina superior derecha. Se abrirá una consola en la parte de abajo donde tu programa se ejecutará.

XXX captura imagen Play

XXX captura imagen de 3 en raya ejecutándose

#### ¡Socorro! El programa no funciona

¿El resultado no es el esperado? Es lo habitual. Habrá algún error en el código y te tocará depurarlo.

En la ventana inferior de Visual Studio Code verás varias pestañas. 

* En la pestaña **Terminal** verás el resultado de la ejecución de tu programa.
* En la pestaña **Problems** verás la lista de errores que el compilador ha encontrado en tu programa. En tal caso, en el *Terminal* solo verás un lenguaje de tipo "La compilación ha terminado con errores".

Los mensajes pueden estar en español o en inglés, dependiendo del compilador, pero ¿qué esperabas? Si quieres aprender a programar, tienes que acostumbrarte a manejar el inglés técnico.

El mensaje de error te dará información sobre lo que hay de malo en tu código y te dirá en qué línea, aproximadamente, está el error.

Cuando lo hayas localizado, **regresa a tu editor de texto, haz los cambios necesarios, guarda las modificaciones y vuelve a compilar y ejecutar el programa** (pulsando de nuevo el botón "Play").

Y así hasta que funcione.

¡Mucha paciencia y sangre fría! Recuerda siempre que la mayor parte del tiempo de programación se va en depurar programas, no en escribirlos.

## 9.6. Ejercicios propuestos

#### Ejercicio 1. Hola mundo

En este ejercicio, vamos a preparar nuestro entorno de trabajo.

1. Instala Visual Studio Code. Puedes descargarlo de [https://code.visualstudio.com/download](https://code.visualstudio.com/download) o bien instalarlo desde la tienda de aplicaciones de tu sistema operativo.

2. Abre Visual Studio Code y haz clic en el botón de extensiones (en el panel izquierdo). Busca una extensión llamada "C/C++ IntelliSense" e instálala.

3. Escribe un programa que salude con un "Hola, mundo". Encontrarás el código más abajo. Este programa es un clásico en el mundillo de la programación; siempre se usa para comprobar si un nuevo entorno de desarrollo está funcionando bien.

4. Ejecútalo y asegúrate de que el resultado es el esperado. Si algo falla, llama al profesor y no pases al siguiente ejercicio hasta dejar tu Visual Studio Code en perfecto estado de funcionamiento.

```c
#include <stdio.h>
int main()
{
   printf("Hola, mundo\n");
   return 0;
}
```

#### Ejercicio 2. Convertir de euros a dólares

Vamos a empezar por algo sencillito.

Escribe un programa en C capaz de leer un número real y un tipo de moneda, que puede ser "euro" o "dólar", y que convierta al tipo de moneda indicado, suponiendo que está expresada en la otra. 

Por ejemplo, si la cantidad es 15 y la moneda es "dólar", se supondrá que se trata de 15 € y que hay que convertirlos a dólares.

Utiliza el tipo de cambio que esté vigente el día en el que escribas el programa.</div>

#### Ejercicio 3. Tabla de multiplicar

Escribe un programa en C que pida un número y muestre la tabla de multiplicar de ese número.

Por ejemplo, si el usuario del programa escribe el número 3, la salida del programa debe ser:

```
3 x 1 = 3
3 x 2 = 6
3 x 3 = 9
3 x 4 = 12
3 x 5 = 15
3 x 6 = 18
3 x 7 = 21
3 x 8 = 24
3 x 9 = 27
3 x 10 = 30
```


#### Ejercicio 4. Juego del número secreto

Ahora algo solo un poquito más complicado: una versión en C del clásico juego del número secreto.

Se trata de un juego en el que el ordenador "piensa" un número al azar entre 1 y 100 y el jugador tiene que adivinarlo.

Cada vez que el jugador escribe un número, el programa le dice: "Mi número secreto es mayor" o "Mi número secreto es menor".

Cuando el jugador por fin acierta, el ordenador le dice: "Enhorabuena, has acertado", y añade el número de intentos que ha necesitado para acertar el número secreto.

#### Ejercicio 5. Juego de memoria

Ahora empieza la diversión.

Vamos a escribir en C un juego que podemos bautizar como "Juego de memoria". Será un juego en modo texto (bastante feo, por lo tanto), pero totalmente jugable y que nos servirá para afianzar todos los conocimientos adquiridos hasta ahora.

Reglas del juego:

* El juego comenzará preguntando el nivel de dificultad, que puede ser fácil, medio o difícil.
* El ordenador elegirá al azar una serie de números. La serie consistirá al principio en un solo número. Luego serán dos números, luego tres, luego cuatro... y así hasta diez. Los números de la serie solo pueden ser tres: 1, 2 y 3. 
* El ordenador mostrará su serie de números durante un tiempo en la pantalla. Ese tiempo será tanto menor cuanto más alto sea el nivel de dificultad.
* Después, la serie se borrará y el jugador debe demostrar su memoria y sus reflejos repitiéndola. 
* Si el jugador acierta en todos los números de la serie, el ordenador pasará a su siguiente serie (que tendrá un número más). Si el jugador falla, el juego termina.
* Si el jugador es capaz de repetir con éxito todas las series (desde la que solo tiene un número hasta la que tiene 10), el jugador gana.

#### Ejercicio 6. Pelota que rebota

Escribe un programa en C que muestre una pelota moviéndose por la pantalla y rebotando en sus bordes. La pelota se puede simular con el carácter “O”, escribiéndolo en diferentes celdas de la pantalla cada vez.

(Para este ejercicio necesitarás usar la librería *ncurses*)

Puedes realizar el programa en tres fases sucesivas. Para aprobar la actividad debes completar al menos la primera fase. Para sacar un 10 tienes que terminar la tercera fase.

* FASE 1: la “pelota” se mueve y rebota por la pantalla, pero va dejando un “rastro” de Oes.

```
O           O
 O         O O
  O       O   O
   O     O
    O   O
     O O
      O
```

* FASE 2: la “pelota” se mueve por la pantalla sin dejar rastro. Es decir, cada vez que se escribe la “O” en una nueva posición, se borra de la posición que ocupaba anteriormente. El resultado debe dar sensación de movimiento sin parpadeos.

```
           O


```

FASE 3: la “pelota” se mueve por la pantalla dejando una “estela” de cuatro o cinco “Oes” (u otros caracteres, como en la figura) a su paso.
    
```
      .
       .
        o
         o
          O


```

#### Ejercicio 7. Juego de automovilismo

Escribe un programa que simule un sencillo juego de automovilismo. La pantalla del juego debe tener un aspecto parecido a este:

```
                              |         |
                              |         |
                              |         |
                              |         |
                               |         |
                               |         |
                                |         |
                                 |         |
                                 |         |
                                 |         |
                                |         |
                                |    H    |
```

El jugador (cuyo vehículo representaremos con una H) puede mover su coche hacia la izquierda y hacia la derecha. Su objetivo es no salirse de la carretera, que tiene los límites marcados por un carácter "\|" a cada lado. Si se sale, pierde una vida. Si pierde tres vidas, la partida termina y el programa debe mostrar el tiempo que el conductor ha conseguido aguantar sin perder sus vidas.

La carretera se va desplazando de abajo a arriba, aprovechándose del scroll propio de la pantalla de texto. La carretera no debe ser recta, sino que tendrá irregularidades, como las mostradas en la figura, generadas al azar.

## 9.7. Ejercicios resueltos

Aquí iremos poniendo los ejercicios que resolvamos en clase.

