---
layout: page
title: 1.2 Contenedores con Docker
permalink: /docker/
nav_order: 2
has_children: false
parent: 1 Herramientas de desarrollo web
grand_parent: Desarrollo Web en Entorno Servidor
---

## 1.2. Contenedores con Docker
{: .no_toc }

- TOC
{:toc}


### 1.2.1. ¿Qué es Docker?

**Docker** es una herramienta de virtualización basada en *contenedores*.

Un **contenedor** es un **paquete de software completamente independiente del sistema donde se ejecuta**. Recibe ese nombre por los contenedores que se utilizan en el transporte marítimo, que tienen unas medidas y una forma estandarizada y que aíslan por completo la carga que llevan dentro del exterior.

Un contenedor Docker hace lo mismo, pero con un conjunto de software: lo aísla por completo del resto del sistema. El software que hay dentro del contenedor se puede ejecutar en cualquier máquina gracias al *runtime* de Docker (el programa que sabe interpretar y ejecutar contenedores), sin necesidad de instalar ni configurar nada de ese software directamente en tu ordenador.

**Un contenedor puede contener cualquier cosa**. Por ejemplo, un servidor Apache. De ese modo, podemos ejecutar Apache en cualquier máquina (siempre que tenga Docker instalado) sin necesidad de instalarlo de verdad, con todo lo que ello conlleva de configuración, dependencias, consumo de recursos, etc.

Un contenedor puede ponerse en marcha cuando queramos y detenerse en cualquier momento y, salvo que le digamos explícitamente lo contrario (ahora veremos cómo), no dejará ningún rastro permanente en la máquina anfitriona.

<div style="text-align: center; padding: 20px; background-color: #ccc">
<i>En definitiva, con Docker puedes usar y/o testear cualquier programa sin tener que instalarlo realmente, y su rendimiento es comparable al de una aplicación instalada de forma tradicional.</i>
</div>

#### Contenedores vs Imágenes

Los contenedores Docker se crean a partir de **imágenes**. Una imagen es como el "molde": contiene el software y todas sus dependencias ya instaladas y configuradas. A partir de una misma imagen puedes lanzar tantos contenedores como necesites. 

Dicho con términos de programación orientada a objetos: las imágenes son como las *clases*, y los contenedores son como los *objetos* que se instancian a partir de ellas.

Cada cual puede construir sus propias imágenes (con un archivo llamado *Dockerfile*, algo que estudiaréis en el módulo de *Despliegue de Aplicaciones Web*) o usar imágenes ya hechas por otros. 

Existen repositorios públicos de imágenes y el más conocido es **Docker Hub** (`hub.docker.com`), donde puedes encontrar imágenes oficiales de prácticamente cualquier software conocido. Allí buscaremos nuestros servidores para PHP, MySQL, Redis, Python, Apache, Nginx...

<div style="padding: 20px; background-color: #ccc" markdown="1">
**Un contenedor NO ES una máquina virtual**<br><br>
Este es un matiz importante. Una máquina virtual virtualiza hardware completo y arranca su propio sistema operativo entero, lo que la hace pesada y lenta de iniciar. Un contenedor Docker, en cambio, **comparte el núcleo (kernel) del sistema operativo anfitrión** y solo aísla el proceso mediante mecanismos del propio sistema operativo. Por eso un contenedor arranca en segundos (a veces milisegundos) y consume muchísimos menos recursos que una máquina virtual equivalente.
</div>

### 1.2.2. Instalación y comandos básicos de Docker

La forma más cómoda de tener Docker si usas **Windows** o **Mac** es instalar **Docker Desktop**, que incluye tanto el motor de Docker como una interfaz gráfica, así como **Docker Compose** ya integrado. 

En **Linux**, normalmente instalarás el paquete *Docker Engine* junto con el plugin de *Compose* desde el repositorio de tu distribución. En los ordenadores del instituto ya lo encontrarás todo instalado.

Aunque existe interfaz gráfica, lo habitual como desarrollador/a es trabajar con Docker **desde la línea de comandos**. 

Esto no pretende ser un manual completo de Docker (lo verás con más detalle en otros módulos), pero sí vamos a enumerar aquí, a modo de "chuleta", los comandos que más vas a necesitar como desarrollador/a web.

#### Chuleta con los comandos más frecuentes de Docker

