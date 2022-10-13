---
layout: page
title: 10. Orientación a objetos
permalink: /orientacion-a-objetos/
nav_order: 10
has_children: true
parent: Introd. a la prog. y al diseño 3D
---

# 10. Orientación a objetos
{: .no_toc }

- TOC
{:toc}

En este capítulo vamos a introducir las técnicas de **programación orientada a objetos** y su implementación en Javascript.

La programación orientada a objetos es una forma de programar (un *paradigma*, dicen los teóricos) que implica organizar el código fuente de una determinada manera. Desde que este paradigma se impuso con fuerza en la década de 1990, se ha comprobado que las aplicaciones orientadas a objetos son más fáciles de diseñar y de mantener que las aplicaciones que usan técnicas de programación más anticuadas (lo que se llama **programación estructurada clásica**).

Javascript es un lenguaje orientado a objetos, aunque hace una interpretación un poco peculiar de lo que significa este concepto. En este capítulo, veremos primero qué es la programación orientada a objetos y luego nos centraremos en cómo aplicar esas ideas a Javascript.

## 10.1. Conceptos básicos de programación orientada a objetos

Los párrafos que vienen a continuación se basan en un texto **Yukihiro Matsumoto**, el creador del lenguaje Ruby. La razón es sencilla: me parece una explicación insuperable (gracias a Matsumoto, claro, no a mí).

Para entender qué significa exactamente **programación orientada a objetos**, primero tenemos que comprender en qué consiste la **programación tradicional** o no orientada a objetos.

En programación tradicional, cualquier problema informático se resuelve codificando un conjunto de algoritmos que trabajan sobre un conjunto de datos. Es decir, los datos son elementos pasivos: es el código el que se encarga de hacer todo el trabajo por ellos. 

A medida que los proyectos crecen, el código también lo hace, y llega un momento en el que es imposible saber cómo funciona todo el sistema. Surgen interacciones imprevistas e impredecibles entre distintas partes del programa. El fallo más tonto, como un error tipográfico, puede convertirse en una pesadilla cuya localización puede suponer muchas horas de trabajo (y, en consecuencia, mucho dinero).

Como dice Matsumoto, el mantenimiento de estos programas se convierte en algo parecido a **transportar un calamar gigante intentado que ninguno de sus tentáculos te alcance la cara**.

Lo que hace la programación orientada a objetos es cambiar esta forma de trabajar. No supone una revolución con los métodos anteriores, sino un cambio en la forma en la que se hacen las mismas cosas de siempre.

La mayoría del trabajo se delega a los propios datos, de modo que **los datos ya no son estáticos**, sino que se encargan de mantenerse en forma a sí mismos. De nuevo en palabras de Matsumoto: *dejamos de tratar cada pieza de dato como una caja en la que se puede abrir su tapa y arrojar cosas en ella y empezamos a tratarlos como máquinas funcionales cerradas con unos pocos interruptores y diales bien definidos*.

Un dato en programación orientada a objetos (es decir, una caja con interruptores, botoncitos y diales) puede tener, en sus tripas, algo muy simple o muy complejo. No se puede saber desde el exterior y no se nos permite abrir la máquina (excepto cuando estamos completamente seguros de que algo está mal en su diseño), por lo que se nos obliga a utilizar los interruptores y leer los diales para interactuar con los datos. Una vez construida una de esas máquinas, no queremos tener que volver a pensar en cómo funciona internamente.

### 10.1.1. Un ejemplo sencillo para entender el concepto de "objeto"

Seguimos con Matsumoto para ilustrar con un ejemplo sencillo qué es eso de una “máquina con unos pocos interruptores y diales”.

Seguramente en tu cocina tienes un horno microondas (aunque, en realidad, para este ejemplo podrías elegir cualquier electrodoméstico). El horno consta, entre otros muchos subsistemas, de un temporizador. Su trabajo consiste en mantener el horno encendido durante un tiempo determinado por el usuario.

¿Cómo podríamos representar esto en un lenguaje de programación? En Javascript, por ejemplo, el temporizador podría ser, simplemente, una variable de tipo *number*. El programa manipularía esa variable disminuyendo el valor una vez por segundo, y permitiría al usuario establecer el tiempo inicial del temporizador antes de poner el horno en marcha.

Con este enfoque tradicional, un error en cualquier parte del programa podría terminar asignando un valor falso a la variable, como un número negativo o un tiempo de varias horas. *Hay un número infinito de razones inesperadas por las que podría llegar a suceder esto*. Cualquiera con cierta experiencia programando sabe que se pueden perder horas o días tratando de encontrar ese error.

Pero si programamos con un lenguaje orientado a objetos, *no pensaremos en el tipo de datos que mejor se ajusta a un temporizador de microondas, sino en el modo en el que un temporizador de microondas funciona en el mundo real*.

No parece una gran diferencia, pero lo es.

