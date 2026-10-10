---
layout: page
title: 5.5 Ejemplo completo. CRUD de usuarios
permalink: /springboot/ejemplo-crud
nav_order: 5
has_children: true
parent: 5 SSR y API REST con Spring Boot
grand_parent: Desarrollo Web en Entorno Servidor
---

## 5.5. Ejemplo completo: CRUD de usuarios
{: .no_toc }

- TOC
{:toc}

Con todo lo que hemos visto, ya estamos en condiciones de crear nuestra primera aplicación web 100% funcional con Spring Boot. Verlo todo bien reunido hará que todos los conceptos que hemos recorrido poco a poco queden mucho más claros.

Vamos a construir un ejemplo sencillo para hacer un CRUD de una tabla de usuarios, que tendrá, para simplificar, solo estos tres campos:
* id
* nombre
* email

Vamos a construir una aplicación Spring Boot típica, con el código organizado en estas capas:
* **Entity** -> representa la tabla de la base de datos (usuarios)
* **Repository** -> acceso a datos
* **Service** -> lógica de negocio
* **Controller** -> captura las peticiones y llama a los servicios adecuados
* **Vistas** -> renderiza la salida HTML

### 5.5.1. La Entity Usuario

Una Entity, como sabemos, representa una de las tablas que se almacenan en la base de datos. En nuestro caso, como trabajamos con usuarios, nuestra Entity es una `class Usuario` con este aspecto:

```java
import jakarta.persistence.*;

@Entity
@Table(name = "usuarios")
public class Usuario {

    @Id
    @GeneratedValue(strategy = GenerationType.IDENTITY)
    private Long id;

    private String nombre;
    private String email;

    public Usuario() {}

    public Usuario(String nombre, String email) {
        this.nombre = nombre;
        this.email = email;
    }

    public Long getId() {
        return id;
    }

    public String getNombre() {
        return nombre;
    }

    public String getEmail() {
        return email;
    }

    public void setNombre(String nombre) {
        this.nombre = nombre;
    }

    public void setEmail(String email) {
        this.email = email;
    }
}
```

### 5.5.2. El Repository

El Repository, como ya hemos explicado, es la capa que se encarga de acceder a la base de datos.

El repositorio para usuarios se crea simplemente extendiendo la interfaz `JpaRepository`.

```java
import org.springframework.data.jpa.repository.JpaRepository;

public interface UsuarioRepository extends JpaRepository<Usuario, Long> {
}
```

¡Y eso es todo! Spring genera automáticamente los métodos `findAll()`, `findById()`, `save()`, `deleteById()` y otros muchos para la tabla de usuarios.

### 5.5.3. El Service

Un Service contiene la lógica de negocio de la aplicación, que en Laravel suele ir colocada en el controlador. 

Aquí se establece cómo se gestionan los usuarios. Observa que nuestro código se limita a invocar métodos del Repository, sin hacer realmente nada nuevo. Muchos Services son así de simples.

```java
import org.springframework.stereotype.Service;
import java.util.List;

@Service
public class UsuarioService {

    private final UsuarioRepository repository;

    public UsuarioService(UsuarioRepository repository) {
        this.repository = repository;
    }

    public List<Usuario> obtenerTodos() {
        return repository.findAll();
    }

    public Usuario obtenerPorId(Long id) {
        // Si el id no existe, devolverá null
        return repository.findById(id).orElse(null);
    }

    public Usuario guardar(Usuario usuario) {
        return repository.save(usuario);
    }

    public void eliminar(Long id) {
        repository.deleteById(id);
    }
}
```

### 5.5.4. El Controller

El Controller es la capa que expone los endpoints de la aplicación, es decir, el lugar donde se enlazan los endpoints (como `"GET /usuarios/3"` o cualquier otro endpoint) con el código Java.

El controller usará, por un lado, el Service de usuarios (para acceder a los datos) y, por otro, las vistas (para generar las salidas HTML).

