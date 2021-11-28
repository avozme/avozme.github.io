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

Así, un programa compilado en una máquina PC bajo Windows no funcionará en un Mac o en un PC bajo Linux, a menos que se vuelva a compilar el programa fuente en el nuevo sistema. En cambio, un programa interpretado funcionará en todas las plataformas, siempre que dispongamos del intérprete en cada una de ellas.

**JavaScript** es un ejemplo de lenguaje interpretado tremendamente popular gracias al crecimiento de Internet. Los programas escritos con JavaScript (llamados comúnmente *scripts*) pueden funcionar en cualquier máquina que disponga de un intérperte Javascript, y resulta que todos los navegadores web tienen uno.

Por eso, **cualquier programa escrito en Javascript puede ejecutarse prácticamente en cualquier ordenador del mundo** sin tocarle ni una coma.

En cambio, **C++**, por ejemplo, es un lenguaje compilado, lo que hace que los programas desarrollados con estos lenguajes se ejecuten más rápido (¡pero mucho más rápido!) que sus equivalentes en JavaScript. Sin embargo, tendrás que volver a compilarlos si deseas ejecutarlos en una máquina con diferente hardware o diferente sistema operativo.

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

Según las cifras de Madnight, Javascript continúa siendo el lenguaje preferido por la mayoría de los programadores (aunque está lejos de sus tiempos memorables, donde llegó a utilizarse en casi el 30% de los proyectos activos en Github). Viejas glorias como Java, C++, PHP y C aguantan muy bien el tipo, con unos números muy estables, porque tienen una base de programadores muy fieles a sus espaldas, mientras que algunos lenguajes recientes como Go y Typescript se han hecho un hueco en el ránking de los 10 más usados.

## 5.2. ¡Bienvenidos a Javascript!

### 5.2.1.  Características básicas de Javascript

* Javascript es un lenguaje de **alto nivel**.
* Es **imperativo y estructurado**. Admite **orientación a objetos basada en prototipos**, no en clases (puede que no entiendas lo que significa esto, pero de momento no importa).
* Su **tipado es débil y dinámico**.
* La **sintaxis** de sus estructuras de control está **heredada del lenguaje C**, como la de Java, PHP o Python, por lo que guarda bastantes semejanzas con estos otros lenguajes.
* Es un **lenguaje interpretado**, pensado para ser ejecutado dentro de un navegador web. Por lo tanto, no es particularmente eficiente, pero sí muy portable. Sin embargo, también existen **compiladores y precompiladores** que permiten construir con Javascript cualquier tipo de programa, no solo aplicaciones web.
* Es **altamente portable**. Cualquier programa en Javascript debería poder ejecutarse sin ninguna adaptación particular en cualquier navegador web reciente.
* Su integración con los navegadores web hace que pueda manipular cualquier página web, incluso después de estar cargada en el navegador.
* Es uno de los lenguajes de programación **más populares** del mundo en la actualidad. Aunque se ha intentado reemplazar muchas veces, ningún otro lenguaje lo ha conseguido (de momento).

### 5.2.2. Breve historia de Javascript

Javascript fue un lenguaje creado en la década de 1990 para el ya desaparecido navegador web **Netscape Navigator**. En aquellos primeros tiempos de internet, las páginas web eran sitios muy poco vistosos, con mucho texto y unas pocas imágenes, y Javascript pretendía introducir un poco de movimiento y dinamismo en esas páginas tan aburridas.

**Internet Explorer**, el principal competidor de Netscape, respondió creando el **VB Script** y, posteriormente, un lenguaje muy similar a Javascript (pero no igual) llamado **JScript**. Esos lenguajes no tuvieron éxito e Internet Explorer terminó por aceptar la existencia de Javascript.

Aquella competición entre Netscape e Internet Explorer se llamó *guerra de los navegadores* y, aunque Netscape la perdió y acabó desapareciendo, Javascript ha permanecido hasta hoy como el heredero directo aquella época convulsa.

Desde entonces, Javascript ha tenido una evolución enorme, y ha pasado de ser apenas un lenguaje de juguete con el que se podían conseguir un puñado de efectos dinámicos en los sitios web a ser un lenguaje muy potente y bien definido, capaz de sustentar la estructura de aplicaciones web complejas.

