---
layout: page
title: 4 Arquitectura MVC
permalink: /mvc/
nav_order: 4
has_children: false
parent: Desarrollo Web en Entorno Servidor
---
# 4. Arquitectura MVC
{: .no_toc }

- TOC
{:toc}

Cuando hablamos de arquitectura de una aplicación web nos referimos a la estructura básica que la sustenta, como los pilares de un edificio en construcción. Si quitas las paredes, las ventanas, las puertas, los azulejos de la cocina... todavía pueden distinguirse las formas fundamentales, ¿verdad?

En este tema, hablaremos mucho de la arquitectura más popular en aplicaciones web (llamada MVC; no te preocupes, pronto se convertirá en tu mejor amiga). Pero, antes, vamos a darle una vuelta al término "arquitectura", porque en aplicaciones web se usa con dos significados distintos que conviene que tengas claros para no hacerte un lío. 

## 4.1 Arquitecturas FÍSICAS multinivel (multitier)

Hablamos indistintamente de "arquitectura de una aplicación web" para referirnos a dos cosas distintas: la arquitectura física y la arquitectura lógica. Y ahí empiezan los líos.

Vamos a intentar desliarnos antes de apretar el nudo.

Una **arquitectura física de varios niveles** (multinivel o multitier, en inglés) consiste en un conjunto de ordenadores conectados a una red que ejecutan de forma conjunta una aplicación.

El ejemplo más sencillo es la arquitectura cliente-servidor, la más popular en aplicaciones web sencillas: una máquina cliente y una máquina servidor ejecutan alternativamente fragmentos del código, proporcionando al usuario final la sensación de una aplicación unificada. 

![Arquitectura en 2 niveles](/assets/images/04-arquitectura-2-niveles.png)

Por supuesto, nada impide que tengamos más de dos máquinas colaborando en red par ejecutar una aplicación web. Podemos tener, por ejemplo, un cliente, un servidor web y un servidor de bases de datos (estos dos últimos en dos máquinas físicas diferentes). Esto sería una arquitectura de 3 niveles físicos.

La arquitectura de N niveles tendría este aspecto:

![Arquitectura en N niveles](/assets/images/04-arquitectura-N-niveles.png)

## 4.2 Arquitecturas LÓGICAS multicapa (multilayer)

Ahora viene la vuelta de tuerca: la arquitectura de una aplicación también puede referirse a sus capas (layers) lógicas. Es decir, a las capas de software que nosotros, como desarrolladores, crearemos.

Dividir una aplicación en capas que colaboran entre sí por medio de interfaces bien definidos no es una idea nueva, ni pertenece exclusivamente al ámbito de la programación web. Pero la mayor parte de las aplicaciones web hacen uso de este mecanismo de abstracción.

La idea es dividir nuestra aplicación en capas de niveles de abstracción cada vez mayor. La capa superior (la más abstracta) es la que interacciona con el usuario: ahí se implementará nuestro interfaz de usuario, o lo que en aplicaciones web se llama *front-end*.

La capa inferior (la menos abstracta) es la que está en contacto con el hardware de la máquina. Bueno, con el hardware no: debajo de ella habrá otras capas que ya no pertenecen a nuestra aplicación y que se encargarán de ello: el sistema operativo, el servidor, el gestor de bases de datos, o lo que sea. Pero nuestra capa inferior será la que interactúe con esas otras capas que escapan a nuestros dominios y que están en contacto con la máquina.

Esta división en capas de abstracción, que puede parecer al neófito una complicación innecesaria, tiene un montón de ventajas y por eso se usa en cualquier aplicación un poco más complicada que "Hola, mundo".

### 4.2.1. Ventajas de las arquitecturas multicapa

Las arquitecturas multicapa permiten varias cosas que no pueden hacerse con los códigos monolíticos. Entre otras:

* Desarrollar en paralelo cada capa (mayor rapidez de desarrollo).
* Aplicaciones más robustas (gracias al encapsulamiento. ¿Te suena? ¡Programación orientada a objetos!).
* Matenimiento más sencillo.
* Más flexibilidad para añadir módulos.
* Más escalabilidad para aumentar rendimiento.
* Más seguridad, al poder aislar (relativamente) cada capa del resto.
* Mejor escalabilidad: es más fácil hacer crecer al sistema.
* Mejor rendimiento (aunque esto podría discutirse: puedes hacer un sistema multicapa con un rendimiento desastroso y un sistema monolítico que vaya como un tiro. Pero, en general, es más fácil mejorar el rendimiento trabajando en cada capa por separado).
* Es más fácil hacer el control de calidad, incluyendo la fase de pruebas.

