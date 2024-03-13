---
layout: page
title: 5. Gestores de contenido
permalink: /cms/
parent: Tecnologías de la Información y la Comunicación 2º BACHILLERATO
nav_order: 5
has_children: false
---

# 5. Gestores de contenido
{: .no_toc }

- TOC
{:toc}

Este capítulo aún está en construcción.

## 5.1. Introducción a los CMS

### 5.1.1. Qué es un CMS

**Un CMS (Content Management System)** es una aplicación web que se ejecuta en un servidor y se controla desde un navegador (cliente), y que nos permite:

* Crear a través del navegador un sitio web completamente nuevo en muy poco tiempo.
* Administrar fácilmente todo lo relacionado con el sitio web: usuarios, privilegios, contenido, apariencia, menús, etc.
* Y todo ello sin tener conocimientos de HTML, CSS, PHP ni el resto de tecnologías (ojo: no es necesario, pero sí conveniente)

El CMS guarda el **contenido** del sitio web en una **base de datos**.

Cuando se solicita una página, un programa escrito en PHP (o en otro lenguaje de servidor) busca el contenido de esa página en la BD y la genera dinámicamente, entregándola al navegador web (cliente).

Además, otro conjunto de programas permiten agregar nuevo contenido, modificar el contenido existente, crear usuarios, gestionar privilegios, etc. Todo ello altera los datos existentes en la BD, que a su vez alteran la forma en la que el usuario percibe la página cuando la visita.

El CMS tiene, entonces, dos partes bien diferenciadas:

* La **parte visitable** de la web, que es lo que los visitantes ven (la web en sí).
* La **parte de administración** del sitio (también llamada ***dashboard*** o ***panel de administración***). El dashboard sólo es accesible a algunos usuarios (administradores, editores, etc). El CMS siempre necesita, por ello, un control de acceso de usuarios o *login*.

Tu trabajo con el CMS consistirá en aprender a usar el panel de administración para conseguir construir una web visitable lo más atractiva posible.

### 5.1.2. Tipos de CMS

Hay un montón (¡pero un montón!) de CMS, y cada uno tiene sus propias características, puntos fuertes y puntos débiles.

Como hay tantos, resulta útil clasificarlos por su **funcionalidad**. Así, nos encontramos con CMS de estos tipos (entre otros):

* CMS genéricos (para cualquier tipo de sitio web)
* CMS para blogs.
* CMS para foros.
* CMS para wikis.
* CMS para e-learning (aprendizaje en línea)
* CMS para e-commerce (comercio electrónico)
* CMS para publicaciones digitales (periódicos, revistas...)

Algo tremendamente odioso de los CMS es que **son fuertemente incompatibles** entre sí. Cada uno utiliza un interfaz distinto, bases de datos completamente diferentes para almacenar la información, módulos incompatibles, etc.

### 5.1.3. Algunos ejemplos de CMS importantes

Entre los CMS abundan las soluciones opensource o software libre. Por ejemplo:

* Para **Blogs**: WordPress, Jekyll, GetSimple, Umbraco...
* Para **Wikis**: MediaWiki, XWiki, DokuWiki...
* Para **Foros**: phpBB, MyBB, bbPress, Discourse...
* Para **e-learning**: Moodle, WebCT, Mahara, etc.
* Para **e-commerce**: PrestaShop, Magento, OsCommerce, OpenCart...

