---
layout: page
title: 3.6 Ejercicios propuestos
permalink: /cookies-sesiones-seguridad/ejercicios-propuestos.html
nav_order: 1
has_children: false
parent: 3 Cookies, sesiones y seguridad
grand_parent: Desarrollo Web en Entorno Servidor
---

## 3.6. Ejercicios propuestos
{: .no_toc }

- TOC
{:toc}

Vamos a enfilar el final de este tema con una batería de ejercicios propuestos, que consistirán en una serie de mejoras sobre nuestra implementación de las listas de control de acceso.

Ten en cuenta que lo que hagas aquí se puede reutilizar en posteriores proyectos de aplicaciones web, así que vamos a tomárnoslo en serio, ¿te parece?

Como vamos a trabajar con la implementación anterior, tal vez te apetezca ponerla a funcionar en tu servidor local. El código fuente lo puedes copiar de este mismo documento. Para que no tengas que construir la base de datos a mano, puedes usar [este archivo SQL](/docs/dwes/_site/assets/code/03-acl.sql) para importarla en tu servidor local.

#### Ejercicio 1. Crear la capa de seguridad

Si te fijas en el código fuente, hemos accedido en varios puntos al array superglobal *$_SESSION*. Más arriba dijimos que las variables de sesión de PHP no son completamente seguras. Confiar nuestro mecanismo de autenticación a esas variables es como jugar a la ruleta rusa.

¿Y si queremos cambiarlo? Por ejemplo, por *cookies*. Vale, las *cookies* tampoco son muy seguras, pero la pregunta sigue siendo la misma: ¿y si queremos cambiar la forma en la que se almacena el ID del usuario logueado tras la autenticación?

La única manera es *revisar TOOOODO el código fuente* y cambiar las referencias a *$_SESSION* por *$_COOKIE* (o el mecanismo que hayamos elegido para sustituir a las variables de sesión). Y, si pretendemos mejorar la seguridad de la aplicación, no solo sustituirla, lo mismo: ponte a revisar todo tu código una y otra vez.

Por eso suele construirse una **capa de seguridad**. Que es lo que te propongo hacer ahora.

La capa de seguridad no es más que una clase (podemos llamarla *Seguridad* o *Security*) guardada en un archivo aparte que contendrá una colección de métodos para gestionar la seguridad de la aplicación. Así, cada vez que queramos cambiar algo en la forma se protege de los ataques, solo tendremos que acudir a esa clase y tocar aquí o allí, como en una intervención quirúrjica muy localizada.

Así que, en este ejercicio, te pido crear una clase *Seguridad* (o *Security*) que contenga, para empezar, estos métodos:

* **openSession()**: para abrir una sesión de usuario cuando alguien se loguee correctamente. Este método seguirá usando una variable de sesión de PHP (ya lo cambiaremos después). Por ahora, solo queremos centralizar en esta clase el manejo de sesiones y seguridad.
* **getUserId()**: devuelve el ID del usuario logueado (si existe).
* **getUserRoles()**: devuelve un array con los roles del usuario logueado (si existe)
* **getUserPermissions()**: devuelve un array con los permisos del usuario logueado (si existe)

Cuando tengas hecha esa clase, sustituye cualquier referencia a $_SESSION en el código fuente de nuestro caso práctico (ver sección anterior) por llamadas a métodos de esta clase, hasta que el programa funcione exactamente igual que antes, pero con la clase Seguridad integrada en él.

#### Ejercicio 2. Filtrar los datos de entrada

Añade un nuevo método en la clase *Seguridad* que puedes llamar ***filter()***.

Este método recibirá un *string* y lo devolverá filtrado, es decir, limpio de cualquier carácter o palabra sospechosa.

Puedes empezar por eliminar los caracteres especiales como "<", ">", "#" o "$", señal de que alguien puede estar intentando inyectar Javascript, SQL o tratando de atacar mediante CSRF. Con eso ya irás bastante seguro.

