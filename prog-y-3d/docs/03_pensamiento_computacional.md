---
layout: page
title: 5. Pensamiento computacional
permalink: /pensamiento-computacional/
nav_order: 5
has_children: true
parent: Introd. a la prog. y al diseño 3D
---

# 5. Pensamiento computacional
{: .no_toc }

- TOC
{:toc}


## 5.1. ¿Qué es eso del pensamiento computacional?

El pensamiento computacional es un proceso de **formulación y resolución de problemas que utiliza los conceptos de la ingeniería informática**. 

Es decir, consiste en pensar como lo haría un científico-informático cuando está frente un problema y tener la habilidad y la actitud para que nos sea útil tanto en nuestra vida personal como profesional. 

Hemos dicho "vida personal", sí. Uno de los errores más frecuentes cuando se habla de *pensamiento computacional* es considerar que solo se aplica a la Informática.

El pensamiento computacional **sirve para resolver problemas cotidianos haciendo uso de las técnicas y habilidades de los programadores/as informáticos** y obtener así soluciones que pueden ser representadas mediante una serie de pasos o instrucciones.

Aquí tienes un vídeo que desarrolla esta interesante idea en tres minutos:

<iframe width="560" height="315" src="https://www.youtube.com/embed/veXgaxaNICM" title="YouTube video player" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture" allowfullscreen></iframe>



## 5.2. Características del pensamiento computacional

Según las definiciones que hemos visto en el apartado anterior, el pensamiento computacional es un proceso de resolución de problemas que incluye las siguientes características:

* Reformular problemas de forma que se permita el uso de un ordenador y otras herramientas para ayudar a resolverlos.
* Organizar y analizar lógicamente la información.
* Representar la información a través de abstracciones como los modelos y las simulaciones.
* Automatizar soluciones haciendo uso del pensamiento algorítmico (estableciendo una serie de pasos ordenados para llegar a la solución).
* Identificar, analizar e implementar posibles soluciones con el objetivo de lograr la combinación más efectiva y eficiente de pasos y recursos.
* Generalizar y transferir este proceso de resolución de problemas para ser capaz de resolver una gran variedad de familias de problemas.

#### Ejemplo de pensamiento computacional

Escribir **una receta de cocina** siguiendo unos pasos o instrucciones sería un buen primer ejemplo de aplicación para el pensamiento computacional.

Por ejemplo, supongamos que queremos cocinar un *risotto* utilizando un sobre de comida preparada (para que sea más rápido). No te preocupes si no tienes ni idea de lo que es un *risotto*. En realidad, y gracias al pensamiento computacional, no necesitas saber lo que es para prepararlo, puesto que el pensamiento computacional te permite disponer de una receta.

En este caso, los pasos de la receta serían más o menos estos:

1. Abrir el sobre
2. Poner a calentar el agua
3. Esperar a que el agua hierva
4. Si hierve, verter el sobre
5. Remover el contenido de la olla
6. Apagar el fuego y dejar reposar
7. Servir en el plato para "x" personas

Si sigues esos pasos, seguro que puedes obtener algo comestible aunque no tengas ni idea de qué estás cocinando en realidad, ¿verdad?

El pensamiento computacional consiste en enfrentarse a un problema (como "cocinar un *risotto*") y obtener una solución (como una "receta") que permita solucionarlo todas las veces que sean necesarias.

Si la "receta" anterior la escribiéramos usando un lenguaje de programación, tendríamos en nuestras manos un programa de ordenador.

De hecho, podemos "escribirla" en un lenguaje de programación por bloques gráficos, como el popular *Scratch*, y nos quedaría algo así:

![Ejemplo de receta escrita con Scratch](/docs/prog-y-3d/_site/assets/images/01-scratch.jpg)

## 5.3. El pensamiento computacional vs la programación

Los términos "pensamiento computacional" y "programación" no son sinónimos. Esta es una confusión muy habitual.

La programación solo es una de las posibles herramientas con la que se pone en práctica el pensamiento computacional. Por eso la programación y el pensamiento computacional comparten los mismos procesos cognitivos.

La programación limita sus procesos de resolución de problemas al ámbito de la informática. Para ello, hace uso de diferentes lenguajes de programación.

Puedes pedir a un ordenador que haga muchas cosas, pero no que prepare un *risotto*. Así que el pensamiento computacional puede aplicarse a problemas más allá de la informática.

