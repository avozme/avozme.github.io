---
layout: page
title: 6 Servicios web
permalink: /servicios-web/
parent: Desarrollo Web en Entorno Servidor
nav_order: 6
---
# 6. Servicios web
{: .no_toc }

- TOC
{:toc}

Los **servicios web** son un tipo particular de aplicación web: una aplicación pensada no solo para ser usada por usuarios humanos, sino por otras aplicaciones.

Existen dos estándares para crear servicios web. En este tema, vamos a estudiar esos dos estándares y a ver cómo podemos construir una aplicación de este tipo.

## 6.1. ¿Qué es un servicio web?

### 6.1.1. Una definición de servicio web

Un **servicio web** es una aplicación web capaz de **comunicarse e intercambiar información con otra aplicación** (que denominaremos *cliente*) independientemente de la plataforma en la que cada una se ejecute.

Es decir, el servicio web puede estar programado en PHP y correr bajo un sistema operativo GNU/Linux y el cliente puede estar programado con C# y correr bajo un Windows, y deberían ser capaces de comunicarse y trabajar juntas. Pero es importante que quede claro que, en este caso, la aplicación web (servidor) y la aplicación cliente *son dos aplicaciones diferentes*.

Los mensajes que las aplicaciones se intercambian generalmente tienen formato **XML** o **JSON**.

Existen dos estándares principales en la industria para implementar servicios web, denominados **SOAP** y **REST**. A lo largo el tema, vamos a aprender cómo funciona cada uno de ellos.

### 6.1.2. Diferencias entre servicios web y aplicaciones web

Llegados a este punto, puede que estés pensando: "Vale, pero ¿en qué se diferencia todo esto de una aplicación web MVC? ¿No intercambian también el cliente y el servidor información independientemente de la plataforma en la que se ejecuta cada uno?".

Pues sí, pero hay algunas **diferencias fundamentales entre un *servicio web* y una *aplicación web***:

* Una aplicación web está diseñada para que un ser humano interactúe con ella a través de un interfaz DHTML. Un servicio web, en cambio, está pensado para que lo use otra aplicación informática (el cliente), no necesariamente un ser humano.
* Por ese motivo, los servicios web suelen carecer de interfaz de usuario y no producen salidas HTML legibles. Es decir, un servicio web puro **no suele tener vistas**.
* En cambio, los servicios web suelen producir salidas XML o JSON, pensadas para que los clientes las procesen. Una aplicación web, en cambio, solo responde con XML o JSON cuando recibe una petición Ajax, algo que veremos en el tema siguiente.

Por lo demás, un servicio web puede tener una arquitectura *aproximadamente* MVC, y digo *aproximadamente* porque el servicio web, como acabo de contarte, carece de vistas. Pero puede seguir conservando sus controladores y sus modelos. Los controladores se encargarán de convertir los datos de los modelos a JSON o XML y devolverlos al cliente.

## 6.2. SOAP

**SOAP (Single Object Access Protocol)** es un mecanismo estandarizado para la implementación, descripción y publicación de servicios en red.

SOAP establece el modo en el que deben comportarse el cliente y el servidor para hablar entre sí, así como la forma en la que el servidor debe dar a conocer sus servicios.

### 6.2.1. La pila de protocolos de SOAP

El estándar **SOAP** define una serie de protocolos de niveles de abstracción crecientes. Esta colección de protocolos suele denominarse **pila de protocolos SOAP**, y son los siguientes:

Nivel de abstracción|Protocolo
-|-
Nivel de descubrimiento|UDDI
-|-
Nivel de publicación|UDDI
-|-
Nivel de descripción|WSDL
-|-
Nivel de mensajería|SOAP
-|-
Nivel de red|TCP, SMTP, FTP, etc

Como ves, SOAP solo es uno de los protocolos de la pila, aunque todo el tinglado recibe el nombre "SOAP" por extensión.

Vamos a explicar brevemente en qué consiste cada protocolo de la pila, y lo vamos a hacer, como en otras ocasiones, por medio de unos ejemplos en lugar de perdernos en largas y farragosas explicaciones.

### 6.2.2. Los protocolos SOAP y WSDL

