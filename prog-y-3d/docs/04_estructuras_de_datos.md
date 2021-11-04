---
layout: page
title: 4. Estructuras de datos
permalink: /estructuras-de-datos/
nav_order: 4
has_children: true
parent: Introd. a la prog. y al diseño 3D
---

# 4. Estructuras de datos
{: .no_toc }

- TOC
{:toc}

Hasta ahora, hemos conocido las estructuras de control básicas de cualquier programa estructurado: secuencia, condición e iteración.

Pero los programas no se componen solo de *instrucciones*, sino también de *datos*.

Todos los datos que hemos manejado hasta ahora eran simples, es decir, se almacenaban en variables en las que solo podíamos guardar un valor en cada momento. Las variables simples se nos quedan cortas en muchas ocasiones (repasa el programa de las 3 en raya, sin ir más lejos, para comprobarlo). En esos casos necesitamos una variable de tipo complejo o *estructura de datos*.

En este capítulo hablaremos de las estructuras de datos y nos centraremos en la más utilizada con diferencia: el *array*. 

Después, introduciremos los conceptos de subalgoritmo, función y biblioteca de funciones, para terminar hablando de uno de los principios básicos de la ingeniería del software: la reutilización del código.

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

La declaración de un vector en pseudocódigo (seguiremos usando la sintaxis de PSeInt) se hace así:

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
   
### 4.2.2. Operaciones con vectores

#### Manipulación de elementos individuales

XXX Los arrays unidimensionales en Java pueden manipularse elemento a elemento. No se pueden modificar todos los elementos a la vez.
Para asignar valores a los elementos de un array, por lo tanto, el mecanismo es este:
int[] serie = new int[5];
serie[0] = 5;
serie[1] = 3;
serie[2] = 7;
...etc...
La inicialización de los valores de un array también puede hacerse conjuntamente en el momento de declararlo, así:
int serie[] = {5, 3, 7, 9, 14};
El resultado de esta declaración será un array de 5 elementos de tipo entero a los que se les asigna estos valores:
0
1
2
3
4
5
3
7
9
14
Cada elemento del array es, a todos los efectos, una variable que puede usarse independientemente de los demás elementos. Así, por ejemplo, un elemento del array serie puede usarse en una instrucción de salida igual que cualquier variable simple de tipo int:
int[] serie = new int[5];
serie[0] = 21;
System.out.println(serie[0]);
Del mismo modo, pueden usarse elementos de array en una instrucción de entrada. Por ejemplo:
int[] serie = new int[5];
serie[0] = Integer.parseInt(System.console().readLine());
serie[1] = serie[0] + 15;
System.out.println(serie[1]);
2.2.2   Recorrido de un array
Una forma muy habitual de manipular un array es accediendo secuencialmente a todos sus elementos, uno tras otro. Para ello, se utiliza un bucle con contador, de modo que la variable contador nos sirve como índice para acceder a cada uno de los elementos del array.
Supongamos, por ejemplo, que tenemos un array de 10 números enteros declarado llamado v, y una variable entera llamada i. Por medio de un bucle, con ligeras modificaciones, podemos realizar todas estas operaciones:
    1) Inicializar todos los elementos a un valor cualquiera (por ejemplo, 0):
for (i = 0; i <= 9; i++)
{
   v[i] = 0;
}
    2) Inicializar todos los elementos con valores introducidos por teclado:
for (i = 0; i <= 9; i++)
{
   printf("Escriba el valor del elemento nº %i: ", i);
   v[i] = Integer.parseInt(System.console().readLine());
}
    3) Mostrar todos los elementos en la pantalla:
for (i = 0; i <= 9; i++)
{
   System.out.println("El elemento nº " + i + " vale " + v[i]);
}
    4) Realizar alguna operación que implique a todos los elementos. Por ejemplo, sumarlos:
suma = 0;
for (i = 0; i <= 9; i++)
{
   suma = suma + v[i];
}
2.2.3   Ordenación de arrays unidimensionales
Otra operación típica que se realiza con arays unidimensionales es ordenar sus elementos mediante algún criterio. Por ejemplo, un array de números enteros puede ordenarse de menor a mayor. Si el array original es este:
0
1
2
3
4
5
3
14
9
8
...después de la ordenación nos quedará este otro array:
0
1
2
3
4
3
5
8
9
14
Del mismo modo, se pueden ordenar los elementos con cualquier otro criterio: de mayor a menor, primero los pares y luego los impares, o cualquier otro que nos resulte útil para resolver un problema.
Métodos de ordenación de arrays hay muchos, desde los más simples (e ineficientes) hasta los más elaborados, y constituyen un área de estudio muy interesante dentro de la algorítmica. 
En la sección de actividades volveremos sobre este asunto, pero ahora mostraremos tres métodos de ordenación muy populares:
    • El método de la burbuja (o de intercambio directo), un método sencillo de entender pero bastante lento
    • El método de selección directa, otro método simple e ineficiente.
    • El método rápido o quicksort, un algoritmo elegante y recursivo que ordena arrays con asombrosa rapidez.
Podríamos explicar ahora cómo funciona cada método mediante una larga parrafada, pero probablemente no se entendería gran cosa y los algoritmos son mucho más informativos por sí mismos. De modo que estudia los tres algoritmos detenidamente para intentar comprenderlos (o, al menos, los dos primeros). Dibuja en un papel un array desordenado de pocos elementos y haz un traceo (o ejecución “a dedo”) de cada método de ordenación para comprender cómo actúa. A estas alturas del curso, deberías ser capaz de entender el funcionamiento del método de la burbuja y el de selección directa. Es posible que el método rápido no puedas comprenderlo hasta el final del curso, ya que utiliza conceptos más avanzados, como la recursividad, y además se trata de un algoritmo que no es trivial en absoluto.
(Nota: LONGITUD_array es una constante que se supone definida en alguna otra parte del programa)
// Ordenación por INTERCAMBIO DIRECTO (burbuja)
void ordenaarray(int v[])
{
  int i, j, elem;
  for (i = 1; i < LONGITUD_array; i++)
  {
     for (j = LONGITUD_array - 1; j >=i; j--)
     {
        if (v[j-1] > v[j])
	{
	  elem = v[j-1];
	  v[j-1] = v[j];
	  v[j] = elem;
	}
     }
  }
}

// Ordenación por SELECCIÓN DIRECTA
void ordenaarray(int v[])
{
  int i, j, minimo, posicion_minimo;
  for (i = 0; i < LONGITUD_array; i++)
  {
	  minimo = v[i];
	  posicion_minimo = i;		
	  for (j=i; j < LONGITUD_array; j++)
	  {
		 if (v[j] < minimo)
		 {
			 minimo = v[j];
			 posicion_minimo = j;
		 }
	  }
	  v[posicion_minimo] = v[i];
	  v[i] = minimo;
   }
}

