# Unidad 4. Vue.js

## 1. Introducción a Vue.js

Vue.js es un **framework JavaScript progresivo** diseñado para construir interfaces de usuario modernas y dinámicas. Se centra en la creación de **Single Page Applications (SPA)**, es decir, aplicaciones web que cargan una única página HTML y actualizan su contenido de forma dinámica sin necesidad de recargar todo el sitio cada vez que el usuario realiza una acción.

### Ventajas principales

- **Evita recargar la página completa** con cada petición al servidor.
- **Permite crear componentes reutilizables**, lo que hace el desarrollo más limpio y modular.
- **Incluye enrutamiento en cliente**, lo que mejora la experiencia del usuario al navegar sin interrupciones.
- **Se integra fácilmente con Laravel**, ya que este framework lo incluye preinstalado.
- Es **open source** y cuenta con una comunidad muy activa.

### Otros frameworks similares

- **Angular** (Google, desde 2010)
- **React** (Facebook/Meta, desde 2013)
- **Vue.js** (open source, desde 2014)
- **Svelte** (open source, desde 2016)

---

## 1.2. Cómo se usa Vue.js

Vue.js se puede utilizar de tres formas diferentes, según lo que necesites construir:

### 🧩 Opción 1: Como una librería JavaScript más
Puedes incluir Vue directamente desde un **CDN** dentro de un archivo HTML. Es la manera más simple de empezar a experimentar.

```html
<script src="https://unpkg.com/vue@3/dist/vue.global.js"></script>
```

Ideal para probar ejemplos pequeños o hacer prototipos rápidos.  
**Limitaciones:** no podrás usar `import/export`, ni archivos `.vue`, ni el compilador `vite`. Tampoco es escalable.

### ⚙️ Opción 2: Con npm para proyectos frontend
Instalando Node.js y npm, puedes crear proyectos Vue completos con toda su potencia: componentes, build tools, dependencias, etc.

### 🧱 Opción 3: Integrado en Laravel
Si ya usas Laravel, puedes trabajar con Vue directamente dentro del proyecto. Así tienes un desarrollo **full stack** (backend con Laravel + frontend con Vue) todo en el mismo entorno.

---

## 2. Vue.js como librería JavaScript

La forma más sencilla de empezar con Vue es usarlo como una librería directamente en tu HTML.

```html
<!DOCTYPE html>
<html lang="es">
<head>
  <meta charset="UTF-8">
  <title>Probando Vue.js</title>
  <script src="https://unpkg.com/vue@3/dist/vue.global.js"></script>
</head>
<body>
  <div id="app"></div>
  <script>
    const { createApp } = Vue;
    const app = createApp({ /* Código Vue aquí */ });
    app.mount('#app');
  </script>
</body>
</html>
```

Esto te permitirá experimentar con la sintaxis de Vue y entender su reactividad.  
Sin embargo, esta modalidad **no es recomendable para proyectos grandes**.

---

### Ejemplos básicos

**Ejemplo 1 – Hola mundo**

```html
<div id="app">{{ message }}</div>

<script src="https://unpkg.com/vue@3/dist/vue.global.js"></script>
<script>
const { createApp } = Vue;
createApp({
  data() { return { message: 'Hola mundo' }; }
}).mount('#app');
</script>
```

**Ejemplo 2 – Pregunta y respuesta**

```html
<div id="app">
  <p>La pregunta es: {{ pregunta }}</p>
  <p>La respuesta es: {{ respuesta }}</p>
</div>

<script src="https://unpkg.com/vue@3/dist/vue.global.js"></script>
<script>
const { createApp } = Vue;
createApp({
  data() {
    return {
      pregunta: '¿Cómo te llamas?',
      respuesta: 'Pepito Pérez'
    }
  }
}).mount('#app');
</script>
```

**Ejemplo 3 – Condicional simple**
```html
<p v-if="visible">Ahora puedes verme</p>
```

**Ejemplo 4 – Bucle**
```html
<p v-for="animal in animales">{{ animal }}</p>
```

**Ejemplo 5 – Formulario**
```html
<input v-model="nombre" placeholder="Tu nombre">
<p>Tu nombre es: {{ nombre }}</p>
```

**Ejemplo 6 – Evento click**
```html
<button @click="saludar">Púlsame</button>
```

**Ejemplo 8 – Componente “Hola mundo”**
```html
app.component('hola-mundo', {
  template: '<div>¡Hola mundo!</div>'
});
```

