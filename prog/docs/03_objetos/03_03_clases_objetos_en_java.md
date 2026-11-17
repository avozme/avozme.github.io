---
layout: page
title: 3.3. Clases y objetos en Java
permalink: /objetos/declaracion-clases-objetos-java
nav_order: 3
has_children: true
parent: 3. Los objetos
grandparent: Programación
---

## 3.3. Clases y objetos en Java
{: .no_toc }

- TOC
{:toc}

Ya hemos visto qué es una clase y qué es un objeto, y también que los objetos tienen dentro datos (atributos o propiedades) y código (métodos).

Ahora llega el turno de aprender a crear clases y objetos con Java. Y, como los humanos aprendemos bien por imitación, vamos a aprenderlo mostrando unos ejemplos que luego podrás adaptar a tus necesidades.

### 3.3.1. Un ejemplo muy sencillo

Para crear un objeto y empezar a usarlo, es necesario que antes exista una clase (el molde)

Veremos más detalles sobre cómo crear clases en el tema 5, porque Java puede llegar a ser muy sutil en esto. Por ahora, aprenderemos a declarar clases simples. 

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

### 3.3.2. Un ejemplo más realista

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

