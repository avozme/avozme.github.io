---
layout: page
title: 2.1. Qué es la programación estructurada
permalink: /programacion-estructurada/introduccion/
nav_order: 1
has_children: true
parent: 2. Programación estructurada
grandparent: Programación
---
## 2.1. Qué es la programación estructurada

El término programación estructurada se refiere a un conjunto de técnicas que han ido evolucionando desde los primeros trabajos del holandés E. Dijkstra. Pese a ser físico, Dijkstra fue uno de los más importantes científicos de la computación hasta su muerte en 2002. Una de sus frases más famosas es:

> "La pregunta de si un computador puede pensar no es más interesante que la pregunta de si un submarino puede nadar"

Estas técnicas de programación estructurada de Dijkstra aumentan la productividad del programador, reduciendo el tiempo requerido para escribir, verificar, depurar y mantener los programas, y por ese motivo han sido plenamente asimiladas por la programación orientada a objetos.

Allá por mayo de 1966, Böhm y Jacopini demostraron (en la revista "Communications of the ACM", vol. 9, nº 5) que se puede escribir cualquier programa propio utilizando solo tres tipos de estructuras de control: la secuencial, la selectiva (o condicional) y la repetitiva. A esto se le llama **Teorema de la programación estructurada**, y define un programa propio como un programa que cumple tres características:

* Posee un sólo punto de inicio y un sólo punto de fin.
* Existe al menos un camino que parte del inicio y llega hasta el fin pasando por todas las partes del programa.
* No existen bucles infinitos.

Realmente, el trabajo de Dijkstra basado en este teorema fue revolucionario, porque lo que venía a decir es que, para construir programas más potentes y en menos tiempo, lo que había que hacer era simplificar las herramientas que se utilizaban para hacerlos, en lugar de complicarlas más. Este regreso a la simplicidad, unido a las técnicas de ingeniería del software, acabó con la crisis del software de los años 70.

Por lo tanto, los programas estructurados deben limitarse a usar tres estructuras:

* Secuencial
* Selectiva (o condicional)
* Repetitiva

La programación orientada a objetos, como vimos en el tema 1, es una evolución de la programación estructurada clásica en la que los algoritmos y los datos se encapsulan en clases que más tarde se instancian en objetos que interactúan entre sí. Pero lo que hay dentro de esos algoritmos siguen siendo programas estructurados. Es decir, la POO es un superconjunto de la programación estructurada clásica, y por eso es pertinente que, en este punto, estudiemos esas estructuras detenidamente.
