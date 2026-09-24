---
layout: page
title: 3.1 Frameworks MVC y Laravel
permalink: /laravel/frameworks-mvc-y-laravel.html
parent: 3 Aplicaciones SSR con Laravel
grand_parent: Desarrollo Web en Entorno Servidor
nav_order: 1
has_children: false
---

# 3.1. Frameworks MVC y Laravel
{: .no_toc }

- TOC
{:toc}

Un **framework** es un conjunto estandarizado de prácticas de programación, herramientas y componentes para resolver una serie de problemas habituales.

El framework proporciona una serie de **clases, librerías y otros componentes** para facilitar el desarrollo ágil, seguro y escalable de nuevas aplicaciones.

Por lo tanto, la idea clave es esta: *no inventar la rueda cada vez que la necesitamos*.

Un framework no es una aplicación terminada ni una librería concreta. Es una base sobre la que construimos nuestra aplicación y que establece una determinada forma de organizarla y de resolver problemas habituales.

## 3.1.1. ¿Realmente necesito un framework para desarrollar una aplicación web?

> **Los frameworks *nunca* son imprescindibles...**<br>
> **...pero *casi siempre* son muy convenientes.**

Podemos desarrollar una aplicación web directamente con PHP, sin utilizar ningún framework. Sin embargo, a medida que una aplicación crece aparecen una serie de problemas que tenemos que resolver una y otra vez:

- Organización del código y separación de responsabilidades.
- Gestión de las peticiones HTTP y las rutas.
- Generación de respuestas y vistas.
- Acceso a bases de datos.
- Validación de datos recibidos de los usuarios.
- Gestión de sesiones y autenticación.
- Protección frente a problemas de seguridad habituales.
- Configuración de la aplicación.
- Reutilización de código y mantenimiento.
- Pruebas y otras tareas habituales del desarrollo.

Un framework proporciona soluciones ya desarrolladas para muchos de estos problemas y establece una estructura común para nuestra aplicación.

**Hay programadores pro-frameworks y anti-frameworks**. Los programadores anti-frameworks acaban desarrollando, aposta o sin querer, su propio framework después de llevar varias aplicaciones MVC a sus espaldas.

Para decidir si necesitas un framework o no, tienes que conocer antes cómo funcionan y qué ventajas e inconvenientes presentan.

Usar un framework tiene ciertas **ventajas**, como:

* Reutilización del trabajo ya hecho (recuerda: no reinventar la rueda).

* Extensa documentación.

* Separación en capas.

* Seguimiento de buenas prácticas de programación.

* Escalabilidad y mantenimiento.

* Desarrollo más rápido y, por tanto, más económico.

Pero también tiene algunos **inconvenientes**:

* A veces pueden limitar el desarrollo.

* Curva de aprendizaje costosa (más en unos frameworks que en otros). Es decir: al principio iremos más lentos que sin framework, hasta que le cojamos el tranquillo.

* Puede llegar a implicar más trabajo, dependiendo del proyecto.

* Preferencias personales: algunos programadores solo se sienten cómodos si todo el código es suyo.

* Actualizaciones frecuentes. Una actualización importante de un framework puede obligarnos a adaptar parte de nuestra aplicación.

* Ocultan parte del funcionamiento de la aplicación: no son un sustituto del aprendizaje de PHP, HTTP, bases de datos o programación web.

Es decir, que la idea es que, al usar un framework, solo te centres en desarrollar lo importante. El resto (lo que ya estaba desarrollado en el framework y que es común a muchas aplicaciones web) no te quita tiempo.

## 3.1.2. La arquitectura MVC

MVC, como ya vimos en el tema anterior, son las siglas de **Model-View-Controller** (Modelo-Vista-Controlador). También vimos que se trata de un patrón de arquitectura utilizado para separar diferentes responsabilidades dentro de una aplicación.

La idea básica es separar:

* **Modelo**: representa los datos de la aplicación y la lógica relacionada con ellos.

* **Vista**: se encarga de presentar información al usuario.

* **Controlador**: recibe y procesa las peticiones, coordina el trabajo necesario y decide qué respuesta devolver.

