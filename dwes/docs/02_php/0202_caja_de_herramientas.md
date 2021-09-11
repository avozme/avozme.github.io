---
layout: page
title: 2.2 Caja de herramientas
permalink: /php/caja-de-herramientas
nav_order: 2
has_children: false
parent: 2 Introducción a PHP
grand_parent: Desarrollo Web en Entorno Servidor
---

## 2.2. Caja de herramientas para desarrollar de aplicaciones web
{: .no_toc }

- TOC
{:toc}

Para desarrollar apliaciones web necesitamos una caja de herramientas bastante completa. Algunas herramientas son fundamentales, como el martillo o el destornillador de una caja de herramientas convencional. Otras, en cambio, son optativas y dependerán del trabajo que vayamos a realizar y de nuestras propias preferencias como desarrolladores.

En esta sección vamos a hacer un repaso de las herramientas fundamentales, las que no pueden faltar en tu caja de herramientas. Algunas ya las conoces y otras las aprenderemos a manejar a lo largo de este curso. Se trata de:

* DHTML (HTML, CSS y Javascript)
* PHP u otro lenguaje de script de servidor (Python, Ruby, Perl, etc)
* MySQL / MariaDB u otro SGBD que permita acceso remoto.

### 2.2.1. HTML

![Logo de HTML5](/assets/images/02-logo-html.png)

**DHTML** (Dynamic HTML) no es un lenguaje como tal, sino que, como probablemente sabes ya, es la conjunción de tres lenguajes:

* HTML
* CSS
* JavaScript

DHTML, en conjunción con, PHP son los lenguajes que nos van a permitir ejecutar programas en el servidor y acceder a sus recursos a través de páginas web, pero existen otras posibles combinaciones como:

* DHTML con ASP
* DHTML con JSP
* DHTML con Python, Ruby, Perl, etc.

HTML significa *"HyperText Markup Language"* (Lenguaje de Etiquetas de Hipertexto). Como sin duda sabrás, se trata de un lenguaje para formatear documentos:

* Permite definir el tipo de letra, tamaño, formato y color de los textos.
* Permite insertar imágenes y otro contenido multimedia.
* Permite crear listas, tablas, enumeraciones...
* Permite crear enlaces entre secciones del mismo documento, o enlaces con otros documentos (hipertexto)

A lo largo de este texto supondremos que tú, lector o lectora, estás familiarizado con HTML. Tampoco es que necesites un nivel profesional para entenderlo todo, pero conocerlo con cierta profundidad te ayudará. Y, desde luego, si no conoces HTML en absoluto, no comprenderás nada de lo que ocurra a partir de ahora. Por lo tanto, si HTML es para ti un desconocido, es mejor que pares aquí y busques un poco de información al respecto antes de continuar. Te sorprenderá ver que HTML es bastante sencillo de comprender.

Recuerda que **HTML *NO* es un lenguaje de programación**: no permite programar algoritmos. Pero sí permite incrustar otros lenguajes de programación en su interior, como enseguida veremos. Esos trozos de código incrustados dentro de HTML se denominan ***scripts***.

#### Brevísima historia de HTML

* En 1990 se crea HTML (procedente de un lenguaje anterior, SGML) junto con la World Wide Web, para formatear los documentos de la www.
* Se amplía en sucesivas versiones hasta la 3.0, que no consiguió éxito debido a las limitaciones de los navegadores de la época.
* Comienza la guerra de navegadores: Microsoft y Netscape sacan sus propios “dialectos” de HTML y destrozan en estándar.
* A partir de HTML 4, los navegadores intentan unir las características de los dos, pero el resultado es demasiado confuso y complejo.
* Se hace evidente que hay que hacer una “limpieza” de HTML. Así surge XHTML, la versión XML de HTML, mucho más estricta y formal, con menos añadidos pero igual de potente.

Después de esta accidentada historia, nos encontramos que, en la situación actual, las versiones de HTML que puedes encontrarte pululando por la www son:

* **HTML 4.01 transicional**: HTML clásico, con todos los elementos del HTML antiguo. En la actualidad está obsoleto, pero aún quedan muchas páginas antiguas que lo utilizan.
* **HTML 4.01 estricto**: también llamado XHTML, no permite usar los elementos HTML desaprobados, tales como definición de formatos. También se considera obsoleto.
* **HTML5**: elimina definitivamente los elementos antiguos del lenguaje e incorpora algunos nuevos para completar la asimilación con XML. Es el estándar actual.
* La especificación para **HTML6** (o HTML Next) está actualmente en desarrollo.

