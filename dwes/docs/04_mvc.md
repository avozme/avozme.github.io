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

En ingeniería del software, como en cualquier otra ingeniería, existen una serie de soluciones estandarizadas que se ajustan sorprendentemente bien a una enorme variedad de situaciones diferentes. Estas soluciones se denominan **patrones de software**, y vamos a empezar este tema hablando de ellas.

Después nos centraremos en los **patrones de arquitectura**, y sobre todo en uno en concreto denominado **MVC o Modelo-Vista-Controlador** que tiene una enorme importancia en el ámbito de las aplicaciones web.

Pero, antes de meternos a saco con el patrón MVC, tendremos que darle un par de vueltas al término "arquitectura", porque, en el ámbito de las aplicaciones web, se usa con dos significados distintos que conviene que tengas claros para no hacerte un lío.

Terminaremos el tema mostrando, como siempre, un ejemplo de código bastante basado en la arquitectura MVC, de modo que puedas usarlo para comprender mejor los conceptos teóricos y como base para tus propios proyectos.

## 4.1. Patrones de software

Antes de entrar en la parte más práctica de todo este asunto, es decir, antes de que veamos los patrones de arquitectura y los apliquemos en un ejemplo concreto de aplicación web, tienes que dejarme que te hable de los **patrones de software**.

Los patrones de software son *soluciones comprobadas a problemas comunes en el desarrollo de software*. La arquitectura MVC, de hecho, es un patrón, porque se ha probado infinidad de veces y se adapta a la perfección a multitud de problemas diferentes.

Para que un patrón pueda considerarse tal cosa, tiene que cumplir estas condiciones:

* Debe haber sido comprobado en otros sistemas.
* Debe ser fácilmente reutilizable.
* Debe ser aplicable a diferentes circunstancias.
* Debe estar bien documentado.

### 4.1.1. Tipos de patrones

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

### 4.1.2. Ejemplo de patrón: el patrón Singleton

Antes de centrarnos en el patrón MVC, vamos a ver, solo a modo de ejemplo, otro tipo de patrón: **el patrón Singleton**, que está considerado un *patrón de diseño*.

Algunos recursos en una aplicación son de tal naturaleza que sólo puede existir una instancia de ese tipo de recurso. Por ejemplo, la conexión a la base de datos a través de un manejador de base de datos. A veces interesa compartir un manejador de base de datos para que el resto de recursos no tengan que conectarse y desconectarse continuamente de la BD, y sólo debería existir una instancia de ese manejador.

El patrón Singleton cubre esta necesidad. Un objeto es “singleton” si la aplicación puede generar una y sólo una instancia del mismo.

Esta es una implementación sencilla y reutilizable de ese patrón. Utiliza un constructor privado para evitar que se creen varias instancias del objeto y un método *static* para obtener la única instancia permitida. 

Ojo, que solo se trata de un ejemplo. De hecho, ni siquiera está completo, porque en PHP hay varias formas de construir un objeto sin pasar por el constructor. No te lo tomes como algo que tengas que aprenderte de memoria o algo así. Lo interesante de este ejemplo es que veas que existen muchos patrones que pueden (y, de hecho, deben) reutilizarse una y otra vez en el diseño de aplicaciones.

```php
class Singleton
{
   private static $instancia;  // Referencia a la única instancia de este objeto. Es private
                               // para que nadie pueda usarla desde fuera del objeto

   // Constructor privado. Nadie podrá crear objetos desde fuera de la clase.
   private function __construct()
   {
      $this->contador = 0;
   }

   // Este método comprueba si existe ya una instancia del objeto Singleton.
   // Si existe, la devuelve. Si no existe, la crea antes de devolverla.
   public static function getInstance()
   {
      if ( self::$instancia instanceof self)
      {
         self::$instancia = new self;
      }
      return self::$instancia;
   }
}
?>
```

Teniendo una clase como esa, el objeto Singleton puede usarse de este modo:

```php
// Las dos variables contendrán, en realidad, el mismo objeto Singleton
$single1 = Singleton::getInstance();
$single2 = Singleton::getInstance();
```

Por supuesto, a la clase Singleton podemos añadirle todos los métodos que necesitemos, como a cualquier clase, sin que pierda su condición de Singleton.

## 4.2. Arquitectura de una aplicación web

Ahora que tenemos claro qué es un patrón de software, vamos a centrarnos en los **patrones de arquitectura**.

Pero existe un problema cuando hablamos de "arquitectura de una aplicación" en el ámbito de las aplicaciones web.

El problema es este: usamos el término *"arquitectura de una aplicación"* para referirnos a dos cosas distintas: la *arquitectura física* y la *arquitectura lógica*.

Vamos a intentar explicar la diferencia.

### 4.2.1. Arquitecturas FÍSICAS multicapa (multitier)

Una **arquitectura física de varios niveles** (multinivel o *multitier*, en inglés) consiste en un conjunto de ordenadores conectados a una red que ejecutan de forma conjunta una aplicación.

El ejemplo más sencillo es la arquitectura cliente-servidor, la más popular en aplicaciones web sencillas: una máquina cliente y una máquina servidor ejecutan alternativamente fragmentos del código, proporcionando al usuario final la sensación de una aplicación unificada. 

![Arquitectura en 2 niveles](/docs/dwes/_site/assets/images/04-arquitectura-2-niveles.png)

Por supuesto, nada impide que tengamos más de dos máquinas colaborando en red para ejecutar una aplicación web. Podemos tener, por ejemplo, un cliente, un servidor web y un servidor de bases de datos (estos dos últimos en dos máquinas físicas diferentes). Esto sería una arquitectura de 3 niveles físicos.

Esta arquitectura se puede generalizar. Una con N niveles físicos tendría este aspecto:

![Arquitectura en N niveles](/docs/dwes/_site/assets/images/04-arquitectura-N-niveles.png)

La arquitectura física es algo que incumbe sobre todo a los administradores de sistemas, que son los encargados de montarla, configurarla y mantenerla. Para el programador, sin embargo, suele resultar transparente.

Por ejemplo, cuando nos conectamos a un servidor de bases de datos desde nuestra aplicación, poco importa que ese servidor esté en la misma máquina física o en otra máquina diferente: la forma de conectarse y operar con la base de datos es exactamente la misma.

Así que la arquitectura física, siendo importante, no lo es demasiado para nosotros y nosotras como desarrolladores.

En cambio, la arquitectura lógica es otra historia...

### 4.2.2. Arquitecturas LÓGICAS multicapa (multilayer)

Ahora viene la vuelta de tuerca: la arquitectura de una aplicación también puede referirse a sus capas (*layers* en inglés) lógicas. Es decir, a las capas de software que nosotros, los desarrolladores/as, creamos.

**Dividir una aplicación en capas que colaboran entre sí por medio de interfaces bien definidos** no es una idea nueva, ni pertenece exclusivamente al ámbito de la programación web. Pero la mayor parte de las aplicaciones web hacen uso de este mecanismo de abstracción.

La idea es fragmentar nuestra aplicación en capas de niveles de abstracción cada vez mayor. En un extremo, la **capa más abstracta** es la que interacciona con el **usuario**: ahí se implementará nuestro interfaz de usuario, o lo que en aplicaciones web se llama *front-end*.

En el otro extremo, la **capa menos abstracta** es la que está en contacto con el **hardware** de la máquina. Bueno, en el caso de una aplicación web, no hay contacto directo con el harware, sino con otras capas aún menos abstractas que están fuera de nuestra aplicación, como el sistema operativo, el servidor web o el gestor de bases de datos. Esas capas externas a nuestra aplicación son las que, realmente, interaccionan con el hardware en última instancia.

Esta división en capas de abstracción, que puede parecer una complicación innecesaria, tiene un montón de ventajas y por eso se usa en cualquier aplicación un poco más complicada que "Hola, mundo".

### 4.2.3. Ventajas de las arquitecturas multicapa

Las arquitecturas multicapa permiten varias cosas que no pueden hacerse con los códigos monolíticos. Entre otras:

* Desarrollar en paralelo cada capa (mayor rapidez de desarrollo).
* Aplicaciones más robustas gracias al encapsulamiento. ¿Te suena? ¡Programación orientada a objetos! Cada capa se implementa en una clase, y cada clase hace su trabajo sin importunar a las demás y sin preocuparse por cómo funcionan las otras internamente.
* El matenimiento es más sencillo.
* Más flexibilidad para añadir módulos.
* Más seguridad, al poder aislar (relativamente) cada capa del resto.
* Mejor escalabilidad: es más fácil hacer crecer al sistema.
* Mejor rendimiento (aunque esto podría discutirse: puedes hacer un sistema multicapa con un rendimiento desastroso y un sistema monolítico que vaya como un tiro. Pero, en general, es más fácil mejorar el rendimiento trabajando en cada capa por separado).
* Es más fácil hacer el control de calidad, incluyendo la fase de pruebas.

El único inconveniente reseñable de las arquitecturas multicapa es que pueden hacer que una aplicación muy simple se vuelva artificialmente más compleja de lo necesario. Pero eso solo sucede en aplicaciones muy, pero que muy simples. Para cualquier aplicación convencional, la arquitectura multicapa simplifica el diseño en lugar de complicarlo.

En resumen: todo son ventajas. Ya ves por qué todo el mundo hace aplicaciones web con arquitecturas multicapa.

## 4.3. La arquitectura Modelo-Vista-Controlador (MVC)

Y por fin llegamos a la palabreja: la arquitectura Modelo-Vista-Controlador o MVC.

Cuando hablamos de **arquitectura de una aplicación** nos referimos a la estructura básica que la sustenta, como los pilares de un edificio en construcción. Si quitas las paredes, las ventanas, las puertas, los azulejos de la cocina... todavía pueden distinguirse las formas fundamentales, ¿verdad?

Pues bien, el *patrón de arquitectura* más popular en aplicaciones web se llama **MVC o Modelo-Vista-Controlador** y muy pronto se va a convertir para ti en un viejo amigo. 

### 4.3.1. ¿Qué es el MVC?

El MVC es tan solo **una arquitectura multicapa estandarizada**. Una arquitectura de **3 capas**, para ser exactos.

Este es el esquema de una arquitectura en 3 capas. Recuerda lo que hemos visto antes: cada capa ejecuta una parte de la solución, y entre ellas colaboran para formar la aplicación completa. La capa superior interactúa con el usuario; la capa inferior, con la máquina (donde dice "hardware", debería decir "cualquier cosa menos abstracta que nuestro programa"). Tienes permiso para imaginar cada capa como una clase con sus métodos y atributos.

![Arquitectura en 3 capas](/docs/dwes/_site/assets/images/04-arquitectura-3-capas.png)

Pues bien, si a esas tres capas les ponemos nombres exóticos como *modelo*, *vista* y *controlador*, y tuneamos un poco el esquema, ya lo tenemos: **la arquitectura MVC**.

![Arquitectura MVC](/docs/dwes/_site/assets/images/04-arquitectura-mvc.png)

Es decir, **la arquitectura MVC solo es un caso particular de la arquitectura en 3 capas**.

¿Y ya está? Bueno, no. Ahora tienes que aprender qué significa *en realidad* esta palabrería.

Porque todo esto está muy bien como construcción teórica, pero ¿cómo te afecta a ti a la hora de programar? ¿Qué clases tienes que crear? ¿Qué parte del código hay que poner en cada clase?

En la práctica, es más simple de lo que parece. Lo vas a ver enseguida. Y lo maravilloso es que el 99,99% de las aplicaciones web encajan como un guante en esta arquitectura. Es decir, apenas tendremos que hacer trabajo de diseño previo, porque, si es una aplicación web, ya sabemos qué clases tendremos que construir: los que nos indique la arquitectura MVC.

Antes de pasar a la parte práctica de todo esto, permíteme un breve apunte: por supuesto, nada impide construir arquitecturas con más de 3 capas. De hecho, nosotros vamos a usar una variante del MVC en el que se añade una capa adicional por debajo del modelo, es decir, una arquitectura con 4 capas. Pero ya llegaremos a eso.

### 4.3.2. MVC en la práctica: una implementación incremental

Tras esta introducción al MVC, vamos a estudiar a fondo este patrón. Y lo vamos a hacer por medio de un ejemplo, que es como mejor suelen comprenderse estas cosas. Una vez terminado y comprendido el ejemplo, daremos una definición más teórica.

Es decir, que lo vamos hacer al revés de lo habitual: primero la práctica y luego la teoría. Según mi experiencia, la gente suele comprenderlo mejor en ese orden.

Pero, para que esto funcione, tienes que **leer el código fuente con atención**. Es un código sencillo y bien comentado, y que se va complicando muy poco a poco, en pasos incrementales, desde un código clásico monolítico hasta una implementación completa de un MVC.

Si lo lees con la atención que te pido, verás como, **al acabar, entenderás perfectamente en qué consiste el MVC** y podrás empezar a aplicarlo en tus proyectos.

El ejemplo con el que vamos a trabajar es este: supongamos que queremos programar una pequeña aplicación web que nos permita hacer publicaciones en una especie de blog simplificado. Esas publicaciones se guardan como registros en una tabla de una base de datos.

En el código de ejemplo sobre el que vamos a trabajar, nos vamos a centrar en una funcionalidad concreta de este mini-blog: el listado de los artículos existentes en la base de datos.

#### Código monolítico

Una primera aproximación a la solución, **sin usar ningún patrón de arquitectura** en absoluto, podría ser esta (échale un vistazo y asegúrate de entenderlo):

```php
<?
  // Conectamos con la base de datos
  $db = new mysqli('mi-host', 'mi-usuario', 'mi-clave', 'mi-base-de-datos');
  // Lanzamos una consulta para recuperar los artículos que haya en la base de datos
  $res = $db->query('SELECT fecha, titulo FROM articulo');
?>
// Generamos una tabla HTML con el resultado de la consulta
<h1>Listado de Artículos</h1>
<table>
     <tr> <th>Fecha</th> <th>Titulo</th> </tr>
<?php
  // Recorremos fila a fila el resultado de la consulta
  while ($row = $res->fetch_array())  {
      echo "<tr>";
      echo "<td> ".$row['fecha']." </td>";
      echo "<td> ".$row['titulo']." </td>";
      echo "</tr>";
  }
  echo "</table>";
  // Cerramos la conexión con la BD
  $db->close();
?>
```

Esta solución se denomina **monolítica**, porque incluye todo el código necesario en el mismo bloque. 

Por supuesto, para un ejemplo tan simple como este, el código monolítico es más que suficiente, pero en un sistema más complejo pronto empieza a convertirse en un monstruo inmanejable.

