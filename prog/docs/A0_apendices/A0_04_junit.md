---
layout: page
title: A4. JUnit
permalink: /apendices/junit/
nav_order: 4
has_children: true
parent: Apéndices
grandparent: Programación
---

## Apéndice 4. JUnit

Cuando un programa ha sido escrito, aún queda mucho trabajo: hay que comprobar que funciona como debe. Las pruebas de un programa deberían incluir las siguientes comprobaciones:

* Verificar que el programa no tiene errores de ejecución.  
  * Verificar que el programa hace lo que se esperaba de él.  
  * Verificar que el programa es eficiente, es decir, que no tarda una barbaridad en hacer su tarea.

Existen herramientas de prueba y testeo semiautomáticas, como JUnit, que veremos someramente al final de este apéndice.

El objetivo final es construir software de buena calidad. Pero, ¿qué demonios es un programa de "buena calidad"? Empezaremos por tratar de definir ese concepto tan escurridizo.

## **II.1 La calidad en el software**

La calidad no es un concepto fácil de definir. Dice un aforismo que “sólo se nota la existencia de la calidad en un producto cuando está ausente”

Además, el concepto de calidad en el software es diferente que en otros productos industriales porque:

* El software se desarrolla, no se fabrica.  
  * El software no tiene existencia física: su calidad no depende del soporte.  
  * El software no se degrada con el uso: su calidad no depende de su resistencia.  
  * El software es muy complejo y la ingeniería del software es aún muy joven e inexperta: el software se entrega muchas veces con defectos conocidos o desconocidos.  
  * El software se suele hacer a medida.  
  * El software es más flexible que otros productos: puede cambiarse con más facilidad.

### **Factores de calidad**

Como el concepto de calidad es escurridizo, se suele hablar de los factores que afectan a la calidad, y que son, entre otros:

* Facilidad de uso, prueba y mantenimiento.  
  * Eficiencia: que el sistema trabaje consumiendo la menor cantidad posible de recursos.  
  * Fiabilidad: que el sistema no falle al realizar sus funciones.  
  * Corrección: que el software haga lo que se espera de él.  
  * Flexibilidad: que sea fácil de modificar.  
  * Portabilidad: que sea fácil de migrar a otro entorno.  
  * Eficacia: que resuelva todos los problemas de la mejor forma posible.

Si el software cumple con estos requisitos, se supone que es de “buena calidad”

### **Estándares de calidad**

Los estándares de calidad, como ISO 9001, establecen cómo debe funcionar la organización para asegurar un desarrollo de calidad:

* Realización de un plan de control de la calidad a lo largo de todo el proyecto.  
  * Normas que el personal debe cumplir al desarrollar su trabajo para asegurar la calidad.  
  * Actividades de revisión y auditorías periódicas.  
  * Informes de problemas.  
  * Controles sobre el análisis, el diseño, la codificación y la documentación  
  * Planes de control y prueba a lo largo de todo el desarrollo.  
  * Métricas de software para control del proyecto.  
  * Etc.

Pero, ojo, los estándares de calidad no aseguran que el producto desarrollado sea en efecto un producto de calidad, solo que habrá más posibilidades de que lo sea.

Una tercera parte independiente evaluará el trabajo de desarrollo de software. Es lo que se denomina una auditoría externa. Si el auditor establece que el equipo de desarrollo ha cumplido las recomendaciones de ISO o AENOR, la empresa quedará certificada y avalada como fabricante de “software de calidad”

Las normas de calidad de la ISO (International Organization for Standarization) surgieron en sectores de seguridad crítica: nuclear, militar, aeroespacial. Con el tiempo se han extendido a todos los sectores. En concreto, la serie ISO 9000 es aplicable a las empresas fabricantes de software. La norma actual es la ISO 9001:2000

Puedes encontrar más información en:  
http\://www\.iso.ch/iso/en/iso9000-14000/index.htm

En cuanto a AENOR (Asociación Española de Normalización y Certificación), recomienda usar la ISO 9001:2000, o una versión más antigua, ISO 9001:1994, ligeramente modificada para el desarrollo de software. AENOR tiene publicaciones donde explica cómo aplicar las normas ISO de calidad para obtener la certificación y se encarga de certificar, mediante auditorías, a las empresas que cumplen la norma ISO.

