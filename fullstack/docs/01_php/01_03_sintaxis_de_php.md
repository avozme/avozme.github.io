---
layout: page
title: 1.3 Sintaxis de PHP
permalink: /php/sintaxis-de-php.html
nav_order: 3
has_children: false
parent: 1 Programación web con PHP
grand_parent: Desarrollo web full stack
---

## 1.3. La sintaxis de PHP
{: .no_toc }

- TOC
{:toc}

### 1.3.1. Cómo incrustar PHP dentro de HTML

El código PHP se escribe incrustado dentro de un documento de texto mediante estas etiquetas:

```html
<?php .... ?>
```

**Este archivo debe tener *SIEMPRE* extensión .php, *NO* .html**

Cuando el servidor web encuentre un archivo con extensión .html, lo enviará al cliente sin mirar ni siquiera lo que hay en su interior.

En cambio, cuando el servidor web encuentre un archivo con extensión .php, lo abrirá y buscará las etiquetas <?php ... ?>, y ejecutará el código que haya dentro antes de enviar el resultado al cliente. El resto del archivo, es decir, lo que esté fuera de las etiquetas de PHP, se enviará al cliente sin modificar.

### 1.3.2. Comentarios

Los comentarios de PHP se pueden escribir de varias formas:

```php
// Comentario de una línea
#  Comentario de una línea
/* Comentario de una o varias líneas */
```

### 1.3.3. Variables y constantes

Las **variables** de una función/clase/método PHP son siempre **locales**, es decir, sólo están disponibles en esa función/clase/método, salvo que se indique otra cosa.

Si se definen variables fuera de una función, serán **globales** a todo el fichero actual, pero no pueden usarse en el código ubicado en otros ficheros. Existen maneras de lograr que una variable sea global a todo el código, pero, vamos... ¿en serio quieres hacer eso?

(Nota anticipatoria: hay ciertas situaciones en las que una aplicación web *necesita* variables globales, pero ya lo veremos en su momento. Por ahora, solo recuerda que usar variables globales es una pésima práctica de programación).

El **identificador** de variable siempre debe empezar por $. Esta es una peculiaridad de PHP que al principio descoloca un poco.

En PHP moderno, **el tipado fuerte es la norma**. Aunque históricamente PHP era muy permisivo, hoy en día se recomienda activar el modo de tipado estricto al principio de cada archivo:

```php
declare(strict_types=1);
```

Esto obliga a que los tipos coincidan exactamente, evitando errores difíciles de encontrar. Al inicializar variables en el código general, PHP deduce el tipo, pero en clases y funciones (como veremos más adelante) **siempre indicaremos el tipo explícitamente**.

Ejemplos:

```php
declare(strict_types=1);

$a = 4;                  // int
$media = 52.75;          // float
$texto = "Hoy es lunes"; // string
$esValido = true;        // bool
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

**El tipado de PHP es históricamente débil**, lo que permitía mezclar tipos alegremente. Sin embargo, **esto ya no se permite en el desarrollo profesional**. En modo estricto, mezclar tipos provocará un error inmediato, lo cual es preferible a tener un comportamiento imprevisible. Siempre debes convertir los tipos manualmente si es necesario. Por ejemplo:

```php
declare(strict_types=1);

$a = 3;                // int
$b = "10";             // string
$c = $a + (int)$b;     // Convertimos explícitamente a entero antes de sumar
```

Los **tipos de datos** predefinidos en PHP son:

* integer (entero)
* double (real)
* bool (booleano)
* string (cadena)
* array (pues eso)

En cuanto a las **constantes**, se crean con la función **define()**:

```php
declare(strict_types=1);

