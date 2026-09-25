---
layout: page
title: 3.2 Práctica guiada. Hola mundo con Laravel
permalink: /laravel/hola-mundo.html
parent: 3 Aplicaciones SSR con Laravel
grand_parent: Desarrollo Web en Entorno Servidor
nav_order: 2
has_children: false
---

## 3.2. Nuestra primera aplicación en Laravel
{: .no_toc }

- TOC
{:toc}

Ya sabemos qué es Laravel y por qué puede resultar útil utilizar un framework para desarrollar aplicaciones web.

Ha llegado el momento de dejar la teoría y crear nuestra primera aplicación.

La idea de este apartado es muy sencilla: **crear una aplicación Laravel desde cero para entender cómo está organizada y hacer que responda a nuestras primeras peticiones HTTP**.

No vamos a aprender todavía *todos* los componentes de Laravel. De hecho, muchas cosas que veremos ahora solo tendrán sentido cuando avancemos en el tema. **Lo importante es empezar a familiarizarnos con el entorno de trabajo**.

---

### PASO 0. Prerrequisitos para que Laravel funcione

Para desarrollar una aplicación con Laravel necesitamos disponer de un entorno de desarrollo con las herramientas necesarias.

Para Laravel 13, los prerrequisitos principales son:

* **PHP 8.3 o superior**.
* **Composer**, el gestor de dependencias de PHP.
* **Node.js y npm** si vamos a trabajar con CSS y JavaScript.
* **MySQL** u otro gestor de bases de datos si vamos a usar base de datos.
* **Laravel Installer**, la herramienta de línea de comandos que nos permitirá crear nuevas aplicaciones Laravel.

En lugar de instalar todo esto en nuestra máquina, ya vimos en el Tema 1 que es más limpio y portable hacerlo con **contenedores Docker**, de modo que eso es lo primero que tenemos que hacer.

### PASO 1: Crear la infraestructura con Docker: Laravel Sail

Vamos a utilizar **docker** y **docker compose** pero, en lugar de crear manualmente nuestro `docker-compose.yml`, vamos a recurrir a **Laravel Sail**, una herramienta que Laravel proporciona para trabajar con docker y compose.

De esta forma, el ordenador de desarrollo **solo necesita tener instalado docker con docker compose**. PHP, Composer, Node.js, MySQL y el resto de servicios necesarios funcionarán dentro de contenedores. 

1. Instala Docker y Docker Compose en tu máquina (si no lo tienes ya). *Si no sabes cómo hacerlo, revisa el Tema 1*.
2. Abre un terminal de texto en tu carpeta de trabajo y teclea esto (sustituye `hola-laravel` por el nombre que le quieras dar a tu aplicación):

    ```bash
    $ curl -s "https://laravel.build/hola-laravel" | bash
    ```

    Este comando descarga todos los archivos de Laravel en un subdirectorio llamado `hola-laravel`. 
3. Revisa el directorio `hola-laravel` (o el nombre que le hayas puesto) y comprueba que se han descargado un montón de archivos y subcarpetas. Si está vacío, es que algo ha ido mal.

### PASO 2: Arrancar y parar Laravel Sail

1. Abre un terminal de texto en el directorio de tu proyecto Laravel.
2. Pon en marcha todos los servicios (Apache, PHP, MySQL, etc) haciendo:

    ```bash
    $ ./vendor/bin/sail up
    ```

   O bien:

    ```bash
    $ ./vendor/bin/sail up -d
    ```

    Esto es el equivalente a hacer `docker compose up` o `docker compose up -d`, pero usando `sail`, la herramienta de Laravel, como sustituto. 

3. Comprueba que Laravel está funcionando bien haciendo visitando en tu navegador la dirección `http://localhost`. Debería verse la pantalla de bienvenida de Laravel 13.    
4. Detén los contenedores como harías con docker compose: o bien pulsando `CTRL+C` o bien tecleando  `./vendor/bin/sail down`.

**OJO: La primera vez que levantes los contenedores puede tardar bastante**, porque tiene que descargar y construir las imágenes necesarias. La siguientes veces será mucho más rápido.

### PASO 3. Comprobar versión de PHP

Como hemos decidido no instalar PHP en nuestro ordenador, si ejecutas en un terminal de texto de tu máquina el comando `$ php`, lo lógico es que te responda con un `command not found` (salvo que tengas instalado PHP por otra razón).

