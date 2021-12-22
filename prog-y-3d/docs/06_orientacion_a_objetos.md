---
layout: page
title: 6. Orientación a objetos
permalink: /orientacion-a-objetos/
nav_order: 6
has_children: true
parent: Introd. a la prog. y al diseño 3D
---

# 6. Orientación a objetos
{: .no_toc }

- TOC
{:toc}

 Orientación a objetos. Clases, objetos y constructores. Herencia. Subclases y superclases. Polimorfismo y sobrecarga. Encapsulamiento y ocultación.

En este capítulo vamos a introducir, de manera muy superficial, las técnicas de **programación orientada a objetos** y su implementación en Javascript.

La programación orientada a objetos es una forma de programar (un *paradigma*, dicen los teóricos) que implica organizar el código fuente de una determinada manera. Desde que este paradigma se impuso con fuerza en la década de 1990, se ha comprobado que las aplicaciones orientadas a objetos son más fáciles de diseñar y de mantener que las aplicaciones que usan técnicas de programación más anticuadas (lo que se llama **programación estructurada clásica**).

Javascript es un lenguaje orientado a objetos, aunque hace una interpretación un poco peculiar de lo que significa este concepto. En este capítulo, veremos primero qué es la programación orientada a objetos y luego nos centraremos en cómo aplicar esas ideas a Javascript.

## 6.1. Conceptos básicos de programación orientada a objetos

Los párrafos que vienen a continuación los he tomado y adaptado de un libro anterior mío, "Java para novatos", que a su vez se basa en un texto Yukihiro Matsumoto, el creador del lenguaje Ruby. La razón es sencilla: me parece una explicación insuperable (gracias a Matsumoto, claro, no a mí).

Para entender qué significa exactamente programación **orientada a objetos**, primero tenemos que comprender en qué consiste la **programación tradicional** o no orientada a objetos.

En programación tradicional, cualquier problema informático se resuelve codificando un conjunto de algoritmos que trabajan sobre un conjunto de datos. Es decir, los datos son elementos pasivos: es el código el que se encarga de hacer todo el trabajo por ellos. 

A medida que los proyectos crecen, el código también lo hace, y llega un momento en el que es imposible saber cómo funciona todo el sistema. Surgen interacciones imprevistas e impredecibles entre distintas partes del programa. El fallo más tonto, como un error tipográfico, puede convertirse en una pesadilla cuya localización puede suponer muchas horas de trabajo (y, en consecuencia, mucho dinero).

Como dice Matsumoto, el mantenimiento de estos programas se convierte en algo parecido a transportar un calamar gigante intentado que ninguno de sus tentáculos te alcance la cara.

Lo que hace la programación orientada a objetos es cambiar esta forma de trabajar. No supone una revolución con los métodos anteriores, sino un cambio en la forma en la que se hacen las mismas cosas de siempre.

La mayoría del trabajo se delega a los propios datos, de modo que **los datos ya no son estáticos**, sino que se encargan de mantenerse en forma a sí mismos. De nuevo en palabras de Matsumoto: dejamos de tratar cada pieza de dato como una caja en la que se puede abrir su tapa y arrojar cosas en ella y empezamos a tratarlos como máquinas funcionales cerradas con unos pocos interruptores y diales bien definidos.

Un dato en programación orientada a objetos (es decir, una caja con interruptores, botoncitos y diales) puede tener, en sus tripas, algo muy simple o muy complejo. No se puede saber desde el exterior y no se nos permite abrir la máquina (excepto cuando estamos completamente seguros de que algo está mal en su diseño), por lo que se nos obliga a utilizar los interruptores y leer los diales para interactuar con los datos. Una vez construida una de esas máquinas, no queremos tener que volver a pensar en cómo funciona internamente.

### 6.1.1. Un ejemplo sencillo para entender el concepto de "objeto"

Seguimos con Matsumoto para ilustrar con un ejemplo sencillo qué es eso de una “máquina con unos pocos interruptores y diales”.

Seguramente en tu cocina tienes un horno microondas (aunque, en realidad, para este ejemplo podrías elegir cualquier electrodoméstico). El horno consta, entre otros muchos subsistemas, de un temporizador. Su trabajo consiste en mantener el horno encendido durante un tiempo determinado por el usuario.

¿Cómo podríamos representar esto en un lenguaje de programación? En Javascript, por ejemplo, el temporizador podría ser, simplemente, una variable de tipo *number*. El programa manipularía esa variable disminuyendo el valor una vez por segundo, y permitiría al usuario establecer el tiempo inicial del temporizador antes de poner el horno en marcha.

Con este enfoque tradicional, un error en cualquier parte del programa podría terminar asignando un valor falso a la variable, como un número negativo o un tiempo de varias horas. *Hay un número infinito de razones inesperadas por las que podría llegar a suceder esto*. Cualquiera con cierta experiencia programando sabe que se pueden perder horas o días tratando de encontrar ese error.

Pero si programamos con un lenguaje orientado a objetos, no pensaremos en el tipo de datos que mejor se ajusta a un temporizador de microondas, sino en el modo en el que un temporizador de microondas funciona en el mundo real. No parece una gran diferencia, pero lo es.

El programador, o el diseñador, necesitará dedicar cierto tiempo a decidir qué es exactamente un temporizador de microondas y cómo se espera que el mundo exterior interactúe con el. Por fin, construirá una pequeña máquina (una pieza de software) con controles que permitan establecer, consultar y disminuir su valor.

Por ejemplo, podemos decidir crear el temporizador impidiendo asignarle un valor arbitrario, por la sencilla razón de que los temporizadores de microondas no trabajan de esa forma en el mundo real: solo permiten asignar múltiplos de 10 segundos, por lo general.

Es decir: existen sólo unas cuantas cosas que un temporizador de microondas puede hacer, y sólo permitiremos esas cosas. Así, si alguien desde otra parte del programa trata de asignar algún valor no permitido al temporizador, como un número negativo, le resultará imposible hacerlo por la sencilla razón de que el propio temporizador no lo permitirá. Ya no es un dato "tonto" y estático, que permite que cualquiera lo manipule. Es un dato "listo", con control y autonomía sobre su propio comportamiento. *Lo hemos convertido en un **objeto***. 

De ese modo, estaremos protegiendo una parte del programa de errores cometidos en otras partes y que, en programación tradicional, se propagan como el fuego en un tanque de gasolina.