Hoy en día, Javascript suele utilizarse con librerías y *frameworks* que mejoran su estructura y aumentan su potencia. El estándar del lenguaje está publicado por la **ECMA** (European Computer Manufacturers Association) y se denomina **ECMAScript**. Todos los navegadores web respetan ese estándar en gran medida.

### 5.2.3. Sintaxis básica de Javascript
 
#### Generalidades sintácticas

Hay algunas normas básicas de la sintaxis de Javascript que tienes que conocer:

* **Los bloques de código se marcan con las llaves** ( **{** y **}** ). Por ejemplo, después de una sentencia *while* (equivalente al *mientras* de pseudocódigo) hay que abrir una llave. El cuerpo de bucle comprenderá desde esa llave de apertura hasta la siguiente llave de cierre, así:

   ```javascript
   while (condicion) {
      Instrucción 1 del bucle
      Instrucción 2 del bulce
      ...
      Instrucción N del bucle
   }
   ```

   La llave de cierre, por tanto, sería el equivalente al *FinMientras* de pseudocódigo.

* Todas las instrucciones **terminan con un punto y coma** ( **;** ). Excepción: si una instrucción contiene un bloque marcado con llaves ( { ... } ), se considera que esa instrucción termina al cerrar el bloque, y en ese caso no hace falta poner punto y coma.

   ```javascript
   a = 10;                     // La instrucción de asignación termina con ;
   while (condicion) {
      // Cuerpo del bucle
   }                           // El bucle termina con }, así que no necesita ;
   ```

* Los **identificadores** de variables, funciones, etc., no pueden empezar con un número ni contener espacios o símbolos especiales, salvo el de subrayado ( _ )

   ```javascript
   a5 = 1;     // Identificador de variable válido
   5a = 1;     // Identificador de variable NO válido
   ```

* Las **cadenas de caracteres** pueden encerrarse entre **comillas simples** ( '...' ) o **comillas dobles** ( "..." )

   ```javascript
   a = "Soy una cadena";
   b = 'Yo también soy una cadena';
   ```

* El lenguaje es **sensitivo a las mayúsculas**. Es decir, no es lo mismo que una variable se llame *edad* que *Edad* o *EDAD*.

#### Tipos de datos primitivos

Javascript utiliza varios tipos de datos simples llamados **primitivos**. Los más importantes son: 

* **number**: números enteros y reales, indistintamente.
* **string**: cadenas de caracteres.
* **boolean**: datos de tipo lógico, es decir, de los que solo pueden valer *true* (verdadero) o *false* (falso). 

Como es un lenguaje de tipado dinámico, esos tipos **pueden variar durante la ejecución**, dependiendo de lo que hagas con las variables.

De hecho, Javascript es tan flexible que **ni siquiera es necesario declarar las variables** (aunque es aconsejable). Es decir, que puedes usar una variable cuando la necesites sin tener que declararla antes.

Las variables en Javascript se declaran con las palabras clave **var** o **let**. Las diferencias entre una y otra tienen que ver con el ámbito de la variable y las veremos enseguida.

Por ejemplo:

```javascript
var a = "Hola";
let b = 1;
var c;
d = 3;
```

En el código anterior hemos declarado tres variables, a, b y c. Observa que, **al declarar una variable, no se especifica el tipo**: Javascript decidirá su tipo en función del valor que se le asigne.

Así pues, el tipo de la variable a será *string*, y el de la variable b será *number*. ¿Qué pasará con el tipo de la variable c? Hasta que no se le asigne algún valor, permanecerá *undefined*. 

Fíjate, por último, en que no hemos declarado la variable d, sino que la hemos usado directamente. Esto también es válido en Javascript, aunque, en general, poco recomendable por razones que comentaremos luego. El tipo de esta variable también será *number*.

### 5.2.4. Conversiones de tipo

Javascript, como hemos dicho, es un lenguaje de **tipado dinámico**. Es decir, que las variables pueden variar de tipo a lo largo del programa:

```javascript
var a = 1;    // Variable tipo number
// Aquí pueden ir varias instrucciones más
a = "Hola";   // Ahora la variable es de tipo string
```

