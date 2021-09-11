---
layout: page
title: 1.2 Wordpress
permalink: /cms/wordpress
nav_order: 2
has_children: false
parent: 1 Sistemas gestores de contenido (CMS)
grand_parent: Desarrollo Web en Entorno Servidor
---


## 1.2. Wordpress
{: .no_toc }

- TOC
{:toc}

Wordpress es sin duda el campeón actual de los CMS. Algunas estadísticas afirman que el 90% de los sitios web de internet está hecho con Wordpress. Probablemente son estadísticas un poco infladas, pero la importancia de este CMS es innegable y cualquier desarrollador web debe conocerlo, aunque sea para odiarlo.

Wordpress es un CMS enfocado a la creación de blogs, pero, en su estadio actual, permite crear casi cualquier tipo de sitio web: tiendas online, portales, revistas digitales, álbumes de imágenes o recursos de cualquier tipo... 

Está desarrollado en PHP bajo licencia GPL y se ha convertido en una auténtica plataforma de desarrollo web por sí mismo. Tiene detrás una enorme comunidad de desarrolladores y diseñadores, que se encargan de actualizarlo y de crear plugins y temas para la comunidad.

### 1.2.1. Características principales de Wordpress

Las características principales de Wordpress son:

* Separación entre el contenido y el diseño. El contenido se almacena en una base de datos. El diseño, en una plantilla, que es un conjunto de archivos CSS y PHP.
* Apuesta decidida por la apariencia atractiva del resultado final (aunque esto depende mucho de la plantilla, claro) . 
* La estructura y diseño visual del sitio depende de un sistema de plantillas. Es decir: cambias la plantilla y todo el sitio web cambia de aspecto, conservando el mismo contenido.
* La visualización final del contenido también depende de los plugins y widgets que se hayan instalado, y que pueden modificar sustancialmente en funcionamiento tanto del front-end como del back-end.
* Código claro, bien estructurado y con una API bien documentada (alrededor del 50% de los programadores querrán internarme en un psiquiátrico por haber escrito esto).
* Apuesta decidida por respetar las recomendaciones del W3C, aunque, desde luego, hay plugins y plantillas que no lo hacen. 
* Las entradas publicadas se ordenan por fecha, aunque esto se puede modificar. Wordpress se diseñó para hacer *blogging* y esa intención inicial aún permanece intacta, pero con un poco de manipulación puede emplearse para cualquier cosa.

#### Funcionalidades de Wordpress

Wordpress hace magia. Así de sencillo.

Si te vas a convertir en desarrollador/a web, Wordpress es tu peor enemigo, porque permite que cualquier usuario medio, sin tener ni idea de programación, pueda crear un sitio web solvente y de aspecto profesional en un rato.

No te voy a engañar: *a ti te llevaría meses programar algo parecido desde cero*.

Pero **Wordpress también tiene sus limitaciones**, y cuando sus usuarios las descubren, necesitan a un programador que sepa meterse en las tripas del sistema para retorcérselas. Ahí es donde entrarás tú.

De modo que sí: **Wordpress es tu peor enemigo, pero puede convertirse en tu mejor aliado**.

Para eso, tienes que conocer qué es capaz de hacer y qué no. Entre sus asombrosas funciones podemos contar estas:

* Fácil instalación, actualización y personalización. 
* Actualizaciones automáticas.
* Múltiples usuarios con diferentes roles. 
* Capacidad de crear páginas estáticas además de entradas de blog. 
* Organización de las publicaciones por categorías y etiquetas ("tags"). 
* Buscador integrado de contenido.
* Editor WYSIWYG ("What You See Is What You Get") por bloques.
* Guardado automático de los artículos mientras se escriben. 
* Moderación de comentarios.
* Personalización de las URIs de cada publicación.
* Distribución de los artículos y comentarios mediante RSS y otros mecanismos estandarizados. 
* Gestión intuitiva de la biblioteca multimedia. 
* Admite plugins para aumentar y/o modificar la fucionalidad del sistema, a riesgo de convertirlo en una "monstruo de Frankenstein" hecho a pegotes.
* Admite plantillas que cambian de forma radical la apariencia del sitio.
* Admite widgets o pequeñas utilidades adicionales que pueden ubicarse en los lugares que la plantilla permita. 

#### Plantillas de Wordpress

Las plantillas (o *themes*) de Wordpress son **diseños CSS que sirven para establecer la apariencia y estructura del sitio web**. Algunas también modifican parte del panel de administración.

Hay una gran comunidad dedicada al diseño de estas plantillas. Puedes encontrarlas tanto en el sitio de Wordpress (comprobadas y aprobadas oficialmente) como en sitios web de terceros. Muchas son gratuitas, otras de pago y, la mayoría, tienen una versión gratuita con funciones adicionales de pago.

Las posibilidades de las plantillas, tanto a nivel de diseño, estructura o gestión, son tan grandes que te permiten tener desde un simple blog hasta un sitio web completamente personalizable de forma intuitiva desde el panel de administración.

Hay un gran campo de trabajo en las plantillas de Wordpress para un desarrollador web. Más adelante veremos como crear plantillas nuevas, algo que también te servirá para modificar las plantillas existentes.

#### Widgets

Los widgets son **pequeñas aplicaciones** que proporcionan nuevas funcionalidades a un programa o que permiten un acceso rápido a funcionalidades usadas con frecuencia.

Pueden ser vistosos como, por ejemplo, relojes en pantalla, calculadoras, calendarios o nubes de tags; o pueden ser discretos pero útiles como, por ejemplo, un cuadro con enlaces de interés o un contador del número de visitas.

Wordpress incorpora un sistema de widgets para sus plantillas que ofrece numerosas posibilidades y flexibilidad para el diseño y estructura de sus blogs. Cada plantilla puede soportar un número diferente de Widgets en distintas posiciones de la pantalla.

#### Plugins

Hay una monstruosa cantidad de plugins que **potencian el uso de Wordpress y que lo convierten en un CMS prácticamente de propósito general**. Encontrarás un plugin para casi cualquier cosa que se te ocurra. Bueno, no: encontrarás decenas de plugins para casi cualquier cosa que se te ocurra.

Pero (¡siempre hay un pero!) con los plugins se corre el riesgo de empezar a parchear Wordpress hasta convertirlo en un amasijo informe de código puesto a pegotes. Muchos sitios web montados con Wordpress se vuelven ingobernables (y extraordinariamente lentos y pesados en la carga) por la gran cantidad de plugins que tienen activados.

Otro problema de los plugins es que pueden provocar incontables problemas con las actualizaciones del sistema.

En el ámbito de los plugins también hay mucho trabajo potencial para un futuro desarrollador/a web como tú: tanto para crear plugins nuevos y adaptados a las necesidades del cliente como para optimizar y racionalizar el uso de plugins existentes en los sitios que ya están en funcionamiento.

