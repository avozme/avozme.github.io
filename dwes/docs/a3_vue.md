---
layout: page
title: Apéndice III. Vue js
permalink: /vue-js/
nav_order: 11
has_children: false
parent: Desarrollo Web en Entorno Servidor
---
# Apéndice 3. Vue.js
{: .no_toc }

- TOC
{:toc}


## A3.1. ¿Qué es Vue.js?

Vue.js es un **framework para Javascript** orientado al **diseño de interfaces de usuario** para aplicaciones web y a la **creación de aplicaciones OVA** (One View Application) o SPA (Single Page Application).

Es similar a otros frameworks como **Angular** o **React**, aunque más fácil de aprender. Al igual que estos dos, tiene licencia de *software libre*.

Para usar Vue.js en un proyecto se puede optar por alguna de estas vías:

1. Incluirlo como una librería Javascript más (mejor desde un CDN). Por ejemplo:

   ```html
   <script src="https://cdn.jsdelivr.net/npm/vue@2.7.14/dist/vue.js"></script>
   ```

2. Usarlo en combinación con un servidor Node. Hay que instalar Node.js y npm en el lado del servidor. Esto permite desarrollar toda la aplicación web con Javascript, de modo que el código sea, al menos en teoría, más fácil de desarrollar y mantener, además de más eficiente.

3. Usarlo en combinación con Laravel. En este caso, como es lógico, hay que tener Laravel corriendo en un servidor Apache o similar. Laravel proporciona su propio servidor Node. De este modo, conseguimos la eficiencia del código Javascript precompilado sin renunciar a la potencia de PHP con Laravel en el lado del servidor.

## A3.2. Algunos ejemplos sencillos

Para ver cómo trabaja Vue.js (independientemente de que lo estemos usando solo o en combinación con Laravel), vamos a escribir algunos ejemplos sencillos de entender, en lugar de teorizar sobre la estructura de las páginas desarrolladas con Vue.

### Ejemplo 1: hola, mundo

Por supuesto, tenemos que empezar por aquí. Observa detenidamente este código:

```html
    <div id="app">
        {{ message }}
    </div>
    
    <script src="https://cdn.jsdelivr.net/npm/vue@2.7.14/dist/vue.js"></script>

    <script>
        const app = new Vue({
            el: '#app',
            data: {
                message: 'Hola mundo'
            }
        });
    </script>
```

Observa cómo la página consta únicamente de un <div> con el id "app", y dentro solo aparece el contenido ```{{message}}```. Se parece a Blade, pero no lo es: se trata de un dato de Vue.js.

Más abajo, después de incluir Vue.js a través de un CDN, creamos un objeto de tipo Vue al que le definimos dos atributos:

* **el**: aquí vuelve a aparecer el id del <div> HTML. Esto hace que Vue.js enlace este objeto con la capa HTML.
* **data**: aquí se definen los datos de Vue.js. Al establecer el valor de "message" como "Hola mundo", automáticamente aparecerá el texto "Hola mundo" en el contenido ```{{message}}``` de nuestro <div>.

Por supuesto, el objeto Vue puede tener muchos más datos (tantos como necesitemos), cuya procedencia puede ser una base de datos del servidor, por ejemplo.

Con este sencillo ejemplo tal vez ya puedas vislumbrar la facilidad con la que pueden construirse vistas usando Vue para crear plantillas HTML y PHP para extraer datos del servidor. Pero, si aún no lo ves, no te preocupes que vamos a poner ejemplos un poco más complejos.

### Ejemplo 2: pregunta y respuesta

En el siguiente ejemplo, puedes ver un <div> parecido al anterior pero que usa dos variables, llamadas ```{{pregunta}}``` y  ```{{respuesta}}```, cuyos valores se asignan desde Vue:

```html
    <div id="app">
        <p>La pregunta es: {{ pregunta }}.</p> 
        <p>La respuesta es: {{ respuesta }}.</p> 
    </div>

    <script src="https://cdn.jsdelivr.net/npm/vue@2.7.14/dist/vue.js"></script>
    <script>
        const app = new Vue({
            el: '#app',
            data: {
                pregunta: "¿Cómo te llamas?",
                respuesta: "Pepito Pérez"
            }
        });
    </script>
```

### Ejemplo 3: Condicional simple

Con Vue también puede hacerse una salida HTML condicional, que dependa de los valores de las variables de Vue.

