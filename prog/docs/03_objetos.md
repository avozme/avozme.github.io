---
layout: page
title: 3. Los objetos
permalink: /introduccion-programacion/
nav_order: 3
has_children: true
parent: Programación
---
# UD 3. Los objetos. Una introducción a la POO
{: .no_toc }
![Imagen de introducción al tema 3](/docs/prog/_site/assets/images/03_intro.jpg)

## Índice
{: .no_toc }
- TOC
{:toc}


En este capítulo introduciremos los conceptos básicos sobre programación orientada a objetos y aprenderemos a construir nuestras primeras clases y, con ellas, nuestros primeros programas verdaderamente orientados a objetos.

En los manuales de introducción a la programación hay dos tendencias: una, que ha quedado un poco desfasada, consiste en ignorar todas las cuestiones relativas a los objetos y centrarse al principio en las estructuras de control. Este enfoque está heredado de los manuales de programación clásicos, pues consiste, básicamente, en aprender programación estructurada y, más adelante, encajar las destrezas aprendidas en el paradigma de orientación a objetos.

La segunda tendencia, que es la que se está imponiendo en la actualidad y que seguiremos aquí, consiste en programar dentro del paradigma orientado a objetos desde el minuto cero, de modo que el aprendiz no tenga que hacer ninguna adaptación mental posterior: tus primeros programas ya serán aplicaciones 100% orientadas a objetos y, por tanto, asimilará ese modo de trabajar de manera paulatina y natural, sin los vicios ocultos que a veces tienen los programadores que llegan a la programación orientada a objetos procedentes de la programación estructurada clásica.

En este tema expondremos en qué consiste el famoso paradigma, utilizando para ello ejemplos y analogías que lo harán fácilmente comprensible. Después definiremos los elementos principales tales como clases, objetos, métodos o atributos. Construiremos nuestras primeras clases y diremos algunas cosas interesantes sobre los paquetes de Java. Terminaremos el tema explicando cómo hacer operaciones de entrada/salida con el usuario, de manera que podamos empezar a construir programas interactivos y funcionales.

## 3.1. Entendiendo la programación orientada a objetos

#### Pensamiento orientado a objetos

Java es un lenguaje orientado a objetos: pero, ¿qué significa exactamente “orientado a objetos”? Para responder a esta pregunta, primero tenemos que comprender en qué consiste la programación tradicional o “no orientada a objetos”.

En programación tradicional, cualquier problema informático se resuelve codificando un conjunto de algoritmos que trabajan sobre un conjunto de datos. Es decir, los datos son elementos pasivos: es el código el que se encarga de hacer todo el trabajo por ellos. 

A medida que los proyectos crecen, el código también lo hace, y llega un momento en el que es imposible saber cómo funciona todo el sistema. Surgen interacciones imprevistas e impredecibles entre distintas partes del programa. El fallo más tonto, como un error tipográfico, puede convertirse en una pesadilla cuya localización puede suponer muchas horas de trabajo (y, en consecuencia, mucho dinero). 

Como dice Yukihiro Matsumoto, creador del lenguaje Ruby, el mantenimiento de estos programas se convierte en algo parecido a transportar un calamar gigante intentado que ninguno de sus tentáculos te alcance la cara.

Lo que hace la programación orientada a objetos es cambiar la forma de trabajar. No supone una revolución con los métodos anteriores, sino un cambio en la forma en la que se hacen las mismas cosas de siempre. La mayoría del trabajo se delega a los propios datos, de modo que los datos ya no son estáticos, sino que se encargan de mantenerse en forma a sí mismos. De nuevo en palabras de Matsumoto: dejamos de tratar cada pieza de dato como una caja en la que se puede abrir su tapa y arrojar cosas en ella y empezamos a tratarlos como máquinas funcionales cerradas con unos pocos interruptores y diales bien definidos. 

Lo que se define anteriormente como una “máquina” puede ser, en su interior, algo muy simple o muy complejo. No se puede saber desde el exterior y no se nos permite abrir la máquina (excepto cuando estamos completamente seguros de que algo está mal en su diseño), por lo que se nos obliga a utilizar los interruptores y leer los diales para interactuar con los datos. Una vez construida una de esas máquinas, no queremos tener que volver a pensar en cómo funciona internamente. 

#### Un ejemplo sencillo para entender las clases y los objetos

Pongamos un ejemplo sencillo para entender el concepto de objeto y de “máquina con unos pocos interruptores y diales”.

Seguramente en tu cocina tienes un horno microondas (aunque, en realidad, para este ejemplo podrías elegir cualquier electrodoméstico). El horno consta, entre otros muchos subsistemas, de un temporizador. Su trabajo consiste en mantener el horno encendido durante un tiempo determinado por el usuario. ¿Cómo podríamos representar esto en un lenguaje de programación? En Java, por ejemplo, el temporizador podría ser, simplemente, una variable numérica de tipo float o double. El programa manipularía esa variable disminuyendo el valor una vez por segundo, y permitiría al usuario establecer el tiempo inicial del temporizador antes de poner el horno en marcha.

Con este enfoque tradicionalista, un error en cualquier parte del programa podría terminar asignando un valor falso a la variable, como un número negativo o un tiempo de varias horas. Hay un número infinito de razones inesperadas por las que podría llegar a suceder esto. Cualquiera con cierta experiencia programando sabe que se pueden perder horas o días tratando de encontrar ese error.

Pero si programamos con un lenguaje orientado a objetos, no pensaremos en el tipo de datos que mejor se ajusta a un temporizador de microondas, *sino en el modo en el que un temporizador de microondas funciona en el mundo real*. No parece una gran diferencia, pero lo es.