define("VERSION_APP", "1.0.0");
echo VERSION_APP;    // Muestra: 1.0.0. ¡Fíjate en que no lleva el símbolo $!
```

Las constantes, por convenio, suelen nombrarse en MAYÚSCULAS. El propio PHP tiene muchas constantes predefinidas (todas en mayúsculas) de ámbito global, como PHP_VERSION o PHP_OS. 

Algunas de estas constantes predefinidas empiezan y terminan por un doble subrayado, como \_\_LINE\_\_ o \_\_FILE\_\_. Estas constantes se llaman **constantes mágicas** y nos van a resultar muy útiles más adelante. 


### 1.3.4. Operadores

Los operadores en PHP son iguales que los de Java, que, a su vez, los heredó de C/C++:

* Asignación: $a = 3;
* Comparación:  ==, <=, >=, !=, <=>, etc.
* Operadores aritméticos: +, -, *, /, %...
* Operadores lógicos: &&, \|\|, !
* Operadores de asignación combinados: +=, -=, ++, --, *=, /=, etc

Existen operadores más esotéricos, como el operador ternario o los operadores a nivel de bit, que no usaremos demasiado. Sin embargo, PHP cuenta con algunos operadores curiosos que a lo mejor no conoces y que te pueden ahorrar mucho trabajo. Te los cuento brevemente:

**Operador de coalescencia nulo**. Con ese nombre tan rebuscado se conoce al operador ?? (doble interrogante). Simplemente, asigna a una variable valor u otro dependiendo de si está definida o no:

```php
declare(strict_types=1);

$user = $nombreUsuario ?? "invitado";
```

La variable $user del ejemplo anterior tomará el valor $nombreUsuario si y solo si esa variable, $nombreUsuario, existe y tiene un valor asignado. En caso contrario, tomará el valor "sin-nombre".

**Operador nave espacial**. Así se conoce el operador <==>. ¡Otro bonito chiste de informáticos! Se usa para comparar dos expresiones y decidir cuál es la menor. Devuelve -1 (si la primera expresión es menor que la segunda), 0 (si son iguales) o 1 (si la primera expresión es mayor que la segunda):

```php
declare(strict_types=1);

$resultado = $var1 <=> $var2;
echo $resultado;   // Mostrará -1, 0 o 1
```

### 1.3.5. Arrays

Los arrays en PHP son colecciones de variables del mismo o de distinto tipo identificadas por un índice. Se parecen más a los ArrayList de Java que a los arrays clásicos propiamente dichos.

```php
declare(strict_types=1);

$a = []; 
$a[1] = "lunes";
$a[2] = 1;        // Un array puede contener tipos mixtos, pero se recomienda homogeneidad
```

El índice no tiene por qué ser un número entero: puede ser un String (array asociativo):

```php
declare(strict_types=1);

$paises = [
    "ESP" => "España",
    "FRA" => "Francia",
    "POR" => "Portugal"
];
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

### 1.3.6. Estructuras de control

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
declare(strict_types=1);

$paises = [
    "España" => "ESP",
    "Francia" => "FRA",
    "Portugal" => "POR"
];