El programador, o el diseñador, necesitará dedicar cierto tiempo a decidir qué es exactamente un temporizador de microondas y cómo se espera que el mundo exterior interactúe con el. Por fin, construirá una pequeña máquina (una pieza de software) con controles que permitan establecer, consultar y disminuir su valor.

Por ejemplo, podemos decidir crear el temporizador impidiendo asignarle un valor arbitrario, por la sencilla razón de que los temporizadores de microondas no trabajan de esa forma en el mundo real: solo permiten asignar múltiplos de 10 segundos, por lo general.

Es decir: existen sólo unas cuantas cosas que un temporizador de microondas puede hacer, y sólo permitiremos esas cosas. Así, si alguien desde otra parte del programa trata de asignar algún valor no permitido al temporizador, como un número negativo, le resultará imposible hacerlo por la sencilla razón de que el propio temporizador no lo permitirá. Ya no es un dato "tonto" y estático, que permite que cualquiera lo manipule. Es un dato "listo", con control y autonomía sobre su propio comportamiento. 

*Lo hemos convertido en un **objeto***. 

De ese modo, estaremos protegiendo una parte del programa de errores cometidos en otras partes y que, en programación tradicional, se propagan como el fuego en un tanque de gasolina.

Por si fuera poco, los lenguajes orientados a objetos nos permiten que, una vez que hayamos diseñado un temporizador de microondas (o el objeto que sea), podamos fabricar tantos como sea necesario. Habremos creado un patrón o molde de temporizador y, a partir de ese molde, se pueden construir objetos diferentes (pero similares) indefinidamente.

Pues bien, el *molde* se conoce como **clase**, y cada temporizador concreto que fabriquemos a partir de ese molde se conoce como **objeto**.

Aclaremos, sin embargo, que la programación orientada a objetos no es una solución milagrosa: nada impide, en cualquier lenguaje, escribir código poco claro, descuidado, inestable o directamente erróneo.

A continuación hablaremos de los “interruptores y diales” del temporizador del microondas (métodos) y, un poco después, veremos como se construyen los moldes (clases).

### 10.1.2. Métodos

En la programación orientada a objetos, como acabamos de ver, no se piensa en manipular los datos directamente desde el exterior de un objeto, sino que son los propios objetos los que deciden cómo se debe operar sobre ellos. Se pasa un mensaje al objeto y este mensaje provoca algún tipo de acción o respuesta significativa por parte del objeto. Esto ocurre sin que nos importe cómo realiza el objeto, interiormente, el trabajo.

Las *tareas que podemos pedir que un objeto realice* (o lo que es lo mismo, los *mensajes* que el objeto comprende) son los **métodos**. 

En Javascript, se llama a un método con la **notación punto** (como en Java, C++, Python, Ruby o muchos otros lenguajes). El objeto con el que nos comunicamos se nombra a la izquierda del punto. Por ejemplo: 

```javascript
mi_cadena = "Hoy es viernes";
alert("Cadena convertida a mayúsculas: " + mi_cadena.toUpperCase()); 
```

Hemos enviado a un objeto llamado *mi_cadena* (que es, evidentemente, una cadena de caracteres) el menaje *toUpperCase()*. La salida por pantalla será:

```
Cadena convertida a mayúsculas: HOY ES VIERNES
```

Intuitivamente es fácil comprender lo que ha ocurrido aquí: al objeto *mi_cadena* se le ha pedido que nos calcule una versión de sí mismo con todos los caracteres convertidos en mayúscula.

Técnicamente, lo que hemos hecho se llama **invocar el método *toUpperCase()*** del objeto mi_cadena. 

Otros objetos pueden hacer una interpretación un poco diferente de *toUpperCase()*, o no comprenderlo en absoluto.

Cuando un objeto recibe un mensaje que no conoce, se produce un error. Por lo tanto, hay que conocer qué métodos son aceptables para un objeto, aunque no se necesita saber como están programados por dentro. Los métodos, recuerda, son como los diales del horno microondas: como usuario, tienes que saber qué diales existen y cómo usarlos, pero no cómo están construidos.

### 10.1.3. Atributos

Los **atributos** de un objeto definen las **características** del mismo. Por ejemplo, un atributo del temporizador del microondas debería ser el número de segundos que éste debe permanecer activo, y un atributo de un objeto de tipo String debe de ser el número de caracteres de que consta la cadena.

Al programador que usa un objeto deberían importarle un bledo los atributos del mismo. Él (o ella) se encargará de usar el objeto a través de sus métodos, y éstos operarán con los atributos, si ello es necesario, de forma totalmente transparente al programador. 

Es decir, los atributos raramente son accesibles desde el exterior del objeto, salvo que, por razones de diseño, el programador del objeto haya decidido lo contrario.

### 10.1.4. Herencia

En programación orientada a objetos, unas clases pueden **heredar** de otras.

El concepto de herencia, en este contexto, se parece a la herencia genética entre seres vivos. Un ser vivo hereda por vía genética ciertas características de sus progenitores. Del mismo modo, una clase puede heredear ciertas características de sus clases-madre.

