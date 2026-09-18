---
layout: page
title: 2.7 Una aplicación PHP de ejemplo
permalink: /php/aplicacion-PHP-ejemplo/
nav_order: 7
has_children: false
parent: 2 PHP como lenguaje de servidor
grand_parent: Desarrollo Web en Entorno Servidor
---

## 2.7. Una aplicación PHP de ejemplo
{: .no_toc }

- TOC
{:toc}

En esta sección vamos a ver el código fuente de una aplicación web PHP con arquitectura MVC moderna.

Será una aplicación pequeña pero 100% completa, así que lee con atención este código fuente. Si solo vas a leer una sección de este tema, probablemente esta sea la más importante.

### 2.7.1. Vamos a construir un CRUD

Vamos a hacer el **CRUD** de una tabla `articles`.

**CRUD** es el acrónimo de *Create, Read, Update, Delete* (Crear, Leer, Actualizar, Borrar). Es la forma habitual de referirse a una aplicación o fragmento de aplicación que **realiza el mantenimiento completo de una tabla de la base de datos**.

Imagínate que vamos a crear un trocito de una aplicación más grande: una tienda online. Para ser exactos, vamos ha programar la parte encargada de gestionar el *catálogo de la tienda*, es decir, los artículos que hay a la venta.

Cada artículo tendrá un *título*, una *descripción*, un *precio* y un *stock* disponible. En una tienda real habría más cosas, como varias imágenes o unos gastos de envío, pero por ahora vamos a mantenerlo lo más simple posible.

La aplicación PHP que vamos a construir va a constar de:

* Un **listado** de todos los artículos.
* Un **formulario** para crear un artículo nuevo.
* Un **formulario** para editar uno ya existente.
* Un **botón** para eliminar un artículo.

Esto es lo que hace cualquier panel de administración sobre cualquier tabla maestra. 

Vamos a construirlo **a mano, sin ningún framework**, para que veas con tus propios ojos qué es lo que hay realmente detrás del patrón MVC antes de que empecemos a usar Laravel, que automatiza casi todo lo que aquí vamos a escribir aquí.

Este es el aspecto de las carpetas y archivos que vamos a crear. Puedes comprobar que es la misma estructura de la que ya hablamos en la sección anterior, aunque hemos añadido algunas cosas más:

```
tienda-articulos/
├── composer.json
├── database.sql             ← Estructura de la base de datos
├── public/
│   ├── index.php            ← FronController y "punto de entrada" de toda la aplicación
│   └── .htaccess            ← Configuración extra para Apache (la necesitamos para enrutar)
└── src/
    ├── Config/
    │   └── Database.php     ← Conexión con la BD (lo vamos a sacar del FrontController)
    ├── Core/
    │   └── Router.php       ← Enrutador (lo vamos a sacar del FrontController)
    ├── Controllers/
    │   └── ArticleController.php
    ├── Models/
    │   └── Article.php
    └── Views/
        └── articles/
            ├── index.php
            ├── create.php
            └── edit.php
```

Iremos construyendo la aplicación «de fuera hacia dentro»: primero la base de datos, luego la estructura del proyecto y, por último, cada una de las piezas del MVC (Modelo, Vista y Controlador).

### 2.7.2. La base de datos

Antes que nada, vamos a crear la base de datos y la tabla que vamos a usar. 

Llamaremos a la base de datos `tienda`, así que **tendrás que cambiar un poco el `docker-compose.yml`** para que tu servicio de MySQL use esta base de datos por defecto.

Este sería el contenido de `database.sql`:

```sql
CREATE TABLE articles (
    id          INT AUTO_INCREMENT PRIMARY KEY,
    title       VARCHAR(150) NOT NULL,
    description TEXT NULL,
    price       DECIMAL(8,2) NOT NULL DEFAULT 0,
    stock       INT NOT NULL DEFAULT 0,
    created_at  TIMESTAMP DEFAULT CURRENT_TIMESTAMP
);

-- Puedes poner otros artículos aquí, solo son datos de prueba
INSERT INTO articles (title, description, price, stock) VALUES
('Teclado mecánico', 'Teclado mecánico retroiluminado, switches rojos', 59.99, 15),
('Ratón inalámbrico', 'Ratón óptico inalámbrico, 2.4GHz', 19.95, 40),
('Monitor 27"', 'Monitor IPS Full HD de 27 pulgadas, 75Hz', 149.00, 8);
```

