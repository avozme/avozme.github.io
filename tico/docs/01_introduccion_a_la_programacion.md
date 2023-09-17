---
layout: page
title: 1. Introducción a la programación
permalink: /introduccion-a-la-programacion/
nav_order: 1
has_children: true
parent: Tecnologías de la Información y la Comunicación 2º BACHILLERATO
---

# 1. Introducción a la programación
{: .no_toc }


- TOC
{:toc}

## 1.1. El pensamiento computacional

El pensamiento computacional es un proceso de **formulación y resolución de problemas que utiliza los conceptos de la ingeniería informática**. 

Es decir, consiste en pensar como lo haría un científico-informático cuando está frente un problema y tener la habilidad y la actitud para que nos sea útil tanto en nuestra vida personal como profesional. 

Hemos dicho "vida personal", sí. Uno de los errores más frecuentes cuando se habla de *pensamiento computacional* es considerar que solo se aplica a la Informática.

El pensamiento computacional **sirve para resolver problemas cotidianos haciendo uso de las técnicas y habilidades de los programadores/as informáticos** y obtener así soluciones que pueden ser representadas mediante una serie de pasos o instrucciones.

Aquí tienes un vídeo que desarrolla esta interesante idea en tres minutos:

<iframe width="560" height="315" src="https://www.youtube.com/embed/veXgaxaNICM" title="YouTube video player" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture" allowfullscreen></iframe>

### 1.1.2. Características del pensamiento computacional

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

![Ejemplo de receta escrita con Scratch](/docs/tico/_site/assets/images/01-scratch.jpg)

### 1.1.3. El pensamiento computacional vs la programación

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

## 1.2. ¿Qué es exactamente eso de "programar un ordenador"?

**Programar un ordenador** no es más que proporcionarle a la máquina un conjunto de instrucciones y datos para que realice una tarea. Esa tarea, generalmente, resuelve un problema concreto, que puede ir desde realizar complicados cálculos matemáticos hasta entretenernos con un videojuego en nuestros ratos de ocio.

El conjunto de las instrucciones que conforma el programa se denomina **código fuente**, y tiene que estar escrito en un lenguaje comprensible por la máquina, es decir, un **lenguaje de programación**.

Esas instrucciones se traducen a **código binario** (que, recuerda, es lo único que puede comprender el ordenador). La CPU de un ordenador está construida de manera que puede entender y ejecutar ciertas instrucciones binarias, gracias a lo cual nuestro programa acaba ejecutándose en las entrañas de la máquina.

Este es un fragmento de un programa informático real escrito en lenguaje PHP. Implementa un algoritmo de ordenación de elementos llamado *Bubble Sort* o, en español, *método de la burbuja*. No es necesario, ni mucho menos, que lo entiendas de momento. Solo quiero que le eches un vistazo para que veas el aspecto que tiene un programa real (o un fragmento) escrito en un lenguaje real.

```php
function bubble_Sort($my_array )
{
	do
	{
		$swapped = false;
		for( $i = 0, $c = count( $my_array ) - 1; $i < $c; $i++ )
		{
			if( $my_array[$i] > $my_array[$i + 1] )
			{
				list( $my_array[$i + 1], $my_array[$i] ) =
						array( $my_array[$i], $my_array[$i + 1] );
				$swapped = true;
			}
		}
	}
	while( $swapped );
return $my_array;
}

$test_array = array(3, 0, 2, 5, -1, 4, 1);
echo "Original Array :";
echo implode(', ',$test_array );
echo "Sorted Array:";
echo implode(', ',bubble_Sort($test_array)). PHP_EOL;
```

(Fuente: php.net)


## 1.3. Algunos conceptos fundamentales (antes de empezar)

Antes de lanzarse a programar un ordenador, es necesario conocer algunos conceptos fundamentales relacionados con los ordenadores. Estos conceptos forman parte de la "culturilla" popular, pero no todo el mundo los tiene claros. En esta sección, vamos a aclarar qué cosas como:
* ¿Qué narices es el código binario (o código máquina) y por qué es tan importante en informática?
* ¿Qué es el código ASCII, el UTF-8 o el Unicode?
* ¿Qué diferencia hay entre bit o byte? ¿Y entre un GB y un TB? ¿Y entre un GB (con B mayúscula) y un Gb (con b minúscula)? O, más difícil aún, ¿es lo mismo un GB que un GiB? Menudo lío de letras, ¿verdad?

### 1.3.1. Codificación de la infirmación

Un **código** es un *método de representación de la información*. Se compone de un conjunto de símbolos, llamado **alfabeto**, y de un conjunto de **reglas** para combinar esos símbolos de forma correcta.

Estos son algunos ejemplos de códigos que utilizas todos los días o que, al menos, conoces:

* **Ejemplo 1**: la lengua castellana es un código. Su alfabeto es el abecedario (a, b, c, d, e ... z), pero los símbolos del alfabeto no se pueden combinar a lo loco, sino que existen unas reglas, y sólo siguiendo esas reglas se codifica correctamente la información, dando lugar a mensajes con sentido. Esas reglas las habéis estudiado en la asignatura de lengua castellana desde la enseñanza primaria.
* **Ejemplo 2**: el código morse también es un código. Su alfabeto es muy reducido: sólo el punto (.) y la raya (–), pero combinando los dos símbolos correctamente, se puede transmitir cualquier información.
* **Ejemplo 3**: el sistema de numeración decimal es un código. Tiene un alfabeto de 10 símbolos (0, 1, 2, 3, 4, 5, 6, 7, 8 y 9). Combinándolos según ciertas reglas, puede usarse para transmitir información. Pero ojo, no cualquier información, solamente información numérica. Hemos dicho que los códigos sirven para representar información, pero no que tengan que servir para representar toda la información posible. Aunque sólo sirva para los números, el sistema de numeración también es un código.

### 1.3.2. El código binario

Pues bien, **el sistema de numeración binario también es un código**.

Es muy parecido al sistema de numeración decimal, con la única diferencia de la cantidad de símbolos del alfabeto. Si el decimal tiene diez, el binario sólo tiene dos: el 0 y el 1.

En todo lo demás son iguales, así que el sistema binario también sirve para representar información numérica. 

Pero, ¿puede representarse cualquier número con sólo dos símbolos? 

La respuesta es sí. El modo de hacerlo consiste en combinar los símbolos 0 y 1 adecuadamente, igual que hacemos con los números decimales. En el sistema decimal contamos así: 0, 1, 2, 3, 4, 5, 6, 7, 8, 9. Cuando queremos pasar a la siguiente cantidad, empezamos a agrupar los dígitos de dos en dos: 10, 11, 12, 13, 14, 15, 16, 17, 18, 19. Al volver a terminar las unidades, vamos incrementando las decenas: 20, 21, 22, etc.

