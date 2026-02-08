---
layout: page
title: Apéndice 3. Despliegue con Openstack
permalink: /openstack/
nav_order: 8
has_children: false
parent: Desarrollo web full stack
---
# Apéndice 3. Despliegue con Openstack
{: .no_toc }

- TOC
{:toc}


## A3.1. ¿Qué es Openstack?

**OpenStack** es un proyecto *open source* que permite gestionar recursos virtuales de computación, redes, almacenamiento e imágenes, para diseñar y gestionar nubes privadas y públicas. Proporciona una virtualización de "infraestructura como servicio" o *IaaS* (Infraestructure as a Service).

En palabras más simples, Openstack nos permite desplegar una nube en la que virtualizar cualquier infraestructura hardware razonablemente concebible: ordenadores, redes, dispositivos de almacenamiento, etc. Y, además, nos permite interconectar todos esos componentes entre sí.

Por lo tanto, Openstack es perfecto para montar servidores web y de bases de datos adaptados a nuestras necesidades, de manera que podamos desplegar en ellos nuestras aplicaciones web.

Como son servidores virtuales, es fácil crearlos, replicarlos, eliminarlos o modificarlos, incluso en caliente. Por ejemplo, puedes añadir más memoria RAM a un servidor sin necesidad siquiera de apagarlo.

## A3.2. Creando servidores en Openstack para desplegar aplicaciones web

José Juan Sánchez ha elaborado una completísima documentación sobre Openstack. La podéis encontrar aquí:

[https://josejuansanchez.org/openstack-celia/](https://josejuansanchez.org/openstack-celia/)

No vamos a repetir aquí lo que ya pone en esa guía, porque además corresponde al módulo de "Despliegue de Aplicaciones Web". Aquí solo resumiremos los pasos necesarios para crear un servidor en Openstack adecuado para desplegar tus aplicaciones:

**1) Accede a Openstack** en [https://172.16.0.11](https://172.16.0.11). Lógicamente, necesitarás una cuenta de usuario en vigor.

<div style="font-size: 80%; margin-left: 20%; background-color: #ddd; font-style: italic;  padding: 5px 15px 5px 15px;">
  <p>¡OJO! Esa IP solo está disponible dentro de la red del Departamento de Informática del IES Celia Viñas. Para acceder desde el exterior (desde tu casa, por ejemplo), necesitas instalar y configurar un VPN. <strong>Esto es optativo, solo para acceder desde fuera del instituto a Openstack</strong>.</p>
  <ol>
    <li>
      Descarga el cliente de OpenVPN para tu sistema operativo favorito.
      <ul>
        <li>Linux: <a href="https://openvpn.net/cloud-docs/openvpn-3-client-for-linux/" target="_blank">https://openvpn.net/cloud-docs/openvpn-3-client-for-linux/</a></li>
        <li>Android: <a href="https://play.google.com/store/apps/details?id=net.openvpn.openvpn&hl=es_CL" target="_blank">https://play.google.com/store/apps/details?id=net.openvpn.openvpn&hl=es_CL</a></li>
        <li>Windows: <a href="https://openvpn.net/client-connect-vpn-for-windows/" target="_blank">https://openvpn.net/client-connect-vpn-for-windows/</a></li>
        <li>MacOS: <a href="https://openvpn.net/client-connect-vpn-for-mac-os/" target="_blank">https://openvpn.net/client-connect-vpn-for-mac-os/</a></li>
      </ul>
    </li>

    <li>
      Utiliza el archivo de configuración <code>.ovpn</code> para <strong>alumnos</strong> que encontrarás en Moodle para conectar con el servidor de OpenVPN.
      <pre>
$ openvpn3 session-start --config &lt;fichero .ovpn&gt;
      </pre>
    </li>

    <li>
      Accede con tu usuario y contraseña (son diferentes que los de Openstack; tu profesor te habrá facilitado estas credenciales)
    </li>

    <li>
      Una vez que te hayas conectado a la VPN tendrás acceso a las máquinas de OpenStack.
      <br>
      La URL del dashboard de OpenStack es:
      <a href="https://172.16.0.11/" target="_blank">https://172.16.0.11/</a>
    </li>

    <li>
      Para cambiar la contraseña de tu usuario de la VPN accede a la URL:
      <a href="http://172.16.0.1/" target="_blank">http://172.16.0.1/</a>
    </li>

    <li>
      Para obtener información de la sesión de VPN:
      <pre>
$ openvpn3 sessions-list
      </pre>
    </li>
    <li>
      Para cerrar la sesión de VPN:
      <pre>
$ openvpn3 session-manage --path &lt;session-path&gt; --disconnect
      </pre>
      &mdash;&gt; el <code>&lt;session-path&gt;</code> se obtiene de la información de la sesión (ver punto anterior).
    </li>
  </ol>

</div>


**2) Crea una instancia nueva** (por ejemplo, un Ubuntu 22.04 con 10 GB de disco y 1 GB de RAM debería ser suficiente para un servidor normalito).

**3) Asocia una IP flotante** a la instancia. Es la única forma de poder entrar a tu máquina virtual posteriormente.

**4) Lanza la instancia y conéctate por SSH** con ella. Necesitarás crear un par de claves SSH en Openstack y guardar tu clave privada en un archivo llamado "id_rsa" de tu usuario (la ubicación de este archivo depende del sistema operativo; tendrás que consultar dónde hacerlo según que sistema uses). Una vez hecho esto, puedes conectarte así:

   ```
   $ ssh ubuntu@dirección_IP
   ```