Importa este archivo desde **phpMyAdmin** (lo montamos en el apartado 1.2 con Docker). O, si abres un terminal dentro del contenedor de MySQL, también puedes importarlo desde la línea de comandos de MySQL.

### 2.7.3. Estructura del proyecto

Vamos a organizar el código en carpetas **siguiendo el patrón MVC** que hemos visto, con una **capa adicional `Core` para un pequeño enrutador** que vamos a sacar del Front Controller y a ubicar en un archivo aparte.

**Primero vamos a crear el archivo `composer.json`** en la carpeta raíz del proyecto, que le dice a Composer dónde encontrar nuestras propias clases (*autoloading*):

```json
{
    "autoload": {
        "psr-4": {
            "App\\": "src/"
        }
    }
}
```

Recuerda que esto significa: *"cualquier clase cuyo namespace empiece por `App\` la vas a encontrar dentro de la carpeta `src/`"*. 

Por ejemplo, la clase `App\Models\Article` la buscará en `src/Models/Article.php`. 

Guarda el archivo `composer.json` y **genera el autoloader** con uno de estos dos comandos (como nuestra aplicación no tiene dependencias de paquetes adicionales, el segundo comando es suficiente):

```bash
$ composer install        # Genera autoloader e instala otras dependencias del proyecto
$ composer dump-autoload  # Solo genera el autoloader
```

Todo el tráfico HTTP va a entrar siempre, como ya vimos, por el **FrontController** (`public/index.php`), que decidirá, según la URL solicitada, qué código ejecutar. 

Para que esto funcione bien con un servidor Apache, **necesitamos un archivo `public/.htaccess` que redirija todas las peticiones** hacia `index.php`:

```apache
RewriteEngine On
RewriteCond %{REQUEST_FILENAME} !-f
RewriteRule ^ index.php [QSA,L]
```

No le des muchas vueltas, porque configurar Apache escapa a las pretensiones de este módulo. Si lo traducimos a español, lo que hemos ordenado a Apache es: *"si la URL solicitada no corresponde a un archivo real que exista (una imagen, un CSS...), redirige la petición a `index.php`, conservando la cadena de consulta (`QSA`) y sin seguir mirando más reglas (`L`)"*.

(Si, lo sé, la configuración de Apache parece un conjuro de magia, pero, por suerte, de esto suelen encargarse los administradores de sistemas).

### 2.7.4. Conexión a la base de datos

Esta clase se encargará de abrir la conexión con PDO y devolverla, para no repetir la conexión en cada consulta. 

Fíjate en su curioso comportamiento: la primera vez que se pide la conexión, se crea; las siguientes veces, se reutiliza la misma. **A esto se lo denomina patrón *Singleton***, que es un patrón de programación que se usa cuando quieres asegurarte de crear una sola instancia de un determinado objeto en una aplicación, como es nuestro caso. 

El patrón Singleton, que probablemente ya conozcas de Java, suele implementarse con un atributo `static`.

`src/Config/Database.php`:

```php
<?php

declare(strict_types=1);

namespace App\Config;

use PDO;
use PDOException;

class Database
{
    private static ?PDO $connection = null;   // Esta línea "huele" a Java, pero es rara, ¿verdad? Luego la explicamos

    public static function getConnection(): PDO
    {
        if (self::$connection === null) {     // self en PHP = this en Java
            $host = 'localhost';
            $dbName = 'tienda';
            $user = 'root';
            $password = '';

            $dsn = "mysql:host={$host};dbname={$dbName};charset=utf8mb4";

            try {
                self::$connection = new PDO($dsn, $user, $password, [
                    PDO::ATTR_ERRMODE            => PDO::ERRMODE_EXCEPTION,
                    PDO::ATTR_DEFAULT_FETCH_MODE => PDO::FETCH_ASSOC,
                ]);
            } catch (PDOException $e) {
                // die finaliza la ejecución bruscamente tras mostrar el mensaje error
                // (es como una "salida de emergencia" en caso de error grave)
                die('Error de conexión a la base de datos: ' . $e->getMessage());
            }
        }

        return self::$connection;
    }
}
```

Tres detalles que conviene que entiendas bien:

* `private static ?PDO $connection` dice que la variable `$connection` puede ser de tipo `PDO` pero también puede ser `null`. Es como escribir `private static Optional<PDO>`. La interrogación sustituye al `Optional`. Este tipo de declaraciones previene errores de tipo *NullPointerException*.
* `PDO::ATTR_ERRMODE => PDO::ERRMODE_EXCEPTION` le dice a PDO que, si algo falla (una consulta mal escrita, una conexión caída...), debe lanzar una excepción en lugar de devolver simplemente `false` sin más explicación. Así logramos que PHP tenga el mismo espíritu que las excepciones de Java. Pero, si lo prefieres, PHP puede ser más "silencioso" en el tratamiento de excepciones... pero entonces puede que no te enteres de qué errores de ejecución están ocurriendo.
* `PDO::ATTR_DEFAULT_FETCH_MODE => PDO::FETCH_ASSOC` hace que, cuando leamos filas de la base de datos, PDO nos las devuelva como arrays asociativos (`['id' => 1, 'title' => 'Teclado...', ...]`) en lugar de con índices numéricos (`[0 => 1, 1 => 'Teclado...', ...]`). Los arrays asociativos son mucho más legibles para esto, porque incluyen el nombre de la columna además del valor.

### 2.7.5. El modelo: la clase `Article`

El **modelo** representa tanto los datos de un artículo como las operaciones para leerlos y escribirlos en la base de datos. En una aplicación grande, muchas veces se separan estas dos responsabilidades (una clase "entidad" y otra "repositorio"), como ocurría con *JPA/Hibernate* en Java. Pero, para este primer ejemplo, las mantendremos juntas por simplicidad.

`src/Models/Article.php`:

```php
<?php

declare(strict_types=1);

namespace App\Models;

use App\Config\Database;

class Article
{
    // Constructor PHP moderno, con promoción automática de propiedades
    public function __construct(
        public int $id,
        public string $title,
        public ?string $description,
        public float $price,
        public int $stock,
    ) {
    }

    // Obtener todos los artículos
    public static function all(): array
    {
        $pdo = Database::getConnection();
        $stmt = $pdo->query('SELECT * FROM articles ORDER BY id DESC');

        $articles = [];   // Así se declara un array vacío en PHP
        foreach ($stmt->fetchAll() as $row) {
            // Esto añade un elemento a la siguiente posición del array sin necesidad
            // de manipular el índice con un contador
            $articles[] = self::fromRow($row);
        }

        return $articles;
    }

    // Obtener un artículo por id
    public static function find(int $id): ?self   // Puede devolver Article o null
    {
        $pdo = Database::getConnection();
        $stmt = $pdo->prepare('SELECT * FROM articles WHERE id = :id');
        $stmt->execute(['id' => $id]);
        $row = $stmt->fetch();

        // Operador ternario. Funciona como en Java. 
        // Si $row es false, devuelve null; si no, devuelve el resultado de self::fromRow($row)
        // (=== compara valor y tipo, == compara solo valores y convierte tipos si es necesario)
        return $row === false ? null : self::fromRow($row);
    }

    // Insertar un artículo nuevo en la BD
    public static function create(string $title, ?string $description, float $price, int $stock): void
    {
        $pdo = Database::getConnection();
        $stmt = $pdo->prepare(
            'INSERT INTO articles (title, description, price, stock)
             VALUES (:title, :description, :price, :stock)'
        );

        $stmt->execute([
            'title'       => $title,
            'description' => $description,
            'price'       => $price,
            'stock'       => $stock,
        ]);
    }

    // Actualizar un artículo existente en la BD
    public function update(): void
    {
        $pdo = Database::getConnection();
        $stmt = $pdo->prepare(
            'UPDATE articles
             SET title = :title, description = :description, price = :price, stock = :stock
             WHERE id = :id'
        );

        $stmt->execute([
            'title'       => $this->title,
            'description' => $this->description,
            'price'       => $this->price,
            'stock'       => $this->stock,
            'id'          => $this->id,
        ]);
    }

    // Borrar un artículo de la BD
    public static function delete(int $id): void
    {
        $pdo = Database::getConnection();
        $stmt = $pdo->prepare('DELETE FROM articles WHERE id = :id');
        $stmt->execute(['id' => $id]);
    }

    // Crear un nuevo objeto Article a partir de los datos contenidos en $row.
    // Es un método auxiliar para no escribir varias veces lo mismo en los métodos anteriores.
    private static function fromRow(array $row): self
    {
        return new self(
            id: (int) $row['id'],
            title: $row['title'],
            description: $row['description'],
            price: (float) $row['price'],
            stock: (int) $row['stock'],
        );
    }
}
```

Cosas que merece la pena que te pares a mirar:

* **El constructor.** `public function __construct(public int $id, public string $title, ...)` declara **y** asigna las propiedades de la clase en una sola línea, gracias a poner `public` delante de cada parámetro. En Java habrías escrito los cuatro atributos por un lado y luego, dentro del constructor, una asignación para cada uno. PHP 8 te ahorra ese código mecánico y repetitivo. Recuerda que esto se llama *promoción de propiedades en el constructor*.
* **`?string`.** Recuerda que el signo de interrogación antes de un tipo significa "este valor puede ser de este tipo, o puede ser `null`". 
* **Ninguna consulta se construye concatenando texto.** Fíjate en que en todas las consultas usamos marcadores con dos puntos (`:title`, `:id`...) y le pasamos los valores reales a `execute()` en un array. Esto es una **sentencia preparada**, y es la defensa fundamental contra los ataques de **inyección SQL** que hemos visto. 
* **`self::fromRow($row)`** es un método privado de ayuda para no repetir cinco veces el mismo código de "convertir una fila de la base de datos en un objeto `Article`".
* **Usamos `self` en lugar de `Article`**. Si te fijas en los métodos que devuelven un `Article` (como `fromRow()`), verás que hemos puesto `self` como tipo de retorno. Si hubiéramos puesto `Article`, también funcionaría, pero con `self` podemos cambiar más tarde el nombre de la clase sin tener que revisar todo el código.

### 2.7.6. El enrutador y el front controller

En **enrutador** o **router** es la parte de la aplicación que decide, según el endpoint que se haya pedido en el navegador (y el verbo HTTP que use: `GET` o `POST`, como vimos en el apartado 2.1), qué controlador y qué método se van a encargar de responder.

Por ejemplo:
* Si el endpoint es `articles/show/3`, el enrutador debe llamar al controlador de artículos (normalmente llamado `ArticleController`), al método `show()`, y pasarle como parámetro el valor `3`.
* En cambio, si el endpoint fuera algo como `clients/delete/8`, hay que llamar al `ClientController`, método `delete()`, pasándole el id `8`.

Vamos a construir un enrutador mínimo. No hace ni la mitad de cosas que el de Laravel (que veremos más adelante), pero te sirve para entender exactamente cuál es el trabajo de un enrutador. 

Por simplicidad, cuando necesitemos identificar un artículo concreto, usaremos un parámetro de consulta (`articles/show?id=3`) en lugar de un segmento dinámico en la URL (`articles/show/3`). El endpoint es mucho más feo, pero resulta igualmente funcional y para este ejemplo es suficiente.

`src/Core/Router.php`:

```php
<?php

declare(strict_types=1);

namespace App\Core;

class Router
{
    // Aquí guardaremos las rutas válidas de nuestra aplicación
    private array $routes = [];

    // Este método guarda las rutas por GET
    public function get(string $path, array $action): void
    {
        $this->routes['GET'][$path] = $action;
    }

    // Este método guarda las rutas por POST
    public function post(string $path, array $action): void
    {
        $this->routes['POST'][$path] = $action;
    }

    // Este método saca del array de rutas válidas el controlador y el método 
    // que hay que invocar para una ruta ($path) y un método ('GET' o 'POST') determinados
    public function dispatch(string $method, string $path): void
    {
        $action = $this->routes[$method][$path] ?? null;

        if ($action === null) {
            http_response_code(404);
            echo '404 - Página no encontrada';
            return;
        }

        // Extrae nombre del controlador y nombre del método
        [$controllerClass, $methodName] = $action;
        // Instancia el controlador
        $controller = new $controllerClass();
        // Invoca el método
        $controller->$methodName();
    }
}
```

Y el front controller que lo pone todo en marcha, `public/index.php`:

```php
<?php

declare(strict_types=1);

require_once __DIR__ . '/../vendor/autoload.php';

use App\Core\Router;
use App\Controllers\ArticleController;

session_start();

if (empty($_SESSION['csrf_token'])) {
    $_SESSION['csrf_token'] = bin2hex(random_bytes(32));
}

$router = new Router();

// Registramos todas las rutas o endpoints a los que va a responder nuestra aplicación,
// junto con el nombre del controlador y el nombre del método a los que corresponden.
$router->get('/articles', [ArticleController::class, 'index']);
$router->get('/articles/create', [ArticleController::class, 'create']);
$router->post('/articles', [ArticleController::class, 'store']);
$router->get('/articles/edit', [ArticleController::class, 'edit']);
$router->post('/articles/update', [ArticleController::class, 'update']);
$router->post('/articles/delete', [ArticleController::class, 'delete']);

// Descomponemos la URL de entrada para extraer controlador y métodos
$path = parse_url($_SERVER['REQUEST_URI'], PHP_URL_PATH) ?? '/';  // Saca URL
$method = $_SERVER['REQUEST_METHOD'];   // Saca verbo http (GET o POST)

// Si la URL es solo '/', saltamos a '/articles'
if ($path === '/') {
    header('Location: /articles');
    exit;
}

// Pasamos el control al enrutador para que llame al controlador y método correctos
$router->dispatch($method, $path);
```