(Esto se debe a que, en los sistemas de numeración, cada dígito tiene un valor posicional, es decir, tiene un valor diferente dependiendo del lugar que ocupe en el número general. Por ejemplo, en el número 283, el 3 tiene valor de tres, pero el 8 no tiene valor de ocho, sino de ochenta, y el 2 no tiene valor de dos, sino de doscientos)

En binario, el razonamiento es el mismo. Empezamos a contar por 0 y 1, pero entonces ya hemos agotado los símbolos, así que empezamos a agruparlos: 10, 11. Como hemos vuelto a agotarlos, seguimos combinándolos: 100, 101, 110, 111, 1000, 1001, 1010, y así sucesivamente.

Así, los 16 primeros números binarios comparados con sus equivalentes decimales son:

Decimal|Binario
-|-
0|0000
1|0001
2|0010
3|0011
4|0100
5|0101
6|0110
7|0111
8|1000
9|1001
10|1010
11|1011
12|1100
13|1101
14|1110
15|1111

Los números escritos en código binario tienen el mismo valor que en decimal, y sólo cambia la representación. Es decir, “15” en decimal y “1111” en binario representan exactamente a la misma idea: quince.

#### Convertir números binarios a decimales

Para obtener la representación decimal de un número binario hay que proceder según el Teorema Fundamental de la Normalización, del siguiente modo: 

1. Numeramos la posición que ocupa cada dígito binario de derecha a izquierda, empezando por 0. Por ejemplo, en el número binario 1010011, numeraremos las posiciones así:

   ```
         Posiciones --> 6 5 4 3 2 1 0
            Dígitos --> 1 0 1 0 0 1 1
   ```

2. Multiplicamos cada dígito binario por 2 elevado a la posición del dígito y sumamos todos los resultados. Con el número del ejemplo anterior:

   <p align='center'>1 x 2<sup>6</sup> + 0 x 2<sup>5</sup> + 1 x 2<sup>4</sup> + 0 x 2<sup>3</sup> + 0 x 2<sup>2</sup> + 1 x 2<sup>1</sup> + 1 x 2<sup>0</sup></p>

3. Ahora sólo nos quedaría sumar los resultados de todas las multiplicaciones:

   <p align='center'>64 + 0 + 16 + 0 + 0 + 2 + 1 = 83</p>

Por lo tanto, el número binario 1010011 es equivalente al número decimal 83. 

Es habitual indicar con un subíndice el sistema de numeración al que pertenece cada número, así:

<p align='center'>1010011<sub>2</sub> = 83<sub>10</sub></p>

#### Convertir números decimales a binarios

El proceso contrario se realiza dividiendo sucesivamente el número decimal entre dos, y cogiendo el último cociente y todos los restos en el orden inverso al que los obtuvimos.

Por ejemplo, vamos hallar la representación binaria del número 83<sub>10</sub>:

<p align='center'><img alt='División binaria' src='/tico/_site/assets/images/02-division-binaria.png'></p>

Tomando el último cociente (que siempre es 1) y todos los restos desde el último hacia el primero (es decir, 010011, siguiendo la dirección de la flecha), obtenemos el número binario 1010011. Por lo tanto, podemos decir que:

<p align='center'>83<sub>10</sub> = 1010011<sub>2</sub></p>

#### Operaciones aritméticas binarias

La operaciones aritméticas binarias se realizan exactamente igual que las decimales, aunque teniendo la precaución de usar sólo los dos símbolos permitidos (0 y 1), lo que puede parecernos un poco extraño al principio.

Por ejemplo, para realizar una suma de dos números binarios, escribiremos ambos números uno encima de otro, alineados a la derecha, como hacíamos cuando estábamos aprendiendo a sumar. Luego, iremos sumando los dígitos de derecha a izquierda, como haríamos con dos números decimales, con la precaución de sumar también el acarreo cuando se produzca.

Vamos a sumar los números 11001<sub>2</sub> y 1011<sub>2</sub>:

```
     1  1     1       <-- acarreos
     1  1  0  0  1
+       1  0  1  1
  ----------------
  1  0  0  1  0  0
```

Del mismo modo, pueden realizarse otras operaciones aritméticas como restas, productos o divisiones.

### 1.3.3. El código ASCII

Hasta ahora hemos visto que mediante el código binario se pueden representar números, pero no sabemos cómo se las apaña un ordenador para **representar las letras**, o, dicho en terminología informática, los **caracteres alfanuméricos** (que incluyen números, letras y otros símbolos, como los signos de puntuación).

**El código ASCII consiste en una correspondencia entre números binarios de 8 dígitos y caracteres alfanuméricos**. 

(Bueno, en realidad el código ASCII original usaba números binarios de 7 dígitos, pero eso es otra historia. El ASCII que ha llegado hasta nuestros días es el ASCII extendido de 8 bits).

Así, por ejemplo, al número 65<sub>10</sub> (expresado en binario, 01000001<sub>2</sub>) se le hace corresponder la letra "A", al 66<sub>10</sub> la "B", al 67<sub>10</sub> la "C", etc.

De este modo, el ordenador puede también manejar letras, y lo hace del mismo modo en que maneja números: mediante combinaciones de ceros y unos.

La siguiente tabla muestra los 127 primeros caracteres del código ASCII junto con el número al que corresponden en decimal, binario, octal y hexadecimal (estos dos últimos son sistemas de numeración que veremos enseguida):

![Tabla ASCII simplificada](/docs/tico/_site/assets/images/02-tabla-ascii.png)
(Fuente: Wikimedia Commons - Dominio público)

Es importante resaltar que los códigos ASCII siempre tienen 8 dígitos binarios, rellenándose con ceros a la izquierda si fuera necesario. Así ocurre en el caso de la letra A, que, como hemos dicho, se representa con el código 01000001.

Si te tomas la molestia de calcular cuántos caracteres diferentes pueden representarse con el código ASCII, verás que son exactamente 256. Suficientes para todos los caracteres habituales, ¿verdad? Aunque, un momento... ¿Y qué hay de los caracteres griegos? ¿O los caracteres cirílicos del ruso? Eso por no hablar del chino y o el japonés.

Si queremos dar cabida a cualquier idioma del mundo, el código ASCII se nos queda rápidamente pequeño. Por eso se ideó otra forma de codificación de caracteres que es la que más se usa en la actualidad: Unicode.