* ```docker run [nombre-imagen]``` — Lanza un contenedor a partir de la imagen especificada. Si la imagen no está descargada en tu ordenador, Docker la descargará antes de Docker Hub (o del repositorio que tengas configurado).
* ```docker images``` — Lista las imágenes que ya tienes descargadas en tu máquina.
* ```docker ps``` — Muestra los contenedores que están actualmente en marcha. Con ```docker ps -a``` ves también los detenidos.
* ```docker stop [id-del-contenedor]``` — Detiene un contenedor en marcha. Su id (o su nombre) se obtiene con ```docker ps```.
* ```docker start [id-del-contenedor]``` — Vuelve a poner en marcha un contenedor detenido.
* ```docker rm [id-del-contenedor]``` — Elimina un contenedor (debe estar detenido). Esto borra su sistema de archivos interno: cualquier dato que no esté en un volumen (ver más abajo) se perderá para siempre.
* ```docker rmi [nombre-imagen]``` — Elimina una imagen descargada de tu disco.
* ```docker exec -it [id-del-contenedor] bash``` — Abre una terminal *dentro* de un contenedor en marcha. Muy útil para investigar qué está pasando ahí dentro. Si la imagen no trae `bash` instalado (es habitual en imágenes basadas en Alpine), prueba con `sh`.
* ```docker logs -f [id-del-contenedor]``` — Muestra en tiempo real lo que el contenedor va escribiendo en su salida estándar (por ejemplo, el log de peticiones de Apache). Imprescindible para depurar.

### 1.2.3. Docker Compose: orquestando varios contenedores a la vez

En cuanto tu proyecto necesita más de un contenedor (por ejemplo, un servidor web, una base de datos y una herramienta de administración), lanzarlos uno a uno a mano con `docker run`, recordando todos sus parámetros, se vuelve un infierno. Para eso existe **Docker Compose**.

Docker Compose te permite describir, en un único archivo llamado **`docker-compose.yml`**, todos los contenedores (llamados *servicios* en la jerga de Compose) que forman tu aplicación: qué imagen usa cada uno, qué puertos expone, qué variables de entorno necesita, qué volúmenes monta y de qué otros servicios depende. Con ese archivo escrito, levantar (o tirar abajo) toda tu infraestructura de desarrollo se reduce a un único comando.

#### ¿Con guion o sin guion?

Es posible que veas por internet el comando para ejecutar Docker Compose escrito a veces como `docker-compose` (con guion) y a veces como `docker-compose`(sin guion).

* La versión con guion es un programa aparte que hay que instalar manualmente. Se trata de la versión 1 de Compose y hoy en día se considera obsoleta, aunque sigue funcionando.
* En la actualidad, Compose viene integrado como un *plugin* del propio Docker, y el comando correcto de la versión 2 se escribe **sin guion y con espacio**: `docker compose`. 

#### Chuleta de comandos esenciales de Docker Compose

Los comandos esenciales de Compose, ejecutados en el directorio donde tengas tu `docker-compose.yml`, son:

* ```docker compose up -d``` — Crea y arranca todos los servicios definidos en el archivo. La opción `-d` hace que se ejecuten en segundo plano y te devuelva el control de la terminal.
* ```docker compose down``` — Detiene y elimina todos los contenedores del proyecto (conserva los volúmenes con nombre; ver la siguiente sección).
* ```docker compose ps``` — Muestra una lista con el estado actual de los servicio.
* ```docker compose logs -f``` — Muestra en tiempo real los logs de todos los servicios a la vez (o de uno solo, si añades su nombre: `docker compose logs -f web`).
* ```docker compose exec [servicio] bash``` — Abre una terminal dentro de uno de los servicios. Muy útil si necesitas *entrar* en el servicio virtualizado para ejecutar comandos en él.

### 1.2.4. Persistencia de datos

Por defecto, **todo lo que ocurre dentro de un contenedor es efímero**. Esto quiere decir que si tu contenedor escribe archivos en su propio sistema de ficheros interno y luego eliminas ese contenedor, esos archivos desaparecen sin dejar rastro. 

Esto es un problema serio en cuanto metemos, por ejemplo, una base de datos en un contenedor. ¡Si tu MySQL vive en un contenedor y ese contenedor se destruye, adiós a todos tus datos! 

Para evitarlo, existen los **volúmenes de Docker**, que sirven para que una carpeta del contenedor "sobreviva" fuera de él, es decir, en la máquina "real". 

