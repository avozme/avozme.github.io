---
layout: page
title: 1.1 Algunas cosas que debes saber sobre los CMS
permalink: /cms/algunas-cosas-que-debes-saber
nav_order: 1
has_children: false
parent: 1 Sistemas gestores de contenido (CMS)
grand_parent: Desarrollo Web en Entorno Servidor
---


## 1.1. Algunas cosas que debes saber sobre los CMS
{: .no_toc }

- TOC
{:toc}

### 1.1.1. Inconvenientes de desarrollar una web desde cero

Desarrollar sitios web programándolos desde cero (o más o menos desde cero, porque la mayor parte de las veces se parte de librerías existentes) tiene varias **ventajas** como:

* Nos permite sacar el máximo partido tanto del servidor como de los clientes.
* Nos da un control absoluto sobre el sitio web que estamos desarrollando.
* Nos posibilita ajustarnos al máximo a los requerimientos y crear aplicaciones a medida.

Pero también tiene **inconvenientes**:

* La creación de un sitio desde cero es un proceso muy largo.
* Las ampliaciones y actualizaciones del sitio también resultan lentas y costosas.
* Ambas tareas (creación y actualización) requieren personal altamente cualificado, con conocimientos de todas las tecnologías implicadas. Es decir, desarrolladores web. Y eso cuesta dinero.

Cuando los inconvenientes superan a las ventajas, el equipo de desarrollo puede optará por **no desarrollar desde cero**. Esto ocurre en la inmensa mayoría de los proyectos. No es necesario inventar la rueda cada vez que tengamos que construir un coche, ¿verdad? Pues para construir una aplicación web pasa lo mismo.

Ahora bien, ¿de qué base partimos? Podemos construir una biblioteca de clases que resuelvan las tareas más habituales de cualquier aplicación web, cosas como la autenticación de usuarios, la seguridad, el acceso a bases de datos, etc. Cosas que se repiten una y otra vez con muy pocas variaciones.

Esa biblioteca de clases puede ser más grande o más pequeña, más elaborada o más simple, más configurable o más rígida. Pero, sea como sea, nos ahorrará tiempo y esfuerzo en el desarrollo de nuevos proyectos. A esas bibliotecas se las denomina ***frameworks*** y es rara la aplicación web que no se programa usando alguna de las muchas que hay por ahí pululando, bien se usa un framework propio creado por el propio equipo de desarrollo.

Pero se puede ir un paso más allá y utilizar una biblioteca más grande, una que ya te lo dé casi todo hecho y a la que solo tengas que indicarle qué tipografía, qué colores y qué contenidos quieres mostrar en tu web, y ella solita se las apañe para generarte la web de forma casi automática.

Esta solución casi mágica son los **sistemas gestores de contenido (CMS)** de los que estamos hablando. Sin programar una sola línea de código, puedes tener lista en unos minutos una web plenamente funcional y de aspecto profesional.

Por suerte para nosotros, los desarrolladores/as web, la CMS no pueden hacerlo todo. Son soluciones extraordinariamente eficaces para montar sitios web convencionales, pero cuando quieres crear algo que se salga de los límites muy marcados del CMS, necesitas a un programador/a. Y entonces, ¿a quién vas a llamar?

### 1.1.2. Cómo funciona un CMS

**Un CMS (Content Management System)** es una aplicación web que se ejecuta en un servidor y se controla desde un navegador (cliente), y que nos permite:

* Crear a través del navegador un sitio web completamente nuevo en muy poco tiempo.
* Administrar fácilmente todo lo relacionado con el sitio web: usuarios, privilegios, contenido, apariencia, menús, etc.
* Y todo ello sin tener conocimientos de HTML, CSS, PHP ni el resto de tecnologías (ojo: no es necesario, pero sí conveniente)

El CMS guarda el **contenido** del sitio web en una **base de datos**.

Cuando se solicita una página, un programa escrito en PHP (o en otro lenguaje de servidor) busca el contenido de esa página en la BD y la genera dinámicamente, entregándola al navegador web (cliente).

Además, otro conjunto de programas permiten agregar nuevo contenido, modificar el contenido existente, crear usuarios, gestionar privilegios, etc. Todo ello altera los datos existentes en la BD, que a su vez alteran la forma en la que el usuario percibe la página cuando la visita.

Al sitio web en sí se le denomina a veces ***front-end***. El front-end, en este sentido, es lo que ve el visitante de la web.

A las páginas de adminsitración del sitio se les llama a veces ***back-end*** o ***dashboard*** (panel de administración). El back-end sólo es accesible a algunos usuarios (administradores, editores, etc). El CMS siempre necesita, por ello, un control de acceso de usuarios o login.