## **II.2 La fase de pruebas**

Puede que estés pensando: vale, pero a mí, como programador o programadora, ¿todo esto de la calidad que narices me importa?

He visto a muchos programadores principiantes que se contentan con entregar versiones de sus programas mal resueltas, ineficientes, poco escalables o ilegibles escudándose en el hecho de que funcionan. “Es una porquería, lo sé, pero funciona”. Quizá cambiaron esa forma de trabajar con el transcurso de los años, pero no soy optimista al respecto. Creo que las personas tendemos a reproducir, en cada ámbito de nuestras vidas, la forma de trabajar que nos ha dado resultados en el pasado.

Por lo tanto, aspirar a escribir programas de buena calidad (siendo, como hemos visto, un concepto escurridizo) debería ser nuestro objetivo desde el primer momento. No importa si estás haciendo algo tan simple como una tabla de multiplicar o algo tan complejo como un juego de ajedrez inteligente. Deberías conocer las técnicas que, como programador, te van a facilitar la labor de crear programas de calidad.

Pues bien, el objetivo de la fase de pruebas es precisamente asegurar la calidad del software según los factores que hemos enumerado más arriba, y, ¡sorpresa\!, el encargado de hacer esas pruebas, excepto en organizaciones muy grandes, suele ser el propio programador.

Las pruebas consisten en dos acciones complementarias:

* Verificación: comprobar que el sistema funciona y no produce errores de ejecución.  
  * Validación: comprobar que el sistema responde a las especificaciones de requisitos del cliente, es decir, que el programa hace lo que debe hacer.

La acciones y técnicas de la fase de pruebas se llevan a cabo en todas las etapas del desarrollo del software, no solo al final. El momento del desarrollo en el que nos encontremos condiciona el tipo de pruebas que podremos realizar, pero las pruebas siempre están realimentando (o deberían) el proceso de desarrollo. 

## **Pruebas según la forma de realización**

La idea es que, como programador, no te pongas a probar tu código a lo loco. Todos comprobamos de alguna forma que nuestro código funciona: ejecutamos nuestro programa, introducimos unos cuantos datos de entrada, y comprobamos que la salida es correcta o que, al menos, lo parece.

Pues no: eso no es suficiente.

Necesitamos algo más sistemático, algún mecanismo que nos asegure que hemos comprobado todas las posibilidades. Esos mecanismos son las pruebas de caja negra y de caja blanca:

* **De caja negra**: comprueban el funcionamiento de un componente software (por ejemplo, un módulo) a través de su interfaz, sin ocuparse de su funcionamiento interno.  
  * **De caja blanca**: comprueban el funcionamiento interno de un componente software.

### **Pruebas de caja negra**

Cada componente (p. ej., un método, o una clase) se prueba sin “mirar” en su interior. Es decir, se comprueba si el componente realiza correctamente sus funciones enviándole juegos de datos diferentes y estudiando su reacción.

Los juegos de datos deben cubrir todos los casos posibles. Para ello, se aísla cada entrada del módulo y se establecen casos de prueba para:

* Datos válidos  
  * Datos no válidos

El módulo debe reaccionar adecuadamente a cada conjunto de datos.

Los conjuntos de datos similares se denominan **clases de equivalencia**. Por ejemplo, supón que estamos probando un método encargado de calcular la edad en años de una persona a partir de su fecha de nacimiento. El interfaz del método puede ser algo así:

**`int calcularEdad (int diaNac, int mesNac, int anoNac);`**

Para este método podemos establecer las siguientes clases de equivalencia y probar el módulo con datos pertenecientes a cada clase. Las clases de equivalencia pueden ser:

A) Clases de equivalencia válidas:

* DiaNac \>= 1 y DiaNac \<= 31

* MesNac \>= 1 y MesNac \<= 12

* AñoNac \> 1900 y AñoNac \<= \[Año actual\]

B) Clases de equivalencia inválidas:

* DiaNac \< 1 o DiaNac \> 31

* MesNac \< 1 o MesNac \> 12