Esto es extraordinariamente útil para **reutilizar código** y, por lo tanto, facilitar y abaratar el desarrollo y el mantenimiento de las aplicaciones informáticas.

Por ejemplo, si en una aplicación tenemos una clase llamada *Vehículo* con ciertos atributos (*matrícula*, *marca*, *modelo*, etc), podemos crear varias subclases o clases-hijas llamadas *Turismo*, *Camión* o *Bicicleta*. Todas ellas heredarán los atributos y métodos de la clase-madre. Es decir, todas tendrán *matrícula*, *marca* y *modelo*, por ejemplo.

Pero algunas de las subclases pueden necesitar atributos o métodos adicionales (¿qué tal un atributo *número_plazas* para *Turismo*?), mientras que otras pueden prescindir de algunos atributos o métodos (las bicicletas no suelen tener matrícula).

Sin embargo, todas las subclases siguen siendo vehículos, y el código fuente que hayamos escrito para la clase *Vehículo* sigue siendo válido en cada una de ellas, sin necesidad de reescribirlo.

## 10.2. Los objetos en Javascript

Una vez comprendidos los conceptos básicos de programación orientada a objetos, vamos a ver cómo se utilizan en Javascript.

Javascript ha hecho, históricamente, una interpretación un poco peculiar del paradigma de orientación a objetos. De hecho, se decía de él que no era un lenguaje orientado a objetos, sino orientado a prototipos. No importa demasiado lo que esto significa, al menos de momento. Afortunadamente, desde la versión EC6 del año 2015, Javascript admite definiciones de clases y objetos mucho más convencionales y respetuosas con el paradigma.

### 10.2.1. Creación de objetos con Javascript

En JavaScript, **crear un objeto individual** es tan sencillo como declarar una variable con esta sintaxis:

```javascript
var book = {};
```

Por supuesto, esto creará un objeto llamado *book* que estará vacío. Para que el objeto tenga atributos y métodos, hay que rellenarlo con código. Observa el siguiente ejemplo:

```javascript
var book = {
  title: 'The Lord of the Rings',
  year: 1954,
  genre: ['epic', 'fantasy'],
  getTitle: function() {
    alert(this.title);
  }
  getGenres: function () {
    alert(this.genre[0] + ' ' + this.genre[1]);
  },
};
```

Este objeto se compone de **tres atributos** (*title, year, genre*) y dos métodos (*getGenres()* y *getTitle()*).

A los atributos les hemos asignado algunos valores. De este modo, podemos invocar a los métodos y comprobar que el objeto responde correctamente. Así:

```javascript
book.getTitle();
book.getGenres();
``` 

El resultado serán dos pantallas de tipo *alert()* donde se nos mostrarán los textos "The Lord of the Rings" y "epic fantasy", respectivamente.

En el objeto anterior, también podemos acceder y modificar los atributos del objeto. Observa este código:

```javascript
alert(book.title);
book.title = "Harry Potter and the Philosopher's Stone";
alert(book.title);
```

El primer *alert()* mostrará "The Lord of the Rings" (exactamente igual que el método *getTitle()*), mientras que el segundo *alert()* mostrará "Harry Potter and the Philosopher's Stone", porque hemos accedido y modificado el atributo *title* del objeto *book*.

### 10.2.2. El objeto "this"

Es posible que te haya llamado la atención la presencia de la palabra ***this*** en el objeto *book*.

Esa palabra se refiere **al objeto actual** sobre el que se está ejecutando el código. En el ejemplo, *this* es equivalente a *book*. Si, por ejemplo, le cambiásemos el nombre a la variable *book*, no será necesario cambiar el código fuente de sus métodos porque esos métodos se refieren a *this*, no a *book*. 

Puedes verlo mejor en este ejemplo:

```javascript
var book1 = {
  title: 'The Lord of the Rings',
  getTitle: function() {
    alert(this.title);
  }
}

var book2 = {
  title: 'The Hunger Games',
  getTitle: function() {
    alert(this.title);
  }
}
```

En el objeto *book1* podíamos haber utilizado el identificador *book1* en lugar de *this*, y funcionaría exactamente igual. Lo mismo suceden con *book2*. 

¿Cuál es la ventaja, entonces, de usar *this*? Muy pronto aprenderemos a crear múltiples objetos a partir *del mismo código fuente*. En ese caso, ¿qué tendríamos que poner en el código fuente? Si escribimos *book1*, el código ya no funcionaría para *book2*, y si escribimos *book2*, no funcionaría para *book1*. En cambio, escribiendo *this*, el método *getTitle()* funciona con *book1*, con *book2* y con cualquier otro objeto que creemos a partir del mismo molde.

### 10.2.3. Las clases en Javascript

*(**Nota importante**: como hemos dicho al principio, vamos a utilizar la sintaxis de Javascript EC6 y posterior. Si no sabes de qué estamos hablando, no te preocupes: solo tienes que mantener tu navegador web actualizado para asegurarte que entiende el Javascript moderno).*