Por último, y al igual que ocurría con las plantillas, tienes que saber que muchos plugins son gratuitos, otros son de pago, y otros tienen versiones gratuitas que se vuelven de pago cuando queremos utilizar sus características más atractivas.

#### Fallos de seguridad de Wordpress

Las críticas más contundentes contra Wordpress siempre se han centrado en sus problemas de seguridad. En mayo de 2007, por ejemplo, un estudio reveló que el 98% de los blogs basados en Wordpress eran vulnerables a ataques.

Todos los sistemas que se vuelven muy populares se vuelven inseguros por el simple hecho de que se multiplican los ataques contra ellos.

La receta para minimizar los posibles problemas de seguridad es sencilla: **mantener Wordpress actualizado**. No podemos hacer mucho más allá de eso.

### 1.2.2. Instalación y explotación de Wordpress

#### Instalación de Wordpress

Wordpress es un CMS increíblemente sencillo de instalar y poner en marcha. El proceso de instalación se ha depurado tanto, que cualquier usuario medio sin especiales conocimientos técnicos puede llevarlo a cabo.

Como tú no eres un usuario/a medio, no vamos a detenernos mucho en ello, porque es realmente sencillo. A continuación, resumimos los pasos:

1. Necesitas, obviamente, ciertos prerrequisitos: acceso a un servidor web con soporte para PHP y un servidor de bases de datos MariaDB o similar.
2. Crea una base de datos vacía. Puedes llamarla como quieras (siempre que recuerdes el nombre, claro).
3. Descarga el código fuente de Wordpress (¡solo del sitio oficial, por favor! Es decir, de wordpress.org) y súbelo a una carpeta en tu servidor. La carpeta debe ser accesible vía web. 

   Puedes usar FTP para ello. Muchos servidores tienen un navegador de archivos vía web que también te permitirá subir el código fuente. Otros servidores incluso te ofrecen la posibilidad de instalar Wordpress desde el propio panel de control de servidor. Consulta con tu proveedor o trastea con el panel de control para ver si es tu caso.
4. Lanza el programa de instalación. Esto se logra, simplemente, escribiendo la URI de tu wordpress. Algo como https://tu-servidor/tu-carpeta, donde "tu-servidor" es el nombre de dominio de tu servidor y "tu-carpeta" es la carpeta donde subiste el código fuente de Wordpress.
5. Aparecerá una pantalla como esta. A partir de aquí, solo tienes que seguir las instrucciones.

![Pantalla de instalación de Wordpress](/assets/images/01-wordpress-instalacion.png)

#### Explotación de Wordpress

Una vez que tienes instalado tu Wordpress en el servidor, ya dispones de un sitio en línea que puedes visitar en la URI https://tu-servidor/tu-carpeta.

El sitio es por completo funcional pero, obviamente, está vacío de contenido. Su aspecto será más o menos como este:

![Wordpress recién instalado](/assets/images/01-wordpress-recien-instalado.jpg)

Lo que estás viendo aquí es la plantilla (*theme*) por defecto de Wordpress. Dependiendo de la versión que instales, tendrá un aspecto algo diferente. Una instalación nueva también incorpora una publicación (*post*) de ejemplo (con un comentario también de ejemplo), así como una página estática.

Lo siguiente que tienes que hacer es acceder al panel de administración, que estará hubicado en https://tu-servidor/tu-carpeta/wp-admin. Verás una pantalla de login donde tendrás que introducir el usuario y la contraseña de administración de Wordpress. Estas credenciales las seleccionaste durante el proceso de instalación.

Una vez traspasada la puerta del login, encontrarás una pantalla con la que debes familiarizarte: el **panel de administración** o ***dashboard*** de Wordpress.

![Panel de administración de Wordpress](/assets/images/01-wordpress-panel-administracion.png)

El resto de tu trabajo consistirá en familiarizarte con este panel de administración. Es una aplicación web muy completa e intuitiva, y a cualquier usuario/a un poco avezado no le costará trabajo hacerse con ella, e incluso le resultará divertido. No hay que decir que no necesitas saber nada de programación para manejar este panel.

Solo a modo de introducción, te resumo las secciones principales que puedes encontrar en el *dashboard* de Wordpress, accesibles mediante el menú de la izquierda:

* **Post**. Son las publicaciones de Wordpress (recuerda que, originalmente, era una herramienta para hacer *blogging*). Los artículos se crean con un sencillo editor WYSIWYG al que se le pueden ir añadiendo bloques. Hay multitud de opciones de configuración de cada artículo: a qué categoría pertenecen, qué etiquetas tienen, si se permiten o no los comentarios, la fecha de la publicación, la autoría, etc.
* **Media**. Es la biblioteca multimedia. Desde aquí se organizan todos los recursos multimedia: imágenes, vídeos, audios, documentos... Cualquiera de esos recursos puede incrustarse en cualquier post.
* **Pages**. Son las páginas estáticas de Wordpress. A diferencia de los posts, no se organizan cronológicamente ni se pueden asignar a categorías. Se utilizan para las páginas cuyo contenido debe estar siempre accesible y cambia poco con el tiempo: "Acerca de", "Contacto" y cosas así.
* **Comments**. Desde aquí se moderan los comentarios que los visitantes hayan hecho a los posts.

Aquí termina la parte del *dashboard* dedicada a gestionar el **contenido** del sitio. El resto de menús se dedican a gestionar la **apariencia y configuración** del sitio:

* **Appearance**: Aquí se manipulan las plantillas (themes), los widgets, los menús... Pasarás incontables horas de diversión (y desesperación) en esta sección.
* **Plugins**: No te desvelo nada nuevo si te digo que desde aquí gestionas los plugins, ¿verdad?
* **Users**: Puedes dar acceso a otros usuarios a tu Wordpress. Hay varios niveles o roles de acceso: administrador, editor, publicador... Cada rol verá un menú de administración diferente.
* **Tools**: Diferentes herramientas útiles. Importar y exportar contenido son las principales. Muchos plugins añadirán opciones a este menú (otros las añadirán en otra parte).
* **Settings**: Opciones de configuración del sitio. Aquí se pueden cambiar muchas cosas muy importantes: el nombre del sitio, el formato de las URIs, si se permiten o no comentarios por defecto, si los comentarios se publican inmediatamente o tiene que moderarlos un administrador. Conviene que te pases un rato curioseando y probando cosas.

### 1.2.3. Breve tour por Wordpress para novatos

Todo esto puede parecer complicadísimo, pero Wordpress (a nivel de usuario) es muy secillo de usar cuando has pasado un poco de tiempo con él.

Si es tu primera vez con Wordpress, te recomiendo que te prepares un café (o tu infusión favorita), te sientes sin prisa ante el ordenador en algún momento en el que no te vayan a interrumpir durante varias horas y dediques una sesión intensiva a hacer lo siguiente:

