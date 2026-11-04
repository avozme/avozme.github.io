---
layout: page
title: 2.6. Control de excepciones
permalink: /programacion-estructurada/control-excepciones/
nav_order: 6
has_children: true
parent: 2. Programación estructurada
grandparent: Programación
---
## 2.6. Control de excepciones
{: .no_toc }

- TOC
{:toc}

El manejo de excepciones consiste en **prever y capturar los posibles errores de ejecución** para redirigirlos a una rutina de código preprogramada, **evitando que el programa finalice inesperadamente**.

El control de excepciones permite al programador evitar que el programa falle durante la ejecución de forma inesperada. Bueno, mejor dicho: no evita que el programa falle, pero sí que explote. Se suele usar, por lo tanto, en lugares sensibles donde podría ocurrir un error de ejecución. Normalmente, en entradas de datos del usuario o en operaciones aritméticas con valores impredecibles.


### 2.6.1. El bloque try-catch-finally

Este es el lugar donde más frecuentemente te vas a encontrar un manejador de excepciones programa.

Un bloque `try-catch` tiene esta sintaxis genérica:

```java
try {
    // Sentencias que pueden fallar
} catch (ExcepcionTipo1 e) {
    // Control de la excepción 1
} catch (ExcepcionTipo2 e) {
    // Control de la excepción 2
} finally {
    // Código opcional que se ejecuta siempre
}
```

La JVM **intentará ejecutar las intrucciones del bloque `try`**. En caso de que **ocurra un error** de ejecución, buscará si ese error (o "excepción", en jerga informática) está recogido en alguno de los bloques `catch`. En tal caso, **ejecutará el bloque `catch`** y luego seguirá ejecutando el programa como si tal cosa.

El bloque `finally` es opcional. Si existe, se ejecutará siempre, no importa si ha ocurrido una excepción (y se ejecutó un bloque `catch`) o si el bloque `try` terminó sin error.

**Ejemplo:** Este programa divide un número a entre otro b y muestra el resultado:

```java
class Test {
   public static void main(String[] args) {
      int a = 10, b = 0, c;
      c = a / b;   // ¡¡***ERROR DE DIVISIÓN POR CERO***!!
      System.out.println("Resultado: " + c);
   }
}
```

Si compilas esta clase verás que todo va bien, pero intenta ejecutarla y verás lo que pasa. Obtendrás algo así como:

`Exception in thread "main" java.lang.ArithmeticExcepcion: / by zero at test.main (test.java:6)`

¡Eso te pasa por intentar dividir entre 0! No queda muy bien que digamos que un programa profesional emita estos mensajes apocalípticos durante la ejecución, y menos aún que detenga su ejecución bruscalemnte. 

Para eso se usa el control de excepciones. Observa como aplicarlo al ejemplo anterior:



```java
class Test {
    public static void main(String[] args) {
        int a = 10, b = 0, c;
        try {
            c = a / b;
        } catch (ArithmeticException e) {
            System.out.println("Error al hacer la división");
            c = 0;
        }
        System.out.println("Resultado: " + c);
    }
}
```

Ahora, si se produce una `ArithmeticException` al hacer la división, no salta la rutina por defecto de la JVM, sino que el error es redirigido a nuestro bloque `catch`, donde nuestro código toma las riendas de la situación y trata de redirigirla para que el programa pueda seguir ejecutándose y salir airoso del brete.

### 2.6.2. try-with-resources

Desde Java 8 existe una forma ligeramente diferente de escribir bloques `try-catch` denominada **try-with-resources**. Está pensada para **liberar los recursos reservados** (como archivos abiertos, por ejemplo) de forma automática aunque ocurra una excepción en el código.

Veremos con detalle esa sintaxis alternativa cuando trabajemos con ficheros y con conexiones remotas a bases de datos. De momento, solo lo mencionamos para que sepas lo que es, por si te lo encuentras por ahí.

Visualmente, lo único que distingue un bloque `try-with-resources` de un `try-catch` tradicional es que, el primero, lleva una o varias instrucciones entre paréntesis a continuación del `try`:

```java
// Bloque try-catch convencional
try {
   // Instrucciones que puede fallar
}
catch(Exception e) {
   // Manejador de excepciones
}


// Bloque try-with-resources
try (instrucciones que bloquean recursos) {
   // Instrucciones que pueden fallar
}
catch(Exception e) {
   // Manejador de excepciones
}
```