```java
import org.springframework.stereotype.Controller;
import org.springframework.ui.Model;
import org.springframework.web.bind.annotation.*;

@Controller
@RequestMapping("/usuarios")
public class UsuarioController {

    private final UsuarioService service;

    public UsuarioController(UsuarioService service) {
        this.service = service;
    }

    // LISTAR USUARIOS
    @GetMapping("")
    public String listarUsuarios(Model model) {
        model.addAttribute("usuarios", service.obtenerTodos());
        return "usuarioList";
    }

    // MOSTRAR UN USUARIO
    @GetMapping("/{id}")
    public String verDetalle(@PathVariable Long id, Model model) {
        Usuario usuario = service.obtenerPorId(id);
        if (usuario == null) {
            return "redirect:/usuarios";
        }
        model.addAttribute("usuario", usuario);
        return "usuarioDetalle";
    }

    // FORMULARIO CREAR
    @GetMapping("/nuevo")
    public String mostrarFormularioNuevo(Model model) {
        model.addAttribute("usuario", new Usuario());
        return "usuarioForm";
    }

    // GUARDAR (CREATE / UPDATE)
    @PostMapping("/guardar")
    public String guardarUsuario(@ModelAttribute Usuario usuario) {
        service.guardar(usuario);
        return "redirect:/usuarios";
    }

    // FORMULARIO EDITAR
    @GetMapping("/editar/{id}")
    public String mostrarFormularioEditar(@PathVariable Long id, Model model) {
        Usuario usuario = service.obtenerPorId(id);
        model.addAttribute("usuario", usuario);
        return "usuarioForm";
    }

    // ELIMINAR
    @GetMapping("/eliminar/{id}")
    public String eliminarUsuario(@PathVariable Long id) {
        service.eliminar(id);
        return "redirect:/usuarios";
    }
}
```

Observa, en el código anterior, estas anotaciones importantes:
* `@Controller`: Indica a Spring Boot que esta clase define un controlador.
* `@RequestMapping("/usuarios")`: Define la ruta base de todos los métodos de este controlador.
* `@GetMapping`, `@PostMapping`: Asocian métodos HTTP con métodos Java. Fíjate que algunos llevan un parámetro, como `@GetMapping("/{id}")`. Eso significa que el endpoint incluirá un dato `"id"`, no solo el verbo HTTP y la ruta.
  Por ejemplo, en el caso de `@GetMapping("/{id}")`, significa que la petición HTTP debe tener esta forma: `GET /usuarios/id`
  El dato `"id"` de ese endpoint se usará para pasárselo al método `verDetalle()` del controlador. Por eso, si pedimos el endpoint `GET /usuarios/3`, el servidor sabe que tiene que consultar el usuario con $id = 3$ y mostrarnos una vista con su detalle.
* `@PathVariable`: Permite leer variables que se han pasado por la URL, como el $id = 3$ de `GET /usuarios/3`.
* `@ModelAttribute`: Permite recibir los datos de un formulario HTML empaquetados (mapeados) en un objeto de tipo `Usuario`.

Con el código de este controlador, ya tenemos construida una sencilla aplicación CRUD para la tabla de usuarios, con estos endpoints:
* `GET /usuarios`: Obtener una vista HTML con todos los usuarios
* `GET /usuarios/{id}`: Obtener una vista HTML con un usuario
* `GET /usuarios/nuevo`: Mostrar una vista HTML con un formulario para creación de un nuevo usuario
* `POST /usuarios/guardar`: Crear un nuevo usuario o modificar uno existente
* `GET /usuarios/editar/{id}`: Mostrar una vista HTML con un formulario para modificar un usuario que ya existe (por eso se le pasa un id)
* `GET /usuarios/eliminar/{id}`: Eliminar el usuario con ese id. Después de eliminar, redirigirá a `GET /usuarios` para volver a mostrar la lista de usuarios.

