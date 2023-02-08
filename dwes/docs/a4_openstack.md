---
layout: page
title: Apéndice IV. Despliegue con Openstack
permalink: /openstack/
nav_order: 12
has_children: false
parent: Desarrollo Web en Entorno Servidor
---
# Apéndice 4. Despliegue con Openstack
{: .no_toc }

- TOC
{:toc}


## A4.1. ¿Qué es Openstack?

**OpenStack** es un proyecto *open source* que permite gestionar recursos virtuales de computación, redes, almacenamiento e imágenes, para diseñar y gestionar nubes privadas y públicas. Proporciona una virtualización de "infraestructura como servicio" o *IaaS* (Infraestructure as a Service).

En palabras más simples, Openstack nos permite desplegar una nube en la que virtualizar cualquier infraestructura hardware razonablemente concebible: ordenadores, redes, dispositivos de almacenamiento, etc. Y, además, nos permite interconectar todos esos componentes entre sí.

Por lo tanto, Openstack es perfecto para montar servidores web y de bases de datos adaptados a nuestras necesidades, de manera que podamos desplegar en ellos nuestras aplicaciones web.

Como son servidores virtuales, es fácil crearlos, replicarlos, eliminarlos o modificarlos, incluso en caliente. Por ejemplo, puedes añadir más memoria RAM a un servidor sin necesidad siquiera de apagarlo.

## A4.2. Creando servidores en Openstack para desplegar aplicaciones web

José Juan Sánchez ha elaborado una completísima documentación sobre Openstack. La podéis encontrar aquí:

[https://josejuansanchez.org/openstack-celia/](https://josejuansanchez.org/openstack-celia/)

No vamos a repetir aquí lo que ya pone en esa guía, porque además corresponde al módulo de "Despliegue de Aplicaciones Web". Aquí solo resumiremos los pasos necesarios para crear un servidor en Openstack adecuado para desplegar tus aplicaciones:

1. **Accede a Openstack** en [https://172.16.0.11](https://172.16.0.11). Lógicamente, necesitarás una cuenta de usuario en vigor.

2. **Crea una instancia nueva** (por ejemplo, un Ubuntu 22.04 con 10 GB de disco y 1 GB de RAM debería ser suficiente para un servidor normalito).

3. **Asocia una IP flotante** a la instancia. Es la única forma de poder entrar a tu máquina virtual posteriormente.

4. **Lanza la instancia y conéctate por SSH** con ella. Necesitarás crear un par de claves SSH y guardar tu clave privada en un archivo llamado "id_rsa" de tu usuario (la ubicación de este archivo depende del sistema operativo; tendrás que consultar dónde hacerlo según que sistema uses):

   ```
   $ ssh ubuntu@dirección_IP
   ```
5. **Añade una regla al grupo de seguridad de Openstack para poder acceder al servidor por http**. Esto se hace desde el panel de administración  de Openstack, siguiendo esta ruta: *Openstack -> grupos de seguridad -> Admin reglas -> Agregar reglas*. Después, añade un "Acceso por HTTP".

6. **Instala docker, docker-compose, git y composer** en la máquina virtual (bueno, y cualquier otra cosa que te sea necesaria para tu aplicación). Para ello, conéctate a tu máquina virtual por SSH y teclea esto:

    ```
    $ sudo apt install docker docker-compose git composer
    $ sudo adduser ubuntu docker  (Añadir usuario "ubuntu" al grupo "docker")
    ```

7. **Instala el software necesario para que tu aplicación web funcione**. Esto se puede hacer de forma nativa, instalado Apache, MySQL y todo lo que tu aplicación necesite, o virtualizando todos esos componentes con Docker, que es más fácil, escalable y recomendable.

    Como es diferente desplegar una aplicación web escrita en PHP clásico que hacerlo con una escrita con Laravel, vamos a mostrar los siguientes pasos de forma diferenciada para cada situación.

### A4.2.1. Caso 1: mi aplicación está escrita en PHP clásico

Asegúrate de que has seguido correctamente los pasos previos expuestos en el [apartado A4.2](../openstack/#a42-creando-servidores-en-openstack-para-desplegar-aplicaciones-web) antes de continuar por aquí.

1. **Monta los contenedores Docker necesarios para crear un servidor web**. Para ello, puedes seguir los pasos que detallamos en el ejemplo del [Apéndice 2](../docker/#a24-un-ejemplo-montando-un-servidor-web-con-persistencia-de-datos), donde montamos un servidor con Apache, PHP, MariaDB y PHPMyAdmin. Por supuesto, estos pasos los tienes que ejecutar en tu máquina virtual de Openstack, conectándote a ella por SSH, no en tu máquina local.

2. **Lanza los contenedores con *docker-compose***. Si has seguido correctamente los pasos para montar el servidor que detallamos en el Apéndice 2, con esto tu servidor estará escuchando en la IP flotante que hayas asignado a tu máquina virtual.

3. **Despliega tu código**. Si usas *git* (como deberías estar haciendo), es tan simple como hacer ```git clone``` en el directorio donde hayas lanzado Docker.

¡Listo! Tu aplicación estará respondiendo en la IP flotante que hayas configurado. Compruébalo con tu navegador web preferido.

### A4.2.2. Caso 2: mi aplicación está escrita con Laravel

Asegúrate de que has seguido correctamente los pasos previos expuestos en el [apartado A4.2](../openstack/#a42-creando-servidores-en-openstack-para-desplegar-aplicaciones-web) antes de continuar por aquí.

Para usar Laravel, debes instalar todas las dependencias en el servidor. Esto puede ser complicado, porque Laravel requiere de bastantes componentes. Por eso es recomendable instalarlo también con **Docker** (es decir, instalar **Laravel Sail**).

Los pasos para lograrlo serían los siguientes (recuerda que debes ejecutarlos en tu servidor, conectándote a él por SSH):

1. **Si queremos una instalación de Laravel limpia** haremos esto en la máquina virtual:

    ```
    $ curl -s https://laravel.build/mi-app | bash   (cambiar "mi-app" por otro nombre para la app)
    $ cd mi-app (o el directorio que hayas elegido en la instrucción anterior)
    $ ./vendor/bin/sail up -d
    ```

    En cambio, **si ya tienes una aplicación Laravel funcionando** (por ejemplo, en tu localhost), bastará con que la clones con ```git clone``` o, si no usas *git* (mal hecho), que copies el código manualmente a tu máquina virtual con *scp*.

2. **Instalar las dependencias de PHP y lanzar migraciones**. Si tu aplicación Laravel no tiene directorio "vendor", tendrás que generarlo con *composer*. Y crear la estructura de la base de datos lanzando tus migraciones:

    ```
    $ ./vendor/bin/sail composer update    (necesitas tener al menos "sail" dentro de "vendor")
    $ php artisan migrate:fresh --seed     (necesitarás configurar antes el .env)
    ```

3. **Resolver problemas de permisos**. Si la aplicación Laravel da un error de acceso al directorio "storage", concédele permisos 777:

    ```
    $ sudo chmod -R 777 storage
    $ ./vendor/bin/sail artisan cache:clear
    $ ./vendor/bin/sail artisan config:clear
    $ ./vendor/bin/sail artisan config:cache
    ```

4. **Resolver problemas con sesiones, caché y vistas**. Si la aplicación Laravel da errores con la sesiones, la caché o las vistas, asegúrate de que dentro del directorio */storage/framework* existen los subdirectorios *cache*, *sessions* y *views*, los tres con permisos 777. Si no existen, créalos. 

5. **Lanzar Node** (si es necesario). Si tu aplicación Laravel usa Node (por ejemplo, porque hayas instalado Laravel Breeze), tendrás que lanzar Node en el servidor:

    ```
    $ ./vendor/bin/sail npm install
    $ ./vendor/bin/sail npm run dev
    ```

    Eso dejará el servidor Node corriendo. No lo detengas: necesitará estár permanentemente activo (como Sail) para que la aplicación Laravel funcione bien.

    Hemos observado que, en el servidor Ubuntu de Openstack, el comando ```npm run dev``` puede dar el error "ENOSPC: System limit for number of file watchers reached". Si te sucede esto, haz lo siguiente:

    ```
    $ sudo nano /etc/sysctl.conf
    ```

    Ahora añade esta línea al final de archivo:

    ```
    fs.inotify.max_user_watches = 524288
    ```

    Con eso, ```npm run dev``` debería funcionar bien.
 
¡Listo! Con esto, deberías tener tu servidor escuchando en la IP flotante que hayas asignado a tu máquina virtual.
