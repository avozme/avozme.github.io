---
layout: page
title: 3.3 Peticiones, rutas, controladores y respuestas
permalink: /laravel/peticiones-rutas-controladores-respuestas.html
parent: 3 Aplicaciones SSR con Laravel
grand_parent: Desarrollo Web en Entorno Servidor
nav_order: 3
has_children: false
---

## 3.3. Peticiones, rutas, controladores y respuestas
{: .no_toc }

- TOC
{:toc}

Llegados a este punto, ya debes haber creado tu primera aplicación Laravel ("Hola, mundo") y habrás aprendido algo fundamental sobre el **enrutador**: cómo hacer que la solicitud de una URL termine ejecutando un método de un controlador.

En esta sección, profundizaremos en el **enrutador**, un componente fundamental de cualquier aplicación web, e introduciremos los **controladores**, que toman el control del flujo de ejecución redirigido desde el enrutador.

### 3.3.1. ¿Qué es el enrutador?

El **enrutador** de Laravel es el componente que captura los endpoints solicitados al servidor y hace 3 cosas con ellos:

1. **Los traduce a acciones**, normalmente invocaciones de métodos de los controladores.

2. **Mapea fragmentos de la URL** a variables PHP que serán inyectadas como parámetros a los métodos del controlador.

    Esto significa que, si le pides al servidor una ruta como `http://mi-servidor/user/delete/12`, el enrutador "trocea" ese endpoint para extraer los segmentos ("user", "delete" y "12"). Y tú decides qué hacer a partir de esa información.

    *(Lo normal en este ejemplo sería que invocaras el método `delete()` del controlador `UserController`, y que ese método recibiera como parámetro el dato `12`, que será el id del usuario que se pretende borrar).*

3. **Distingue el verbo http** empleado para solicitar una página al servidor. 

    Es decir, para el enrutador no es lo mismo una solicitud enviada por `GET` que otra enviada por `POST`. 
    
    Incluso admite verbos que aún no están soportados por HTML, como `DELETE` o `PUT`. Un poco más abajo explicaremos qué narices significan.

### 3.3.2. Enrutamiento básico

En la práctica guiada del "Hola, mundo" vimos que el enrutador web de Laravel está en el archivo `/routes/web.php`. 

Observa en este ejemplo `web.php` las **cuatro formas básicas** que hay de enrutar:

```php
use App\Http\Controllers\HolaController;

// Forma 1: generar la salida directamente en el enrutador, con un closure (función sin nombre)
Route::get('/hola', function() {
    return "Hola, mundo";
});

// Forma 2: llamar a una función de un controlador sin pasarle parámetros
Route::get('/hola', [HolaController::class, 'show']);

// Forma 3: llamar a una función de un controlador pasándole parámetros
Route::get('/hola/{nombre}', [HolaController::class, 'show']);

// Forma 4: llamar a una función de un controlador con un parámetro optativo
Route::get('/hola/{nombre?}', [HolaController::class, 'show']);
```

La diferencia esntre la forma 3 y la 4 es que, en la forma 3, la ruta debe llevar forzosamente un dato a continuación de `/hola` (algo como: `http://mi-servidor/hola/juan`). Si no lo lleva, el enrutador considerará que no se trata de esa ruta y seguirá buscando alguna ruta coincidente en el resto del archivo.

En cambio, en la forma 4, el dato final es optativo, así que el enrutador invocará el método `show()` del controlador tanto si ese dato aparece en la URL como si no lo hace.

Además, se puede afinar aún más qué tipo de datos nos interesa. Por ejemplo, si solo queremos entrar a `show()` cuando el `{nombre}` sea una colección de caracteres alfabéticos y no números, haríamos esto:

```php
Route::get('/hola/{nombre}', [HolaController::class, 'show'])->whereAlpha('id');;
```

Laravel 13 tiene un montón de método tipo `whereXxx()`, como `whereAlpha()`, `whereNumber()`, `whereAlphaNumeric()`, `whereUuid()`, etc.

### 3.3.3. Rutas con nombre

Es MUY recomendable **asignar un nombre a las rutas** en el enrutador. Esto hace que, más adelante, podamos cambiar la URL de los enlaces sin tener que modificar el código fuente de nuestras vistas.

