---
layout: page
title: 2.8 Práctica final
permalink: /php/practica-final/
nav_order: 8
has_children: false
parent: 2 PHP como lenguaje de servidor
grand_parent: Desarrollo Web en Entorno Servidor
---

## 2.8. Práctica final
{: .no_toc }

- TOC
{:toc}

Para cerrar la unidad de PHP vas a construir, paso a paso, **tu primera aplicación web completa renderizada en el servidor (SSR)**, es decir, con todo el HTML generado desde PHP.

En el proceso vas a aplicar todo lo que hemos visto en este tema: arquitectura MVC, namespaces, Composer, PDO con sentencias preparadas, sesiones y protección CSRF.

### Antes de empezar (aviso para navegantes)

#### Esto no es "el CRUD de artículos otra vez"

En el apartado 2.7 tienes un CRUD completo y funcional de una tabla `articles`. **No vamos a pedirte que hagas lo mismo con otro nombre.** 

Copiar esa estructura, cambiar `article` por `libro` o por `producto` y entregar eso no te va a servir de nada.

Lo que vamos a hacer es más ambicioso: partir de esa misma estructura (que debes comprender bien: el front controller, el router, el patrón MVC, la conexión PDO...) y ampliarla para resolver cosas nuevas como:

* Relaciones entre tablas
* Autenticación de usuarios
* Permisos según quién ha creado cada cosa
* Protección de formularios. 

#### Qué vamos a construir

Vamos a crear un **tablón de anuncios de la clase**. Será una aplicación donde los usuarios registrados pueden publicar anuncios (por ejemplo, "vendo libro de texto", "busco grupo para proyecto", "se me olvidó un cargador en el aula 21", etc) organizados por categoría, y donde cualquier otro usuario registrado puede dejar comentarios en ellos.

Las piezas que vas a necesitar construir son:

* **Usuarios** que se registran, inician sesión y cierran sesión.
* **Publicaciones** (anuncios), cada una asociada al usuario que la creó, con título, cuerpo y categoría.
* **Comentarios**, cada uno asociado a una publicación y a un usuario, formando una relación uno-a-muchos (una publicación tiene muchos comentarios).
* **Permisos por propiedad**: cualquier usuario registrado puede publicar y comentar, pero *solo el autor de una publicación puede editarla o borrarla*.
* Un **buscador** simple que filtre las publicaciones por título o por categoría.

#### AVISO IMPORTANTE sobre el uso de la IA en esta práctica

Tienes luz verde para usar IA a lo largo de todo el desarrollo. De hecho, te lo recomendamos activamente, siempre que sea **de forma ética y eficiente**, es decir, como acelerador de tu trabajo, no como sustituto. 

En concreto, en esta práctica te va a venir muy bien para:

* **Generar esqueletos o fragmentos de código**: la estructura inicial de un controlador, una consulta SQL con JOIN que aún no domines del todo, el HTML repetitivo de un formulario...
* **Ayudarte a resolver errores**: pegar un mensaje de error críptico de PHP o de PDO y que te explique qué significa y por dónde empezar a mirar.
* **Usarla como profesor particular**: pedirle que te explique un concepto que no te haya quedado claro o una línea de código que no entiendes, o por qué falla una sesión, o cualquier otra cosa, acelerará enormemente tu aprendizaje.

Usada así, esta práctica que hace unos años nos podía llevar meses de trabajo en clase, hoy la puedes tener funcionando en un par de semanas, y sin aprender ni un ápice menos. Al contrario: vas a poder dedicar el tiempo que antes se iba en escribir código repetitivo y en depurar errores tontos a entender mejor el porqué de cada decisión y centrarte en tus propias dudas para ir resolviéndolas de forma quirúrgica.

<span style="color: red">¡¡ADVERTENCIA!!</span> **Da igual si una línea de tu entrega la escribiste tú a mano, te la generó una IA, o es una mezcla de ambas cosas. *Tienes que entenderla y saber explicarla igual de bien.*** 

En la corrección de esta práctica y en el examen te podemos hacer preguntas concretas sobre tu propio código, en vivo y sin ayuda de ninguna IA. 

No hace falta que te memorices el código de memoria (eso ni tiene sentido ni te lo vamos a pedir), pero sí que lo entiendas de verdad: qué hace cada parte, por qué está ahí, y qué pasaría si la quitaras o la cambiaras.

