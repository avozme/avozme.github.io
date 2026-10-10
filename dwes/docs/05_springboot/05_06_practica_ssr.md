---
layout: page
title: 5.6 Práctica final SSR
permalink: /springboot/practica-ssr
nav_order: 6
has_children: true
parent: 5 SSR y API REST con Spring Boot
grand_parent: Desarrollo Web en Entorno Servidor
---

## 5.6. Práctica final SSR: Tienda de productos con categorías
{: .no_toc }

- TOC
{:toc}


Vamos a construir una aplicación web SSR (con Thymeleaf) que gestione una tienda online sencilla con productos y categorías.

### Objetivos

- Configurar un proyecto Spring Boot con MySQL, Spring Web, Spring Data JPA y Thymeleaf.
- Crear las entidades `Product` y `Category` con relación 1:N.
- Implementar repositorios, servicios y controladores para ambas.
- Construir las vistas Thymeleaf para el CRUD completo.
- AMPLIACIÓN: Proteger las rutas de creación/edición/borrado con Spring Security.

### Uso de la Inteligencia Artificial (IA)

Puedes y debes usar la IA para ayudarte, pero, como en ocasiones anteriores, de forma **ética y eficiente**:

1. **Construye pieza a pieza**: empieza por la entidad, luego el repositorio, luego el servicio, luego el controlador, luego la vista. No pidas todo a la vez.
2. **Entiende cada línea**: si la IA te genera una anotación que no reconoces, pregúntale qué hace. Tendrás que explicarla en la defensa.

> **¡ATENCIÓN!**
> Recueda que se realizarán preguntas orales y/o escritas sin IA sobre el código entregado en encuentros con el profesor o durante el propio examen. No superar esta fase implica suspender la práctica.

### PASO 0. Crear el proyecto

Crea un proyecto nuevo con Spring Initializr (desde VS Code o desde [start.spring.io](https://start.spring.io/)) con estas dependencias:
- Spring Web
- Spring Data JPA
- MySQL Driver
- Thymeleaf
- Spring Security

### PASO 1. Configurar la base de datos

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

### PASO 2. Entidades

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

### PASO 3. Repositorios y Servicios

Crea:
- `CategoryRepository extends JpaRepository<Category, Long>`
- `ProductRepository extends JpaRepository<Product, Long>`
- `CategoryService` con los métodos `findAll()`, `findById()`, `save()`, `delete()`
- `ProductService` con los mismos métodos

### PASO 4. Controladores SSR

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

### PASO 5. Vistas Thymeleaf

Crea las vistas en `src/main/resources/templates/`:
- `categories/list.html`: tabla con todas las categorías y links de acción
- `categories/form.html`: formulario para crear y editar (el mismo, como en Laravel)
- `products/list.html`: tabla con nombre, precio y categoría de cada producto
- `products/form.html`: formulario que incluye un `<select>` con las categorías disponibles

### PASO 6. (AMPLIACIÓN) Autenticación

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

### PASO 7. Testear

Arranca la aplicación ejecutando la clase principal desde tu IDE. Abre el navegador en `http://localhost:8080/products`.

### Entrega

La entrega debe cumplir **estrictamente** con estos requisitos. El incumplimiento de cualquiera de ellos conllevará penalización o rechazo de la entrega:

1. **Código fuente comprimido**: Sube a Moodle Centros un archivo ZIP con tu proyecto. **EXCEPTUANDO la carpeta `/target`**. (Si la incluye, serás penalizado).
2. **Vídeo demostrativo**: Graba un vídeo capturando tu pantalla y demostrando el funcionamiento de tu aplicación. Debes explicarlo **con tu propia voz** (nada de voces sintetizadas o IA). Sube el vídeo a Moodle Centros o un enlace a YouTube/Drive, como prefieras.
3. **Repositorio público**: Incluye un enlace a tu repositorio público en GitHub o GitLab. *Se revisará el historial de commits*.
4. **Conversación con la IA**: Sube un archivo .docx o .odt con TODA tu conversación con la IA. Necesitamos ver cómo has interactuado con la Inteligencia Artificial.
5. **Reproducibilidad**: El profesor descargará tu ZIP (o clonará tu repo) y compilará todo el paquete. **La aplicación debe funcionar inmediatamente** sin necesidad de tocar nada más.

### Rúbrica de calificación

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