Por si fuera poco, los lenguajes orientados a objetos nos permiten que, una vez que hayamos diseñado un temporizador de microondas (o el objeto que sea), podamos fabricar tantos como sea necesario. Habremos creado un patrón o molde de temporizador y, a partir de ese molde, se pueden construir objetos diferentes (pero similares) indefinidamente.
Pues bien, el molde se conoce como clase, y cada temporizador concreto que fabriquemos a partir de él se conoce como objeto.
Aclaremos, sin embargo, que la programación orientada a objetos no es una solución milagrosa: nada impide, en cualquier lenguaje, escribir código poco claro, descuidado, inestable o directamente erróneo.
A continuación hablaremos de los “interruptores y diales” del temporizador del microondas (métodos) y, en próximos capítulos, veremos como se construyen los moldes (clases).
Métodos
En la programación orientada a objetos, como acabamos de ver, no se piensa en manipular los datos directamente desde el exterior de un objeto, si no que son los propios objetos los que deciden cómo se debe operar sobre ellos. Se pasa un mensaje al objeto y este mensaje provoca algún tipo de acción o respuesta significativa por parte del objeto. Esto ocurre sin que nos importe cómo realiza el objeto, interiormente, el trabajo. 
Las tareas que podemos pedir que un objeto realice (o lo que es lo mismo, los mensajes que comprende) son los métodos. 
En Java, se llama a un método con la notación punto (como en C++, Python, Ruby o muchos otros lenguajes). El objeto con el que nos comunicamos se nombra a la izquierda del punto. Por ejemplo: 
String mi_cadena = "Esto es una cadena de caracteres";
System.out.println("La longitud de la cadena es: " + mi_cadena.length()); 
La salida por pantalla será:
La longitud de la cadena es 32
Intuitivamente es fácil de comprender: a este objeto cadena se le está pidiendo que diga la longitud que tiene (y, como es una cadena de caracteres, nos responde con la cantidad total de letras de que consta). Técnicamente, lo que hemos hecho se llama invocar el método length() del objeto mi_cadena. 
Otros objetos pueden hacer una interpretación un poco diferente de length. La decisión sobre cómo responder a un mensaje, o si se responde en absoluto, se toma durante la ejecución del programa, y la acción cambiará dependiendo de la variable que se use. 
String mi_cadena = "Esto es una cadena de caracteres";
String[] mi_array = {mi_cadena, "Otra cadena"};
System.out.println("La longitud de la cadena es: " + mi_cadena.length());
System.out.println("La longitud del array es: " + mi_array.length());
La salida por pantalla será: 
La longitud de la cadena es 32
La longitud del array es 2
Por lo tanto, lo que haga length() variará dependiendo del objeto con el que estemos hablando. En el primer caso, le pedimos a mi_cadena su longitud. Como se trata de una cadena de caracteres, solo hay una respuesta posible. En el segundo caso, se lo pedimos a mi_array, que es una colección compuesta por dos cadenas. Podríamos pensar que el método length() pudiera contar todos los caracteres en total almacenados en el objeto (43 en total). Pero lo más plausible es que nos devuelva 2, que es el número de elementos del array.
No importa si por el momento no entiendes bien lo que son los strings o los arrays. Lo que hay que tener en cuenta ahora es que el objeto array conoce lo que significa ser un array, y el string, lo que significa ser string, y ambos saben exactamente lo que tienen que hacer si les pedimos que nos calculen su propia longitud (lenght). 
En Java, las piezas de datos llevan consigo ese conocimiento, por lo que las solicitudes que se les hace se pueden satisfacer en las formas adecuadas para el tipo de dato. Esto libera al programador de la carga de memorizar una gran cantidad de nombres de funciones, ya que una cantidad relativamente pequeña de nombres de métodos, que corresponden a conceptos que sabemos como expresar en lenguaje natural, se pueden aplicar a diferentes tipos de datos siendo el resultado el que lógicamente cabría esperar. Esta característica de los lenguajes orientados a objeto se conoce como polimorfismo. 
Cuando un objeto recibe un mensaje que no conoce, se produce un error. Por lo tanto, hay que conocer qué métodos son aceptables para un objeto, aunque no se necesita saber como están programador por dentro. Los métodos, insistimos, son como los diales del horno microondas: como usuario, tienes que saber qué diales existen y cómo usarlos, pero no cómo están construidos por dentro.
 Atributos
Los atributos de un objeto definen las características del mismo. Por ejemplo, un atributo del temporizador del microondas debería ser el número de segundos que éste debe permanecer activo, y un atributo de un objeto de tipo String debe de ser el número de caracteres de que consta la cadena.
Al programador que usa un objeto deberían importarle un bledo los atributos del mismo. Él (o ella) se encargará de usar el objeto a través de sus métodos, y éstos operarán con los atributos, si ello es necesario, de forma totalmente transparente al programador. Es decir, los atributos raramente son accesibles desde el exterior del objeto, salvo que, por razones de diseño, el programador del objeto haya decidido lo contrario.





Un objeto es una colección de datos relacionados y/o funcionalidad (que generalmente consta de algunas variables y funciones, que se denominan propiedades y métodos cuando están dentro de objetos). Vamos a trabajar a través de un ejemplo para mostrate cómo son.

Para empezar, haz una copia local de nuestro archivo oojs.html . Esto contiene muy poco: un elemento <script> para que escribas tu código fuente en él. Lo usaremos como base para explorar la sintaxis básica de los objetos.

Al igual que con muchas cosas en JavaScript, la creación de un objeto a menudo comienza con la definición e iniciación de una variable. Intenta ingresar lo siguiente debajo del código JavaScript que ya está en tu archivo, luego guarda y actualiza:

var persona = {};
Copy to Clipboard
Si ingresas persona en tu entrada de texto y presionas el botón, debes obtener el siguiente resultado:

[objeto Objeto]
Copy to Clipboard
¡Felicidades!, acabas de crear tu primer objeto. ¡Trabajo realizado! Pero este es un objeto vacío, por lo que realmente no podemos hacer mucho con él. Actualicemos nuestro objeto para que se vea así:

var persona = {
  nombre: ['Bob', 'Smith'],
  edad: 32,
  genero: 'masculino',
  intereses: ['música', 'esquí'],
  bio: function () {
    alert(this.nombre[0] + '' + this.nombre[1] + ' tiene ' + this.edad + ' años. Le gusta ' + this.intereses[0] + ' y ' + this.intereses[1] + '.');
  },
  saludo: function() {
    alert('Hola, Soy '+ this.nombre[0] + '. ');
  }
};
Copy to Clipboard
Después de guardar y actualizar, intenta ingresar algunos de los siguientes en tu entrada de texto:

persona.nombre
persona.nombre[0]
persona.edad
persona.intereses[1]
persona.bio()
persona.saludo()
Copy to Clipboard
¡Ahora tienes algunos datos y funcionalidades dentro de tu objeto, y ahora puedes acceder a ellos con una sintaxis simple y agradable!

Nota: Si tienes problemas para hacer que esto funcione, intenta comparar tu código con nuestra versión - ve oojs-finished.html (también ve que se ejecuta en vivo). La versión en vivo te dará una pantalla en blanco, pero eso está bien. De nuevo, abre tu devtools e intenta escribir los comandos anteriores para ver la estructura del objeto.

Entonces, ¿qué está pasando aquí? Bien, un objeto se compone de varios miembros, cada uno de los cuales tiene un nombre (por ejemplo, nombre y edad) y un valor (por ejemplo, ['Bob', 'Smith'] y 32). Cada par nombre/valor debe estar separado por una coma, y el nombre y el valor en cada caso están separados por dos puntos. La sintaxis siempre sigue este patrón:

var nombreObjeto = {
  miembro1Nombre: miembro1Valor,
  miembro2Nombre: miembro2Valor,
  miembro3Nombre: miembro3Valor
}
Copy to Clipboard
El valor de un miembro de un objeto puede ser prácticamente cualquier cosa: en nuestro objeto persona tenemos una cadena de texto, un número, dos arreglos y dos funciones. Los primeros cuatro elementos son elementos de datos y se denominan propiedades del objeto. Los dos últimos elementos son funciones que le permiten al objeto hacer algo con esos datos, y se les denomina métodos del objeto.

Un objeto como este se conoce como un objeto literal — literalmente hemos escrito el contenido del objeto tal como lo fuimos creando. Esto está en contraste con los objetos instanciados de las clases, que veremos más adelante.

Es muy común crear un objeto utilizando un objeto literal cuando deseas transferir una serie de elementos de datos relacionados y estructurados de alguna manera, por ejemplo, enviando una solicitud al servidor para ponerla en una base de datos. Enviar un solo objeto es mucho más eficiente que enviar varios elementos individualmente, y es más fácil de procesar que con un arreglo, cuando deseas identificar elementos individuales por nombre.

Notación de punto
Arriba, accediste a las propiedades y métodos del objeto usando notación de punto (dot notation). El nombre del objeto (persona) actúa como el espacio de nombre (namespace); al cual se debe ingresar primero para acceder a cualquier elemento encapsulado dentro del objeto. A continuación, escribe un punto y luego el elemento al que deseas acceder: puede ser el nombre de una simple propiedad, un elemento de una propiedad de arreglo o una llamada a uno de los métodos del objeto, por ejemplo:

persona.edad
persona.intereses[1]
persona.bio()
Copy to Clipboard
Espacios de nombres secundarios
Incluso es posible hacer que el valor de un miembro del objeto sea otro objeto. Por ejemplo, intenta cambiar el miembro nombre de

nombre: ['Bob', 'Smith'],
Copy to Clipboard
a

nombre : {
  pila: 'Bob',
  apellido: 'Smith'
},
Copy to Clipboard
Aquí estamos creando efectivamente un espacio de nombre secundario (sub-namespace). Esto suena complejo, pero en realidad no es así: para acceder a estos elementos solo necesitas un paso adicional que es encadenar con otro punto al final. Prueba estos:

persona.nombre.pila
persona.nombre.apellido
Copy to Clipboard
Importante: en este punto, también deberás revisar tu código y cambiar cualquier instancia de

nombre[0]
nombre[1]
Copy to Clipboard
a

nombre.pila
nombre.apellido
Copy to Clipboard
De lo contrario, sus métodos ya no funcionarán.

Notación de corchetes
Hay otra manera de acceder a las propiedades del objeto, usando la notación de corchetes. En lugar de usar estos:

persona.edad
persona.nombre.pila
Copy to Clipboard
Puedes usar

persona['edad']
persona['nombre']['pila']
Copy to Clipboard
Esto se ve muy similar a cómo se accede a los elementos en un arreglo, y básicamente es lo mismo: en lugar de usar un número de índice para seleccionar un elemento, se esta utilizando el nombre asociado con el valor de cada miembro. No es de extrañar que los objetos a veces se denominen arreglos asociativos: asocian cadenas de texto a valores de la misma manera que las arreglos asocian números a valores.

Establecer miembros de objetos
Hasta ahora solo hemos buscado recuperar (u obtener) miembros del objeto: también puede establecer (actualizar) el valor de los miembros del objeto simplemente declarando el miembro que deseas establecer (usando la notación de puntos o corchetes), de esta manera:

persona.edad = 45;
persona['nombre']['apellido'] = 'Cratchit';
Copy to Clipboard
Intenta ingresar estas líneas y luego vuelve a ver a los miembros para ver cómo han cambiado:

persona.edad
persona['nombre']['apellido']
Copy to Clipboard
Establecer miembros no solo es actualizar los valores de las propiedades y métodos existentes; también puedes crear miembros completamente nuevos. Prueba estos:

persona['ojos'] = 'avellana';
persona.despedida = function() { alert("¡Adiós a todos!"); }
Copy to Clipboard
Ahora puedes probar a los nuevos miembros:

persona['ojos']
person.despedida()
Copy to Clipboard
Un aspecto útil de la notación de corchetes es que se puede usar para establecer dinámicamente no solo los valores de los miembros, sino también los nombres de los miembros. Digamos que queremos que los usuarios puedan almacenar tipos de valores personalizados en sus datos personales, escribiendo el nombre y el valor del miembro en dos entradas de texto. Podríamos obtener esos valores de esta manera:

var nombrePerzonalizado = entradaNombre.value;
var valorPerzonalizado = entradaValor.value;
Copy to Clipboard
entonces podríamos agregar este nuevo miembro nombre y valor al objeto persona de esta manera:

persona[nombrePerzonalizado] = valorPerzonalizado;
Copy to Clipboard
Para probar esto, intenta agregar las siguientes líneas en tu código, justo debajo de la llave de cierre del objeto persona:

var nombrePerzonalizado = 'altura';
var valorPerzonalizado = '1.75m';
persona[nombrePerzonalizado] = valorPerzonalizado;
Copy to Clipboard
Ahora intenta guardar y actualizar, e ingresa lo siguiente en tu entrada de texto:

persona.altura
Copy to Clipboard
Agregar una propiedad a un objeto no es posible con la notación de puntos, que solo puede aceptar un nombre de miembro literal, no un valor variable que apunte a un nombre.

