---
layout: page
title: 3.8 Sesiones, autenticación y middlewares
permalink: /laravel/sesiones-autenticacion.html
parent: 3 Aplicaciones SSR con Laravel
grand_parent: Desarrollo Web en Entorno Servidor
nav_order: 8
has_children: false
---

## 3.8. Sesiones, autenticación y middlewares
{: .no_toc }

- TOC
{:toc}

Como es lógico, Laravel también proporciona su propio sistema de manejo de **variables de sesión**, es decir, variables persistentes en el servidor asociadas a cada cliente.

Las variables de sesión de Laravel son mucho más seguras y poderosas que las variables de sesión estándar de PHP. En esta sección vamos a ver cómo funcionan y qué posibilidades nos ofrecen las sesiones en Laravel. También veremos cómo construir un robusto sistema de **autenticación de usuarios** con muy poco trabajo y qué son y qué papel juegan los **middlewares** en todo esto.

### 3.8.1. Drivers de sesión

Las sesiones de configuran en *`/config/sessions.php`*, y una de las cosas que debes configurar ahí es el **driver** de sesión, es decir, el tipo de manejador que quieres que manipule las sesiones.

* ***Database***:
   
   En las últimas versiones de Laravel (a partir de la v11), el driver por defecto suele ser ***database***. Laravel almacenará las sesiones de los usuarios en la tabla `sessions` de tu base de datos. Es seguro, escalable y muy recomendable.

* ***Files***:

   Tradicionalmente fue el driver por defecto. Laravel guardará las variables de sesión en ficheros especiales en el servidor (que nosotros no tenemos que manejar). Es sencillo pero menos escalable que la base de datos.

* ***Memcached*** y ***Redis***:
   
   Para aplicaciones en producción con muchísima carga, Laravel recomienda usar ***memcached*** o ***redis*** porque son extremadamente rápidos guardando las sesiones en memoria RAM. Ambos son *daemons* del sistema, lo que significa que el servidor debe soportarlos para que puedas usarlos.

Una vez elegido del driver, si el servidor lo soporta, no tienes que hacer nada más en especial: desde el punto de vista del programador, todos se manejan exactamente igual, porque Laravel hará todo el trabajo específico con el driver por ti.

### 3.8.2. Persistencia de las variables de sesión

Laravel maneja dos tipos de variable según su persistencia:

* **Variables flash**: solo duran una petición y luego desaparecen.
* **Variables de sesión convencionales**: existen hasta que las destruimos expresamente.

#### Variables flash

Son variables de sesión que solo duran una petición y luego se *autodestruyen*. Se usan típicamente para enviar un *feedback* o mensaje de retroalimentación al usuario.

Te lo muestro con un ejemplo. Imagina el típico formulario de *login*. En caso de producirse un error, lo habitual es que la aplicación nos muestre de nuevo ese formulario con un mensaje del tipo de "Usuario no reconocido". 

Para lograr eso, haríamos lo siguiente en el controlador. Observa el uso del **método `*with()*`** para crear una variable flash de sesión llamada *mensaje*:

```php
    return ('login/form')->with('mensaje', 'Usuario no reconocido');
```

En la vista, podemos acceder a esa variable flash. Por ejemplo, así:

```php
    @if (session('mensaje'))
        {% raw %}{{ session('mensaje'); }}{% endraw %}
    @endif
```

A partir de este momento, la variable flash se destruye y cualquier intento de acceder a ella provocará un error de ejecución.

#### Variables de sesión convencionales

Las variables de sesión convencionales se manejan con la **clase *Session***, que tiene un montón de métodos estáticos para crear variables, destruirlas, consultarlas, etc.

Los métodos más útiles son:

* **put()** -> almacena una variable de sesión:

   ```php
      Session::put('nombre-variable', 'valor');
   ```

* **push()** -> elimina una variable de sesión:

   ```php
      Session::push('nombre-variable');
   ```

* **get()** -> devuelve el valor de una variable de sesión:

   ```php
      $v = Session::get('nombre-variable');
      $v = Session::get('nombre-variable', 'valor-por-defecto');
   ```

* **all()** -> devuelve todas las variables de sesión en un array:

   ```php
      $a = Session::all('nombre-variable', 'valor');
   ```

* **flush()** -> elimina todas las variables de sesión:

   ```php
      Session::flush();
   ```

* **flash()** -> crea manualmente una variable de sesión de tipo flash:

   ```php
      Session::flash('nombre-variable', 'valor');
   ```

### 3.8.3. Autenticación

La autenticación de usuarios, es decir, el sistema de *login* seguido de la creación de una o varias variables de sesión asociadas al usuario, es un componente habitual de muchas aplicaciones web.