foreach ($paises as $nombre => $codigo) {
    echo "Nombre del país: $nombre - Código: $codigo<br>";
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

### 1.3.7. Funciones y procedimientos

Los subprogramas se escriben en PHP con la palabra *function*. En el desarrollo moderno, **siempre definiremos el tipo de los argumentos y del valor de retorno**.

* **Funciones**: Devuelven un valor con *return*.
* **Procedimientos**: Realizan una acción sin devolver valor (su tipo de retorno es `void`).

Ejemplo de una función moderna con tipado estricto:

```php
declare(strict_types=1);

function calcular_iva(float $base, float $porcentaje): float
{
   return $base * ($porcentaje / 100);
}

// Invocación segura
$precio = 100.0;
$iva = calcular_iva($precio, 21.0);
```

#### Argumentos con valor predefinido

PHP permite asignar valores por defecto, lo que hace que los parámetros sean opcionales:

```php
declare(strict_types=1);

function calcular_iva(float $base, float $porcentaje = 21.0): float {
    return $base * ($porcentaje / 100);
}

$a = calcular_iva(1000.0, 4.0);  // Usa 4%
$b = calcular_iva(1000.0);       // Usa el 21% por defecto
```

#### Gestión moderna de archivos: Autoloading y Composer

Históricamente, PHP usaba `include` y `require` para cargar archivos manualmente. **En el desarrollo profesional actual, esto se considera una mala práctica** y ha sido sustituido por el **Autoloading** (Carga automática) y gestores como **Composer**.

*   **include / require**: (Legado) Cargan manualmente un script. Si usas `require` y el archivo no existe, la aplicación se detiene (preferible a `include` que solo da un aviso).
*   **Autoloading (Estándar PSR-4)**: Es el sistema que usan frameworks como Laravel. Consiste en una configuración que le dice a PHP: "si intento usar una clase que no conoces, búscala automáticamente en esta carpeta".

Gracias a esto, **ya no escribirás `include` en cada archivo**. Simplemente usarás la clase y PHP se encargará de encontrarla. Veremos cómo configurar esto en el apartado de MVC y Composer.


### 1.3.8. Funciones anónimas, funciones lambda o *closures*

En muchos lenguajes modernos es habitual el uso de las **funciones anónimas, funciones lambda o *closures***. Aunque no son exactamente lo mismo, se parecen mucho y por ahora no entraremos en detalles sobre sus diferencias.

Se trata de funciones que no tienen nombre y que se usan directamente en una asignación a una variable o como parámetro de otra función.

Las funciones anónimas suelen usarse en estos contextos:

* **Cuando necesitas una función pequeña, con lógica breve**, que no va a ser usada en ningún otro lugar. En este caso es más limpio crear una función anónima en el sitio donde la necesitas, y no una función aparte con su declaración, devolución de resultados y toda la parafernalia.
* **Si necesitas pasar una función como argumento** a otra función.
* **Si necesitas una función que capture el valor de variables externas** a la propia función.
* **Si necesitas asociar una función a un callback, un evento o una promesa** (ya aprenderás que son estas cosas).

En cambio, cuando la lógica de una función sea compleja, o bien su código se necesite invocar desde muchos lugares de la aplicación, **es mejor que uses funciones tradicionales**, con su nombre, su declaración y su cuerpo bien definido.

Ten en cuenta que, si se usan mal, la funciones anónimas **pueden volver incomprensible el código**.

Aquí puedes ver un ejemplo sencillo de función anónima:


```php
declare(strict_types=1);

$numero = 8;
$doble = function(int $n): int {
    return $n * 2;
};

echo $doble($numero);   // Imprimirá 16
```

Hemos asignado la función anónima a una variable, llamada $doble. Por eso, al tratar de imprimir la variable, se invocará la función automáticamente.

En este es otro ejemplo, una función sin nombre se pasa como parámetro:

```php
declare(strict_types=1);

function procesar(array $datos, callable $callback): void {
    foreach ($datos as $d) {
        echo $callback($d) . PHP_EOL;
    }
}

procesar([1, 2, 3], fn(int $n): int => $n * $n);
```

La función *procesar()* recibe dos parámetros: el primero es un array con datos y, el segundo, es una función anónima que **le indica cómo procesar** esos datos. En este caso, se calculará el cuadrado de cada uno de los datos del array, pero podría ser cualquier otra cosa. 

Piensa en lo flexible que se vuelve la función *procesar()* al utilizarla de este modo: ¡ahora el mismo código puede servir para hacer casi cualquier cosa con el array!

### 1.3.9. Clases y objetos

A partir de la versión 5, PHP incluyó un completo soporte para orientación a objetos. Las clases, métodos y atributos se declaran de forma muy semejante a C++ y Java.

#### Declaración de clases

En este ejemplo puedes ver cómo se declara una clase en PHP. Observa cómo se indica la **herencia** (*extends*) y cómo se declara el **constructor**  (*__construct()*):

```php
declare(strict_types=1);

class MiClase extends ClaseMadre
{
    // PHP 7.4+ permite tipar las propiedades
    public string $var1 = 'pública';
    private string $var2;

    public function __construct(string $valor) {
        $this->var2 = $valor;
    }

    public function mostrarVar(): void {
        echo $this->var2;
    }

    private function resetVar(): void {
       $this->var2 = '';
    }
}
```

#### Constructor Property Promotion (PHP 8.0)

En las clases modernas, ya no es necesario declarar los atributos al principio y luego asignarles valor en el constructor. Podemos hacer ambas cosas a la vez en la propia firma del constructor:

```php
class Usuario {
    public function __construct(
        private string $nombre,
        private string $email,
        public readonly int $id
    ) {}
}
```

Al poner `public`, `private` o `protected` delante de un argumento del constructor, PHP crea automáticamente el atributo y le asigna el valor. Además, fíjate en la palabra **readonly**: indica que el valor solo puede asignarse una vez (normalmente en el constructor) y ya no podrá cambiarse, lo cual es fantástico para la integridad de los datos.

#### Notación flecha (->)

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
declare(strict_types=1);

class MiClase {
    public function __construct(
        protected string $var1
    ) {}
}

class MiSubclase extends MiClase {
    public function __construct(
        string $param1,
        private string $var2
    ) {
        parent::__construct($param1);
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
```php
declare(strict_types=1);

class MiClase {
    private string $var1 = "Atributo privado";

    public function getVar1(): string {
        return $this->var1;
    }

    public function setVar1(string $value): self {
        $this->var1 = $value;
        return $this; 
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

### 1.3.10. Salida de datos

PHP puede hacer salidas de datos como cualquier otro lenguaje de programación: puede enviar texto a una impresora o datos a un fichero. O puede dibujar ventanas y componentes en un entorno gráfico de usuario.

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

#### Abreviatura para echo

En PHP moderno, hay una abreviatura para *echo()* que se usa muchísimo:

```php
// Estas dos líneas son equivalentes:
<?php echo("Hola mundo"); ?>
<?= "Hola mundo" ?>
```

Esta abreviatura solo se usa para hacer *echo()*. Si tienes una lógica PHP más compleja, debes usar los tags <?php ... ?> habituales.

### 1.3.11. Paso de parámetros por la URL

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

### 1.3.12. Entrada de datos a través de formulario

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

### 1.3.13. Validación y saneamiento de formularios

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
declare(strict_types=1);

if (!isset($_REQUEST["nombre"])) {
    echo "Error: el campo nombre es obligatorio";
}
if (!isset($_REQUEST["email"])) {
    echo "Error: el campo email es obligatorio";
}

// Sanear entradas (FILTER_SANITIZE_STRING está obsoleto desde PHP 8.1)
$nombre = filter_var($_REQUEST["nombre"], FILTER_SANITIZE_SPECIAL_CHARS);
$email = filter_var($_REQUEST["email"], FILTER_SANITIZE_EMAIL);
```

Tras la ejecución de este código nos habremos asegurado de que el usuario ha rellenado los dos campos y que esos campos no contienen ningún carácter sospechoso de ataque.

*filter_var()* admite otros valores como segundo parámetro. Son estos:

* **FILTER_SANITIZE_SPECIAL_CHARS**: Escapa caracteres especiales (sustituye a FILTER_SANITIZE_STRING, que está obsoleto desde PHP 8.1).
* **FILTER_SANITIZE_NUMBER_INT**: elimina cualquier carácter que no sea numérico (solo respeta los caracteres "+" y "-")
* **FILTER_SANITIZE_URL**: elimina cualquier carácter que no forme parte de una URL. El decir, solo deja las letras, los números y algunos caracteres especiales como _, : o ?
* **FILTER_SANITIZE_EMAIL**: elimina cualquier carácter que no forme parte de una dirección de email típica.

Si solo queremos validar un string procedente de un formulario, podemos cambiar los valores anteriores por **FILTER_VALIDATE_INT**, **FILTER_VALIDATE_EMAIL**, etc. Es decir, cambiaremos la palabra SANITIZE por VALIDATE. De ese modo, la función *filter_var()* no cambiará el string, sino que comprobará si pasa el filtro o no y nos devolverá *true* o *false*.

Existen otros filtros más complejos que puedes consultar en la referencia oficial del lenguaje.

Y, por supuesto, para construir validaciones más específicas, siempre puede programarlas por tu cuenta y riesgo, usando las funciones de procesamiento de strings que te ofrece PHP y currándotelo un poco.

### 1.3.14. Namespaces

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
// Con Autoloading/Composer, ya no necesitas include_once()
use Persona\Empleado\Empleado;                   // Usamos la clase mediante su Namespace

$emp = new Empleado(nombre: "Juan");             // ¡Y ya tenemos disponible la clase!
```

### 1.3.15. Novedades de PHP 8+

PHP 8 y sus versiones sucesivas han introducido características que modernizan notablemente el lenguaje:

**Expresión match**
Es una mejora sobre el clásico `switch`. Es más segura (comparación estricta `===`) y devuelve un valor directamente:

```php
$resultado = match ($codigo) {
    1 => "Pendiente",
    2 => "Enviado",
    3 => "Entregado",
    default => "Desconocido",
};
```

**Promoción de propiedades en el constructor**
Permite declarar y asignar atributos directamente en el constructor, evitando el código repetitivo:

```php
// En lugar de declarar arriba y asignar abajo...
class Usuario {
    public function __construct(
        public string $nombre,
        public string $email,
        private int $edad
    ) {}
}
```

**Operador Nullsafe (?->)**
Evita errores al acceder a métodos de objetos que podrían ser `null`. Si el objeto es nulo, la cadena se detiene y devuelve `null` en lugar de lanzar un error:

```php
$ciudad = $usuario?->getDireccion()?->getCiudad();
```

**Enums**
Permiten definir tipos de datos con un conjunto limitado de valores posibles, mejorando la robustez del código:

```php
enum EstadoPedido: string {
    case Pendiente = 'P';
    case Enviado = 'E';
    case Entregado = 'D';
}
```

### 1.3.16. Extensiones de PHP y referencia del lenguaje: cómo usar la biblioteca del lenguaje sin volverse loco

Para terminar con esta introducción a PHP, no podemos dejar de hablar de las **bibliotecas de clases y funciones** que vienen con cualquier distribución del lenguaje.

PHP dispone, literalmente, de miles de funciones y métodos disponibles para usar con nuestros programas. Estas funciones y métodos resuelven casi cualquier problema común concebible.

Como la biblioteca de PHP es tan grande, los administradores del servidor deben decidir qué funciones y clases están disponibles activando o desactivando **extensiones de PHP**, que es una forma rebuscada de referirse a las bibliotecas del lenguaje. Cuando un servidor tiene activada una determinada extensión de PHP, todas sus funciones y métodos están disponibles para nuestros programas.

Es imposible conocer toda esa vasta colección de funciones, clases y métodos. Para eso está la referencia oficial del lenguaje, que puedes encontrar en [https://www.php.net/manual](https://www.php.net/manual)

Por ejemplo, existen muchas funciones para manipular strings. Imagina que un día necesitas convertir todos los caracteres de un string a mayúsculas. Parece razonable suponer que, si las bibliotecas de PHP son tan grandes, exitirá una función que pueda hacer eso por nosotros. ¿Cómo la localizamos?

Mi consejo es que acudas siempre a [https://www.php.net/manual](https://www.php.net/manual) y allí utilices el buscador. Por ejemplo, teclea en la caja de búsqueda la palabra "strings". En la página de resultados obtendrás una lista con todas las funciones relativas a strings. La función que estamos buscando debe incluir la palabra "upper". Una rápida búsqueda por la página de resultados te conducirá a la función *strtoupper()*, que es justo la que estábamos buscando.

Si accedes a la página de *strtoupper()* encontrarás una completa descripción de la función y, lo que es más importante, algunos ejemplos de código que puedes copiar, pegar y adaptar a tu caso concreto.

Si, por alguna razón, decides buscar información sobre las biblioteca de PHP fuera de la web oficial, asegúrate que el sitio es de confianza y que la información que ofrece está actualizada: hay muchos sitios web que proporcionan soluciones obsoletas, inseguras o directamente erróneas.

Por supuesto, también está la opción de recurrir a una IA generativa. Pero hazte un favor a ti y a tu cerebro de programador en formación: no te fíes al 100% de su respuesta y, sobre todo, **nunca, nunca jamás le pidas a una IA que resuelva tu problema**. Pídele mejor que *te explique* cómo podrías resolver el problema, y después trata de resolverlo por ti mismo. Si no, no habrás aprendido nada por el camino y, aunque tu programa funcione bien, habrás perdido el tiempo miserablemente.