Un par de cosas importantes:

* **`ArticleController::class`** no ejecuta nada: es solo una forma de escribir el nombre completo de la clase (con su namespace) como una cadena de texto. Equivale a `ArticleController.class.getName()` en Java.
* **`session_start()`** activa el sistema de sesiones de PHP, que vimos en el apartado 2.3. Lo llamamos una única vez, aquí, al principio de todo, antes de que se envíe ninguna salida al navegador. A partir de este momento, `$_SESSION` funciona como un almacén de datos que persiste entre peticiones distintas del mismo usuario.
* **El token CSRF** (`$_SESSION['csrf_token']`) se genera una sola vez por sesión y lo iremos incluyendo, como verás enseguida, en todos los formularios que modifiquen datos. Es nuestra defensa contra los ataques **CSRF** que vimos en el apartado 2.3.
* `parse_url()` se queda solo con la parte de la ruta (como `/articles/edit`) y descarta la cadena de consulta (como `?id=3`). Eso no significa que perdamos el `id`: PHP sigue rellenando `$_GET['id']` automáticamente a partir de la URL completa, lo usemos o no para decidir el enrutado.

### 2.7.7. El controlador: `ArticleController`

El **controlador** toma el control que le cede el **enrutador**, recoge los datos que pudieran acompañar a la petición (`$_GET` o `$_POST`), le pide al modelo lo que necesite y decide qué vista mostrar (o a qué otra URL redirigir).

Los métodos de los controladores suelen tener unos nombres casi estandarizados (aunque puede haber pequeñas variaciones o métodos adicionales que sean específicos de un controlador), así quédate con los nombres de los métodos que aparecen en `ArticleController`, porque te los vas a encontrar muuuchas veces a lo largo de este curso.

`src/Controllers/ArticleController.php`:

```php
<?php

declare(strict_types=1);

namespace App\Controllers;

use App\Models\Article;

class ArticleController
{
    // Mostrar todos los artículos
    public function index(): void
    {
        $articles = Article::all();
        // Carga la vista /Views/articles/index.php, encargada de mostrar el array $articles
        require __DIR__ . '/../Views/articles/index.php';
    }

    // Mostrar un artículo por $id
    public function show(): void
    {
        $id = (int) ($_GET['id'] ?? 0);
        $article = Article::find($id);

        if ($article === null) {
            http_response_code(404);
            echo 'Artículo no encontrado.';
            return;
        }
        // Carga la vista para mostrar artículos (show.php)
        require __DIR__ . '/../Views/articles/show.php';
    }

    // Formulario para crear un artículo
    public function create(): void
    {
        // Carga la vista con el formulario de crear artículos
        require __DIR__ . '/../Views/articles/create.php';
    }

    // Almacenar el artículo que viene del formulario de create()
    public function store(): void
    {
        $this->checkCsrfToken();

        $title = trim($_POST['title'] ?? '');
        $description = trim($_POST['description'] ?? '');
        $price = (float) ($_POST['price'] ?? 0);
        $stock = (int) ($_POST['stock'] ?? 0);

        if ($title === '') {
            $_SESSION['error'] = 'El título es obligatorio.';
            // Redirige al endpoint '/articles/create'
            header('Location: /articles/create');
            exit;
        }

        Article::create($title, $description, $price, $stock);

        $_SESSION['success'] = 'Artículo creado correctamente.';
        // Redirige al endpoint '/articles'
        header('Location: /articles');
        exit;
    }

    // Formulario para modificar un artículo
    public function edit(): void
    {
        $id = (int) ($_GET['id'] ?? 0);
        $article = Article::find($id);

        if ($article === null) {
            http_response_code(404);
            echo 'Artículo no encontrado.';
            return;
        }

        // Carga la vista con el formulario de editar artículos
        require __DIR__ . '/../Views/articles/edit.php';
    }

    // Almacenar el artículo que viene del formulario de edit()
    public function update(): void
    {
        $this->checkCsrfToken();

        $id = (int) ($_POST['id'] ?? 0);
        $article = Article::find($id);

        if ($article === null) {
            http_response_code(404);
            echo 'Artículo no encontrado.';
            return;
        }

        $article->title = trim($_POST['title'] ?? '');
        $article->description = trim($_POST['description'] ?? '');
        $article->price = (float) ($_POST['price'] ?? 0);
        $article->stock = (int) ($_POST['stock'] ?? 0);

        $article->update();

        $_SESSION['success'] = 'Artículo actualizado correctamente.';
        header('Location: /articles');
        exit;
    }

    // Borrar un artículo
    public function delete(): void
    {
        $this->checkCsrfToken();

        $id = (int) ($_POST['id'] ?? 0);
        Article::delete($id);

        $_SESSION['success'] = 'Artículo eliminado.';
        header('Location: /articles');
        exit;
    }

    // Comprobar el token CSRF. Se usa como método private auxiliar para no 
    // escribirlo varias veces a lo largo del controlador.
    private function checkCsrfToken(): void
    {
        $token = $_POST['csrf_token'] ?? '';

        if (!hash_equals($_SESSION['csrf_token'] ?? '', $token)) {
            http_response_code(419);
            die('Token CSRF inválido. Recarga la página e inténtalo de nuevo.');
        }
    }
}
```

