---
layout: page
title: 3.4. Métodos
permalink: /objetos/metodos/
nav_order: 4
has_children: true
parent: 3. Los objetos
grandparent: Programación
---

## 3.4. Métodos: paso de parámetros y devolución de resultados
{: .no_toc }

- TOC
{:toc}

### 3.4.1. Paso de parámetros

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

### 3.4.2. Devolución de resultados

Probablemente habrás observado que algunos métodos terminan con la sentencia **return** y otros nos. Los que sí lo hacen devuelven un resultado al código que los llamó. Ese resultado puede ser de cualquier tipo y también hay que indicarlo en la declaración del método.

El método seDatos() anterior no devuelve nada, por lo que, en la declaración, se usa la palabra void (vacío). Pero el método getEdad(), por ejemplo, devuelve un valor entero (la edad de la persona), y por eso se indica int en la declaración:

```java
public int getEdad() {
   return edad;
}
```

### 3.4.3. Métodos y atributos static

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

### 3.4.4. Constructores: primeros pasos

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