¿Qué es "this" (este)?
Es posible que hayas notado algo un poco extraño en nuestros métodos. Mira esto, por ejemplo:

saludo: function() {
  alert('¡Hola!, Soy '+ this.nombre.pila + '.');
}
Copy to Clipboard
Probablemente te estés preguntando qué es "this". La palabra clave this se refiere al objeto actual en el que se está escribiendo el código, por lo que en este caso this es equivalente a la persona. Entonces, ¿por qué no escribir persona en su lugar? Como verás en el artículo JavaScript orientado a objetos para principiantes cuando comenzaremos a crear constructores, etc., this es muy útil: siempre asegurará que se usen los valores correctos cuando cambie el contexto de un miembro (por ejemplo, dos diferentes instancias de objetos persona) pueden tener diferentes nombres, pero querráx usar su propio nombre al decir su saludo).

Vamos a ilustrar lo que queremos decir con un par de objetos persona simplificados:

var persona1 = {
  nombre: 'Chris',
  saludo: function() {
    alert('¡Hola!, Soy '+ this.nombre + '.');
  }
}

var persona2 = {
  nombre: 'Brian',
  saludo: function() {
    alert('¡Hola!, Soy '+ this.nombre + '.');
  }
}
Copy to Clipboard
En este caso, persona1.saludo() mostrará "¡Hola!, Soy Chris"; persona2.saludo() por otro lado mostrará "¡Hola!, Soy Brian", aunque el código del método es exactamente el mismo en cada caso. Como dijimos antes, this es igual al objeto en el que está el código; esto no es muy útil cuando se escriben objetos literales a mano, pero realmente se vuelve útil cuando se generan objetos dinámicamente (por ejemplo, usando constructores) Todo se aclarará más adelante.

Has estado usando objetos todo el tiempo
A medida que has estado repasando estos ejemplos, probablemente hayas pensando que la notación de puntos que has usando es muy familiar. ¡Eso es porque la has estado usando a lo largo del curso! Cada vez que hemos estado trabajando en un ejemplo que utiliza una API de navegador incorporada o un objeto JavaScript, hemos estado usando objetos, porque tales características se crean usando exactamente el mismo tipo de estructuras de objetos que hemos estado viendo aquí, aunque más complejos que nuestros propios ejemplos personalizados.

Entonces cuando usaste métodos de cadenas de texto como:

myCadena.split(',');
Copy to Clipboard
Estabas usando un método disponible en una instancia de la clase String. Cada vez que creas una cadena en tu código, esa cadena se crea automáticamente como una instancia de String, y por lo tanto tiene varios métodos/propiedades comunes disponibles en ella.

Cuando accediste al modelo de objetos del documento (document object model) usando líneas como esta:

var miDiv = document.createElement('div');
var miVideo = document.querySelector('video');
Copy to Clipboard
Estaba usando métodos disponibles en una instancia de la clase Document. Para cada página web cargada, se crea una instancia de Document, llamada document, que representa la estructura, el contenido y otras características de la página entera, como su URL. De nuevo, esto significa que tiene varios métodos/propiedades comunes disponibles en él.

Lo mismo puede decirse de prácticamente cualquier otro Objeto/API incorporado que hayad estado utilizando: Array, Math, etc.

Ten en cuenta que los Objetos/API incorporados no siempre crean instancias de objetos automáticamente. Como ejemplo, la API de Notificaciones, que permite que los navegadores modernos activen las notificaciones del sistema, requiere que crees una instancia de un nuevo objeto para cada notificación que desees disparar. Intenta ingresar lo siguiente en tu consola de JavaScript:

var miNotificacion = new Notification('¡Hola!');
Copy to Clipboard
De nuevo, veremos qué son los constructores en un artículo posterior.

Nota: Es útil pensar en la forma en que los objetos se comunican como paso de mensajes — cuando un objeto necesita otro objeto para realizar algún tipo de acción a menudo enviará un mensaje a otro objeto a través de uno de sus métodos, y esperará una respuesta, que conocemos como un valor de retorno.

Programacion Orientada a Objetos— lo básico
Para empezar, daremos una descripción simple y de alto nivel acerca de lo que es la Programación Orientada a Objetos (POO). Decimos simple, porque la POO puede volverse complicada rápidamente, y darte un tratamiento completo ahora, probablemente podría confundirte más que ayudar. La idea básica de la POO es que usamos objetos para modelar cosas del mundo real que queremos representar en nuestros programas, y/o proveemos una simple manera para acceder a la funcionalidad que, de otra manera, sería difícil o imposible de usar.

Los objetos pueden contener información y código relacionados, los cuales representan información acerca de lo que estás tratando de modelar, y la funcionalidad o comportamiento que deseas que tenga.  Los datos de un Objeto (y frecuentemente, también las funciones) se pueden almacenar ordenadamente (la palabra oficial es encapsular) dentro del paquete de un objeto (al que se puede asignar un nombre específico, llamado a veces espacio de nombres), haciéndolo fácil de estructurar y acceder; los objetos también se usan comúnmente como almacenes de datos que se pueden enviar fácilmente a través de la red.

Definiendo una plantilla de objeto
Vamos a considerar un sencillo programa que muestra información sobre estudiantes y profesores en una escuela. Aquí daremos un vistazo a la POO (Programación Orientada a Objetos) en general, no en el contexto de algún lenguaje de programación específico.

Para empezar, podríamos volver a ver al objeto Persona de nuestro artículo de primeros objetos, que define los datos generales y funcionalidades de una persona. Hay muchas cosas que podrías saber acerca de una persona (su dirección, estatura, tamaño de calzado, perfil de ADN, número de pasaporte, rasgos significativos de su personalidad...), pero, en este caso, solo estamos interesados en mostrar su nombre, edad, género e intereses, además de una pequeña introducción sobre este individuo basada en los datos anteriores. También queremos que sea capaz de saludar. 

Esto es conocido como abstracción —  crear un modelo simple de algo complejo que represente sus aspectos más importantes y que sea fácil de manipular para el propósito de nuestro programa.



En algunos lenguajes de POO, esta definición de tipo de objeto se la llama class (JavaScript utiliza diferentes mecanismos y terminologías, como verás a continuación) — esto no es en realidad un objeto, en vez de esto es un modelo que define las características que un objeto debería tener.

Creando objetos
Partiendo de nuestra clase, podemos crear instancias de objetos — objetos que contienen los datos y funcionalidades definidas en la clase original. Teniendo a nuestra clase Persona, ahora podemos crear gente con características más específicas: 



