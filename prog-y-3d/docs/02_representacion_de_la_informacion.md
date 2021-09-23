---
layout: page
title: 2. Representación de la información
permalink: /representacion-de-la-informacion/
nav_order: 2
has_children: true
parent: Introd. a la prog. y al diseño 3D
---

# 2. Representación de la información
{: .no_toc }

<span style='color: red'><strong>ATENCIÓN: este capítulo aún está en construcción</strong></span>

El ordenador es una máquina digital, es decir, binaria. Cualquier aprendiz de programador/a debe conocer esa forma de codificación, y otras primas suyas (como la octal y la hexadecimal) antes de aventurarse en los vericuetos de la programación. Dedicaremos todo este tema a hacerlo.

- TOC
{:toc}

## 2.1. Los códigos

Un **código** es un *método de representación de la información*. Se compone de un conjunto de símbolos, llamado **alfabeto**, y de un conjunto de **reglas** para combinar esos símbolos de forma correcta.

Estos son algunos ejemplos de códigos que utilizas todos los días o que, al menos, conoces:

* Ejemplo 1: la lengua castellana es un código. Su alfabeto es el abecedario (a, b, c, d, e ... z), pero los símbolos del alfabeto no se pueden combinar a lo loco, sino que existen unas reglas, y sólo siguiendo esas reglas se codifica correctamente la información, dando lugar a mensajes con sentido. Esas reglas las habéis estudiado en la asignatura de lengua castellana desde la enseñanza primaria.
* Ejemplo 2: el código morse también es un código. Su alfabeto es muy reducido: sólo el punto (.) y la raya (–), pero combinando los dos símbolos correctamente, se puede transmitir cualquier información.
* Ejemplo 3: el sistema de numeración decimal es un código. Tiene un alfabeto de 10 símbolos (0, 1, 2, 3, 4, 5, 6, 7, 8 y 9). Combinándolos según ciertas reglas, puede usarse para transmitir información. Pero ojo, no cualquier información, solamente información numérica. Hemos dicho que los códigos sirven para representar información, pero no que tengan que servir para representar toda la información posible. Aunque sólo sirva para los números, el sistema de numeración también es un código.

### 2.1.1. El código binario

Pues bien, el sistema de numeración binario también es un código.

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

XXX insertar imagen división binaria

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

### 2.1.2. El código ASCII

Hasta ahora hemos visto que mediante el código binario se pueden representar números, pero no sabemos cómo se las apaña un ordenador para **representar las letras**, o, dicho en terminología informática, los **caracteres alfanuméricos** (que incluyen números, letras y otros símbolos, como los signos de puntuación).

**El código ASCII consiste en una correspondencia entre números binarios de 8 dígitos y caracteres alfanuméricos**. 

(Bueno, en realidad el código ASCII original usaba números binarios de 7 dígitos, pero eso es otra historia. El ASCII que ha llegado hasta nuestros días es el ASCII extendido de 8 bits).

Así, por ejemplo, al número 65<sub>10</sub> (expresado en binario, 01000001<sub>2</sub>) se le hace corresponder la letra "A", al 66<sub>10</sub> la "B", al 67<sub>10</sub> la "C", etc.

De este modo, el ordenador puede también manejar letras, y lo hace del mismo modo en que maneja números: mediante combinaciones de ceros y unos.

Es importante resaltar que los códigos ASCII siempre tienen 8 dígitos binarios, rellenándose con ceros a la izquierda si fuera necesario. Así ocurre en el caso de la letra A, que, como hemos dicho, se representa con el código 01000001.

Si te tomas la molestia de calcular cuántos caracteres diferentes pueden representarse con el código ASCII, verás que son exactamente 256. Suficientes para todos los caracteres habituales, ¿verdad? Aunque, un momento... ¿Y qué hay de los caracteres griegos? ¿O los caracteres cirílicos del ruso? Eso por no hablar del chino y o el japonés.

Si queremos dar cabida a cualquier idioma del mundo, el código ASCII se nos queda rápidamente pequeño. Por eso se ideó otra forma de codificación de caracteres que es la que más se usa en la actualidad: Unicode.

### 2.1.3. El código Unicode

XXX revisar desde aquí

### 2.1.4. El código hexadecimal

Es importante conocer y saber manejar el código binario al ser el método de codificación que emplean los ordenadores digitales, pero este código tiene dos serios inconvenientes:

    • Primero, resulta difícil de manipular para cerebros que, como los nuestros, están habituados a pensar en decimal (o habituados a no pensar en absoluto, que también se da el caso). 

    • Segundo, los números binarios pueden llegar a tener cantidades enormes de dígitos (es habitual trabajar con números de 16, 32 ó 64 dígitos binarios), lo cual los convierte en inmanejables.