Hay dos tipos de volúmenes que te interesa distinguir:

| Tipo | ¿Qué es? | ¿Cuándo se usa? |
|---|---|---|
| **Bind mount** | Una carpeta de *tu propio ordenador* se "engancha" a una ruta dentro del contenedor. Tú decides la ruta exacta en el host. | Para el código fuente de tu aplicación: así editas los archivos con tu editor de siempre y los cambios se reflejan al instante dentro del contenedor, sin reconstruir nada. |
| **Volumen con nombre** (*named volume*) | Docker gestiona el almacenamiento por ti, en un lugar interno que no necesitas conocer. Se declara con un nombre y Docker se encarga del resto. | Para datos que deben persistir pero que no necesitas mirar directamente, como los ficheros internos de una base de datos. |

En `docker-compose.yml`, los volúmenes se declaran así:

```yaml
services:
  web:
    image: php:8.3-apache
    volumes:
      - ./src:/var/www/html          # bind mount: carpeta local ./src
  db:
    image: mysql:8.4
    volumes:
      - db_data:/var/lib/mysql       # volumen con nombre: db_data

volumes:
  db_data:                           # hay que declararlo también aquí
```

**Cuidado con `docker compose down -v`.** El comando `docker compose down` normal **no** borra los volúmenes con nombre: tus datos de la base de datos sobrevivirán aunque tires abajo los contenedores y los vuelvas a levantar. Pero si añades la opción `-v` (`docker compose down -v`), sí que los borra. Resérvala solo para cuando quieras empezar de cero de verdad.

### 1.2.5. Cómo levantar un entorno de desarrollo para PHP con Docker Compose

Para comprender mejor todo esto, vamos a ver cómo montaríamos, con imágenes **oficiales** de Docker Hub, un entorno típico para desarrollar una aplicación PHP. 

Estas aplicaciones suelen necesitar varios servicios:

* **Un servidor web con PHP** integrado
* **Una base de datos MySQL** (o MariaDB, SQLite, MongoDB o cualquier otra)
* **PHPMyAdmin** para administrar visualmente la base de datos.

La estructura de carpetas de un proyecto así puede ser como esta:

```
mi-proyecto/
├── docker-compose.yml    <--- Archivo de configuración de Docker Compose
├── php/
│   └── custom.ini        <--- Configuración adicional para PHP
└── src/
    └── index.php         <--- Punto de entrada de la aplicación PHP
```

En nuestro **`docker-compose.yml`** indicaremos las imágenes oficiales de Apache con PHP, de MySQL y de PHPMyAdmin. Los números que hay al lado del nombre de la imagen se refieren a la versión. Por ejemplo, con este archivo instalaremos PHP 8.3 o MySQL 8.4:

```yaml
services:
  web:
    image: php:8.3-apache
    ports:
      - "8080:80"
    volumes:
      - ./src:/var/www/html
      - ./php/custom.ini:/usr/local/etc/php/conf.d/custom.ini:ro
    depends_on:
      - db

  db:
    image: mysql:8.4
    environment:
      MYSQL_ROOT_PASSWORD: root
      MYSQL_DATABASE: practica
      MYSQL_USER: dev
      MYSQL_PASSWORD: dev
    volumes:
      - db_data:/var/lib/mysql

  phpmyadmin:
    image: phpmyadmin
    environment:
      PMA_HOST: db
    ports:
      - "8081:80"
    depends_on:
      - db

volumes:
  db_data:
```

Algunas cosas que conviene que entiendas de este archivo:

* Usamos la imagen oficial **`php:8.3-apache`**, que trae Apache y PHP ya integrados en un único contenedor. Es la forma más directa de levantar un servidor PHP para desarrollo, sin tener que andar conectando dos contenedores Apache y PHP independientes.
* El servicio `web` publica el **puerto 80** del contenedor (el puerto estándar de HTTP) en el **puerto 8080** de tu máquina (eso significa `"8080:80"`), así que accederás a tu aplicación en la URL **http://localhost:8080**. Es importante elegir un puerto libre en tu máquina, porque si ya tienes otro servidor usando ese puerto en tu equipo, el contenedor no podrá arrancar. Por eso se elige el puerto 8080, que suele estar libre y "recuerda" al puerto 80 estándar de HTTP.
* La carpeta `./src` de tu proyecto se monta como *bind mount* en `/var/www/html`. Es decir, los archivos que haya en la carpeta `./src` de tu disco duro y los que haya en la carpeta `/var/www/html` dentro del contenedor serán exactamente los mismos. Y esa es precisamente la carpeta donde Apache busca los archivos que tiene que servir. ¡Cualquier cambio que hagas en `./src` se ve reflejado al momento!
* Para la imagen de **`mysql:8.4`** usamos unas variables de entorno para configurar el usuario root, la base de datos inicial, el usuario y la contraseña de desarrollo. Los datos se guardarán en un volumen con nombre `db_data`, así que sobrevivirán aunque reinicies los contenedores.
* **phpMyAdmin** se conecta automáticamente al servicio `db` gracias a la variable `PMA_HOST: db`. Puedes acceder a él en la URL **http://localhost:8081**.