### 2.6.3. El manejo de excepciones y la entrada de datos por teclado

El lugar donde más frecuentemente te vas a encontrar un manejador de excepciones es, sin duda, en las **entradas de datos al programa**. La razón es sencilla: cuando un usuario (u otro sistema) puede introducir datos en nuestro programa, por definición estamos creando un "coladero" por donde pueden entrar toda clase de cosas desagradables: errores tipográficos (una letra cuando el programa esperaba un número, por ejemplo), código malicioso, cadenas vacías y vaya usted a saber qué. 

Por eso, encontrarás **la entrada de datos frecuentemente encerrada en un `try-catch` que la protege**. 

Observa el siguiente ejemplo. Se trata de una clase que pide dos números por teclado y los suma:

```java
public class Suma {
    public static void main (String [] args) {
        InputStreamReader isr = new InputStreamReader(System.in);
        BufferedReader br = new BufferedReader (isr);
        int s1, s2, suma;


        try {
            System.out.print("Sumando 1 : ");
            s1 = Integer.parseInt(br.readLine());
            System.out.print("Sumando 2 : ");
            s2 = Integer.parseInt(br.readLine());
        }
        catch (Exception e) {
            System.out.println("Se ha producido un error. 
                       Asegúrese de haber introducido dos números");
            s1 = 0; s2 = 0;
            e.printStackTrace();  // ¡Quitar esto de la versión final!
        }
        suma=s1+s2;
        System.out.println ("La suma es " + s1 + "+" + s2 +"="+ suma);
    }
}
```

Se ha encerrado toda la parte de entrada de datos en un bloque `try`, porque las dos entradas de datos se tienen que convertir a números enteros (`parseInt`) antes de procesarlas como sumandos, ya que las entradas de datos siempre son cadenas de caracteres. Y es ese proceso de conversión el que puede fallar.
¿No te lo crees? Prueba a ejecutar el método anterior sin `try-catch` y, cuando el programa te pida un número, teclea una letra. El `parseInt()` se pegará un zurriagazo.

Como sabemos que la forma más probable de fallo de este código es la conversión a entero, podemos capturar ese error de ejecución y tratarlo con nuestro propio código, en lugar de dejar a la JVM que se encargue ello y emita esos mensajes de error tan poco recomendables para el usuario final.

Una última nota: observa como, en el bloque `catch`, hemos colocado una llamada al método `printStackTrace()`. Eso nos muestra información sobre la excepción y puede ser muy útil a la hora de **depurar** el programa porque nos dirá exactamente qué excepción se ha producido, y así podremos contemplar nuevas excepciones que se nos hubieran escapado. Pero **en la versión definitiva** del programa **esa línea debería desaparecer** para evitar, de nuevo, mensajes de error incomprensibles al usuario final (la podemos sustituir por un mensaje de error comprensible para el usuario, por ejemplo).

### 2.6.4. Excepciones poco excepcionales: un uso incorrecto de las excepciones

Algunos programadores usan las excepciones para situaciones “poco excepcionales” (¡Ojo!, incluso algunas IAs lo hacen a veces). Esto **es una mala práctica** de programación y deberías evitarla.

Te lo explico mejor con un ejemplo. Mira la excepción de este código:


```java
// *** ¡¡OJO!! ¡¡CÓDIGO DE MALA CALIDAD!! ¡¡NO USAR!! ***

Scanner sc = new Scanner(System.in);
while (true) {
    try {
         System.out.print("Introduce un número: ");
         int num = sc.nextInt(); // si no es número → excepción
         System.out.println("Has introducido: " + num);
    } catch (Exception e) {
         System.out.println("Fin de la lectura (dato no válido)");
         break; // salimos del bucle gracias a la excepción
    }
}
```

Este bucle de lectura de datos funciona, es decir, lee números hasta que se introduce una letra, pero utiliza un mecanismo excepcional (el manejador de excepciones) para controlar algo que es “normal” según la propia naturaleza del bucle (que el usuario teclee una letra).

Este código se considera de mala calidad porque:

* Usa excepciones para controlar el flujo normal, no los errores (error grave de diseño)
* Las excepciones son costosas en tiempo de ejecución.
* El código es menos claro que si se hubiera planteado un bucle `while()` como es debido.

Por tanto, recuerda: **las excepciones deben reservarse para casos excepcionales**. De ahí su nombre. La ejecución normal de un algoritmo jamás debería pasar por una excepción.