Aquí puedes ver un ejemplo sencillo. Si la variable *visible* vale *true*, se verá el texto "Ahora puedes verme". En el momento en el que cambie el valor de *visible* a *false*, el texto despaparecerá. Ten en cuenta que esto sucede dinámicamente, es decir, con la página ya cargada.

```html
    <div id="app">
        <p v-if="visible">Ahora puedes verme</p>
    </div>

    <script src="https://cdn.jsdelivr.net/npm/vue@2.7.14/dist/vue.js"></script>
    <script>
        const app = new Vue({
            el: '#app',
            data: {
                visible: true
            }
        });
    </script>
```

### Ejemplo 4: Bucle for

Igual que puede hacerse una salida HTML condicional, también puede generarse una salida HTML a partir de un array recorrido con un bucle de tipo for.

Observa el siguiente ejemplo, donde un array con nombres de animales genera la salida HTML a partir de su contenido:

```html
    <div id="app">
        <p v-for="animal in arrayAnimales"> {{ animal }} </p>
    </div>

    <script src="https://cdn.jsdelivr.net/npm/vue@2.7.14/dist/vue.js"></script>
    <script>
        const app = new Vue({
            el: '#app',
            data: {
              arrayAnimales: ['Perro', 'Gato', 'Oveja', 'Caballo']
            }
        });
    </script>
```

### Ejemplo 5: formularios

Con Vue.js se pueden asociar campos de formulario a variables de Vue, de modo que si cambia una, cambiará también la otra dinámicamente.

En el siguiente ejemplo hemos asociado un campo de un formulario ("nombre") con un atributo del objeto Vue. Observa que, para hacer ese enlace, hay que definir una propiedad HTML llamada *v-model*.

```html
    <div id="app">
        <p>Nombre: <input type="text" v-model="nombre"></p>
        <p>Tu nombre es: {{ nombre }}</p>
    </div>


    <!-- Scripts -->
    <script src="https://cdn.jsdelivr.net/npm/vue@2.7.14/dist/vue.js"></script>
    <script>
        const app = new Vue({
            el: '#app',
            data: {
                nombre: ''
            }
        });
    </script>
```

A partir de este momento, si cambiamos dinámicamente el valor de *data.nombre*, el campo del formulario también cambiará, así como el texto "Tu nombre es: ...". Y, al contrario, si escribimos algo en el campo del formulario, cambiará el valor de la variable *data.nombre* y, en consecuencia, el texto "Tu nombre es: ..."

### Ejemplo 6: evento click

Otra cosa que puede hacerse con Vue, como es lógico, es capturar los eventos y asociarlos a métodos.

Observa cómo en el siguiente ejemplo se asocia el evento "click" de un botón al método *saludar()* del objeto Vue. Presta atención a la sintaxis de Vue:

```html
    <div id="app">
        <p>Nombre: <input type="text" v-model="nombre"></p>
        <p><button @click="saludar">Púlsame</button></p>
    </div>

    <script src="https://cdn.jsdelivr.net/npm/vue@2.7.14/dist/vue.js"></script>
    <script>
        const app = new Vue({
            el: '#app',
            data: {
                nombre: ''
            },
            methods: {
                saludar() {
                    alert('Hola, ' + this.nombre);
                }
            }

        });
    </script>
```

### Ejemplo 7: evento key

Otro evento habitual que conviene capturar es el de pulsación de una tecla concreta sobre un elemento HTML. 

En el siguiente ejemplo, capturaremos la pulsación de la tecla *Enter* en el campo "nombre" del formulario. Al hacerlo, se ejecutará el método *saludar()*:

```html
    <div id="app">
        <p>Nombre: <input type="text" @keyup.enter="saludar" 
                    v-model="nombre"></p>
        <p><button @click="saludar">Púlsame</button></p>
    </div>

    <script src="https://cdn.jsdelivr.net/npm/vue@2.7.14/dist/vue.js"></script>
    <script>
        const app = new Vue({
            el: '#app',
            data: {
                nombre: ''
            },
            methods: {
                saludar() {
                    alert('Hola, ' + this.nombre);
                }
            }

        });
    </script>
```

### Ejemplo 8: componente "Hola mundo"

Algo fundamental en los frameworks como Vue es la definición de **componentes**.

Un **componente** es un elemento HTML asociado con Vue que puede reutilizarse cuantas veces sea necesario. Cada componente puede tener un conjunto de datos y métodos asociados, y sus datos pueden cambiar dinámicamente, alterando el contenido del componente.

