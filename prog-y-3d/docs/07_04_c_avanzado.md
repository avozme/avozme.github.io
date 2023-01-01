---
layout: page
title: 9.4. Un poco de C avanzado
permalink: /c-avanzado/
nav_order: 4
has_children: true
parent: 9. El lenguaje C
grand_parent: Introd. a la prog. y al diseño 3D
---

## 9.4. Un poco de C avanzado
{: .no_toc }

- TOC
{:toc}

En esta sección vamos a ver algunas cosas (¡no todas!) sobre C avanzado: una introducción a los punteros, algo sobre gestión dinámica de memoria, un poco acerca de los arrays dinámicos y cómo usar librerías no estándar importantes tales como Ncurses (para añadir color y otros efectos a nuestros programas de texto) o SDL (para añadir gráficos y sonidos).

### 9.4.1. Punteros

Comprender y usar correctamente los punteros es con seguridad **lo más complicado del lenguaje C**, pero también se trata de un mecanismo muy poderoso. Tan poderoso que un simple puntero descontrolado (hay quien los llama *punteros locos*) puede provocar que el programa se cuelgue o se comporte de forma extraña e impredecible.

Todos los programadores con cierta experiencia en C reconocerán que, a veces, programar con punteros es como quedarse atrapado en un ascensor con un montón de serpientes pitón enloquecidas. Pero, cuando se les coge el tranquillo y se les ata en corto, permiten hacer auténticas virguerías.

### 9.4.2. Comprendiendo los punteros

Dentro de la memoria del ordenador, cada **dato** almacenado ocupa **una o más celdas contiguas de memoria**. El número de celdas de memoria requeridas para almacenar un dato depende de su tipo. Por ejemplo, un dato de tipo entero puede ocupar 32 bits (es decir, 4 bytes), mientras que un dato de tipo carácter ocupa 8 bits (es decir, 1 byte).

<div style='padding: 10px; background-color: #ddd'><strong>Un puntero no es más que una variable cuyo contenido no es un dato, sino la dirección de memoria donde está almacenado un dato.</strong></div>

Veámoslo a través de un ejemplo. Imaginemos que v es una variable de tipo carácter y que, por tanto, necesita 1 byte para ser almacenada. La declaración e inicialización de la variable será como la siguiente:

```c
char v;
v = 'A';
```

Al ejecutar este código, el sistema operativo asigna automáticamente una celda de memoria para el dato. Supongamos que la celda asignada tiene la dirección 1200. Al hacer la asignación v = 'A', el sistema almacena en la celda 1200 el valor 65, que es el código ASCII de la letra 'A':


Dirección de memoria|Contenido
-|-
1198|
1199|
1200|65
1201|
...|...

Cuando usamos la variable v a lo largo del programa, el sistema consulta el dato contenido en la celda de memoria asignada a la variable. Esa celda será siempre la misma a lo largo de la ejecución: la 1200. 

Por ejemplo, al encontrar esta instrucción:

```c
printf("%c", v);
```

.. el compilador acude a la celda 1200 de la memoria, consulta el dato almacenado en ella en ese momento y sustituye la variable v por ese dato.

El programador no tiene modo de saber en qué posición de memoria se almacena cada dato, a menos que utilice punteros. Los punteros sirven, entonces, para conocer la dirección de memoria donde se almacena el dato, y no el dato en sí. 

La dirección ocupada por una variable v se determina escribiendo **&v**. Por lo tanto, el **operador &** es un operador unario, llamado **operador dirección**, que proporciona la dirección de memoria de una variable.

La dirección de v se le puede asignar a otra variable mediante esta instrucción:

```c
char* p;
p = &v; 
```

Resultará que esta nueva variable es un puntero a v, es decir, una variable cuyo contenido es la dirección de memoria ocupada por la variable v. *Representa la dirección de v y no su valor*. Por lo tanto, el contenido de p será 1200, mientras que el contenido de v será 65.

El dato almacenado en la celda apuntada por la variable puntero puede ser accedido mediante el operador asterisco aplicado al puntero. Así pues, la expresión *p devuelve el valor 65, que es el contenido de la celda apuntada por p. El **operador \*** es un operador unario, llamado **operador indirección**, que opera sólo sobre una variable puntero.

Resumiendo: podemos tener *variables "normales"* y utilizar el operador & para conocer su dirección de memoria. O podemos tener *variables puntero*, que ya son en sí mismas direcciones de memoria, y utilizar el operador * para acceder al dato que contienen:

* **El operador dirección (&)** sólo puede actuar sobre variables que **no** sean punteros. En el ejemplo anterior, la variable v vale 65 y la expresión &v vale 1200.
* **El operador indirección (\*)** sólo puede actuar sobre variables que sean punteros. En el ejemplo anterior, la expresión *p vale 65 y la variable p vale 1200.

Las variables puntero pueden apuntar a direcciones donde se almacene cualquier tipo de dato: enteros, flotantes, caracteres, cadenas, arrays, estructuras, etc. Esto es tremendamente útil y proporciona una enorme potencia al lenguaje C, pero también es una fuente inagotable de errores de programación difíciles de detectar y corregir, como iremos viendo en los siguientes temas  

### 9.4.3. Declaración e inicialización de punteros

Las variables de tipo puntero, como cualquier otra variable, deben **declararse** antes de ser usadas. 

Cuando una variable puntero es definida, *el nombre de la variable debe ir precedido por un \**. 

El tipo de dato que aparece en la declaración se refiere al tipo de dato que se almacena en la dirección representada por el puntero, en vez del puntero mismo. Así, una declaración de puntero general es:

Por ejemplo:

```c
int *numero;
char *letra;
```

La variable *numero* no contiene un número entero, sino *la dirección de memoria donde se almacenará un número entero*. La variable letra tampoco contiene un carácter, sino *la dirección de memoria donde se almacenará un carácter*.

Cuando un puntero ha sido declarado pero no inicializado, apunta a una dirección de memoria indeterminada. Si tratamos de usarlo en esas condiciones obtendremos resultados impredecibles (y casi siempre desagradables). 

Antes de usar cualquier puntero hay que **asegurarse de que está apuntando a una dirección válida**, es decir, a la dirección de alguna variable del tipo adecuado. Por ejemplo, así:

```c
int *numero;
int a;
numero = &a;
```

El puntero *numero* ahora sí está en condiciones de ser usado, porque está apuntado a la dirección de la variable *a*, que es de tipo *int*, como el puntero.

Otra posibilidad es hacer que un puntero apunte a NULL. El identificador NULL es una constante definida en el lenguaje que indica que un puntero no está apuntando a ninguna dirección válida y que, por lo tanto, no se debe utilizar:

```c
int *numero = NULL;
```

### 9.4.4. Asignación de punteros

Se puede asignar una variable puntero a otra siempre que ambas apunten al mismo tipo de dato. Al realizar la asignación, ambos punteros quedarán apuntando a la misma dirección de memoria.

Observa este ejemplo y trata de determinar qué resultado se obtiene en la pantalla (antes de leer la solución que aparece más abajo):