El programador, o el diseñador, necesitará dedicar cierto tiempo a decidir qué es exactamente un temporizador de microondas y cómo se espera que el mundo exterior interactúe con el. Por fin, construirá una pequeña máquina (una pieza de software) con controles que permitan establecer, consultar y disminuir su valor.

El temporizador se crea, por ejemplo, sin un mecanismo para asignarle un valor arbitrario, por la sencilla razón de que los temporizadores de microondas no trabajan de esa forma: solo permiten asignar múltiplos de 10 segundos, por lo general. Existen sólo unas cuantas cosas que un temporizador de microondas puede hacer, y sólo permitiremos esas cosas. Así, si alguien desde otra parte del programa trata de asignar algún valor no permitido al temporizador, como un número negativo, le resultará imposible hacerlo. Estaremos protegiendo una parte del programa de errores cometidos en otras partes y que, en programación tradicional, se propagan como el fuego en un tanque de gasolina.

Por si fuera poco, los lenguajes orientados a objetos nos permiten que, una vez que hayamos diseñado un temporizador de microondas (o el objeto que sea), podamos fabricar tantos como sea necesario. Habremos creado un patrón o molde de temporizador y, a partir de ese molde, se pueden construir objetos diferentes (pero similares) indefinidamente.

Pues bien, el molde se conoce como **clase**, y cada temporizador concreto que fabriquemos a partir de él se conoce como **objeto**.

Aclaremos, sin embargo, que la programación orientada a objetos no es una solución milagrosa: nada impide, en cualquier lenguaje, escribir código poco claro, descuidado, inestable o directamente erróneo.

A continuación hablaremos de los “interruptores y diales” del temporizador del microondas (**métodos**) y, en próximos temas, veremos como se construyen los moldes (**clases**).

#### Métodos

En la programación orientada a objetos, como acabamos de ver, no se piensa en manipular los datos directamente desde el exterior de un objeto, si no que son los propios objetos los que deciden cómo se debe operar sobre ellos. Se pasa un mensaje al objeto y este mensaje provoca algún tipo de acción o respuesta significativa por parte del objeto. Esto ocurre sin que nos importe cómo realiza el objeto, interiormente, el trabajo. 

Las tareas que podemos pedir que un objeto realice (o lo que es lo mismo, los mensajes que comprende) son los **métodos**. 

En Java, se llama a un método con la notación punto (como en C++, Python, Ruby o muchos otros lenguajes). El objeto con el que nos comunicamos se nombra a la izquierda del punto. Por ejemplo: 

```java
String mi_cadena = "Esto es una cadena de caracteres";
System.out.println("La longitud de la cadena es: " + mi_cadena.length());
```

La salida por pantalla será:

```text
La longitud de la cadena es 32
```

Intuitivamente es fácil de comprender: a este objeto cadena se le está pidiendo que diga la longitud que tiene (y, como es una cadena de caracteres, nos responde con la cantidad total de letras de que consta). Técnicamente, lo que hemos hecho se llama *invocar el método length() del objeto mi\_cadena*. 

Otros objetos pueden hacer una interpretación un poco diferente de length. La decisión sobre cómo responder a un mensaje, o si se responde en absoluto, se toma durante la ejecución del programa, y la acción cambiará dependiendo de la variable que se use. 

```java
String mi_cadena = "Esto es una cadena de caracteres";
String[] mi_array = {mi_cadena, "Otra cadena"};
System.out.println("La longitud de la cadena es: " + mi_cadena.length());
System.out.println("La longitud del array es: " + mi_array.length());
```

La salida por pantalla será: 

```text
La longitud de la cadena es 32
La longitud del array es 2
```

Por lo tanto, lo que haga length() variará dependiendo del objeto con el que estemos hablando. En el primer caso, le pedimos a mi\_cadena su longitud. Como se trata de una cadena de caracteres, solo hay una respuesta posible. En el segundo caso, se lo pedimos a mi\_array, que es una colección compuesta por dos cadenas. Podríamos pensar que el método length() pudiera contar todos los caracteres en total almacenados en el objeto (43 en total). Pero lo más plausible es que nos devuelva 2, que es el número de elementos del array.

No importa si por el momento no entiendes bien lo que son los strings o los arrays. Lo que hay que tener en cuenta ahora es que el objeto array conoce lo que significa ser un array, y el string, lo que significa ser string, y ambos saben exactamente lo que tienen que hacer si les pedimos que nos calculen su propia longitud (lenght). 

En Java, las piezas de datos llevan consigo ese conocimiento, por lo que las solicitudes que se les hace se pueden satisfacer en las formas adecuadas para el tipo de dato. Esto libera al programador de la carga de memorizar una gran cantidad de nombres de funciones, ya que una cantidad relativamente pequeña de nombres de métodos, que corresponden a conceptos que sabemos como expresar en lenguaje natural, se pueden aplicar a diferentes tipos de datos siendo el resultado el que lógicamente cabría esperar. Esta característica de los lenguajes orientados a objeto se conoce como **polimorfismo**. 

Cuando un objeto recibe un mensaje que no conoce, se produce un error. Por lo tanto, hay que conocer qué métodos son aceptables para un objeto, aunque no se necesita saber como están programador por dentro. Los métodos, insistimos, son como los diales del horno microondas: como usuario, tienes que saber qué diales existen y cómo usarlos, pero no cómo están construidos por dentro.

#### Atributos