Para entender cómo funciona el **protocolo SOAP** (el más importante de la pila, como ya te habrás imaginado por su nombre) y, en menor medida, el **protocolo WSDL**, vamos a implementar tres ejemplos de servicios web muy sencillos:

* En el primero veremos cómo construir un servidor que devuelva colecciones de datos en forma de array.
* En el segundo veremos cómo puede un servidor devolver datos con estructura más compleja formateados con JSON.
* En el tercero montaremos un pequeño servidor con WSDL.

#### Ejemplo 1: Consulta de una BD de marcas y modelos de coches

Vamos a programar un servicio web muy simple capaz de servir a los clientes que nos lo pidan un listado de las **marcas de coches** que existen y otro con los **modelos** registrados que pertenecen a una marca en concreto.

El servidor, por lo tanto, necesita dos funciones:

* obtenerMarcas
* obtenerModelos($idMarca)

Aquí ya se ve la primera diferencia con REST: ni los nombres de los métodos están estandarizados, ni hay una colección de métodos predefinidos para cada tipo de recurso. Cuando veamos REST en el siguiente apartado, entenderás mejor qué significa esta afirmación.

El cliente, como es lógico, debe conocer cómo utilizar el servidor. Esto puede hacerse mediante el protocolo WSDL (que ya veremos un poco después) o por otras vías más tradicionales: documentación de la API, guía del desarrollador, manual de usuario...

En estos ejemplos, tanto el servidor como el cliente estarán escritos en PHP. Por supuesto, puede usarse cualquier otro lenguaje para ello, en particular en el lado del cliente. Para saber cómo hacer un cliente SOAP en otros lenguajes, consulta la documentación de tu lenguaje preferido.

**EN EL LADO DEL SERVIDOR** necesitaremos crear un objeto de tipo *SoapServer* y definir los métodos a los que el servidor va a responder. La clase *SoapServer* forma parte de la biblioteca de clases estándar de PHP y debería estar disponible en tu servidor a partir de PHP5.

Vamos a empezar por los métodos. Crearemos un fichero (por ejemplo, llamado **GestionAutomoviles.class.php**) en cuyo interior escribiremos una clase con los métodos que necesitemos. Para nuestro ejemplo de marcas y modelos de coches, podría ser algo así:

```php
class GestionAutomoviles
{
  public function obtenerMarcas()
    {
      $db = new mysqli(<datos-de-la-conexión>);

      $marcas = array();
      if( $db )
      {
        $result = $db->query('select id, marca from marcas');
        while( $row = $result->fetch_array() )
          $marcas[$row['id']] = $row['marca'];
        $db->close();
      }

      return $marcas;
    }
    
    public function obtenerModelos($idMarca)
    {		
      $db = new mysqli(<datos-de-la-conexión>);
      $modelos = array();

      if( $marca !== 0 )
      {
        $result = $db->query('select id, modelo from modelos
                                where marca = ' . $idMarca );
        while( $row = $result->fetch_array() )
            $modelos[$row['id']] = $row['modelo'];
      }
      $db->close();
      return $modelos;
    }
}
```

Ahora, en otro archivo aparte que llamaremos, por ejemplo, **webservice.php**, *registramos el servicio* usando la clase *SoapServer* de PHP y asignándole la clase anterior, *GestionAutomoviles*. Se hace así:

```php
<?php
   include 'GestionAutomoviles.class.php';
   $soap = new SoapServer(null, array('uri' => 'http://localhost/'));
   $soap->setClass('GestionAutomoviles');
   $soap->handle();
?>
```

Si observas el constructor de *SoapServer* verás que tiene dos argumentos:

* El **fichero WSDL** donde se describe el servicio. Como aún no vamos a usar fichero WSDL, ese argumento lo dejaremos a *null* por ahora.
* La **URI** donde el servidor va a estar escuchando. Puede ser el directorio raíz de nuestro servidor o cualquier subdirectorio o archivo. En el ejemplo, hemos puesto simplemente *localhost*, pero tú tendrás que adaptarlo a tu servidor.

