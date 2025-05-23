---
layout: page
title: 7 Ajax
permalink: /ajax/
parent: Desarrollo Web en Entorno Servidor
nav_order: 7
---
# 7. Ajax
{: .no_toc }

- TOC
{:toc}

## 7.1. Un poco de introducción al asunto

## 7.1.1. ¿Qué es Ajax?

**Ajax** significa **Asynchronous Javascript And XML**.

Qué bien, ¿no?

¿Y eso qué quiere decir?

Ajax es una tecnología javascript para lanzar y recibir las peticiones al servidor en segundo plano. La página sigue funcionando con normalidad mientras la petición al servidor se resuelve: el usuario puede interactuar con ella y la página responde y no se queda *congelada* a la espera de que el servidor conteste.

**Todo eso es lo que significa "de forma asíncrona"**.

Esta forma de trabajar, que puede parecer una chorrada, se creó para que las páginas dieran la impresión de ser más ágiles de lo que en realidad eran (sobre todo en una época en la que las redes eran más lentas y los servidores podían tardar bastante en responder).

En la actualidad, Ajax ha permitido algo que parecía impensable hace una década: que gran parte de la página se ejecute en el cliente y que se pidan al servidor solo los fragmentos de la página que necesitan ser actualizados. Ajax permite actualizar las páginas sin necesidad de recargarlas por completo, lo que mejora la usabilidad y velocidad de respuesta, y cambia radicalmente nuestra forma de programar una aplicación web.

### 7.1.2. Ajax no sirve, en realidad, para nada

Esa es la pura verdad.

Puedes programar una aplicación web completa, compleja y profesional sin hacer una sola petición Ajax.

Pero Ajax mejora el rendimiento y la experiencia del usuario. Puedes sustituir unas pocas peticiones convencionales por peticiones Ajax sin cambiar demasiado en tu aplicación. Por ejemplo, para borrar un recurso, puedes lanzar la petición DESTROY por Ajax y actualizar tu vista para eliminar el recurso del documento HTML cuando el servidor responda.

Esto es fácil de hacer. Y muy recomendable. Te aconsejo empezar a trastear con Ajax de este modo.

### 7.1.3. Y, sin embargo, Ajax ha cambiado la forma en la que desarrollamos aplicaciones web

Cómo algo que, en realidad, no sirve para nada ha logrado cambiar la forma en la que desarrollamos aplicaciones web puede parecer un misterio a simple vista, pero existe una razón muy simple para ello y te la cuento ahora mismo.

La mayoría de las aplicaciones web se pasan todo el tiempo haciendo lo mismo: accediendo a recursos de una base de datos para consultarlos, crearlos, modificarlos o borrarlos, todo ello mediante interfaces de usuario semejantes. Es decir, el interfaz de usuario para crear, modificar y borrar productos de una base de datos es prácticamente el mismo que el que se usa para crear, modificar y borrar proveedores, por decir algo.

Así que alguien se preguntó: *¿por qué estamos programando todo el tiempo lo mismo?*

Ajax nos permite hacer algo muy ingenioso para evitar este engorro: **diseñar un interfaz de usuario genérico y vacío, solo compuesto por contenedores preparados para nutrirse de datos del servidor**.

Por ejemplo, podemos diseñar un típico interfaz de usuario HTML que nos muestre una lista de recursos (productos, proveedores, o lo que sea) junto con los botones de "Update" y "Delete", además de un botón de "Add new". Pero ese interfaz estará vacío, y mediante Ajax lo cargaremos con productos, con proveedores o con lo que necesitemos. Crearemos el interfaz una vez y lo podemos reutilizar miles de veces, para todo tipo de recursos.

Este tipo de aplicaciones, también llamadas **SPA (Single-page applications)**, necesitan una arquitectura algo distinta de la que usamos en las aplicaciones web tradicionales, además de una librería en el lado del cliente para ayudarnos en la creación de contenedores genéricos (librerías como **Angular**, **React** o **Vue.js**). Aunque excede a nuestros propósitos profundizar en estas librerías, veremos algunos fundamentos sobre el uso de Vue.js con Laravel al final de este capítulo.

En lo que sigue de este capítulo, aprenderemos los fundamentos de Ajax usándolo de forma puntual en el entorno de una aplicación web convencional con arquitectura MVC, no construyendo una aplicación SPA, que es algo mucho más complejo que, en todo caso, llegará después.

## 7.2. Cómo enviar peticiones Ajax al servidor con JavaScript clásico

En este apartado vamos a aprender a enviar y recibir respuestas por Ajax **mediante JavaScript clásico**.

El objeto XMLHttpRequest es la forma tradicional de trabajar con Ajax en JavaScript. Hay rumores fundados de que este objeto va a ser declarado obsoleto en breve (puede que ya lo esté cuando leas estas líneas).

