---
layout: page
title: 3.11 Query Builder y otras herramientas
permalink: /laravel/query-builder.html
parent: 3 Aplicaciones SSR con Laravel
grand_parent: Desarrollo Web en Entorno Servidor
nav_order: 11
has_children: false
---

Introducción breve a:
Query Builder.
SQL mediante Laravel.
Collections.
Helpers.
Route Model Binding.
Factories.
Paginación.
Storage.
etc.

Pero con una regla:

"Lo conocemos, no necesariamente lo dominamos."

Por ejemplo, enseñar:

Product::where('price', '>', 100)->get();

frente a:

DB::table('products')
    ->where('price', '>', 100)
    ->get();

y explicar cuándo puede resultar útil Query Builder.