En el siguiente ejemplo vemos el componente más sencillo posible. Se trata de un sencillo <div> con el típico texto "Hola mundo" en su interior. Observa cómo se declara el componente usando la expresión **Vue.component()**. Luego se le asocia un nombre ("hola-mundo") y un código HTML (template).

Ese componente puede usarse todas las veces que haga falta. En este ejemplo, lo usamos dos veces, por lo que el texto "Hola mundo" aparecerá dos veces en la ventana del navegador.

```html
    <div id="app">
        <hola-mundo></hola-mundo>
        <hola-mundo></hola-mundo>
    </div>

    <script src="https://cdn.jsdelivr.net/npm/vue@2.7.14/dist/vue.js"></script>
    <script>
        Vue.component('hola-mundo', {
            template: '<div>¡Hola mundo!</div>'
        });
        const app = new Vue({
            el: '#app'
        });
    </script>
```

### Ejemplo 9: Componente "Lista de tareas"

Vamos a crear un componente un poco más complejo, que contenga datos y métodos.

Se trata de un componente llamado "mis-tareas", que servirá para añadir una lista de tareas a una persona.

El componente dispondrá de un dato, llamado *tareas*, que será un array de strings. También tendrá un método, que llamaremos *crearTarea()*, cuyo cometido será agregar al array de tareas una tarea nueva.

Esa tarea nueva la tomaremos de un *input* de texto de un formulario, cuyo evento *keyup.enter* asociaremos al método *crearTarea()*. También añadiremos un botón "Añadir tarea" con su evento *click* asociado al mismo método.

En este código puedes ver cómo se haría todo esto con Vue. Observa bien la sintaxis tan curiosa que utiliza Vue para definir los datos y los métodos. En esta ocasión, escribiremos "data()" y no "data:" porque vamos a colocar un *return* dentro de esa sección:

```html
    <div id="app">
        <mis-tareas></mis-tareas>
    </div>


    <script src="https://cdn.jsdelivr.net/npm/vue@2.7.14/dist/vue.js"></script>
    <script>
        Vue.component('mis-tareas', {
            template:
                `<div>
                    <ul>
                        <li v-for="tarea in tareas"> {{ tarea }} </li>
                    </ul>
                    Nueva tarea: <input type="text" v-model="nuevaTarea" 
                                  @keyup.enter="crearTarea">
                    <button @click="crearTarea">Añadir tarea</button>
                </div>`,
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
        const app = new Vue({
            el: '#app'
        });
    </script>
```

El componente "mis-tareas" puede reutilizarse cuantas veces sean necesarias, y cada componente tendrá sus propios datos. Por ejemplo, podemos crear dos listas de tareas independientes, una para Juan Pérez y otra para Susana Sánchez, así:

```html
    <div id="app">
        <h1>Tareas del equipo de trabajo</h1>
        <h2>Juan Pérez</h2>
        <mis-tareas></mis-tareas>
        <h2>Susana Sánchez</h2>
        <mis-tareas></mis-tareas>
    </div>
```


## A3.3. Cómo recibe Vue.js datos del servidor

La potencia de Vue.js comenzará a verse si logramos alimentar los componentes con datos procedentes del servidor. Entonces estaremos cerca de lograr una aplicación web con una sola vista que pueda ir cambiando según los datos que se reciban de un servidor web.

La idea es que ya tenemos una vista cargada que queremos actualizar con datos procedentes del servidor. Por lo tanto, todas las peticiones al servidor deben ser asíncronas.

Como ya sabes, para hacer peticiones asíncronas debes utilizar **Ajax**, ya sea en su forma tradicional (con el objeto *XMLHttpResponse*) o mediante alguna libería moderna (como *fetch* o *axios*).

En el siguiente ejemplo, tenemos un *input* de tipo *text* para teclear un DNI. Cuando se introduzca algo en ese *input*, se ejecutará el método *getNameAndLastName()* (observa que el evento se llama, precisamente, *@input*).

Ese método está declarado como ***async***, lo que significa que contiene una operación asíncrona en su interior. Una función asíncrona permite utilizar el controlador *await* para esperar a que una promesa se resuelva antes de continuar la ejecución del código.