Por esa razón, no es muy buena idea usarlo para desarrollos nuevos. Sin embargo, lo vamos a ver aquí por dos razones: primera, porque hay mucho código antiguo JavaScript circulando por ahí donde lo vas a encontrar. Y, segunda, porque es una forma muy conveniente de comprender cómo funciona la comunicación asíncrona con el servidor.

En apartados posteriores veremos cómo trabajar con Ajax mediante otros mecanismos no (presuntamente) obsoletos.

### 7.2.1. Peticiones sin datos al servidor

La forma más sencilla (y primitiva) de usar Ajax es **lanzar una petición asíncrona al servidor** sin que el usuario de la web se percate de ello (porque se hará en segundo plano). El servidor no sabrá si la petición se lanzó en primer o en segundo plano y, en realidad, no le importa: él se limitará a atender la petición.

Para lanzar una petición mediante Ajax usando JavaScript tradicional (luego veremos cómo hacerlo con jQuery, que simplifica bastante el proceso), necesitamos crear un objeto de tipo **XMLHttpRequest**. Este objeto nos permitirá controlar todo el proceso de envío de la petición, recepción de la posible respuesta y control de los errores que hayan podido ocurrir.

Observa detenidamente este fragmento de código JavaScript:

```javascript
peticion_http = new XMLHttpRequest();
peticion_http.onreadystatechange = procesa_respuesta;
peticion_http.open('GET', 'http://servidor/recurso');
peticion_http.send(null);


function procesa_respuesta() {
    if(peticion_http.readyState == 4) {
      if(peticion_http.status == 200) {
        alert(peticion_http.responseText);
      }
    }
}
```

En las cuatro primeras líneas se crea el objeto de tipo XMLHttpRequest y luego se hacen tres cosas clave con él:
1. **Se le indica qué función se debe ejecutar cuando el servidor responda**. Recuerda que esta función se ejecutará también en segundo plano, sin que el usuario de la página se percate de que está sucediendo algo.
2. **Se le indica qué recurso del servidor se quiere invocar** (típicamente, una URL). Para ello se usa el método open(). Ahí también se indica el método de envío de datos al servidor (GET o POST), incluso si no se envían datos al servidor en absoluto, como en este ejemplo.
3. Por último, **se lanza la petición al servidor** con el método send(). El argumento "null" debe sustituirse por los datos que se envían al servidor mediante GET en caso de que los hubiera.

Eso deja lista la petición. JavaScript permanecerá a la escucha en segundo plano hasta que el servidor responda. Cuando lo haga, se ejecutará la función procesa_respuesta().

En esa función se hacen tres cosas muy importantes:
1. **Se comprueba si el estado de la petición (readyState) es 4**. Eso significa que el servidor ha terminado de procesarla. La petición pasa por varios estados hasta completarse, y el servidor informa de todos ellos. Es decir, la función procesa_respuesta() se ejecuta al menos una vez para cada uno de estos estados:
   * readyState == 1 -> OPENED: Se acaba de abrir la comunicación con el servidor. Es decir, se acaba de ejecutar open().
   * readyState == 2 -> HEADERS_RECEIVED: Se acaba de enviar la petición al servidor. Es decir, se acaba de ejecutar send().
   * readyState == 3 -> LOADING: Se está recibiendo la respuesta del servidor.
   * readyState == 4 -> DONE: Se ha recibido la respuesta del servidor.
   Por eso es necesario comprobar que readyState == 4 antes de hacer ninguna otra cosa.
2. **Se comprueba que la respuesta del servidor es 200**. Esto, según el protocolo http, significa que no hay errores en la página. El servidor puede responder con otros códigos, como 404 (recurso no encontrado) o 403 (prohibido el acceso a ese recurso). Puedes encontrar en miles de sitios de internet todas las posibles respuestas de una petición http.
3. Si readyState == 4 y status == 200, significa que **todo ha ido bien y el servidor ha respondido**. Ya podemos hacer lo que sea que tengamos que hacer con esa respuesta. En este ejemplo, nos hemos limitado a mostrar esa respuesta en un alert. Observa en el ejemplo como la respuesta del servidor se recibe en forma de String en el atributo responseText.

### 7.2.2. Peticiones con datos al servidor (GET)

Si has entendido el ejemplo anterior, este te va a costar muy poco. Simplemente, vamos a **enviar algunos datos al servidor por GET**, exactament igual que lo haríamos si los enviáramos mediante un formulario. De hecho, el servidor no notará la diferencia.

El código para lograrlo es este:

```javascript
var cp = document.getElementById("codigo_postal");
var telefono = document.getElementById("telefono");
 
query_string = "&codigo_postal=" + encodeURIComponent(cp.value) +
               "&telefono=" + encodeURIComponent(telefono.value);

peticion_http = new XMLHttpRequest();
peticion_http.onreadystatechange = procesa_respuesta;
peticion_http.open('GET', 'http://servidor/scrip.php');
peticion_http.send(query_string);

function procesa_respuesta() { .... }
```