**EN EL LADO DEL CLIENTE**: para comprobar que nuestro servidor SOAP funciona bien, necesitamos crear un secillo cliente que consuma ese servicio. Como hemos dicho antes, esta parte también la vamos a programar en PHP, aunque podría hacerse en cualquier otro lenguaje con soporte SOAP.

Necesitamos crear un objeto de tipo *SoapClient*:

```php
$soapS = new SoapServer(null, "URI del servidor");
```

Nuevamente, el primer argumento del constructor es el fichero WSDL. Como aún no trabajamos con ellos, lo dejamos a null. Si tuviéramos fichero WSDL, no necesitaríamos indicar la URI del servidor, porque el propio fichero WSDL lo establecería de forma inequívoca.

Una vez hecho eso, podemos consumir los servicios del cliente. Por ejemplo: 

```php
<?php
   $client = new SoapClient(null, array('uri' => 'http://localhost/',
       'location' => 'http://localhost/<ruta>/webservice.php'));
   $marcas = $client->obtenerMarcas();
   foreach($marcas as $key => $value )
      echo $value;   
?>
```

Fíjate en la manera en la que hemos indicado la localización del servidor: en un array, le decimos a *SoapClient* su ubicación y la ruta de acceso al fichero que maneja el servicio (en nuestro ejemplo, webservice.php).

#### Ejemplo 2: Lista de libros de una biblioteca.

El ejemplo anterior funciona porque tanto cliente como servidor trabajan en PHP. Pero si el cliente no fuera PHP, podría tener problemas al recibir los datos de respuesta del servidor, que son arrays PHP.

Lo más adecuado cuando se responden datos complejos es enviarlos en algún formato estándar de intercambio de información, como **XML o JSON**.

En este nuevo ejemplo, vamos a crear un servidor que nos devuelva la **lista de libros de una biblioteca** (lo que incluirá el id, el título y el ISBN de cada libro) empaquetada en un string **JSON**.

De momento, tampoco usaremos WSDL (fichero de descripción del servicio).

**LADO DEL SERVIDOR** 

Definimos los métodos de nuestro servidor (archivo *libros.class.php*). En este ejemplo, solo habrá un método :

```php
class libros
{
      private function getLibrosJSON()
      {
         $sql = "SELECT * FROM libros";
         $db = new dbAbstract();  // Suponemos que existe una capa
                                  // de abstracción de datos
         return json_encode($db->consulta($sql));
     }
     ...aquí irían más métodos que pudiera tener el servidor
}
```     
     
Después, registramos el servidor (archivo *libros.server.php*):

```php
<?php
   include 'libros.class.php';
   $soap = new SoapServer(null, array('uri' => 'http://localhost/'));
   $soap->setClass('libros');
   $soap->handle();
?>
```

**LADO DEL CLIENTE**

De nuevo, lo vamos a crear en PHP, que es el lenguaje con el que estamos trabajando, pero podrías programarlo con cualquier otro lenguaje de programación de tu elección. 

```php
<?php
   $client = new SoapClient(null, array('uri' => 'http://localhost/',
       'location' => 'http://localhost/libros.server.php'));
   $listaLibros = $libros->getLibrosJSON();
?>
```

A partir de ahí, el cliente dispondrá en la variable *$listaLibros* de la información recibida del servidor (id, titulo, isbn de todos los libros) empaquetada en formato JSON.

#### Ejemplo 3: Servicio de calculadora

Este será un servicio mucho más simple y hasta un poco tontorrón, pero no te lo tomes a mal: solo es un ejemplo.

El servicio simple y tontorrón proporcionará dos métodos:

* **sumar (op1, op2)** --> Devuelve la suma de op1 y op2
* **restar (op1, op2)** --> Devuelve la diferencia entre op1 y op2

Y va a ser un servicio muy simple y tontorrón porque, ahora sí, **usaremos WSDL para definir el servicio** y que los clientes sepan cómo usarlo. Así será más fácil que entiendas la estructura de estos ficheros, que no son nada fáciles de entender porque no están escritos para que los lean personas, sino otros programas.

**LADO DEL SERVIDOR**