// Ordenación rápida (QUICKSORT)
// NOTA: en esta implementación, por simplicidad, suponemos que el array v
// es un atributo de clase
void ordenaarray(int iz, int de)
{
  int i, j, x, w;
  
  i = iz;
  j = de;
  x = v[(iz+de) / 2];
  do
  {
     while (v[i] < x) i++;
     while (x < v[j]) j--;
     
     if (i <= j)
     {
        w = v[i];
	 v[i] = v[j];
	 v[j] = w;
	 i++;
	 j--;
     }
   }
   while (i <= j);

   w = v[i];
   v[i] = v[de];
   v[de] = w;
   
   if (iz < j) ordena_array(iz, j);
   if (i < de) ordena_array(i, de);
}
2.2.4   Búsqueda en arrays unidimensionales
En los arrays, como en todas las estructuras de datos que contienen muchos datos en su interior, también es habitual encontrarse con la operación de búsqueda.
La operación de búsqueda consiste en, dado un array y dado un dato cualquiera, determinar si el dato está en alguna posición del array y, si es necesario, averiguar cuál es esa posición.
La operación de búsqueda puede llegar a ser muy lenta (con el método de búsqueda secuencial, que enseguida veremos), por lo que si en un programa tenemos que realizar búsquedas en arrays grandes repetidas veces, debemos pensar el modo de lograr que las búsquedas sean más rápidas. Por fortuna, existe una forma muy simple de hacer una búsqueda en un array de manera tremendamente rápida (con el método llamado de búsqueda binaria, que también veremos). Pero esta forma tiene un problema: para que funcione, el array debe estar previamente ordenado. El proceso de ordenación, como acabamos de ver, es lento y costoso, pero, a cambio, obtendremos unos tiempos de búsqueda notablemente mejores.
Resumiendo, si necesitamos hacer búsquedas de datos en arrays unidimensionales en algún programa:
    • Si las búsquedas se realizan pocas veces, o bien los arrays son pequeños, optaremos por la búsqueda secuencial, que no necesita ordenar previamente el array.
    • Si las busquedas se realizan muchas veces y los arrays son de gran tamaño, optaremos por la búsqueda binaria, pero antes debemos ordenar el array con alguno de los métodos que hemos estudiado en la sección anterior.
Búsqueda secuencial
Consiste, simplemente, en recorrer el array desde el primer elemento hasta el último. Si encontramos el dato buscado, podemos interrumpir la búsqueda. Si no, continuaremos hasta el final del array.
Esta es una posible implementación en C:
// Búsqueda secuencial
// Buscamos el elemento “dato” en el array “v”
// Devolvemos la posición donde está “dato” o, si no lo encontramos, -1
int buscar(int v[], int dato)
{
  int i = 0;
  int x = -1;
  
  while ((i < LONGITUD_array) && (x == -1))
  {
     if (v[i] == dato)	// ¡Lo hemos encontrado!
	  x = i;	// Anotamos en x la posición
     i++;
  }
  return x;
}
Búsqueda binaria
Para que esta búsqueda funcione, el array debe estar previamente ordenado, como ya hemos aclarado.
El método consiste en lo siguiente: 
    • Supongamos que v es el array y que contiene N elementos. Llamaremos iz a la posición del elemento izquierdo del array (inicialmente, iz = 0). Llamaremos de a la posición del elemento derecho del array (inicialmente, de = N-1)
    • Tomamos un x igual al punto medio entre iz y de, es decir, x = (iz/de) / 2
    • Miramos el elemento v[x]. Si es el dato que buscábamos, ya hemos terminado. Si no, pueden ocurrir dos cosas:
    1. Que v[x] sea mayor que el dato que buscábamos. En ese caso, y dado que el array está ordenado, continuamos la búsqueda a la izquierda de x, haciendo que de = x.
    2. Que v[x] sea menor que el dato que buscábamos. En ese caso, continuamos la busqueda a la derecha de x, haciendo iz = x.
    • Repetimos desde el paso 2 hasta que encontremos el elemento buscado o hasta que iz = de (lo que significará que el elemento no está en el array)