### 4.2.2. Esquema Modelo-Vista-Controlador (MVC)

Y por fin llegamos a la palabreja: Modelo-Vista-Controlador o MVC. ¿Qué narices es esto?

Tan solo una arquitectura multicapa estandarizada. Una arquitectura de 3 capas, para ser exactos.

Este es el esquema de una arquitectura en 3 capas. Recuerda: cada capa ejecuta una parte de la solución, y entre ellas colaboran para formar la aplicación completa. La capa superior interactúa con el usuario; la capa inferior, con la máquina (donde dice "hardware", debería decir "cualquier cosa menos abstracta que nuestro programa"). Tienes permiso para imaginar cada capa como una clase con sus métodos y atributos.

![Arquitectura en 3 capas](/assets/images/04-arquitectura-3-capas.png)

Pues bien, si a esas tres les ponemos nombres exóticos como modelo, vista y controlador, y remeneamos un poco el esquema, ya lo tenemos: la arquitectura MVC.

![Arquitectura MVC](/assets/images/04-arquitectura-mvc.png)

Es decir, la arquitectura MVC solo es un caso particular de la arquitectura en 3 capas.

¿Y ya está? Bueno, no. Ahora tienes que aprender qué signfica *en realidad* esta palabrería.

Para que tengas una idea completa del asunto, ahora tienes que aprender qué parte de la aplicación se ejecuta en cada una de las capas. Pero es más simple de lo que parece. Y lo maravilloso es que el 99,99% de las aplicaciones web encajan como un guante en esta arquitectura. Es decir, apenas tendremos que hacer trabajo de diseño previo, porque, si es una aplicación web, ya sabemos qué clases tendremos que construir: los que nos indique la arquitectura MVC.

Antes de entrar en profundidad, un breve apunte: por supuesto, nada impide construir arquitecturas con más de 3 capas. De hecho, nosotros vamos a usar una variante del MVC en el que se añade una capa adicional por debajo del modelo, es decir, una arquitectura con 4 capas. Pero ya llegaremos a eso.

## 4.3. Patrones de software

Los **patrones de software** son soluciones comprobadas a problemas comunes en el desarrollo de software.

Para que un patrón pueda considerarse tal cosa, tiene que cumplir estas condiciones:

* Debe haber sido comprobado en otros sistemas.
* Debe ser fácilmente reutilizable.
* Debe ser aplicable a diferentes circunstancias.
* Debe estar bien documentado.

La documentación típica de un patrón de software incluye:

* Problema que resuelve.
* Contexto en el que es aplicable.
* Fuerzas, objetivos y restricciones.
* Solución que propone.
* Ejemplos.
* Contexto resultante.
* Exposición razonada.
* Otros patrones relacionados.

### 4.4.2. Tipos de patrones:

Dependiendo del grado de abstracción del patrón, existen patrones de diverso tipo:

* De arquitectura
* De diseño
* De creación de objetos
* De estructura de clases
* De comportamiento
* De dialectos
* De interacción o interfaz de usuario
* De análisis
* De dominio

Quizá no te sorprenda oír que el esquema MVC se considera un **patrón de software de arquitectura**.

### 4.4.3. Ejemplo de patrón: el patrón Singleton

Antes de centrarnos en MVC, vamos a ver, solo a modo de ejemplo, otro tipo de patrón: **el patrón Singleton**.

Algunos recursos en una aplicación son de tal naturaleza que sólo puede existir una instancia de ese tipo de recurso. Por ejemplo, la conexión a la base de datos a través de un manejador de base de datos. A veces interesa compartir un manejador de base de datos para que el resto de recursos no tengan que conectarse y desconectarse continuamente de la BD, y sólo debería existir una instancia de ese manejador.

El patrón Singleton cubre esta necesidad. Un objeto es “singleton” si la aplicación puede generar una y sólo una instancia del mismo.

Esta es una implementación reutilizable de ese patrón:

```php
<?php
require_once("DB.php");

class DatabaseConnection
{
  public static function get()
  {
    static $db = null;
    if ( $db == null )
      $db = new DatabaseConnection();
    return $db;
  }
  
  private $_handle = null;

  private function __construct()
  {
    $dsn = 'mysql://root:password@localhost/photos';
    $this->_handle =& DB::Connect( $dsn, array() );
  }
  
  public function handle()
  {
    return $this->_handle;
  }
}

print( "Handle = ".DatabaseConnection::get()->handle()."\n" );
print( "Handle = ".DatabaseConnection::get()->handle()."\n" );
?>
```