MVC resulta especialmente útil cuando las aplicaciones crecen y necesitamos mantenerlas y modificarlas durante mucho tiempo.

*Debes tener muy claros estos conceptos porque vamos a trabajar con ellos continuamente durante todo el curso.*

## 3.1.3. ¿Qué framework escoger?

Existen multitud de frameworks PHP, aunque no todos utilizan exactamente la misma arquitectura ni ofrecen las mismas características.

Entre los frameworks PHP más conocidos se encuentran:

* **Laravel**: framework PHP orientado al desarrollo de aplicaciones web modernas, con una sintaxis expresiva y una gran cantidad de herramientas integradas.

* **Symfony**: framework PHP muy completo y modular, utilizado tanto para desarrollar aplicaciones completas como para proporcionar componentes reutilizables a otros proyectos.

* **CodeIgniter**: framework PHP ligero que apuesta por una estructura sencilla y una reducida cantidad de convenciones.

También existen o han existido otros frameworks PHP importantes, como **Yii, CakePHP** o **Zend Framework**. Este último fue sustituido por **Laminas** en 2019.

Lamentablemente, no hay respuesta a la pregunta: ¿qué framework es mejor?

Puedes pasar el resto de tu vida leyendo en foros y en blogs, descargando e instalando varios frameworks para desecharlos a los dos días, esperando a que salga una nueva versión o un framework nuevo...

Nunca podrás responder a esa pregunta de forma universal. Como mucho, podrás responder a esta otra: ¿qué framework prefiero? Y eso solo después de haber probado varios durante algún tiempo.

Además, el framework por sí solo puede no ser suficiente para un desarrollo completo, y probablemente harán falta otros componentes que afectarán a la experiencia de programación. Algunos ejemplos son:

* Librerías adicionales del lado del servidor.

* Librerías y frameworks del lado del cliente: Vue, React, Angular, etc.

* Herramientas para CSS y diseño de interfaces, como Bootstrap o Tailwind CSS.

No debemos confundir un framework de backend con un framework de frontend: pueden utilizarse conjuntamente para construir una aplicación web completa.

## 3.1.4. Laravel 13

**Laravel es un framework PHP para el desarrollo de aplicaciones web**. Está basado en una arquitectura que sigue principalmente el patrón MVC y proporciona herramientas para resolver muchos de los problemas habituales del desarrollo web.

Laravel nació en 2011 y desde entonces ha evolucionado hasta convertirse en el frameworks PHP más utilizado con diferencia en el mundo profesional.

Una de sus características más importantes es que intenta proporcionar una experiencia de desarrollo sencilla y coherente, ofreciendo soluciones integradas para tareas como el enrutamiento, las vistas, el acceso a bases de datos, la validación, las sesiones, la autenticación, las colas o las pruebas.

La versión que utilizaremos en este tema es **Laravel 13**. Laravel sigue un ciclo de versiones mayores anual y Laravel 13 fue publicada en marzo de 2026. Requiere PHP 8.3 o superior.

## 3.1.5. Características principales de Laravel

Para ir abriendo boca, te cuento algunos de los puntos fuertes que tiene Laravel:

1. **Sintaxis simple y expresiva.** Laravel intenta que el código sea fácil de leer y escribir. Por supuesto, si el programador que lo usa es un chapuzas, el código será una chapuza también.

2. **ORM Eloquent.** Permite trabajar con bases de datos mediante modelos y relaciones, evitando tener que escribir directamente muchas de las consultas SQL habituales. Ya veremos en qué consiste esto.

3. **Sistema de plantillas Blade.** Proporciona una forma sencilla y potente de crear vistas y reutilizar plantillas. También lo veremos con bastante profundidad.

4. **Enrutamiento y controladores.** Laravel proporciona un sistema completo para asociar las peticiones HTTP con el código que debe procesarlas.

5. **Migraciones y seeders.** Permite definir y modificar la estructura de la base de datos mediante código, así como introducir datos iniciales o de prueba.

6. **Validación de datos.** Proporciona herramientas para comprobar los datos recibidos en las peticiones antes de procesarlos.

7. **Middleware.** Permite ejecutar código antes o después de determinadas peticiones y, entre otras cosas, controlar el acceso a determinadas partes de la aplicación.