Para poner en marcha todo este enooorme entorno de desarrollo, simplemente teclea este comando:

```
$ docker compose up -d
```

Y para detenerlo:

```
$ docker compose down
```

<div class="box warn" markdown="1">
**OJO: Las contraseñas de este ejemplo son solo para desarrollo local.** 
Nunca subas a tu repositorio un `docker-compose.yml` con contraseñas reales escritas tal cual, ni lo uses así en un servidor accesible desde fuera. En un entorno real, esos valores se suelen colocar en un archivo llamado `.env` (que se añade a `.gitignore`, para que no esté en los repositorios de código).
</div>

### 1.2.6. Ajustando la configuración de PHP

Es habitual que tengas que tocar alguna directiva del **`php.ini`**, el archivo de configuración del intérprete PHP. 

Si trabajaras con un PHP instalado de forma nativa en tu máquina, bastaría con localizar ese archivo, editarlo y reiniciar el servidor. Pero, como el PHP vive ahora dentro de la imagen del contenedor, editar un `php.ini` que esté "dentro" no sirve de nada: en cuanto reconstruyas o vuelvas a crear el contenedor, tus cambios habrán desaparecido, porque formaban parte de una capa efímera de la imagen, no de un volumen.

La solución, igual que con los datos de la base de datos, es la **persistencia mediante volúmenes**: en vez de editar el `php.ini` de dentro del contenedor, **montamos nuestro propio archivo de configuración adicional** desde fuera, que suele llamarse `custom.ini`. Las imágenes oficiales de PHP están preparadas, en realidad, para cargar junto con `php.ini` cualquier archivo `.ini` que coloques en `/usr/local/etc/php/conf.d/` dentro del contenedor.

Y eso es justo lo que hemos hecho en nuestro `docker-compose.yml`: montar `./php/custom.ini` en esa ruta. El contenido de ese `custom.ini` podría ser algo así:

```ini
display_errors = On
error_reporting = E_ALL
opcache.enable = 0
upload_max_filesize = 20M
post_max_size = 20M
max_execution_time = 120
memory_limit = 256M
```

Te contamos a continuación lo que significan todas estas directivas.

#### Directivas que (probablemente) tendrás que tocar en desarrollo

* **Mostrar los errores en pantalla**: `display_errors = On` y `error_reporting = E_ALL`. En producción, esto debe estar desactivado (`display_errors = Off`), porque mostrar los errores al usuario final es un problema de seguridad.
* **Desactivar la caché de opcode**: `opcache.enable = 0`. Con la caché activada, PHP no siempre detecta que has modificado un archivo y puede seguir ejecutando una versión antigua compilada en memoria. En producción, en cambio, `opcache` **sí** debe estar activada: mejora mucho el rendimiento.
* **Subida de archivos y tiempos de ejecución**: `upload_max_filesize`, `post_max_size`, `max_input_time`, `max_execution_time` y `memory_limit`, según lo que necesite tu aplicación.

<div class="box" markdown="1">
**¿Y Xdebug?** Si quieres depurar tu código PHP paso a paso desde tu editor, necesitarás instalar la extensión **Xdebug**, que no viene incluida en la imagen oficial de PHP por defecto. Esto ya requiere construir tu propia imagen a partir de un `Dockerfile` (añadiendo `RUN pecl install xdebug && docker-php-ext-enable xdebug`), algo que queda fuera del alcance de este apartado, pero que puedes explorar por tu cuenta si te apetece ir un paso más allá.
</div>

### 1.2.7. ¿Y qué pasa con Redis, Python y otros servicios?

