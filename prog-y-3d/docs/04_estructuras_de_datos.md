---
layout: page
title: 4. Estructuras de datos. Subalgoritmos
permalink: /estructuras-de-datos/
nav_order: 4
has_children: true
parent: Introd. a la prog. y al diseño 3D
---

# 4. Estructuras de datos. Subalgoritmos
{: .no_toc }

- TOC
{:toc}

Hasta ahora, hemos conocido las estructuras de control básicas de cualquier programa estructurado: secuencia, condición e iteración.

Pero los programas no se componen solo de *instrucciones*, sino también de ***datos***.

Todos los datos que hemos manejado hasta ahora eran simples, es decir, se almacenaban en variables en las que solo podíamos guardar un valor en cada momento. Las variables simples se nos quedan cortas en muchas ocasiones (repasa el programa de las 3 en raya, sin ir más lejos, para comprobarlo). En esos casos necesitamos una variable de tipo complejo o **estructura de datos**.

En este capítulo hablaremos de las estructuras de datos y nos centraremos en la más utilizada con diferencia: el **array**. 

Después, introduciremos los conceptos de **subalgoritmo, función y biblioteca de funciones**, para terminar hablando de uno de los principios básicos de la ingeniería del software: la **reutilización del código**.

## 4.1. Estructuras de almacenamiento de datos

Hemos trabajado, por el momento, con los tipos de datos básicos: enteros, reales, caracteres, lógicos...  Es el momento de dar el salto a los **tipos de datos complejos**, también llamados **estructuras de datos**.

Las estructuras de datos pueden ser de dos tipos:

* **Estáticas**: son aquellas que ocupan un espacio determinado en la memoria del ordenador. Este espacio es invariable y se especifica durante la escritura del código fuente.
* **Dinámicas**: son aquellas cuyo espacio ocupado en la memoria puede modificarse durante la ejecución del programa.

Existe todo un universo de estructuras de datos: desde los arrays, presentes en casi cualquier programa, hasta estructuras mucho más exóticas como pilas, colas, listas enlazadas, árboles, grafos, etc.

Nosotros no pretendemos verlas todas, ni mucho menos, pero sí que conozcas la más importante de todas: el array.

## 4.2. Arrays unidimensionales (vectores)

Un **array** (también llamado **arreglo**, sobre todo en América latina) es una *agrupación de muchos datos individuales del mismo tipo bajo el mismo nombre*. Cada dato individual de un array es accesible mediante un índice.

Por ejemplo, un array de números enteros es una colección de muchos números enteros a los que les adjudicamos un único identificador.

El caso más simple de array es el **array unidimensional**, también llamado **vector**. Se trata, sin duda, del rey de las estructuras de almacenamiento.

### 4.2.1. Declaración de vectores

La **declaración de un vector** en pseudocódigo (seguiremos usando la sintaxis de PSeInt) se hace así:

```
Definir nombre_variable Como tipo
Dimension nombre_variable[tamaño]
```

Por ejemplo:

```
Definir serie como Entero
Dimension serie[10]
```

La variable *serie* será un vector que contendrá 10 números enteros. Todos los números recibirán el mismo nombre, es decir, *serie*. 

Se puede acceder a cada uno de los números que forman el vector escribiendo a continuación del nombre un número entre corchetes. Ese número se denomina **índice**.

Observa el siguiente ejemplo:

```
Definir serie como Entero
Dimension serie[5]
serie[2] <- 20
serie[3] <- 15
serie[4] <- serie[2] + serie[3]
Escribir serie[4]
```

El vector *serie* de este ejemplo puede almacenar hasta 5 números enteros. En su posición 2 se almacena el número 20, y en su posición 3, el 15. Luego se suman ambos valores, y el resultado se almacena en la posición 4. Finalmente, se imprime en la pantalla el resultado de la suma, es decir, 35.

Es muy útil representar los vectores de forma gráfica para entenderlos mejor. El vector serie del ejemplo anterior se puede representar así:

<pre>
            +------------+----+----+----+----+----+
            | Posiciones |  0 |  1 |  2 |  3 |  4 |
    serie = +------------+----+----+----+----+----+
            | Valores    |  ? |  ? | 20 | 15 | 35 |
            +------------+----+----+----+----+----+
</pre>

Observa algo muy importante: **el primer elemento del vector tiene el índice 0**, es decir, el primer elemento es **serie[0]**.

Como este vector tiene 5 elementos, el último será serie[4], no serie[5]. Observa también que los elementos 0 y 1 no han sido utilizados y, por lo tanto, tienen un valor desconocido, exactamente lo mismo que ocurre con cualquier variable de tipo simple que no se inicialice.

*(Nota: PSeInt se puede configurar para que el primer elemento del vector tenga índice 1, no 0, pero, como la mayor parte de los lenguajes de programación reales usan el 0, supondremos que PSeInt también lo está haciendo)*

Como es lógico, se pueden construir vectores cuyos elementos sean de cualquier otro tipo simple, como números reales o caracteres, con la única restricción de que todos los elementos sean del mismo tipo.

Y, por supuesto, pueden construirse vectores cuyos elementos sean otros vectores. Obtendremos así un array bidimensional, del que hablaremos un poco más adelante.
   

### 4.2.2. Manipulación de elementos de un vector

Los vectores deben manipularse **elemento a elemento**. *No se pueden modificar todos los elementos a la vez.*

Por ejemplo, **para asignar valores a los elementos de un vector**, esta sería la manera:

```
Definir serie como Entero
Dimension serie[5]
serie[0] <- 5
serie[1] <- 3
serie[2] <- 7
...etc...
```

Cada elemento del vector es, a todos los efectos, una variable que puede usarse independientemente de los demás elementos. Así, por ejemplo, un elemento del vector *serie* puede usarse en una instrucción de salida igual que cualquier variable simple de tipo entero:

```
Escribir(serie[2])
```

Del mismo modo, pueden usarse elementos de un vector en una instrucción de entrada. Por ejemplo:

```
Escribir "Dime un número entero"
Leer (serie[4])
```

### 4.2.3. Recorrido de un vector

La forma habitual de utilizar un vector es **accediendo en secuencia a todos sus elementos**, uno tras otro. 

Para ello, se utiliza un **bucle con contador**, de modo que la variable contador nos sirve como **índice** para acceder a cada uno de los elementos del vector.

