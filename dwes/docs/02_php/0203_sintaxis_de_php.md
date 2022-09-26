---
layout: page
title: 2.3 Sintaxis de PHP
permalink: /php/sintaxis-de-php.html
nav_order: 3
has_children: false
parent: 2 Introducción a PHP
grand_parent: Desarrollo Web en Entorno Servidor
---

## 2.3. La sintaxis de PHP
{: .no_toc }

- TOC
{:toc}

### 2.3.1. Cómo incrustar PHP dentro de HTML

El código PHP se escribe incrustado dentro de un documento de texto mediante estas etiquetas:

```html
<?php .... ?>
```

**Este archivo debe tener *SIEMPRE* extensión .php, *NO* .html**

Cuando el servidor web encuentre un archivo con extensión .html, lo enviará al cliente sin mirar ni siquiera lo que hay en su interior.

En cambio, cuando el servidor web encuentre un archivo con extensión .php, lo abrirá y buscará las etiquetas <?php ... ?>, y ejecutará el código que haya dentro antes de enviar el resultado al cliente. El resto del archivo, es decir, lo que esté fuera de las etiquetas de PHP, se enviará al cliente sin modificar.

### 2.3.2. Comentarios

Los comentarios de PHP se pueden escribir de varias formas:

```php
// Comentario de una línea
#  Comentario de una línea
/* Comentario de una o varias líneas */
```

### 2.3.3. Variables y constantes

Las **variables** de una función/clase/método PHP son siempre **locales**, es decir, sólo están disponibles en esa función/clase/método, salvo que se indique otra cosa.

Si se definen variables fuera de una función, serán **globales** a todo el fichero actual, pero no pueden usarse en el código ubicado en otros ficheros. Existen maneras de lograr que una variable sea global a todo el código, pero, vamos... ¿en serio quieres hacer eso?

(Nota anticipatoria: hay ciertas situaciones en las que una aplicación web *necesita* variables globales, pero ya lo veremos en su momento. Por ahora, solo recuerda que usar variables globales es una pésima práctica de programación).

El **identificador** de variable siempre debe empezar por $. Esta es una peculiaridad de PHP que al principio descoloca un poco.

En PHP, no es necesario declarar las variables: al inicializarlas queda especificado el tipo. A partir de PHP7 pueden indicarse los tipos predefinidos (int, float, string...), pero solo es algo optativo.

Ejemplos:

```php
$a = 4;                  // Variable entera (PHP5+)
int $a = 4;              // Variable entera (PHP7+)
$media = 52.75;          // Variable real
$texto = "Hoy es lunes"; // Variable string
```

Cualquier variable puede **cambiarse de tipo** con funciones como **intval(), floatval()** o **strval()**:

```php
$a = "10";          // $a es una cadena
$b = intval($a);    // $a se convierte a entero y se asigna a $b
```

Como no hay que declarar las variables, a veces no estaremos seguros de si una variable existe y tiene un valor válido (no nulo) asignado. Para averiguarlo existe la función **isset()**, que nos devuelve *true* si la variable existe y *false* en caso contrario. Del mismo modo, hay otra función muy útil, **unset()**, que hace desaparecer a una variable ya definida y libera la memoria que ocupaba:

```php
if (isset($nombre)) {
    echo $nombre;    // Solo muestra el nombre si la variable tiene algún valor
} else {
    echo "El nombre no está definido";
}
```

**El tipado de PHP es débil**, así que puedes encontrarte expresiones donde **se mezclen tipos**. PHP hará las conversiones que le parezca oportunas, con resultados a veces imprevisibles, por lo que no es buena idea recurrir a estas estratagemas a menos que sepas muy bien lo que estás haciendo y el resultado que obtendrás. Por ejemplo:

```php
$a = 3;                // a es un integer
$b = "Hoy es lunes";   // b es un string
$c = $a + $b;          // ¡Esto funciona, pero ¿a que no predices bien el resultado?
```

Los **tipos de datos** predefinidos en PHP son:

* integer (entero)
* double (real)
* bool (booleano)
* string (cadena)
* array (pues eso)

En cuanto a las **constantes**, se crean con la función **define()**:

```php
define("NOMBRE", "Pepito Pérez");  // NOMBRE es una constante
echo NOMBRE;    // Muestra el valor de la constante. ¡Fíjate en que no lleva el símbolo $!
```

Las constantes, por convenio, suelen nombrarse en MAYÚSCULAS. El propio PHP tiene muchas constantes predefinidas (todas en mayúsculas) de ámbito global, como PHP_VERSION o PHP_OS. 