El código de este servidor es extremadamente simple. Fíjate en que ahora, el crear el objeto SoapServer, sí indicamos el nombre del archivo WSDL (*calculadora.wsdl*):

```php
<?php
   $server = new SoapServer("calculadora.wsdl");
 
   function sumar($operando1,$operando2){
      return $operando1 + $operando2;
   }
 
   function restar($operando1,$operando2){
      return $operando1 - $operando2;
   }
 
   $server->AddFunction("sumar");
   $server->AddFunction("restar");
   $server->handle();
?>
```

**LADO DEL CLIENTE**

El cliente lo volveremos a programar en PHP, aunque ya sabes que puedes programarlo en cualquier otro lenguaje.

Fíjate en que también indicamos el archivo WSDL al crear el objeto *SoapClient*, y no es necesario informarle de nada más porque el archivo WSDL ya contiene todo lo necesario para que el cliente sepa conectarse al servidor:

```php
<?php
 $clienteSOAP = new SoapClient('http://ejemplo.com/test/wsdl/calculadora.wsdl');
 
 // Vamos a probar el servidor con un par de llamadas de ejemplo
 $resultado_suma = $clienteSOAP->sumar(4.75, 12.5);
 $resultado_resta = $clienteSOAP->restar(4.75, 12.5);
 
 echo "La suma es: " . $resultado_suma . "<br>";
 echo "La resta es: " . $resultado_resta . "<br>";
?>
```

**DOCUMENTO WSDL**

El documento WSDL es un archivo de texto alojado en el servidor donde se describen todos los aspectos del servicio:

* Los **mensajes** que se pueden intercambiar entre el cliente y el servidor.
* Los **argumentos** y tipos de datos de esos mensajes.
* Las **operaciones** y sus tipos
* Las **rutas** donde puede encontrarse el servidor

Se trata de un documento en formato XML que resulta bastante farragoso de leer, así que tómatelo con calma (ahora entenderás por qué hemos elegido un servicio tan simple como el de este ejemplo para ver su archivo WSDL: si usáramos un servicio más realista, el archivo resultaría un monstruo de miles de líneas).

Aquí lo tienes:

```xml
  <message name="calculadoraPeticion">
    <part name="operando1" type="xsd:float" />
    <part name="operando2" type="xsd:float" />
  </message>
 
  <message name="calculadoraRespuesta">
    <part name="respuesta" type="xsd:float" />
  </message>

  <portType name="calculadoraPort">
    <operation name="sumar">
      <input message="tns:calculadoraPeticion" />
      <output message="tns:calculadoraRespuesta" />
    </operation>
    <operation name="restar">
      <input message="tns:calculadoraPeticion" />
      <output message="tns:calculadoraRespuesta" />
    </operation>
  </portType>

  <binding name="calculadoraBinding" type="tns:calculadoraPort">
    <soap:binding style="rpc" />
    <operation name="sumar">
        <soap:operation soapAction="urn:calculadora#sumar" />
        <input>
          <soap:body use="encoded" namespace="urn:calculadora" />
        </input>
        <output>
          <soap:body use="encoded" namespace="urn:calculadora" />
        </output>
    </operation>
    <operation name="restar">
        <soap:operation soapAction="urn:calculadora#restar" />
        <input>
          <soap:body use="encoded" namespace="urn:calculadora"/>
        </input>
       <output>
          <soap:body use="encoded" namespace="urn:calculadora"/>
        </output>
    </operation>
  </binding>
  
  <service name="calculadoraServicio">
    <port name="calculadoraPort" binding="tns:calculadoraBinding">
      <soap:address location="http://ejemplo.com/test/wsdl/calculadora_server.php" />
    </port>
  </service>
```

Escribir los documentos WSDL a mano es casi imposible. Y hacerlo sin cometer errores, es imposible del todo. Para eso existen **herramientas automatizadas** que toman el archivo con la clase que contiene los métodos del servicio y generan automáticamente el archivo WSDL.

Puedes encontrar estas herramientas de creación automática del archivo WSDL en cualquier IDE avanzado (como Netbeans o Eclipse) y también en muchos sitios web.