### 1.3.4. El código UTF-8 de Unicode

El código ASCII no es, desde luego, el único que existe para representar letras en binario, pero sí el más popular por motivos históricos.

A finales de la década de 1980, se empezó a desarrollar un proyecto para codificar de forma unívoca todos los caracteres de todas las lenguas del mundo (¡incluidas lenguas muertas!). A ese proyecto se lo denominó **Unicode**.

Unicode se ha impuesto con fuerza en la actualidad. Por ejemplo, este documento que estás leyendo ahora mismo está codificado con Unicode, en su versión UTF-8.

Y es que Unicode tiene varias implementaciones:

* **UTF-8**: los caracteres se codifican en grupos de 8 bits. Algunos solo necesitan 8 bits, pero otros necesitan 16, 24 o incluso 32 bits. Por ejemplo, la "N" se codifica con 8 bits (los mismos que en el viejo ASCII), pero la "Ñ" se codifica con 16: los 8 correspondientes a la "N" más los 8 correspondientes al símbolo "~"
* **UTF-16**: los caracteres se codifican en grupos de 16 bits. Algunos solo necesitan 16 bits, pero otros necesitan el doble, es decir, 32.
* **UTF-32**: los caracteres se codifican en grupos de 32 bits. Eso da un total de 2<sup>32</sup> caracteres posibles, más que suficientes para codificar todas las lenguas existentes en el mundo. Es la forma de Unicode más simple que existe.

La codificación más popular es la **UTF-8 de Unicode**. Aunque es algo más compleja que la UTF-32, los textos codificados de este modo ocupan mucho menos espacio. 

Los primeros 127 caracteres del UTF-8 se corresponden con el viejo código ASCII. Por eso mismo, y para propósitos prácticos, las tablas clásicas de código ASCII siguen siendo vigentes, al menos hasta el carácter número 127.

### 1.3.5. El código hexadecimal

Es importante conocer y saber manejar el código binario al ser el método de codificación que emplean los ordenadores digitales, pero este código tiene dos serios inconvenientes:

1. **Resulta difícil de manipular para nuestros cerebros**, que destán habituados a pensar en decimal (o habituados a no pensar en absoluto, que también se da el caso). 

2. **Los números binarios pueden llegar a tener cantidades enormes de dígitos**. Es habitual trabajar con números de 16, 32 o 64 dígitos binarios, lo cual los convierte en inmanejables.

Por este motivo, suelen usarse, en programación, otros dos sistemas de numeración llamados **octal** y **hexadecimal**.  

* El **sistema octal** maneja 8 símbolos distintos: 0, 1, 2, 3, 4, 5, 6 y 7.
* El **sistema hexadecimal**, por su parte, tiene 16 símbolos: 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, A, B, C, D, E y F.

Sin duda, el más utilizado de los dos es el hexadecimal y por este motivo nos vamos a detener en él, aunque haciendo notar que el octal funciona de la misma manera.

En hexadecimal, por tanto, es normal ver números cuyos dígitos son letras del alfabeto. Por ejemplo: 2AF5 es un número válido escrito en hexadecimal (exactamente, 10997 en decimal). 

La forma de contar, por supuesto, es la misma: 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, A, B, C, D, E, F, y después empezamos a agrupar los símbolos: 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 1A, 1B, 1C, 1D, 1E, 1F. Seguiríamos con 20, 21, 22, etc.

Podemos construir una tabla para comparar los primeros números en los tres sistemas de numeración que conocemos. Hemos rellenado los primeros números binarios con ceros a la izquierda por razones que pronto se verán, pero en realidad los números no cambian (recuerda que un cero a la izquierda no tiene ningún valor, ni en binario ni en el resto de sistemas)

Decimal|Binario|Hexadecimal
-|-|-
0|0000|0
1|0001|1
2|0010|2
3|0011|3
4|0100|4
5|0101|5
6|0110|6
7|0111|7
8|1000|8
9|1001|9
10|1010|A
11|1011|B
12|1100|C
13|1101|D
14|1110|E
15|1111|F

Si te fijas, cada dígito hexadecimal se corresponde exactamente con una combinación de 4 dígitos binarios. Así, por ejemplo, el número binario 1001 1101 se puede escribir más resumidamente como 9D en hexadecimal (porque 1001<sub>2</sub> equivale a 9<sub>16</sub> y 1101<sub>2</sub> equivale a D<sub>16</sub>).

Y **esa es la gran utilidad del sistema hexadecimal**: permite manipular números binarios de forma más escueta y resumida, de manera que nos sean más fáciles de manejar a nosotros, los humanos, que somos muy propensos a cometer errores.

#### Convertir números hexadecimales a decimales

El mecanismo es el mismo que ya utilizamos para convertir números binarios, sólo que cambiando la base del sistema de numeración de 2 a 16, ya que ahora vamos a manejar números hexadecimales. 

Por lo tanto, los pasos a seguir son: 

1. Numeramos las posiciones que ocupa cada dígito hexadecimal de derecha a izquierda, empezando por 0. Por ejemplo, en el número hexadecimal 2AF, numeraremos las posiciones así:

   ```
       Posiciones -->  2  1  0
                       2  A  F
   ```

2. Multiplicamos cada dígito hexadecimal por 16 elevado a la posición del dígito y sumamos todos los resultados. Con el número 2AF lo haríamos así:

<p align='center'>2 x 16<sup>2</sup> + A x 16<sup>1</sup> + F x 16<sup>0</sup></p>

Según la tabla de anterior, tenemos que el dígito hexadecimal A equivale a 10 en decimal, y que F equivale a 15. Por lo tanto la operación quedaría así:

<p align='center'>2 x 16<sup>2</sup> + 10 x 16<sup>1</sup> + 15 x 16<sup>0</sup></p>

Ahora sólo nos falta resolver la operaciones y sumar:

<p align='center'>2 x 256 + 10 x 16 + 15 x 1 = 687</p>

Por lo tanto, el número hexadecimal 2AF es equivalente al número decimal 687. Indicándolo con subíndices, lo expresaríamos así:

<p align='center'>2AF<sub>16</sub> = 687<sub>10</sub></p>

#### Convertir números decimales a hexadecimales

El proceso también es idéntico al realizado con números binarios, pero sustituyendo la división entre 2 por divisiones entre 16, que es la base del sistema hexadecimal.

#### Relación entre números hexadecimales y binarios

La verdadera utilidad del sistema hexadecimal es que **se puede utilizar en lugar del binario**, siendo más fácil de manejar. Para que ello sea posible, el paso de hexadecimal a binario y viceversa debe poder hacerse con mucha rapidez.