Además, Javascript también es un lenguaje **débilmente tipado**, lo que significa que no hace comprobaciones estrictas de tipos a la hora de asignar un valor a una variable o de comparar dos expresiones.

Por ejemplo, estas instrucciones son correctas:

```javascript
a = 5;      // La variable a es de tipo number
b = "A";    // La variable b es de tipo string
c = a + b;  // ¿Qué ocurre si las mezclamos en una expresión?
```

¿Qué resultado crees que obtendrás con una mezcla de tipos como esta? ¿Por qué no haces la prueba?

Cuando mezclas tipos, estás dejando que el lenguaje de programación decida cuál será el resultado, por lo que puedes obtener resultados imprevisibles. Es mejor que tú controles qué conversiones de tipo se hacen. Para eso, Javacript dispone de varias herramientas:

* **typeof**: Nos dice de qué tipo es una variable.

   ```javascript
   a = 5;
   document.write(typeof a);   // En la pantalla, aparecerá escrito "number"
   ```

* **String**: Convierte la variable a un *string* (cadena de caracteres).

   ```javascript
   a = 5;          // a es el número entero 5 
   b = String(a);  // b es la cadena "5"
   ```
* **parseInt** y **parseFloat**: Convierte la variable a un *number* entero o real (es decir, a sin decimales o con decimales).

   ```javascript
   a = "5 pollos"; // a es una cadena
   b = parseInt(a);  // Javascript tratará de convertir la cadena a un número entero
   document.write(b);  // ¿Qué crees que aparecerá en la pantalla?
   ```

### 5.2.5. Asignación y ámbito de las variables

La **asignación** de valores a variables en Javascript es fácil de explicar: se hace con el **símbolo igual (=)**, no con el símbolo <= que usábamos en pseudocódigo:

```javascript
var a;      // Declaración de la variable a
var b = 1;  // Declaración y asignación de valor a la variable b
a = b + 5;  // Asignación de valor a la variable a
```

El problema del **ámbito de las variables** es más complicado de explicar.

El **ámbito** (o ***scope***, en inglés) de una variable es *el lugar del programa donde esa variable está disponible*.

Primero, la versión corta: las **variables en Javascript son locales**. Es decir, solo son accesibles desde el algoritmo o subalgoritmo donde se declaran.

La versión larga es que Javascript ofrece una flexibilidad un poco mareante para manejar el ámbito de las variables.

Vamos a tratar de explicarlo con unos cuantos ejemplos sencillos. 

Unas líneas más arriba dijimos que Javascript permite declarar las variables con ***var*** o con ***let***, o bien no declararlas, ¿verdad?

Pues bien: el ámbito de la variable dependerá de *dónde* declaremos la variable (si lo hacemos) y de cómo lo hagamos (con *var* o con *let*).

#### Declarar variables con *var*

Las variables declaradas con ***var*** son **locales a la función** donde se declaran, o **globales** si se declaran en el exterior de cualquier función.

```javascript
var a = 1;  // Variable global

function mostrarMensaje() {
    var b = 2;    // Variable local
    document.write("La variable a vale ", a, " y la variable b vale ", b);
}
```

En este ejemplo, la variable a es **global**, lo que significa que será accesible desde cualquier parte de este programa (incluyendo el interior de la función *mostrarMensaje()*).

La variable b, en cambio, es **local a la función** *mostrarMensaje()*. Si tratamos de acceder a ella desde el exterior de esa función, se producirá un error de ejecución.

#### Declarar variables con *let*

Las variables declaradas con ***let*** son **locales al bloque** donde se declaran, o **globales** si se declaran en el exterior de cualquier bloque.

Un **bloque** es cualquier cosa encerrada entre dos llaves ({ y }). Observa el siguiente ejemplo:

```javascript
let a = 1;  // Variable global

function mostrarMensaje() {
    let b = 2;    // Variable local a la función
    if (b > 0) {
        let c = 3;   // Variable local al bloque if
        document.write("La variable a vale ", a, ", la variable b vale ", b, " y la variable c vale ", c);
    }
}
```

En este ejemplo tenemos 3 variables:

* La variable a vuelve a ser **global**, lo que significa que será accesible desde cualquier parte de este programa.
* La variable b es **local a la función**. Está disponible desde su declaración hasta la llave de cierre de la función.
* La variable c es **local a su bloque**. Es decir, está disponible desde su declaración hasta la llave de cierre del *if*.

#### No declarar las variables

Con Javascript, como ya hemos visto, es perfectamente posible **no declarar las variables** y usarlas sin más.

Sin embargo, cuando haces este tipo de cosas, dejas que sea el lenguaje de programación el que tome decisiones por ti. En este caso, que decida sobre el ámbito de la variable. Por eso mi consejo es que *siempre* declares las variables, aunque no les asignes ningún valor inicial.

Si decides usar las variables sin declarar, tienes que saber que Javascript las considerará a todas **globales**, independientemente del punto del programa donde hayas usado la variable por primera vez.

```javascript
a = 1;  // Variable global

function mostrarMensaje() {
    b = 2;    // Variable global
    if (b > 0) {
        c = 3;   // Variable global
        document.write("La variable a vale ", a, ", la variable b vale ", b, " y la variable c vale ", c);
    }
}
```

### 5.2.6. Operadores y expresiones

Los **operadores y expresiones en Javascript** son iguales que los que hemos empleado en pseudocódigo:

* Operadores **aritméticos**: +, -, \*, /, % (este último significa *módulo de la división*).
* Operadores **relacionales**: >, <, >=, <=...

Sin embargo, hay algunas **diferencias** importantes entre el pseudocódigo de PseInt y Javascript. Son estas:

* La **asignación**, como ya hemos visto más arriba, se hace con el **símbolo igual (=)**, no con <=.
   
   ```javascript
   a = 5;        // A la variable a se le asigna el valor 5
   b = a + 1;    // A la variable b se le asigna el valor a + 1
   ```

* La **comparación de igualdad** se hace con un **doble igual (==)**, no con un solo igual (=). Esto es así para distinguir la comparación de la asignación.
   
   ```javascript
   if (a == 5) {    // Comparación: ¿es a igual a 5?
       b = a + 1;   // Asignación: b toma el valor a + 1
   }
   ```
   
* Existe el **operador incremento (++)**. Se utiliza para sumar una unidad a una variable.
   
   ```javascript
   while (i < 10) {
       i++;         // Esto es equivalente a: i = i + 1
   }
   ```
   
* También existe el **operador decremento (- -)**, para restar una unidad a una variable.
   
   ```javascript
   while (i > 0) {
       i--;     // Equivalente a: i = i - 1
   }
   ```
   
* Los **operadores lógicos** (Y, O, NO) se escriben de forma distinta:
   * **Y** se escribe **&&**. 
   * **O** se escribe **\|\|**. 
   * **NO** se escribe **!** (sí, sí, es una admiración).
   
   ```javascript
   if (a > 0) && (b > 0) {   // Operador Y: tienen que darse las dos condiciones a la vez
       ...
   }
   ```
   
Hay algunas otras diferencias, desde luego, pero con esto ya tienes para hacer un buen montón de programas.

### 5.2.7. Estructuras de control

Las **estructuras de control** en Javascript son muy similares a las que hemos utilizado en pseudocódigo, cambiando ligeramente la notación empleada. 

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

### 5.2.8. Subalgoritmos

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

### 5.2.9. Entrada y salida

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

### 5.2.10. Arrays

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

### 5.2.11. Los objetos predefinidos de Javascript

Los **objetos**, como hemos dicho varias veces ya, los estudiaremos en el próximo capítulo. Por ahora te basta saber que son construcciones de Javascript que encierran dentro de sí una serie de funciones y variables para manipular diferentes elementos y facilitar la vida al programador.

Por ejemplo, los arrays son objetos.

Pues bien, existen muchos otros objetos predefinidos en Javascript. Te voy a presentar a unos cuantos particularmente útiles, aunque debes saber que hay muchos más. Cuando vayas profundizando en tu conocimiento de este lenguaje los irás conociendo.