O, si tu archivo con la clave no está en el lugar establecido por tu sistema operativo, puedes conectar así:

   ```
   $ ssh -i ruta-al-archivo-con-la-clave-privada ubuntu@dirección_IP
   ```

**5) Añade una regla al grupo de seguridad de Openstack para poder acceder al servidor por http**. Esto se hace desde el panel de administración  de Openstack, siguiendo esta ruta: *Red -> Grupos de seguridad -> Administrar reglas -> Agregar regla*. Después, elije la regla predefinida que se llama "HTTP".

**6) Añade una regla al grupo de seguridad de Openstack para poder acceder a MySQL**. Como antes, se hace desde el panel de administración de Openstack (*Red -> Grupos de seguridad -> Administrar reglas -> Agregar regla*). En esta ocasión, elije la regla predefinida "MySQL".

**7) Instala docker, docker-compose, git y composer** en la máquina virtual (bueno, y cualquier otra cosa que te sea necesaria para tu aplicación). Para ello, *recuerda conectarte antes a tu máquina virtual por SSH* y teclea esto:

    ```
    $ sudo apt install docker docker-compose git composer
    $ sudo adduser ubuntu docker  (Añadir usuario "ubuntu" al grupo "docker")
    ```

**8) Instala el software necesario para que tu aplicación web funcione**. Esto se puede hacer de forma nativa, instalado Apache, MySQL y todo lo que tu aplicación necesite, o virtualizando todos esos componentes con Docker (por ejemplo, con Laravel Sail), que es más fácil, escalable y recomendable.

Como es diferente desplegar una aplicación web escrita en PHP clásico que hacerlo con una escrita con Laravel, vamos a mostrar los siguientes pasos de forma diferenciada para cada situación.

### A3.2.1. Caso 1: mi aplicación está escrita en PHP clásico

Asegúrate de que has seguido correctamente los pasos previos expuestos en el [apartado A3.2](../openstack/#a32-creando-servidores-en-openstack-para-desplegar-aplicaciones-web) antes de continuar por aquí.

1. **Monta los contenedores Docker necesarios para crear un servidor web**. Para ello, puedes seguir los pasos que detallamos en el ejemplo del [Apéndice 2](../docker/#a24-montando-con-docker-un-servidor-web-con-persistencia-de-datos), donde montamos un servidor con Apache, PHP, MariaDB y PHPMyAdmin. Por supuesto, estos pasos los tienes que ejecutar en tu máquina virtual de Openstack, conectándote a ella por SSH, no en tu máquina local.

2. **Lanza los contenedores con *docker-compose***. Si has seguido correctamente los pasos para montar el servidor que detallamos en el Apéndice 2, con esto tu servidor estará escuchando en la IP flotante que hayas asignado a tu máquina virtual.

3. **Despliega tu código**. Si usas *git* (como deberías estar haciendo), es tan simple como hacer ```git clone``` en el directorio donde hayas lanzado Docker.

¡Listo! Tu aplicación estará respondiendo en la IP flotante que hayas configurado. Compruébalo con tu navegador web preferido.

### A3.2.2. Caso 2: mi aplicación está escrita con Laravel

Asegúrate de que has seguido correctamente los pasos previos expuestos en el [apartado A3.2](../openstack/#a32-creando-servidores-en-openstack-para-desplegar-aplicaciones-web) antes de continuar por aquí.

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

5. **Lanzar npm** (si es necesario). Si tu aplicación Laravel usa ```npm``` (por ejemplo, porque hayas instalado Laravel Breeze o porque estés creando un frontend con Vue.js), tendrás que lanzar Node en el servidor:

    ```
    $ ./vendor/bin/sail npm install
    $ ./vendor/bin/sail npm run dev
    ```

    Eso dejará el servidor Node corriendo, apropiado si aún estás desarrollando la aplicación porque los cambios en las vistas (o en los archivos .vue) se compilarán sobre la marcha. 
    
    En cambio, si la aplicación ya está terminada o no quieres desarrollar en este servidor, solo desplegar, ejecuta:
    
    ```
    $ ./vendor/bin/sail npm run build
    ```

    Hemos observado que, en el servidor Ubuntu de Openstack, los comandos ```npm run dev``` o ```npm run build``` pueden dar el error "ENOSPC: System limit for number of file watchers reached". Si te sucede esto, haz lo siguiente:

    ```
    $ sudo nano /etc/sysctl.conf
    ```

    Ahora añade esta línea al final de archivo:

    ```
    fs.inotify.max_user_watches = 524288
    ```

    Con eso, ```npm run``` debería funcionar bien.
 
¡Listo! Ya deberías tener tu servidor escuchando en la IP flotante que hayas asignado a tu máquina virtual.

***(¡OJO! Puedes levantar la app en tu servidor de OpenStack con Laravel Sail, y funcionará correctamente, pero ten en cuenta que Sail es un servidor pensado para solo para DESARROLLO. Para PRODUCCIÓN no se considera seguro ni tiene buen rendimiento. Existen otras soluciones para ello, como Laravel Forge, o montar contenedores Docker bien configurados, que nosotros no vamos a trabajar por falta de tiempo)***