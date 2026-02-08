---
layout: page
title: 5 Intertia.js
permalink: /inertia/
parent: None
nav_order: 5
---
# 5. Inertia.js
{: .no_toc }

- TOC
{:toc}

## 5.1. ¿Cómo funciona Inertia?

Tradicionalmente, para usar Vue con Laravel tenías dos opciones:
1. **Blade con Vue**: Usar Vue solo para pequeños componentes dentro de páginas Blade.
2. **SPA Separada**: Crear una API REST en Laravel y un proyecto Vue independiente que la consuma.

**Inertia.js elimina esta dicotomía**. Permite crear una SPA real, pero escribiendo el código como si fuera una aplicación clásica de Laravel. Los controladores devuelven componentes de Vue en lugar de vistas de Blade, e Inertia se encarga de que la transición entre páginas sea instantánea sin recargar el navegador.

### 5.1.1. El protocolo Inertia
Cuando haces clic en un enlace de Inertia, sucede lo siguiente:
1. Inertia intercepta el clic y hace una petición **XHR** al servidor.
2. El servidor detecta que es una petición de Inertia y, en lugar de devolver HTML completo, devuelve un objeto **JSON** con los datos (*props*) y el nombre del componente de Vue.
3. El frontend recibe el JSON y sustituye el componente actual por el nuevo, manteniendo el estado global de la aplicación.

## 5.2. Instalación y configuración básica

### 5.2.1. Lado del Servidor (Laravel)
En tu proyecto Laravel, instala el adaptador de Inertia:

```bash
composer require inertiajs/inertia-laravel
```

Luego, debes configurar el middleware en `bootstrap/app.php` (en Laravel 11/12):

```php
->withMiddleware(function (Middleware $middleware) {
    $middleware->web(append: [
        \App\Http\Middleware\HandleInertiaRequests::class,
    ]);
})
```

### 5.2.2. Lado del Cliente (Vue)
Instala las dependencias de frontend:

```bash
npm install @inertiajs/vue3 vue
```

Configura tu archivo `resources/js/app.js` para arrancar la aplicación Inertia:

```javascript
import { createApp, h } from 'vue'
import { createInertiaApp } from '@inertiajs/vue3'

createInertiaApp({
  resolve: name => {
    const pages = import.meta.glob('./Pages/**/*.vue', { eager: true })
    return pages[`./Pages/${name}.vue`]
  },
  setup({ el, App, props, plugin }) {
    createApp({ render: () => h(App, props) })
      .use(plugin)
      .mount(el)
  },
})
```

## 5.3. Creando tu primera página

### El Controlador
En Laravel, en lugar de usar `view()`, usas `Inertia::render()`:

```php
use Inertia\Inertia;

public function index()
{
    return Inertia::render('Eventos/Index', [
        'eventos' => Evento::all()
    ]);
}
```

### El Componente Vue (`resources/js/Pages/Eventos/Index.vue`)
El componente recibe los datos directamente como *props*:

```vue
<script setup>
defineProps({ eventos: Array })
</script>

<template>
  <h1>Lista de Eventos</h1>
  <ul>
    <li v-for="evento in eventos" :key="evento.id">
      {{ evento.nombre }}
    </li>
  </ul>
</template>
```

## 5.4. Navegación con `<Link>`

Para que la navegación sea instantánea y no recargue la página, **nunca** uses etiquetas `<a>` de HTML. Usa el componente `<Link>` de Inertia:

```vue
<script setup>
import { Link } from '@inertiajs/vue3'
</script>

<template>
  <Link href="/usuarios">Ver Usuarios</Link>
</template>
```

Inertia se encarga de que esta navegación sea una petición AJAX por debajo, actualizando solo el contenido necesario.

## 5.5. Ventajas de usar Inertia
* **No necesitas una API**: Te ahorras el desarrollo de rutas API, controladores API y autenticación mediante tokens (como Sanctum), ya que usas la sesión estándar de Laravel.
* **Productividad**: Desarrollas mucho más rápido al no tener que gestionar dos proyectos por separado.
* **SEO & SSR**: Inertia soporta Server-Side Rendering de forma nativa si lo necesitas.
* **Experiencia de usuario**: La navegación es fluida, como en una SPA profesional, pero con la robustez de un backend clásico.
