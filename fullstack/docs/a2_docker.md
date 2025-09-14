---
layout: page
title: Apéndice 2. Virtualización con Docker
permalink: /docker/
nav_order: 7
has_children: false
parent: Desarrollo web full stack
---
# Apéndice 2. Virtualización con Docker
{: .no_toc }

- TOC
{:toc}


## A2.1. ¿Qué es Docker?

**Docker** es una herramienta de virtualización basada en *contenedores*.

Un **contenedor** es un paquete de software completamente independiente del sistema donde se ejecuta. Recibe ese nombre por los contenedores que se utilizan en el transporte marítimo, que tienen unas medidas y una forma estandarizada y que aislan por completo la carga que llevan dentro del exterior.

Un contenedor Docker hace lo mismo, pero con un conjunto de software: lo aisla por completo del exterior. El software que hay dentro del contenedor se puede ejecutar en cualquier máquina gracias al *runtime* de Docker, que se comporta como un mini-sistema operativo virtualizado que corre sobre la máquina anfitrión.

Un contenedor puede contener cualquier cosa. Por ejemplo, Apache. De ese modo, podemos ejecutar Apache en cualquier máquina (siempre que tenga previamente instalado Docker) sin necesidad de instalarlo realmente, con todo lo que ello conlleva de configuración de la máquina, consumo de recursos, etc. El contenedor Docker puede ponerse en marcha cuando queramos y detenerse en cualquier momento, sin dejar ningún rastro en la máquina anfitriona.

En definitiva, puedes usar y/o testear *cualquier* programa sin tener que instalarlo realmente en tu máquina.

Los contenedores Docker vienen empaquetados en **imágenes**, a partir de los cuales pueden lanzarse todos los contenedores que necesitemos. Es decir, las imágenes con como las *clases* en programación orientada a objetos, y los contenedores son como los objetos que se instancian a partir de esas clases.

Cada cual puede construir las imágenes que necesite o usar imágenes ya hechas, con todo lo necesario en su interior para ejecutar cualquier software sin necesidad de instalarlo ni configurarlo. Hay repositorios públicos de imágenes, como **DockerHub**, donde uno puede encontrar imágenes de prácticamente cualquier cosa.

## A2.2. Comandos usuales de Docker

Aunque Docker puede usarse desde un interfaz gráfico (como **Docker Desktop**), lo habitual es hacerlo desde la línea de comandos.

Esto no es un manual de Docker, pero sí vamos a enumerar aquí los comandos principales que nos serán útiles como desarrolladores web para que puedas usarlos como referencia rápida cuando tengas que trabajar con Docker.

* ```docker run [nombre-imagen]``` - Lanza un contenedor a partir de la imagen especificada. Si la imagen no está descargada en el ordenador, la buscará en el repositorio configurado (por defecto, *DockerHub*).
* ```docker ps``` - Muestra un listado con los contenedores que hay actualmente en el sistema. Un contenedor no tiene por qué estar necesariamente corriendo, sino que existen otros estados (detenido, preparado, finalizado, etc). Con ```docker ps -a``` podemos ver todos los contenedores, también los detenidos.
* ```docker stop [id-del-contenedor]``` - Detiene un contenedor. Su id puede obtenerse con ```docker ps```.
* ```docker start [id-del-contenedor]``` - Reanuda un contenedor.
* ```docker exec -it [id-del-contenedor] bash``` - Abrir un terminal en el contenedor.
* ```docker-compose up -d``` - Inicia todos los contenedores especificados en el archivo *docker-compose.yml* del directorio actual. Necesitas tener instalado, además de Docker, el programa *docker-compose*.
* ```docker-compose down``` - Detiene todos los contenedores especificados en el archivo *docker-compose.yml* del directorio actual.

## A2.3. Persistencia de datos

Cualquier cosa que guardes en un contenedor de Docker se perderá cuando el contenedor se detenga. Por ejemplo, si estás haciendo una aplicación web que usa una base de datos MySQL, y tu servidor MySQL está en un contenedor Docker, toda la información de esa base de datos se perderá cada vez que destruyas el contenedor.

Es posible evitar eso usando la persistencia de datos. Consiste en pedirle a Docker que guarde datos *fuera* del contenedor, para que estos no se pierdan al reiniciarlo o eliminarlo. Por ejemplo, los datos de la base de datos.

La persistencia se puede habilitar con **docker run**. Por ejemplo:

```
$ docker run -d --name mysql-container -e MYSQL_ROOT_PASSWORD=clave123 -v mysql-data:/var/lib/mysql mysql:latest
```

La persistencia se habilita con *-v mysql-data:/var/lib/mysql*, que crea (o usa) un volumen llamado *mysql-data* y lo monta en la ruta */var/lib/mysql* de la máquina real, que es donde MySQL suele guardar los datos.