Todo lo que has visto en este apartado se puede aplicar exactamente igual a cualquier otro servicio que necesites añadir a tu `docker-compose.yml`. 

Por ejemplo, **Redis** es un servicio que se usa, entre otras cosas, para cachear resultados de una base de datos y acceder a ellos más rápidamente. Añadirlo a tu stack de servicios es tan sencillo como añadir esto a `docker-compose.yml`:

```yaml
  redis:
    image: redis:7
    ports:
      - "6379:6379"
```

Y una aplicación **Python** (algo que retomaremos con más calma cuando lleguemos a FastAPI y los microservicios) se usa con Docker de forma parecida, normalmente a partir de una imagen oficial `python:3.x-slim`, sobre la que se instalan las dependencias del proyecto. 

Así que la idea de fondo es siempre la misma: una imagen por servicio, un contenedor por instancia, y Compose organizando cómo se relacionan los contenedores entre sí.

### 1.2.8. De un entorno de desarrollo a un entorno de producción

Todo lo que hemos montado en este apartado está pensado **exclusivamente para desarrollo local**. 

Cuando tengas que desplegar todo esto en un servidor de verdad (algo que haremos al final del curso) hay bastantes cosas que debes cambiar, pero conviene que sepas ya, aunque sea de forma superficial, que existen estas diferencias:

* **Nada de bind mounts para el código.** En producción, el código de la aplicación se copia *dentro* de la imagen al construirla, y esa imagen es la que se despliega. Los bind mounts son cómodos en desarrollo precisamente copian los cambios al interior del contenedor en el acto. Pero eso mismo es indeseable en producción, cuando quieres que lo que se ejecute sea exactamente lo que probaste, ni una línea más.
* **`display_errors` a `Off`, `opcache` activada**, y en general, toda configuración de depuración en PHP desactivada.
* **Contraseñas y claves fuera del `docker-compose.yml`**, gestionadas mediante variables de entorno inyectadas de forma segura (desde archivos `.env`, por ejemplo).
* **No publiques puertos que no necesites exponer al exterior.** Por ejemplo, el puerto de la base de datos no debería estar accesible desde fuera de la red interna de contenedores; y herramientas como phpMyAdmin, si se usan en producción, deben protegerse muy bien. O, mejor aún, no desplegarse en producción en absoluto.
* **Versiones de imagen fijas.** Es preferible usar algo como `mysql:8.4` en lugar de `mysql:latest`. Esto último hará que Docker use la última versión disponible de la imagen mysql, y te puedes llevar una sorpresa el día que un cambio de versión repentino haga que tu aplicación no funcione.
* **Políticas de reinicio y límites de recursos.** En producción se configuran cosas los límites de CPU y memoria por contenedor, para que ningún contenedor pueda acaparar todos los recursos del servidor, y otras cuestiones relativas al rendimiento y recuperación automática ante fallos.
* **Uso de proxy inverso** que se encarga de servir HTTPS (con certificados TLS) y repartir el tráfico entre servicios. En producción, no es habitual exponer los contenedores directamente.

### 1.2.9. ¿Quieres saber más?