He aquí una implementación en Java:
// Búsqueda binaria
// Buscamos el elemento “busc” en el array “v”, que debe estar ordenado
// Devolvemos la posición donde está “busc” o, si no lo encontramos, -1
void buscar_binario(int v[], int busc)
{
   int izq, der, mitad, encontrado;

   // Iniciamos una búsqueda binaria
   encontrado = 0;
   izq = 0;
   der = LONGITUD_array – 1;

   while ((izq < der-1) && (encontrado == 0))
   {
	mitad = izq + ((der - izq) / 2);	// Calculamos la posición “mitad”

	if (v[mitad] == busc)	// ¡Lo hemos encontrado!
	   encontrado = 1;
	if (v[mitad] > busc)	// Seguimos buscando en la mitad izquierda
	   der = mitad;
	if (v[mitad] < busc)	// Seguimos buscando en la mitad derecha
	   izq = mitad;

   }

   if (encontrado == 1)
	return mitad;
   else
	return -1;
}
El algoritmo de búsqueda es más complejo, como puede verse, pero los tiempos de búsqueda con el método binario son mucho más pequeños. Para un array de N elementos, el método secuencial necesita un promedio de N/2 pasos para localizar el elemento buscado, mientras que el método binario tarda una media de log2 N pasos. ¿Qué no parece muy impresionante? Fíjate en estos datos:
    1. Si el array es pequeño (por ejemplo, N = 10):
        a. La búsqueda secuencial necesita una media de 5 pasos.
        b. La búsqueda binaria necesita una media de 3 pasos.
    2. Si el array es mediano (por ejemplo, N = 100):
        a. La búsqueda secuencial necesita una media de 50 pasos.
        b. La búsqueda binaria necesita una media de 6 ó 7 pasos.
    3. Si el array es grande (por ejemplo, N = 1000), la mejora de tiempo empieza a ser notable:
        a. La búsqueda secuencial necesita una media de 500 pasos.
        b. La búsqueda binaria necesita una media de… ¡10 pasos!
    4. Si el array es muy grande (por ejemplo, N = 100.000), la mejora de tiempo es aún mayor:
        a. La búsqueda secuencial necesita una media de 50.000 pasos.
        b. La búsqueda binaria necesita una media de sólo 16 pasos.
La mejora en el tiempo de búsqueda es, por lo tanto, mayor cuanto mayor es el array. Por eso dijimos que la búsqueda binaria se emplea cuando los arrays son muy grandes.
2.3    Arrays como parámetros
Para pasar un array como parámetro a un método, en la llamada a la función se escribe simplemente el nombre del array. Recuerda que los arrays son objetos, y que los objetos, en Java, se pasan como direcciones de memoria.
El hecho de que a la función se le pase la dirección del array y no sus valores provoca un efecto importante: que los arrays siempre pueden modificarse en el interior del método y esa modificación afecta al exterior. Esta discusión la mantuvimos en el tema 2 (sección "paso de parámetros"), así que revísala si no lo tienes claro, porque es un asunto importante. Esto mismo también sucede con los arrays multidimensionales que veremos más adelante. 
Repetimos: si algún elemento del array se modifica en un método, también será modificado en el métdo desde el que fue pasado.
Por ejemplo, supongamos que serie es un array de 15 números enteros. Para pasarlo como parámetro a un método llamado metodo1() escribiríamos simplemente esto:
int serie[] = new int[15];
metodo1(serie);
En cuanto a la definición del método, la declaración de un parámetro que en realidad es un array se hace así:
void metodo1 (int serie[]);	

 Ejemplo  Un programa que sirve para leer 50 números por teclado, y calcular la suma, la media y la desviación típica de todos los valores. La desviación es una magnitud estadística que se calcula restando cada valor del valor medio, y calculando la media de todas esas diferencias.
Observa el siguiente programa de ejemplo detenidamente, prestando sobre todo atención al uso de los arrays unidimensionales y a cómo se pasan como parámetros. 
Los números de la serie se almacenarán en un array float de 50 posiciones llamado valores. La introducción de datos en el array se hace en el método introducirValores(). Recuerda que, al modificar el array dentro del método, también se modificará en el método que lo llamó. 
Después, se invoca a 3 métodos que calculan las tres magnitudes.
class Estadisticas
{
   public static void main(String[] args)
   {
	float valores[] = new float[50];
	float suma, media, desviacion;
	
	introducirValores(valores);
	suma = calcularSuma(valores);	
	media = calcularMedia(valores, suma);
	desviacion = calcularDesviacion(valores, media);
	System.out.println("La suma es " + suma);
	System.out.println("La media es " + media);
	System.out.println("La desviación es " + desviacion);
   }

