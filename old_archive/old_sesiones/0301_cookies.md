---
layout: page
title: 3.1 Cookies
permalink: /cookies-sesiones-seguridad/cookies.html
nav_order: 1
has_children: false
parent: 3 Cookies, sesiones y seguridad
grand_parent: Desarrollo Web en Entorno Servidor
---

## 3.1. Cookies
{: .no_toc }

- TOC
{:toc}

En esta sección vamos a ver qué son las *cookies* y cómo podemos acceder a ellas para crearlas o manipularlas desde PHP.

### 3.1.1. ¿Qué son las cookies?

Las ***cookies*** son pequeños archivos de texto enviados desde el servidor que se almacenan en el lado del cliente. Es decir, en el navegador.

Permiten guardar información de forma persistente, de manera que se mantenga entre una petición al servidor y otra. Una *cookie* puede estar viva durante minutos, horas, días o incluso indefinidamente.

Desde PHP, se pueden usar las *cookies* usando la función ***setcookie()*** y el array global ***$_COOKIE***. Vamos a ver cómo. 

### 3.1.2. Manejando cookies con PHP

#### Enviar una cookie: setcookie()

Esta función define una *cookie* que se enviará al cliente junto con el resto de las cabeceras de HTTP. Devuelve *true* si la cookie se envía con éxito o *false* en caso contrario. 

Su sintaxis es:

```php
bool setcookie ( string $name [, string $value [, int $expire = 0 [, string $path [, string $domain [, bool $secure = false [, bool $httponly = false ]]]]]] )
```

Las *cookies* deben enviarse **antes de que el programa genere ninguna salida**. Esto no es un capricho de PHP, sino una restricción del protocolo http. Por lo tanto, debes llamar a esta función antes de hacer *cualquier* salida, incluidos espacios en blanco. En caso contrario, la *cookie* no estará disponible hasta que la página se recargue.

La función *setcookie()* admite un montón de parámetros, la mayor parte de ellos optativos:

* **name**: El nombre de la *cookie*. Este es el único obligatorio. 
* **value**: El valor de la *cookie*.
* **expire**: El tiempo que la *cookie* tardará en expirar. Se trata de una fecha expresada en [formato Unix](https://es.wikipedia.org/wiki/Tiempo_Unix).
* **path**: La ruta del servidor para la que la *cookie* estará disponible. Si se utiliza '/', la *cookie* estará disponible en la totalidad del dominio.
* **domain**: El dominio para el cual la *cookie* está disponible.
* **secure**: Si la *cookie* solo debería enviarse en caso de conexión https, pon este argument a *true*.
* **httponly**: Esta *cookie* solo será accesible a través de http. Es decir, no podrá accederse a la *cookie* desde Javascript.

Aquí tienes tres ejemplos de envío de la misma cookie:

```php
<?php 
$value = "I'm your father"; 

setcookie("VaderQuote", $value); 
setcookie("VaderQuote", $value, time()+3600);  // la cookie expira en una hora 
setcookie("VaderQuote", $value, time()+3600, "/quotes/", "bestquotes.com", 1); 
?>
```

#### Recuperar una cookie: $_COOKIES[]

Para ver el contenido de una *cookie*, simplemente hay que acceder al array global *$_COOKIES*. Por ejemplo: 

```php
<?php 
// Imprimir una cookie individual 
echo $_COOKIE["VaderQuote"]; 
?> 
```

#### Borrar una cookie 

Para forzar el borrado de una cookie en el cliente basta con enviarla con una fecha de expiración anterior a la fecha actual. Por ejemplo:

```php
<?php 
setcookie ("VaderQuote", "", time() - 3600);  // Establece la fecha de expiración una hora en el pasado
?>
``` 
