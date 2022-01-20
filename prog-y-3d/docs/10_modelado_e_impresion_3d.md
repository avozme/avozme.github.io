---
layout: page
title: 10. Modelado e impresión 3D
permalink: /modelado-e-impresion-3d/
nav_order: 10
has_children: true
parent: Introd. a la prog. y al diseño 3D
---

# 10. Modelado e impresión 3D
{: .no_toc }

- TOC
{:toc}

En este capítulo vamos a aprender a usar una herramienta de **modelado 3D** llamada **TinkerCAD**. Se trata de una aplicación online muy sencilla (para tratarse de modelado 3D), intuitiva y gratuita que puede usarse desde cualquier navegador web, independientemente de tu sistema operativo.

Posteriormente, veremos como los modelos 3D creados con TinkerCAD puede **trocearse en capas** (*slicing*) para su tratamiento con una impresora 3D y qué tenemos que hacer para **obtener ese modelo finalmente impreso**.

## 10.1. Software para diseño 3D: TinkerCAD

*(Este apartado está adaptado del artículo "Mega Tutorial TinkerCAD, cómo utilizarlo Paso a Paso", publicado por Jorge Lorenzo en https://of3lia.com/tinkercad-tutorial-completo/)*

Aunque existen programas de modelado 3D tan alucinantes como *Blender*, *Maya* o *3DSmax* (el primero de ellos, encima, gratuito), para aprender los fundamentos de estas técnicas sin complicarse mucho la vida, sin duda lo más apropiado es **TinkerCAD**. 

TinkerCAD es versátil, no hace falta instalarlo, es muy potente, es muy estable y, además, es online.

Es verdad que resulta algo más limitado que sus hermanos mayores, ya que no tiene tantas opciones como otros programa de modelado 3D, pero, para la gran mayoría de nosotros, lo que ofrece TinkerCAD es más que suficiente.

### 10.1.1. Qué es TinkerCAD y cómo funciona

**TinkerCAD** es un **programa de modelado 3D** que crea las piezas con el método *lowpoly*, que consiste en la **unión de polígonos** en un número relativamente bajo (comparado con otros programas) para crear los modelos. 

TinkerCAD trae un montón de figuras geométricas predefinidas para que las puedas usar en tus diseños. Para crear un perro, por ejemplo, tendrías que pensar qué conjunto de figuras es más adecuado unir: cilindros para las patas, una esfera para la cabeza, dos conos para las orejas... Cada una de estas figuras está constituida por un montón de polígonos que TinkerCAD maneja por nosotros.

XXX imagen de perro cutre

Además, como TinkerCAD es online, no hay que descargarlo, instalarlo ni configurarlo: basta con crearse una cuenta en su web [www.tinkercad.com](https://www.tinkercad.com/). Existen cuentas de tres tipos: 

* Educadores: pensada para profesores/as que quieren usar TinkerCAD en sus clases.
* Estudiantes: para alumnos/as de los profesores anteriores. Los profesores pueden crear clases y los estudiantes pueden unirse a esas clases. Los miembros de una clase pueden interactuar entre ellos, ver sus diferentes trabajos o colaborar en grupos.
* Cuentas personales: para el público en general.

XXX imagen home + imagen tipos usuario

### 10.1.2. Moviéndose por TinkerCAD

Los controles de TinkerCAD son muy sencillos. Eso sí, necesitarás un ratón con ruleta central. Estos son los principales:

* **Click izquierdo**: Selección.
* **Click derecho**: Rotación.
* **Ruleta del ratón**: Zoom.
* **Click en ruleta ratón**: Traslación.

Cuando seleccionas un objeto, aparecen unos controles muy intuitivos a su alrededor para **moverlo, rotarlo y escalarlo**. Además, también puedes mover el **cubo** que hay en la parte superior izquierda para mover todo el objeto y si das doble click en sus caras posicionas tu vista de forma perpendicular a ese plano.

XXX tutorial-tinkercad-2

### 10.1.3. El panel de control

En esta imagen puedes ver el aspecto del **panel de control** de TinkerCAD con sus áreas principales numeradas:

XXX tutorial-tinkercad-3

Las áreas del panel de control son estas:

1. **Espacio de trabajo**. El cuadrado grande es la superficie de trabajo y el pequeño son las opciones de dicha superficie: tamaño total, tamaño de la rejilla y unidades de medición.

2. **Modos de visualización**. El primero es el ***cubo*** de visualización, que nos permite rotar el objeto. Después tenemos la ***vista inicial***, para volver a la visualización estándar, los controles de ***zoom*** (para acercarnos o alejarnos del objeto) y el ***cambio de vista*** (para activar o desactivar la perspectiva isométrica).

3. **Zona de edición de objetos**. Aquí podremos ocultar objetos si nos molestan, hacer simetrías, agrupar, desagrupar y alinear. Es una de las herramientas que más usaremos.

4. **Zona de usuario**: importar y exportar archivos y acceder funcionalidades adicionales.

5. **Banco de piezas**. Aquí está toda la (enorme) biblioteca de pieza prediseñadas de TinkerCAD. Esta es una de las principales características que diferencian a TinkerCAD de otros programas de modelado 3D: la enorme cantidad de figuras predefinidas que existen. Otros programas tienen solo cubos, conos, cilindros y poco más.

   Encima de la biblioteca encontrarás las herramientas del **plano de trabajo** y la **regla**. Más adelante veremos para qué sirven.

6. **Herramientas de edición del documento**: copiar, pegar, duplicar, eliminar, rehacer, deshacer... Si hacemos click justo al lado del nombre del documento, podremos cambiar su visibilidad y su tipo de licencia.

### 10.1.4. Cómo modelar objetos 3D con TinkerCAD

**Modelar objetos 3D** con TinkerCAD es muy fácil, al menos en comparación con otros programas de diseño 3D.

Vamos a hacer recorrido por el proceso mediante unos ejemplos, revisando con ellos las cuatro cosas fundamentales que se usan en todos los modelados. Una vez que hayas asimilado esas cuatro cosas, podrás aplicarlas por tu cuenta para diseñar cualquier otro objeto, simplemente dejando volar tu imaginación.

#### Hacer uniones y vaciados entre formas

Una de las cosas más habituales que se han en los programas de diseño 3D es **unir dos objetos** entre sí.

Para entender cómo funciona, sigue estos pasos:

1. Arrastra un cubo al espacio de trabajo.
2. Arrastra un cilindro al espacio de trabajo.
3. Agranda el cilindro.
4. Mete el cubo en el cilindro y vuelve a pulsar el cubo.
5. Ahora te toca decidir: déjalo como está o selecciona la opción *"hueco"*. Cuando te decidas, pulsa *"Agrupar"*.

Si has escogido la primera opción, se habrá formado un sólido a partir de la **unión** de las dos piezas. La pieza resultante es ahora una sola, y cuando la escales o la muevas se moverá como tal.

Si has escogido la segunda opción 2, se habrá formado un sólido a partir de la **diferencia** de una pieza con la otra. Es decir, has escogido que el cubo sea un hueco. Y si juntas un sólido con un hueco, ¿qué tienes? Muy fácil: un sólido con un agujero.

Acabas de practicar tu primer **vaciado** de piezas.

La unión y el vaciado son dos de las operaciones más comunes durante el modelado. Si controlas bien estas dos operaciones, puedes hacer casi cualquier cosa.

tutorial-tinkercad-7

#### Cambiar el plano de trabajo

Sigamos trabajando con nuestro sólido con agujero, al que vamos a llamar *"cabaña"*. 

Ahora queremos ponerle un bonito **tejado cónico**. Para ello, podemos crear un cono, agrandarlo y subirlo hasta la parte superior de nuestro objeto, ¿verdad?

Pero *hay una solución más fácil*.

Seleccionar la herramienta **Plano de trabajo** y sitúa el nuevo plano sobre el tejado de nuestra pieza. Verás que también puedes ponerlo en las paredes, en la puerta o donde te dé la gana.

tutorial-tinkercad-8

Ahora crea un cono sobre el plano y listo. Como ves, el nuevo plano de trabajo tiene otro color para distinguirlo del original.

Esta es herramienta es muy útil para no tener que mover objetos continuamente hasta colocarlos en su lugar. Además, no necesitas tener una cara plana para crear un nuevo plano de trabajo: incluso puedes hacerlo tangente a una esfera.

Para **volver al plano de trabajo original**, pulsa sobre la herramienta y selecciónalo otra vez. Así de sencillo.

tutorial-tinkercad-9

#### Transformar, alinear y medir

El siguiente ejemplo lo vamos a hacer con **cuatro esferas** coloreadas como las fichas del parchís:

tutorial-tinkercad-10

Lo primero que haremos será **transformarlas**. Para ello, selecciona una de ellas (la azul, por ejemplo), y verás que salen varios iconos:

* Los **puntos blancos** transforman la pieza en dos dimensiones a la vez (X e Y) o solo el eje Z.
* Los **puntos negros** transforman la pieza en una sola dimensión (X o Y).
* La **flecha negra** superior mueve el objeto hacia arriba y hacia abajo.
* Las **flechas curvas** rotan la pieza en cualquiera de los 3 ejes (X, Y o Z).

Si, además, pulsas la **tecla Mayúsculas** y mueves uno de los puntos blancos, la figura se **escala** uniformemente.

tutorial-tinkercad-11

Otra cuestión fundamental es **alinear objetos**. Cuando tienes varios objetos, a menudo necesitarás dejarlos perfectamente alineados. Hacerlo a mano es tedioso e inexacto. TinkerCAD lo hace por ti.

Simplemente, selecciona la esfera roja y la esfera verde y pulsa "Alinear". Vamos a alinearlas en la línea media del eje longitudinal.

tutorial-tinkercad-12

Y ahora intena alinear todas las esferas entre sí, en disposición de rectángulo.

tutorial-tinkercad-13

Finalmente, vamos a ver para que sirve la **regla**. 

Al posicionar la regla te darás cuenta de dos cosas:

* Puedes cambiar todas las medidas de la pelota (ya que las ves).
* Puedes cambiar la posición relativa de los objetos con respecto a la regla.

tutorial-tinkercad-14

Esto te ayudará a saber la posición relativa entre los objetos, por si necesitas medidas exactas. Vamos a probarlo poniendo las esferas en forma de cuadrado de 40 mm de lado.

tutorial-tinkercad-15

Si interiorizas todo esto bien (a base de practicar un buen rato), ya puedes considerarte un usuario/a avanzado/a en TinkerCAD. Pero aún vamos a aprender un par de cosas más...

### 10.1.5. Edición de objetos externos a TinkerCAD

TinkerCAD también puede manipular modelos 3D hechos por otras personas, aunque hayan usado otros programas.

Por ejemplo, vamos a diseñar una taza con la cabeza de Ironman capaz de contener en su interior una lata de refresco convencional.

Ve a la web de [Thingiverse](https://www.thingiverse.com/), un portal donde los usuarios suben sus diseños 3D para que otros usuarios puedan descargarlos libremente, y descárgarte el busto de Ironman (simplemente, busca "Ironman Bust"):

tutorial-tinkercad-16

(Si tienes problemas para descargarlo, inténtalo desde [aquí](XXX link a STL de ironman en assets))

Ahora sigue estos pasos:

* Escala el busto para que mida 140 mm de ancho.
* Crea 3 cubos huecos para quitarle toda la parte del cuerpo (hombros incluidos). El cubo central hasta la barbilla mide 63mm de alto. Ahora se los restamos.
* Inserta un cilindro de 67mm de diámetro y 115mm de alto. Esto es debido a que las latas convencionales de refresco miden 66mm de diámetro, y tenemos que dejar al menos 1mm de holgura.
* Inserta un toroide (o "donut") como mango.
* Haz la unión de todos los elementos.

tutorial-tinkercad-17

Más o menos así debería quedarte el resultado: ¡una taza de Ironman para latas diseñada en cinco minutos!

tutorial-tinkercad-18

### 10.1.6. El generador de formas

Si has usado las formas básicas un tiempo, te habrás dado cuenta de que cada objeto tiene sus propiedades: longitud, altura, anchura. Pero ¿y si hubiera objetos con otras propiedades diferentes? ¿Y si los pudiéramos crear nosotros y asignarles las propiedades que queramos?

Para eso sirve el **generador de formas**. Lo encontrarás en el mismo lugar que las formas básicas, pero en otra pestaña diferente. Ten en cuenta que todos estos objetos tienen diferentes propiedades modificables: lapared de ladrillos, por ejemplo, además del grosor, el ancho o el alto, te permite manipular el número de filas de ladrillos o el grosor de los ladrillos, propiedades que no tendrían sentido en otros objetos.

Entre los objetos que puedes encontrar en el generador de formas encontrarás cosas tan locas como:

* Mapas de muchos lugares del mundo, incluyendo Europa y países europeos.
* Una casa completa con jardín.
* Importar archivos .svg (imágenes vectoriales)
* Generador de código QR.
* Diagramas circulares y de barras.
* Figuras del Carcassonne (un popular juego de mesa).
* Engranajes diversos.
* Un generador de funciones 3D y otro de superficies.
* Un taladro (la boquilla)
* Un mandala.
* Una caja ventilada para meter placas electrónicas.
* Un reflector parabólico paramétrico.
* Perfiles aerodinámicos de avión.
* Una matriz circular de perfil personalizable.
* Una matriz 3D con cubos y nomenclatura matriz.
* La curva de Moebius.
* Un árbol con fractales.
* El mosaico de Penrose.
* Simuladores de terreno (rocoso y de hierva).

¡Y así hasta 17 páginas completas!

### 10.1.7

XXXYYY

📝 Esto no acaba aquí guaperas: Ejercicio Práctico.
¿Te has enterado de algo? No contestes, y haz mi ejercicio.

Consiste en replicar el coche de Of3lia de forma un tanto apañada y solo mediante las figuras básicas. Si quieres ahorrar tiempo usa el truco de cambio de plano y alinea cuanto puedas. No te doy más pistas.

3, 2, 1… Al lío 🙂

tutorial-tinkercad-27
tutorial-tinkercad-28
tutorial-tinkercad-29
Solución
▶️ Más Tutoriales de TinkerCAD en Video
He estado buscando algunos tutoriales de TinkerCAD en video por si te venían mejor, aunque personalmente, creo que vas a tardar más en verlos que en leerte este artículo, pero hay gente que lo asume mejor.

El mejor que he encontrado es este, que es el único que no me parece un petardo de ver. Disfrútalo 🙂


💙 ¿Qué te ha parecido mi tutorial de TinkerCAD el mejor programa de diseño 3D online?
Disfruto muchísimo haciendo estos tutoriales la verdad, pero es una matada. Espero que hayas disfrutado este tutorial de tinkercad 3d para diseñar en español, inglés o el idioma que sea, es lo chulo de esto, solo hace falta contar y ya.

Si has llegado aqúi, mis enhorabuenas, casi nadie lo consigue. Me encantaría saber que te ha parecido el post y cualquierduda quetengas, no dudes en ponérmela por aquí 🙂

Si quieres ver más programas de diseño 3D (los que yo uso), te dejo un post estupendo que hice hace poco (y lo actualizo).

Un abrazo y hasta la próxima.



## 10.2. Software para *slicing* (laminado)

## 10.3. Creación e impresión de figuras básicas

## 10.4. Transformación, rotación y unión de figuras básicas

## 10.5. Formatos de archivo para impresión 3D

## 10.6. Pruebas de impresión

## 10.7. Actividades propuestas