* AñoNac \< 1900 o AñoNac \> \[Año actual\]

Si el módulo reacciona bien con datos de todas las clases, habrá superado la prueba de caja negra. Pero observa que no hay que probar TODOS los datos posibles: basta con hacer UNA prueba de cada clase de equivalencia. En este ejemplo bastaría con probar:

* Un día correcto (p. ej: 10\) junto con un mes y un año correctos.

* Un día correcto, un mes correcto y un año incorrecto (p. ej: 2020\)

* Un día correcto junto con un mes y un año incorrectos.

* Etc.

Es, pues, necesario elaborar previamente una cuidadosa batería de pruebas para que no se nos pase ninguna  posibilidad. Además, a veces no es nada fácil identificar todas las clases de equivalencia. Por ejemplo: si introducimos la fecha '30/02/1995' el módulo debería interpretarlo como un error, pero según nuestro diseño de pruebas esa fecha es correcta.

Además de hacer una prueba con cada clase de equivalencia, es recomendable añadir casos de prueba para:

* Valores límite (justo por encima y por debajo de los rangos válidos)

* Valores típicos de error (errores comunes que puedan cometer los usuarios)

* Valores imposibles (por ejemplo, introduciendo cadenas alfanuméricas donde se esperaban números enteros)

### **Pruebas de caja blanca**

En las pruebas de caja blanca, cada componente (p. ej., un método) se prueba indagando en su lógica interna. Para ello se confeccionan baterías de prueba que hagan ejecutarse todos los posibles caminos al menos una vez.

Por ejemplo, si en un módulo tenemos un fragmento de algoritmo con esta forma:

**`if (a > 10) {`**  
   **`acciones 1`**  
**`}`**  
**`else {`**  
   **`acciones 2`**  
**`}`**

... habrá que probarlo con los datos a \> 10 y a \<= 10 para que el flujo de ejecución discurra por los dos caminos posibles.

Para diseñar las baterías de pruebas de caja blanca hay que tener en cuenta, por tanto:

* Las condiciones o ramificaciones.  
  * Las condiciones múltiples.  
  * Los bucles (que se pueden ejecutar 0, 1 o varias veces)  
  * Las invocaciones a otros bloques de código.

## **II.3 Pruebas según el momento de realización**

Según el momento en el que se realicen, las pruebas pueden ser:

* Unitarias: prueba de un componente individual aislado del resto del sistema.  
  * De integración: prueba de varios componentes individuales cooperando entre sí.  
  * De sistema: prueba de todos los componentes individuales ensamblados y cooperando entre sí.  
  * De carga: prueba de integración con un volumen de datos real.  
  * De aceptación: pruebas con la presencia del cliente para obtener su visto bueno.

### **Pruebas unitarias**

En las pruebas unitarias, cada componente (método, clase, paquete, etc.) debe ser probado de manera individual y aislado del resto, diseñando para ese componente pruebas de caja negra y de caja blanca.

### **Pruebas de integración**

Los componentes no trabajan en realidad aislados, sino que están acoplados: comparten información y se invocan unos a otros. Una vez probados individualmente, es necesario probar que los diferentes componentes funcionan bien cuando trabajan juntos.

Los fallos en estas pruebas suelen deberse a problemas en la comunicación entre clases.

Las pruebas de integración suelen hacerse poco a poco. Por ejemplo, primero se toman dos o tres clases ya probadas, y se les hace una prueba conjunta. Cuando la superan, se unen a otros dos o tres, y así sucesivamente.

Las baterías de pruebas de integración deben ser de caja negra y de caja blanca.

### **Pruebas de sistema**

Cuando las pruebas de integración alcanzan a la totalidad del sistema, se denomina prueba de sistema.

Si el sistema es grande, puede hablarse de subsistemas, pero estas pruebas no dejan de ser otra cosa que pruebas de integración cada vez más grandes.

Las baterías de pruebas de sistema también serán de caja negra y de caja blanca.

### **Pruebas de carga**

Las pruebas suelen hacerse con baterías de prueba irreales, diseñadas para probar el sistema en condiciones controladas.

