---
layout: page
title: 3.9 Práctica final
permalink: /laravel/practica-final.html
parent: 3 Aplicaciones SSR con Laravel
grand_parent: Desarrollo Web en Entorno Servidor
nav_order: 9
has_children: false
---

## 3.9. Práctica final: Plataforma de gestión de proyectos colaborativos
{: .no_toc }

- TOC
{:toc}

Ha llegado el momento de poner a prueba todo lo que has aprendido sobre Laravel. Esta práctica final no es una simple repetición de los apuntes; es un reto que simula un proyecto real. Tendrás que investigar, planificar y programar.

Vas a construir una **Plataforma de gestión de proyectos colaborativos** donde los usuarios pueden crear proyectos y asignar a otros usuarios a trabajar en ellos con distintos roles.

### IMPORTANTE: uso de IA en esta práctica

Gracias a herramientas de IA, una práctica que antes llevaba dos meses de trabajo o que no podía ni plantearse en un curso como este, ahora puede completarse con éxito en una semana y sin aprender menos.

**Puedes y debes usar la IA** para ayudarte, pero debes hacerlo de forma **ética y eficiente**:

1. **Prohibido copiar y pegar todo este enunciado en la IA**. Si le pides a la IA que te haga la práctica entera, te vomitará un código inmenso que no entenderás, que probablemente no funcionará bien y que será imposible de entender y de defender. *Si haces eso en una empresa, estarás en la calle al día siguiente*.
2. **Construye pieza a pieza**. Pide ayuda a la IA para tareas concretas. Por ejemplo: *"Genera una migración para la tabla de proyectos, con estos campos (a continuación, le explicas qué campos son)"*, *"¿Cómo guardo un dato extra en una tabla intermedia N:N en Laravel?"*, *"Haz este formulario de Blade visualmente más atractivo con Tailwind"*... 

   Es decir, tienes que **comprender lo que le estás pidiendo**, y para eso tienes que **saber cómo funciona Laravel**.
3. **Comprende cada línea de código**. Eres el responsable final de tu aplicación. Si hay un bloque de código que no entiendes, pídele a la IA que te lo explique línea por línea o pregúntale al profesor.

> **RECUERDA QUE** parte de la evaluación consistirá en una defensa oral o preguntas escritas sin acceso a IA, y que esas preguntas pueden aparecerte en el examen. Si no sabes explicar cómo funciona tu propia aplicación, la práctica completa estará **suspensa**, independientemente de que funcione o que seamuy bonita, porque no habrás podido demostrar *tu autoría*.

---

### Especificación de requisitos

La aplicación será tipo **SSR (Server-Side Rendering)** o **MPA (Multi-Page Application)**, es decir, todas las vistas deben ser generadas en el servidor utilizando Blade.

#### 1. Base de datos
Trabajaremos con estas entidades:

* **Users (Usuarios)**: Para el sistema de autenticación.
* **Projects (Proyectos)**: Cada proyecto debe tener un título, descripción, fecha límite y estado.
* **Relación 1:N *(Projects <-> Users)***: Todo proyecto debe tener un usuario creador/propietario.
* **Relación N:N *(Projects <-> Users)***: Un usuario puede participar en muchos proyectos, y un proyecto puede tener muchos usuarios asignados.
  * *Atención*: La tabla intermedia de la relación N:N (**pivote**) no solo unirá `user_id` y `project_id`. Debe incluir un campo adicional llamado `role` (por ejemplo: 'Desarrollador', 'Diseñador', 'Tester') y un campo `contribution_hours` (horas que el usuario ha trabajado en el proyecto).

![Diagrama ER](/docs/dwes/_site/assets/images/03_practica_final_diagram_er.png)

#### 2. Funcionalidades
Debes implementar las siguientes funcionalidades:

* **Autenticación**: Solo los usuarios logueados pueden ver y crear proyectos. Usa Laravel Breeze u otro Starter Kit simple.
* **CRUD de Proyectos**: Listar, ver detalle, crear, editar y eliminar.
  * *Solo el propietario* de un proyecto puede editarlo o borrarlo (Autorización).
* **Gestión de Participantes (N:N)**: Dentro de la vista detalle de un proyecto, el propietario debe poder añadir a otros usuarios registrados al proyecto, especificando qué `role` van a tener. También debe poder anotar cuántas horas ha trabajado cada usuario.

#### 3. Diseño visual
La aplicación **debe ser visualmente atractiva**. No se aceptarán prácticas con HTML crudo o estilos descuidados.
* Utiliza clases de **TailwindCSS** (que viene integrado con Breeze) o escribe tu propio CSS para diseñar tarjetas de proyectos, botones estilizados, formularios limpios y tablas ordenadas.
* Si un usuario no está logueado, debe ver una bonita *landing page* (página de inicio) invitándole a registrarse.

---

### Fases de desarrollo recomendadas

Para no saturarte, te recomiendo encarecidamente que sigas este orden:

1. **Fase 1: Preparación**. Crea el proyecto en Sail (usa un Laravel limpio, no con el que hemos estado trabajando durante el tema), configura la base de datos e instala la autenticación (Breeze). Haz tu primer *commit* en Git.
2. **Fase 2: Modelos, migraciones, seeders**. Crea las migraciones para las tablas. Asegúrate de añadir las claves foráneas correctamente. Añade algún seeder para tener algunos datos de prueba en las tablas con los que puedas jugar.
3. **Fase 3: CRUD básico**. Haz el controlador y las vistas Blade para crear, listar y borrar proyectos de forma simple.
4. **Fase 4: Relaciones complejas**. Añade la lógica para asignar usuarios a proyectos desde la vista de detalle. Vas a tener que investigar cómo usar el método `attach()` y `sync()` enviando datos extra para la tabla pivote (lo tienes en los apuntes).
5. **Fase 5: Diseño y pulido**. Dedica la última parte a maquetar con Tailwind CSS (¡investiga, investiga!), añadir colores, mejorar la navegación y pulir detalles funcionales y visuales.

---

### Normas de entrega

La entrega debe cumplir **estrictamente** con estos requisitos. El incumplimiento de cualquiera de ellos conllevará penalización o rechazo de la entrega:

1. **Código fuente comprimido**: Sube a Moodle Centros un archivo ZIP con tu proyecto. **EXCEPTUANDO la carpeta `/vendor` y `/node_modules`**. (Si las incluyes, serás penalizado).
2. **Vídeo demostrativo**: Graba un vídeo capturando tu pantalla y demostrando el funcionamiento de tu aplicación. Debes explicarlo **con tu propia voz** (nada de voces sintetizadas o IA). Sube el vídeo a Moodle Centros o un enlace a YouTube/Drive, como prefieras.
3. **Repositorio público**: Incluye un enlace a tu repositorio público en GitHub o GitLab. *Se revisará el historial de commits*.
4. **Reproducibilidad**: El profesor descargará tu ZIP (o clonará tu repo), ejecutará `./vendor/bin/sail up -d` y `./vendor/bin/sail artisan migrate`. **La aplicación debe funcionar inmediatamente** sin necesidad de tocar nada más.

---

### Rúbrica de calificación

La evaluación se realizará según los siguientes ítems. Cada nivel de logro otorga una puntuación:
* **0**: Sin hacer o sin evidencia de esfuerzo.
* **1**: Hecho, pero con errores graves o muy incompleto.
* **2**: Hecho y funcional, pero mejorable (faltan detalles, bugs menores).
* **3**: Perfecto, cumple todos los requisitos con excelencia.

| Ítem Evaluable | Peso | Nivel 0 | Nivel 1 | Nivel 2 | Nivel 3 |
| :--- | :---: | :--- | :--- | :--- | :--- |
| **0. Uso ético y eficiente de la IA (Eliminatorio)** | **Requisito imprescindible** | No sabe explicar el código. Uso fraudulento de IA. | (No se aplica) | (No se aplica) | Explica y defiende el código perfectamente. |
| **1. Entrega en tiempo y forma** | **10%** | No entregado / Formato incorrecto. | Faltan requisitos de entrega o carpeta /vendor incluida. | Cumple mayoría de normas, falta algún detalle menor en vídeo/repo. | Cumple escrupulosamente todas las normas. |
| **2. Control de versiones** | **10%** | Sin repositorio. | Un único commit al final del proyecto. | Varios commits, pero mensajes pobres o irregulares. | Uso continuado de Git, commits atómicos y descriptivos. |
| **3. Base de datos y relaciones (1:N y N:N)** | **20%** | No hay migraciones funcionales. | Relaciones mal planteadas o migraciones con errores graves. | Relaciones funcionales, pero falla la tabla pivote compleja. | Diseño de BD perfecto, claves foráneas y tabla pivote extra correctas. |
| **4. Controladores y rutas** | **20%** | No responde a las URL pedidas. | Rutas desorganizadas, código espagueti en controladores. | CRUD funcional, controladores correctos pero lógica mejorable. | Controladores limpios (resource), validación de request y lógica impecable. |
| **5. Autenticación** | **15%** | Cualquiera puede acceder a todo. | Auth funcional, pero sin proteger todas las rutas privadas. | Rutas protegidas, pero falla la autorización (alguien puede borrar proyectos ajenos). | Sistema seguro. Autenticación y Autorización aplicadas correctamente. |
| **6. Vistas blade y UX** | **15%** | No hay interfaz / Errores de renderizado. | Vistas muy básicas, sin herencia ni plantillas compartidas. | Uso correcto de Blade, interfaz funcional pero poco atractiva. | Excelente uso de componentes/layouts Blade y diseño UI muy atractivo. |
| **7. Calidad y organización del código** | **10%** | Código ilegible, variables sin sentido. | Mala indentación, código duplicado o comentado innecesariamente. | Código ordenado pero con ligeras deficiencias de buenas prácticas. | Código limpio, variables autoexplicativas, indentación perfecta y modular. |

*Recuerda que, para aprobar, es obligatorio obtener un Nivel 3 en el ítem 0 (Uso ético de IA). Este ítem se valorará con posterioridad el resto de la práctica.*