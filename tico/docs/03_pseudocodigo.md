---
layout: page
title: 3. Programación con pseudocódigo, Python y Javascript
permalink: /pseudocodigo-python-javascript/
nav_order: 3
has_children: true
parent: Tecnologías de la Información y la Comunicación 2º BACHILLERATO
---


# 3. Programación con pseudocódigo, Python y Javascript
{: .no_toc }


- TOC
{:toc}

## 3.1. Pseudocódigo

El pseudocódigo **no es un lenguaje formal de programación**, sino un **pseudolenguaje**.

Es decir, se asemeja a los lenguajes de programación, pero cada cual se lo monta un poco como quiere. No hay una única forma correcta y universalmente aceptada de escribir el pseudocódigo.

Nosotros vamos a usar una sintaxis concreta tomada de una utilidad llamada **[PSeInt](http://pseint.sourceforge.net/)**. Así podremos no solo escribir nuestros programas, sino ejecutarlos, depurarlos e incluso ver su diagrama de flujo.

### 3.1.1. Instrucciones típicas en pseudocódigo (versión PSeInt)

Las instrucciones de pseudocódigo tienen una correspondiencia directa con los símbolos de los diagramas de flujo.

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

### 3.1.2. Un ejemplo sencillo de algoritmo escrito en pseudocódigo

Lo mejor para comprender cómo se escribe un programa en pseudocódigo es ver un ejemplo. 

Vamos a mostrando un **ejemplo sencillo pero muy completo** de algoritmo escrito en pseudocódigo.

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

Léelo con atención y asegúrate de entenderlo antes de continuar. También es buena idea que intentes representar este mismo algoritmo mediante un diagrama de flujo y compares esa representación con el pseudocódigo anterior. Te darás cuenta de que, en realidad, son dos formas de describir exactamente el mismo programa.

### 3.1.3. Cómo ejecutar un programa escrito en Pseudocódigo

Si has escrito el programa usando el dialecto de PseInt, no hay nada más fácil: basta con que pegues el código fuente en el editor de texto de PseInt y pulses el botón de "Ejecutar".

Ten en cuenta que, si tu programa tiene errores de escritura, la ejecución no se lanzará, sino que PseInt te marcará en rojo las líneas donde ha detectado el error o errores. Tendrás que corregirlos antes de poder ejecutar el programar.


## 3.2. Python

Los **lenguajes de programación reales** son algo más complejos que el pseudocódigo. Unos más y otros menos.

Uno de los lenguajes más semejantes a pseudocódigo que, además, está muy de moda últimamente es **el lenguaje Python**. Puedes crear programas sencillos con Python de forma muy semejante a cómo lo harías con pseudocódigo (aunque, por supuesto, Python tiene muchas otras características adicionales que lo hacen muy potente y en las que no vamos a entrar aquí).

### 3.2.1. Correspondencia entre pseudocódigo y Python

En la siguiente tabla se muestran las correspondencias entre las principales instrucciones de pseudocódigo y las de Python:

<table>
    <tr>
        <td style='background-color: lightgrey'>
        <strong>PSEUDOCÓDIGO</strong>
        </td>
        <td style='background-color: lightgrey'>
        <strong>PYTHON</strong>
        </td>
    </tr>
    <tr>
        <td>
        <strong>// Condicional simple</strong><br>
        Si condición entonces<br>
        &nbsp;&nbsp;&nbsp;acciones-1<br>
        FinSi
        </td>
        <td>
        <strong># Condicional simple</strong><br>
        if condicion:<br>
        &nbsp;&nbsp;&nbsp;acciones
        </td>
    </tr>
    <tr>
        <td>
        <strong>// Condicional doble</strong><br>
        Si condición entonces<br>
        &nbsp;&nbsp;&nbsp;acciones-1<br>
        Sino<br>
        &nbsp;&nbsp;&nbsp;acciones-2<br>
        FinSi
        </td>
        <td>
        <strong># Condicional doble</strong><br>
        if condicion:<br>
        &nbsp;&nbsp;&nbsp;acciones-1<br>
        else:<br>
        &nbsp;&nbsp;&nbsp;acciones-2<br>
        </td>
    </tr>
    <tr>
        <td>
        <strong>// Bucle tipo “mientras”</strong><br>
        Mientras condición hacer<br>
        &nbsp;&nbsp;&nbsp;acciones<br>
        FinMientras
        </td>
        <td>
        <strong># Bucle tipo “mientras”</strong><br>
        while condición:<br>
        &nbsp;&nbsp;&nbsp;acciones
        </td>
    </tr>
    <tr>
        <td>
        <strong>// Bucle tipo “para”</strong><br>
        Para variable <- valor_inicial hasta valor_final Hacer<br>
        &nbsp;&nbsp;&nbsp;acciones<br>
        FinPara
        </td>
        <td>
        <strong># Bucle tipo “para” </strong><br>
        for elemento in secuencia:<br>
        &nbsp;&nbsp;&nbsp;acciones
        </td>
    </tr>
    <tr>
        <td>
        <strong>// Asignación</strong><br>
        a <- 20
        </td>
        <td>
        <strong># Asignación </strong><br>
        a = 20
        </td>
    </tr>
    <tr>
        <td>
        <strong>// Salida de datos</strong><br>
        Escribir "El resultado es ", x
        </td>
        <td>
        <strong># Salida de datos </strong><br>
        print("El resultado es ", x)
        </td>
    </tr>
    <tr>
        <td>
        <strong>// Entrada de datos</strong><br>
        Escribir "Dime un número"<br>
        Leer variable
        </td>
        <td>
        <strong># Entrada de datos </strong><br>
        variable = input("Dime un número")
        </td>
    </tr>
</table>

Como puedes observar, para escribir Python en lugar de Pseudocódigo basta con cambiar ligeramente la sintaxis de las instrucciones y, por supuesto, escribirlas en inglés en lugar de usar el castellano.

Observa que Python no tiene instrucciones del tipo "FinSi" o "FinMientras". Para marcar el final de un bloque, Python usa la **sangría izquierda**, es decir, el espacio que hay a la izquierda del texto: si un texto está más sangrado que la instrucción anterior, significa que ha comenzado un bloque de código. Si el texto regresa a la sangría que tenía antes, significa que ese bloque ha terminado.

Lo mostramos en el siguiente ejemplo, donde se puede ver un bucle while escrito con Pseudocódigo y con Python. Fíjate en cómo marca cada lenguaje el comienzo y el final del bucle:

<table>
    <tr>
        <td style='background-color: lightgrey'>
        <strong>PSEUDOCÓDIGO</strong>
        </td>
        <td style='background-color: lightgrey'>
        <strong>PYTHON</strong>
        </td>
    </tr>
<tr>
<td>
<pre>
i <- 0<br>
Mientras i < 100 hacer<br>
   // Aquí empieza el cuerpo bucle.<br>
   // La sangría izquierda es optativa, y sirve<br>
   // para facilitar la lectura del código.<br>
   Escribir i<br>
   i <- i + 1<br>
FinMientras<br>
<br>
// Esta instrucción ya está fuera del bucle<br>
Escribir "El bucle ha terminado"<br>
</pre>
</td>
<td>
<pre>
i = 0<br>
while i < 100:<br>
   # Aquí empieza el cuerpo del bucle.<br>
   # La sangría izquierda es OBLIGATORIA.<br>
   # Sirve para marcar el cuerpo del bucle.<br>
   print i<br>
   i = i + 1<br>
  <br>
# Esta instrucción ya está fuera del bucle<br>
# porque no tiene sangría izquierda<br>
print "El bucle ha terminado"<br>
</pre>
</td>
</tr>
</table>

### 3.2.2. Un ejemplo sencillo de algoritmo escrito en Python

Teniendo en cuenta la tabla anterior, es fácil escribir en Python el mismo programa que hicimos antes con pseudocódigo; ya sabes, aquel que mostraba todos los números enteros que hay entre dos números cualesquiera, A y B, que se introducen por teclado. Aquí lo tienes:

```python
# Definir las variables A, B, inicio, final e i
A = int(input("Dime un número: "))
B = int(input("Dime otro número: "))

# Determinar los valores de inicio y final
if A < B:
    inicio = A
    final = B
else:
    inicio = B
    final = A

# Mostrar los números desde inicio hasta final
print("Estos son los números desde", inicio, "hasta", final)
i = inicio

while i <= final:
    print(i)
    i = i + 1
```

Observa cómo se hace la entrada de datos en las dos primeras instrucciones del algoritmo: no solo hay que usar la intrucción **input()**, sino que hay que usar una segunda instrucción **int()**. 

Esto ocurre porque, en Python, cualquier cosa que se lea por el teclado se considera una cadena de caracteres. Para manipularla como otra cosa (por ejemplo, un número entero), es necesario *convertirla explícitamente* a ese tipo de datos. Y eso es exactamente lo que hace **int()**: convertir lo que le pases entre paréntesis en un número entero.

### 3.2.3. Cómo ejecutar un programa escrito Python

Existen muchas maneras de ejecutar un programa con Python. Aquí te vamos a mencionar dos de las más simples:

<strong>1) Usando Thonny</strong>