Debe hacerse una prueba con un volumen de datos real para comprobar que el sistema reacciona correctamente. Por ejemplo, no es lo mismo manipular una tabla de una base de datos con 20 registros de prueba que una tabla real con 200.000 registros. Un programa que funcionaba estupendamente con 20 registros puede pegarse el batacazo padre con 200.000.

### **Pruebas de aceptación**

Se realizan en el domicilio del cliente. No son “demos” ni prototipos, sino muestras del sistema funcionando en tiempo real.

Un tipo especial (y frecuente) de estas pruebas es la ejecución del sistema en paralelo con el viejo sistema al que va a sustituir.

## **II.4 ¿Cuándo se realizan las pruebas?:**

La fase de pruebas debe estar presente a lo largo de todo el desarrollo, y no sólo cuando el programa está terminado.

Como criterios generales digamos que:

* Las pruebas unitarias se deben hacer al finalizar cada componente software (método, clase, paquete...)  
  * Las pruebas de integración se deben hacer cuando se disponga de varios componentes ya probados.  
  * Las pruebas de sistema se deben hacer al final del desarrollo, cuando se dispone de todo el sistema.  
  * Las pruebas de carga se deben hacer después de superar las pruebas de sistema.  
  * Las pruebas de aceptación se harán siempre después de las de carga.

#### **Estrategia de arriba a abajo (top \- down)**

Consiste en comenzar las pruebas unitarias por las clases de alto nivel, más abstractos, que interactúan con el usuario o que controlan otras clases. Para probarlos, los componentes que están por debajo deben ser “simulados” mediante clases auxiliares vacías, que sólo se encargan de devolver las respuestas esperadas.

#### **Estrategia de abajo a arriba (bottom \- up)**

Consiste en comenzar las pruebas unitarias por las clases de bajo nivel, que interaccionan con otros sistemas (como bases de datos). Este enfoque no suele necesitar de módulos auxiliares, y además permite trabajar en paralelo (diferentes personas pueden probar diferentes módulos al mismo tiempo)

Como contrapartida, es una estrategia más difícil de planificar y gestionar.

#### **Estrategia combinada**

Los componentes críticos se prueban en bottom – up, y el resto de top \- down. 

## **II.5 Versiones de prueba del software de propósito general**

Nosotros casi siempre nos referimos a sistemas de gestión hechos a medida, pero en el software comercial de propósito general las pruebas son diferentes, existiendo versiones alfa y versiones beta de los productos antes de lanzarlos al mercado.

* **Versión alfa:** el producto aún es inestable, pero está completo. Se envía a un grupo reducido y escogido de usuarios para que lo prueben siguiendo ciertas pautas y comunicando los errores observados al equipo de desarrollo.  
  * **Versión beta:** el producto es más estable que en la versión alfa, pero no está completamente probado. Se ofrece a un conjunto amplio de usuarios para que lo prueben (a veces, al público en general). Los usuarios deben tener algún mecanismo para poder comunicar, si lo desean, las incidencias que observen. A veces, una versión beta permanece en el mercado durante años.  
  * **Release candidate:** versión del sistema terminada y probada, lista para su publicación salvo correcciones de última hora.  
  * **Versión de disponibilidad general o versión dorada:** producto en su versión final que está en proceso de lanzamiento inminente. A veces se denomina **versión RTM** (Release To Manufacturing)

## **II.6 Las pruebas en el software libre**

Los sistemas de software libre son los distribuidos bajo licencia GPL o similar. Esta licencia permite usar, copiar, distribuir y modificar el código fuente libremente.

Librerar el código hace que cualquiera pueda participar en la mejora del software. Esa colaboración hace que el software evolucione muy deprisa y con menor coste.

¡Pero “libre” no significa “gratis”\!

El software libre sólo se refiere a la forma de distribución del programa, no a su desarrollo: el desarrollo del software libre sigue el mismo proceso de ingeniería que el software propietario.

El Open source (código abierto) es un movimiento parecido al del software libre, pero basado en consideraciones técnicas en lugar de ideológicas. En la práctica, los dos movimientos se confunden. Las grandes compañías recelan del movimiento del software libre, por lo que apoyan principalmente el Open source. La diferencia entre los dos movimientos, por tanto, no es práctica, sino ideológica.