1. **Instala un Wordpress** de prueba en tu servidor local o en un servidor remoto si aún no lo has hecho.
2. Accede al **panel de administración**.
3. **Crea dos o tres categorías**. Antes deberás decidir qué temática tendrá tu sitio. Utiliza algún tema de tu interés: un deporte, la tecnología, la programación, el cine, la literatura... Si usas algo que te interese, la experiencia será mucho más fructífera. Por ejemplo, si tu temática es "programación", podrías crear las categorías "Java", "PHP" y "Python", por decir algo.
4. **Crea un par de entradas** por cada categoría. No tienen que ser nada especial: solo estamos jugueteando. Copia y pega texto de alguna otra publicación de internet. O redáctalas tú, como prefieras. Asegúrate de incluir alguna imagen y otros elementos multimedia.
5. **Crea alguna página** ("Acerca de", "Sobre mí", "Contacto" o algo así).
6. **Cambia de plantilla**. Prueba varias que te gusten y, cuando te decidas por una, métete en sus opciones de configuración y trastea un rato. Algunas plantillas son configurables hasta límites enfermizos. Otras, en cambio, son muy limitadas. No olvides ir observando cómo estos cambios afectan a la forma en la que los visitantes verían en blog.
7. **Instala algunos plugins** de prueba que te parezcan interesantes. Por ejemplo, galerías de imágenes o formularios de contacto.
8. **Crea algunos usuarios** adicionales con distintos roles. Accede con ellos al panel de administración para ver las diferencias entre unos roles y otros.
9. **Juguetea sin miedo con las opciones** del menu "Settings". Algunas de ellas podrían dejar tu Wordpress totalmente inoperativo. ¡Bienvenido a la vida real! Trata de resolver el problema bicheando en internet. Antes o después, eso mismo te ocurrirá con sitios reales.

Cuando termines esta experiencia inmersiva (que puede llevarte varios días), estarás en condiciones de montar un sitio web con Wordpress real.

### 1.2.4. Cómo crear y modificar una plantilla de Wordpress

Wordpress dispone de una API de funciones útiles para desarrollar nuestras propias plantillas (*themes*) y plugins. Como vamos a hacer a lo largo de todo el texto, veremos este asunto de forma práctica: **creando nuestra propia plantilla desde cero**.

Por cierto, que a lo largo de toda la sección nos referiremos indistintamente a las plantillas de Wordpress como *plantillas*, *temas* o *themes*, pues así lo encontrarás en toda la documentación que consultes.

¿Estás preparado/a? ¡Vamos allá!

#### Las plantillas o temas de Wordpress

Como ya hemos dicho, existen muchos sitios web donde adquirir plantillas (*themes*), empezando por el propio sitio oficial de Wordpress. Algunas son gratuitas, otras de pago, y otras tienen versiones gratuitas incompletas o parcialmente desactivadas, y versiones de pago que permiten usar todas las funcionalidades. 

Pero, a veces, queremos ir un paso más allá y desarrollar nuestra propia plantilla. Para ello, tenemos dos opciones:

1. **Utilizar una plantilla base**. Existen muchas plantillas básicas diseñadas para ser usadas como base para desarrollar nuevas plantillas. Contienen todos los elementos mínimos necesarios de una plantilla de Wordpress, además de otras características, de modo que el trabajo de creación de la nueva plantilla se minimiza. Estas plantillas a veces también se llaman *frameworks* Algun plantillas básicas muy conocidas son *Bones*, *Basic* o *Divi*. Los desarrolladores profesionales pueden acabar creando su propia plantilla base a partir de la cual crear el resto de plantillas a su gusto.

2. **Desarrollar la plantilla desde cero**. Este proceso es más costoso en tiempo, pero conseguiremos aproximarnos más a lo que estamos buscando, evitando estar atados a un *framework* que no hemos programado nosotros y conservando el control absoluto sobre los archivos y contenidos de la plantilla.

En este texto vamos a decantarnos por la segunda opción, no porque sea mejor ni peor, sino porque es lo más didáctico si pretendemos aprender cómo se organizan las plantillas de Wordpress.

#### Dónde localizar las plantillas instaladas

Puedes encontrar los temas instalados a través del panel de administración (*dashboard*) de tu Wordpress, en el menú Appearance -> Themes.

Pero, para nuestros propósitos, es mejor hacerlo navegando directamente entre las carpetas del servidor, en la ruta *carpeta-de-wordpress -> wp-content -> themes*.

Ahí encontrarás una carpeta por cada plantilla de Wordpress instalada en tu sistema. Bastará, entonces, con crear una carpeta nueva para iniciar la construcción de nuestra plantilla.

A partir de ahora supondremos que estamos creando un nuevo tema llamado ***mi-tema***. Es decir, dentro de la carpeta *themes*, habremos creado un directorio llamado *mi-tema*.

#### Archivos mínimos de un tema de Wordpress

Wordpress funciona mediante **módulos**. Por ejemplo, para insertar el pie de una página habremos de llamar al archivo *footer.php*, en caso de que exista. Y lo mismo con la cabecera, la barra de navegación, etc. Cada uno de esos elementos es un módulo.

Una plantilla de Wordpress puede estar formada por muchos archivos, pero **para que un tema de Wordpress funcione sólo necesita dos archivos: index.php y style.css**. Está claro que con sólo estos dos archivos tendremos un tema muy básico, pero será considerado por Wordpress un tema válido si estos dos archivos están bien configurados.

A continuación vamos a desarrollar una plantilla completa que nos sirva de base para otros proyectos. Contendrá una cabecera, un pie y una barra lateral. No pretendemos desarrollar una plantilla supercompleja con funciones avanzadas, claro, pero sí una bastante completa que podamos usar por sí misma o como base para proyectos más complejos.

Nuestro tema va a tener la mayor parte de los archivos habituales en los temas "profesionales". ¿Qué cuáles son esos archivos? Aquí tienes una lista con una breve explicación de cada uno:

* **/images**. Carpeta con las imágenes de la plantilla.
* **/js**. Carpeta con los archivos de JavaScript.
* **style.css**. Hoja de estilos de la plantilla. *Obligatoria para que la plantilla funcione.*
* **index.php**. Página principal. *Obligatoria para que la plantilla funcione.*
* **screenshot.png**. Imagen en miniatura. Se verá en el dashboard de Wordpress (menú Apariencia -> Temas).
* **favicon.ico**. La imagen que se verá en el navegador (o al guardar el sitio como un marcador).
* **header.php**. Cabecera de la plantilla.
* **sidebar.php**. Barra lateral de la plantilla.
* **footer.php**. Pie de página de la plantilla.
* **single.php**. Una entrada (post) individual.
* **page.php**. Una página estática individual.
* **category.php**. Página de resultados de una categoría.
* **tag.php**. Página de resultados de una etiqueta.
* **search.php**. Página de resultados de búsqueda.
* **functions.php**. Funciones genéricas de nuestra plantilla (accesibles desde todos los archivos de la misma).

Como es lógico, para crear una buena plantilla es fundamental que poseas un buen dominio de HTML y CSS. Si no, mejor dedícate a otra cosa (por ejemplo, a aprender HTML y CSS).