   /* Lee 50 números y los almacena en el array N pasado por variable */
   private void introducir_valores(float n[])
   {
	int i;
	for (i=1; i<=49; i++)
	{
		printf("Introduzca el valor nº %d: ", i);
		n = Integer.parseInt(System.console().readLine());
	}
   }

   /* Devuelve la suma todos los elementos del array N */
   private float calcularSuma(float n[50])	
   {
	int i;
	float suma;
	suma = 0;
	for (i=1; i<=49; i++)
		suma = suma + n[i];
	return suma;
   }

   /* Devuelve el valor medio de los elementos del array N. 
      Necesita conocer la suma de los elementos para calcular la media */
   private float calcularMedia(float N[50], float suma)	
   {
	int i;
	float media;
	media = suma / 50;
	return media;
   }

   /* Calcula la desviación típica de los elementos del array N. 
      Necesita conocer la media para hacer los cálculos */
   private float calcularDesviacion(float n[50], float media)
   {
	int i;
	float diferencias;
	diferencias = 0;
	for (i=1; i<=49; i++)
		diferencias = diferencias + abs(N[i] – media) ;
	diferencias = diferencias / 50;
	return diferencias;
   }
}
2.4 Métodos para arrays unidimensionales
Los arrays unidimensionales, como objetos que son, disponen de varios métodos muy útiles que facilitan el trabajo con ellos. Por ejemplo, los heredados de la clase Object (v. tema 4):
    • equals(): permite discernir si dos referencias son el mismo objeto.
    • clone(): permite duplicar el array en profundidad. 
En el tema 4 hablábamos de las peculiaridades y limitaciones de estos dos métodos, y de cómo a veces es conveniente sobreescribirlos. Pues bien, el método clone() para arrays unidimensionales está sobreescrito, y produce una copia en profundidad del array original. Por lo tanto, el array clonado tiene un contenido idéntico al original, pero está alojado en otra zona de la memoria y tienen vidas separadas. Son arrays unidimensionales de igual contenido pero distinta referencia.
Eso significa que, en el ejemplo siguiente, aunque los 3 arrays unidimensionales v1, v2 y v3 contienen los mismos valores, v1.equals(v2) devolverá false y v1.equals(v3) devolverá true:
byte[] v1 ={1,2,3};
byte[] v2 = (byte[]) v1.clone();
byte[] v3 = v1;

Además, los arrays unidimensionales en Java tiene otros métodos propios. Citamos a continuación los más usuales:
    • length: devuelve el número de elementos del array. ¡Cuidado! No es un método, sino un atributo (no lleva paréntesis)
    • sort(): permite ordenar el array por casi cualquier criterio. Se puede seleccionar el rango de ordenación (para no ordenar todo el array, solo una parte) y el método.
    • fill(): para rellenar de valores el array.
    • binarySearch(): realiza una búsqueda binaria.
Como ves, los chicos de Sun Microsystems pensaron en todo para hacer la vida del programador más sencilla. Puedes encontrar información detallada de estos métodos y otros en el sitio oficial de Oracle: http://docs.oracle.com/javase/8/docs/api/index.html