Como vimos antes, una **clase** en un molde a partir del cual podemos crear objetos idénticos (aunque luego cada uno pueda evolucionar de forma independiente del resto).

Por ejemplo, podemos definir una clase *Book* que tenga en su interior los atributos (*title*, *genre*, etc) y los métodos (como *getTitle()*), y a partir de ella podemos crear todos los objetos de tipo *Book* que necesitemos. Así, solo habremos escrito el código fuente una vez, y lo podemos reutilizar tantas veces como sea necesario, no cada vez que vayamos a crear un libro.

En Javascript, la clase *Book* se declara así:

```javascript
class Book {
  title;                  // Atributo
  constructor(title) {    // Método constructor
    this.title = title;
  }
  getTitle() {            // Otro método
      alert(this.title);
  }
}
```

Esta clase contiene:
* **Un atributo** (*title*).
* **El método *constructor()***, que se ejecutará automáticamente al crear cada nuevo objeto del tipo *Book*. Es importante que se llame exactamente así. Observa que tiene un parámetro, *title*.
* **El método *getTitle()*** , que nos mostrará el título del libro mediante un *alert()*. Este método puede tener el nombre que queramos y podría hacer cualquier otra cosa con el libro. Nos limitamos al mostrar el título como ejemplo de algo que tiene sentido hacer con un libro.

Ahora podemos crear todos los *Books* que queramos, y todos utilizarán el mismo código y tendrán los mismos atributos. Por ejemplo:

```javascript
var book1 = new Book('The Lord of the Rings');
var book2 = new Book('The Hunger Games');
var book3 = new Book('The Neverending Story');
```

Acabamos de crear tres objetos de tipo *Book* diferentes. Observa cómo se usa la palabra *new* delante del nombre de la clase y como, al crear cada libro, debemos pasar su título como parámetro. *Esto es así porque el constructor de la clase tenía un parámetro*, el título del libro.

Ahora podemos usar los métodos de esos objetos, y cada uno actuará sobre su propio conjunto de atributos. Por ejemplo:

```javascript
book1.getTitle();
book2.getTitle();
book3.getTitle();
```

Este código provocará la ejecución de tres *alerts* consecutivos, que nos mostrarán, uno tras otro, los títulos de nuestros tres libros.

(Nota: por convenio, el nombre de la clase suele escribirse con mayúscula inicial, mientras que el nombre de los atributos, métodos y objetos individuales se escribe empezando en minúsculas).

### 10.2.4. Herencia en Javascript

*(Nuevamente, nos referiremos a cómo se maneja la herencia en las versiones recientes de Javascript (EC6 o posterior). ¡Asegúrate de tener tu navegador web actualizado!)*

Cuando se crea una clase, se puede hacer desde cero o bien se puede basar en otra clase preexistente. En este segundo caso, la nueva clase **hereda los atributos y los métodos** de la **clase-madre** o **superclase**, a los que puede añadir sus propios atributos y métodos.

Esto permite reutilizar grandes cantidades de código de forma bien organizada y sin necesidad de volver a escribirlo.

Lo vamos a entender mejor con otro ejemplo. **Vamos a crear una clase nueva**, en esta ocasión llamada ***Person***. Tendrá dos atributos (*name* y *age*) y un método (*getName()*), además del constructor:

```javascript
class Person {
  // Atributos
  name;   
  age;
  // Método constructor
  constructor(firstname, lastname, age) {
    this.name = {firstname, lastname};
    this.age = age;
  }
  // Otros métodos
  getName() {
    alert("Esta persona se llama: " + this.name.firstname + " " + this.name.lastname);
  }
}
```

En este caso, pasamos tres parámetros a la función constructora. Dos de ellos (*firstname* y *lastname*) los agrupamos dentro de un solo atributo (*name*). Por ese motivo, en el método *getName()* tenemos que acceder a cada uno de los elementos de *name* por separado. Podríamos haber utilizado dos atributos diferenciados, pero hemos preferido hacerlo así para darle un poco de variedad a los ejemplos y para que veas que el número de parámetros del constructor no tiene por qué coincidir con el número de atributos.

Ahora, por supuesto, podemos **crear todos los objetos que queramos a partir de la clase *Person***. Por ejemplo:

```javascript
var person1 = new Person('Juan', 'Pérez', 25);
var person2 = new Person('Ana', 'López', 37);
```

A continuación, podemos **crear nuestras clases-hija** o **clases derivadas** que hereden de *Person*. Observa detenidamente este código y enseguida entenderás cómo funciona la herencia:

```javascript
class Student extends Person {
  // Atributos adicionales
  course;
  // Método constructor
  constructor(firstname, lastname, age, course) {
    super(firstname, lastname, age);
    this.course = course;
  }
  // Otros métodos
  getCourse() {
    alert("Este estudiante está matriculado en el curso: " + this.course);
  }
}

class Teacher extends Person {
  // Atributos adcicionales
  speciality;
  // Método constructor
  constructor(firstname, lastname, age, speciality) {
    super(firstname, lastname, age);
    this.speciality = speciality;
  }
  // Otros métodos
  getSpeciality() {
    alert("La especialidad de este profesor/a es: " + this.speciality);
  }
}
```

