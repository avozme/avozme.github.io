---
layout: page
title: 2.2 PHP moderno
permalink: /php/moderno/
nav_order: 2
has_children: false
parent: 2 PHP como lenguaje de servidor
grand_parent: Desarrollo Web en Entorno Servidor
---

## 2.2. PHP moderno
{: .no_toc }

- TOC
{:toc}

Quizá hayas oído que PHP es un lenguaje desordenado, sin tipos y un poco caótico. Eso era cierto hace 15 años. Hoy en día, a partir de PHP 7 y sobre todo con **PHP 8**, el lenguaje se ha transformado en una herramienta robusta, orientada a objetos, con tipado estricto y un ecosistema profesional.

Como ya sabes programar, no te contaremos qué es un `if` o cómo hacer un bucle `for` (funcionan exactamente en Java y en PHP). En la siguientes secciones vamos a ver cómo es PHP y que hace que el PHP moderno sea... eso, moderno.

### 2.2.1. Diferencias de PHP con respecto a Java

Empecemos con lo básico. Si vienes de Java, esta es una buena forma de saber a que "huele" PHP.

PHP y Java derivan de C++, así que su sintaxis es semejante (podríamos decir que son "primos"). Por eso, si sabes programar en Java, saltar a PHP es muy sencillo.

Pero existen ciertas diferencias importantes. A continuación te resumo las principales:

| En Java... | En PHP... |
|---|---|
| Las variables se declaran con un tipo (`String nombre;`) | Las variables empiezan siempre por `$` y, por defecto, no necesitan tipo (`$nombre`). PHP 8 te permite añadir tipos en parámetros, propiedades y retornos, y está fuertemente recomendado hacerlo en proyectos grandes. Si encabezas el programa con la línea `declare(strict_types=1)`, PHP te obligará a declarar los tipos. |
| Un programa tiene un método `public static void main()` como punto de entrada | Un script PHP se ejecuta de arriba abajo en cuanto se carga. No hay un "main": el archivo `public/index.php` hace ese papel, como verás enseguida. |
| `package com.miapp.modelos;` y `import com.miapp.modelos.Articulo;` | `namespace App\Models;` y `use App\Models\Article;`. Es exactamente la misma idea, con otra sintaxis. |
| El *classpath* y Maven o Gradle resuelven qué archivo `.class` corresponde a cada clase | **Composer** hace ese trabajo mediante el llamado autoload PSR-4: le dices "las clases del namespace `App\` están en la carpeta `src/`" y él se encarga de cargar el archivo correcto cuando lo necesites. |
| `ArrayList<String>` para listas, `HashMap<String, Object>` para diccionarios | Un único tipo, el **array**, hace de las dos cosas. `$colores = ['rojo', 'verde'];` es una lista; `$persona = ['nombre' => 'Ana', 'edad' => 20];` es un diccionario (aquí lo llamamos *array asociativo*). |
| Los datos de una petición HTTP llegan en un objeto `HttpServletRequest`, con métodos como `request.getParameter("nombre")` | PHP te los deja directamente en variables globales con forma de array asociativo, llamadas **superglobales**: `$_GET`, `$_POST`, `$_SESSION`, `$_SERVER`... Por ejemplo, `$_POST['title']` es el equivalente a `request.getParameter("title")`. |
| **JDBC**: `Connection`, `PreparedStatement`, `stmt.setString(1, valor)`, `stmt.executeQuery()` | **PDO** (*PHP Data Objects*): un objeto `PDO` es tu `Connection`, y `$pdo->prepare()` te da un objeto equivalente a `PreparedStatement`. La diferencia más cómoda: en vez de encadenar un `setXxx()` por cada parámetro, en PDO se los pasas todos juntos en un array a `execute()`. |
| Declaras un campo y luego lo asignas en el constructor (`this.titulo = titulo;`) | PHP 8 permite hacer las dos cosas en una sola línea, escribiendo el tipo de visibilidad delante del parámetro del constructor. Lo verás en la clase `Article`, y es una de las cosas que más se agradecen viniendo de Java. |
| El código se compila a bytecode antes de ejecutarse | PHP es un lenguaje interpretado: guardas el archivo `.php`, recargas la página en el navegador, y el servidor lo interpreta en ese mismo instante. No hay paso de compilación. |

**IMPORTANTE:** Para usar PHP en un entorno Web, el código PHP debe ir precedido de la marca `<?php`. ¡Si no, el servidor web creerá que estás escribiendo HTML, aunque la extensión del archivo sea `.php`! 

Y si necesitas intercalar PHP con HTML en el mismo archivo (una mala práctica que a veces es inevitable), puedes cerrar PHP con `?>`:

```php
<!-- Esto es código HTML convencional -->
<h1>Hola mundo</h1>
<?php
   // A partir de aquí empieza PHP
   echo "<p>Esto lo ha generado PHP</p>";
?>
<!-- Aquí ha terminado PHP y continúa HTML -->
<p>Esto lo ha generado HTML</p>
```

### 2.2.2. Tipado estricto en PHP8 (Strict Types)