Cuando una instancia del objeto es creada a partir de una clase, se ejecuta la función constructora (constructor en inglés) de la clase para crearla. El proceso de crear una instancia del objeto desde una clase se llama instanciación.

Clases especializadas
En este caso nosotros no queremos personas genericas — queremos docentes y estudiantes, que son los dos tipos más específicos de personas. En POO, podemos crear nuevas clases basadas en otras clases, estas nuevas clases secundarias se pueden hacer para  heredar los datos y código de su clase primaria, de modo que pueden reutilizar la funcionalidad común a todos los tipos de objetos en lugar de tener que duplicarla. Cuando la funcionalidad difiere entre clases, puedes definir funciones especializadas directamente en ellas según sea necesario.



Esto es realmente útil, los profesores y los estudiantes comparten muchas características comunes como el nombre, el género y la edad, por lo que es conveniente tener que definir esas características solo una vez. También puedes definir la misma característica por separado en diferentes clases, ya que cada definición de esa característica estará en un espacio de nombres diferente. Por ejemplo, el saludo de un estudiante puede tener la forma "Yo, soy [Nombre]" (por ejemplo, Yo, soy Sam), mientras que un profesor puede usar algo más formal, como "Hola, mi nombre es [Prefix] [lastName], y enseño [Asunto] ". (Por ejemplo, Hola, mi nombre es Sr. Griffiths, y yo enseño Química).

Nota:  la palabra elegante para la capacidad de múltiples tipos de objetos de implementar la misma funcionalidad es polimorfismo. Por si acaso te preguntabas.

Ahora puedes crear instancias de objetos de las clases "hijo". Por ejemplo:



En el resto del articulo, comenzaremos a ver como podemos practicar la teoría de POO en JavaScript.

Constructores e instancias de objetos
Algunas personas sostienen que JavaScript no es un verdadero lenguaje orientado a objetos — por ejemplo, su enunciado class es sólo azúcar sintáctica sobre la herencia prototípica existente y no es una class en el sentido tradicional. JavaScript, utiliza funciones especiales llamadas funciones constructoras para definir objetos y sus características. Son útiles porque a menudo te encontrarás con situaciones en las que no sabes cuántos objetos crearás; los constructores proporcionan los medios para crear tantos objetos como necesites de una manera efectiva, adjuntando datos y funciones a ellos según sea necesario.

Cuando se crea una nueva instancia del objeto a partir de una función constructora, su funcionalidad central (tal como se define en su prototipo, que exploraremos en el artículo Prototipos de objetos) no se copia en el nuevo objeto como lenguajes OO "clásicos", sino que la funcionalidad está vinculada a través de una cadena de referencia llamada cadena prototipo. Así que esto no es una verdadera instanciación, estrictamente hablando, JavaScript usa un mecanismo diferente para compartir funcionalidad entre objetos.

Nota: no ser "POO clásica" no es necesariamente algo malo; Como se mencionó anteriormente, la POO puede ser muy compleja muy rápidamente, y JavaScript tiene algunas agradables formas de aprovechar las características de la OO sin tener que profundizar demasiado en ello.

Exploremos la creación de clases a través de constructores y la creación de instancias de objetos a partir de ellas en JavaScript. En primer lugar, nos gustaría que hicieras una nueva copia local del archivo oojs.html que vimos en nuestro primer artículo de Objetos.

Un ejemplo simple
Comencemos por ver cómo puedes definir una persona con una funcion normal. Agrega esta funcion dentro del elemento script:
function createNewPerson(name) {
  var obj = {};
  obj.name = name;
  obj.greeting = function() {
    alert('Hi! I\'m ' + this.name + '.');
  };
  return obj;
}
Copy to Clipboard
Ahora puedes crear una nueva persona llamando a esta funcion — prueba con las siguientes lineas en la consola Javascript de tu navegador:
var salva = createNewPerson('Salva');
salva.name;
salva.greeting();
Copy to Clipboard
Esto funciona bastante bien, pero es un poco largo; si sabemos que queremos crear un objeto, ¿por qué necesitamos crear explícitamente un nuevo objeto vacío y devolverlo? Afortunadamente, JavaScript nos proporciona un práctico acceso directo, en forma de funciones constructoras — ¡hagamos una ahora!
Reemplaza tu función anterior por la siguiente:
function Person(name) {
  this.name = name;
  this.greeting = function() {
    alert('Hi! I\'m ' + this.name + '.');
  };
}
Copy to Clipboard
La función constructora es la versión de JavaScript de una clase. Notarás que tiene todas las características que esperas en una función, aunque no devuelve nada o crea explícitamente un objeto — básicamente sólo define propiedades y métodos. Verás que la palabra clave this se está usando aquí también — es básicamente decir que cuando se crea una de estas instancias de objeto, la propiedad name del objeto será igual al valor del nombre pasado a la llamada del constructor, y el método greeting() usará también el valor del nombre pasado a la llamada del constructor.

Nota: Un nombre de función constructora generalmente comienza con una letra mayúscula — esta convención se utiliza para hacer que las funciones constructoras sean más fáciles de reconocer en el código.

Entonces, ¿cómo llamamos a un constructor para crear algunos objetos?

Agrega las siguientes líneas debajo de tu código anterior:
var person1 = new Person('Bob');
var person2 = new Person('Sarah');
Copy to Clipboard
Guarda el código y vuelve a cargarlo en el navegador, e intenta ingresar las siguientes líneas en la consola Javascript :
person1.name
person1.greeting()
person2.name
person2.greeting()
Copy to Clipboard
¡Guaw! Ahora veras que tenemos dos nuevos objetos, cada uno de los cuales está almacenado en un espacio de nombres diferente: para acceder a sus propiedades y métodos, debes llamarlos como person1 o  person2; están cuidadosamente empaquetados para que no entren en conflicto con otras funciones. Sin embargo, tienen disponible la misma propiedad name y el método greeting(). Ten en cuenta que están utilizando su propio name que se les asignó cuando se crearon; esta es una razón por la cual es muy importante usar this, para que usen sus propios valores, y no algún otro valor.

Veamos nuevamente las llamadas del constructor:

var person1 = new Person('Bob');
var person2 = new Person('Sarah');
Copy to Clipboard
En cada caso, la  palabra clave new se usa para indicarle al navegador que queremos crear una nueva instancia del objeto, seguida del nombre de la función con sus parámetros requeridos entre paréntesis, y el resultado se almacena en una variable — muy similar a cómo se llama a una función estándar. Cada instancia se crea de acuerdo con esta definición:

function Person(name) {
  this.name = name;
  this.greeting = function() {
    alert('Hi! I\'m ' + this.name + '.');
  };
}
Copy to Clipboard
Una vez creados los nuevos objetos, las variables person1 y person2 contienen los siguientes objetos:

{
  name: 'Bob',
  greeting: function() {
    alert('Hi! I\'m ' + this.name + '.');
  }
}

{
  name: 'Sarah',
  greeting: function() {
    alert('Hi! I\'m ' + this.name + '.');
  }
}
Copy to Clipboard
Ten en cuenta que cuando llamamos a nuestra función constructora, estamos definiendo greeting() cada vez, lo cual no es lo ideal. Para evitar esto, podemos definir funciones en el prototipo, que veremos más adelante.

Creando nuestro constructor final
El ejercicio que vimos anteriormente fue solo un ejemplo simple para comenzar. Ahora crearemos nuestra función constructor Person() final.

Elimina el código que insertaste hasta ahora y agrega este constructor de reemplazo; este es exactamente el mismo que el ejemplo simple del principio, con un poco más de complejidad:
function Person(first, last, age, gender, interests) {
  this.name = {
    'first': first,
    'last' : last
  };
  this.age = age;
  this.gender = gender;
  this.interests = interests;
  this.bio = function() {
    alert(this.name.first + ' ' + this.name.last + ' is ' + this.age + ' years old. He likes ' + this.interests[0] + ' and ' + this.interests[1] + '.');
  };
  this.greeting = function() {
    alert('Hi! I\'m ' + this.name.first + '.');
  };
}
Copy to Clipboard
Ahora, agrega la siguiente línea para crear una instancia del objeto:
var person1 = new Person('Bob', 'Smith', 32, 'male', ['music', 'skiing']);
Copy to Clipboard
Ahora verás que puedes acceder a las propiedades y métodos justo como lo hiciste anteriormente — intenta esto en tu consola JS:

person1['age']
person1.interests[1]
person1.bio()
// etc.
Copy to Clipboard
Nota: Si tienes problemas para lograr que funcione, puedes comparar tu código con nuestra versión — ve oojs-class-finished.html (también lo puedes ver corriendo en vivo).

Ejercicios adicionales
Para empezar, intenta añadir un par de líneas de creación de objetos propias, y trata de obtener y asignar valores a los miembros de las instancias del objeto.

Además, hay un par de problemas con nuestro método bio() — la salida siempre incluye el pronombre "He", incluso para personas de otros géneros. Y bio solamente incluye dos intereses, sin importar la cantidad que hay en el arreglo interests. ¿Podrías corregir esto en la definición de la clase (constructor)? Puedes poner cualquier código dentro de un constructor (probablemente necesites algunos condicionales y un bucle). Piensa como se deben estructurar las declaraciones dependiendo del género, y de la cantidad de intereses.

Note: Si estás atascado, hay una respuesta en nuestro repositorio de GitHub (see it live) — igualmente ¡intentea resolverla primero!

Otras formas de crear instancias de objetos
Hasta ahora hemos visto dos diferentes formas de crear una instancia de objeto — declarando un objeto literal, y usando una función constructora (ver arriba).

Esto tiene sentido, pero hay otras formas — se muestran aquí para que te vayas familiarizando en caso de encontrarte con ellas.

El constructor Object()
Antes que nada, puedes usar el constructor Object() para crear un nuevo objeto. Si, incluso objetos genéricos tienen un constructor que genera un objeto vacío.

Intenta ingresar este código en la consola JavaScript de tu navegador:
var person1 = new Object();
Copy to Clipboard
Esto guarda un objeto vacío en la variable person1. Luego pueded agregar propiedades y métodos a este objeto usando la notación de punto (.) o de corchetes (['']); prueba estos ejemplos en tu consola:
person1.name = 'Chris';
person1['age'] = 38;
person1.greeting = function() {
  alert('Hi! I\'m ' + this.name + '.');
};
Copy to Clipboard
También puedes pasar un objeto literal como parámetro al constructor Object(), para precargarlo con propiedades/métodos. Prueba esto en tu consola:
var person1 = new Object({
  name: 'Chris',
  age: 38,
  greeting: function() {
    alert('Hi! I\'m ' + this.name + '.');
  }
});
Copy to Clipboard
Usando el método create()
Los constructores te pueden ayudar a ordenar tu código — puedes crear constructores en un lugar, y luego crear instancias cuando sean necesarias.

Sin embargo, algunas personas prefieren crear instancias de objetos sin crear antes constructores, especialmente si van a crear solamente pocas instancias de un objeto.

JavaScript tiene un método llamado create() que permite hacer esto. Con este método puedes crear un nuevo objeto basado en cualquier otro objeto existente.

Con tu ejercicio de la sección anterior cargado en el navegador, prueba esto en tu consola JavaScript
var person2 = Object.create(person1);
Copy to Clipboard
Y ahora prueba esto:
person2.name
person2.greeting()
Copy to Clipboard
Verás que person2 fue creado basado en person1 — tiene las mismas propiedades y métodos.

Una limitación del método create() es que no está soportado por el navegador IE8. Por lo que los constructores serán más efectivos sin necesitas soportar navegadores antiguos.

Más tarde, exploraremos en detalle los efectos de create().


Prototipos de objetos
Anterior
Overview: Objects
Siguiente
Los prototipos son un mecanismo mediante el cual los objetos en JavaScript heredan características entre sí. En este artículo, explicaremos como funcionan los prototipos y también cómo se pueden usar las propiedades de estos para añadir métodos a los contructores existentes.

Prerrequisitios:	Conocer las funciones en Javascript, conocimientos básicos de Javascript (ver Primeros Pasos y Building blocks) y Javascript orientado a Objetos (ver Introducción a Objetos).
Objetivo:	Comprender los prototipos de objectos de Javascript, cómo funciona la cadena de prototype, y cómo añadir nuevos métodos a la propiedad prototype.
¿Un lenguaje basado en prototipos?
JavaScript es a menudo descrito como un lenguaje basado en prototipos - para proporcionar mecanismos de herencia, los objetos pueden tener un objeto prototipo, el cual actúa como un objeto plantilla que hereda métodos y propiedades.

Un objeto prototipo del objeto puede tener a su vez otro objeto prototipo, el cual hereda métodos y propiedades, y así sucesivamente. Esto es conocido con frecuencia como la cadena de prototipos, y explica por qué objetos diferentes pueden tener disponibles propiedades y métodos definidos en otros objetos.