¿Dónde está entonces PHP? Está *dentro* de uno de los contenedores levantados con `sail`.

Para abrir un terminal *dentro* de un contenedor, vimos en el tema 1 que docker tiene el comando `docker exec -it <id-contenedor> bash`. Sin embargo, con Laravel Sail es más fácil acceder al contenedor. Basta con que teclees `./vendor/bin/sail` delante del comando que quieras ejecutar *dentro* del contenedor.

1. Abre un terminal de texto en la carpeta del proyecto.
2. Levanta los contenedores de Laravel (si no están corriendo ya).
3. Teclea esto para ver la versión exacta de PHP que está usando el contenedor que te ha proporcionado Laravel:

```bash
./vendor/bin/sail php --version
```

**RECUERDA:** Más adelante tendrás que ejecutar muchas veces cosas *dentro* de los contenedores, como `artisan`, `mysql`, `npm` o `composer`. Se hace exactamente igual que ahora hemos ejecutado `php`.

### PASO 4. Echar un vistazo a la arquitectura de Laravel

Si abrimos la carpeta del proyecto, encontraremos una **estructura de archivos y carpetas** parecida a esta:

```text
hola-laravel/
│
├── app/
├── bootstrap/
├── config/
├── database/
├── public/
├── resources/
├── routes/
├── storage/
├── tests/
├── vendor/
│
├── .env
├── .env.example
├── artisan
├── composer.json
├── package.json
└── vite.config.js
```

**No necesitas conocer todavía todos estos directorios**. Basta con saber para qué sirven algunos de los más importantes:

* **`app/`**: contendrá la mayor parte del código de nuestra aplicación (cuando lo escribamos).

* **`bootstrap/`**: contiene los archivos necesarios para arrancar el framework y algunos archivos generados para mejorar el rendimiento. No suele tocarse.

* **`config/`**: contiene los archivos de configuración de la aplicación.

* **`database/`**: contiene todo lo necesario para que la base de datos funcione.

* **`public/`**: es el directorio público de la aplicación. Contiene `index.php`, que es el punto de entrada de las peticiones HTTP (como el Front Controller de Laravel), además de otros recursos accesibles vía web.

* **`resources/`**: contiene las vistas y los recursos del frontend, como CSS, JavaScript, imágenes, etc.

* **`routes/`**: contiene las definiciones de las rutas de nuestra aplicación para que en enrutador de Laravel trabaje correctamente.

* **`storage/`**: contiene archivos generados por Laravel, como logs, cachés y otros archivos internos. ¡No tocar!

* **`tests/`**: contiene las pruebas automatizadas de la aplicación.

* **`vendor/`**: contiene las dependencias instaladas por Composer. ¡No tocar!.

También hay **algunos archivos muy importantes** en la raíz del proyecto:

* **`.env`**: contiene configuración específica del entorno en el que se ejecuta la aplicación.

* **`.env.example`**: sirve como ejemplo de las variables de entorno que necesita la aplicación.

* **`artisan`**: es el script que nos permite utilizar la consola de Laravel.

* **`composer.json`**: describe las dependencias PHP y otra información del proyecto.

* **`package.json`**: describe las dependencias y scripts relacionados con Node.js.

* **`compose.yaml`**: configuración para docker compose (sail).


No es necesario que memorices esta estructura. Cuando vayas trabajando con ella te familiarizarás sin darte cuenta.

### PASO 5. Crear el archivo `.env`

El archivo `.env` contiene **los valores de configuración** que pueden variar dependiendo del entorno en el que ejecutemos nuestra aplicación, como el nombre de la  base de datos o las credenciales para esa misma la base de datos.

Un archivo `.env` recién creado contiene, entre otras cosas, estas variables:

```text
APP_NAME=Laravel
APP_ENV=local
APP_KEY=
APP_DEBUG=true
APP_URL=http://localhost

DB_HOST=host_de_la_base_de_datos
DB_DATABASE=mi_base_de_datos
DB_USERNAME=usuaro_base_de_datos
DB_PASSWORD=password_base_de_datos
```

Laravel viene con **un archivo `.env.example`** que te sirve como punto de partida para construir tu `.env`. 