Supongamos, por ejemplo, que tenemos un vector de 10 números enteros declarado llamado *v*, y una variable entera llamada *i*, que será nuestro índice. Por medio de un bucle, con ligeras modificaciones, podemos realizar todas estas operaciones:

* **1. Inicializar todos los elementos a un valor cualquiera** (por ejemplo, 0):

   ```
   Para i <- 0 hasta 9 hacer
      v[i] <- 0
   FinPara
   ```
* **2. Inicializar todos los elementos con valores introducidos por teclado**:

   ```
   Para i <- 0 hasta 9 hacer
      Escribir "Dime el valor del elemento nº ", i
      Leer v[i] 
   FinPara
   ```
* **3. Mostrar todos los elementos en la pantalla**:

   ```
   Para i <- 0 hasta 9 hacer
      Escribir "El elemento nº ", i, " vale ", v[i]
   FinPara
   ```
* **4. Realizar alguna operación que implique a todos los elementos**. Por ejemplo, sumarlos en un **acumulador**:

   ```
   suma <- 0
   Para i <- 0 hasta 9 hacer
      suma <- suma + v[i]
   FinPara
   Escribir "La suma de todos los elementos es: ", suma
   ```

### 4.2.4. Ordenación de vectores

Otra operación típica que se realiza con vectores es **ordenar sus elementos** mediante algún criterio. 

Por ejemplo, un vector de números enteros puede ordenarse de menor a mayor (o al revés), mientras que un vector de caracteres puede ordenarse alfabéticamente.

Supongamos, por ejemplo, que tenemos un vector de números enteros con estos valores:

<pre>
+----+----+----+----+----+----+----+----+----+----+
|  0 |  1 |  2 |  3 |  4 |  5 |  3 | 14 |  9 |  8 |
+----+----+----+----+----+----+----+----+----+----+
</pre>

Después de la ordenación, nos quedará este otro vector:

<pre>
+----+----+----+----+----+----+----+----+----+----+
|  0 |  1 |  2 |  3 |  3 |  4 |  5 |  8 |  9 | 14 |
+----+----+----+----+----+----+----+----+----+----+
</pre>

Del mismo modo, se pueden ordenar los elementos con cualquier otro criterio: de mayor a menor, primero los pares y luego los impares, o cualquier otro que nos resulte útil para resolver un problema.

Métodos de ordenación de vectores hay muchos, algunos muy simples (e ineficientes) y otros muy elaborados, y constituyen un área de estudio muy interesante dentro de la algorítmica.

Aquí vamos a presentar uno de los métodos más sencillos que existen para ordenar un vector, de modo que te resulte fácil entenderlo. Para aprender los métodos más complejos y rápidos ya tendrás tiempo en el futuro, ¿no te parece?

#### Ordenación mediante selección directa

La **selección directa** es probablemente el método de ordenación más fácil de entender porque es lo que la mayoría de nosotros haríamos si tuviéramos que ordenar un conjunto de elementos a mano. Esto no quiere decir que sea fácil de programar para un principiante, pero vamos a intentarlo.

Vamos a suponer que tratamos de ordenar un vector de números enteros de menor a mayor pero, como hemos dicho, la misma idea podría emplearse para ordenar cualquier otra cosa y mediante cualquier otro criterio.

El método de selección directa recorre el vector desde el principio hasta localizar el elemento más pequeño, guardando su posición y su valor en dos variables que llamaremos *posicion_minimo* y *valor_minimo*. Al terminar, coloca ese elemento mínimo en la primera posición del vector y lo intercambia con el elemento que antes ocupaba esa primera posición.

(Para hacer ese intercambio de valores, es necesario usar una variable auxiliar que llamaremos *aux*).

El proceso se repite, pero ahora desde la *segunda* posición del vector original. De nuevo volvemos a buscar el elemento más pequeño mirándolos todos de uno en uno. Al terminar, colocamos ese elemento mínimo en la *segunda* posición del vector, intercambiándola por el número que antes estaba en la segunda posición.

Volvemos a hacerlo, ahora desde la *tercera* posición del vector original, y así sucesivamente hasta terminar de recorrer el vector completo.

**Observa con detenimiento el código fuente de esta implementación**. No pases por él de puntillas para dedicarte a otra cosa. Dedica unos minutos para tratar de ejecutarlo *a mano*, es decir, con papel y lápiz, apuntando el valor de las variables para ver cómo actúa el algoritmo y cómo construye, pasada tras pasada, el vector ordenado.

```
Algoritmo seleccion_directa
	Definir i, j, aux Como Entero
	Definir valor_minimo, posicion_minimo Como Entero
	Definir vector Como Entero
	Dimensión vector[100]
	
	// Primero, vamos a llenar el vector_original con valores al azar entre 1 y 500, por ejemplo
	Para i desde 0 hasta 99 Hacer
		vector[i] <- azar(500)
	FinPara
	
	// Ahora empieza el algoritmo de ordenación por selección directa
	Para i desde 0 hasta 99 Hacer
		valor_minimo <- vector[i]
		posicion_minimo <- i
		Para j desde 0 hasta 99 Hacer
			Si vector[j] < valor_minimo Entonces
				valor_minimo <- vector[j]
				posicion_minimo <- j
			FinSi
		FinPara
		aux <- vector[i]
		vector[i] <- valor_minimo
		vector[posicion_minimo] <- aux
	FinPara
	
	// Por fin, escribimos el vector ordenado para ver que todo ha funcionado bien
	Para i desde 0 hasta 99 Hacer
		Escribir vector[i]
	FinPara
	
FinAlgoritmo
```

### 4.2.5. Búsqueda en vectores

En los vectores, como en todas las estructuras de datos que contienen muchos datos en su interior, también es habitual encontrarse con la **operación de búsqueda**.

Dado un vector y un dato cualquiera, la búsqueda consiste en determinar si ese dato está en alguna posición del vector y, si es necesario, averiguar cuál es esa posición.

La **búsqueda secuencial**, es decir, elemento a elemento, puede llegar a ser muy lenta si el vector es muy grande. Si en un programa tenemos que realizar búsquedas en vectores grandes repetidas veces, debemos pensar el modo de lograr que las búsquedas sean más rápidas.