¿No es cierto que los estudiantes y los profesores suelen ser personas (en la mayoría de los casos, al menos)? Pues bien, aquí hemos **definido dos nuevas clases llamadas *Student* y *Teacher***. Pero no las hemos definido *completamente*, sino que hemos **reutilizado la clase *Person***.

Y lo hemos hecho indicando que **tanto *Student* como *Teacher* heredan de la clase *Person***. Esto se indica con la palabra ***extends*** en la declaración de la clase. Es decir, que las dos nuevas clases heredan todo el contenido de su clase-madre.

Luego, simplemente, hemos añadido los nuevos atributos y nuevos métodos que existen en esas clases pero no tienen sentido en la clase-madre.

Observa bien los constructores de *Student* y *Teacher*. Ahí encontrarás la palabra ***super***. En el siguiente apartado veremos lo que significa. El resto del código es bastante trivial.

Ahora podemos hacer algo como esto y funcionará:

```javascript
var person1 = new Person('Juan', 'Pérez', 25);
var person2 = new Student('Ana', 'López', 16, '1º bachillerato A');
var person3 = new Teacher('Laura', 'Sánchez', 42, 'Matemáticas');
```

Acabamos de crear tres personas diferentes. La primera es una persona genérica, la segunda es una estudiante (y tiene un atributo y un método extra del que carecen las personas genéricas) y la tercera es una profesora (con su propio atributo y método extra).

(Por supuesto, los estudiantes y los profesores podrían tener más atributos y métodos adicionales, no solo uno).

Por lo tanto, los tres objetos tendrán un método *getName()*, pero solo el *Student* tendrá un método *getCourse()* y solo el *Teacher* tendrá un método *getSpeciality()*:

```javascript
person1.getName();        // Funciona
person2.getName();        // Funciona
person3.getName();        // Funciona

person1.getCourse();      // NO FUNCIONA. person1 no es un Student
person2.getCourse();      // Funciona
person3.getCourse();      // NO FUNCIONA. person3 no es un Student

person1.getSpeciality();  // NO FUNCIONA. person1 no es un Teacher
person2.getSpeciality();  // NO FUNCIONA. person2 no es un Teacher
person3.getSpeciality();  // Funciona
```

### 10.2.5. El objeto "super"

En los constructores de las clases *Student* y *Teacher* del apartado anterior hemos usado la palabra ***super***. ¿Qué significa exactamente?

***super*** es una **referencia a la superclase**.

Por lo tanto, al escribir ```super(firstname, lastname, age)```, estamos **invocando al constructor de la superclase *Person***. Esto es **obligatorio** hacerlo en todos los constructores de las clases derivadas.

Del mismo modo, si escribiéramos algo como ```super.getName()```, estaríamos invocando al método getName() de la clase madre, no de la clase actual. Esto, por supuesto, no es obligatorio, y solo lo haremos si realmente nuestro código lo necesita.

### 10.2.6. Algunos aspectos avanzados

Como ves, la programación orientada a objetos no es más que una manera particular de organizar el código fuente en clases que se ha revelado muy útil a la hora de minimizar el tiempo y el esfuerzo para construir y mantener proyectos grandes.

La programación orientada a objetos tiene otras características más avanzadas que vamos a describir muy brevemente, no porque sean complicadas de entender o de usar, sino porque solo tienen sentido cuando trabajas en proyectos muy grandes y con un conjunto de clases muy elaborado. 

Como de momento solo estamos aprendiendo, aún no necesitamos profundizar en ello. Ya lo harás cuando llegue tu momento y te lo pida el cuerpo. Lo que sí es importante es que estos conceptos te suenen para que puedas buscar información cuando lo necesites.

* **Clases abstractas**: son clases de las que *no se pueden crear objetos*. 

   ¿Entonces para qué sirven?, te preguntarás. Muy sencillo: para hacer herencia a partir de ellas.

   Normalmente, las clases abstractas son clases muy genéricas de las que no tiene sentido crear un objeto, porque ese objeto apenas sería funcional. La clase abstracta se limita a proporcionar un conjunto de atributos y métodos que heredan todas las clases-hija.

* **Herencia múltiple**: ocurre cuando una clase hereda de varias clases-madre a la vez. Proporciona una enorme flexibilidad a la hora de diseñar nuestra arquitectura de clases, pero también provoca no pocos problemas. Muchos lenguajes, entre ellos Javascript, no la permiten. Otros, como C++ o Python, sí.

* **Visibilidad**: los métodos y atributos de los objetos se pueden hacer **públicos o privados**. Si son públicos, quiere decir que pueden usarse desde cualquier lugar del código fuente. Si son privados, quiere decir que solo pueden usarse desde el código escrito dentro de la propia clase.

   Esto se hace para que el objeto funcione como una caja negra, cuyas "tripas" sean invisibles al exterior.

   Generalmente, los atributos de una clase suelen hacerse privados, mientras que la mayor parte de los métodos suelen ser públicos, pero puede haber tantas excepciones a esta regla que sería imposible enumerarlas. 