1. Buscar el archivo `.env.example` que debe venir con tu distribución limpia de Laravel.
2. Cópialo o renómbralo como `.env`.

**Importante:** recuerda que el archivo `.env` contiene información delicada y **no debe subirse a un repositorio Git**. ¡Comprueba que está en `.gitignore` antes de sincronizar nada!


### PASO 6. Probar artisan, la consola de Laravel

**Artisan** es una de las herramientas que más vas a utilizar durante el desarrollo de aplicaciones con Laravel. 

Se trata de una **interfaz de línea de comandos para interactuar con Laravel** y se usa para muchísimas tareas habituales, como crear controladores, modelos o migraciones, limpiar cachés, ejecutar tareas de mantenimiento, etc.

1. Abre un terminal de texto en el directorio del proyecto.
2. Comprueba que artisan funciona:

    ```bash
    $ ./vendor/bin/sail artisan   
    ```

    Esto debe mostrarte información sobre los comandos disponibles. Iremos viendo muchos de ellos conforme los necesitemos a lo largo del tema.

3. Prueba este comando concreto:

    ```bash
    $ ./vendor/bin/sail artisan route:list
    ```

    Esto te mostrará las rutas que Laravel tiene registradas en la aplicación. Como Laravel está limpio y recién instalado, solo deben aparecer estas:

    ```text
    GET|HEAD   / .......................
    GET|HEAD   up .....................
    ```

### PASO 7. Crear nuestra primera ruta

1. Abre el archivo `routes/web.php`. Este es el enrutador principal de Laravel.
2. Añade esto:

    ```php
    use Illuminate\Support\Facades\Route;

    Route::get('/hola', function () {
        return 'Hola mundo';
    });
    ```

3. Ejecuta el comando `./vendor/bin/sail artisan route:list`. Debería mostrarte una nueva ruta `/hola`.
4. En tu navegador web, visita la dirección `http://localhost/hola`. Deberías ver una página web que simplemente dice `Hola mundo`. ¡Acabas de hacer tu primer "Hola mundo" con Laravel.

#### ¿Qué ha ocurrido?

Hemos creado una ruta nueva en `web.php`, y le hemos dicho a Laravel que capture el endpoint `/hola` y ejecute un fragmento de código, un sencillo `return 'Hola mundo'`. 

Cuando Laravel recibe un texto como respuesta a una Request http, genera por defecto un documeto HTML con ese texto como contenido.

Por eso vemos `Hola mundo` al visitar el endpoint `http://localhost/hola`.

### PASO 8. Crear una ruta con un parámetro

1. Abre `routes/web.php` y añade:

    ```php
    Route::get('/saludo/{nombre}', function ($nombre) {
        return "Hola, $nombre";
    });
    ```

2. Visita, por ejemplo, `http://localhost/saludo/Ana`. Deberías ver una página en blanco con el texto "Hola, Ana".

   Si pruebas con otros nombres, la página cambiará.

#### ¿Qué ha ocurrido?

Hemos creado una **ruta parametrizada**.

Al crear la ruta o endpoint, hemos añadido `{nombre}` escrito entre llaves (`{ }`). La ruta resultante ha sido `hola/{nombre}`. 

Eso hace que Laravel coja *cualquier cosa* que se escriba a continuación de `http://localhost/hola` y la asigne a la variable `$nombre`. Por eso, al hacer `return "Hola, $nombre"` vemos exactamente el nombre que incluimos en el endpoint.

En cambio, si volvemos a pedir `http://localhost/hola`, Laravel seguirá generando un `Hola mundo`, porque la ruta `hola/{nombre}` **no coincide** con el endpoint que acabamos de solicitar y sí lo hace la ruta `/hola`.

### Una advertencia final: desarrollo frente a producción

El entorno que estamos utilizando es un **entorno de desarrollo**.

Laravel Sail está pensado precisamente para proporcionar un entorno Docker sencillo para desarrollar aplicaciones Laravel. Permite comenzar a programar pronto, sin necesidad de configurar trabajosamente un servidor.

Cuando una aplicación se pone en producción, se elige cuidadosamente una **configuración de producción**. En un servidor de producción normalmente utilizaremos una infraestructura diferente y configurada para las necesidades de la aplicación, donde primará la velocidad de ejecución y la seguridad por encima de la facilidad de puesta en marcha. 
