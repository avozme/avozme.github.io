---
layout: page
title: 3.5 Formularios y validación
permalink: /laravel/formularios.html
parent: 3 Aplicaciones SSR con Laravel
grand_parent: Desarrollo Web en Entorno Servidor
nav_order: 5
has_children: false
---

Contenidos
Formularios HTML.
GET / POST.
Request.
Obtener datos enviados.
Validación.
Reglas de validación.
Mensajes de error.
Redirección después de un error.
CSRF.
Métodos HTTP PUT, PATCH y DELETE mediante formularios.

Por ejemplo:

$request->validate([
    'nombre' => 'required|max:100',
    'precio' => 'required|numeric|min:0',
]);
Práctica

Crear y validar un producto.

Todavía podemos guardar los datos temporalmente en memoria.

Esto produce una primera aplicación interactiva bastante antes de llegar a Eloquent.