Existe una forma muy simple de hacer una búsqueda en un vector de manera tremendamente rápid: con el método llamado **búsqueda binaria**. Pero la búsqueda binaria tiene un problema: para que funcione, el vector debe estar previamente ordenado. El proceso de ordenación, como acabamos de ver, es lento y costoso, pero, a cambio, obtendremos unos tiempos de búsqueda notablemente mejores.

Resumiendo: si necesitamos hacer búsquedas de datos en vectores en algún programa:

* Si las búsquedas se realizan pocas veces, o bien los vectores son pequeños, optaremos por la búsqueda secuencial, que no necesita ordenar previamente el vector.
* Si las busquedas se realizan muchas veces y los vectores son de gran tamaño, optaremos por la búsqueda binaria, pero antes debemos ordenar el vector.

#### Búsqueda secuencial

Consiste, simplemente, en **recorrer el vector desde el primer elemento hasta el último**. 

Si encontramos el dato buscado, podemos interrumpir la búsqueda. Si no, continuaremos hasta el final del vector.

Esta es una posible implementación en pseudocódigo, suponiendo que el vector tiene 100 elementos. Míralo despacio y ejecuta a mano el algoritmo. ¡Esas ejecuciones con lápiz y papel son un excelente ejercicio para los/las programadores/as principiantes!

```
  // Búsqueda secuencial
  // Buscamos el elemento "dato" en el vector "v"
  Definir i, posicion, v como Entero
  Dimension v[100]
  i <- 0
  posicion <- -1               // Si posición vale -1 significa que
                               // aún no hemos encontrado lo que buscamos
  
  Mientras i < 100 y posicion = -1 hacer
     Si v[i] = dato  Entonces  // ¡Lo hemos encontrado!
        posicion <- i         // Anotamos la posición
     FinSi
     i <- i + 1
  FinMientras

  Si posicion >= 0 Entonces
     Escribir "El dato ", dato, " estaba en la posición ", posicion
  SiNo
     Escribir "No he encontrado el dato ", dato, " en el vector"
  FinSi
```

#### Búsqueda binaria

Para que esta búsqueda funcione, como hemos dicho, **el vector debe estar previamente ordenado**.

El **método de búsqueda binaria** consiste en lo siguiente: 

* **Paso 1**. Supongamos que v es el vector y que contiene N elementos. Llamaremos *izq* a la posición del elemento izquierdo del array (inicialmente, izq = 0). Llamaremos *der* a la posición del elemento derecho del array (inicialmente, der = N-1)
* **Paso 2**. Tomamos un x igual al punto medio entre izq y der, es decir, x <- (izq/der) / 2
* **Paso 3**. Miramos el elemento v[x]. Si es el dato que buscábamos, ya hemos terminado. Si no, pueden ocurrir dos cosas:
   * **3a**. Que v[x] sea mayor que el dato que buscábamos. En ese caso, y dado que el array está ordenado, continuamos la búsqueda a la izquierda de x, haciendo que der <- x.
   * **3b**. Que v[x] sea menor que el dato que buscábamos. En ese caso, continuamos la busqueda a la derecha de x, haciendo izq <- x.
* **Paso 4**. Repetimos desde el paso 2 hasta que encontremos el elemento buscado o hasta que izq = der (lo que significará que el elemento no está en el vector)

Esta es una posible implementación en pseudocódigo. Recuerda: no mires el código por encima para pasar a otra cosa. Léelo con calma, como si fueran las instrucciones para montar un mueble de Ikea, y ejecútalo con lápiz y papel hasta que te asegures de que entiendes cómo funciona.

```
// Búsqueda binaria.
// Buscamos el elemento "busc" en el vector "v", que debe estar previamente ordenado de menor a mayor.
// Supondremos que "v" es un vector de enteros de 100 elementos, por ejemplo.

   Definir izq, der, mitad, encontrado como Entero

   // Iniciamos una búsqueda binaria
   encontrado <- 0
   izq <- 0    // Primera posición del vector
   der <- 99   // Última posición del vector

   Mientras izq < der-1 y encontrado = 0 Hacer
      mitad <- izq + ((der - izq) / 2)    // Calculamos la posición "mitad"
      Si v[mitad] = busc Entonces
         // ¡Lo hemos encontrado!
         encontrado <- 1
      FinSi
      Si v[mitad] > busc Entonces
         // Seguiremos buscando por la mitad izquierda
         der <- mitad
      FinSi
      Si v[mitad] < busc Entonces
         // Seguiremos buscando por la mitad derecha
         izq <- mitad
   FinMientras

   Si encontrado = 1 Entonces
      Escribir "El dato ", busc, " está en la posición ", encontrado, " del vector"
   SiNo
      Escribir "El dato ", busc, " no está en el vector"
   FinSi
```

Este algoritmo de búsqueda es más complejo que el secuencial, como puede verse, pero los tiempos de búsqueda con el método binario son mucho más pequeños.

Para un vector de N elementos, el método secuencial necesita un promedio de N/2 pasos para localizar el elemento buscado, mientras que el método binario tarda una media de log<sub>2</sub>N pasos. 

¿No te parece una diferencia muy impresionante? Fíjate en estos datos:

* Si el vector es pequeño (por ejemplo, N = 10):
   * a. La búsqueda secuencial necesita una media de 5 pasos.
   * b. La búsqueda binaria necesita una media de 3 pasos.
* Si el vector es mediano (por ejemplo, N = 100):
   * a. La búsqueda secuencial necesita una media de 50 pasos.
   * b. La búsqueda binaria necesita una media de 6 ó 7 pasos.
* Si el vector es grande (por ejemplo, N = 1000), la mejora de tiempo empieza a ser notable:
   * a. La búsqueda secuencial necesita una media de 500 pasos.
   * b. La búsqueda binaria necesita una media de… ¡10 pasos!
* Si el vector es muy grande (por ejemplo, N = 100.000), la mejora de tiempo es aún mayor:
   * a. La búsqueda secuencial necesita una media de 50.000 pasos.
   * b. La búsqueda binaria necesita una media de sólo 16 pasos.

La mejora en el tiempo de búsqueda es, por lo tanto, mayor cuanto mayor es el vector. Por eso dijimos que la búsqueda binaria se emplea cuando los vectores son muy grandes.


## 4.3. Arrays bidimiensionales (matrices)