No ponemos la función procesa_respuesta() porque es la misma de antes. En cambio, sí que hay algunos añadidos en el código de preparación de la solicitud, ¿verdad?

Para empezar, hemos cogido un par de datos de un formulario: el código postal y el teléfono (puede ser un formulario de alta de usario o algo por el estilo: recuerda que esto solo es un ejemplo).

Luego hemos creado una variable llamada queryString que contiene el string con los datos que queremos enviar al servidor por GET. Como los datos por GET se codifican en la URL, es necesario usar el formato de la URL (separando las variables con el carácter &) y codificar cualquier carácter especial (con la función encodeURIComponente() de Javascript).

Por último, en el momento de hacer send(), hemos agregado nuestra query_string para que sea enviada al servidor. Una vez allí, PHP la podrá procesar como cualquier otra string enviada por GET, es decir, usando las variables superglobales $_GET o $_REQUEST.

### 7.2.3. Peticiones con datos al servidor (POST)

Si, en lugar de enviar datos al servidor por GET, preferimos **enviar datos por POST**, la técnica es muy similar a la anterior, con un par de variaciones:

1. Debemos indicar "POST" en lugar de "GET" en el método open(), como es lógico.
2. Debemos indicarle a Ajax que el paquete http llevará variables POST en su cabecera. Para eso se usa el método setRequestHeader().

Lo puedes ver en el siguiente ejemplo:

```javascript
var cp = document.getElementById("codigo_postal");
var telefono = document.getElementById("telefono");
 
query_string = "&codigo_postal=" + encodeURIComponent(cp.value) +
               "&telefono=" + encodeURIComponent(telefono.value);

peticion_http = new XMLHttpRequest();
peticion_http.onreadystatechange = procesa_respuesta;
peticion_http.open("POST", "http://servidor/script.php");
peticion_http.setRequestHeader("Content-Type", "application/x-www-form-urlencoded");
peticion_http.send(query_string);

function procesa_respuesta() { .... }
```

### 7.2.4. Peticiones con datos al servidor (XML)

Todo esto está muy bien si lo que enviamos al servidor son un par de datos sueltos, como el código postal y el teléfono en los ejemplos anteriores. Pero **¿y si tenemos que enviar mucha información?** Digamos, por ejemplo, un array de códigos postales y teléfonos.

En ese caso, usar GET se hace inviable (por la limitación de caracteres), así que recurriremos a POST y **empaquetaremos nuestros datos en un string XML o JSON**. En este ejemplo, vamos a usar XML:

```javascript
var cp = document.getElementById("codigo_postal");
var telefono = document.getElementById("telefono");
xml = "<datos>" +
      "<cp>" + cp + </cp>" + <telefono> + telefono + </telefono> +
      "</datos>";

peticion_http = new XMLHttpRequest();
peticion_http.onreadystatechange = procesa_respuesta;
peticion_http.open("POST", "http://servidor/script.php");
peticion_http.setRequestHeader("Content-Type", "application/x-www-form-urlencoded");
peticion_http.send(xml);

function procesa_respuesta() { .... }
```

## 7.3. Cómo recibir la respuesta del servidor con JavaScript clásico

En todos los ejemplos anteriores, el servidor conestaba con un simple texto que mostrábamos por medio de un alert() de Javascript. Ni siquiera nos preocupamos por el contenido de ese texto. Podría ser cualquier cosa: algo como "petición procesada", "usuario borrado" o cosas por el estilo.

Pero **a veces el servidor tiene que contestar algo complejo**. Por ejemplo, una tabla completa. En ese caso, como es lógico, necesitamos recurrir a **XML o JSON** para empaquetar todos los datos de la respuesta y enviarlos desde el servidor hacia el cliente.

Vamos a ver un par de ejemplo, uno resuelto con XML y otro con JSON. En ninguno de los dos casos mostraremos cómo lo hace el servidor para crear los datos: supondremos que eso ya sabes hacerlo, puesto que se trata de PHP. Nos centraremos en cómo procesa Ajax, es decir, Javascript, esa respuesta.

### 7.3.1. Recepción de datos XML

En este ejemplo, el servidor nos devuelve un string XML consistente en un array de códigos postales y teléfonos (de clientes, de usuarios, de lo que sea. Recuerda -otra vez- que solo es un ejemplo).

Observa cómo esa respuesta se accede por medio de responseXML (no responseText, como hasta ahora). A partir de ahí, Javascript puede usar esa respuesta como un objeto XML cualquiera: puede buscar hijos de un nodo, puede buscar nodos por su tag, etc.

En el ejemplo, nos limitamos a recuperar el código postal y el teléfono del primer elemento del array y a mostrarlo en el documento preexistente, en una capa con el ID "respuesta".