### PASO 1. Preparar el proyecto

**Objetivo:** montar el esqueleto del proyecto, igual que en el apartado 2.7, dejando preparada una capa de acceso a datos reutilizable para no repetir código de conexión en cada modelo.

Tareas:

* Montar la infraestructura Apache + PHP + MySQL + PHPMyAdmin con Docker Compose (ver apartado 1.2).
* Crear la estructura de carpetas: `src/Controllers`, `src/Models`, `src/Views`, `src/Core`, `public/`.
* Inicializar Composer (`composer init`) y configurar el autoload PSR-4 para que el namespace `App\` apunte a `src/`.
* Ejecutar `composer dump-autoload`.
* Crear un archivo de configuración `config.php` **fuera del control de versiones** (añádelo a tu `.gitignore` — ver apartado 1.1), con las credenciales de tu base de datos:

  ```php
  // config.php
  return [
      'db' => [
          'host'    => 'localhost',
          'dbname'  => 'tablon_nuncios',
          'user'    => 'root',
          'pass'    => 'laquesea',
          'charset' => 'utf8mb4',
      ],
  ];
  ```

* Crear una clase `App\Core\Database` que:
  * En su constructor, cargue `config.php` y establezca la conexión PDO (recuerda `PDO::ATTR_ERRMODE => PDO::ERRMODE_EXCEPTION`, como en el apartado 2.7).
  * Ofrezca, al menos, estos métodos genéricos:
     * `query(string $sql, array $params = []): PDOStatement` -> Recibe como parámetro una consulta SQL y los argumentos para procesar esa consulta, y devuelve el PDOStatement resultante de lanzar la consulta.
     
        Por ejemplo, una posible llamada a este método podría ser: `Database::query('SELECT * FROM users WHERE id = :id', ['1'])`. El método debe ejecutar la consulta `SELECT * FROM users WHERE id = 1` y devolver el resultado (o null si no encuentra nada)

     * `fetchAll(string $sql, array $params = []): ?array` -> Funciona como la anterior, pero devuelve el resultado en forma de array en lugar de devolver el PDOStatement (o null si no encuentra nada).
     * `fetchOne(string $sql, array $params = []): ?array` -> Igual que la anterior, pero devuelve solo el primer registro del resultado de la consulta en lugar de todos (o null si no encuentra nada).

  La idea es que, de aquí en adelante, **ningún modelo cree su propia conexión PDO ni escriba `$pdo->prepare()` directamente**: todos van a apoyarse en esta **clase de abstracción de datos**. Es el mismo principio de "no te repitas" que ya conoces de la programación en Java, aplicado a la capa de datos.

* Diseñar y crear las tablas de tu base de datos: como mínimo, `users`, `posts` (con una clave foránea `user_id`) y `comments` (con claves foráneas `post_id` y `user_id`). Recuerda usar `password_hash()` para el campo de la contraseña de `users`, porque nunca se debe guardar una contraseña en texto plano en la BD.

### PASO 2. Crear un modelo base para no repetirte

**Objetivo:** evitar escribir tres veces el mismo código de "obtener todos", "obtener uno por id" y "borrar por id" en cada uno de tus modelos.

Tareas:

* Crea una clase abstracta `App\Models\BaseModel` que reciba en su constructor la instancia de `Database` y **el nombre de la tabla**, y que implemente, como mínimo, los siguientes métodos comunes: 

   * `getAll(): ?array` -> Obtener todos los registros de la tabla base del modelo (el nombre de la tabla se conoce porque lo recibió el constructor de la clase). Usa `Database::fetchAll()` para lanzar la consulta.
   * `getById(int $id): ?array` -> Obtener el registro que coincida con el `$id`. Usa `Database::fetchOne()`.
   * `delete(int $id): void` -> Eliminar el registro que coincida con el `$id`. En este caso, no tienes nada en `Database` para hacerlo. ¿Te parece buena idea añadirlo o sería mejor dejarlo aquí, en `BaseModel`?
   * `insert(array $data)` -> Añadir a la tabla un registro que vendrá codificado en el array `$data` en forma de pares `campo => valor`. Por ejemplo, para insertar un nuevo usuario, el array $data puede valer: `['email' => 'capitantrueno@iescelia.org', 'username' => 'capitan', 'password' => 'la-contraseña-que-sea']` 
   * `update(int $id, array $data)` -> Modificar el registro `$id` con los datos pasados en el array `$data`, que será una colección de pares `'campo' => 'valor'`, como en `insert()`.

* En los siguientes pasos construiremos el resto de modelos concretos (`Post`, `Comment`, `User`), que heredarán de `BaseModel` y solo añadan lo que les sea propio: 

  * `Post`, por ejemplo, necesitará un método para buscar por título o categoría
  * `User`, por ejemplo, necesitará un método `findByEmail()` para el login.
  * Es posible que te surja la necesidad de crear algún otro método el algún modelo. No te cortes: hazlo cuando sea necesario.
  * También es posible que algunos modelos no tengan que añadir nada y, por lo tanto, se queden vacíos y solo hereden el código de `BaseModel` sin añadir nada más.

Como ves, todo lo que aprendiste sobre herencia y clases abstractas en Java es directamente aplicable a situaciones realistas como esta.

### PASO 3. Autenticación de usuarios - modelo `User` y controlador `AuthController`

**Objetivo:** que un visitante pueda registrarse, iniciar sesión y cerrar sesión, y que la aplicación sepa en todo momento quién es.

Tareas:

* Crea el modelo `User` que herede de `BaseModel` y añada solo el método `findByEmail(string $email, string $password): ?int`. Este método recibirá un email y una password (encriptada) y comprobará si existe en la base de datos usando `Database::fetchOne()`. Devuelve el `$id` del usuario si encuentra al usuario o `null` si no lo encuentra.
* Crea luego un controlador llamado `AuthController` con estas acciones: `showRegisterForm`, `register`, `showLoginForm`, `login`, `logout`.

   * `showRegisterForm()` y `showLoginForm()` se limitan a mostrar la vista con los formularios correspondientes.
   * `register()` -> inserta un usuario nuevo en la base de datos usando el método `User::insert()`. Asegúrate de pasarle la contraseña encriptada con `password_hash()`, nunca con `md5()` (obsoleto y poco seguro) y, por supuesto, nunca en texto plano.
   * `login()` -> busca al usuario por su email llamando a `User::findByEmail()`. Si el usuario existe, arranca la sesión (`session_start()`, que ya viste en el apartado 2.7) y guarda en `$_SESSION` el id y el email del usuario.
   * `logout()` -> destruye la sesión (`session_destroy()`).

* Añade en la cabecera de tu web un enlace a "Iniciar sesión" o, si el usuario ya está logueado, que aparezca su email y un enlace de "Cerrar sesión".

### PASO 4. Publicaciones - modelo `Post` y controlador `PostController`

**Objetivo:** que cualquier usuario logueado pueda publicar, pero que solo pueda editar o borrar *sus propias* publicaciones.

Tareas:

* Crea el modelo `Post` (heredando de `BaseModel`) y el controlador `PostController`, con las acciones `index`, `show`, `create`, `store`, `edit`, `update`, `destroy` (puedes llamarlas como prefieras, pero esos nombres están bastante estandarizados).
  * `index` - Mostrar todos los posts
  * `show` - Mostrar solo un post (el id debe indicarse en la URL)
  * `create` - Mostrar formulario de creación de un post nuevo.
  * `store` - Insertar un post nuevo, cuyos datos se reciben desde el formulario anterior, en la BD.
  * `edit` - Mostrar formulario de modificación de post existente.
  * `update` - Modificar el post en la base de datos.
  * `destroy` - Eliminar un post
* En `index` se debe mostrar el listado de publicaciones y, si se recibe un parámetro de búsqueda, filtrarlas por título o categoría (una cláusula LIKE es suficiente).
* `create` y `store` deben estar protegidos: si el usuario no está logueado, se le redirige al login con un mensaje explicativo, en lugar de dejarle publicar.
* Antes de mostrar el formulario de edición o de ejecutar el borrado, tienes que comprobar que el `user_id` de la publicación coincide con el id del usuario que hay en la sesión. 
  
  Si no coincide, no dejes pasar la petición (puedes devolver un error 403 "Prohibido", o redirigir con un mensaje de "no tienes permiso para hacer esto"). Esto es lo que en el mundo real se llama **autorización** (que puedas hacer algo), que no hay que confundir con la **autenticación** (que sepamos quién eres).

* No olvides las sentencias preparadas en todas las consultas, y `htmlspecialchars()` en todo lo que vuelque a las vistas. Si no te acuerdas de por qué, repasa el apartado 2.7.9.

### PASO 5. Comentarios con relación 1:N - modelo `Comment` y controlador `CommentController`

**Objetivo:** que los usuarios logueados puedan comentar en las publicaciones de otros, y que esos comentarios se muestren dentro de la vista de detalle de cada publicación.

Tareas:

* Crea el modelo `Comment` (hereda de `BaseModel`) y un `CommentController`.
* En la vista de detalle de una publicación (`Post::show()`), muestra el listado de sus comentarios (ordenados por fecha) y, debajo, un formulario para añadir uno nuevo, visible solo si el usuario está logueado.
* Al guardar un comentario, asegúrate de asociarlo tanto al `post_id` de la publicación como al `user_id` del usuario logueado que puedes sacar de `$_SESSION` (nunca de un campo oculto del formulario, porque un usuario malicioso lo podría manipular).
* Los comentarios, a diferencia de las publicaciones, no hace falta que se puedan editar ni borrar en esta práctica, aunque puedes añadirlo por tu cuenta, con las mismas reglas de propiedad del apartado anterior.
* Fíjate en que no te hemos indicado qué métodos debes crear en `CommentController`. Te dejamos que lo deduzcas tú.
* Tampoco te indicamos si el modelo `Comment` necesita métodos adicionales o le basta con los que hereda de `BaseModel`. Nuevamente, decídelo tú *(Pista: en realidad, hay varias formas correctas de resolverlo)*.

### PASO 6. El escudo CSRF en todos los formularios

**Objetivo:** proteger ante ataques CSRF todos los formularios que modifiquen datos.

Tareas:

* Genera un único token CSRF por sesión (igual que en el ejemplo del CRUD de artículos) y añádelo como campo oculto en **todos** tus formularios que hagan `POST`: crear/editar/borrar publicaciones, comentar, e incluso el propio login y registro.
* En cada acción que reciba un `POST`, comprueba el token con `hash_equals()` antes de hacer nada más. Si no coincide, no sigas ejecutando esa acción.

### PASO 7. (Opcional, para subir nota) Rutas limpias

**Objetivo:** sustituir las URL con parámetros (`?controller=Post&action=show&id=3`) por URLs limpias del estilo `/posts/3`, como las que verás en cualquier framework moderno.

*Aviso: este paso es de los que se pueden complicar bastante. Solo recomendable si ya tienes todo lo anterior funcionando y te sobra tiempo.*

Tareas:

* Diseña un pequeño enrutador que sea capaz de interpretar una URL como `/posts/delete/3` y deducir de ahí que hay que llamar al método `destroy(3)` del `PostController`.
* Debe funcionar para cualquier controlador y cualquier id, no solo para publicaciones.
* Pista: vas a necesitar expresiones regulares para "trocear" la URL en sus partes (controlador, acción, parámetro) y un archivo `.htaccess` parecido al que ya usaste en el apartado 2.7 para que todas las peticiones lleguen a tu `index.php`.

### PASO 8. Plan de pruebas con IA

PHP permite automatizar el proceso de *testing* con PHPUnit, pero su instalación y aplicación excede a los propósitos de esta introducción.

Vamos a hacer un ***testing* validado manualmente** a partir de una lista de casos de prueba.

Añade al proyecto un archivo llamado `TESTING.md` en formato [Markdown](https://www.markdownguide.org/cheat-sheet/) donde:

* Generes con ayuda de IA una lista de casos de prueba ("¿qué debería pasar si...?") para las funcionalidades principales. 

   Por ejemplo, puedes pedirle a la IA algo como: *"Genera 10 casos de prueba para un sistema de posts y comentarios. Incluye casos normales, casos límite y casos de error. Formatéalo con viñetas. Para cada elemento de la lista, especifica qué debe hacer la aplicación y cuál debería ser su respuesta"*.

   O puedes ser más específico si ves que este prompt no es lo bastante bueno (**pista: NO LO ES**).

* Ejecuta manualmente cada caso en tu aplicación y anota en el documento `TESTING.md` la respuesta de tu aplicación y si pasa la prueba o falla.

### Entrega de la práctica

* **Comprime todo el código fuente**, incluyendo `TESTING.md`, y súbelo a Moodle Centros dentro del plazo indicado por el profesor.
* **Graba un vídeo** en el que muestres la aplicación funcionando y donde se vea, en este orden, cómo funciona lo siguiente:
  * La autenticación de usuarios (registro y login)
  * El CRUD de publicaciones (crear, listar, editar, borrar)
     * (Que se vea que un usuario solo puede editar y borrar sus propias publicaciones)
  * Publicación de comentarios
  * Búsqueda de publicaciones
  Sube el vídeo a Moodle Centros junto con tu código fuente.
* **Sube también el link a tu repositorio** GitHub o GitLab con el código del proyecto.
* **El proyecto debe ser reproducible** nada más descargarlo en otro equipo sin más que lanzar el comando `docker compose up -d`
* **Recuerda que puedes tener que hacer una defensa oral parcial y/o responder a preguntas sobre tu código** en un examen escrito **SIN IA**. Asegúrate de **ENTENDER** (no memorizar) todo el código que has entregado.


### Rúbrica de corrección

Esta es la rúbrica que usaremos para corregir la práctica del tablón de anuncios. Cada ítem se puntúa de **0 a 3**:

* **0 — Sin hacer**: no funciona o no hay evidencia de esfuerzo.
* **1 — Insuficiente**: está intentado, pero falla en aspectos importantes o funciona solo a medias.
* **2 — Correcto**: cumple lo que se pide, con algún error leve.
* **3 — Excelente**: cumple lo que se pide y además demuestra algo extra (cuidado, robustez, una solución elegante, ir un poco más allá de lo mínimo).

La nota final será la suma de todos los ítems, convertida sobre 10. 

|   | Ítem evaluable | 0 puntos | 1 punto | 2 puntos | 3 puntos |
|---|---|---|---|---|---|---|
| 1 | **Entrega en tiempo y forma** | No se entrega, o se entrega sin poder ejecutarse en absoluto | Se entrega tarde sin justificación, o faltan archivos/instrucciones para poder arrancarla | Se entrega en plazo y se puede poner en marcha siguiendo tus instrucciones | Se entrega en plazo, arranca a la primera, e incluye instrucciones claras (README) y datos de prueba |
| 2 | **Arquitectura del proyecto** (MVC, namespaces, Composer, `.gitignore`) | No hay separación en Modelo/Vista/Controlador, o el proyecto no usa namespaces ni Composer | La estructura existe pero está mal aplicada (lógica de negocio en las vistas, controladores que acceden directamente a la BD sin pasar por el modelo...) | Estructura MVC correcta, con namespaces y autoload PSR-4 funcionando, y credenciales fuera del control de versiones | Todo lo anterior, además de una organización de carpetas y nombres de clase especialmente claros y coherentes |
| 3 | **Capa de acceso a datos** (`Database` + `BaseModel`) | No existe una capa común: cada modelo crea su propia conexión PDO | Existe pero se usa de forma inconsistente (algunos modelos la usan, otros no; hay código PDO duplicado en varios sitios) | `Database` y `BaseModel` existen y todos los modelos las usan correctamente, sin duplicar código de conexión | Además de lo anterior, la capa está bien diseñada (métodos genéricos reutilizables, manejo claro de errores) |
| 4 | **Autenticación de usuarios** (registro, login, logout, sesiones) | No funciona, o las contraseñas se guardan sin `password_hash()` | Funciona parcialmente: falta alguna operación (logout, por ejemplo), o hay fallos puntuales de validación | Registro, login y logout funcionan correctamente, con `password_hash()`/`password_verify()` y sesión bien gestionada | Además, valida bien los casos límite (email duplicado, contraseña vacía, credenciales incorrectas con mensajes claros) |
| 5 | **CRUD de publicaciones** (crear, listar, editar, borrar) | Falta alguna operación, o ninguna funciona de forma fiable | Las operaciones básicas funcionan, pero con errores en casos concretos (por ejemplo, el formulario de edición no precarga los datos) | Las cuatro operaciones funcionan correctamente y de forma consistente | Además, incluye validaciones cuidadas (campos obligatorios, mensajes de error claros al usuario) |
| 6 | **Autorización por propiedad** (solo el autor edita/borra lo suyo) | No existe ningún control: cualquier usuario puede editar o borrar publicaciones ajenas | El control existe pero es incompleto (por ejemplo, protege el botón en la vista, pero no la acción si se manipula la URL a mano) | Un usuario no puede editar ni borrar publicaciones ajenas, ni siquiera manipulando la URL o el formulario directamente | Además, gestiona con elegancia el caso de intento no autorizado (mensaje claro, código de estado HTTP apropiado, sin romper la aplicación) |
| 7 | **Comentarios** (relación uno-a-muchos) | No implementados, o no se asocian correctamente a la publicación y al usuario | Funcionan pero con fallos (por ejemplo, se puede comentar sin estar logueado, o el `user_id` se toma de un campo manipulable en vez de la sesión) | Los comentarios se muestran y se crean correctamente, asociados a la publicación y al usuario de la sesión | Además, están bien presentados (orden cronológico claro, buena integración visual en la vista de detalle) |
| 8 | **Buscador / filtrado de publicaciones** | No implementado | Implementado pero poco fiable (falla con ciertos términos, no usa sentencias preparadas, resultados incorrectos) | Filtra correctamente por título o categoría, con sentencias preparadas | Además, combina bien varios criterios de búsqueda o mejora la experiencia de uso (por ejemplo, mantiene el término buscado en el formulario) |
| 9 | **Seguridad** (sentencias preparadas, `htmlspecialchars()`, CSRF) | Hay consultas construidas por concatenación, o no se escapa la salida en las vistas, o no hay token CSRF en ningún formulario | Se aplica de forma parcial: algunas consultas o vistas están protegidas y otras no | Todas las consultas usan sentencias preparadas, toda salida a HTML pasa por `htmlspecialchars()`, y todos los formularios de modificación llevan y comprueban el token CSRF | Además, demuestra haber pensado en algún caso límite extra de seguridad no explícitamente pedido en el enunciado |
| 10 | **Calidad y organización del código** | Código desordenado, nombres poco claros, duplicación evidente entre archivos | Es legible pero con inconsistencias (mezcla de estilos, nombres poco descriptivos en partes del proyecto) | Nombres claros y consistentes, sin duplicación relevante, código legible de principio a fin | Además, el código está especialmente bien comentado o estructurado donde de verdad aporta valor (sin comentarios superfluos) |
| 11 | **Testing** | No entrega el documento de testing | Entrega el documento pero no respeta el formato especificado o no realiza las pruebas sobre la aplicación | Entrega el documento y realiza las pruebas sobre la aplicación, pero las pruebas son pocas o no figuran tests importantes | Entrega el documento, realiza las pruebas sobre la aplicación y no se deja ninguna prueba importante |
| 12 | **Control de versiones** | No usa Git/GitHub/GitLab o no entrega la dirección del repositorio público | Usa Git pero apenas hace commits a lo largo de todo el desarrollo | Usa Git y hace commits con frecuencia, pero con nombres irrelevantes o confusos | Usa Git de forma adecuada para permitir un correcto seguimiento del proyecto y la resolución de problemas si fuera necesario |
| 13 | **Defensa del código** (preguntas orales o escritas sin IA) | No sabe explicar decisiones básicas de su propio código | Explica algunas partes, pero con inseguridad o errores conceptuales relevantes | Explica con soltura las decisiones principales de su código y responde bien a preguntas no anticipadas | Además, es capaz de razonar alternativas ("también podría haberlo hecho así, pero elegí esto porque...") |

<div style="color: red; font-size: 125%" markdown="1">**ATENCIÓN:** Si el ítem 13 no se supera (calificación inferior a 2), toda la práctica puede darse por suspensa, independientemente de la calificación obtenida, puesto que no puede garantizarse su autoría.
</div>

#### Ampliación de nota: rutas limpias (apartado 2.8.8)

Este ítem no resta si no se ha hecho, y no forma parte del total de puntos: se suma aparte, después de calcular la nota anterior.

| Nivel | Descripción | Puntos |
|---|---|---|
| No implementado | — | +0 |
| Implementado de forma básica | Funciona para al menos un controlador y una acción con parámetro | +0,5 |
| Implementado correctamente | Funciona de forma genérica para cualquier controlador, acción y parámetro | +1 |