### 2.2.3. CSS

![Logo de CSS3](/assets/images/02-logo-css.jpg)

**CSS** significa ***"Cascade Style Sheet"*** (Hojas de estilo en cascada).

CSS, como sin duda ya sabes, es un lenguaje para la definición de los formatos utilizados en una página web. Sólo permite definir el formato (es decir, el aspecto: colores, tipografías, disposición de los elementos...) de la página, no su contenido.

Al definir los formatos en otra parte, se pueden reutilizar a lo largo de una o incluso de varias páginas: si cambiamos la definición CSS del formato, se cambian automáticamente los formatos de todas las páginas que usen esa definición.

El objetivo último de CSS es **separar completamente el formato de la página de su contenido**.

CSS 2.1 se usaba con HTML 4. **CSS3 se usa con HTML5 y se considera el estándar actual**. Está soportado universalmente, aunque, como sin duda habrás sufrido en tus carnes, los diferentes navegadores pueden interpretar de forma ligeramente distinta algunas definiciones CSS.

Si todo esto te suena tan raro como el idioma Kinglon, deberías aprender un poco de CSS antes de continuar. Explicar los fundamentos de CSS excede a los propósitos de este texto. Si aún los desconoces, encontrarás muchos recursos sobre CSS en la red.
Tampoco es necesario que te conviertas en un experto/a en CSS de la noche a la mañana, ni mucho menos: con que comprendas su sintaxis básica es suficiente. El resto puede consultarse en cualquier manual online de referencia y ya mejorarás con el tiempo y la experiencia.

### 2.2.4. Javascript

![Logo de Javascript](/assets/images/02-logo-js.jpg)

JavaScript es un lenguaje interpretado que puede ser incrustado dentro del código HTML de una página web.

El código JavaScript puede **interactuar y modificar cualquier parte del documento HTML**, por lo que dota a las páginas web de **dinamismo e interactividad**.

***JavaScript no es Java***, por mucho que su nombre se parezca. También su sintaxis puede recordar un poco a Java en algunas ocasiones. Pero déjame que te lo repita de nuevo: *Javascript no es Java*. Se parecen tanto como un euro y un yen japonés. Las dos son monedas de curso legal, pero ahí terminan sus semejanzas.

La implementación de JavaScript de cada navegador es distinta, obteniéndose resultados que no siempre son iguales, por desgracia para los desarrolladores. Por ejemplo, el motor Javascript de Chrome se llama *V8*, mientras que el de Firefox es *Rhino* y el de Safari y Microsoft Edge es *WebKit*.

Este texto tampoco es un manual de Javascript. Nuevamente, si no sabes nada de Javascript, debes detenerte aquí y aprender los fundamentos antes de continuar, o te perderás una parte importante de lo que sigue. Y, nuevamente, no es necesario que te conviertas en un fuera de serie del lenguaje. De momento, basta con que lo comprendas y hayas hecho unas cuantas prácticas con él. Irás mejorando con la experiencia.

Porque déjame que te cuente un secreto: no se puede programar una aplicación web solo con PHP. Cualquier aplicación web lleva parte de su código en el servidor (PHP u otro lenguaje de servidor) y parte en el cliente (ya sabes: HTML, CSS y Javascript), si bien es cierto que muchos programadores se especializan más en una parte que en la otra. Pero *debes conocer ambas caras de la moneda para poder participar con éxito en el desarrollo de una aplicación web completa*.

Por último, ten en cuenta que son muy pocos los desarrollos que, en la actualidad, se hacen directamente con Javascript clásico en el lado del cliente. Lo más habitual es utilizar librerías más o menos simples, o incluso completísimos frameworks, que ocultan el Javascript que existe debajo. Algunas de las librerías más populares son: **Prototype, jQuery, Angular, Vue.js o React**.

### 2.2.5. PHP

![Logo de PHP](/assets/images/02-logo-php.jpg)

**PHP** es un acrónimo recursivo. Significa ***“PHP Hypertext Preprocessor”***.

Sí, así es el sentido del humor de los informáticos. Qué le vamos a hacer.