* **Sobrecarga**. Sobrecargar un método consiste en crear varias versiones del mismo que se diferencian por el número de parámetros. Puede llegar a ser muy útil en programas muy grandes con jerarquías de clases muy complejas.

* **Polimorfismo**. Se llama *polimorfismo* a la capacidad de los lenguajes orientados a objetos de que existan varias versiones diferentes de un mismo elemento (métodos, generalmente) que se nombran del mismo modo pero se comportan de modo diferente.

   Probablemente sigues sin entender qué narices significa la frase anterior aunque la hayas leído varias veces, ¿verdad?

   Tranquilidad, porque a todo el mundo le ocurre la primera vez que le mencionan el término polimorfismo. Te lo explico con un ejemplo, pero tampoco te preocupes demasiado: no es algo que vayas a usar hasta dentro de muuucho tiempo.

   Imagina que tenemos una superclase llamada *Person* con sus clases derivadas como *Student* o *Teacher*. Es decir, como en los ejemplos anteriores. Hasta aquí, bien.

   Ahora sigue imaginando que tienes un método, el que sea, en la clase *Person*. Por ejemplo, *getProfession()*. Todos los objetos de tipo *Student* o *Teacher* heredarán el método *getProfession()*. Ahora bien, ¿tiene sentido que ese método sea el mismo para *Student* que para *Teacher*? Probablemente no. ¡Para empezar, el estudiante ni siquiera tiene profesión (aún)!

   Una cosa muy interesante que pueden hacer las clases-hija es **sobreescribir** los métodos, es decir, coger un método heredado y cambiar su código fuente. Así, puedes tener diferentes versiones del método *getProfession()*, una para cada clase de la jerarquía.

   Y ya lo tienes. Eso es una manifestación del **polimorfismo**: tener un método (*getProfession()*) con diferentes formas o implementaciones. Según cuál sea el objeto con el que lo llames, se ejecutará una versión u otra del método. Esto puede parecer una chorrada, pero con jerarquías de clases muy complejas ayuda a resolver situaciones muy chungas. Por ejemplo: ¿qué pasa si un profesor es, a su vez, estudiante en algún curso? Según el papel de esa persona en cada momento, habrá que ejecutar una versión diferente de *getProfession()*.

   Si has llegado hasta aquí en esta explicación, puedes volver a leer la definición de polimorfismo y seguramente sí la entenderás.

### 10.2.7. Objetos predefinidos de Javascript

Ahora que ya conoces un poco sobre la programación orientada a objetos y cómo trabajar con ella en Javascript, puedo confesarte un secreto: *has estado utilizando objetos desde el primer momento en el que empezaste a trabajar con Javascript*.

Así es. Como Javascript es un lenguaje orientado a objetos, hay un montón de objetos predefinidos que existen en todos los programas Javascript para que los uses si los necesitas.

Por ejemplo, cuando hacías *Math.rand()*, estabas invocando al método *rand()* del **objeto *Math***. Este objeto es un poco especial, porque no necesitas crear una instancia. Es decir, no necesitas hacer ```var math = new Math()``` para usarlo. Con algunas clases ocurre esto, y se llaman **clases estáticas**.

Otro objeto predefinido que seguro que has utilizado sin saber que lo era es el **objeto *window***. En este caso, es un objeto normal, no estático, pero no tenemos que crearlo con ```var window = new Window()``` porque Javascript lo crea automáticamente para nosotros cada vez que abrimos una ventana del navegador web.

De hecho, los métodos *alert()* o *confirm()* son, en realidad, métodos del objeto *window*. Es decir, podemos escribir *window.alert()* o *window.confirm()*, y funcionarían exactamente igual. Lo que ocurre es que, si no indicamos un objeto delante del nombre del método, Javascript interpretará que se trata de un método del objeto *window*.

Y así hay otro buen puñado de objetos predefinidos cuya existencia te conviene conocer. Algunos de ellos son:

* **Math**: contiene un montón de métodos para operaciones matemáticas.
* **window**: métodos y atributos para manejar la ventana del navegador donde se ejecuta la aplicación.
* **Date**: para trabajar con fechas y horas.
* **Number**: operaciones relacionadas con números.
* **String**: para trabajar con cadenas de caracteres.
* **Array**: para trabajar con arrays.
* **JSON**: para trabajar con datos complejos codificados como JSON, un formato de intercambio de información muy utilizado con Javascript y otros lenguajes.
* **Error**: para manipular los errores de ejecución y obtener información sobre ellos. 

## 10.3. Un ejemplo completo

Vamos a terminar esta pequeña introducción a la programación orientada a objetos mostrando un ejemplo completo desarrollado con Javascript.

Puedes considerarlo un ejercicio resuelto. Es decir: *primero puedes intentar hacerlo tú, y luego comparar tu intento con mi solución*. No es necesario que tu solución y la mía sean idénticas, desde luego, puesto que siempre hay varias formas correctas de hacer lo mismo.

