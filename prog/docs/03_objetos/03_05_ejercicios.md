---
layout: page
title: 3.5. Ejercicios propuestos
permalink: /objetos/ejercicios/
nav_order: 5
has_children: true
parent: 3. Los objetos
grandparent: Programación
---

## 3.5. Ejercicios propuestos

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