Por este motivo, suelen usarse, en programación, otros dos sistemas de numeración llamados octal y hexadecimal.  El octal maneja 8 símbolos distintos y, el hexadecimal, 16. Sin duda, el más utilizado es el hexadecimal y por este motivo nos vamos a detener en él, aunque haciendo notar que el octal funciona de la misma manera, sólo que empleando los dígitos del 0 al 7.


Si el sistema binario utiliza dos símbolos (0 y 1) y el decimal utiliza 10 (0, 1, 2, 3, 4, 5, 6, 7, 8 y 9), el hexadecimal emplea 16 símbolos, que son: 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, A, B, C, D, E y F.
En hexadecimal, por tanto, es normal ver números cuyos dígitos son letras del alfabeto. Por ejemplo: 2AF5 es un número válido escrito en hexadecimal (exactamente, el 10997 en decimal). La forma de contar, por supuesto, es la misma: 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, A, B, C, D, E, F, y después empezamos a agrupar los símbolos: 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 1A, 1B, 1C, 1D, 1E, 1F. Seguiríamos con 20, 21, 22, etc.

Podemos construir una tabla para comparar los primeros números en los tres sistemas de numeración que conocemos. Hemos rellenado los primeros números binarios con ceros a la izquierda por razones que pronto se verán, pero en realidad los números no cambian (recuerda que un cero a la izquierda no tiene ningún valor, ni en binario ni en el resto de sistemas)

XXX insertar tabla

Si te fijas, cada dígito hexadecimal se corresponde exactamente con una combinación de 4 dígitos binarios. Así, por ejemplo, el número binario 1001 1101 se puede escribir más resumidamente como 9D en hexadecimal. Y esa es la gran utilidad del sistema hexadecimal: permite manipular números binarios de forma más escueta y resumida, de manera que nos sean más fáciles de manejar a nosotros, los humanos, que somos muy propensos a cometer errores.
Convertir números hexadecimales a decimales
El mecanismo es el mismo que ya utilizamos para convertir números binarios, sólo que cambiando la base del sistema de numeración de 2 a 16, ya que ahora vamos a manejar números hexadecimales. Por lo tanto, los pasos a seguir son: 
    1) Numeramos las posiciones que ocupa cada dígito hexadecimal de derecha a izquierda, empezando por 0. Por ejemplo, en el número hexadecimal 2AF, numeraremos las posiciones así:

XXX insertar imagen

    2) Multiplicamos cada dígito hexadecimal por 16 elevado a la posición del dígito y sumamos todos los resultados. Con el número 2AF lo haríamos así:

2 x 162 + A x 161 + F x 160

Según la tabla de anterior, tenemos que el dígito hexadecimal A equivale a 10 en decimal, y que F equivale a 15. Por lo tanto la operación quedaría así:

2 x 162 + 10 x 161 + 15 x 160

Ahora sólo nos falta resolver la operaciones y sumar:

2 x 256 + 10 x 16 + 15 x 1 = 687

Por lo tanto, el número hexadecimal 2AF16 es equivalente al número decimal 68710. Indicándolo con subíndices, lo expresaríamos así:
2AF16 = 68710

#### Convertir números decimales a hexadecimales

El proceso también es idéntico al realizado con números binarios, pero sustituyendo la división entre 2 por divisiones entre 16, que es la base del sistema hexadecimal.

#### Relación entre números hexadecimales y binarios

La verdadera utilidad del sistema hexadecimal es que se puede utilizar en lugar del binario, siendo más fácil de manejar. Para que ello sea posible, el paso de hexadecimal a binario y viceversa debe poder hacerse con mucha rapidez.

Para convertir un número hexadecimal a binario, basta con sustituir cada dígito hexadecimal por sus cuatro cifras binarias correspondientes, según la tabla de la página anterior. Por ejemplo:

2AF16 = 0010 1010 11112

Del mismo modo, para convertir un número binario a hexadecimal, lo agruparemos en bloques de 4 cifras binarias (empezando por la derecha) y buscaremos la correspondencia en la tabla. Por ejemplo, el número binario 100100 se convierte así:

0010 01002 = 2416

Observa que hemos rellenado con ceros a la izquierda para obtener bloques de 4 dígitos binarios sin alterar la esencia del número. 

Por supuesto, no es obligatorio hacerlo, pero las primeras veces puede facilitar las cosas. Con un poco de práctica conseguirás convertir binarios a hexadecimales y viceversa de un sólo vistazo y sin necesidad de consultar la tabla.