Para convertir un número hexadecimal a binario, basta con **sustituir cada dígito hexadecimal por sus cuatro cifras binarias** correspondientes, según la tabla de correspondencias que hemos visto más arriba. Por ejemplo:

<p align='center'>2AF<sub>16</sub> = 0010 1010 1111<sub>2</sub></p>

Del mismo modo, para convertir un número binario a hexadecimal, lo agruparemos en bloques de 4 cifras binarias (empezando por la derecha) y buscaremos la correspondencia en la tabla. Por ejemplo, el número binario 100100 se convierte así:

<p align='center'>0010 0100<sub>2</sub> = 24<sub>16</sub></p>

Observa que hemos rellenado con ceros a la izquierda para obtener bloques de 4 dígitos binarios sin alterar la esencia del número. 

Por supuesto, no es obligatorio usar este truco de rellenar con ceros a la izquierda, pero las primeras veces puede facilitar las cosas. Con un poco de práctica conseguirás convertir binarios a hexadecimales y viceversa de un sólo vistazo y sin necesidad de consultar la tabla.

### 1.3.6. Unidades de medida de información

Como hemos visto, el código binario es el fundamento del funcionamiento de los ordenadores: toda la información que el ordenador maneja, ya sea numérica o alfanumérica, se encuentra codificada en binario.

Del mismo modo que para medir distancias se utiliza el metro, o para medir masas se utiliza el gramo, **para medir la cantidad de información almacenada o procesada en un ordenador existe una unidad de medida**. 

Como el ordenador representa toda la información en binario, **la unidad fudamental de medida de la cantidad de información es el dígito binario** (es decir, 0 ó 1), también llamado **BIT** (de BInary digiT)

Un bit es realmente muy poca cantidad de información. Recuerda que, por ejemplo, para almacenar un sólo carácter en código ASCII son necesarios 7 u 8 bits. ¡Para un único carácter! 

Del mismo modo que el metro dispone de **múltiplos** (el decámetro, el hectómetro, el kilómetro, etc), también los tiene el bit, y son los siguientes:

* **Bit**: Unidad fundamental de medida de la cantidad de información.
* **Byte**: 1 byte equivale a 8 bits (un carácter). Esto no siempre ha sido así, pero, en la actualidad, se acepta la cifra de 8 como estándar. Cuidado con el nombre, porque se parecen y es un error común confundir el bit con el byte.
* **Kibibyte (KiB)**: 1 kilobyte son 1024 bytes. Fïjate que es parecido al kilómetro (1000 metros), pero no exactamente igual.
* **Mebibyte (MiB)**: 1 megabyte equivale a 1024 kilobytes.
* **Gibibyte (GiB)**: 1 gigabyte equivale a 1024 megabytes.
* **Tebibyte (TiB)**: 1 terabyte equivale a 1024 gigabytes
* **Pebibyte (PiB)**: 1 pebibyte equivale a 1024 tebibytes.
* **Exbibyte (EiB)**: 1 exbibyte equivale a 1024 pebibytes.

Podemos resumir las unidades de medida de información en la siguiente tabla:

```
1 Byte  =    8 bits
1 KiB   = 1024 Bytes
1 MiB   = 1024 KiB
1 GiB   = 1024 MiB
1 TiB   = 1024 GiB
1 PiB   = 1024 TiB
1 EiB   = 1024 PiB
```

Existe otra colección de múltiplos del Byte que se incrementan en potencias de 10, como sucede con los múltiplos de otras magnitudes físicas (tales como el kilómetro, el kilogramo, etc). Se introdujeron hace unos años para acabar con la confusión que provocaba el hecho de que algunos fabricantes consideraban que 1 KB eran 1024 Bytes, mientras que otros decían que eran 1000 Bytes. 

Estas otras unidades son:

* **Kilobyte (KB)**: 1 kilobyte son 1000 bytes.
* **Megabyte (MB)**: 1 megabyte equivale a 1000 kilobytes.
* **Gigabyte (GB)**: 1 gigabyte equivale a 1000 megabytes.
* **Terabyte (TB)**: 1 terabyte equivale a 1000 gigabytes
* **Petabyte (PB)**: 1 petabyte equivale a 1000 terabytes.
* **Exabyte (EB)**: 1 exabyte equivale a 1000 petabytes.

Podemos resumir las unidades de medida de información en la siguiente tabla:

```
1 Byte =    8 bits
1 KB   = 1000 Bytes
1 MB   = 1000 KB
1 GB   = 1000 MB
1 TB   = 1000 GB
1 PB   = 1000 TB
1 EB   = 1000 EB
```

**Las unidades decimales son más pequeñas que las correspondientes binarias**. Es decir, 1 GB, por ejemplo, son menos Bytes que 1 GiB. La diferencia es tanto mayor cuanto más grande es la unidad. 

Por ejemplo, 1 KB es un 2,35% más pequeño que 1 KiB, pero 1 EB es un 13,3% más pequeño que 1 EiB. ¡Entre 1 EB y 1 EiB hay 150 millones de GB de diferencia! Por lo tanto, no es de extrañar que las compañías de telefonía o los fabricantes de dispositivos de almacenamiento publiciten sus capacidades en las unidades más pequeñas posible, para que lo que te ofertan parezca más de lo que es.

Por último, hacemos notar que, en ocasiones, también se usan los mismos múltiplos para el bit, no para el Byte. Así, puedes encontrarte con megabits (Mb) o mebibits (Mib), que son, respectivamente, un millón (1.000.000) de bits y 220 bits (1.048.576). O con gigabits (Gb) o gigibits (Gib). La conversión entre los múltiplos del bit los del Byte se realiza multiplicando o dividiendo entre 8, como es lógico. Observa como **se usa la "b" minúscula para distinguir los bits de los Bytes**. 

## 1.4. Programas y algoritmos

Para realizar un programa es necesario idear previamente un algoritmo. Esto es importante hasta el extremo de que, sin algoritmo, no existiría el programa.

Un algoritmo, como hemos visto, es una **secuencia ordenada de acciones que conducen a la solución de un problema en un número finito de pasos simples**.

Por ejemplo, vamos a escribir un algoritmo para determinar si un número entero cualquiera (que llamaremos N) es par o impar:

```
- Inicio del algoritmo
- Paso 1. Preguntar qué número concreto es N.
- Paso 2. Si N es divisible entre 2, entonces la solución es "PAR".
- Paso 3. Si N no es divisible entre 2, entonces la solución es "IMPAR".
- Paso 4. Imprimir la solución.
- Fin del algoritmo
```

