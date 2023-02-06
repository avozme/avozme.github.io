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

5. **Instala docker, git y composer** en la máquina virtual (bueno, y cualquier otra cosa que te sea necesaria para tu aplicación):

    ```
    $ sudo apt install docker git composer
    $ sudo adduser ubuntu docker  (Añadir usuario "ubuntu" al grupo "docker")
    ```

6. **Instala tu servidor con docker**. Es lo más recomendable.

    Si vas a usar Laravel, instálalo mediante Docker (Sail). Si tu proyecto es de PHP clásico, también te recomiendo usar Docker para instalar Apache, MySQL o cualquier otra cosa que necesites en el servidor. En el Apéndice 2 tienes información sobre cómo hacerlo.

    Por ejemplo, para instalar Laravel haríamos esto en la máquina virtual:

    ```
    $ curl -s https://laravel.build/mi-app | bash   (cambiar "mi-app" por otro nombre para la app)
    $ cd mi-app (o el directorio que hayas elegido en la instrucción anterior)
    $ ./vendor/bin/sail up -d
    ```

    Por supuesto, siempre puedes instalar en tu servidor Apache, MySQL o lo que sea de forma nativa, y configurarlos para que tu aplicación funcione con ellos. Pero hacerlo con docker te dará menos quebraderos de cabeza.

7. **Añade una regla al grupo de seguridad de Openstack para poder acceder al servidor por http**. Esto se hace desde el panel de administración  de Openstack, siguiendo esta ruta: *Openstack -> grupos de seguridad -> Admin reglas -> Agregar reglas*. Después, añade un "Acceso por HTTP".

Si estás desplegando una aplicación Laravel, es posible que necesites un par de pasos adicionales:

8. Si tu aplicación Laravel no tiene directorio "vendor", tendrás que generarlo con composer. Y crear la estructura de la base de datos lanzando tus migraciones:

    ```
    $ ./vendor/bin/sail composer update    (necesitas tener al menos "sail" dentro de "vendor")
    $ php artisan migrate:fresh --seed     (necesitarás configurar antes el .env)
    ```

9. Si la aplicación Laravel da un error de acceso al directorio "storage", concédele permisos 777:

    ```
    $ sudo chmod -R 777 storage
    $ ./vendor/bin/sail artisan cache:clear
    $ ./vendor/bin/sail artisan config:clear
    $ ./vendor/bin/sail artisan config:cache
    ```

¡Listo! Con esto, deberías tener tu servidor escuchando en la IP que hayas asignado como "IP flotante" en el paso 3.
