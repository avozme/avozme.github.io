---
layout: page
title: 4 Vue.js
permalink: /vue-js/
nav_order: 4
parent: Desarrollo web full stack
---
# 4. Vue.js
{: .no_toc }

- TOC
{:toc}

Vue.js es un **framework para Javascript** orientado al **diseño de interfaces de usuario** para aplicaciones web y a la **creación de aplicaciones OVA** (One View Application) o SPA (Single Page Application).

Es similar a otros frameworks como **Angular**, **React** o **Svelte**, aunque con una curva de aprendizaje menos empinada, y tiene licencia de software libre.

En este tema vamos a aprender los fundamentos de Vue.js para consumir los API REST que ya sabemos construir, de modo que podamos crear una aplicación de tipo OVA o SPA de forma rápida, eficiente y flexible, y lo haremos con dos enfoques diferentes: usando Vue para crear un frontend independiente del API (que sería nuestro backend) e integrando las dos partes en una sola aplicación (full stack).

## 4.1. Introducción a Vue.js

Vue.js es lo que se llama un **framework JavaScript progresivo** diseñado para construir interfaces de usuario modernas y dinámicas. Se centra en la creación de **Single Page Applications (SPA)**, es decir, aplicaciones web que cargan una única página HTML y actualizan su contenido de forma dinámica sin necesidad de recargar todo el sitio cada vez que el usuario realiza una acción.

#### Ventajas principales

- **Evita recargar la página completa** con cada petición al servidor.
- **Permite crear componentes reutilizables**, lo que hace el desarrollo más limpio y modular.
- **Incluye enrutamiento en cliente**, lo que mejora la experiencia del usuario al navegar sin interrupciones.
- **Se integra fácilmente con Laravel**, ya que este framework lo incluye preinstalado.
- Es **open source** y cuenta con una comunidad muy activa.

#### Otros frameworks similares

- **Angular** (Google, desde 2010)
- **React** (Facebook/Meta, desde 2013)
- **Vue.js** (open source, desde 2014)
- **Svelte** (open source, desde 2016)

## 4.2. Cómo se usa Vue.js

Vue.js se puede utilizar de **tres formas diferentes**, según lo que necesites construir:

**Opción 1: Como una librería JavaScript más**

  Puedes incluir Vue directamente desde un CDN dentro de un archivo HTML. Es la manera más simple de empezar a experimentar.

  ```html
  <script src="https://unpkg.com/vue@3/dist/vue.global.js"></script>
  ```

  A partir de aquí, puedes usar Vue dentro de esta página. Es ideal para probar ejemplos pequeños o hacer prototipos rápidos, pero no podrás hacer uso de características importantes de Vue como usar `import/export` para cargar otros componentes o para diseñar soluciones escalables.

  *Veremos esta forma de trabajar con Vue en el [apartado 4.3](../vue-js/#43-vuejs-como-librer%C3%ADa-javascript) de este tema.*


**Opción 2: Con npm para proyectos frontend**

  Instalando *Node.js* y *npm*, puedes crear proyectos Vue completos exprimiendo toda su potencia: componentes, build tools, dependencias, etc.

  Esta opción se usa cuando queremos escribir una aplicación web de tipo **frontend**, es decir, que se ejecute en el cliente web consumiendo los datos producidos por el **backend** (que se ejecuta en el servidor). 

  Este tipo de división frontend/backend, como ya sabes, ha sido y sigue siendo muy común en la industria, porque independiza por completo un proyecto de otro, aunque complica y encarece el desarrollo de todo el conjunto.

  *Veremos esta forma de trabajar con Vue en el [apartado 4.4](../vue-js/#44-vuejs-con-npm-para-aplicaciones-frontend) de este tema.*

**Opción 3: Integrado en Laravel**

  Si ya usas Laravel, puedes trabajar con Vue directamente dentro del proyecto Laravel. 

  Así conseguiríamos un verdader desarrollo **full stack** (backend con Laravel + frontend con Vue), todo en el mismo entorno.

  *Veremos esta forma de trabajar con Vue en el [apartado 4.5](../vue-js/#45-vuejs-integrado-en-laravel-para-aplicaciones-full-stack) de este tema.*


## 4.3. Vue.js como librería JavaScript

La forma más sencilla de empezar con Vue es usarlo como una librería directamente en tu HTML. El aspecto que tendría ese HTML sería algo así:

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

Esta modalidad **no es recomendable para proyectos grandes**, pero la emplearemos ahora para que conozcas de forma práctica las principales características de Vue a través de **un puñado de ejemplos**.

*[Puedes descargar el código fuente completo de todos los ejemplos desde aquí](https://github.com/avozme/vue-examples)*.

#### Ejemplo 1 – Hola mundo

Observa cómo se extrae la propiedad ***createApp*** del objeto ***Vue*** y se usa para construir otro objeto (***app***).

Este objeto, que puede llamarse de otro modo aunque suele denominarse así, *app*, se utiliza para asignarle datos (con ***data()***) o, como veremos en otros ejemplos, métodos, templates, eventos, etc. 

Finalmente, el objeto *app* **se monta**, es decir, se renderiza dentro del árbol DOM de la página.

Observa asimismo que, dentro del bloque HTML, **hay un div con el id="app"**. Ese *id* tiene que coincidir con el nombre de la variable donde se montó Vue. El resultado final será que el texto ***{%raw%}{{ message }}{%endraw%}*** se sustituirá por el valor que se le dio en la función *data()*.

No dudes en analizar el código detenidamente y probarlo en tu navegador web para comprobar que funcione.

```html
<!DOCTYPE html>
<html lang="es">
  <head>
    <meta charset="utf-8">
    <title>Ejemplo de uso de Vue.js</title>
  </head>
  <body>
    <div id="app">
      {%raw%}{{ message }}{%endraw%}
    </div>
        
    <script src="https://unpkg.com/vue@3/dist/vue.global.js"></script>

    <script>
      const { createApp } = Vue;   // Extrae createApp del objeto Vue

      const app = createApp({
        data() {
          return {
            message: 'Hola mundo'
          };
        }
      });
      app.mount('#app');
    </script>
  </body>
</html>
```

#### Ejemplo 2 – Pregunta y respuesta

En este ejemplo vamos a ver cómo *data()* puede preparar múltiples datos para que sean renderizados en el árbol DOM.

```html
<!DOCTYPE html>
<html lang="es">
  <head>
    <meta charset="utf-8">
    <title>Ejemplo de uso de Vue.js</title>
  </head>
  <body>
    <div id="app">
      {%raw%}
        <p>La pregunta es: {{ pregunta }}.</p> 
        <p>La respuesta es: {{ respuesta }}.</p> 
      {%endraw%}
    </div>

    <script src="https://unpkg.com/vue@3/dist/vue.global.js"></script>

    <script>
      const { createApp } = Vue;
      const app = createApp({
        data() {
          return {
            pregunta: "¿Cómo te llamas?",
            respuesta: "Pepito Pérez"
          };
        }
      });
      app.mount('#app');
    </script>
  </body>
</html>
```

#### Ejemplo 3 – Condicional simple

Vue también permite hacer salidas HTML condicionadas a los valores de los datos, como puedes ver en este ejemplo.

Cambia el valor del *data* ***visible*** dentro de Vue para ver qué efecto tiene en la página final.

```html
<!DOCTYPE html>
<html lang="es">
  <head>
    <meta charset="utf-8">
    <title>Ejemplo de uso de Vue.js</title>
  </head>
  <body>
    <div id="app">
        <p v-if="visible">Ahora puedes verme</p>
    </div>

    <script src="https://unpkg.com/vue@3/dist/vue.global.js"></script>

    <script>
      const { createApp } = Vue;
    
      const app = createApp({
        data() {
          return {
            visible: true
          };
        }
      });

      app. mount('#app');
    </script>
  </body>
</html>
```

#### Ejemplo 4 – Bucle

Igual que podemos hacer salidas HTML condicionadas por los datos, también podemos ***iterar*** sobre los datos para hacer salidas múltiples.

Observa este código y ejecútalo en tu navegador web:

```html
<!DOCTYPE html>
<html lang="es">
  <head>
    <meta charset="utf-8">
    <title>Ejemplo de uso de Vue.js</title>
  </head>
  <body>
    <div id="app">
      <p v-for="animal in arrayAnimales"> {%raw%}{{ animal }}{%endraw%} </p>
    </div>

    <script src="https://unpkg.com/vue@3/dist/vue.global.js"></script>

    <script>
      const { createApp } = Vue;

      const app = createApp({
        data() {
          return {
            arrayAnimales: ['Perro', 'Gato', 'Oveja', 'Caballo']
          };
        }
      });
      app.mount('#app');
    </script>
  </body>
</html>
```

#### Ejemplo 5 – Formulario

En este ejemplo puedes ver cómo Vue posibilida **el mapeo o emparejamiento de campos de un formulario HTML** con variables declaradas en el *data()* de Vue, de modo que, si cambia una, cambia automáticamente la otra:

```html
<!DOCTYPE html>
<html lang="es">
  <head>
    <meta charset="utf-8">
    <title>Ejemplo de uso de Vue.js</title>
  </head>
  <body>
    <div id="app">
        <p>Nombre: <input type="text" v-model="nombre"></p>
        <p>Tu nombre es: {%raw%}{{ nombre }}{%endraw%}</p>
    </div>

    <script src="https://unpkg.com/vue@3/dist/vue.global.js"></script>

    <script>
      const { createApp } = Vue;

      const app = createApp({
        data() {
          return {
            nombre: ''
          };
        }
      });
      app.mount('#app');
    </script>
  </body>
</html>
```

#### Ejemplo 6 – Evento click

Introducimos aquí los ***methods*** de Vue para que veas cómo puedes **capturar un evento** de tipo ***click()*** (observa el ***@click*** en la sección HTML) y asociarlo a código Vue.

```html
<!DOCTYPE html>
<html lang="es">
  <head>
    <meta charset="utf-8">
    <title>Ejemplo de uso de Vue.js</title>
  </head>
  <body>
    <div id="app">
        <p>Nombre: <input type="text" v-model="nombre"></p>
        <p><button @click="saludar">Púlsame</button></p>
    </div>

    <script src="https://unpkg.com/vue@3/dist/vue.global.js"></script>
    <script>
      const { createApp } = Vue;
      const app = createApp({
        data() {
          return {
            nombre: ''
          };
        },
        methods: {
          saludar() {
            alert('Hola, ' + this.nombre);
          }
        }
      });
      app.mount('#app');
    </script>
  </body>
</html>
```

#### Ejemplo 7 – Evento key

Otro evento que a menudo nos interesa capturar (hay más, pero se manejan de forma parecida) es el **evento de "tecla pulsada"**.

En el siguiente ejemplo vemos cómo asociar ese evento (***@key***) a un elemento HTML y disparar con él un método declarado en Vue.

```html
<!DOCTYPE html>
<html lang="es">
  <head>
    <meta charset="utf-8">
    <title>Ejemplo de uso de Vue.js</title>
  </head>
  <body>
    <div id="app">
      <p>Nombre: <input type="text" @keyup.enter="saludar" v-model="nombre"></p>
      <p><button @click="saludar">Púlsame</button></p>
    </div>

    <script src="https://unpkg.com/vue@3/dist/vue.global.js"></script>
    <script>
      const { createApp } = Vue;
      const app = createApp({
        data() {
          return {
            nombre: ''
          };
        },
        methods: {
          saludar() {
            alert('Hola, ' + this.nombre);
          }
        }
      });
      app.mount('#app');
    </script>
  </body>
</html>
```

#### Ejemplo 8 – Componente “Hola mundo”

Un elemento fundamental de Vue son los componentes. Se trata de bloques reutilizables que pueden contener, entre otras cosas, un **template** o fragmento de código HTML con datos de Vue en su interior, además de *data()*, *methods()*, etc.

El siguiente componente de Vue es el más simple posible: apenas un fragmento de HTML estático. Pero en este ejemplo puedes ver cómo reutilizamos el componente todas las veces que lo necesitemos sin tener que volver a escribirlo.

```html
<!DOCTYPE html>
<html lang="es">
  <head>
    <meta charset="utf-8">
    <title>Ejemplo de uso de Vue.js</title>
  </head>
  <body>
    <div id="app">
      <hola-mundo></hola-mundo>
      <hola-mundo></hola-mundo>
    </div>

    <script src="https://unpkg.com/vue@3/dist/vue.global.js"></script>
    <script>
      const { createApp } = Vue;

      // Creamos la app
      const app = createApp({});

      // Registramos el componente hola-mundo
      app.component('hola-mundo', {
          template: '<div>¡Hola mundo!</div>'
      });

      // Montamos la app
      app.mount('#app');
    </script>
  </body>
</html>
```

#### Ejemplo 9 – Componente “mis-tareas”

El siguiente ejemplo muestra un componente un poquito más elaborado que "Hola mundo" (ejemplo 8). En este caso, tenemos un componente llamado "***mis-tareas***" con un HTML algo más complejo, que incluye datos (se itera sobre ellos con *v-for*), eventos (como *@click*), así como sus propios *data()* y *methods*.

```html
<!DOCTYPE html>
<html lang="es">
  <head>
    <meta charset="utf-8">
    <title>Ejemplo de uso de Vue.js</title>
  </head>
  <body>
    <div id="app">
      <mis-tareas></mis-tareas>
    </div>

    <script src="https://unpkg.com/vue@3/dist/vue.global.js"></script>
    <script>
      const { createApp } = Vue;

      const app = createApp({});

      // Registro del componente "mis-tareas"
      app.component('mis-tareas', {
        template: {%raw%}
          `<div>
            <ul>
              <li v-for="tarea in tareas" :key="tarea">{{ tarea }}</li>
            </ul>
            Nueva tarea: 
            <input type="text" v-model="nuevaTarea" @keyup.enter="crearTarea">
            <button @click="crearTarea">Añadir tarea</button>
          </div>`,{%endraw%}
          data() {
            return {
              nuevaTarea: '',
              tareas: []
            };
        },
        methods: {
          crearTarea() {
            if (this.nuevaTarea.trim() !== '') {
              this.tareas.push(this.nuevaTarea.trim());
              this.nuevaTarea = '';
            }
          }
        }
      });

      app.mount('#app');

    </script>
  </body>
</html>
```

#### Ejemplo 10 – Reutilizar el componente “mis-tareas”

En este último ejemplo de introducción vamos a ver cómo se puede reutilizar el componente "mis-tareas" para ilustrar que cada ocurrencia del componente **tiene su propio estado**, es decir, su propio conjunto de datos.

Lee el código y ejecútalo luego en tu navegador web, para ver qué pasa.

```html
<!DOCTYPE html>
<html lang="es">
  <head>
    <meta charset="utf-8">
    <title>Ejemplo de uso de Vue.js</title>
  </head>
  <body>
    <div id="app">
      <h1>Tareas del equipo de trabajo</h1>
      <h2>Pepito Pérez</h2>
      <mis-tareas></mis-tareas>
      <h2>Susana Sánchez</h2>
      <mis-tareas></mis-tareas>
    </div>
    <script src="https://unpkg.com/vue@3/dist/vue.global.js"></script>
    <script>
      const { createApp } = Vue;
      const app = createApp({});
      app.component('mis-tareas', {
            template:{%raw%}
              `<div>
                <ul>
                    <li v-for="(tarea, index) in tareas" :key="index">
                      {{ tarea }}
                    </li>
                </ul>
                Nueva tarea: <input type="text" v-model="nuevaTarea" 
                              @keyup.enter="crearTarea">
                <button @click="crearTarea">Añadir tarea</button>
              </div>`,{%endraw%}
              data() {
                    return {
                        nuevaTarea: '',
                        tareas: []
                    }
              },
            methods: {
              crearTarea() {
                  this.tareas.push(this.nuevaTarea);
                  this.nuevaTarea = '';
              }
            }

      });

      app.mount('#app');
    </script>
  </body>
</html>
```

## 4.4. Vue.js con npm para aplicaciones frontend

Cuando quieres desarrollar una SPA completa, Vue se puede usar para **construir un *frontend*** que ataque a un *backend* escrito en cualquier otro lenguaje (puede ser PHP con Laravel o cualquier otra cosa).

En esta situación estaremos hablando de **dos proyectos completamente independientes**: uno para el front y otro para el back. De hecho, pueden existir varios front atacando al mismo back, cada uno de ellos ofreciendo una solución distinta.

Si lo usamos de este modo, Vue se utiliza junto con **Node.js**, **npm** y herramientas modernas de compilación como **Vite**. También usará el **API fetch** o **Axios** para lanzar las peticiones de datos al servidor.

### 4.4.1. Pasos para desarrollar un frontend con Vue

#### PASO 1. Instala Node, npm y Vite

La noticia rara es que no necesitamos *Node.js*, pero lo instalaremos porque viene con *npm* y *vite*, que son las herramientas que realmente nos harán falta. Pero ¿qué diferencia hay entre estos tres elementos? 

* **Node.js** es un entorno de ejecución de JavaScript para servidores web. Añade al JavaScript convencional soporte para acceso a bases de datos, gestión de sesiones, etc. Por tanto, no lo usaremos directamente, pero sí nos harán falta *npm* y *vite*, que forman parte de Node.
* **npm** (Node Package Manager) es el gestor de paquetes de Node. Nos resultará imprescindible para gestionar las dependencias de Vue y para **traducir Vue a JavaScript** comprensible por los navegadores web. Ten en cuenta que Vue no puede ser comprendido por ningún navegador, por lo que su código debe convertirse a JavaScript convencional.
* **Vite** es un servidor rápido de desarrollo que traduce en tiempo real nuestro código Vue a JavaScript convencional para que podamos ir probando nuestro código conforme lo desarrollamos.

Después de instalar Node, comprueba que tanto Node como npm funcionan:

```bash
$ node -v
$ npm -v
```

Esto te devolverá la versión de cada uno de ellos. Necesitarás la versión 20 de Node o superior.

#### PASO 2. Crea un nuevo proyecto Vue

Crearemos un proyecto vacío de Vue con este comando de npm:

```bash
$ npm create vue@latest
```

Durante la creación del proyecto, npm te hará varias preguntas, como:

   * **Project name**: escribe el que quieras (te sugerirá algo como "frontend-vue").
   * **TypTypeScript, JSX Support, etc**: No marques nada, no lo lo necesitas por ahora.
   * **Experimental features**: No marques ninguna.
   * **Skip example code**: Puedes responder «yes» para que no te cree ningún archivo .vue de ejemplo.

#### PASO 3. Revisa la estructura de directorios

Tras la creación del proyecto se debe haber desplegado una estructura de directorios como esta:

```
src/
├─ main.js
├─ App.vue
└─ components/
   ├─ Componente1.vue
   ├─ Componente2.vue
   ├─ Componente3.vue
   └─ Etc.
```

* **main.js** es el punto de entrada de la aplicación. Se encarga de hacer el ***createApp()*** y montar la aplicación en un div de HTML (típicamente, un div con ***id="#app"***).
* **App.vue** es el componente raíz de la aplicación. Funciona como contenedor principal donde se renderizan todos los demás componentes. Generalmente incluye la estructura base de la app: encabezado, navegación, etc.
* En la carpeta *components* se añaden todos los componentes que vayamos a necesitar.

Los componentes de Vue suelen tener todos esta estructura (profundizaremos en ello más adelante):

```html
<template>
    HTML del componente
</template>
<script>
    Código Vue y JavaScript del componente
</script>
<style>
    Estilos CSS del componente
</style>
```

#### PASO 4. Instala las dependencias necesarias

npm se encargará de instalar todo lo necesario para que Vue funcione. Simplemente teclea:

```bash
$ cd frontend-vue   # O el nombre de la carpeta de tu proyecto
$ npm install
```

#### PASO 5. Lanza/detén el servidor de desarrollo
   
```bash
$ npm run dev
```

Esto hace que *vite* traduzca todo el código Vue a JavaScript para que puedas ver el resultado en un navegador web. La traducción se hará en tiempo real, es decir, cualquier cambio en Vue se podrá revisar inmediatamente en el navegador.

El servidor de desarrollo suele dejar disponible tu frontend en ***http://localhost:5173***

Cuando termines la sesión de trabajo, **detén el servidor** de desarrollo pulsando **CTRL + C**.

#### PASO 6. Lanza tu backend

Asegúrate de que tu backend está corriendo también, o si no el frontend no tendrá de dónde sacar los datos para trabajar.

El backend puede estar funcionando en tu servidor local o en cualquier servidor remoto. Esto es indiferente, porque el front y el back son por completo independientes en este tipo de aplicaciones.

#### PASO 7. Revisa posibles errores de CORS

Cuando empieces a desarrollar el frontend puedes obtener **errores de CORS** al pedir datos al servidor.

En ese caso, deberás configurar el CORS en tu backend.

**CORS** (Cross Origin Resource Sharing) es un mecanismo de seguridad del servidor que impide que un frontend alojado en otro lugar acceda a sus datos, salvo que le indiquemos al servidor que ese frontend es de confianza.

El CORS se configura de forma diferente según el backend que hayas montado. Por ejemplo, con Laravel se hace editando el archivo ```config/cors.php```.

### 4.4.2. Pasos para desplegar un frontend con Vue

Cuando tu frontend esté terminado y listo para desplegar en un servidor de internet, sigue estos pasos:

1. **Genera y optimiza todo el código** del frontend:

    ```bash
    $ npm run build
    ```
   Esto creará código JavaScript minimizado y optimizado, comprensible por los navegadores web. El código optimizado se guardará en la carpeta ***dist***

2. **Copia el contenido de *dist* a tu carpeta *public*** de Laravel o a una carpeta de acceso público vía web de tu servidor (*htdocs* o algo así; dependerá del servidor). 

3. **Configura el CORS en tu servidor** si es necesario. Esto tendrás que hacerlo si el front y el back están ubicados en servidores diferentes.

### 4.4.3. Pedir datos al servidor: fetch y axios

El frontend de Vue suele pedir datos al backend usando el *API fetch* o la librería *Axios*:

* El **API fetch** es una interfaz nativa de JavaScript que permite hacer solicitudes HTTP (como GET, POST, etc.) desde el navegador web en segundo plano, sin recargar la página ni detener la ejecución de la misma. Es decir, permite enviar y recibir datos de servidores sin que el usuario de la web se percate de ello.
* La **librería Axios** es una librería de JavaScript que hace lo mismo que el API fetch, pero ofrece algunas funcionalidades adicionales, como conversión automática a JSON.

Nosotros usaremos el API fetch en los próximos ejemplos, pero no entraremos en muchos detalles porque la estudiaréis en el módulo de "Desarrollo web en entorno cliente".

### 4.4.4. Estructura típica de un componente vue

Los componentes de Vue suelen tener todos esta estructura:

```html
<template>
    HTML del componente
</template>
<script>
    Código Vue y JavaScript del componente
</script>
<style>
    Estilos CSS del componente
</style>
```

Dentro de la sección ***script***, un componente puede llevar muchas cosas. Las más habituales son:

* **data()** → código JS que devuelve un objeto con el estado actual del componente.
* **mounted()** → código JS que se ejecuta cuando el componente se ha desplegado en el árbol DOM de la página.
* **created()** → código JS que se ejecuta al crear el componente, antes de que esté en el DOM.
* **methods** → contiene funciones JS que se pueden invocar desde el template (con los eventos @click, @submit, etc)
* **computed** → define propiedades calculadas a partir de otras propiedades. Se recalculan automáticamente si alguna cambia.
* **template** → estructura visual (HTML) del componente.

Por ejemplo, en este sencillo componente puedes ver cómo se escriben muchos de los elementos Vue de la lista anterior:

```html
<template>
    <h2>Contador: {{ count }}</h2>
    <p>Doble del contador (computado): {{ doubleCount }}</p>
    <button @click="increment">Incrementar</button>
</template>

<script>
export default {
  name: 'Contador',
  data() {     // Devuelve el estado del componente
    return {
      count: 0
    };
  },
  created() {   // Se ejecuta cuando el componente es creado
    console.log('Componente creado. (created)');
  },
  mounted() {   // Se ejecuta cuando el componente se monta en el árbol DOM de la página
    console.log('Componente montado en el DOM. (mounted)');
  },
  methods: {    // Se ejecutan como respuesta a eventos en la página (ver @click más arriba)
    increment() {
      this.count++;
    }
  },
  computed: {   // Se ejecutan si cambian los datos base (this.count, en este caso)
    doubleCount() {
      return this.count * 2;
    }
  }
};
</script>
```

### 4.4.5. Enrutamiento en el cliente

Otra de las cosas que puede hacer Vue es **enrutar en el lado del cliente**. Es decir, en lugar de ser Laravel (o quien sea que esté en el lado del servidor) quien haga el enrutamiento de cada *endpoint* hacia un controlador y un método para generar una nueva vista, es el propio navegador quien se encarga de decidir qué hay que hacer con cada ruta, sin llamar al servidor.

Generalmente, con este tipo de enrutamiento, cada ruta provocará la carga de un nuevo componente de Vue, con lo cual la página cambia ante los ojos del usuario sin que haya intervenido el servidor.

Por ejemplo, la ruta ***/home*** puede cargar un componente llamado ***Home.vue*** y la ruta /***about*** puede cargar un componente llamado ***About.vue***. Esto se indica así en Vue, en un archivo especial de rutas:

```javascript
const routes = [
  { path: '/home', component: Home },
  { path: '/about', component: About }
]
```

Ninguno de esos dos *endpoints* (/home o /about) llama realmente al servidor, sino que los componentes ya existen en el cliente, por lo que la carga es mucho más rápida que en una aplicación web tradicional.

Por supuesto, algunos componentes pueden requerir datos del servidor. Esos componentes lanzarán una petición en segundo plano al servidor desde su propio código, normalmente usando ***fetch*** o ***axios***, y esperarán una respuesta JSON para actualizar lo que el usuario está viendo. En estos casos sí intervendrá, además del enrutador del cliente, el enrutador del servidor.

**Enrutar en el cliente**, por lo tanto, tiene algunas **ventajas** sobre el enrutamiento en el servidor:

* El usuario puede usar atrás/adelante del navegador y todo funciona sin recargar ni reenviar datos al servidor.
* Los «megacomponentes» pueden dividirse con más facilidad en componentes más pequeños.
* El backend se simplifica (aunque el frontend se complica en la misma medida).
* La navegación es más fluida porque hay menos accesos al servidor.

#### Cambios que hay que hacer para enrutar en el cliente

Por defecto, Vue no hará enrutamiento en el frontend, pero puedes activar ese enrutamiento fácilmente:

1. **Instala en enrutador** de Vue (si aún no lo has hecho).

    ```bash
    $ npm install vue-router
    ```

2. **Define las rutas y los componentes** a los que cada ruta corresponde en un archivo de rutas. Este archivo puedes llamarlo como quieras, como por ejemplo ***src/router.js***. Debe tener un aspecto como este:

    ```javascript
    import { createRouter, createWebHistory } from 'vue-router'
    // Importamos todos los componentes que vayamos a direccionar desde en enrutador
    import ProductosList from './components/ProductosList.vue'
    import ProductoForm from './components/ProductoForm.vue'

    // Definimos todas las rutas y el componente al que apuntan
    const routes = [
      { path: '/', redirect: '/productos' },
      { path: '/productos', component: ProductosList },
      { path: '/productos/nuevo', component: ProductoForm }
    ]

    const router = createRouter({
      history: createWebHistory(),
      routes
    })

    export default router
    ```

3. **Carga el enrutador en tu *main.js***, antes de montar la app:

    ```javascript
    import router from './router'

    createApp(App).use(router).mount(#app);
    ```

4. **Usa `<router-link>` en los enlaces a los componentes** en lugar de links normales con `<a href...>`. Por ejemplo, en tu ***App.vue*** podría aparecer algo como esto:

    ```vue
    <template>
      <div>
        <h1>Mi App de Productos</h1>
        <router-link to="/productos">Productos</router-link>
        <router-link to="/productos/nuevo">Nuevo Producto</router-link>
        <router-view />
      </div>    
      etc...
    </template>
    ```
    
    Observa como cada `<router-link>` te lleva a una de las rutas que hemos definido en ***routes.js***, que a su vez provocan la carga de un componente Vue

    El elemento `<router-view>` que aparece justo después de los `<router-link>` indica a Vue que ahí, justo en ese punto, debe renderizar el componenten que se corresponda con la ruta actual.

### 4.4.6. Ejemplo completo: frontend con Vue v1 - solo mostrar datos

Para asimilar mejor toda esta sección e ilustrar bien cómo se usa Vue para construir frontends independientes del backend, vamos a crear un frontend con Vue para consumir [el API «Compras» que programamos como ejemplo en el tema anterior](https://github.com/avozme/compras).

Recuerda que este API servía los datos de tres tablas:

* **Productos**(id, nombre, descripcion, precio, stock) → son los productos de una tienda online ficticia.
* **Clientes**(id, nombre, apellido1, apellido2 y email) → son los clientes de la tienda online.
* **Compras**(cliente_id, producto_id, fecha, hora, unidades) → es la relación N:N entre Productos y Clientes.

Vamos a programar **3 versiones** sucesivamente más complejas de este frontend:

* **Versión 1**: solo mostrará los listados de datos y no permitirá modificarlos. Es la más sencilla y por donde debes empezar a leer el código.
* **Versión 2**: añadiremos funcionalidades CRUD a la versión 1, por lo que ya tendremos una aplicación 100% funcional, aunque aún hará enrutamiento en el servidor.
* **Versión 3**: añadiremos enrutamiento en el cliente a la versión 2, por lo que tendremos una verdadera aplicación SPA que minimiza las recargas y los accesos al servidor.

En la primera versión, crearemos los tres componentes para que tan solo *muestren los datos disponibles en la base de datos*, pero no permitan manipularlos (ni insertar, ni modificar, ni borrar).

La app principal de Vue (#app) estará dividida, pues, en 3 componentes:

* **productos-list** → lista de productos
* **clientes-list** → lista de clientes
* **compras-list** → lista de compras

[ACCEDE AQUÍ AL CÓDIGO COMPLETO DE ESTA VERSIÓN](https://github.com/avozme/frontend-compras-v1)

#### Código más importante de la versión 1
 
**Archivo *main.js***

Como siempre, este será el punto de entrada de la aplicación. Se encargará tan solo de montar el elemento *app*:

```javascript
import { createApp } from 'vue'
import App from './App.vue'

createApp(App).mount('#app')
```

**Archivo *App.vue***

Este componente contiene la plantilla (template) principal de la aplicación. 

Observa cómo se usan los ***v-if*** y ***v-else*** para renderizar un componente `<productos-list>`, `<clientes-list>` o `<compras-list>` según qué vista esté activa en este momento. Esto no será necesario cuando usemos enrutamiento en el cliente en la versión 3 de la aplicación.

```html
<template>
  <div class="container">
    <h1>Tienda Online - Panel de gestión</h1>

    <nav>
      <button @click="vista = 'productos'">Productos</button>
      <button @click="vista = 'clientes'">Clientes</button>
      <button @click="vista = 'compras'">Compras</button>
    </nav>

    <hr />

    <section v-if="vista === 'productos'">
      <productos-list />
    </section>

    <section v-else-if="vista === 'clientes'">
      <clientes-list />
    </section>

    <section v-else>
      <compras-list />
    </section>
  </div>
</template>

<script>
import ProductosList from './components/ProductosList.vue'
import ClientesList from './components/ClientesList.vue'
import ComprasList from './components/ComprasList.vue'

export default {
  components: {
    ProductosList,
    ClientesList,
    ComprasList
  },
  data() {
    return {
      vista: 'productos'
    }
  }
}
</script>

<style>
   /* Aquí irían los estilos CSS */
</style>
```

**Archivo *components/ProductosList.vue***

Este componente prepara los datos de los productos para mostarlos en una tabla HTML. Observa dos cosas:

* Cómo se hace un ***v-for*** sobre el array de productos para generar la tabla HTML con los datos.
* Cómo se hace la llamada al servidor con ***fetch()*** en cuanto está montado en el DOM de la página para recibir como respuesta un JSON con los datos de los productos.

```vue
<template>
  <div>
    <h2>Productos</h2>
    <table border="1">
      <thead>
        <tr>
          <th>ID</th>
          <th>Nombre</th>
          <th>Descripción</th>
          <th>Precio</th>
          <th>Stock</th>
        </tr>
      </thead>
      <tbody>
        <tr v-for="producto in productos" :key="producto.id">
          <td>{{ producto.id }}</td>
          <td>{{ producto.nombre }}</td>
          <td>{{ producto.descripcion }}</td>
          <td>{{ producto.precio }}</td>
          <td>{{ producto.stock }}</td>
        </tr>
      </tbody>
    </table>
  </div>
</template>

<script>
export default {
  data() {
    return {
      productos: []
    }
  },
  async mounted() {
    const res = await fetch('http://localhost/api/productos')
    this.productos = await res.json()
  }
}
</script>
```

**Archivo *components/ClientesList.vue***

Este componente es como *productos-list*, pero aplicado a los clientes. No mostraremos el código aquí para no alargar esto innecesariamente. 

Recuerda que puedes ver y descargar el código completo de este ejemplo en [https://github.com/avozme/frontend-compras-v1](https://github.com/avozme/frontend-compras-v1) 

**Archivo *components/ComprasList.vue***

Este componente es como *productos-list*, pero con los datos de las compras. 

Fíjate que a Vue le da igual si esta tabla es una **tabla maestra** o una **tabla pivote** (relación N:N): para el frontend se trata tan solo de otra colección de datos que se van a mostrar en un componente *data-table*.

Tampoco mostraremos el código aquí, porque es casi idéntico al de *ProductosList.vue*. Recuerda que tienes el código completo disponible en [https://github.com/avozme/frontend-compras-v1](https://github.com/avozme/frontend-compras-v1) 

### 4.4.7. Ejemplo completo: frontend con Vue v2 - CRUD completo, enrutamiento en servidor

El frontend anterior consume el API Compras, pero lo hace solo para consultar los listados de datos.

Podemos mejorarlo **añadiendo funcionalidades de CRUD** a cada uno de los componentes con datos (*productos-list*, *clientes-list* y *compras-list*). Eso complicará el código de cada componente, claro, pero nos ofrecerá una aplicación mucho más completa.

Puedes echar un vistazo al código de esta versión más completa aquí. Solo vamos a mostrar el CRUD de Productos, pero los otros dos (Clientes y Compras) se resuelven de forma muy similar:

[ACCEDE AQUÍ AL CÓDIGO FUENTE COMPLETO DE LA VERSIÓN 2](https://github.com/avozme/frontend-compras-v2)

#### Código más importante de la Versión 2

Los archivos *index.js* y *App.vue* serían idénticos a los de la versión anterior. Lo único que cambia en esta versión son los componentes *ProductosList.vue*, *ClientesList.vue* y *ComprasList.vue*, que se vuelven más complejos al incorporar todas las funcionalidades de un CRUD.

**Archivo *components/ProductosList.vue* con CRUD completo**

```html
<template>
  <div>
    <!-- Barra de búsqueda -->
    <div class="search-bar">
      <input
        v-model="filtro"
        placeholder="Buscar producto..."
        @input="filtrarProductos"
      />
      <button @click="abrirNuevo">+ Nuevo producto</button>
    </div>

    <!-- Tabla de productos -->
    <table>
      <thead>
        <tr>
          <th>ID</th>
          <th>Nombre</th>
          <th>Descripción</th>
          <th>Precio</th>
          <th>Stock</th>
          <th>Acciones</th>
        </tr>
      </thead>
      <tbody>
        <tr v-for="producto in productosFiltrados" :key="producto.id">
          {%raw%}
          <td>{{ producto.id }}</td>
          <td>{{ producto.nombre }}</td>
          <td>{{ producto.descripcion }}</td>
          <td>{{ producto.precio }}</td>
          <td>{{ producto.stock }}</td>
          {%endraw%}
          <td>
            <button @click="abrirEdicion(producto)">Editar</button>
            <button @click="eliminarProducto(producto.id)">Borrar</button>
          </td>
        </tr>
      </tbody>
    </table>

    <!-- Formulario de creación / edición -->
    <div v-if="mostrarFormulario" class="formulario">
      <h3>{%raw%}{{ productoActual.id ? 'Editar producto' : 'Nuevo producto' }}{%endraw%}</h3>
      <form @submit.prevent="guardarProducto">
        <label>Nombre:</label>
        <input v-model="productoActual.nombre" required />

        <label>Descripción:</label>
        <input v-model="productoActual.descripcion" />

        <label>Precio:</label>
        <input v-model.number="productoActual.precio" type="number" min="0" step="0.01" required />

        <label>Stock:</label>
        <input v-model.number="productoActual.stock" type="number" min="0" required />

        <div class="acciones">
          <button type="submit">Guardar</button>
          <button type="button" @click="cerrarFormulario">Cancelar</button>
        </div>
      </form>
    </div>
  </div>
</template>

<script>
export default {
  data() {
    return {
      productos: [],
      productosFiltrados: [],
      filtro: '',
      mostrarFormulario: false,
      productoActual: {
        id: null,
        nombre: '',
        descripcion: '',
        precio: 0,
        stock: 0
      },
      apiUrl: 'http://localhost:8000/api/productos'
    }
  },

  async mounted() {
    await this.cargarProductos()
  },

  methods: {
    async cargarProductos() {
      const res = await fetch(this.apiUrl)
      this.productos = await res.json()
      this.productosFiltrados = this.productos
    },

    filtrarProductos() {
      const texto = this.filtro.toLowerCase()
      this.productosFiltrados = this.productos.filter(p =>
        p.nombre.toLowerCase().includes(texto)
      )
    },

    abrirNuevo() {
      this.productoActual = { id: null, nombre: '', descripcion: '', precio: 0, stock: 0 }
      this.mostrarFormulario = true
    },

    abrirEdicion(producto) {
      this.productoActual = { ...producto }
      this.mostrarFormulario = true
    },

    cerrarFormulario() {
      this.mostrarFormulario = false
    },

    async guardarProducto() {
      const metodo = this.productoActual.id ? 'PUT' : 'POST'
      const url = this.productoActual.id
        ? `${this.apiUrl}/${this.productoActual.id}`
        : this.apiUrl

      await fetch(url, {
        method: metodo,
        headers: { 'Content-Type': 'application/json' },
        body: JSON.stringify(this.productoActual)
      })

      await this.cargarProductos()
      this.cerrarFormulario()
    },

    async eliminarProducto(id) {
      if (!confirm('¿Seguro que deseas eliminar este producto?')) return

      await fetch(`${this.apiUrl}/${id}`, { method: 'DELETE' })
      await this.cargarProductos()
    }
  }
}
</script>

<style scoped>
   /* Aquí iría el CSS */
</style>
```

**Archivos *src/components/ClientesList.vue*** y ***src/components/ComprasList.vue***

Estos archivos son muy semejantes a *ProductosList.vue*, pero adaptados a la estrucura de Clientes y Compras, así que no los mostraremos aquí. Puedes consultar el código completo en [https://github.com/avozme/frontend-compras-v2](https://github.com/avozme/frontend-compras-v2)

### 4.4.8. Ejemplo completo: frontend con Vue v3 - CRUD completo, enrutamiento en cliente

La versión más completa de este frontend no solo haría un CRUD completo de cada recurso, sino que **enrutaría en el cliente** para minimizar los accesos al servidor y agilizar la ejecución.

Además, lo lógico es dividir los componentes como ***ProductosList.vue*** en dos piezas:

* ***ProductosList.vue*** solo mostrará la lista de productos y los botones de acción.
* ***ProductosForm.vue*** mostrará el formulario de insertar/modificar producto.

Esta misma división debería hacerse con Clientes y con Compras. Obtendríamos así una aplicación frontend **bien diseñada y fácilmente escalable** con esta estructura de directorios:

```
src/
├─ main.js    ➔ prepara el createApp de Vue y la monta
├─ routes.js  ➔ enrutador
├─ App.vue    ➔ componente principal
└─ components/
   ├─ ProductosList.vue ➔ listado de productos con acciones CRUD
   ├─ ProductoForm.vue  ➔ formulario añadir/editar productos
   ├─ ClientesList.vue  ➔ listado de clientes con acciones CRUD
   ├─ ClienteForm.vue   ➔ formulario añadir/editar clientes
   ├─ ComprasList.vue   ➔ listado de compras con acciones CRUD
   └─ ComprasForm.vue   ➔ formulario añadir/editar compras
```

Aquí solo te mostraré el código de ***ProductosForm*** y ***ProductosList***, además de los cambios necesarios en los archivos ***main.js***, ***routes.js*** y ***App.vue***, pero puedes ver el código completo de los otros componentes (Clientes y Compras) en el siguiente link.

[ACCEDE AQUÍ AL CÓDIGO FUENTE COMPLETO DE ESTA VERSIÓN](https://github.com/avozme/frontend-compras-v3)

#### Código más importante de la versión 3

**Archivo *src/router.js***

Este es el **archivo de enrutamiento** (no tiene una ubicación estándar y puedes encontrarlo en otros lugares del proyecto). Define qué componente se va a cargar con cada ruta.

Por ejemplo, en el código de aquí abajo (recuerda: está incompleto; el código completo lo tienes [aquí](https://github.com/avozme/frontend-compras-v3)), la ruta `/productos` producirá la carga del componente *ProductosList.vue*, mientras que la ruta `/productos/nuevo` cargará el componente *ProductoForm.vue*. 

```javascript
import { createRouter, createWebHistory } from 'vue-router'
import ProductosList from './components/ProductosList.vue'
import ProductoForm from './components/ProductoForm.vue'

const routes = [
  { path: '/', redirect: '/productos' },
  { path: '/productos', component: ProductosList },
  { path: '/productos/nuevo', component: ProductoForm },
]

const router = createRouter({
  history: createWebHistory(),
  routes
})

export default router
```

Hay que modificar el archivo principal de Vue (***src/main.js***) para que importe el router y lo use antes de montar la app. Algo así:

**Archivo *src/main.js***

```javascript
import { createApp } from 'vue'
import App from './App.vue'
import router from './router'

createApp(App).use(router).mount('#app')
```

**Archivo *src/App.vue***

En el componente principal de Vue (***src/App.vue***) hay que colocar un `<router-view />` en el punto donde queremos que se muestren los componentes asociados a las rutas. También es habitual mostrar links construidos con `<router-link>` en lugar de `<a href...>`.

Por ejemplo, en el ejemplo de aquí abajo (recuerda, está incompleto) hacemos que el texto "Lista de productos" enlace con la ruta "/productos", que a su vez provoca la carga del componente *ProductosList.vue* según se definió en el archivo *routes.js*.

```vue
<template>
  <div>
    <nav style="margin-bottom: 1rem;">
      <router-link to="/productos">Lista de productos</router-link> |
      <router-link to="/productos/nuevo">Producto nuevo</router-link> |
    </nav>
    <router-view />
  </div>
</template>
```

**Archivo *components/ProductosList.vue***

Este componente muestra la lista de productos.

```vue
<template>
  <div>
    <div class="search-bar">
      <input
        v-model="filtro"
        placeholder="Buscar producto..."
        @input="filtrarProductos"
      />
      <router-link to="/productos/nuevo">
        <button>Nuevo producto</button>
      </router-link>
    </div>

    <table>
      <thead>
        <tr>
          <th>ID</th>
          <th>Nombre</th>
          <th>Descripción</th>
          <th>Precio</th>
          <th>Stock</th>
          <th>Acciones</th>
        </tr>
      </thead>
      <tbody>
        <tr v-for="producto in productosFiltrados" :key="producto.id">
          <td>{{ producto.id }}</td>
          <td>{{ producto.nombre }}</td>
          <td>{{ producto.descripcion }}</td>
          <td>{{ producto.precio }}</td>
          <td>{{ producto.stock }}</td>
          <td>
            <router-link :to="`/productos/${producto.id}/editar`">
              <button>Editar</button>
            </router-link>
            <button @click="eliminarProducto(producto.id)">Borrar</button>
          </td>
        </tr>
      </tbody>
    </table>
  </div>
</template>

<script>
export default {
  data() {
    return {
      productos: [],
      productosFiltrados: [],
      filtro: '',
      apiUrl: 'http://localhost/api/productos'
    }
  },

  async mounted() {
    await this.cargarProductos()
  },

  methods: {
    async cargarProductos() {
      const res = await fetch(this.apiUrl)
      this.productos = await res.json()
      this.productosFiltrados = this.productos
    },

    filtrarProductos() {
      const texto = this.filtro.toLowerCase()
      this.productosFiltrados = this.productos.filter(p =>
        p.nombre.toLowerCase().includes(texto)
      )
    },

    async eliminarProducto(id) {
      if (!confirm('¿Seguro que deseas eliminar este producto?')) return
      await fetch(`${this.apiUrl}/${id}`, { method: 'DELETE' })
      await this.cargarProductos()
    }
  }
}
</script>
```

**Archivo *components/ProductoForm.vue***

Este componente gestiona el formulario para añadir/editar un producto.

```vue
<template>
  <div class="formulario">
    <h3>{%raw%}{{ esEdicion ? 'Editar producto' : 'Nuevo producto' }}{%endraw%}</h3>
    <form @submit.prevent="guardarProducto">
      <label>Nombre:</label>
      <input v-model="producto.nombre" required />

      <label>Descripción:</label>
      <input v-model="producto.descripcion" />

      <label>Precio:</label>
      <input v-model.number="producto.precio" type="number" min="0" step="0.01" required />

      <label>Stock:</label>
      <input v-model.number="producto.stock" type="number" min="0" required />

      <div class="acciones">
        <button type="submit">Guardar</button>
        <router-link to="/productos"><button type="button">Cancelar</button></router-link>
      </div>
    </form>
  </div>
</template>

<script>
export default {
  props: ['id'],
  data() {
    return {
      producto: { id: null, nombre: '', descripcion: '', precio: 0, stock: 0 },
      apiUrl: 'http://localhost/api/productos'
    }
  },

  computed: {
    esEdicion() {
      return !!this.id
    }
  },

  async mounted() {
    if (this.esEdicion) {
      const res = await fetch(`${this.apiUrl}/${this.id}`)
      this.producto = await res.json()
    }
  },

  methods: {
    async guardarProducto() {
      const metodo = this.esEdicion ? 'PUT' : 'POST'
      const url = this.esEdicion ? `${this.apiUrl}/${this.id}` : this.apiUrl

      await fetch(url, {
        method: metodo,
        headers: { 'Content-Type': 'application/json' },
        body: JSON.stringify(this.producto)
      })

      this.$router.push('/productos')
    }
  }
}
</script>
```

## 4.5. Vue.js integrado en Laravel para aplicaciones full stack

Hay dos formas de combinar Laravel y Vue:

1. **Frontend separado:** Vue consume una API REST creada con Laravel, como hemos visto en la sección anterior. 

    Esto es ideal si quieres mantener la independencia entre front y back. Tendrías dos aplicaciones separadas que puedes desarrollar, escalar o versionar independientemente una de la otra.

2. **Integrado en Laravel:** Vue se ejecuta dentro del propio proyecto Laravel. 

    Esto es perfecto si buscas un desarrollo full stack unificado. Tendrías *un solo proyecto* (más complejo, pero solo uno).

### 4.5.1. Cómo instalar Vue dentro de Laravel paso a paso

1. **Instala Vue y el plugin de Vite**

     Si has instalado Laravel con compose:

   ```bash
   $ npm install vue @vitejs/plugin-vue
   ```
   
   Si has instalado Laravel con Sail: 
   
   ```bash
   $ ./vendor/bin/sail npm install vue @vitejs/plugin-vue`
   ```

    Recuerda que ***Vite*** sirve para traducir Vue a JavaScript estándar *en caliente*, es decir, durante el desarrollo, para poder ver el efecto de los cambios inmediatamente.


2. **Edita `vite.config.js`:** añade los imports y activa Vue.

    ```javascript
    import { defineConfig } from 'vite';
    import laravel from 'laravel-vite-plugin';
    import vue from '@vitejs/plugin-vue';  // Importamos plugin de Vue
    import tailwindcss from '@tailwindcss/vite';

    export default defineConfig({
        plugins: [
            laravel({
                input: [
                    'resources/css/app.css',
                    'resources/js/app.js',
                ],
                refresh: true,
            }),
            vue(),         // Añadimos soporte para .vue
            tailwindcss(),
        ],
        resolve: {
            alias: {
                'vue': 'vue/dist/vue.esm-bundler.js',
            },
        },    
    });
    ```

3. **Edita `resources/js/app.js`:** este es el archivo de entrada a Vue, así que debes añadir aquí los componentes Vue que tu aplicación vaya a usar. Por ejemplo, para registrar un componente ***Productos.vue***:

   ```js
    import './bootstrap';
    import { createApp } from 'vue';
    import Productos from './components/Productos.vue';

    const app = createApp({});
    app.component('productos', Productos);
    app.mount('#app');
   ```

4. **Inicia el servidor de desarrollo:** 

   ```bash
   $ npm install   # Solo la primera vez!!
   $ npm run dev
   ```

   O, si trabajas con Sail:

   ```bash
   $ ./vendor/bin/sail npm install   # Solo la primera vez!!
   $ ./vendor/bin/sail npm run dev
   ```


A partir de ahora, ya puedes usar Vue en tus vistas de Blade. Por ejemplo:

```html
@vite('resources/js/app.js')   <!-- Habilita Vue en esta vista-->
<div id="app">
  <example-component></example-component>
</div>
```

### 4.5.2. Estructura de directorios de un proyecto Laravel + Vue

Como has podido observar en los ejemplos anteriores, cuando usas Vue con Laravel, los archivos de Vue se colocan en el directorio ***resources/js*** de Laravel:

```
laravel-project/
├─ resources/
│  ├─ js/
│  │  ├─ app.js      ←---- punto de entrada Vue
│  │  └─ components/
│  │     ├─ ExampleComponent.vue
│  │     └─ OtrosComponentes.vue
│  ├─ views/
│  │  └─ welcome.blade.php
├─ routes/
│  └─ web.php
│
└─resto del proyecto Laravel...
```

### 4.5.3. Ejemplo completo: CRUD con Vue.js y Laravel

Como siempre hacemos, vamos a ilustrar cómo se usa Vue dentro de Laravel mediante un ejemplo sencillo pero completo, puesto que es la mejor forma de comprenderlo.

Vamos a crear una aplicación CRUD completa (Create, Read, Update, Delete) para gestionar la tabla de Productos con la que hemos venido trabajando desde el tema 3.

```
Productos(id#, nombre, descripcion, precio, stock)
```

Tendremos a Laravel en el backend y a Vue en el frontend, pero trabajando en modo full stack y no como dos aplicaciones independientes.

**TIENES EL CÓDIGO FUENTE COMPLETO DE ESTE EJEMPLO EN: [github.com/avozme/crud-laravel-vue](https://github.com/avozme/crud-laravel-vue)**

#### Pasos generales

1. Crear el proyecto Laravel.
2. Activar Vue dentro de Laravel.
3. Configurar la base de datos.
4. Crear modelos, migraciones y seeders.
5. Crear el controlador RESTful.
6. Añadir las rutas API.
7. Crear los componentes Vue.
8. Crear las vistas Blade.
9. Compilar y desplegar.

#### PASO 1. Crear proyecto de Laravel

Recuerda que hay dos formas «oficiales» de crear un proyecto Laravel nuevo:

A) **Con composer:**

```bash
$ composer create-project laravel/laravel tienda
$ cd nombre-app
$ php artisan serve   # El servidor estará en http://localhost:8080
```
 
B) **Con Sail (docker):**

```bash
$ curl -s https://laravel.build/mi-app | bash
$ cd mi-app
$ ./vendor/bin/sail up   # El servidor estará en http://localhost
```

#### PASO 2. Preparación de Vue dentro de Laravel

A partir de Laravel 12, Vue no viene activado por defecto con Laravel, pero es fácil ponerlo en marcha:

Con composer:

```bash
$ npm install vue @vitejs/plugin-vue
```

Con Sail:

```bash
$ ./vendor/bin/sail npm install vue @vitejs/plugin-vue
```

A continación, edita el archivo ***vite.config.js*** del directorio raíz:

```javascript
// Añadir este import:
import vue from '@vitejs/plugin-vue';
export default defineConfig({
  plugins: 
    // Deja aquí todo como está. Solo tienes 
    // que añadir esto al final:
    vue(),
  ],
  resolve: {
    alias: {
      'vue': 'vue/dist/vue.esm-bundler.js',
    },
  },   
});
```

También tienes que editar el archivo ***resources/js/app.js***, es decir, el punto de entrada de Vue, para registrar el componente que vamos a usar (*Productos.vue*):

```javascript
import './bootstrap';
import { createApp } from 'vue';
import Productos from './components/Productos.vue';

const app = createApp({});
app.component('productos', Productos);
app.mount('#app');
```

#### PASO 3. Configurar la conexión con la base de datos

Como con cualquier aplicación Laravel, debes editar el ***archivo .env*** para configurar la conexión con la BD. Los siguientes parámetros son los apropiados si usas Sail. En otro caso, sustitúyelos por los tuyos:

```
DB_CONNECTION=mysql
DB_HOST=mysql
DB_PORT=3306
DB_DATABASE=laravel
DB_USERNAME=sail
DB_PASSWORD=password
```

#### PASO 4. Modelos, migraciones, seeders

En este ejemplo solo tendremos un **modelo**, el de Productos. Lo creamos con la **opción -m** para que al mismo tiempo se cree la migración:

```bash
$ php artisan make:model Producto -m                # Con composer
$ ./vendor/bin/sail artisan make:model Producto -m  # Con sail
```

Edita el modelo ***app/Models/Producto.php*** para hacer *fillables* todos los campos. Así podremos hacer asignación de datos masiva desde un formulario:

```php
namespace App\Models;

use Illuminate\Database\Eloquent\Model;
use HasFactory;

class Producto extends Model
{
    // Campos que se pueden asignar masivamente
    protected $fillable = ['nombre', 'descripcion', 'precio', 'stock'];
}
```

Edita también el ***método up()*** de la **migración** ***database/migrations/xx_create_productos_table.php:***

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

Por último, lanza la migración para crear la tabla:

```bash
$ php artisan migrate                # Con composer
$ ./vendor/bin/sail artisan migrate  # Con sail
```

Optativamente, por supuesto, puedes crear un *Seeder* para llenar con datos de prueba la tabla de Productos.

#### PASO 5: Crear el controlador RESTful

Crea el controlador de productos con la opción ***- -api*** para convertirlo en controlador RESTful: 

```bash
php artisan make:controller ProductoController --api
```

Los métodos del controlador ***app/Http/Controllers/ProductoController.php*** devolverán solo datos JSON, no vistas completas:

```php
<?php
namespace App\Http\Controllers;

use App\Models\Producto;
use Illuminate\Http\Request;

class ProductoController extends Controller {
    public function index() {
        return response()->json(Producto::all(), 200);
    }

    public function store(Request $request) {
        $producto = Producto::create($request->all());
        return response()->json($producto, 201);
    }

    public function show($id) {
        return response()->json(Producto::findOrFail($id), 200);
    }

    public function update(Request $request, $id) {
        $producto = Producto::findOrFail($id);
        $producto->update($request->all());
        return response()->json($producto, 200);
    }

    public function destroy($id) {
        Producto::destroy($id);
        return response()->json(null, 204);
    }
}
```

#### PASO 6. Rutas API

Instala los componentes API de Laravel (necesario a partir de Laravel 12):

```bash
$ php artisan install:api                # Con composer
$ ./vendor/bin/sail artisan install:api  # Con sail
```

Ya puedes editar ***routes/api.php***:

```php
use App\Http\Controllers\ProductoController;
Route::apiResource('productos', ProductoController::class);
```

Esto hará accesible nuestra API en *http://servidor/api/productos*. Por ejemplo: *http://servidor/api/productos/destroy/1*

#### PASO 7. Crear los componentes de Vue

Como en este ejemplo solo trabajamos con productos, el único componente que necesitamos es `Productos.vue`, que crearemos en ***resources/js/components/Productos.vue***. Podría ser algo así:

```html

<template>
  <div>
    <h2>Gestión de productos</h2>

    <input v-model="filtro" placeholder="Buscar producto..." class="border p-2 mb-3">

    <ul>
      <li v-for="p in productosFiltrados" :key="p.id">
        {%raw%}{{ p.nombre }} - {{ p.precio }}{%endraw%} € 
        <button @click="editar(p)">Editar</button>
        <button @click="borrar(p.id)">Eliminar</button>
      </li>
    </ul>

    <h3>{%raw%}{{ editando ? 'Editar producto' : 'Nuevo producto' }}{%endraw%}</h3>
    <input v-model="form.nombre" placeholder="Nombre">
    <input v-model="form.descripcion" placeholder="Descripción">
    <input v-model="form.precio" type="number" placeholder="Precio">
    <input v-model="form.stock" type="number" placeholder="Stock">
    <button @click="guardar">Guardar</button>
  </div>
</template>

<script>
export default {
  name: 'Productos',
  data() {
    return {
      productos: [],
      form: { id: null, nombre: '', descripcion: '', precio: '', stock: '' },
      filtro: '',
      editando: false,
      apiBase: 'http://localhost/api/productos'
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
      try {
        const res = await fetch(this.apiBase,{
          headers: { 'Accept': 'application/json' }
        });
        if (!res.ok) throw new Error('Error al cargar productos');
        this.productos = await res.json();
      } catch (error) {
        console.error(error);
      }
    },
    async guardar() {
      try {
        const options = {
          method: this.editando ? 'PUT' : 'POST',
          headers: {
            'Content-Type': 'application/json',
            'Accept': 'application/json'
          },
          body: JSON.stringify(this.form)
        };

        const url = this.editando ? `${this.apiBase}/${this.form.id}` : this.apiBase;

        const res = await fetch(url, options);
        if (!res.ok) throw new Error('Error al guardar el producto');

        this.resetForm();
        this.cargarProductos();
      } catch (error) {
        console.error(error);
      }
    },
    editar(prod) {
      this.form = { ...prod };
      this.editando = true;
    },
    async borrar(id) {
      try {
        const res = await fetch(`${this.apiBase}/${id}`, { method: 'DELETE' });
        if (!res.ok) throw new Error('Error al borrar el producto');
        this.cargarProductos();
      } catch (error) {
        console.error(error);
      }
    },
    resetForm() {
      this.form = { id: null, nombre: '', descripcion: '', precio: '', stock: '' };
      this.editando = false;
    },
  },
  mounted() {
    this.cargarProductos();
  },
};
</script>
```

#### PASO 8: Crear las vistas Blade

De nuevo, solo necesitaremos la vista de productos para este ejemplo. La crearemos en ***resources/views/productos.blade.php:*** y en ella cargaremos el componente *productos* que hemos creado con Vue:

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

<div style='background-color: #ddd'><strong>Ten en cuenta que esta vista no se generará en el back, como ocurriría con una aplicación backend, sino que la utilizará Vue para renderizar su frontend SPA.</strong></div>

Debes dirigir el ***endpoint /*** a la nueva vista para que Vue tome el control nada más entrar en la aplicación. Para ello, edita el archivo ***routes/web.php*** y dirige la ruta raíz a nuestra vista:
 
```php
Route::get('/', function () {
    return view('productos');
});
```

#### PASO 9: Desplegar, compilar, probar

Durante el desarrollo debes ejecutar npm en modo dev:

```bash
$ npm run dev                      # Para Laravel con compose
$ ./vendor/bin/sail npm run dev    # Para Laravel con sail
```

Así Vite traducirá cualquier cambio que hagas en Vue a un JavaScript comprensible por el navegador en tiempo real, y podrás ir viendo el resultado inmediatamente en *http://localhost:8000* (si trabajas con compose y has levantado el back con `php artisan serve`) o en *http://localhost* (si trabajas con Sail y has levantado el back con `./vendor/bin/sail up`).

Sin embargo, para construir el build final debes ejecutar npm así:

```bash
$ npm run build                    # Para Laravel con compose
$ ./vendor/bin/sail npm run build  # Para Laravel con sail
```

Esto convertirá Vue en unos archivos JavaScript estándar minimizados y optimizados en la carpeta ***/public*** de Laravel que se servirán junto con el resto de Laravel.

A partir de aquí, puedes **desplegar** la aplicación en cualquier servidor web como harías con cualquier proyecto de Laravel. Lo mejor sería:

* Clonar todo en el servidor web de producción (mejor con git)
* Reconfigurar el archivo .env para el nuevo servidor
* Lanzar el servidor y probarlo todo

**Recuerda que tienes el código fuente completo de este ejemplo en [github.com/avozme/crud-laravel-vue](https://github.com/avozme/crud-laravel-vue)**

## 4.6. Práctica final: CRUD de cursos y estudiantes

Para practicar todo esto vamos a construir un **CRUD completo usando Vue y Laravel** para el siguiente caso:

Crea una aplicación web con Laravel (backend) y Vue (frontend) que nos permita:

* Crear, ver, editar y eliminar Cursos
* Crear, ver, editar y eliminar Estudiantes
* Relacionar Estudiantes con un Curso (relación 1:N)

Las **tablas de la base de datos** tendrán esta estructura:

* **courses**(id#, name, description)
* **students**(id#, name, email, course_id)

Como ves, un curso puede tener muchos estudiantes pero cada estudiante solo pertenece a un curso.

Los pasos que debes seguir para construir esta aplicación son los mismos que hemos seguido en el [ejemplo del apartado anterior](../vue-js/#45-vuejs-integrado-en-laravel-para-aplicaciones-full-stack):

1. **Crear el proyecto Laravel**
2. **Preparar Vue dentro de Laravel**
3. **Configurar la conexión con la base de datos**
4. **Crear modelos y migraciones** y, optativamente, seeders
5. **Crear el controlador API RESTful**
6. **Añadir las rutas API**
7. **Construir los componentes Vue**. ¡Este es el paso más costoso! 

    Puedes crear un megacomponente para cada recurso (Courses.vue y Students.vue) o dividirlos en componentes más sencillos (CoursesList.vue + CoursesForm.vue y StudentsList.vue + StudentsForm.vue). Tendrás que estudiar cómo gestionar la relación entre las dos tablas a nivel del interfaz de usuario.

8. **Crear las vistas Blade**. No olvides dirigir la ruta raíz (/) a alguna de tus vistas (la que quieras que haga de "home" de la aplicación).
9. **Desplegar, compilar, probar**
10. (EXTRA) **Enrutar en el cliente**. Modifica tus componentes para que el enrutamiento se haga en el cliente y así construir una aplicación 100% SPA.
11. (EXTRA) **Desplegar en Openstack**. Monta un servidor en Openstack, despliega allí tu aplicación y ajusta los archivos de configuración (como .env) para que todo funcione (*[--> Más info sobre Openstack aquí](../openstack/)*).


