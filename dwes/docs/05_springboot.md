---
layout: page
title: 5 SSR y API REST con Spring Boot
permalink: /springboot/
nav_order: 5
has_children: true
parent: Desarrollo Web en Entorno Servidor
---

# 5. SSR y API REST con Spring Boot
{: .no_toc }

- TOC
{:toc}

<div style="text-align: center; padding: 20px; background-color: #ccc">
<a href="https://www.dropbox.com/scl/fi/xd1z2yyxbrqmt4j6quvvf/05_springboot.pdf?rlkey=8lgsfcw7w0sn74kt2ooxdnic7&st=vpn8u6xc&dl=0">
DESCARGAR PRESENTACIÓN
</a>
</div>

Ya conoces Laravel: has construido aplicaciones SSR con Blade, API RESTful devolviendo JSON y has trabajado con Eloquent ORM. **Spring Boot hace lo mismo, pero desde el ecosistema Java**.

La buena noticia es que los conceptos son idénticos: controladores, modelos, vistas, rutas, ORM, autenticación, JSON... Solo cambia el lenguaje (Java en lugar de PHP) y algunos detalles de la herramienta. Por ejemplo, cuando veas "Entity + Repository + Service" piensa en "Modelo + Eloquent" y encajará en tu cabeza a la primera.

## 5.1. ¿Qué es Spring Boot?

**Spring** es el framework Java más utilizado en entornos empresariales. **Spring Boot** es una capa encima de Spring que elimina casi toda la configuración manual y te proporciona *proyectos listos para ejecutarse en dos minutos*.

Igual que Laravel incluye servidores de desarrollo (como **Sail**), Spring Boot incluye un **servidor web embebido** (Tomcat). No necesitas instalar ni configurar ningún servidor externo.

#### Conceptos clave (Laravel vs Spring Boot)

Para introducir Spring Boot lo más deprisa posible, probablemente lo mejor sea ver un cuadro comparativo con lo que ya conoces (Laravel):

| Concepto | Laravel (PHP) | Spring Boot (Java) |
| :--- | :--- | :--- |
| ORM / Modelo | Eloquent Model | Entity + JPA/Hibernate |
| Acceso a BD | `Product::all()`, `find()` | `JpaRepository` (generado) |
| Lógica de negocio | Directamente en Controlador | Clase `@Service` |
| Controlador | `ProductController.php` | `ProductController.java` |
| Vistas (SSR) | Blade (`.blade.php`) | Thymeleaf (`.html`) |
| Rutas | `routes/web.php` | Anotaciones en el controlador |
| Configuración | `.env` + `config/` | `application.properties` |
| Migraciones | `php artisan migrate` | Hibernate `ddl-auto` (genera tablas) |

#### Características de Spring Boot

Spring Boot facilita el desarrollo principalmente de tres maneras:

1. Configura automáticamente muchas cosas. El framework analiza el proyecto y, a partir de las dependencias que utilizamos, intenta deducir qué configuración es necesaria.
2. Incluye un servidor web embebido. Esto significa que no necesitamos instalar ni configurar un servidor externo para ejecutar nuestra aplicación.
3. Simplifica la gestión de dependencias, algo que en proyectos Java grandes puede llegar a ser bastante tedioso.

Gracias a estas características, Spring Boot permite crear aplicaciones web y APIs REST de forma muy rápida, con menos código y configuración que en generaciones anteriores de frameworks Java.

Para entender mejor cómo funciona, conviene fijarse en cinco ideas fundamentales sobre las que se basa Spring Boot: 

- **autoconfiguración**
- **starter dependencies**
- **servidor web embebido**
- **inversión de control**
- **inyección de dependencias**

Vamos a verlas muy brevemente.

#### Autoconfiguración

Una de las características más importantes de Spring Boot es la autoconfiguración.

La idea es sencilla: el framework intenta detectar automáticamente qué necesita la aplicación y configura esos componentes por nosotros.

Por ejemplo, si en el proyecto añadimos una dependencia para trabajar con aplicaciones web, Spring Boot asume que necesitaremos un servidor HTTP y configura automáticamente todo lo necesario para que la aplicación pueda recibir peticiones web.

Del mismo modo, si añadimos dependencias para trabajar con bases de datos, Spring Boot prepara la infraestructura necesaria para gestionar conexiones, transacciones y otras tareas relacionadas.

Esto no significa que no se pueda personalizar la configuración, ni que la autoconfiguración siempre funcione a la perfección. En proyectos reales es bastante habitual que algo falle y haya que configurarlo a mano. Pero lo importante es que no es necesario configurar todo desde cero para empezar a trabajar.

#### Starter dependencies

Otro concepto muy importante en Spring Boot es el de starter dependencies.

En proyectos Java tradicionales, cuando queremos añadir una nueva funcionalidad solemos tener que incluir varias librerías distintas. A veces estas librerías dependen a su vez de otras, lo que puede generar configuraciones bastante complejas que se intentan gestionar con gestores de proyectos como Maven.

Spring Boot simplifica este proceso agrupando conjuntos de dependencias que suelen utilizarse juntas. Estos conjuntos se llaman starters.

Por ejemplo, existe un starter específico para desarrollar aplicaciones web. Al incluir ese starter en el proyecto, automáticamente se añaden todas las librerías necesarias para construir un backend HTTP utilizando Spring.

En lugar de tener que investigar qué dependencias necesitamos una por una, basta con incluir el starter adecuado y Spring Boot se encarga del resto.

#### Servidor web embebido

En las aplicaciones web Java tradicionales era necesario instalar y configurar un servidor de aplicaciones por separado. Uno de los más conocidos es Tomcat.

Después de compilar nuestra aplicación, normalmente se generaba un archivo especial (un archivo WAR) que debía desplegarse dentro de ese servidor para poder ejecutarse.

Spring Boot cambia completamente esta forma de trabajar. Las aplicaciones creadas con Spring Boot incluyen un servidor web embebido dentro del propio programa. Esto significa que no necesitamos instalar nada adicional.