Actualmente, Laravel proporciona los denominados *Starter Kits*, que son componentes que se pueden instalar para delegar todo este trabajo y no tener que programar nosotros mismos el formulario de login, el registro, la seguridad, etc.

Para la autenticación, Laravel dispone de varios *Starter Kits*. El más simple y recomendado oficialmente para empezar en Laravel 13 sigue siendo **Laravel Breeze**.

### 3.8.4. El Starter Kit más simple: Laravel Breeze

***Laravel Breeze*** contiene el código mínimo necesario para crear un sistema de autenticación completo y seguro (login, registro, reseteo de contraseñas, etc.) usando Blade de forma muy sencilla.

Para **instalar el Starter Kit**, abre un terminal (si usas Sail, recuerda añadir `./vendor/bin/sail` delante de `artisan` y `npm`):

```bash
$ composer require laravel/breeze --dev
$ ./vendor/bin/sail artisan breeze:install blade
$ ./vendor/bin/sail artisan migrate
$ ./vendor/bin/sail npm install
$ ./vendor/bin/sail npm run build
```

Estos comandos instalarán la librería, publicarán las vistas y controladores básicos de autenticación en tu proyecto y actualizarán la base de datos. No hace falta complicarse más, Breeze hará todo el trabajo pesado.

Una vez hecho esto, Breeze creará automáticamente el archivo de rutas `routes/auth.php` y varias vistas en `resources/views/auth/`. Puedes probar directamente visitando `/login` y `/register` en tu navegador. Ya tienes un sistema de usuarios funcional y seguro.

### 3.8.5. Autenticación y vistas: cómo generar código dependiendo del tipo de usuario

En las vistas, tenemos un par de directivas de Blade muy útiles relacionadas con las sesiones: ***@auth*** y ***@guest***. Puedes ver cómo funcionan en este ejemplo:

```html
@auth
    <p>Bienvenido, {% raw %}{{ Auth::user()->name }}{% endraw %}</p>
    <!-- Este código solo se renderiza si hay un usuario logueado -->
@endauth

@guest
    <p>Por favor, identifícate.</p>
    <a href="{% raw %}{{ route('login') }}{% endraw %}">Login</a>
    <!-- Este código solo se renderiza si NO hay sesión -->
@endguest
```

Además, podemos acceder a los datos del usuario mediante la clase `Auth`:

```php
$user = Auth::user(); // Devuelve el usuario actualmente logueado o null si no hay sesión
if (Auth::check()) {  // Devuelve true si el usuario actual está logueado
   // ...
}
```