* Documentación oficial de Docker: [docs.docker.com](https://docs.docker.com/)
* Referencia completa de Docker Compose: [docs.docker.com/compose](https://docs.docker.com/compose/)
* Imágenes oficiales en Docker Hub: [PHP](https://hub.docker.com/_/php), [MySQL](https://hub.docker.com/_/mysql), [Redis](https://hub.docker.com/_/redis), [Python](https://hub.docker.com/_/python)

### 1.2.10. Práctica de Docker

#### Objetivos de la práctica

Con esta práctica vamos a **crear una infraestructura de desarrollo web con PHP** desde cero y vamos a escribir y ejecutar un programa muy simpe en PHP para comprobar que la infraestructura funciona.

Ten en cuenta que esta misma infraestructura nos servirá para hacer aplicaciones web con PHP mucho más complejas sin cambiar absolutamente nada.

La práctica utiliza únicamente imágenes de Docker Hub ya construidas. No tendrás que crear ningún `Dockerfile` para construir tus propias imágenes (eso lo harás en el módulo de *Despliegue de Aplicaciones Web*).

<div style="padding: 20px; background-color: #ccc" markdown="1">
<strong style="color:#900">¡ATENCIÓN! </strong>
A lo largo de la práctica verás varios recuadros como este donde se te pedirá que respondas a algunas preguntas. Cuando entregues la práctica, no solo tendrás que subir a Moodle Centros el código fuente de la misma, sino también un documento con las respuestas a estas preguntas.
</div>

---

#### Qué pretendemos hacer

Vamos a crear el entorno realista para desarrollar aplicaciones web con PHP.

En lugar de **instalar Apache, PHP, MySQL y phpMyAdmin** directamente en tu ordenador, vas a crear un entorno de desarrollo idéntico, pero utilizando Docker.

Usaremos esta estructura de carpetas:

```text
┌───────────────────────────────────────────────┐
│                                               │
│   docker-php/                                 │
│   ├── docker-compose.yml                      │
│   ├── php/                                    │
│   │   └── custom.ini                          │
│   └── src/                                    │
│       └── index.php                           │
└───────────────────────────────────────────────┘
```

La carpeta `src` **contendrá el código fuente**, que en esta aplicación será un simple `index.php` pero, más adelante, se complicará con muchos otros archivos. Gracias al *bind mount*, podrás editar los archivos con tu editor habitual y Apache, aunque esté dentro de un contenedor, los verá inmediatamente.

Vamos a guiarte paso a paso para que consigas montar y probar este entorno de desarrollo web.

---

#### PASO 1. Crear el proyecto

* Crea una carpeta llamada `docker-php` en cualquier lugar de tu disco duro.
* Dentro de ella, crea la estructura de directorios que hemos puesto más arriba (los archivos `docker-compose.yml`, `custom.ini` e `index.php` son archivos de texto que pueden estar vacíos de momento).
* Abre `docker-compose.yml` y transcribe *exactamente* el contenido que hay más abajo.


<div style="padding: 20px; background-color: #ccc" markdown="1">
<strong style="color:#900">PREGUNTA 1. </strong>
Crea un documento `respuestas.doc` nuevo. Analizando el archivo `docker-compose.yml` que tienes aquí abajo, responde a estas preguntas. Redacta tus respuestas en `respuestas.doc` (investiga en Internet si hay cosas que no sabes):

   * **1a)** ¿Qué servicio utiliza el puerto 8080 de nuestro ordenador?
   * **1b)** ¿Qué puerto del contenedor corresponde al puerto 8080 de nuestro ordenador?
   * **1c)** ¿Qué servicio utiliza el puerto 8081?
   * **1d)** ¿Por qué el servicio `db` no necesita publicar ningún puerto?
</div>

Este es el archivo `docker-compose.yml` que debes tener en tu proyecto. Es importante que comprendas lo que pone en él, porque es el corazón del entorno de desarrllo:

```yaml
services:

  web:
    image: php:8.3-apache

    ports:
      - "8080:80"

    volumes:
      - ./src:/var/www/html
      - ./php/custom.ini:/usr/local/etc/php/conf.d/custom.ini:ro

    depends_on:
      - db

  db:
    image: mysql:8.4

    environment:
      MYSQL_ROOT_PASSWORD: root
      MYSQL_DATABASE: practica
      MYSQL_USER: dev
      MYSQL_PASSWORD: dev

    volumes:
      - db_data:/var/lib/mysql

  phpmyadmin:
    image: phpmyadmin

    environment:
      PMA_HOST: db

    ports:
      - "8081:80"

    depends_on:
      - db

volumes:
  db_data:
```

#### PASO 2. Configurar PHP para desarrollo

* Abre el archivo `php/custom.ini`
* Escribe en él este contenido:
  ```ini
  display_errors = On
  error_reporting = E_ALL
  opcache.enable = 0

  upload_max_filesize = 20M
  post_max_size = 20M
  max_execution_time = 120
  memory_limit = 256M
  ```

<div style="padding: 20px; background-color: #ccc" markdown="1">
<strong style="color:#900">PREGUNTA 2. </strong>
Responde en el documento `respuestas.doc` a estas preguntas (investiga un poco por ahí si lo necesitas):

   * **2a)** ¿Por qué necesitamos crear el archivo `custom.ini`?
   * **2b)** ¿Qué significa cada una de las líneas de nuestro `custom.ini`?
</div>


#### PASO 3. Crear la primera aplicación PHP

Vamos a crear una aplicación PHP muy sencilla, aunque aún no sepamos nada de PHP.