Fíjate en varios detalles que conectan directamente con lo que vimos en apartados anteriores:

* **`$_POST['title'] ?? ''`**. En esta expresión vuelve a aparecer el operador `??`. Recuerda que significa: "si `$_POST['title']` existe y no es null, úsalo; si no, usa la cadena vacía".
* **Borrar y actualizar se hacen por `POST`, nunca por `GET`.** Esto no es casualidad: como estudiamos en el apartado 2.1, los verbos `GET` no deberían cambiar el estado del servidor. Si el botón de borrar fuera un simple enlace `<a href="/articles/delete?id=3">`, cualquier robot que rastree tu web, o el propio botón de "precargar enlaces" de algunos navegadores, podría borrarte artículos sin que nadie lo pidiera de verdad. Por eso el borrado y el update van siempre dentro de un `<form method="post">`.
* **`checkCsrfToken()`** se llama al principio de cualquier acción que modifique datos (`store`, `update`, `delete`), y compara el token que llega en el formulario con el que guardamos en la sesión, usando `hash_equals()` en lugar de un simple `==`. Usamos `hash_equals()` porque hace la comparación en un tiempo constante, evitando que un atacante pueda deducir el token comparando cuánto tarda la respuesta en llegar (lo que se conoce como un *timing attack*); es un detalle fino, pero es la forma correcta de comparar tokens secretos.
* **`header('Location: /articles'); exit;`** es cómo se hace una redirección HTTP en PHP: se manda la cabecera `Location` (recuerda las cabeceras HTTP del apartado 2.1) y cortamos la ejecución con `exit` para que no se siga procesando nada más después de la redirección.
* **`require __DIR__ . '/../Views/articles/index.php'` hace que, en ese punto, se *inyecte* el código del archivo `Views/articles/index.php`, como si estuviera escrito en este mismo script. Así es como pueden invocarse las vistas una vez preparados sus datos.

### 2.7.8. Las vistas

Las **vistas** son las responsables de generar el HTML, para:

* *Mostrar datos* al usuario.
* *Recoger datos* del usuario (con formularios, botones u otros elementos con los que interaccionar)

Las vistas no deberían decidir nada de lógica de negocio (es decir, de la lógica de la aplicación; lo de "negocio" es una traducción literal del inglés). Tampoco deberían tocar la base de datos directamente. **Se limitan a generar un HTML con los datos que el controlador les haya dado**.

A continuación te muestro cómo podrían ser las vistas de este CRUD de artículos en versión ultrasimple.

#### Vista para mostrar todos los artículos

`src/Views/articles/index.php`:

```php
<?php /** @var \App\Models\Article[] $articles */ ?>
<!DOCTYPE html>
<html lang="es">
<head>
    <meta charset="UTF-8">
    <title>Artículos</title>
</head>
<body>
    <h1>Artículos</h1>

    <?php if (!empty($_SESSION['success'])): ?>
        <p style="color: green;"><?= htmlspecialchars($_SESSION['success']) ?></p>
        <?php unset($_SESSION['success']); ?>
    <?php endif; ?>

    <?php if (!empty($_SESSION['error'])): ?>
        <p style="color: red;"><?= htmlspecialchars($_SESSION['error']) ?></p>
        <?php unset($_SESSION['error']); ?>
    <?php endif; ?>

    <p><a href="/articles/create">➕ Nuevo artículo</a></p>

    <table border="1" cellpadding="6">
        <thead>
            <tr>
                <th>ID</th>
                <th>Título</th>
                <th>Precio</th>
                <th>Stock</th>
                <th>Acciones</th>
            </tr>
        </thead>
        <tbody>
            <?php foreach ($articles as $article): ?>
                <tr>
                    <td><?= $article->id ?></td>
                    <td><?= htmlspecialchars($article->title) ?></td>
                    <td><?= number_format($article->price, 2) ?> €</td>
                    <td><?= $article->stock ?></td>
                    <td>
                        <a href="/articles/edit?id=<?= $article->id ?>">Editar</a>

                        <form action="/articles/delete" method="post" style="display:inline"
                              onsubmit="return confirm('¿Seguro que quieres eliminar este artículo?');">
                            <input type="hidden" name="id" value="<?= $article->id ?>">
                            <input type="hidden" name="csrf_token" value="<?= $_SESSION['csrf_token'] ?>">
                            <button type="submit">Eliminar</button>
                        </form>
                    </td>
                </tr>
            <?php endforeach; ?>
        </tbody>
    </table>
</body>
</html>
```

#### Vista para mostrar un solo artículo

`src/Views/articles/show.php`:

```php
<?php /** @var \App\Models\Article $article */ ?>
<!DOCTYPE html>
<html lang="es">
<head>
    <meta charset="UTF-8">
    <title><?= htmlspecialchars($article->title) ?></title>
</head>
<body>
    <h1><?= htmlspecialchars($article->title) ?></h1>

    <p><strong>ID:</strong> <?= $article->id ?></p>
    <p><strong>Precio:</strong> <?= number_format($article->price, 2) ?> €</p>
    <p><strong>Stock disponible:</strong> <?= $article->stock ?> unidades</p>

    <?php if ($article->description): ?>
        <h2>Descripción</h2>
        <p><?= htmlspecialchars($article->description) ?></p>
    <?php endif; ?>

    <hr>

    <p>
        <a href="/articles/edit?id=<?= $article->id ?>">✏️ Editar</a>

        <form action="/articles/delete" method="post" style="display:inline"
              onsubmit="return confirm('¿Seguro que quieres eliminar este artículo?');">
            <input type="hidden" name="id" value="<?= $article->id ?>">
            <input type="hidden" name="csrf_token" value="<?= $_SESSION['csrf_token'] ?>">
            <button type="submit">🗑️ Eliminar</button>
        </form>
    </p>

    <p><a href="/articles">← Volver al listado</a></p>
</body>
</html>
```

#### Vista para mostrar el formulario de creación de artículo nuevo

`src/Views/articles/create.php`:

```php
<!DOCTYPE html>
<html lang="es">
<head>
    <meta charset="UTF-8">
    <title>Nuevo artículo</title>
</head>
<body>
    <h1>Nuevo artículo</h1>

    <form action="/articles" method="post">
        <input type="hidden" name="csrf_token" value="<?= $_SESSION['csrf_token'] ?>">

        <label>Título:
            <input type="text" name="title" required>
        </label><br>

        <label>Descripción:
            <textarea name="description"></textarea>
        </label><br>

        <label>Precio:
            <input type="number" step="0.01" name="price" required>
        </label><br>

        <label>Stock:
            <input type="number" name="stock" required>
        </label><br>

        <button type="submit">Guardar</button>
    </form>

    <p><a href="/articles">← Volver al listado</a></p>
</body>
</html>
```

#### Vista para mostrar el formulario de edición de un artículo existente

(**Nota**: a menudo, se usa el mismo formulario para crear y editar elementos; aquí hemos hecho dos diferentes para no enredar más la solución)

`src/Views/articles/edit.php`:

```php
<?php /** @var \App\Models\Article $article */ ?>
<!DOCTYPE html>
<html lang="es">
<head>
    <meta charset="UTF-8">
    <title>Editar artículo</title>
</head>
<body>
    <h1>Editar artículo</h1>

    <form action="/articles/update" method="post">
        <input type="hidden" name="csrf_token" value="<?= $_SESSION['csrf_token'] ?>">
        <input type="hidden" name="id" value="<?= $article->id ?>">

        <label>Título:
            <input type="text" name="title" value="<?= htmlspecialchars($article->title) ?>" required>
        </label><br>

        <label>Descripción:
            <textarea name="description"><?= htmlspecialchars($article->description ?? '') ?></textarea>
        </label><br>

        <label>Precio:
            <input type="number" step="0.01" name="price" value="<?= $article->price ?>" required>
        </label><br>

        <label>Stock:
            <input type="number" name="stock" value="<?= $article->stock ?>" required>
        </label><br>

        <button type="submit">Actualizar</button>
    </form>

    <p><a href="/articles">← Volver al listado</a></p>
</body>
</html>
```

Un detalle que **no puedes pasar por alto**: cada vez que imprimimos en el HTML un dato que viene del usuario o de la base de datos (`$article->title`, `$article->description`...), lo envolvemos en `htmlspecialchars()`. Recuerda que esta función convierte caracteres como `<`, `>` o `"` en su equivalente de entidad HTML (`&lt;`, `&gt;`, `&quot;`), de modo que, si alguien hubiera tratado de inyectar SQL o Javascript, el navegador lo mostraría como texto literal en lugar de ejecutarlo.

Esta es una defensa básica contra **XSS** (*Cross-Site Scripting*). 

La regla general: **todo lo que salga hacia el HTML y no sea algo que haya escrito el propio programador, *tiene* que pasar por el filtro de `htmlspecialchars()`.**

### 2.7.9. Cómo probarlo tú mismo

Puedes poner en marcha esta aplicación web (técnicamente, **desplegar** esta aplicación web) en la infraestructura basada en servicios que aprendimos a montar con Docker en el tema 1:

1. Levanta la infraestructura de Apache + PHP + MySQL + PHPMyAdmin con Docker Compose. No olvides ponerle el nombre `tienda` a la base de datos en tu `docker-compose.yml`
2. Entra en PHPMyAdmin e importa `database.sql`. También puedes importarlo abriendo un terminal de texto en el contenedor de MySQL y usando la línea de comandos.
3. En la raíz del proyecto, ejecuta `composer install` para generar el autoloader.
4. Abre `http://localhost:8080` en el navegador. Deberías acabar redirigido a `http://localhost:8080/articles`, con el listado de los artículos que haya en la base de datos.

**IMPORTANTE**. Apache necesitará el módulo `mod_rewrite` activado para que el `.htaccess` funcione. Si tu Apache no lo hace, tendrás que ver cómo modificarlo para activar ese módulo. También necesitarás apuntar el `DocumentRoot` de Apache a la carpeta `public/`, nunca a la raíz del proyecto (así te aseguras de que nadie pueda acceder directamente a `src/` ni a `composer.json` desde el navegador).

### 2.7.10. Qué se queda fuera a propósito (y por qué)

Este ejemplo es deliberadamente simple y un poco artesanal. 

Estas son algunas cosas que en un proyecto real no se harían y que hemos dejado fuera a propósito para que puedas centrarte en entender los fundamentos:

* **No hay validación de errores por campo.** En una aplicación real, si el precio no es un número válido, querrías decírselo al usuario junto al campo concreto, no solo con un mensaje genérico.
* **No hay ningún ORM.** Toda consulta SQL la hemos escrito nosotros, a mano, en la clase `Article`. Herramientas como Eloquent (Laravel) o Doctrine automatizan gran parte de este código repetitivo, pero es importante que sepas escribir esas consultas por ti mismo antes de dejar que una herramienta lo haga por ti.
* **El router es extremadamente simple.** No admite parámetros dentro de la ruta (`/articles/3`), ni agrupar rutas, ni middlewares. Veremos más adelante cómo Laravel resuelve todo esto con elegancia.
* **No hay ninguna capa de autenticación.** Cualquiera que acceda a la URL puede crear, editar o borrar artículos. En una aplicación real, estas acciones estarían protegidas por un sistema de autenticación.
* **No hay plantillas o templates de vistas.** Las vistas de una aplicación suelen compartir una gran parte del código: el CSS, los scripts javascript, la cabecera, el menú de navegación, el pie, etc. Tal y como hemos construido esta solución, cada vista tiene que incluir todo eso ella misma, con lo que estamos repitiendo un montón de código. En una aplicación real, sacaríamos esos trozos repetitivos a archivos como `header.php`, `nav.php` o `footer.php` y los incluiríamos en cada vista.