```javascript
function procesaRespuesta() {
  if(peticion_http.readyState == 4) {
    if(peticion_http.status == 200) {
      var xml = peticion_http.responseXML;
      var datos = xml.getElementsByTagName("datos")[0];
      var telefono = datos.getElementsByTagName("telefono")[0].
                     firstChild.nodeValue;
      var cp = datos.getElementsByTagName("cp")[0].
               firstChild.nodeValue;
 
      document.getElementById("respuesta").innerHTML = 
             "Codigo postal = " + codigo_postal + "<br/>" + 
             "Telefono = " + telefono;
    }
  }
}
```

### 7.3.2. Recepción de datos JSON

Javascript prefiere JSON a XML, es no es un secreto. Casi todos los programadores lo prefieren, en realidad. Así que veamos cómo hacer lo mismo que antes, pero ahora con JSON.

La respuesta JSON llegará en responseText, no en responseXML. Eso significa que Javascript la recibe como un String cualquiera.

Luego, con la función eval() de Javascript, podemos convertir ese String en un objeto complejo y, a partir de ahí, usar ese objeto para acceder a todos sus elementos.

En el ejemplo, como antes, solo accederemos al primer código postal y al primer teléfono y los mostraremos en la capa "respuesta" de nuestro documento.

```javascript
function procesaRespuesta() {
  if(http_request.readyState == 4) {
  if(http_request.status == 200) {
    var json = http_request.responseText;
    var objeto_json = eval("("+json+")");
    var telefono = objeto_json.datos.telefono;
    var codigo_postal = objeto_json.datos.cp;
    document.getElementById("respuesta").innerHTML = 
             "Codigo postal = " + codigo_postal + "<br/>" + 
             "Telefono = " + telefono;
    }
  }
}
```

## 7.4. Ajax y jQuery

El uso de jQuery facilita enormemente la programación de llamadas Ajax al servidor. El decir: se puede manejar Ajax al 100% sin recurrir a jQuery, pero con jQuery es más fácil.

jQuery ofrece varias funciones para hacer llamadas Ajax:

* **$.ajax()** → La más configurable pero también la más compleja.
* **$.get()** → Para lanzar peticiones GET sencillas.
* **$.post()** → Para lanzar peticiones POST sencillas
* **$.load()** → Para lanzar peticiones GET y cargar la respuesta en una capa.

Vamos a verlas una por una.

### 7.4.1. Función $.ajax()

Tiene esta sintaxis:

```javascript
$.ajax({
  url: '/ruta/hasta/script.php',
  type: 'POST',
  data: 'parametro1=valor1&parametro2=valor2',
  contentType: 'tipo de contenido que enviamos al servidor',
  dataType: 'tipo de contenido con el que responde el servidor',
  success: function(data) { // Aquí el código para procesar la respuesta },
  fail: function() { // Aquí el código para procesar el error }
});
```

Bueno, en realidad $.ajax() admite más argumentos aparte de los que te muestro aquí arriba, pero estos son los principales. Si quieres verlos todos, te sugiero que te des una vuelta por la documentación oficial de jQuery, que por cierto es fantásticamente buena.

Observa como, en una sola invocación, conseguimos hacerlo todo: indicar la URL donde se dirigirá la petición, el tipo de envío de datos (GET o POST), los datos que enviamos al servidor, el tipo de datos que recibiremos como respuesta, el nombre de la función que procesará la respuesta e, incluso, el nombre de la función que procesará el error, en caso de que el servidor responda con un código de error.

En ***contentType*** puedes indicar el tipo de datos que vas a enviar al servidor. Por defecto, se supone que es 'application/x-www-form-urlencoded; charset=UTF-8', pero te puede interesar cambiarlo por 'multipart/form-data', por ejemplo, si vas a enviar un archivo binario (como una imagen).

En ***dataType*** puedes indicar el tipo de datos que se espera que te devuelva el servidor. Por defecto será 'text', es decir, texto plano, pero puedes indicar cosas muy variadas, como 'xml', 'json', 'html' o incluso 'script' si el servidor te va a devolver un fragmento de código JavaScript. Esto ayuda a su procesamiento posterior en la sección ***success***.

Por último, en la sección ***success*** puedes acceder a los datos devueltos por el servidor a través de la variable ***data***, que tendrá el formato correspondiente al tipo de datos que hayas indicado en ***dataType***. Por ejemplo, si en ***dataType*** especificaste que el servidor iba a responder con un objeto json, jQuery tratará de convertir la respuesta a un objeto asumiendo el formato json y te la dejará preparada y lista para usar en el parámetro ***data***.

Aquí vemos un ejemplo de uso de $.ajax():