Algunas de estas constantes predefinidas empiezan y terminan por un doble subrayado, como \_\_LINE\_\_ o \_\_FILE\_\_. Estas constantes se llaman **constantes mágicas** y nos van a resultar muy útiles más adelante. 


### 2.3.4. Operadores

Los operadores en PHP son iguales que los de Java, que, a su vez, los heredó de C/C++:

* Asignación: $a = 3;
* Comparación:  ==, <=, >=, !=, <=>, etc.
* Operadores aritméticos: +, -, *, /, %...
* Operadores lógicos: &&, \|\|, !
* Operadores de asignación combinados: +=, -=, ++, --, *=, /=, etc

Existen operadores más esotéricos, como el operador ternario o los operadores a nivel de bit, que no usaremos demasiado. Sin embargo, PHP cuenta con algunos operadores curiosos que a lo mejor no conoces y que te pueden ahorrar mucho trabajo. Te los cuento brevemente:

**Operador de coalescencia nulo**. Con ese nombre tan rebuscado se conoce al operador ?? (doble interrogante). Simplemente, asigna a una variable valor u otro dependiendo de si está definida o no:

```php
$user = $nombreUsuario ?? "sin-nombre";
```

La variable $user del ejemplo anterior tomará el valor $nombreUsuario si y solo si esa variable, $nombreUsuario, existe y tiene un valor asignado. En caso contrario, tomará el valor "sin-nombre".

**Operador nave espacial**. Así se conoce el operador <==>. ¡Otro bonito chiste de informáticos! Se usa para comparar dos expresiones y decidir cuál es la menor. Devuelve -1 (si la primera expresión es menor que la segunda), 0 (si son iguales) o 1 (si la primera expresión es mayor que la segunda):

```php
$resultado = $var1 <==> $var2;
echo $resultado;   // Mostrará -1, 0 o 1, dependiendo de los valores de $var1 y $var2
```

### 2.3.5. Arrays

Los arrays en PHP son colecciones de variables del mismo o de distinto tipo identificadas por un índice. Se parecen más a los ArrayList de Java que a los arrays clásicos propiamente dichos.

```php
$a[1] = "lunes";
$a[2] = 1;        // El array de PHP puede contener datos de diferente tipo en cada elemento
$a[3] = "martes";
$a[4] = 2;
etc.
```

El índice no tiene por qué ser un número entero: puede ser un String (array asociativo):

```php
$a["ESP"] = "España";
$a["FRA"] = "Francia";
$a["POR"] = "Portugal";
```

Como los arrays son objetos, dispones de un montón de métodos y atributos para consultarlos y manipularlos. No es mi intención proporcionarte aquí una lista exhaustiva, porque son muchos y para eso ya está la documentación oficial, pero sí te voy a mostrar algunos que te permitan hacerte una idea:

* **count($a)**: devuelve el número de elementos del array $a.
* **in_array("valor", $a)**: busca el elemento "valor" en el array $a. Devuelve *true* o *false*.
* **unset($a[4])**: elimina un elemento (el 4, en este ejemplo) del array $a.
* **next($a)**: devuelve el siguiente elemento de un array (el primero, si es la primera vez que se invoca).
* **prev($a)**: devuelve el elemento anterior de un array (el último si es la primera vez que se invoca).
* **array_push($a, $elemento)**: añade el $elemento al final del array $a.
* **$elemento = array_pop($a)**: elimina el último elemento del array $a (y lo asigna a la variable $elemento).
* **sort($a)** y **asort($a)**: ordena el array $a. *sort()* se utiliza con arrays convencionales y *asort()* con arrays asociativos.

### 2.3.6. Estructuras de control

Vamos a hacer un repaso muy rápido por las estructuras de control de PHP. Si ya conoces otros lenguajes como Java, todas te resultarán familiares.

#### Condicionales

El condicional doble tiene la sintaxis habitual:

```php
if (condición)
{
acciones-1;
}
else
{
acciones-2;
}
```

Por supuesto, la parte del ```else``` puede eliminarse si no la necesitas, y obtendrías un condicional simple.

#### Bucle while

El bucle de *tipo while* tiene este aspecto:

```php
while (condición)
{
acciones;
}
```

#### Bucle repeat

El bucle de *tipo repeat*, es decir, con la condición al final, tiene esta sintaxis:

```php
do
{
acciones;
}
while (condición);
```

#### Bucles for y foreach

El bucle *for* controlado por contador es idéntico a C/C++ y Java:

```php
for (inicialización; condición; incremento)
{
acciones;
}
```