* **Date**. Permite obtener la fecha y hora actual del reloj del ordenador. Por ejemplo:

   ```javascript
   var d = new Date(); // Fecha y hora actual
   document.write('Día de la semana', d.getDay());
   document.write('Día del mes', d.getDate());
   document.write('Mes', d.getMonth());
   document.write('Año', d.getFullYear());
   ```
* **Math**. Este objeto contiene una enorme colección de funciones matemáticas. Algunas son: 
   * *sin(x), cos(x), tan(x)*: calcula el seno, el coseno y la tangente de x.
   * *max(valor1, valor2, ..., valorN), min(valor1, valor2, ..., valorN)*: calcula el máximo o el mínimo de una lista de valores.
   * *round(x)*: redondea el número x al entero más próximo. Si ya era entero, lo deja como estaba.
   * *trunc(x)*: trunca el número x. Es decir, elimina los decimales, sin redondear.
   * *pow(b, e)*: calcula la potencia de b elevado a e.
   * *random()*: devuelve un número real aleatorio entre 0 y 1. Si quieres que sea un aleatorio entero entre dos valores cualesquiera, tendrás que hacer algo así:

      ```javascript
      document.write("Aleatorio de 0 a 1:  " + Math.random());
      document.write("Aleatorio de 0 a 99: " + Math.trunc(Math.random()*100));
      document.write("Aleatorio de 1 a 100:" + Math.trunc(Math.random()*100 + 1));
      document.write("Aleatorio de 0 a 100:" + Math.trunc(Math.random()*101));
      ```

* **window**. Proporciona acceso a una ventana del navegador web. Te ofrece métodos muy interesantes como:
   * *open()*: abre una ventana del navegador nueva.
   * *close()*: cierra una ventana del navegador.
   * *moveTo(x, y)*: mueve la ventana actual a la posición x, y.
   * *resizeTo(tamañoX, tamañoY)*: cambia el tamaño de la ventana actual.
   * *screenX* y *screenY*: nos da las coordenadas X e Y donde se encuentra la ventana ubicada en este momento.
   * *innerWidth* y *innerHeight*: nos devuelve el espacio disponible dentro de la ventana del navegador (en píxeles).

* **document**. Proporciona acceso al texto escrito dentro de la ventana del navegador. Lo hemos estado usando para generar la salida de nuestros programas. Estos son algunos métodos:
   * *write()*: añade texto a la ventana del navegador.
   * *writeln()*: añade texto a la ventana del navegador, y termina con una salto de línea.
   * *open()*: elimina todo el contenido que haya en la ventana del navegador e inicia una nueva salida.
   * *close()*: finaliza el envío de datos a la ventana del navegador.
   * *getElementById()*: recupera un elemento del navegador a partir de su id.

## 5.3. Escribiendo programas con Javascript

Ya conocemos cómo se manejan los principales componentes de un programa con Javascript: variables, instrucciones de control, asignaciones, funciones, etc.

Ahora nos queda saber cómo juntamos todo eso para escribir nuestros programas, ¿no te parece?

Por fortuna, en esto Javascript también se parece mucho a pseudocódigo. 

### 5.3.1. Caja de herramientas

¿Qué necesitamos para comenzar a escribir programas en Javascript? ¿Tendrás que instalar un montón de programas de desarrollo en tu ordenador?

La verdad es que no. Para desarrollar con Javascript basta con que tengas instalado:

* **Un editor de texto**. No te sirve Microsoft Word ni Libreoffice Writer. Tiene que ser un editor de texto *plano*, es decir, que no introduzca información de formato en el archivo. Solo el texto.

   Existen muchísimos editores de estas características, porque son programas muy simples y livianos. El **bloc de notas** de Windows es uno de ellos, aunque resulta poco recomendable porque no colorea el código fuente ni te ayuda a corregir errores.

   Un editor de texto para programación que ha tenido un crecimiento espectacular en los últimos años a nivel aficionado y profesional es **[Visual Studio Code](https://code.visualstudio.com/)**. Es multiplataforma (tiene versiones para Windows, Linux y Mac) y de código abierto. Y es una auténtica maravilla, así que te recomiendo que lo descargues (¡siempre de la web oficial, por favor!) y lo instales.

   Si trabajas con Linux, seguramente lo encuentres en los repositorios oficiales de tu distribución. Esa, por supuesto, también es una fuente confiable desde donde instalarlo.

* **Un navegador web**. Todos los navegadores web llevan en sus tripas un intérprete de Javascript, puesto que todas las páginas web actuales utilizan Javascript para funcionar. Puedes usar el navegador web que más te guste: Google Chrome, Mozilla Firefox, Microsoft Edge, el Safari de Apple, Opera, etc.

### 5.3.2. Flujo de trabajo

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

### 5.3.3. Dónde y cómo escribir el código fuente

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

## 5.4. Eventos y temporizadores

### 5.4.1. Eventos de Javascript

Javascript puede responder a los **eventos** que sucedan en la página web.

¿Qué es un evento? Esto es fácil de responder: un evento es cualquier cosa que suceda dentro del navegador a lo que el navegador pueda responder.

Por ejemplo, un evento es "hacer clic con el ratón sobre un enlace". Otro evento es "escribir un carácter en un cuadro de texto". Y otro evento es: "cerrar la ventana del navegador".

Hay muchos eventos distintos, y cada uno puede ocurrir asociado a cualquier elemento de la página web. Pero el evento estrella es, sin duda, "hacer clic".

Observa el siguiente fragmento de código HTML. No hace falta que sepas HTML. Tú solo míralo:

```html
<button>Púlsame</button>
```

¿Te imaginas lo que se verá en el navegador si cargas esa página? Pues sí: un botón cuyo texto será "Púlsame".

Ahora mira el mismo código, ligeramente modificado:

```html
<button onclick='procesar_boton()'>Púlsame</button>
```

Ese "onclick" a continuación del botón significa que **vamos a capturar el evento clic de ratón** asociado al botón. Al hacer clic sobre él, se ejecutará la función *procesar_boton()* de Javascript.

Usaremos algún evento *onclick()* como este en los ejercicios para conseguir resultados curiosos.

Sobre los eventos, se podría hablar muchísimo más, pero como introducción a Javascript es suficiente por ahora...

### 5.4.2. Temporizadores de Javascript

Lo que te voy a contar ahora puede considerarse Javascript avanzado (o, al menos, no es Javascript básico). Pero lo vas a necesitar para hacer juegos y otras diversiones con Javascript y, en fin, tampoco es tan complicado...

Se trata de los **temporizadores**.

Un temporizador es como el cronómetro de una bomba de relojería de las que salen en las películas. Ya sabes, esas bombas que siempre tienen una pantalla LCD donde se ve una cuenta atrás que indica cuánto falta para que explote.

(El temporizador es el cronómetro, no la bomba, que conste...)

Un temporizador se pone en marcha así:

```javascript
setTimeout('nombre-de-función', intervalo);
```

El *nombre-de-función* es exactamente eso: el nombre de alguna función Javascript que ya exista. El *intervalo* es un número entero.

Lo que hace el temporizador es **iniciar una cuenta atrás de *intervalo* milisegundos y, cuando el cronómetro llega a cero, se ejecuta la función indicada**.

Por ejemplo:

```javascript
setTimeout('saludar', 1000);

function saludar() {
   alert("Hola, mundo");
}
```

Si ejecutas este código, verás que el saludo (¡Hola, mundo!) tarda exactamente un segundo en aparecer. El temporizador se ha encargado de ello. Nada más ejecutar el código, se ha puesto en marcha un temporizador cuyo encargo es ejecutar la función *saludar()* al cabo de 1000 milisegundos (es decir, un segundo).

Programar acciones para que se realicen en el futuro abre muchísimas posibilidades. En particular, piensa en qué ocurriría si hacemos que la propia función *saludar()* vuelva a reestablecer el temporizador:

```javascript
setTimeout('saludar', 1000);

function saludar() {
   alert("Hola, mundo");
   setTimeout('saludar', 1000);
}
```

Detente un momento a tratar de averiguar qué ocurriría al ejecutar este programa y por qué podríamos decir sin dudarlo que se trata de uno de los programas más plastas que hemos escrito hasta ahora. Si no te lo crees, pruébalo y lo comprobarás.

## 5.5. Un ejemplo completo

Llegó la hora de poner manos a la obra.

Si hay una sección de este capítulo que tienes que leer con atención, es esta. Así que es un mal momento para tener prisa.

Vamos a escribir un **programa completo en Javascript**. Te puede servir de plantilla para desarrollar tus propios programas a partir de aquí.

El programa en cuestión será una versión del juego de **las tres en raya** que resolvimos en el tema de introducción a la programación. No dudes en repasar aquel ejercicio resuelto para ver el pseudocódigo, puesto que nuestro programa será una traducción literal de ese pseudocódigo a Javascript.

Aquí tienes el código fuente completo. Estúdialo con atención y asegúrate de entenderlo todo (o un gran porcentaje) antes de continuar. Ah, y no dejes de compararlo línea a línea con el mismo código en pseudocódigo.

### 5.5.1. El código fuente

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

### 5.5.2. ¿Cómo ejecutar y depurar este programa?

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

## 5.6. Ejercicios propuestos

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
<h1>Ventana nerviosa</h1>
<body>
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
* **Pista nº 2**. En el ejercicio anterior cambiábamos las propiedades *top* y *left* de un botón, pero los botones (y cualquier cosa que haya en una página web) tienen muchas otras propiedades (¡pero MUCHAS!). Una de ellas se llama ***visibility***, y puede tomar dos valores: *visible* o *hidden*.

#### Ejercicio 5. Pelota de goma

Busca en internet una imagen de una pelota que te guste y descárgala. En esa imagen no debe aparecer nada más, excepto la pelota. 

Luego insértala en una página web, así:

```html
<body>
   <img src='nombre-del-archivo-de-la-imagen' style='width: 100px; height: 100px' id='pelota'>
</body>  
```

En *'nombre-del-archivo-de-la-imagen'*, como es lógico, tendrás que escribir el nombre del archivo que contiene tu pelota. Le hemos asignado 100 píxeles de ancho y 100 de alto, pero si es demasiado pequeña o demasiado grande, siéntete libre de cambiar esas cantidades.

**Ahora escribe en Javascript un programa para que la pelota rebote por la pantalla como si fuera una pelota de verdad.**

Para conseguirlo, tendrás que:

* Alterar de nuevo las propiedades *top* y *left* de la pelota
* Usar las propiedades el objeto ***window*** para evitar que la pelota se salga de los márgenes de la pantalla.
* Utilizar un **temporizador** para mover la pelota cada x milisegundos. Según el valor de x, la pelota se moverá más deprisa o más despacio.

**Mejora para los más valientes**: trata de añadir un botón a este programa. Al pulsarlo, la pelota se detendrá. Al volver a pulsarlo, la pelota se pondrá en marcha de nuevo.

#### Ejercicio 6. Tres en raya improved

**Modifica el juego de las tres en raya para que sea más atractivo al usuario y más cómodo de jugar.**

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

#### Ejercicio 7. Tenis

(Aviso: este ejercicio es de dificultad elevada)

Ya sabes hacer que una pelota rebote (ejercicio 5). **Vamos a mejorar ese programa haciendo una versión del clásico juego de tenis *"Pong"***, el primer videojuego comercial de la historia.

Si no conoces el *Pong*, bichea un poco por Internet para averiguar cómo es.

¡Y ahora trata de programar una versión actualizada en Javascript!

#### Ejercicio 8. Carretera al infierno

(Aviso: este ejercicio es de dificultad elevada)

En esta ocasión, vamos a programar **un juego que llamaremos "Carretera al infierno"**.

En el juego, manejaremos un coche (busca en internet la imagen de un coche visto desde arriba). El coche aparecerá en la parte inferior de la pantalla, centrado y mirando hacia arriba.

Una carretera irá desplazándose de arriba a abajo. La carretera no será recta, sino que tendrá irregularidades aleatorias hacia la izquierda y hacia la derecha. Nuestro objetivo es mover el coche hacia la izquierda y hacia la derecha para evitar que se salga de la carretera.

La carreterá se moverá cada vez más deprisa. **El objetivo del juego es aguantar la mayor cantidad posible de tiempo sin salirnos.**

## 5.7. Ejercicios resueltos

Aquí iremos poniendo los ejercicios que resolvamos en clase.