* Abre `src/index.php` y escribe exactamente este contenido:

  ```php
  <!DOCTYPE html>
  <html lang="es">
  <head>
      <meta charset="UTF-8">
      <title>Mi primer servidor PHP</title>
  </head>
  <body>

      <h1>¡Mi servidor PHP funciona!</h1>

      <p>Esta página está siendo ejecutada por PHP dentro de Docker.</p>

      <p>
          <?php
              echo "PHP está funcionando correctamente.<br>";
              $n = 6;
              echo "Esta es es la tabla de multiplicar del número $n: <br>";
              for ($i = 1; $i <= 10; $i++) {
                   echo "$n x $i = ". $n * $ i ."<br>";
              }
          ?>
      </p>

  </body>
  </html>
  ```

#### PASO 4. Levantar el entorno de ejecución

* Abre una terminal de texto dentro de la carpeta `docker-php`.
* Ejecuta el comando:

  ```bash
  $ docker compose up -d
  ```

  (La primera vez Docker tendrá que descargar las imágenes necesarias desde Docker Hub, por lo que este proceso puede tardar un poco).

  (Recuerda que la opción `-d` hace que los servicios se ejecuten en segundo plano, para no bloquear la terminal).

* Cuando se hayan descargado las imágenes y los contenedores hayan arrancado, comprueba que están en estado *running* o *up* con el comando:

  ```bash
  $ docker compose ps
  ```

  (Deberías encontrar tres servicios en funcionamiento: web, db y phpmyadmin).

* Si algo no funciona, no empieces a modificar cosas al azar. En lugar de eso, ejecuta este comando y trata de buscar la causa del error:

  ```bash
  $ docker compose logs
  ```

  (El objetivo es que empieces a utilizar los logs, y no la intuición ni la iluminación divina, como herramienta de diagnóstico).

<div style="padding: 20px; background-color: #ccc" markdown="1">
<strong style="color:#900">PREGUNTA 3. </strong>
Pega en el documento `respuestas.doc` la salida del comando `docker compose ps`.
</div>


#### PASO 5. Probar y modificar la aplicación PHP

* Abre un navegador web y visita la dirección **http://localhost:8080**. Deberías ver:

> ¡Mi servidor PHP funciona! PHP está funcionando correctamente.

   ...seguido de la tabla de multiplicar del número 6.

* Modifica el archivo `index.php` para que, además de la tabla de multiplicar, nos diga si el número $n es par o impar y si es positivo o negativo (no tengas miedo: la sintaxis de PHP es muy parecida a la de Java)
* Guarda el archivo `index.php` y vuelve a cargar la página **http://localhost:8080** para comprobar si tus cambios funcionan.
* En caso de error de ejecución, revisa el código fuente hasta que logres que el programa funcione.

<div style="padding: 20px; background-color: #ccc" markdown="1">
<strong style="color:#900">PREGUNTA 4. </strong>
Responde en el documento `respuestas.doc` a estas preguntas:

   * **4a)** ¿Por qué los cambios en `index.php` se han reflejado inmediatamente en el contenedor? ¿Qué tiene esto que ver con el **bind mount**?
   * **4b)** ¿PHP te ha mostrado algún mensaje de error cuando has modificado el código fuente? ¿Qué mensaje o mensajes han sido?
</div>


#### PASO 6. Comprobar phpMyAdmin y la persistencia de MySQL

* Abre la URL **http://localhost:8081** (fíjate en el puerto, que es 8081 en lugar de 8080).
* Debe aparecer la pantalla de autenticación de phpMyAdmin. Utiliza estas credenciales (que se configuraron en `docker-compose.yml`):
  ```text
  Servidor: db
  Usuario: dev
  Contraseña: dev
  ```

* Comprueba que existe la base de datos llamada `practica` (también se configuró en `docker-compose.yml`), que debería estar vacía.
* En phpMyAdmin, dentro de la base de datos `practica`, crea una tabla sencilla llamada `alumnos` con los campos `id` (INTEGER) y `nombre` (VARCHAR 100)
* Inserta un par de alumnos de prueba en la tabla que acabas de crear. Invéntate los datos.
* Vuelve a la terminal y echa abajo todos los contenedores:

  ```bash
  $ docker compose down
  ```

* Comprueba que los contenedores han desaparecido:

  ```bash
  $ docker compose ps
  ```

* Comprueba que ahora PHP no responde: ve a tu navegador web y carga la URL **http://localhost:8080**. Debería darte el error de "localhost ha rechazado la conexión" o algo parecido.
* Vuelve a levantar el entorno:

  ```bash
  $ docker compose up -d
  ```