Cuando ejecutamos la aplicación, el propio programa arranca su servidor web interno y empieza a aceptar peticiones HTTP. Desde el punto de vista del desarrollador, esto hace que trabajar con aplicaciones web sea mucho más sencillo: basta con ejecutar el proyecto como cualquier otra aplicación Java.

Este servidor embebido, que suele ser Tomcat (aunque hay otros), no solo se usa en desarrollo, sino que también, cada vez más, se usa en producción.

#### Inversión de control (IoC) e inyección de dependencias

¿Te has fijado que en Laravel nunca tenía que crear controladores o modelos? Nunca escribías nada como `$c = new ProductController()`. Eso es porque una pieza del núcleo de Laravel llamada *Service Container* inyectaba automáticamente todos esos objetos ya creados en tus archivos. 

Spring Boot hace exactamente lo mismo. Se llama **IoC** (***Inversion of Control***): en lugar de crear objetos manualmente con `new`, es el framework quien los crea y conecta entre sí.

La diferencia es que en Laravel esto es casi transparente (tú no te enteras de cuándo ni cómo se está haciendo) y en Spring Boot **hay que indicarlo explícitamente con una anotación (`@Autowired`) o con un constructor**. Ya veremos exactamente cómo, pero la idea de fondo es la misma.

## 5.2. Crear un proyecto Spring Boot

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



## 5.3. Relaciones entre entidades

**Spring Data JPA** es el ORM Spring Boot (como Eloquent lo es de Laravel). Es un derivado de **Hibernate/JPA**, que debiste ver, aunque fuera por encima, en primer curso (si no es así, no te apures: se parece mucho a Eloquent).

Por tanto, Spring Data JPA se encarga de gestionar las relaciones entre tablas y mover los datos entre la base de datos real y los objetos (entities) de nuestra aplicación.

En esta sección vamos a resumir muy deprisa, sin entrar en detalles farragosos, cómo lo hace Spring Boot para **especificar las relaciones entre entidades**. Como todo en Spring Boot, se basa en el uso de las **anotaciones**.

#### Relación 1:1

En **relaciones 1:1**, las dos entidades relacionadas tienen en teoría el mismo “peso” en la relación (no hay una entidad dominante). Nosotros, como programadores y según la semántica de la relación, decidiremos **qué entidad es la dominante**.

Por ejemplo, si tenemos una entidad `Alumno` y otra entidad `Email` con una relación 1:1 entre ellas, parece claro que *la entidad `Alumno` es propietaria de esa relación y `Email` es la parte inversa*, puesto que un email no tiene sentido si no pertenece a un alumno pero un alumno sí puede existir sin email.

En tal caso, expandiríamos la clave ajena `email_id` a la tabla `alumnos` como clave ajena y lo implementaríamos así con Spring Boot:

```java
// ******** ENTIDAD ALUMNO ********
@Entity
public class Alumno {
   @OneToOne
   @JoinColumn(name = "email_id")   //  <-- Esta es la clave ajena
   private Email email;
   // Aquí iría el resto de la entidad Alumno
}

// ******** ENTIDAD EMAIL ********
@Entity
public class Email {
   @OneToOne(mappedBy = "email") //  <-- mapped indica que la otra entidad “manda”
   private Alumno alumno;
   // Aquí iría el resto de la entidad Email
}
```

#### Relaciones 1:N

En las **relaciones 1:N** siempre **"manda" la entidad del lado 1** (la que tiene la clave ajena en la base de datos).

Por ejemplo, si tenemos una entidad `Alumno` y otra entidad `Curso` con una relación 1:N entre ellas, siempre es la entidad `Alumno` la propietaria de la relación (su table contendrá un `curso_id` como clave ajena). `Curso` es la parte inversa.

La implementación con Spring Boot de las dos entidades sería así:

```java
// ******** ENTIDAD ALUMNO ********
@Entity
public class Alumno {
    @ManyToOne
    @JoinColumn(name="curso_id")  // <-- Clave ajena
    private Curso curso; 
   // Aquí iría el resto de la entidad Alumno
}

// ******** ENTIDAD CURSO ********
@Entity
public class Curso {
   @OneToMany(mappedBy = "curso")//  <-- mapped indica que la otra entidad “manda”
   private List<Alumno> listaAlum;
   // Aquí iría el resto de la entidad Curso
}
```

#### Relaciones N:N

Las **relaciones N:N**, como ya sabrás, generan una **tabla intermedia** llamada tabla **pivote**. 

A veces, se crea una entidad para esa tabla pivote (sobre todo cuando tiene mucha importancia en la aplicación o tiene muchos atributos adicionales) y sus conexiones con las tablas maestras se manejan como dos relaciones 1:N diferentes, pero lo habitual es que la tabla pivote no genere una entidad, sino que se indique en las entidades maestras.

En este caso, de nuevo, tenemos una **relación “igual por los dos lados”**, es decir, donde no hay de entrada una entidad propietaria y otra inversa. Es la semántica del problema la que nos dirá **qué entidad es dominante** en la relación, y así se lo indicaremos a Spring Boot.

Por ejemplo, si tenemos una entidad `Alumno` con una relación N:N con otra entidad `Asignatura`, parece razonable que sea el `Alumno` la entidad dominante. En tal caso, describiríamos así las entidades:

```java
// ******** ENTIDAD ALUMNO ********
@Entity
public class Alumno {  
    @ManyToMany
    @JoinTable(               
        name = "alumno_asignatura", // <-- Nombre de la tabla pivote
        joinColumns = @JoinColumn(name = "alumno_id"),
        inverseJoinColumns = @JoinColumn(name = "asignatura_id")
    )
    private List<Asignatura> asignaturas;
   // Aquí iría el resto de la entidad Alumno
}

// ******** ENTIDAD ASIGNATURA ********
@Entity
public class Asignatura {  
    @ManyToMany(mappedBy = "asignaturas")
    private List<Alumno> alumnos;
   // Aquí iría el resto de la entidad Asignatura
}
```