Una **matriz**, **tabla** o **array bidimiensional**, igual que un vector, es una colección de elementos individuales, todos del mismo tipo, agrupados bajo el mismo identificador. 

La diferencia con el vector es que, en el momento de declararlo y de acceder a cada elemento individual, debemos utilizar **dos índices** en lugar de uno.

Una matriz de, por ejemplo, 4x4 elementos, se declara así:

```
Definir matriz como Entero
Dimension matriz[4][4]
```

La variable *matriz* no consta de 4 elementos enteros, sino de 16, organizados en 4 filas y 4 columnas. Podemos representar gráficamente la matriz como una tabla:

<pre>
     Filas
       |
       V
     +----+----+----+----+----+
     |    |  0 |  1 |  2 |  3 |   <-- Columnas
     +----+----+----+----+----+
     |  0 |    |    |    |    |
     +----+----+----+----+----+
     |  1 |    |    |    |    |
     +----+----+----+----+----+
     |  2 |    |    |    |    |
     +----+----+----+----+----+
     |  3 |    |    |    |    |
     +----+----+----+----+----+
</pre>

**Cada casilla de la matriz es identificable mediante una pareja de índices**. Normalmente, el primero de los índices se refiere a la fila y, el segundo, a la columna. 

Por ejemplo, si hacemos estas asignaciones:

```
matriz[0][0] <- 5
matriz[1][0] <- 1
matriz[3][2] <- 13
```

...el estado en el que quedará la matriz anterior será este:

<pre>
     Filas
       |
       V
     +----+----+----+----+----+
     |    |  0 |  1 |  2 |  3 |   <-- Columnas
     +----+----+----+----+----+
     |  0 |  5 |    |    |    |
     +----+----+----+----+----+
     |  1 |  1 |    |    |    |
     +----+----+----+----+----+
     |  2 |    |    |    |    |
     +----+----+----+----+----+
     |  3 |    |    | 13 |    |
     +----+----+----+----+----+
</pre>

Por descontado, los dos tamaños de la matriz pueden ser diferentes, obteniéndose tablas que son más anchas que altas o más altas que anchas.

Por lo demás, **las matrices se utilizan exactamente igual que los vectores**. A modo de ejemplo, este sería el código para inicializar una matriz de 5x10 enteros con todos sus elementos a 0. Observa cómo se usan los dos bucles anidados para acceder a todos los elementos:

```
Definir i, j como Entero
Definir m como Entero
Dimension m[5][10]

Para i <- 0 hasta 4 hacer
   Para j <- 0 hasta 9 hacer
       m[i][j] <- 0
   FinPara
FinPara
```

## 4.4. Arrays de múltiples dimensiones

Del mismo modo que a los arrays unidimensionales (vectores) se les puede añadir un segundo índice, obteniendo las matrices, se puede generalizar esta práctica, dando lugar a **arrays multidimensionales**. 

Por ejemplo, el siguiente es un array de cinco dimensiones compuesto de números enteros:

```
Definir ejemplo como Entero
Dimension ejemplo[10][10][4][5][7];
```

Estos arrays no se pueden representar gráficamente (aunque con los de tres dimensiones se puede intentar dibujar un cubo), pero su utilización es idéntica a la de los arrays de una o dos dimensiones.

## 4.5. Programación modular: subalgoritmos

Los algoritmos tienden a hacerse muy grandes cuando tratamos de resolver un problema complejo. Esto es lógico, ¿no te parece? Cuanto más complicado sea el problema, más difícil y largo será plantear su solución.

Para enfrentar este hecho inevitable existe la **programación modular**. Consiste en algo tan simple como dividir el problema en subproblemas más sencillos, y estos a su vez en otros más sencillos, hasta que tengamos un conjunto de mucho problemas pequeñitos que sí podemos resolver individualmente de forma simple. Después, solo nos queda unir todas las piezas del puzle para obtener nuestra solución compleja.

Cada una de esas soluciones a pequeños problemas se denomina **subalgoritmo** (no es un nombre muy original, lo sé). Y esta técnica de descomposición sucesiva en problemas complejos en subproblemas simples se conoce como **divide y vencerás** (*divide and conquer*, en inglés). Es muy útil no solo en programación, sino en la mayor parte de los problemas del mundo real.

### 4.5.1. Algoritmo principal y subalgoritmos

El problema principal siempre se resuelve en un algoritmo que denominaremos **algoritmo principal**. Este es el que hará de "pegamento" del puzle.

Los subproblemas más sencillos se resolverán en **subalgoritmos**, también llamados **módulos** a secas. Los subalgoritmos están subordinados al algoritmo principal, de manera que éste es el que decide cuándo debe ejecutarse cada subalgoritmo y con qué conjunto de datos.

El algoritmo principal realiza **llamadas** o **invocaciones** a los subalgoritmos, mientras que estos le devuelven resultados. Así, el algoritmo principal va recogiendo todos los resultados y puede generar la solución al problema global.

Cuando el algoritmo principal hace una llamada al subalgoritmo (es decir, lo invoca), se empiezan a ejecutar las instrucciones del subalgoritmo. Cuando este termina, la ejecución continúa por la instrucción siguiente a la de invocación. También se dice que el subalgoritmo devuelve el control al algoritmo principal, ya que éste toma de nuevo el control del flujo de instrucciones después de habérselo cedido temporalmente al subalgoritmo.

El programa principal puede invocar a cada subalgoritmo el número de veces que sea necesario. A su vez, cada subalgoritmo puede invocar a otros subalgoritmos, y éstos a otros, etc. Cada subalgoritmo devolverá el control al algoritmo que lo invocó.

Lógicamente, **los subalgoritmos deben tener asignado un nombre** para que puedan ser invocados desde el algoritmo principal. Ahora bien, la forma de declarar un subalgoritmo varía ligeramente según el tipo de subalgoritmo de que se trate. Porque existen dos tipos de subalgoritmo, llamados **funciones** y **procedimientos**, que vamos a ver enseguida.

### 4.5.2. Funciones

Las **funciones** son subalgoritmos que resuelven un problema sencillo y **devuelven un resultado** al algoritmo que las invoca. Esto último es lo que las distingue de los procedimientos.

Las funciones pueden tener argumentos, aunque no es obligatorio. Los **argumentos** son los datos que se proporcionan a la función en la invocación, y que la función utilizará para sus cálculos.