La función *fetch()* devuelve una promesa que se resuelve con la respuesta HTTP. Al usar *await*, se espera a que la promesa se resuelva antes de continuar la ejecución del código, lo que nos permite trabajar con la respuesta como si fuera síncrono. Esto hace que el código sea más fácil de entender y mantener. (Si no se utilizase la palabra *async* delante del nombre del método, el *await* se ejecutaría de forma asíncrona y tendríamos que trabajar con callbacks o encadenando promesas para acceder a los datos).

Una vez que se recibe la respuesta del servidor (un JSON con el nombre y el apellido de la persona a la que corresponde ese DNI), se coloca en las dos posiciones reservadas dentro de la plantilla.

```html
<template>
  <div>
    <input type="text" v-model="dni" @input="getNameAndLastname" placeholder="Ingresa el DNI">
    <p>Nombre: {{ name }}</p>
    <p>Apellido: {{ lastname }}</p>
  </div>
</template>

<script>
export default {
  data() {
    return {
      dni: '',
      name: '',
      lastname: ''
    }
  },
  methods: {
    async getNameAndLastname() {
      try {
        const response = await fetch(`http://mi-servidor.com/person/${this.dni}`);
        const data = await response.json();
        this.name = data.name;
        this.lastname = data.lastname;
      } catch (error) {
        console.error(error);
      }
    }
  }
}
</script>
```

### A3.3.1. Ejemplo completo: CRUD con Vue y un servidor RESTful programado con PHP

Supongamos ahora que tenemos una base de datos con una tabla llamada "Libros" cuyos campos son id, título, numPaginas, genero, pais y año. Supongamos también que tenemos un servidor REST programado con PHP que usa esa tabla.

No es un ejemplo realista, desde luego (la tabla está horrorosamente diseñada), pero sí que nos servirá para ilustrar cómo puede interactuar Vue con un servidor RESTful.

En el siguiente código, se usa ***axios*** en lugar de *fetch*. Se trata de otra librería Javascript para hacer peticiones asíncronas al servidor. Es muy similar a *fetch* o *jQuery.ajax*. Como se utiliza mucho, te la muestro en este ejemplo para que veas qué aspecto tiene.

```html
<template>
  <div>
    <table>
      <tr>
        <th>ID</th>
        <th>Título</th>
        <th>Número de páginas</th>
        <th>Género</th>
        <th>País</th>
        <th>Año</th>
      </tr>
      <tr v-for="libro in libros" :key="libro.idLibro">
        <td>{{ libro.idLibro }}</td>
        <td>{{ libro.titulo }}</td>
        <td>{{ libro.numPaginas }}</td>
        <td>{{ libro.genero }}</td>
        <td>{{ libro.pais }}</td>
        <td>{{ libro.ano }}</td>
      </tr>
    </table>
  </div>
</template>

<script>
export default {
  data() {
    return {
      libros: []
    }
  },
  created() {
    this.cargarLibros();
  },
  methods: {
    async cargarLibros() {
      try {
        const response = await axios.get('https://tu-api-rest.com/libros');
        this.libros = response.data;
      } catch (error) {
        console.error(error);
      }
    }
  }
}
</script>
```

En el código anterior puedes ver cómo, usando *axios*, se puede hacer dinámicamente la carga de libros y asignarla al array *libros*, que a su vez está asociado al template HTML.

Pero ¿y si queremos añadir las funcionalidades típicas de un CRUD, como "Editar" o "Borrar"? En el siguiente ejemplo puedes ver cómo construir un CRUD completo con Vue (hemos simplificado la tabla de libros para que solo tenga los campos Título, Autor y Editorial, pero lógicamente podrían ser campos cualesquiera):

```html
<template>
  <div>
    <table>
      <thead>
        <tr>
          <th>ID</th>
          <th>Título</th>
          <th>Autor</th>
          <th>Editorial</th>
          <th>Acciones</th>
        </tr>
      </thead>
      <tbody>
        <tr v-for="book in books">
          <td>{{ book.id }}</td>
          <td>{{ book.title }}</td>
          <td>{{ book.author }}</td>
          <td>{{ book.editorial }}</td>
          <td>
            <button @click="editBook(book)">Editar</button>
            <button @click="deleteBook(book.id)">Borrar</button>
          </td>
        </tr>
      </tbody>
    </table>
    <hr>
    <h3>Crear un nuevo libro</h3>
    <form @submit.prevent="createBook">
      <label>Título:</label>
      <input type="text" v-model="newBook.title">
      <label>Autor:</label>
      <input type="text" v-model="newBook.author">
      <label>Editorial:</label>
      <input type="text" v-model="newBook.editorial">
      <button type="submit">Crear</button>
    </form>
    <hr>
    <h3>Actualizar un libro existente</h3>
    <form @submit.prevent="updateBook">
      <input type="hidden" v-model="currentBook.id">
      <label>Título:</label>
      <input type="text" v-model="currentBook.title">
      <label>Autor:</label>
      <input type="text" v-model="currentBook.author">
      <label>Editorial:</label>
      <input type="text" v-model="currentBook.editorial">
      <button type="submit">Actualizar</button>
    </form>
  </div>