En el resto de esta sección, vamos a construir nuestra plantilla en 11 sencillos pasos. Bueno, o no tan sencillos, eso ya lo decides tú...

#### Paso 1: La hoja de estilos (style.css)

El primer paso para construir una plantilla de Wordpress siempre es el archivo ***style.css*** (dentro de la carpeta "mi-tema"). 

Ese archivo debe abrirse con estas líneas de comentario para que Wordpress lo reconozca como la hoja de estilos de la plantilla y la información aparezca en *Apariencia -> Temas*:

```css
	/*
	Theme Name: Mitema
	Theme URI: el lugar donde vayas a alojar el tema 
                 para ponerlo a disposición de la comunidad
	Description: La descripción del tema
	Author: Tu nombre y apellidos
	Author URI: la web profesional del creador del tema
            Version: 1.0
	*/
```

A partir de aquí, puedes escribir tu propio código de CSS como harías con cualquier otra página web. De momento, puedes dejarlo así e ir añadiendo reglas CSS más adelante.

#### Paso 2: Imágenes y JavaScript (subdirectorios /images y /js)

Para este *theme* vamos a utilizar dos pequeñas librerías Javascript:

* ***Modernizr***, que sirve para detectar las capacidades de HTML5 y CSS3 del navegador (por si nos topamos con un navegador anticuado, cosa que es, lamentablemente, más frecuente de lo que pueda parecer).
* ***Respond***, que sirve para que las versiones jurásicas de Internet Explorer sepa interpretar los media queries de CSS3.

Te lo confieso:  podríamos crear nuestra plantilla sin estas librerías, pero las usaremos de excusa para que veas cómo se integra una librería Javascript en una plantilla de Wordpress.

Para alojar ese tipo de contenido adicionarl, vamos a **crear las carpetas *"images"* y *"js"*** dentro de la carpeta *"mi-tema"*.

* En la carpeta *"js"* colocaremos una copia de las librerías Modernizr y Respond (¡siempre bajadas de la web del desarrollador, por favor!).
* En la carpeta *"images"* colocaremos más adelante las imágenes que vayamos necesitando para nuestro CSS. 
   ¡Ojo! Hay dos archivos de imagen obligatorios para todas las plantillas Wordpres, ***screenshot.png*** y el ***favicon.ico***, pero estos se deben ubicar en el directorio raíz del tema y no dentro de la carpeta *"images"*. Recuerda que Wordpress utiliza estos dos archivos para la previsualización del tema y para el icono de la página una vez que el tema se active.

#### Paso 3: Crear la cabecera del tema y el menú de navegación (header.php)

El archivo ***header.php*** contiene la cabecera de todas las páginas que se carguen con nuestro tema. Es el lugar donde suele ponerse el logo, el menú principal, un banner con imágenes o cualquier otra cosa que queramos que aparezca en la parte superior de todas las páginas del sitio web.

Este es un código sencillito para empezar con header.php:

```html
	<!DOCTYPE html>
	<html <?php language_attributes(); ?>>
	<head>
	  <meta charset= <?php bloginfo( 'charset' ); ?>">
	  <title><?php wp_title(); ?></title>
	  <!-- Definimos el viewport para dispositivos móviles -->
	  <meta name="viewport" content="width=device-width, minimum-scale=1">
	  <link rel="shortcut icon" href="<?php echo get_stylesheet_directory_uri(); ?>/favicon.ico" />
	  <link rel="stylesheet" media="all" href="<?php bloginfo( 'stylesheet_url' ); ?>" />
	  <link rel="pingback" href="<?php bloginfo( 'pingback_url' ); ?>" />
	  <?php wp_head(); ?>
	</head>
	<body>
	  <div class="wrapper">
	    <header>
	      <h1><a href="<?php echo get_option('home'); ?>"><?php bloginfo('name'); ?></a></h1>
	      <hr>
	      <?php wp_nav_menu( array('menu' => 'Main', 'container' => 'nav' )); ?>
	    </header>
```

Echa un vistazo al código sin miedo. La mayor parte es HTML, y solo hay un toquecito de PHP aquí y allá. ¿Qué dices? ¿Qué aún no sabes PHP? Verás, no hay mucho que entender aquí, así que no te asustes a la primera de cambio.

Vamos a analizar el código línea a línea para que entiendas lo que hace:

* Observa que, después del *doctype*, hemos usado un poquito de PHP para indicar el idioma de la instalación de Wordpress, utilizando en PHP la función *language_attributes()*. Esa es una de las muchas funciones del API de Wordpress que podemos llamar desde PHP, pero no desde HTML. 

* Observa también que **todo el código PHP tiene que ir entre las etiquetas "<?php>" y "?>"**, aunque seguro que ya te habías dado cuenta de eso si realmente has intentado leer el código, ¿verdad?

* En la siguiente línea, y con el objetivo de asignar el *charset*, también hemos recurrido a una función de Wordpress (*bloginfo()*), así como para el título de la página (función *wp_title()*). Todas esas funciones deben llamarse desde PHP, por lo que abrimos y cerramos las etiquetas "<?php>" y "?>" cada vez que lo necesitamos.

* Más abajo especificaremos el *viewport*. Si tu tema no va a ser responsivo, puedes quitar esta línea de código.

* Justo después, para mostrar la URL al *favicon.ico* le indicamos la ruta a la carpeta "mi-tema" de la instalación de Wordpress. Eso se consigue con la función de Wordpress *get_stylesheet_directory_uri()*.

* Un poco más abajo se usa la función *bloginfo()* con el argumento 'stylesheet_directory', que tiene el mismo efecto que *get_stylesheet_directory_uri()*.

* Finalmente, se usa la función *wp_head()* de Wordpress, necesaria para que los plugins y otras funcionalidades de Wordpress estén disponibles en las páginas cargadas con nuestro tema. A partir de aquí cerramos la etiqueta *head* de HTML y empezamos con los contenidos de *body*.

Quizás en este punto te estés preguntando por qué incluir el body en header.php. La razón es sencilla: algunos contenidos de la cabecera del tema van a aparecer en todas las páginas del sitio web, por lo que, al incluirlo aquí, evitamos duplicar código y logramos que el mantenimiento del tema sea más sencillo. 

Así, dentro de la sección "<header>" del *body* HTML, incluiremos nuestra cabecera. En este ejemplo, hemos puesto el nombre del sitio web con un enlace a la página de inicio:

```html
	<h1><a href="<?php echo get_option('home'); ?>"><?php bloginfo('name'); ?></a></h1>
```

Fíjate que dentro del "<header>" hemos escrito esta línea:

```php
	<?php wp_nav_menu( array('menu' => 'Main', 'container' => 'nav' )); ?>
```

Sirve para crear el menú de navegación. Para que funcione correctamente, primero deberemos añadir al archivo ***functions.php*** (que contiene las funciones propias del tema, como dijimos antes) este código:

```php
	<?php
	// Registro del menú de Wordpress
	add_theme_support( 'nav-menus' );
	if ( function_exists( 'register_nav_menus' ) ) {
	    register_nav_menus(
	        array(
	          'main' => 'Main'
	        )
	    );
	}
	?>
```

Este código crea un menú llamado "Main" que nos aparecerá en el panel de administración de Wordpress, en *Apariencia -> Menús*. Lo que este código dice es que si existe una función llamada *register_nav_menus*, entonces debe crearse un nuevo menú de navegación llamado *Main*. Además, la función de Wordpress *add_theme_support()* sirve para indicar que en este tema queremos poder crear menús dinámicos.

A partir de aquí, simplemente habremos de ir a *Apariencia -> Menús* en el *Dashboard* de Wordpress, crear nuestro menú y guardarlo, como con cualquier otro *theme*.

Con esto ya tenemos la cabecera del tema creada junto con su menú de navegación.

#### Paso 4: Crear la barra lateral para widgets (sidebar.php)

Si has trasteado un poco con Wordpress, te habrás dado cuenta de que la mayoría de los temas incluyen una barra lateral a la derecha o a la izquierda del contenido principal. Bueno, algunos incluyen varias barras laterales, pero vamos a centrarnos en una, que es lo más frecuente.

Las barras laterales suelen utilizarse para contener los ***widgets***. Hay temas que admiten *widgets* (la mayoría) y otros que no. Lo primero que tendremos que hacer, entonces, es informar a Wordpress de que nuestro tema **sí admite *widgets***. Para ello, abriremos de nuevo el archivo ***functions.php*** e incluiremos esta función:

```php
	<?php
	     //  Main Sidebar
	     if(function_exists('register_sidebar'))
	          register_sidebar(array(
	          'name' => 'Main Sidebar',
	           'before_widget' => '<hr>',
	            'after_widget' => '',
	          'before_title' => '<h3>',
	          'after_title' => '</h3>',
	     ));
	?>
```

Si activamos este tema y vamos al *dashboard* de Wordpress, en el menú *Apariencia -> Widgets* veremos que nos aparece una nueva zona de *widgets* llamada *"Main Sidebar"*. 

Una vez creada la zona lista para *widgets*, vamos a llamarla dentro del archivo ***sidebar.php***, otro archivo típico de casi todas las plantillas. Creamos este archivo y escribimos:

```html
	<section id="sidebar">
	  <?php if ( !function_exists('dynamic_sidebar') || !dynamic_sidebar('Main Sidebar') ) : ?>
	  <?php endif; ?>
	</section>
```

Hemos utilizado un id llamado *"sidebar"* porque en este tema sólo va a existir una barra lateral. Si quieres que tu tema tenga más barras laterales, quizás prefieras utilizar una clase *"sidebar"* en lugar de un id.

Y listo, ya tenemos creada la barra lateral lista para contener *widgets*.

#### Paso 5: Crear el pie de página (footer.php)

Llega el momento de crear otro elemento común en casi todos los temas: el pie que aparecerá en todas las páginas del sitio web. 

Recuerda que Wordpress funciona por módulos, y que los módulos son como piezas de un puzle: hasta ahora hemos ido creando esas piezas (*header*, *sidebar*, y ahora el *footer*) para luego montarlas todas en *index.php*. Pero eso será un poco más adelante. Ahora centrémonos en el *footer*.

El *footer* se crea, oh sorpresa, en un archivo llamado ***footer.php*** que puede quedarnos así:

```html
	<footer>
	  <p>&amp;amp;amp;copy; <?php bloginfo('name'); ?>, <?=date('Y');?>. Mi primer tema.</p>
	</footer>
	</div> <!-- Fin de wrapper -->
	<?php wp_footer(); ?>
	</body>
	</html>
```

Fíjate en que la capa id="wrapper" empezó en el *header* y la terminamos ahora, en el *footer*. Esto es lo más habitual, pero si queremos un *header* o un *footer* que se extienda por toda la pantalla, podemos mover las posiciones de los *div* que abren y cierran la capa "wrapper".

Aquí aparece una llamada a la función de Wordpress *wp_footer()*, que es semejante a *wp_header()*. Estas funciones son lo que se llaman **hooks de Wordpress** y hacen funcionar los plugins que instalemos. Si no la incluyes, tu tema funcionará, pero la mayor parte de los plugins, no.

#### Paso 6: Crear la página principal (index.php)

La página principal se diseña en el archivo ***index.php***. Nuestro index tendrá inicialmente este aspecto:

```html
	<?php get_header(); ?>
	  <section id="main">
	  </section> <!-- Fin de main -->
	    <?php  get_sidebar()?>
	  <?php get_footer(); ?>
```

Observa estas tres funciones clave del API de Wordpress:

* ***get_header()*** inserta los contenidos del archivo header.php en ese punto.
* ***get_sidebar()*** hace lo mismo con la barra lateral.
* ***get_footer()*** hace... bueno, ya te imaginas lo que hace, ¿verdad?

Así montamos nuestro puzle de tres piezas. Fácil, ¿no? Sí, sí, un puzle muy sencillo, pero con la estructura básica de muchos temas de Wordpress. Y, en cualquier caso, podemos complicarlo añadiendo más cosas.

Que es justo lo que vamos a hacer ahora...

#### Paso 7. El loop de Wordpress (otra vez index.php)

En el ***loop*** reside toda la magia de Wordpress. 

¿Qué es el *loop*? Es un bucle (claro) en el que se muestran las entradas almacenadas en la base de datos de Wordpress. Y nosotros podemos decidir cómo se muestran esas entradas.

Este código de ejemplo de *loop* debe añadirse a continuación del anterior en ***index.php***:

```html
	<?php if (have_posts()) :  while (have_posts()) : the_post(); ?>
	    <h2><a href="<?php the_permalink(); ?>"><?php the_title(); ?></a></h2>
	   <small>Publicado el <?php the_time('j/m/Y') ?> por <?php the_author_posts_link() ? </small>
	    <?php the_excerpt(); ?>
	  <?php endwhile; else: ?>
	    <p><?php _e('No hay entradas .'); ?></p>
	  <?php endif; ?>
```

La primera línea constituye el auténtico ***loop***:

```html
	<?php if(have_posts()) : ?><?php while(have_posts()) : the_post(); ?>
```

Wordpress mirará si hay alguna entrada disponible (*if(have_posts())*). Si es así, entramos en un bucle que se repite para todos los posts (*while(have_posts())*). Y, para cada post, se recupera su contenido de la base de datos (*the_post()*).

Una vez seleccionado el post, se muestra su información: la fecha de publicación (*the_time()*), los autores (*the_author_posts_link())*, el extracto (*the_excerpt()*)... Si no hay posts, se muestra el mensaje de "No hay entradas".

#### Paso 8. Añadir thumbnails al loop (seguimos en index.php)

