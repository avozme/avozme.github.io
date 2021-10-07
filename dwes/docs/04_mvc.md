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

#### Cuarta (y última) mejora: transformación en clases y objetos reutilizables. Código fuente definitivo

Para terminar, vamos a dejar el **código bien organizado** y a mostrarlo completo.

Lo que haremos en esta última etapa es **empaquetarlo todo en clases reutilizables**. Observa que sigue siendo el mismo código fuente, solo que empaquetado en clases y métodos. Lo único que queda fuera de una clase es la instanciación inicial del objeto controlador.

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

# 4.5. Ejercicios propuestos

Para terminar, como siempre, vamos a proponer algunos casos prácticos para que pongas manos a la obra.

Se trata de crear, paso a paso, una aplicación web de corte realista que puede ser muy útil en un lugar como un instituto, una empresa, una oficina o cualquier otra organización medianamente compleja.

Un problema que se presenta a menudo en estas organizaciones es la necesidad de compartir ciertos recursos, como proyectores, ordenadores portátiles, salas de conferencias o de exposiciones, etc.

En nuestro instituto, por ejemplo, tenemos unas hojas impresas colgadas con una chincheta en un tablón de anuncios para que el profesorado reserve los carritos con portátiles o las aulas de informática, de modo que dos personas no traten de usar a la vez el mismo recurso.

Es un método un poco primitivo (aunque eficaz, todo hay que decirlo) que se puede informatizar fácilmente mediante una aplicación web. Y eso es lo que proponemos aquí.

Se trata de **escribir una aplicación para reservar recursos** de una organización. Los recursos pueden ser de cualquier tipo (ordenadores, proyectores, espacios físicos, etc.). Los usuarios, que tendrán que estar registrados, podrán reservar cada recurso durante tramos horarios predefinidos.

Las tablas de la aplicación, por lo tanto, serán estas:

* Resources(id#, name, description, location, image) -> Los recursos que se pueden reservar
* Users(id#, username, password, realname) -> Los usuarios registrados
* TimeSlots(id#, dayOfWeek, startTime, endTime) -> Los tramos temporales en lo que se pueden hacer reservas
* Reservations(idResource#, idUser#, idTimeSlot#, date, remarks) -> Las reservas (remarks = comentarios)

La aplicación, una vez rellenadas con datos las tablas maestras *Resources*, *Users* y *TimeSlots*, permitirá a los usuarios registrados reservar recursos. Antes tendrán que autenticarse (es decir, pasar por un login). Para hacer una reserva, un usuario tiene que seleccionar un recurso, una fecha y un tramo horario. Si el recurso ya está reservado, no se podrá reservar por segunda vez, obviamente.

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