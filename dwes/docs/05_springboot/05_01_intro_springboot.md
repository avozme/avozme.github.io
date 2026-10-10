---
layout: page
title: 5.1 Introducción a Spring Boot
permalink: /springboot/introduccion/
nav_order: 1
has_children: true
parent: 5 SSR y API REST con Spring Boot
grand_parent: Desarrollo Web en Entorno Servidor
---

## 5.1. Introducción a Spring Boot
{: .no_toc }

- TOC
{:toc}

[Descargar presentación](https://www.dropbox.com/scl/fi/4qw4lad75w2k3bcncq09h/05_01_springboot_intro.pdf?rlkey=o88eezibur5lehi9mjqs9mjzd&st=k0lyjkd7&dl=0){: .btn .btn-primary }

**Spring** es el framework Java más utilizado en entornos empresariales. **Spring Boot** es una capa encima de Spring que elimina casi toda la configuración manual y te proporciona *proyectos listos para ejecutarse en dos minutos*.

Igual que Laravel incluye servidores de desarrollo (como **Sail**), Spring Boot incluye un **servidor web embebido** (Tomcat). No necesitas instalar ni configurar ningún servidor externo.

### 5.1.1. Laravel vs Spring Boot

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

### 5.1.2. Características de Spring Boot

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

### 5.1.3. Autoconfiguración

Una de las características más importantes de Spring Boot es la autoconfiguración.

La idea es sencilla: el framework intenta detectar automáticamente qué necesita la aplicación y configura esos componentes por nosotros.

Por ejemplo, si en el proyecto añadimos una dependencia para trabajar con aplicaciones web, Spring Boot asume que necesitaremos un servidor HTTP y configura automáticamente todo lo necesario para que la aplicación pueda recibir peticiones web.

Del mismo modo, si añadimos dependencias para trabajar con bases de datos, Spring Boot prepara la infraestructura necesaria para gestionar conexiones, transacciones y otras tareas relacionadas.

Esto no significa que no se pueda personalizar la configuración, ni que la autoconfiguración siempre funcione a la perfección. En proyectos reales es bastante habitual que algo falle y haya que configurarlo a mano. Pero lo importante es que no es necesario configurar todo desde cero para empezar a trabajar.

### 5.1.4. Starter dependencies

Otro concepto muy importante en Spring Boot es el de starter dependencies.

En proyectos Java tradicionales, cuando queremos añadir una nueva funcionalidad solemos tener que incluir varias librerías distintas. A veces estas librerías dependen a su vez de otras, lo que puede generar configuraciones bastante complejas que se intentan gestionar con gestores de proyectos como Maven.

Spring Boot simplifica este proceso agrupando conjuntos de dependencias que suelen utilizarse juntas. Estos conjuntos se llaman starters.

Por ejemplo, existe un starter específico para desarrollar aplicaciones web. Al incluir ese starter en el proyecto, automáticamente se añaden todas las librerías necesarias para construir un backend HTTP utilizando Spring.

En lugar de tener que investigar qué dependencias necesitamos una por una, basta con incluir el starter adecuado y Spring Boot se encarga del resto.

### 5.1.5. Servidor web embebido

En las aplicaciones web Java tradicionales era necesario instalar y configurar un servidor de aplicaciones por separado. Uno de los más conocidos es Tomcat.

Después de compilar nuestra aplicación, normalmente se generaba un archivo especial (un archivo WAR) que debía desplegarse dentro de ese servidor para poder ejecutarse.

Spring Boot cambia completamente esta forma de trabajar. Las aplicaciones creadas con Spring Boot incluyen un servidor web embebido dentro del propio programa. Esto significa que no necesitamos instalar nada adicional.

Cuando ejecutamos la aplicación, el propio programa arranca su servidor web interno y empieza a aceptar peticiones HTTP. Desde el punto de vista del desarrollador, esto hace que trabajar con aplicaciones web sea mucho más sencillo: basta con ejecutar el proyecto como cualquier otra aplicación Java.

Este servidor embebido, que suele ser Tomcat (aunque hay otros), no solo se usa en desarrollo, sino que también, cada vez más, se usa en producción.

### 5.1.6. Inversión de control (IoC) e inyección de dependencias

¿Te has fijado que en Laravel nunca tenía que crear controladores o modelos? Nunca escribías nada como `$c = new ProductController()`. Eso es porque una pieza del núcleo de Laravel llamada *Service Container* inyectaba automáticamente todos esos objetos ya creados en tus archivos. 

Spring Boot hace exactamente lo mismo. Se llama **IoC** (***Inversion of Control***): en lugar de crear objetos manualmente con `new`, es el framework quien los crea y conecta entre sí.

La diferencia es que en Laravel esto es casi transparente (tú no te enteras de cuándo ni cómo se está haciendo) y en Spring Boot **hay que indicarlo explícitamente con una anotación (`@Autowired`) o con un constructor**. Ya veremos exactamente cómo, pero la idea de fondo es la misma.
