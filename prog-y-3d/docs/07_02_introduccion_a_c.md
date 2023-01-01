---
layout: page
title: 9.2. Introducción a C
permalink: /introduccion-a-c/
nav_order: 2
has_children: true
parent: 9. El lenguaje C
grand_parent: Introd. a la prog. y al diseño 3D
---

## 9.2. Introducción a C
{: .no_toc }

- TOC
{:toc}


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