Recuerda que este algoritmo está **escrito para que lo ejecute un ordenador**, no para que lo ejecute una persona. Por eso el Paso 1 es "Preguntar qué número es N": porque el ordenador tendrá que preguntarnos a nosotros, los humanos, el número. Y por eso el Paso 4 es "Imprimir la solución": porque el ordenador nos ofrecerá el resultado imprimiéndolo en la pantalla o en un papel.

Este algoritmo resuelve el problema planteado en un número finito de pasos simples. Lógicamente, al ordenador no le podemos dar estas instrucciones tal y como las hemos escrito, sino que habrá que expresarlo en un lenguaje de programación, pero esto es algo que trataremos más adelante.

### 1.4.1. Datos y tipos de datos

Los algoritmos, como hemos dicho, son colecciones de instrucciones que resuelven un problema.

Pero esas instrucciones **siempre trabajan con datos**, es decir, con información formalizada para su uso en un ordenador:

* **Los datos de entrada** son datos que el algoritmo necesita para trabajar. En el ejemplo anterior, el número "N" es un dato de entrada.
* **Los datos de salida** son datos que el algoritmo produce como resultado de sus cálculos. En el ejemplo anterior, "solución" es un dato de salida.

Los datos siempre pertenecen a un **tipo de datos**, que es el rango de valores que ese dato puede tomar. Existen multitud de tipos de datos posibles, pero empezaremos trabajando solo con estos:

* **Enteros**. Los datos de este tipo solo pueden tomar como valores números enteros (positivos o negativos). Ejemplos: 3, 28, -15, 0, 4982...
* **Reales**. Números con decimales. Ejemplos: 18.25, -3.198887
* **Caracteres**. Letras, números, signos de puntuación... Ojo, si un dato es de tipo "carácter", solo puede contener en cada momento un único carácter. Ejemplos: 'a', 'Z', '&', '?'
* **Cadenas de caracteres**. O, simplemente, *cadenas*. Son colecciones de letras, números, signos de puntuación... Es decir, palabras y cualquier cosa que se le parezca. Ejemplos: "Hoy es lunes", "sgcv08 e98 ie7f83 ?so9&/". Suelen distinguirse de los caracteres individuales por la doble comilla, aunque esto depende del lenguaje de programación.
* **Lógicos o booleanos**. Estos datos solo pueden tener dos valores: *verdadero* o *falso*.

### 1.4.2. Variables y constantes

Las **variables** de un algoritmo son como las variables en una ecuación matemática: representaciones de un dato a las que asignamos un nombre o identificador.

En el algoritmo para averiguar si un número es par o impar, *N* es una variable y *solución* es otra variable.

Las variables pueden tomar un valor perteneciente a un tipo de datos. Ese valor puede cambiar a lo largo del algoritmo (por eso se denominan *variables*). Lo que no puede cambiar es el tipo de datos al que pertenecen. Es decir: si una variable es entera, no puede cambiar y pasar a ser real durante la ejecución del programa.

(Bueno, hay lenguajes que sí permiten hacer esto, pero esa es otra historia).

Por eso, la mayoría de los lenguajes de programación exigen que les indiquemos a qué tipo de datos pertenece cada variable antes de usarlas por primera vez. Es algo que también haremos en pseudocódigo. Eso se denomina **declarar una variable**. 

Así pues, podemos mejorar el algoritmo anterior con la declaración de las variables "N" y "solución":

```
- Inicio del algoritmo
- Declaración de variables:
   - N es un número entero.
   - solución es una cadena de caracteres.
- Paso 1. Averiguar qué número es N.
- Paso 2. Si N es divisible entre 2, entonces la solución es "PAR".
- Paso 3. Si N no es divisible entre 2, entonces la solución es "IMPAR".
- Paso 4. Imprimir la solución.
- Fin del algoritmo
```

Las **constantes** se parecen a las variables: tienen un nombre y un tipo, y se les asigna un valor. La única diferencia es que una constante *no puede cambiar de valor durante la ejecución del algoritmo* y una variable sí.

### 1.4.3. Subalgoritmos

Cuando un algoritmo es muy complejo, lo dividimos en trozos más simples que denominamos **subalgoritmos**. En programación, esos subalgoritmos se denominan **procedimientos** o **funciones**. Son casi la misma cosa, con una sutil diferencia que ya veremos cuando llegue el momento.

Los lenguajes de programación reales, además de las instrucciones básicas que enseguida vamos a ver, tienen unas colecciones de funciones predefinidas llamadas **bibliotecas**. Esas funciones se encargan de realizar tareas habituales y repetitivas, de modo que nos ahorran un montón de trabajo.

Por ejemplo, es posible escribir algoritmos para hacer cálculos matemáticos complejos, tales como logaritmos o raíces cuadradas. Para evitarnos ese trabajo, todos los lenguajes de programación disponen de una biblioteca de funciones matemáticas que incluye, entre otras muchas cosas, el cálculo de logaritmos y de raíces cuadradas para cuando los necesitemos. Así que vamos a suponer, cuando escribamos pseudocódigo, que también tenemos a nuestra disposición de esas bibliotecas de funciones.

Algunos subalgoritmos o funciones que existen en todos los lenguajes de programación y que podemos considerar que también existen en pseudocódigo son las siguientes:

* abs(x). Calcula el valor absoluto de x. Funciona con números reales y con enteros.
* sen(x). Calcula el seno de x. Devuelve valores reales.
* cos(x). Calcula el coseno de x. Devuelve valores reales.
* exp(x). Calcula e<sup>x</sup>. Devuelve un real.
* ln(x). Calcula el logaritmo neperiano de x. Devuelve un valor real.
* redon(x). Redondea el número x al valor entero más próximo. El valor x será real, y la función devolverá un entero.
* trunc(x). Trunca el número x, es decir, le elimina la parte decimal. El valor x será real, y la función devolverá un entero.
* rc(x). Calcula la raíz cuadrada de x. Devuelve un valor real
* azar(x). Genera un número al azar entre 0 y x. Supondremos que solo funciona con números enteros.

### 1.4.4. Expresiones y operadores

Una **expresión** es una combinación de constantes, variables, operadores y funciones.

Por ejemplo, esto es una expresión:

<p align='center'>rc((5 + x) / 2)</p>

En esta expresión, aparecen dos constantes literales (5 y 2), una variable (x), dos operadores aritméticos (+ y /) y una función (rc, para calcular la raíz cuadrada), además de los paréntesis, que sirven para manipular la prioridad de las operaciones.