#### Primera mejora: controlador + vista

Vamos a aproximarnos un poco a la solución MVC **separando ese código monolítico en dos bloques** (que guardaremos en archivos distintos):

* **Un controlador** (archivo *index.php*).
* **Una vista** (archivo *showAllArticles.php*).

Primero, el **controlador**. Se encargará de recuperar los datos, pero *no de mostrarlos*. Generar el interfaz de usuario, es decir, el HTML, será la labor que le dejaremos a la vista. El controlador preparará esos datos y los empaquetará en un array para que estén disponibles en la vista. Y la vista la insertaremos en el controlador con un *include()*.

```php
<?
  // Este es el controlador.
  // Como esta aplicación de ejemplo solo realiza una acción,
  // no usamos de momento la variable "action"

  // Conectamos a la BD y sacamos la lista de artículos
  $db = new mysqli('mi-host', 'mi-usuario', 'mi-clave', 'mi-base-de-datos');
  $res = $db->query('SELECT fecha, titulo FROM articulo');

  // Convertimos la lista de artículos, que es un cursor de MySQL, en un array estándar de PHP
  $articles = array();
  while ($row = $res->fetch_array())  {
      $articles[] = $row;
  }
  $db->close();

  // Incluimos el código de la vista, donde se usará el array de artículos
  // para generar la tabla HTML.
  include('showAllArticles.php');
?>
```

La **vista** que mostrará los datos del array contiene un código muy semejante al de la solución monolítica, solo que ahora estará ubicada en un archivo aparte (*showAllArticles.php*) y hará un bucle sobre el array de resultados que le ha preparado el controlador: 

```php
<h1>Listado de Articulos</h1>
<table>
     <tr> <th>Fecha</th> <th>Titulo</th> </tr>
     <?php 
     foreach($articles as $article) {
        echo "<tr>
           <td>".$article['fecha']."</td>
           <td>".$article['titulo']."</td>
        </tr>";
     }
     ?>
</table>
```

#### Segunda mejora: modelo, vista y controlador

En esta segunda mejora, **dividiremos el código en tres bloques** (ubicados, de nuevo, en archivos diferentes):

* **Un modelo** para los artíclos (archivo *articles.php*). Contendrá una clase con un método que se encargará de acceder a la base de datos y empaquetar el resultado de la consulta en un array.
* **Una vista** (archivo *showAllArticles.php*). Se encargará de generar el HTML con el resultado de la consulta.
* **Un controlador** (archivo *index.php*). Se encargará de invocar al modelo y a la vista en el orden correcto.

Por lo tanto, el **controlador** (*index.php*), al extraer de él todo lo que tenga que ver con la base de datos, se queda en algo tan sencillo como esto:

```php
include('articles.php');       // En este archivo estará el modelo
$articulos = Model::getAll();  // Este método del modelo nos devuelve la lista de artículos
include('showAllArticles.php');   // En este archivo estará la vista
```

El **modelo** (*articles.php*) consta de una clase con solo un método (de momento) encargado de consultar todos los artículos y devolverlos empaquetados en un array:

```php
<?php
class Articles {
  public function getAll()
  {
    $db = new mysqli('mi-host', 'mi-usuario', 'mi-clave', 'mi-base-de-datos');
    $res=$db->query('SELECT fecha, titulo FROM articulo');

    $articles = array();
    while ($row = $res->fetch_array())  {
        $articles[] = $row;
    }
    $db->close();
    return $articles;
  }
}
?>
```

Por último, la **vista** (*showAllArticles.php*) será exactamente igual que en la versión anterior: un recorrido por el array de artículos para mostrarlos en formato HTML:

```php
<h1>Listado de Articulos</h1>
<table>
     <tr> <th>Fecha</th> <th>Titulo</th> </tr>
     <?php 
     foreach($articles as $article) {
        echo "<tr>
           <td>".$article['fecha']."</td>
           <td>".$article['titulo']."</td>
        </tr>";
     }
     ?>
</table>
```

#### Tercera mejora: añadiendo capa de abstracción de datos

Como no sabemos lo que es el miedo, vamos a complicar nuestro patrón modelo-vista-controlador con una **cuarta capa**: la **capa de abstracción de datos**.

La idea de esta capa adicional es proporcionar un mecanismo de abstracción respecto del gestor de base de datos concreto que estemos utilizando.

Vaya frasecita, ¿eh? *"Un mecanismo de abstracción respecto del gestor de base de datos"*. Si no has bizqueado un poco al leerlo, es que tienes los nervios de acero. ¿Qué narices significa eso?

Es solo una de esas expresiones de que los informáticos usamos para fardar, como cuando un médico te dice que estás acatarrado, pero te lo dice en latín para que parezca más complicado de lo que es.

Te explico qué es eso del *"mecanismo de abstracción bla, bla, bla"*.

Si te fijas en el **modelo** de la solución anterior, verás que estamos usando una clase (*mysqli*) y unos métodos que solo funcionan con MySQL o MariaDB. Si quiséramos cambiar el gestor de base de datos (algo relativamente frecuente), tendríamos que revisar *todos* nuestros modelos, y tal vez modificar y volver a probar miles de líneas de código.

Una forma de independizar nuestra aplicación del gestor de base de datos que haya debajo es programar lo que se llama **capa de abstracción** que contenga dos o tres métodos genéricos (como *consultar()* para lanzar SELECT o *manipular()* para lanzar INSERT, UPDATE o DELETE).

De ese modo, cuando queramos hacer una consulta desde el modelo, no lo haremos con los métodos de MySQL (como *query()*, *fetch_array()* y similares), sino con los nuestros (*consultar()*, *manipular()*, o como los hayamos querido llamar). Si algún día necesitamos cambiar el gestor de base de datos, solo tendremos que reescribir el código de esa capa de abstracción, es decir, un par de decenas de líneas de código frente a varios miles que teníamos que revisar y probar antes.

Por lo tanto, en esta tercera mejora vamos a dividir el código en cuatro bloques:

* **Un controlador** (archivo *index.php*).
* **Una vista** (archivo *view.php*).
* **Un modelo en dos capas**:
   * **Capa de abstracción de datos** (*db.php*)
   * **Capa de acceso a datos** (el modelo de artículos propiamente dicho) (*articles.php*).

El código de la **capa de abstracción** sería algo así:

```php
class Db {

  private $db; // Aquí guardaremos la conexión con la base de datos

  /**
   * Abre la conexión con la base de datos
   * @param $server URL del servidor de la base de datos
   * @param $username Nombre de usuario en ese servidor
   * @param $pass Contraseña
   * @param $dbname Nombre de la base de datos
   * @return 0 si la conexión se realiza con normalidad y -1 en caso de error
   */
  function createConnection($server, $username, $pass, $dbname) {
    $db = new mysqli($servidor, $usuario, $clave, $dbname);
    if ($db->connect_errno) return -1;
    else return 0;
  }

  /**
   * Cierra la conexión con la base de datos
   */
  function closeConnection() {
    if ($this->db) $this->db->close();
  }

  /**
   * Lanza una consulta (SELECT) contra la base de datos.
   * ¡Ojo! Este método solo funcionará con sentencias SELECT.
   * @param $sql El código de la consulta que se quiere lanzar
   * @return Un array bidimensional con los resultados de la consulta (estará vacío si la consulta no devolvió nada)
   */
  function dataQuery($sql) {
    $res = $this->db->query($sql);
    $resArray = array();
    if ($res) {
      $resArray = $res->fetch_all();
    }
    return $resArray;
  }

  /**
   * Lanza una sentencia de manipulación de datos contra la base de datos.
   * ¡Ojo! Este método solo funcionará con sentencias INSERT, UPDATE, DELETE y similares.
   * @param $sql El código de la consulta que se quiere lanzar
   * @return El número de filas insertadas, modificadas o borradas por la sentencia SQL (0 si no produjo ningún efecto).
   */
  function dataManipulation($sql) {
    $this->db->query($sql);
    return $this->db->affected_rows;
  }
}
```

El código del **modelo** va a hacer uso de la capa de abstracción en lugar de usar los métodos de la clase *mysqli* directamente:

```php
include "Db.php";

class Articles {

  public function getAll() {
    $db = new Db();  // Creamos un objeto para usar nuestra capa de abstracción

    // Conectamos con la BD a través de nuestra capa de abstracción
    $db->createConnection('mi-host', 'mi-usuario', 'mi-clave', 'mi-base-de-datos');

    // Lanzamos la consulta a través de nuestra capa de abstracción.
    // Nos devolverá directamente un array estándar de PHP.
    $articles = $db->dataQuery('SELECT fecha, titulo FROM articulo');

    // Cerramos la conexión con la BD
    $db->closeConnection();

    return $articles;
  }

}
```

El **controlador** y la **vista** son exactamente los mismos que en la solución anterior, así que no vamos a escribir el código de nuevo. Esto es lógico: solo hemos modificado la forma en la que trabaja el modelo, pero gracias al encapsulamiento de los objetos, el resto de la aplicación no se ha enterado de ello.

#### Cuarta mejora: transformación en clases y objetos reutilizables.

Ahora vamos a dejar el **código bien organizado** y a mostrarlo (casi) completo.

Lo que haremos es **empaquetarlo todo en clases reutilizables**. Observa que sigue siendo el mismo código fuente, solo que empaquetado en clases y métodos. Lo único que queda fuera de una clase es la instanciación inicial del objeto controlador.

Fíjate bien en cómo hemos convertido las vistas en una clase con un método *show()* que nos servirá para mostrar cualquier vista y reutilizar el mismo *header* y el mismo *footer*. Cada vista se programará en un archivo independiente que deberemos organizar en directorios y subdirectorios. De momento, nuestra aplicación solo tiene una vista llamada *showAllArticles*, pero se podrían visualizar todas las necesarias usando el método *show()*.

Otra cosa que quiero que observes con mucha atención es **el punto de entrada a la aplicación** (archivo ***index.php***), porque lo hemos dejado preparado para poder añadir nuevas funciones al programa con posterioridad, así como varios controladores. El método que se ejecutará dependerá no solo de la **variable *"action"*** que se pasa por GET, sino también de otra variable llamada ***"controller"***, que también se pasa por GET, y que contendrá el nombre de la clase del controlador.

Así, para invocar, por ejemplo, el método *showAll()* del controlador *ArticlesController*, la ruta debería ser esta:

<code>
http://mi-servidor/index.php?controller=ArticlesController&action=showAll
</code>

Este *index.php* es tan genérico que **te servirá para montar cualquier aplicación MVC en el futuro**.

Si repasas el código del ejemplo resuelto de tema anterior (el de la autenticación mediante ACL), verás que ya se parecía mucho a este esquema, aunque en aquel *index.php* siempre utilizábamos el mismo controlador.

**Punto de entrada a la aplicación** (*index.php*)

```php
<?php
  include("articlesController.php");

  // Miramos a ver si se indica alguna acción en la URL
  if (!isset($_REQUEST['action'])) {
    // No hay acción en la URL. Usamos la acción por defecto (main). Puedes cambiarla por cualquier otra que vaya bien con tu aplicación.
    $action = "main";
  } else {
    // Sí hay acción en la URL. Recuperamos su nombre.
    $action = $_REQUEST['action'];
  }

  // Hacemos lo mismo con el nombre del controlador
  if (!isset($_REQUEST['controller'])) {
    // No hay controlador en la URL. Asignaremos un controlador por defecto (Articles). Por supuesto, puedes cambiarlo por otro que vaya bien con tu aplicación.
    $controllerClassName = "ArticlesController";
  } else {
    // Sí hay controlador en la URL. Recuperamos su nombre.
    $controllerClassName = $_REQUEST['controller'];
  }

  // Instanciamos el controlador e invocamos al método que se llama como la acción
  $controller = new $controllerClassName();
  $controller->$action();
?>

```

**Controlador de artículos** (articlesController.php)

```php
// Controlador. Debería tener un método por cada posible valor de la variable "action".
include ("view.php");
include ("articles.php");

class ArticlesController {

   public function showAll() {
      $data['articles'] = Articles::getAll();
      View::show("showAllArticles", $data);
   }

   // Añadir a partir de aquí un método por cada posible valor de la variable "action"

}
```

**Clase vista** (view.php)

```php
<?php

class View
{
   public function show($viewName, $data=null) {
      include("header.php");
      include("$viewName.php", $data);
      include("footer.php");
   }
}

?>
```

**Vista showAllArticles** (showAllArticles.php)

```html
<h1>Listado de Articulos</h1>
<table>
     <tr> <th>Fecha</th> <th>Titulo</th> </tr>
     <?php 
     $articles = $data['articles'];
     foreach($articles as $article) {
        echo "<tr>
           <td>".$articles['fecha']."</td>
           <td>".$articles['titulo']."</td>
        </tr>";
     }
     ?>
</table>
```

**Modelo - Capa de acceso a datos** (articles.php)

```php
include "db.php";

class Articles {

  public function getAll() {
    $db = new Db();
    $db->createConnection('mi-host', 'mi-usuario', 'mi-clave', 'mi-base-de-datos');
    $articles = $db->dataQuery('SELECT fecha, titulo FROM articulo');
    $db->closeConnection();
    return $articles;
  }
}
```

**Modelo - Capa de abstracción de datos** (db.php)

```php
class Db {

  private $db; // Aquí guardaremos la conexión con la base de datos

  /**
   * Abre la conexión con la base de datos
   * @param $server URL del servidor de la base de datos
   * @param $username Nombre de usuario en ese servidor
   * @param $pass Contraseña
   * @param $dbname Nombre de la base de datos
   * @return 0 si la conexión se realiza con normalidad y -1 en caso de error
   */
  function createConnection($server, $username, $pass, $dbname) {
    $db = new mysqli($servidor, $usuario, $clave, $dbname);
    if ($db->connect_errno) return -1;
    else return 0;
  }

  /**
   * Cierra la conexión con la base de datos
   */
  function closeConnection() {
    if ($this->db) $this->db->close();
  }

  /**
   * Lanza una consulta (SELECT) contra la base de datos.
   * ¡Ojo! Este método solo funcionará con sentencias SELECT.
   * @param $sql El código de la consulta que se quiere lanzar
   * @return Un array bidimensional con los resultados de la consulta (estará vacío si la consulta no devolvió nada)
   */
  function dataQuery($sql) {
    $res = $this->db->query($sql);
    $resArray = array();
    if ($res) {
      $resArray = $res->fetch_all();
    }
    return $resArray;
  }

  /**
   * Lanza una sentencia de manipulación de datos contra la base de datos.
   * ¡Ojo! Este método solo funcionará con sentencias INSERT, UPDATE, DELETE y similares.
   * @param $sql El código de la consulta que se quiere lanzar
   * @return El número de filas insertadas, modificadas o borradas por la sentencia SQL (0 si no produjo ningún efecto).
   */
  function dataManipulation($sql) {
    $this->db->query($sql);
    return $this->db->affected_rows;
  }
}
```

