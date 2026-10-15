---
layout: page
title: 7 Consumo de APIs y frontend reactivo para SPA
permalink: /servicios-web/
parent: Desarrollo Web en Entorno Servidor
nav_order: 7
---
# 7. Consumo de APIs y frontend reactivo para SPA
{: .no_toc }

- TOC
{:toc}

[Descargar presentación](https://www.dropbox.com/scl/fi/1yagmh6bgjc02xg6blwnq/07_consumo_api_vue.pdf?rlkey=qvogcai2dwj1pm5pb77k8f7qx&st=muywgnfy&dl=0){: .btn .btn-primary }


## 7.1. ¿Qué es Vue.js y por qué usarlo?

### 7.1.1. Aplicaciones SSR vs aplicaciones SPA

Hasta ahora, en asignaturas anteriores o en los primeros temas de este módulo, hemos construido aplicaciones web tradicionales utilizando **SSR (Server-Side Rendering)** con herramientas como Blade en Laravel. En ese modelo, cada vez que el usuario hace clic en un enlace o envía un formulario, el servidor (PHP) procesa la petición, genera una página HTML completa desde cero y se la envía al navegador. Esto obliga al navegador a recargar la página entera constantemente.

También hemos aprendido a construir **APIs** (de tipo REST o de cualquier otro tipo) que no generan vistas, sino datos que deben ser consumidos por otro programa (como Postman) o por otro servicio (como hacen los microservicios de FastAPI).

**Vue.js** es un **framework progresivo de Javascript** que nos permite consumir servicios para crear aplicaciones web completas de tipo **SPA (*Single Page Applications*)**.

En una SPA, a diferencia de las SSR, **el navegador carga una única página HTML**. A partir de ahí, es el código Javascript (en este caso, controlado por Vue.js) el que se encarga de actualizar dinámicamente el contenido de ese documento ya cargado en el navegador.

Así, cuando necesitamos leer o guardar datos en la base de datos, Javascript se comunica con nuestro servidor (nuestra API REST) en segundo plano, recibe los datos en formato JSON y actualiza solo las partes necesarias de la pantalla, sin que la página parpadee ni se recargue por completo.

Esto no solo **disminuye la latencia** (el tiempo de espera entre que el usuario hace algo y que la web responde), sino que también **mejora la experiencia del usuario**, que encuentra una aplicación mucho más interactiva. Como contrapartida, introduce una mayor complejidad en el desarrollo.

*Es decir, que podríamos decir que las aplicaciones SPA son «buenas» para el usuario y «malas» para el programador.*

Puesto que ya conoces Javascript, Typescript y has trasteado con Angular o React, los conceptos básicos te resultarán muy familiares. Vue ofrece las mismas ventajas (componentes, reactividad, enlace de datos) pero con una curva de aprendizaje que muchos desarrolladores consideran más amable.

### 7.1.2. Crear un proyecto Vue.js con Vite

Antiguamente, era común importar Vue simplemente añadiendo una etiqueta `<script>` en un archivo HTML (usando un CDN) o empaquetarlo dentro del propio proyecto de Laravel con herramientas antiguas.

Hoy en día, **muchos proyectos separan completamente el código del *frontend* del *backend***. Son dos proyectos distintos, desarrollados por equipos distintos, que correrán en puertos o incluso máquinas distintas.

Para **crear un proyecto frontend profesional con Vue**, el estándar actual de la industria es utilizar **Vite**, una herramienta de construcción ultrarrápida. Para crear tu proyecto, solo tienes que abrir tu terminal en una carpeta nueva (fuera de tu proyecto Laravel) y ejecutar:

```bash
$ npm create vue@latest
```

(Lógicamente, necesitas tener instalado `npm`, el compilador de *Node.js*)

El asistente te hará varias preguntas (puedes decirle que "Sí" a Vue Router si tu app tendrá varias pantallas, y que "No" a cosas más avanzadas como Pinia o Testing por ahora). Una vez creado el proyecto, debes entrar en la carpeta, instalar las dependencias e iniciar el servidor de desarrollo:

```bash
$ cd nombre-de-tu-proyecto
$ npm install   # Instala dependencias
$ npm run dev   # Lanza servidor de desarrollo (susa npm run build para versión definitiva)
```

Esto levantará un servidor de desarrollo local (generalmente en `http://localhost:5173`) donde podrás ver tu aplicación Vue funcionando. Los cambios que hagas se reflejarán inmediatamente en el resultado mientras `npm run dev` esté funcionando.

Para generar una versión definitiva de la aplicación, ejecuta `$ npm run build` y los archivos compilados se generarán en la carpeta `/dist`.

## 7.2. Conceptos básicos: reactividad y componentes (SFC)

En un proyecto Vue moderno, no trabajamos con archivos `.html` sueltos. Trabajamos con **Single-File Components (SFC)**. Esto significa que cada pieza de nuestra interfaz (un botón, un formulario de login, una barra de navegación) se guarda en un archivo con extensión `.vue`.

Un archivo `.vue` agrupa en un mismo lugar las tres tecnologías de la web: HTML, Javascript y CSS. Tiene esta estructura:

1. `<template>`: Aquí va el código HTML.
2. `<script setup>`: Aquí va la lógica en Javascript (o Typescript).
3. `<style scoped>`: Aquí van los estilos CSS que se aplicarán *solo* a este componente.

### 7.2.1. Reactividad con la Composition API

El concepto más importante de Vue es la **Reactividad**. En Javascript tradicional, si cambias el valor de una variable, tienes que buscar manualmente el elemento en el HTML (con `document.getElementById`) y actualizar su texto. 

**En Vue se declaran variables reactivas**. Si el valor de esa variable cambia en Javascript, *Vue se da cuenta automáticamente y actualiza el HTML donde esa variable esté siendo usada*. 

Para hacer esto, utilizamos la **Composition API**, que es el estándar en Vue 3. Simplemente importamos la función `ref` y envolvemos nuestros datos con ella.

Fíjate en este ejemplo sencillo de un archivo `Contador.vue`:

```html
<template>
  <div class="caja-contador">
    <!-- Usamos dobles llaves para mostrar la variable de Vue reactiva -->
    <h2>El contador vale: {{ contador }}</h2>
    
    <!-- Al hacer click, llamamos a la función incrementar -->
    <button @click="incrementar">Sumar uno</button>
  </div>
</template>

<script setup>
import { ref } from 'vue';

// Al usar ref(), convertimos un simple 0 en una variable reactiva
const contador = ref(0);

const incrementar = () => {
  // ATENCIÓN: En Javascript, para modificar el valor de una variable ref, 
  // SIEMPRE debemos acceder a la propiedad .value
  contador.value = contador.value + 1;
};
</script>

<style scoped>
.caja-contador {
  border: 1px solid blue;
  padding: 20px;
}
</style>
```

Observa que:

* En el `<template>` está el código HTML. Podemos usar la variable Vue directamente escribiendo `{{ contador }}`.
* En el `<script setup>` está el código Javascript o Typescript. Ahí se define `contador` es un objeto reactivo creado con `ref()` y se crea el método `incrementar()` que suma 1 al contador.
* Fíjate en que, para leer o modificar el valor de una variable reactiva, tienes que escribir `nombre_variable.value`.

### 7.2.2. Directivas esenciales de Vue

Las **directivas** son **atributos especiales que añadimos a las etiquetas HTML** para dotarlas de lógica. 

Las directivas de Vue empiezan siempre por `v-`. Si ya conoces Angular (donde se usan directivas como `*ngIf`, `*ngFor`), esto te resultará familiar.

**1. Atributos dinámicos (`v-bind` o `:`):**
Si quieres que el atributo de una etiqueta HTML (como un `src`, un `href` o una `class`) tome su valor de una variable de Javascript, no uses llaves dobles, sino que debes escribir `:` delante del atributo.

```html
<img :src="urlDeLaImagen" :alt="textoAlternativo">
<a :href="enlaceDinamico">Haz clic aquí</a>
```

**2. Renderizado condicional (`v-if` y `v-else`):**
Permite mostrar u ocultar partes del HTML dependiendo de si una condición se cumple o no. Vue inserta o elimina físicamente los elementos del DOM.

```html
<p v-if="usuarioLogueado">¡Hola, bienvenido de nuevo!</p>
<p v-else>Por favor, inicia sesión para continuar.</p>
```

**3. Bucles (`v-for`):**
Permite repetir un bloque de HTML por cada elemento de un array. Es obligatorio acompañarlo de un atributo `:key` único (suele ser el ID del elemento) para que Vue no se vuelva loco actualizando listas grandes.

```html
<ul>
  <li v-for="tarea in listaDeTareas" :key="tarea.id">
    {% raw %}{{ tarea.titulo }} - {{ tarea.estado }}{% endraw %}
  </li>
</ul>
```

**4. Eventos (`v-on` o `@`):**
Se usa para escuchar eventos del usuario (clicks, pulsaciones de teclas, envíos de formulario, etc.).

```html
<button @click="guardarDatos">Guardar</button>
<!-- El modificador .prevent evita que el navegador recargue la página (equivale a event.preventDefault()) -->
<form @submit.prevent="procesarFormulario">
  ...
</form>
```

**5. Formularios (`v-model`):**
Esta directiva es crucial. Establece una conexión bidireccional (*two-way data binding*) entre un *input* del HTML y una variable reactiva de Javascript.

Es decir: **si el usuario escribe en la caja de texto, la variable se actualiza al instante**. Y **si la variable cambia en Javascript, la caja de texto muestra el nuevo valor** automáticamente.

```html
<template>
  <input type="text" v-model="nombreUsuario" placeholder="Escribe tu nombre">
  <p>Hola, {% raw %}{{ nombreUsuario }}{% endraw %}</p>
</template>

<script setup>
import { ref } from 'vue';
const nombreUsuario = ref('');
</script>
```

## 7.3. Consumo de APIs con Axios

Llegamos a la parte central de este tema. 

Queremos **construir un interfaz de usuario** con Vue para procesar **los datos servidos por nuestra API** (da igual cómo esté construida, con Laravel, Spring Boot, FastAPI o cualquier otra cosa).

Así que nuestra maravillosa interfaz en Vue no sirve de nada si no nos comunicamos con nuestra API para obtener la información real de la base de datos y enviar los cambios que haga el usuario.

Para **hacer peticiones HTTP asíncronas desde Javascript**, el navegador nos proporciona la función nativa llamada `fetch`. Sin embargo, en el ecosistema Vue (y React), la inmensa mayoría de los desarrolladores prefiere utilizar una librería externa llamada **Axios**.

Axios es más cómoda que Fetch porque:
1. Convierte automáticamente las respuestas a JSON (con `fetch` tienes que hacer un `.json()` intermedio).
2. Lanza errores automáticamente si el servidor responde con un código 400 o 500 (con `fetch` tienes que comprobar el `response.ok` a mano).
3. Es más fácil de configurar globalmente (por ejemplo, para enviar tokens de seguridad en todas las peticiones).

**Para usar Axios**, solo tienes que **instalarlo** en nuestro proyecto Vue:
```bash
$ npm install axios
```

### 7.3.1. Petición básica con Axios

Como casi siempre, lo mejor para entender cómo funciona algo es verlo en funcionamiento y fijarse atentamente en cómo trabaja.

Observa cómo obtenemos, por ejemplo, una lista de libros. Para asegurarnos de que la petición se hace nada más cargar la página, utilizamos `onMounted`, que ejecuta el código que le pasemos justo en el momento en que el componente se dibuja en la pantalla.

(Este código iría en la parte `<script setup>` del componente Vue que corresponda, ya veremos uno completo):

```javascript
import { ref, onMounted } from 'vue';
import axios from 'axios';

const libros = ref([]);   // Lista vacía

// Se ejecuta automáticamente al cargar el componente
onMounted(async () => {
  try {
    // Hacemos una petición GET a nuestra API
    const respuesta = await axios.get('http://localhost/api/libros');
    // Guardamos los datos que nos envía el servidor en nuestra variable reactiva
    // (Axios convierte el JSON recibido a un array Javascript automáticamente)
    libros.value = respuesta.data;
  } catch (error) {
    console.error("Hubo un error al descargar los libros", error);
  }
});
```

### 7.3.2. El temido error de CORS

Si copias el código anterior y levantas tu API, por ejemplo, en Laravel (en `localhost` o en `localhost:8000`) y ejecutas tu frontend en Vue (`localhost:5173`), verás que **no funciona**. 

Al abrir la consola del navegador (F12), te encontrarás con un error enorme en rojo que menciona la palabra **CORS**.

#### ¿Qué es el CORS?
CORS (*Cross-Origin Resource Sharing*) es un mecanismo de seguridad implementado **por los navegadores web**. Por defecto, los navegadores bloquean cualquier petición asíncrona que tu código Javascript intente hacer hacia un dominio, subdominio o puerto diferente al de la página desde la que se sirvió la página. 

En nuestro caso, el navegador se queja porque *la página se cargó desde `localhost` o `localhost:8000` y la petición de datos está llegando desde `localhost:5173`*. Y, para el navegador, esos son dos servidores diferentes y lo interpreta como un **intento de ataque**.

#### ¿Cómo se soluciona el error de CORS?

El CORS **no se soluciona en el frontend (Vue)**. Es el servidor Backend (tu API en Laravel o tu microservicio en FastAPI) el que debe responderle al navegador y decirle algo como: *"tranquilo, conozco a este frontend y le doy permiso para acceder a mis datos"*.

* **En Laravel:** Abre el archivo `config/cors.php`. Busca la clave `'allowed_origins'` y añade la URL de tu frontend:
  ```php
  'allowed_origins' => ['http://localhost:5173'],
  ```
  *(Nota: En las versiones posteriores a Laravel 11, CORS ya viene bastante permisivo por defecto o se configura en el archivo `bootstrap/app.php`)*.

* **En Spring Boot** es fácil configurar CORS para un controlador concreto:

  ```java
  @RestController
  @CrossOrigin(origins = "http://localhost:5173")
  public class UsuarioController {

      @GetMapping("/api/usuarios")
      public String listarUsuarios() {
          return "Lista de usuarios";
      }
  }
  ```

  En cambio, si quieres configurarlo globalmente para toda la API, la cosa se complica y es diferente si estás usando Spring Security o no. En este curso no entraremos en esos detalles avanzados.

* **En FastAPI:** Tienes que usar el **middleware `CORSMiddleware`**, que ya viene incluido con el paquete estándar. En este ejemplo se ilustra cómo se usa:

    ```python
    import os

    from fastapi.middleware.cors import CORSMiddleware

    ORIGENES_PERMITIDOS = os.getenv("ORIGENES_PERMITIDOS", "http://localhost:5173").split(",")

    app.add_middleware(
        CORSMiddleware,
        allow_origins=ORIGENES_PERMITIDOS,
        allow_methods=["GET", "POST", "PUT", "PATCH", "DELETE"],
        allow_headers=["*"],
    )
    ```

    - **`allow_origins`**: la lista de orígenes autorizados. Aquí hemos puesto el servidor de desarrollo de Vue (que trabajaremos en el tema próximo). Lo hemos tomado de una variable de entorno para poder cambiarla en producción. Evita usar `allow_origins=["*"]` salvo en pruebas rápidas o en APIs verdaderamente públicas, porque eso autoriza a cualquier web del mundo.
    - **`allow_methods`**: qué métodos HTTP se permiten.
    - **`allow_headers`**: qué cabeceras puede enviar el cliente.

    Añade este middleware a **los servicios a los que llamará el frontend directamente**. En nuestro ejemplo de usuarios y pedidos, serían tanto el servicio de usuarios como servicio de pedidos. En arquitecturas más grandes se suele poner un único punto de entrada (llamado *gateway*) y se configura CORS solo allí.

Una vez configurado tu backend para permitir peticiones cruzadas, el navegador dejará pasar la información y tu Vue por fin recibirá el JSON con los datos. 

**Ten muy presente este error, porque es el problema número uno al que te enfrentarás al separar frontend y backend**, independientemente de si hablas con un monolito o con decenas de microservicios.

## 7.4. Autenticación y manejo de estado (Tokens)

Otro cambio radical al pasar de una SSR a una SPA es **la forma en la que los usuarios inician sesión**.

En aplicaciones web tradicionales de Laravel, por ejemplo, cuando un usuario hacía login, PHP creaba una **Sesión** en la memoria del servidor y le metía una **Cookie** al navegador del usuario. En cada clic posterior, el navegador enviaba esa Cookie automáticamente, y Laravel sabía quién era el usuario. 

Sin embargo, las APIs RESTful son por definición **"Stateless" (Sin estado)**. No recuerdan nada de una petición a otra y no utilizan Cookies de sesión. Entonces, ¿cómo demostramos quiénes somos al intentar crear un nuevo curso o borrar una academia en la base de datos?

La respuesta son los **Tokens (como JWT o Laravel Sanctum)**. El flujo es el siguiente:

1. **Login:** El usuario teclea su email y contraseña en un formulario hecho en Vue. Vue envía esos datos a la ruta `/api/login` del backend mediante una petición `POST` normal.
2. **Generación del Token:** El backend verifica que la contraseña sea correcta en la base de datos. Si lo es, genera una cadena de texto muy larga, cifrada y firmada (el **Token**) y se la devuelve a Vue en formato JSON.
3. **Almacenamiento:** Vue recibe el Token y debe guardarlo en algún lugar seguro del navegador que no se borre al cerrar la pestaña. Lo ideal es guardarlo en el **`localStorage`**.
4. **Peticiones posteriores:** Cada vez que Vue intente acceder a una ruta protegida de la API (por ejemplo, para borrar algo), deberá adjuntar ese Token manualmente en las cabeceras HTTP (los *Headers*) de la petición, específicamente en una cabecera llamada `Authorization: Bearer <el_token>`.

Vamos a ver cómo se programa esto paso a paso.

#### Paso 1: El componente de Login en Vue

Imagina que tenemos un archivo `Login.vue`. Vamos a crear un formulario, capturar los datos y enviarlos a la API.

```html
<template>
  <div class="login-form">
    <h2>Iniciar Sesión</h2>
    <!-- .prevent evita que la página se recargue -->
    <form @submit.prevent="iniciarSesion">
      <div>
        <label>Email:</label>
        <input type="email" v-model="credenciales.email" required>
      </div>
      <div>
        <label>Contraseña:</label>
        <input type="password" v-model="credenciales.password" required>
      </div>
      <button type="submit">Entrar</button>
    </form>
    
    <!-- Mostramos errores si los hay -->
    <p style="color: red;" v-if="errorMsg">{{ errorMsg }}</p>
  </div>
</template>

<script setup>
import { ref } from 'vue';
import axios from 'axios';
// Si usas Vue Router, importarás el router para redirigir al usuario
import { useRouter } from 'vue-router'; 

const router = useRouter();

const credenciales = ref({
  email: '',
  password: ''
});
const errorMsg = ref('');

const iniciarSesion = async () => {
  errorMsg.value = '';
  try {
    // 1. Enviamos el POST al backend
    const respuesta = await axios.post('http://localhost/api/login', credenciales.value);
    
    // 2. El servidor responde con éxito y nos entrega un JSON que contiene el token.
    // Supongamos que viene en respuesta.data.token
    const tokenGenerado = respuesta.data.token;
    
    // 3. Guardamos el token en la caja fuerte del navegador (localStorage)
    localStorage.setItem('miTokenSeguro', tokenGenerado);
    
    // 4. Redirigimos al usuario a la pantalla principal de la aplicación
    router.push('/dashboard');
    
  } catch (error) {
    // Si la contraseña está mal, el servidor devolverá un código de error (ej: 401)
    errorMsg.value = 'Credenciales incorrectas. Vuelve a intentarlo.';
  }
};
</script>
```

#### Paso 2: Usar el token en rutas protegidas

Ahora el usuario ya está logueado y tiene su token en el `localStorage`. Supongamos que quiere ver la lista de sus academias privadas o crear una nueva. Si intentamos hacer `axios.post('/api/academias')` sin más, Laravel rechazará la petición con un error 401 (No autorizado) porque no sabe quiénes somos.

Debemos **adjuntar el token** sacándolo previamente del `localStorage`:

```javascript
const crearAcademia = async (datosNuevaAcademia) => {
  try {
    // Recuperamos el token de la caja fuerte
    const token = localStorage.getItem('miTokenSeguro');
    
    // Realizamos la petición POST, pasando los datos, y un tercer parámetro
    // que es un objeto de configuración para Axios donde metemos las cabeceras (Headers)
    const respuesta = await axios.post('http://localhost/api/academias', datosNuevaAcademia, {
      headers: {
        'Authorization': `Bearer ${token}`
      }
    });
    
    console.log("¡Academia creada con éxito!", respuesta.data);
  } catch (error) {
    console.error("Error al crear. ¿Estás seguro de que tienes un token válido?", error);
  }
};
```

*(Nota técnica: En proyectos profesionales, para no tener que escribir esto del `localStorage` y el `Header` en TODAS las peticiones que hagas en tu aplicación, se configuran los "Interceptors" de Axios, que son trozos de código que se ejecutan automáticamente antes de cada petición para inyectar el token por ti. Pero entender el proceso manual es vital para comprender cómo funciona la seguridad en las APIs modernas).*

#### Paso 3: Cerrar sesión (Logout)

Hacer *logout* en un frontend tipo SPA es la cosa más sencilla del mundo. Al no haber sesiones en el servidor que destruir (aunque sí puedes invalidar el token en la BD si tu API lo permite), a nivel de interfaz de usuario basta con **borrar el token** del `localStorage` y redirigir al Login.

```javascript
const cerrarSesion = () => {
  localStorage.removeItem('miTokenSeguro');
  router.push('/login');
};
```
Si el token no está, tu código ya no podrá adjuntarlo y cualquier petición a la API fallará bloqueando el acceso al usuario.

## 7.5. Ejemplo completo: Un CRUD con Vue y Axios

Para afianzar todos los conocimientos, vamos a ver el código completo de un componente diseñado para gestionar libros (Listarlos, crearlos y borrarlos). Estudia detenidamente los comentarios del código para entender qué hace cada parte de la plantilla y cada función del *script*.

```html
<template>
  <div class="contenedor">
    <h2>Gestión de Libros de la Biblioteca</h2>
    
    <!-- 1. FORMULARIO PARA CREAR NUEVOS LIBROS -->
    <!-- .prevent captura el evento submit y ejecuta la función crearLibro -->
    <form @submit.prevent="crearLibro" class="formulario-creacion">
      <input type="text" v-model="nuevoLibro.titulo" placeholder="Escribe el título" required>
      <input type="text" v-model="nuevoLibro.autor" placeholder="Escribe el autor" required>
      <!-- Desactivamos el botón si estamos guardando para evitar dobles clics -->
      <button type="submit" :disabled="estaGuardando">
        {% raw %}{{ estaGuardando ? 'Guardando...' : 'Añadir Libro' }}{% endraw %}
      </button>
    </form>

    <hr>

    <!-- 2. ESTADO DE CARGA -->
    <p v-if="estaCargando">Conectando con el servidor para descargar los libros...</p>
    
    <!-- 3. LISTADO PRINCIPAL -->
    <!-- Se muestra solo si no está cargando y hay al menos un libro -->
    <ul v-else-if="libros.length > 0">
      <li v-for="libro in libros" :key="libro.id" class="elemento-lista">
        <strong>{% raw %}{{ libro.titulo }}</strong> escrito por <em>{{ libro.autor }}{% endraw %}</em>
        
        <!-- Botón para borrar pasándole el ID exacto de este libro en concreto -->
        <button @click="borrarLibro(libro.id)" class="boton-peligro">Eliminar</button>
      </li>
    </ul>

    <!-- 4. ESTADO VACÍO -->
    <p v-else>No hay ningún libro en la base de datos todavía.</p>
  </div>
</template>

<script setup>
import { ref, onMounted } from 'vue';
import axios from 'axios';

// --- VARIABLES REACTIVAS DE ESTADO ---
// Almacena el array de libros que vendrá del servidor
const libros = ref([]);
// Controla si se muestra el mensaje de carga general
const estaCargando = ref(false);
// Controla si el formulario está en proceso de envío
const estaGuardando = ref(false);

// Objeto reactivo enlazado bidireccionalmente con los inputs del formulario
const nuevoLibro = ref({
  titulo: '',
  autor: ''
});

// URL base de nuestra API REST
const API_URL = 'http://localhost/api/libros';


// --- MÉTODOS Y LÓGICA ---

// Este código se ejecuta automáticamente nada más cargar la página
onMounted(() => {
  obtenerTodosLosLibros();
});

const obtenerTodosLosLibros = async () => {
  estaCargando.value = true;
  try {
    const respuesta = await axios.get(API_URL);
    // El servidor ha respondido bien, guardamos el JSON en nuestra variable
    libros.value = respuesta.data;
  } catch (error) {
    alert("Error de conexión al obtener el listado.");
    console.error(error);
  } finally {
    // Pase lo que pase (éxito o error), ocultamos el mensaje de carga
    estaCargando.value = false; 
  }
};

const crearLibro = async () => {
  estaGuardando.value = true;
  try {
    // Enviamos un POST adjuntando el objeto nuevoLibro como cuerpo (Body) JSON
    const respuesta = await axios.post(API_URL, nuevoLibro.value);
    
    // Si ha ido bien, en lugar de recargar TODA la lista desde el servidor, 
    // simplemente inyectamos el nuevo libro que nos devuelve el servidor al final de nuestro array local.
    // Esto es rapidísimo y la interfaz se actualizará al instante.
    libros.value.push(respuesta.data);
    
    // Vaciamos las cajas de texto del formulario restaurando los valores por defecto
    nuevoLibro.value = { titulo: '', autor: '' }; 
    
  } catch (error) {
    alert("Ha ocurrido un problema al guardar el libro en la base de datos.");
  } finally {
    estaGuardando.value = false;
  }
};

const borrarLibro = async (idAEliminar) => {
  // Siempre es buena idea pedir confirmación al usuario
  if (!confirm("¿Estás completamente seguro de borrar este libro?")) {
    return;
  }

  try {
    // Enviamos el verbo DELETE a la URL específica del libro
    await axios.delete(`${API_URL}/${idAEliminar}`);
    
    // Borrado exitoso en el servidor. Ahora limpiamos la interfaz gráfica.
    // Sobrescribimos el array de libros filtrando y dejando fuera el libro que acabamos de borrar.
    libros.value = libros.value.filter(libro => libro.id !== idAEliminar);
    
  } catch (error) {
    alert("Error al intentar borrar el libro.");
  }
};
</script>

<style scoped>
/* Un poco de CSS para que no se vea feo, solo afectará a este componente */
.contenedor { max-width: 600px; margin: auto; font-family: sans-serif; }
.formulario-creacion { display: flex; gap: 10px; margin-bottom: 20px; }
.elemento-lista { display: flex; justify-content: space-between; padding: 10px; border-bottom: 1px solid #ccc; }
.boton-peligro { background-color: #d9534f; color: white; border: none; padding: 5px 10px; cursor: pointer; }
.boton-peligro:hover { background-color: #c9302c; }
</style>
```

## 7.6. Práctica final: frontend para Gestión de Academias

Es hora de crear la interfaz gráfica para la API RESTful de la Unidad 4. 

Vas a desarrollar un **Frontend SPA completo y funcional** utilizando **Vue.js 3 y Vite**, que se comunique con la API de Gestión de Academias que desarrollaste previamente. Todo lo que has aprendido en las secciones anteriores deberás ponerlo en práctica aquí.

### Requisitos Técnicos

1. **Creación del Proyecto:** Debes inicializar tu frontend usando Vite (`npm create vue@latest`). Usa **Vue Router** (dile que sí en el asistente de instalación) para poder tener navegación real entre páginas (pantalla de login, pantalla principal, etc).
2. **Librerías HTTP:** Instala y usa Axios (`npm install axios`) para realizar todas las peticiones a la API.
3. **Gestión del Estado:** Debes guardar el token de autenticación en el `localStorage` del navegador. Si intentas entrar a una URL privada sin token, la aplicación debería impedírtelo.
4. **Diseño Visual:** Puedes usar CSS puro, o cualquier framework que prefieras (Bootstrap, TailwindCSS, Vuetify), pero la aplicación debe lucir decente, limpia y ser usable.

### Flujo y Vistas a implementar

Deberás implementar las siguientes pantallas (componentes rutados en tu Vue Router):

#### 1. Sistema de Autenticación
- **Vista de Registro:** Un formulario para que un usuario se registre (`POST /api/register`).
- **Vista de Login:** Un formulario para iniciar sesión (`POST /api/login`). Debe recoger el Token Sanctum que devuelve la API y almacenarlo en `localStorage`. Si el login es correcto, redírigelo a la vista principal.
- **Botón de Logout:** Presente en la barra de navegación cuando el usuario está logueado. Debe eliminar el token del `localStorage` y devolverte a la pantalla de Login.

#### 2. Gestión de Academias (Solo usuarios autenticados)
- **Listado de Academias:** Muestra las academias creadas por el usuario autenticado. Al cargar esta vista, debes hacer un `GET /api/academies` incluyendo el Token en la cabecera, de lo contrario la API te rechazará.
- **Crear Academia:** Formulario para añadir una nueva academia (`POST /api/academies`).
- **Eliminar Academia:** Botones junto a cada academia en el listado para borrar academias. Debe enviar la petición `DELETE` a la API.

#### 3. Cursos y Estudiantes
- **Listado de Cursos:** Una vista que muestre todos los cursos disponibles en las academias.
- **Inscripción de Estudiantes:** Dentro de los detalles de un curso, debe haber un formulario, selector o listado para poder inscribir a un Estudiante a dicho curso (llamando al endpoint de la tabla pivote de tu API que desarrollaste en el tema 4).

### Normas de entrega

El incumplimiento de cualquiera de los siguientes requisitos conllevará penalización o rechazo de la entrega:

1. **API y Base de Datos corriendo:** Para poder evaluar la práctica, el profesor necesitará poder levantar tanto tu frontend como tu backend. 
2. **Código fuente del Frontend:** Sube a Moodle Centros un archivo ZIP con tu proyecto Vue, **excluyendo estrictamente la carpeta `/node_modules`** (esta carpeta es gigantesca, si la subes suspenderás la entrega).
3. **Repositorio público:** Enlace a tu repositorio público en GitHub o GitLab, con commits periódicos y descriptivos.
4. **Vídeo de demostración:** Graba un vídeo capturando tu pantalla, con **tu propia voz** haciendo una demostración completa del uso del frontend en el navegador (registrarse, hacer login, ver cómo cambia la interfaz al loguearse, crear una academia, verla en el listado, e inscribir un estudiante). El vídeo debe demostrar visualmente que tu frontend funciona bien.
5. **Conversación con la IA:** Sube un archivo .docx o .odt con TODA tu conversación con la IA, si la has utilizado para resolver bugs o entender conceptos. Necesitamos ver cómo has interactuado con la Inteligencia Artificial.

### Rúbrica de calificación

La evaluación se realizará según los siguientes ítems (niveles 0 a 3):
* **0**: Sin hacer o sin evidencia de esfuerzo.
* **1**: Hecho, pero con errores graves o funcionamiento muy deficiente.
* **2**: Hecho y funcional, pero mejorable (falta alguna validación, bugs menores, no cumple el 100% de la lógica).
* **3**: Perfecto, cumple todos los requisitos con excelencia y código limpio.

| Ítem Evaluable | Peso | Nivel 0 | Nivel 1 | Nivel 2 | Nivel 3 |
| :--- | :---: | :--- | :--- | :--- | :--- |
| **0. Uso ético y eficiente de la IA (Eliminatorio)** | **Requisito** | No defiende el código. Uso fraudulento. | (No se aplica) | (No se aplica) | Entiende y explica el funcionamiento de los componentes y la comunicación asíncrona perfectamente en una prueba oral o escrita. |
| **1. Entrega en tiempo y forma** | **10%** | No entregado / Formato erróneo. | Faltan requisitos (ej. node_modules incluido) o falta vídeo. | Cumple mayoría, fallos en explicación del vídeo o faltan flujos menores. | Cumple 100% de la norma. Vídeo nítido, bien narrado y demostrativo. |
| **2. Enrutamiento Vue Router y Componentes** | **20%** | No usa Vue Router. Todo metido a la fuerza en App.vue. | Navegación rota, componentes mal estructurados. | Rutas funcionales pero sin protección de acceso para usuarios no logueados (Cualquiera puede entrar a ver academias tecleando la URL). | Estructura SFC impecable, rutas públicas y privadas correctamente protegidas. |
| **3. Autenticación Frontend (Token)** | **20%** | No hay login funcional en el frontend. | Login funciona pero el token no se guarda correctamente, obligando a recargar. | Guarda el token, pero su manejo es ineficiente o repetitivo en el código. | Login y Logout perfectos. Almacenamiento seguro del token en `localStorage` y cabeceras bien construidas. |
| **4. Consumo de API CRUD (Academias)** | **20%** | Falla la petición a la API. | Listado estático, no sincroniza con la API, o CORS bloqueando peticiones de forma continua. | Lee y escribe en la API, pero el estado de la UI no se actualiza al momento (hay que recargar página manualmente para ver los cambios). | Reactividad perfecta: Listar, crear y borrar se refleja inmediatamente en el HTML del frontend sin recargas. |
| **5. Consumo relaciones N:M (Inscripciones)** | **20%** | No interactúa con endpoints relacionales de la API. | Falla al enviar los datos estructurados que espera la API para matricular alumnos. | Funciona, pero la UI es muy confusa y no queda claro qué estudiante va a qué curso. | Frontend inscribe estudiantes a cursos de forma limpia, mostrando avisos de éxito o de error. |
| **6. Diseño y Experiencia de Usuario (UI/UX)** | **10%** | HTML puro sin CSS. Totalmente feo e inusable. | Aspecto visual muy pobre o descuadrado. | Diseño funcional pero tosco, sin feedback para el usuario (ni spinners de carga, ni mensajes de error). | Interfaz atractiva y usable (usando CSS propio o Framework), da feedback visual durante cargas (loaders) y alerta en caso de fallos. |

*Nota: Recuerda que para aprobar es obligatorio obtener el Nivel 3 en el ítem 0 y que este ítem se valorará con posterioridad al resto de la práctica (en entrevistas o pruebas individuales o durante el examen).*
