---
layout: page
title: 3.4 Vistas y Blade
permalink: /laravel/vistas-y-blade.html
parent: 3 Aplicaciones SSR con Laravel
grand_parent: Desarrollo Web en Entorno Servidor
nav_order: 4
has_children: false
---

## 3.4. Vistas y plantillas. Blade
{: .no_toc }

- TOC
{:toc}


**Blade es un poderoso y sencillo sub-lenguaje** que nos permitirá **generar plantillas de vistas** para minimizar el código que necesitaremos para nuestras vistas.

Laravel permite trabajar directamente con **Angular**, **React** o **Vue** (a través de **Intertia**) para genera las vistas, pero Blade sigue siendo una pieza importante en las aplicaciones fullstack de tipo SSR o MPA, es decir, las que generan el HTML en el servidor.

Las plantillas Blade admiten condiciones y bucles para operar con las variables PHP, de modo que la misma plantilla se comporta de forma diferente con diferentes conjuntos de datos. **¡Y se acabó la pesadilla de abrir y cerrar comillas en las instrucciones ```echo```!**

Con Blade, tampoco será necesario abrir y cerrar php (```<?php ... ?>```) para operar con las variables del servidor y generar la salida.

El código escrito con Blade no solo es más limpio y fácil de depurar que con PHP básico, sino también más seguro, porque Blade dificulta los ataques con XSS.

Pero es no es todo. Además, unas plantillas pueden heredar de otras para reutilizar mejor el código.

Así que Blade tiene un montón de ventajas y ningún inconveniente. Bueno, sí que tiene un inconveniente: que tienes que aprender a usarlo. Pero es tan sencillo que, cuando hayas trabajado con Blade un poco, te preguntarás cómo habías podido vivir hasta ahora sin él.

### 3.4.1. Master layout

***Layout*** es una forma genérica de referirse al diseño de capas del interfaz de usuario de una aplicación. Es decir, el *layout* de una aplicación es el diseño de los elementos de su interfaz de usuario.

![Ejemplos de layout](/docs/dwes/_site/assets/images/07-ejemplos-de-layout.png)