```javascript
  $(document).ready(function () {
    $.ajax({
      type: "POST",
      url: "mi-script.php",
      data: {email: $("#email").val()},
      success: function (data) {
                  $("#message").html(data);
               },
      error: function (req, status, error) {
                  alert(req + " " + status + " " + error);
             }
    });
  });
```

Si es la primera vez que ves código jQuery, esto te sonará tanto como el chino mandarín. Pero no te agobies, que en realidad es muy fácil. Te lo explico en cuatro frases.

La primera línea, ***$(document).ready()***, sirve para indicar al navegador que no debe ejecutar la función que haya ahí dentro hasta que el documento no se haya cargado por completo y el árbol DOM desplegado en la memoria del cliente. Solo entonces se lanzará el resto del código. Es algo muy común en el código jQuery.

Después viene la llamada Ajax, con varios de los atributos que mencionábamos antes. Fíjate que no hemos usado ni ***dataType*** ni ***contentType***, por lo que se asumirán los valores por defecto.

En la sección ***data*** se especifican los datos que se envían a mi-script.php. Solo enviamos un email, pero podríamos enviarle más cosas. Observa que lo hemos formateado en json. Es lo más habitual.

En la sección ***success*** hemos colocado directamente el código de la función que se lanzará al recibir la respuesta del servidor. Esa forma de inyectar funciones sin nombre directamente es muy habitual de jQuery. La función se limita a tomar la respuesta del servidor y mostrarla en una capa con el ID "#message", pero, por supuesto, podría hacer cualquier otra cosa más compleja.

En la sección ***error***, por último, lanzamos un mensaje de error mediante un alert(), que solo saltará si ocurre algún error durante la petición Ajax. Fíjate en que esa función tiene tres parámetros (optativos) que utilizamos para informar al usuario con más detalle de qué error se ha producido.

### 7.4.2. Funciones $.get() y $.post()

En muchas ocasiones, no necesitamos usar ni la mínima parte de las posibilidades de la función $.ajax(). Cuando tenemos que **hacer una llamada sencillita por Ajax** al servidor y no queremos complicarnos la vida, puede ser más útil y rápido recurrir a las funciones **$.get()** y **$.post()**.

Como su propio nombre indica, $.get() lanza una petición Ajax mediante GET y $.post() hace lo mismo, pero con POST. Su sintaxis es esta:

```javascript
$.get(url, datos, funcion_manejadora);
$.post(url, datos, funcion_manejadora);
```

Aquí tienes un ejemplo en el que llamamos por Ajax a ***mi-script.php***, enviándole mediante GET un nick de usuario. El servidor responderá con un texto plano que contendrá el nombre de ese usuario y lo mostrará mediante un alert():

```javascript
$.get('mi-script.php',
      { user: 'juanperez03' },
      function(username) {
         alert('Hola, ' + username);
      }
);
```

### 7.4.3. Función $.load()

Un caso particularmente simple (y habitual) de uso de Ajax es aquel en el que **lanzamos una petición al servidor para rellenar una capa de nuestra página con la información que el servidor nos devuelve**.

Por ejemplo, imagina que tenemos un formulario de registro de usuarios y, en el campo del nick del usuario, deseamos comprobar si ese nick ya está en uso en la base de datos. Mediante Ajax, se puede hacer de forma dinámica y atractiva capturando el evento onblur en del campo nick y lanzando en ese momento una petición Ajax al servidor para que haga la consulta a la base de datos.

Si el usuario ya existe, el servidor puede responder con un texto el tipo "Ese usuario ya existe". En caso contrario, puede responder con "Ese nick está disponible" o algo así. En ambos casos, ese String puede mostrarse en una capa junto al cuadro de texto, una capa que, hasta ese momento, habrá estado vacía.

Este escenario tan habitual se puede resolver con $.ajax(), con $.get() o con $.post(), pero existe una función jQuery específica para ello. Se llama **$.load()** y tiene esta sintaxis:

```javascript
$('#info').load('mi-script.php');
```

Simplemente, se ejecuta ***mi-script.php*** en el servidor y se carga el texto de respuesta en la capa #info. Sin funcion manejadora ni historias. Más fácil, imposible, ¿verdad?

## 7.5. Ajax y la API Fetch

Hubo un tiempo en el que todos los programadores que querían una sintaxis limpia a la hora de usar Ajax se decantaban por jQuery. Sin embargo, la tecnología en el campo del desarrollo web cambia tan deprisa, que jQuery ya se considera una biblioteca algo desfasada.

Sin embargo, la sintaxis de $.ajax(), la función de jQuery para gestionar llamadas Ajax, ha tenido un eco en las versiones más recientes de JavaScript, que ahora tiene su propia forma integrada de hacer solicitudes Ajax: mediante la **API Fetch**, un nuevo estándar para realizar solicitudes de servidor.

En esta sección vamos a aprender a lanzar peticiones GET y POST usando la API Fetch de JavaScript.