```c
int a, b, c;
int *p1, *p2;
a = 5;
p1 = &a;	/* p1 apunta a la dirección de memoria de la variable a */
p2 = p1;	/* a p2 se le asigna la misma dirección que tenga p1 */
b = *p1;
c = *p1 + 5;	/* Suma 5 a lo que contenga la dirección apuntada por p1 */
printf("%i %i %i %p %p", a, b, c, p1, p2);
```

En la pantalla se imprimirá “5 5 10”, que es el contenido de las variables a, b y c al terminar la ejecución de este bloque de instrucciones, y la dirección a la que apuntan p1 y p2, que debe ser la misma. Observa que con *printf* y la cadena de formato "%p" se puede mostrar la dirección de memoria de cualquier variable.

### 9.4.5. Punteros y arrays

#### Punteros y arrays de una dimensión

Los punteros y los arrays tienen una relación muy estrecha en C, ya que **el nombre de un array es en realidad un puntero al primer elemento** de ese array. 

Es decir, si *x* es un array undimensional, la dirección del primer elemento puede ser expresada como *&x[0]* o simplemente como *x*. 

Y, del mismo modo, la dirección del elemento i-ésimo se puede expresar como *&x[i]* o como *(x+i)*. En este caso, la expresión *(x+i)* no es una operación aritmética convencional, sino una operación con punteros.

Si &x[i] y (x+i) representan la dirección del i-ésimo elemento de x, podemos decir que x[i] y *(x+i) representan el **contenido** de esa dirección, es decir, el valor del i-ésimo elemento de x. Observa que la forma x[i] es la que hemos estado utilizando hasta ahora para acceder a los elementos de un vector.

Los arrays, por lo tanto, pueden utilizarse con índices o con punteros. Al programador suele resultarle mucho más cómodo utilizar la forma x[i] para acceder al elemento i-ésimo de un array. Sin embargo, hay que tener en cuenta que la forma *(x+i) es mucho más eficiente que x[i], por lo que suele preferirse cuando la velocidad del ejecución es un factor determinante.

#### Punteros y arrays multidimensionales

Un array multidimensional es en realidad una colección de varios arrays unidimensionales (vectores). Por tanto, se puede definir un array multidimensional como un puntero a un grupo contiguo de arrays unidimensionales.

El caso más simple de array de varias dimensiones es el bidimiensional. Supongamos que *x* es un array bidimensional de enteros con 10 filas y 20 columnas. Podemos declarar *x* de dos formas:

```c
int x[10][20];   /* Declaración convencional */
int (*x)[20];    /* Declaración como puntero */
```
En la segunda declaración, *x* se define como un puntero a un grupo de array unidimensionales de 20 elementos enteros. Así *x* apunta al primero de los arrays de 20 elementos, que es en realidad la primera fila (fila 0) del array bidimensional original. Del mismo modo (x+1) apunta al segundo array de 20 elementos, y así sucesivamente.

Por ejemplo, el elemento de la columna 2 y la fila 5 puede ser accedido de estas dos maneras:

```c
x[2][5];      /* Acceso convencional */
*(*(x+2)+5);  /* Acceso mediante punteros */
```

Esta instrucción parece muy complicada pero es fácil de desentrañar:
    
* (x+2) es un puntero a la columna 2
* *(x+2) es el objeto de ese puntero y refiere a toda la columna. Como la columna 2 es un array unidimensional,  *(x+2) es realmente un puntero al primer elemento de la columna 2.
* (*(x+2)+5) es un puntero al elemento 5 de la columna 2.
* El objeto de este puntero *(*(x+2)+5) refiere al elemento 5 de la columna 2.

### 9.4.6. Paso de punteros como parámetros

A menudo los punteros son **pasados a las funciones como argumentos**. Esto permite que datos de la porción de programa desde el que se llama a la función sean accedidos por la función, alterados dentro de ella y devueltos de forma alterada. 

Este uso de los punteros se conoce como **paso de parámetros por variable o referencia** y lo hemos estado utilizando hasta ahora sin saber muy bien lo que hacíamos.

Cuando los punteros son usados como argumento de una función, es necesario tener cuidado con la declaración y uso de los parámetros dentro de la función. Los argumentos formales que sean punteros deben ir precedidos por un asterisco. Observa detenidamente el siguiente ejemplo:

```c
#include <stdio.h>
void funcion1(int, int);
void funcion2(int*, int*);

int main(void)
{
  int u, v;
  u = 1;
  v = 3;
  funcion1(u,v);
  printf("Después de la llamada a funcion1:  u=%d v=%d\n", u, v);
  funcion2(&u,&v);
  printf("Después de la llamada a funcion2:  u=%d v=%d\n", u, v);
}

void funcion1(int u, int v)	
{
   u=0;
   v=0;
}

void funcion2(int *pu, int *pv)
{
   *pu=0;
   *pv=0;
}
```

La función de *funcion1()* utiliza **paso de parámetros por valor**. Cuando es invocada, los valores de las variables *u* y *v* del programa principal son *copiados* en los parámetros *u* y *v* de la función. Al modificar estos parámetros dentro de la función, el valor de u y v en el programa principal no cambia. 

En cambio, *funcion2()* utiliza paso de parámetros por por referencia. Lo que se pasa a la función no es el *valor* de las variables sino su *dirección* de memoria, es decir, un puntero a las celdas de memoria donde *u* y *v* están almacenadas. Dentro de la función, se utiliza el operador asterisco para acceder al *contenido* de *pu* y *pv* y, en consecuencia, se altera el contenido de las posiciones de memoria apuntadas por *pu* y *pv*. El resultado es que las variables *u* y *v* del programa principal quedan modificadas.

Por lo tanto, la salida del programa debe ser:

```
Después de la llamada a funcion1:  u=1 v=3
Después de la llamada a funcion2:  u=0 v=0
```

¿Recuerdas que la función *scanf()* requiere que sus argumentos vayan precedidos por &, mientras que *printf()* no lo necesita? Hasta ahora no podíamos comprender por qué, pero ahora podemos dar una razón: *scanf()* necesita que sus argumentos vayan precedidos del símbolo & porque necesita las direcciones de los datos que van a ser leídos, para poder colocar en esas posiciones de memoria los datos introducidos por teclado. En cambio, printf() no necesita las direcciones, sino únicamente los valores de los datos para poder mostrarlos en la pantalla.

Al estudiar los arrays y las estructuras ya vimos en detalle cómo se deben pasar como parámetros a las funciones. Recuerda que los arrays siempre se pasan por variable y no es necesario usar el símbolo & en la llamada, ya que el propio nombre del array se refiere, en realidad, a la dirección del primer elemento.

### 9.4.7. Devolución de punteros

Una función también puede devolver un puntero. Para hacer esto, la declaración de la función debe indicar que devolverá un puntero. Esto se realiza precediendo el nombre de la función con un asterisco. Por ejemplo:

```c
double *pf;
pf = funcion(argumentos);
printf("%lf", *pf);
```

Cuando esta función sea invocada, devolverá un puntero a un dato de tipo double, y por lo tanto debe ser asignada a una variable de ese tipo. Por ejemplo, así:

### 9.4.8. Punteros a punteros

Un último aspecto (a la vez confuso y potente) de los punteros es la posibilidad de definir punteros que, a su vez, apunten a otros punteros. Esto no es un trabalenguas, sino que, técnicamente, se denomina **indirección múltiple**. 