Por lo tanto, no es un documento que vayas a tener que redactar tú, ni siquiera que leer tú: se trata de una descripción del servicio escrita por y para programas informáticos. Por eso no tiene un formato demasiado legible para un humano.
  
### 6.2.3. UDDI

Este protocolo, que también forma parte de la pila SOAP, es muy fácil de explicar.

*Olvídate de que existe*. 

Fin de la explicación. Fácil, ¿verdad?

Por si esta explicación te sabe a poco, te diré que UDDI fue un intento de la industria por estandarizar repositorios de servicios, de manera que cualquier cliente pudiera lanzar una petición a la red para descubrirlos y usarlos.

Imagina que tienes una web que necesita conocer la previsión del tiempo en una zona, la que sea. Puedes localizar un servicio web que te proporcione esa información (ya sea de forma gratuita o mediante una suscripción, eso es irrelevante). Hay, de hecho, muchos servidores que ofrecen este servicio, empezando por el de la Agencia Estatal de Meteorología de España.

Para usar ese servicio, tienes que conocer el servidor que lo ofrece y luego bucear en su API para avieriguar cómo narices debes pedirle la información y en qué formato te la va a devolver. Y, una vez hecho eso, ya estás listo para programar tu cliente y consumir ese servicio.

Pues bien: el servicio UDDI buscaba implementar una manera para que el servidor publicara el tipo de servicio que oferta y los clientes pudieran escanear la red en busca de esos servicios, para luego seleccionar uno y lanzar peticiones contra él, todo ello de forma automatizada y transparente al programador.

Era una idea interesante, ¿verdad? Pero murió hace mucho. De hecho, entró en punto muerto en el año 2006, cuando Microsoft e IBM decidieron abandonar el proyecto.

Así que, lo dicho: aunque en teoría el protocolo UDDI forma parte de la pila SOAP, puedes actuar como si no existiera.

## 6.3. REST

### 6.3.1. ¿Qué es REST?

**REST (Representational State Transfer)** es un mecanismo de intercambio de información entre clientes y servidores de una red.

A diferencia de SOAP, está orientado a los datos, esto es, proporciona siempre los mismos tipos de acceso a los recursos, sin posibilidad de definir nuevas operaciones.

Por esa razón se dice que **REST está orientado a los datos** mientras que **SOAP está orientado a los procesos**.

Actualmente, gran parte de las APIs, ya sean públicas o privadas, se programan según el diseño REST para que los programadores que las usen sepan qué esperar de la API sin necesidad de consultar farragosas páginas de documentación o de pelearse con el servidor mediante el infalible método de ensayo y error.

### 6.3.2. Las 7 operaciones REST

Un servidor REST debe implementar **siete operaciones de acceso a cada tipo de recurso**. 

Si no las implementa, ya no es REST. Podrá ser *aproximadamente* REST, pero no REST.

Los nombres de las operaciones, los datos que se esperan que se devuelvan y el verbo http de acceso deben respetarse escrupulosamente.

Imagina que estamos programando un servidor REST para acceder, por ejemplo, a un recurso llamado *Producto* dentro de una aplicación más grande (por ejemplo, una tienda online). En la siguiente tabla tienes las siete operaciones que un servidor REST puede realizar con ese recurso, es decir, con los productos de la base de datos. También te indico qué significa cada operación y un ejemplo típico de la URL que permitirá el acceso a través de https.

|Operación|Significado|Verbo|URL típica|
|---|---|---|---|
|index|Mostrar todos los producto|GET|https://servidor/producto/|
|show|Mostrar un producto|GET|https://servidor/producto/id|
|create|Mostrar formulario de creación de un producto|GET|https://servidor/producto/create|
|store|Crear un producto con los datos procedentes de un formulario|POST|https://servidor/producto/store|
|edit|Mostrar el formulario de edición de un producto|GET|https://servidor/producto/edit/id|
|update|Actualizar el producto con los datos procedentes del formulario|PUT o PATCH|https://servidor/producto/update/id|
|destroy|Eliminar un producto|DELETE|https://servidor/producto/destroy/id|

Hay una excepción a esta regla: las operaciones *create* y *edit* podrían no estar disponibles en algunas APIs REST, cuando estas estén diseñadas para que las usen otras aplicaciones y no seres humanos.