PHP es un lenguaje de programación de propósito general. De hecho, junto con librerías como PHP-Qt o PHP-GTK, puedes programar con él cualquier aplicación de escritorio con sus ventanitas, sus botoncitos y toda la pesca.

Pero, por circunstancias más debidas al azar que a otra cosa, se empezó a usar para desarrollo web al comienzo de la web 2.0, y hoy en día se utiliza casi exclusivamente para ese propósito. Que es el propósito que a nosotros nos interesa, claro.

Cuando se usa en desarrollo web, PHP aparece embebido dentro de documentos HTML. Enseguida veremos cómo se hace eso.

Igual que sucedía con Javascript, pocos proyectos nuevos se desarrollan con PHP clásico. Lo normal es usar un framework (o colección compleja de librerías) que ocultan en todo o en parte el funcionamiento de PHP, que sigue corriendo debajo. Por supuesto, cualquier desarrollador/a web debe conocer tanto PHP como el funcionamiento de los frameworks que corren sobre PHP.

Nosotros nos centraremos primero en PHP clásico, y más adelante veremos los frameworks para PHP, centrándonos en uno de los más populares y potentes que existen en la actualidad: **Laravel**.

#### Características de PHP

* PHP permite conectarse con múltiples bases de datos: MySQL, MariaDB, Oracle, PostgreSQL, SQL Server, DB2, etc. También puede conectar por ODBC.
* Se parece mucho a otros lenguajes de tercera generación y orientados a objeto (en particular a C/C++ y, por tanto, a Java). Su curva de aprendizaje para los que ya saben programar es muy plana.
* Es un lenguaje con tipado dinámico y débil. Es decir, los tipos de datos se asignan en tiempo de ejecución y pueden mezclarse tipos de datos con bastante libertad. Esto tiene ventajas e inconvenientes que descubrirás en tus carnes cuando empieces a programar con PHP.
* Es un lenguaje orientado a objetos, pero conserva todas las características de los lenguajes estructurados, es decir: se puede programar sin recurrir a los objetos. Un punto a su favor para nostálgicos, aunque lo recomendable es programar con objetos *siempre*.
* Es un lenguaje tremendamente flexible. Casi todo se puede hacer de tres o cuatro formas diferentes. Eso le permite adaptarse a los gustos personales de cada programador/a.

#### Brevísima historia de PHP

* Surge en 1995 como extensión de CGI (otro lenguaje para acceso a funciones del servidor)
* PHP3 (1998) tuvo un gran éxito comercial.
* PHP4 (2000) es la versión más extendida (por desgracia): la mayoría de los scripts en PHP que circulan por la red están escritos en esta versión obsoleta.
* PHP5 (2004) tiene soporte para orientación a objetos y una biblioteca de clases bastante bien diseñada. Por lo tanto, desde esta versión PHP pasa de ser un lenguaje estructurado (3GL) a ser un lenguaje orientado a objetos.
* PHP6 empezó a desarrollarse en 2007 y se canceló en 2014.
* PHP7 introdujo novedades menores y estuvo vigente hasta 2020. En el momento de escribi esto (junio de 2021) es la versión dominante en la mayoría de los servidores web.
* PHP8 es la última versión (8.0.7 en junio de 2021). Las versiones PHP4 y PHP5 se consideran obsoletas e inseguras, aunque muchas aplicaciones existentes aún las utilicen. Sigue habiendo soporte para PHP7, pero todas las nuevas aplicaciones se deberían escribir pensando en PHP8.

#### Lo nuevo en PHP8

PHP8 no tiene demasiadas novedades con respecto a PHP7, como este no las tenía con respecto a PHP5.

Debes tener en cuenta que el mayor salto evolutivo se produjo entre PHP 4 y PHP 5. A partir de ahí, y para principiantes como nosotros, la cosa no ha cambiado demasiado.

Algunas de las novedades más destacables de PHP8 son de este calibre:

* Mejoras importantes de rendimiento, con la aparición de JIT (Just in Time Compiler), un compilador de PHP que trabaja de forma transparente al programador para incrementar la velocidad de ejecución.
* Mejoras menores en el manejo de las clases y métodos abstractos.
* Simplificación en la declaración de atributos.
* Posibilidad de usar arrays con índices negativos.

Como ves, nada que vaya a revolucionar la forma de trabajar con PHP.

#### Ventajas de PHP sobre otros lenguajes