Por ejemplo, el resultado del siguiente fragmento de código en C debe ser que se imprima el número 15 en la pantalla:

```c
int n;
int* p1;      /* puntero a un número entero */
int** p2;     /* puntero a un puntero de números enteros */
p1 = &n;	     /* p1 contiene la dirección de n */
p2 = &p1;	  /* p2 contiene la dirección de p1 */
**p2 = 15;    
printf("%i", n);
```

### 9.4.9. Gestión dinámica de la memoria: arrays dinámicos

Según hemos visto hasta ahora, la memoria reservada para cada variable se define en el momento de escribir el código del programa. 

Por ejemplo, si declaramos una variable de tipo *int*, ésta tendrá asignados 2 o 4 bytes de memoria (esa cantidad puede variar dependiendo del compilador y del sistema operativo). Entonces, si declaramos un array de 100 números enteros, el array tendrá reservados 200 o 400 bytes de memoria.

*¿Pero qué ocurre si no sabemos de antemano cuántos elementos puede llegar a tener el array?*

Por ejemplo, imaginemos un problema consistente en leer por teclado (u otro dispositivo de entrada) una cantidad indefinida de números para almacenarlos en un array y luego hacer ciertas operaciones con ellos. ¿De qué tamaño podemos definir el array? ¿De 100 elementos? ¿Y si el usuario introduce 101 elementos?

Para estas situaciones, que son muy frecuentes, existe la **asignación dinámica de memoria**, que consiste en reservar memoria para las variables en tiempo de ejecución, es decir, mientras el programa está funcionando. Así, es posible "estirar" o "encoger" sobre la marcha el espacio reservado para el array, dependiendo de las necesidades de cada momento.

Veremos enseguida que, para manejar la memoria dinámicamente, es imprescindible **el uso de punteros**. De hecho, este es uno de los grandes frutos que vamos a obtener de ellos.

Como los arrays son la estructura de datos más simple y fácil de entender, vamos a centrarnos en crear y manipular **arrays dinámicos**, pero los principios que veamos aquí son aplicables a cualquier otra estructura dinámica simple, como pilas, listas o colas, o complejas, como árboles o grafos.

#### Reserva de memoria con *malloc()*

Ya que un nombre de array es en realidad un puntero a su primer elemento, es posible definir un array como una variable puntero en vez de como un array convencional. Así, estas dos definiciones sirven para un vector de números enteros:

```c
int vector1[100];
int* vector2;
```

* El *vector1* se define del modo convencional de un array. Esto produce la reserva de un bloque fijo de memoria al empezar la ejecución del programa lo suficientemente grande como para almacenar 100 números enteros.
* El *vector2* se define como puntero a entero. En este caso, no se reserva ninguna cantidad de memoria para almacenar los números enteros. 

Si intentamos acceder a los elementos de los vectores obtendremos resultados diferentes:

```c
vector1[5] = 83;
vector2[5] = 27;	/* Esto es un error */
```

La primera asignación funcionará correctamente, ya que el quinto elemento del *vector1* tiene un espacio de memoria asignado. La segunda asignación producirá un efecto impredecible, ya que *vector2* no tiene ningún espacio de memoria asignado y, por lo tanto, el dato 27 se escribirá en una posición de memoria correspondiente a otro dato u otro programa. La consecuencia puede llegar a ser bastante desagradable.

Se necesita, pues, reservar un fragmento de memoria antes de que los elementos del array sean procesados. Tales tipos de reserva se realizan mediante la **función *malloc()*** o alguna de sus variedades. Observa bien su uso en este ejemplo:

```c
int *x;
x = (int *) malloc (100 * sizeof(int));
```

La función *malloc()* reserva un especio de memoria consistente en 100 veces el tamaño de un número entero. Fíjate bien en el uso del *sizeof(int)*: se trata de un operador unario que devuelve el tamaño de un tipo de dato cualquiera, tanto simple como complejo.

Suponiendo que *sizeof(int)* fuera 2 (es decir, que cada número de tipo int ocupase 2 bytes), lo que se le está pidiendo a *malloc()* es que reserve 100 * 2 bytes, es decir, 200 bytes de memoria.

Además, es necesario usar el **molde (int \*)**, ya que malloc() devuelve un puntero sin tipo (es decir, un puntero a *void*), así que hay que convertirlo a puntero a entero antes de asignarlo a la variable x, que efectivamente es un puntero a entero.

De esta manera, la variable *vector2* pasa a ser un **array dinámico**: se comporta como un array y puede usarse como tal, pero su tamaño ha sido definido durante la ejecución del programa. Y más adelante, en el mismo programa, podemos redefinir el tamaño del array para acortarlo o alargarlo.

Si la función *malloc()* falla devolverá un puntero a NULL. Utilizar un puntero a NULL es la forma más segura de hacer explotar tu programa, así que siempre debemos comprobar que el puntero devuelto es correcto. Una vez hecho esto, podemos utilizar x con toda tranquilidad como si fuera un array de 100 números enteros. Por ejemplo:

```c
int *x, i;
x = (int *) malloc (100 * sizeof(int));
if (x == NULL)
  printf("Error en la asignación de memoria");
else
{
  printf("Se ha reservado con éxito espacio para 100 números");
  for (i=0; i<100; i++)
  {
	printf("Introduzca un número:");
	scanf("%i", &x[i]);
  }
}
```

#### Liberación de memoria con *free()*

El programador debe tener dos precauciones básicas a la hora de manejar la memoria dinámicamente:

* **Asignar memoria** a un puntero antes de usarlo con *malloc()* u otra función similar
* **Liberar la memoria asignada**, cuando ya no va a usarse más, con *free()* u otra función similar.

Si no se libera la memoria asignada a un puntero, teóricamente no ocurre nada grave, salvo que podemos terminar por agotar la memoria disponible si reservamos continuamente y nunca liberamos. 

Es, en cualquier caso, una costumbre muy saludable.

Para liberar la memoria reservada previamente con *malloc()* u otra función de su misma familia, se utiliza la función *free()*. Observa su uso en este ejemplo:

```c
int *x, i;
x = (int *) malloc (100 * sizeof(int));
... instrucciones de manipulación de x ...
free(x);
```

Toda la memoria reservada con *malloc()* quedará liberada después de hacer *free()* y se podrá utilizar para guardar otros datos o programas. El puntero *x* quedará apuntado a NULL y no debe ser utilizado hasta que se le asigne alguna otra dirección válida.

#### Funciones básicas para la gestión dinámica de la memoria

Además de *malloc()* y *free()* existen otras funciones similares pero con pequeñas diferencias. A continuación resumimos las más usuales y mostramos un ejemplo de su uso.

Pero antes haremos una advertencia: todas las funciones de reserva de memoria devuelven un puntero a NULL si no tienen éxito. Por lo tanto, deben ir seguidas de un condicional que compruebe si el puntero apunta a NULL antes de utilizarlo.

* **calloc()**: Reserva un bloque de memoria para almacenar num elementos de tam bytes y devuelve un puntero void al comienzo del bloque.


   El siguiente ejemplo reserva espacio para 35 números enteros:
   
   ```c
   int* p;
   p = (int*) calloc(35, sizeof(int));
   ```

