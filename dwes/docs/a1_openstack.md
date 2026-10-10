---
layout: page
title: Apéndice I. Openstack
permalink: /openstack/
nav_order: 9
parent: Desarrollo Web en Entorno Servidor
---

# Apéndice I. Openstack
{: .no_toc }

<div style="color:red; font-size: 150%"><strong>ESTE MATERIAL AÚN ESTÁ EN DESARROLLO</strong></div>

- TOC
{:toc}


## A1.1. ¿Qué es Openstack?

**OpenStack** es un proyecto *open source* que permite gestionar recursos virtuales de computación, redes, almacenamiento e imágenes, para diseñar y gestionar nubes privadas y públicas. Proporciona una virtualización de "infraestructura como servicio" o *IaaS* (Infraestructure as a Service).

En palabras más simples, Openstack nos permite desplegar una nube en la que virtualizar cualquier infraestructura hardware razonablemente concebible: ordenadores, redes, dispositivos de almacenamiento, etc. Y, además, nos permite interconectar todos esos componentes entre sí.

Por lo tanto, Openstack es perfecto para montar servidores web y de bases de datos adaptados a nuestras necesidades, de manera que podamos desplegar en ellos nuestras aplicaciones web.

Como son servidores virtuales, es fácil crearlos, replicarlos, eliminarlos o modificarlos, incluso en caliente. Por ejemplo, puedes añadir más memoria RAM a un servidor sin necesidad siquiera de apagarlo.

## A1.2. Creando VPS en Openstack

El profesor José Juan Sánchez, del Departamento de Informática del IES Celia Viñas, ha elaborado una completa documentación sobre Openstack. La podéis encontrar aquí:

[https://josejuansanchez.org/openstack-celia/](https://josejuansanchez.org/openstack-celia/)

No vamos a repetir lo que ya pone en esa guía, porque además corresponde al módulo de "Despliegue de Aplicaciones Web". Aquí solo resumiremos los pasos necesarios para crear un servidor en Openstack adecuado para desplegar tus aplicaciones:

1. **Accede a Openstack** en [https://172.16.0.11](https://172.16.0.11). Lógicamente, necesitarás una cuenta de usuario en vigor. *Si estás fuera de la red de IES Celia Viñas, necesitarás una cuenta en nuestra VPN para acceder*.

2. **Crea una instancia nueva** (por ejemplo, un Ubuntu 24.04 con 20 GB de disco y 2 GB de RAM debería ser suficiente para un servidor normalito).

3. **Asocia una IP flotante** a la instancia. Es la única forma de poder entrar a tu máquina virtual posteriormente.

4. **Lanza la instancia y conéctate por SSH** con ella. Necesitarás crear un par de claves SSH y guardar tu clave privada en un archivo llamado "id_rsa" de tu usuario (la ubicación de este archivo depende del sistema operativo; tendrás que consultar dónde hacerlo según que sistema uses):

   ```bash
   $ ssh ubuntu@dirección_IP
   ```
5. **Añade una regla al grupo de seguridad de Openstack para poder acceder al servidor por http y https**. Esto se hace desde el panel de administración de Openstack, siguiendo esta ruta: *Red -> Grupos de seguridad -> Administrar reglas -> Agregar regla*. Después, elije las reglas predefinidas que se llaman "HTTP" y "HTTPS" (puertos 80 y 443).

6. **Añade una regla al grupo de seguridad de Openstack para poder acceder a tu Base de Datos** (si la necesitas exponer). Desde el mismo panel, puedes abrir el puerto 3306 si usas MySQL/MariaDB o el 5432 si usas PostgreSQL.

7. **Instala docker, docker-compose y git** en la máquina virtual (y cualquier otra cosa que te sea necesaria, como **composer** o **npm**). *Recuerda conectarte antes a tu máquina virtual por SSH*. Por ejemplo:

    ```bash
    $ sudo apt update
    $ sudo apt install docker.io docker-compose git composer
    $ sudo adduser ubuntu docker  # Añadir usuario "ubuntu" al grupo "docker"
    # Cierra sesión y vuelve a entrar por SSH para que el grupo docker surta efecto
    ```

8. **Instala el software necesario para que tu aplicación web funcione**. Esto se puede hacer de forma nativa (instalando Apache, MySQL, etc.) o virtualizando esos componentes con Docker, que es más fácil, limpio y escalable.

    Como es diferente desplegar una aplicación web escrita en PHP clásico que hacerlo con otros frameworks o lenguajes, vamos a mostrar los siguientes pasos de forma diferenciada para cada tecnología.

## A1.3. Desplegar en Openstack una aplicación web escrita en PHP

Asegúrate de que has seguido correctamente los pasos previos expuestos en el [apartado A1.2](#a12-creando-vps-en-openstack) antes de continuar por aquí.

1. **Monta los contenedores Docker necesarios para crear un servidor web**. Para ello, puedes seguir los pasos que detallamos en el ejemplo del Apéndice 2, donde montamos un servidor con Apache, PHP, MariaDB y PHPMyAdmin. Esos pasos los tienes que ejecutar en tu máquina virtual de Openstack, conectándote a ella por SSH.

2. **Despliega tu código**. Si usas *git*, es tan simple como hacer `git clone` de tu repositorio dentro de la carpeta que hayas mapeado como volumen en tu Docker para el servidor web.

3. **Lanza los contenedores con *docker-compose***. Navega al directorio donde esté tu archivo `docker-compose.yml` y ejecuta:
    ```bash
    $ docker-compose up -d
    ```

¡Listo! Tu aplicación estará respondiendo en la IP flotante de tu máquina.

## A1.4. Desplegar en Openstack una aplicación web o API hecha con Laravel

Asegúrate de que has seguido correctamente los pasos del [apartado A1.2](#a12-creando-vps-en-openstack).

Para desplegar Laravel, la forma más cómoda es apoyarnos en **Laravel Sail** (que usa Docker por debajo), ya que nos instala todas las dependencias (PHP, MySQL, Redis, etc.) sin ensuciar el servidor.

1. **Clona tu repositorio**. Conéctate por SSH y baja tu código:
    ```bash
    $ git clone https://github.com/tu-usuario/tu-repo-laravel.git mi-app
    $ cd mi-app
    ```

2. **Configura las variables de entorno**.
    ```bash
    $ cp .env.example .env
    $ nano .env
    ```
    Configura tus credenciales de base de datos. Recuerda poner `APP_ENV=production` y `APP_DEBUG=false` en un entorno real.

3. **Instala las dependencias de PHP**. Como aún no tienes Sail levantado porque no tienes la carpeta `vendor`, puedes usar un contenedor temporal para instalarlas:
    ```bash
    $ docker run --rm -v $(pwd):/var/www/html -w /var/www/html laravelsail/php83-composer:latest composer install --ignore-platform-reqs
    ```

4. **Levanta Sail y prepara la base de datos**.
    ```bash
    $ ./vendor/bin/sail up -d
    $ ./vendor/bin/sail artisan key:generate
    $ ./vendor/bin/sail artisan migrate --force
    ```

5. **Compilar el frontend (Solo si tu app usa Blade/Vue/React integrado)**. Si tu aplicación usa Vite para compilar recursos estáticos, **NUNCA debes ejecutar `npm run dev` en un servidor de producción**. Ese comando es solo para desarrollo local y bloqueará la terminal. En producción, debes compilar los archivos:
    ```bash
    $ ./vendor/bin/sail npm install
    $ ./vendor/bin/sail npm run build
    ```
    Esto generará los archivos optimizados en la carpeta `public/build/`.

6. **Permisos**. Si Laravel da un error de permisos en `storage` o `bootstrap/cache`, corrígelo:
    ```bash
    $ sudo chmod -R 775 storage bootstrap/cache
    $ sudo chown -R $USER:www-data storage bootstrap/cache
    ```

## A1.5. Desplegar en Openstack un backend hecho con Spring Boot

Desplegar una aplicación Java con **Spring Boot** es extremadamente sencillo, ya que Spring Boot empaqueta un servidor web interno (Tomcat normalmente) dentro del propio archivo ejecutable.

1. **Instala Java y Maven en tu servidor**. Conéctate por SSH y ejecuta:
    ```bash
    $ sudo apt update
    $ sudo apt install openjdk-17-jdk maven  # O la versión de Java que uses (17, 21...)
    ```

2. **Clona tu repositorio**.
    ```bash
    $ git clone https://github.com/tu-usuario/tu-repo-spring.git mi-api-spring
    $ cd mi-api-spring
    ```

3. **Configura tu aplicación**. Modifica el archivo `src/main/resources/application.properties` (o `application.yml`) para asegurarte de que apunta a la base de datos correcta en producción. Si usas MySQL, tendrás que instalarlo en tu servidor (nativamente o con Docker) y crear la base de datos que Spring Boot espera encontrar.

4. **Empaqueta la aplicación**. Este comando descargará las dependencias y compilará el código, generando un archivo `.jar` en la carpeta `target/`.
    ```bash
    $ mvn clean package -DskipTests
    ```

5. **Ejecuta la aplicación**. Puedes lanzar el servidor directamente. Por defecto escuchará en el puerto 8080. Si quieres que se quede ejecutando en segundo plano aunque cierres la terminal, puedes usar `nohup`:
    ```bash
    $ nohup java -jar target/mi-aplicacion-0.0.1-SNAPSHOT.jar > log.txt 2>&1 &
    ```
    *(Asegúrate de tener el puerto 8080 abierto en el Grupo de Seguridad de Openstack, o cambia el puerto al 80 en el `application.properties` ejecutando el comando como `sudo`).*

## A1.6. Desplegar en Openstack una API hecha con FastAPI

Para desplegar una API en Python construida con **FastAPI**, lo habitual es usar un entorno virtual de Python y lanzar el servidor ASGI llamado `uvicorn`.

1. **Instala Python y virtualenv en tu servidor**.
    ```bash
    $ sudo apt update
    $ sudo apt install python3 python3-venv python3-pip
    ```

2. **Clona tu repositorio**.
    ```bash
    $ git clone https://github.com/tu-usuario/tu-repo-fastapi.git mi-api-fastapi
    $ cd mi-api-fastapi
    ```

3. **Crea un entorno virtual e instala las dependencias**. Esto aísla las librerías de tu aplicación del resto del sistema operativo.
    ```bash
    $ python3 -m venv venv
    $ source venv/bin/activate
    $ pip install -r requirements.txt
    ```

4. **Ejecuta Uvicorn**. Para desplegar en producción, le diremos a Uvicorn que escuche en todas las interfaces de red (`0.0.0.0`) y en el puerto 8000. Si lo ejecutamos en segundo plano:
    ```bash
    $ nohup uvicorn main:app --host 0.0.0.0 --port 8000 > log.txt 2>&1 &
    ```
    *(Nota: Reemplaza `main:app` por el nombre de tu archivo Python y el nombre de tu instancia de FastAPI. Recuerda abrir el puerto 8000 en el panel de seguridad de Openstack).*

## A1.7. Desplegar en Openstack un frontend SPA (Vue.js, Angular o React)

Desplegar una aplicación frontend de tipo SPA es muy distinto a desplegar un backend. Una SPA, una vez terminada, **no necesita Node.js ni ningún motor de ejecución en el servidor**. Son solo archivos estáticos (HTML, CSS y JS). El servidor web solo tiene que entregarlos al navegador.

Para ello, usaremos el servidor web más rápido y popular para archivos estáticos: **Nginx**.

1. **Instala Nginx y Node.js en tu servidor**.
    ```bash
    $ sudo apt update
    $ sudo apt install nginx
    # Instalamos Node desde los repositorios para poder compilar nuestro frontend:
    $ sudo apt install nodejs npm
    ```

2. **Clona el repositorio de tu frontend**.
    ```bash
    $ git clone https://github.com/tu-usuario/tu-repo-vue.git mi-frontend
    $ cd mi-frontend
    ```

3. **Configura la URL de tu API (IMPORTANTE)**. Antes de compilar, asegúrate de que tu código frontend apunta a la IP pública (o dominio) de tu servidor Backend en Openstack, y NO a `localhost`. Si usas variables de entorno (ej. `.env.production`), ajústalas ahora.

4. **Instala y compila para producción**.
    ```bash
    $ npm install
    $ npm run build
    ```
    Este proceso generará una carpeta llamada `dist` (o `build` dependiendo del framework) con el código final optimizado para el navegador.

5. **Copia los archivos a Nginx**. El servidor Nginx, por defecto en Ubuntu, sirve los archivos alojados en `/var/www/html`. Solo tenemos que copiar el contenido de nuestra carpeta `dist` allí.
    ```bash
    $ sudo rm -rf /var/www/html/*
    $ sudo cp -r dist/* /var/www/html/
    ```

6. **Configura el enrutamiento para SPA en Nginx (Opcional pero muy recomendado)**. Si usas Vue Router (o Angular Router) en modo "History", si un usuario recarga la página en una ruta como `/academias`, Nginx dará un error 404 porque no existe ese archivo físico. Nginx debe redirigir todo a `index.html`.
    ```bash
    $ sudo nano /etc/nginx/sites-available/default
    ```
    Busca el bloque `location / { ... }` y déjalo así:
    ```nginx
    location / {
        try_files $uri $uri/ /index.html;
    }
    ```
    Reinicia Nginx para aplicar los cambios:
    ```bash
    $ sudo systemctl restart nginx
    ```

¡Ya está! Si introduces la IP flotante de tu servidor en tu navegador, Nginx entregará tu frontend SPA, y este a su vez se comunicará con tu API en el backend.
