---
layout: page
title: 1.10 Práctica final
permalink: /php/practica.html
nav_order: 10
has_children: false
parent: 1 Programación web con PHP
grand_parent: Desarrollo web full stack
---


## 1.10. Práctica final del tema 1
{: .no_toc }

- TOC
{:toc}

Para terminar la unidad didáctica de PHP vamos a proponer un caso prácticos más completo para que pongas manos a la obra.

Se trata de modificar y mejorar, paso a paso, [la aplicación de la Biblioteca](../php/mvc/#175-una-implementación-completa-biblioteca).

### 1.10.1. Control de acceso de usuarios con sesiones

Objetivo: Añadir a la [Biblioteca](../php/mvc/#175-una-implementación-completa-biblioteca) un sistema básico de autenticación y autorización.

Tareas:

* **Crear tabla *usuarios* en la BD**: crea una tabla con campos idUsuario, nombreUsuario y password (encriptado con password_hash de PHP).
* **Crear formulario de login**: vista *views/usuario/login.php* con campos usuario y contraseña.
* **Crar modelo *Usuario***:
   * Método *checkLogin*(*$nombreUsuario, $password*) que verifique las credenciales.
* **Iniciar sesiones**:
   * En *index.php*, inicia la sesión con session_start().
   * Si el usuario está logueado, guarda su id y nombre en $_SESSION.
* **Proteger acciones**:
   * Sólo permitir insertar, modificar o borrar libros/autores si el usuario está logueado.
   * En caso contrario, redirigir a la vista de login con un mensaje de error.
* **Cerrar sesión**: añade un enlace “Cerrar sesión” en el menú de navegación.

### 1.10.2. Capa de abstracción de datos

Objetivo: Que los modelos no dependan de PDO ni de la base de datos concreta.

Tareas: 

* **Crea una clase Database** en *core/Database.php* que:
   * Tenga un constructor que establezca la conexión con la base de datos.
   * Defina métodos genéricos como *query($sql, $params = [])* y *fetchAll()*, *fetch()*. Estos últimos devolverán un array con los datos de la consulta (o *null* si la consulta no devolvió nada).
* **Modifica el modelo *Libro*** para que use la clase *Database* en lugar de crear su propio objeto PDO.
* **Comprueba que la aplicación sigue funcionando igual**.

### 1.10.3. CRUD completo de Autores

Objetivo: Poder crear, leer, actualizar y borrar autores.

Tareas: Añadir a la aplicación el mantenimiento de Autores de libros:

* **Crear nuevo modelo *Autor*** con los métodos: *insert(), update(), delete(), getAll(), get($id)*.
* **Añadir métodos necesarios al controlador *index.php***:
   * *mostrarListaAutores()*
   * *formularioInsertarAutor()*
   * *insertarAutor()*
   * *formularioModificarAutor()*
   * *modificarAutor()*
   * *borrarAutor()*
* **Crear las vistas necesarias** en views/autor/:
   * *all.php* para listar y enlazar a modificar/borrar, igual que en libros.
   * *form.php* para insertar o editar, igual que en libros.
* **Añadir el enlace “Autores” en el menú de navegación** (ya existe, pero ahora tendrá funcionalidad).

### 1.10.4. Modelo genérico base

Objetivo: Evitar duplicar código en los modelos.

Tareas: 

* **Crea una clase abstracta *BaseModel*** en *models/BaseModel.php* con métodos comunes como:
   * Constructor que reciba el nombre de la tabla y el nombre de la columna clave primaria.
   * *get($id)*
   * *getAll()*
   * *delete($id)*
* **Haz que los modelos *Libro* y *Autor* hereden de *BaseModel*** y utilicen estos métodos en lugar de reescribirlos.
* **Adapta las consultas específicas** (por ejemplo, *search* de *Libro*) para que convivan con esta herencia.

### 1.10.5. Controladores múltiples

Objetivo: Separar las responsabilidades de cada entidad.

Tareas:

* **Crea los controladores** *controllers/LibrosController.php* y *controllers/AutoresController.php*.
* **Mueve a cada uno de ellos** los metodos correspondientes (listar, insertar, modificar, borrar).
* **Crea un *index.php*** nuevo que llame al controlador adecuado a partir de la variable *controller* que vendrá, junto con *action* en la petición POST o GET. Algo así:

```php
$controller = $_REQUEST['controller'] ?? 'Libros';
$action = $_REQUEST['action'] ?? 'index';
$controllerClass = $controller . 'Controller';
require "controllers/$controllerClass.php";
(new $controllerClass())->$action();
```

* **Ajusta todos los enlaces en las vistas** para pasar el nombre del controlador como parámetro, no solo la acción (*?controller=Autores&action=mostrarListaAutores*).

### 1.10.6. Archivo de configuración

Objetivo: Posibilitar el cambio de las credenciales de la base de datos sin tocar el código.

Tareas:

* **Crea un archivo *config.php*** que contenga el *return* de un array como este:

```php
return [
    'db' => [
        'host' => 'mariadb',
        'dbname' => 'nombre-base-de-datos',
        'user' => 'tu-usuario',
        'pass' => 'tu-contraseña',
        'charset' => 'utf8mb4'
    ]
];
```

* **En *Database.php*, usa *require "config.php"*** para obtener el array, y conéctate a la base de datos usando esas credenciales.
* **Comprueba que cambiando el archivo de configuración** (por ejemplo, otra contraseña) la aplicación sigue funcionando sin tocar los modelos.

### 1.10.7. Enrutador

(Este paso es optativo)

*Advertencia: ¡este paso puede resultar complicadillo!*

Objetivo: crear un enrutador como el de los frameworks avanzados para construir rutas limpias.

Recuerda que un enrutador moderno debería ser capaz de coger una URL limpia, como esta:

<code>
https://mi-servidor/book/delete/37
</code>

...y deducir de ahí que hay que invocar el método *borrarLibro(37)* del controlador de libros.

Debería funcionar con cualquier ruta construida de ese modo y cualquier cantidad de controladores. A ver si se te ocurre algo para incorporar un enrutador como este a la aplicación.

(No sé si te has dado cuenta, pero, poco a poco, hemos ido construyendo nuestro porpio *mini-framework* casero para programar aplicaciones MVC)