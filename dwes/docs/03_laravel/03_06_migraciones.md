---
layout: page
title: 3.6 La base de datos. Migraciones, seeders y modelos
permalink: /laravel/migraciones-modelos.html
parent: 3 Aplicaciones SSR con Laravel
grand_parent: Desarrollo Web en Entorno Servidor
nav_order: 6
has_children: false
---

Juntaría tus actuales:

3.10 Migraciones
parte de 3.11 Eloquent
parte de 3.15
Contenidos
Configuración de la base de datos.
.env.
Migraciones.
Crear tablas.
Modificar tablas.
Rollback.
Seeders.
Factories, aunque sea muy brevemente.
Modelos Eloquent.
Convenciones de nombres.

Ejemplo:

php artisan make:model Product -m

y:

php artisan migrate

Aquí también introduciría claramente la relación:

tabla ↔ modelo Eloquent