Muchos de estos CMS desaparecerán, se fundirán con otros o se dividirán en varios proyectos desde que yo escriba estas líneas hasta que tú las leas. Lo mejor es que eches un vistazo a alguna lista actualizada de CMS, como [esta de Wikipedia](https://en.wikipedia.org/wiki/List_of_content_management_systems).


### 5.1.4. Explotación de un CMS

IMPORTANTE: esto puede diferir notablemente de un CMS a otro, pero, en general, todos tienen una serie de elementos en común. Nosotros nos centraremos a partir de aquí en la explotación del CMS más popular de todos: Wordpress.

Los pasos que suelen ser habituales en casi todos los CMS, una vez realizada la instalación, son:

1. Asignar una password de alta seguridad al usuario administrador que se crea por defecto.
2. Crear otros usuarios y asignarles privilegios.
3. Editar la página de inicio del sitio web.
4. Cambiar la plantilla (apariencia) del sitio.
5. Instalar módulos de ampliación o *plugins* (si es necesario).
6. Crear el contenido y/o revisar el contenido creado por otros usuarios.

## 5.2. Wordpress, el rey de los CMS

Wordpress es sin duda el campeón actual de los CMS. Algunas estadísticas afirman que el 90% de los sitios web de internet está hecho con Wordpress. Probablemente son estadísticas un poco infladas, pero la importancia de este CMS es innegable.

Wordpress es un CMS enfocado a la creación de blogs pero, en su estadio actual, permite crear casi cualquier tipo de sitio web: tiendas online, portales, revistas digitales, álbumes de imágenes o recursos de cualquier tipo, etc.

### 5.2.1. Características principales de Wordpress

Las características principales de Wordpress son:

* Separación entre el contenido y el diseño. El contenido se almacena en una base de datos. El diseño, en una plantilla, que es un conjunto de archivos escritos con CSS y los lenguajes de programación Javascript y PHP.
* Apuesta decidida por la apariencia atractiva del resultado final (aunque esto depende mucho de la plantilla, claro) . 
* La estructura y diseño visual del sitio depende de un sistema de plantillas. Es decir: cambias la plantilla y todo el sitio web cambia de aspecto, conservando el mismo contenido.
* La visualización final del contenido también depende de los plugins y widgets que se hayan instalado, y que pueden modificar sustancialmente en funcionamiento tanto del front-end como del back-end.
* Apuesta decidida por respetar las recomendaciones del W3C, aunque, desde luego, hay plugins y plantillas que no lo hacen. 
* Las entradas publicadas se ordenan por fecha, aunque esto se puede modificar. Wordpress se diseñó para hacer *blogging* y esa intención inicial aún permanece intacta, pero con un poco de manipulación puede emplearse para cualquier cosa.

### 5.2.2. Funcionalidades de Wordpress

**Wordpress hace magia**. Así de sencillo. Permite que cualquier usuario medio, sin tener ni idea de programación, pueda crear un sitio web solvente y de aspecto profesional en un rato. *A un programador web le llevaría semanas programar algo parecido desde cero*.

Pero **Wordpress también tiene sus limitaciones**, y en ese caso necesitarás a un programador web a mano para superarlas.

Entre las asombrosas funciones de Wprdpress podemos mencionar estas:

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

### 5.2.3. Plantillas de Wordpress

Las plantillas (o *themes*) de Wordpress son **diseños CSS que sirven para establecer la apariencia y estructura del sitio web**. Algunas también modifican parte del panel de administración.

Hay una gran comunidad dedicada al diseño de estas plantillas. Puedes encontrarlas tanto en el sitio de Wordpress (comprobadas y aprobadas oficialmente) como en sitios web de terceros. Muchas son gratuitas, otras de pago y, la mayoría, tienen una versión gratuita con funciones adicionales de pago.

Las posibilidades de las plantillas, tanto a nivel de diseño, estructura o gestión, son tan grandes que te permiten tener desde un simple blog hasta un sitio web completamente personalizable de forma intuitiva desde el panel de administración.

### 5.2.4. Widgets

Los widgets son **pequeñas aplicaciones** que proporcionan nuevas funcionalidades a un programa o que permiten un acceso rápido a funcionalidades usadas con frecuencia.

Pueden ser vistosos como, por ejemplo, relojes en pantalla, calculadoras, calendarios o nubes de tags; o pueden ser discretos pero útiles como, por ejemplo, un cuadro con enlaces de interés o un contador del número de visitas.

Wordpress incorpora un sistema de widgets para sus plantillas que ofrece numerosas posibilidades y flexibilidad para el diseño y estructura de sus blogs. Cada plantilla puede soportar un número diferente de Widgets en distintas posiciones de la pantalla.

### 5.2.5. Plugins

Hay una monstruosa cantidad de plugins que **potencian el uso de Wordpress y que lo convierten en un CMS prácticamente de propósito general**. Encontrarás un plugin para casi cualquier cosa que se te ocurra. Bueno, no: encontrarás decenas de plugins para casi cualquier cosa que se te ocurra.

Pero (¡siempre hay un pero!) con los plugins se corre el riesgo de empezar a parchear Wordpress hasta convertirlo en un amasijo informe de código puesto a pegotes. Muchos sitios web montados con Wordpress se vuelven ingobernables (y extraordinariamente lentos y pesados en la carga) por la gran cantidad de plugins que tienen activados.

Otro problema de los plugins es que pueden provocar incontables problemas de seguridad y de fallos con las actualizaciones del sistema.

Por último, y al igual que ocurría con las plantillas, tienes que saber que muchos plugins son gratuitos, otros son de pago, y otros tienen versiones gratuitas que se vuelven de pago cuando queremos utilizar sus características más atractivas.

### 5.2.6. Fallos de seguridad de Wordpress

Las críticas más contundentes contra Wordpress siempre se han centrado en sus problemas de seguridad. Diversos estudios a lo largo del tiempo han revelado que la gran mayoría de los sitios web basados en Wordpress son vulnerables a ataques porque no se actualizan tan a menudo como deberían.

Todos los sistemas que se vuelven muy populares se vuelven inseguros por el simple hecho de que se multiplican los ataques contra ellos y Wordpress no es una excepción.

La receta para minimizar los posibles problemas de seguridad es sencilla: **mantener nuestro Wordpress siempre actualizado**, algo que puede hacerse fácilmente desde el panel de administración.

## 5.3. Cómo se usa Wordpress

Una vez que tienes instalado tu Wordpress en el servidor, ya dispones de un sitio en línea al que puedes acceder como visitante (y ver lo que vería cualquiera) o como administrador (y ver solo "las tripas" o "la sala de máquinas" del sitio web).

El sitio es por completo funcional pero, obviamente, está vacío de contenido. Su aspecto será más o menos como este:

![Wordpress recién instalado](/docs/tico/_site/assets/images/01-wordpress-recien-instalado.jpg)

Lo que estás viendo aquí es la plantilla (*theme*) por defecto de Wordpress. Dependiendo de la versión que instales, tendrá un aspecto algo diferente. Una instalación nueva también incorpora una publicación (*post*) de ejemplo (con un comentario también de ejemplo), así como una página estática.

Lo siguiente que tienes que hacer es acceder al panel de administración, que estará hubicado en https://tu-servidor/wp-admin. Verás una pantalla de login donde tendrás que introducir el usuario y la contraseña de administración de Wordpress. Estas credenciales se seleccionaron durante el proceso de instalación.

Una vez traspasada la puerta del login, encontrarás una pantalla con la que debes familiarizarte: el **panel de administración** o ***dashboard*** de Wordpress.

![Panel de administración de Wordpress](/docs/tico/_site/assets/images/01-wordpress-panel-administracion.png)

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

## 5.4. Breve tour por Wordpress para novatos

Todo esto puede parecer complicadísimo, pero Wordpress (a nivel de usuario) es muy secillo de usar cuando has pasado un poco de tiempo con él.

Si es tu primera vez con Wordpress, te recomiendo que te prepares un café (o tu infusión favorita), te sientes sin prisa ante el ordenador en algún momento en el que no te vayan a interrumpir durante varias horas y dediques una sesión intensiva a hacer lo siguiente:

1. Accede al **panel de administración** de tu Wordpress.
2. **Crea dos o tres categorías**. Antes deberás decidir qué temática tendrá tu sitio. Utiliza algún tema de tu interés: un deporte, la tecnología, la programación, el cine, la literatura... Si usas algo que te interese, la experiencia será mucho más fructífera. Por ejemplo, si tu temática es "programación", podrías crear las categorías "Java", "PHP" y "Python", por decir algo.
3. **Crea un par de entradas** por cada categoría. No tienen que ser nada especial: solo estamos jugueteando. Copia y pega texto de alguna otra publicación de internet. O redáctalas tú, como prefieras. Asegúrate de incluir alguna imagen y otros elementos multimedia.
4. **Crea alguna página** ("Acerca de", "Sobre mí", "Contacto" o algo así).
5. **Cambia de plantilla**. Prueba varias que te gusten y, cuando te decidas por una, métete en sus opciones de configuración y trastea un rato. Algunas plantillas son configurables hasta límites enfermizos. Otras, en cambio, son muy limitadas. No olvides ir observando cómo estos cambios afectan a la forma en la que los visitantes verían en blog.
6. **Instala algunos plugins** de prueba que te parezcan interesantes. Por ejemplo, galerías de imágenes o formularios de contacto.
7. **Crea algunos usuarios** adicionales con distintos roles. Accede con ellos al panel de administración para ver las diferencias entre unos roles y otros.
8. **Juguetea sin miedo con las opciones** del menu "Settings". Algunas de ellas podrían dejar tu Wordpress totalmente inoperativo. ¡Bienvenido a la vida real! Trata de resolver el problema bicheando en internet. Antes o después, eso mismo te ocurrirá con sitios reales.

Cuando termines esta experiencia inmersiva (que puede llevarte varios días), estarás en condiciones de montar un sitio web con Wordpress real.