## 4.5. El patrón MVC en la práctica

Tras esta introducción, vamos a estudiar a fondo el patrón MVC. Y lo vamos a hacer por medio de un ejemplo, que es como mejor suelen comprenderse estas cosas. Una vez terminado y comprendido el ejemplo, daremos una definición forma del patrón MVC. 

Si lees el código fuente con atención, verás como, al acabar, entenderás perfectamente en qué consiste el MVC y podrás empezar a aplicarlo en tus proyectos.

El ejemplo con el que vamos a trabajar es este: supongamos que queremos programar una pequeña aplicación web que nos permita hacer publicaciones en una especie de blog simplificado. Esas publicaciones se guardan como registros en una tabla de una base de datos.

En el código de ejemplo sobre el que vamos a trabajar, nos vamos a centrar en obtener de la base de datos el listado de los artículos existentes para mostrarlo en una página HTML.

### 4.5.1. Código monolítico

Una primera aproximación a la solución, sin usar ningún patrón de arquitectura en absoluto, podría ser esta (échale un vistazo y asegúrate de entenderlo):

```php
<?
  // Conectamos con la base de datos
  $db = new mysqli('host', 'usuario', 'clave', 'dbname');
  // Lanzamos una consulta para recuperar los datos que necesitamos
  $resultado=$db->query('SELECT fecha, titulo FROM articulo');
?>
// Generamos una tabla con el resultado de la consulta
<h1>Listado de Artículos</h1>
<table>
     <tr> <th>Fecha</th> <th>Titulo</th> </tr>
<?php
  // Recorremos fila a fila el resultado de la consulta
  while ($fila = $resultado->fetch_array())  {
      echo "<tr>";
      echo "<td> ".$fila['fecha']." </td>";
      echo "<td> ".$fila['titulo']." </td>";
      echo "</tr>";
  }
  echo "</table>";
  // Cerramos la conexión con la BD
  $db->close();
?>
```

Esta solución se denomina **monolítica**, porque incluye todo el código necesario en el mismo bloque. Por supuesto, para un ejemplo tan simple como este, el código monolítico es más que suficiente, pero en un sistema más complejo pronto empieza a convertirse en un monstruo inmanejable.

### 4.5.2. Primera mejora: controlador + vista

Vamos a aproximarnos un poco a la solución MVC separando ese código monolítico en dos bloques (que guardaremos en archivos distintos):

* Un controlador.
* Una vista.

Primero, el **controlador**. Se encargará de recuperar los datos, pero *no de mostrarlos*. Generar el interfaz de usuario, es decir, el HTML, será la labor que le dejaremos a la vista. El controlador preparará esos datos y los empaquetará en un array para que estén disponibles en la vista. Y la vista la insertaremos en el controlador con un include().

```php
<?
  // Este es el controlador (esta aplicación solo realiza una acción)

  $db = new mysqli('localhost', 'usuario', 'clave', 'dbname');
  $resultado=$db->query('SELECT fecha, titulo FROM articulo');

  $articulos = array();
  while ($fila = $resultado->fetch_array())  {
      $articulos[] = $fila;
  }

  $db->close();

  include('vista.php');
?>
```

La **vista** que mostrará los datos del array contiene un código muy semejante al de la solución monolítica, solo que ahora estará ubicada en un archivo aparte, llamado vista.php, y hará un bucle sobre el array de resultados que le ha preparado el controlador: 

```php
<h1>Listado de Articulos</h1>
<table>
     <tr> <th>Fecha</th> <th>Titulo</th> </tr>
<?php foreach($articulos as $articulo): ?>
    <tr>
        <td><?php echo $articulo['fecha']?></td>
        <td><?php echo $articulo['titulo']?></td>
    </tr>
<?php endforeach;?>
</table>
```

### 4.5.3. Segunda mejora: modelo, vista y controlador

En esta segunda mejora, dividiremos el código en tres bloques (ubicados, de nuevo, en archivos diferentes):

* Un modelo (archivo model.php) --> Contendrá una clase con un método que se encargará de acceder a la base de datos y empaquetar el resultado de la consulta en un array.
* Una vista (archivo view.php) --> Se encargará de generar el HTML con el resultado de la consulta.
* Un controlador (archivo index.php) --> Se encargará de invocar al modelo y a la vista en el orden correcto.