* Software libre: el software debe compartirse para fomentar la colaboración entre usuarios, la cohesión social, el acceso de todos a la tecnología y la compartición de conocimiento (que hace a los programas avanzar más deprisa con menos coste)  
  * Open source: sólo se quedan con la última parte.

El software libre y el open source tienen ciertas peculiaridades por la forma en que se distribuye este tipo de software:

* Las versiones beta son más abundantes que en el software propietario, y no suelen dirigirse a un público restringido, sino a todo el mundo.  
  * A menudo, se liberan versiones inestables (cuya estabilidad no ha sido bien comprobada)  
  * Las versiones estables suelen tener una cifra par en el segundo número de la versión. Por ejemplo: 4.6.18.8-0  
  * Las versiones inestables suelen tener una cifra impar en el segundo número de la versión. Ej. 4.7.18.8-0

## **II.7 Recomendaciones finales para la fase de pruebas**

1. Las pruebas deben ser realizadas por personas distintas a los diseñadores y programadores.

2. Los casos de prueba pueden ser tan numerosos que deben diseñarse y documentarse cuidadosamente.

3. La fase de pruebas debe extenderse a lo largo de todo el proceso de desarrollo y no solo al final.

4. La posibilidad de encontrar errores en un determinado componente del programa es proporcional al número de errores ya encontrados en ese mismo componente.

5. TODAS las fases de prueba encuentran errores. Si no los encontramos, no es que no existan, es que estamos haciendo mal las pruebas.

6. La fase de pruebas nunca termina: no podemos asegurar que “éste era el último error que quedaba”. Para dar por finalizada la fase de pruebas podemos usar dos criterios aproximados:

7. Terminar cuando expire el tiempo asignado a las pruebas en la planificación del proyecto.

8. Terminar cuando los casos de prueba que hemos diseñado ya no detecten más errores.

## **II.8 JUnit: una introducción**

JUnit es un **marco de pruebas unitarias** para Java. Permite automatizar las pruebas de tipo unitario para librar al programador de tener que hacerlas “a mano”.