Por defecto, PHP es un lenguaje de tipado débil. 

Esto significa que, si sumas el número `5` a la cadena `"10"`, PHP se encoge de hombros, convierte la cadena en un número y te devuelve `15`. 

¡Pero en proyectos grandes, esta característica se convierte en una pesadilla de depuración!

Para **obligar a PHP a comportarse como un lenguaje de tipado fuerte** (donde sumar un int y un string te lance un error), **siempre** debes poner esta línea al principio de todos tus archivos PHP, justo después de `<?php`:

```php
<?php
declare(strict_types=1);

function sumar(int $a, int $b): int {
    return $a + $b;
}

echo sumar(5, 10);   // Funciona: 15
echo sumar(5, "10"); // FATAL ERROR: TypeError
```

Fíjate en la firma de la función: hemos definido el tipo de los parámetros (`int`) y el tipo del valor de retorno (`: int`). Acostúmbrate a hacerlo **siempre**.

#### Union Types y Nullable Types
En PHP 8 podemos decir que una variable puede ser de más de un tipo, o que puede ser nula (usando el símbolo `?`):

```php
function buscarUsuario(int $id): ?string {
    // Retorna un string si lo encuentra, o null si no.
}

function procesarDato(int|string|float $dato): void {
    // $dato puede ser entero, cadena o decimal. "void" significa que no devuelve nada, como en Java.
}
```

### 2.2.3. Programación orientada a objetos moderna con PHP

La POO en PHP es prácticamente idéntica a Java: usamos `class`, `interface`, herencia de clases e interfaces, `extends` para clases derivadas, etc.

Una de las grandes mejoras de PHP 8 es la **promoción de propiedades del constructor** (Constructor Property Promotion). Antes, para crear una clase con atributos, tenías que escribir mucho código repetitivo. Ahora es así de limpio:

```php
<?php
declare(strict_types=1);

class Usuario {
    // PHP define automáticamente las propiedades privadas y las asigna en el constructor.
    public function __construct(
        private int $id,
        private string $nombre,
        private string $email
    ) {}

    public function getNombre(): string {
        return $this->nombre;
    }
}

$user = new Usuario(1, "Ana", "ana@ejemplo.com");
```

Fíjate que cómodo es: PHP *definirá por ti* las propiedades privadas `$id`, `$nombre` y `$email` y las inicializará en el constructor.

### 2.2.4. Namespaces (Espacios de nombres)

En un proyecto real pueden existir literalmente CIENTOS de clases. ¿Qué pasa si tú creas una clase llamada `Database` y descargas una librería que también tiene una clase llamada `Database`? 

Lo has adivinado: **el código explota**.

Para evitarlo, se inventaron los **Namespaces**. Son como los "paquetes" (packages) de Java. Te permiten agrupar tus clases en carpetas lógicas.

```php
<?php
// Archivo: src/Controllers/UserController.php
namespace App\Controllers; // Este es nuestro "paquete"

use App\Models\User; // Importamos la clase User de otro namespace (equivalente a "import" en Java)

class UserController {
    public function mostrar(int $id): void {
        $usuario = new User($id); // Instanciamos la clase importada
    }
}
```

### 2.2.5. Composer: el gestor de dependencias

Si en Java tienes Maven o Gradle, y en Node.js tienes NPM, en PHP el gestor de dependencias indiscutible es **Composer**.

Composer hace dos cosas fundamentales:
1. **Descargar librerías de terceros** (desde [Packagist.org](https://packagist.org/)) y mantenerlas actualizadas.
2. **Autoloading (Carga automática de clases)**: Olvídate de escribir `require` o `include` en cada archivo, Composer se encarga por ti.

Para iniciar un proyecto con Composer, abres la terminal en tu carpeta y escribes:
```bash
composer init
```
Esto te generará un archivo `composer.json`. Ahí se configura el Autoloading para que Composer pueda localizar y cargar automáticamente las clases.

Por ejemplo,  que básicamente le dice a PHP: *"Oye, cuando veas que uso una clase del namespace `App\`, búscalo en la carpeta `src/`"*.

```json
{
    "autoload": {
        "psr-4": {
            "App\\": "src/"
        }
    }
    "require": {
       "monolog/monolog": "^3.0"
    }    
}
```

* En la parte "autoload" se indican las clases de nuestro propio proyecto que queremos que se autocarguen (Lo de "psr-4" es un estándar de autoloading y hay que ponerlo siempre como lo ves aquí).
* En la parte "require" sin indican librerías de terceros que queremos que Composer busque y descargue. Al poner "^3.0" decimos que queremos la verión 3.0 de la librería "monolog" o una versión superior.

Después, ejecutas `composer dump-autoload`, y en tu archivo `index.php` principal (tu Front Controller) solo tienes que poner una línea:

```php
<?php
require __DIR__ . '/vendor/autoload.php';

// ¡A partir de aquí, puedes usar cualquier clase de tu proyecto sin hacer más includes!
// Por ejemplo:
$app = new \App\Controllers\HomeController();
```