#### Lo que queremos hacer

Este es un ejemplo clásico para practicar la herencia entre clases, porque resulta fácil de entender y de programar.

Se trata de escribir un programa que sea capaz de calcular ciertas magnitudes, como el área y el perímetro, de muchos tipos diferentes de figuras geométricas. Empezaremos por círculos, cuadrados y rectángulos, pero podríamos extender el programa con facilidad para abarcar otras figuras.

Observa el diagrama de aquí abajo. Se trata de un **diagrama de clases**, una representación gráfica de las clases que existen en un programa y cómo heredan unas de otras. No te asustes: es sencillo leer un diagrama de clases. Más abajo te doy algunas pistas.

![Diagrama de clases - Figuras geométricas](/docs/prog-y-3d/_site/assets/images/06-01-figuras-geometricas.jpg)

Cada "caja" de este diatrama es una clase, y en cada clase se indica su nombre, sus atributos y sus métodos. Delante de cada atributo y método verás un símbolo: + significa que ese atributo o método es público, es decir, accesible desde otras clases, y - significa que es privado, accesible solo desde la propia clase.

Si no se indica lo contrario, Javascript considerará que los atributos y métodos son públicos. Es decir, todos los atributos y métodos que hemos usado hasta ahora son públicos. En sistemas complejos, es importante distinguir los atributos y métodos públicos de los privados.

Además, el diagrama expresa cómo heredan las clases unas de otras. La clase *Figura* es la madre de toda la jerarquía, también llamada **superclase**. Las clases *Círculo* y *Rectángulo* son hijas de *Figura*, es decir, **subclases** o **clases derivadas**. Por último, la clase *Cuadrado* es subclase de *Rectángulo*.

Por supuesto, podíamos haber añadido más figuras, pero con estas ya tienes entretenimiento para un rato. Observa, por cierto, como *Cuadrado* hereda de *Rectángulo*, y no directamente de *Figura*.

El programa que vamos a escribir tiene que incluir lo siguiente:

1. **La superclase *Figura*** (figura geométrica), que contendrá:
   * Dos atributos: color (String) y relleno (boolean).
   * Un constructor que recibirá dos argumentos para inicializar los atributos.
   * *Getters* y *setters*, es decir, métodos para consultar el valor de los atributos (*getColor()* y *getRelleno()*) y para establecer el valor de los atributos (*setColor()* y *setRelleno()*). Entiendes por qué se llaman *getters* y *setters*, ¿verdad?
   * Un método *toString()* que devolverá la cadena: "Soy una figura de color xxx y rellena/no rellena", según lo que valgan los atributos en ese momento.
2. **Una subclase de *Figura* llamada *Círculo***. La clase *Círculo* contendrá:
   * Un atributo llamado *radio* (un número real).
   * Un constructor, como se ve en el diagrama de clases.
   * *Getter* y *setter* para el radio.
   * Los métodos *getArea()* y *getPerimetro()*. Si no recuerdas como calcular el área y el perímetro (o circunferencia) de un círculo... bueno, ¿para qué está la wikipedia?
   * El método *toString()* heredado de *Figura* se debe sobreescribir. Ahora, el método devolverá: "Soy un círculo con radio = x, esta es mi superclase: yyy", donde yyy es la salida del método *toString()* de la superclase de *Figura*.
4. **Una subclase de *Figura* llamada *Rectángulo***. La clase *Rectángulo* se comportará igual que *Círculo*, con las lógicas diferencias en atributos y métodos *getters* y *setters*. Mira el diagrama de clases si tienes alguna duda.
5. **Una subclase de *Rectángulo* llamada *Cuadrado***. Esta clase podía haberse modelado como subclase de *Figura*, pero es más cómodo hacerlo como subclase de *Rectángulo*, porque podemos aprovechar casi todo el código de su superclase. Basta con crear el siguiente constructor:

   ```javascript
   class Cuadrado {
      constructor(side) {
         super(side, side);  // Llama al constructor de la superclase Rectangulo
      }
   }
   ```

   * Además de crear el constructor, sobreescribiremos, como en los otros casos, el método *toString()*.
   * Atención, pregunta: ¿necesitarás sobreescribir *getArea()* y *getPerimetro()*, o funcionarán tal y como han sido heredados de *Rectángulo*? Haz la prueba a ver qué pasa...
   * También sobreescribiremos los métodos *setAlto()* y *setAncho()* para evitar que el largo y el ancho del cuadrado puedan tener dimensiones diferentes.
6. Finalmente, tendremos que escribir un fragmento de código para testear que todo lo anterior funcione, creando unas cuantas figuras de cada tipo y llamando a algunos métodos.

#### Nuestra implementación

En la implementación de la clase *Figura* vamos a usar comentarios en formato **javadoc**. Es una manera de escribir los comentarios que te vas a encontrar a menudo por ahí, puesto que se trata de un estándar de la industria.