Las funciones tienen, obligatoriamente, que devolver un resultado. Si no lo hacen, no son funciones. Este resultado suele almacenarse en una variable para usarlo posteriormente.

Veamos un ejemplo. Nuevamente, emplearemos la sintaxis del pseudocódigo de PSeInt, pero cualquier otro pseudocódigo o lenguaje de programación real utilizará una sintaxis semejante.

Supongamos que tenemos estamos escribiendo un programa para calcular los precios de unos artículos a la venta en una tienda. Vamos a escribir un subalgoritmo que se encargue de calcular el IVA de cada artículo.

```
Algoritmo precios
	Definir nombre como cadena
	Definir precio como real
	Definir precio_con_iva como real
	
	Repetir
	Escribir "Dime el nombre de otro artículo:"
		Leer nombre
		Escribir "Dime su precio (negativo para terminar):"
		Leer precio
		precio_con_iva <- precio + calcular_iva(precio)
		Escribir "El precio con IVA es ", precio_con_iva
	Hasta Que precio < 0
FinAlgoritmo

SubAlgoritmo iva <- calcular_iva(precio)
	Definir porcentaje como real
	Definir iva como real
	iva <-  precio * 0.21   // Suponemos que el IVA es el 21%
FinSubalgoritmo
```

En este ejemplo puedes ver cómo **se declara un subalgoritmo**:

* Se utiliza la palabra **SubAlgoritmo**
* Se indica a continuación cuál es el dato que devolverá al algoritmo principal (en este caso, la variable *iva*)
* Luego se indica su nombre, *calcular_iva* y, entre paréntesis, los datos que recibirá del algoritmo principal (en este ejemplo, *precio*). Esos datos se denominan *parámetros* del subalgoritmo.
* Después se escribe el código del subalgoritmo. Fíjate en que es un código completamente normal, como el de cualquier algoritmo.

Los lenguajes de programación, de hecho, poseen un puñado de funciones predefinidas de las que ya hemos usado unas cuántas. ¿Recuerdas cuando usabas las funciones azar(), truncar() o redondear()? No son más que funciones, es decir, subalgoritmos, que ya vienen incorporados al lenguaje de programación.

### 4.5.3.  Procedimientos

Los **procedimientos** son subalgoritmos que no devuelven ningún valor al algoritmo principal. Es decir, sin como las funciones, pero no devuelven ninguna variable al terminar.

La declaración de un procedimiento es similar a la de una función. Lo vemos en este ejemplo, sacado el juego de las 3 en raya del tema anterior. Si repasas aquel ejercicio resuelto, verás que está lleno de procedimientos.

```
Algoritmo tres_en_raya
	Definir tablero Como Caracter
	Dimension tablero[10]
	
	inicializar(tablero)
	mostrar(tablero)
   // Etc (el juego de las tres en raya continuaba a partir de aquí)
FinAlgoritmo

SubAlgoritmo inicializar(tablero por referencia) 
	Definir i como entero
	Para i <- 1 hasta 9 Hacer
		tablero[i] <- " "
	FinPara
FinSubAlgoritmo

SubAlgoritmo mostrar(tablero)
	Escribir "ESTADO ACTUAL DEL TABLERO"
	Escribir "+---+---+---+"
	Escribir "| ",tablero[1]," | ",tablero[2]," | ",tablero[3]," |"
	Escribir "+---+---+---+"
	Escribir "| ",tablero[4]," | ",tablero[5]," | ",tablero[6]," |"
	Escribir "+---+---+---+"
	Escribir "| ",tablero[7]," | ",tablero[8]," | ",tablero[9]," |"
	Escribir "+---+---+---+"	
FinSubAlgoritmo
```

Este algoritmo principal invoca a dos procedimientos: uno, llamado *inicializar()*, se encarga de poner un espacio en blanco en cada posición del tablero. Otro, llamado *mostrar()*, se encarga de dibujar el tablero en la pantalla. Como ves, cada subalgoritmo tiene el encargo de resolver una pequeña parte del problema global.

Fíjate en que la declaración de los procedimientos es idéntica a la de las funciones, pero sin devolver ninguna variable.

### 4.5.4. Invocación de subalgoritmos

Para que las instrucciones escritas en un subalgoritmo sean ejecutadas es necesario, como ya hemos dicho, que el subalgoritmo se *llame* o *invoque* desde otro algoritmo.

La invocación consiste en una mención al **nombre del subalgoritmo** seguida, entre paréntesis, de los **valores que se desan asignar a los parámetros**. Deben aparecer tantos valores como parámetros tenga el subalgoritmo, y además coincidir en el tipo de datos. 

Estos parámetros se podrán utilizar, dentro del subalgoritmo, como cualquier otra variable.

Como las funciones devuelven valores, la **invocación de una función** debe aparecer a la derecha de una **instrucción de asignación**:

```
precio_con_iva <- precio + calcular_iva(precio)
```

En cambio, como los procedimientos no devuelven ningún valor, la **invocación de un procedimiento** nunca aparece en una instrucción de asignación:

```
inicializar(tablero)
mostrar(tablero)
```

### 4.5.5. Paso de parámetros

El paso de parámetros, o comunicación de datos del algoritmo invocante al subalgoritmo invocado, puede hacerse mediante, al menos, dos métodos:

* **Paso de parámetros por valor**, que es la forma más sencilla pero no permite al subalgoritmo devolver resultados en los parámetros.
* **Paso de parámetros por referencia**, que es más complejo pero permite a los subalgoritmos devolver resultados en los parámetros.

Veamos cada método detenidamente.

#### Paso de parámetros por valor

Los subalgoritmos, como hemos visto, pueden tener una serie de parámetros en su declaración. Estos parámetros se denominan **parámetros formales**.

Por ejemplo, imaginemos un subalgoritmo llamado *potencia()* que calcula la potencia de dos números enteros que llamaremos *base* y *exponente*. Ese subalgoritmo se declararía así:

```
SubAlgoritmo potencia(base, exponente)
```

En esta declaración, *base* y *exponente* son los **parámetros formales**.

Cuando el subalgoritmo es invocado, se le pasan entre paréntesis los valores de los parámetros. A éstos se les denomina **parámetros actuales**; por ejemplo:

```
a <- 5
b <- 3
potencia(a,b)
```