Luego busca todos los puntos de la aplicación donde se accede a las variables de la URL sin filtro (es decir, los puntos donde se usa $_REQUEST, $_GET o $_POST) y llama al método *filter()* antes de acceder a esas variables.

Más adelante, puedes mejorar la función de filtrado localizando palabras como "script", "location.href" o similares. Lo bueno de esta solución es que no tendrás que tocar el resto del programa: al tener la función de filtrado encapsulada en la clase *Seguridad*, cualquier mejora posterior afectará a toda la aplicación sin modificar el código externo a esta clase.

#### Ejercicio 3. Cerrar la sesión y destruir las variables

Es algo que no hemos hecho hasta ahora, ¿verdad?

La clase *Seguridad* debe tener un método para destruir las variables de sesión y cerrar la sesión de un usuario autenticado. Lo podemos llamar ***closeSession()***.

Habrá que añadir una opción "Cerrar sesión" en el menú principal de la aplicación que enlace con una entrada del controlador que, a su vez, invoque este método de la clase *Seguridad*.

#### Ejercicio 4. Añadir cookies para controlar la sesión

Hemos dicho a lo largo del texto que manejar las sesiones de usuario solo con las variables de sesión de PHP es arriesgado, puesto que un atacante podría suplantar la sesión con relativa facilidad capturando la *cookie* "phpsessid".

Para proporcionar a este mecanismo un extra de protección, se pueden crear *cookies* adicionales que nos den una pista en caso de que se produzca un ataque. Estas *cookies* se manipulan desde la clase *Seguridad* de forma transparente al resto del programa. Es decir, el resto de clases ni se enteran de que la seguridad de la aplicación se está incrementando. ¡Es la magia de la programación orientada a objetos!

Las *cookies* que vamos a crear en este punto son:

* idUsuario: Guardaremos el id del usuario logueado en una *cookie* además de en una variable de sesión. Cada vez que la clase *Seguridad* vaya a comprobar algo (los permisos del usuario, por ejemplo), se asegurará de que la *cookie* y la variable de sesión contienen exactamente el mismo valor. Cualquier discrepancia provocará un cierre de la sesión inmediato.
* idRol: Haremos lo mismo con el rol del usuario.
* myToken: Será una *cookie* con un valor aleatorio que guardaremos en el cliente, al mismo tiempo que crearemos una variable de sesión donde se guardará el mismo valor. Si un atacante suplanta el id de sesión de PHP, probablemente no suplantará este token. En cada operación de la clase *Seguridad* comprobaremos que los dos tokens coinciden y, si no es así, cerraremos la sesión.

#### Ejercicio 5. Añadir una tabla para controlar la sesión

El mecanismo extra de seguridad que hemos implementado en el apartado anterior no es suficiente. Un atacante avispado se percatará antes o después de que hay por ahí pululando una *cookie* adicional (nuestro token), y terminará suplantándolo.

Para subir un escalón en nuestra protección frente a ataques, necesitamos crear una tabla en la base de datos que tenga más o menos esta estructura:

```sql
 CREATE TABLE IF NOT EXISTS `MySessions` (
    `id` varchar(40) NOT NULL,
    `ipAddress` varchar(45) NOT NULL,
    `idUser` INTEGER NOT NULL,
    `idRol` INTEGER NOT NULL,
    `token` varchar(200) NOT NULL,
    `timestamp` int(10) unsigned DEFAULT 0 NOT NULL,
    PRIMARY KEY (id)
);
```

Cuando un usuario de autentique en la aplicación, crearemos sus variables de sesión y sus *cookies* como hasta ahora y, además, insertaremos un registro en la tabla *MySessions* con toda la información de la sesión, a la que añadiremos:

* La IP desde la que el cliente se ha conectado. Curiosea en internet para averiguar cómo se puede obtener este dato.
* La fecha y hora exacta de esa conexión (a eso se le denomina *timestamp* o marca de tiempo).