Lógicamente, para resolver la expresión, es decir, para evaluar su resultado, debemos conocer cuál es el valor de la variable x.

Si suponemos que la variable x tiene el valor 7, el resultado de la expresión será 2,449.

La forma más habitual de encontrar una expresión es combinada con una **sentencia de asignación a una variable**. Por ejemplo:

<p align='center'>y <- raiz((5 + x) / 2)</p>

En estos casos, la expresión (lo que hay a la derecha del signo "<-") se evalúa y *su resultado es asignado a la variable* situada a la izquierda del "<-". 

En el ejemplo anterior, suponiendo que la variable x valiera 7, la expresión se evaluaría como 2,449, y, por lo tanto, ese es el valor que se asignaría a la variable y.

En las expresiones anteriores se han realizado algunas operaciones matemáticas (como sumas o divisiones). Los símbolos que se usan para ello se denominan **operadores**. En programación, existen distintos tipos de operadores:

* **Operadores aritméticos**: para hacer operaciones matemáticas convencionales. Los más habituales son + (suma), - (resta), * (producto), / (división) y MOD (resto de la división entera).
* **Operadores relacionales**: se utilizan para comparar números, aunque también pueden comparar caracteres o cadenas alfabéticamente. Los más habituales son < (menor que), > (mayor que), = (igual que), != (distinto de), <= (menor o igual que) y > (mayor o igual que). El resultado de estas comparaciones siempre es un valor lógico, es decir, verdadero o falso.
* **Operadoresl lógicos**: se utilizan para comparar otros datos lógicos y relacionarlos entre sí. Los más habituales son Y, O y NO. Estas palabras tienen el mismo significado que en la lengua natural.

Observa, por ejemplo, este fragmento de pseudocódigo muy fácil de entender:

```
puntos_carnet = <poner-aquí-un-número-entero>
edad = <poner-aquí-otro-número-entero>
Si edad >= 18 y puntos_carnet > 0 Entonces
   escribir "Puedes conducir"
FinSi
Si edad < 18 o puntos_carnet = 0 Entonces
   escribir "No puedes conducir"
FinSi
```

Aquí se usan dos variables, *puntos_carnet* y *edad* (que pueden tomar el valor que quieras ponerle) y luego se hacen dos comparaciones que implican operadores relacionales y lógicos.

* En la primera comparación, se tienen que cumplir a la vez las dos condiciones (que la edad sea mayor o igual que 18 años y que los puntos del carnet sean superiores a cero) para que el programa nos diga *"Puedes conducir"*.
* En la segunda comparación, basta con que una de las dos condiciones se cumpla para que el programa diga *"No puedes conducir"*.

Es habitual encontrar varias operaciones juntas en una misma línea. En estos casos es imprescindible conocer la **prioridad de los operadores**, porque las operaciones se calcularán en el orden de prioridad y el resultado puede ser muy distinto del esperado. 

En general, los operadores aritméticos tienen la máxima prioridad y, entre ellos, la multiplicación y la división son más prioritarias que la suma o la resta. Los siguientes operadores por prioridad son los relacionales y, por último, los lógicos. Sin embargo, esto puede variar según el lenguaje de programación concreto.

Lo más apropiado, si tenemos dudas sobre el orden en el que se van a ejecutar las operaciones, es usar paréntesis, exactamente igual que hacemos en matemáticas.

### 1.4.5. Tipos de instrucciones

Hemos dicho varias veces que los algoritmos constan de dos elementos: un conjunto de datos (representados por constantes y variables) y un conjunto de instrucciones.

Son muy pocas, en realidad, las instrucciones que necesitamos para construir algoritmos que funcionen. Increíblemente pocas:

* **Instrucciones de entrada de datos**. Sirven para indicar que, en ese punto, hay que proporcionar un dato al algoritmo. En el *Paso 1* del algoritmo para determinar si un número es par o impar hay una instrucción de entrada.
* **Instrucciones de salida de datos**. Sirven para que el algoritmo nos facilite el resultado de sus cálculos. En el *Paso 4* del algoritmo par-impar hay una instrucción de salida.
* **Instrucciones de asignación**. Sirven para asignar un valor a una variable.
* **Instrucciones para crear subalgoritmos**. Sirven para declarar subalgoritmos y darles un nombre.
* **Instrucciones condicionales**. Sirven para bifurcar el posible flujo de ejecución del algoritmo. Las instrucciones condicionales contienen siempre una condición que puede ser verdadera o falsa. Si es verdadera, el algoritmo continúa por un camino. Si es falsa, continúa por otro. Antes o después, esa bifurcación finaliza y el flujo del algoritmo vuelve a reunirse.
* **Instrucciones iterativas**. Sirven para repetir una o varias instrucciones un número finito de veces. Son la estructura más difícil de manejar para los programadores principiantes.

## 1.5. Diagramas de flujo y pseudocódigo

### 1.5.1. Formas de escribir algoritmos

Necesitamos un método de escritura de algoritmos que sea independiente del lenguaje de programación que luego se vaya a utilizar. Así se podrán traducir más tarde a cualquier lenguaje. 

Cuatro posibles maneras de escribir un algoritmo son:

* **Lenguaje natural** (como hicimos con el algoritmo para decidir si un número es o no par).
* **Diagramas de flujo**
* **Pseudocódigo**
* **Un lenguaje de programación real**

Por supuesto, también podríamos escribir los algoritmos directamente con un lenguaje de programación real, pero, si eres principiante, es más fácil aprender a programar usando pseudocódigo o diagramas de flujo que hacerlo con un lenguaje de programación. No tengas prisa: el lenguaje de programación llegará muy pronto.

El lenguaje natural (castellano, en nuestro caso) no es apropiado porque, como todos los lenguajes naturales humanos, tiene muchas ambigüedades que provocarían que, a veces, no quedara claro lo que queremos decir.

Los **diagramas de flujo** son representaciones gráficas de los algoritmos que ayudan a comprender de forma visual su funcionamiento. Tienen el inconveniente de que ocupan mucho espacio, por lo que no son apropiados para programas muy grandes.

El **pseudocódigo** es un lenguaje de codificación de algoritmos basado en la lengua castellana, pero donde solo se permite un conjunto reducido de palabras con un significado muy concreto. El pseudocódigo tiene dos propiedades que nos interesarán mucho: facilita considerablemente el aprendizaje de las técnicas de programación y logra que la traducción a un lenguaje de programación real sea casi instantánea. 