Hay una variedad de bucle *for* muy interesante: el bucle *foreach* para recorrido de arrays asociativos:

```php
foreach ($array as $índice=>$var)
{
acciones;
}
```

El bucle *foreach* se repite una vez para cada valor guardado en el array. Ese valor se asigna a la variable *$var* en cada repetición.

Por ejemplo:

```php
$a["ESP"] = "España";
$a["FRA"] = "Francia";
$a["POR"] = "Portugal";

foreach ($a as $pais=>$codigo) {
    echo "Nombre del país: $pais - Código: $codigo<br>";
}
```

La salida de este programa será:

```
Nombre del país: España - Código: ESP
Nombre del país: Francia - Código: FRA
Nombre del país: Portugal - Código: POR
```

#### break y continue

Como en muchos otros lenguajes, las instrucciones **break** y **continue** pueden usarse en el interior del cuerpo de los bucles para lograr este comportamiento:

* **break**. "Rompe" el bucle, es decir, se sale del bucle y continúa ejecutando el programa por la instrucción que haya inmediatamente después del mismo.
* **continue**. Deja de ejecutar la iteración actual y vuelve al comienzo del bucle para iniciar una nueva iteración.

#### Sintaxis alternativa con dos puntos

Las estructuras de control de PHP tienen una sintaxis alternativa que elimina el uso de las llaves, muy denostadas por algunos programadores. Por ejemplo, una instrucción *if* puede escribirse de forma tradicional:

```php
if ($i < 0) {
    echo "La variable es menor que cero";
}
```

...o bien con la "sintaxis dos puntos":

```php
if ($i < 0):
    echo "La variable es menor que cero";
endif;
```

Puedes elegir la sintaxis con la que te sientas más cómodo/a. Nosotros, en este manual, usaremos la primera por estar más extendida, pero las dos son igualmente válidas.

### 2.3.7. Funciones y procedimientos

Los subprogramas (funciones y procedimientos) se escriben en PHP del mismo modo: con la palabra *function*.

* Las **funciones** deben devolver un valor en su última línea con *return*. Si necesitas devolver varios valores, puedes empaquetarlos en un array o en un objeto.
   Ten en cuenta que, después de un *return*, la función terminará de forma inmediata y devolverá el control de ejecución al código desde la que fue invocada. Es decir: cualquier línea de código de la función que esté por debajo del *return* nunca se ejecutará.
* Los **procedimientos** no tienen *return*. Realizan su función y terminan.

Los **argumentos** de las funciones o procedimientos en PHP siembre se pasan ***por valor***.

Por si hay algún despistado/a: pasar argumentos por valor significa que PHP copiará en el parámetro de la función el *valor* de la variable con la que se invoca a dicha función, pero serán dos variables distintas. Si modificamos un parámetro dentro del código de la función, la variable con la que fue invocada no se verá afectada.

Veámoslo con un ejempolo. Esta es una función con dos argumentos:

```php
function calcular_iva($base, $porcentaje)
{
   $total = $base * $porcentaje / 100;
   return $total;
}
```

Para invocar a esta función, haremos algo como esto en algún otro punto del código fuente:

```php
$iva = $calcular_iva($precio_del_articulo, 21);
```

En esta ocasión, hemos invocado a la función $calcular_iva() con dos parámetros: una variable ($precio_del_articulo) y una constante literal (21). Ambos parámetros se pasan por valor a la función. Eso significa que el valor de $precio_del_articulo se copia en el parámetro $base, y el valor del literal 21 se copia en $porcentaje. Cualquier modificación de $base o $porcentaje que pudiera producirse dentro del código de la función, no afectaría para nada a las variables originales ($precio_del_articulo y el literal 21). Por último, la función devuelve un valor mediante su *return* y ese valor se asigna a la varible $iva.

Si esto del paso de parámetros por valor sigue sonándote a chino, quizá deberías repasar tus conocimientos sobre fundamentos de programación. Busca en internet algo como "paso de parametros por valor y por referencia" y dedica un rato a desentrañar los misterios del paso de parámetros antes de continuar.

#### Definir el tipo de los argumentos

Desde PHP7, se puede definir el tipo de los argumentos de cualquier función:

```php
function calcular_iva(float $base, float $porcentaje) {
    ...
}
```

Esto es completamente optativo. Ahora bien, si defines el tipo de los argumentos y luego le pasas a la función un argumento de otro tipo, obtendrás un error de ejecución *TypeError*, como es lógico.

#### Definir el tipo de la función

Desde PHP7 también se puede, optativamente, definir el tipo de datos que devolverá la función en el *return*:

```php
function calcular_iva(float $base, float $porcentaje): float {
    ...
}
```

Esto provocará que se evalúe de forma estricta el tipo de datos durante la invocación a la función y que se puedan producir errores de tipo (*TypeError*) en tiempo de ejecución, como es natural.

#### Argumentos con valor predefinido

Algo muy útil que nos ofrece PHP es la posibilidad de asignar un valor por defecto a los argumentos de las funciones. Observa este ejemplo:

```php
function calcular_iva($base, $porcentaje = 0.21) {
    ...
}
```

El argumento *$porcentaje* tiene un valor por defecto, 0.21. Eso significa que podemos invocar esta función de dos maneras:

```php
$a = calcular_iva(1000, 0.04); // Calculará el IVA de 1000 euros con un porcentaje del 4%
$b = calcular_iva(1000);       // Calculará el IVA de 1000 euros con un porcentaje del 21%
```

Como ves, en la primera invocación pasamos un valor para el argumento *$porcentaje* (0.04), por lo que ese argumento tomará ese valor. En cambio, en la segunda invocación nos olvidamos del segundo parámetro. Eso provocaría un error de ejecución en muchos lenguajes de programación, ¿verdad? Bueno, pues PHP lo ejecutará sin problemas, porque le hemos asignado un valor por defecto a *$porcentaje*.

Eso significa que, si no le pasamos ningún valor, el argumento tomará su valor por defecto (0.21), y la función se ejecutará con ese valor asignado a esa variable.

#### Funciones anónimas o *closures*

Javascript ha extendido como una plaga el uso de las funciones anónimas o *closures*. Se trata de funciones que no tienen nombre y que se usan directamente en una asignación a una variable o como parámetro de otra función.

Yo tengo una opinión muy radical al respecto: *las funciones anónimas hacen el código mucho más ilegible y su uso debería restringirse al máximo*. Pero tienes que saber que esta no es una opinión mayoritaria, al menos actualmente.

Las funciones anónimas deberían usarse solo cuando la función en cuestión no va a invocarse nunca desde ningún otro punto del programa: el hecho de no asignarles nombre hace que su código no sea reutilizable.

Aquí puedes ver un ejemplo sencillo de función anónima:


```php
$numero = 8;
$doble = function(int $numero) {
    return $numero * 2;
}
echo $doble;   // Imprimirá 16
```

#### include y require

Cuando desarrollamos mucho código, a menudo colocamos colecciones de funciones (llamadas **bibliotecas**) en archivos diferentes que el resto del código.

Para usar una función definida en otro archivo, necesitamos incluir ese código en nuestro archivo actual. Eso se hace con **include** y **require**:

* **include** se utiliza para incluir el código fuente de la biblioteca en nuestro archivo actual. Si la biblioteca no se encuentra, se produce un error de ejecución, pero el script actual continúa ejecutándose.
* **require** también se utiliza para incluir el código fuente de la biblioteca en nuestro archivo actual. Pero si la biblioteca no se encuentra, se produce un error de ejecución y el script actual se detiene.

Las variantes **include_once** y **require_once** se utilizan para evitar las inclusiones repetidas de código. Estas suelen ocurrir cuando nuestro programa es muy grande y varios scripts incluyen las mismas bibliotecas. Para prevenir errores por redefinición de funciones, se usa **include_once** o **require_once**:

```php
include_once "mi_biblioteca.php";    // Incluye las funciones del archivo mi_biblioteca.php
```

El uso de *include* y *require* está en retroceso gracias a los **espacios con nombre** de las versiones recientes de PHP. Más adelante hablaremos de ellos.


### 2.3.8. Clases y objetos

A partir de la versión 5, PHP incluyó un completo soporte para orientación a objetos. Las clases, métodos y atributos se declaran de forma muy semejante a C++ y Java.

#### Declaración de clases

En este ejemplo puedes ver cómo se declara una clase en PHP. Observa cómo se indica la **herencia** (*extends*) y cómo se declara el **constructor**  (*__construct()*):

```php
class MiClase extends ClaseMadre
{
    // Declaración de propiedades (atributos)
    public  $var1 = 'soy una variable pública de instancia';
    private $var2 = 'y yo soy otra variable de instancia, pero privada';

    // Método constructor (siempre se llama __construct)
    public function __construct($valor) {
        $this->var2 = $valor;
    }

    // Declaración de un método público
    public function mostrarVar() {
        echo $this->var2;
    }

    // Declaración de un método privado
    private function resetVar() {
       $this->var2 = '';
    }

    public function otroMetodo() {
        // ...etc...
    }
}
```