Los **atributos** de un objeto definen las características del mismo. Por ejemplo, un atributo del temporizador del microondas debería ser el número de segundos que éste debe permanecer activo, y un atributo de un objeto de tipo String debe de ser el número de caracteres de que consta la cadena.

Al programador que usa un objeto deberían importarle un bledo los atributos del mismo. Él (o ella) se encargará de usar el objeto a través de sus métodos, y éstos operarán con los atributos, si ello es necesario, de forma totalmente transparente al programador. Es decir, los atributos raramente son accesibles desde el exterior del objeto, salvo que, por razones de diseño, el programador del objeto haya decidido lo contrario.

## 3.2. Definiciones formales: clase, objeto, método, atributo

Una vez vista de manera informal la filosofía que subyace en el paradigma de orientación a objetos, pasamos a enumerar de manera más formal los diferentes conceptos que aparecerán de ahora en adelante de manera insistente. Como hemos dicho muchas veces, no te preocupes (de momento) si no entiendes todo lo que aquí se dice. Preocúpate solo si, al finalizar el libro, sigues sin saber qué son algunos de los siguientes conceptos.

#### Objetos

Un objeto es una unidad que engloba dentro de sí un conjunto de datos y las funciones necesarias para el tratamiento de esos datos. 

Un objeto se caracteriza por:

* Su identidad: cada objeto es único y diferente del resto. Internamente se le asigna un ID para diferenciarlo de otros objetos, aunque pertenezcan a la misma clase y tengan todos sus valores internos con el mismo valor.

* Su estado: el estado de un objeto viene dado por el valor de sus atributos o variables internas.

* Su comportamiento: el comportamiento de un objeto se define mediante los métodos o fragmentos de código que operan con los atributos internos del objeto e interactúan, si es necesario, con otros objetos. 

#### Atributos

Los atributos son los datos incluidos en un objeto. Son como las variables en los lenguajes de programación clásicos, pero están encapsuladas dentro de un objeto y, salvo que se indique lo contrario, son invisibles desde el exterior.

#### Métodos

Se llaman métodos a las funciones que pertenecen a un objeto. Es decir: son fragmentos de código con un nombre que permite invocarlos y ejecutarlos, pero están encapsulados dentro del objeto. Tienen acceso a los atributos del mismo y son la forma de operar con los atributos desde el exterior del objeto. Son, en definitiva, los "diales" de la caja negra. 

#### Clases

Una clase es un patrón para construir objetos. Por tanto, un objeto es una variable perteneciente a una clase determinada. Es importante distinguir entre objetos y clases: la clase es simplemente una declaración, no tiene asociado ningún objeto. Y todo objeto debe pertenecer a una clase.

#### Mensajes

El mensaje es el modo en que se comunican los objetos entre sí. Un mensaje no es más que una llamada a un método de un determinado objeto. Cuando llamemos a un método de un objeto, a menudo diremos que estamos enviando un mensaje a ese objeto, y el objeto reaccionará ejecutando el código asociado a ese mensaje. 

#### Interfaz

Las clases (y, por lo tanto, también los objetos) tienen partes públicas y partes privadas. La parte pública es visible para el resto de los objetos, mientras que la privada sólo es visible para el propio objeto. A la parte pública de un objeto se le denomina interfaz. 

## 3.3. Características de la POO: abstracción, encapsulamiento, herencia y polimorfismo

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

## 3.4. Ventajas de la OOP

La OOP se ha impuesto con fuerza en las dos últimas décadas, y no ha sido por casualidad. De hecho, proporciona varias ventajas importantes a la hora de desarrollar y mantener aplicaciones software, que se traducen, en definitiva, en un ahorro de tiempo y esfuerzo. Y, en consecuencia, de dinero.

Estas ventajas son:

* **Modularidad**: el código de un objeto puede modificarse, mantenerse o mejorarse sin que ello afecte al resto del sistema, siempre que respetemos su interfaz (así, los demás objetos del programa se seguirán comunicando con el objeto modificado sin que sepan que éste ha cambiado)

* **Reutilización de código**: es muy sencillo utilizar clases y objetos de terceras partes. Solo tienen que publicar el interfaz de sus clases, y podemos empezar a usarlas en muy poco tiempo, sin preocuparnos de cómo funcionan por dentro, igual que el técnico de la lavadora sustituye una pieza electrónica por otra sin saber exactamente como están hechas.

* **Facilidad de prueba y mantenimiento**: si tenemos un objeto que está dando problemas, es fácil aislar el elemento que falla y modificarlo sin que ello afecte al resto del código de la aplicación.

* **Ocultación de información**: como cada objeto oculta los detalles de su implementación al resto, es virtualmente imposible que un malfuncionamiento en una parte del sistema pueda afectar a otras.

## 3.5. Declaración de clases y objetos en Java

Para crear un objeto y empezar a usarlo, es necesario que antes exista una clase (el molde)

Veremos más detalles sobre cómo crear clases en el tema 4, porque Java puede llegar a ser muy sutil en esto. Por ahora, aprenderemos a declarar clases simples. 

En Java, la forma más simple de declarar una clase es ésta:

```java
class MiClase {
   private static int miAtributo1;
   private float miAtributo2;

   public void miMetodo1() {
      <código del método>
   }

   public int miMetodo2(int a, b) {
      int r;
      <código del método>
      return r;

   }
}
```

En este ejemplo, hemos declarado una clase llamada MiClase (que debemos guardar en un archivo llamado MiClase.java). La clase tiene dos atributos, miAtributo1 y miAtributo2, uno de tipo int y otro de tipo float. Ambos son private, lo que significa que no son accesibles desde fuera de la clase (típico de los atributos). Además, uno de ellos es static, es decir, solo se creará una vez aunque se definan varios objetos de esta clase.