En esta invocación de la función potencia(), los **parámetros actuales** son a y b, es decir, 5 y 3.

Al invocar un subalgritmo, *los parámetros actuales son asignados a los parámetros formales en el mismo orden en el que fueron escritos*. 

Dentro del subalgoritmo, los parámetros se pueden utilizar como si fueran variables. Así, en el ejemplo anterior, dentro de la función *potencia()*, el parámetro *base* puede usarse como una variable a la que se hubiera asignado el valor 5, mientras que *exponente* es como una variable a la que se hubiera asignado el valor 3.

Cuando el subalgoritmo termina de ejecutarse, sus parámetros formales base y exponente **dejan de existir**.

#### Paso de parámetros por referencia

En el paso de parámetros por referencia se produce una **ligadura entre el parámetro actual y el parámetro formal**, de modo que si el parámetro formal se modifica dentro del subalgoritmo, *el parámetro actual, propio del algoritmo principal, también será modificado*.

Los argumentos siempre se pasan por valor excepto cuando indiquemos explícitamente que el paso es por referencia colocando el símbolo.

Por ejemplo:

```
SubAlgoritmo potencia(base, exponente, resultado por referencia)
   resultado = base ^ exponente
FinSubAlgoritmo
```

Observa cómo el parámetro *resultado* está pasado por referencia. Ahora veamos cómo se invoca a este subalgoritmo:

```
a <- 5
b <- 3
c <- 0
potencia(a, b, c)
```

En este caso, pasamos tres parámetros actuales, ya que el subalgoritmo tiene tres parámetros formales. El tercero de ellos, llamado c, se pasa por referencia, y por lo tanto queda ligado al parámetro formal *resultado*.

El parámetro formal es modificado en la instrucción ```resutado = base ^ exponente```, y como está ligado con el parámetro actual c, el valor de la variable c también se modifica. Por lo tanto, c toma el valor 125.

Cuando el subalgoritmo termina de ejecutarse, dejan de existir todos sus parámetros formales (base, exponente y resultado), *pero la ligadura de resultado con la variable c hace que esta variable conserve el valor 125* incluso cuando el parámetro resultado ya no exista.

### 4.5.6. Ámbito de las variables

#### Variables locales

Se llama **ámbito de una variable** a la parte de un programa donde dicha variable puede utilizarse.

En la mayoría de los lenguajes, las variables declaradas en un algoritmo son **locales** a ese algoritmo, es decir, no existen fuera del algoritmo y, por tanto, no pueden utilizarse más allá de sus fronteras.

Cuando el algoritmo comienza, las variables se crean, reservándose un espacio en la memoria RAM del ordenador para almacenar su valor. Cuando el algoritmo termina, todas sus variables se destruyen, liberándose el espacio en la memoria RAM.

Todos los resultados que un algoritmo obtenga durante su ejecución, por lo tanto, se perderán al finalizar, salvo que sean devueltos al algoritmo que lo invocó o sean dirigidos a algún dispositivo de salida (como la pantalla).

#### Variables globales

En ocasiones, es conveniente utilizar variables cuyo ámbito exceda el del algoritmo donde se definen y puedan utilizarse en varios algoritmos y subalgoritmos. Esas variables se denominan **globales**.

Las variables globales son bombas de relojería en potencia. Pueden paracer objetos atractivos y útiles a primera vista, pero antes o después te explotarán en la cara. Si alguna vez sientes la tentación de usar variables globales para algo, es mejor que te sientes y esperes a que se te pasen.

Si, aún así, estás convencido/a de que necesitas usar alguna variable global, debes saber que todos los lenguajes proporcionan algún mecanismo para crearlas, generalmente indicando durante su declaración que esa variable es de ámbito global.

### 4.5.7. Reutilización de código

El diseño de un algoritmo mediante divide y vencerás tiene, además de la ventaja evidente de poder afrontar problemas de gran tamaño, otra ventaja adicional: la posibilidad de **reutilizar subalgoritmos previamente escritos**. 

Es habitual que, una vez resuelto un problema sencillo mediante una función o un procedimiento, ese mismo problema, o uno muy parecido, se nos presente más adelante, durante la realización de otro programa. Entonces nos bastará con volver a utilizar esa función o procedimiento, sin necesidad de volver a escribirlo.

Es por esto, entre otras razones, que **los subalgoritmos deben ser lo más independientes y autónomos posible**.

Es habitual agrupar varios subalgoritmos relacionados (por ejemplo: varios algoritmos que realicen diferentes operaciones matemáticas) en un mismo archivo, formando lo que se denomina una **biblioteca** (*libraries*, en inglés). Cada lenguaje trata las bibliotecas de manera distinta.

Por último, señalemos que, para reutilizar con éxito el código, es importante que esté bien documentado. En concreto, en cada algoritmo deberíamos documentar claramente:

* La función del algoritmo, es decir, explicar qué hace
* Los parámetros de entrada, si los hay
* Los datos de salida, es decir, el resultado que devuelve o la forma de utilizar los parámetros por referencia

## 4.6. El estilo de escritura

No podemos finalizar estos temas de introducción sin referirnos a algunas **reglas de estilo básicas** que deben observarse a la hora de escribir código fuente. Y es que la escritura de un algoritmo debe ser siempre lo más clara posible, ya se esté escribiendo en pseudocódigo o en un lenguaje de programación real.

La razón es evidente: los algoritmos pueden llegar a ser muy complejos, y si a su complejidad le añadimos una escritura sucia y desordenada, se volverán ininteligibles.

Todos los programadores han experimentado la frustración que se siente al ir a revisar un algoritmo redactado pocos días antes y no entender ni una palabra de lo que uno mismo escribió.

Por esta razón, y ya desde el principio, debemos acostumbrarnos a respetar ciertas reglas básicas en cuanto al estilo de escritura. Por supuesto, un programa puede funcionar correctamente sin aplicar ninguna de las cosas que vamos a mencionar aquí, pero no es a la corrección a lo que nos referimos ahora, sino al estilo. 

### 4.6.1. Partes de un algoritmo

Los algoritmos deberían tener siempre una estructura en tres partes:

1. Cabecera: contiene el nombre del programa o algoritmo.
2. Declaraciones: contiene la declaración de las variables.
3. Acciones: contiene las instrucciones del algoritmo.