</template>

<script>
import axios from 'axios';

export default {
  data() {
    return {
      books: [],
      newBook: {
        id: null,
        title: '',
        author: '',
        editorial: ''
      },
      currentBook: {
        id: null,
        title: '',
        author: '',
        editorial: ''
      },
      bookIdToDelete: null
    }
  },
  created() {
    this.getBooks();
  },
  methods: {
    async getBooks() {
      try {
        const response = await axios.get('http://mi-servidor.com/books');
        this.books = response.data;
      } catch (error) {
        console.error(error);
      }
    },
    async createBook() {
      try {
        const response = await axios.post('http://mi-servidor.com/books', this.newBook);
        this.books.push(response.data);
        this.newBook = { id: null, title: '', author: '', editorial: '' };
      } catch (error) {
        console.error(error);
      }
    },
    async updateBook() {
      try {
        const response = await axios.put(`http://mi-servidor.com/books/${this.currentBook.id}`, this.currentBook);
        this.getBooks();
        this.currentBook = { id: null, title: '', author: '', editorial: '' };
      } catch (error) {
        console.error(error);
      }
    },
    async deleteBook(bookId) {
      try {
        await axios.delete(`http://mi-servidor.com/books/${bookId}`);
        this.getBooks();
      } catch (error) {
        console.error(error);
      }
    },
    editBook(book) {
      this.currentBook = Object.assign({}, book);
    }
  }
}
</script>
```

## A3.4. Vue.js con Laravel

Laravel permite instalar Vue a través de *artisan*. Se puede usar Vue sin necesidad de hacer todo esto, pero si lo haces al "estilo Laravel", obtendrás ciertas ventajas adicionales.

### A3.4.1. Instalar Vue en Laravel

El modo más sencillo de tener Vue en Laravel es instalar *laravel/ui* (aunque existen otras maneras). Este paquete sirve para hacer autenticación de usuarios (como Breeze o Jetstream).

```
$ composer require laravel/ui
```

A continuación lanzamos *artisan*, instalamos las dependencias de Node y recompilamos todo:

```
$ php artisan ui vue
$ npm install
$ npm run dev
```

Una vez hecho esto, el archivo *public/js/app.js* contendrá los contenedores de Vue. Por lo tanto, debes incluirlo en tus vistas:

```html
<script src="{% raw %}{{ mix('/js/app.js') }}{% endraw %}"></script>
```

Ya puedes usar Vue en esa vista (asegúrate de utilizar el id “app”):

```html
<div id="app">
   <example-component></example-component>
</div>
```

El componente "example-component" viene creado por defecto pero, por supuesto, puedes crear tus propios componentes. Vamos a ver cómo.

### A3.4.2. Crear componentes

Para **crear un componente**, solo tienes que crear un archivo .vue en el directorio *resources/js/components*. Allí ya encontrarás un archivo llamado *example-component.vue*. Puedes usarlo como plantilla para crear componentes adicionales.

Después de crearlo, debes **registrar el componente** en *resources/js/app.js*. Nuevamente, encontrarás que ya está registrado el componente "example-component", así:

```javascript
Vue.component('example-component', 
             require('./components/ExampleComponent.vue').default);