### 7.5.1. Promesas de JavaScript

Para hacer peticiones asíncronas al servidor el la API Fetch, usaremos el **método *fetch()***.

Y el método *fetch()* devuelve lo que en JavaScript se denomina **una promesa** (*promise*), así que, antes de continuar, tenemos que comprender qué es eso de las promesas.

#### Entendiendo las *promesas* de JavaScript

Imagina que vas a pedir una pizza a un local de comida rápida. Pagas en el mostrador y te dan un ticket con un número. Cuando llamen a ese número, podrás recoger tu pizza.

*Ese ticket es una promesa.*

El ticket significa que, en el futuro, obtendrás una pizza. Pero que todavía no la tienes.

Cuando llaman a tu número, significa que la promesa se ha cumplido. Si no te llaman, significa que la promesa no se cumplió.

Hay múltiples razones por las que una promesa puede no cumplirse nunca, ¿verdad? En el caso de la pizza, puede que el cocinero se quede sin ingredientes, puede que un inspector de sanidad cierre el establecimiento o puede haber un incendio en la cocina.

Literalmente, hay millones de razones por las que una promesa podría no cumplirse, aunque lo normal es que lo haga.

En resumen, una promesa se resuelve cuando ocurre alguna de estas cosas:

* Obtenemos la comida.
* No obtenemos la comida pero sí una razón de por qué no.

Las promesas, de hecho, pueden estar en **3 estados**:

* **Pendientes**. Una promesa recién lanzada está en este estado.
* **Resueltas**. La promesa pasa a este estado si se resuelve correctamente.
* **Rechazadas**. La promesa pasa a este estado si se produce un error y no puede atenderse la petición.

Con Javascript no vas a pedir una pizza, como es lógico, pero sí que puedes pedir datos al servidor de forma asíncrona, que es justo lo que hace Ajax. El Javascript moderno maneja estas peticiones al servidor mediante promesas, de forma que, cuando se pide una URL al servidor, se crea una promesa en estado "pendiente" y, cuando el servidor responde, la promesa pasa a estar "resuelta" o "rechazada", dependiendo de la respuesta.

Vas a ver como, con el nuevo estilo funcional de Javascript, es muy fácil lanzar la petición Ajax con *fetch()* y atender las respuestas del servidor.

### 7.5.2. Lanzando peticiones asíncronas con *Fetch*

La sintaxis básica de una petición asíncrona con *fetch()* es esta:

```javascript
fetch(url)
  .then(function() {
    // Este código se ejecuta cuando el estado pasa a "Promesa Resuelta"
  })
  .catch(function() {
    // Este código se ejecuta cuando el estado pasa a "Promesa Rechazada"
  });
```
 
Con el método *fetch()* se obtiene una **promesa**. La *url* es, lógicamente, la dirección del servidor a la que se lanza la petición. Si la promesa se resuelve con éxito, es decir, si el servidor responde correctamente, se ejecuta la función dentro del método *then()*. Y, si falla, se ejecuta la función que hay dentro de *catch()*.

Lo habitual, por supuesto, es que **el servidor responda a nuestras peticiones con datos**. Puede ser algo tan simple como un valor booleano o algo tan complejo como una tabla llena de objetos formateada en JSON.

Si la llamada al servidor va a devolver datos, estos se recogen en un parámetro de la función del *then()*. Del mismo modo, si se ha producido un error, este se recoge como parámetro en la función del *catch()*:

```javascript
fetch('https://mi-servidor/mi-ruta')
  .then(function(data) {
    // Procesar la respuesta. Los datos están en "data"
  })
  .catch(function(error) {
    // Procesar el error. El error está en "error"
  });
```

### 7.5.3. Lanzar peticiones por POST

Fetch supondrá que todas las peticiones al servidor se envían por GET, salvo que se le indique lo contrario. De hecho, la petición anterior también puede escribirse así:

```javascript
fetch('https://mi-servidor/mi-ruta', {method: "GET"})
  .then(function(data) {
    // Procesar la respuesta. Los datos están en "data"
  })
  .catch(function(error) {
    // Procesar el error. El error está en "error"
  });
```

Para lanzar **una petición por POST** se debe utlizar el segundo argumento de la función *fetch()*, indicando que le método de envío será POST y cuál es el contenido del encabezado http, donde se empaquetan los datos de todas las peticiones POST.

Por ejemplo:

```javascript
const url = 'https://mi-servidor/mi-ruta';

let data = {
  name: 'Pepe',
  age: 42
}

let httpData = {
  method: 'POST',
  body: data,
  headers: new Headers()
}

fetch('https://mi-servidor/mi-ruta', {
  method: 'POST',
  body: {name: 'Fulgencio', age: 42},
  headers: {"Content-type": "application/json; charset=UTF-8"}
})
.then(function() {
    // Procesar la respuesta del servidor
});
```

