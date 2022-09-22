---
layout: page
title: Apéndice II. Virtualización con Docker
permalink: /docker/
nav_order: 10
has_children: false
parent: Desarrollo Web en Entorno Servidor
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

Es posible evitar eso usando la persistencia de datos.

XXX completar esta sección XXX

## A2.4. Un ejemplo: montando un servidor web con persistencia de datos

En esta sección vamos a mostrar cómo montar un servidor web con imágenes Docker y levantarlo o apagarlo con docker-compose.

Usaremos las imágenes de Bitnami, un desarrollador español recientemente adquirido por VMWare. Sus imágenes son fáciles de configurar (dentro de lo que cabe) y bastante confiables.

Vamos a poner en marcha **cuatro contenedores** simultáneamente:

1. **Servidor Apache** (imagen bitnami/apache)
2. **Intérprete PHP** (image bitnami/phpfpm)
3. **Servidor MariaDB** (imagen bitnami/mariadb)
4. **PHPMyAdmin** (imagen bitnami/phpmyadmin)

Además, necesitamos que los datos de MariaDB sean persistentes, es decir, que no se pierdan cuando detengamos los contenedores.

Si buscamos en DockerHub cada una de esas imágenes, encontraremos un archivo de configuración *docker-compose.yml* para cada una de ellas. 

Tenemos que construir un ***docker-compose.yml*** único combinando todos los archivos de configuración de todas las imágenes y ubicarlo en el directorio raíz de nuestro proyecto. Nos debe quedar algo así:

```yaml
version: '2'
services:
  php:
    image: bitnami/php-fpm:latest
    ports:
      - 9000:9000
    volumes:
      - .:/app
  apache:
    image: bitnami/apache:latest
    ports:
      - 80:8080
    volumes:
      - ./apache-vhost/myapp.conf:/vhosts/myapp.conf:ro
      - .:/app
    depends_on:
      - php
  mariadb:
    image: docker.io/bitnami/mariadb:10.6
    environment:
      - MARIADB_ROOT_PASSWORD=bitnami
    volumes:
      - 'mariadb_data:/bitnami'
  phpmyadmin:
    image: docker.io/bitnami/phpmyadmin:5
    ports:
      - '8000:8080'
    depends_on:
      - mariadb

volumes:
  mariadb_data:
    driver: local
```

Además, necesitamos crear un subdirectorio llamado ***apache-vhost*** y, dentro de él, colocar un archivo *myapp.conf* con este contenido:

```
LoadModule proxy_fcgi_module modules/mod_proxy_fcgi.so
<VirtualHost *:8080>
  DocumentRoot "/app"
  ProxyPassMatch ^/(.*\.php(/.*)?)$ fcgi://php:9000/app/$1
  <Directory "/app">
    Options Indexes FollowSymLinks
    AllowOverride All
    Require all granted
    DirectoryIndex index.php
  </Directory>
</VirtualHost>
```

Esto hace que todas las peticiones de scripts PHP que lleguen al servidor se pasen automáticamente al contenedor de PHP para que las interprete.

Ya podemos **poner en marcha los cuatro contenedores** tecleando (en el directorio de trabajo):

```
$ docker-compose up -d
```

Para **detener los contenedores**, teclearemos:

```
docker-compose down
```

El servidor estará respondiendo en la dirección http://localhost. Es muy importante que no tengas otro proceso usando el puerto 80 (el típico de http), o de lo contrario el contenedor de Apache no arrancará. Esto puede suceder si tienes un Apache nativo corriendo en tu máquina.

En cuanto a PHPMyAdmin, lo encontrarás eh http://localhost:8000.

Esos puertos (el 80 y el 8000) se pueden cambiar trasteando un poco con el archivo docker-compose.yml. Recuerda detener y volver a lanzar los contenedores cada vez que cambies la configuración.

Por último, si necesitas instalar dependencias de PHP con **composer**, puedes hacerlo creando un archivo *composer.json* en el directorio raíz del proyecto y ejecutando *composer install* dentro del contenedor de PHP:

```
$ docker-compose exec php composer install
```

#### Cómo editar el archivo php.ini de un contenedor Docker

Si necesitamos **editar el archivo php.ini** del servidor virtualizado, tendremos que conectarnos al contenedor de PHP.

1. Sacamos la lista de contenedores activos. Así averiguaremos el ID del contenedor de PHP.

```
$ docker ps
```

2. Copiamos el archivo PHP.INI del PHP. En el caso de Bitnami, ese archivo está ubicado en /opt/bitnami/php/etc:

```
$ docker cp [id-del-contenedor]:/opt/bitnami/php/etc .
```

3. Abrimos php.ini y lo editamos.

4. Enviamos el php.ini modificado de nuevo al contenedor:

```
$ docker cp php.ini [id-del-contenedor]:/opt/bitnami/php/etc
```

No te olvides de detener el contenedor y volver a ponerlo en marcha para que los cambios surtan efecto.