Si queremos **añadir *thumbnails*** (imágenes destacadas) a cada publicación como sucede en muchos sitios web, lo que haremos es lo siguiente: vamos al archivo ***functions.php*** y añadimos este código:

```html
	<?php
	//Habilitar thumbnails
	add_theme_support('post-thumbnails');
            set_post_thumbnail_size(200, 150, true);
	?>
```

Con este código hemos habilitado los *thumbnails* de nuestras entradas y hemos establecido un tamaño para los mismos de 200x150 píxeles. Una vez hecho esto, modificaremos el *loop* de ***index.php*** como sigue:

```html
	<?php if (have_posts()) :  while (have_posts()) : the_post(); ?>
	    <h2><a href="<?php the_permalink(); ?>"><?php the_title(); ?></a></h2>
	   <small>Publicado el <?php the_time('j/m/Y') ?> por <?php the_author_posts_link() ?>  </small>
	   <div class="thumbnail">
	      <?php
	          if ( has_post_thumbnail() ) {
	                the_post_thumbnail();
          }
	      ?>
	   </div>
	      <?php the_excerpt(); ?>
	  <?php endwhile; else: ?>
	    <p><?php _e('No hay entradas .'); ?></p>
	  <?php endif; ?>
```

Observa que hemos añadido un par de líneas en las que se comprueba si el post tiene *thumbnail* y, en caso afirmativo, lo recuperamos de la base de datos y lo mostramos (función *the_post_thumbnail()*).

La forma concreta en la que queremos que se visualice todo esto debe establecerse mediante CSS, por supuesto, en el archivo *style.css*.

Vamos a dejar de añadir cosas *loop* en este punto, pero podríamos seguir ìncorporando elementos. Por ejemplo, **una paginación** de las entradas. Encontrarás en la red mucha información sobre el tema, aunque lo más práctico es bajarse una plantilla sencillita ya hecha que incluya lo que sea que queremos hacer y curiosear en su código fuente.

#### Paso 9. Resultados de la búsqueda (search.php)

Los resultados de la búsqueda se especifican en el archivo ***search.php***. He aquí un ejemplo:

```html
	<?php get_header(); ?>
	    <section id="main">
	  <h2>Resultados de la búsqueda</h2>
	         <?php if (have_posts()) :  while (have_posts()) : the_post(); ?>
	      <h2><a href="<?php the_permalink(); ?>"><?php the_title(); ?></a></h2>
	     <small>Publicado el <?php the_time('j/m/Y') ?> por <?php the_author_posts_link() ?>  </small>
	     <div class="thumbnail">
	        <?php
	            if ( has_post_thumbnail() ) {
	                  the_post_thumbnail();
	            }
	        ?>
	     </div>
	        <?php the_excerpt(); ?>
	 
	 <?php endwhile; ?>
	<?php if (function_exists("pagination")) {
	    pagination($additional_loop->max_num_pages);
	} ?>
	<?php  else: ?>
	<div class="entry"><?php _e('Lo sentimos, no hay resultados con este término de búsqueda.'); ?></div>
	<?php endif; ?>
	</section> <!-- Fin de main -->
	<?php  get_sidebar()?>
	<?php get_footer(); ?>
```

Fíjate qué curioso: se parece mucho a *index.php*.

Tiene sentido, puesto que el resultado de una búsqueda no es otra cosa que una lista de *posts*.

Esta página es la que va a mostrar los resultados de una búsqueda, así que vamos a necesitar habilitar el buscador en nuestro *theme*. Un buen sitio para colocarlo puede ser el *sidebar*. Iremos a nuestro archivo *sidebar.php* y, justo antes de la función que habilita la zona de *widgets* en la barra lateral, incluiremos este código:

```html
	<form method="get" id="searchform" action="<?php bloginfo('url'); ?>/">
	  <input type="text" placeholder="Buscar…" value="<?php the_search_query(); ?>" name="s" id="s" />
	  <button type="submit" class="icon-only"  id="searchsubmit"></button>
	</form>
```

Con esto tenemos un campo de búsqueda en nuestra barra lateral.

No olvides que en el archivo *style.css* debes dar formato a todas las clases e ids para que la plantilla se visualice como tú quieras.

#### Paso 10. Configurar la vista de las entradas (single.php)

La página de cada entrada o post individual es aquella donde solo se ve una entrada con todo su contenido. 

El archivo donde se define esto es ***single.php***, y puede ser más o menos así:

```html
	<?php get_header(); ?>
	    <section id="main">
	        <article id="single">
	          <?php if(have_posts()) : ?><?php while(have_posts()) : the_post(); ?>
	            <h2><a href="<?php the_permalink() ?>" rel="bookmark" title="Enlace permanente a <?php the_title_attribute(); ?>"><?php the_title(); ?>. </a></h2>
	              <small> Publicado por <?php the_author_posts_link() ?>  el <?php the_time('j/m/Y') ?>. Categoría: <?php the_category(', '); ?> </small><br>
	          <div class="post">
	 
	             <?php the_content(); ?>
	        </div>
	<?php endwhile; ?>
	<?php endif; ?>
	  </article> <!-- Fin de single -->
	  </section> <!-- Fin de main -->
	  <?php  get_sidebar()?>
	<?php get_footer(); ?>
```

Si has llegado hasta aquí, te resultará fácil comprender este código. Si en el *loop* principal (en *index.php*) utilizamos *the_excerpt()* para mostrar el extracto de la entrada, aquí utilizamos la función *the_content()* para recuperar el contenido completo de la entrada.

Por supuesto, esto se puede complicar hasta el infinito. A modo de ejemplo, observa cómo podríamos mostrar las entradas relacionadas:

```html
	    <?php
	    $tags = wp_get_post_tags($post->ID);
	    if ($tags) {
	      $tag_ids = array();
	      foreach($tags as $individual_tag) $tag_ids[] = $individual_tag->term_id;
	      $args=array(
	      'tag__in' => $tag_ids,
	      'post__not_in' => array($post->ID),
	      'showposts'=>5, // Number of related posts that will be shown.
	      'caller_get_posts'=>1
	      );
	    $my_query = new wp_query($args);
	      if( $my_query->have_posts() ) {
	        echo '<h3>Artículos relacionados</h3><ul>';
	        while ($my_query->have_posts()) {
	          $my_query->the_post();
	          ?>
	          <li><a href="<?php the_permalink() ?>" rel="bookmark" title="Permanent Link to <?php the_title_attribute(); ?>"><?php the_title(); ?></a></li>
	        <?php
	        }
	        echo '</ul>';
	      }
	         wp_reset_query();
	    }
	?>
```

#### Paso 11: Habilitar y mostrar los comentarios

Para permitir los comentarios en una entrada, añadiremos este código a nuestro archivo ***functions.php***:
	
```php
       // Permitir comentarios encadenados
	function enable_threaded_comments(){
	    if (is_singular() AND comments_open() AND (get_option('thread_comments') == 1)) {
	       wp_enqueue_script('comment-reply');
	    }
	}
	add_action('get_header', 'enable_threaded_comments');
```