2.5 Representación interna de los arrays unidimensionales
Finalizaremos la sección sobre arrays unidimensionales hablando de cómo se almacenan en la memoria del ordenador. Es importante tener una idea clara porque muchas de las cosas que suceden con los arrays unidimensionales se explican fácilmente a partir de su disposición en memoria.
En la memoria del ordenador, todos los elementos de los arrays unidimensionales se almacenan en posiciones de memoria consecutivas.
Por ejemplo, si v1 es un array de 10 números de tipo byte (cada número de dicho tipo ocupa 1 byte de memoria), el compilador asignará un espacio de memoria al elemento 0. Imaginemos que dicho espacio de memoria se ubica en la dirección 2000. Entonces, el resto de elementos del array ocuparán la posición 2001, la 2002, la 2003, … hasta la 2009 (ver figura)
Por otro lado, si un array v2 consta de 50 números de tipo short, y suponemos que los datos de este tipo ocupan 2 bytes, si el primer elemento tiene asignada la posición 2000, el siguiente estará en la posición 2002, el siguiente en la 2004, etc.
¿Qué ocurre si se intenta acceder a un elemento del array más allá de su límite? Dicho de otro modo, si tenemos un array de 10 elementos, ¿qué pasa si intentamos utilizar el elemento undécimo? Lógicamente, que estaremos invadiendo el espacio de direcciones que hay más allá del límite del array: la dirección 2010 y siguientes en el caso del array v1, y la 2020 y siguientes en el caso del array v2. Esas direcciones pertenecerán a otras variables o, lo que es peor, a algún fragmento de código.
La JVM, durante la ejecución, comprobará que no intentemos acceder más allá del límite del array (ni por arriba, ni por abajo). Si lo hacemos, obtendremos un error de ejecución que es deseable evitar a toda costa. Esto se puede conseguir encerrando las operaciones sobre arrays unidimensionales en bloques try-catch y capturando las posibles excepciones, o bien programando las rutinas de acceso a arrays unidimensionales con el debido cuidado. Un enfoque mixto, utilizando ambas técnicas, es sin duda el más adecuado.


3 Arrays bidimiensionales (matrices)
Una matriz, tabla o array bidimiensional, como un array, es una colección de elementos individuales, todos del mismo tipo, agrupados bajo el mismo identificador. La diferencia con el array es que, en el momento de declararlo y de acceder a cada elemento individual, debemos utilizar dos índices en lugar de uno:
int[][] matriz = new int[4][4];
Tenemos aquí una variable compleja llamada matriz que no consta de 4 elementos enteros, sino de 16, es decir, 4x4. Podemos representar gráficamente la matriz como una tabla:

Columnas
Filas
0
1
2
3
0




1




2




3




Cada casilla de la tabla o matriz es identificable mediante una pareja de índices. Normalmente, el primero de los índices se refiere a la fila, y el segundo, a la columna. Por ejemplo, si hacemos estas asignaciones:
matriz[0][0] = 5;
matriz[1][0] = 1;
matriz[3][2] = 13;
…el estado en el que quedará la matriz será el siguiente:

0
1
2
3
0
5



1
1



2




3


13

Por descontado, los dos índices de la matriz pueden ser diferentes, obteniéndose tablas que son más anchas que altas o más altas que anchas.
Una matriz es realmente un array de arrays unidimensionales, así que la salida por pantalla de las siguientes instrucciones será, respectivamente, 4 y 4. El primer 4 se refiere al número de filas de la matriz, y,  el segundo, al número de columnas de la primera fila:
System.out.println(matriz.length);
System.out.println(matriz[0].length);
Por lo demás, las matrices se utilizan exactamente igual que los arrays unidimensionales. A modo de ejemplo, este sería el código para inicializar una matriz de 5x10 enteros con todos sus elementos a 0. Observa cómo se usan los dos bucles anidados para acceder a todos los elementos:
int m[][] = new int[5][10];
int i, j;
for (i = 0; i <= 4; i++)
{
   for (j = 0; j <= 9; j++)
   {
       m[i][j] = 0;
   }
}
3.1   Arrays de múltiples dimensiones
Del mismo modo que a los arrays unidimensionales se les puede añadir un segundo índice, obteniendo las matrices, se puede generalizar esta práctica, dando lugar a arrays multidimensionales. Por ejemplo, el siguiente es un array de cinco dimensiones compuesto de números enteros:
int ejemplo[][][][] = new int[10][10][4][5][7];
Estos arrays no se pueden representar gráficamente (aunque con los de tres dimensiones se puede intentar dibujar un cubo), pero su utilización es idéntica a la de los arrays de una o dos dimensiones.