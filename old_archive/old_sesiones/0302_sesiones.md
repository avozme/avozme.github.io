---
layout: page
title: 3.2 Sesiones
permalink: /cookies-sesiones-seguridad/sesiones.html
nav_order: 1
has_children: false
parent: 3 Cookies, sesiones y seguridad
grand_parent: Desarrollo Web en Entorno Servidor
---

## 3.2. Sesiones
{: .no_toc }

- TOC
{:toc}

En esta sección vamos a aprenderlo todo (bueno, o casi todo) sobre las variables de sesión en PHP.

### 3.2.1. ¿Qué es eso de las variables de sesión?

Las **sesiones** de PHP son un mecanismo para que un script almacene variables (llamadas **variables de sesión**) en el servidor de manera persistente, de modo que posteriores ejecuciones de programas en el servidor solicitadas desde el mismo cliente pueden acceder a esas variables.

Es decir: en la práctica, **las variables de sesión se comportan como si fueran variables globales a toda la aplicación web**.

Seguro que te habían dicho que usar variables globales es una mala idea y una pésima práctica de programación. Eso es cierto y, al mismo tiempo, usarlas resulta inevitable. *Bienvenido/a al extravagante mundo de las aplicaciones web*.

Por ese motivo, debe reducirse el uso de las variables de sesión a lo estrictamente imprescindible. ¿Qué cosas resulta útil guardar en variables de sesión? Cosas como el ID o el nombre de un usuario logueado en un sistema o el estado de la aplicación. Poco más. Cosas pequeñas pero tremendamente importantes. 

Cada cliente tiene su propio espacio de variables de sesión en el servidor, de manera que no se mezclan unas con otras, ni un cliente puede acceder a las variables de otro cliente.

La forma en la que PHP logra distinguir a los clientes entre sí es enviándoles, de forma transparente, una *cookie* con un valor aleatorio distinto para cada cliente. "De forma transparente" significa que ni el programador ni el usuario se enteran de que esa *cookie* existe: PHP se encarga de hacerlo por su cuenta.

En el archivo *php.ini* se puede configurar la manera en la que PHP almacenará las variables de sesión (en memoria, en un fichero, etc), pero esto es irrelevante de cara a su funcionamiento y compete más al administrador del sistema que al programador. Lo que a nosotros nos interesa es aprender a crear variables de sesión, asignarles valor y recuperarlo posteriormente.

### 3.2.2. Abrir sesiones: session_start()

Antes de acceder a cualquier variable de sesión (ya sea para crearla, para modificarla o para eliminarla) necesitamos indicarle a PHP que queremos usar variables de sesión en ese programa.

La función ***session_start()*** se usa para eso: habilita el acceso a las variables de sesión, es decir, crea una nueva sesión o reanuda una sesión preexistente.

Las sesiones admiten un nombre, por si necesitas crear sesiones separadas para el mismo cliente. No obstante, la mayor parte de las veces te bastará con crear sesiones sin nombre, sin necesidad de pasar ningún argumento a *session_start()*.

### 3.2.3. Usar variables de sesión: $_SESSION

Las variables de sesión se manipulan a través del array superglobal ***$_SESSION***.

Si necesitas una variable de sesión llamada, por ejemplo, *nombre_usuario*, simplemente haz esto:

```php
session_start();
$_SESSION['nombre_usuario'] = "valor-de-la-variable";
```

Por supuesto, el valor de esa posición del array $_SESSION puede consultarse o modificarse cuando lo necesitemos, porque se trata de un array como otro cualquiera... salvo que es *superglobal*, es decir, es accesible desde cualquier punto del programa.

### 3.2.4. Eliminar variables de sesión: unset() y session_destroy()

La función **unset()** se utiliza para destruir cualquier variable, incluidas las de sesión:

```php
unset($_SESSION['nombre_usuario']);
```

Si lo que deseas es destruir *todas* las variables de sesión, es preferible recurrir a ***session_destroy()***.

Ahora bien, session_destroy() destruye la información asociada a la sesión actual, pero no elimina realmente las variables de la memoria del servidor ni borra la *cookie* de sesión del cliente. 

Si eres un fanático de la seguridad y quieres asegurarte de destruir todas las variables de sesión, puedes usar la función ***session_unset()***. Y, para borrar la cookie de sesión, debes usar ***setcookie()***, como en este ejemplo:

```php

<?php
session_start();

// Destruimos todas las variables de sesión (optativo)
session_unset();

// Si queremos destruir la sesión completamente, borramos también la cookie de sesión.
$params = session_get_cookie_params();
setcookie(session_name(), '', time() - 42000,
        $params["path"], $params["domain"],
        $params["secure"], $params["httponly"]
);

// Finalmente, cerramos 0la sesión
session_destroy();
?>
```