Por lo tanto, el **controlador** se queda en algo tan sencillo como esto:

```php
include('model.php');	  // En este archivo estará el modelo
$articulos = Model::getAll();
require('view.php');		// En este archivo estará la vista
```

El **modelo** consta de una clase con un método (de momento) encargado de consultar todos los artículos y devolverlos empaquetados en un array:

```php
<?php
class Model {
  public function getAll()
  {
    $db = new mysqli('localhost', 'usuario', 'clave', 'dbname');
    $resultado=$db->query('SELECT fecha, titulo FROM articulo');

    $articulos = array();
    while ($fila = $resultado->fetch_array())  {
        $articulos[] = $fila;
    }

    $db->close();

    return $articulos;
  }
}
?>
```

Por último, la **vista** será exactamente igual que en la versión anterior: un recorrido por el array de artículos para mostrarlos en formato HTML:

```php
<h1>Listado de Articulos</h1>
<table>
     <tr> <th>Fecha</th> <th>Titulo</th> </tr>
<?php foreach($articulos as $articulo): ?>
    <tr>
        <td><?php echo $articulo['fecha']?></td>
        <td><?php echo $articulo['titulo']?></td>
    </tr>
<?php endforeach;?>
</table>
```

### 4.5.4. Tercera mejora: añadiendo capa de abstracción de datos

Como no sabemos lo que es el miedo, vamos a complicar nuestro patrón modelo-vista-controlador con una cuarta capa: la capa de abstracción de datos.

La idea de esta capa adicional es proporcionar un mecanismo de abstracción respecto del gestor de base de datos concreto que estemos utilizando.

Si te fijas en el **modelo** de la solución anterior, verás que estamos usando una clase (mysqli) y unos métodos que solo funcionan con MySQL o MariaDB. Si quiséramos cambiar el gestor de base de datos, tendríamos que revisar todos nuestros modelos.

Una forma de independizar la aplicación del gestor de base de datos es programar una **capa de abstracción** que contenga dos o tres métodos genéricos (como consultar() para lanzar SELECT o manipular() para lanzar INSERT, UPDATE o DELETE).

De ese modo, cuando queramos hacer una consulta desde el modelo, no lo haremos con los métodos de MySQL o de otro gestor de bases de datos,  que traduzcan una petición genérica (como consultar("SELECT * FROM users")) a una petición concreta para un gestor de base de datos (new mysqli(...), $db->query(), etc).

Por lo tanto, en esta tercera mejor vamos a dividir el código en cuatro bloques:

* Un controlador (archivo index.php).
* Una vista (archivo view.php).
* Un modelo en dos capas
   * Capa de abstracción de datos (dbabstract.php)
   * Capa de acceso a datos (el modelo propiamente dicho) (model.php).

El código de la **capa de abstracción** sería algo así:

```php
class DbAbstract {
  private $db;
  function crearConexion($servidor, $usuario, $clave, $dbname) {
    $db = new mysqli($servidor, $usuario, $clave, $dbname);
  }

  function cerrarConexion() {
    if ($db) $db->close();
  }

  function consulta($consulta) {
    $res = $db→query($consulta);
    $resArray = array();
    if ($res) {
      $resArray = $res->fetch_all();
    }
    return $resArray;
  }
  ...etc... (añadimos cualquier función que acceda directamente a MySQL)
}
```

El código del **modelo** va a hacer uso de la capa de abstracción:

```php
include "DbAbstract.php";

class Model {

  public function getAllArticulos() {
    $db = new dbAbstract();
    $db->crearConexion('localhost', 'usuario', 'clave', 'dbName');
    $articulos = $db->consulta('SELECT fecha, titulo FROM articulo');
    $db->cerrarConexion();
    return $articulos;
  }

}
```

El **controlador** y la **vista** son exactamente los mismos que en la solución anterior.

### 4.5.5. Cuarta (y última) mejora: transformación en clases y objetos reutilizables

Para terminar, vamos a dejar el código bien organizado y a mostrarlo completo.

Lo que haremos en esta última etapa es empaquetarlo todo en clases reutilizables. Observa que sigue siendo el mismo código fuente, solo que empaquetado en clases y métodos. Lo único que queda fuera de una clase es la instanciación del objeto controlador.

Fíjate bien en cómo hemos convertido las vistas en una clase con un método show() que nos servirá para mostrar cualquier vista y reutilizar el mismo header y el mismo foorter. Cada vista se programará en un archivo independiente que deberemos organizar el directorios y subdirectorios.

