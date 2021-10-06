---
layout: page
title: 3.3. Sesiones, cookies y control de acceso
permalink: /cookies-sesiones-seguridad/control-de-acceso.html
nav_order: 1
has_children: false
parent: 3 Cookies, sesiones y seguridad
grand_parent: Desarrollo Web en Entorno Servidor
---

## 3.3. Control de acceso a las aplicaciones web
{: .no_toc }

*Cookies* y variables de sesión se usan a menudo, por separado o de forma combinada, para controlar el acceso a una aplicación web. Es decir, para hacer el *login*.

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