Algo que suele llamar la atención de los programadores que vienen de Java u otros lenguajes semejantes es que PHP **no utiliza la notación punto** para acceder a los miembros de una clase, sino la **notación flecha (->)**. Por eso en el ejemplo anterior ves cosas como *$this->var* en lugar de *this.var*

#### Instanciación de objetos

Para **instanciar** un objeto de una clase, se usa la palabra ***new***. El constructor puede llevar parámetros o no, como en Java. En el ejemplo anterior, el constructor tenía un argumento, así que *new* se usará así:

```php
$miObjeto = new miClase('Estoy aprendiendo PHP');
$miObjeto->mostrarVar();
```

La salida de este programa sería "Estoy aprendiendo PHP".

#### $this y parent

Como ya habrás supuesto, la variable **$this** se refiere siempre al objeto que está ejecutando el código, exactamente igual que en Java, Javascript y muchos otros lenguajes orientados a objeto.

A veces, cuando tenemos una jerarquía de clases y unas heredan de otras, necesitamos invocar algún método de la clase madre o superclase. En ese caso, usaremos la palabra **parent** seguida de la **notación cuatro puntos (::)**. Observa cómo se hace en este ejemplo, en el que el constructor de la subclase invoca al constructor de la superclase:

```php
class MiClase {
    private $var1;
    public function __construct($param) {
        $this->var1 = $param;
    }
}

class MiSubclase extends MiClase {
    private $var2;
    public function __construct($param1, $param2) {
        $this->var2 = $param2;
        parent::__construct($param1);   // Llamada a un método de la superclase
    }
}
```

#### Miembros públicos, privados y protegidos

En PHP, mientras no se indique otra cosa, todos los miembros de una clase se considerarán públicos (*public*). Como en Java, existen tres niveles de visibilidad que podemos escoger para cada atributo y cada método:

* **public**: ese método o atributo es accesible desde el exterior de la clase.
* **private**: ese método o atributo solo puede usarse desde dentro de la clase.
* **protected**: ese método o atributo puede usarse desde dentro de la clase o desde cualquier clase hija.

#### Getters y setters

En PHP también es habitual, como en muchos lenguajes de programación, que los atributos sean a menudo privados y que existan métodos ***getters*** y ***setters*** que se encarguen de manipularlos adecuadamente, sin que se acceda a los datos de los objetos desde el exterior. Esto es esencial para que los objetos funcionen como "cajas negras".

Los *getters* suelen devolver el valor de un atributo, pero los *setters*, en otros lenguajes, no devuelven nada. Sin embargo, en PHP es costumbre que los *setters* devuelvan el objeto completo, es decir, que terminen con un ***return $this***. Así:

```php
class MiClase {
    private $var1 = "Esto es un atributo privado";
    // Getter
    public function getVar1() {
        return $var1;
    }
    // Setter
    public function setVar1($value) {
        $var1 = $value;
        return $this;   // Devolvemos el objeto al terminar
    }
}
```

Si lo hacemos así, estaremos creando lo que se llama un **fluent interface** o interfaz fluido, que es una forma rebuscada de decir que podremos encadenar varias invocaciones a métodos del objeto en una sola instrucción, algo que permite que el código se vea más organizado y legible.

Para que veas en qué consiste el *fluent interface*, vamos a poner un ejemplo. Imagina que la clase anterior tuviera más atributos (*$var1, $var2, $var3*, etc), cada uno con sus respectivos *setters*. La forma tradicional de invocarlos todos sería algo así:

```php
$obj = new MiClase();
$obj->setVar1($valor1);
$obj->setVar2($valor2);
$obj->setVar3($valor3);
// etc.
```

En cambio, si los *setters* devuelven *this* podemos usar un *fluent interface* y escribirlo así:

```php
$obj = new MiClase();
$obj->setVar1($valor1)
    ->setVar2($valor2)
    ->setVar3($valor2);
```

Puede parecer un cambio insignificante, pero cuando los objetos son muy complejos, el código *fluent* se hace mucho más legible que el código tradicional. ¡Además, es gratis!

#### Clases abstractas e interfaces

Como en Java y otros lenguajes orientados a objetos, PHP también permite construir **clases abstractas**, que son clases que no se pueden instanciar. El objetivo de estas clases, como recordarás, es crear un molde a partir del cual puedan heredar otras clases que sí sean instanciables.

Una clase abstracta se crea añadiendo la palabra *abstract* a la definición de la clase:

```php
abstract class MiClase {
    ...
}
```