### 2.1.5. El código octal

XXX redactar

## 2.2. Unidades de medida de información

Como hemos visto, el código binario es el fundamento del funcionamiento de los ordenadores: toda la información que el ordenador maneja, ya sea numérica o alfanumérica, se encuentra codificada en binario.

Del mismo modo que para medir distancias se utiliza el metro, o para medir masas se utiliza el gramo, para medir la cantidad de información almacenada o procesada en un ordenador existe otra unidad de medida. Como el ordenador representa toda la información en binario, la unidad fudamental es el dígito binario (es decir, 0 ó 1), también llamado BIT (de BInary digiT)

Un bit es realmente muy poca cantidad de información. Recuerda que, por ejemplo, para almacenar un sólo carácter en código ASCII son necesarios 7 u 8 bits. ¡Para un único carácter! Del mismo modo que el metro dispone de múltiplos (el decámetro, el hectómetro, el kilómetro, etc), también los tiene el bit, y son los siguientes:

    • Byte: 1 byte equivale a 8 bits (un carácter). Esto no siempre ha sido así, pero, en la actualidad, se acepta la cifra de 8 como estándar. Cuidado con el nombre, porque se parecen y es un error común confundir el bit con el byte.
    • Kibibyte (KiB3 ): 1 kilobyte son 1024 bytes. Fïjate que es parecido al kilómetro (1000 metros), pero no exactamente igual.
    • Mebibyte (MiB): 1 megabyte equivale a 1024 kilobytes.
    • Gibibyte (GiB): 1 gigabyte equivale a 1024 megabytes.
    • Tebibyte (TiB): 1 terabyte equivale a 1024 gigabytes
    • Pebibyte (PiB): 1 pebibyte equivale a 1024 tebibytes.
    • Exbibyte (EiB): 1 exbibyte equivale a 1024 pebibytes.

Podemos resumir las unidades de medida de información en la siguiente tabla:

  1 Byte =    8 bits
  1 KiB   = 1024 Bytes
  1 MiB   = 1024 KiB
  1 GiB   = 1024 MiB
  1 TiB   = 1024 GiB
  1 PiB   = 1024 TiB
  1 EiB   = 1024 PiB

Existe otra colección de múltiplos del Byte que se incrementan en potencias de 10, como sucede con los múltiplos de otras magnitudes físicas (tales como el kilómetro, el kilogramo, etc). Se introdujeron hace unos años para acabar con la confusión que provocaba el hecho de que algunos fabricantes consideraban que 1 KB eran 1024 Bytes, mientras que otros decían que eran 1000 Bytes. 

Estas otras unidades son:

    • Kilobyte (KB): 1 kilobyte son 1000 bytes.
    • Megabyte (MB): 1 megabyte equivale a 1000 kilobytes.
    • Gigabyte (GB): 1 gigabyte equivale a 1000 megabytes.
    • Terabyte (TB): 1 terabyte equivale a 1000 gigabytes
    • Petabyte (PB): 1 petabyte equivale a 1000 terabytes.
    • Exabyte (EB): 1 exabyte equivale a 1000 petabytes.

Podemos resumir las unidades de medida de información en la siguiente tabla:

  1 Byte =    8 bits
  1 KB   = 1000 Bytes
  1 MB   = 1000 KB
  1 GB   = 1000 MB
  1 TB   = 1000 GB
  1 PB   = 1000 TB
  1 EB   = 1000 EB

Las unidades decimales son más pequeñas que las correspondientes binarias. Es decir, 1 GB, por ejemplo, son menos Bytes que 1 GiB. La diferencia es tanto mayor cuanto más grande es la unidad. Por ejemplo, 1 KB es un 2,35% más pequeño que 1 KiB, pero 1 EB es un 13,3% más pequeño que 1 EiB. ¡Entre 1 EB y 1 EiB hay 150 millones de GB de diferencia! Por lo tanto, no es de extrañar que las compañías de telefonía o los fabricantes de dispositivos de almacenamiento publiciten sus capacidades en las unidades más pequeñas posible.

Por último, hacemos notar que, en ocasiones, también se usan los mismos múltiplos para el bit, no para el Byte. Así, puedes encontrarte con megabits (Mb) o mebibits (Mib), que son, respectivamente, un millón (1.000.000) de bits y 220 bits (1.048.576). O con gigabits (Gb) o gigibits (Gib). La conversión entre los múltiplos del bit los del Byte se realiza multiplicando o dividiendo entre 8, como es lógico. Observa como se usa la "b"minúscula para distinguir los bits de los Bytes. 