Soy consciente de que esta tabla necesita algunas explicaciones adicionales, así que vamos a ello.

En primer lugar, ¿qué es eso de los *verbos* que figura en cada petición?

### 6.3.3. Los verbos http: GET, POST, PUT, PATCH y DELETE

El protocolo http define dos tipos de petición al servidor, GET y POST. El estándar REST aumenta estos tipos en otros tres: PUT, PATCH y DELETE.

Veamos qué significa exactamente cada uno:

* **GET** se utiliza para *solicitar* datos al servidor. Por ejemplo: "Dame toda la información de un producto".
* **POST** se utiliza para *enviar* datos al servidor. Por ejemplo: "Aquí tienes toda la información de un producto; anda, almacénalo en tu base de datos".
* **PUT/PATCH** se utiliza para solicitar al servidor la modificación de datos que ya existen. Por ejemplo: "Este es el nuevo precio de un producto que ya estaba en tu base de datos. Tómalo y actualízalo".

   Si se van a actualizar *todos* los datos de un producto, se utiliza *PUT*. Si se va a actualizar solo *una parte* de los datos de un producto, se utiliza *PATCH*.

* **DELETE** se usa para solicitar la eliminación de datos en el servidor. Por ejemplo: "Elimina este producto".

Por ese motivo, en algunas URLs de la tabla anterior enviamos un id como parte de la ruta. Ese id indicará al servidor qué producto le estamos pidiendo que nos busque, modifique o elimine.

Una moraleja tal vez imprevista de esta tabla es que nunca deberías enviar datos al servidor mediante GET, puesto que GET solo tendría que usarse para *obtener* datos del servidor.

Otra moraleja es que el propio verbo de la petición http ya contiene información sobre lo que se le está pidiendo hacer al servidor. De hecho, en un servidor REST, contiene información fundamental. Por eso es tan importante respetar las convenciones.

Si ya has trabajado con HTML antes, seguro que conocías el significado de GET y POST, pero probablemente nunca habías oído hablar de PUT, PATCH y DELETE, ¿verdad?

### 6.3.4. El problema de PUT, PATCH y DELETE

Cuando solicitamos una URL a un servidor sin indicar otra cosa, el protocolo http/https asumirá que se trata de una petición GET.

Si en un formulario indicamos que el método de envío de los datos al servidor es POST, los datos que el usuario rellene en ese formulario se enviarán al servidor mediante POST, como parte del paquete http, en una zona especialmente dedicada a empaquetarlos:

```html
<form action='http://servidor/lo-que-sea' method='POST'>
...cuerpo del formulario
</form>
```

Pero **con HTML5 *no hay manera de hacer una petición al servidor por PUT, por PATACH o por DELETE***.

Esto se debe a que la implementación actual de http no contempla los verbos PUT, PATCH ni DELETE. Sin embargo, **en el estándar REST estos verbos son fundamentales**. 

Como a nosotros nos interesa construir servidores REST con acceso por http, es decir, vía web, aquí tenemos un grave problema.

Mientras llega una nueva implementación de http y/o de HTML, **este problema tiene dos soluciones temporales**:

* Sustituir las llamadas con PUT, PATCH o DELETE por llamadas POST convencionales. Esto hará que, en la práctica, nuestro servidor deje de ser REST, claro.
* Parchear las llamadas con PUT, PATCH o DELETE mediante un campo oculto (de tipo *hidden*) en el formulario. Esta es la forma en la que se realizan las implementaciones REST vía web en la actualidad. Tienes un ejemplo en este formulario:

```html
<form action='http://servidor/lo-que-sea' method='POST'>
   <input type='hidden' name='_method' value='PUT'>
   ...cuerpo del formulario...
</form>
```

Tal vez recuerdes que esto es exactamente lo que hace Laravel para implementar llamadas mediante PUT, PATCH o DELETE. ¿Qué dices? ¿Que no te acuerdas? Entonces quizá sea el momento de que retrocedas y repases un poco el enrutador de Laravel.

### 6.3.5. REST y RESTful: ¿hay alguna diferencia?

