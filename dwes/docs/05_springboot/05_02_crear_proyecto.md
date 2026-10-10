---
layout: page
title: 5.2 Crear un proyecto Spring Boot
permalink: /springboot/crear-proyecto/
nav_order: 2
has_children: true
parent: 5 SSR y API REST con Spring Boot
grand_parent: Desarrollo Web en Entorno Servidor
---

## 5.2. Crear un proyecto Spring Boot
{: .no_toc }

- TOC
{:toc}


[Descargar presentación](https://www.dropbox.com/scl/fi/mark0en03rhbv00qs9qie/05_02_crear_proyecto.pdf?rlkey=3ykkuvoego946uheumtibygoq&st=6hcthp6r&dl=0){: .btn .btn-primary }


Vamos a ponernos directamente en marcha y a crear un primero proyecto con Spring Boot.

### 5.2.1. Spring Initializr

La forma más rápida de crear un proyecto es **Spring Initializr** en [https://start.spring.io/](https://start.spring.io/), una herramienta diseñada para lanzar proyectos de Spring Boot con un mínimo de configuración. Muchos IDEs ya lo incluyen (IntelliJ IDEA, VS Code con el plugin de Spring, etc).

Al lanzar Spring Initializr te hará algunas preguntas:
- **Project:** Maven
- **Language:** Java
- **Spring Boot:** elige la última versión estable (3.x actualmente, compatible con Java 17+)
- **Dependencies:** selecciona las que necesites según el tipo de aplicación (ver siguiente sección).

#### Dependencias habituales

| Dependencia | Cuándo usarla |
| :--- | :--- |
| **Spring Web** | Siempre: habilita el servidor web y los controladores |
| **Spring Data JPA** | Para acceso a BD con ORM (equivale a Eloquent) |
| **MySQL Driver** | Si usas MySQL/MariaDB |
| **Thymeleaf** | Solo en aplicaciones SSR (equivale a Blade) |
| **Spring Security** | Para autenticación y autorización |
| **Lombok** | Opcional: genera getters/setters automáticamente, menos código |

#### Estructura del proyecto

Igual que los proyectos de Laravel tienen una **estructura de carpetas** muy definida, Spring Boot tiene la suya propia:

```text
src/
  main/
    java/
      com/ejemplo/
        MiAplicacion.java       ← Clase principal
        entity/                 ← Entidades JPA (modelos)
        repository/             ← Repositorios (acceso a BD)
        service/                ← Servicios (lógica de negocio)
        controller/             ← Controladores HTTP
    resources/
      templates/                ← Vistas Thymeleaf (solo SSR)
      static/                   ← CSS, JS, imágenes
      application.properties    ← Configuración
```

### 5.2.2. La clase principal

Estamos en Java, así que necesitas un `main()`. Se coloca en la clase que lanzará la ejecución de Spring Boot. Siempre se hace del mismo modo:

```java
@SpringBootApplication
public class MiAplicacion {
    public static void main(String[] args) {
        SpringApplication.run(MiAplicacion.class, args);  // Aquí se lanza Spring Boot
    }
}
```
La anotación `@SpringBootApplication` activa el **autoescaneo de componentes**, es decir, que Spring buscará clases con anotaciones como `@Controller`, `@Service`, `@Repository`, etc. y las instanciará y conectará entre sí automáticamente.


### 5.2.3. Configuración: application.properties

Equivale al `.env` de Laravel. Aquí se definen las **propiedades de la conexión a la base de datos** entre otros parámetros:

```properties
# Conexión a MySQL
spring.datasource.url=jdbc:mysql://localhost:3306/mi_base_de_datos
spring.datasource.username=root
spring.datasource.password=mi_password

# Indica a Hibernate que genere/actualice las tablas automáticamente según las Entities
# (equivale a las migraciones de Laravel, pero sin control de versiones)
spring.jpa.hibernate.ddl-auto=update

# Mostrar el SQL generado en consola (útil en desarrollo)
spring.jpa.show-sql=true
```

* **Hibernate/JPA** es el equivalente de Spring Boot a **Eloquent** en Laravel, es decir, es el ORM que mapeará automáticamente datos de la base de datos en objetos de nuestra aplicación, enseguida veremos como (en realidad, se trata de una evolución de Hibernate llamada *Spring Boot JPA*, pero no entraremos en tantos detalles).
* `spring.datasource.url=jdbc:mysql://localhost/test` define la dirección de la base de datos (tipo de base de datos, servidor y nombre de la base de datos).
* `spring.datasource.username=root` define el nombre del usuario de la base de datos.
* `spring.datasource.password=1234` $\rightarrow$ define... bueno, ¡ya te lo imaginas, ¿no?!
* `spring.jpa.hibernate.ddl-auto=update` permite que Spring, con Hibernate, genere automáticamente las tablas de la base de datos, si no existen.

Hibernate tomará como referencia las Entities que hayamos definido y creará las tablas a partir de ahí. El valor "update" implica que, si hacemos un cambio en una Entity, Hibernate modificará también la estructura de la tabla. Por lo tanto:
* si la tabla no existe, Hibernate la crea
* si añadimos un campo nuevo, Hibernate añade la columna
* si modificamos la entidad, Hibernate intenta adaptar la tabla

Esto resulta extremadamente útil durante el desarrollo, ya que evita tener que crear manualmente las tablas cada vez que cambiamos el modelo de datos.

`ddl-auto` admite otros valores distintos de "update", como:
* `none` -> No realiza cambios en la base de datos
* `validate` -> Comprueba que la estructura coincide
* `update` -> Actualiza la estructura si es necesario
* `create` -> Elimina y vuelve a crear las tablas
* `create-drop` -> Crea las tablas al iniciar y las borra al cerrar

Durante el desarrollo suele utilizarse `update` o `create`. En entornos de producción (cuando una aplicación ya está online y funcionando), normalmente se emplea `none` o `validate`.

---

### 5.2.4. Los modelos: entities y repositories

#### Entity (= medio modelo Eloquent)

Spring Boot trata los modelos de forma un poco diferente que Laravel porque *divide el papel de los modelos de Laravel en dos partes*:

1. **Entity**: Representa los datos como objetos.
2. **Repository**: Proporciona los métodos para acceder a esos datos (insertar, buscar, borrar, etc).

Por tanto, una Entity es una clase Java que **representa una tabla de la base de datos**.

Observa en este ejemplo las anotaciones JPA que mapean los atributos a columnas, como `@Column` o `@Id`:

```java
import jakarta.persistence.*;

@Entity
@Table(name = "products")
public class Product {

    @Id
    @GeneratedValue(strategy = GenerationType.IDENTITY)
    private Long id;

    @Column(nullable = false)
    private String name;

    @Column
    private String description;

    @Column(nullable = false)
    private Double price;

    // Constructor por defecto (obligatorio para JPA)
    public Product() {}

    // Constructor, getters y setters...
    public Long getId() { return id; }
    public String getName() { return name; }
    public void setName(String name) { this.name = name; }
    public Double getPrice() { return price; }
    public void setPrice(Double price) { this.price = price; }
    // ... etc
}
```

> **TRUCO**
> Si añades ***Lombok*** al proyecto, puedes reemplazar todos los getters/setters por una sola anotación `@Data` encima de la clase y ahorrar mucho código repetitivo.

#### Repository (= el otro medio modelo de Laravel)

Los repositories de Spring Boot implementan los **métodos para acceder a los datos**.

Salvo que queramos añadir algún método raro, con extender `JpaRepository` es suficiente para disponer de todos los métodos automáticamente. Obsérvalo en este ejemplo.

```java
import org.springframework.data.jpa.repository.JpaRepository;

// ¡OJO! El repositorio es un interface, no una clase
public interface ProductRepository extends JpaRepository<Product, Long> {
    // Spring genera automáticamente: findAll(), findById(), save(), deleteById()...
    // Puedes añadir métodos personalizados. Por ejemplo:
    List<Product> findByNameContaining(String keyword);
}
```

Si lo comparamos con Laravel:

* Con Eloquent hacemos `Product::all()`
* Con los repositories de Spring Boot hacemos: `productRepository.findAll()`

La idea, como ves, es idéntica y solo cambia un poco la forma en la que se implementa.


### 5.2.5. Los controladores: sevices y controllers

#### La capa de servicio

En Laravel, se suele escribir la lógica directamente en el controlador. 

En Spring Boot existe una **capa intermedia** llamada **Service** que actúa entre el controlador y el repository. Mírala en acción en este ejemplo:

```java
import org.springframework.stereotype.Service;
import java.util.List;

@Service
public class ProductService {

    private final ProductRepository repository;

    // Spring inyecta automáticamente el repository (=modelo) en el constructor.
    // Lo guardaremos en una propiedad de la clase.
    public ProductService(ProductRepository repository) {
        this.repository = repository;
    }

    // Implementaremos varios de los métodos típicos de los controladores
    public List<Product> findAll() {
        return repository.findAll();
    }

    public Product findById(Long id) {
        return repository.findById(id)
               .orElseThrow(() -> new RuntimeException("Producto no encontrado"));
    }

    public Product save(Product product) {
        return repository.save(product);
    }

    public void delete(Long id) {
        repository.deleteById(id);
    }
}
```

#### Controladores tipo SSR para generar vistas (@Controller)

Un **controlador convencional** para aplicaciones SSR usa la anotación `@Controller` y devuelve el **nombre de una plantilla** Thymeleaf (no JSON). 

Los datos se pasan a la vista a través del objeto `Model`, que funciona como los arrays o como el método `compact()` de Laravel.

Lo ves mejor en este ejemplo. **Observa bien el uso de la anotación `@GetMapping`, porque así es como Spring Boot hace el enrutado**.

```java
import org.springframework.stereotype.Controller;
import org.springframework.ui.Model;
import org.springframework.web.bind.annotation.*;

@Controller
@RequestMapping("/products")
public class ProductController {

    private final ProductService service;

    public ProductController(ProductService service) {
        this.service = service;
    }

    // GET /products → lista (equivale a index() de Laravel)
    @GetMapping
    public String index(Model model) {
        model.addAttribute("products", service.findAll());
        return "products/index"; // → templates/products/index.html
    }

    // GET /products/{id} → detalle (equivale a show())
    @GetMapping("/{id}")
    public String show(@PathVariable Long id, Model model) {
        model.addAttribute("product", service.findById(id));
        return "products/show";
    }

    // GET /products/nuevo → formulario de creación (equivale a create())
    @GetMapping("/nuevo")
    public String create(Model model) {
        model.addAttribute("product", new Product());
        return "products/form";
    }

    // POST /products/guardar → guardar nuevo o editado (equivale a store()/update())
    @PostMapping("/guardar")
    public String save(@ModelAttribute Product product) {
        service.save(product);
        return "redirect:/products";
    }

    // GET /products/editar/{id} → formulario de edición (equivale a edit())
    @GetMapping("/editar/{id}")
    public String edit(@PathVariable Long id, Model model) {
        model.addAttribute("product", service.findById(id));
        return "products/form";
    }

    // GET /products/eliminar/{id} → borrar (equivale a destroy())
    @GetMapping("/eliminar/{id}")
    public String delete(@PathVariable Long id) {
        service.delete(id);
        return "redirect:/products";
    }
}
```

---

#### Controladores para API REST (@RestController)

Si en lugar de una aplicación SSR quieres construir una API REST que devuelva JSON (igual que hicimos con Laravel), el proceso es casi idéntico y solo cambia la anotación del controlador y lo que se devuelve.

| | `@Controller` (SSR) | `@RestController` (API) |
| :--- | :--- | :--- |
| Qué devuelve | Nombre de plantilla Thymeleaf (HTML) | Objetos Java → Se convierten a JSON automáticamente |
| `return` | `"products/index"` | `product` o `List<Product>` |
| Usa `Model` | Sí | No |
| Clientes | Navegador web | Postman, apps móviles, frontend SPA |

De nuevo, lo vemos mejor con un ejemplo sencillo:

```java
import org.springframework.web.bind.annotation.*;
import org.springframework.http.ResponseEntity;
import java.util.List;

@RestController
@RequestMapping("/api/products")
public class ProductApiController {

    private final ProductService service;

    public ProductApiController(ProductService service) {
        this.service = service;
    }

    // GET /api/products → devuelve JSON con todos los productos
    @GetMapping
    public List<Product> index() {
        return service.findAll();
    }

    // GET /api/products/{id} → devuelve JSON con un producto
    @GetMapping("/{id}")
    public ResponseEntity<Product> show(@PathVariable Long id) {
        return ResponseEntity.ok(service.findById(id));
    }

    // POST /api/products → crea un producto (recibe JSON en el body)
    @PostMapping
    public ResponseEntity<Product> store(@RequestBody Product product) {
        Product saved = service.save(product);
        return ResponseEntity.status(201).body(saved);
    }

    // PUT /api/products/{id} → actualiza un producto
    @PutMapping("/{id}")
    public ResponseEntity<Product> update(@PathVariable Long id, @RequestBody Product product) {
        product.setId(id);
        return ResponseEntity.ok(service.save(product));
    }

    // DELETE /api/products/{id} → elimina un producto
    @DeleteMapping("/{id}")
    public ResponseEntity<Void> destroy(@PathVariable Long id) {
        service.delete(id);
        return ResponseEntity.noContent().build(); // Código 204
    }
}
```


### 5.2.6. Vistas: Thymeleaf

Si en Laravel teníamos Blade, en Spring Boot tenemos **Thymeleaf para ayudarnos a generar vistas**.

Las vistas son archivos `.html` que Thymeleaf procesa antes de enviarlos al navegador.

Como ya conoces Blade, comprender Thymeleaf es un juego de niños, porque hace lo mismo escrito de forma diferente:

| Thymeleaf | Blade (equivalente) | Para qué |
| :--- | :--- | :--- |
| `th:text="${var}"` | `{% raw %}{{ $var }}{% endraw %}` | Mostrar una variable |
| `th:each="item : ${list}"` | `@foreach($list as $item)` | Bucle |
| `th:if="${condicion}"` | `@if($condicion)` | Condicional |
| `th:href="@{/ruta}"` | `route('nombre')` | Enlace dinámico |
| `th:action="@{/ruta}"` | `action="{% raw %}{{ route(...) }}{% endraw %}"` | Acción de formulario |
| `th:field="*{campo}"` | `name="campo"` | Campo de formulario |
| `th:replace="~{frag :: nombre}"` | `@include('partial')` | Incluir fragmento |

Obsérvalo en esta vista de ejemplo que muestra una lista productos:

```html
<!DOCTYPE html>
<html xmlns:th="http://www.thymeleaf.org">
<head><title>Productos</title></head>
<body>
    <h1>Lista de productos</h1>
    <a th:href="@{/products/nuevo}">Nuevo producto</a>
    <table>
        <tr th:each="product : ${products}">
            <td th:text="${product.name}"></td>
            <td th:text="${product.price}"></td>
            <td>
                <a th:href="@{/products/editar/{id}(id=${product.id})}">Editar</a>
                <a th:href="@{/products/eliminar/{id}(id=${product.id})}">Eliminar</a>
            </td>
        </tr>
    </table>
</body>
</html>
```

#### Cómo enviar datos del controlador a la vista 

Para enviar datos del controlador a la vista debes prepararlos, como es lógico, en el controlador:

```php
// Controlador de Usuarios (fragmento)
public String listarUsuarios(Model model) {
   model.addAttribute("usuarios", usuarioService.findAll());
   return "usuariosList";  
}
```

La vista debe llamarse `usuariosList.html` y recibirá en la variable `usuarios` la lista de usuarios:

```html
<!-- Vista usuariosList.html (fragmento) -->
<table>
   <tr th:each="usuario : ${usuarios}">
       <td th:text="${usuario.nombre}"></td>
       <td th:text="${usuario.email}"></td>
   </tr>
</table>
```

#### Atributos Thymeleaf

Los **atributos de Thymeleaf** se pueden usar en cualquier elemento HTML. Se distinguen de los atributos normales de HTML porque **empiezan por `th:`** y pueden servir, entre otras cosas, para:

* Mostrar datos inyectados desde el controlador

    ```html
        <p th:text="${usuario.nombre}"></p>
    ```

* Iterar sobre colecciones:

    ```html
        <tr th:each="usuario : ${usuarios}">
                <td th:text="${usuario.nombre}"></td>
    ```

* Procesar condicionales para mostrar u ocultar contenido:

    ```html
        <p th:if="${usuario.activo}">Activo</p>
    ```

* Integrarse en formularios para indicar el action o el contenido de un input

    ```html
        <form th:action="@{/usuarios}" method="post">
            <input type="text" th:field="*{nombre}" />
        </form>
    ```

* Generar enlaces con URLs creadas automáticamente.

    ```html
        <a th:href="@{/usuarios/{id}(id=${usuario.id})}">Ver</a>
    ```

### 5.2.7. Chuleta de anotaciones clave de Spring Boot

En esta tabla os resumimos las anotaciones más importantes que hemos ido viendo a lo largo de este recorrido rápido por Spring Boot:

| Anotación | Equivalente en Laravel | Para qué sirve |
| :--- | :--- | :--- |
| `@SpringBootApplication` | — | Clase principal, punto de inicio |
| `@Controller` | — | Controlador que devuelve vistas (SSR) |
| `@RestController` | — | Controlador que devuelve JSON (API) |
| `@Service` | — | Lógica de negocio (capa Service) |
| `@Repository` | — | Acceso a BD (aunque JpaRepository ya la incluye) |
| `@Entity` | `extends Model` | Clase mapeada a una tabla |
| `@RequestMapping` | `Route::` en `web.php` | Prefijo de ruta para el controlador |
| `@GetMapping` | `Route::get()` | Endpoint GET |
| `@PostMapping` | `Route::post()` | Endpoint POST |
| `@PutMapping` | `Route::put()` | Endpoint PUT |
| `@DeleteMapping` | `Route::delete()` | Endpoint DELETE |
| `@PathVariable` | `$id` en método de controlador | Variable de la URL (`/product/{id}`) |
| `@RequestBody` | `$request->all()` | Cuerpo JSON de la petición (API) |
| `@ModelAttribute` | `$request->all()` | Datos de formulario HTML (SSR) |
| `@Autowired` | Inyección automática de Laravel | Inyección de dependencias |
