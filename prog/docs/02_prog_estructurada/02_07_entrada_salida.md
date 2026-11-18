---
layout: page
title: 2.7. Entrada y salida por consola
permalink: /programacion-estructurada/entrada-salida-consola/
nav_order: 7
has_children: true
parent: 2. Programación estructurada
grandparent: Programación
---

## 2.7. Entrada y salida por consola
{: .no_toc }

- TOC
{:toc}


Vamos a terminar este tema mencionando la entrada de datos por teclado y la salida de datos por consola: dos cuestiones imprescindibles para realizar cualquier programa de empiece a hacer cosas interesantes.

Ambos dispositivos se manejan mediante la clase System. Esta clase está en el paquete java.lang, que se carga automáticamente en todas las aplicaciones Java, sin necesidad de hacer import (en el ejemplo de la sección anterior, por lo tanto, hicimos un poco de trampa al ejecutar import java.lang.System)

La clase System contiene tres objetos static que se crean automáticamente al ejecutar cualquier programa Java, y que se destruyen ellos solitos al terminar. Estos objetos son:

* **System.out:** para manejar la salida estándar (consola)

* **System.in:** para manejar la entrada estándar (teclado)

* **System.err**: para manejar la salida de errores. No la usaremos de momento.

La salida a través del objeto System.out y, en concreto, del método System.out.println(), ya la has visto en multitud de ejemplos. Simplemente, envía el String indicado entre paréntesis a la consola.

```java
System.out.println("Hola, mundo");
```

Algo más complicada es la entrada de datos por teclado. Observa con atención este ejemplo:

```java
char c;
try {
   c = (char) System.in.read();
} catch (Excepcion e) {
   e.printStackTrace();
}
```

¡Uf\! A menudo se dice que Java no es un lenguaje adecuado para aprender a programar, y esta es una de las ocasiones en las que uno piensa que esa afirmación podría ser cierta. Es arduo explicar a un principiante qué demonios pone ahí. Digamos que Java tiene una obsesión un pelín delirante por la seguridad, y que ese mamotreto que ves ahí arriba es un reflejo de ello.

Ese trozo de código sirve para leer un carácter, ¡un simple carácter\!, por el teclado, y almacenarlo en la variable c. Todo ello se envuelve en un bloque try-catch de manejo de excepciones, de forma que si ocurre algo inesperado (como que el usuario teclee veinte caracteres en lugar de uno, o que haya pulsado CTRL-C, o que la CPU haya explotado, o vaya usted a saber qué), el programa sea capaz de detectarlo y reaccionar adecuadamente.

No te agobies ahora por los detalles. Recuerda que, para hacer una entrada por teclado, necesitas copiar y pegar el código de más arriba, y adaptarlo a tus variables. Ya volveremos más adelante, cuando estemos preparados, sobre el manejo de excepciones y el bloque try-catch.

Si lo que quieres es algo más sencillito (aunque menos seguro, ojo), como leer una cadena de caracteres completa desde el teclado en lugar de un solo carácter sin tener que escribir veinte líneas de código, existen otras formas de lograrlo. Insisto, menos seguras, porque pueden producir errores de ejecución. Pero nos servirán para empezar.

Aquí tres de ellas: 

**Forma número 1: usando System.console()**

```java
String dato = System.console().readLine();
```

**Forma número 2: usando un objeto Scanner**

```java
Scanner sc = new Scanner();
String s = sc.nextLine();
```

**Forma número 3: usando un objeto BufferedReader**

```java
InputStreamReader isr = new InputStreamReader(System.in);
BufferedReader buff = new BufferedReader(isr);
String dato = buff.readLine();
```

La primera forma es la más sencilla. ¿Para qué montar tanto lío para leer unos cuantos caracteres del teclado? Bien, la biblioteca de clases de Java está diseñada para ser muy robusta y versátil, y eso hace que haya que pagar algún pequeño precio en cuanto a usabilidad y legibilidad en ocasiones.

De estas tres formas, la más ortodoxa es la tercera, pero también es la más complicada. En cambio, la segunda, es decir, usar el objeto Scanner, es la manera más versátil y cómoda. Esa es la forma en la que vamos a preferir leer el teclado a lo largo de los próximos temas, pero te ponemos aquí las tres formas para que te suenen, por si las ves en código escrito por ahí.

#### Cómo usar correctamente un objeto Scanner

* Importar el paquete java.util.Scanner

* Crear un objeto de tipo Scanner

* Pedirle al objeto de tipo Scanner que te lea datos por teclado, indicándole el tipo de dato que esperas obtener.

Aquí tienes un ejemplo un poco más completo para que puedas ver la entrada por teclado en acción:

```java
Scanner sc = new Scanner(System.in);  // Creamos el objeto scanner
System.out.println("Por favor, teclea tu nombre: ");
String nombre = sc.nextLine();
System.out.println("Ahora teclea tu edad: ");
int edad = Integer.nextInt();
System.out.println("Hola, " + nombre + ", tienes " + edad + " años");
```

Sí, lo has adivinado: sc.nextLine() te devuelve lo que sea que se haya tecleado convertido en un String, mientras que nextInt() te lo devuelve como un int. Como todo lo que se lee desde el teclado es, en principio, un String, esta última conversión podría fallar y debería estar dentro de un bloque try-catch, pero esa... esa es otra historia.

La mala noticia es esa: leer el teclado con Scanner podría fallar en algunas consolas. Para hacer un código totalmente confiable necesitas recurrir al BufferedReader, o sea, a la forma más complicada. El ejemplo anterior quedaría más o menos así (observa como hemos resumido en una línea la creación de los objetos InputStreamReader y BufferedReader):

```java
import java.io.*;
...

BufferedReader buff = new BufferedReader(new InputStreamReader(System.in));
try {
   String nombre = buff.readLine();
}
catch (Exception e) {
   e.printStackTrace();
}
System.out.println("Ahora teclea tu edad: ");
int edad = Integer.parseInt(buff.readLine());
System.out.println("Hola, " + nombre + ", tienes " + edad + " años");
```

Recuerda: sin agobios. Para hacer entrada por teclado, por el momento solo tienes que recordar tres palabras: **copia**, **pega** y **adapta**.