Personalmente, encuentro más sencillo hacerlo todo a través de **docker-compose**. Por ejemplo, mira este archivo de configuración docker-compose.yml:

```yaml
services:
  mysql:
    image: mysql:latest
    container_name: mysql-container
    volumes:
      - mysql-data:/var/lib/mysql
    ports:
      - "3306:3306"

volumes:
  mysql-data:
```

Con este archivo de configuración se lanzará un contenedor de *mysql* en cuanto tecleemos *docker-compose up*. Observa estas dos líneas:

* La línea *volumes* dentro del servicio *mysql* monta el volumen virtual *mysql-data* en */var/lib/mysql*, el lugar de la máquina real donde MySQL suele guardar los datos.
* La línea *volumes* al final del archivo declara el volumen llamado *mysql-data*, que Docker creará si no existe.

Así, los datos persisten en */var/lib/mysql* aunque detengas o elimines el contenedor.

## A2.4. Montando con Docker un servidor web con persistencia de datos

En esta sección vamos a mostrar cómo montar un servidor web con imágenes Docker y levantarlo o apagarlo con docker-compose.

Usaremos las imágenes oficiales de cada desarrollador, y necesitaremos poner en marcha **cuatro contenedores** simultáneamente, por lo que será mucho más cómodo hacerlo con docker-compose para poder levantarlas todas a la vez y no de una en una:

1. **Servidor Apache**
2. **Intérprete PHP**
3. **Servidor MariaDB**
4. **PHPMyAdmin**

Además, necesitamos que los datos de MariaDB sean persistentes, es decir, que no se pierdan cuando detengamos los contenedores.

Para lograr todo esto, sigue estos pasos:

### Paso 1. Crear ./docker-compose.yml

Crea un archivo ***docker-compose.yml*** en tu directorio de trabajo con este contenido exacto, para trabajar con las imágenes oficiales de nuestros cuatro servicios:

```yaml
services:
  php:
    image: php:8.2-fpm
    volumes:
      - ./app:/app
      - ./custom.ini:/usr/local/etc/php/conf.d/custom.ini

  apache:
    image: httpd:2.4
    ports:
      - "8080:80"
    volumes:
      - ./app:/app
      - ./apache-custom/httpd.conf:/usr/local/apache2/conf/httpd.conf:ro
      - ./apache-custom/myapp.conf:/usr/local/apache2/conf/extra/myapp.conf:ro
    depends_on:
      - php

  mariadb:
    image: mariadb:10.6
    environment:
      MYSQL_ROOT_PASSWORD: 1234
      MYSQL_DATABASE: pruebas
      MYSQL_USER: user
      MYSQL_PASSWORD: 1234
    volumes:
      - mariadb_data:/var/lib/mysql

  phpmyadmin:
    image: phpmyadmin/phpmyadmin
    ports:
      - "8000:80"
    environment:
      PMA_HOST: mariadb
    depends_on:
      - mariadb

volumes:
  mariadb_data:
```

### Paso 2. Crear ./apache-custom/httpd.conf

Por defecto, la imagen oficial de Apache no interpreta el código PHP, sino que lo sirve en texto plano, como si fuera HTML.

Para reconfigurar esa imagen sin tener que meter mano al Dockerfile (algo que aprenderás a hacer en otros módulos) tienes que:

1. Crear el directorio ***apache-custom*** en tu carpeta de trabajo.
2. Crear el archivo ***httpd.conf*** dentro de *apache-custom* con este contenido:

```
# httpd.conf mínimo preparado para usar Apache httpd:2.4 + PHP-FPM

ServerRoot "/usr/local/apache2"

# Puerto en el que Apache escuchará dentro del contenedor
Listen 80

# Módulos esenciales
LoadModule mpm_event_module modules/mod_mpm_event.so
LoadModule authn_core_module modules/mod_authn_core.so
LoadModule authz_core_module modules/mod_authz_core.so
LoadModule unixd_module modules/mod_unixd.so
LoadModule dir_module modules/mod_dir.so
LoadModule mime_module modules/mod_mime.so
LoadModule log_config_module modules/mod_log_config.so
LoadModule env_module modules/mod_env.so
LoadModule setenvif_module modules/mod_setenvif.so
LoadModule alias_module modules/mod_alias.so
LoadModule negotiation_module modules/mod_negotiation.so
LoadModule autoindex_module modules/mod_autoindex.so
LoadModule headers_module modules/mod_headers.so

# Módulos necesarios para proxying a PHP-FPM
LoadModule proxy_module modules/mod_proxy.so
LoadModule proxy_fcgi_module modules/mod_proxy_fcgi.so

# Información del servidor
ServerAdmin you@example.com
ServerName localhost:80

# Archivos de tipos mime
TypesConfig conf/mime.types

# Logs: enviar a stdout/stderr para que docker-compose logs funcione bien
ErrorLog /proc/self/fd/2
CustomLog /proc/self/fd/1 common

# Seguridad por defecto
<Directory />
    AllowOverride none
    Require all denied
</Directory>

# DocumentRoot por defecto
DocumentRoot "/usr/local/apache2/htdocs"
<Directory "/usr/local/apache2/htdocs">
    Options Indexes FollowSymLinks
    AllowOverride None
    Require all granted
</Directory>

# Índices (queremos que index.php tenga preferencia sobre index.html)
<IfModule dir_module>
    DirectoryIndex index.php index.html
</IfModule>

# Incluimos el virtualhost personalizado que defines en apache-custom/myapp.conf
Include conf/extra/myapp.conf

# Fin del archivo
```