Bien, para ser exactos, los métodos y propiedades son definidos en la propiedad prototype, que reside en la función constructora del objeto, no en la instancia misma del objeto.

En JavaScript, se establece un enlace entre la instancia del objeto y su prototipo (su propiedad __proto__, la cual es derivada de la propiedad prototype sobre el constructor), y las propiedades y metodos son encontrados recorriendo la cadena de prototipos.

Nota: Es importante entender que, tanto el prototipo de la instancia de un objeto (al cual se accede mediante Object.getPrototypeOf(obj), o a través de la propiedad __proto__) como el prototipo que contiene el constructor (que se encuentra en la propiedad prototype del constructor) hacen referencia al mismo objeto.

Vamos a echar un vistazo a algunos ejemplos para intentar aclarar estos conceptos.

Entendiendo objectos prototipos
Volvamos al ejemplo anterior en el que acabamos definiendo nuestro constructor Person() — cargue el ejemplo en su navegador. Si aún no lo tienes luego de haber trabajado el último artículo, usa nuestro ejemplo oojs-class-further-exercises.html (vea también el código fuente).

En este ejemplo, hemos definido una función constructor, así:

function Persona(nombre, apellido, edad, genero, intereses) {

  // definiendo de propiedades y métodos
  this.first = first;
  this.last = last;
//...
}
Copy to Clipboard
Entonces hemos creado una instancia de un objeto como este:

var person1 = new Persona('Bob', 'Smith', 32, 'hombre', ['music', 'skiing']);
Copy to Clipboard
Si escribe "person1." en su consola JavaScript, debería ver que el navegador intenta completarlo automáticamente con los nombres de miembro disponibles en este objeto:



En esta lista, podra ver los miembros definidos en el objeto prototipo de person1, que es la Persona() (Persona() es el constructor) - nombre, edad, género, intereses, biografía y saludos. Sin embargo, también verá algunos otros miembros - watch, valueOf, etc - que están definidos en el objeto prototipo de Persona() 's, que es un Objeto (Object). Esto demuestra que el prototipo cadena funciona.



Entonces, ¿qué sucede si llama a un método en person1, que está definido en Object? Por ejemplo:

person1.valueOf()
Copy to Clipboard
Este método valueOf() simplemente retornará el valor del objeto sobre el que se llama - ¡pruébalo y verás! En este caso, lo que pasa es que:

El navegador comprueba inicialmente si el objeto person1 tiene un método valueOf() disponible en él.
Si no lo hace, entonces el navegador comprueba si el objeto prototipo del objeto person1 (el prototipo del constructor de Persona()) tiene un método valueOf() disponible en él.
Si tampoco lo hace, entonces el navegador comprueba si el objeto prototipo del objeto prototipo del constructor Persona() (Objeto() prototipo del objeto prototipo del constructor) tiene un método valueOf() disponible en él. Lo hace, así que es llamado, y todo funciona!
Nota: Queremos reiterar que los métodos y propiedades no se copian de un objeto a otro en la cadena del prototipo. Ellos son accedidos subiendo por la cadena como se ha descrito anteriormente.

Nota: No existe oficialmente una forma de acceder directamente al objeto prototipo de un objeto - los "enlaces" entre los elementos de la cadena están definidos en una propiedad interna, denominada [[prototipo]] en la especificación del lenguaje JavaScript (ver ECMAScript).

La mayoría de los navegadores modernos, sin embargo, ofrecen una propiedad disponible llamada __proto__ (es decir, 2 subrayados en cada lado), que contiene el objeto prototipo del constructor del objeto. Por ejemplo, pruebe person1.__proto__ y person1.__proto__.__proto__ para ver cómo se ve la cadena en código!

Desde ECMAScript 2015 se puede acceder indirectamente al objeto prototipo de un objeto mediante Object.getPrototypeOf(obj).

La propiedad prototype: Donde se definen los miembros hereditarios
Entonces, ¿dónde se definen las propiedades y métodos heredados? Si miras la página de referencia de Object, verás en la parte izquierda un gran número de propiedades y métodos - muchos más que el número de miembros heredados que vimos disponibles en el objeto person1. Algunos son heredados y otros no, ¿por qué?

La respuesta es que los heredados son los que están definidos en la propiedad prototype (podría llamarse subespacio de nombres), es decir, los que empiezan con Object.prototype, y no los que empiezan sólo con Object. El valor de la propiedad del prototipo es un objeto, que es básicamente un repositorio(bucket) para almacenar propiedades y métodos que queremos que sean heredados por los objetos más abajo en la cadena del prototipo.

Así que Object.prototype.watch(), Object.prototype.valueOf(), etc., están disponibles para cualquier tipo de objeto que herede de Object.prototype, incluyendo nuevas instancias de objeto creadas desde el constructor.

Object.is(), Object.keys(), y otros miembros no definidos dentro del prototipo del repositorio(bucket) no son heredados por instancias de objeto o tipos de objeto que heredan de Object.prototype. Sino que son métodos/propiedades disponibles sólo en el propio constructor Object().

Nota: Esto parece extraño - ¿cómo se puede tener un método definido en un constructor, que en sí mismo es una función? Bueno, una función es también un tipo de objeto - vea la referencia del constructor de Function() si no nos cree.

Puede comprobar las propiedades de los prototipos existentes - vuelva a nuestro ejemplo anterior e intente introducir lo siguiente en la consola JavaScript:
Person.prototype
Copy to Clipboard
El resultado no le mostrará mucho - después de todo, no hemos definido nada en el prototipo de nuestro constructor personalizado! Por defecto, el prototipo de un constructor siempre comienza vacío. Ahora intente lo siguiente:
Object.prototype
Copy to Clipboard
Verá un gran número de métodos definidos en la propiedad Prototype de Object, que están disponibles en los objetos que heredan de Object, como se ha mostrado anteriormente.

Verá otros ejemplos de herencia de cadena de prototipos en todo JavaScript - intente buscar los métodos y propiedades definidas en el prototipo de los objetos globales String, Date, Number y Array, por ejemplo. Todos ellos tienen un número de miembros definidos en su prototipo, por lo que, por ejemplo, cuando se crea una cadena, como ésta:

var myString = 'Esto es mi String.';
Copy to Clipboard
myString inmediatamente tiene una serie de métodos útiles disponibles en él, como split(), indexOf(), replace(), etc.