El nombre se le asigna a una ruta añadiendo `->name('nombre')` al final:

```php
Route::get('/contactame', 'Controlador@contacto')->name('contact');
```

En tu código fuente, debes referirte a esta ruta siempre con la expresión `route('contact')` (ya veremos exactamente cómo se hace esto), pero el usuario verá la dirección `https://servidor/contactame`.

En el futuro se puede cambiar la forma en la que lo ve el usuario. Por ejemplo, puedes cambiar `Route::get('/contactame'...)` por `Route::get('/acerca-de'...)`, pero no tendrás que modificar ni una línea de código más en tu aplicación, porque internamente esa ruta seguirá llamándose `route('contact')`. 

### 3.3.4. Verbos http: GET, POST, PUT, PATCH y DELETE

Además de GET, en el enrutador se pueden enrutar otras acciones:

```php
Route::get();    // Solicitudes habituales
Route::post();   // Recepción de datos de formulario (para insert)
Route::put();    // Recepción de datos para update (también puede escribirse Route::patch(), que no es lo mismo, pero casi)
Route::delete(); // Recepción de datos para delete
Route::match(array('GET','POST'), 'ruta', acción)
                 // Responderá tanto a GET como a POST
```

Los verbos PUT, PATCH y DELETE no están soportados aún por HTML. Las razones por las que esto ocurre son tan confusas que, sinceramente, creo que ni siquiera en el W3C lo entienden. *La cuestión es que aún no existen y punto*.

Es decir, no puedes crear un formulario así: ```<form method='PUT'>```, porque tu navegador no lo entenderá. Solo puedes poner ```<form method='GET'>``` o ```<form method='POST'>```.

Cuando trabajes con Laravel, **debes emular PUT, PATCH o DELETE** en los formularios así:

```html
<form action="/foo/bar" method="POST">
    @method('DELETE')
```

Tal vez, llegado a este punto, te estés preguntando qué diferencia hay entre `PUT` y `PATCH`. O tal vez no. Salta a la siguiente sección si no te interesan estas sutilezas. Continúa leyendo en caso contrario.

En teoría, una petición enviada por `PUT` debería culminar con la ejecución de un `UPDATE` en el servidor que modifique *un recurso entero*. Es decir, un registro completo de una tabla de la base de datos. 

En cambio, `PATCH` debería emplearse cuando el `UPDATE` vaya a modificar solo *una parte de los campos de un registro*, y no todos.

¿Que te parece una chorrada hacer esa distinción? Bueno, lo que tú o yo opinemos no importa demasiado. Todo esto es un estándar y, por lo tanto, hay que comérselo con patatas.

### 3.3.5. Orden de las rutas

El **orden** en el que se escriben las rutas en el enrutador es importante.

Por ejemplo, si pedimos la dirección `http://mi-servidor/usuario/crear`, escribir estas dos rutas en este orden es un error:

```php
Route::get('usuario/{nombre}', [UserController::class, 'show']);
Route::get('usuario/crear', [UserController::class, 'create']);
```

El enrutador tratará de mostrar un usuario cuyo nombre sea "crear" (que seguramente no existirá) porque la petición encaja con las dos rutas y el enrutador elegirá la primera ruta que encuentre.

La solución pasa por alterar el orden de las líneas en el enrutador:

```php
Route::get('usuario/crear', [UserController::class, 'create']);
Route::get('usuario/{nombre}', [UserController::class, 'show']);
```

De este modo, la petición `http://mi-servidor/usuario/crear` seguirá encajando en las dos rutas, pero el enrutador elegirá la primera. En cambio, una petición parecida pero con cualquier otro nombre (por ejemplo, `http://mi-servidor/usuario/luis`), solo encajará con la segunda ruta.

**Recuerda: Laravel elegirá sempre la *primera ruta que coincida***.

### 3.3.6. Servidor RESTful