Los **lenguajes de programación reales** son más complejos que el pseudocódigo, pero la transición de uno a otro se hace con mucha facilidad.

### 1.5.2. Un ejemplo real

A continuación, vamos a mostrar el algoritmo que determina si un número es par escrito como un diagrama de flujo, como pseudocódigo y con un lenguaje de programación real (Python). Solo es un ejemplo, pero deberías echarle un vistazo con detenimiento para comprobar si lo entiendes o no. 

*"Con detenimiento"* significa que no lo leas deprisa y corriendo para marcharte a hacer otra cosa en dos minutos. Respira hondo y tómate tu tiempo.

Si no lo entiendes todo, no te agobies todavía. Aprenderás a escribir pseudocódigo y diagramas de flujo muy pronto.

**1. El algoritmo "Par-Impar" escrito en lenguaje natural:**

```
- Inicio del algoritmo
- Declaración de variables:
   - N es un número entero.
   - solución es una cadena de caracteres.
- Paso 1. Averiguar qué número es N.
- Paso 2. Si N es divisible entre 2, entonces la solución es "PAR".
- Paso 3. Si N no es divisible entre 2, entonces la solución es "IMPAR".
- Paso 4. Imprimir la solución.
- Fin del algoritmo
```

**2. El algoritmo "Par-Impar" escrito como diagrama de flujo:**

![Diagrama de flujo par-impar](/docs/tico/_site/assets/images/03-par-impar.png)

**3. El algoritmo "Par-Impar" escrito como pseudocódigo:**

```
Algoritmo par_impar
	Definir N como Entero
	Definir solucion como Cadena

	Escribir "Dime un número:"
	Leer N
	Si N MOD 2 = 0 Entonces
		solucion <- "PAR"
	SiNo
		solucion <- "IMPAR"
	FinSi
	Escribir "El número ", N, " es ", solucion
FinAlgoritmo
```

**4. El algoritmo "Par-Impar" escrito con un lenguaje real (Python):**

```python
def par_impar():
  n = int()
  solucion = ""

  print("Dime un número:")
  n = int(input())

  if n % 2 == 0:
    solucion = "PAR"
  else:
    solucion = "IMPAR"

  print("El número {} es {}".format(n, solucion))
```

## 1.6. Los lenguajes de programación

Acabas de ver un ejemplo de código escrito en un lenguaje de programación real (Python, en ese caso). Pero literalmente hay *cientos* de lenguajes de programación: constituyen un ecosistema muy extenso y en constante evolución. 

Para orientarse un poco en esa jungla, nada mejor que clasificar los lenguajes igual que los biólogos clasifican a las criaturas vivas.

### 1.6.1. Tipos de lenguaje según el nivel de abstracción: alto y bajo nivel

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

### 1.6.2. Tipos de lenguaje según su generación

Los lenguajes de programación también se clasifican según la generación a la que pertenecen.

El lenguaje máquina fue el lenguaje de primera generación. Los ensambladores fueron los lenguajes de segunda generación. A partir de ahí, surgió una explosión de lenguajes diferentes que podemos clasificar como:

* **Lenguajes de tercera generación** (o **imperativos**), en los que el programador escribe una secuencia de instrucciones que el ordenador debe ejecutar en un orden preestablecido. Son los lenguajes más "clásicos": C, Basic, Cobol, Fortran, Pascal, etc.
* **Lenguajes de cuarta generación** (o **4GL**), dirigidos a facilitar la creación de interfaces con el usuario y con otras aplicaciones, como las bases de datos. Un ejemplo de estos lenguajes es SQL, universalmente utilizado para manipular bases de datos y omnipresente en muchas aplicaciones web actuales.
* **Lenguajes orientados a objetos**, que son una evolucuión de los lenguajes de tercera generación y que permiten construir con mayor facilidad y robustez programas modulares complejos. Ejemplos de lenguajes orientados a objetos son C++, C#, Java, Javascript, Python, PHP o Ruby. Algunos de ellos son multiparadigma, es decir, permiten programar con orientación a objetos pero también permiten hacer programación estructurada clásica, sin objetos.
* **Lenguajes declarativos** y **lenguajes funcionales**, propios de la inteligencia artificial, como Prolog o Lisp.
* **Lenguajes de bloques**. Están pensados para el aprendizaje del pensamiento computacional desde muy corta edad, pero son cada vez más potentes. El más conocido es Scratch.
* **Otros** tipos aún más específicos: lenguajes concurrentes, paralelos, distribuidos, etc.

En general, podemos decir que un programador acostumbrado a trabajar con un lenguaje de tercera generación puede aprender con poco esfuerzo cualquier otro lenguaje de tercera generación y, con algo más de trabajo, un lenguaje orientado a objetos. Sin embargo, el "salto" a otros tipos de lenguajes, como los declarativos, cuesta más porque las fundamentos de estos lenguajes son muy diferentes.

### 1.6.3. Tipos de lenguaje según su forma de traducción 
 
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

El **intérprete** es notablemente **más lento** que el compilador, ya que realiza la traducción al mismo tiempo que la ejecución. Además, esa traducción se lleva a cabo siempre que se ejecuta el programa, mientras que el compilador sólo la hace una vez. Hay un evidente malgasto de recursos.

Sin embargo, los intérpretes tienen una gran ventaja sobre los compiladores, y es que logran que **los programas sean más portables**, es decir, que puedan ejecutarse en diferentes máquinas con diferentes sistemas operativos sin apenas cambios.

Así, un programa *compilado* en una máquina PC bajo Windows no funcionará en un Mac o en un PC bajo Linux, a menos que se vuelva a compilar el programa fuente en el nuevo sistema. En cambio, un programa *interpretado* funcionará en todas las plataformas, siempre que dispongamos del intérprete en cada una de ellas.

**C/C++ es un ejemplo de lenguaje compilado. Python es un ejemplo de lenguaje interpretado.**

Eso significa que un programa escrito, por ejemplo, con **Python**, puede funcionar en cualquier máquina que disponga de un intérperte Python, que, hoy en día, es casi cualquiera. Por eso, **cualquier programa escrito en Python puede ejecutarse prácticamente en cualquier ordenador del mundo** sin tocarle ni una coma.

En cambio, los programas desarrollados con C/C++ se ejecutan **más rápido** (¡muuucho más rápido!) que sus equivalentes en Python. Sin embargo, **tendrás que volver a compilarlos** si deseas ejecutarlos en una máquina con diferente hardware o diferente sistema operativo.

### 1.6.4. Tipos de lenguaje según su tipado

