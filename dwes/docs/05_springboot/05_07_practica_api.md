---
layout: page
title: 5.7 Práctica final API
permalink: /springboot/practica-api
nav_order: 7
has_children: true
parent: 5 SSR y API REST con Spring Boot
grand_parent: Desarrollo Web en Entorno Servidor
---

## Práctica final API: Biblioteca
{: .no_toc }

- TOC
{:toc}


Vas a construir una API RESTful con Spring Boot para gestionar una biblioteca: autores, libros y lectores. Sin vistas, sin Thymeleaf. Solo controladores que devuelven JSON, testeados con Postman.

### Objetivos

- Crear las entidades `Author`, `Book` y `Reader` con relaciones 1:N y N:N.
- Exponer endpoints RESTful que devuelvan y reciban JSON.
- Proteger los endpoints de escritura con autenticación (Basic Auth para simplificar).
- Testear todos los endpoints con Postman.

### Uso de la Inteligencia Artificial (IA)

Las mismas reglas que en la práctica SSR: usa la IA para tareas concretas, entiende el código generado y prepárate para defenderlo.

> **¡ATENCIÓN!**
> Defensa del código sin IA: elimatoria. No superarla implica suspender la práctica.

### PASO 0. Crear el proyecto

Crea un proyecto Spring Boot con estas dependencias:
- Spring Web
- Spring Data JPA
- MySQL Driver
- Spring Security

*(No incluyas Thymeleaf: esta es una API pura, sin vistas).*

### PASO 1. Configurar la base de datos

```properties
spring.datasource.url=jdbc:mysql://localhost:3306/biblioteca_spring
spring.datasource.username=root
spring.datasource.password=tu_password
spring.jpa.hibernate.ddl-auto=update
spring.jpa.show-sql=true
```

### PASO 2. Entidades y relaciones

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

### PASO 3. Repositorios y Servicios

Crea los repositorios y servicios para las tres entidades. Los servicios deben permitir:
- `AuthorService`: CRUD completo de autores
- `BookService`: CRUD completo de libros, más un método `addReader(bookId, readerId)` y `removeReader(bookId, readerId)` para gestionar la relación N:N
- `ReaderService`: CRUD completo de lectores

### PASO 4. Controladores API

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

### PASO 5. AMPLIACIÓN: Autenticación (Basic Auth)

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

### PASO 6. Testear con Postman

Crea una colección en Postman con todas las peticiones. Para los endpoints protegidos, ve a la pestaña **Authorization** → **Basic Auth** y usa `admin` / `admin123`.

Prueba al menos:
1. `GET /api/books` → debe devolver JSON con la lista de libros y el nombre del autor
2. `POST /api/authors` → crea un autor (body JSON: `{"name": "García Márquez", "nationality": "Colombiana"}`)
3. `POST /api/books` → crea un libro asociado al autor anterior
4. `POST /api/books/{id}/readers/{readerId}` → añade un lector a un libro y comprueba que la tabla intermedia se actualiza
5. `DELETE /api/books/{id}/readers/{readerId}` → quita ese lector y verifica

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