Un **servidor RESTful** es aquel que responde a la [arquitectura REST](https://juanda.gitbooks.io/webapps/content/api/arquitectura-api-rest.html).

La arquitectura REST no es más que una forma estandarizada de construir un servidor para que realice las tareas típicas de mantenimiento de recursos. Y los recursos pueden ser cualquier cosa que se almacene en el servidor: usuarios, clientes, productos, películas, facturas... 

Es decir: el 99% de las veces, los recursos son registros en una tabla de la base de datos.

El enrutador de un servidor RESTful contendrá las 7 operaciones habituales en la arquitectura REST para cada recurso accesible desde la red, y que permiten manipular el recurso: mostrarlo, buscarlo, insertarlo, modificarlo o borrarlo.

Por ejemplo, para un recurso llamado "user", esas 7 operaciones son:

```php
use App\Http\Controllers\UserController;

Route::get('users', [UserController::class, 'index'])->name('user.index');                // Recupera todos los usuarios
Route::get('users/{user}', [UserController::class, 'show'])->name('user.show');           // Recupera un usuario concreto con id = user
Route::get('users/crear', [UserController::class, 'create'])->name('user.create');        // Lanza el formulario de creación de usuarios
Route::post('users/{user}', [UserController::class, 'store'])->name('user.store');        // Recoge los datos del formulario y los inserta en la base de datos
Route::get('users/{user}/edit', [UserController::class, 'edit'])->name('user.edit');      // Lanza el formulario de modificación de usuarios
Route::patch('users/{user}', [UserController::class, 'update'])->name('user.update');     // Recoge los datos del formulario y modifica el usuario de la base de datos
Route::delete('users/{user}', [UserController::class, 'destroy'])->name('user.destroy');  // Elimina al usuario de la base de datos
```

Ten encuenta que, si estás construyendo un servidor RESTful, es buena práctca **respetar los nombres y URLs de las rutas**. Así, cualquier otro usuario o aplicación que use tu servidor sabrá cómo manipular los recursos sin necesidad de consultar la documentación técnica.

Laravel te permite **generar automáticamente las 7 rutas REST** anteriores con esta única entrada en el enrutador:

```php
use App\Http\Controllers\UserController;

Route::resource('users', UserController::class);
```


### 3.3.7. Los controladores en Laravel. Responses

Los controladores, como ya sabemos, son las clases que **toman el control** de la aplicación una vez que el enrutador redirige el flujo de ejecución.

En esta sección vamos a ver cómo se crean en Laravel.

1. Los **controladores** en Laravel **heredan de la clase `Controller`**.

   ```php
   class MiControlador extends Controller {
      ...
   }
   ```

2. Su nombre debería escribirse en singular, CamelCase y terminando en la palabra Controller. Por ejemplo: `UserController`, `LoginController`, `ArticleController`...

3. **Cada método del controlador terminar con un `return` de algo que pueda enviarse al cliente**. Los casos más habituales son:

   * **Devolver un string** -> Laravel lo convertirá automáticamente en una `HTTP response 200` y lo devolverá como una página web.
   * **Devolver un array** u otra estructura de datos compleja -> Laravel lo convertirá en `JSON` y enviará al cliente esos datos.
   * **Devolver una vista** (`return view('nombre-vista')` -> Laravel renderiza la vista y devuelve el HTML al cliente (ya veremos cómo funcionan las vistas).
   * **Devolver una redirección** (`return redirect('/products');`) -> Laravel devuelve una respuesta HTTP de redirección y el navegador realiza una nueva petición a la dirección indicada.
   * **Devolver un JSON explícito** (por ejemplo: `return response()->json(['nombre' => 'Juan', 'edad' => 25]);)`
   * **Devolver una respuesta HTTP personalizada**. Por ejemplo:

    ```php
        return response('contenido', 201)
                ->header('mi-cabecera', 'contenido')
                ->header('otra-cabecera', 'más-contenido')
                ->cookie('mi-cookie', 'valor');
                (etc)
    ```

### 3.3.8. Datos de entrada al controlador: Requests

Al controlador pueden llegar **datos procedentes de un formulario**. Aunque siguen existiendo las variables `$_GET` y `$_POST` de PHP, lo recomendable en Laravel es usar el objeto `Request`.

Obsérvalo en acción en este pequeño ejemplo:

```php
use Illuminate\Http\Request;

public function store(Request $request)
{
    $nombre = $request->input('nombre');

    // ...
}
```

El objeto `Request` **se inyecta como parámetro** en cualquier método del controlador que necesite hacer uso de él y, a partir de ahí, puedes acceder a los campos del formulario con:

* `$request->input('nombre')` -> para recuperar un input de texto llamado `nombre`.
* `$request->all()` -> para recuperar todos los inputs a la vez en forma de array.
* `$request->has('nombre')` -> para comprobar si entre los datos existe uno llamado `nombre` (devuelve `true`o `false`).
* (Hay más métodos, pero con estos vamos bien por ahora).

### 3.3.9. Tres formas de crear un controlador

Los controladores se pueden crear a mano: vas al directorio `/app/http/controllers`, creas allí un archivo vacío y empiezas a escribir código como una fiera.

Pero nadie lo hace así porque **Artisan** ya crea el esqueleto del archivo por ti. Así que es mejor que vayas a lo práctico: abre una consola en tu servidor web y ponte a escribir.

* **Forma 1. Crear un controlador vacío.**

    Por ejemplo, para crear un controlador para la tabla de usuarios:

    ```
    $ ./vendor/bin/sail php artisan make:controller UserController
    ```

* **Forma 2. Crear un controlador de tipo resource.**

    Estos controladores se generan automáticamente con un andamiaje para **construir recursos REST**. Es decir, la clase ya llevará incorporados los métodos estándar `index()`, `create()`, `store()`, `show()`, `edit()`, `update()` y `destroy()` de REST.

    (Si no sabes de qué estamos hablando, revisa la sección que dedicamos al RESTful un poco más arriba)

    Para crear un controlador RESTful:

    ```
    $ ./vendor/bin/sail php artisan make:controller UserController --resource
    ```

    No te olvides de añadir al enrutador (`/routes/web.php`) las rutas REST para este tipo controlador. Te recuerdo que se pueden resumir las siete rutas en esta sola entrada del enrutador:

    ```
    Route::resource('nombreRecurso', Controlador::class);
    ```

    En nuestro ejemplo:

    ```
    use App\Http\Controllers\UserController;

    Route::resource('usuarios', UserController::class);
    ```

* **Forma 3. Crear un controlador tipo API.**

    Una **API** (*Application Programming Interface*) es un interfaz entre programas. Es decir, es la forma en la que unos programas interaccionan con otros.

    Algunas aplicaciones web se diseñan para que otros programas las utilicen, no para que las utilicen seres humanos. En estos casos, el interfaz de usuario no existe (o es mínimo) y lo importante es el API. Y los métodos del controlador no devuelven vistas, sino datos formateados en JSON.

    Se puede construir con Laravel un controlador tipo API de forma muy simple, porque es parecido a un *resource*, pero sin `create()` ni `edit()`, porque una API no necesita mostrar los formularios de inserción/modificación.

    ```
    $ ./vendor/bin/sail php artisan make:controller UserController --api
    ```

    De nuevo, no te olvides de las entradas en el enrutador. Puedes englobarlas todas en una sola entrada con este aspecto:

    ```
    use App\Http\Controllers\UserController;

    Route::apiResource('usuarios', UserController::class);
    ```

    Construiremos APIs con Laravel en el próximo tema.

### 3.3.10. Práctica de rutas y controladores

En esta pequeña práctica vamos a aplicar lo que hemos aprendido sobre **rutas, verbos HTTP y controladores**, creando un controlador de tipo `resource` para gestionar un recurso llamado `products`. 

Todavía no será una aplicación "usable" (eso lo haremos al final del tema), pero se acercará bastante.

*La práctica está pensada para trabajar con la infraestructura Docker + Laravel Sail que ya conoces.*

#### Al terminar la práctica...

Si terminas esta práctica con éxito serás capaz de:

- Crear controladores.
- Registrar las rutas REST de un recurso.
- Identificar qué URL y qué verbo HTTP corresponden a cada método del controlador.
- Consultar las rutas disponibles mediante `route:list`.
- Realizar redirecciones mediante `redirect()`.


---

#### PASO 1. Crear el controlador tipo `resource`

1. Crea un controlador de tipo `resource`:

    ```bash
    $ ./vendor/bin/sail artisan make:controller ProductController --resource
    ```

    Laravel creará el archivo `app/Http/Controllers/ProductController.php` 

2. Abre el archivo. Si todo ha ido bien, deberías encontrar los siete métodos habituales de un controlador REST, es decir, `index()`, `create()`, `store()`, `show()`, `edit()`, `update()` y `destroy()`

    De momento vamos a dejar esos métodos vacíos. Tú solo comprueba que se han creado.


#### PASO 2. Registrar las rutas resource

1. Abre `routes/web.php`

2. Añade la importación del controlador y registra las siete rutas con una única instrucción:

    ```php
    // Esto importa el controlador:
    use App\Http\Controllers\ProductController;

    // Esto añade las 7 rutas típicas REST en una sola línea
    Route::resource('products', ProductController::class);
    ```

3. Comprueba que las rutas se han registrado tecleando en el terminal de texto:

    ```bash
    $ ./vendor/bin/sail artisan route:list
    ```

    Deberías ver las siete rutas REST de `products`, más las que creamos el otro día para el "Hola mundo". Observa que **dos rutas utilizan el mismo endpoint ()`/products`)**, pero que una lo hace por `GET` y otra por `POST`. Así es como el servidor las distingue:

    **Si las 7 rutas recién añadidas no aparecen** puede ser necesario limpiar la caché de rutas, una memoria caché que Laravel usa para acelerar la ejecución.

    ```bash
    $ ./vendor/bin/sail artisan route:clear   # Con esto limpias la caché de rutas
    $ ./vendor/bin/sail artisan route:list    # Luego vuelve a probar a sacar el listado
    ```

    **¡No continúes hasta que tus 7 rutas REST aparezcan en el listado!**.

#### PASO 3. Implementar respuestas sencillas

Vamos a crear una **respuesta temporal de texto simple** en los métodos del controlador. Más adelante aprenderemos a consultar la base de datos y crear las respuestas adecuadas.

Edita el archivo `app/Http/Controllers/ProductController.php` y añade un `return` de texto simple a cada método:

```php
    public function index()
    {
        return 'Aquí aparecerá el listado de todos los productos de la BD';
    }
    public function create()
    {
        return 'Aquí se mostrará el formulario para crear un producto nuevo';
    }
    public function store(Request $request)
    {
        return 'Aquí estaría el código para almacenar el producto de create() en la BD';
    }
    public function show(string $id)
    {
        return "Aquí se mostraría el producto con id = $id";
    }
    // Continúa tú con el resto de métodos (¿sabes ya lo que hace cada método REST?)
    // (Si no es así, ¡repasa el tema o pregunta!)
```

#### PASO 4. Comprobar los nombres de las rutas

Prueba en tu navegador web los métodos del controlador.

* Para probar `ProductController::index()`, escribe el endpoint `http://localhost/products`.
* Para probar `ProductController::create()`, escribe el endpoint `http://localhost/products/create`.
* Para probar `ProductController::show()`, escribe el endpoint `http://localhost/products/id`, donde `id` sea el ID del producto que quieres mostrar.
* ¿Qué endpoint debes usar para probar el resto de rutas? ¿Hay alguna ruta que no puedas probar directamente desde tu navegador web? ¿Por qué?

    (**Asegúrate de que sabes contestar a estas preguntas antes de continuar**; si no lo sabes, ¡averígualo!)

#### PASO 5. Probar una redirección

1. Añade esta ruta a `routes/web.php` (solo para probar una redirección, no tiene utilidad real):

    ```php
    Route::get('/ir-a-productos', function () {
        return redirect()->route('products.index');
    });
    ```

2. Pruébala visitando `http://localhost/ir-a-productos`. Debería llevarte a `/products`.
3. Añade un método a tu controlador `ProductController.php` que haga lo mismo, es decir, `return redirect()->route('products.index');`.
4. Modifica la ruta anterior `/ir-a-productos` para que te lleve al método que acabas de crear en el controlador, en lugar de ejecutar la redirección desde el propio enrutador.

    ¡Como en otros ejercicios, aunque de momento solo estamos "jugando", no continúes si algo no te funciona o no lo entiendes!