* Entra nuevamente en **http://localhost:8080**: PHP debe estar ahí de nuevo.
* Entra nuevamente en **http://localhost:8081** y accede a PHPMyAdmin. Si todo ha ido bien, la base de datos `practica` debería seguir existiendo, con una tabla `alumnos` que contendrá los mismos datos que habías añadido antes.

<div style="padding: 20px; background-color: #ccc" markdown="1">
<strong style="color:#900">PREGUNTA 5. </strong>
Responde en el documento `respuestas.doc` a estas preguntas:

   * **5a)** ¿Por qué no se ha borrado la tabla aunque hayamos eliminado los contenedores?
   * **5b)** ¿Qué nombre recibe, en `docker-compose.yml`, el volumen para MySQL?
   * **5c)** ¿Cómo podríamos forzar el borrado de la tabla al echar abajo los contenedores? (investígalo si aún no lo sabes)
   * **5d)** ¿Cómo podríamos abrir un terminal de texto *dentro* del contenedor de MySQL para ejecutar comandos en él?
</div>

#### Entrega

Sube a Moodle Centros el documento `respuestas.pdf` obtenido a partir de `respuestas.doc` con las respuestas a las cinco preguntas de la práctica.

Sube también todo el contenido de tu proyecto comprimido en un único archivo .zip

(El profesor/a debería poder descargar el .zip, descomprimirlo y obtener una réplica exacta de tu entorno de desarrollo con solo escribir `docker compose up -d`).

#### Ampliaciones opcionales

(Solo si acabas la práctica antes que tus compañeros y quieres profundizar un poco más)

**Ampliación 1: página de información**

Modifica `index.php` para que muestre la versión de PHP, la fecha y hora actuales y el nombre del servidor.
Investiga las funciones o constantes necesarias para lograrlo.

**Ampliación 2: investigar el entorno**

Abre un terminal dentro del contenedor `web` y ejecuta el comando `php -m`.
Investiga qué extensiones de PHP están disponibles.

**Ampliación 3: añadir Redis**

Añade al `docker-compose.yml` un cuarto servicio:

```yaml
redis:
  image: redis:7
```

Comprueba que el servicio se levanta correctamente.

#### Rúbrica de corrección

Esta práctica se calificará siguiendo la siguiente rúbrica:
* 0 = sin hacer o sin evidencia de esfuerzo
* 1 = hecho pero incorrecto
* 2 = hecho correctamente, pero mejorable
* 3 = hecho superando las espectativas

Se calificarán de 0 a 3, según la rúbrica anterior, los siguientes ítems evaluables, que tendrán un peso diferente en la puntación final, tal como está indicado en esta tabla:

| Criterio | Peso |
|---|---:|
| Estructura de carpetas y archivos correcta | 5% |
| `docker-compose.yml` correctamente configurado con los tres servicios | 5% |
| Apache + PHP funcionando en `localhost:8080` | 5% |
| Aplicación PHP funcionando y mostrando que PHP se ejecuta | 5% |
| phpMyAdmin funcionando y conectado a MySQL | 5% |
| Base de datos `practica` correctamente creada | 10% |
| Comprende la correspondencia de puertos entre servicios Docker y la máquina anfitrión (pregunta 1) | 5% |
| Comprende la necesidad y utilidad de `custom.ini` (pregunta 2) | 5% |
| Levanta y comprueba el entorno de ejecución (pregunta 3) | 10% |
| Comprende el concepto de bind mount (pregunta 4) | 10% |
| Modifica correctamente un archivo .php sencillo (pregunta 4) | 10% |
| Comprende el concepto de persistencia de volúmenes (pregunta 5) | 10% |
| Abre terminales dentro de los servicios y ejecuta comandos en ellas (pregunta 5) | 5% |
| Entrega de la práctica en tiempo y forma | 10% |
| **TOTAL** | **100%** |

**IMPORTANTE**

Para considerar la práctica **superada**, deberán cumplirse como mínimo estos cuatro requisitos, independientemente de la nota que salga de aplicar la rúbrica:

- `docker compose up -d` funciona.
- `localhost:8080` muestra la aplicación PHP modificada por ti.
- `localhost:8081` permite acceder a phpMyAdmin.
- La base de datos sobrevive a `docker compose down` + `docker compose up -d`.