*(Ejemplos de layout adaptados a diferentes tamaños de pantalla. Imagen tomada de [Seobility.net](https://www.seobility.net/en/wiki/Media_Queries) y publicada con licencia [CC BY-SA 4.0](https://creativecommons.org/licenses/by-sa/4.0/))*

El ***master layout*** es el diseño maestro del que derivan todas las vistas. Las aplicaciones web suelen tener un *master layout* muy definido, y todas las vistas de la aplicación lo respetan.

Ese *master layout* suele almacenarse, por convenio, en un archivo llamado *`/resources/views/layouts/app.blade.php`*, aunque la elección de ese nombre es del programador.

Vamos a construir un *master layout* de ejemplo. Será muy simple, pero más adelante puedes complicarlo todo lo que quieras, y cada modificación afectará automáticamente a todas las vistas de tu aplicación.

```html
<html>
 <head>
    <title>@yield('Titulo')</title>
 </head>
 <body>
    @section('sidebar')
        Este es mi master sidebar.
    @endsection
    <div class="container">
        @yield('content')
    </div>
 </body>
</html>
```

Aquí nos encontramos con varias **directivas** importantes de Blade:

* **@yield('Titulo')** --> Aquí se mostrará un contenido llamado 'Título', que en el master layout está vacío (sin contenido). Las vistas que hereden del master layout tendrán que definir cuál es el valor de 'Título', y ese valor aparecerá escrito aquí.

* **@section('sidebar')** --> Esto define una sección llamada 'sidebar' que NO está vacía (contiene el texto "Este es mi master sidebar", pero podría contener cualquier otra cosa). Las vistas que hereden del master layout podrán AÑADIR contenido a esta sección.

* **@endsection** --> MArca el final de la sección 'sidebar'.

* **@yield('content')** --> De nuevo, aquí irá un contenido llamado 'content', que está vacío en el master layout y cuyo contenido real tendrá que definirse en las vistas que hereden de esta.

### 3.4.2. Vistas que heredan del master layout

Después de crear nuestro *master layout*, lo siguiente es empezar a construir vistas que lo utilicen.

Es decir, que **hereden** de él todos sus componentes y añadan nuevos elementos, respetando la configuración básica establecida por el *master layout*.

El aspecto de una vista que herede del *master layout* de nuestro ejemplo anterior debería ser este:

```html
@extends('layouts.app')
@section('title', 'Titulo de la página')
@section('sidebar')
<p>Esto se añadirá al master sidebar.</p>
@endsection
@section('content')
<p>Aquí va el contenido de mi página.</p>
@endsection

```

De nuevo tenemos varias *directivas* de Blade muy importantes:

* **@extends('layouts.app')** --> Esto indica que esta vista hereda del master layout.

* **@section('title, 'Título de la página')** --> Aquí se define el contenido de la sección 'Título' que en el master layout estaba vacía.

* **@section('sidebar')** --> Aquí añade contenido a la sección 'sidebar', que en el master layout no estaba vacía.

* **@endsection** --> Se emplea cuando el contenido de una sección ocupa varias líneas de código y no es posible escribirlo dentro de la propia directiva.

### 3.4.3. Cómo pasar variables a las vistas

Las **variables** a las vistas suelen enviarse **empaquetadas en un array**, pero también hay otras maneras.

Hay varias formas de lograrlo y todas son correctas. Puedes emplear la que te resulte más cómoda o más elegante:

```php
// Forma 1: crear el array antes de llamar a la vista
$data['variable1'] = 'valor';
$data['variable2'] = 'valor';
return view('vista', $data);

// Forma 2: crear un array con el constructor array() (SINTAXIS ANTICUADA, PERO AÚN FUNCIONA)
return view('vista', array('variable1'=>'valor', 'variable2'=>'valor'));

// Forma 3: usar el método with()
return view('vista')->with(['variable1'=>'valor', 'variable2'=>'valor']);

// Forma 4: crear un array con corchetes [] (MÁS USADA)
return view('vista', ['variable1'=>'valor', 'variable2'=>'valor']);

// Forma 5: usar la función compact() (MÁS USADA)
return view('vista', compact('variable1', 'variable2'));
```

**Todas las formas son válidas**, pero las 4 y 5 son las más usadas en la actualidad.

### 3.4.4. Cómo usar las variables en las vistas

Vale, ya hemos enviado algunas variables a las vistas. Ahora, ¿cómo las usamos?

La vista no recibe el array con las variables, sino **las variables ya extraídas del array**. Esto significa que, si le pasas a una vista un par de variables como ```['variable1'=>'valor', 'variable2'=>'valor']```, en la vista existirán dos variables llamadas *`$variable1`* y *`$variable2`*, y no encontrarás ni rastro del array que las contenía.

Veámoslo con un ejemplo. Supongamos que tenemos este método en un controlador:

```php

public function show() {
   return view('page', array('name' => 'Manolo Escobar'));
}

```

En la vista *`/resources/views/page.blade.php`* tendrás disponible una variable *`$name`*, y la puedes usar de este modo:

```html
@extends('layouts.app')
@section('title', 'Page Title')
@section('sidebar')
  <p>Esto se añadirá al sidebar del master layout.</p>
@endsection
@section('content')
 <h2>{% raw %}{{$name}}{% endraw %}</h2>   
 <p>Este es el contenido de mi página.</p>
@endsection
```

Observa que hemos respetado el *master layout* de ejemplo que creamos más arriba. Observa también cómo se hace el `echo` de la variable: nada de abrir y cerrar PHP (```<?php ... ?>```) ni de abrir y cerrar comillas: simplemente, se encierra la variable entre llaves dobles (```{% raw %}{{$variable}}{% endraw %}```), y Laravel se encargará de traducir eso al `echo` correspondiente.

La vista queda de ese modo mucho más limpia y, por lo tanto, es más fácil de escribir, leer y depurar.

### 3.4.5. Condiciones en las vistas

Blade admite **expresiones condicionales** para modificar el aspecto de una vista dependiendo del valor de una variable o del estado de la aplicación.

Por supuesto, eso también puede hacerse sin Blade: solo hay que usar un `if` de PHP. Pero con Blade es más fácil y limpio porque, nuevamente, no tendremos que andar abriendo y cerrando PHP ni peleándonos con las comillas del `echo`.

En el siguiente ejemplo, el contenido de la vista depende de la variable *`$day`* enviada desde el controlador. Observa como el `if` de PHP se sustituye por la directiva *`@if`* de Blade.

Controlador:

```php
public function show() {
   return view('page', array('name' => 'Manolo','day' => 'Viernes'));
}
```

Vista *`/resources/views/page.blade.php`*:

```html
@extends('layouts.app')
@section('title', 'Page Title')
@section('sidebar')
  <p>Esto se añadirá al sidebar del master layout.</p>
@endsection
@section('content')
 <h2>{% raw %}{{$name}}{% endraw %}</h2>    
  <p>Este es el contenido de mi página.</p>
  @if ($day == 'Viernes')
      <p>Hoy me roban el carro</p>
  @else
      <p>Hoy me dedico a cantar</p>
  @endif
@endsection
```

### 3.4.6. Bucles en las vistas

Igual que existen condiciones, Blade también permite hacer **bucles** para simplificar la generación de vistas.

Por ejemplo, en la siguiente vista recorremos un array llamado *`$bebidas`* y mostramos su contenido.

Controlador:

```php
public function show() {
   $bebidas = array('Cerveza','Agua','Zumo');
   return view('page',array('name' => 'Manolo','day' => 'Lunes',
                            'bebidas' => $bebidas));
}
```

Vista *`/resources/views/page.blade.php`*:

```html
@extends('layouts.app')
@section('title', 'Page Title')
@section('sidebar')
  <p>Esto se añadirá al sidebar del master layout.</p>
@endsection
@section('content')
 <h2>{% raw %}{{$name}}{% endraw %}</h2>    
  <p>Este es el contenido de mi página.</p>
  @if ($day == 'Viernes')
      <p>Hoy me roban el carro</p>
  @else
      <p>Hoy me dedico a cantar</p>
  @endif
  <h2>Estas son las bebidas disponibles:</h2>
  @foreach ($bebidas as $bebida)
     {% raw %}{{$bebida}}{% endraw %} <br>
  @endforeach
@endsection
```

Observa que, nuevamente, esto mismo podría hacerse con PHP clásico, pero con Blade el código queda mucho más limpio y resulta menos propenso a errores.

### 3.4.7. Otras directivas Blade

Blade dispone de multitud de directivas para hacer prácticamente cualquier cosa en la vista sin tener que recurrir a PHP. En esta lista mostramos solo las directivas más habituales.

- **@section** → Marca el inicio de una sección de contenido.

- **@endsection** → Marca el final de una sección.

- **@show** → Marca el final de una sección y la muestra.

- **@yield('section')** → Muestra el contenido de una sección (si existe, claro).

- **@extends('view')** → Hereda de una plantilla padre.

- **@parent** → Muestra el contenido de la sección del mismo nombre en la plantilla padre.

- **@include('view')** → Incluye una subvista.

- **@if - @else - @endif** → Condicional.

- **@for - @endfor** → Bucle for clásico.

- **@foreach - @endforeach** → Buche foreach.

- **@forelse - @empty - @endforelse** → Como foreach, pero con tratamiento de arrays que vienen vacíos.

- **@break - @continue** → Para usar en los bucles.

- **@switch - @case - @break** → Condicional múltiple.

- **@isset($variable) - @endisset** → Comprueba si la variable existe.

- **@auth - @endauth** → La sección solo se muestra si hay un usuario autenticado en la aplicación.

- **@php - @endphp** → Para añadir código PHP plano. Usar con moderación.

- **{% raw %}{{-- Comment --}}{% endraw %}** → Comentarios (no serán renderizados).

- **{% raw %}{{ $variable }}{% endraw %}** → Equivalente a echo $variable, pero no es necesario abrir y cerrar PHP, y nos protegemos contra inyección de JS.

- **{% raw %}{{ $variable ?? texto-por-defecto }}{% endraw %}** → Como el anterior, pero chequea si la variable existe. Si existe, muestra su valor. Si no, muestra

texto-por-defecto.

- **$loop** →  Es una variable muy útil para usar en y/o depurar un foreach. Nos dice si estamos en el primer elemento, en el último, cuántos loops llevamos, etc.

### 3.4.8. Tratamiento de formularios con Blade

Blade también facilita un montón el **tratamiento de los formularios**. Y, por supuesto, filtra por nosotros cualquier código malicioso que traten de colarnos a través de ellos.

Vamos a verlo con un ejemplo.

Imaginemos una vista con este formulario (fíjate cómo indicamos la ruta en el *action*):

```html
<form method="POST" action="{% raw %}{{ route('mi-ruta') }}{% endraw %}">
  @csrf   <!-- Para evitar ataques CSRF -->
  <input type="email" name="email"><br>
  <input type="text" name="asunto"><br>
  <textarea name="contenido"></textarea><br>
  <button type="submit">Enviar</button>
</form>
```

Recuerda que los métodos PUT, PATCH y DELETE no existen aún en HTML y que Laravel los simula con un campo oculto en el formulario que se crea con la directiva **`@method('PUT')`** (o PATCH o DELETE). En este formulario no la hemos usado porque se envía por POST.

Lo que sí hemos usado es la directiva **@csrf**. *Todos los formularios que hagan actualizaciones de datos del servidor deberían llevarla*. Impide los ataques por CSRF, incrustado un token aleatorio en el formulario que Laravel se encargará de comprobar cuando los datos del formulario regresen al servidor. No te preocupes si no entiendes bien como funciona, por Laravel se encarga de hacerlo todo. Tú solo tienes que colocar la directiva @csrf en todos tus formularios.

En el enrutador, definiremos la ruta "mi-ruta" del action del formulario:

```php
use \App\Http\Controllers\MiControlador;

Route::post('mi-ruta', [MiControlador::class, 'store']);
```

Y, en el controlador, creamos el método `store()`. Observa cómo recuperamos los datos del formulario a través de la variable $r:

```php
public function store(Request $r) {
  $email = $r->input("email");
  $asunto = $r->input("asunto");
  ...etc...
}
```

Esta es una forma alternativa para el controlador:

```php
public function store() {
$email = request("email");
$asunto = request("asunto");
...etc...
}

```

### 3.4.9. Validación de formularios con Blade

Otra cosa que Blade facilita muchísimo es la **validación de formularios en el lado del servidor**.

<div style='font-size: 80%; margin-left: 5%; margin-right: 5%; background: #eee; color: #666'>

<p>Aquí toca hacer un paréntesis para responder a esta pregunta: ¿dónde deberían validarse los formularios? ¿En el cliente (con HTML y Javascript) o en el servidor (con PHP y Laravel)?</p>

<p>La respuesta es: en los dos sitios. Sobre todo si es un formulario con información sensible.</p>

<p>La validación en el cliente es más sencilla de hacer. Comprobar que un campo de texto de un formulario no se envía vacío, por ejemplo, es algo trivial con HTML. Y con Javascript es solo un poquito más complicado.</p>

<p>Hacer esas comprobaciones en el servidor resulta más trabajoso: hay que recibir el formulario, comprobar los valores de los campos y, si hay un error, tenemos que volver a enviar el formulario, pero respetando los datos que el usuario ya hubiera tecleado, todo ello junto con un mensaje informando del error.</p>

<p>Sí, en el servidor es más complicado. Pero también más seguro. Las validaciones en el cliente pueden desactivarse (puedo usar un navegador antiguo para evitar las comprobaciones por HTML, y puedo deshabilitar temporalmente el motor de Javascript), así que son una primera barrera defensiva muy convieniente pero poco segura.</p>

<p>Las comprobaciones en el servidor son más confiables, porque el servidor no está bajo el control de los usuarios. Así que deberíamos hacer los dos conjuntos de comprobaciones en todos nuestros formularios.</p>

<p>Y aquí es donde Laravel nos ayuda.</p>

</div>

Vamos a retomar **la vista** del ejemplo anterior y a modificar el formulario para que se valide en el servidor. Tendríamos que añadirle algunas cositas:

```html
<form method="POST" action="{%raw %}{{ route('mi-ruta') }}{% endraw %}">
  @if ($errors->any()) 
     @foreach ($errors->all() as $error)
         {% raw %}{{ $error }}{% endraw %}<br>
     @endforeach
  @endif
  <input type="email" name="email"><br>
  ...resto del formulario igual... 
</form>
```

Fíjate en cómo mostramos los errores -si los hay- con un bucle. El objeto *`$errors`* (disponible en todas las vistas) tiene muchos más métodos útiles que puedes consultar en la documentación de Laravel.

Y el **controlador** quedaría así. Observa cómo definimos varias **reglas de validación** para campos del formulario:

```php
public function store(Request $request) {
  $request->validate([
     'email' => 'required|email',
     'asunto' => 'required'
  ]);
  // A partir de aquí, se procesa el formulario igual que antes
```

Puedes consultar todas las reglas de validación admitidas en [https://laravel.com/docs/validation](https://laravel.com/docs/validation).

Cuando vuelve a cargarse el formulario que contenía un error, suele ser apropiado hacerlo con los datos que el usuario ya había tecleado. A esto se le llama **"repopular" el formulario**, y con Blade se hace así (observa el atributo *value* del campo *email*):

```html
<form method="POST" action="{% raw %}{{ route('mi-ruta') }}{% endraw %}">
  @if ($errors->any()) 
     @foreach ($errors->all() as $error)
          {% raw %}{{ $error }}{% endraw %}<br>
     @endforeach
  @endif
  <input type="email" name="email" value="{% raw %}{{ old('email') }}{% endraw %}"><br>
  ...resto del formulario igual... 
</form>
```

Otra forma especialmente útil de mostrar mensajes de error es esta:

```html
@error('email')
    <span>{% raw %}{{ $message }}{% endraw %}</span>
@enderror
```

### 3.4.10. Añadir CSS y Javascript a nuestras vistas

Laravel 13 se basa en **Vite** y **Tailwind**:

- **Vite** es una herramienta que organiza y optimiza todos los archivos para las vistas, como imágenes, CSS, librerías Javascript, etc.
- **Tailwind** es un framework CSS que facilita el diseño del interfaz de usuario HTML usando clases predefinidas (por ejemplo `<button class='boton-pricipal'>Guardar</button>`)

No es necesario que aprendas estas dos herramientas adicionales, pero sí que te las vas a encontrar en los desarrollo Laravel profesionales.

Laravel usa dos archivos, `resources/js/app.js`y `resources/css/app.css`, para cargar *Vite* y *Tailwind*, así que deben estar incluidos en todas las vistas o, mejor, en tu *master layout*:

```html
@vite(['resources/css/app.css', 'resources/js/app.js'])
```

Si queremos **añadir reglas CSS**, lo habitual es:

1. Abrir el archivo *`/resources/sass/app.css`*
2. Añadir el CSS que necesitemos *sin cambiar el contenido que ya existe*.
3. Recompilar este archivo.

La recompilación se hace con ayuda de **npm**, el compilador de **Node.js** (que viene incluido con Laravel)

```
$ ./vendor/bin/sail npm run dev   # Usa este comando si vas a seguir haciendo cambios en el CSS y quieres ver cómo queda "en vivo"
$ ./vendor/bin/sail npm run build # Usa este comando cuando hayas terminado de editar el CSS, para generar la versión optimizada definitiva
```

*(Hablaremos de Node y npm, y de qué pintan dentro de Laravel, más adelante)*

También puedes, simplemente, guardar tu CSS y tu Javascript en el **directorio `/public`** de Laravel, aunque **no es lo más recomendable** por razones de seguridad y rendimiento. En ese caso, los archivos serían accesibles de forma pública y puedes usarlos en tu HTML con `<link rel="stylesheet" href="mi-archivo-css.css">`


### 3.4.11. Práctica con vistas y Blade

En la práctica anterior del apartado 3.3 dejamos preparada la infraestructura de `products`: migración, modelo, controlador (tipo `resource`) y rutas.

Vamos a dar el siguiente paso, que consistirá en **crear las vistas de los productos y conectarlas con el controlador**.

La idea no es todavía implementar la aplicación CRUD completa, porque aún no sabemos interactuar con los datos de la base de datos. **De momento, vamos a utilizar datos fijos preparados en el controlador** para aprender cómo se relacionan las distintas piezas de una aplicación Laravel.

Al terminar la práctica deberías tener esta estructura de vistas:

```text
resources/views/
├── layouts/
│   └── app.blade.php
└── productos/
    ├── index.blade.php
    ├── create.blade.php
    ├── edit.blade.php
    └── show.blade.php
```

#### Objetivos

Al terminar la práctica habrás aprendido a:

- Crear una vista Blade.
- Organizar las vistas utilizando un layout común.
- Utilizar `@extends`, `@section` y `@yield`.
- Pasar datos desde un controlador a una vista.
- Mostrar variables con `{% raw %}{{ }}{% endraw %}`.
- Recorrer datos con `@foreach`.
- Generar URLs utilizando `route()`.
- Crear formularios Blade.
- Utilizar `@csrf` para proteger los formularios.
- Utilizar `@method()` para simular los métodos HTTP `PUT` y `DELETE` desde un formulario HTML.
- Mostrar errores de validación con `@error`.
- Recuperar los datos introducidos anteriormente mediante `old()`.
- Cargar los recursos CSS y JavaScript mediante `@vite()`.

#### PASO 1. Crear el layout principal

1. Ve a tu aplicación de prueba de Laravel (`hola-laravel` o como tú la hayas llamado).
2. Crea un archivo de texto vacío: `resources/views/layouts/app.blade.php`
   Este archivo será la plantilla común de nuestras páginas. Todas las páginas de productos compartirán la misma estructura HTML básica que definiremos aquí. De esta forma no tendremos que repetir el `<html>`, el `<head>`, el menú, etc. en cada vista.
3. El contenido de `app.blade.php` puede ser algo como esto (puedes hacer cambios, si quieres):

  ```html
  <!DOCTYPE html>
  <html lang="es">
  <head>
      <meta charset="UTF-8">
      <meta name="viewport" content="width=device-width, initial-scale=1.0">

      <title>@yield('title', 'Productos')</title>

      @vite(['resources/css/app.css', 'resources/js/app.js'])
  </head>

  <body>

      <header>
          <h1>Gestión de productos</h1>

          <nav>
              <a href="{% raw %}{{{% endraw %} route('products.index') {% raw %}}}{% endraw %}">Productos</a>
              <a href="{% raw %}{{{% endraw %} route('products.create') {% raw %}}}{% endraw %}">Nuevo producto</a>
          </nav>
      </header>

      <main>
          @yield('content')
      </main>

  </body>
  </html>
  ```
  <div markdown="1" style="color: red; font-style: italic">
   Si no entiendes algo de lo que pone en esta vista maestra, **pregunta, indaga, repasa los apuntes**, pero **NO CONTINÚES SI NO LO ENTIENDES**.
  </div>

#### PASO 2. Aprender a compilar recursos de Vite

En el layout anterior hemos utilizado `@vite(['resources/css/app.css', 'resources/js/app.js'])` 

Esto indica a Laravel que cargue los recursos gestionados por Vite.

1. Para que Vite procese los archivos mientras hacemos cambios, debes ejecutar:
  ```bash
  sail npm run dev
  ```
  *Deja este proceso funcionando mientras trabajas con la aplicación.*

2. Cuando hayas terminado de hacer cambios en tus CSS, JS y vistas en general, debes utilizar:

  ```bash
  sail npm run build
  ```

  Por ahora no necesitamos modificar `app.css` ni `app.js`. Lo importante es entender que el layout es un buen lugar para incluir los recursos que necesitan todas nuestras vistas.

#### PASO 3. Crear la vista `index`

1. Crea un archivo de texto vacío `resources/views/productos/index.blade.php`
   Esta será la página que muestre la lista de productos.

2. Modifica el método `index()` del controlador `ProductController.php`:
  ```php
  public function index()
  {
      // Unos cuantos productos de prueba (más adelante aprenderemos a extraerlos
      // de la base de datos)
      $productos = [
          [
              'id' => 1,
              'name' => 'Teclado mecánico',
              'description' => 'Teclado mecánico con conexión USB.',
              'price' => 59.90
          ],
          [
              'id' => 2,
              'name' => 'Ratón inalámbrico',
              'description' => 'Ratón inalámbrico con sensor óptico.',
              'price' => 29.95
          ],
          [
              'id' => 3,
              'name' => 'Monitor 24"',
              'description' => 'Monitor Full HD de 24 pulgadas.',
              'price' => 149.00
          ]
      ];

      // *** ¡¡¡ ESTO ES LO IMPORTANTE !!! ***
      // Invocamos la renderización de la vista y le pasamos la lista de productos.
      return view('productos.index', [
          'productos' => $productos
      ]);
  }
  ```

3. Edita el contenido de la vista `index.blade.php`. Prueba con este:

    ```html
    @extends('layouts.app')

    @section('title', 'Listado de productos')

    @section('content')

        <h2>Productos</h2>

        <p>
            <a href="{% raw %}{{ route('products.create') }}{% endraw %}">Crear producto</a>
        </p>

        @foreach ($productos as $producto)
            <article>
                <h3>
                    <a href="{% raw %}{{ route('products.show', $producto['id']) }}{% endraw %}">
                        {% raw %}{{ $producto['name'] }}{% endraw %}
                    </a>
                </h3>

                <p>{% raw %}{{ $producto['description'] }}{% endraw %}</p>

                <p>Precio: {% raw %}{{ $producto['price'] }}{% endraw %} €</p>

                <p>
                    <a href="{% raw %}{{ route('products.show', $producto['id']) }}{% endraw %}">
                        Ver producto
                    </a>

                    <a href="{% raw %}{{ route('products.edit', $producto['id']) }}{% endraw %}">
                        Editar
                    </a>
                </p>
            </article>
        @endforeach

    @endsection
    ```

4. Prueba ahora en tu navegador el endpoint `http://localhost/products`. Deberías ver la lista de productos.

<div markdown="1" style="color: red; font-style: italic">
**De nuevo, lee este código y ASEGÚRATE DE ENTENDERLO TODO,** no te limites a copiar y probar irreflexivamente. Si algo no lo entiendes, indaga, pregunta, revisa los apuntes.
</div>

#### PASO 4. Crear la vista `show`

Vamos a continuar creando vistas. Ahora le toca a `show`, para mostrar el detalle de un único producto identificado por si ID.

1. Crea el archivo `resources/views/productos/show.blade.php`

2. Modifica el método `show()` del controlador `ProductController.php`:
  ```php
  public function show(string $id)
  {
      // Producto de prueba. Pronto aprenderemos a traerlo de la BD.
      $producto = [
          'id' => $id,
          'name' => 'Teclado mecánico',
          'description' => 'Teclado mecánico con conexión USB.',
          'price' => 59.90
      ];

      // *** ESTO ES LO IMPORTANTE ***
      // Renderizamos la vista y le pasamos los datos del producto
      return view('productos.show', [
          'producto' => $producto
      ]);
  }
  ```

3. Escribe el contenido de la vista `resources/views/productos/show.blade.php`:
    ```html
    @extends('layouts.app')

    @section('title', $producto['name'])

    @section('content')

        <h2>{% raw %}{{ $producto['name'] }}{% endraw %}</h2>

        <p>{% raw %}{{ $producto['description'] }}{% endraw %}</p>

        <p>
            <strong>Precio:</strong>
            {% raw %}{{ $producto['price'] }}{% endraw %} €
        </p>

        <p>
            <a href="{% raw %}{{ route('products.index') }}{% endraw %}">
                Volver al listado
            </a>

            <a href="{% raw %}{{ route('products.edit', $producto['id']) }}{% endraw %}">
                Editar producto
            </a>
        </p>

    @endsection
    ```

4. Prueba ahora el endpoint `http://localhost/products/1`. Debería mostrarte los datos del producto de prueba.
5. Prueba a llegar a esta misma vista desde `index.blade.php`. Deberías llegar haciendo clic en cualquiera de los productos de la lista.

<div markdown="1" style="color: red; font-style: italic">
**Otra vez: lee este código y ASEGÚRATE DE ENTENDERLO TODO,** no te limites a copiar y pegar. Y, si algo no se entiende, indaga, pregunta, revisa los apuntes.
</div>

#### PASO 5. Crear la vista `create`

En este paso construiremos el formulario para crear un producto.

1. Crea el archivo de texto `resources/views/productos/create.blade.php`

2. En el método `create()` del controlador coloca simplemente la llamada a la vista:
  ```php
  public function create()
  {
      return view('productos.create');
  }
  ```

3. Escribe el código de la vista. Puede ser algo así:
    ```html
    @extends('layouts.app')

    @section('title', 'Nuevo producto')

    @section('content')

        <h2>Nuevo producto</h2>

        <form method="POST" action="{% raw %}{{ route('products.store') }}{% endraw %}">

            @csrf

            <p>
                <label for="name">Nombre:</label>
                <input
                    type="text"
                    id="name"
                    name="name"
                    value="{% raw %}{{ old('name') }}{% endraw %}"
                >

                @error('name')
                    <span>{% raw %}{{ $message }}{% endraw %}</span>
                @enderror
            </p>

            <p>
                <label for="description">Descripción:</label>
                <textarea
                    id="description"
                    name="description"
                >{% raw %}{{ old('description') }}{% endraw %}</textarea>

                @error('description')
                    <span>{% raw %}{{ $message }}{% endraw %}</span>
                @enderror
            </p>

            <p>
                <label for="price">Precio:</label>
                <input
                    type="number"
                    id="price"
                    name="price"
                    step="0.01"
                    value="{% raw %}{{ old('price') }}{% endraw %}"
                >

                @error('price')
                    <span>{% raw %}{{ $message }}{% endraw %}</span>
                @enderror
            </p>

            <button type="submit">
                Guardar producto
            </button>

        </form>

    @endsection
    ```

4. En este momento todavía no vamos a implementar la creación del producto en la base de datos, porque aún no sabemos hacerlo. Pero sí puedes *simular* la creación. Simplemente, visita el endpoint `http://localhost/products/create` y pulsa en "guardar producto".
  Tu navegador enviará una Request `POST /products`, y Laravel ejecutará en consecuencia `ProductController@store`.
  De momento ese método solo te mostrará algo como "Aquí se almacenará el producto".

<div markdown="1" style="color: red; font-style: italic">
**Nos repetimos de nuevo: lee este código y ASEGÚRATE DE ENTENDERLO TODO,** no te limites a copiar y pegar. Además, esta vista tiene muchas cosas importantes, como la validación de formularios. Si algo no se entiende, como siempre: indaga, pregunta, revisa los apuntes hasta que se entienda.
</div>

#### PASO 6. Crear la vista `edit`

En este paso no te vamos a guiar.

**Vamos a dejar que lo hagas tú solito/a.**

(Si has entendido todo lo anterior, deberías tener una idea bastante aproximada de cómo hacerlo y probarlo, aunque aún necesitarás un poco de ayuda).

#### PASO 7. Añadir un formulario de borrado

El borrado es una operación peliaguda: no solo es destructiva, sino que tiene que llegar al servidor por `POST`, así que no se puede implementar en un link.

Por eso no pudimos probarlo en la práctica anterior, como no pudimos probar `store()` ni `update()`.

Vamos a añadir un miniformulario a la vista `show` para poder invocar el método `destroy()`, aunque, de momento, no borrará nada de la base de datos.

1. Añade al final de `show.blade.php` esto:
    ```html
    <form
        method="POST"
        action="{% raw %}{{ route('products.destroy', $producto['id']) }}{% endraw %}"
    >

        @csrf
        @method('DELETE')

        <button type="submit">
            Eliminar producto
        </button>

    </form>
    ```

2. Visita un endpoint como `/products/1` y pulsa el botón "Eliminar producto" que debería aparecerte bajo los datos del producto.

3. Si todo va bien, ese botón te llevará a `ProductController@destroy`, que te mostrará un mensaje provisional del tipo "Aquí irá el código para eliminar un producto"

<div markdown="1" style="color: red; font-style: italic">
**¿Hace falta que lo digamos? ASEGÚRATE DE ENTENDERLO TODO** antes de continuar.
</div>

#### Revisión final

Si has hecho caso y has ido analizando el código que hemos ido creando, deberías ser capaz de **localizar cada uno de estos elementos y explicar para qué sirven**. *Ten en cuenta que te podemos hacer este tipo de preguntas en cualquier revisión oral de prácticas obligatorias o en los exámenes*.

| Concepto | ¿Dónde aparece? |
|---|---|
| `@extends` | En las vistas de productos |
| `@section` | En las vistas de productos |
| `@yield` | En `layouts/app.blade.php` |
| `{% raw %}{{ }}{% endraw %}` | Al mostrar datos |
| `@foreach` | En `productos/index.blade.php` |
| `route()` | En enlaces y formularios |
| `@csrf` | En los formularios |
| `@method` | En los formularios `PUT` y `DELETE` |
| `@error` | En los formularios |
| `old()` | En los campos de los formularios |
| `@vite()` | En `layouts/app.blade.php` |