Puede que hayas leído en algún sitio esa palabreja: RESTful. ¿Significa lo mismo que REST? ¿Qué diferencia hay?

En realidad, es casi lo mismo:

* **REST** se refiere a una **aplicación web** con una arquitectura como la que hemos estado comentando en los epígrafes anteriores.
* **RESTful** se refiere a **una API** que respeta la arquitectura REST. No una aplicación web, sino una API. Es decir, RESTful se refiere a un *servicio web*, pensado para responder a otros programas, no a usuarios humanos.

RESTful y JSON tienen una relación especial: todas **las APIs RESTful devuelven sus datos formateados en JSON**.

Entiéndeme: si a tu servidor le llega una petición de tipo GET a través de una ruta como esta: ```https://servidor/producto/18```, no hay nada que te impida devolver los datos del producto 18 formateados en XML, por ejemplo, pero tienes que ser consciente de que tu API habrá dejado de ser RESTful.

El ejemplo típico de servidor RESTful es el que usan las **aplicaciones OVA (*one-view-application*)**. Estas aplicaciones, una vez cargada la vista principal, hacen toda la comunicación con el servidor mediante Ajax, sin abandonar jamás esa vista. 

Las aplicaciones OVA lanzan peticiones al servidor y este responde mediante JSON en lugar de con vistas completas. Una aplicación así, en el lado del cliente, se está comportando como un consumidor de servicios y, en el lado del servidor, como una API.

Veremos Ajax en el capítulo siguiente y aprenderemos a construir aplicaciones OVA, que son cada vez más frecuentes. En estos casos, el lado del cliente y el lado del servidor *actúan como aplicaciones independientes*, conectadas solo por la API (aunque la experiencia del usuario sea la de encontrarse ante una única aplicación). Por ese motivo, hay programadores/as que se especializan en desarrollo en el lado del cliente (**front-end**) y otros que se especializan en desarrollo en el lado del servidor (**back-end**).

Conclusión: si vas a desarrollar una API, es buena idea que sea RESTful. En ese caso, cada vez que tengas que devolver un producto (o lo que sea) formateado en JSON desde tu controlador, es mejor que te olvides de las vistas y te limites a hacer algo así:

```php
public function show($id) {
   $producto = modelo-de-productos::get($id); // Obtenemos los datos del producto $id pidiéndoselos a nuestro modelo
   echo json_encode($producto);
}
```

### 6.3.6. REST vs SOAP

Ya sabemos en qué consisten las dos grandes arquitecturas para construir servicios web. Ahora, la pregunta del millón: ¿cuál es mejor de las dos?

**SOAP es más flexible que REST**: permite definir nuevas operaciones sobre los recursos, mientras que REST está limitado a las 7 operaciones predefinidas.

**REST es mucho más sencillo de usar e implementar que SOAP**: las operaciones son bien conocidas y no es necesario describirlas (WSDL) ni publicarlas de ningún modo. Para usar un servidor REST, no hay que estudiarse ninguna API ni pelearse con estructuras de datos desconocidas.

Por todo ello, para la mayor parte de las aplicaciones REST es más que suficiente, y de ahí su mayor implantación en la actualidad.

### 6.3.7. Algunos trucos para implementar un servidor REST

Para implementar un servidor REST (o RESTful, si se trata de una API pura) basta con:

* Crear una arquitectura MVC para los recursos/datos que deseemos servir.

   Recuerda que, con Laravel, esto se puede conseguir con el comando:

```
$ php artisan make:controller --resource <controlador>
```

* En lugar de mostrar los recursos en una vista, los devolveremos al cliente mediante JSON con un sencillo *echo* (recuerda que esa salida la recibirá el cliente, no un ser humano)

   Si estamos trabajando con Laravel, en lugar de ```return view()``` usaremos ```return response()->json(<datos>)``` al final de cada método del controlador. Laravel se encargará de enviar ese valor devuelto al cliente.

* Es importante respetar los nombres de las peticiones HTTP (create, store, edit, update, etc), así como los verbos (GET, POST, PUT, PATCH o DELETE), puesto que serán los que el cliente utilice.