PHP es el líder indiscutible en el desarrollo de aplicaciones web del lado del servidor. Hace años (¡muchos!) que algunos se empeñan en decir que está muerto o que está destinado a desaparecer, pero sigue ahí, obstinadamente en el número uno.

Por algo será.

Algunas de las ventajas que han hecho de PHP el líder de los lenguajes del lado del servidor durante tanto tiempo son:

* Es un lenguaje libre y abierto.
* Es muy eficiente (comparado con otros lenguajes del lado del servidor).
* Es ejecutable en (casi) cualquier servidor.
* Cuenta con una excelente documentación y miles de foros y sitios donde consultar dudas.
* La curva de aprendizaje es baja si ya sabes programar.
* Existen mogollón de entornos de desarrollo para PHP, para todos los gustos.
* Ofrece fácil interoperatibilidad con otros sistemas, en particular con bases de datos.
* Comunidad muuuy grande.
* Su sintaxis, estabilidad y seguridad han mejorado enormemente desde los tiempos algo caóticos de PHP4.

#### Inconvenientes de PHP

PHP también presenta algunos inconvenientes, por supuesto. No hay nada perfecto. Entre ellos, podemos destacar:

* Fallos de diseño (corregidos en su mayoría a partir de PHP5), como:
   * Los métodos para acceso a bases de datos cambian según el SGBD usado.
   * Nombres de funciones inconsistentes.
   * No es completamente orientado a objetos.
   * Tipado confuso y, a veces, impredecible.
* Grandes (e incompatibles) cambios entre versiones.
* Pérdida lenta pero constante de cuota de mercado.
* Pésima relación señal/ruido en la web: ¡hay demasiados *malos* desarrolladores en PHP!

### 2.2.6. MariaDB

![Logo de MariaDB](/assets/images/02-logo-mariadb.jpg)

Otra de las herramientas básicas de nuestra caja de herramientas es el **gestor de bases de datos relacionales** (SGBD).

**MariaDB** es el SGBD líder del mercado de las aplicaciones web. Nos permitirá conectarnos a una base de datos en red y ejecutar sentencias SQL de forma remota al visitar una aplicación web.

Existen otras posibilidades, desde luego. Entre las más populares están:

* MySQL
* SQL Server
* Oracle
* PostgreSQL
* SQLite

También está la posibilidad de usar base de datos no relacionales, como *MongoDB*, *Cassandra* o *Redis*. PHP puede conectarse también a estos sistemas, pero la forma de trabajar es diferente que con bases de datos relacionales. Como estas últimas son, de lejos, las predominantes en el mercado, nos centraremos en ellas.

A partir de ahora, cuando hablemos de bases de datos, siempre nos estaremos refiriendo a MariaDB o MySQL indistintamente (ya que, en la práctica, son indistinguibles para el desarrollador), pero cualquier otra base de datos relacional puede usarse del mismo modo con mínimos cambios en el código fuente.

#### Características de MariaDB

* MariaDB es un gestor de bases de datos relacional multiusuario y multiplataforma.
* Permite mútiples conexiones remotas.
* Es software libre.
* Existen librerías para acceder a MariaDB desde muchos lenguajes: C/C++, Java, PHP, Perl, Pascal... Además, hay drivers ODBC.
* Está muy extendida en aplicaciones web, generalmente en combinación con PHP.
* Cuenta un interfaz gráfico programado en PHP, llamado PHPMyAdmin, que se ejecuta en el navegador web. Por supuesto, se puede usar cualquier otro cliente compatible con MySQL, como MySQL Workbench.

#### Brevísima historia de MariaDB

* MySQL surgió como un proyecto OpenSource en Suecia en 1995.
* El objetivo era lograr un SGBD rápido y fiable que cumpliera con el estándar SQL.
* Las primeras versiones (que se denominaron mSQL) eran muy ineficientes.
* La popularización de PHP y su ganancia en eficiencia a partir de la versión 3 la han hecho muy popular en la actualidad.
* Tras su adquisición por Oracle, se intentó relegar al segmento medio-bajo en el mercado de los SGBD y surgió un fork: MariaDB (traducción para los recién llegados: "fork" significa "proyecto nuevo surgido a partir de otro proyecto ya existente").
* La versión más reciente (actualizado en junio de 2021) es MariaDB 10.5.10