Thonny es un IDE, es decir, un Entorno Integrado de Desarrollo, especialmente simple y pensado para trabajar con Python. Lo de IDE significa que incluye en un solo programa todo lo necesario para desarrollar aplicaciones (editor, intérprete, depurador y otro montón de herramientas que no hemos visto). 

Por lo tanto, solo tienes que instalar Thonny (si aún no lo tienes) y escribir el código Python en su editor. Después, bastará con pulsar el botón de "Ejecución".

<strong>2) Mediante un intérprete online de Python</strong>

Existen muchos intérpretes online de Python que, sin necesidad de instalar nada en tu máquina, son capaces de ejecutar tu código fuente escrito en Python.

Solo tienes que acceder a uno de estos intérpretes y (a veces registrándote antes, a veces sin registro) copiar y pegar tu código y pulsar el botón de ejecución.

Algunos intérpretes online de Python bastante confiables son el de [W3Schools](https://www.w3schools.com/python/python_compiler.asp) o el de [Porgramiz](https://www.programiz.com/python-programming/online-compiler/).


## 3.3. Javascript

**Javascript** es otro de los lenguajes más utilizados en la actualidad. Aunque no es tan limpio ni sencillo como Python, es fácil empezar a hacer programas sencillos con él.

Además, se caracteriza porque se ejecuta dentro de los navegadores web. Es decir, para empezar a trabajar con Javascript no necesitas más que un **editor de texto** y tu **navegador web** preferido.

En las siguientes secciones vamos a ver una breve introducción a Javascript.

### 3.3.1. Correspondencia entre pseudocódigo y Javascript

En la siguiente tabla se muestran las correspondencias entre las principales instrucciones de pseudocódigo y las de Javascript:

<table>
    <tr>
        <td style='background-color: lightgrey'>
        <strong>PSEUDOCÓDIGO</strong>
        </td>
        <td style='background-color: lightgrey'>
        <strong>JAVASCRIPT</strong>
        </td>
    </tr>
    <tr>
        <td>
        <strong>// Condicional simple</strong><br>
        Si condición entonces<br>
        &nbsp;&nbsp;&nbsp;acciones-1<br>
        FinSi
        </td>
        <td>
        <strong>// Condicional simple</strong><br>
        if (condicion) {<br>
        &nbsp;&nbsp;&nbsp;acciones;<br>
        }
        </td>
    </tr>
    <tr>
        <td>
        <strong>// Condicional doble</strong><br>
        Si condición entonces<br>
        &nbsp;&nbsp;&nbsp;acciones-1;<br>
        Sino<br>
        &nbsp;&nbsp;&nbsp;acciones-2;<br>
        FinSi
        </td>
        <td>
        <strong>// Condicional doble</strong><br>
        if (condicion) {<br>
        &nbsp;&nbsp;&nbsp;acciones-1;<br>
        }<br>
        else {<br>
        &nbsp;&nbsp;&nbsp;acciones-2;<br>
        }<br>
        </td>
    </tr>
    <tr>
        <td>
        <strong>// Bucle tipo “mientras”</strong><br>
        Mientras condición hacer<br>
        &nbsp;&nbsp;&nbsp;acciones<br>
        FinMientras
        </td>
        <td>
        <strong>// Bucle tipo “mientras”</strong><br>
        while (condición) {<br>
        &nbsp;&nbsp;&nbsp;acciones;<br>
        }<br>
        </td>
    </tr>
    <tr>
        <td>
        <strong>// Bucle tipo “para”</strong><br>
        Para variable <- valor_inicial hasta valor_final Hacer<br>
        &nbsp;&nbsp;&nbsp;acciones<br>
        FinPara
        </td>
        <td>
        <strong>// Bucle tipo “para” </strong><br>
        for (variable = valor_inicial; condicion; incremento) {<br>
        &nbsp;&nbsp;&nbsp;acciones;<br>
        }<br>
        </td>
    </tr>
    <tr>
        <td>
        <strong>// Asignación</strong><br>
        a <- 20
        </td>
        <td>
        <strong>// Asignación </strong><br>
        a = 20;
        </td>
    </tr>
    <tr>
        <td>
        <strong>// Salida de datos</strong><br>
        Escribir "El resultado es ", x
        </td>
        <td>
        <strong>// Salida de datos </strong><br>
        alert("El resultado es " + x);<br>
        <i>o bien:</i><br>
        document.write("El resultado es " + x);<br>
        <i>o bien:</i><br>
        document.getElementById('?').innerHTML += "El resultado es " + x;
        </td>
    </tr>
    <tr>
        <td>
        <strong>// Entrada de datos</strong><br>
        Escribir "Dime un número"<br>
        Leer variable
        </td>
        <td>
        <strong>// Entrada de datos </strong><br>
        variable = prompt("Dime un número");
        </td>
    </tr>
</table>

A continuación tienes un pequeño ejemplo de un algoritmo escrito en Pseudocódigo y su equivalente en Javascript. Fíjate en cómo se usan las llaves { y } para marcar el principio y el fin de un bloque de instrucciones.

<table>
    <tr>
        <td style='background-color: lightgrey'>
        <strong>PSEUDOCÓDIGO</strong>
        </td>
        <td style='background-color: lightgrey'>
        <strong>JAVASCRIPT</strong>
        </td>
    </tr>
<tr>
<td>
<pre>
i <- 0<br>
Mientras i < 100 hacer<br>
   Escribir i<br>
   i <- i + 1<br>
FinMientras<br>
<br>
// Esta instrucción ya está fuera del bucle<br>
Escribir "El bucle ha terminado"<br>
</pre>
</td>
<td>
<pre>
let i = 0;  // La primera vez que se usa una variable es conveniente anteponer la palabra "let"<br>
while (i < 100) {<br>
   document.write(i);<br>
   i = i + 1;<br>
}<br>
// Esta instrucción ya está fuera del bucle<br>
document.write("El bucle ha terminado");<br>
</pre>
</td>
</tr>
</table>

### 3.3.2. Un ejemplo sencillo de programa escrito en Javascript

Teniendo en cuenta la tabla anterior, es fácil escribir en Javascript el mismo programa que hicimos antes con pseudocódigo; ya sabes, aquel que mostraba todos los números enteros que hay entre dos números cualesquiera, A y B, que se introducen por teclado. 

Vamos a escribirlo usando **alert()** para la salida de datos, pero podríamos sustituirlo por **document.write()** y obtendríamos el mismo resultado, solo que presentado de otro modo. Te animo a probarlo para comprobar las diferencias.

```javascript
// Obtener los números del usuario
let A = parseInt(prompt("Dime un número: "));
let B = parseInt(prompt("Dime otro número: "));

// Determinar los valores de inicio y final
let inicio, final;
if (A < B) {
    inicio = A;
    final = B;
} else {
    inicio = B;
    final = A;
}

// Mostrar los números desde inicio hasta final
alert("Estos son los números desde " + inicio + " hasta " + final);

// Iterar y mostrar cada número
for (let i = inicio; i <= final; i++) {
    alert(i);
}
```

Observa cómo se hace la entrada de datos en las dos primeras instrucciones del algoritmo: no solo hay que usar la intrucción **prompt()**, sino que hay que usar una segunda instrucción **parseInt()**. 

Esto ocurre porque, en Javascript, cualquier cosa que se lea por el teclado se considera una cadena de caracteres. Para manipularla como otra cosa (por ejemplo, un número entero), es necesario *convertirla explícitamente* a ese tipo de datos. Y eso es exactamente lo que hace **parseInt()**: convertir lo que le pases entre paréntesis en un número entero.

### 3.3.3. Cómo ejecutar un programa escrito Javascript

Aunque los programas en Javascript pueden ejecutarse de diferentes maneras, sin duda la más habitual es lanzar el programa **dentro de un navegador web**.

Para lograrlo, debes seguir estos pasos:

1. Escribe tu programa Javascript con un editor de textos.
2. Coloca una etiqueta **script** *antes* y *después* de tu código fuente (ver ejemplo más abajo).
3. Guarda el archivo con extensión .html (por ejemplo, "mi-programa.html").
4. Abre el archivo .html con un navegador web.

Por ejemplo, el programa anterior se tendría que escribir así en el archivo .html (observa las etiquetas **script** antes y después del código):

```html
<script>
  // Obtener los números del usuario
  let A = parseInt(prompt("Dime un número: "));
  let B = parseInt(prompt("Dime otro número: "));
  // ...etc...
</script>
```

### 3.3.4. Funciones con Javascript

Javascript es un lenguaje **modular**, es decir, permite la escritura de subalgoritmos dentro de algoritmos. Todos los subalgoritmos en Javascript se llaman **funciones**.

Esta es la forma de crear una función:

```javascript
function nombre_funcion(parámetros) {
   Instrucciones de la función;
   return expresión;
}
```

El **return** es optativo. Una función de Javascript puede no tener **return**. Los **parámetros** también son optativos: puede haber funciones sin ningún parámetro y funciones con decenas de ellos.

La **invocación** de un subalgoritmo desde el algoritmo principal se hace poniendo el nombre de la función y su lista de parámetros (si los tiene).

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

### 3.3.5. Entrada y salida de datos con Javascript

Hay varias formas de hacer la entrada y salida de datos con Javascript, es decir, hay varios equivalentes a la instrucciones **Leer** y **Escribir** de pseudocódigo.

Para nuestros primeros ejemplos, hemos usado la función **prompt()** para hacer la entrada y **document.write()** o **alert()** para hacer la salida.

Vamos a ver un poco más despacio en qué se diferencian estos métodos.

#### Entrada de datos con prompt()

La **entrada de datos** en Javascript puede hacerse de diversas maneras. En particular, usando **formularios HTML**, pero de momento no necesitas pelearte con eso.

En esta primera toma de contacto con el lenguaje, vamos a conformarnos con la función **prompt()**. Esta función muestra un mensaje en forma de ventana emergente y permite escribir un texto, asignándolo a una variable.

Observa cómo se usa *prompt()* con este ejemplo escrito primero en pseudocódigo y luego en Javascript:

Pseudocódigo:
```
Escribir("Dime un número")
Leer n
```

Javascript:
```html
<script>
   n = prompt("Dime un número");
</script>
```

#### Salida de datos con innerHTML, document.write() y alert()

La forma más sencilla de hacer la salida de datos con Javascript es usar **document.write()** o su hermana melliza, **document.writeln()**.

Mira cómo se usa en este ejemplo:

Código:
```html
<script>
document.write("Hola, mundo");
</script>
```

Sin embargo, **document.write()** tiene un grave problema: puede que el texto de salida *no se muestre inmediatamente*. La decisión de cuándo se muestra la salida la toma el navegador y hay poco que puedas hacer al respecto. Por eso, la usaremos en contadas ocasiones.

Otra manera muy sencilla de hacer salida de datos es con **alert()**. Esta función muestra un texto en forma de ventana emergente. Parecido a *prompt()*, pero sin caja de texto para escribir. Observa a *alert()* en acción en el siguiente ejemplo:

Código:
```html
<script>
alert("Hola, mundo");
</script>
```

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

**Paso 2. Dentro de tu programa Javascript, utiliza *document.getElementById('salida').innerHTML = expresión* para hacer la salida**. Sí, lo sé, es un poco largo, pero Javascript es así. Por ejemplo, mira este código:

```html
<div id='salida' style='text-align: center; border-style: solid; border-color: black'></div>
<script>
   document.getElementById('salida').innerHTML = "Hola, mundo";
</script>
```
**Paso 3. Utiliza *document.getElementById('salida').innerHTML += expresión* si no quieres perder la salida anterior**. Es decir, si usas un **igual** (=), cada salida de datos borrará la pantalla. Si usas **más igual** (+=), la salida de datos se añadirá a la anterior, sin borrarla:

```html
<div id='salida' style='text-align: center; border-style: solid; border-color: black'></div>
<script>
   document.getElementById('salida').innerHTML += "Hola, mundo";
</script>
```

**Paso 4 (OPTATIVO). Cambia las propiedades de tu caja de salida**. Intenta juguetear con las propiedades ***text-align***, ***border-style*** o ***border-color*** del *div* de salida. Además, hay muchas otras propiedades que puedes asignarle a esa caja. Si te atreves, investiga un poco cómo cambiar el color del texto o la tipografía.

### 3.3.6. Alterando las propiedades de la página web con Javascript

Una de las cosas que hacen tan atractivo a Javascript es la posibilidad de manipular *cualquier* elemento de una página web para moverlo, ocultarlo o cambiarlo de forma, aspecto o contenido.

Para lograrlo, necesitas saber un poco de HTML. Si no es tu caso, olvida esta parte por ahora hasta que aprendas HTML.

Imagina que tienes una sencilla web con un texto, una imagen y un botón. Algo como esto:

```html
<h1 id='texto' style='color: red'>Esto es un título</h1>
<img id='imagen' src='mi-imagen' style='position: absolute; top: 100px; left: 50x'>
<input type='button' onclick='cambiar()'>Púlsame</input>
```

El texto se verá de color rojo y la imagen se posicionará en las coordenadas 100x50 de la ventana del navegador. Observa que ambos elementos tienen un atributo **id**. Esto es necesario para que, posteriormente, Javascript pueda modificarlos. 

Pues bien, con Javascript puedes cambiar eso cuando la página ya está cargada. Y vamos a hacer que suceda cuando se haga clic en el botón. ¿Has visto que el botón tiene un atributo llamado **onclick**? El nombre que aparece a continuación es el de una función Javascript que se ejecutará cuando se pulse el botón.

Así pues, puedemos añadir un pequeño script que haga cambios en la página:

```html
<h1 id='texto' style='color: red'>Esto es un título</h1>
<img id='imagen' src='mi-imagen' style='position: absolute; top: 100px; left: 50x'>
<input type='button' value='Púlsame' onclick='cambiar()'>

<script>
    function cambiar() {
        document.getElementById('texto').style.color = 'blue';
        document.getElementById('imagen').style.top = '200px';
    }
</script>
```

¿Puedes adivinar lo que ocurrirá al hacer clic en el botón? Exacto: el texto "Esto es un título" cambiará de rojo a azul, y la imagen se moverá hacia abajo en la pantalla. ¡Pruébalo en un navegador web si no te lo crees!

### 3.6.7. Temporizadores de Javascript

Lo que te voy a contar ahora puede considerarse Javascript avanzado (o, al menos, no es Javascript básico). Pero lo vas a necesitar para hacer juegos y otras diversiones con Javascript y, en fin, tampoco es tan complicado...

Se trata de los **temporizadores**.

Un temporizador es como el cronómetro de una bomba de relojería de las que salen en las películas. Ya sabes, esas bombas que siempre tienen una pantalla LCD donde se ve una cuenta atrás que indica cuánto falta para que explote.

(El temporizador es el cronómetro, no la bomba, que conste...)

Un temporizador se pone en marcha así:

```javascript
var timer = setTimeout('nombre-de-función', intervalo);
```

El *nombre-de-función* es exactamente eso: el nombre de alguna función Javascript que ya exista. El *intervalo* es un número entero.

Lo que hace el temporizador es **iniciar una cuenta atrás de *intervalo* milisegundos y, cuando el cronómetro llega a cero, se ejecuta la función indicada**.

Por ejemplo:

```javascript
var timer = setTimeout('saludar', 1000);

function saludar() {
   alert("Hola, mundo");
}
```

Si ejecutas este código, verás que el saludo (¡Hola, mundo!) tarda exactamente un segundo en aparecer. El temporizador se ha encargado de ello. Nada más ejecutar el código, se ha puesto en marcha un temporizador cuyo encargo es ejecutar la función *saludar()* al cabo de 1000 milisegundos (es decir, un segundo).

Programar acciones para que se realicen en el futuro abre muchísimas posibilidades. En particular, piensa en qué ocurriría si hacemos que la propia función *saludar()* vuelva a reestablecer el temporizador:

```javascript
var timer = setTimeout('saludar', 1000);

function saludar() {
   alert("Hola, mundo");
   setTimeout('saludar', 1000);
}
```

Detente un momento a tratar de averiguar qué ocurriría al ejecutar este programa y por qué podríamos decir sin dudarlo que se trata de uno de los programas más plastas que hemos escrito hasta ahora. Si no te lo crees, pruébalo y lo comprobarás.

Por último, si, por lo que sea, necesitas **detener un temporizador** que ya está en marcha, solo tienes que usar la función ***clearTimeout()***:

```javascript
clearTimeout(timer);
```

Lógicamente, la variable *timer* debe ser la misma que usaste al crear el temporizador.

### 3.3.8. Los objetos predefinidos de Javascript

Los **objetos predefindos de Javascript** son elementos del lenguaje que encierran dentro de sí una serie de funciones y variables para manipular diferentes aspectos de la página web y para facilitar la vida al programador.

Existen muchos objetos predefinidos en Javascript. Te voy a presentar a unos cuantos particularmente útiles, aunque debes saber que hay muchos más. Para esta introducción, con estos tendremos más que de sobra.

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

## 3.4. Errores frecuentes entre programadores novatos

En esta sección recopilo para ti algunas de las dudas, errores y pifias más frecuentes que, según mi experiencia como profesor de programación, suelen asaltar a los principantes.

Tanto si estás aprendiendo a programar con pseudocódigo como si lo haces con un lenguaje de programación real (como Python), es muy probable que hayas caído o vayas a caer en alguno de los siguientes errores, así que es buena idea que les eches un vistazo antes de lanzarte a hacer tu próximo programa.

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

## 3.4. Ejercicios propuestos

Vamos a resolver con pseudocódigo (o con Python o Javascript, si lo prefieres) varios de los ejercicios que ya propusimos hacer con diagramas de flujo. 

La idea es que ahora los **escribas, depures y pruebes tecleando el código**, no dibujando del diagrama de flujo.

Por lo tanto, necesitarás PseInt (si usas pseudocódigo) o Thonny (si usas Python) para realizar los siguientes ejercicios.

### 3.4.1. Ejercicios para pseudocódigo y Python

#### Ejercicio introductorio

**Ejercicio 0**.
<div style='background: #eee'>Escribe un programa que, simplemente, muestre el mensaje "Hola, mundo" por la consola de texto. Este programa, por tradición, es el primero que se escribe cuando un programador/a está probando un lenguaje o un entorno de desarrollo nuevo.</div>

#### Ejercicios con condicionales

**Ejercicio 9**. 
<div style='background: #eee'>Escribe un programa que lea tres números por teclado, X, Y y Z, y te diga si están ordenados de menor a mayor, es decir, si X es menor que Y y, además, Y es menor que Z.</div>

**Ejercicio 10 (optativo para ampliar)**. 
<div style='background: #eee'>Modifica el programa anterior para que, además de decirte si X, Y y Z están ordenados, te diga si son consecutivos.</div>

#### Ejercicios con bucles

**Ejercicio 17**. 
<div style='background: #eee'>Escribe un programa que calcule el sumatorio entre 1 y n, siendo n un entero introducido por teclado. Es decir, tiene que calcular 1 + 2 + 3 + ...  + n y mostrar el resultado en la pantalla.</div>

**Ejercicio 25**. 
<div style='background: #eee'>Escribe un programa que genere una combinación al azar para la quiniela (es decir, 14 valores dentro del conjunto 1, X o 2). Puedes generar un número aleatorio entre 1 y n con PseInt usando la función <i>azar(n)</i>. Con Python, eso mismo se hace escribiendo <i>randint(1,n)</i></div>

**Ejercicio 30. Juego del número secreto (optativo para ampliar)**. 
<div style='background: #eee'>En este programa, el ordenador elegirá un número al azar entre 1 y 100. El usuario irá introduciendo números por teclado, y el ordenador le irá dando pistas: "mi número es mayor" o "mi número es menor", hasta que el usuario acierte. Entonces el ordenador le felicitará y le comunicará el número de intentos que necesitó para acertar el número secreto**.</div>

**Ejercicio 33. Juego de dados (optativo: solo para valientes)**.

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

### 3.4.2. Ejercicios exclusivos para Javascript

Si lo tuyo es Javascript, a continuación te propongo algunos ejercicios interesantes (o eso espero) para que practiques con este lenguaje. IMPORTANTE: no intentes hacerlos con Pseudocódigo o con Python. No es que no se pueda, es que resulta mucho más difícil.

**EJERCICIO JAVASCRIPT 1. Botón saltarín**

**Vamos a hacer una página web con un botón. Al pulsar ese botón, Javascript hará que ¡el botón cambie de sitio!**

Para eso, capturaremos el **evento *click*** del botón.

El botón lo tienes que crear antes mediante HTML. No importa que no sepas HTML. Solo echa un vistazo a este código. Luego cópialo en un archivo de texto y guarda el archivo con el nombre ejercicio1.html:

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

Ahora solo te queda programar la función *mover_boton()*, que en el código anterior está vacía.

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

Con eso, el botón se moverá al hacer clic sobre él, pero solo la primera vez. Quedará colocado en la posición top = 150px y left = 250px y ya no se desplazará más.

**¿Y si quisiéramos que se moviera *siempre* que hagamos clic sobre él?** Piensa cómo lograrlo. Eso es lo que tienes que conseguir en este ejercicio.

**EJERCICIO JAVASCRIPT 2. Ventana nerviosa y botones evanescentes**

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

**EJERCICIO JAVASCRIPT 3. Colorines**

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

**EJERCICIO JAVASCRIPT 4. Pelota de goma**

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

**EJERCICIO JAVASCRIPT 5. Tenis**

*(ADVERTENCIA: este ejercicio es de dificultad elevada)*

Ya sabes hacer que una pelota rebote (ejercicio 5). **Vamos a mejorar ese programa haciendo una versión del clásico juego de tenis *"Pong"***, el primer videojuego comercial de la historia.

Si no conoces el *Pong*, bichea un poco por Internet para averiguar cómo es.

¡Y ahora trata de programar una versión actualizada en Javascript!

**EJERCICIO JAVASCRIPT 6. Carretera al infierno**

*(Advertencia: este ejercicio es de dificultad elevada)*

En esta ocasión, vamos a programar **un juego que llamaremos "Carretera al infierno"**.

En el juego, manejaremos un coche (busca en internet la imagen de un coche visto desde arriba). El coche aparecerá en la parte inferior de la pantalla, centrado y mirando hacia arriba.

Una carretera irá desplazándose de arriba a abajo. La carretera no será recta, sino que tendrá irregularidades aleatorias hacia la izquierda y hacia la derecha. Nuestro objetivo es mover el coche hacia la izquierda y hacia la derecha para evitar que se salga de la carretera.

La carreterá se moverá cada vez más deprisa. **El objetivo del juego es aguantar la mayor cantidad posible de tiempo sin salirnos.**