Después, aparece la definición de dos métodos. Ambos son public, esto es, pueden ser usados por otros objetos externos a esta clase. El primero no devuelve ningún resultado (void), y el segundo devuelve un valor entero (int). Este último, además, tiene una variable local de tipo int llamada r.

Recuerda que la clase solo es un molde, un patrón. La forma de crear un objeto usando este molde es esta:

```java
MiClase miObjeto = new MiClase;
```

A partir de este momento existirá una variable en el programa llamada miObjeto en cuyo interior existirán todos los elementos de MiClase: los atributos y los métodos. Y podemos crear todos los objetos que necesitemos a partir de ese molde.

#### Un ejemplo más realista

Supongamos que estamos desarrollando una aplicación para administrar los datos personales y académicos del alumnado de un instituto. Dentro de la aplicación, hemos detectado que existe un tipo de dato llamado "persona" (también podría haber sido "alumno"), que tiene ciertas características (nombre, edad, sexo, etc) y con el que se pueden llevar a cabo ciertas operaciones (asignarle un nombre, preguntarle cuál es su edad, etc)

Esas características son los atributos. Esas operaciones son los métodos. Así, el aspecto de la clase Persona sería, más o menos, este:

```java
class Persona {

   private String nombre;
   private String apellido;
   private int edad;
   private char sexo;

   public String getNombre() {
      return nombre;
   }
   public void setNombre(String txt) {
      nombre = txt;
   }

   public String getApellido() {
      return apellido;
   }
   public void setApellido(String txt) {
      apellido = txt;
   }

   public int getEdad() {
      return edad;
   }
   public void setEdad(int n) {
      edad = n;
   }

   public String getSexo() {
      String s;
      if (sexo == 'H') s = "Hombre";
      if (sexo == 'M') s = "Mujer";
      if (sexo != 'H') && (sexo != 'M') s = "Desconocido";
      return s;
   }
   public void setSexo(char s) {
      sexo = s;
   }
}
```

Observa como los atributos son privados, y hemos definido un método público para consultar y modificar cada uno de ellos. Los métodos saben cómo deben proceder con los atributos, y el programador que usa la clase no deben preocuparle esos detalles: una vez escrita y probada la clase, podemos olvidarnos de ella y usarla sin tener en cuenta su implementación. Solo tenemos que conocer cuáles son sus métodos públicos y para qué sirve cada uno.

Este es un ejemplo de cómo podríamos usar esta clase para crear una persona llamada Miguel Pérez, de 23 años de edad y sexo masculino:

```java
class PersonaMain {

   public static void main(String[] args) {
      Persona a = new Persona();
      a.setNombre("Miguel");
      a.setApellido("Pérez");
      a.setEdad(23);
      a.setSexo('H');
      // Ahora vamos a mostrar por pantalla la información
      // para asegurarnos que todo se ha almacenado correctamente
      System.out.println("Nombre: " + a.geNombre() + " " +
                                      a.getApellido());
      System.out.println("Edad: " + a.getEdad());
      System.out.println("Sexo: " + a.getSexo());
    }
  }
```

Si compilamos y ejecutamos el programa PersonaMain, la salida por pantalla debería ser esta:

```text
Nombre: Miguel Pérez
Edad: 23
Sexo: Masculino
```

Observa que, aunque en el interior del objeto el sexo se almacena como un carácter H, al recuperarlo con getsexo() se nos devuelve el string "Masculino". Ese es el comportamiento del objeto y, como usuarios del mismo, no nos importa cuál es el procedimiento interno por el que se ha obtenido ese resultado. Lo usamos y punto.

Por cierto: para usar la clase Persona desde la clase PersonaMain, NO debes hacer import persona ni nada parecido, porque eso solo sirve para importar paquetes y no clases individuales. Basta con que ambas clases residan *en el mismo directorio*.

## 3.6. Más sobre métodos

### 3.6.1. Paso de parámetros

Los métodos pueden recibir una serie de valores denominados parámetros. En la clase Persona del ejemplo anterior, el método setEdad(), por ejemplo, recibía un parámetro de tipo int llamado n. En ese parámetro se indica al método cuál es la edad que debe almacenarse en el estado del objeto.

Por lo tanto, los parámetros son imprescindibles para que el objeto reciba los mensajes correctamente. Si no, ¿cómo le indicaríamos al objeto de tipo Persona cuál es la edad que tiene que almacenar?

Un método puede tener una lista larguísima de parámetros, o ninguno. Lo más habitual es que tenga entre cero y unos pocos. 

En la declaración del método hay que indicar el tipo de cada parámetro. Observa este ejemplo:

```java
public void setDatos(String nombre, String apellido, int edad, char sexo)
```

Este hipotético método setDatos() podría servir para asignar valor a todos los atributos de la clase Persona del ejemplo anterior. Por supuesto, cuando llamemos al método setDatos() para que se ejecute, será necesario pasarle cuatro datos que coincidan en tipo con los cuatro parámetros. Esta podría ser una posible invocación:

```java
p = new Persona();
p.setDatos("Ana", "Sánchez", 45, 'M');
```

Esas dos líneas de código, pues, son equivalentes a estas otras:

```java
p = new Persona();
p.setNombre("Ana");
p.setApellido("Sánchez");
p.setEdad(45);
p.setSexo('M');
```

Al pasar un parámetro a un método, por tanto, **se copia el valor de dato en el argumento** del método. Por ejemplo, al hacer p.setEdad(45), estamos copiando un dato (el número 45\) en el parámetro edad del método setEdad() del objeto de tipo Persona.