Una vez declaradas las entidades, puedes **olvidarte de la tabla pivote**, porque Spring Data JPA se encargará de gestionarla automáticamente.

## 5.4. Autenticación con Spring Security

En Laravel teníamos los Starter Kits con autenticación, de los que probamos Breeze con el Middleware `auth`. 

Pues bien, **Spring Security** hace las mismas funciones en Spring Boot. Vamos a ver, muy brevemente, cómo usarlo.

#### Añadir la dependencia

**Spring Security** no se instala por defecto con Spring Boot.

Cuando crees el proyecto con Spring Initializr puedes seleccionar el módulo **Spring Security**. O, si el proyecto ya existe, puedes añadir el módulo manualmente al archivo `pom.xml` de Maven:

```xml
<dependency>
    <groupId>org.springframework.boot</groupId>
    <artifactId>spring-boot-starter-security</artifactId>
</dependency>
```

A partir de ahora, Spring Security **protegerá todos los endpoints** automáticamente y mostrará una pantalla de login por defecto si intenta acceder un usuario no autenticado. *La contraseña generada aparece en la consola al arrancar la aplicación*.

#### Autenticación en aplicaciones SSR con formulario de login

Como hemos visto, cuando añades Spring Security al proyecto, **todos los endpoints quedan protegidos por defecto**: si el usuario intenta acceder a cualquier URL sin haberse autenticado, Spring Security le redirigirá automáticamente a un formulario de login.

Pero normalmente querremos más control: definir qué rutas son públicas, qué rutas son privadas y personalizar el formulario de login. Para eso, se crea una **clase de configuración** anotada con `@Configuration` que le dice a Spring Security cómo comportarse.

A continuación veremos el proceso completo, paso a paso.

**Paso 1: La clase `SecurityConfig` (equivale al Middleware `auth` de Laravel)**

Esta clase define las reglas de acceso:

```java
import org.springframework.context.annotation.Bean;
import org.springframework.context.annotation.Configuration;
import org.springframework.security.config.annotation.web.builders.HttpSecurity;
import org.springframework.security.web.SecurityFilterChain;

@Configuration
public class SecurityConfig {

    @Bean
    public SecurityFilterChain filterChain(HttpSecurity http) throws Exception {
        http
            // 1. Definir qué rutas son públicas y cuáles requieren login
            .authorizeHttpRequests(auth -> auth
                .requestMatchers("/", "/login", "/css/**").permitAll()  // Rutas públicas
                .anyRequest().authenticated()                            // El resto, privadas
            )
            // 2. Configurar el formulario de login
            .formLogin(form -> form
                .loginPage("/login")           // URL de tu formulario de login personalizado
                .loginProcessingUrl("/login")  // URL a la que envía el POST el formulario
                .defaultSuccessUrl("/inicio", true)  // A dónde ir tras un login correcto
                .failureUrl("/login?error")    // A dónde ir si el login falla
                .permitAll()
            )
            // 3. Configurar el logout
            .logout(logout -> logout
                .logoutUrl("/logout")          // URL que activa el cierre de sesión
                .logoutSuccessUrl("/login?logout")  // A dónde ir tras el logout
                .permitAll()
            );

        return http.build();
    }
}
```

**Paso 2: Dónde están los usuarios — `UserDetailsService`**

Spring Security necesita saber de dónde sacar los usuarios para verificar sus contraseñas. Eso se define implementando la interfaz `UserDetailsService`. En desarrollo puedes usar usuarios en memoria para ir rápido:

```java
import org.springframework.context.annotation.Bean;
import org.springframework.security.core.userdetails.User;
import org.springframework.security.core.userdetails.UserDetailsService;
import org.springframework.security.provisioning.InMemoryUserDetailsManager;
import org.springframework.security.crypto.bcrypt.BCryptPasswordEncoder;
import org.springframework.security.crypto.password.PasswordEncoder;

// Añade estos beans dentro de tu clase SecurityConfig:

@Bean
public UserDetailsService userDetailsService() {
    // Creamos un usuario "admin" con contraseña "1234" (guardada hasheada con BCrypt)
    var admin = User.builder()
        .username("admin")
        .password(passwordEncoder().encode("1234"))  // ¡Nunca guardes contraseñas en texto plano!
        .roles("ADMIN")
        .build();
    return new InMemoryUserDetailsManager(admin);
}

@Bean
public PasswordEncoder passwordEncoder() {
    return new BCryptPasswordEncoder();
}
```

Para aplicaciones reales, en lugar de `InMemoryUserDetailsManager`, implementarías el `UserDetailsService` para cargar los usuarios desde tu base de datos. Por ejemplo:

```java
@Service
public class MiUserDetailsService implements UserDetailsService {

    // Suponemos que tienes un repositorio de usuarios en la BD
    private final UsuarioRepository usuarioRepository;

    public MiUserDetailsService(UsuarioRepository usuarioRepository) {
        this.usuarioRepository = usuarioRepository;
    }

    @Override
    public UserDetails loadUserByUsername(String email) throws UsernameNotFoundException {
        // Busca el usuario en la base de datos
        Usuario usuario = usuarioRepository.findByEmail(email)
            .orElseThrow(() -> new UsernameNotFoundException("Usuario no encontrado: " + email));

        // Devuelve un objeto UserDetails que Spring Security entiende
        return User.builder()
            .username(usuario.getEmail())
            .password(usuario.getPassword())  // La contraseña DEBE estar hasheada en la BD
            .roles("USER")
            .build();
    }
}
```

**Paso 3: El controlador de login**

Necesitas un controlador con un endpoint `GET /login` que devuelva la vista del formulario:

```java
@Controller
public class AuthController {

    // GET /login → muestra el formulario
    @GetMapping("/login")
    public String mostrarLogin() {
        return "auth/login";  // → templates/auth/login.html
    }
}
```