JUnit es software libre y se puede descargar de [junit.org](http://junit.org), aunque los IDEs más populares lo incluyen de un modo u otro. Más abajo  explicamos cómo ponerlo en marcha en Netbeans y VS Code.

Aunque veréis JUnit con más detalle en el módulo de Entornos de Desarrollo, vamos a presentaros aquí los conceptos fundamentales para que conozcáis una herramienta de automatización de pruebas.

Ten en cuenta que **JUnit no es la única herramienta de testing para Java**. Existen muchas más, entre las que podemos mencionar:

* **TestNG**: alternativa popular a JUnit  
  * **Arquillian**: orientada a pruebas de integración más que unitarias  
  * **Mockito**: para simular dependencias  
  * **Selenium**: se usa para testing de aplicaciones web hechas con Java

## **Cómo funciona JUnit**

JUnit basa su funcionamiento en escribir **programas de testeo** que prueban métodos de otras clases para ver si devuelven lo que se supone que deben devolver.

Por ejemplo, supongamos que tenemos una clase **Calculadora** cuyo funcionamiento queremos probar con JUnit:

**`public class Calculadora {`**

    **`public int sumar(int a, int b) {`**  
        **`return a + b;`**  
    **`}`**

    **`public int restar(int a, int b) {`**  
        **`return a - b;`**  
    **`}`**  
**`}`**

Para JUnit tendremos que escribir una **clase de prueba**, que podemos llamar **CalculadoraTest**, con este aspecto:

**`public class CalculadoraTest {`**  
    **`@Test`**  
    **`public void testSumar() {`**  
        **`Calculadora calculadora = new Calculadora();`**  
        **`int resultado = calculadora.sumar(2, 3);`**  
        **`assertEquals(5, resultado, "La suma debería ser 5");`**  
    **`}`**  
    **`@Test`**  
    **`public void testRestar() {`**  
        **`// Instanciamos la clase Calculadora`**  
        **`Calculadora calculadora = new Calculadora();`**

        **`// Llamamos al método a probar y comparamos el resultado`**  
        **`int resultado = calculadora.restar(5, 3);`**

        **`// Verificamos que el resultado sea el esperado`**  
        **`assertEquals(2, resultado, "La resta debería ser 2");`**  
    **`}`**  
**`}`**

* La **anotación @Test** indica que el método es una prueba o test de otro método.  
* **assertEquals(expected, actual)** se usa para comparar el valor esperado con el valor real obtenido. Si son iguales, la prueba queda superada; si no, la prueba falla y muestra el mensaje «La suma debería ser 5» o «La resta debería ser 2».

## **Los asserts**

Los **asserts** que aparecen en las clases de prueba de JUnit son los que establecen qué clase de test se va a pasar en cada caso. Los hay de muchos tipos:

* assertEquals() → Para ver si un método devuelve un valor concreto  
  * assertNotEquals() → Al contrario que el anterior  
  * assertTrue() → Para ver si una condición es verdadera  
  * assertFalse() → Al contrario que el anterior  
  * assertSame() → Para ver si dos objetos son el mismo (en memoria)  
  * assertArrayEquals() → Para ver si dos arrays contienen lo mismo  
  * assertThrows() → Para ver si se lanza una excepción determinada  
  * assertTimeout() → Para ver si un proceso tarda menos de un tiempo determinado.  
  * assertAll() → Para agrupar varios assert en un solo bloque.

Hoy en día, lo más habitual es **pasarle a una IA** el código de la clase que queremos probar y pedirle que genere una clase de prueba. Luego solo tenemos que revisar el código generado por la IA para comprobar que los tests tienen sentido y que no queda nada importante por comprobar.

## **Configurar Maven para JUnit en VSCode**

Solo asegúrate de que tu proyecto Maven tiene estas dependencias en el archivo **pom.xml** (si aún no sabes qué es Maven, mira el apéndice sobre Maven que acompaña a este mismo tema, donde explicamos cómo funciona este gestor de proyectos).

De momento, no necesitas saber mucho de Maven salvo dos cosas: Maven te ayuda a enlazar tus programas Java con herramientas adicionales, como JUnit, y su configuración se controla desde un archivo llamado **pom.xml**, que debe contener esto para poder usar JUnit:

**`<dependency>`**  
    **`<groupId>org.junit.jupiter</groupId>`**  
    **`<artifactId>junit-jupiter-api</artifactId>`**  
    **`<version>5.8.2</version>`**  
    **`<scope>test</scope>`**  
**`</dependency>`**  
**`<dependency>`**  
    **`<groupId>org.junit.jupiter</groupId>`**  
    **`<artifactId>junit-jupiter-engine</artifactId>`**  
    **`<version>5.8.2</version>`**  
    **`<scope>test</scope>`**  
**`</dependency>`**

(Jupiter es la biblioteca que permite crear las clases con anotaciones @Test)

## **Ejecución de las pruebas**

Una vez que tenemos programadas las clases de testeo y que hemos configurado el proyecto para usar JUnit, solo tenemos que lanzar los tests.

**A) Con NetBeans, Eclipse o IntelliJ:**

Se lanzan las pruebas desde el propio IDE.

P. ej: en NetBeans, se lanzan con Run → Test Project

**B) Con Visual Studio Code**

Necesitarás haber creado un proyecto Maven (o Gradle).

Ahora puedes lanzar las pruebas a mano con el comando:

**`mvn test`**

O también puedes abrir la paleta de comandos (Ctrl+Shift+P) y buscar “Test Explorer”. Se abrirá la vista Test Explorer, desde donde puedes lanzar las pruebas sin salirte a la consola.

Tras ejecutar las pruebas, JUnit nos dará un informe como este:

**`-------------------------------------------------------`**  
 **`T E S T S`**  
**`-------------------------------------------------------`**  
**`Running CalculadoraTest`**  
**`Tests run: 2, Failures: 0, Errors: 0, Skipped: 0, Time elapsed: 0.159 sec`**  
**`Results :`**  
**`(Aquí se indicarían los errores encontrados, en caso de haberlos)`**

[image1]: <data:image/png;base64,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>