```

Puedes usar ese registro como plantilla para registrar tus propios componentes.

Una vez creados y registrados, los componentes estarán disponibles para usarlos en cualquier vista.

### A3.4.3. Ejemplo completo: CRUD con Laravel y Vue

En este ejemplo vamos a seguir todos los pasos necesarios para crear un CRUD sencillo con Laravel y Vue. Lo vamos a hacer con el Vue integrado en Laravel, pero ten en cuenta que también funcionaría si cargamos la versión de Vue que queramos desde un CDN o desde nuestros propios archivos Javascript.

Los pasos que vamos a describir para crear el CRUD son:

1. Crear proyecto Laravel
2. Configurar conexión con base de datos
3. Crear modelos y lanzar las migraciones
4. Crear al menos un controlador
5. Añadir las rutas
6. Instalar Laravel Vue UI
7. Iniciar Vue en Laravel
8. Construir los componentes Vue
9. Enrutamiento con Vue

#### PASO 1. Crear proyecto Laravel

```
$ composer create-project laravel/laravel laravel-vue-crud --prefer-dist
```

#### PASO 2. Configurar conexión con BD

Editamos el archivo .env:

```
DB_CONNECTION=mysql
DB_HOST=127.0.0.1
DB_PORT=3306
DB_DATABASE=???
DB_USERNAME=???
DB_PASSWORD=???
```

#### PASO 3. Crear modelos / Lanzar migraciones

Por ejemplo, vamos a centrarnos en una tabla llamada *products*:

```
$ php artisan make:model Product -m
$ php artisan migrate
```

(lógicamente, hay que escribir la migración antes de lanzarla)

#### PASO 4. Crear controlador

Seguimos trabajando con la tabla *products*, ahora creando su controlador:

```
$ php artisan make:controller ProductController
```

Los métodos del controlador devolverán solo datos, no vistas, puesto que van a trabajar con Vue en el lado del cliente. 

Por ejemplo, podrían ser algo así:

```php
    public function index()
    {
        $products = Product::all()->toArray();
        return response()->json($products);      
    }
    public function store(Request $request)
    {
        $product = new Product([
            'name' => $request->input('name'),
            'detail' => $request->input('detail')
        ]);
        $product->save();
        return response()->json('Product created!');
    }

    public function show($id)
    {
        $product = Product::find($id);
        return response()->json($product);
    }

    public function update($id, Request $request)
    {
        $product = Product::find($id);
        $product->update($request->all());
        return response()->json('Product updated!');
    }

    public function destroy($id)
    {
        $product = Product::find($id);
        $product->delete();
        return response()->json('Product deleted!');
    }
```

Observa que no hemos escrito los método *create()* ni *edit()*, puesto que no tienen sentido en una API REST controlada desde el cliente: esos formularios de creación y edición los construirá el cliente, no el servidor.

#### PASO 5. Añadir rutas

Editamos nuestro archivo *routes/web.php*. Podría quedar como esto:

```php
Route::post('/producto',
       [App\Http\Controllers\ProductController::class, 'store']);
Route::get('/producto/{product_id}',
       [App\Http\Controllers\ProductController::class, 'show']);
Route::delete('/eliminar-producto/{product_id}',
       [App\Http\Controllers\ProductController::class, 'delete']);
Route::get('/todos-productos',
       [App\Http\Controllers\ProductController::class, 'all']));
Route::put('/actualizar-producto/{product_id}',
       [App\Http\Controllers\ProductController::class, 'update']);
```

#### PASO 6. Instalar Laravel Vue UI

***laravel/ui*** es un componente de Laravel que incluye varios paquetes orientados a la creación del interfaz de usuario, entre ellos Vue.

Si instalas *laravel/ui*, se creará la carpeta *resources/js/components* para colocar ahí los componentes de Vue.

```
$ composer require laravel/ui
$ php artisan ui vue
$ npm run dev
```

Además de *laravel/ui*, en muchos casos se instala también:

* **Vue-router**: un enrutador para Vue. Facilita la selección de los componentes que hay que cargar en cada ruta.
* **Vue-axios**: un cliente HTTP para lanzar peticiones asíncronas al servidor, es decir, peticiones por Ajax. Es parecido a *fetch* y hay quien lo prefiere usar en su lugar.

Para instalar estos dos componentes tendremos que recurrir a *npm*, el gestor de paquetes de Node, puesto que trabajan en el lado del cliente:

```
$ npm install vue-router vue-axios
```

#### PASO 7. Iniciar Vue en Laravel

Tenemos que crear un layout para nuestra aplicación en *resources/views/layout/app.blade.php*. 

Ese layout debe incluir el archivo ***js/app.js***, que es donde estará la librería Vue.

Un layout muy sencillito podría ser algo como esto:

```html
<head>
    <meta name="csrf-token" value="{% raw %}{{ csrf_token() }}{% endraw %}" />
    <title>Ejemplo de CRUD con Vue y Laravel</title>
    <link href="{% raw %}{{ mix('css/app.css') }}{% endraw %}" type="text/css" 
          rel="stylesheet" />