### 5.5.5. Las vistas

El controlador anterior usa 3 vistas:
* `usuarioList`: muestra la lista de usuarios. Añadiremos a esta vista varios links, para añadir usuarios nuevos (`GET /usuarios/nuevo`), modificar un usuario (`GET /usuarios/editar/{id}`), eliminar usuarios (`GET /usuarios/eliminar/{id}`) y ver el detalle de un usuario (`GET /usuarios/{id}`). Por lo tanto, ejercerá como vista principal de nuestra aplicación, porque desde aquí se puede hacer todo.
* `usuarioForm`: muestra un formulario para añadir un usuario nuevo. Reutilizaremos la misma vista para que nos permita editar un usuario existente.
* `usuarioDetalle`: muestra los datos de un solo usuario.

Vamos a ver el código de cada una de ellas.

#### Vista `src/main/resources/templates/usuarioList.html`

Esta, como te he dicho, es la vista principal, pues incluye toda la información y links para ejecutar el resto de acciones. Observa bien cómo los links no se crean con direcciones absolutas, sino con expresiones de Thymeleaf como `th:href="@{/usuarios/nuevo}"`.

```html
<!DOCTYPE html>
<html xmlns:th="http://www.thymeleaf.org">
<head>
    <title>Lista de usuarios</title>
    <meta charset="UTF-8">
</head>
<body>
    <h1>Lista de usuarios</h1>
    <a th:href="@{/usuarios/nuevo}">Añadir usuario</a>
    <br><br>
    <table border="1">
        <thead>
            <tr>
                <th>ID</th>
                <th>Nombre</th>
                <th>Email</th>
                <th>Acciones</th>
            </tr>
        </thead>
        <tbody>
            <tr th:each="usuario : ${usuarios}">
                <td th:text="${usuario.id}"></td>
                <!-- Si hacemos click en el nombre nos lleva a la vista detalle -->
                <td>
                    <a th:href="@{/usuarios/{id}(id=${usuario.id})}"
                       th:text="${usuario.nombre}">
                    </a>
                </td>
                <td th:text="${usuario.email}"></td>
                <td>
                    <a th:href="@{/usuarios/editar/{id}(id=${usuario.id})}">Editar</a>
                    <a th:href="@{/usuarios/eliminar/{id}(id=${usuario.id})}"
                       onclick="return confirm('¿Seguro que quieres eliminar este usuario?')">
                        Eliminar
                    </a>
                </td>
            </tr>
        </tbody>
    </table>
</body>
</html>
```

#### Vista `src/main/resources/templates/usuarioForm.html`

Como esta vista debe servirnos como formulario para añadir y para modificar usuarios, verás que el título se muestra con un condicional de tipo `(condición ? acción-true : acción-false)`. La "condición" de esa expresión consiste en mirar si existe un id de usuario asignado. Si es así, estamos tratando de modificar un usuario. Si no existe un id, es porque estamos tratando de añadir un usuario nuevo.

Observa también cómo tratan de rellenarse los inputs del formulario con el contenido del usuario. El asterisco en `th:field="*{nombre}"` le dice a Thymeleaf que, si existe un valor para `"nombre"`, debe mostrarlo en ese input y, si no existe, debe dejar el input en blanco.

Ese sencillo truco nos permite reutilizar el mismo formulario para añadir usuarios nuevos (el formulario saldrá en blanco) y para modificar usuarios existentes (el formulario saldrá relleno con los datos actuales del usuario).