Observa que **no necesitas un endpoint `POST /login`** en tu controlador: Spring Security intercepta automáticamente el POST a `/login` (según lo configurado en `loginProcessingUrl`), verifica las credenciales usando tu `UserDetailsService` y gestiona la sesión.

**Paso 4: La vista del formulario de login**

El formulario de login es HTML estándar con un atributo crucial: los campos deben llamarse **`username`** y **`password`** para que Spring Security los reconozca. Podría ser algo así:

```html
<!-- templates/auth/login.html -->
<!DOCTYPE html>
<html xmlns:th="http://www.thymeleaf.org">
<head><title>Login</title></head>
<body>
    <h1>Iniciar sesión</h1>

    <!-- Mensaje de error si el login falló -->
    <p th:if="${param.error}" style="color: red;">Email o contraseña incorrectos.</p>
    <!-- Mensaje tras logout -->
    <p th:if="${param.logout}" style="color: green;">Sesión cerrada correctamente.</p>

    <!-- IMPORTANTE: los campos se llaman 'username' y 'password' -->
    <form th:action="@{/login}" method="post">
        <div>
            <label>Email:</label>
            <input type="text" name="username" required />
        </div>
        <div>
            <label>Contraseña:</label>
            <input type="password" name="password" required />
        </div>
        <button type="submit">Entrar</button>
    </form>
</body>
</html>
```

**Paso 5: Mostrar u ocultar elementos según el estado de autenticación**

En las vistas Thymeleaf, puedes usar el dialecto de Spring Security (añade la dependencia `thymeleaf-extras-springsecurity6` en tu `pom.xml`) para mostrar u ocultar contenido según si el usuario está autenticado:

```html
<!-- Añade esto al <html> de tus plantillas: -->
<html xmlns:th="http://www.thymeleaf.org"
      xmlns:sec="http://www.thymeleaf.org/extras/spring-security">

<!-- Mostrar solo si hay sesión (equivale a @auth de Blade) -->
<div sec:authorize="isAuthenticated()">
    <p>Bienvenido, <span sec:authentication="name"></span>!</p>
    <form th:action="@{/logout}" method="post">
        <button type="submit">Cerrar sesión</button>
    </form>
</div>

<!-- Mostrar solo si NO hay sesión (equivale a @guest de Blade) -->
<div sec:authorize="isAnonymous()">
    <a th:href="@{/login}">Iniciar sesión</a>
</div>

<!-- Mostrar solo si el usuario tiene rol ADMIN -->
<div sec:authorize="hasRole('ADMIN')">
    <a th:href="@{/admin}">Panel de administración</a>
</div>
```

> **¡ATENCIÓN!**
> El botón de logout **debe ser un formulario POST**, no un simple enlace GET. Spring Security, por razones de seguridad (protección CSRF), rechaza los logout que llegan por GET.

#### Autenticación en API REST con JWT

En las aplicaciones SSR, la sesión del usuario se mantiene mediante una **cookie** que el navegador envía automáticamente en cada petición. Sin embargo, en una API REST pura los clientes pueden ser apps móviles, scripts o frontends SPA que no manejan cookies de esa manera. Por eso las APIs usan, como ya vimos con Laravel, un mecanismo diferente: **los tokens**.

El estándar más extendido hoy en día son los **JWT (JSON Web Tokens)**. Son cadenas de texto codificadas que el servidor genera cuando el usuario se autentica y que el cliente debe incluir en todas sus peticiones posteriores. *Equivalen exactamente a los tokens de Sanctum que ya conoces de Laravel*.

Un JWT tiene tres partes separadas por puntos (`.`):
- **Header**: indica el algoritmo de firma
- **Payload**: contiene datos del usuario (id, email, rol, fecha de expiración)
- **Signature**: garantiza que nadie ha manipulado el token

El flujo completo es así:
1. El cliente hace `POST /api/auth/login` enviando `email` y `password` en JSON.
2. El servidor verifica las credenciales contra la base de datos.
3. Si son correctas, el servidor genera un JWT firmado con una clave secreta y se lo devuelve al cliente.
4. A partir de ese momento, en cada petición protegida, el cliente incluye la cabecera: `Authorization: Bearer <el_token>`. **Si no lo hace, sus peticiones serán rechazadas**.
5. Spring Security intercepta la petición, extrae el token, verifica su firma y, si es válido, da acceso al recurso.

**Implementación con la librería `jjwt`**

La forma más habitual de implementar JWT en Spring Boot es con la librería `jjwt`. Añádela a tu `pom.xml`:

```xml
<dependency>
    <groupId>io.jsonwebtoken</groupId>
    <artifactId>jjwt-api</artifactId>
    <version>0.12.6</version>
</dependency>
<dependency>
    <groupId>io.jsonwebtoken</groupId>
    <artifactId>jjwt-impl</artifactId>
    <version>0.12.6</version>
    <scope>runtime</scope>
</dependency>
<dependency>
    <groupId>io.jsonwebtoken</groupId>
    <artifactId>jjwt-jackson</artifactId>
    <version>0.12.6</version>
    <scope>runtime</scope>
</dependency>
```

Y define la clave secreta en `application.properties`:

```properties
# Clave para firmar los tokens. Debe ser larga y secreta (¡no la subas a Git!)
app.jwt.secret=clave-super-secreta-y-muy-larga-para-firmar-tokens-jwt-2024
app.jwt.expiration=86400000  # 24 horas en milisegundos
```

**Clase `JwtUtil`: generar y validar tokens**