* **free()**: Libera el bloque de memoria apuntado por un puntero y que previamente había sido reservado.

* **malloc()**: Reserva un bloque de memoria de tam bytes y devuelve un puntero void al comienzo del mismo. Por ejemplo, para reservar espacio para una cadena de 100 caracteres:

   ```c
   char* texto;
   texto = (char*) malloc(100 * sizeof(char));
   ```

* **realloc()**: Cambia el tamaño de un bloque de memoria apuntado por puntero. Dicho bloque ha debido ser previamente asignado con malloc() u otra función similar. El nuevo tamaño será de tam bytes. Devuelve un puntero void al comienzo del bloque.


   En el siguiente ejemplo, se reserva espacio para 100 caracteres, pero luego se modifica el tamaño del bloque para dar cabida hasta 500 caracteres:

   ```c
   char* texto;
   texto = (char*) malloc(100 * sizeof(char));
   /* Aquí irían las instrucciones que utilicen el puntero texto
      con un tamaño de 100 caracteres */
   texto = (char*) realloc(texto, 500 * sizeof(char));
   /* A partir de aquí, el mismo puntero texto puede usarse para
      manejar hasta 500 caracteres */
   ```

### 9.4.10. Librerías no estándar que molan: ncurses

Además de las librerías estándar ANSI, existen muchas (¡muchísimas!) librerías de terceros que se pueden usar en nuestros programas. Las que vamos a ver a continuación nos permitirán introducir colores, sonidos y movimientos en nuestros programas, pero debes tener presente una cosa: al no ser librerías estándar, los programas creados con estas librerías serán más difícilmente portables a otros sistemas.

#### Qué es Ncurses

**Ncurses** es una **librería para el manejo de interfaces basadas en texto**. 

Es decir, se trata de un conjunto de funciones ya programadas que podemos utilizar en nuestros programas de texto para mejorar su aspecto. Con Ncurses podemos añadir colores, escribir en cualquier parte de la pantalla o borrar caracteres concretos. Por ejemplo, este programa para generar y resolver sudokus está escrito con Ncurses:

![Ejemplo de programa escrito con Ncurses](/docs/prog-y-3d/_site/assets/images/05-ncurses.png)

Desde luego, la pantalla anterior sería imposible de obtener con las librerías estándar de C.

#### Compilación y enlace

Como Ncurses no es una librería estándar, es necesario ordenar al compilador que la enlace con nuestro programa. 

Si compilas desde la consola, esto se hace añadiendo la opción –lncurses al comando *gcc*. Por ejemplo:

* ```gcc holamundo.c```: compila holamundo.c sin enlazarlo con la librería Ncurses
* ```gcc -lncurses holamundo.c```: compila holamundo.c enlazándolo con Ncurses

Si trabajas desde desde Visual Studio Code y tienes la librería Ncurses instalada en tu sistema, no es necesario que hagas nada en especial. Un simple ```#include <ncurses.h>``` bastará para poder usar la librería.

Ncurses tiene muchísimas funciones, pero nosotros sólo nos referiremos aquí a las más básicas, que nos permitirán añadir color a nuestros textos y controlar libremente la posición del cursor de escritura. Pero Ncurses va mucho más allá, permitiendo la creación de capas de texto superpuestas, menús desplegables y muchas otras cosas en la consola de texto.

#### Inicialización de Ncurses

Para utilizar las funciones de Ncurses en nuestro programa, basta con que incluyamos la siguiente llamada:

```c
initscr();
```

Esta función crea una ventana de texto. La ventana se llama *stdscr* (que significa "standard screen", es decir, "pantalla estándar"). A partir de aquí podremos utilizar cualquier función de Ncurses, pues todas actúan sobre esa ventana (se pueden crear varias ventanas sobre stdscr, pero nosotros no profundizaremos en esa posibilidad). Por ejemplo, una función que suele ir justo después es:

```c
keypad (stdscr, 1);
```

Esto sirve para activar la recepción de teclas especiales (como F1, F2, ESC, etc). Si no llamamos a keypad(), no podremos utilizar ese tipo de teclas en nuestro programa. El segundo parámetro sirve para activar (1) o desactivar (0) la recepción de teclas especiales.

A continuación te dejo una lista con las principales funciones de inicialización de Ncurses:

* **initscr()**. Inicializa Ncurses y crea la pantalla estándar. Debe ser invocada antes que cualquier otra función de la librería.
* **keypad()**. Activa / desactiva la recepción de teclas especiales, como F1, ESC, Intro, etc. Si activar = 1, se activa la recepción. Si activar = 0, se desactiva.
* **echo()** y **noecho()**. Activa / desactiva el eco de caracteres. Si el eco está activo, lo que se escriba en el teclado aparece en la pantalla. Si está inactivo, no.
* **cbreak()** y **nocbreak()**. Activa / desactiva el envío inmediato de teclas. Normalmente, cuando se teclea algo no es enviado al programa hasta que no se pulsa "intro". La función cbreak() hace que todo cuanto se teclee sea enviado al programa sin necesidad de "intro". La función nocbreak() desactiva este comportamiento
* **nodelay(stdscr)**. Activa / desactiva la espera para lectura de teclado. Las funciones para leer un solo carácter, como getch(), detienen la ejecución del programa hasta que se pulsa alguna tecla. Llamando a esta función con el parámetro activar = 1, conseguiremos que el programa no se detenga en getch() aunque no se pulse tecla alguna. Para desactivarlo, llamaremos a la función con activar = 0.

* **endwin()**. Finaliza Ncurses. Hay que llamar a esta función antes de terminar el programa para liberar la memoria ocupada y restaurar la consola al estado inicial.

#### Escribir y leer con ncurses

Cuando utilicemos Ncurses debemos olvidarnos de las funciones de entrada/salida estándar, como *scanf()*, *printf()*, *gets()* o *puts()*. En su lugar usaremos estas otras funciones:

* **printw()** y **putstr()**. Para escribir usaremos la función *printw()*, que funciona igual que *printf()* pero sobre una ventana de Ncurses. También podemos usar *putstr()*, que es como *puts()*, es decir, sirve para imprimir cadenas
* **getstr()** y **getch()**. Para leer disponemos de *getstr()*, que es como *gets()*, es decir, sirve para leer cadenas por teclado. De modo que, si queremos leer un número, debemos leerlo como cadena y luego convertirlo a número (con las funciones estándar *atoi()*, *atof()*, etc). También podemos usar *getch()*, que lee un único carácter.
* **move()**. Posiciona el cursor de texto en la columna x y la fila y de la pantalla. ¡Atención! Se indica primero la fila y luego la columna.
* **refresh()**. Actualiza la pantalla. Es el único modo de asegurarnos de que los cambios realizados se muestren instantáneamente. Si no, Ncurses decidirá cuándo actualizar la pantalla por su cuenta, y te aseguro que no lo hace continuamente.

#### Dar color a nuestro texto

Antes de utilizar los colores en la terminal de texto hay que inicializarlos llamando a la función *start_color()* sin argumentos, así:

```c
if (has_colors())
  start_color();
```