Esta petición *fetch()* está enviando por POST al servidor dos datos, "name" (con el valor "Fulgencio") y "age" (con el valor "42").

El API Fetch puede usarse de otras maneras y, además, aún está en desarrollo, por lo que sufrirá cambios continuos en los próximos años. Pero con esto tienesf más que suficiente para empezar a trabajar con el servidor en modo asíncrono en una gran variedad de situaciones diferentes.

## 7.6. Ajax y Laravel

Al trabajar con **Laravel**, estamos acostumbrados a que cada método del controlador termine devolviendo una vista completa (*return view...*). ¿Pero qué pasa si hacemos una petición Ajax a una aplicación web escrita con Laravel en el lado del servidor?

Laravel puede continuar devolviendo una vista completa, pero eso no suele ser lo que Ajax espera recibir como respuesta. Ajax espera respuestas cortas y concisas: algo como 'true' o 'false', o un número, o un String o, como mucho, una estructura de datos más compleja formateada en XML o JSON. Pero no una página web completa con su cabecera, su cuerpo y toda la parafernalia.

Y eso es precisamente lo que devuelve Laravel al rederizar cualquier vista. Así que, ¿cómo lo hacemos?

### 7.6.1. Paso 1. Crear un controlador para las peticiones Ajax

Esto no es imprescindible, pero sí suele ser una práctica habitual: **reunir todas las peticiones Ajax en un único controlador**. 

Ten en cuenta que, para el servidor, no hay diferencia entre una petición Ajax y una petición normal. El servidor recibe su petición por http o https y la atiende, ejecutando en enrutador, el controlador y todo lo que venga detrás, y produciendo una salida como resultado que se envía de vuelta al cliente. Punto.

Así que suele ser buena idea separar las peticiones Ajax de las peticiones normales mediante la diferenciación de controladores, salvo que tengas una muy biena razón para no hacerlo.

Por lo tanto, crearemos un controlador ***AjaxController*** y añadiremos a nuestro enrutador (*/routes/web.php*) las líneas correspondientes, como esta:

```php
Route::post('miJqueryAjax','AjaxController@miMetodo');
```

### 7.6.2. Paso 2. Crear los métodos del controlador

Lo siguiente sería **crear los métodos que necesitemos en AjaxController** (o, si hemos decidido no crear un controlador específico para Ajax, crear los métodos en los controladores que corresponda).

Solo hay que tener una cosa clara: estos métodos que responderán a las peticiones Ajax **no pueden terminar con una vista**. 

Imagina un método que reponderá a una petición Ajax y que solo deba responder con un String, cuyo valor pueda ser "Ese usuario ya existe" o "Usuario disponible". Lo haríamos así:

```php
class AjaxController extends Controller {
   public function miMetodo() {
     ...aquí va mi código... 
     if ($lo_que_sea) $result = "Ese usuario ya existe";
     else $result = "Usuario disponible";
     return $result;
   }
}
```

Imagina ahora que queremos devolver algo más complicado, como un array o una colección de datos. No pasa nada: los formateamos como json y los enviamos de regreso al cliente, así:

```php
class AjaxController extends Controller {
   public function miMetodo() {
     ...aquí va mi código... 
      return response()->json($mi_variable_compleja);
   }
}
```

Por supuesto, esta última manera también te funcionará para devolver un simple String, un booleano o un entero. Es la forma más conveniente de terminar un método de un controlador que va a ser invocado por Ajax y no mediante una petición normal al servidor.

Ten en cuenta que:

* La salida de una petición Ajax suele ser JSON, pero podría ser otra cosa: HTML, XML o simple texto plano.
* Lo repetimos una vez más: para responder a una petición Ajax no se debe renderizar una vista (¡salvo que tengas una muy buena excusa para hacerlo!), sino que basta con un return response().

### 7.6.3. Paso 3. Agregar el token CSRF a las peticiones

Como vimos al estudiar Laravel, **las peticiones enviadas por POST con Laravel deben llevar el token CSRF** o serán rechazadas. Esto se hacía para prevenir cierto tipo de ataques frecuentes a través de formularios HTML. Los detalles no son importantes aquí y, en todo caso, puedes repasar el capítulo sobre Laravel o sobre Sesiones, Cookies y Seguridad para revisar el concepto.

Lo importante ahora es esto: cuando lances una petición POST mediante Ajax, Laravel la rechazará porque no llevará el token CSRF. Recuerda que el servidor no tiene ni idea de si la petición llega desde Ajax o no: para él, se trata de datos que provienen de un formulario HTML, y si no lleva ese token, automáticamente se convierte en un formulario sospechoso.

Así que, si tienes Laravel en el lado del servidor, **necesitas agregar el token CSRF a las peticiones por POST**, así:

```javascript
$.ajax({
     method: "POST",
     url: "mi-url",
     data: {
         "_token": "{% raw %}{{ csrf_token() }}{% endraw %}"
     },
     ...etc... 
});
```

Por supuesto, puedes añadir más ***data*** a tu petición: tantos datos como necesites enviar al servidor.

Como esto puede ser un poco engorroso, hay una forma de agregar automáticamente el token CSRF a **todas** las peticiones. Basta con escribir esto en el header de nuestro layout:

```html
   <meta name="csrf-token" content="{% raw %}{{ csrf_token() }}{% endraw %}">
   <script type="text/javascript">
      $.ajaxSetup({
          headers: {
             'X-CSRF-TOKEN': $('meta[name="csrf-token"]').attr('content')
          }
      });
   </script>
```

A partir de ahora, podremos hacer las peticiones Ajax normalmente, porque el token CSRF se añadirá él solito a cada petición Ajax.

## 7.7. Creando una OVA con Vue.js y PHP

**Vue.js** (o, más popularmente, Vue) es un framework para Javascript pensado para ayudarte a crear **interfaces de usuario y aplicaciones OVA** (one-view-application).

Vue.js añade ciertos componentes tanto a Javascript como a HTML para facilitar la creación de este tipo de aplicaciones. Aunque no es parte de nuestra materia (ya que es un framework del lado del cliente), puedes encontrar una introducción a Vue.js en los apéndices de estos mismos apuntes.

Ten en cuenta que, además de Vue.js, existen otros frameworks que trabajan de forma parecida, como Angular o React. Puedes investigar un poco por ahí y verás que los tres tienen más semejanzas que diferencias.

Vue.js hace todas las peticiones al servidor de forma asíncrona, es decir, usando Ajax, pero queda tan encapsulado por el framework que el programador no es consciente de estar haciendo peticiones Ajax.

En esta sección vamos a ver un **pequeño ejemplo**: vamos a crear con Vue.js el front para consumir un servicio API REST basado en una tabla de Libros que podría formar parte de un sistema mayor (por ejemplo, una biblioteca).

Sin más preámbulos, te presento el código:

```html
<script src="https://cdn.jsdelivr.net/npm/vue/dist/vue.js"></script>
<template>
  <div>
    <table>
      <tr>
        <th>ID</th>
        <th>Título</th>
        <th>Número de páginas</th>
        <th>Género</th>
        <th>País</th>
        <th>Año</th>
      </tr>
      <tr v-for="libro in libros" :key="libro.idLibro">
        <td>{{ libro.idLibro }}</td>
        <td>{{ libro.titulo }}</td>
        <td>{{ libro.numPaginas }}</td>
        <td>{{ libro.genero }}</td>
        <td>{{ libro.pais }}</td>
        <td>{{ libro.ano }}</td>
      </tr>
    </table>
  </div>
</template>

<script>
export default {
  data() {
    return {
      libros: []
    }
  },
  created() {
    this.cargarLibros();
  },
  methods: {
    async cargarLibros() {
      try {
        const response = await axios.get('https://tu-api-rest.com/libros');
        this.libros = response.data;
      } catch (error) {
        console.error(error);
      }
    }
  }
}
</script>
```

Este código crea una tabla HTML que muestra los libros obtenidos de la API REST. La tabla se construye a partir de una lista de libros que se encuentra en el objeto data del componente Vue. Cada vez que el componente se cree, se llama al método cargarLibros() que hace una petición HTTP GET a la API REST utilizando la librería Axios. Cuando se obtiene la respuesta de la API, se actualiza el objeto data libros con los datos obtenidos.

Otro enfoque: 

```html
<template>
  <div>
    <table>
      <tr>
        <th>ID</th>
        <th>Título</th>
        <th>Número de páginas</th>
        <th>Género</th>
        <th>País</th>
        <th>Año</th>
      </tr>
      <tr v-for="libro in libros" :key="libro.idLibro">
        <td>{{ libro.idLibro }}</td>
        <td>{{ libro.titulo }}</td>
        <td>{{ libro.numPaginas }}</td>
        <td>{{ libro.genero }}</td>
        <td>{{ libro.pais }}</td>
        <td>{{ libro.ano }}</td>
      </tr>
    </table>
  </div>
</template>

<script>
export default {
  data() {
    return {
      libros: []
    }
  },
  created() {
    this.cargarLibros();
  },
  methods: {
    async cargarLibros() {
      try {
        const response = await axios.get('https://tu-api-rest.com/libros');
        this.libros = response.data;
      } catch (error) {
        console.error(error);
      }
    }
  }
}
</script>

<!-- utiliza el componente en tu aplicación Vue -->
<div id="app">
  <libros-tabla></libros-tabla>
</div>

<!-- registra el componente en la aplicación Vue -->
<script>
new Vue({
  el: '#app',
  components: {
    'libros-tabla': LibrosTabla
  }
});
</script>
```