#### Quinta (y última) mejora: añadiendo un modelo genérico

En todos los modelos nos solemos encontrar una serie de operaciones que se repiten una y otra vez, como:

* Obtener todos los registros de una tabla.
* Obtener un registro de una tabla buscando por id.
* Borrar un registro a partir de su id.
* Insertar un registro.
* Modificar un registro.

Podemos programar un modelo genérico que haga estas cosas *sea cual sea la tabla de la que se trate*. Así no tendremos que escribir una y otr avez las mismas operaciones para cada uno de los modelos: bastará con que nuestros modelos **hereden** de este modelo genérico, y todas esas operaciones ya estarán disponibles sin escribir ni una línea de código.

Vamos a llamar ***Model*** a ese modelo genérico. Observa bien el siguiente código:

**Modelo genérico** (model.php)

```php
class Model {

  protected $table;  // Aquí guardaremos el nombre de la tabla a la que estamos accediendo
  private $db;       // Y aquí la capa de abstracción de datos

  public function __construct($tableName)  {
    $this->table = $tableName;
    $this->db = new Db();
    $this->db->createConnection('mi-host', 'mi-usuario', 'mi-clave', 'mi-base-de-datos');
  }

  public function getAll() {
    $list = $this->db->dataQuery('SELECT * FROM '.$this->table);
    $db->closeConnection();
    return $list;
  }
}
```

¡Acabamos de crear un método *getAll()* genérico que funcionará con cualquier tabla!

Mira ahora en qué poquita cosa se queda nuestro **modelo *Articles***:

```php
include "db.php";

class Articles extends Model {

  public __construct() {
    $this->table = "articles";
  }

}
```

Como el modelo *Articles* hereda ahora del modelo genérico, *Model*, resulta que ya posee un método llamado *getAll()* que, por lo tanto, no tenemos que programar. A cambio, todo lo que tenemos que hacer es asignar el valor correcto al atributo *$this->table*, para que el modelo genérico *Model* sepa el nombre de la tabla con la que tiene que trabajar.

Si ampliásemos nuestro modelo genérico, *Model*, con más funciones genéricas, todas ellas se heredarían en *Articles* (y en cualquier otro modelo de la aplicación). Las únicas funciones que tendríamos que escribir en *Articles* serían las específicas de ese modelo, si es que tiene alguna. Por experiencia, te puedo decir que la mayoría de los modelos no necesitarán ninguna función específica adicional, quedando así su código reducido a la mínima expresión.

Vamos a añadir algunas funciones más a nuestro modelo genérico:

```php
class Model {

  protected $table;  // Aquí guardaremos el nombre de la tabla a la que estamos accediendo
  private $db;       // Y aquí la capa de abstracción de datos

  public function __construct($tableName)  {
    $this->table = $tableName;
    $this->db = new Db();
    $this->db->createConnection('mi-host', 'mi-usuario', 'mi-clave', 'mi-base-de-datos');
  }

  public function getAll() {
    $list = $this->db->dataQuery("SELECT * FROM ".$this->table);
    return $list;
  }

  public function get($id) {
    $record = $this->db->dataQuery("SELECT * FROM ".$this->table." WHERE id = ".$id);
    return $record;
  } 

  public function delete($id) {
    $result = $this->db->dataQuery("DELETE FROM ".$this->table." WHERE id = ".$id);
    return $result;
  }
}
```

Solo faltaría crear una función *insert()* y otra *update()* para tener un CRUD completo en nuestro modelo genérico. ¿Te atreves a hacerlo? (Advertencia: generalizar estas dos funciones es bastante más difícil que todas las demás).

## 4.4. El patrón MVC en la teoría

Ahora que hemos aprendido a manejarnos con el patrón MVC por medio de un ejemplo, estamos en condiciones de definirlo de manera más teórica. E incluso entender esa definición, no te vayas a creer.

El patrón MVC consiste, pues, en dividir la aplicación en tres capas:

* **Los modelos**, donde se programa la *lógica de negocio*. De esa forma tan rimbombante se refiere la literatura técnica al acceso a los datos con los filtros, algoritmos y restricciones que el sistema imponga. 
   
   Dicho en palabras más sencillas, esto significa que en los modelos debemos colocar todo el código de acceso a la base de datos o a cualquier otro recurso del servidor (como las variables de sesión, por ejemplo). Los modelos deben empaquetar esos datos en objetos estándar de PHP (como arrays) y devolverlos al controlador.

   Lo más práctico es **crear un modelo para cada tabla maestra** de la base de datos.

   Los *frameworks* automatizan los métodos más típicos de cada modelo, como insertar un registro, borrar, actualizar, consultar uno o consultar todos. Ya veremos de qué formas tan alucinantes se las ingenian para hacer todo esto con un mínimo de esfuerzo por nuestra parte y, por supuesto, sin escribir el mismo código una y otra vez.

* **Las vistas**, donde se programan todas las salidas HTML que el usuario final va a ver y con las que va a interactuar.

   El código Javascript y CSS, por lo tanto, forma parte de las vistas.

   En las vistas estará el grueso del código de cualquier aplicación. Los *frameworks* más avanzados incluyen sistemas de **plantillas** para reutilizar fragmentos de vistas, así como lenguajes adicionales para simplificar la codificación de las vistas. Pero, si programamos en PHP clásico, tendremos que construir las vistas manualmente.

* **Los controladores**, donde se captura cada petición del usuario y se dirige el flujo de ejecución, invocando a los modelos y a las vistas en el orden adecuado.

   En una aplicación pequeña, bastará con tener un controlador para todo. Cuando la aplicación crece, suele hacerse **un controlador por cada modelo**, es decir, un controlador por cada tabla maestra.

   Los controladores estarán compuestos por una colección de métodos, uno para cada funcionalidad de la aplicación. El método que se ejecute en cada ocasión estará controlado por la URL. En concreto, por la variable *"action"* que se pasará por GET, aunque, por supuesto, puedes ponerle otro nombre si *"action"* no te gusta.
   
   En los *frameworks*, esta variable "action" se transforma en una URL limpia que, a través de un objeto adicional llamado **enrutador**, termina provocando la invocación del método adecuado. 

   Es decir: en una aplicación MVC como las que hemos visto hasta ahora, tendremos una ruta como esta para, por ejemplo, consultar el artículo con id 37:

   <code>https://mi-servidor/index.php?action=showArticle&idArticle=37</code>

   En cambio, en un *framework* avanzado, la ruta tendrá un aspecto más limpio para hacer lo mismo. Algo así como:

   <code>https://mi-servidor/articles/show/37</code>

   Y el enrutador se encargará trocear esa URL y extraer de ella la información para instanciar el controlador adecuado y llamar al método correcto.

## 4.5. Ejercicios resueltos

### 4.5.1. Biblioteca v2

