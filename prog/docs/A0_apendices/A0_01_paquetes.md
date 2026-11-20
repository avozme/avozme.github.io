---
layout: page
title: A1. Paquetes
permalink: /apendices/paquetes/
nav_order: 1
has_children: true
parent: Apéndices
grandparent: Programación
---

## Apéndice 1. Paquetes

#### Qué son los paquetes en Java

Un **paquete** o **package** es un conjunto de clases relacionadas entre sí empaquetadas en un archivo. En el JDK existen multitud de paquetes estándar que usarás continuamente, y, además, puedes encontrar paquetes de terceros para hacer todo tipo de cosas. Y tú mismo aprenderás a hacer tus propios paquetes.

Un paquete en Java es, pues, lo que en otros lenguajes se denomina librería o biblioteca.

Por ejemplo, en el JDK existe un paquete llamado java.io, donde se agrupan todas las clases que permiten hacer la entrada/salida de datos (por consola y teclado, pero también escribir en archivos de disco, por ejemplo).

El uso de paquetes permite agrupar las clases relacionadas en un solo lugar y, además, evitar posibles conflictos con nombres de clases y métodos que se repitan. Al estar en paquetes separados, ya no es posible la confusión.

Para usar un paquete se utiliza la sentencia import. En este ejemplo puedes ver su uso:

```java
// Para importar la clase System del paquete java.lang
import java.lang.System;

// Para importar TODAS las clases del paquete java.lang
import java.lang.*;
```

Una vez importado un paquete, podemos usar los métodos del mismo sin indicar el nombre completo del paquete. Por ejemplo, en lugar de hacer esto:

```java
System.out.println("Hola, mundo");
```

Podemos hacer esto:

```java
import java.lang.System;
out.println("Hola, mundo");
```

Para acceder correctamente a los paquetes, el compilador de Java necesita saber dónde están los archivos de la biblioteca de clases, es decir, tienes que configurar adecuadamente la variable de entorno CLASSPATH. Esto ya no es necesario en las última versiones de Java si hablamos de los paquetes estándar del JDK, pero sí lo será si utilizas paquetes de terceros.

```bash
$ CLASSPATH = <ruta a la biblioteca de clases>:<ruta 2>:<ruta 3>:etc
$ export CLASSPATH
```

(sustituye el carácter : por ; si estás trabajando en un sistema Windows)

Recuerda que, como vimos en el tema 1, también puedes compilar el programa con la opcion \-cp, indicando a continuación el classpath de tu aplicación:

```bash
$ javac -cp /ruta/a/mis/clases nombre.java
```

#### Algunos paquetes notables del JDK

El JDK de Java, como hemos dicho, proporciona una colección realmente enorme de clases, todas ellas agrupadas en sus correspondientes paquetes. Puedes consultar la lista completa en la documentación oficial online de Oracle.

Realmente, no existe ningún programador en el mundo que conozca en profundidad el funcionamiento de todas esas clases, ni falta que le hace para programar bien. Sería tan absurdo como suponer que una persona debe conocer a todos los habitantes de la ciudad en la que vive. Uno conoce a sus compañeros de trabajo o de clase, a su familia, tal vez a sus vecinos, y a un puñado más o menos extenso de amigos. Eso sucede también con la biblioteca de clases: acabarás conociendo con bastante detalle algunas clases a fuerza de usarlas una y otra vez, pero el resto serán como esa gente anónima que te cruzas continuamente por la calle.

Eso sí, si algún día las necesitas, debes ser capaz de acudir a la documentación (mejor la oficial), mirar un par de ejemplos, y hacer uso de cualquier clase de la biblioteca que no habías conocido antes.

Te presentamos aquí una lista con los paquetes más utilizados del JDK de Java, de modo que sepas por dónde empezar a buscar en caso necesario y que te vayan sonando los nombres:

* **java.lang**: Contiene la clases fundamentales del lenguaje. Se carga automáticamente con cuaquier programa, sin necesidad de hacer import.

* **java.util**: Clases relacionadas con las colecciones y estructuras de datos: listas, colas, pilas, y muchas otras.

* **java.io, java.nio**: Clases relacionadas con la entrada/salida por consola y por otras vías.

* **java.math**: Clases para cálculos y operaciones matemáticas.

* **java.awt, java.swing**: Clases para generar interfaces gráficos (ventanas, botones, etc)

* **java.sql**: Clases para gestionar el acceso a bases de datos externas.

* **java.net**: Clases para gestionar el trabajo en red.