Pero los valores no siempre se copian. De hecho, existen dos formas de enviar parámetros a un método:

* **Paso de parámetros por valor**: este es el caso que hemos visto hasta ahora. Los datos se copian en los argumentos del método. Esto quiere decir que el método trabaja con una copia de los datos originales. Si el método los altera de alguna manera, los datos originales NO se modifican, porque el método trabaja con su propia copia de los datos.

* **Paso de parámetros por referencia**: en este caso, el método no trabaja con una copia de los datos, sino con los datos mismos. Por lo tanto, si el método altera esos datos de alguna manera, los datos originales también se ven afectados, puesto que son los mismos.

En Java, no se puede elegir el tipo de paso de parámetros que queremos usar, sino que Java lo decidirá por nosotros: el paso de parámetros por valor es el que Java utiliza con los tipos primitivos (variables de tipo int, double, char, etc). El paso de parámetros por referencia, en cambio, se usa con el resto objetos complejos (como String, ArrayList o muchos otros que iremos viendo a lo largo del curso)

Por ahora no te preocupes demasiado por esto del paso de parámetros por valor y por referencia. Lo iremos comprendiendo poco a poco, con la práctica, y volveremos a ello desde un punto de vista más formal en el Tema 5\. Si has seguido el curso con aprovechamiento hasta entonces, verás como lo comprendes todo mucho mejor.

### 3.6.2. Devolución de resultados

Probablemente habrás observado que algunos métodos terminan con la sentencia **return** y otros nos. Los que sí lo hacen devuelven un resultado al código que los llamó. Ese resultado puede ser de cualquier tipo y también hay que indicarlo en la declaración del método.

El método seDatos() anterior no devuelve nada, por lo que, en la declaración, se usa la palabra void (vacío). Pero el método getEdad(), por ejemplo, devuelve un valor entero (la edad de la persona), y por eso se indica int en la declaración:

```java
public int getEdad() {
   return edad;
}
```

### 3.6.3. Métodos y atributos static

Algunos métodos, como algunos atributos, pueden estar precedidos de la palabra **static**.

Esto quiere decir que, para esa clase, se creará solo una instancia de ese método o atributo. No importa si se crean 800 objetos de tipo Persona: el atributo o el método static solo se creará una vez, y los 800 objetos de esa clase, del primero al último, lo compartirán.

Esto no solo permite ahorrar recursos en términos de memoria, sino que a veces resulta muy útil (si no, ¡no lo habrían inventado\!). Por ejemplo, podemos usar un atributo static para llevar la cuenta del número de personas que se han creado:

```java
class Persona {

   // Al crear la primera persona, esta variable se pondrá a 0
   private static int numPersonas = 0;   

   static void contarNuevaPersona() {
      // Incrementamos el contador de personas
      numPersonas++;
   }

   // El resto de la clase sería igual que antes
}
```

Si cada vez que creamos un objeto de la clase persona llamamos al método contarNuevaPersona(), el atributo numPersonas se incrementará en una unidad y contendrá el número total de objetos de esa clase que existen. En cambio, si no fuera un atributo static, cada objeto Persona tendría su propio atributo puesto a 0 en el momento de su creación, y la llamada a contarNuevaPersona() establecería su valor a 1\.

Eso sí, tendremos que acordarnos de llamar a nuevaPersona() cada vez que creamos un objeto de tipo Persona, o, si no, no llevaremos bien la cuenta:

```java
Persona p = new Persona();
p.contarNuevaPersona();  // Si se nos olvida esto, la cuenta de personas
                         // ya no se será correcta.
p.setNombre("Miguel");
etc.
```

Es lógico suponer que siempre querremos llamar a contarNuevaPersona() cada vez que creemos un objeto Persona, ¿no? También es de suponer que se trata de una situación habitual, esto eso, que a menudo hay algún método que debemos invocar siempre justo después de crear un objeto. ¿Existirá alguna forma de hacerlo automáticamente, sin necesidad de confiar en la buena memoria del programador?

La respuesta, obviamente, es sí: los métodos constructores.

### 3.6.4. Constructores: primeros pasos

En Java existen dos tipos de métodos especiales llamados **constructores** y **destructores** de objetos. No es obligatorio programarlos para cada clase, pero sí que aparecen con frecuencia, sobre todo los constructores (de los destructores hablaremos más adelante)

El constructor es un método que es invocado automáticamente al crear un objeto de la clase. Su función suele ser **inicializar el estado del objeto**.

Por ejemplo, en la clase Persona de los ejemplos anteriores un posible constructor sería este:

```java
class Persona {

   Persona() {
      nombre = ""; apellido = "";
      edad = 0;
      sexo = 'X';
      contarNuevaPersona();
   }
   // El resto de la clase quedaría igual
}
```

Observa varias cosas importantes:

* El nombre del constructor debe coincidir con el de la clase.

* El constructor se ha usado para inicializar con valores vacíos todos los atributos de la clase.

* También se ha aprovechado para invocar el método nuevaPersona(), que contabiliza todos los objetos Persona creados por el programa. Así, esa contabilización se automatiza, porque nuevaPersona() será invocado siempre que se cree un objeto Persona. Ya no tenemos que confiar en la buena memoria del programador.

* El constructor no devuelve nada ni se indica su visibilidad (por definición, tiene que ser public)

* Los constructores pueden parametrizarse y, de hecho, sobrecargarse. Observa como en la siguiente variación de la clase Persona hay dos constructores, uno con parámetros y otro sin ellos:

```java
class Persona {

   Persona() {
      nombre = ""; apellido = "";
      edad = 0;
      sexo = 'X';
      nuevaPersona();
   }

   Persona(String n, String a, int e, char s) {
      nombre = n; apellido = a;
      edad = e;
      sexo = s;
      nuevaPersona();
   }

   // El resto de la clase quedaría igual
}
```

Esto es una excelente idea, porque ahora podemos crear personas por dos vías diferentes con el mismo resultado. Lo ilustramos en este ejemplo:

```java
// Creamos una persona con el constructor sin parámetros
// y luego le asignamos los valores
Persona p1 = new Persona();
p1.setNombre("Miguel");
p1.setApellido("Pérez");
p1.setEdad(23);
p1.setSexo('H');
// Ahora creamos otra persona con el constructor parametrizado
Persona p2 = new Persona("Luisa", "Martínez", 21, 'M');
```

Presentamos por último la versión "todo junto" de la clase Persona, con todos los elementos que hemos ido añadiendo (método static y constructor polimórfico)

```java
// Versión definitiva de la clase Persona

class Persona {

   private String nombre;
   private String apellido;
   private int edad;
   private char sexo;
   private static int numPersonas = 0;   // Al crear la primera persona,
                                         // esta variable se pondrá a 0
   // Constructor sin parámetros
   Persona() {
      nombre = ""; apellido = "";
      edad = 0;
      sexo = 'X';
      nuevaPersona();
   }

   // Constructor con parámetros
   Persona(String n, String a, int e, char s) {
      nombre = n; apellido = a;
      edad = e;
      sexo = s;
      nuevaPersona();
   }

   // Método estático para contar en número de personas creadas
   static void nuevaPersona() {
      numPersonas++;   // Se incrementa cada vez que se crea una persona
   }

   public String getNombre() {
      return nombre;
   }
   public void setNombre(String txt) {
      nombre = txt;
   }

   public String getApellido() {
      return apellido;
   }
   public void setApellido(String txt) {
      apellido = txt;
   }

   public int getEdad() {
      return edad;
   }
   public void setEdad(int n) {
      edad = n;
   }

   public String getSexo() {
      String s;
      if (sexo == 'H') s = "Hombre";
      if (sexo == 'M') s = "Mujer";
      if (sexo != 'H') && (sexo != 'M') s = "Desconocido";
      return s;
   }
   public void setSexo(char s) {
      sexo = s;
   }
}
```

## 3.7. Apéndice importante: entrada y salida por consola en Java

Vamos a terminar este tema mencionando la entrada de datos por teclado y la salida de datos por consola: dos cuestiones imprescindibles para realizar cualquier programa de empiece a hacer cosas interesantes.

Ambos dispositivos se manejan mediante la clase System. Esta clase está en el paquete java.lang, que se carga automáticamente en todas las aplicaciones Java, sin necesidad de hacer import (en el ejemplo de la sección anterior, por lo tanto, hicimos un poco de trampa al ejecutar import java.lang.System)

La clase System contiene tres objetos static que se crean automáticamente al ejecutar cualquier programa Java, y que se destruyen ellos solitos al terminar. Estos objetos son:

* **System.out:** para manejar la salida estándar (consola)

* **System.in:** para manejar la entrada estándar (teclado)

* **System.err**: para manejar la salida de errores. No la usaremos de momento.

La salida a través del objeto System.out y, en concreto, del método System.out.println(), ya la has visto en multitud de ejemplos. Simplemente, envía el String indicado entre paréntesis a la consola.

```java
System.out.println("Hola, mundo");
```

Algo más complicada es la entrada de datos por teclado. Observa con atención este ejemplo:

```java
char c;
try {
   c = (char) System.in.read();
} catch (Excepcion e) {
   e.printStackTrace();
}
```

¡Uf\! A menudo se dice que Java no es un lenguaje adecuado para aprender a programar, y esta es una de las ocasiones en las que uno piensa que esa afirmación podría ser cierta. Es arduo explicar a un principiante qué demonios pone ahí. Digamos que Java tiene una obsesión un pelín delirante por la seguridad, y que ese mamotreto que ves ahí arriba es un reflejo de ello.

Ese trozo de código sirve para leer un carácter, ¡un simple carácter\!, por el teclado, y almacenarlo en la variable c. Todo ello se envuelve en un bloque try-catch de manejo de excepciones, de forma que si ocurre algo inesperado (como que el usuario teclee veinte caracteres en lugar de uno, o que haya pulsado CTRL-C, o que la CPU haya explotado, o vaya usted a saber qué), el programa sea capaz de detectarlo y reaccionar adecuadamente.

No te agobies ahora por los detalles. Recuerda que, para hacer una entrada por teclado, necesitas copiar y pegar el código de más arriba, y adaptarlo a tus variables. Ya volveremos más adelante, cuando estemos preparados, sobre el manejo de excepciones y el bloque try-catch.

Si lo que quieres es algo más sencillito (aunque menos seguro, ojo), como leer una cadena de caracteres completa desde el teclado en lugar de un solo carácter sin tener que escribir veinte líneas de código, existen otras formas de lograrlo. Insisto, menos seguras, porque pueden producir errores de ejecución. Pero nos servirán para empezar.

Aquí tres de ellas: 

**Forma número 1: usando System.console()**

```java
String dato = System.console().readLine();
```

**Forma número 2: usando un objeto Scanner**

```java
Scanner sc = new Scanner();
String s = sc.nextLine();
```

**Forma número 3: usando un objeto BufferedReader**

```java
InputStreamReader isr = new InputStreamReader(System.in);
BufferedReader buff = new BufferedReader(isr);
String dato = buff.readLine();
```