```java
import io.jsonwebtoken.*;
import io.jsonwebtoken.security.Keys;
import org.springframework.beans.factory.annotation.Value;
import org.springframework.stereotype.Component;
import java.util.Date;
import javax.crypto.SecretKey;

@Component
public class JwtUtil {

    @Value("${app.jwt.secret}")
    private String secret;

    @Value("${app.jwt.expiration}")
    private long expiration;

    // Genera un token JWT para un usuario dado su email (u otro identificador)
    public String generateToken(String email) {
        SecretKey key = Keys.hmacShaKeyFor(secret.getBytes());
        return Jwts.builder()
            .subject(email)
            .issuedAt(new Date())
            .expiration(new Date(System.currentTimeMillis() + expiration))
            .signWith(key)
            .compact();
    }

    // Extrae el email del payload del token
    public String extractEmail(String token) {
        return parseClaims(token).getSubject();
    }

    // Valida que el token es correcto y no ha expirado
    public boolean isValid(String token) {
        try {
            parseClaims(token);
            return true;
        } catch (JwtException e) {
            return false;
        }
    }

    private Claims parseClaims(String token) {
        SecretKey key = Keys.hmacShaKeyFor(secret.getBytes());
        return Jwts.parser().verifyWith(key).build().parseSignedClaims(token).getPayload();
    }
}
```

**Controlador de autenticación (`/api/auth`)**

```java
import org.springframework.http.ResponseEntity;
import org.springframework.security.authentication.*;
import org.springframework.web.bind.annotation.*;

@RestController
@RequestMapping("/api/auth")
public class AuthApiController {

    private final AuthenticationManager authManager;
    private final JwtUtil jwtUtil;

    public AuthApiController(AuthenticationManager authManager, JwtUtil jwtUtil) {
        this.authManager = authManager;
        this.jwtUtil = jwtUtil;
    }

    // POST /api/auth/login → recibe {"email":"...", "password":"..."}
    @PostMapping("/login")
    public ResponseEntity<?> login(@RequestBody LoginRequest request) {
        try {
            // Spring Security verifica las credenciales
            authManager.authenticate(
                new UsernamePasswordAuthenticationToken(request.email(), request.password())
            );
            // Si llega aquí, las credenciales son correctas. Generamos el token.
            String token = jwtUtil.generateToken(request.email());
            return ResponseEntity.ok(new LoginResponse(token));
        } catch (BadCredentialsException e) {
            return ResponseEntity.status(401).body("Credenciales incorrectas");
        }
    }

    // Records de Java (equivalen a DTOs simples)
    public record LoginRequest(String email, String password) {}
    public record LoginResponse(String token) {}
}
```

**Filtro JWT: interceptar peticiones y validar el token**

Este es el componente que intercepta cada petición entrante, extrae el token de la cabecera `Authorization`, lo valida y, si es correcto, autentica al usuario en el contexto de Spring Security:

```java
import jakarta.servlet.*;
import jakarta.servlet.http.*;
import org.springframework.security.authentication.UsernamePasswordAuthenticationToken;
import org.springframework.security.core.context.SecurityContextHolder;
import org.springframework.security.core.userdetails.UserDetailsService;
import org.springframework.stereotype.Component;
import org.springframework.web.filter.OncePerRequestFilter;
import java.io.IOException;

@Component
public class JwtFilter extends OncePerRequestFilter {

    private final JwtUtil jwtUtil;
    private final UserDetailsService userDetailsService;

    public JwtFilter(JwtUtil jwtUtil, UserDetailsService userDetailsService) {
        this.jwtUtil = jwtUtil;
        this.userDetailsService = userDetailsService;
    }

    @Override
    protected void doFilterInternal(HttpServletRequest request,
                                    HttpServletResponse response,
                                    FilterChain chain) throws ServletException, IOException {

        String header = request.getHeader("Authorization");

        // Si no hay cabecera Bearer, dejamos pasar la petición (puede ser una ruta pública)
        if (header == null || !header.startsWith("Bearer ")) {
            chain.doFilter(request, response);
            return;
        }

        String token = header.substring(7); // Quitamos "Bearer "
        if (jwtUtil.isValid(token)) {
            String email = jwtUtil.extractEmail(token);
            var userDetails = userDetailsService.loadUserByUsername(email);
            var auth = new UsernamePasswordAuthenticationToken(
                userDetails, null, userDetails.getAuthorities()
            );
            // Registramos al usuario como autenticado en el contexto de Spring Security
            SecurityContextHolder.getContext().setAuthentication(auth);
        }

        chain.doFilter(request, response);
    }
}
```

**Configuración de Spring Security para API JWT**

```java
@Configuration
public class SecurityConfig {

    private final JwtFilter jwtFilter;

    public SecurityConfig(JwtFilter jwtFilter) {
        this.jwtFilter = jwtFilter;
    }

    @Bean
    public SecurityFilterChain filterChain(HttpSecurity http) throws Exception {
        http
            .csrf(csrf -> csrf.disable())  // Las APIs REST no necesitan protección CSRF
            .sessionManagement(s -> s.sessionCreationPolicy(SessionCreationPolicy.STATELESS))
            .authorizeHttpRequests(auth -> auth
                .requestMatchers("/api/auth/**").permitAll()  // Login libre
                .anyRequest().authenticated()                 // El resto requiere token
            )
            // Añadimos nuestro filtro JWT ANTES del filtro de autenticación por defecto
            .addFilterBefore(jwtFilter, UsernamePasswordAuthenticationFilter.class);

        return http.build();
    }

    @Bean
    public AuthenticationManager authenticationManager(AuthenticationConfiguration config)
            throws Exception {
        return config.getAuthenticationManager();
    }
}
```

**Cómo se usa en Postman**

1. Haz `POST http://localhost:8080/api/auth/login` con el body:
   ```json
   { "email": "admin@ejemplo.com", "password": "1234" }
   ```
2. Copia el token que devuelve el servidor.
3. En las siguientes peticiones, ve a la pestaña **Authorization** → **Bearer Token** y pega el token.

A partir de ahí, Postman incluirá automáticamente la cabecera `Authorization: Bearer <token>` en todas tus peticiones.