También existen los **interfaces**, que son parecidos a las clases abstractas pero no pueden incorporar nada de código a los métodos. Es decir, se trata de una mera definición de métodos. Todas las clases que usen ese interfaz deben respetar e implementar esos métodos. Esto se hace cuando queremos que una colección de clases independientes proporcionen un conjunto de métodos homogéneos.

Los interfaces se definen así:

```php
interface MiInterface {
    public function unMetodo();
    public function otroMetodo($parametro1, $parametro2);
    etc.
}
```

Posteriormente, todas las clases que vayan a usar ese interface deben declararse de este modo:

```php
class MiClase implements MiInterface {
    ...
}
```

#### Métodos estáticos

Los métodos estáticos en PHP funcionan igual que en Java: se usan cuando una clase no tiene estado (es decir, no tiene atributos), o bien cuando ese método no tiene nada que ver con el estado de los objetos, sino que responde exactamente igual para todas las instancias.

Los métodos estáticos se declaran así:

```php
class MiClase {
    // Esto es un método estático
    public static function miMetodo() {
        ...
    }
}
```

Para invocar un método estático, como es lógico, no es necesario instanciar ningún objeto. De hecho, si intentamos invocarlo a través de un objeto, fallará. Estos métodos se invocan a través del nombre de la clase directamente, usando la **notación cuatro puntos (::)**:

```php
// Esto invocará el método estático del ejemplo anterior
MiClase::miMetodo();
```

### 2.3.9. Salida de datos

PHP puede hacer salidas de datos como cualquier otro lenguaje de programación: puede enviar texto a una impresora p datos a un fichero. O puede dibujar ventanas y componentes en un entorno gráfico de usuario.

Pero cuando PHP se ejecuta como parte de una aplicación web, nada de eso tiene sentido: esa salida se produciría en el servidor, y nosotros no estamos allí para verla. Nosotros estamos en nuestro cliente (navegador web), pidiendo al servidor que ejecute un programa PHP.

En este contexto, la salida PHP *tiene que ser siempre código HTML válido*. Ese código HTML será recibido por tu navegador, interpretado y mostrado.

Observa el uso de *echo* para producir una salida HTML desde este pequeño script PHP:

```html
<body>
 <?php 
     echo "Soy un script de PHP y estoy generando 
               código HTML. Para demostrarlo
               voy a escribir <strong>esto en negrita</strong>"
  ?>
</body>
```