La primera forma es la más sencilla. ¿Para qué montar tanto lío para leer unos cuantos caracteres del teclado? Bien, la biblioteca de clases de Java está diseñada para ser muy robusta y versátil, y eso hace que haya que pagar algún pequeño precio en cuanto a usabilidad y legibilidad en ocasiones.

De estas tres formas, la más ortodoxa es la tercera, pero también es la más complicada. En cambio, la segunda, es decir, usar el objeto Scanner, es la manera más versátil y cómoda. Esa es la forma en la que vamos a preferir leer el teclado a lo largo de los próximos temas, pero te ponemos aquí las tres formas para que te suenen, por si las ves en código escrito por ahí.

#### Cómo usar correctamente un objeto Scanner

* Importar el paquete java.util.Scanner

* Crear un objeto de tipo Scanner

* Pedirle al objeto de tipo Scanner que te lea datos por teclado, indicándole el tipo de dato que esperas obtener.

Aquí tienes un ejemplo un poco más completo para que puedas ver la entrada por teclado en acción:

```java
Scanner sc = new Scanner(System.in);  // Creamos el objeto scanner
System.out.println("Por favor, teclea tu nombre: ");
String nombre = sc.nextLine();
System.out.println("Ahora teclea tu edad: ");
int edad = Integer.nextInt();
System.out.println("Hola, " + nombre + ", tienes " + edad + " años");
```

Sí, lo has adivinado: sc.nextLine() te devuelve lo que sea que se haya tecleado convertido en un String, mientras que nextInt() te lo devuelve como un int. Como todo lo que se lee desde el teclado es, en principio, un String, esta última conversión podría fallar y debería estar dentro de un bloque try-catch, pero esa... esa es otra historia.

La mala noticia es esa: leer el teclado con Scanner podría fallar en algunas consolas. Para hacer un código totalmente confiable necesitas recurrir al BufferedReader, o sea, a la forma más complicada. El ejemplo anterior quedaría más o menos así (observa como hemos resumido en una línea la creación de los objetos InputStreamReader y BufferedReader):

```java
import java.io.*;
...

BufferedReader buff = new BufferedReader(new InputStreamReader(System.in));
try {
   String nombre = buff.readLine();
}
catch (Exception e) {
   e.printStackTrace();
}
System.out.println("Ahora teclea tu edad: ");
int edad = Integer.parseInt(buff.readLine());
System.out.println("Hola, " + nombre + ", tienes " + edad + " años");
```

Recuerda: sin agobios. Para hacer entrada por teclado, por el momento solo tienes que recordar tres palabras: **copia**, **pega** y **adapta**.

## EJERCICIOS PROPUESTOS

#### Ejercicio 3.1: Paso de parámetros por valor

Analiza el siguiente código y predice qué mostrará por pantalla ANTES de ejecutarlo.

Después, ejecútalo para comprobar si tenías razón.

```java
public class ParametrosPorValor {
    public static void main(String[] args) {
        int numero = 10;
        System.out.println("Antes de llamar al método: numero = " + numero);
        duplica(numero);
        System.out.println("Después de llamar al método: numero = " + numero);
    }

    public static void duplica(int n) {
        n = n * 2;
        System.out.println("Dentro del método: n = " + n);
    }
}
```

#### Ejercicio 3.2: Paso de parámetros por referencia

Analiza el siguiente código y predice qué mostrará por pantalla ANTES de ejecutarlo.

Después, ejecútalo para comprobar si tenías razón.

```java
class Persona {
    private int nombre = "Torcuato";
    String getNombre() {
        return this.nombre;
    }
    public void setNombre(String nombre) {
        this.nombre = nombre;
    }
}

public class ParametrosPorReferencia {

    public static void main(String[] args) {
        Persona miPersona = new Persona();
        System.out.println("Antes de llamar al método: nombre = " + miPersona.getNombre());
        asignaNombre(miPersona);
        System.out.println("Después de llamar al método: nombre = " + miPersona.getNombre());
    }

    public static void asignaNombre(Persona p) {
        p.setNombre("Robustiana");
        System.out.println("Dentro del método: nombre = " + p.getNombre());
    }

}
```

#### Ejercicio 3.3: Uso de return

Analiza el siguiente código y predice qué mostrará por pantalla ANTES de ejecutarlo.

Después, ejecútalo para comprobar si tenías razón.

```java
public class Ej2_03_UsoDeReturn {

    public static int multiplicaPorDos(int x) {
        x = x * 2;
        System.out.println("Dentro del método: x = " + x);
        return x;
    }

    public static void main(String[] args) {
        int numero = 5;
        System.out.println("Antes de llamar al método: numero = " + numero);

        multiplicaPorDos(numero);
        System.out.println("Después de llamar SIN guardar el resultado: numero = " + numero);

        numero = multiplicaPorDos(numero);
        System.out.println("Después de llamar GUARDANDO el resultado: numero = " + numero);
    }
}
```

#### Ejercicio 3.4: Clase RelojSolar

Crea una clase RelojSolar que permita convertir horas en distintos formatos:

* segundosADias(double segundos)

* horasAMinutos(double horas)

Recuerda:

* 1 día = 24 horas

  * 1 hora = 60 minutos

  * 1 minuto = 60 segundos

Crea otra clase para probar la anterior. Esta otra clase debe tener un método main() que pida al usuario una cantidad de tiempo (por ejemplo, segundos) y muestre su equivalente en días y horas.

#### Ejercicio 3.5: Clase ConversorMonedas

