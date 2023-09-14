---
layout: page
title: 4. Modelado e impresión 3D
permalink: /modelado-e-impresion-3d/
nav_order: 4
has_children: true
parent: Introd. a la prog. y al diseño 3D
---

# 4. Modelado e impresión 3D
{: .no_toc }

- TOC
{:toc}

En este capítulo vamos a aprender a usar una herramienta de **modelado 3D** llamada **TinkerCAD**. Se trata de una aplicación online muy sencilla (para tratarse de modelado 3D) e intuitiva que puede usarse desde cualquier navegador web, independientemente de tu sistema operativo. Y, encima, es gratuita.

También veremos cómo los modelos 3D creados con TinkerCAD pueden **laminarse en capas** (*slicing*) para su tratamiento con una impresora 3D y qué tenemos que hacer para **obtener ese modelo finalmente impreso**.

## 4.1. Software para diseño 3D: TinkerCAD

*(Este apartado está adaptado del artículo "Mega Tutorial TinkerCAD, cómo utilizarlo Paso a Paso", publicado por Jorge Lorenzo en https://of3lia.com/tinkercad-tutorial-completo/)*

Aunque existen programas de modelado 3D tan alucinantes como *Blender*, *Maya* o *3DSmax* (el primero de ellos, encima, gratuito), para aprender los fundamentos de estas técnicas sin complicarse mucho la vida, sin duda lo más apropiado es **TinkerCAD**. 

TinkerCAD es versátil, no hace falta instalarlo, es muy potente, es muy estable y, además, es online.

Es verdad que resulta algo más limitado que sus hermanos mayores, ya que no tiene tantas opciones como otros programa de modelado 3D, pero, para la gran mayoría de nosotros, lo que ofrece TinkerCAD es más que suficiente.

### 4.1.1. Qué es TinkerCAD y cómo funciona

**TinkerCAD** es un **programa de modelado 3D** que crea las piezas con el método *lowpoly*, que consiste en la **unión de polígonos** en un número relativamente bajo (comparado con otros programas) para crear los modelos. 

TinkerCAD trae un montón de figuras geométricas predefinidas para que las puedas usar en tus diseños. Para crear un perro, por ejemplo, tendrías que pensar qué conjunto de figuras es más adecuado unir: cilindros para las patas, una esfera para la cabeza, dos conos para las orejas... Cada una de estas figuras está constituida por un montón de polígonos que TinkerCAD maneja por nosotros.

![Figura simple](/docs/prog-y-3d/_site/assets/images/10-tinkercad-01.jpg)
<div style='font-size: 75%; font-style: italic'>
Un perro salchicha modelado con TinkerCAD de forma muy cutre y empleando solo formas geométricas simples
</div>

Además, como TinkerCAD es online, no hay que descargarlo, instalarlo ni configurarlo: basta con crearse una cuenta en su web [www.tinkercad.com](https://www.tinkercad.com/). Existen cuentas de tres tipos: 

* Educadores: pensada para profesores/as que quieren usar TinkerCAD en sus clases.
* Estudiantes: para alumnos/as de los profesores anteriores. Los profesores pueden crear clases y los estudiantes pueden unirse a esas clases. Los miembros de una clase pueden interactuar entre ellos, ver sus diferentes trabajos o colaborar en grupos.
* Cuentas personales: para el público en general.

![TinkerCAD - Homepage](/docs/prog-y-3d/_site/assets/images/10-tinkercad-00-A.png)
<div style='font-size: 75%; font-style: italic'>
Homepage de TinkerCAD
</div>
<div>&nbsp;</div>

![TinkerCAD - Tipos de usuario](/docs/prog-y-3d/_site/assets/images/10-tinkercad-00-B.png)
<div style='font-size: 75%; font-style: italic'>
Al registrarte, puedes indicar qué tipo de usuario eres<br>
</div>

### 4.1.2. Moviéndose por TinkerCAD

Los controles de TinkerCAD son muy sencillos. Eso sí, necesitarás un ratón con ruleta central. Estos son los principales:

* **Click izquierdo**: Selección.
* **Click derecho**: Rotación.
* **Ruleta del ratón**: Zoom.
* **Click en ruleta ratón**: Traslación.

Cuando seleccionas un objeto, aparecen unos controles muy intuitivos a su alrededor para **moverlo, rotarlo y escalarlo**. Además, también puedes mover el **cubo** que hay en la parte superior izquierda para mover todo el objeto y si das doble click en sus caras posicionas tu vista de forma perpendicular a ese plano.

![Controles de TinkerCAD](/docs/prog-y-3d/_site/assets/images/10-tinkercad-02.jpg)

### 4.1.3. El panel de control

En esta imagen puedes ver el aspecto del **panel de control** de TinkerCAD con sus áreas principales numeradas:

![Panel de control de TinkerCAD](/docs/prog-y-3d/_site/assets/images/10-tinkercad-03.jpg)

Las áreas del panel de control son estas:

1. **Espacio de trabajo**. El cuadrado grande es la superficie de trabajo y el pequeño son las opciones de dicha superficie: tamaño total, tamaño de la rejilla y unidades de medición.

2. **Modos de visualización**. El primero es el ***cubo*** de visualización, que nos permite rotar el objeto. Después tenemos la ***vista inicial***, para volver a la visualización estándar, los controles de ***zoom*** (para acercarnos o alejarnos del objeto) y el ***cambio de vista*** (para activar o desactivar la perspectiva isométrica).

3. **Zona de edición de objetos**. Aquí podremos ocultar objetos si nos molestan, hacer simetrías, agrupar, desagrupar y alinear. Es una de las herramientas que más usaremos.

4. **Zona de usuario**: importar y exportar archivos y acceder funcionalidades adicionales.

5. **Banco de piezas**. Aquí está toda la (enorme) biblioteca de pieza prediseñadas de TinkerCAD. Esta es una de las principales características que diferencian a TinkerCAD de otros programas de modelado 3D: la enorme cantidad de figuras predefinidas que existen. Otros programas tienen solo cubos, conos, cilindros y poco más.

   Encima de la biblioteca encontrarás las herramientas del **plano de trabajo** y la **regla**. Más adelante veremos para qué sirven.

6. **Herramientas de edición del documento**: copiar, pegar, duplicar, eliminar, rehacer, deshacer... Si hacemos click justo al lado del nombre del documento, podremos cambiar su visibilidad y su tipo de licencia.

### 4.1.4. Cómo modelar objetos 3D con TinkerCAD

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

![Uniones y vaciados con TinkerCAD](/docs/prog-y-3d/_site/assets/images/10-tinkercad-07.jpg)

#### Cambiar el plano de trabajo

Sigamos trabajando con nuestro sólido con agujero, al que vamos a llamar *"cabaña"*. 

Ahora queremos ponerle un bonito **tejado cónico**. Para ello, podemos crear un cono, agrandarlo y subirlo hasta la parte superior de nuestro objeto, ¿verdad?

Pero *hay una solución más fácil*.

Seleccionar la herramienta **Plano de trabajo** y sitúa el nuevo plano sobre el tejado de nuestra pieza. Verás que también puedes ponerlo en las paredes, en la puerta o donde te dé la gana.

![Cambiar el plano de trabajo](/docs/prog-y-3d/_site/assets/images/10-tinkercad-08.jpg)

Ahora crea un cono sobre el plano y listo. Como ves, el nuevo plano de trabajo tiene otro color para distinguirlo del original.

Esta es herramienta es muy útil para no tener que mover objetos continuamente hasta colocarlos en su lugar. Además, no necesitas tener una cara plana para crear un nuevo plano de trabajo: incluso puedes hacerlo tangente a una esfera.

Para **volver al plano de trabajo original**, pulsa sobre la herramienta y selecciónalo otra vez. Así de sencillo.

![Volver al plano de trabajo original](/docs/prog-y-3d/_site/assets/images/10-tinkercad-09.jpg)

#### Transformar, alinear y medir

El siguiente ejemplo lo vamos a hacer con **cuatro esferas** coloreadas como las fichas del parchís:

![Cuatro esferas](/docs/prog-y-3d/_site/assets/images/10-tinkercad-10.jpg)

Lo primero que haremos será **transformarlas**. Para ello, selecciona una de ellas (la azul, por ejemplo), y verás que salen varios iconos:

* Los **puntos blancos** transforman la pieza en dos dimensiones a la vez (X e Y) o solo el eje Z.
* Los **puntos negros** transforman la pieza en una sola dimensión (X o Y).
* La **flecha negra** superior mueve el objeto hacia arriba y hacia abajo.
* Las **flechas curvas** rotan la pieza en cualquiera de los 3 ejes (X, Y o Z).

Si, además, pulsas la **tecla Mayúsculas** y mueves uno de los puntos blancos, la figura se **escala** uniformemente.

![Escalado](/docs/prog-y-3d/_site/assets/images/10-tinkercad-11.jpg)

Otra cuestión fundamental es **alinear objetos**. Cuando tienes varios objetos, a menudo necesitarás dejarlos perfectamente alineados. Hacerlo a mano es tedioso e inexacto. TinkerCAD lo hace por ti.

Simplemente, selecciona la esfera roja y la esfera verde y pulsa "Alinear". Vamos a alinearlas en la línea media del eje longitudinal.

![Alineación](/docs/prog-y-3d/_site/assets/images/10-tinkercad-12.jpg)

Y ahora intena alinear todas las esferas entre sí, en disposición de rectángulo.

![Alineación en rectángulo](/docs/prog-y-3d/_site/assets/images/10-tinkercad-13.jpg)

Finalmente, vamos a ver para que sirve la **regla**. 

Al posicionar la regla te darás cuenta de dos cosas:

* Puedes cambiar todas las medidas de la pelota (ya que las ves).
* Puedes cambiar la posición relativa de los objetos con respecto a la regla.

![Regla](/docs/prog-y-3d/_site/assets/images/10-tinkercad-14.jpg)

Esto te ayudará a saber la posición relativa entre los objetos, por si necesitas medidas exactas. Vamos a probarlo poniendo las esferas en forma de cuadrado de 40 mm de lado.

![Regla](/docs/prog-y-3d/_site/assets/images/10-tinkercad-15.jpg)

Si interiorizas todo esto bien (a base de practicar un buen rato), ya puedes considerarte un usuario/a avanzado/a en TinkerCAD. Pero aún vamos a aprender un par de cosas más...

### 4.1.5. Edición de objetos externos a TinkerCAD

TinkerCAD también puede manipular modelos 3D hechos por otras personas, aunque hayan usado otros programas.

Por ejemplo, vamos a diseñar una taza con la cabeza de Ironman capaz de contener en su interior una lata de refresco convencional.

Ve a la web de [Thingiverse](https://www.thingiverse.com/), un portal donde los usuarios suben sus diseños 3D para que otros usuarios puedan descargarlos libremente, y descárgarte el busto de Ironman (simplemente, busca "Ironman Bust"):

![Edición de objetos externos con TinkerCAD](/docs/prog-y-3d/_site/assets/images/10-tinkercad-16.jpg)

(Si tienes problemas para descargarlo, inténtalo desde [aquí](/docs/prog-y-3d/_site/assets/images/10-ironman-bust.stl))

Ahora sigue estos pasos:

* Escala el busto para que mida 140 mm de ancho.
* Crea 3 cubos huecos para quitarle toda la parte del cuerpo (hombros incluidos). El cubo central hasta la barbilla mide 63mm de alto. Ahora se los restamos.
* Inserta un cilindro de 67mm de diámetro y 115mm de alto. Esto es debido a que las latas convencionales de refresco miden 66mm de diámetro, y tenemos que dejar al menos 1mm de holgura.
* Inserta un toroide (o "donut") como mango.
* Haz la unión de todos los elementos.

![Edición de objetos externos con TinkerCAD](/docs/prog-y-3d/_site/assets/images/10-tinkercad-17.jpg)

Más o menos así debería quedarte el resultado: ¡una taza de Ironman para latas diseñada en cinco minutos!

![Taza de Ironman](/docs/prog-y-3d/_site/assets/images/10-tinkercad-18.jpg)

### 4.1.6. El generador de formas

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
* Simuladores de terreno (rocoso y de hierba).

¡Y así hasta 17 páginas completas!

### 4.1.7. Algunos aspectos avanzados de TinkerCAD

Aunque es un software mucho más sencillo que otros como *Blender* o *Maya*, TinkerCAD también esconde sus características avanzadas. Aquí te resumo algunas que pueden resultarte útiles.

#### Atajos de teclado

Si te aprendes los siguientes atajos de teclado, te convertirás en un diseñador (o diseñadora) mucho más rápido y eficaz:

* **Ctrl + C, Ctrl + V**: copiar y pegar.
* **Ctrl + Z, Ctrl + Y**: deshacer y rehacer.
* **Ctrl + D**: duplicar el objeto seleccionado.
* **Ctrl + H**: ocultar el objeto seleccionado.
* **Ctrl + Shift + H**: mostrar todos los objetos ocultos.
* **Ctrl + G**: agrupar los objetos seleccionados.
* **Ctrl + Shift + G**: desagrupar el objeto seleccionado.
* **L**: abrir la herramienta para alinear.
* **M**: abrir la herramienta "espejo".

#### Diferencia entre "copy-paste" y "duplicar"

Si te has fijado, hay dos formas de crear copias de un objeto: por un lado, el clásico "copiar y pegar" y, por otro, "duplicar".

La principal diferencia entre estos dos procedimientos es cómo manejan las transformaciones:

* **Si haces "copiar y pegar"**, las transformaciones que hayas aplicado al objeto copiado no se aplican al nuevo objeto. Por ejemplo, si el objeto copiado está rotado 20 grados a la derecha, la copia no lo estará.
* **Si haces "duplicar"**, todas las transformaciones del objeto original se aplicarán también al objeto duplicado.

#### Cambiar la rejilla

El plano de trabajo tiene una rejilla cuadriculada que nos ayuda a conseguir la sensación de perspectiva. Esa rejilla puede cambiarse haciendo clic en la esquina inferior derecha del área de trabajo, donde está el **botón "Edit Grid"**.

En la ventana que aparece entonces puedes elegir la configuración de la rejilla que más te convenga. Por ejemplo, puedes cambiar el tamaño del plano de trabajo. Puede ser muy útil para hacerlo coincidir con el tamaño de la cama de tu impresora 3D.

#### Bloques de código

**Tinkercad Codeblocks** permite generar objetos mediante programación visual (no confundir con "Code Blocks", una herramienta *open source* de programación visual semejante a *Scratch*).

Para iniciar *Codeblocks* en TinkerCAD, solo tienes que ir a la página principal de la web, iniciar tu sesión y hacer click en la opción "Bloques de código" -> "Crear nuevo bloque de código".

![Acceso a Codeblocks](/docs/prog-y-3d/_site/assets/images/10-codeblocks-01.png)

La edición de objetos por bloques de código te proporciona un montón de objetos predefinidos para empezar a trabajar con ellos. Es buena idea que pruebes alguno sencillito para ver qué aspecto tienen los bloques de código. Si has trabajado con *Scratch*, te resultará muy familiar. En general, cualquiera que haya programado alguna vez, se acostumbrará rápidamente a los bloques de código.

Por ejemplo, este es el aspecto de los bloques de código que generan una sencilla mesa con cuatro patas:

![Generación de mesa roja con Codeblocks](/docs/prog-y-3d/_site/assets/images/10-codeblocks-02.png)

A la izquierda tienes los tipos de bloque disponibles, en el centro los bloques que estás usando y a la derecha el resultado.

Los bloques de la zona centras se "ejecutan" de arriba a abajo para obtener la figura final. Para "ejecutar" el programa y ver cómo se va construyendo la figura al seguir los pasos, pulsa el botón "Play" que hay arriba a la derecha.

Por ejemplo, en el programa de la imagen anterior, la secuencia de pasos es esta:

* Se definen algunas variables, como el alto, el ancho y la profundidad de la mesa, o la longitud de las patas.
* Se crea un cubo de color rojo
* Se mueve el cubo a la posición 0,0 del plano de trabajo.
* Se crean otros dos cubos, que se usarán para hacer el "vaciado" de la parte inferior de la mesa.
* Se agrupan los tres cubos, haciendo la operación de vaciado (como haríamos con el editor 3D).
* Se reposiciona el grupo resultante para que la mesa quede justo sobre el plano de trabajo

Puedes encajar y desencajar bloques de la secuencia para cambiar la manera en la que se genera el objeto. De este modo, y con un poco de práctica, lograrás crear objetos muy complejos en menos tiempo que si los hicieras con el editor 3D.

### 4.1.8. Exportando nuestros modelos para impresión 3D

Desde TinkerCAD, es muy sencillo **exportar un modelo para imprimirlo con una impresora 3D**.

Simplemente, haz clic en el **botón "Exportar"** que encontrarás tanto en la pantalla de edición del modelo como en la pantalla principal de TinkerCAD.

También podemos abrir la pantalla de edición de un modelo y seleccionar un solo objeto de nuestra escena (si es que tenemos varios) y, a continuación, hacer clic en "Exportar" para guardar en un archivo solo ese objeto, no la escena completa.

Al exportar un modelo 3D, la aplicación te preguntará qué **formato de archivo** quieres utilizar. Para impresión 3D, TinkerCAD soporta archivos STL y OBJ, así que ha llegado el momento de que conozcas qué tipos de archivos para modelos 3D existen.

## 4.2. Formatos de archivo para impresión 3D

Como ocurre con las imágenes planas o los archivos de vídeo, hay un montón de formatos diferentes para los modelos 3D. En este apartado vamos a conocer los principales y qué características tienen.

Todos los archivos de modelos 3D contienen, como mínimo, una definición de la geometría de la pieza. Algunos, además, pueden contener información sobre las texturas, la escala, etc.

A la hora de elegir un formato u otro, tienes que fijarte en la precisión con la que son capaces de reproducir el modelo original y, además, consultar la documentación de tu impresora para saber qué formatos soporta.

#### Formato STL

El formato STL es el formato de modelos 3D *más popular* en el ámbito de la impresión 3D. Y también uno de los *más antiguos* y *menos precisos*.
   
Fue creado en los años 90 por la empresa 3D Systems para la impresión 3D usando esterolitografía. Los archivos STL contienen las coordenadas de los polígonos que conforman la **geometría tridimensional** del objeto, excluyendo otras propiedades como el color, la escala, o la estructura del modelo. Una peculiaridad de los archivos STL es que el único polígono que soporta es el **triángulo**, por lo que, si nuestro modelo está hecho con otro tipo de polígonos, al exportarlo a STL estos polígonos se descomponen en triángulos.

Existen varios tipos de archivo STL, pero los más comunes son el **ASCII** y el **binario**. Hay varios matices en el funcionamiento de cada uno, pero quédate con la idea de que los STL binarios son algo más pequeños y aparecieron como respuesta al tamaño creciente de los STL ASCII. A pesar de ser más ligeros, los STL binarios siguen ocupando demasiado tamaño si queremos dar mucha resolución a un objeto, ya que necesitaremos incluir muchos triángulos.

Este formato es, actualmente, el más utilizado para compartir modelos para impresión 3D, aunque no es ni de lejos el mejor, ya que existen formatos más modernos que ocupan menos espacio y añaden más información.

#### Formato OBJ

El formato OBJ, pese a ser menos conocido que el STL, es también muy popular y casi cualquier software relacionado con el diseño o la impresión 3D acepta este formato. Este formato es mucho más complejo y dispone de dos modos de funcionamiento:

* **Modo preciso**. Un archivo OBJ que utilice codificación precisa no hara descripción del modelo en polígonos, como sí hace un STL. En su lugar, conservará la geometría original del modelo utilizando unas líneas tridimensionales conocidas como **NURBS** (Non-uniform Rational B-spline). Esto significa que, usando un OBJ podemos capturar la geometría «original» del modelo, no una aproximación construída a partir de triángulos.

* **Modo aproximado**. Un archivo OBJ que utilice una codificación aproximada genera una versión simplificada de la superficie del modelo a través de polígonos, como ocurre con un STL. En este caso, no estamos limitados a triángulos, sino que se pueden usar otros polígonos, por lo que, pese a ser solo una aproximación de la geometría original, podemos conseguir acabados más suaves.

En ambos casos, además de la propia geometría del modelo 3D, un archivo OBJ incluye información adicional como:

* Un mapa de textura: básicamente, una imagen 2D que representa la «piel» del modelo. Este mapa de texturas es entendido por otros programas y así podemos recuperar la textura y colores originales del modelo.
* Iluminación: fuentes de luz para iluminar adecuadamente el modelo en un programa de edición 3D.
* Metadatos: quién creó el modelo, cuándo, con qué programa, etc.

En resumen, el formato OBJ es una *excelente alternativa a STL* si queremos mayor precisión en los modelos.

#### Formato 3MF

Otro de los problemas de los archivos STL es que son totalmente desestructurados, ya que contienen únicamente una lista de coordenadas de los bordes de los triángulos que componen la superficie del objeto. Nada en un archivo STL impide que un objeto tenga errores en su definición como, por ejemplo, agujeros, triángulos que se intersectan entre sí, triángulos volteados o invertidos, vértices no compartidos (es decir, que quedan "sueltos"), etc.

Estos problemas, derivados de un mal modelado o de una mala exportación, pueden prevenirse usando el formato 3MF. Los modelos que exportemos como 3MF serán validados para evitar todos estos errores, por lo que podemos estar seguro de que nuestro archivo podrá ser impreso en 3D sin errores.

Además de prevenir los errores, un archivo 3MF incluye mucha más información, ya que puede comprimir otros archivos y encapsularlos en un solo paquete, como hacemos al usar un archivo ZIP. Esa información adicional incluye:

* **Escala**: Los modelos tienen escala y unidades por lo que siempre tendremos el mismo tamaño al margen de la impresora o del laminador que usemos.
* **Escenas**: Un archivo 3MF puede contener varios modelos separados y guardarlos como modelos diferentes que pertenecen a una misma escena.
* **Colores y texturas**, como los OBJ.
* **Ajustes de impresión**: junto a los modelos se pueden incluir los ajustes de impresión. De esta manera nos aseguramos de que compartimos no sólo el modelo, sino también cómo queremos que se imprima.

Además, un archivo 3MF está comprimido y ocupa mucho menos que un STL.

Por todo esto, *3MF es uno de los formatos más recomendables para la impresión 3D*.

#### Otros formatos

Existen varios formatos más que también son interesantes:

* **Formato STP**. Es el formato estándar para compartir modelos 3D según la norma ISO 10303. Este formato es muy interesante para intercambiar los modelos entre programas de CAD, ya que un archivo en este formato se podrá editar fácilmente en softwares de CAD convencionales.

* **Formato Collada**. Este formato está en desuso, pero antes se utilizaba mucho para el intercambio de archivos entre programas como *Maya* o *3DSmax*. Puede incluír geometría, color, textura y también información sobre las cinemáticas de los modelos.

* **Formato FBX**. Muy usado en la industria del cine, incluye información sobre el «esqueleto» de las figuras, lo cual es importante para su animación.

## 4.2. Software para *slicing* (corte o laminado)

Para la impresión 3D, no solo necesitamos disponer de un modelo 3D convenientemente diseñado con una herramienta como *TinkerCAD*, *Maya* o *Blender*, sino que debemos preparar nuestro modelo para la impresión en capas.

El **software para corte o laminado** (*slicing*, en inglés) se encarga de eso: se trata de un programa que convierte el modelo 3D en una serie de finas capas y produce un fichero que contiene el **código G**, que no es otra cosa que el conjunto de instrucciones adecuadas para un determinado tipo de impresora 3D.

(El lenguaje G, por cierto, es un lenguaje de programación de control numérico muy extendido, pero no es necesario aprenderlo para imprimir en 3D, porque el *slicer* se encarga de todo)

Existen numerosos programas de laminado en el mercado, y muchos de ellos son gratuitos, pero sin duda el número uno es uno con el peculiar nombre de **Cura**.

**Ultimaker Cura** es un programa gratuito, multiplataforma (Windows, Linux, Mac) y de código abierto mantenido por Ultimaker (un fabricante de impresoras 3D) y una ferviente comunidad de usuarios.

Admite archivos STL, 3MF y OBJ, que el slicer 3D puede reparar en caso necesario. Además, crea rutas de herramientas, así como estimaciones del material y el tiempo de impresión. 

Dispone de ajustes para novatos y para expertos, por lo que es muy apropiado para cualquier tipo de usuario. Los resultados de impresión son generalmente muy buenos.

El software Cura se actualiza continuamente y dispone de montones de plugins externos. Existe una versión *enterprise* que no es gratuita y que dispone de plugins especialmente diseñados para profesionales.

![Aspecto general de Ultimaker Cura](/docs/prog-y-3d/_site/assets/images/10-cura-01.jpg)
<div style='font-size: 75%; font-style: italic'>
Aspecto de Ultimaker Cura en su versión para Windows
</div>

Para **preparar un modelo 3D con Cura** y **dejarlo listo para imprimir**, simplemente sigue estos pasos:

1. Instala Cura en tu ordenador y ejecútalo.
2. Abre tu modelo 3D. Cura admite los formatos STL, OBJ y 3MF, así que puedes abrir los modelos hechos con TinkerCAD sin problemas.
3. En la parte superior del área de trabajo verás dos botones, etiquetados como "1" y "2" (ver captura de pantalla más abajo). Pulsa el botón "1" para seleccionar tu tipo de impresora. Si no está en la lista, selecciona la que más se parezca.
4. Después, pulsa el botón "2" para seleccionar los ajustes de impresión. Si has seleccionado bien la impresora, estos ajustes ya vendrán preestablecidos y no tendrás que tocarlos. En caso contrario, tendrás que juguetear un poco con ellos hasta conseguir una impresión adecuada.
5. Inicia el laminador pulsando en el botón que encontrarás abajo y a la derecha.
6. Una vez terminado el laminado, se habilitará el botón "Preview" (en la parte superior de la ventana) para previsualizar el resultado. Es muy útil para comprobar si el modelo es apto para su impresión o si contiene errores.
7. Guarda el trabajo en una memoria USB o disco extraíble para poder transferirlo a tu impresora. Algunas impresoras más avanzadas soportan la impresión por red o a través de servicios *cloud*, por lo que puedes imprimir tu modelo directamente desde Cura.

![Un modelo 3D laminado por Cura](/docs/prog-y-3d/_site/assets/images/10-cura-02.png)
<div style='font-size: 75%; font-style: italic'>
Aspecto de Cura justo después de preparar un modelo 3D para su impresión. Arriba puedes observar los botones para seleccionar la impresora (etiquetado como "1") y para los ajustes de impresión (etiquetado como "2"). El botón "Preview" ya está disponible porque el <i>slicing</i> ya ha finalizado.
</div>

## 4.4. Pruebas de impresión

La impresión 3D ha avanzado mucho en los últimos años, pero aún se encuentra dando sus primeros pasos.

Te digo esto para que comprendas por qué imprimir en 3D no es tan sencillo como hacerlo en 2D.

En tu vieja impresora de inyección de tinta o láser, simplemente cargas una hoja de papel, envías un archivo para imprimir, y en unos segundos tienes una copia perfectamente impresa.

Sin embargo, si alguna vez has cambiado los cartuchos de tinta o el tóner de tu impresora, quizá te hayas fijado en que la impresora hace un **calibrado automático** inmediatamente después. Esto es necesario para que la impresión se haga correctamente, esto es, para que cada punto de tinta se imprima en el lugar correcto de la página.

Por desgracia, las impresoras 3D necesitan un **calibrado manual** porque, como te digo, esta tecnología aún está dando sus primeros pasos.

Y ese calibrado puede llegar a ser una tortura.

Aprender a calibrar bien una impresora 3D es importante para:

* Que los componentes no se rompan.
* Que tus piezas salgan perfectas.
* Evitar dolores de cabeza y filamento malgastado.

### 4.4.1. Diez pasos para calibrar una impresora 3D

**1. Limpia bien la impresora 3D**: Muchas veces no nos damos cuenta la cantidad de roña que hay en nuestras impresoras y de lo que afecta a su funcionamiento. Límpiala a conciencia antes de imprimir nada.

**2. Tensa bien las correas**: Las correas de la impresora siempre tienen que estar bien tensas para que no haya problemas de pérdida de pasos. Es la parte más importante de la mecánica.

**3. Cambia piezas desgastadas**: Nada de "ya lo cambiaré cuando se rompa". Los fallos por rotura en las impresoras hacen efecto dominó, y un simple rodamiento en mal estado puede acabar estropeando otras piezas.

**4. Lubrica todo bien**: Una máquina lubricada es una máquina con años de vida. Lubrica bien los componentes necesarios: aceite de silicona para rodamientos y grasa de litio para husillos y varillas.

**5. Instala Marlin**: Marlin es un *firmware* abierto y gratuito que funciona en muchas impresoras 3D. El *firmware* es un pequeño programa que controla la propia impresora. Si puedes instalar Marlin en tu impresora 3D, conseguirás configurarla y afinarla con mucha más facilidad.

**6. Mira los pasos de los motores**: Es decir, cuando "avanza" cada motor en cada giro. Con Marlin se puede ajustar al milímetro el paso de motor. Si no es posible, tienes que mirar si el software que trae tu impresora te permite ajustarlo.

**7. Calibra el flujo de plástico**: Hay veces que nuestro extrusor se desajusta y no extruye lo que debería extruir, sacando más cantidad o menos cantidad de plástico de la necesaria.

**8. Afina la distancia del Eje Z**: Esta distancia es vital para la impresión: si lo dejas muy lejos, el plástico 3D no se pegará; si lo haces muy cerca, habrá una sobrepresión que acabará deformando la figura. Una distancia de 0,15mm suele funcionar bien.

**9. Testéalo todo con un cubo**: Una vez hecho todo hay que comprobar si va bien. Para ello, lo mejor es imprimir un cubo u otra figura muy simple.

**10. Imprímete algo bonito**: Así comprobarás si realmente todo se ha calibrado correctaemente.

### 4.4.2. Modelos de prueba

Hablando de imprimir "algo bonito", existen **modelos de prueba** usados para **probar específicamente ciertas capacidades de tu impresora 3D** y ayudarte a calibrarla. Por ejemplo, unos modelos pueden probar la habilidad de tu impresora para imprimir puentes o voladizos; otros pueden probar la precisión o el acabado de la superficie, y otros ponen a prueba determinados ajustes del programa de corte o slicer, como la velocidad, la temperatura o la extrusión de las capas.

Estos son algunos modelos de prueba muy populares:

#### 3D Benchy

**3DBenchy** es el buque insignia, nunca mejor dicho, de las pruebas de impresión más populares. Con este modelo, puedes experimentar con todo tipo de elementos, desde voladizos hasta extrusiones.

Si quieres poner a punto tu impresora, Benchy te ayudará a determinar los ajustes necesarios para obtener las impresiones perfectas. La presencia de unos cuantos barquitos Benchy alrededor de una impresora es un signo inequívoco de un fabricante experimentado.

![3DBenchy](/docs/prog-y-3d/_site/assets/images/10-modelos-de-prueba-3dbenchy.jpg)

#### All in one 3D printer test

Como su nombre indica, este test «todo en uno» para impresoras 3D contempla todo tipo de elementos: voladizos, puentes, encordado, extrusión, temperatura, tensión de la correa... 

Una vez realizada la impresión, podrás encontrar una solución para los problemas que hayan surgido en la guía de resolución de problemas que suele acompañar al modelo y en muchos sitios de internet.

![All in one 3D printer test](/docs/prog-y-3d/_site/assets/images/10-modelos-de-prueba-todo-en-uno.png)

#### Dado de calibración XYZ de 20 mm

Este dado de calibración es un modelo sencillo, rápido y fácil para poner a tu impresora contra las cuerdas. Su objetivo principal es ayudarte a ajustar la precisión de tu impresora modificando los pasos por mm, pero también permite probar la temperatura, la extrusión y la vibración.

![Dado de calibración XYZ](/docs/prog-y-3d/_site/assets/images/10-modelos-de-prueba-dado-calibracion.jpg)

#### Cali Cat, el gato para calibración 

Cali Cat es un modelo sencillo y adorable que te permitirá probar la precisión, los voladizos, los detalles, los puentes, las extrusiones y la vibración en tu impresora, todo ello en menos de una hora. Diseñado para realizar la calibración inicial, este lindo gatito te permitirá calibrar tu impresora en muy poco tiempo.

Curiosidad: si imprimes un gato el doble de grande que el otro, el gato pequeño encajará perfectamente sobre el grande.

![CaliCat](/docs/prog-y-3d/_site/assets/images/10-modelos-de-prueba-cali-cat.png)

#### Modelo paramétrico para la calibración de la cama 

La nivelación de la cama suele ser el paso más complejo de la calibración de una impresora 3D. Este modelo te permitirá detectar cómo mejorar las primeras capas de tus impresiones.

![Calibración de cama](/docs/prog-y-3d/_site/assets/images/10-modelos-de-prueba-calibracion-cama.jpg)

## 4.5. Imprimir el modelo

Hemos diseñado nuestro modelo 3D, lo hemos exportado a un archivo STL, OBJ o 3MF, lo hemos laminado y tenemos nuestra impresora razonablemente bien calibrada. ¡Por fin llega el momento de ponernos a imprimir!

¿Cómo se hace eso?

Lógicamente, el procedimiento exacto depende del modelo de impresora 3D que tengamos, pues incluso entre impresoras FDM puede haber muchas diferencias.

La mayoría de las impresoras FDM domésticas tienen un **panel de control con botones o diales, un puerto USB y una pantalla** para comunicarse con el usuario. En estos modelos, tienes que guardar tu **código G** (el que genera el software de *slicing*) en una memoria USB (o disco duro externo) y conectarla al puerto USB del panel de control.

Para asegurarte de que no hay problemas con la lectura, formatea la memoria USB como **FAT32**. Si eso no es posible, consulta el manual de usuario de tu impresora para ver qué sistemas de ficheros soporta.

![Uniones y vaciados con TinkerCAD](/docs/prog-y-3d/_site/assets/images/10-impresoras-3d-panel-de-control.jpg)
<div style='font-size: 75%; font-style: italic'>
Panel de control típico de una impresora FDM doméstica. El puerto USB suele estar en un lateral.
</div>


La electrónica del panel de control revisará el contenido de la memoria USB y te permitirá elegir el archivo que quieres imprimir. La forma de hacer esto también puede ser diferente en unas impresoras que en otras: algunas cuentan con una rueda que se gira a un lado y a otro para cambiar la selección y que se pulsa para aceptar la selección. Otras tienen botones o pantallas táctiles para lograr el mismo efecto.

Por último, la impresora te preguntará por algunos parámetros de configuración (como la temperatura) y te pedirá confirmación para iniciar la impresión. Además, cuando el proceso de impresión comience, te irá informando en la pantalla de cómo se está desarrollando o de posibles errores.

### 4.5.1. Consejos antes de imprimir

Además de hacer un adecuado mantenimiento de la impresora (limpieza, calibración, etc), antes de imprimir cualquier modelo es necesario **preparar la cama y cargar el filamento**.

La **preparación de la cama** suele consistir en aplicar un material antideslizante a su superficie, sobre todo si es de cristal. Hay quien usa **cintas especiales**, como *Kapton Tape*, que se vende en distintos anchos, para crear una capa antideslizante muy fina y resistente. También existen láminas de plástico como *BuildTak*. Puedes encontrar todos estos productos en cualquier tienda especializada física u *online*.

Si no tienes a mano nada de esto, la **cinta de pintor** (*Blue tape*, o incluso cinta de carrocero de toda la vida) es una solución barata y aceptable.

Otras personas prefieren imprimir directamente sobre el cristal, que debe estar en buen estado, sin arañazos profundos. En tal caso, es necesario rociarlo con un ***spray* antideslizante** como *3DLac* o *DimaFix*. También se puede usar **laca para el pelo**, que por su naturaleza crea una capa invisible levemente pegajosa que puede limpiarse después con un trapo humedecido con agua.

![Figura simple](/docs/prog-y-3d/_site/assets/images/10-impresora-3d-problema-de-adherencia-cama.jpg)
<div style='font-size: 75%; font-style: italic'>
Pieza despegada por falta de adherencia a la cama
</div>

![Figura simple](/docs/prog-y-3d/_site/assets/images/10-impresora-3d-cintas-antideslizantes.jpg)
<div style='font-size: 75%; font-style: italic'>
Kapton tape (cinta específica para camas de impresoras 3D) y blue painter tape (cinta de pintor azul)
</div>

La **carga de filamento** solo es necesaria si este no está ya cargado de una impresión anterior. Cambiar el filamento es sencillo: se calienta el cabezal, se saca el material, se coloca la nueva bobina y se introduce el filamento. Si el material del nuevo filamento fuera diferente del viejo, hay que limpiar el cabezal antes de volver a introducir el nuevo.

Por supuesto, debes asegurarte de que queda filamento suficiente en la bobina para imprimir la pieza. Algunos programas como *Cura* te hacen una estimación del peso de la pieza que vas a imprimir, para que puedas estimar si tu bobina es suficiente.

<iframe width="560" height="315" src="https://www.youtube.com/embed/53tj0cSil_8" title="YouTube video player" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture" allowfullscreen></iframe>
<div style='font-size: 75%; font-style: italic'>
Cómo sustituir una bobina y cargar el filamento en el extrusor
</div>

La **limpieza del extrusor** es imprescindible para evitar atascos en el cabezal de impresión. Debe hacerse depués de cada impresión y comprobarse antes de imprimir.

Esta limpieza puede hacerse de varias maneras. Muchos usuarios utilizan un *hilo de nylon* del grosor adecuado, que puede conseguirse en cualquier ferretería. Se calienta el cabezal y se hace pasar el nylon por él hasta que salga limpio. El nylon tiene una temperatura de fusión superior a los filamentos FDM, por lo que limpiará los restos sin derretirse él mismo. Luego se enfría el cabezal hasta los 90º y se retira el filamento de nylon. Veremos que sale sucio. Se tiene que repetir esta operación hasta que salga limpio. También existen filamentos hechos adrede para este propósito. 

En casos extremos, puede ser necesario desmontar el extrusor para hacer la limpieza desde el interior.

<iframe width="560" height="315" src="https://www.youtube.com/embed/tT1bZKQpm38" title="YouTube video player" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture" allowfullscreen></iframe>
<div style='font-size: 75%; font-style: italic'>
Cómo limpiar el extrusor con un filamento de nylon
</div>

<iframe width="560" height="315" src="https://www.youtube.com/embed/ADhby6hNBcQ" title="YouTube video player" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture" allowfullscreen></iframe>
<div style='font-size: 75%; font-style: italic'>
Cómo desmontar el extrusor en caso de atasco persistente
</div>


### 4.5.2. Consejos durante la impresión

Mientras la impresora trabaja podemos hacer una **inspección visual periódica** de cómo se está imprimiendo nuestra pieza. Esto es particularmente importante en las primeras capas, que es donde suelen darse la mayor parte de los problemas. Por ejemplo, porque la pieza se deslice sobre la cama.

Todos los paneles de control permiten suspender la impresión en cualquier momento si obervamos que algo está saliendo mal.

El proceso de impresión puede durar bastante tiempo: desde unos minutos hasta varias horas. Todo depende de la complejidad de la pieza y de los ajustes de la impresora (velocidad, grosor de cada capa, etc), así que tampoco es necesario que te pases las horas muertas observando trabajar al cabezal de impresión, pero sí es buena idea que te pases de vez en cuando para ver cómo va el trabajo.

Asegúrate de que en el entorno de la impresora no se producen **corrientes de aire** durante la impresión. El filamento es muy ligero y la corriente de aire puede desviarlo, dando lugar a un inoportuno error de impresión. Para el correcto enfriamento del filamento, la **temperatura ambiente** debe ser moderada (menos de 30º C). El **exceso de polvo** en el ambiente y la **luz solar directa** también pueden afectar a la calidad de la impresión.

### 4.5.3. Consejos para después de imprimir

**Corta el filamento** sobrante. Para ello, necesitarás disponer de unos alicates apropiados.

**Retira la pieza** de la cama con cuidado, en particular si aplicaste alguna sustancia antideslizante, porque entonces la pieza estará ligeramente pegada a la cama. Antes de retirarla, **espera al menos 5 minutos** para que toda la pieza se endurezca.

**Limpia la cama**, sobre todo si la rociaste con *spray*. Retira cualquier resto de plástico con una espátula suave. Si has aplicado laca para el pelo, límpiala con un trapo humedecido con agua u otro disolvente. Los *sprays* específicos para impresoras 3D también se limpian con agua, pero estos últimos pueden durarte varias impresiones antes de tener que volver a aplicarlos. En cualquier caso, antes de poner una nueva capa de *spray*, limpia bien la anterior. Por último, si has utilizado una cinta antideslizante, retírala si está en mal estado y limpia los restos de adhesivo, si los hubiera, con el disolvente apropiado (alcohol o acetona suelen dar buen resultado).

**Limpia el extrusor**. Te explicamos como hacerlo en el apartado "Antes de imprimir" que encontrarás un poco más arriba.

**Comprueba la pieza**, no solo sus acabados, sino también sus dimensiones. Esto te permitirá descubrir errores de calibrado de tu impresora antes de que se hagan muy grandes. En algunas piezas, y dependiendo del material utilizado para la impresión, puede aplicarse una capa protectora de **acetona** (solo para plástico ABS) o una resina de recubrimiento llamada **XTC**, que permite lijar y pintar la pieza, dándole un aspecto mucho más liso.

![Figura simple](/docs/prog-y-3d/_site/assets/images/10-impresoras-3d-xtc.jpg)
<div style='font-size: 75%; font-style: italic'>
Una pieza antes y después de la aplicación de una resina XTC.
</div>

### 4.5.4. Algunos *tips* para usar la impresora de CR10-mini con éxito

En el momento de escribir esto, en el IES Celia Viñas contamos con una impresora **Crealty CR10-mini**. Se trata de una impresora de filamento capaz de imprimir en plástico ABS y PLA.

Después de varios meses de experiencia trabajando con ella, podemos proporcionarte algunos consejos adicionales referidos a este modelo concreto:

* Calienta el filamento un poco por encima de la temperatura indicada por el fabricante del mismo, sobre todo en invierno. Alrededor de 210 o 215º van bien para el PLA. El ABS necesitará que pongas la máquina a tope de temperatura. Ojo, porque cada vez que inicies una nueva impresión, la impresora hará bajar su temperatura hasta los valores establecidos de fábrica y tendrás que volver a subirlos.
* Calienta también la cama un poco por encima de lo normal: unos 60º para el PLA y 70-80º para el ABS.
* La calibración de la altura de la cama es *fundamental* para obtener un buen resultado. Si no, las piezas se despegarán hagas lo que hagas. Recuerda que el ABS se despega con más facilidad que el PLA.
* Limpia y calibra la cama antes de cada impresión. Los laminados de Cura hacen varias pasadas de calibración previas antes de empezar a imprimir. Úsalas para darle un último toque a la calibración mirando de perfil cómo se mueve el extrusor y a qué distancia de la cama está. Recuerda que debe estar muy, muy cerca del cristal pero sin llegar a tocarlo.
* Usa laca del pelo extrafuerte o, mejor aún, algún spray específico para mejorar el agarre de la pieza a la cama. Debes reponerlo antes de cada impresión y extender una capa generosa cuando la cama aún no esté demasiado caliente.
* Usa un poco de cinta de carrocero para asegurarte de que el cristal no se mueve de su posición en la cama.
* Las piezas con una base muy grande se imprimen mejor. Cuanto menor es la base con la que apoyan en la cama, más posibilidades hay de que se muevan y la impresión se estropee. Si la pieza es pequeña y siempre se te despega, platéate alguna de estas alternativas:
   * Aumentar su tamaño.
   * Reducir la velocidad de impresión.
   * Añadir a la pieza una base de apoyo de tamaño generoso.


## 4.6. Ejercicios

**Ejercicio 1**.  Regístrate en TinkerCAD y familiarízate con el entorno de trabajo. Tienes que aprender, como mínimo, a rotar, trasladar y hacer zoom de la vista, así como a insertar objetos, escalarlos y moverlos. 

**Ejercicio 2**. Trata de crear con TinkerCAD [este sencillo perro salchicha](/docs/prog-y-3d/_site/modelado-e-impresion-3d/#411-qu%C3%A9-es-tinkercad-y-c%C3%B3mo-funciona).

**Ejercicio 3**. Sigue los pasos de los apuntes para crear con TinkerCAD la cabaña que aparece [aquí](/docs/prog-y-3d/_site/modelado-e-impresion-3d/#414-cómo-modelar-objetos-3d-con-tinkercad)

**Ejercicio 4**. Sigue los pasos de los apuntes para crear con TinkerCAD la estructura con cuatro esferas alineadas que aparece [aquí](/docs/prog-y-3d/_site/modelado-e-impresion-3d/#transformar-alinear-y-medir)

**Ejercicio 5**. Intenta crear con TinkerCAD la taza con el busto de Ironman que se describe [aquí](/docs/prog-y-3d/_site/modelado-e-impresion-3d/#415-edici%C3%B3n-de-objetos-externos-a-tinkercad). Puedes usar otro busto que localices en Thingverse (o en algún otro sitio de modelos 3D de libre uso) si lo tuyo no son Los Vengadores.

**Ejercicio 6**. Instala el programa *Ultimaker Cura* en tu ordenador. Exporta la taza de Ironman (o del busto que hayas empleado) a formato STL y ábrela con *Cura*. Haz el *slicing* (laminado) para dejarla lista para su impresión. Guarda el archivo con el resultado.

**Ejercicio 7**. Utiliza los bloques de código para crear con TinkerCAD 10 mesas de cuatro patas, siguiendo las pistas que se dan en [este apartado](/docs/prog-y-3d/_site/modelado-e-impresion-3d/#bloques-de-código). Las mesas deben estar lo bastante separadas unas de otras como para que se puedan ver con facilidad. A ver si consigues que cada una tenga un color diferente.

**Ejercicio 8**. Modifica el ejercicio anterior para generar 28 mesas en lugar de 10. Colócalas como si fueran las mesas de un aula para 28 personas (por ejemplo, haciendo 4 filas de 7 mesas). Crea 28 sillas y colócalas junto a las mesas. Por último, crea una mesa (un poco más grande) junto con su silla para el profesor y colócala en un extremo de la clase. 

**Ejercicio OBLIGATORIO**. Ya conoces los fundamentos del modelado e impresión 3D. Ahora, para evaluar este bloque de la asignatura, te voy a pedir que  prepares dos modelos distintos:

   * **Un modelo para imprimir**. Debe ser algo sencillito (un llavero con tu nombre, por ejemplo). Expórtalo a STL, lamínalo con *Cura* e imprímelo. Haremos turnos de impresión para que todos/as tengáis ocasión de usar la impresora 3D.
   * **Un modelo para lucirte**. Este puede (y debe) ser todo lo complejo que quieras. Deja volar tu imaginación o, mejor todavía, deja que se te vaya un poco la olla para crear algo que solo tú puedas hacer. Este modelo tendrás que subirlo a Moodle Centros.

   *Importante: los dos modelos deben ser tuyos, no descargados de Internet (aunque puedes descargar alguna parte para reutilizarla, como hicimos con la taza de Ironman)*