En cualquier operación posterior, la clase *Seguridad* realizará todas las comprobaciones que ya realizaba hasta ahora y, además, lanzará una consulta a la base de datos para recuperar, mediante el valor del token, el ID del usuario y su rol. Si el token no existe en la base de datos, mal asunto: cerramos la sesión. Y si hay cualquier discrepancia entre los valores de la base de datos, de las variables de sesión y de las cookies, mal asunto también: cerramos la sesión.

La seguridad puede continuar mejorándose indefinidamente. Por ejemplo: si detectamos un posible ataque procedente de una dirección IP, podemos pasarla a una tabla de "direcciones baneadas" e impedir cualquier intento de conexión en el futuro desde esa dirección.


#### Ejercicio 6. Limitar el acceso al controlador (y completar la aplicación)

Todo esto está muy bien (aunque te hace volverte un poco paranoico, ¿verdad?), pero, por muchas mejoras en la seguridad que estemos introduciendo, cualquier atacante, incluso sin pasar por el login, puede escribir esto en su navegador y meterse hasta la cocina en nuestra aplicación:

```
https://mi-servidor/index.php?action=showMainMenu
```

Sustituye "showMainMenu" por cualquier otra cosa (¿qué tal "deleteUser"?) y tienes un problema de los gordos.

Para programar una aplicación web segura necesitamos **proteger los métodos del controlador**, de manera que solo pueda ejecutarlos un usuario autenticado y con los privilegios adecuados.

Fíjate en que cada usuario tendrá acceso a diferentes métodos del controlador, dependiendo de su rol. Por ejemplo, a un método como *showMainMenu()* podrá acceder cualquier usuario logueado, pero un método como *deleteUser()* debe estar más limitado y solo los administradores deberían poder ejecutarlo.

Así que tienes que añadir una barrera de entrada en cada método del controlador, en forma de un par de líneas de código que comprueben:

a) Que hay un usuario correctamente autenticado.
b) Que ese usuario tiene privilegios suficientes para ejecutar este método.

Las dos comprobaciones se hacen invocando métodos de la clase *Seguridad*. Te dejo a ti pensar cómo se implementa esto exactamente (en realidad, hay varios modos).

Si cualquiera de las dos comprobaciones falla, el usuario verá una pantalla de "Acceso prohibido" o algo por el estilo.

#### Ejercicio 7. Actualizar periódicamente el ID de sesión

Una técnica de defensa frecuente es modificar el ID de sesión periódicamente (cada pocos minutos, o bien cada vez que se recibe una petición del cliente).

Implementa esta opción en tu aplicación. Te advierto que es lo más complicado que has hecho hasta ahora. Puedes considerar que este es un ejercicio de nivel avanzado.

#### Ejercicio 8. Aplicar a un caso realista

Por último, vamos a aplicar todas estas mejoras en la seguridad a una aplicación web más completa.

Para ello, utiliza el código fuente de tu Videoclub (la aplicación que programamos en el tema anterior). Si no dispones de ese código, puedes usar el de la Biblioteca. Lo encontrarás en un capítulo anterior de este mismo texto. No es que sea una aplicación muy completa, pero si te servirá para comprobar que la capa de seguridad es muy eficaz contra los ataques más habituales.

Añade la clase *Seguridad* al código fuente de tu aplicación y sustituye la apertura de la sesión por llamadas a los métodos de la clase *Seguridad*. Por último, protege todos los accesos al controlador para asegurarte de que solo los usuarios con los privilegios adecuados puede ejecutar ese código.

Y una última advertencia: por mucho que protejas una aplicación web, puedes encontrarte con atacantes que burlen tus medidas de seguridad. La única solución para eso es disponer siempre de un *backup* de tu código y tu base de datos para restaurarlo todo en caso de catástrofe, así que no dejes de hacer copias con frecuencia (o contrata un proveedor de *hosting* que las haga por ti).