Importante: La propiedad prototype es una de las partes más confusamente nombradas de JavaScript - podría pensarse que this apunta al objeto prototipo del objeto actual, pero no lo hace (es un objeto interno al que puede accederse mediante __proto__, ¿recuerda?). en su lugar, prototype es una propiedad que contiene un objeto en el que se definen los miembros que se desea que se hereden.

Revisando create()
Anteriormente mostramos cómo Object.create() crea una nueva instancia de objeto.

Por ejemplo, pruebe esto en la consola JavaScript de su ejemplo anterior:
var person2 = Object.create(person1);
Copy to Clipboard
Lo que hace create() es crear un nuevo objeto a partir de un objeto prototipo específico. Aquí, la person2 se crea utilizando la person1 como objeto prototipo. Puede comprobarlo introduciendo lo siguiente en la consola:
person2.__proto__
Copy to Clipboard
Esto devolverá el objeto Persona.

La propiedad constructor
Cada función de constructor tiene una propiedad prototype cuyo valor es un objeto que contiene una propiedad constructor. Esta propiedad constructor apunta a la función constructor original.

Como verá en la siguiente sección, las propiedades definidas en la propiedad Person.prototype (o en general en la propiedad prototype de una función de constructor, que es un objeto, como se mencionó en la sección anterior) se hacen disponibles a todas las instancias de objetos creadas utilizando el constructor Person(). Por lo tanto, la propiedad del constructor también está disponible tanto para los objetos person1 como para los objetos person2.

Por ejemplo, pruebe estos comandos en la consola:
person1.constructor
person2.constructor
Copy to Clipboard
Ambos deberían devolver el constructor Person(), ya que contienen la definición original de esas instancias.

Un truco interesante es que se puede añadir paréntesis al final de la propiedad constructor (añadiendo todos los parámetros requeridos) para crear otra instancia desde ese constructor. Después de todo, el constructor es una función, por lo que puede ser invocada usando paréntesis; solamente se necesita incluir la palabra clave new para especificar que se quiere usar la función como un constructor.

Inténtese esto en la consola:
let person3 = new person1.constructor('Karen', 'Stephenson', 26, 'female', ['playing drums', 'mountain climbing']);
Copy to Clipboard
Ahora intente acceder a las características del nuevo objeto, como:
person3.name.first
person3.age
person3.bio()
Copy to Clipboard
Esto funciona. No se necesita usarlo con frecuencia, pero puede ser realmente útil cuando se quiera crear una instancia nueva y por alguna razón no se tenga disponible fácilmente una referencia al constructor original.

La propiedad constructor tiene otros usos. Por ejemplo, si se tiene una instancia y se quiere devolver el nombre del que el constructor es una instancia, se puede usar lo siguiente:

instanceName.constructor.name
Copy to Clipboard
Intente esto, por ejemplo:

person1.constructor.name
Copy to Clipboard
Nota: El valor de constructor.name puede cambiar (debido a herencia de prototipos, binding, preprocesores, transpiladores, etc.), por lo que para ejemplos más complejos es preferible usar el operador instanceof en su lugar. 

Modificando prototipos
Vamos a echar un vistzo a un ejemplo para modificar la propiedad prototype de una función constructor (los métodos añadidos a la propiedad prototipo están disponibles en todas las instancias de los objetos creados a partir del constructor).

Regresemos a nuestro ejemplo oojs-class-further-exercises.html y creemos una copia local del código fuente. Debajo del código JavaScript existente, agrega el siguiente código, el cuál añade un nuevo método a la propiedad prototype del constructor:
Person.prototype.farewell = function() {
  alert(this.name.first + ' has left the building. Bye for now!');
};
Copy to Clipboard
Guarda el código y abre la página en el navegador, e ingresa lo siguiente en la entrada de texto.
person1.farewell();
Copy to Clipboard
Deberías obtener un mensaje de alerta mostrando el nombre de la persona como se define dentro del constructor. Esto es realmente útil, pero lo que es más útil es que toda la cadena de herencia se ha actualizado dinámicamente; automáticamente hace que este nuevo método esté disponible en todas las instancias del objeto creadas desde el constructor

Piensa sobre esto por un momento. En nuestro código definimos el constructor, luego creamos una insancia del objeto desde el constructor, después agregamos un nuevo método a el prototipo del constructor.

function Person(first, last, age, gender, interests) {

  // property and method definitions

}

var person1 = new Person('Tammi', 'Smith', 32, 'neutral', ['music', 'skiing', 'kickboxing']);

Person.prototype.farewell = function() {
  alert(this.name.first + ' has left the building. Bye for now!');
};.
Copy to Clipboard
Pero el método farewell() aún se encuentra disponible en la instancia person1, su funcionalidad disponible ha sido automáticamente actualizada incluído en método recién definido farewell().

Nota: Si estás teniendo problemas haciendo funcionar este ejemplo, echa un vistazo en nuestro ejemplo oojs-class-prototype.html (míralo ejecutarse en tiempo real).

Raramente verás propiedades definidas en la propiedad prototype, ya no son muy flexibles cuando son definidas de esta forma. Por ejemplo, puedes añadir una propiedad como esta:

Person.prototype.fullName = 'Bob Smith';
Copy to Clipboard
Esto no es muy flexible, ya que la persona podría no llamarse así. Sería mucho mejor construir fullname desde name.first y name.last.

Person.prototype.fullName = this.name.first + ' ' + this.name.last;
Copy to Clipboard
Sin embargo esto no funciona, ya que this estará referenciando al scope global en este caso, no al scope de la función. Llamar esta propiedad retornaría undefined undefined. Esto funcionó bien en el método que declaramos anteriormente dentro del prototipo, porque se encuentra dentro del scope de la función, que se transferirá con éxito al scope de la instancia del objeto.Así que deberías definir propiedades constantes en el prototipo (p.e. una que nunca necesite cambiar), pero generalmente funciona mejor definir propiedades dentro del constructor.

De hecho, un patrón bastante común para la mayoría de definiciones de objetos es declarar las propiedades dentro del constructor, y los métodos en el prototipo. Esto hace el código más fácil de leer, ya que el constructor sólo contiene las definiciones de propiedades, y los métodos están en bloques separados. Por ejemplo:

// Constructor with property definitions

function Test(a, b, c, d) {
  // property definitions
}

// First method definition

Test.prototype.x = function() { ... };

// Second method definition

Test.prototype.y = function() { ... };

// etc.
Copy to Clipboard
Este patrón puede verse en acción en el ejemplo de la aplicación de planificador escolar de Piotr Zalewa.