Y en ***single.php***, justo antes de la línea del *endwhile*, escribiremos:

```html
	<div class="comentarios">
	  <?php comments_template(); ?>
	</div>
```

Nuevamente, será el CSS, como es lógico, el que determine cómo se verán los comentarios.

#### Paso 12: Crear la página de categorías y etiquetas

Los archivos ***category.php*** y ***tags.php*** muestran, en ambos casos, una lista de entradas:
* *category.php* muestra las entradas que pertenecen a una categoría.
* *tags.php* muestra las entradas que contienen una etiqueta concreta.

Eso significa que, de cara a la creación de la plantilla, los dos archivos son prácticamente iguales entre sí, y que los dos archivos contienen un *loop* muy semejante al de *index.php*.

Para nuestra plantilla de ejemplo, te sugerimos que, en lugar de crear esos dos archivos, añadas esto antes del *loop* de *index.php*:

```html
	<?php $post = $posts[0];  ?>
	  <?php  if (is_category()) { ?>
	    <h2>Categoría: <?php get_the_category(); ></h2>
	  <?php } elseif( is_tag() ) { ?>
	    <h2>Etiqueta: <?php single_tag_title(); ?></h2>
	<?php } ?>
```

Cuando Wordpress vaya a mostrar, por ejemplo, la lista de artículos de una categoría, buscará el archivo *category.php* en la plantilla pero, como no lo encontrará, recurrirá a *index.php*. Y nuestro archivo *index.php* detectará que está mostrando los artículos de una categoría (*if (is_category()*) y mostrará el nombre de esa categoría antes del listado.

#### ¿Y ahora qué?

Ya tienes una plantilla sencilla y funcional creada desde cero.

La creación de plantillas no termina aquí, claro. Solo hemos sentado las bases, pero son unas bases sólidas. La API de Wordpress es muy amplia, a menudo confusa y casi siempre redundante. Especializarse en el desarrollo para Wordpress es una tarea de largo recorrido que no puede aprenderse en unas cuantas horas. 

Pero si has llegado hasta aquí, ya has hecho, probablemente, lo más difícil.

La mayoría de las plantillas tienen más archivos que la nuestra. Por ejemplo:

* ***page.php***, para mostrar páginas estáticas.
* ***author.php***, para mostrar la página de "acerca de".
* ***404.php***, para crear nuestra propia página de error "not found".

Por último, aquí tienes un diagrama de las relaciones que existen entre los archivos típicos de una plantilla Wordpress. Recuerda que el único obligatorio (además de styles.css) es index.php, y que una plantilla compleja puede tener otros archivos adicionales a los que aquí se muestran.

![Jerarquía de archivos de un tema de Wordpress](/assets/images/01-wordpress-jerarquia-archivos-tema.png)
[Fuente: Wikimedia Commons](https://commons.wikimedia.org/wiki/File:Wordpress_Template_Hierarchy.png)

Cuando Wordpress busque alguno de estos archivos y no le encuentre, recurrirá al siguiente en la jerarquía, y si no existe, al siguiente, y así hasta llegar a *index.php*, que sí debe existir. Eso es lo que nos ocurría en el Paso 12, cuando creábamos la plantilla para categorías dentro de *îndex.php* y no en *category.php*.

### 1.2.5. Plugins de Wordpress

Los plugins de Wordpress, como cualquier plugin, son **añadidos que incrementan las funcionalidades del sistema base**. La arquitectura flexible de Wordpress permite realizar esa ampliación en casi cualquier sentido y es una de las razones del éxito de este CMS: con los plugins adecuados, un CMS originalmente pensado para hacer *blogging* puede convertirse casi en cualquier cosa.

Los plugins, como ya hemos visto, se gestionan desde el menú "Plugins" del *dashboard*. Al instalar y activar un plugin, lo más habitual es que aparezca una nueva entrada de menú en algún sitio del *dashboard*. Cada plugin es virtualmente un programa nuevo acoplado a Wordpress, por lo que debes remitirte a la documentación de ese plugin para saber cómo utilizarlo.

Hay muchos plugins gratuitos, otros muchos de pago y una gran mayoría que tienen una versión limitada gratuita y otra de pago con funciones adicionales. El desarrollo de plugins para Wordpress es una industria que proporciona muchos puestos de trabajo a programadores/as en la actualidad.

Como hicimos con los *themes*, **vamos a ilustrar con un ejemplo el proceso de creación de plugins**. Haremos algo muy sencillo pero bien construido, de manera que pueda servirte para desarrollos posteriores más realistas.

El plugin se llamará **"Chiste"** y se encargará de imprimir un chiste aleatorio cada vez que lo llamemos desde nuestra plantilla. El chiste aleatorio se extraerá de una tabla con chistes que almacenaremos en la base de datos. Lo puedes usar para imprimir un chiste en tu web de cuando en cuando, o para mostrar un chiste diferente cada vez que se carga la página, o yo qué sé para qué.

Construiremos el plugin paso a paso, desde una versión muy simple que siempre contará el mismo chiste hasta la versión definitiva. De este modo, comprenderás muy bien el funcionamiento del sistema de plugins de Wordpress.

#### **Crear un plugin nuevo**

Para crear el plugin "Chiste" basta con crear un archivo llamado ***chiste.php*** en una carpeta llamada también *chiste* y ubicada a su vez en *wp-content/plugins/*

Dentro del archivo *chiste.php*, escribiremos el comentario de cabecera para que Wordpress lo reconozca como un plugin válido (igual que sucede con las plantillas). Es muy importante respetar la sintaxis.

```php
<?php
   /*
      Plugin Name: nombre del plugin
      Plugin URI: uri oficial del desarrollador/a del plugin
      Description: qué hace el plugin
      Version: numero de versión
      Author: Nombre del programador/a
      Author URI: uri del programador/a
   */
   
   /*
      Todo esto aparecerá en el panel de 
      administración de plugins del dashboard
   */ 
?>
```

#### **Añadir funciones al plugin**

Vamos a crear nuestra primera función dentro del plugin. Abre el archivo ***chiste.php*** y añade esto:

```php
   function chiste(){
      echo "Van dos por tres calles y se cae el de enmedio";   
   }
```

Supongo que este código no requiere demasiada explicación, ¿no? Pues ahí lo dejamos.

#### **Instalar y desinstalar el plugin**

Para poder instalar y desinstalar un plugin desde el panel de administracion de Wordpress, es necesario crear dos funciones más en ***chiste.php***: una para instalar y otra para desinstalar. Estas funciones, por ahora, las dejaremos vacías.

Además, al final del archivo ***chiste.php*** hay que usar la funcion del API de Wordpress add_action() para indicar las funciones que activan y desactivan el plugin.

Es más fácil hacerlo que explicarlo. Ahí va:

```php
   function chiste_instala(){
      // Por ahora, la dejamos vacía
   }
   function chiste_desinstala(){
      // Por ahora, la dejamos vacía
   }   

   add_action('activate_chiste/chiste.php','chiste_instala');
   add_action('deactivate_chiste/chiste.php', 'chiste_desinstala');
```

#### **Cómo usar las funciones del plugin**

Ahora ya puedes usar este plugin tan chistoso. Solo debes colocar en alguna sección de tu plantilla la siguiente línea:

```php
<?php chiste(); ?>
```

Por ejemplo, si colocas esa función en el archivo *header.php* de tu plantilla, cada vez que se cargue el header (es decir, en todas las páginas), la función *chiste()* será invocada y, hala, un chiste impreso en tu pantalla.

#### **Configurar el plugin desde el panel de administración**

Ahora vamos a crear una entrada dentro de los menús del *dashboard* que nos permita modificar las opciones de este plugin.

La entrada de menú la integraremos en el menú "opciones". Para lograrlo, necesitamos dos funciones más en nuestro archivo ***chiste.php***:

* *chiste_panel()*: aquí incluiremos el html necesario para la pantalla de configuración de nuestro plugin. Para no mezclar html dentro del código, usaremos la función include() de PHP, de manera que podamos colocar el HTML en otro archivo a parte.
* *chiste_add_menu()*: aquí usaremos la función del API de Wordpress *add_options_page()*, que sirve para añadir una entrada al menó "Opciones".

Además, llamaremos a otra función del API, *add_action()*, para provocar la invocación de *chiste_add_menu()* cada vez que Wordpress vaya a crear su menú de administración.

```php
<?php
   function chiste_panel(){      
      include('template/panel.html');
   }
   function chiste_add_menu(){   
      if (function_exists('add_options_page')) {
         //add_menu_page
         add_options_page('chiste', 'chiste', 'manage_options', basename(__FILE__), 'chiste_panel');
      }
   }
   if (function_exists('add_action')) {
      add_action('admin_menu', 'chiste_add_menu'); 
   } 
?>
```

Quizá la línea de *add_options_page()* requiera alguna explicación adicional, ¿verdad? Lo único que hacemos ahí es añadir una entrada al menú de opciones del *dashboard*, indicándole en los parámetros:
* El título de la pantalla de administración de nuestro plugin ("chiste").
* El texto de la entrada de menú (también "chiste").
* El permiso necesario del usuario que podrá ver este elemento de menú. Hemos elegido "manage_options", que es un permiso típico de los administradores del sitio. Otros usuarios de menor nivel no podrán acceder a este menú. Tienes una lista completa de los permisos (o *capabilities*, en jerga de Wordpress) en https://wordpress.org/support/article/roles-and-capabilities/)
* La URI amigable para esta opción de menú. Puede ser cualquier cosa, siempre que no esté ya en uso. Hemos usado el propio nombre del archivo (*basename(__FILE__)*) para evitar conflictos con otras opciones de menú.
* El nombre de la función que se invocará cuando se haga clic en ese elemento de menú (es decir, *chiste_panel()*).


El archivo *panel.html* será un simple formulario html que mostrará la configuración del plugin. Crearemos algo muy sencillo. Por supuesto, se puede mejorar con un poco de HTML y CSS. Lo guardaremos en ***template/panel.html***:

```html
<form method="post" action="" id="chiste">
<label for="chiste_inserta" accesskey="s">Inserte su chiste<input type='text' id='chiste_inserta'  name='chiste_inserta' value='' /></label>
<input type='submit' name='' value='enviar' />
</form>
```

Por último, modificaremos la función *chiste_panel()* para poder visualizar nuestros avances:

```php
<?php
   function chiste_panel(){      
      include('template/panel.html');
   }
   echo "<h1>{$_POST['chiste']}</h1>";
?>
```

Podemos probar que todo funciona escribiendo algo en el formulario (pulsando "Enviar").

#### **Acceder a la BD desde nuestro plugin**

También se puede acceder a la base de datos de Wordpress desde un plugin. Esto es práctico para, por ejemplo, crear nuestra propia tabla adicional con la que gestionar el contenido del plugin, que es justo lo que nosotros queremos.

Para ello, antes debemos desinstalar el plugin desde el panel de control. Solo así podremos modificar la función de instalación y ejecutarla más adelante de nuevo.

Las funciones de Wordpress que manejan la BD se invocan con una variable global ***$wpdb***:

```php
<?php
function chiste_instala(){
   global $wpdb;   // Variable para acceder a la BD
   $table_name= $wpdb->prefix . "chistes";
   $sql = " CREATE TABLE $table_name(
      id INTEGER NOT NULL AUTO_INCREMENT ,
      chiste TEXT NOT NULL ,
      PRIMARY KEY ( `id` )   
   ) ;";
   $wpdb->query($sql);
   $sql = "INSERT INTO $table_name (chiste) VALUES ('Van dos por tres calles y se cae el de enmedio');";
   $wpdb->query($sql);
}   

function chiste_desinstala(){
   global $wpdb; 
   $tabla_nombre = $wpdb->prefix . "chistes";
   $sql = "DROP TABLE $tabla_nombre";
   $wpdb->query($sql);
}   
?>
```

Por supuesto, hay que agregar los datos a la BD desde nuestro panel de configuración del plugin, para lo cual modificaremos la función *chiste_panel()*:

```php
function chiste_panel(){
   include('template/panel.html');         
   global $wpdb; 
   $table_name = $wpdb->prefix . "chistes";
   if(isset($_POST['chiste_inserta'])){   
         $sql = "INSERT INTO $table_name (chiste) VALUES ('{$_POST['chiste_inserta']}');";
         $wpdb->query($sql);
   }
}
```

¡Ahora que ya podemos insertar chistes en nuestra BD desde el *dashboard* de Wordpress!

Solo nos queda poder mostrarlos en nuestra función *chiste()*. Para esto, extraeremos un chiste de manera aleatoria de nuestra BD modificando la función *chiste()*:

```php
function chiste(){
   global $wpdb; 
   $table_name = $wpdb->prefix . "chistes";
   $chiste = $wpdb->get_var("SELECT chiste FROM $table_name ORDER BY RAND() LIMIT 0, 1; " );
   include('template/chiste.html');      
}
```

Ahora modifiquemos nuestro ***template/chiste.html*** para que imprima la variable $chiste:

```html
<h1><?php echo $chiste;?></h1>
```

Para terminar, vamos modificar el html de nuestro panel de opciones para que se adapte al html del administrador de Wordpress y no quede tan feo. Esto es solo una cuestión estética, por supuesto. Pero, ya que hacemos algo, vamos a hacerlo bien:

```html
 <div class="wrap"> 
   <form method="post" action="">
      <fieldset>
         <legend>Introduce un nuevo chiste</legend>
         <label for = "chiste" accesskey = "c">Escriba el chiste<input type = "textarea" id = "chiste_inserta"  name= "chiste_inserta" /></label>
         <input type = "submit" name="" value="Enviar" />
      </fieldset>
   </form>
</div>
```