(Más métodos de Auth en [la documentación oficial](https://laravel.com/docs/authentication))

### 3.8.6. Diferencia entre Autenticación y Autorización

Es fundamental no confundir estos dos conceptos:
- **Autenticación (Authentication)**: Es el proceso de verificar **quién eres**. (Ej: Hacer login con usuario y contraseña).
- **Autorización (Authorization)**: Es el proceso de verificar **qué puedes hacer**. (Ej: ¿Este usuario autenticado tiene permisos para borrar este producto concreto? ¿Es administrador?).

En esta sección nos estamos centrando en la Autenticación. La Autorización en Laravel se maneja usando *Gates* y *Policies*, que son mecanismos para proteger acciones concretas.

### 3.8.7. Autenticación y middlewares: cómo proteger las rutas

Los **middlewares** de Laravel son componentes que capturan y filtran todas las peticiones HTTP que llegan a la aplicación (literalmente, se ponen *en medio*).

Para proteger partes de tu aplicación y exigir que el usuario haya hecho login, Laravel nos proporciona el middleware integrado ***auth***.

La forma moderna y recomendada de aplicarlo es directamente en el archivo de rutas (`routes/web.php`):

```php
// Proteger una ruta individual
Route::get('/ruta-privada', [MiControlador::class, 'metodo'])->middleware('auth');

// Proteger un grupo de rutas (muy común para recursos protegidos)
Route::middleware('auth')->group(function () {
    Route::get('/dashboard', [DashboardController::class, 'index']);
    Route::resource('products', ProductController::class)->except(['index', 'show']);
});
```

Si intentas acceder a una de estas rutas sin estar logueado, el middleware `auth` lo detectará y te redirigirá automáticamente a la página de login.

### 3.8.8. Práctica de sesiones y autenticación

Vamos a **incorporar un sistema de autenticación** a nuestra pequeña aplicación de productos y categorías, y lo vamos a hacer usando Laravel Breeze.

El objetivo es que cualquier usuario (incluso los visitantes anónimos o *guests*) pueda **ver** el catálogo de productos (`index` y `show`), pero solo los usuarios autenticados puedan **crear, editar o borrar** productos.

#### Objetivos
- Instalar el Starter Kit de autenticación (Breeze).
- Proteger las rutas sensibles usando el middleware `auth`.
- Ocultar los botones de creación, edición y borrado en las vistas para los usuarios no logueados (`@auth` / `@guest`).

#### PASO 1. Instalar Laravel Breeze

1. Abre tu terminal y ejecuta los siguientes comandos para instalar Breeze en su versión más simple (Blade):
   ```bash
   $ composer require laravel/breeze --dev
   $ ./vendor/bin/sail artisan breeze:install blade
   $ ./vendor/bin/sail artisan migrate
   $ ./vendor/bin/sail npm install
   $ ./vendor/bin/sail npm run build
   ```
2. Entra en tu navegador a `http://localhost/register` y crea una cuenta de usuario para ti.
3. Al terminar, deberías estar logueado. Puedes ver arriba a la derecha tu nombre y la opción de hacer *Log Out*.

#### PASO 2. Proteger las rutas de modificación en `web.php`

1. Abre `routes/web.php`.
2. Seguramente tengas una ruta `Route::resource('products', ProductController::class);`. Cámbiala por esto para que `index` y `show` sean públicas, pero que el resto requieran login:
   ```php
   use App\Http\Controllers\ProductController;

   // Rutas PÚBLICAS de productos
   Route::resource('products', ProductController::class)->only(['index', 'show']);

   // Rutas PRIVADAS (Protegidas por middleware 'auth')
   Route::middleware('auth')->group(function () {
       Route::resource('products', ProductController::class)->except(['index', 'show']);
   });
   ```
3. Cierra sesión (o abre una ventana de incógnito) e intenta entrar a `http://localhost/products/create`. Verás que te redirige automáticamente a la pantalla de login. ¡Eso significa que la protección funciona!

#### PASO 3. Ocultar botones en las vistas

Aunque la ruta esté protegida, los enlaces en las vistas seguirán apareciendo si no los ocultamos, lo que genera una mala experiencia de usuario (pulsarán el botón para nada, porque, si no están autenticados, el middleware `auth` los redirigirá a la pantalla de login).

1. Abre `resources/views/productos/index.blade.php`.
2. Rodea el enlace de "Crear producto" y los enlaces de "Editar" con la directiva `@auth` para que solo se vean si estás logueado:

   ```html
   @auth
       <p>
           <a href="{% raw %}{{ route('products.create') }}{% endraw %}">Crear producto</a>
       </p>
   @endauth
   
   <!-- Bucle foreach de los productos... -->
   
   @auth
       <p>
           <a href="{% raw %}{{ route('products.edit', $producto->id) }}{% endraw %}">Editar</a>
       </p>
   @endauth
   ```

3. Repite este proceso en `resources/views/productos/show.blade.php`, rodeando los enlaces o formularios de editar y borrar con `@auth`.

#### PASO 4. Saludar al usuario autenticado

1. Abre tu *master layout* principal (el tuyo propio, o el de Breeze).
2. Añade este bloque en la cabecera (header o nav) para saludar al usuario y darle la opción de login/logout:

   ```html
   <nav>
       <a href="{% raw %}{{ route('products.index') }}{% endraw %}">Catálogo</a>
       
       @auth
           <span>¡Hola, {% raw %}{{ Auth::user()->name }}{% endraw %}!</span>
           <!-- El logout de Breeze debe hacerse por POST, por eso usamos un formulario oculto -->
           <form method="POST" action="{% raw %}{{ route('logout') }}{% endraw %}" style="display:inline;">
               @csrf
               <button type="submit">Cerrar Sesión</button>
           </form>
       @endauth
       
       @guest
           <a href="{% raw %}{{ route('login') }}{% endraw %}">Login</a>
           <a href="{% raw %}{{ route('register') }}{% endraw %}">Registro</a>
       @endguest
   </nav>
   ```

   **Ahora tu aplicación diferencia a los visitantes anónimos de los usuarios registrados con capacidad de administrar datos**. Has asegurado tu CRUD con variables de sesión y el middleware de Laravel.

<div markdown="1" style="color: red; font-style: italic">
**ASEGÚRATE DE ENTENDER TODO LO QUE HAS HECHO Y NO SOLO DE QUE FUNCIONE.** 

Recuerda que cuando hagas prácticas de entrega obligatoria y exámenes, te podremos preguntar, por escrito u oralmente, qué hace tu código para comprobar que realmente lo entiendes, independientemente de si el código lo has escrito todo tú o lo has generado con ayuda de una IA.

<span style="font-size: 75%">(En esta práctica, Laravel Breeze habrá creado mucho código mezclado con tus controladores y tus vistas. Obviamente, ese código no es tuyo y no tienes por qué conocerlo, pero sí tener una idea global de qué hace y distinguirlo del que sí es tuyo)</span>
</div>