Otra cosa que quiero que observes con atención es el controlador, porque lo hemos dejado preparado para poder añadir nuevas funciones al programa con posterioridad. Este controlador te servirá de esqueleto para montar tus propias aplicaciones MVC.

**index.php**

```php
$controlador = new Controller();
$controlador->main();
```

**controller.php**

```php
include ("View.php");
include ("Model.php");

class Controller {

   public function main() {
      $estado = (isset($_REQUEST['do']) ? $_REQUEST['do'] ; "formLogin");

      switch ($estado) {
         case "formLogin": ...
         case "checkLogin": ...
         case "showAllArticles":
             $articulos = Articulos::getAllArticulos();
             View::show("showAllArticles");
             break; 
         case "...etc...": ...
      }
    }
}
```

**view.php**

```php
<?php

class View
{
   public function show($nombreVista) {
      include("header.php");
      include("$nombreVista.php");
      include("footer.php");
   }
}

?>
```

**showAllArticles.php**

```html
   <h1>Listado de Articulos</h1>
   <table>
        <tr> <th>Fecha</th> <th>Titulo</th> </tr>
   <?php foreach($articulos as $articulo): ?>
       <tr>
           <td><?php echo $articulo['fecha']?></td>
           <td><?php echo $articulo['titulo']?></td>
       </tr>
   <?php endforeach;?>
   </table>
   <?php
    }
}
```

**model.php**

```php
include "dbabstract.php";

class Model {

  public function getAll() {
    $db = new dbAbstract();
    $db->crearConexion('localhost', 'usuario', 'clave','dbName');
    $articulos = $db->cosulta('SELECT fecha, titulo FROM articulo');
    $db->cerrarConexion();
    return $articulos;
  }
}
```

**dbabstract.php**

```php
class DbAbstract {
  private $db;
  function crearConexion($servidor, $usuario, $clave, $dbname) {
    $db = new mysqli($servidor, $usuario, $clave, $dbname);
  }

  function cerrarConexion() {
    if ($db) $db->close();
  }

  function consulta($consulta) {
    $res = $db→query($consulta);
    $resArray = array();
    if ($res) {
      $resArray = $res->fetch_all();
    }
    return $resArray;
  }
  ...etc... (añadimos cualquier función que acceda directamente a MySQL)
}
```

## 4.6. El patrón MVC en la teoría

Ahora que hemos aprendido a manejarnos con el patrón MVC por medio de un ejemplo, estamos en condiciones de definirlo de manera más teórica y, oh maravilla, incluso entender esa definición.

El patrón MVC divide la aplicación en tres capas:

* **Los modelos**, donde se programa la *lógica de negocio*. De esa forma tan rimbombante se refiere la literatura técnica al acceso a los datos con los filtros, algoritmos y restricciones que el sistema imponga. 
   
   En la práctica, esto significa que en los modelos debemos colocar todo el código de acceso a la base de datos o a cualquier otro recurso del servidor (como las variables de sesión, por ejemplo). Los modelos deben empaquetarlos en objetos estándar de PHP (como arrays) y devolverlos al controlador.

   Lo más práctico es crear un modelo para cada tabla maestra de la base de datos.

   Los frameworks automatizan los métodos más típicos de cada modelo, como insertar un registro, borrar, actualizar, consultar uno o consultar todos.

* **Las vistas**, donde se programan todas las salidas HTML que el usuario final va a ver y con las que va a interactuar.

   El código Javascript y CSS, por lo tanto, forma parte de las vistas.

   En las vistas estará el grueso del código de cualquier aplicación. Los frameworks más avanzados incluyen sistemas de plantillas y lenguajes adicionales para simplificar este proceso, pero si programamos en PHP clásico, tendremos que construir las vistas manualmente.

* **Los controladores**, donde se captura cada petición del usuario y se dirige el flujo de ejecución, invocando a los modelos y a las vistas en el orden adecuado.

   En una aplicación pequeña, bastará con tener un controlador para todo. Cuando la aplicación crece, suele hacerse un controlador por cada modelo, es decir, un controlador por cada tabla maestra.

   Nuestros controladores van a estar compuestos por un switch muy grande con un case para cada funcionalidad de la aplicación. Ese switch estará dirigido por una variable de control. En los frameworks, este switch se transforma en una colección de métodos, lo cual proporciona un código mucho más elegante, pero que funcionalmente hace lo mismo.