Más ejemplos completos en [github.com/avozme/vue-examples](https://github.com/avozme/vue-examples).

---

## 3. Vue.js con npm para aplicaciones frontend

Cuando quieres desarrollar una SPA completa, Vue se usa junto con **npm** y herramientas modernas de compilación como **Vite**.

### Arquitectura típica
El frontend de Vue suele conectarse con un backend (por ejemplo Laravel) mediante **API REST** usando `fetch()` o `axios`.

Ejemplo de estructura básica:

```
src/
├─ main.js
├─ App.vue
└─ components/
   ├─ DataTable.vue
   ├─ ProductosList.vue
   ├─ ClientesList.vue
   └─ ComprasList.vue
```

---

### Crear un nuevo proyecto Vue

1. Instala Node.js (versión 20 o superior).
2. Crea el proyecto:
   ```bash
   npm create vue@latest
   ```
3. Ejecuta el servidor de desarrollo:
   ```bash
   npm run dev
   ```
4. Por defecto se abre en `http://localhost:5173`.

---

### Desplegar en producción

Cuando termines el desarrollo:

```bash
npm run build
```
Los archivos optimizados se guardan en `/dist`.  
Puedes copiarlos a `/public` en tu proyecto Laravel para que el backend y el frontend se sirvan desde el mismo servidor.

---

## 4. Vue.js con Laravel para aplicaciones full stack

Hay dos formas de combinar Laravel y Vue:

1. **Frontend separado:** Vue consume una API REST creada con Laravel.  
   Ideal si quieres mantener independencia entre front y back.
2. **Integrado en Laravel:** Vue se ejecuta dentro del propio proyecto Laravel.  
   Perfecto si buscas un desarrollo full stack unificado.

### Instalación paso a paso

1. **Instala Vue y el plugin de Vite:**
   ```bash
   npm install vue @vitejs/plugin-vue
   ```
   (Si usas Sail: `./vendor/bin/sail npm install vue @vitejs/plugin-vue`)

2. **Edita `vite.config.js`:** añade los imports y activa Vue.
3. **Edita `resources/js/app.js`:**
   ```js
   import { createApp } from 'vue';
   import ExampleComponent from './components/ExampleComponent.vue';
   const app = createApp({});
   app.component('example-component', ExampleComponent);
   app.mount('#app');
   ```
4. **Inicia el servidor de desarrollo:**
   ```bash
   npm run dev
   ```

---

## 5. Ejemplo completo: CRUD con Vue.js y Laravel

Vamos a crear una aplicación CRUD completa (Create, Read, Update, Delete) para gestionar productos.

### Estructura de la tabla
```
Productos(id, nombre, descripcion, precio, stock)
```

### Pasos generales
1. Crear el proyecto Laravel.
2. Activar Vue dentro de Laravel.
3. Configurar la base de datos.
4. Crear modelos, migraciones y seeders.
5. Crear el controlador RESTful.
6. Añadir las rutas API.
7. Crear los componentes Vue.
8. Crear las vistas Blade.
9. Compilar y desplegar.

---

### Modelo y migración

```bash
php artisan make:model Producto -m
```

```php
Schema::create('productos', function (Blueprint $table) {
  $table->id();
  $table->string('nombre');
  $table->text('descripcion')->nullable();
  $table->decimal('precio', 8, 2);
  $table->integer('stock');
  $table->timestamps();
});
```

---

### Controlador RESTful

```bash
php artisan make:controller ProductoController --api
```

Ejemplo de métodos:
```php
public function index() {
    return response()->json(Producto::all(), 200);
}

public function store(Request $request) {
    $producto = Producto::create($request->all());
    return response()->json($producto, 201);
}
```

---

### Rutas API

```php
use App\Http\Controllers\ProductoController;
Route::apiResource('productos', ProductoController::class);
```

---

### Componente Vue: `Productos.vue`

```vue
<template>
  <div>
    <h2>Gestión de productos</h2>

    <input v-model="filtro" placeholder="Buscar producto">
    <ul>
      <li v-for="p in productosFiltrados" :key="p.id">
        {{ p.nombre }} - {{ p.precio }} € 
        <button @click="editar(p)">Editar</button>
        <button @click="borrar(p.id)">Eliminar</button>
      </li>
    </ul>

    <h3>{{ editando ? 'Editar producto' : 'Nuevo producto' }}</h3>
    <input v-model="form.nombre" placeholder="Nombre">
    <input v-model="form.descripcion" placeholder="Descripción">
    <input v-model="form.precio" type="number" placeholder="Precio">
    <input v-model="form.stock" type="number" placeholder="Stock">
    <button @click="guardar">Guardar</button>
  </div>
</template>

<script>
import axios from 'axios';
export default {
  data() {
    return {
      productos: [],
      form: { id: null, nombre: '', descripcion: '', precio: '', stock: '' },
      filtro: '',
      editando: false,
    };
  },
  computed: {
    productosFiltrados() {
      return this.productos.filter(p =>
        p.nombre.toLowerCase().includes(this.filtro.toLowerCase())
      );
    },
  },
  methods: {
    async cargarProductos() {
      const res = await axios.get('/api/productos');
      this.productos = res.data;
    },
    async guardar() {
      if (this.editando) await axios.put(`/api/productos/${this.form.id}`, this.form);
      else await axios.post('/api/productos', this.form);
      this.resetForm();
      this.cargarProductos();
    },
    editar(p) {
      this.form = { ...p };
      this.editando = true;
    },
    async borrar(id) {
      await axios.delete(`/api/productos/${id}`);
      this.cargarProductos();
    },
    resetForm() {
      this.form = { id: null, nombre: '', descripcion: '', precio: '', stock: '' };
      this.editando = false;
    }
  },
  mounted() { this.cargarProductos(); }
};
</script>
```

---

### Vista Blade

```html
<!DOCTYPE html>
<html lang="es">
<head>
  <meta charset="UTF-8">
  <title>Gestión de Productos</title>
  @vite('resources/js/app.js')
</head>
<body>
  <div id="app">
    <productos></productos>
  </div>
</body>
</html>
```

Finalmente, edita `routes/web.php`:

```php
Route::get('/', function () {
    return view('productos');
});
```

---

### Despliegue final

Durante el desarrollo:
```bash
npm run dev
```

Para el build final:
```bash
npm run build
```

El resultado se servirá desde `/public` junto con Laravel.  
Puedes consultar el ejemplo completo en GitHub:  
👉 [github.com/avozme/crud-laravel-vue](https://github.com/avozme/crud-laravel-vue)

---

**Fin de la unidad 4 – Vue.js**  
I.E.S. Celia Viñas (Almería) · Desarrollo Web Full Stack
