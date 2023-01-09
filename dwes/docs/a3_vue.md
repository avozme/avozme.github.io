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

#### Ejemplo 1: hola, mundo

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

#### Ejemplo 2: pregunta y respuesta

En el siguiente ejemplo, puedes ver un <div> parecido al anterior pero que usa dos variables, llamadas ```{{pregunta}}``` y  ```{{respuesta}}```, cuyos valores se asignan desde Vue:

```html
    <div id="app">
        <p>La pregunta es: {{ pregunta }}.</p> 
        <p>La respuesta es: {{ respuesta }}.</p> 
    </div>

    <script src="https://servidor/vue.js"></script>
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

#### Ejemplo 3: Condicional simple

Con Vue también puede hacerse una salida HTML condicional, que dependa de los valores de las variables de Vue.

Aquí puedes ver un ejemplo sencillo. Si la variable *visible* vale *true*, se verá el texto "Ahora puedes verme". En el momento en el que cambie el valor de *visible* a *false*, el texto despaparecerá. Ten en cuenta que esto sucede dinámicamente, es decir, con la página ya cargada.

```html
    <div id="app">
        <p v-if="visible">Ahora puedes verme</p>
    </div>

    <script src="https://servidor/vue.js"></script>
    <script>
        const app = new Vue({
            el: '#app',
            data: {
                visible: true
            }
        });
    </script>
```

#### Ejemplo 4: Bucle for

Igual que puede hacerse una salida HTML condicional, también puede generarse una salida HTML a partir de un array recorrido con un bucle de tipo for.

Observa el siguiente ejemplo, donde un array con nombres de animales genera la salida HTML a partir de su contenido:

```html
    <div id="app">
        <p v-for="animal in arrayAnimales"> {{ animal }} </p>
    </div>

    <script src="https://servidor/vue.js"></script>
    <script>
        const app = new Vue({
            el: '#app',
            data: {
              arrayAnimales: ['Perro', 'Gato', 'Oveja', 'Caballo']
            }
        });
    </script>
```

#### Ejemplo 5: formularios

Con Vue.js se pueden asociar campos de formulario a variables de Vue, de modo que si cambia una, cambiará también la otra dinámicamente.

En el siguiente ejemplo hemos asociado un campo de un formulario ("nombre") con un atributo del objeto Vue. Observa que, para hacer ese enlace, hay que definir una propiedad HTML llamada *v-model*.

```html
    <div id="app">
        <p>Nombre: <input type="text" v-model="nombre"></p>
        <p>Tu nombre es: {{ nombre }}</p>
    </div>


    <!-- Scripts -->
    <script src="https://servidor/vue.js"></script>
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

#### Ejemplo 6: evento click

XXX en desarrollo