La llamada previa a *has_colors()* se realiza para asegurarnos de que nuestra consola soporta el uso de colores. Es raro encontrar una consola que no permita colores, pero existen, así que no está de más hacer la comprobación.

Una vez hecho esto, podemos utilizar los colores básicos definidos en *ncurses.h*, cuyas constantes son COLOR_BLACK, COLOR_WHITE, COLOR_YELLOW, etc.

Para utilizar esos colores se deben agrupar en parejas: un color para el texto junto con un color para el fondo. A cada pareja se le asigna un número a través de la función *init_pair()*. Por ejemplo:

```c
init_pair(1, COLOR_YELLOW, COLOR_BLUE);
```

Esto define a la *pareja de colores nº 1* como *texto amarillo sobre fondo azul*. De este modo podemos definir, por lo general, hasta 64 parejas.

Después, para **activar una pareja de color**, haremos esta llamada:

```c
attron(COLOR_PAIR(1));
```

Esto activa la pareja de colores nº 1, de manera que todo el texto que aparezca en la pantalla a partir de este momento se verá amarillo con el fondo azul.

La función *attron()*, además de para activar parejas de colores, sirve para cambiar otros atributos del texto. Por ejemplo, lo siguiente se utiliza para escribir en **negrita**:

```c
attron(A_BOLD);
```