### Paso 3. Crear ./apache-custom/myapp.conf

En este archivo de configuración adicional redirigiremos todas las peticiones de archivos .php hacia el contenedor con el intérprete PHP. El resto de archivos serán servidos por Apache.

Crea el archivo ***myapp.conf*** dentro del directorio *apache-custom* con este contenido:

```
<VirtualHost *:80>
    DocumentRoot "/app"

    <Directory "/app">
        Options Indexes FollowSymLinks
        AllowOverride All
        Require all granted
        DirectoryIndex index.php
    </Directory>

    # Enviar todas las peticiones a .php al FPM del contenedor `php`
    ProxyPassMatch ^/(.*\.php(/.*)?)$ fcgi://php:9000/app/$1
</VirtualHost>
```

### Paso 4. Crear el archivo custom.ini

Este archivo contiene las **opciones de configuración adicionales para PHP**.

PHP se configura dentro del contenedor correspondiente, en un archivo llamado *php.ini*. Podemos agregar configuraciones adicionales sin necesidad de tocar el contenedor con un archivo de configuración adicional que mapearemos al interior del contenedor.

Crea un archivo llamado ***custom.ini*** en tu directorio de trabajo con este contenido:

```
display_errors = On
error_reporting = E_ALL
opcache.enable = 0
extension=pdo
extension=pdo_mysql
```

Esto habilitará la extensión PDO para MySQL y las opciones de depuración de errores. En un entorno de producción, estas opciones se cambiarían, claro.

Si necesitas configuraciones adicionales para PHP (como incrementar el tamaño máximo de archivos subidos al servidor o el tiempo de procesamiento de un script), puedes hacerlo en este custom.ini y volver a levantar el servidor.

### Paso 5. Crear un Dockerfile personalizado para PHP

La extensión PDO para MySQL no viene instalada por defecto en la imagen oficial de PHP-FPM. Debemos modificar la imagen para poder usar esta extensión.

Lo más adecuado para ello es crear un archivo ***Dockerfile*** con este contenido:

```
# 1. Base PHP-FPM oficial
FROM php:8.2-fpm

# 2. Instalar dependencias necesarias para pdo_mysql
RUN apt-get update && apt-get install -y \
        default-mysql-client \
        libzip-dev \
        unzip \
    && docker-php-ext-install pdo pdo_mysql \
    && rm -rf /var/lib/apt/lists/*

# 3. Copiar el código PHP al contenedor
COPY app/ /var/www/html/

# 4. Copiar el custom.ini
COPY custom.ini /usr/local/etc/php/conf.d/custom.ini

# 5. Establecer el directorio de trabajo
WORKDIR /var/www/html

# 6. Opcional: exponer puerto (necesario para acceder desde localhost)
EXPOSE 9000
```

Después de esto, reconstruye el contenedor ejecutando este comando en el directorio donde tengas el Dockerfile:

```
$ docker build -t mi-php-pdo .
```

### Paso 6. Levantar los contenedores con docker-compose up

Ya podemos **poner en marcha los cuatro contenedores** tecleando (en el directorio de trabajo):

```
$ docker-compose up --build
```

O bien, si no hemos tocado la configuración de los contenedores recientemente:

```
$ docker-compose up
```

También podemos lanzarlo en segundo plano, para que la consola no se quede bloqueada:

```
$ docker-compose up -d
```

### Paso 7. Probar los contenedores

Si todo ha ido bien, deberías tener estos servicios activos:

* **http://localhost:8080** -> Aquí debería estar escuchando Apache/PHP. Si pones un archivo .php en la carpeta ./app de tu proyecto, tendría que verse el resultado.
* **http://localhost:8000** -> Aquí debería estar escuchando PHPMyAdmin. El usuario y contraseña de la base de datos están en el docker-compose.yml (los puedes cambiar allí si no te gustan).

### Paso 8. Detener los contenedores

Para detener los contenedores, tan solo teclea:

```
docker-compose down
```

O bien pulsa **CTRL + C** si inciaste docker-compose en segundo plano (con la opción -d).