> **¡ATENCIÓN!**
> La implementación de JWT tiene bastante código de infraestructura (el filtro, la clase `JwtUtil`, la configuración). Esto es completamente normal en Spring Boot: es código que se escribe una vez y luego no se toca. Compáralo con Sanctum en Laravel, donde también existía ese código de infraestructura, pero lo instalaba Breeze automáticamente.

## 5.5. Ejemplo completo: CRUD de usuarios

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

#### La Entity Usuario

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

#### El Repository

El Repository, como ya hemos explicado, es la capa que se encarga de acceder a la base de datos.

El repositorio para usuarios se crea simplemente extendiendo la interfaz `JpaRepository`.

```java
import org.springframework.data.jpa.repository.JpaRepository;

public interface UsuarioRepository extends JpaRepository<Usuario, Long> {
}
```

¡Y eso es todo! Spring genera automáticamente los métodos `findAll()`, `findById()`, `save()`, `deleteById()` y otros muchos para la tabla de usuarios.

#### El Service

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

#### El Controller

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

#### Las vistas

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

#### Probando la aplicación

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

## Práctica final SSR: Tienda de productos con categorías

Vamos a construir una aplicación web SSR (con Thymeleaf) que gestione una tienda online sencilla con productos y categorías.

#### Objetivos

- Configurar un proyecto Spring Boot con MySQL, Spring Web, Spring Data JPA y Thymeleaf.
- Crear las entidades `Product` y `Category` con relación 1:N.
- Implementar repositorios, servicios y controladores para ambas.
- Construir las vistas Thymeleaf para el CRUD completo.
- AMPLIACIÓN: Proteger las rutas de creación/edición/borrado con Spring Security.

#### El reto y el uso de la Inteligencia Artificial (IA)

Puedes y debes usar la IA para ayudarte, pero, como en ocasiones anteriores, de forma **ética y eficiente**:

1. **Construye pieza a pieza**: empieza por la entidad, luego el repositorio, luego el servicio, luego el controlador, luego la vista. No pidas todo a la vez.
2. **Entiende cada línea**: si la IA te genera una anotación que no reconoces, pregúntale qué hace. Tendrás que explicarla en la defensa.

> **¡ATENCIÓN!**
> Recueda que se realizarán preguntas orales y/o escritas sin IA sobre el código entregado en encuentros con el profesor o durante el propio examen. No superar esta fase implica suspender la práctica.

#### PASO 0. Crear el proyecto