</head>
<body>
    <div id="app"></div>
    <script src="{% raw %}{{ mix('js/app.js') }}{% endraw %}" type="text/javascript">
    </script>
</body>
```

#### PASO 8. Construir componentes Vue

Este es el paso más largo. 

Los componentes que necesitemos se crean en archivos individuales en el directorio *resources/js/components*. Por ejemplo, vamos a crear componentes como:

* *AllProduct.vue*: para mostrar todos los productos.
* *CreateProduct.vue*: formulario para creación de un nuevo producto.
* *EditProduct.vue*: formulario para edición de productos existentes.

Una vez creados, se pueden reutilizar en cualquier punto de la aplicación.

Cada componente de Vue en Laravel tiene esta estructura:

```html
<template>
    <!-- HTML del componente -->
</template>
<script>
    // Código del componente
</script>
<style>
    // Estilos del componente
</style>
```

Por ejemplo, el componente *CreateProduct.vue* podría ser así: 

```html
<template>
   <div class="panel panel-default" >
      <div class="panel-heading">Nuevo producto</div>
      <div class="panel-body">
         <form action="" v-on:submit.prevent="newProduct()">                
             <div class="form-group">
                 Referencia: <input type="text" class="form-control" name="reference" v-model="reference">
             </div>
             <div class="form-group">
                 Categoría: <input type="text" class="form-control" name="category" v-model="category">
             </div>
             <div class="form-group">
                 Precio: <input type="text" class="form-control" name="cost" v-model="cost">
             </div>
             <div class="form-group">
                 Cantidad: <input type="text" class="form-control" name="quantity" v-model="quantity">
             </div>
             <button type="submit" class="btn btn-primary">
                 Enviar Producto
             </button>
         </form>
      </div>
   </div>
</template>
<script>
    export default {
        data() {   // Datos que recogemos del componente
            return {
                reference: '',
                category: '',
                cost: '',
                quantity: ''
            }
        },
        methods: {
            newProduct() {
                const params = {
                    reference: this.reference,
                    category: this.category,
                    cost: this.cost,
                    quantity: this.quantity
                };
                this.reference = '';  //eliminamos los valores para que los campos del formulario se vacien
                this.category = '';
                this.cost = '';
                this.quantity = '';
                axios.post('/producto', params)
                    .then((response) => {
                        const product = response.data;
                        this.$emit('new', product);
                    });
            }
        }
    }
</script>
```

Observa que hemos asociado el método *newProduct()* con el evento *v-on:submit.prevent*. Esto hace que el evento *submit* del formulario se redirija al método que nos interesa. La palabra *prevent* se refiere a que queremos prevenir (evitar) su comportamiento por defecto, es decir, evitar que el navegador envíe directamente el formulario al servidor.

Por lo tanto, al pulsar "submit", se pasará el control al método *newProduct()*, que será quien se encargue de enviar el formulario al servidor de forma asíncrona mediante *axios*.

#### PASO 9: enrutamiento con Vue

Vue dispone en Laravel de su propio enrutador en un paquete llamado ***vue-router***. Como dijimos antes, si lo instalas puedes enrutar también en el lado del cliente.

El enrutador de Vue con Laravel está ubicado en el archivo *resources/js/routes.js*.

El enrutamiento con Vue permite seleccionar de los componentes que se deben cargar en el lado del servidor en cada ruta. Esto facilita mucho el trabajo en las aplicaciones OVA (*one view application*).

El enrutador de Vue está escrito en Javascript, claro, no en PHP, y tiene un aspecto como este:

```javascript
export const routes = [
    {
        name: 'home',
        path: '/',
        component: AllProduct
    },
    {
        name: 'create',
        path: '/create',
        component: CreateProduct
    },
    {
        name: 'edit',
        path: '/edit/:id',
        component: EditProduct
    }
];
```

Observa cómo, para cada ruta, se indica un nombre (de uso interno para la aplicación), una URL y el componente (o componentes) que se cargarán en el *layout* en caso de solicitar esa ruta.

Ese componente, a su vez, se encargará de pedir los datos al servidor mediante alguna de las rutas definidas en el enrutador de Laravel (*web.php*), por lo que el uso del enrutador de Vue no implica que dejemos de usar el enrutamiento en el servidor.