```html
<!DOCTYPE html>
<html xmlns:th="http://www.thymeleaf.org">
<head>
    <title th:text="${usuario.id} == null ? 'Nuevo usuario' : 'Editar usuario'"></title>
    <meta charset="UTF-8">
</head>
<body>
    <h1 th:text="${usuario.id} == null ? 'Crear usuario' : 'Editar usuario'"></h1>
    <form th:action="@{/usuarios/guardar}" th:object="${usuario}" method="post">
        <!-- ID oculto para edición -->
        <input type="hidden" th:field="*{id}" />
        <div>
            <label>Nombre:</label><br>
            <input type="text" th:field="*{nombre}" required />
        </div>
        <br>
        <div>
            <label>Email:</label><br>
            <input type="email" th:field="*{email}" required />
        </div>
        <br>
        <button type="submit">Guardar</button>
    </form>
    <br>
    <a th:href="@{/usuarios}">Volver al listado</a>
</body>
</html>
```

#### Vista `src/main/resources/templates/usuarioDetalle.html`

Esta vista muestra el detalle de un usuario, un link para volver a la vista principal y otro link para modificar este usuario.

Es la vista más simple de las tres y no tiene demasiado sentido, porque los usuarios de esta pequeña aplicación apenas tienen datos. Sin embargo, en una aplicación real, donde un usuario pudiera tener muchos más campos, sería una vista importante para poder visualizar todos los campos del usuario que no se vieran en la lista de usuarios.

```html
<!DOCTYPE html>
<html xmlns:th="http://www.thymeleaf.org">
<head>
    <title>Detalle de usuario</title>
    <meta charset="UTF-8">
</head>
<body>
    <h1>Detalle del usuario</h1>
    <p>
        <strong>ID:</strong>
        <span th:text="${usuario.id}"></span>
    </p>
    <p>
        <strong>Nombre:</strong>
        <span th:text="${usuario.nombre}"></span>
    </p>
    <p>
        <strong>Email:</strong>
        <span th:text="${usuario.email}"></span>
    </p>
    <br>
    <a th:href="@{/usuarios}">Volver al listado</a>
    <a th:href="@{/usuarios/editar/{id}(id=${usuario.id})}">Editar</a>
</body>
</html>
```

### 5.5.6. Probando la aplicación

Para probar la aplicación, solo nos queda configurarla en `src/main/resources/application.properties`, donde tenemos que añadir los datos de la conexión a la BD. Si elegimos MySQL como base de datos, esos datos serán:

```properties
spring.datasource.url=jdbc:mysql://localhost:3306/tu_database
spring.datasource.username=tu_usuario
spring.datasource.password=tu_password
# No es necesario indicar el dialecto en Spring Boot 3.x, Hibernate lo detecta solo:
spring.jpa.hibernate.ddl-auto=update
spring.jpa.show-sql=true
```

> **¡ATENCIÓN!**
> El parámetro `spring.jpa.database-platform=org.hibernate.dialect.MySQL8Dialect` era necesario en versiones antiguas de Spring Boot pero está **obsoleto en Spring Boot 3.x**: Hibernate detecta automáticamente el dialecto a partir de la URL de conexión. Si lo pones, puede que salga un warning en la consola.

¡OJO! Tendrás que poner en marcha el servidor de MySQL por tu cuenta. Spring Boot tiene un servidor web embebido, pero no un servidor de MySQL.

Una vez hecho esto, ya tenemos una mini aplicación web terminada, lista para interactuar con un humano a través de un navegador web. Solo tienes que abrir tu navegador web preferido y probar el endpoint principal:

`http://localhost:8080/usuarios`

Esa URL te dará acceso al endpoint `GET /usuarios`, que te mostrará la lista de usuarios y links al resto de endpoints a los que responde el controlador de usuarios (añadir, modificar, borrar, etc.).

> **¡ATENCIÓN!**
> En el controlador anterior usamos `@GetMapping("/eliminar/{id}")` para borrar un usuario por comodidad en el ejemplo. En la práctica, eliminar un recurso con una petición GET es una mala práctica (cualquier spider o bot puede borrar datos sin querer). En una aplicación real deberías usar un formulario HTML con `method="post"` y, si quieres ser más estricto, un campo oculto `_method=DELETE` o un `@PostMapping("/eliminar/{id}")`.