En la versión 2 de la biblioteca (ver [ejercicios resueltos del Tema 2](/docs/dwes/_site/php/ejercicios-resueltos.html#283-biblioteca)) hemos convertido el código monolítico en **una arquitectura MVC**, aunque aún no hemos introducido la capa de abstracción de datos ni la de seguridad.

Además, solo mostraremos hecha toda la parte correspondiente a la tabla *libros*. Con esto es suficiente para comprender cómo funciona esta arquitectura sin necesidad de alargar innecesariamente el código. En cualquier caso, el mantenimiento de la tabla *personas* se resolvería de forma muy parecida. 

#### Controlador (index.php)

En aplicaciones grandes suele haber varios controladores. Aquí, de momento, vamos a apañarnos solo con uno.

```php
<!-- BIBLIOTECA VERSIÓN 2
     Características de esta versión:
       - Código con arquitectura MVC
       - Sin capa de abstracción de datos
       - Sin seguridad, sesiones ni control de acceso
-->
<?php
    include_once("models/libro.php");  // Modelos
    include_once("models/persona.php");
    include_once("view.php");   // Plantilla de vista

    // Miramos el valor de la variable "action", si existe. Si no, le asignamos una acción por defecto
    if (isset($_REQUEST["action"])) {
        $action = $_REQUEST["action"];
    } else {
        $action = "mostrarListaLibros";  // Acción por defecto
    }

    // Creamos un objeto de tipo Biblioteca y llamamos al método $action()
    $biblio = new Biblioteca();
    $biblio->$action();

    class Biblioteca {
        private $db;     // Conexión con la base de datos
        private $libro, $persona; // Modelos

        public function __construct() {
            $this->libro = new Libro();
            $this->persona = new Persona();
        }

        // --------------------------------- MOSTRAR LISTA DE LIBROS ----------------------------------------
        public function mostrarListaLibros() {
            $data["listaLibros"] = $this->libro->getAll();
            View::render("libro/all", $data);
        }

        // --------------------------------- FORMULARIO ALTA DE LIBROS ----------------------------------------

        public function formularioInsertarLibros() {
            $data["todosLosAutores"] = $this->persona->getAll();
            $data["autoresLibro"] = array();  // Array vacío (el libro aún no tiene autores asignados)
            View::render("libro/form", $data);
        }

        // --------------------------------- INSERTAR LIBROS ----------------------------------------

        public function insertarLibro() {
            // Primero, recuperamos todos los datos del formulario
            $titulo = $_REQUEST["titulo"];
            $genero = $_REQUEST["genero"];
            $pais = $_REQUEST["pais"];
            $ano = $_REQUEST["ano"];
            $numPaginas = $_REQUEST["numPaginas"];
            $autores = $_REQUEST["autor"];            

            // Le pedimos al modelo que guarde el libro en la BD
            $result = $this->libro->insert($titulo, $genero, $pais, $ano, $numPaginas);
            if ($result == 1) {
                // Si la inserción del libro ha funcionado, continuamos insertando los autores, pero
                // necesitamos conocer el id del libro que acabamos de insertar
                $idLibro = $this->libro->getMaxId();
                // Ya podemos insertar todos los autores junto con el libro en "escriben"
                $result = $this->libro->insertAutores($idLibro, $autores);
                if ($result > 0) {
                    $data["info"] = "Libro insertado con éxito";
                } else {
                    $data["error"] = "Error al insertar los autores del libro";
                }
            } else {
                // Si la inserción del libro ha fallado, mostramos mensaje de error
                $data["error"] = "Error al insertar el libro";
            }
            $data["listaLibros"] = $this->libro->getAll();
            View::render("libro/all", $data);

        }

        // --------------------------------- BORRAR LIBROS ----------------------------------------

        public function borrarLibro() {
            // Recuperamos el id del libro que hay que borrar
            $idLibro = $_REQUEST["idLibro"];
            // Pedimos al modelo que intente borrar el libro
            $result = $this->libro->delete($idLibro);
            // Comprobamos si el borrado ha tenido éxito
            if ($result == 0) {
                $data["error"] = "Ha ocurrido un error al borrar el libro. Por favor, inténtelo de nuevo";
            } else {
                $data["info"] = "Libro borrado con éxito";
            }
            $data["listaLibros"] = $this->libro->getAll();
            View::render("libro/all", $data);

        }

        // --------------------------------- FORMULARIO MODIFICAR LIBROS ----------------------------------------

        public function formularioModificarLibro() {
            // Recuperamos los datos del libro a modificar
            $data["libro"] = $this->libro->get($_REQUEST["idLibro"]);
            // Renderizamos la vista de inserción de libros, pero enviándole los datos del libro recuperado.
            // Esa vista necesitará la lista de todos los autores y, además, la lista
            // de los autores de este libro en concreto.
            $data["todosLosAutores"] = $this->persona->getAll();
            $data["autoresLibro"] = $this->persona->getAutores($_REQUEST["idLibro"]);
            View::render("libro/form", $data);
        }

        // --------------------------------- MODIFICAR LIBROS ----------------------------------------

        public function modificarLibro() {
            // Primero, recuperamos todos los datos del formulario
            $idLibro = $_REQUEST["idLibro"];
            $titulo = $_REQUEST["titulo"];
            $genero = $_REQUEST["genero"];
            $pais = $_REQUEST["pais"];
            $ano = $_REQUEST["ano"];
            $numPaginas = $_REQUEST["numPaginas"];
            $autores = $_REQUEST["autor"];

            // Pedimos al modelo que haga el update
            $result = $this->libro->update($idLibro, $titulo, $genero, $pais, $ano, $numPaginas);
            if ($result == 1) {
                $data["info"] = "Libro actualizado con éxito";
            } else {
                // Si la modificación del libro ha fallado, mostramos mensaje de error
                $data["error"] = "Ha ocurrido un error al modificar el libro. Por favor, inténtelo más tarde";
            }
            $data["listaLibros"] = $this->libro->getAll();
            View::render("libro/all", $data);
        }

        // --------------------------------- BUSCAR LIBROS ----------------------------------------

        public function buscarLibros() {
            // Recuperamos el texto de búsqueda de la variable de formulario
            $textoBusqueda = $_REQUEST["textoBusqueda"];
            // Buscamos los libros que coinciden con la búsqueda
            $data["listaLibros"] = $this->libro->search($textoBusqueda);
            $data["info"] = "Resultados de la búsqueda: <i>$textoBusqueda</i>";
            // Mostramos el resultado en la misma vista que la lista completa de libros
            View::render("libro/all", $data);
        }

        // --------------------------------- MOSTRAR LISTA DE AUTORES ----------------------------------------
        public function mostrarListaAutores() {
            // Esto está en construcción. Llamaremos a una vista inexistente.
            View::render("autor/all");
        }        

    } // class
```

#### Modelo de libros (models/libro.php)

El modelo de libros conserva la función *getAll()* porque, en este caso, no nos sirve el *getAll()* de *Model*. Este último solo nos devolvería los datos existentes en la tabla *Libros*, y nosotros necesitamos que *getAll()* nos devuelva también los autores, es decir, que haga un JOIN entre las tablas *Libros* y *Autores*.

```php
<?php

// MODELO DE LIBROS

class Libro
{

    private $db;

    // Constructor. Habilita la conexión con la base de datos.
    public function __construct()
    {
        $this->db = new mysqli("mariadb", "root", "bitnami", "biblioteca");
    }

    // Obtiene todos los libros de la base de datos y los devuelve como un array de objetos
    public function getAll()
    {
        $resultado = $this->db->query("SELECT * FROM libros
                                        INNER JOIN escriben ON libros.idLibro = escriben.idLibro
                                        INNER JOIN personas ON escriben.idPersona = personas.idPersona
                                        ORDER BY libros.titulo");
        $listaLibros = array();
        while ($fila = $resultado->fetch_object()) {
            $listaLibros[] = $fila;
        }
        return $listaLibros;
    }

    // Obtiene un libro de la base de datos y lo devuelve como un objeto
    public function get($id)
    {
        $result = $this->db->query("SELECT * FROM libros WHERE libros.idLibro = '$id'");
        $libro = $result->fetch_object();
        return $libro;
    }

    // Devuelve el último id asignado en la tabla de libros
    public function getMaxId()
    {
        $result = $this->db->query("SELECT MAX(idLibro) AS ultimoIdLibro FROM libros");
        $idLibro = $result->fetch_object()->ultimoIdLibro;
        return $idLibro;
    }

    // Inserta un libro. Devuelve 1 si tiene éxito o 0 si falla.
    public function insert($titulo, $genero, $pais, $ano, $numPaginas)
    {
        $this->db->query("INSERT INTO libros (titulo,genero,pais,ano,numPaginas) VALUES ('$titulo','$genero', '$pais', '$ano', '$numPaginas')");
        return $this->db->affected_rows;
    }

    // Inserta los autores de un libro. Recibe el id del libro y la lista de ids de los autores en forma de array.
    // Devuelve el número de autores insertados con éxito (0 en caso de fallo).
    public function insertAutores($idLibro, $autores)
    {
        $correctos = 0;
        foreach ($autores as $idAutor) {
            $this->db->query("INSERT INTO escriben(idLibro, idPersona) VALUES('$idLibro', '$idAutor')");
            if ($this->db->affected_rows == 1) $correctos++;
        }
        return $correctos;
    }

    // Actualiza un libro (todo menos sus autores). Devuelve 1 si tiene éxito y 0 en caso de fallo.
    public function update($idLibro, $titulo, $genero, $pais, $ano, $numPaginas)
    {
        $this->db->query("UPDATE libros SET
            titulo = '$titulo',
            genero = '$genero',
            pais = '$pais',
            ano = '$ano',
            numPaginas = '$numPaginas'
            WHERE idLibro = '$idLibro'");
        return $this->db->affected_rows;
    }

    // Elimina un libro. Devuelve 1 si tiene éxito y 0 en caso de fallo.
    public function delete($idLibro)
    {
        $this->db->query("DELETE FROM libros WHERE idLibro = '$idLibro'");
        return $this->db->affected_rows;
    }

    // Busca un texto en las tablas de libros y autores. Devuelve un array de objetos con todos los libros
    // que cumplen el criterio de búsqueda.
    public function search($textoBusqueda)
    {
        // Buscamos los libros de la biblioteca que coincidan con el texto de búsqueda
        $result = $this->db->query("SELECT * FROM libros
					INNER JOIN escriben ON libros.idLibro = escriben.idLibro
					INNER JOIN personas ON escriben.idPersona = personas.idPersona
					WHERE libros.titulo LIKE '%$textoBusqueda%'
					OR libros.genero LIKE '%$textoBusqueda%'
					OR personas.nombre LIKE '%$textoBusqueda%'
					OR personas.apellido LIKE '%$textoBusqueda%'
					ORDER BY libros.titulo");
        $listaLibros = array();
        while ($fila = $result->fetch_object()) {
            $listaLibros[] = $fila;
        }
        return $listaLibros;
    }
}
```

#### Modelo de personas (models/persona.php)

Como dijimos antes, la parte del mantenimiento de la tabla *personas* no se ha resuelto para no alargar innecesarimente el código, así que aquí se incluyen solo las funciones imprescindibles para el mantenimiento de la tabla *libros*.

Añadir el mantenimiento de *personas* sería muy sencillo, ya que es, en esencia, igual que el de *libros*, aunque algo más sencillo en algunas vistas.

```php
<?php
// MODELO DE PERSONAS

class Persona {

    private $db;

    // Constructor. Conecta con la base de datos.
    public function __construct() {
        $this->db = new mysqli("mariadb", "root", "bitnami", "biblioteca");
    }

    // Devuelve todas las personas de la base de datos en forma de array de objetos
    public function getAll() {
        $result = $this->db->query("SELECT * FROM personas");
        $listaPers = array();
        while ($fila = $result->fetch_object()) {
            $listaPers[] = $fila;
        }
        return $listaPers;
    }

    // Devuelve un array con los ids de los autores de un libro
    public function getAutores($idLibro) {
        // Obtenemos solo los autores del libro que estamos buscando
        $autoresLibro = $this->db->query("SELECT idPersona FROM escriben WHERE idLibro = '$idLibro'");
        // Vamos a convertir esa lista de autores del libro en un array de ids de personas
        $listaAutoresLibro = array();
        while ($autor = $autoresLibro->fetch_object()) {
            $listaAutoresLibro[] = $autor->idPersona;
        }
        return $listaAutoresLibro;
    }
}
```

#### Plantilla de las vistas (view.php)

```php
<?php

// PLANTILLA DE LAS VISTAS

class View {
    public static function render($nombreVista, $data = null) {
        include("views/header.php");
        include("views/nav.php");
        include("views/$nombreVista.php");
        include("views/footer.php");
    }
}
```

#### Vista "lista de libros" (views/libro/all.php)

```php
<?php
// VISTA PARA LA LISTA DE LIBROS

// Recuperamos la lista de libros
$listaLibros = $data["listaLibros"];

// Si hay algún mensaje de feedback, lo mostramos
if (isset($data["info"])) {
  echo "<div style='color:blue'>".$data["info"]."</div>";
}

if (isset($data["error"])) {
  echo "<div style='color:red'>".$data["error"]."</div>";
}

echo "<form action='index.php'>
        <input type='hidden' name='action' value='buscarLibros'>
        <input type='text' name='textoBusqueda'>
        <input type='submit' value='Buscar'>
      </form><br>";

// Ahora, la tabla con los datos de los libros
if (count($listaLibros) == 0) {
  echo "No hay datos";
} else {
  echo "<table border ='1'>";
  foreach ($listaLibros as $fila) {
    echo "<tr>";
    echo "<td>" . $fila->titulo . "</td>";
    echo "<td>" . $fila->genero . "</td>";
    echo "<td>" . $fila->numPaginas . "</td>";
    echo "<td>" . $fila->nombre . "</td>";
    echo "<td>" . $fila->apellido . "</td>";
    echo "<td><a href='index.php?action=formularioModificarLibro&idLibro=" . $fila->idLibro . "'>Modificar</a></td>";
    echo "<td><a href='index.php?action=borrarLibro&idLibro=" . $fila->idLibro . "'>Borrar</a></td>";
    echo "</tr>";
  }
  echo "</table>";
}
echo "<p><a href='index.php?action=formularioInsertarLibros'>Nuevo</a></p>";
```

#### Vista para inserción/modificación de libros (views/libro/form.php)

```php
<?php
// VISTA PARA INSERCIÓN/EDICIÓN DE LIBROS

extract($data);   // Extrae el contenido de $data y lo convierte en variables individuales ($libro, $todosLosAutores y $autoresLibro)

// Vamos a usar la misma vista para insertar y modificar. Para saber si hacemos una cosa u otra,
// usaremos la variable $libro: si existe, es porque estamos modificando un libro. Si no, estamos insertando uno nuevo.
if (isset($libro)) {   
    echo "<h1>Modificación de libros</h1>";
} else {
    echo "<h1>Inserción de libros</h1>";
}

// Sacamos los datos del libro (si existe) a variables individuales para mostrarlo en los inputs del formulario.
// (Si no hay libro, dejamos los campos en blanco y el formulario servirá para inserción).
$idLibro = $libro->idLibro ?? ""; 
$titulo = $libro->titulo ?? "";
$genero = $libro->genero ?? "";
$pais = $libro->pais ?? "";
$ano = $libro->ano ?? "";
$numPags = $libro->numPaginas ?? "";

// Creamos el formulario con los campos del libro
echo "<form action = 'index.php' method = 'get'>
        <input type='hidden' name='idLibro' value='".$idLibro."'>
        Título:<input type='text' name='titulo' value='".$titulo."'><br>
        Género:<input type='text' name='genero' value='".$genero."'><br>
        País:<input type='text' name='pais' value='".$pais."'><br>
        Año:<input type='text' name='ano' value='".$ano."'><br>
        Número de páginas:<input type='text' name='numPaginas' value='".$numPags."'><br>";

echo "Autores: <select name='autor[]' multiple size='3'>";
foreach ($todosLosAutores as $fila) {
    if (in_array($fila->idPersona, $autoresLibro))
        echo "<option value='$fila->idPersona' selected>$fila->nombre $fila->apellido</option>";
    else
        echo "<option value='$fila->idPersona'>$fila->nombre $fila->apellido</option>";
}
echo "</select>";

// Finalizamos el formulario
if (isset($libro)) {
    echo "  <input type='hidden' name='action' value='modificarLibro'>";
} else {
    echo "  <input type='hidden' name='action' value='insertarLibro'>";
}
echo "	<input type='submit'></form>";
echo "<p><a href='index.php'>Volver</a></p>";
```

#### Componentes de la plantilla: cabecera, menú de navegación y pie

Aquí te ofrezco unas versiones mínimas de estos componentes que aparecerán en todas las vistas. Obviamente, puedes mejorar el aspecto de tu aplicación retocándolos a tu gusto.

**views/header.php**

```php
<!DOCTYPE html>
<html lang="es">
<head>
    <meta charset="UTF-8">
</head>

<body>
    <h1>BIBLIOTECA</h1>
```

**views/nav.php**

```php
<hr/>
<nav>
    Menú de navegación: 
    <a href='index.php'>Home</a>
    <a href='index.php?action=mostrarListaLibros'>Libros</a>
    <a href='index.php?action=mostrarListaAutores'>Autores</a>
</nav>
<hr/>
```

**views/footer.php**

```php
<h5>Este es el pie de página</h5>
<h5>&copy; 2022 Yo mismo</h5>
</body>
</html>
```

### 4.5.2. Biblioteca v3

En la versión 3 de la biblioteca (ver [ejercicios resueltos del Tema 2](/docs/dwes/_site/php/ejercicios-resueltos.html#283-biblioteca)) hemos convertido el código monolítico en **una arquitectura MVC con capa de abstracción de datos y modelo genérico**, aunque aún se puede mejorar introduciendo seguridad, control de acceso (sesiones) y controladores múltiples.

Como en ocasiones anteriores, solo mostraremos hecha toda la parte correspondiente a la tabla *libros*. Con esto es suficiente para comprender cómo funciona esta arquitectura sin necesidad de alargar innecesariamente el código. En cualquier caso, el mantenimiento de la tabla *personas* se resolvería de forma muy parecida. 

#### Controlador (index.php)

En aplicaciones grandes suele haber varios controladores. Aquí, de momento, vamos a apañarnos solo con uno.

```php
<!-- BIBLIOTECA VERSIÓN 3
     Características de esta versión:
       - Código con arquitectura MVC
       - Un solo controlador
       - Con capa de abstracción de datos
       - Sin seguridad, sesiones ni control de acceso
-->
<?php
    include_once("models/libro.php");  // Modelos
    include_once("models/persona.php");
    include_once("view.php");          // Plantilla de vista

    // Miramos el valor de la variable "action", si existe. Si no, le asignamos una acción por defecto
    if (isset($_REQUEST["action"])) {
        $action = $_REQUEST["action"];
    } else {
        $action = "mostrarListaLibros";  // Acción por defecto
    }

    // Creamos un objeto de tipo Biblioteca y llamamos al método $action()
    $biblio = new Biblioteca();
    $biblio->$action();

    class Biblioteca {
        private $db;             // Conexión con la base de datos
        private $libro, $persona;// Modelos

        public function __construct() {
            $this->libro = new Libro();
            $this->persona = new Persona();
        }

        // --------------------------------- MOSTRAR LISTA DE LIBROS ----------------------------------------
        public function mostrarListaLibros() {
            $data["listaLibros"] = $this->libro->getAll();
            View::render("libro/all", $data);
        }

        // --------------------------------- FORMULARIO ALTA DE LIBROS ----------------------------------------

        public function formularioInsertarLibros() {
            $data["todosLosAutores"] = $this->persona->getAll();
            $data["autoresLibro"] = array();  // Array vacío (el libro aún no tiene autores asignados)
            View::render("libro/form", $data);
        }

        // --------------------------------- INSERTAR LIBROS ----------------------------------------

        public function insertarLibro() {
            // Primero, recuperamos todos los datos del formulario
            $titulo = $_REQUEST["titulo"];
            $genero = $_REQUEST["genero"];
            $pais = $_REQUEST["pais"];
            $ano = $_REQUEST["ano"];
            $numPaginas = $_REQUEST["numPaginas"];
            $autores = $_REQUEST["autor"];            

            $result = $this->libro->insert($titulo, $genero, $pais, $ano, $numPaginas);
            if ($result == 1) {
                // Si la inserción del libro ha funcionado, continuamos insertando los autores, pero
                // necesitamos conocer el id del libro que acabamos de insertar
                $idLibro = $this->libro->getMaxId();
                // Ya podemos insertar todos los autores junto con el libro en "escriben"
                $result = $this->libro->insertAutores($idLibro, $autores);
                if ($result > 0) {
                    $data["info"] = "Libro insertado con éxito";
                } else {
                    $data["error"] = "Error al insertar los autores del libro";
                }
            } else {
                // Si la inserción del libro ha fallado, mostramos mensaje de error
                $data["error"] = "Error al insertar el libro";
            }
            $data["listaLibros"] = $this->libro->getAll();
            View::render("libro/all", $data);

        }

        // --------------------------------- BORRAR LIBROS ----------------------------------------

          public function borrarLibro() {
            // Recuperamos el id del libro que hay que borrar
            $idLibro = $_REQUEST["idLibro"];
            // Pedimos al modelo que intente borrar el libro
            $result = $this->libro->delete($idLibro);
            // Comprobamos si el borrado ha tenido éxito
            if ($result == 0) {
                $data["error"] = "Ha ocurrido un error al borrar el libro. Por favor, inténtelo de nuevo";
            } else {
                $data["info"] = "Libro borrado con éxito";
            }
            $data["listaLibros"] = $this->libro->getAll();
            View::render("libro/all", $data);

        }

        // --------------------------------- FORMULARIO MODIFICAR LIBROS ----------------------------------------

        public function formularioModificarLibro() {
            // Recuperamos los datos del libro a modificar
            $data["libro"] = $this->libro->get($_REQUEST["idLibro"])[0];
            // Renderizamos la vista de inserción de libros, pero enviándole los datos del libro recuperado.
            // Esa vista necesitará la lista de todos los autores y, además, la lista
            // de los autores de este libro en concreto.
            $data["todosLosAutores"] = $this->persona->getAll();
            $data["autoresLibro"] = $this->persona->getAutores($_REQUEST["idLibro"]);
            View::render("libro/form", $data);
        }

        // --------------------------------- MODIFICAR LIBROS ----------------------------------------

        public function modificarLibro() {
            // Primero, recuperamos todos los datos del formulario
            $idLibro = $_REQUEST["idLibro"];
            $titulo = $_REQUEST["titulo"];
            $genero = $_REQUEST["genero"];
            $pais = $_REQUEST["pais"];
            $ano = $_REQUEST["ano"];
            $numPaginas = $_REQUEST["numPaginas"];
            $autores = $_REQUEST["autor"];

            // Pedimos al modelo que haga el update
            $result = $this->libro->update($idLibro, $titulo, $genero, $pais, $ano, $numPaginas);
            if ($result == 1) {
                $data["info"] = "Libro actualizado con éxito";
            } else {
                // Si la modificación del libro ha fallado, mostramos mensaje de error
                $data["error"] = "Ha ocurrido un error al modificar el libro. Por favor, inténtelo más tarde";
            }
            $data["listaLibros"] = $this->libro->getAll();
            View::render("libro/all", $data);
        }

        // --------------------------------- BUSCAR LIBROS ----------------------------------------

        public function buscarLibros() {
            // Recuperamos el texto de búsqueda de la variable de formulario
            $textoBusqueda = $_REQUEST["textoBusqueda"];
            // Buscamos los libros que coinciden con la búsqueda
            $data["listaLibros"] = $this->libro->search($textoBusqueda);
            $data["info"] = "Resultados de la búsqueda: <i>$textoBusqueda</i>";
            // Mostramos el resultado en la misma vista que la lista completa de libros
            View::render("libro/all", $data);
        }

        // --------------------------------- MOSTRAR LISTA DE AUTORES ----------------------------------------
        public function mostrarListaAutores() {
            // Esto está sin desarrollar aún. De momento, llamaremos a una vista inexistente.
            View::render("autor/all");
        }   

        // -------- LA APLICACIÓN CONTINUARÍA DESARROLLÁNDOSE AÑADIENDO FUNCIONES AQUÍ ------------------------

    } // class
```

#### Modelo de libros (models/libro.php)

Los modelos (tanto el de *libros* como el de *personas*) harán uso en esta solución del modelo genérico, *Model*, cuyo código aparece más abajo. De ese modo no tienen que implementar funciones genéricas como *get()*, *getAll()* o *delete()*, porque ya las heredan de *Model*.

A cambio, tienen que asignar un valor a los atributos *table* y *idColumn*, heredados también de *Model*, y donde se indica el nombre de la tabla de la base de datos a la que se refiere este modelo y el nombre del campo *id* de esa misma tabla.

Las funciones que no son "genéricas", es decir, que son específicas de cada modelo, sí que debemos implementarlas, puesto que no estarán en *Model*. Por ejemplo, *getMaxId()* o *insertAutores()* son métodos específicos del modelo *Libro*.

Además, otras funciones que sí son genéricas, como *insert()* o *update()* (para insertar y actualizar datos en la tabla), no se han incluido en *Model* porque resulta difícil generalizarlas, es decir, hacerlas funcionar con cualquier tabla y con cualquier conjunto de campos. Es un ejercicio interesante que pienses alguna manera de lograr esto y así hacer que nuestro modelo genérico *Model* sea aún más potente (y, en consecuencia, que nuestros modelos concretos como *Libro* o *Persona* se vuelvan aún más sencillos).

Observa que todas las funciones de los modelos usan la capa de abstracción de datos (*db*, con sus métodos *dataQuery()* y *dataManipulation()*, como hemos visto a lo largo del tema) para ejecutar el SQL sin depender de la base de datos concreta que estemos usando. Así, si en algún momento cambiamos de gestor de bases de datos, solo hay que modificar la capa de abstracción de datos (*db*), pero los modelos seguirán funcionando sin que les afecte el cambio.

```php
<?php

// MODELO DE LIBROS

include_once "model.php";

class Libro extends Model
{

    // Constructor. Especifica el nombre de la tabla de la base de datos
    public function __construct()
    {
        $this->table = "libros";
        $this->idColumn = "idLibro";
        parent::__construct();
    }

    // Devuelve el último id asignado en la tabla de libros
    public function getMaxId()
    {
        $result = $this->db->dataQuery("SELECT MAX(idLibro) AS ultimoIdLibro FROM libros");
        return $result[0]->ultimoIdLibro;
    }

    // Inserta un libro. Devuelve 1 si tiene éxito o 0 si falla.
    public function insert($titulo, $genero, $pais, $ano, $numPaginas)
    {
        return $this->db->dataManipulation("INSERT INTO libros (titulo,genero,pais,ano,numPaginas) VALUES ('$titulo','$genero', '$pais', '$ano', '$numPaginas')");
    }

    // Inserta los autores de un libro. Recibe el id del libro y la lista de ids de los autores en forma de array.
    // Devuelve el número de autores insertados con éxito (0 en caso de fallo).
    public function insertAutores($idLibro, $autores)
    {
        $correctos = 0;
        foreach ($autores as $idAutor) {
            $correctos += $this->db->dataManipulation("INSERT INTO escriben(idLibro, idPersona) VALUES('$idLibro', '$idAutor')");
        }
        return $correctos;
    }

    // Actualiza un libro (todo menos sus autores). Devuelve 1 si tiene éxito y 0 en caso de fallo.
    public function update($idLibro, $titulo, $genero, $pais, $ano, $numPaginas)
    {
        $ok = $this->db->query("UPDATE libros SET
                                titulo = '$titulo',
                                genero = '$genero',
                                pais = '$pais',
                                ano = '$ano',
                                numPaginas = '$numPaginas'
                                WHERE idLibro = '$idLibro'");
        return $ok;
    }

    // Busca un texto en las tablas de libros y autores. Devuelve un array de objetos con todos los libros
    // que cumplen el criterio de búsqueda.
    public function search($textoBusqueda)
    {
        // Buscamos los libros de la biblioteca que coincidan con el texto de búsqueda
        $result = $this->db->dataQuery("SELECT * FROM libros
					                    INNER JOIN escriben ON libros.idLibro = escriben.idLibro
					                    INNER JOIN personas ON escriben.idPersona = personas.idPersona
					                    WHERE libros.titulo LIKE '%$textoBusqueda%'
					                    OR libros.genero LIKE '%$textoBusqueda%'
					                    OR personas.nombre LIKE '%$textoBusqueda%'
					                    OR personas.apellido LIKE '%$textoBusqueda%'
					                    ORDER BY libros.titulo");
        return $result;
    }
}
```

#### Modelo de personas (models/persona.php)

Como en las versiones anteriores de este programa, la parte del mantenimiento de la tabla *personas* no se ha resuelto por completo para no alargar innecesarimente el código, así que aquí se incluyen solo las funciones imprescindibles para el CRUD de la tabla *libros*.

```php
<?php

// MODELO DE PERSONAS

include_once "model.php";

class Persona extends Model {

    // Constructor. Conecta con la base de datos.
    public function __construct() {
        $this->table = "personas";
        $this->idColumn = "idPersona";
        parent::__construct();
    }

    // Devuelve un array con los ids de los autores de un libro
    public function getAutores($idLibro) {
        // Obtenemos solo los autores del libro que estamos buscando
        $autoresLibro = $this->db->dataQuery("SELECT idPersona FROM escriben WHERE idLibro = '$idLibro'");
        // Vamos a convertir esa lista de autores del libro en un array de ids de personas
        return $autoresLibro;
    }
}
```

#### Modelo genérico (models/model.php)

Te recuerdo que el modelo genérico es la clase de la que heredan todos los demás modelos, y que implementa algunas funciones genéricas, presentes en todos los modelos, como *get()*, *getAll()* o *delete()*. No hemos incluido otras funciones que podrían estar aquí, como *insert()* o *update()*, porque resulta más complejo generalizarlas, pero pensar soluciones para lograrlo es un gran ejercicio mental para un programador web.

Fíjate en que estas funciones genéricas necesitan conocer el nombre de la tabla y el identificador del campo *id* para poder trabajar adecuadamente. Por eso hay que asignarle valor a esos atributos en los constructores de todos los modelos.

Por último, observa que todas las funciones usan la capa de abstracción de datos para independizarlas de la base de datos concreta con la que estemos operando.

```php
<?php

include_once "db.php";

// MODELO GENÉRICO

class Model {

  protected $table;    // Aquí guardaremos el nombre de la tabla a la que estamos accediendo
  protected $idColumn; // Aquí guardaremos el nombre de la columna que contiene el id (por defecto, "id")
  protected $db;       // Y aquí la capa de abstracción de datos

  public function __construct()  {
    $this->db = new Db();
  }

  public function getAll() {
    $list = $this->db->dataQuery("SELECT * FROM ".$this->table);
    return $list;
  }

  public function get($id) {
    $record = $this->db->dataQuery("SELECT * FROM ".$this->table." WHERE ".$this->idColumn."= $id");
    return $record;
  } 

  public function delete($id) {
    $result = $this->db->dataManipulation("DELETE FROM ".$this->table." WHERE ".$this->idColumn." = $id");
    return $result;
  }
}
```

#### Capa de abstracción de datos (db.php)

La capa de abstracción de datos independiza el resto de la aplicación de la base de datos concreta que se esté utilizando.

Esta capa de abstracción funciona con MySQL o MariaDB. Para otros gestores de bases de datos, habría que cambiarla, pero, como ves, se trata en realidad de muy poco código y el cambio sería fácil y rápido. El resto de la aplicación seguiría funcionando sin que le afectara en absoluto.

Las funciones de esta clase hacen uso del objeto *mysqli* y convierten cualquier resultado a datos estándar de PHP (arrays, números enteros, booleanos o lo que sea, siempre que no sean objetos del interfaz con MySQL). Tenemos una función para lanzar SELECT que se llama *dataQuery()* y devuelve un array con los resultados, y otra función para lanzar INSERT, UPDATE o DELETE llamada *dataManipulation()* que devuelve un entero (el número de registros manipulados).

Además, verás que la conexión se establece en el constructor, tomando los datos sobre el servidor, el usuario o la contraseña de un archivo *config.php* para que sean fáciles de cambiar.

```php
<?php

// CAPA DE ABSTRACCIÓN DE DATOS

class Db
{

  private $db; // Aquí guardaremos la conexión con la base de datos

  /**
   * Abre la conexión con la base de datos
   * @return 0 si la conexión se realiza con normalidad y -1 en caso de error
   */
  function __construct()
  {
    // Las constantes DBSERVER, DBUSER, DBPASS y DBNAME deben estar definidas en config.php
    require_once("config.php");
    $this->db = new mysqli(DBHOST, DBUSER, DBPASS, DBNAME);
    if ($this->db->connect_errno) return -1;
    else return 0;
  }

  /**
   * Cierra la conexión con la base de datos
   */
  function close()
  {
    if ($this->db) $this->db->close();
  }

  /**
   * Lanza una consulta (SELECT) contra la base de datos.
   * ¡Ojo! Este método solo funcionará con sentencias SELECT.
   * @param $sql El código de la consulta que se quiere lanzar
   * @return Un array bidimensional con los resultados de la consulta (estará vacío si la consulta no devolvió nada)
   */
  function dataQuery($sql)
  {
    $res = $this->db->query($sql);
    // Ahora vamos a convertir el resultado en un array convencional de PHP antes de devolverlo
    $resArray = array();
    while ($fila = $res->fetch_object()) {
      $resArray[] = $fila;
    }
    return $resArray;
  }

  /**
   * Lanza una sentencia de manipulación de datos contra la base de datos.
   * ¡Ojo! Este método solo funcionará con sentencias INSERT, UPDATE, DELETE y similares.
   * @param $sql El código de la consulta que se quiere lanzar
   * @return El número de filas insertadas, modificadas o borradas por la sentencia SQL (0 si no produjo ningún efecto).
   */
  function dataManipulation($sql)
  {
    $this->db->query($sql);
    return $this->db->affected_rows;
  }
}
```

#### Archivo de configuración (config.php)

Este archivo solo define las constantes DBHOST, DBUSER, DBPASS y DBNAME para la conexión con la base de datos. Así, cuando haya que cambiarlas, solo hay que tocar este archivo (esto debería especificarse en el manual de instalación de la aplicación).

```php
<?php
define('DBHOST', 'mi-servidor');        // Nombre del servidor de bases de datos 
define('DBUSER', 'mi-usuario');         // Usuario para ese servidor
define('DBPASS', 'mi-contraseña');      // Contraseña para ese servidor
define('DBNAME', 'mi-base-de-datos');   // Nombre de la base de datos
```

#### Plantilla de las vistas (view.php)

La plantilla de vistas y las vistas no han cambiado con respecto a la versión anterior.

```php
<?php

// PLANTILLA DE LAS VISTAS

class View {
    public static function render($nombreVista, $data = null) {
        include("views/header.php");
        include("views/nav.php");
        include("views/$nombreVista.php");
        include("views/footer.php");
    }
}
```

#### Vista "lista de libros" (views/libro/all.php)

```php
<?php
// VISTA PARA LA LISTA DE LIBROS

// Recuperamos la lista de libros
$listaLibros = $data["listaLibros"];

// Si hay algún mensaje de feedback, lo mostramos
if (isset($data["info"])) {
  echo "<div style='color:blue'>".$data["info"]."</div>";
}

if (isset($data["error"])) {
  echo "<div style='color:red'>".$data["error"]."</div>";
}

echo "<form action='index.php'>
        <input type='hidden' name='action' value='buscarLibros'>
        <input type='text' name='textoBusqueda'>
        <input type='submit' value='Buscar'>
      </form><br>";

// Ahora, la tabla con los datos de los libros
if (count($listaLibros) == 0) {
  echo "No hay datos";
} else {
  echo "<table border ='1'>";
  foreach ($listaLibros as $fila) {
    echo "<tr>";
    echo "<td>" . $fila->titulo . "</td>";
    echo "<td>" . $fila->genero . "</td>";
    echo "<td>" . $fila->numPaginas . "</td>";
    echo "<td>" . $fila->nombre . "</td>";
    echo "<td>" . $fila->apellido . "</td>";
    echo "<td><a href='index.php?action=formularioModificarLibro&idLibro=" . $fila->idLibro . "'>Modificar</a></td>";
    echo "<td><a href='index.php?action=borrarLibro&idLibro=" . $fila->idLibro . "'>Borrar</a></td>";
    echo "</tr>";
  }
  echo "</table>";
}
echo "<p><a href='index.php?action=formularioInsertarLibros'>Nuevo</a></p>";
```

#### Plantilla para inserción/modificación de libros (views/libro/form.php)

```php
<?php
// VISTA PARA INSERCIÓN/EDICIÓN DE LIBROS

extract($data);   // Extrae el contenido de $data y lo convierte en variables individuales ($libro, $todosLosAutores y $autoresLibro)

// Vamos a usar la misma vista para insertar y modificar. Para saber si hacemos una cosa u otra,
// usaremos la variable $libro: si existe, es porque estamos modificando un libro. Si no, estamos insertando uno nuevo.
if (isset($libro)) {   
    echo "<h1>Modificación de libros</h1>";
} else {
    echo "<h1>Inserción de libros</h1>";
}

// Sacamos los datos del libro (si existe) a variables individuales para mostrarlo en los inputs del formulario.
// (Si no hay libro, dejamos los campos en blanco y el formulario servirá para inserción).
$idLibro = $libro->idLibro ?? ""; 
$titulo = $libro->titulo ?? "";
$genero = $libro->genero ?? "";
$pais = $libro->pais ?? "";
$ano = $libro->ano ?? "";
$numPags = $libro->numPaginas ?? "";

// Creamos el formulario con los campos del libro
echo "<form action = 'index.php' method = 'get'>
        <input type='hidden' name='idLibro' value='".$idLibro."'>
        Título:<input type='text' name='titulo' value='".$titulo."'><br>
        Género:<input type='text' name='genero' value='".$genero."'><br>
        País:<input type='text' name='pais' value='".$pais."'><br>
        Año:<input type='text' name='ano' value='".$ano."'><br>
        Número de páginas:<input type='text' name='numPaginas' value='".$numPags."'><br>";

echo "Autores: <select name='autor[]' multiple size='3'>";
foreach ($todosLosAutores as $fila) {
    if (in_array($fila->idPersona, $autoresLibro))
        echo "<option value='$fila->idPersona' selected>$fila->nombre $fila->apellido</option>";
    else
        echo "<option value='$fila->idPersona'>$fila->nombre $fila->apellido</option>";
}
echo "</select>";

// Finalizamos el formulario
if (isset($libro)) {
    echo "  <input type='hidden' name='action' value='modificarLibro'>";
} else {
    echo "  <input type='hidden' name='action' value='insertarLibro'>";
}
echo "	<input type='submit'></form>";
echo "<p><a href='index.php'>Volver</a></p>";
```

#### Componentes de la plantilla: cabecera, menú de navegación y pie

Aquí te ofrezco unas versiones mínimas de estos componentes que aparecerán en todas las vistas. Obviamente, puedes mejorar el aspecto de tu aplicación retocándolos a tu gusto.

**views/header.php**

```php
<!DOCTYPE html>
<html lang="es">
<head>
    <meta charset="UTF-8">
</head>

<body>
    <h1>BIBLIOTECA</h1>
```

**views/nav.php**

```php
<hr/>
<nav>
    Menú de navegación: 
    <a href='index.php'>Home</a>
    <a href='index.php?action=mostrarListaLibros'>Libros</a>
    <a href='index.php?action=mostrarListaAutores'>Autores</a>
</nav>
<hr/>
```

**views/footer.php**

```php
<h5>Este es el pie de página</h5>
<h5>&copy; 2022 Yo mismo</h5>
</body>
</html>
```

### 4.5.3. Biblioteca v4

Esta última versión de la biblioteca tiene estas características:

* Arquitectura MVC
* Modelo genérico y capa de abstracción
* Controladores múltiples
* Control de acceso (login)
* Capa de seguridad

Algunos de estos componentes los vamos a desarrollar de forma muy simple (como la capa de seguridad), pero de tal manera que sea posible mejorarlos en el futuro sin que afecte al resto de la aplicación.

#### Controlador principal (index.php)

El archivo *index.php* ya no contendrá el controlador único, sino el punto de entrada a la aplicación, encargado de decidir qué controlador debe instanciarse y qué método de ese controlador debe ejecutarse.

Para eso, *index.php* debe recibir siempre dos variables por GET o POST: *controller* y *action*. La primera indicará el nombre del controlador y la segunda el nombre del método.

```php
<!-- BIBLIOTECA VERSIÓN 4 (Y ÚLTIMA)
     Características de esta versión:
       - Arquitectura MVC.
       - Modelo genérico y capa de abstracción de datos.
       - Controladores múltiples.
       - Control de acceso
       - Capa de seguridad
-->
<?php

session_start();

include_once "models/seguridad.php";

// Hacemos include de todos los controladores
foreach (glob("controllers/*.php") as $file) {
    include $file;
}

// Miramos el valor de la variable "controller", si existe. Si no, le asignamos un controlador por defecto
if (isset($_REQUEST["controller"])) {
    $controller = $_REQUEST["controller"];
} else {
    $controller = "UsuariosController";  // Controlador por defecto
}

// Miramos el valor de la variable "action", si existe. Si no, le asignamos una acción por defecto
if (isset($_REQUEST["action"])) {
    $action = $_REQUEST["action"];
} else {
    $action = "formLogin";  // Acción por defecto
}

// Creamos un objeto de tipo $controller y llamamos al método $action()
$biblio = new $controller();
$biblio->$action();
```

#### Controlador de libros (controllers/libros_controller.php)

Este controlador contiene todas las funciones que trabajan con los libros y que, en la versión 3 de la biblioteca, estaban en el controlador único.

Observa cómo TODOS los datos de entrada que se recuperan mediante *$_REQUEST[]* son ahora filtrados a través de la capa de Seguridad para evitar inyecciones de SQL, de Javascript o de cualquier otro código malicioso.

```php
<?php

// CONTROLADOR DE LIBROS
include_once("models/libro.php");  // Modelos
include_once("models/autor.php");
include_once("view.php");

class LibrosController
{
    private $db;             // Conexión con la base de datos
    private $libro, $autor;  // Modelos

    public function __construct()
    {
        $this->libro = new Libro();
        $this->autor = new Autor();
    }

    // --------------------------------- MOSTRAR LISTA DE LIBROS ----------------------------------------
    public function mostrarListaLibros()
    {
        if (Seguridad::haySesion()) {
            $data["listaLibros"] = $this->libro->getAll();
            View::render("libro/all", $data);
        } else {
            $data["error"] = "No tienes permiso para eso";
            View::render("usuario/login", $data);
        }
    }

    // --------------------------------- FORMULARIO ALTA DE LIBROS ----------------------------------------

    public function formularioInsertarLibros()
    {
        if (Seguridad::haySesion()) {
            $data["todosLosAutores"] = $this->autor->getAll();
            $data["autoresLibro"] = array();  // Array vacío (el libro aún no tiene autores asignados)
            View::render("libro/form", $data);
        } else {
            $data["error"] = "No tienes permiso para eso";
            View::render("usuario/login", $data);
        }
    }

    // --------------------------------- INSERTAR LIBROS ----------------------------------------

    public function insertarLibro()
    {
        if (Seguridad::haySesion()) {
            // Primero, recuperamos todos los datos del formulario
            $titulo = Seguridad::limpiar($_REQUEST["titulo"]);
            $genero = Seguridad::limpiar($_REQUEST["genero"]);
            $pais = Seguridad::limpiar($_REQUEST["pais"]);
            $ano = Seguridad::limpiar($_REQUEST["ano"]);
            $numPaginas = Seguridad::limpiar($_REQUEST["numPaginas"]);
            $autores = Seguridad::limpiar($_REQUEST["autor"]);

            $result = $this->libro->insert($titulo, $genero, $pais, $ano, $numPaginas);
            if ($result == 1) {
                // Si la inserción del libro ha funcionado, continuamos insertando los autores, pero
                // necesitamos conocer el id del libro que acabamos de insertar
                $idLibro = $this->libro->getMaxId();
                // Ya podemos insertar todos los autores junto con el libro en "escriben"
                $result = $this->libro->insertAutores($idLibro, $autores);
                if ($result > 0) {
                    $data["info"] = "Libro insertado con éxito";
                } else {
                    $data["error"] = "Error al insertar los autores del libro";
                }
            } else {
                // Si la inserción del libro ha fallado, mostramos mensaje de error
                $data["error"] = "Error al insertar el libro";
            }
            $data["listaLibros"] = $this->libro->getAll();
            View::render("libro/all", $data);
        } else {
            $data["error"] = "No tienes permiso para eso";
            View::render("usuario/login", $data);
        }
    }

    // --------------------------------- BORRAR LIBROS ----------------------------------------

    public function borrarLibro()
    {
        if (Seguridad::haySesion()) {
            // Recuperamos el id del libro que hay que borrar
            $idLibro = Seguridad::limpiar($_REQUEST["idLibro"]);
            // Pedimos al modelo que intente borrar el libro
            $result = $this->libro->delete($idLibro);
            // Comprobamos si el borrado ha tenido éxito
            if ($result == 0) {
                $data["error"] = "Ha ocurrido un error al borrar el libro. Por favor, inténtelo de nuevo";
            } else {
                $data["info"] = "Libro borrado con éxito";
            }
            $data["listaLibros"] = $this->libro->getAll();
            View::render("libro/all", $data);
        } else {
            $data["error"] = "No tienes permiso para eso";
            View::render("usuario/login", $data);
        }
    }

    // --------------------------------- FORMULARIO MODIFICAR LIBROS ----------------------------------------

    public function formularioModificarLibro()
    {
        if (Seguridad::haySesion()) {
            // Recuperamos los datos del libro a modificar
            $data["libro"] = $this->libro->get(Seguridad::limpiar($_REQUEST["idLibro"])[0]);
            // Renderizamos la vista de inserción de libros, pero enviándole los datos del libro recuperado.
            // Esa vista necesitará la lista de todos los autores y, además, la lista
            // de los autores de este libro en concreto.
            $data["todosLosAutores"] = $this->autor->getAll();
            $data["autoresLibro"] = $this->autor->getAutores(Seguridad::limpiar($_REQUEST["idLibro"]));
            View::render("libro/form", $data);
        } else {
            $data["error"] = "No tienes permiso para eso";
            View::render("usuario/login", $data);
        }
    }

    // --------------------------------- MODIFICAR LIBROS ----------------------------------------

    public function modificarLibro()
    {
        if (Seguridad::haySesion()) {
            // Primero, recuperamos todos los datos del formulario
            $idLibro = Seguridad::limpiar($_REQUEST["idLibro"]);
            $titulo = Seguridad::limpiar($_REQUEST["titulo"]);
            $genero = Seguridad::limpiar($_REQUEST["genero"]);
            $pais = Seguridad::limpiar($_REQUEST["pais"]);
            $ano = Seguridad::limpiar($_REQUEST["ano"]);
            $numPaginas = Seguridad::limpiar($_REQUEST["numPaginas"]);
            $autores = Seguridad::limpiar($_REQUEST["autor"]);

            // Pedimos al modelo que haga el update
            $result = $this->libro->update($idLibro, $titulo, $genero, $pais, $ano, $numPaginas);
            if ($result == 1) {
                $data["info"] = "Libro actualizado con éxito";
            } else {
                // Si la modificación del libro ha fallado, mostramos mensaje de error
                $data["error"] = "Ha ocurrido un error al modificar el libro. Por favor, inténtelo más tarde";
            }
            $data["listaLibros"] = $this->libro->getAll();
            View::render("libro/all", $data);
        } else {
            $data["error"] = "No tienes permiso para eso";
            View::render("usuario/login", $data);
        }
    }

    // --------------------------------- BUSCAR LIBROS ----------------------------------------

    public function buscarLibros()
    {
        if (Seguridad::haySesion()) {
            // Recuperamos el texto de búsqueda de la variable de formulario
            $textoBusqueda = Seguridad::limpiar($_REQUEST["textoBusqueda"]);
            // Buscamos los libros que coinciden con la búsqueda
            $data["listaLibros"] = $this->libro->search($textoBusqueda);
            $data["info"] = "Resultados de la búsqueda: <i>$textoBusqueda</i>";
            // Mostramos el resultado en la misma vista que la lista completa de libros
            View::render("libro/all", $data);
        } else {
            $data["error"] = "No tienes permiso para eso";
            View::render("usuario/login", $data);
        }
    }


    // -------- LA APLICACIÓN CONTINUARÍA DESARROLLÁNDOSE AÑADIENDO FUNCIONES AQUÍ ------------------------

} // class
```

#### Controlador de autores (controllers/autores_controller.php)

Este controlador está casi vacío porque, como en las versiones anteriores, no hemos implementado el CRUD de autores para mantener el código lo más pequeño posible. Sin embargo, hacerlo sería muy fácil, puesto que sus métodos son los mismos, o muy semejantes, que los de *LibrosController*.

```php
<?php

include_once("models/autor.php");
include_once("view.php");

class AutoresController {
        // --------------------------------- MOSTRAR LISTA DE AUTORES ----------------------------------------
        public function mostrarListaAutores() {
            // Esto está sin desarrollar aún. De momento, llamaremos a una vista inexistente.
            View::render("autor/all");
        }   
}
```

#### Controlador de usuarios (controllers/usuarios_controller.php)

Este controlador es nuevo. Se introduce para poder crear el control de acceso (pantalla de login). Paralelamente, hemos debido crear una tabla de usuarios y un modelo de usuarios (cuyo código verás más abajo).

Para este controlador no hemos implementado las funciones típicas de un CRUD (tales como *mostrarListaUsuarios()*, *insertarUsuario()*, etc), puesto que nuestra aplicación no hace nada de eso (aunque sería fácil añadirlas). En cambio, tenemos un método *formLogin()*, que muestra el formulario de login, y otro llamado *procesarLogin()* para recoger los datos de ese formulario y comprobar si el usuario y la contraseña son correctos.

```php
<?php

include_once "models/usuario.php";
include_once "models/libro.php";

class UsuariosController {

    private $usuario;

    public function __construct() {
        $this->usuario = new Usuario();
    }

    // Muestra el formulario de login
    public function formLogin() {
        View::render("usuario/login");
    }

    // Comprueba los datos de login. Si son correctos, el modelo iniciará la sesión y
    // desde aquí se redirige a otra vista. Si no, nos devuelve al formulario de login.
    public function procesarFormLogin() {
        $email = Seguridad::limpiar($_REQUEST["email"]);
        $passwd = Seguridad::limpiar($_REQUEST["password"]);
        $result = $this->usuario->login($email, $passwd);
        if ($result) { 
            header("Location: index.php?controller=LibrosController&action=mostrarListaLibros");
        } else {
            $data["error"] = "Usuario o contraseña incorrectos";
            View::render("usuario/login", $data);
        }
    }

    // Cierra la sesión y nos lleva a la vista de login
    public function cerrarSesion() {
        $this->usuario->cerrarSesion();
        $data["info"] = "Sesión cerrada con éxito";
        View::render("usuario/login", $data);
    }
 
}
```

#### Capa de seguridad (models/seguridad.php)

Hemos incluido esta clase entre los modelos, aunque, estrictamente hablando, no es un modelo convencional.

Aglutina todos los métodos relativos a la seguridad, como la creación y destrucción de sesiones o el filtrado de datos de entrada.

Hemos utilizado variables de sesión de PHP, que es la forma más simple de implementar sesiones. Recuerda que este método es inseguro. Lo bueno de mantener todos los métodos en una sola clase es que, si en algún momento queremos incrementar la seguridad de nuestra aplicación, bastará con modificar solo esta clase para lograrlo, y el resto de la aplicación ni se enterará.

```php
<?php

// CAPA DE SEGURIDAD

// Esta clase puede mejorarse indefinidamente para construir
// aplicaciones más seguras. El resto de la aplicación no sufrirá ningún cambio.

// En esta implementación, usaremos variables de sesión para la autenticación de usuarios
// y limpieza de variables sencilla basada en una lista de palabras y caracteres prohibidos. 

class Seguridad {

    // Abre una sesión y guarda el id del usuario
    public static function iniciarSesion($id) {
        $_SESSION["idUsuario"] = $id;
    }

    // Cierra una sesión y elimina el id del usuario
    public static function cerrarSesion() {
        session_destroy();
    }

    // Devuelve el id del usuario que inició la sesión
    public static function getIdUsuario() {
        if (isset($_SESSION["idUsuario"])) {
            return $_SESSION["idUsuario"];
        } else {
            return false;
        }
    }

    // Devuelve true si hay una sesión iniciada y false en caso contrario
    public static function haySesion() {
        if (isset($_SESSION["idUsuario"])) {
            return true;
        }
        else {
            return false;
        }
    }

    // Limpia un texto de caracteres o palabras sospechosas. Devuelve el texto limpio.
    public static function limpiar($text) {
        // Lista de palabras y caracteres prohibidos
        $blackList = ["<", ">", "insert", "update", "delete", "select", "*", "from"];
        foreach ($blackList as $blackWord) {
            $text = str_replace($blackWord, "", $text);
        }
        return $text;
    }
}
```

#### Modelo de libros (models/libro.php)

El modelo de libros no ha sufrido ninguna variación con respecto a la versión 3.

```php
<?php

// MODELO DE LIBROS

include_once "model.php";

class Libro extends Model
{

    // Constructor. Especifica el nombre de la tabla de la base de datos
    public function __construct()
    {
        $this->table = "libros";
        $this->idColumn = "idLibro";
        parent::__construct();
    }

    // Devuelve el último id asignado en la tabla de libros
    public function getMaxId()
    {
        $result = $this->db->dataQuery("SELECT MAX(idLibro) AS ultimoIdLibro FROM libros");
        return $result[0]->ultimoIdLibro;
    }

    // Inserta un libro. Devuelve 1 si tiene éxito o 0 si falla.
    public function insert($titulo, $genero, $pais, $ano, $numPaginas)
    {
        return $this->db->dataManipulation("INSERT INTO libros (titulo,genero,pais,ano,numPaginas) VALUES ('$titulo','$genero', '$pais', '$ano', '$numPaginas')");
    }

    // Inserta los autores de un libro. Recibe el id del libro y la lista de ids de los autores en forma de array.
    // Devuelve el número de autores insertados con éxito (0 en caso de fallo).
    public function insertAutores($idLibro, $autores)
    {
        $correctos = 0;
        foreach ($autores as $idAutor) {
            $correctos += $this->db->dataManipulation("INSERT INTO escriben(idLibro, idPersona) VALUES('$idLibro', '$idAutor')");
        }
        return $correctos;
    }

    // Actualiza un libro (todo menos sus autores). Devuelve 1 si tiene éxito y 0 en caso de fallo.
    public function update($idLibro, $titulo, $genero, $pais, $ano, $numPaginas)
    {
        $ok = $this->db->query("UPDATE libros SET
                                titulo = '$titulo',
                                genero = '$genero',
                                pais = '$pais',
                                ano = '$ano',
                                numPaginas = '$numPaginas'
                                WHERE idLibro = '$idLibro'");
        return $ok;
    }

    // Busca un texto en las tablas de libros y autores. Devuelve un array de objetos con todos los libros
    // que cumplen el criterio de búsqueda.
    public function search($textoBusqueda)
    {
        // Buscamos los libros de la biblioteca que coincidan con el texto de búsqueda
        $result = $this->db->dataQuery("SELECT * FROM libros
					                    INNER JOIN escriben ON libros.idLibro = escriben.idLibro
					                    INNER JOIN personas ON escriben.idPersona = personas.idPersona
					                    WHERE libros.titulo LIKE '%$textoBusqueda%'
					                    OR libros.genero LIKE '%$textoBusqueda%'
					                    OR personas.nombre LIKE '%$textoBusqueda%'
					                    OR personas.apellido LIKE '%$textoBusqueda%'
					                    ORDER BY libros.titulo");
        return $result;
    }
}
```

#### Modelo de personas (models/persona.php)

El modelo de personas también es el mismo que en la versión 3. Recuerda que este modelo está incompleto porque no incluye el CRUD de la tabla de *personas*, que hemos preferido no implementar para mantener la aplicación razonablemente pequeña. Sería muy fácil añadir esas funciones porque son muy parecidas a las del modelo de libros.

```php
<?php

// MODELO DE PERSONAS

include_once "model.php";

class Persona extends Model {

    // Constructor. Conecta con la base de datos.
    public function __construct() {
        $this->table = "personas";
        $this->idColumn = "idPersona";
        parent::__construct();
    }

    // Devuelve un array con los ids de los autores de un libro
    public function getAutores($idLibro) {
        // Obtenemos solo los autores del libro que estamos buscando
        $autoresLibro = $this->db->dataQuery("SELECT idPersona FROM escriben WHERE idLibro = '$idLibro'");
        // Vamos a convertir esa lista de autores del libro en un array de ids de personas
        return $autoresLibro;
    }
}
```

#### Modelo de usuarios (models/usuario.php)

Este modelo es nuevo. Lo hemos introducido para manejar la tabla de usuarios. Recuerda que no hemos hecho un CRUD de *usuarios* (aunque sería fácil programarlo), sino que nos hemos limitado a usar esta tabla para hacer el login.

Observa cómo el método *login* hace uso de la capa de seguridad para iniciar la sesión si la consulta a la base de datos tiene éxito. Ni el modelo ni ninguna otra parte de la aplicación saben cómo se inician realmente las sesiones: eso es tarea de la clase *Seguridad*.

```php
<?php

// MODELO DE USUARIOS

include_once "model.php";

class Usuario extends Model
{

    // Constructor. Especifica el nombre de la tabla de la base de datos
    public function __construct()
    {
        $this->table = "usuarios";
        $this->idColumn = "id";
        parent::__construct();
    }

    // Comprueba si $email y $passwd corresponden a un usuario registrado. Si es así, inicia usa sesión creando
    // una variable de sesión y devuelve true. Si no, de vuelve false.
    public function login($email, $passwd) {
        $result = $this->db->dataQuery("SELECT * FROM usuarios WHERE email='$email' AND password='$passwd'");
        if (count($result) == 1) {
            Seguridad::iniciarSesion($result[0]->id);
            return true;
        } else {
            return false;
        }
    }

    // Cierra una sesión (destruye variables de sesión)
    public function cerrarSesion() {
        Seguridad::cerrarSesion();
    }
}
```

#### Modelo genérico (models/model.php)

El modelo genérico del cual heredan los demás modelos (excepto *Seguridad*) no ha cambiado con respecto a la versión 3. Recuerda que podríamos intentar añadirle más métodos genéricos para insertar y modificar registros de cualquier tabla.

```php
<?php

include_once "db.php";

// MODELO GENÉRICO

class Model {

  protected $table;    // Aquí guardaremos el nombre de la tabla a la que estamos accediendo
  protected $idColumn; // Aquí guardaremos el nombre de la columna que contiene el id (por defecto, "id")
  protected $db;       // Y aquí la capa de abstracción de datos

  public function __construct()  {
    $this->db = new Db();
  }

  public function getAll() {
    $list = $this->db->dataQuery("SELECT * FROM ".$this->table);
    return $list;
  }

  public function get($id) {
    $record = $this->db->dataQuery("SELECT * FROM ".$this->table." WHERE ".$this->idColumn."= $id");
    return $record;
  } 

  public function delete($id) {
    $result = $this->db->dataManipulation("DELETE FROM ".$this->table." WHERE ".$this->idColumn." = $id");
    return $result;
  }
}
```

#### Capa de abstracción de datos (db.php)

La capa de abstracción de datos, que independiza el resto de la aplicación de la base de datos, tampoco ha cambiado desde la versión 3.

Esta capa de abstracción funciona con MySQL y MariaDB. Para otras bases de datos, habría que cambiar esta clase, pero el resto de la aplicación seguiría funcionando sin enterarse del cambio.

```php
<?php

// CAPA DE ABSTRACCIÓN DE DATOS

class Db
{

  private $db; // Aquí guardaremos la conexión con la base de datos

  /**
   * Abre la conexión con la base de datos
   * @return 0 si la conexión se realiza con normalidad y -1 en caso de error
   */
  function __construct()
  {
    // Las constantes DBSERVER, DBUSER, DBPASS y DBNAME deben estar definidas en config.php
    require_once("config.php");
    $this->db = new mysqli(DBHOST, DBUSER, DBPASS, DBNAME);
    if ($this->db->connect_errno) return -1;
    else return 0;
  }

  /**
   * Cierra la conexión con la base de datos
   */
  function close()
  {
    if ($this->db) $this->db->close();
  }

  /**
   * Lanza una consulta (SELECT) contra la base de datos.
   * ¡Ojo! Este método solo funcionará con sentencias SELECT.
   * @param $sql El código de la consulta que se quiere lanzar
   * @return Un array bidimensional con los resultados de la consulta (estará vacío si la consulta no devolvió nada)
   */
  function dataQuery($sql)
  {
    $res = $this->db->query($sql);
    // Ahora vamos a convertir el resultado en un array convencional de PHP antes de devolverlo
    $resArray = array();
    while ($fila = $res->fetch_object()) {
      $resArray[] = $fila;
    }
    return $resArray;
  }

  /**
   * Lanza una sentencia de manipulación de datos contra la base de datos.
   * ¡Ojo! Este método solo funcionará con sentencias INSERT, UPDATE, DELETE y similares.
   * @param $sql El código de la consulta que se quiere lanzar
   * @return El número de filas insertadas, modificadas o borradas por la sentencia SQL (0 si no produjo ningún efecto).
   */
  function dataManipulation($sql)
  {
    $this->db->query($sql);
    return $this->db->affected_rows;
  }
}
```

#### Archivo de configuración (config.php)

Este archivo solo define las constantes DBHOST, DBUSER, DBPASS y DBNAME para la conexión con la base de datos. Así, cuando haya que cambiarlas, solo hay que tocar este archivo (esto debería especificarse en el manual de instalación de la aplicación).

```php
<?php
define('DBHOST', 'mi-servidor');        // Nombre del servidor de bases de datos 
define('DBUSER', 'mi-usuario');         // Usuario para ese servidor
define('DBPASS', 'mi-contraseña');      // Contraseña para ese servidor
define('DBNAME', 'mi-base-de-datos');   // Nombre de la base de datos
```

#### Plantilla de las vistas (view.php)

La plantilla de vistas y las vistas no han cambiado con respecto a la versión anterior, excepto la vista *nav.php*, que ahora muestra la opción "Cerrar sesión" solo si hay una sesión abierta. Observa cómo se hace porque es una construcción bastante habitual en las vistas.

También es nueva la vista *login.php* para el formulario de login que mostramos un poco más abajo.

```php
<?php

// PLANTILLA DE LAS VISTAS

class View {
    public static function render($nombreVista, $data = null) {
        include("views/header.php");
        include("views/nav.php");
        include("views/$nombreVista.php");
        include("views/footer.php");
    }
}
```

#### Vista "lista de libros" (views/libro/all.php)

```php
<?php
// VISTA PARA LA LISTA DE LIBROS

// Recuperamos la lista de libros
$listaLibros = $data["listaLibros"];

// Si hay algún mensaje de feedback, lo mostramos
if (isset($data["info"])) {
  echo "<div style='color:blue'>".$data["info"]."</div>";
}

if (isset($data["error"])) {
  echo "<div style='color:red'>".$data["error"]."</div>";
}

echo "<form action='index.php'>
        <input type='hidden' name='action' value='buscarLibros'>
        <input type='text' name='textoBusqueda'>
        <input type='submit' value='Buscar'>
      </form><br>";

// Ahora, la tabla con los datos de los libros
if (count($listaLibros) == 0) {
  echo "No hay datos";
} else {
  echo "<table border ='1'>";
  foreach ($listaLibros as $fila) {
    echo "<tr>";
    echo "<td>" . $fila->titulo . "</td>";
    echo "<td>" . $fila->genero . "</td>";
    echo "<td>" . $fila->numPaginas . "</td>";
    echo "<td>" . $fila->nombre . "</td>";
    echo "<td>" . $fila->apellido . "</td>";
    echo "<td><a href='index.php?action=formularioModificarLibro&idLibro=" . $fila->idLibro . "'>Modificar</a></td>";
    echo "<td><a href='index.php?action=borrarLibro&idLibro=" . $fila->idLibro . "'>Borrar</a></td>";
    echo "</tr>";
  }
  echo "</table>";
}
echo "<p><a href='index.php?action=formularioInsertarLibros'>Nuevo</a></p>";
```

#### Vista para inserción/modificación de libros (views/libro/form.php)

```php
<?php
// VISTA PARA INSERCIÓN/EDICIÓN DE LIBROS

extract($data);   // Extrae el contenido de $data y lo convierte en variables individuales ($libro, $todosLosAutores y $autoresLibro)

// Vamos a usar la misma vista para insertar y modificar. Para saber si hacemos una cosa u otra,
// usaremos la variable $libro: si existe, es porque estamos modificando un libro. Si no, estamos insertando uno nuevo.
if (isset($libro)) {   
    echo "<h1>Modificación de libros</h1>";
} else {
    echo "<h1>Inserción de libros</h1>";
}

// Sacamos los datos del libro (si existe) a variables individuales para mostrarlo en los inputs del formulario.
// (Si no hay libro, dejamos los campos en blanco y el formulario servirá para inserción).
$idLibro = $libro->idLibro ?? ""; 
$titulo = $libro->titulo ?? "";
$genero = $libro->genero ?? "";
$pais = $libro->pais ?? "";
$ano = $libro->ano ?? "";
$numPags = $libro->numPaginas ?? "";

// Creamos el formulario con los campos del libro
echo "<form action = 'index.php' method = 'get'>
        <input type='hidden' name='idLibro' value='".$idLibro."'>
        Título:<input type='text' name='titulo' value='".$titulo."'><br>
        Género:<input type='text' name='genero' value='".$genero."'><br>
        País:<input type='text' name='pais' value='".$pais."'><br>
        Año:<input type='text' name='ano' value='".$ano."'><br>
        Número de páginas:<input type='text' name='numPaginas' value='".$numPags."'><br>";

echo "Autores: <select name='autor[]' multiple size='3'>";
foreach ($todosLosAutores as $fila) {
    if (in_array($fila->idPersona, $autoresLibro))
        echo "<option value='$fila->idPersona' selected>$fila->nombre $fila->apellido</option>";
    else
        echo "<option value='$fila->idPersona'>$fila->nombre $fila->apellido</option>";
}
echo "</select>";

// Finalizamos el formulario
if (isset($libro)) {
    echo "  <input type='hidden' name='action' value='modificarLibro'>";
} else {
    echo "  <input type='hidden' name='action' value='insertarLibro'>";
}
echo "	<input type='submit'></form>";
echo "<p><a href='index.php'>Volver</a></p>";
```

#### Vista para el formulario de login (views/usuario/login.php)

Esta vista es nueva. Se trata de un simple formulario con un par de mensajes optativos de información al usuario.

```php
<h1>Control de acceso</h1>

<?php
if (isset($data["error"])) {
    echo "<div style='color: red'>".$data["error"]."</div>";
}
if (isset($data["info"])) {
    echo "<div style='color: blue'>".$data["info"]."</div>";
}
?>

<form action="index.php" method="get">
    Email: <input type='text' name='email'><br/>
    Password: <input type='password' name='password'><br/>
    <input type='hidden' name='action' value='procesarFormLogin'>
    <input type='hidden' name='controller' value='UsuariosController'>
    <button type='submit'>Enviar</button>
</form>
```

#### Componentes de la plantilla: cabecera, menú de navegación y pie

Aquí te ofrezco unas versiones mínimas de estos componentes que aparecerán en todas las vistas. Obviamente, puedes mejorar el aspecto de tu aplicación retocándolos a tu gusto.

**views/header.php**

```php
<!DOCTYPE html>
<html lang="es">
<head>
    <meta charset="UTF-8">
</head>

<body>
    <h1>BIBLIOTECA</h1>
```

**views/nav.php**

Esta plantilla la hemos modificado ligeramente con respecto a la versión 3, añadiendo un enlace para cerrar la sesión que solo se verá si hay una sesión iniciada. Para ello, la vista debe recurrir a la clase *Seguridad*.

Fíjate en como se hace porque es una construcción habitual en ciertas vistas.

```php
<hr/>
<nav>
    Menú de navegación: 
    <a href='index.php'>Home</a>
    <a href='index.php?controller=LibrosController&action=mostrarListaLibros'>Libros</a>
    <a href='index.php?controller=AutoresController&action=mostrarListaAutores'>Autores</a>
    <?php
        if (Seguridad::haySesion()) {
            echo "<a href='index.php?controller=UsuariosController&action=cerrarSesion'>Cerrar sesión</a>";
        }
    ?>
</nav>
<hr/>
```

**views/footer.php**

```php
<h5>Este es el pie de página</h5>
<h5>&copy; 2022 Yo mismo</h5>
</body>
</html>
```

## 4.6. Ejercicios propuestos

Para terminar, como siempre, vamos a proponer algunos casos prácticos para que pongas manos a la obra.

Se trata de crear, paso a paso, una aplicación web de corte realista que puede ser muy útil en un lugar como un instituto, una empresa, una oficina o cualquier otra organización medianamente compleja.

Un problema que se presenta a menudo en estas organizaciones es la necesidad de compartir ciertos recursos, como proyectores, ordenadores portátiles, salas de conferencias o de exposiciones, etc.

En nuestro instituto, por ejemplo, tenemos unas hojas impresas colgadas con una chincheta en un tablón de anuncios para que el profesorado reserve los carritos con portátiles o las aulas de informática, de modo que dos personas no traten de usar a la vez el mismo recurso.

Es un método un poco primitivo (aunque eficaz, todo hay que decirlo) que se puede informatizar fácilmente mediante una aplicación web. Y eso es lo que proponemos aquí.

Se trata de **escribir una aplicación para reservar recursos** de una organización. Los recursos pueden ser de cualquier tipo (ordenadores, proyectores, espacios físicos, etc.). Los usuarios, que tendrán que estar registrados, podrán reservar cada recurso durante tramos horarios predefinidos.

Las tablas de la aplicación, por lo tanto, serán estas:

* Resources(id#, name, description, location, image) -> Los recursos que se pueden reservar
* Users(id#, username, password, realname, type) -> Los usuarios registrados
* TimeSlots(id#, dayOfWeek, startTime, endTime) -> Los tramos temporales en lo que se pueden hacer reservas
* Reservations(idResource#, idUser#, idTimeSlot#, date, remarks) -> Las reservas (remarks = comentarios)

La aplicación, una vez rellenadas con datos las tablas maestras *Resources*, *Users* y *TimeSlots*, permitirá a los usuarios registrados **reservar recursos**. Antes tendrán que autenticarse (es decir, pasar por un login). 

Para hacer una reserva, un usuario tiene que seleccionar un recurso, una fecha y un tramo horario. Si el recurso ya está reservado, no se podrá reservar por segunda vez, obviamente.

Además, habrá **usuarios de dos tipos**: 

* *Type user*: es un usuario registrado cualquiera y puede hacer reservas y ver las reservas de otras personas, pero solo puede modificar y borrar sus propias reservas.

* *Type admin*: es un usuario administrador. Puede hacer reservas y puede ver, modificar o borrar cualquier reserva de cualquier otro usuario. Además, puede hacer reservas "en bloque", es decir, puede reservar un recurso en un tramo horario durante un periodo de tiempo. Por ejemplo, puede reservar el recurso "Aula de informática" de 8:05 a 9:05 todos los lunes del primer trimestre sin necesidad de ir reservándolo día por día.

* * *

Para conseguir implementar la aplicación completa, vamos a hacerlo por pasos, de modo incremental. ¡Que cada persona llegue hasta donde buenamente pueda!

**Paso 1. Mantenimiento de la tabla Resources**

En este paso, debes crear todos los elementos necesarios para hacer el manenimiento completo de la tabla de recursos. Es decir: listado, inserción, borrado y modificación de recursos.

Hazlo exactamente en ese orden, porque he escrito las operaciones en orden de dificultad en su implementación.

Para hacerlo, necesitarás:

* El punto de entrada a la aplicación (index.php)
* El controlador de recursos (clase ResourcesController)
* El modelo de recursos (clase Resources)
* La capa de abstracción (clase Db)
* La clase vista (View)
* Una colección de vistas sencillas. Al menos dos: una para mostrar el listado de recursos y otra para el formulario de inserción y modificación (se puede reutilizar el mismo formulario para las dos cosas).

Fíjate en que puedes reutilizar gran parte del código fuente que hemos mostrado como ejemplo de MVC más arriba, con unas pocas adaptaciones.

Lo ideal es hacer que, desde la vista *showAllResources*, se pueda acceder al resto de funcionalidades relacionadas con los recursos. Es decir, esa vista quedaría algo así:

```
MANTENIMIENTO DE RECURSOS

Recurso                     Ubicación         Acciones

Impresora Láser Brother     Aula 8            Modificar | Eliminar
Carrito de portátiles A     Lab. Biología     Modificar | Eliminar
Proyector portátil          Dirección         Modificar | Eliminar
etc.

                                              Añadir nuevo
```
 
Los textos "Modificar", "Eliminar" y "Añadir nuevo" deben ser *links* que nos conduzcan de regreso a la aplicación para realizar esas acciones con los recursos.

**Paso 2. Mantenimiento de la tabla TimeSlots**

El mantenimiento de esta tabla es muy similar al de la anterior. Necesitarás un controlador nuevo y un modelo nuevo, con métodos muy parecidos a los que ya has implementado para *Resources*.

**Paso 3. Mantenimiento de la tabla Users**

Más de lo mismo. Reutiliza y adapta todo lo que puedas. Este tercer mantenimiento de tabla te debería salir con mucha más facilidad y rapidez que los dos anteriores.

**Paso 4. Menú principal**

Hasta ahora, tenemos un puñado de métodos en uno o varios controladores que se invocan pasando variables de control por la URL (algo como <code>http://mi-servidor/index.php?controller=resources&action=showAll</code>). 

En este punto, vamos a juntarlos todos en un menú principal que contendrá enlaces a todas esas URLs. Cuando añadamos más funcionalidades al programa, solo tendremos que agregarlas al menú principal.

Es decir, se trata de construir una vista *"mainMenu"* (o con el nombre que más te guste) a la que se acceda después de superar el login y que muestre algo como esto:

```
Bienvenid@, nombre-de-usuario

MENÚ DE OPCIONES

Mantenimiento de recursos
Mantenimiento de tramos horarios
Mantenimiento de usuarios
Cerrar sesión
```

Los textos "Mantenimiento de recursos", "Mantenimiento de tramos horarios", etc, deben ser *links* que nos conduzcan de regreso a la aplicación para acceder a las vistas de mantenimiento de esos elementos.

**Paso 5. Autenticación**

De momento, cualquiera puede entrar a la aplicación y añadir, modificar o eliminar registros de las tablas maestras.

Vamos a proteger el acceso al menú principal con un sistema de autenticación (login). Puedes reutilizar el código del tema anterior, cuando hablamos de las listas ACL, pero simplificando aquel código, puesto que aquí solo tenemos una tabla de usuarios registrados (nada de tablas de permisos ni roles).

No te olvides de controlar el acceso a los métodos de los controladores para que solo los usuarios debidamente autenticados puedan ejecutarlos.

**Paso 6. Reservas**

Hacer o eliminar reservas consiste, básicamente, en insertar y eliminar registros de la tabla *TimeSlots*.

Sin embargo, no es un mantenimiento como el de las otras tablas, puesto que esta tabla proviene de una relación ternaria entre tres entidades (reservas, slots y usuarios), y no es una tabla maestra como tal.

Por eso dejamos este mantenimiento de tabla para el final: porque es el más *raro* y, además, constituye la pieza principal de la aplicación: si esto no está hecho, la aplicación, simplemente, carece de su funcionalidad principal.

**Paso 7. Roles de usuario**

(Este paso es optativo)

Vamos a añadir un campo nuevo a la tabla de usuarios. Lo llamaremos *"type"*, y solo podrá contener dos valores: 0 (admin) o 1 (user). Puedes usar un VARCHAR si te sientes más cómodo/a que con códigos numéricos.

Si el usuario que entra en la aplicación es de tipo 0 (admin), tendrá acceso al menú principal y a todos los métodos de todos los controlares. Como hasta ahora, vamos.

Pero si el usuario que entra en la aplicación es de tipo 1 (user), en el menú principal solo le aparecerán las opciones de acceso a las reservas. Es decir, no podrá añadir, modificar ni eliminar usuarios, slots o recursos. Cosa que es bastante lógica, ¿no te parece?

Recuerda revisar el acceso a todos los métodos de todos los controladores para asegurarte de que un usuario de tipo 1 no entre, por ejemplo, al método para borrar recursos, ni siquiera escribiendo manualmente la URL.

**Paso 8. Otras mejoras**

(Este paso es optativo)

A la aplicación se le pueden hacer infinitas mejoras. Aquí te sugiero algunas, pero estaría bien que te sacaras otras de tu propia chistera:

* Hacer que las vistas sean visualmente atractivas con CSS y/o Javascript.
* Mostrar un calendario en el que se aprecien visualmente las reservas de una semana o de un mes. O, mejor aún, incorporar un selector para poder ver el día actual, la semana actual o el mes actual (ojo, que esto último es bastante complicadillo).
* Añadir la posibilidad de crear y anular reservas directamente desde el calendario. Observa que, así, la vista principal del usuario de tipo 1 sería el calendario, mientras que el usuario de tipo 0 seguiría accediendo al viejo menú de principal para hacer el mantenimiento completo de tablas.
* Controlar que los usuarios de tipo 1 solo puedan eliminar sus propias reservas, no las de otros usuarios. En cambio, los usuarios de tipo 0 podrán eliminar cualquier reserva.
* Eliminar automáticamente las reservas cuya fecha ya haya pasado.

**Paso 9. Enrutador**

(Este paso es optativo)

*Advertencia: ¡este paso puede resultar complicadillo!*

¿Te atreves a crear un enrutador como el de los frameworks avanzados? No es un elemento fundamental para que la aplicación web funcione, sino que tan solo sirve para construir rutas limpias.

Recuerda que el enrutador tiene que ser capaz de coger una URL limpia, como esta:

<code>
https://mi-servidor/user/show/37
</code>

...y deducir de ahí que hay que invocar el método *show(37)* del controlador de usuarios. O bien el método *showUser(37)* si tu aplicación es tan simple que solo tiene un controlador.

Debería funcionar con cualquier ruta construida de ese modo y cualquier cantidad de controladores.

A ver si se te ocurre algo para incorporar un enrutador como este a la aplicación.

(No sé si te has dado cuenta, pero, poco a poco, estamos construyendo nuestro porpio *framework* casero para programar aplicaciones MVC)