Crea un proyecto nuevo con Spring Initializr (desde VS Code o desde [start.spring.io](https://start.spring.io/)) con estas dependencias:
- Spring Web
- Spring Data JPA
- MySQL Driver
- Thymeleaf
- Spring Security

#### PASO 1. Configurar la base de datos

Edita `src/main/resources/application.properties`:

```properties
spring.datasource.url=jdbc:mysql://localhost:3306/tienda_spring
spring.datasource.username=root
spring.datasource.password=tu_password
spring.jpa.hibernate.ddl-auto=update
spring.jpa.show-sql=true
```

Crea la base de datos `tienda_spring` manualmente en MySQL:

```sql
CREATE DATABASE tienda_spring CHARACTER SET utf8mb4;
```

#### PASO 2. Entidades

**Entidad `Category`:**
- `id` (Long, clave primaria, autoincrementable)
- `name` (String, no nulo)
- Relación `@OneToMany` con `Product`

**Entidad `Product`:**
- `id` (Long, clave primaria, autoincrementable)
- `name` (String, no nulo)
- `description` (String, puede ser nulo)
- `price` (Double, no nulo)
- Relación 1:N con `Category`

Hibernate creará las tablas automáticamente al arrancar la aplicación.

#### PASO 3. Repositorios y Servicios

Crea:
- `CategoryRepository extends JpaRepository<Category, Long>`
- `ProductRepository extends JpaRepository<Product, Long>`
- `CategoryService` con los métodos `findAll()`, `findById()`, `save()`, `delete()`
- `ProductService` con los mismos métodos

#### PASO 4. Controladores SSR

Crea `CategoryController` y `ProductController` con estos endpoints:

**`CategoryController`** (ruta base `/categories`):
- `GET /categories` → lista de categorías
- `GET /categories/nuevo` → formulario nueva categoría
- `POST /categories/guardar` → guardar
- `GET /categories/editar/{id}` → formulario editar
- `GET /categories/eliminar/{id}` → eliminar

**`ProductController`** (ruta base `/products`):
- Los mismos endpoints de categorías, pero para productos
- En el formulario de producto, incluye un `<select>` para elegir la categoría

#### PASO 5. Vistas Thymeleaf

Crea las vistas en `src/main/resources/templates/`:
- `categories/list.html`: tabla con todas las categorías y links de acción
- `categories/form.html`: formulario para crear y editar (el mismo, como en Laravel)
- `products/list.html`: tabla con nombre, precio y categoría de cada producto
- `products/form.html`: formulario que incluye un `<select>` con las categorías disponibles

#### PASO 6. (AMPLIACIÓN) Autenticación

Añade una clase `SecurityConfig` que deje públicas las rutas `GET /products` y `GET /categories`, y exija autenticación para crear, editar y borrar.

Para esta práctica, puedes usar usuarios en memoria. Por ejemplo, añade en `SecurityConfig`:

```java
@Bean
public UserDetailsService users() {
    UserDetails admin = User.builder()
        .username("admin")
        .password("{noop}admin123")  // {noop} = sin encriptación (¡solo para pruebas!)
        .roles("ADMIN")
        .build();
    return new InMemoryUserDetailsManager(admin);
}
```

#### PASO 7. Probar

Arranca la aplicación ejecutando la clase principal desde tu IDE. Abre el navegador en `http://localhost:8080/products`.

#### Entrega

La entrega debe cumplir **estrictamente** con estos requisitos. El incumplimiento de cualquiera de ellos conllevará penalización o rechazo de la entrega:

1. **Código fuente comprimido**: Sube a Moodle Centros un archivo ZIP con tu proyecto. **EXCEPTUANDO la carpeta `/target`**. (Si la incluye, serás penalizado).
2. **Vídeo demostrativo**: Graba un vídeo capturando tu pantalla y demostrando el funcionamiento de tu aplicación. Debes explicarlo **con tu propia voz** (nada de voces sintetizadas o IA). Sube el vídeo a Moodle Centros o un enlace a YouTube/Drive, como prefieras.
3. **Repositorio público**: Incluye un enlace a tu repositorio público en GitHub o GitLab. *Se revisará el historial de commits*.
4. **Conversación con la IA**: Sube un archivo .docx o .odt con TODA tu conversación con la IA. Necesitamos ver cómo has interactuado con la Inteligencia Artificial.
5. **Reproducibilidad**: El profesor descargará tu ZIP (o clonará tu repo) y compilará todo el paquete. **La aplicación debe funcionar inmediatamente** sin necesidad de tocar nada más.

#### Rúbrica de calificación

La evaluación se realizará según los siguientes ítems. Cada nivel de logro otorga una puntuación:
* **0**: Sin hacer o sin evidencia de esfuerzo.
* **1**: Hecho, pero con errores graves o muy incompleto.
* **2**: Hecho y funcional, pero mejorable (faltan detalles, bugs menores).
* **3**: Perfecto, cumple todos los requisitos con excelencia.

| Ítem Evaluable | Peso | Nivel 0 | Nivel 1 | Nivel 2 | Nivel 3 |
| :--- | :---: | :--- | :--- | :--- | :--- |
| **0. Uso ético y eficiente de la IA (Eliminatorio)** | **Requisito** | No defiende el código. Uso fraudulento. | (no aplica) | (no aplica) | Explica y defiende el código sin IA. |
| **1. Entrega en tiempo y forma** | **10%** | No entregado o sin ejecutar. | Falta vídeo o instrucciones de ejecución. | Cumple casi todo. | Entrega completa y reproducible. |
| **2. Control de versiones (Git)** | **10%** | Sin repositorio. | Un único commit final. | Varios commits irregulares. | Commits frecuentes y descriptivos. |
| **3. Entidades y relaciones (BD)** | **20%** | Sin entidades. | Entidades sin relaciones o con errores. | Relaciones 1:N correctas, falla la N:N. | Todas las relaciones perfectas. |
| **4. Capas del proyecto (Service, Repository)** | **25%** | Todo en el controller. | Capas incompletas o mezcladas. | Estructura correcta con pequeños errores. | Separación de capas impecable. |
| **5. Controladores y endpoints** | **25%** | No responde a las URLs. | Endpoints desorganizados o con errores. | CRUD funcional con pequeños problemas. | Endpoints REST correctos, validaciones. |
| **6. Autenticación** | **10%** adicional | Sin protección. | Auth añadida pero no protege correctamente. | Rutas protegidas, falla algún caso. | Auth perfecta, rutas bien diferenciadas. |
| **7. Calidad del código** | **10%** | Código ilegible. | Código desordenado o con mucho código repetido. | Ordenado con algunas deficiencias. | Código limpio, nomenclatura coherente. |

*Nota: para aprobar es obligatorio superar el ítem 0 (Uso ético y eficiente de la IA).*


---

## Práctica final API REST: Biblioteca

Vas a construir una API RESTful con Spring Boot para gestionar una biblioteca: autores, libros y lectores. Sin vistas, sin Thymeleaf. Solo controladores que devuelven JSON, testeados con Postman.

#### Objetivos

- Crear las entidades `Author`, `Book` y `Reader` con relaciones 1:N y N:N.
- Exponer endpoints RESTful que devuelvan y reciban JSON.
- Proteger los endpoints de escritura con autenticación (Basic Auth para simplificar).
- Testear todos los endpoints con Postman.

#### El reto y el uso de la Inteligencia Artificial (IA)

Las mismas reglas que en la práctica SSR: usa la IA para tareas concretas, entiende el código generado y prepárate para defenderlo.

> **¡ATENCIÓN!**
> Defensa del código sin IA: elimatoria. No superarla implica suspender la práctica.

#### PASO 0. Crear el proyecto

Crea un proyecto Spring Boot con estas dependencias:
- Spring Web
- Spring Data JPA
- MySQL Driver
- Spring Security

*(No incluyas Thymeleaf: esta es una API pura, sin vistas).*

#### PASO 1. Configurar la base de datos

```properties
spring.datasource.url=jdbc:mysql://localhost:3306/biblioteca_spring
spring.datasource.username=root
spring.datasource.password=tu_password
spring.jpa.hibernate.ddl-auto=update
spring.jpa.show-sql=true
```

#### PASO 2. Entidades y relaciones

**Entidad `Author`:**
- `id`, `name` (no nulo), `nationality` (puede ser nulo)
- Relación 1:N con `Book`

**Entidad `Book`:**
- `id`, `title` (no nulo), `isbn` (único), `publishedYear`
- Relación 1:N con `Author`
- Relación N:N con `Reader` (un libro puede ser leído por muchos lectores, y un lector puede haber leído muchos libros)

**Entidad `Reader`:**
- `id`, `name`, `email` (único)
- Relación N:N mapeada con `Book`

#### PASO 3. Repositorios y Servicios

Crea los repositorios y servicios para las tres entidades. Los servicios deben permitir:
- `AuthorService`: CRUD completo de autores
- `BookService`: CRUD completo de libros, más un método `addReader(bookId, readerId)` y `removeReader(bookId, readerId)` para gestionar la relación N:N
- `ReaderService`: CRUD completo de lectores

#### PASO 4. Controladores API

Crea tres controladores con `@RestController`:

**`AuthorApiController`** (ruta base `/api/authors`):
- `GET /api/authors` → lista de autores en JSON
- `GET /api/authors/{id}` → detalle de un autor
- `POST /api/authors` → crear (recibe JSON con `@RequestBody`)
- `PUT /api/authors/{id}` → actualizar
- `DELETE /api/authors/{id}` → eliminar (solo si no tiene libros asociados)

**`BookApiController`** (ruta base `/api/books`):
- `GET /api/books` → lista de libros (incluye nombre del autor)
- `GET /api/books/{id}` → detalle con lista de lectores
- `POST /api/books` → crear
- `PUT /api/books/{id}` → actualizar
- `DELETE /api/books/{id}` → eliminar
- `POST /api/books/{id}/readers/{readerId}` → añadir lector al libro
- `DELETE /api/books/{id}/readers/{readerId}` → quitar lector del libro

**`ReaderApiController`** (ruta base `/api/readers`):
- CRUD estándar de lectores

#### PASO 5. AMPLIACIÓN: Autenticación (Basic Auth)

Para simplificar, configura Spring Security con autenticación HTTP Basic. Deja públicos los endpoints GET y protege los demás:

```java
@Configuration
public class SecurityConfig {

    @Bean
    public SecurityFilterChain filterChain(HttpSecurity http) throws Exception {
        http
            .csrf(csrf -> csrf.disable())  // Necesario para APIs REST
            .authorizeHttpRequests(auth -> auth
                .requestMatchers(HttpMethod.GET, "/api/**").permitAll()
                .anyRequest().authenticated()
            )
            .httpBasic(Customizer.withDefaults()); // Autenticación Basic

        return http.build();
    }

    @Bean
    public UserDetailsService users() {
        UserDetails user = User.builder()
            .username("admin")
            .password("{noop}admin123")
            .roles("ADMIN")
            .build();
        return new InMemoryUserDetailsManager(user);
    }
}
```

#### PASO 6. Testear con Postman

Crea una colección en Postman con todas las peticiones. Para los endpoints protegidos, ve a la pestaña **Authorization** → **Basic Auth** y usa `admin` / `admin123`.

Prueba al menos:
1. `GET /api/books` → debe devolver JSON con la lista de libros y el nombre del autor
2. `POST /api/authors` → crea un autor (body JSON: `{"name": "García Márquez", "nationality": "Colombiana"}`)
3. `POST /api/books` → crea un libro asociado al autor anterior
4. `POST /api/books/{id}/readers/{readerId}` → añade un lector a un libro y comprueba que la tabla intermedia se actualiza
5. `DELETE /api/books/{id}/readers/{readerId}` → quita ese lector y verifica

## Entrega

La entrega debe cumplir **estrictamente** con estos requisitos. El incumplimiento de cualquiera de ellos conllevará penalización o rechazo de la entrega:

1. **Código fuente comprimido**: Sube a Moodle Centros un archivo ZIP con tu proyecto. **EXCEPTUANDO la carpeta `/target`**. (Si la incluye, serás penalizado).
2. **Vídeo demostrativo**: Graba un vídeo capturando tu pantalla y demostrando el funcionamiento de tu aplicación. Debes explicarlo **con tu propia voz** (nada de voces sintetizadas o IA). Sube el vídeo a Moodle Centros o un enlace a YouTube/Drive, como prefieras.
3. **Repositorio público**: Incluye un enlace a tu repositorio público en GitHub o GitLab. *Se revisará el historial de commits*.
4. **Conversación con la IA**: Sube un archivo .docx o .odt con TODA tu conversación con la IA. Necesitamos ver cómo has interactuado con la Inteligencia Artificial.
5. **Reproducibilidad**: El profesor descargará tu ZIP (o clonará tu repo) y compilará todo el paquete. **La aplicación debe funcionar inmediatamente** sin necesidad de tocar nada más.

---

#### Rúbrica de calificación

La evaluación se realizará según los siguientes ítems. Cada nivel de logro otorga una puntuación:
* **0**: Sin hacer o sin evidencia de esfuerzo.
* **1**: Hecho, pero con errores graves o muy incompleto.
* **2**: Hecho y funcional, pero mejorable (faltan detalles, bugs menores).
* **3**: Perfecto, cumple todos los requisitos con excelencia.

| Ítem Evaluable | Peso | Nivel 0 | Nivel 1 | Nivel 2 | Nivel 3 |
| :--- | :---: | :--- | :--- | :--- | :--- |
| **0. Uso ético y eficiente de la IA (Eliminatorio)** | **Requisito** | No defiende el código. Uso fraudulento. | (no aplica) | (no aplica) | Explica y defiende el código sin IA. |
| **1. Entrega en tiempo y forma** | **10%** | No entregado o sin ejecutar. | Falta vídeo o instrucciones de ejecución. | Cumple casi todo. | Entrega completa y reproducible. |
| **2. Control de versiones (Git)** | **10%** | Sin repositorio. | Un único commit final. | Varios commits irregulares. | Commits frecuentes y descriptivos. |
| **3. Entidades y relaciones (BD)** | **20%** | Sin entidades. | Entidades sin relaciones o con errores. | Relaciones 1:N correctas, falla la N:N. | Todas las relaciones perfectas. |
| **4. Capas del proyecto (Service, Repository)** | **25%** | Todo en el controller. | Capas incompletas o mezcladas. | Estructura correcta con pequeños errores. | Separación de capas impecable. |
| **5. Controladores y endpoints** | **25%** | No responde a las URLs. | Endpoints desorganizados o con errores. | CRUD funcional con pequeños problemas. | Endpoints REST correctos, validaciones. |
| **6. Autenticación** | **10%** adicional | Sin protección. | Auth añadida pero no protege correctamente. | Rutas protegidas, falla algún caso. | Auth perfecta, rutas bien diferenciadas. |
| **7. Calidad del código** | **10%** | Código ilegible. | Código desordenado o con mucho código repetido. | Ordenado con algunas deficiencias. | Código limpio, nomenclatura coherente. |

*Nota: para aprobar es obligatorio superar el ítem 0 (Uso ético y eficiente de la IA).*