### 4.6.2. Documentación

La expresión "documentación de un programa" se refiere, en realidad, a dos tipos muy distintos de documentación:
    
* La **documentación externa**, formada por todos los documentos ajenos al programa: guías de instalación, guías de usuario, manuales de referencia, manuales técnicos, etc.
* La **documentación interna** es la que se incluye en el propio código programa. Está formada por los comentarios del código fuente.

Los **comentarios** del código fuente deben ser significativos.

Se dice que el código fuente perfecto es aquel que no necesita ningún comentario adicional, porque se explica suficientemente bien a sí mismo y puede leerse sin necesidad de aclaraciones adicionales. 

Esto es un escenario utópico que nunca se da en la realidad, pero debemos programar con la vista puesta en él. Nuestro código debe ser lo más claro y autoexplicativo posible. Cuando no lo logremos, debemos acompañarlo de comentarios que expliquen lo que el código hace y faciliten su comprensión y mantenimiento posterior.

Cada algoritmo, además, debería ir precedido de un comentario que explique lo que ese algoritmo hace. En los subalgoritmos, además, deberían añadirse a ese comentario otros que indiquen cuales son los parámetros de entrada (si existen) y cual es el valor devuelto (si es el caso).

En PSeInt, los comentarios se escriben con una doble barra inclinada (//) al comienzo del mismo. Cada lenguaje de programación tiene su propio estilo de comentarios y deberás curiosear un poco en los manuales para averiguarlo cuando vayas a programar en un lenguaje de programación nuevo.

### 4.6.3. Convenciones de escritura

Se considera una buena práctica de programación seguir ciertas normas de escritura en el código fuente.

Del mismo modo que al escribir en lenguaje natural no solo respetamos la ortografía y la sintaxis (o, al menos, deberíamos hacerlo), sino que también usamos signos de puntuación, dejamos márgenes a ambos lados y procuramos no hacer tachones para que el texto luzca bien y sea cómodo de leer (o, al menos, también deberíamos hacerlo), al escribir en un lenguaje de programación hay ciertas convenciones que no son imprescindibles pero sí muy recomendables.

#### Sangrías

Las instrucciones que aparezcan dentro de un bloque deben tener una sangría mayor que las de apertura y cierre de ese bloque. 

Por ejemplo, las instrucciones que hay dentro de un bucle ```Mientras ... FinMientras``` deberían estar más sangradas que las propias instrucciones ```Mientras``` y ```FinMientras```:

```
Mientras condición hacer
   Instrucción 1
   Instrucción 2
   ...
   Instrucción N
FinMientras
```

Esto es aplicable a cualquier bloque: ```Algoritmo ... FinAlgoritmo```, ```Para ... FinPara```, ```Si ... SiNo ... FinSi```, etc. En particular, este último caso, que puede llevar un bloque ```SiNo``` de forma optativa, se escribe así (fíjate bien en la sangría izquierda):

```
Si condición Entonces
   Instrucciones
SiNo
   Otras Instrucciones
FinSi
```

Si hay un bloque anidado dentro de otro, el bloque más interno se sangrará aún más que el bloque precedente. Por ejemplo:

```
Mientras i < 10 Hacer
   Leer n
   Si n > 0 Entonces
      i <- i + n
   SiNo
      i <- i - n
   FinSi
FinMientras
```

#### Espacios

Algo que aumenta la legibilidad del código es **espaciar suficientemente** (pero no demasiado) los distintos elementos de cada instrucción. Por ejemplo, esta instrucción ya es bastante complicada y difícil de leer:

```
si (a > b) y (c > d * raiz(k) ) entonces a <- k + 5.7 * b
```

Pero se lee mucho mejor que esta otra, en la que se han suprimido los espacios (excepto los imprescindibles):

```
si (a>b)y(c>d*raiz(k))entonces a<-k+5.7*b
```

Al ordenador le dará igual si escribimos ```(a > b)``` o ```(a>b)```, pero a cualquier programador que deba leer nuestro código le resultará mucho más cómoda la primera forma.

Por la misma razón, también es conveniente dejar líneas en blanco entre determinadas instrucciones del algoritmo cuando se considere que mejora la legibilidad.

#### Identificadores

A la hora de elegir identificadores de variables (o de algoritmos y subalgoritmos) es muy importante utilizar **nombres que sean significativos**, es decir, que den una idea de la información que almacena esa variable.

Por ejemplo, si en un programa de nóminas vamos a guardar en una variable la edad de los empleados, es una buena ocurrencia llamar a esa variable "edad", pero no llamarla "x", "a" o "cosa".

Ahora bien, dentro de esta política de elegir identificadores significativos, es conveniente optar por aquellos que sean lo más cortos posible, siempre que sean descifrables. Un identificador llamado "edad_de_los_empleados" es engorroso de escribir y leer, sobre todo si aparece muchas veces en el algoritmo, cuando probablemente "edad_empl" proporciona la misma información. Sin embargo, si lo acortamos demasiado (por ejemplo "ed_em") llegará un momento en el no quede claro lo que significa.

Toda esta idea de significación de los identificadores es extensible a los nombres de los algoritmos, de las funciones, de los procedimientos, de los archivos y, en general, de todos los objetos relacionados con un programa.

Por último, señalar que muchos lenguajes de programación distinguen entre mayúsculas y minúsculas, es decir, que para ellos no es lo mismo el identificador "edad" que "Edad" o "EDAD". Por convenio, los algoritmos suelen nombrarse con la primera letra en mayúscula y el resto en minúsculas, mientras que las variables y funciones suelen nombrarse con la todas las letras en minúscula.

Excepción: si el identificador consta de más de una palabra. En ese caso, ¿cómo es conveniente escribirlo? Existen dos convenciones para eso:

* **CamelCase**: si el identificador consta de más de una palabra, se escriben todas juntas y la primera letra de cada palabra se escribe en mayúsculas. Por ejemplo: ```edadEmpleado```.
* **snake_case**: si el identificador consta de más de una palabra, se escriben separadas por el signo de subrayado (_). Por ejemplo: ```edad_empleado```.

Elegir CamelCase o snake_case es una cuestión de gustos personales. Lo importante es que, optes por el estilo que optes, lo utilices siempre y no mezcles identificadores de un tipo con identificadores de otro.

## 4.6. Ejercicios propuestos

Resuelve los siguientes ejercicios utilizando subalgoritmos cuando la complejidad del problema así lo requiera. Puedes hacerlo con todos, excepto los números 1, 2, 7 y 8, que son tan simples que difícilmente podrás sacar un subalgoritmo de ellos.

#### Ejercicios de vectores (arrays unidimensionales)

**Ejercicio 1: Inicializar un vector**. Escribe un programa en pseudocódigo en el que se defina un vector de 100 números enteros, se inicialicen todos los elementos al valor –1 y se impriman por pantalla.

**Ejercicio 2: Inicializar un vector (más complejo)**. Define dos vectores de 100 números enteros, uno llamado *pares* y otro *impares*. Inicializa el primero con los 100 primeros números pares positivos (es decir, pares[0] contendrá el valor 2, pares[1] contendrá el valor 4, pares[2] contendrá el valor 6, y así sucesivamente). Inicializa el segundo con los 100 primeros números impares positivos. Imprímelo por pantalla para comprobar que lo has hecho correctamente.

**Ejercicio 3: Lotería primitiva**. Escribe un programa que genere al azar una combinación para jugar a la lotería primitiva asegurándote de que ningún número se repite. Pista: puedes utilizar un array de 6 números enteros, asignando a cada posición un número entero aleatorio entre 1 y 49, y comprobando que el número asignado no es igual a ninguno de los asignados anteriormente.

**Ejercicio 4. Estadística básica**. Escribe un programa que pida al usuario N números enteros (siendo N un valor introducido por teclado) y calcule el valor medio de todos ellos, mostrando luego en la pantalla los números que están por encima de la media y los que están por debajo de ella.

**Ejercicio 5. Ordenar vector gigante**. Escribe un programa que defina un vector de 1000 elementos y lo inicialice con valores aleatorios entre 0 y 2.000.000. Posteriormente, el programa debe ordenar los elementos del array de menor a mayor. Prueba luego a cambiar el tamaño del vector hasta los 10.000, 100.000 y 1.000.000 de elementos. ¿El tiempo de respuesta del programa crece linealmente con el tamaño del vector?

**Ejercicio 6. Vector creciente**. Escribe un programa que defina un vector de 10 enteros y lo rellene con números CRECIENTES al azar entre 1 y 100. Es decir, los números serán elegidos aleatoriamente pero siempre tienen que ser mayores que los anteriores: el número que ocupe la posición 1 debe ser mayor que el de la posición 0, el de la posición 2 mayor que el de la 1, y así sucesivamente.

Después de eso, se pedirá al usuario un número entre 1 y el número mayor que exista en el vector. El número introducido por el usuario se insertará en la posición del vector adecuada para conservar el orden, desplazando los demás elementos hacia la derecha, de manera que se pierda el último elemento.

Después de insertar el número introducido por el usuario, el contenido del vector debe mostrarse por la pantalla. El proceso se repetirá hasta que el usuario introduzca un número negativo.

Por ejemplo, supongamos que el array generado al azar por el ordenador, después de ordenarlo, es este:

<pre>
     4 – 18 – 23 – 25 – 44 - 45 – 51 – 72 – 78 - 85
</pre>

Como el número más alto es 85, el programa debe pedir al usuario:

<pre>
     Introduzca un número entre 1 y 85: _
</pre>

Si el usuario teclea, por ejemplo, el número 67, éste debe ser insertado en la posición adecuada para conservar el orden, es decir, entre los números 51 y 72, desplazando a los demás números hacia la derecha, con lo cual se pierde el mayor de todos ellos (85). El vector quedaría así:

<pre>
    4 – 18 – 23 – 25 – 44 - 45 – 51 – 67 - 72 – 78
</pre>


#### Ejercicios de matrices (arrays bidimensionales)

**Ejercicio 7. Inicializar matriz simple**. Escribe un programa en el que se defina una matriz de 10x10 números enteros. Inicializa todos los elementos al valor –1.

**Ejercicio 8. Inicializar matriz complejo**. Repite el ejercicio anterior, inicializando ahora todas las filas pares al valor 0 y todas las filas impares al valor –1.

**Ejercicio 9. Sumar filas**. Escribe un programa que defina una matriz de 6x3 números enteros y luego pida al usuario que introduzca los valores de cada elemento. Después, el programa debe sumar los tres números de cada fila, mostrando los resultados.

**Ejercicio 10. Permutar filas**. Escribe un programa que defina una matriz de 3x5 números enteros y luego pida al usuario que introduzca los valores de cada elemento. Después, debe permutar el contenido de la fila 3 por el de la fila 1, y mostrar por último el contenido de la matriz.

**Ejercicio 11. Sumar matrices**. Escribe un programa que defina dos matrices de 10x5 números enteros y las inicialice con números aleatorios entre 0 y 255. Posteriormente, cada elemento de la primera matriz debe ser sumado con el mismo elemento de la segunda matriz, guardando el resultado en una tercera matriz. Se deben sumar todas las parejas de elementos y mostrar el resultado en la pantalla.

**Ejercicio 12. Jugueteando con matrices**. Escribe un programa que genere al azar una matriz cuadrada de NxN números enteros (siendo N un valor introducido por el usuario) y que luego haga lo siguiente:

* *Mostrar*. Mostrará la matriz tal y como ha sido generada.

* *Perímetro*. Mostrará los elementos que ocupan el borde de la matriz, partiendo de la esquina superior izquierda y recorriéndola hacia la derecha y luego hacia abajo.

* *Centro*. Mostrará los elementos que ocupan el centro geométrico de la matriz. Puede ser 1 (si N es impar) o 4 (si N es par).

* *Espiral*. Hará un recorrido en espiral por la matriz partiendo de la esquina superior izquierda.

Por ejemplo, si la matriz fuera de 4x4 y tuviera este contenido:

<pre>
    4 6 7 8
    2 4 3 9
    0 1 3 4
    7 3 3 5
</pre>

...las distintas operaciones deben obtener este resultado:

* Perímetro: 4 6 7 8 9 4 5 3 3 7 0 2
* Centro: 4 3 1 3
* Espiral: 4 6 7 8 9 4 5 3 3 7 0 2 4 3 3 1

## 4.7. Ejercicios resueltos

(Iremos poniendo aquí los ejercicios resueltos en clase)