¡Cuidado! Los términos front-end y back-end son confusos. En términos de programación, a menudo se denomina ***front-end*** a la parte de la aplicación que se ejecuta en el navegador web y ***back-end*** a la parte de la aplicación que se ejecuta en el servidor e interactúa con los recursos del mismo (como la base de datos). En este otro sentido, el front-end está escrito en HTML, CSS, JavaScript (y cualquiera de las múltiples librerías que existen para Javascript, como jQuery, React o Vue.js) y el back-end está escrito en PHP, Java, Python u otros lenguajes del lado del servidor.

Si encuentras por ahí una oferta de trabajo para un "desarrollador/a back-end" o "desarrollador/a front-end", se refiere a esta última acepción de ambos términos. Es decir, están pidiendo un "desarrollador/a HTML + CSS + Javascript (y librerías de Javascrit)" o un "desarrollador/a en PHP o similar".

### 1.1.3. Tipos de CMS

Hay un montón (¡pero un montón!) de CMS, y cada uno tiene sus propias características, puntos fuertes y puntos débiles.

Como hay tantos, resulta útil clasificarlos.

Algunos autores los clasifican según su **método de distribución**:

* Código abierto y software libre.
* Código propietario.

Pero, personalmente, creo que tiene más sentido clasificarlos por su **funcionalidad**. Así, nos encontramos con CMS de estos tipos (entre otros):

* CMS genéricos (para cualquier tipo de sitio web)
* CMS para blogs.
* CMS para foros.
* CMS para wikis.
* CMS para e-learning (aprendizaje en línea)
* CMS para e-commerce (comercio electrónico)
* CMS para publicaciones digitales (periódicos, revistas...)

Algo tremendamente odioso de los CMS es que **son fuertemente incompatibles** entre sí. Cada uno utiliza un interfaz distinto, bases de datos completamente diferentes para almacenar la información, módulos incompatibles, etc. Existen algunas iniciativas para lograr que los servicios desarrollados en un CMS puedan utilizarse en otros, pero todavía están en un estadio muy inicial.

Lo que sí existen son familias de CMS relacionados entre sí que pueden compartir algunas características, generalmente porque unos CMS han derivado de otros.

### 1.1.4. Algunos ejemplos de CMS importantes

Los CMS propietarios no han podido competir con los CMS libres. Por ello, han evolucionado hacia soluciones cloud computing completas, como Microsoft Azure, Google Cloud o Amazon Web Services (AWS).

Entre los verdaderos CMS abundan las soluciones opensource o software libre. Por ejemplo:

* **Blogs**: WordPress, Jekyll, GetSimple, Umbraco...
* **Wikis**: MediaWiki, XWiki, DokuWiki...
* **Foros**: phpBB, MyBB, bbPress, Discourse...
* **e-learning**: Moodle, WebCT, Mahara, etc.
* **e-commerce**: PrestaShop, Magento, OsCommerce, OpenCart...

Muchos de estos CMS desaparecerán, se fundirán con otros o se dividirán en varios proyectos desde que yo escriba estas líneas hasta que tú las leas. Lo mejor es que eches un vistazo a alguna lista actualizada de CMS, como [esta de Wikipedia](https://en.wikipedia.org/wiki/List_of_content_management_systems).

### 1.1.5. Instalación de un CMS

IMPORTANTE: la instalación puede diferir de un CMS a otro, pero, más o menos, todos necesitan los mismos pasos.

Hay que leer cuidadosamente las instrucciones de instalación, que encontrarás en la web del desarrollador.

Los pasos que suelen ser habituales en casi todos los CMS son:

1. Descargar la última versión del programa de la web del desarrollador.
2. Asegurarse de que el servidor cumple los prerrequisitos para ejectuar el CMS (versión de Apache, PHP, MySQL u otro software necesario)
3. Subir el CMS por al servidor (por ftp, vía web o como tu proveedor de hosting te lo permita).
4. Crear la base de datos.
5. Lanzar la instalación del CMS. Esto suele hacerse cargando una dirección concreta en tu navegador.
6. Adapar el archivo de configuración (suele llamarse config.php, config.inc, o algo similar). En los CMS más elaborados este paso no es necesario, pues el programa de instalación se encarga de generar un archivo de configuración válido.
7. A veces, hay que modificar los permisos de algún directorio y/o archivo.
8. Instalar el paquete de idioma español (si está disponible)

### 1.1.6. Explotación de un CMS

IMPORTANTE: la explotación puede diferir notablemente de un CMS a otro, pero, en general, todo tienen una serie de elementos en común.

Hay que leer cuidadosamente las instrucciones de uso, que encontrarás en la web del desarrollador.

Pasos que suelen ser habituales en casi todos los CMS, una vez realizada la instalación:

1. Asignar una password de alta seguridad al usuario administrador que se crea por defecto.
2. Crear otros usuarios y asignarles privilegios.
3. Editar la página de inicio del sitio web.
4. Cambiar la plantilla (apariencia) del sitio.
5. Instalar módulos de ampliación (si es necesario).
6. Crear el contenido y/o revisar el contenido creado por otros usuarios.

En las siguientes secciones nos centraremos en la instalación y explotación de algunos de los CMS más populares del mercado.