8. **Artisan.** Es la consola de comandos de Laravel. Permite crear componentes, ejecutar migraciones, consultar información de la aplicación y realizar muchas otras tareas habituales.

9. **Ecosistema amplio.** Laravel dispone de numerosas herramientas y paquetes oficiales y de una comunidad muy activa.

10. **Desarrollo full-stack y desarrollo de APIs.** Laravel puede utilizarse para desarrollar una aplicación web completa, generando las vistas desde el servidor, o como backend que proporciona una API a una aplicación frontend desarrollada con tecnologías como Vue, React o Svelte.

## 3.1.6. Convención frente a configuración

Una de las ideas habituales en los frameworks modernos es **"Convention over Configuration"**, es decir, **convención sobre configuración**.

La idea es sencilla: si seguimos unas convenciones conocidas, el framework puede deducir muchas cosas sin que tengamos que configurarlas explícitamente ni comunicárselas de ningún modo. Y eso ahora *un montón* de trabajo y de problemas.

Pongamos un ejemplo para que se entienda mejor. 

Imagina que tenemos una tabla en la base de datos llamada `products`. La **convención** de Laravel es que el modelo para esa tabla se debe llamar `Product`, con mayúscula inicial y en singular, y el controlador debe llamarse `ProductController`.

Si respetas esas convenciones, Laravel conectará todos los elementos automáticamente. Pero si llamas a tu tabla `productos`, a tu modelo `ProductoModel` y a tu controlador `ControladorDePepito`, no encontrará nada y tendrás que decirle dónde está cada cosa y cómo interaccionan entre sí.

*Eso es "convención frente a configuración"*.

Laravel tiene un montón de convenciones para muchísimas cosas: nombres de clases, tablas, columnas, rutas, modelos y otros elementos de la aplicación. Esto permite escribir menos configuración y hace que un programador familiarizado con Laravel pueda orientarse rápidamente dentro de un proyecto.

## 3.1.7. Laravel como framework full-stack

Laravel puede utilizarse como un **framework full-stack**, es decir, como la base para desarrollar tanto el backend como la parte de presentación de una aplicación web. **Esto es lo que aprenderemos a hacer en este tema**.

En este modelo, Laravel recibe las peticiones HTTP, ejecuta la lógica de la aplicación, accede a la base de datos y genera las respuestas HTML que recibe el navegador. 

En este caso podemos utilizar **Blade** para generar HTML desde el servidor. Para aplicaciones que necesitan una interfaz más dinámica, Laravel también puede combinarse con tecnologías como **Livewire** o **Inertia**, que escapan a nuestros propósitos.

Además, Laravel utiliza **Vite** para gestionar y compilar los recursos del frontend, como CSS y JavaScript.

Por tanto, no debemos pensar que Laravel es solamente una herramienta para acceder a una base de datos desde PHP. Puede encargarse de buena parte del ciclo completo de una aplicación web.

## 3.1.8. Laravel como backend para aplicaciones frontend

Laravel también puede utilizarse únicamente como **backend** de una aplicación cuyo frontend se desarrolla con JavaScript. En este caso, Laravel solo proporciona los datos solicitados por el frontend, y es el frontend el que se encarga de la visualización.

**Veremos cómo se usa Laravel de este modo en el tema siguiente**.

En esta forma de funcionamiento, el backend se ocupa principalmente de la lógica de negocio (es decir, la lógica de manejo de los datos), el acceso a los datos, la validación, la autenticación y la exposición de la API, mientras que Vue, React, Svelte u otra tecnología frontend se ocupa de construir la interfaz que utiliza el usuario.

## 3.1.9. ¿Y por qué Laravel?

**No vamos a estudiar Laravel porque sea "el mejor framework PHP"**. Como hemos visto, eso *no existe*.

Lo estudiaremos porque ofrece una combinación especialmente interesante para aprender desarrollo web en PHP: una sintaxis relativamente sencilla, una documentación extensa, muchas herramientas integradas y una arquitectura que nos permite abordar desde aplicaciones web tradicionales hasta APIs para aplicaciones frontend.

Y, sobre todo, porque es el framework PHP más usado en el lado del servidor en la actualidad.