Si guardas este archivo en tu servidor web y lo cargas desde un navegador web (escribiendo la dirección https://tu-servidor/nombre-del-archivo.php), encontrarás que el navegador web recibe el siguiente código como resultado:

```html
<body>
     Soy un script de PHP y estoy generando código HTML.
     Para demostrarlo voy a escribir <strong>esto en negrita</strong>
</body>
```

Es decir, han desaparecido las etiquetas de PHP, así como el *echo*, y lo que recibe el navegador es código HTML limpio e impoluto. De hecho, el navegador no sabe si ese código HTML lo ha escrito una persona o lo ha generado un programa en PHP, como es el caso.

Y ese será tu objetivo: escribir programas capaces de generar código HTML que el navegador pueda recibir e interpretar.

### 2.3.10. Paso de parámetros por la URL

Las aplicaciones web pueden recibir parámetros a través de la propia URL de invocación del servidor.

Imagina que tenemos este link en un documento HTML:

```html
<a href="pagina.php?variable1=valor1&variable2=valor2&etc…">
```

Al hacer clic en él, pediremos al servidor que ejecute el programa cuyo código fuente está en el archivo *pagina.php*, ¿verdad?

Pues bien, ese programa *pagina.php* tendrá a su disposición unas variables llamadas *"*variable1*, *variable2*, etc, que son las que han viajado hasta el servidor en la URL.

Para acceder a esas variables, PHP utiliza un array global llamado **$_GET**, que se indexa con el nombre de las variables. Así:

```php
<?php
echo "La variable 2 vale:".$_GET['variable2']."<br>";
?>
```

Observa el uso del carácter punto (.) para concatenar strings en la salida de *echo*. Esto, en Java y muchos otros lenguajes, se haría con el carácter más (+). PHP es un poquito especial en este detalle.

### 2.3.11. Entrada de datos a través de formulario

Como PHP se ejecuta dentro de HTML, sólo puede recibir datos del usuario de la aplicación a través del navegador web.

Y sólo hay una forma de introducir datos en una página web: *a través de un formulario*.

Veámoslo con un ejemplo. Supongamos que hemos definido en HTML este sencillo formulario:

```html
<body>
<form method="post" action="destino.php">
Nombre<br/>
<input type="text" name="nombre"><br/>
Apellidos<br>
<input type="text" name="apellidos"><br/>
<input type="submit">
</form>
</body>
```

Al pulsar el botón "Enviar", se cargará el script *destino.php* en el servidor.

Ese script recibirá dos variables HTML llamadas *nombre* y *apellido*, con el valor que el usuario haya introducido en el formulario.

Para acceder a las variables HTML, se usa el array del sistema **$_POST**, indexándolo con el nombre de la variable:

```php
<?php 
     echo "La variable nombre vale".$_POST['nombre']."<br>" 
?>
```

Observa que *$_POST* es una variable semejante a *$_GET*. Puedes utilizar una u otra según el valor del atributo *method* de tu formulario HTML.

La variable **$_REQUEST** sirve tanto para POST como para GET. **Por eso será la que nosotros usaremos preferentemente en nuestros programas**.

### 2.3.12. Validación y saneamiento de formularios

Los datos que llegan desde un formulario son una fuente inagotable de quebraderos de cabeza. Para empezar, casi todos los ataques a las aplicaciones web provienen de intentos de los atacantes de usar los formularios como puerta de entrada al servidor. Y no hay que menospreciar el caos que puede provocar en una aplicación un usuario bienintencionado pero torpe que envía al servidor cosas totalmente imprevistas a través de un formulario.

Por lo tanto, todo lo que los usuarios de la aplicación escriban en un formulario debe filtrarse:

1. En el cliente, usando los atributos HTML5 necesarios y, si hace falta, recurriendo a Javascript.
2. En el servidor, mediante PHP o el lenguaje de servidor que estemos usando.

Ese filtro puede ser algo muy simple, como eliminar todos los caracteres no alfabéticos que provengan del formulario, o algo más complejo, como comprobar que el usuario ha escrito una dirección de email bien formada.

Ese proceso de filtrado se denomina **validación y saneamiento**.

Para ayudarnos en esta validación, PHP proporciona la función ***filter_var()***, que limpia diferentes conjuntos de caracteres sospechosos de cualquier dato que provenga del formulario. Esta función recibe como parámetro un string y permite tanto sanearlo como validarlo.

Por ejemplo, supongamos que tenemos un sencillo formulario con dos campos, *nombre* y *email*:

```html
<form action='procesa_formulario.php'>
    <input type='text' name='nombre'>
    <input type='text' name='email'>
    <button type='submit'>Enviar</button>
</form>
```

El script *procesa_formulario.php* recibirá los datos enviados por este formulario (nombre y email) en las variables *$_REQUEST["nombre"]* y *$_REQUEST["email"]*. Pues bien, si queremos sanear (limpiar) cualquier carácter sospechoso que pueda venir en esas variables, podemos hacerlo así:

```php
if (!isset($_REQUEST["nombre"])) {
    echo "Error: el campo nombre es obligatorio";
}
if (!isset($_REQUEST["email"])) {
    echo "Error: el campo email es obligatorio";
}
$nombre = filter_var($_REQUEST["nombre"], FILTER_SANITIZE_STRING);
$email = filter_var($_REQUEST["email"], FILTER_SANITIZE_EMAIL);
```

Tras la ejecución de este código nos habremos asegurado de que el usuario ha rellenado los dos campos y que esos campos no contienen ningún carácter sospechoso de ataque.

*filter_var()* admite otros valores como segundo parámetro. Son estos:

* **FILTER_SANITIZE_STRING**: elimina cualquier etiqueta HTML que encuentre en el string.
* **FILTER_SANITIZE_NUMBER_INT**: elimina cualquier carácter que no sea numérico (solo respeta los caracteres "+" y "-")
* **FILTER_SANITIZE_URL**: elimina cualquier carácter que no forme parte de una URL. El decir, solo deja las letras, los números y algunos caracteres especiales como _, : o ?
* **FILTER_SANITIZE_EMAIL**: elimina cualquier carácter que no forme parte de una dirección de email típica.

Si solo queremos validar un string procedente de un formulario, podemos cambiar los valores anteriores por FILTER_VALIDATE_STRING, FILTER_VALIDATE_NUMBER_INT, etc. Es decir, cambiaremos la palabra SANITIZE por VALIDATE. De ese modo, la función *filter_var()* no cambiará el string, sino que comprobará si pasa el filtro o no y nos devolverá *true* o *false*.

Existen otros filtros más complejos que puedes consultar en la referencia oficial del lenguaje.

Y, por supuesto, para construir validaciones más específicas, siempre puede programarlas por tu cuenta y riesgo, usando las funciones de procesamiento de strings que te ofrece PHP y currándotelo un poco.

### 2.3.13. Namespaces

Cuando las aplicaciones se hacen muy complejas pueden llegar a usar muchísimas clases (tanto nuestras como de librerías) y antes o después nos encontramos con problemas de redefinición. Es decir: dos clases, dos métodos o dos funciones que se llaman igual pero que pertenecen a librerías diferentes.

Los **namespaces** o **espacios con nombre** permiten organizar clases mediante nombres descriptivos, igual que los archivos se organizan en carpetas. ¿Verdad que puedes tener dos archivos que se llamen igual en dos lugares distintos de tu disco duro? Pues eso mismo.

Por ejemplo, podemos tener una clase llamada *Planta* para manejar las existencias de plantas vegetales de un centro comercial, y una clase diferente llamada también *Planta* que se refiera a los diferentes pisos del centro comercial. Cada clase estaría dentro de un *namespace* diferente, y así no se confundirían.

Para asignar una clase (o lo que sea) a un espacio con nombres, basta con indicarlo al principio del archivo que contiene esa clase, así:

```php
namespace vegetales;
```

Cualquier clase o función que se declare en este archivo pertenecerá al *namespace* "vegetales".

Para mantener un **código limpio y bien organizado**, lo habitual es escribir una sola clase en cada archivo, y colocar esos archivos en subcarpetas que tengan el mismo nombre que el *namespace*. De hecho, los *namespaces* de los sistemas complejos suelen incluir una jerarquía de carpetas que se indica así:

```php
namespace Persona\Empleado;
```

El archivo que comience de ese modo debería contener el código fuente de una clase llamada también *Empleado*, y el propio archivo debería llamarse *empleado.php* y localizarse en una subcarpeta llamada *persona/empleado*.

¿Y cómo se usa una clase localizada en un *namespace*? Muy sencillo: indicaremos el *namespace* que queremos utilizar mediante la instrucción ***use***:

```php
include_once("Persona/Empleado/empleado.php");   // Esto incluye el código fuente de la clase Empleado
use Persona/Empleado/Empleado;                   // Esto indica el namespace que queremos utilizar
$emp = new Empleado();                           // ¡Y ya tenemos disponible la clase Empleado!
```

### 2.3.14. Extensiones de PHP y referencia del lenguaje: cómo usar la biblioteca del lenguaje sin volverse loco

Para terminar con esta introducción a PHP, no podemos dejar de hablar de las **bibliotecas de clases y funciones** que vienen con cualquier distribución del lenguaje.

PHP dispone, literalmente, de miles de funciones y métodos disponibles para usar con nuestros programas. Estas funciones y métodos resuelven casi cualquier problema común concebible.

Como la biblioteca de PHP es tan grande, los administradores del servidor deben decidir qué funciones y clases están disponibles activando o desactivando **extensiones de PHP**, que es una forma rebuscada de referirse a las bibliotecas del lenguaje. Cuando un servidor tiene activada una determinada extensión de PHP, todas sus funciones y métodos están disponibles para nuestros programas.

Es imposible conocer toda esa vasta colección de funciones, clases y métodos. Para eso está la referencia oficial del lenguaje, que puedes encontrar en [https://www.php.net/manual](https://www.php.net/manual)

Por ejemplo, existen muchas funciones para manipular strings. Imagina que un día necesitas convertir todos los caracteres de un string a mayúsculas. Parece razonable suponer que, si las bibliotecas de PHP son tan grandes, exitirá una función que pueda hacer eso por nosotros. ¿Cómo la localizamos?

Mi consejo es que acudas siempre a [https://www.php.net/manual](https://www.php.net/manual) y allí utilices el buscador. Por ejemplo, teclea en la caja de búsqueda la palabra "strings". En la página de resultados obtendrás una lista con todas las funciones relativas a strings. La función que estamos buscando debe incluir la palabra "upper". Una rápida búsqueda por la página de resultados te conducirá a la función *strtoupper()*, que es justo la que estábamos buscando.

Si accedes a la página de *strtoupper()* encontrarás una completa descripción de la función y, lo que es más importante, algunos ejemplos de código que puedes copiar, pegar y adaptar a tu caso concreto.

Si, por alguna razón, decides buscar información sobre las biblioteca de PHP fuera de la web oficial, asegúrate que el sitio es de confianza y que la información que ofrece está actualizada: hay muchos sitios web que proporcionan soluciones obsoletas, inseguras o directamente erróneas.