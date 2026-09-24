---
layout: page
title: 3.10 Sesiones, autenticación y middlewares
permalink: /laravel/sesiones-autenticacion.html
parent: 3 Aplicaciones SSR con Laravel
grand_parent: Desarrollo Web en Entorno Servidor
nav_order: 10
has_children: false
---

Aquí concentraría tu actual 3.13.

Pero reduciría muchísimo la parte de autenticación.

Contenidos
Qué es una sesión.
Persistencia de datos entre peticiones.
Middleware.
Autenticación.
Usuario autenticado.
auth.
Protección de rutas.
Diferencia entre autenticación y autorización.

Y algo muy importante:

No enseñaría Laravel Breeze como contenido del tema.

La documentación actual de Laravel ya no plantea Breeze como el camino para nuevos proyectos, y los Starter Kits actuales han cambiado.

Para segundo de DAW me parece más interesante que sepan:

Route::middleware('auth')->group(function () {
    ...
});

que dedicar tres clases a montar un sistema de login.

Si quieres mostrar autenticación, puedes hacerlo mediante un Starter Kit actual y explicar qué ha generado Laravel, pero sin convertir el sistema de autenticación en el objetivo del tema.