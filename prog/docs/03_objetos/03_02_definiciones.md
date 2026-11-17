---
layout: page
title: 3.2. Definiciones y características
permalink: /objetos/definiciones/
nav_order: 2
has_children: true
parent: 3. Los objetos
grandparent: Programación
---

## 3.2. Definiciones y características
{: .no_toc }

- TOC
{:toc}


Una vez vista de manera informal la filosofía que subyace en el paradigma de orientación a objetos, pasamos a enumerar de manera más formal los diferentes **conceptos** que aparecerán de ahora en adelante de manera insistente. Como hemos dicho muchas veces, no te preocupes (de momento) si no entiendes todo lo que aquí se dice. Preocúpate solo si, al finalizar el libro, sigues sin saber qué son algunos de los siguientes conceptos.

### 3.2.1. Conceptos principales en la POO

#### Objetos

Un objeto es una unidad que engloba dentro de sí un conjunto de datos y las funciones necesarias para el tratamiento de esos datos. 

Un objeto se caracteriza por:

* Su identidad: cada objeto es único y diferente del resto. Internamente se le asigna un ID para diferenciarlo de otros objetos, aunque pertenezcan a la misma clase y tengan todos sus valores internos con el mismo valor.

* Su estado: el estado de un objeto viene dado por el valor de sus atributos o variables internas.

* Su comportamiento: el comportamiento de un objeto se define mediante los métodos o fragmentos de código que operan con los atributos internos del objeto e interactúan, si es necesario, con otros objetos. 

#### Clases

Una clase es un patrón para construir objetos. Por tanto, un objeto es una variable perteneciente a una clase determinada. Es importante distinguir entre objetos y clases: la clase es simplemente una declaración, no tiene asociado ningún objeto. Y todo objeto debe pertenecer a una clase.

#### Atributos o propiedades

Los atributos o propiedades son los datos incluidos en un objeto. Son como las variables en los lenguajes de programación clásicos, pero están encapsuladas dentro de un objeto y, salvo que se indique lo contrario, son invisibles desde el exterior.

#### Estado

El estado de un objeto es el conjunto de los valores que, en un momento dado, tengan sus propiedades.

#### Métodos

Se llaman métodos a las funciones que pertenecen a un objeto. Es decir: son fragmentos de código con un nombre que permite invocarlos y ejecutarlos, pero están encapsulados dentro del objeto. Tienen acceso a los atributos del mismo y son la forma de operar con los atributos desde el exterior del objeto. Son, en definitiva, los "diales" de la caja negra. 

#### Mensajes

El mensaje es el modo en que se comunican los objetos entre sí. Un mensaje no es más que una llamada a un método de un determinado objeto. Cuando llamemos a un método de un objeto, a menudo diremos que estamos enviando un mensaje a ese objeto, y el objeto reaccionará ejecutando el código asociado a ese mensaje. 

#### Interfaz

Las clases (y, por lo tanto, también los objetos) tienen partes públicas y partes privadas. La parte pública es visible para el resto de los objetos, mientras que la privada sólo es visible para el propio objeto. A la parte pública de un objeto se le denomina interfaz. 

### 3.2.2. Características principales de la POO

A continuación definiremos otros conceptos relativos a la programación orientada a objetos, abreviada a veces como OOP (del inglés *Object Oriented Programming*). Se trata de las características más destacables de este paradigma: términos que te vas a encontrar en cualquier sitio que hable de OOP.

Algunos de ellos no los vas a comprender todavía, o no en toda su extensión e implicaciones. Ya sabes: no te preocupes. Volveremos a ellos una y otra vez en los siguientes temas.

#### Abstracción

Cuando se programa con OOP, se intentan abstraer las características de los objetos del problema que estamos tratando de informatizar, para crear a partir de ello las clases y sus métodos.

#### Encapsulamiento

Como ya hemos dicho varias veces, los miembros privados de una clase no son accesibles desde otras clases. Es decir, desde una clase no se puede invocar un método de otra clase a menos que se indique lo contrario.

Se denomina encapsulamiento al hecho de que cada objeto se comporte de modo autónomo, de manera que lo que pase en su interior sea invisible para el resto de objetos. Cada objeto sólo responde a ciertos mensajes (llamadas a sus métodos) y proporciona determinadas salidas. Los procesos que lleve a cabo para obtener esas están totalmente ocultos al resto de objetos.

El concepto de encapsulamiento ya estaba presente en la programación modular, donde se perseguía maximizar la cohesión y minimizar el acoplamiento de los módulos. Esa idea es llevada a sus últimos términos por la programación orientada a objetos.

#### Herencia

Es posible diseñar nuevas clases basándose en clases ya existentes. Esto se llama herencia. Cuando una clase hereda de otra, toma todos los atributos y todos los métodos de su clase “madre”, y puede añadir los suyos propios. A veces, algunos de los métodos o datos heredados no son útiles, por lo que pueden ser enmascarados, redefinidos o simplemente eliminados en la nueva clase.

#### Polimorfismo

Este "palabro" se refiere a la posibilidad de crear varias versiones del mismo método, de forma que se comporte de maneras diferentes dependiendo del estado del objeto o de los parámetros de entrada.

### 3.2.3. Ventajas de la POO

La OOP se ha impuesto con fuerza en las dos últimas décadas, y no ha sido por casualidad. De hecho, proporciona varias ventajas importantes a la hora de desarrollar y mantener aplicaciones software, que se traducen, en definitiva, en un ahorro de tiempo y esfuerzo. Y, en consecuencia, de dinero.

Estas ventajas son:

* **Modularidad**: el código de un objeto puede modificarse, mantenerse o mejorarse sin que ello afecte al resto del sistema, siempre que respetemos su interfaz (así, los demás objetos del programa se seguirán comunicando con el objeto modificado sin que sepan que éste ha cambiado)

* **Reutilización de código**: es muy sencillo utilizar clases y objetos de terceras partes. Solo tienen que publicar el interfaz de sus clases, y podemos empezar a usarlas en muy poco tiempo, sin preocuparnos de cómo funcionan por dentro, igual que el técnico de la lavadora sustituye una pieza electrónica por otra sin saber exactamente como están hechas.

* **Facilidad de prueba y mantenimiento**: si tenemos un objeto que está dando problemas, es fácil aislar el elemento que falla y modificarlo sin que ello afecte al resto del código de la aplicación.

* **Ocultación de información**: como cada objeto oculta los detalles de su implementación al resto, es virtualmente imposible que un malfuncionamiento en una parte del sistema pueda afectar a otras.