Puedes obtener más información sobre attron() en las páginas de manual (escribiendo ```$ man attron``` en la consola) o en internet (por ejemplo, [aquí](https://linux.die.net/man/3/attron)).


#### Ejemplo de uso de Ncurses

Para terminar esta breve introducción a la librería Ncurses mostraremos un ejemplo ilustrativo del uso de algunas de las funciones que aquí se han visto.

El siguiente programa utiliza Ncurses para escribir el texto HOLA en color rojo sobre fondo azul y el texto MUNDO en color amarillo sobre fondo verde. El texto HOLA aparece en la línea 11, y MUNDO en la 12. Luego, el programa espera hasta que se pulsa la tecla "flecha arriba", y entonces termina.

```c
#include <ncurses.h>
int main(void)
{
  char carácter;
  initscr();         // Inicializa Ncurses
  keypad(stdscr, 1); // Activa teclas especiales (como las flechas)
  cbreak();          // Para no tener que pulsar Intro tras cada carácter 
  if (has_colors()) start_color();         // Inicializa colores
  init_pair(1, COLOR_RED, COLOR_BLUE);     // Pareja 1 = Texto rojo, fondo azul
  init_pair(2, COLOR_YELLOW, COLOR_GREEN); // Pareja 2 = Texto amarillo, fondo verde
  attron(COLOR_PAIR(1));    // Activa pareja 1
  move(11, 1);
  printw("HOLA");
  attron(COLOR_PAIR(2));    // Activa pareja 2
  move(12, 1);
  printw("MUNDO");
  do
  {  
       carácter = getch();  // Lee un carácter desde el teclado
  }
  while (carácter != KEY_UP);
  endwin();  // Finaliza Ncurses
  return 0;
}
```

### 9.4.11. Librerías no estándar que molan: SDL

**SDL** (iniciales de *Single DirectMedia Layer*) es una biblioteca de C libre y disponible para múltiples plataformas (entre ellas, Linux y Windows). Puedes bajarte la última versión de [http://www.libsdl.org](http://www.libsdl.org).

Esta biblioteca contiene un conjunto muy completo de funciones para manejar gráficos, además de sonidos y distintos dispositivos multimedia (ratón, CD-ROM, etc). Muchos programas escritos en C (en particular, videojuegos) se han desarrollado con SDL. Además, la librería es razonablemente sencilla de usar.

La siguiente captura pertenece a un juego llamado *Unknown Horizons*, desarrollado en 2008 con la librería SDL y cuya última versión es del año 2019. Puedes encontrar en internet muchos otros ejemplos de programas escritos con SDL, tanto antiguos como recientes:

![Ejemplo de juego desarrollado con SDL](/docs/prog-y-3d/_site/assets/images/05-sdl-example.png)

Nosotros sólo nos vamos a centrar en la parte de SDL dedicada a los gráficos. Si quieres más información, en la página web reseñada antes encontrarás una completa documentación.

#### Instalación de SDL

SDL no es una librería C estándar, es decir, no viene "de serie" con el compilador de C. En realidad, tampoco *ncurses* lo es, pero su uso está tan extendido en entornos Unix que viene incorporada a las librerías del compilador gcc.

En cambio, la librería SDL debe ser instalada antes de poder utilizarla. A continuación describimos el proceso de instalación en Linux y en Windows

Existen dos paquetes de SDL: el *runtime*, necesario para ejecutar aplicaciones que usen SDL, y el *development*, necesario para escribir y compilar programas que usen SDL. Nosotros necesitaremos los dos, claro.


**Instalación de SDL en Linux**

* Instala el paquete libSDL-dev desde la tienda de aplicaciones de tu distribución Linux. Eso será suficiente para que se instalen los paquetes de desarrollo y de *runtime*.
* Si estos paquetes no estuvieran en tu repositorio (algo muy raro), puedes bajártelos de [libsdl.org](https://libsdl.org) e instalarlos manualmente. Consulta el manual de tu Linux para aprender a hacer esto último.

**Instalación de SDL en Windows**

* Bájate la última versión de la librería de la web de SDL. Necesitarás la librería de vínculos dinámicos (denominada dll), que es el *runtime* para Windows, y el paquete de desarrollo. 
* La librería de vínculos dinámicos suele venir comprimida en un archivo cuyo nombre es similar a: SDL-x.x.x.zip, donde "x.x.x" es la versión de la libería. Existirán varios paquetes de desarrollo para varios compiladores. Mi consejo es que bajes el que está preparado para el compilador de GNU, cuyo nombre es SDL-devel-x.x.x-mingw32.tar o algo similar. También encontrarás paquetes para otros compiladores.
* Descomprime la librería de vínculos dinámicos. Debes obtener un archivo llamado sdl.dll. Copia este archivo al directorio /windows/system32, o bien ubícalo en la misma carpeta en la que se encuentre el programa que estás escribiendo. 
* Descomprime el paquete de desarrollo. Encontrarás varios directorios y, dentro de ellos, multitud de archivos. Copia los archivos en los directorios del mismo nombre de tu compilador. Por ejemplo, el copia el directorio "include" del paquete de desarrollo al directorio "include" de la carpeta donde esté instalado tu compilador. Repite la operación para todos los directorios cuyo nombre coincida.

#### Compilación y enlace de SDL

Al no ser SDL una librería estándar, el enlace entre nuestro programa y las funciones de SDL no se produce automáticamente. Hay que indicarle al enlazador (o linker) lo que debe hacer.

Si estás utilizando **Visual Studio Code** con la extensión **Code Runner**, la forma de hacer que SDL se enlace con tu programa es, simplemente, incluir la libería SDL en tu código fuente:

```c
#include <SDL2/SDL.h>
```

Si ese include falla, tienes que segurarte de que Code Runner enlazará tu código con la librería SDL. Para ello, hay que agregar "-lSDL2" a la lista de argumentos de la tarea de compilación. Abre el archivo **tasks.json** que encontrarás en el directorio **.vscode** de tu proyecto. Encontrarás algo como esto:

```json
{
    "version": "2.0.0",
    "tasks": [
        {
            "label": "Compile C program with SDL",
            "type": "shell",
            "command": "gcc",
            "args": [
                "-o",
                "program",
                "main.c",
                "-lSDL2"
            ],
            "group": {
                "kind": "build",
                "isDefault": true
            }
        }
    ]
}
```

Mira en la sección "args". Si no aparece la línea "-lSDL2", añádela. Guarda el archivo y listo.

Si utilizas otro entorno de desarrollo distinto de Visual Studio Code, u otra extensión distinta de Code Runner dentro de Visual Studio Code, el proceso debe ser muy parecido, pero tendrás que mirar la documentación de ese entorno o de esa extensión para ver los detalles.

#### Inicialización y terminación de la pantalla gráfica

Una vez instalada la libería y preparado el compilador, podemos usar las funciones de SDL como cualquier otra función estándar de C. Su uso es exactamente igual en Windows y en Linux, por lo que el programa que obtendremos debería compilar sin necesidad de hacerle ningún cambio en ambos sistemas.

Para usar los gráficos, hay que hacer un ```#include <SDL/SDL.h>``` en el archivo fuente, como es natural. Aparece dos veces el nombre "SDL" porque el archivo SDL.h está dentro de una carpeta llamada SDL.

Lo siguiente que hay que hacer es **inicializar la pantalla gráfica**. Para eso disponemos de dos funciones: *SDL_Init()* y *SDL_SetVideoMode()*:

* ***SDL_Init()***. Debe ser la primera función en invocarse. No se puede usar ninguna otra función de SDL si antes no se ha llamado a esta. Hay que pasarle un parámetro que indica qué tipo de sistema multimedia queremos manejar (la tarjeta de vídeo, la de sonido, el CD-ROM, etc). En nuestro caso será la tarjeta de vídeo, ya que sólo nos interesa manipular gráficos. La constante para ello es SDL_INIT_VIDEO:

   ```c
   SDL_Init(SDL_INIT_VIDEO);
   ```

   La fución SDL_Init() devuelve –1 si ocurre algún error al iniciar el sistema de gráficos. En ese caso, el programa no podrá continuar, de modo que debemos comprobar el valor devuelto por SDL_Init().

* ***SDL_SetVideoMode()***. Esta debe ser la segunda función en invocarse, justo a continuación de SDL_Init(). Sirve para establecer el tipo de pantalla gráfica que queremos. Hay que indicarle el tamaño en píxels, el número de bits de color y los atributos de la pantalla. Por ejemplo:

   ```c
   SDL_SetVideoMode(1200, 960, 24, SDL_ANYFORMAT | SDL_DOUBLEBUFFER);
   ```
   
   Esto crea una ventana gráfica de 1200x960 píxeles, con 24 bits de profundidad de color. El último parámetro, *SDL_ANYFORMAT*, es una constante que indica a SDL que puede seleccionar otra profundidad de color si la elegida no está disponible. Este cuarto parámetro puede tomar otros muchos valores que no vamos a ver, pero sí señalaremos que es conveniente añadir la constante *SDL_DOUBLEBUFFER* por motivos de rendimiento (ver ejemplo más abajo).
   
   *SDL_SetVideoMode()* devuelve un puntero a una estructura llamada *SDL_Surface*, definida en *SDL.h*, o NULL si ocurre algún error. Este puntero nos será imprescidible para manejar la pantalla gráfica, así que **debes guardarlo en una variable**. 
   
   Esta variable, además, debe ser **global** si se va a usar en otras partes del programa, contraviniendo una de las buenas prácticas de programación más universales que existen. Sin embargo, si no lo haces así, la variable no funcionará correctamente.
   
   Aquí tienes un ejemplo de inicialización de la pantalla gráfica:
  
```c
  #include <SDL/SDL.h>  
  ...
  SDL_Surface *pantalla;	// Esta variable debe ser GLOBAL
  ...
  if (SDL_Init(SDL_INIT_VIDEO) == -1) {
    puts("Error en la inicialización del sistema de vídeo\n");
    SDL_Quit();
    exit(-1);
  }

  pantalla = SDL_SetVideoMode(1280, 960, 16, SDL_ANYFORMAT|SDL_DOUBLEBUF);
  if (pantalla == NULL) {
    puts("Fallo al establecer el modo de vídeo\n");
    SDL_Quit();
    exit(-1);
  }
  ...
  SDL_Quit();		// Esto se hace al final del programa
```

Tan importante como inicializar la pantalla gráfica es **finalizarla**. Ten en cuenta que la pantalla gráfica consume muchos recursos, y éstos deben ser liberados antes de que el programa termine su ejecución. Para eso tenemos la función *SDL_Quit()*, que se invoca sin argumentos (observa el ejemplo)

#### Dibujar gráficos en la pantalla

Ya tenemos nuestra pantalla gráfica inicializada y lista para empezar a dibujar en ella. Pero, ¿qué tipo de objetos se pueden dibujar?

Aunque las librerías gráficas permiten al programador **pintar píxels individuales** en cualquier punto de la pantalla, lo habitual es **trabajar con imágenes** previamente existentes llamadas ***sprites***. 

Un *sprite* es una imagen guardada en un archivo que puede ser cargada por el programa y mostrada en cualquier parte de la pantalla gráfica y tantas veces como sea necesario.

Por lo tanto, lo primero que necesitas es hacerte con una colección de sprites para tu programa. Si, por ejemplo, suponemos que estamos desarrollando un de ajedrez, necesitaríamos los siguientes:

* Una imagen del tablero.
* Una imagen de cada una de las piezas. 
* Opcionalmente, una imagen de fondo para decorar la pantalla.

Los archivos con las imágenes deben estar en formato BMP. SDL admite otros formatos, pero el BMP es fácil de manipular, así que es buena idea empezar por las imágenes BMP y luego, cuando ya las manejes bien, dar el salto a otros formatos con compresión, como JPG o PNG. Cualquier editor de imágenes te permitirá convertir tus *sprites* a BMP.

Para dibujar una imagen en cualquier punto de la pantalla, hay que hacer dos cosas que pasamos a describir con detalle:

* Cargar la imagen en la memoria (procedente de un archivo BMP)
* Mostrar la imagen en la pantalla

**1. Cargar imágenes en la memoria**

Sólo es necesario cargar las imágenes **una vez**. Normalmente, se hará **al principio del programa**, justo después de la inicialización de SDL. 

Una vez cargadas en la memoria, podremos utilizarlas tantas veces como las necesitemos, a menos que liberemos el espacio de memoria que ocupan. La liberación de espacio, por tanto, debería hacerse al final del programa, justo antes de terminar.

Para cargar una imagen BMP se usa la función *SDL_LoadBMP()*, de esta forma:

```c
  SDL_Surface *tablero;

  tablero = SDL_LoadBMP("tablero.bmp");
  if (tablero == NULL) {
     printf("Error al cargar el archivo tablero.bmp");
     SDL_Quit();
     exit(-1);
  }
```

Observa que *SDL_LoadBMP()* devuelve un puntero a *SDL_Surface*. Este puntero será necesario para luego mostrar la imagen en cualquier lugar de la pantalla. La variable "tablero" debe ser global si se va a usar en más de una función (si es local y la pasamos como parámetro a otra función, SDL fallará).

Las imágenes son rectangulares. En muchas ocasiones, necesitamos mostrar una imagen encima de otra. Es el caso de las piezas, que se mostrarán encima del tablero. Cuando esto ocurre, el color de fondo de la pieza (que decidimos que fuera negro) aparecerá encima del tablero como un desagradable recuadro de color negro. En estas situaciones, hay que avisar a SDL de que, para este *sprite* en concreto, el color negro (o el que decidamos) va a ser transparente, es decir, no debe ser mostrado. Esto se hace así:

```c
  SDL_Surface *peon_blanco;
  Uint32 color;	// Para definir el color de transparencia (donde proceda)

  // Cargamos la imagen del peón blanco
  peon_blanco = SDL_LoadBMP("peon_blanco.bmp");
  if (peon_blanco == NULL) {
     printf("Error al cargar el archivo peon_blanco.bmp");
     SDL_Quit();
     exit(-1);
  }
 
  // Definimos la transparencia (color negro = (0,0,0) )
  color = SDL_MapRGB(peon_blanco->format, 0, 0, 0);
  SDL_SetColorKey(cuadro1, SDL_SRCCOLORKEY | SDL_RLEACCEL, color);
```

Las imágenes cargadas en memoria deben ser liberadas antes de finalizar el programa con una llamada a SDL_FreeSurface(). Por ejemplo, para liberar la memoria ocupada por la imagen "tablero.bmp" que hemos cargado antes usaremos el puntero que obtuvimos al cargarla, así:

```c
SDL_FreeSurface(tablero);
```

**2. Mostrar imágenes en la pantalla**

Una vez cargada una imagen BMP en la memoria, podemos mostrarla en la pantalla a través del puntero *SDL_Surface* que obtuvimos al cargarla. Una imagen cargada puede ser mostrada todas las veces que queramos en cualquier posición de la pantalla.

Por ejemplo, para mostrar la imagen del tablero (que cargamos en un ejemplo del apartado anterior) haríamos lo siguiente (luego comentamos el código):

```c
  SDL_Rect rect;
  rect = (SDL_Rect) {10, 10, 400, 400};
  SDL_BlitSurface(tablero, NULL, pantalla, &rect);
  SDL_Flip(pantalla);
```

La variable *rect* es de tipo *SDL_Rect*, y define un área rectangular de la pantalla. El área rectangular empieza en las coordenadas (10, 10) (esquina superior izquierda de la pantalla) y mide 400 píxels de ancho y 400 de alto, es decir, termina en (410, 410).

*SDL_BlitSurface()* es la función que se encarga de mostrar en la pantalla un *sprite*. La variable *tablero* es de tipo *SDL_Surface*, y debe ser la que nos devolvió *SDL_LoadBMP()* al cargar la imagen del tablero. La variable *pantalla* también es una *SDL_Surface*, y debe ser la que nos devolvió *SDL_SetVideoMode()* al inicializar la pantalla gráfica. Ya dijimos que los punteros que nos devuelven estas funciones son imprescidibles y que debíamos definirlos como variables globales. La variable *rect* es el área rectangular que acabamos de definir.

Fíjate que *rect* es la que indica en qué lugar de la pantalla va a aparecer el *sprite*. En este ejemplo, aparecerá en (10,10). Se le han reservado 400x400 píxels para dibujarse, es decir, hasta la posición (410, 410). Si el *sprite* es más pequeño, no pasará nada (ocupará lo que mida realmente). Si es más grande, se truncará.

Por último, *SDL_Flip()* hace que lo que acabamos de dibujar se muestre realmente en la pantalla. Su efecto es parecido al de la función refresh() de ncurses. En realidad, todo lo que dibujamos se escribe en una zona de memoria específica y, al hacer *SDL_Flip()*, esa zona de memoria se vuelca sobre la memoria de vídeo, apareciendo todo en la pantalla. Esto representa el movimiento de gran cantidad de información entre distintas zonas de memoria, lo cual es un proceso relativamente lento. Por eso, si vamos a dibujar varios sprites consecutivos, es mejor hacer una sola vez *SDL_Flip()*, al final, cuando los hayamos dibujado todos. Llamar a *SDL_Flip()* después de dibujar cada sprite ralentizará notablemente el funcionamiento de nuestro programa.

#### Control del teclado

Para leer el teclado en una ventana gráfica creada con SDL *no* se pueden usar las funciones estándar (como *getchar()* o *gets()*), ni mucho menos las de *ncurses* (como *getstr()*). 

SDL solo permite **leer los caracteres de uno en uno**, y **no muestra eco** por la pantalla (si queremos eco, tenemos que mostrar los caracteres nosotros mismos después de leerlos).

Por lo demás, la forma de capturar un carácter tecleado es similar a la de *ncurses*, solo que un poco más complicada. A continuación se muestra un código de ejemplo:

```c
SDL_Event evento;	  	      // Para leer el teclado

// Leer teclado
if (SDL_PollEvent(&evento))            // Comprobar si se ha pulsado una tecla
{
   if (evento.type == SDL_KEYDOWN)     // Efectivamente, se ha pulsado una tecla
   {
       switch (evento.key.keysym.sym)  // Vamos a mirar qué ecla es
       {
           case SDLK_UP:     ...acciones...; break;	// Flecha arriba
           case SDLK_DOWN:   ...acciones...; break;	// Flecha abajo
           case SDLK_LEFT:   ...acciones...; break;	// Felcha izquierda
           case SDLK_RIGHT:  ...acciones...; break;	// Flecha derecha
           case SDLK_RETURN: ...acciones...; break;	// Intro 
           case SDLK_ESCAPE: ...acciones...; break;	// ESC
           case SDLK_m:      ...acciones...; break;	// Tecla "m" (menú)
        }
    }
}
```

Existen constantes para cualquiera de las otras teclas del teclado. Todas empiezan por *SDLK_*. Por ejemplo, la tecla "a" tendrá el código *SDLK_a*.

#### Definición de colores

Aunque a menudo trabajes con *sprites* basados en imágenes preexistentes, es posible que también necesites definir algún color para usarlo directamente sobre la pantalla gráfica (por ejemplo, para usar transparencias o para escribir un texto).

En SDL no hay colores predefinidos, como en *ncurses*. Los colores debemos definirlos nosotros mezclando los colores básicos RGB (rojo, verde y azul).

Hay dos formas de definir un color: con una variable de tipo *SDL_Color* o con una variable de tipo *Uint32*. El uso de una u otra dependerá de para qué queramos usar ese color:

**a) Con una variable de tipo SDL_Color**:

   ```c
   SDL_Color color;
   color = (SDL_Color) {50, 150, 200, 255};
   ```

   Los cuatro números definen el color. Deben ser números comprendidos entre 0 y 255. El primero es el nivel de rojo (R), el segundo el nivel de verde (G) y el tercero, el nivel de azul (B). El cuarto número es el brillo. El color definido en este ejemplo tiene mucho azul, bastante verde y poco rojo. El resultado debe ser un azul amarillento.

**b) Con una variable de tipo Uint32**:

   ```c
   Uint32 color;
   color = SDL_MapRGB(pantalla->format, 50, 150, 200);  
   ```
   
   En esta ocasión, *pantalla* debe ser un puntero a una imagen *SDL_Surface* que hayamos cargado previamente. Los tres valores siguientes son los niveles RGB. No hay nivel de brillo, porque éste se toma de la imagen apuntada por *pantalla*.

De las dos maneras se pueden definir colores para usarlos posteriormente. Si el color lo necesitamos para una transparencia, recurriremos al segundo método (de hecho, ya vimos un ejemplo de ello al estudiar cómo se cargaban y mostaban las imágenes en SDL; allí usamos el color negro como transparencia). Si el color lo necesitamos para escribir un texto en la pantalla gráfica, usaremos el primer método (como se podrá ver en el siguiente apartado)

#### Mostrar texto en la pantalla gráfica: instalación y uso de la librería SDL_TTF

La librería SDL no permite directamente la escritura de texto en la pantalla gráfica. Esto se debe a que la pantalla gráfica, por definición, no admite caracteres, sino únicamente imágenes.

Por fortuna, a la sombra de SDL se han creado multitud de librerías adicionales que, partiendo de SDL, complementan y mejoran sus prestaciones. Una de ellas es SDL_TTF.

La libería SDL_TTF permite cargar fuentes *true type* que estén guardadas en archivos .ttf y manejarlas como si fueran imágenes BMP en la pantalla gráfica generada por SDL. Necesitamos SDL_TTF, por lo tanto, para escribir los mensajes de usuario y las opciones del menú.

La **instalación** de la librería SDL_TTF es similar a la de SDL, tanto en Linux como en Windows, de modo que puedes remitirte al apartado correspondiente para recordar cómo se hacía. Lo mismo puede decirse en cuanto a la compilación y el enlace.

Igual que SDL, la librería SDL_TTF necesita ser **inicializada** antes de usarla, y **finalizada** antes de terminar el programa para liberar los recursos adquiridos.

Como SDL_TTF corre por debajo de SDL, debe ser inicializada después de SDL, y debe ser terminada antes que SDL. Observa cómo se hace en este ejemplo:

```c
  if(TTF_Init() == -1) {
    printf("Fallo al inicializar SDL_TTF");
    exit(-1);
  }  
```

Inmediatamente después, ya podemos cargar una fuente true type de un archivo TTF, así:

```c
  TTF_Font* fuente;
  ....
  fuente = TTF_OpenFont("arial.ttf", 14);
  if(fuente == NULL) {
    printf("Fallo al abrir la fuente");
    exit(-1);
  }
  TTF_SetFontStyle(fuente, TTF_STYLE_BOLD);
```

La variable *fuente* es un puntero a *TTF_Font*. Debe ser una variable global por el mismo motivo que las variables *SDL_Surface*. La función *TTF_OpenFont()* abre el archivo "arial.ttf" y carga el tipo de letra Arial en tamaño 14 para su uso en el programa. Después es conveniente comprobar que el puntero *fuente* contenga un valor válido y no NULL.

Por último, la función *TTF_SetFontStyle()* puede usarse para determinar el estilo de la fuente. Tenemos varias posibilidades: *TTF_STYLE_BOLD* (negrita), *TTF_STYLE_ITALIC* (cursiva), *TTF_STYLE_UNDERLINE* (subrayado) y *TTF_STYLE_NORMAL*. Si queremos combinar varios estilos, podemos separarlos por el operador "|". Por ejemplo, para poner la fuente en negrita y cursiva escribiríamos esto:

```c
  TTF_SetFontStyle(fuente, TTF_STYLE_BOLD | TTF_STYLE_ITALIC);
```

El proceso de **finalización** del SDL_TTF es inverso y complementario al de inicialización. Primero habrá que liberar todas las fuentes cargadas durante la inicialización, y luego hay que terminar el subsistema SDL_TTF:

```c
  TTF_CloseFont(fuente); 
  TTF_Quit();
```

La variable *fuente* será de tipo *TTF_Font*, y debe coincidir con la que nos devolvió la función *TTF_OpenFont()*. Esta operación la repetiremos con cada una de las fuentes que hayamos cargado.

Recuerda que todo esto debe hacerse ANTES de *SDL_Quit()*, ya que SDL_TTF depende de SDL.

#### Escribir texto con SDL_TTF

Todo esto lo hacemos con un objetivo: poder escribir texto en la pantalla gráfica y sustituir así todas las funciones *printw()* y similares.

Para escribir un texto hay que hacer dos cosas: **primero, convertirlo en una imagen; segundo, mostrar la imagen en la pantalla**.

La conversión de un texto en una imagen se hace con la función *TTF_Render()*:

```c
  SDL_Color color;
  SDL_Surface* txt_img;

  color = (SDL_Color) {255,100,100,255};
  txt_img = TTF_RenderText_Blended(fuente, "Hola mundo", color);
  if(txt_img == NULL) {
	printf("Fallo al renderizar el texto");
	exit(-1);
  }
```

Como ves, hay que hacer bastantes cosas para mostrar un texto en la pantalla gráfica, pero todo es acostumbrarse. Primero, hay que definir un color para el texto (cómo se definen los colores es algo que vimos en el epígrafe anterior). En este caso, hemos escogido un rojo brillante.

Después se invoca a *TTF_RenderText()*, pasándole como parámetros el puntero a la fuente que obtuvimos con *TTF_OpenFont()*, el texto que queremos mostrar y el color. La función nos devuelve un puntero de tipo *SDL_Surface* que, si recuerdas, es exactamente el mismo que usábamos con las imágenes cargadas desde un archivo BMP.

En realidad, la función *TTF_RenderText()* tiene tres formas:

* *TTF_RenderText_Solid()* - realiza una conversión del texto en imagen rápida pero de poca calidad.
* *TTF_RenderText_Shaded()* - la imagen resultante es de gran calidad pero tiene un recuadro negro alrededor
* *TTF_RenderText_Blended()* - la imagen resultante es de gran calidad y sin recuadro negro

En general preferiremos el modo *Blended*, que es el que proporciona mejores resultados. El modo *Shaded* se puede usar en determinados lugares (si no hay otra imagen debajo del texto). El modo *Solid* sólo debe usarse si hay que mostrar mucho texto y el modo *Blended* se revela demasiado lento.

Hasta aquí, sólo hemos convertido el texto "Hola mundo" en una imagen, pero aún no la hemos mostrado en la pantalla. Para hacerlo procederemos como con cualquier otra imagen:

```c
  // Mostramos el texto como si fuera una imagen
  rect = (SDL_Rect) { 500, 280, 100, 30 };
  SDL_BlitSurface(txt_img, NULL, pantalla, &rect);	
  SDL_Flip(scr);
```

Se supone que *rect* es de tipo *SDL_Rect* y que pantalla es el puntero a *SDL_Surface* que nos devolvió *SDL_SetVideoMode()* al inicializar SDL. Así, el texto "Hola mundo" se mostrará en la posición (500, 280) de la pantalla gráfica, reservándose para él 100 píxels de ancho y 30 de alto.