Por *tipado* nos referimos a la forma en la que los lenguajes de programación usan los tipos de datos. Ya sabes: entero, carácter, lógico, etc. Es decir, las categorías a las que puede pertenecer una variable.

Pues bien, según su tipado, los lenguajes pueden ser:

* **De tipado fuerte**: los tipos de datos no pueden mezclarse. Por ejemplo, no puedes sumar un entero y un real, porque son números de distinto tipo. Y mucho menos sumar un entero con un carácter.
* **De tipado débil**: los tipos de datos pueden mezclarse y el lenguaje hace las conversiones de tipos implícitas que le parezca oportunas. Así, en estos lenguajes podrías sumar un entero con un real, o incluso un entero con un carácter. ¿Que cuál sería el resultado? Buena pregunta. Tendrás que probarlo, porque eso depende de las conversiones de tipo que haga el lenguaje.
* **De tipado estático**: los tipos de datos se asignan al escribir el código y no pueden cambiarse durante la ejecución. Esto es típico de los compiladores (aunque no de todos).
* **De tipado dinámico**: los tipos de datos pueden cambiarse alegremente durante la ejecución. Esto es típico de los intérpretes.

Las dos primeras categorías y las dos segundas no son excluyentes. Por ejemplo, pueden existir lenguajes de tipado débil y dinámico, o bien fuerte y estático. Las otras combinaciones (fuerte y dinámico, débil y estático) pueden darse pero son menos habituales. 

### 1.6.5. El *top ten* de los lenguajes de programación

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

Según estas cifras, el conjunto de proyectos que usan lenguaje C o cualquiera de sus variantes (C++ o C#) es muy significativo, sobre todo teniendo en cuenta que C es un lenguaje de la década de 1970, lo cual constituye una eternidad en informática. Que un lenguaje mantenga su vigencia durante tanto tiempo indica lo robusto y confiable que es. Seguramente seguirá con nosotros dentro de muchos años, cuando otros competidores de esta lista ya hayan caído en el olvido.

## 1.7. Ejercicios propuestos

#### Ejercicios de codificación de la información y unidades de medida

**Ejercicio 1**. Investiga y responde a las siguientes cuestiones:

> a) ¿Por qué los ordenadores digitales sólo utilizan ceros y unos, es decir, códigos binarios, en lugar de manejar internamente códigos decimales, como hacemos los humanos?

> b)  ¿Por qué los humanos estamos habituados a un sistema de numeración basado en 10 símbolos y no a cualquier otro, por ejemplo, uno con 8 símbolos, o con 5, o con 12?

**Ejercicio 2**. Tenemos un viejo ordenador con una capacidad de almacenamiento en la memoria principal de 2 GB. Suponiendo que un nombre ocupe 30 caracteres y un apellido ocupe 25, ¿cuántos nombres y apellidos puede almacenar este ordenador?

**Ejercicio 3**. Convierte las siguientes cantidades de información:

> a) 30 GB a MB

> b) 128 KB a bits

> c) 2 MB a bits

> d) 64512 KiB a MiB

**Ejercicio 4**. Convierte los siguientes números al sistema de numeración indicado:

> a) 100101<sub>2</sub> a decimal

> b) 254<sub>10</sub> a binario

> c) 1111111<sub>2</sub> a decimal

> d) 191<sub>10</sub> a binario

**Ejercicio 5**. Convierte los siguientes números entre los sistemas hexadecimal y binario, utilizando la tabla de conversión que hemos visto en este tema. Si puedes hacerlo sin mirar la tabla, mucho mejor.

> a) 10011101<sub>2</sub> a hexadecimal

> b) 110100111011001101<sub>2</sub> a hexadecimal

> c) 38C<sub>16</sub> a binario

> d) FDCA<sub>16</sub> a binario

**Ejercicio 6**. Escribe las palabras "CELIA VIÑAS" en código ASCII (en decimal y en hexadecimal).

**Ejercicio 7**. La cantidad de memoria RAM de un ordenador personal medio ha ido creciendo imparablemente desde que los ordenadores personales se popularizaron en los años 80. Estas son algunas de esas cantidades:

* Año 1982: 256 KiB
* Año 1992: 4 MiB
* Año 2002: 512 MiB
* Año 2012: 4 GiB
* Año 2022: 8 GiB

Dibuja en un gráfico la evolución de estas cantidades y haz una proyección aproximada hasta el año 2032. ¿Cuánta memoria RAM usarán los ordenadores dentro de 10 años? Puedes usar un programa de hoja de cálculo para ayudarte.

**Ejercicio 8**. El tamaño de los discos duros promedios de los ordenadores también ha ido creciendo desde hace cuarenta años. Haz una proyección parecida a la anterior para averiguar qué capacidad de almacenamiento en disco tendrán los ordenadores personales, previsiblemente, dentro de 10 años.

* Año 1982: 10 MiB (los pocos ordenadores que tenían disco duro)
* Año 1992: 1 GiB
* Año 2002: 40 GiB
* Año 2012: 240 GiB
* Año 2022: 2 TiB

#### Ejercicios sobre algoritmos y lenguajes de programación

**Ejercicio 9**. Si x = 5, y = 3 y z = 0, ¿cuál será el valor de las siguientes expresiones?

> a) x * y + z

> b) x + y * z

> c) (x + y) / z

> d) raiz(y * x + 10)

> e) (x + y) * (z + 2)

> f) x + y * z + 2

**Ejercicio 10**. Examina este diagrama de flujo y trata de explicar con palabras qué crees que hace este programa.

![Diagrama de flujo ejercicio 10](/docs/tico/_site/assets/ejercicios-resueltos-pseint/03_01_area_perimetro.png)

**Ejercicio 11**. Examina este diagrama de flujo y trata de explicar con palabras qué crees que hace este programa.

![Diagrama de flujo ejercicio 11](/docs/tico/_site/assets/ejercicios-resueltos-pseint/03_04_positivo_negativo.png)

**Ejercicio 12**. Examina este diagrama de flujo y trata de explicar con palabras qué crees que hace este programa.

![Diagrama de flujo ejercicio 12](/docs/tico/_site/assets/ejercicios-resueltos-pseint/03_14_contar_de_uno_a_n.png)

**Ejercicio 13**. Busca, en al menos dos sitios web diferentes, información sobre cuáles son los lenguajes de programación que más se utilizan en la actualidad. ¡Asegúrate de que sean inforamación actualizada!

Luego haz una lista con los 10 lenguajes más utilizados según cada web. ¿Las listas coinciden entre ellas? ¿Y difieren mucho de los que hemos mencionado en el tema?