El resto de clases son tan sencillas que nos hemos ahorrado los comentarios para no complicar innecesariamente el código fuente.

Como en otras ocasiones, tu trabajo aquí es intentar resolver el ejercicio antes de ver la solución. Y, una vez que empieces a leer la solución, hacerlo poco a poco y sin prisas.

```html
<!DOCTYPE html>
<html>

<head>
    <title>Jerarquía de figuras geométricas</title>
</head>

<body>
    <script>
        /**
         * Clase Figura (figura geométrica genérica)
         */
        class Figura {

            color;    // Atributos
            relleno;

            /**
             * Constructor con parámetros.
             *
             * @param c El color de la figura.
             * @param r Indica si la figura está rellena o no.
             */
            constructor(c, r) {
                this.color = c;
                this.relleno = r;
            }

            /**
             * Determina el color de la figura.
             *
             * @return El color de la figura.
             */
            getColor() {
                return this.color;
            }

            /**
             * Establece el color de la figura.
             *
             * @param c El color de la figura.
             */
            setColor(c) {
                this.color = c;
            }

            /**
             * Determina si la figura está o no rellena.
             *
             * @return True si la figura está rellena, false si no está.
             */
            estaRelleno() {
                return this.relleno;
            }

            /**
             * Cambia el valor del relleno de la figura.
             *
             * @param r True para que la figura pase a estar rellena,
             *          false para que no lo esté.
             */
            setRelleno(r) {
                this.relleno = r;
            }

            /**
             * Devuelve una cadena descriptiva del objeto actual.
             * @return La cadena con la descripción del objeto.
             */
            toString() {
                var s = "Soy una figura de color " + this.color + " y ";
                if (this.relleno) s = s + "estoy rellena";
                else s = s + "no estoy rellena";
                return s;
            }

        }

        class Circulo extends Figura {

            radio;   // Atributo

            constructor(color, relleno, r) {
                super(color, relleno);
                this.radio = r;
            }

            getRadio() {
                return this.radio;
            }

            setRadio(r) {
                this.radio = r;
            }

            getArea() {
                return Math.PI * this.radio * this.radio;
            }

            getPerimetro() {
                return 2 * Math.PI * this.radio;
            }

            toString() {
                return "Soy un círculo de radio " + this.radio +
                    " y esta es mi superclase: " + super.toString();
            }
        }


        class Rectangulo extends Figura {

            ancho;   // Atributos
            alto;

            constructor(color, relleno, an, al) {
                super(color, relleno);
                this.ancho = an;
                this.alto = al;
            }

            getAncho() {
                return this.ancho;
            }

            setAncho(an) {
                this.ancho = an;
            }

            getAlto() {
                return this.alto;
            }

            setAlto(al) {
                this.alto = al;
            }

            getArea() {
                return this.ancho * this.alto;
            }

            getPerimetro() {
                return 2 * this.ancho + 2 * this.alto;
            }

            toString() {
                return "Soy un rectángulo de base " + this.ancho +
                    " y altura " + this.alto +
                    " y esta es mi superclase: " + super.toString();
            }
        }

        class Cuadrado extends Rectangulo {

            constructor(color, relleno, lado) {
                super(lado, lado, color, relleno);
            }

            setAncho(a) {
                super.setAncho(a);
                super.setAlto(a);
            }

            setAlto(a) {
                super.setAncho(a);
                super.setAlto(a);
            }

            toString() {
                return "Soy un cuadrado de lado " + super.getAncho() +
                    " y esta es mi superclase: " + super.toString();
            }
        }

        // --------------------------------------------------------------------------------
        // El siguiente código sirve para TESTEAR la jerarquía de clases
        // --------------------------------------------------------------------------------

        // Primero, vamos a crear una figura con cada constructor y a llamar a toString()
        var fig1 = new Figura("rojo", true);
        alert(fig1.toString());
        var circulo1 = new Circulo("azul", true, 1.5);
        alert(circulo1.toString());
        var rect1 = new Rectangulo("amarillo", false, 8.3, 2.4);
        alert(rect1.toString());
        var cuadrado1 = new Cuadrado("verde", true, 3.1);
        alert(cuadrado1.toString());

        // Probamos ahora algunos métodos sobre los objetos anteriores
        // y volvemos a llamar a toString() para comprobar que 
        // los atributos han cambiado como se esperaba.
        fig1.setColor("blanco");
        alert(fig1.toString());
        circulo1.setRadio(2.5);
        alert("El área del círculo es " + circulo1.getArea());
        alert(circulo1.toString());
        rect1.setAlto(3.0);
        alert("El perímetro del rectángulo es " + rect1.getPerimetro());
        alert(rect1.toString());
        cuadrado1.setAncho(5.1);
        alert("La base del cuadrado es " + cuadrado1.getAlto() + " y su altura es " + cuadrado1.getAncho());
        alert("El área del cuadrado es " + cuadrado1.getArea());
        alert(cuadrado1.toString());
    </script>
</body>

</html>
```