> ***Curiosidad**: ¿sabías que las peronas que aprenden a utilizar un lenguaje de programación muestran mayor capacidad de atención y autonomía, y obtienen en promedio mejores resultados en pruebas matemáticas, que las que no saben programar?*

[Diversos estudios](https://www.redalyc.org/pdf/547/54741184011.pdf) han demostrado que, mediante los lenguajes de programación, se desarrollan ciertas habilidades cognitivas como:

* El pensamiento lógico.
* La creatividad.
* El razonamiento abstracto.
* La capacidad de resolución de problemas.

Así que, si quieres orientar tu vida académica hacia las ciencias o la ingeniería, aprender a programar puede ser una herramienta muy útil para ti. Pero incluso si tus preferencias académicas van por otro camino, las rutinas de pensamiento computacional que adquirirás programando te reportarán muchos beneficios que quizá no sospechabas. 

## 5.4. Algoritmos y descomposición de problemas

Tanto el pensamiento computacional como la programación utilizan procesos cognitivos idénticos, como hemos dicho.

Y el principal de ellos se denomina **"Divide y vencerás"** (*"Divide and Conquer"* en inglés). Es decir: descompón tu problema en problemas más pequeños, hasta que sean lo suficientente pequeños para afrontarlos. Y luego reúnelos todos como un puzle para componer la solución final.

Fácil de explicar, difícil de hacer.

![Divide y vencerás](/docs/prog-y-3d/_site/assets/images/01-divide-y-venceras.jpg)


El pensamiento computacional busca encontrar una "receta" para resolver cualquier problema computable. Esas recetas se denominan **algoritmos**.

Un algoritmo, por tanto, es *un conjunto de pasos que, aplicados sistemáticamente a unos datos de entrada apropiados, resuelven un problema en un numero finito de pasos.*

Nuestra receta de cocina para el *risotto* era un algoritmo. Las instrucciones para fabricar un avión de papel a partir de un folio también lo son. El motor de búsqueda de Google es otro algoritmo.

Obviamente, el grado de complejidad de esos algoritmos no es comparable entre sí. Pero todos son algoritmos.

Los algoritmos tienen una **entrada** (input) y una **salida** (output), y entre ambas están los pasos o instrucciones.

La entrada de un algoritmo pueden ser los ingredientes para cocinar un *risotto*, y la salida es el plato comestible. Este es un algoritmo computable pero no programable, porque ningún ordenador podría ejecutarlo.

La entrada del algoritmo de Google es el texto que escribimos en la caja de búsqueda, y la salida es la lista de resultados. Este es un algoritmo computable y programable (de hecho, la gente de Google lo ha programado, ¿no?)

En realidad, los algoritmos recogen operaciones tan sencillas que pueden ser realizadas con éxito por cualquiera. *Incluso por las máquinas*.

**La unión de máquinas y algoritmos es lo que está cambiando el mundo**. 

El matemático británico [Alan Turing](https://es.wikipedia.org/wiki/Alan_Turing), famoso por haber *hackeado* la máquina Enigma de mensajes cifrados de los nazis muchos años antes de que se inventara el término "*hackear*", y por haberse suicidado tras sufrir una dura persecución debido a su condición homosexual, fue de los primeros que relacionó algoritmos y ordenadores. De hecho, fue de los primeros que imaginó un ordenador tal y como lo conocemos hoy.

Así es: los ordenadores actuales son, en esencia, *Máquinas de Turing* mucho más potentes de lo que Turing pudo soñar.

![Alan Turing](/docs/prog-y-3d/_site/assets/images/01-alan-turing.jpg)


**El trabajo de los programadores/as informáticos** consiste en traducir los problemas del mundo a un lenguaje que una máquina pueda entender. 

Así, **un programa de ordenador** es un algoritmo escrito en un lenguaje de programación. Es decir, un conjunto de miles (¡o millones!) de operaciones sencillas que, como las piezas de un puzle, encajan para dar lugar a la solución final.

Los algoritmos se usan para cualquier cosa: predecir resultados electorales, calcular trayectorias de satélites, conocer nuestros gustos y preferencias... El mundo del trabajo se va *algoritmizando* poco a poco: las diferentes tareas se convierten en algoritmos y se automatiza el trabajo. 

**Las únicas tareas no computables, por el momento, son las relacionadas con la creatividad y las emociones**. ¡Así que ya sabes dónde seguirá existiendo trabajo en las próximas décadas!

## 5.5. Algunos algoritmos famosos en tiempos de internet

La palabra algoritmo se ha puesto de moda en los últimos años. Los ordenadores pueden hacer cálculo mucho más deprisa, y con mucha más fiabilidad, que un cerebro humano. Desde la aparición de Internet, se ha producido un salto cualitativo y estamos llegando a computar cosas que antes parecían imposibles. 

Por eso han surgido disciplinas en plena ebullición como el *big data* o la inteligencia artificial.

#### El Algoritmo de Facebook

![Edgerank, el algoritmo de Facebook](/docs/prog-y-3d/_site/assets/images/01-edgerank.jpg)

En el *big data*, los algoritmos analizan millones de datos de los clientes. Hay algoritmos ejecutándose en los ordenadores de a bordo de los automóviles, en los satélites de control de tráfico o en las redes sociales. 

El algoritmo que decide qué ve cada usuario en su muro de Facebook fue uno de los primeros en utilizar *big data*. Es un algoritmo tan famoso que hasta tiene nombre propio: **EdgeRank**.

Cada vez que Facebook realiza cambios importantes en *EdgeRank*, se produce un revuelo en Facebook. A principios de 2018, por ejemplo, Facebook decidió dar más importancia a los usuarios particulares que a las empresas, marcas y medios de comunicación, en un intento de que la red social volviera a ser más "social" y paliar un poco la invasión de las *fake news*. El cambio dio bastantes quebraderos de cabeza a empresas y medios y, en algunos casos, provocó pérdidas millonarias.

#### Algoritmo de Google

![Pagerank, el algoritmo de Google](/docs/prog-y-3d/_site/assets/images/01-pagerank.jpg)

Tal vez el algoritmo más famoso del mundo, después del de la multiplicación, sea el de Google.

Creado en 1998 y llamado **PageRank**, su éxito revolucionario consistió en que rastreaba la web y daba resultados de búsqueda ordenados por su importancia.

¿Y cómo mide *PageRank* la importancia de cada web? Es un secreto mejor guardado que la fórmula de la Coca-cola. 

El *PageRank* original medía la importancia de una web por la cantidad de webs que estaban enlazadas a ella. Esa fue la clave de su éxito inicial. En la actualidad, sospecho que ni siquiera los ingenieros de Google están muy seguros de qué cosas mide *PageRank* y en qué medida influyen en sus resultados.

Actualmente, *PageRank* es capaz de adaptar sus resultados al usuario (no es lo mismo ser un adulto que un niño, o lanzar una búsqueda desde Almería que hacerlo desde Silicon Valley), ofrecer mapas, imágenes, corregir la ortografía de la búsqueda o entender cuándo en la caja de búsqueda se escribe una pregunta. Y darle respuesta.

#### El algoritmo de Amazon

![A9, el algoritmo de Amazon](/docs/prog-y-3d/_site/assets/images/01-amazon.jpg)

¿Despedido por un algoritmo? No es ciencia ficción. De hecho, es algo que ocurre desde hace años. Las máquinas toman decisiones en lugar de los humanos pero que afectan directamente los humanos.

Entre 2017 y 2018, más de 300 empleados de Amazon fueron despedidos por falta de productividad en una de sus sedes en Baltimore.

Lo llamativo es que detrás esta decisión no hubo una inteligencia humana, sino artificial. Amazon mide individual y automáticamente la productividad de cada trabajador en base al número de paquetes que confeccionan cada hora. El programa, en caso de detectar empleados de baja productividad, genera automáticamente advertencias e incluso procesa automáticamente despidos, sin la intervención de los supervisores.

De esta forma, los empleados son supervisados por algoritmos que llegan hasta el punto de conocer el tiempo que emplean fuera de sus tareças. Por ejemplo, si los empleados dejan de escanear paquetes durante demasiado tiempo, el sistema genera automáticamente alertas y el empleado puede ser despedido.

Por otro lado, Amazon ha sido acusado en repetidas ocasiones de manipular sus algoritmos de búsqueda de productos dentro de su web, para priorizar los productos que les son más rentables. Cosa que no es de extrañar, por otra parte, ¿no te parece?

La cuestión es esta: *un pequeño cambio en un algoritmo puede afectar a una gran parte del comercio electrónico mundial y a miles de fabricantes y vendedores*.

## 5.6. Actividades

#### Ejercicio 1

Vamos a escribir nuestro primer algoritmo. Así, sin miedo.

Imagina que tienes que explicarle a un extraterrestre recién llegado a la Tierra cómo debe cruzar un semáforo para evitar ser arrollado por los coches.

(Si la metáfora del extraterrestre te parece excesiva, imagina que se lo tienes que explicar a un niño o niña muy pequeño)

El extraterrestre (o el niño) solo comprende órdenes muy sencillas: camina, no camines, mira la luz, ¿es verde?, ¿es roja?, y cosas así.

Tienes que exponer las instrucciones en una lista de pasos o "receta de cocina" expresada con acciones sencillas como las anteriores. Venga, a ver qué te sale.

(Nota: no te desesperes si no sabes ni cómo empezar. Eso le pasa a todo el mundo la primera vez)

#### Ejercicio 2

Ahora lo vamos a complicar un poco más, enfrentándonos a un algoritmo clásico en las ciencias de la computación.

Se trata de encontrar el camino más corto entre dos puntos. En nuestro caso, queremos llegar desde A (Salida) hasta F (Meta). Cada camino tiene un peso (el numerito indicado en él). Puedes considerar que ese peso es el tiempo o la distancia, da lo mismo.

Constrúyete una tabla con todos los diferentes caminos o recorridos posibles y el valor total de tiempo (o distancia) que acaba sumando cada uno de ellos.

![Grafo de Dijkstra](/docs/prog-y-3d/_site/assets/images/01-grafo.jpg)

¿Cómo se podría construir un algoritmo genérico que encontrase el camino más corto entre dos puntos cualesquiera, en un mapa con cualquier número de puntos y cualquier número de contexiones?

Trata de pensarlo unos minutos. Después, cuando notes que la cabeza va a explotarte, bichea un poco por Internet en busca del **algoritmo de Dijkstra**. Brevemente y con tus propias palabras, comenta en qué consiste y trata de aplicarlo al problema anterior.

#### Ejercicio 3

Investiga en internet quién fue **Ada Lovelace** y explica en pocas frases qué relación tiene con el mundo de los algoritmos y la programación de ordenadores.

#### Ejercicio 4

Investiga en Internet sobre el escándalo de **Cambridge Analytica** y responde con tus palabras (¡y brevemente!) a las siguientes cuestiones:

1. Detalla qué es Cambridge Analytica y a qué se dedicaba.
2. ¿Con qué fin recababa Cambridge Analytica datos y perfiles de usuarios?
3. ¿Cuándo y por qué se produjo un escándalo mundial relacionado directamente con ella?
4. Describe el funcionamiento del algoritmo de Cambridge Analytica y explica como pudo influenciar mediante el mismo en las victorias de Donald Trump en Estados Unidos y del Brexit en Inglaterra?
5. ¿Cuál fue el número de usuarios de Facebook afectados? ¿Cuantos miles de millones de dólaresperdió Facebook tras el escándalo?
6. Busca y encuentra un video corto en youtube donde aparezca Mark Zuckerberg declarando en el congreso de Estados Unidos, dando explicaciones sobre el escándalo de Cambridge Analytica. (No olvides activar los subtítulos si tienes problemas con el inglés). ¿Con qué argumentos se defendió Zuckerberg de las acusaciones?

#### Ejercicio 5

Vamos investigar entre todos sobre algunos algoritmos famosos en la historia de la computación:

1. Algoritmo del viajante de comercio.
2. Algoritmo de los filósofos comensales.
3. Algoritmo quicksort
4. Algoritmo mergesort
5. Algoritmo bubblesort o algoritmo de la burbuja
6. Algoritmo auto-tune
7. Algoritmo de la transformada rápida de Fourier
8. Algoritmo OkCupid Date Matching
9. Algoritmo de las ocho reinas
10. Algoritmo de la criba de Eratóstenes
11. Algoritmo MD5
12. Algoritmo SHA1

Una vez que se te asigne uno de estos algoritmos, lo que tienes que investigar es muy sencillo:

* ¿Qué problema pretende resolver ese algoritmo?
* ¿Cómo lo resuelve? (Expresado en términos sencillos y de andar por casa)