Crea una clase llamada ConversorMonedas que convierta **yenes** a **euros** y viceversa.  
Incluye dos constructores:

* ConversorMonedas() → establece el tipo de cambio a 0.006 (1 yen = 0.006 €)

  * ConversorMonedas(double tipoCambio) → permite configurar el tipo de cambio manualmente.

Métodos:

* double yenesAEuros(double yenes)

  * double eurosAYenes(double euros)

Escribe además un método main() en otra clase que pida al usuario una cantidad y muestre ambas conversiones.

#### Ejercicio 3.6: Clase MiContador

Crea una clase MiContador con los siguientes métodos:

* Constructor sin parámetros → inicializa el contador a 0  
* Constructor con parámetro entero → asigna un valor inicial  
* incrementa(int cantidad)  
* decrementa(int cantidad)  
* reset()  
* getValor()

Y además:

* getDoble(), getTriple(), getCuadruple() — devuelven el doble, triple y cuádruple del valor actual.

Escribe además una clase de prueba con el método main() que instancie un objeto MiContador y pruebe todos los métodos.

#### Ejercicio 3.7: Clase NaveEspacial

Crea una clase NaveEspacial que permita calcular distancias:

* `parsecsALightyears(double parsecs)`  
* `kilometrosAMillas(double km)`  
* `millasAMetros(double millas)`

*(1 parsec = 3.26156 años luz, 1 milla = 1.609 km, 1 milla = 1609 m)*

Crea otra clase con el método main(), que pedirá al usuario una distancia y mostrará las conversiones usando para ello la clase NaveEspacial.

#### Ejercicio 3.8: Clase Panadería

Una panadería artesanal necesita un programa que calcule cuántas **baguettes** puede hornear con la harina y el agua disponibles.

Cada baguette requiere:

* 250 g de harina  
  * 150 ml de agua

Crea una clase Panadería con estos métodos:

* Panaderia(double harinaKg, double aguaLitros)

  * addHarina(double kg)

  * addAgua(double litros)

  * getNumBaguettes()

  * horneaBaguette() → descuenta los ingredientes de una baguette

  * getHarina() → devuelve la harina restante (kg)

  * getAgua() → devuelve el agua restante (litros)

Crea además una clase de prueba con el método main(), que haga uso de la clase Panadería para probar que todos sus métodos funcionan.

#### Ejercicio 3.9: Clase ConversorMedidasInformación

Crea una clase ConversorDatos capaz de convertir cualquier medida de información en cualquier otra.

El constructor recibe un número y una unidad de medida ("bit", "byte", "KB", "MB", "GB", "TB").

Los métodos de la clase deben ser:

* `getBits()`  
* `getBytes()`  
* `getKB()`  
* `getMB()`  
* `getGB()`  
* `getTB()`

Cada uno devolverá la cantidad de información almacenada en la clase, pero convertida a la unidad de medida correspondiente. Usa potencias de 1024 (no 1000) para las conversiones.

Crea, como siempre, otra clase con el método main() que haga uso de ConversorDatos para probar todos los métodos.

#### Ejercicio 3.10: Gestión de alumnos de un instituto

PARTE 1: Crea una **clase Alumno** en Java que contenga lo siguiente:

**Atributos**:

* nombre (String)  
* numExpediente (int): Número de expediente único para cada estudiante.  
* curso (String): Ejemplo: "1º DAW A", "4º ESO C".  
* faltasJustificadas (int).  
* faltasInjustificadas (int).

**Métodos constructores**:

* Un constructor que reciba todos los datos iniciales (excepto las faltas, que se inicializarán a cero).  
* Otros constructor que solo reciba el nombre y el expediente, y asigne un 0 a las faltas de asistencia y el curso "Desconocido".

**Getters y setters:**

* Getters: Deben existir métodos de tipo get para todos los atributos de la clase.  
  * Setters: Solo haremos un setter para modificar el cursoActual. No será posible cambiar el número de expediente de un alumno ya creado ni modificar los contadores de faltas, excepto con el método registrarFalta() que se describe más abajo.

**Métodos**:

* registrarFalta(boolean esJustificada): Este método recibe un valor booleano. Si es true, incrementa el número de faltasJustificadas del alumno. Si es false, incrementa el número de faltasInjustificadas.  
  * evaluarRiesgoExpulsion(): Devuelve un String indicando el nivel de riesgo en base a las faltas injustificadas. Si faltasInjustificadas es mayor o igual a 10, devuelve "Riesgo de expulsión muy alto". Si faltasInjustificadas está entre 5 y 9 (ambos inclusive), devuelve "Riesgo medio de expulsión - Avisar a la familia". En otro caso devuelve "Riesgo bajo de expulsión".  
  * mostrarInformeAcademico(): Muestra por consola un informe completo con toda la inforamación disponible del alumno: Nombre, número de expediente, curso, total de faltas (justificadas + injustificadas) y el riesgo actual de expulsión.

PARTE 2: Una vez que tengas lista la clase Alumno, crea una segunda **clase Instituto**. Esta clase contendrá el método *main* y realizará las siguientes acciones:

* Crear 3 objetos de tipo Alumno utilizando al menos una vez cada uno de los dos constructores definidos.  
  * Utilizar el setter para cambiar el curso de uno de los alumnos.  
  * Simular las faltas de algunos alumnos: Llama al método registrarFalta() varias veces para algunos de los alumnos, asegurándote de que al menos uno de ellos alcance el nivel de "Riesgo muy alto de expulsión".  
  * Imprimir por consola el informe académico completo de cada uno de los tres alumnos, comprobando que los datos obtenidos son los correctos.
