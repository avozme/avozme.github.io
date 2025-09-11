---
layout: page
title: 3 Cookies, sesiones y seguridad
permalink: /cookies-sesiones-seguridad/
nav_order: 3
has_children: true
parent: Desarrollo Web en Entorno Servidor
---
# 3. Cookies, sesiones y seguridad

{:toc}

En este capítulo vamos a profundizar en varios aspectos de PHP de vital importancia para las aplicaciones web.

Por un lado, tenemos las ***cookies*** y las **sesiones**, dos mecanismos que permiten a la aplicación mantener vivas algunas variables de forma indefinida.

Después estudiaremos un problema endémico a las aplicaciones web: la **seguridad**. En efecto, al tratarse de aplicaciones que, por definición, están permanentemente conectadas a la red, son susceptibles de recibir ataques de manera continua e indiscriminada. Y, de hecho, lo hacen. Veremos cuáles son los tipos de ataque más frecuente y cómo podemos proteger nuestra aplicación contra ellos, algo en lo que juegan un papel importante las *cookies* y las variables de sesión.

Por último, nos centraremos en algo muy relacionado con la seguridad: la autenticación de usuarios para acceder a la aplicación. La mayor parte de las aplicaciones web necesitan un mecanismo seguro de autenticación. Veremos en qué consisten las **listas de control de acceso** y plantearemos una implementación muy completa en la que pondremos en práctica todo lo que hemos aprendido hasta ahora e incluso iremos un paso más allá al introducir la arquitectura MVC, que veremos en el siguiente tema.







