---
layout: page
title: 3.7 Eloquent ORM
permalink: /laravel/eloquent.html
parent: 3 Aplicaciones SSR con Laravel
grand_parent: Desarrollo Web en Entorno Servidor
nav_order: 7
has_children: false
---

Contenidos
Consultar.
Buscar.
Insertar.
Modificar.
Eliminar.
find().
findOrFail().
where().
first().
get().
create().
update().
delete().

Y muy especialmente:

Relaciones
1:1
1:N
N:N

Por ejemplo:

Curso
  │
  └── tiene muchos alumnos

y posteriormente:

Alumno
  │
  └── pertenece a muchos cursos

No intentaría cubrir veinte métodos de Eloquent. El objetivo es que sepan leer y escribir las consultas habituales.