---
layout: page
title: 6.6 Práctica final
permalink: /fast-api/practica-final
nav_order: 5
has_children: true
parent: 6 Microservicios con Python y FastAPI
grand_parent: Desarrollo Web en Entorno Servidor
---

## 6.6. Práctica final: Sistema de reservas de recursos del centro mediante microservicios
{: .no_toc }

- TOC
{:toc}

Vamos a poner a prueba todo lo que hemos aprendido sobre Python, FastAPI y arquitectura de microservicios. Esta práctica final no es una simple repetición de los apuntes. Es **un reto que simula un proyecto real**. Tendrás que investigar, planificar y programar.

Se trata de construir un **Sistema de reservas de recursos de un centro educativo** (el IES Celia Viñas, por ejemplo). Será una API formada por **tres microservicios independientes** que permitirá a los usuarios reservar recursos compartidos (aulas de informática, carritos de portátiles, proyectores, salas de reuniones...) sin que dos reservas se pisen entre sí.

*(En el próximo tema construiremos con Vue.js un Frontend para esta API, de manera que dispondremos de una aplicación web completa y funcional mezclando un montón de tecnologías que realmente se usan en el entorno productivo).*

### IMPORTANTE: uso de IA en esta práctica

Podemos enfrentarnos a esta práctica gracias a que existe la IA para ayudarnos (si no, el temario no abarcaría ni la décima parte). Así que, como en otras ocasiones, **puedes y debes usar la IA**, pero debes hacerlo de forma **ética y eficiente**:

1. **Prohibido copiar y pegar todo este enunciado en la IA** (te vamos a pedir una copia de tu conversación con la IA). Si le pides a la IA que te haga la práctica entera, te vomitará un código inmenso que no entenderás y que probablemente no funcionará bien (y menos aún con tres servicios hablando entre sí).
2. **Construye pieza a pieza**. Pide ayuda a la IA para tareas concretas. Por ejemplo: *"Genera un modelo de SQLAlchemy 2.0 para una tabla de recursos con estos campos (a continuación, le explicas qué campos son)"*, *"¿Cómo valido en un esquema de Pydantic que una fecha de fin sea posterior a la de inicio?"*, *"¿Cómo hago dos peticiones con httpx a la vez y qué pasa si una de las dos falla?"*, etc.

   Es decir, tienes que **comprender lo que le estás pidiendo**, y para eso tienes que **saber cómo funciona FastAPI**.
3. **Comprende cada línea de código**. Eres el responsable final de tu aplicación. Si hay un bloque de código que no entiendes, pídele a la IA que te lo explique línea por línea o pregúntale al profesor.

> **RECUERDA QUE** parte de la evaluación consistirá en una defensa oral o preguntas escritas sin acceso a IA, y que esas preguntas pueden aparecerte en el examen. Si no sabes explicar cómo funciona tu propia aplicación, la práctica completa estará **suspensa**, independientemente de que funcione o de que sea muy elegante, porque no habrás podido demostrar *tu autoría*.

A modo de ejemplo, estas son el tipo de preguntas que te podrán hacer en la defensa:

* ¿Por qué `usuario_id` en la tabla de reservas no es una clave foránea?
* ¿Qué ocurre exactamente si el servicio de recursos está apagado y alguien crea una reserva? ¿Y si está encendido pero tarda 10 segundos en responder?
* ¿Por qué esta función es `async def` y esta otra es `def`? ¿Qué pasaría si cambiaras una por la otra?
* ¿Qué ocurre si quitas el *timeout* de la llamada con `httpx`?
* ¿Por qué el servicio de reservas no necesita CORS para hablar con el de usuarios, pero sí lo necesitaría un frontend?
* ¿Cómo detectas que dos reservas se solapan? ¿Y si dos peticiones idénticas llegan exactamente a la vez?

### Especificación de requisitos

Se trata de una **API REST** formada por tres microservicios desarrollados con **FastAPI**. No hay que desarrollar interfaz gráfica: se probará mediante la documentación Swagger (`/docs`) y Postman. (En el tema siguiente construirás un frontend con Vue.js que consumirá estos mismos servicios, así que deja los servicios bien preparados.)

#### 1. Arquitectura y datos

Los tres servicios serán:
- **usuarios** (puerto 8001).
- **recursos** (puerto 8002).
- **reservas** (puerto 8003).

Tienen que cumplir estas reglas:

* **Deben ser tres proyectos independientes**, cada uno en su carpeta, con su propio `requirements.txt`, su propia configuración de Docker y su propia base de datos.
* **Prohibido compartir base de datos o código** entre servicios. Los servicios solo pueden comunicarse **mediante peticiones HTTP**.
* **Prohibido usar claves foráneas entre servicios**. La integridad de los datos entre servicios se garantiza consultando a la API del servicio correspondiente.
* El servicio de **reservas** es el único que llama a los otros dos. Los servicios de usuarios y recursos **no se conocen entre sí** ni conocen a reservas.

Estas serán las **entidades** de cada servicio (te facilitamos los campos mínimos, pero puedes añadir los que consideres oportunos):

* **Servicio `usuarios`**: 
    `Usuario` → `id`, `nombre`, `email` (único), `rol` (solo admite `profesor`, `alumno` o `conserje`), `activo` (booleano).
* **Servicio `recursos`**: 
    `Recurso` → `id`, `nombre` (único), `tipo` (solo admite `aula`, `portatiles`, `proyector` o `sala`), `capacidad` (entero mayor que 0), `ubicacion` (opcional), `activo` (booleano).
* **Servicio `reservas`**: 
    `Reserva` → `id`, `usuario_id`, `recurso_id`, `inicio` (fecha y hora), `fin` (fecha y hora), `motivo`, `estado` (`confirmada` o `cancelada`) y `creada_en` (generada por el servidor).

> *Nota importante*: en los servicios de usuarios y recursos **no se borrarán registros, solo se desactivarán** (`activo = false`). Tendrás que ser capaz de explicar por qué esta decisión es necesaria en una arquitectura de microservicios, así que piénsalo.

#### 2. Funcionalidades

Debes implementar los siguientes endpoints (rutas orientativas, puedes mejorarlas si tienes una buena razón para ello).

**Servicio `usuarios` (puerto 8001)**

| Método | Ruta | Descripción |
| :--- | :--- | :--- |
| POST | `/usuarios` | Crear usuario. Si el email está duplicado, error `409`. |
| GET | `/usuarios` | Listar con filtros opcionales (necesitas parasarle `rol` y `solo_activos`) y **paginación** (con los datos `pagina` y `limite`). |
| GET | `/usuarios/{id}` | Obtener un usuario. |
| PUT | `/usuarios/{id}` | Actualizar un usuario. |
| PATCH | `/usuarios/{id}/desactivar` | Desactivar un usuario. |

**Servicio `recursos` (puerto 8002)**

| Método | Ruta | Descripción |
| :--- | :--- | :--- |
| POST | `/recursos` | Crear recurso. Si nombre duplicado, error `409`. |
| GET | `/recursos` | Listar con filtros opcionales (`tipo`, `capacidad_min`, `solo_activos`) y **paginación**. |
| GET | `/recursos/{id}` | Obtener un recurso. |
| PUT | `/recursos/{id}` | Actualizar un recurso. |
| PATCH | `/recursos/{id}/desactivar` | Desactivar un recurso. |

**Servicio `reservas` (puerto 8003)**

| Método | Ruta | Descripción |
| :--- | :--- | :--- |
| POST | `/reservas` | Crear una reserva (ver reglas debajo). |
| GET | `/reservas` | Listar con filtros opcionales (`usuario_id`, `recurso_id`, `estado`, `desde`, `hasta`) y **paginación**. |
| GET | `/reservas/{id}` | Obtener una reserva. |
| GET | `/reservas/{id}/detalle` | Devuelve la reserva **junto con los datos del usuario** (nombre, email) **y del recurso** (nombre, tipo). |
| PATCH | `/reservas/{id}/cancelar` | Cancelar una reserva. |
| GET | `/recursos/{recurso_id}/agenda` | Reservas confirmadas de un recurso en un día (parámetro `fecha`), ordenadas por hora de inicio. |

**Reglas de negocio de las reservas:**

* **Validación de los datos de entrada** (con Pydantic, devolviendo `422` si fallan): la fecha de `fin` debe ser posterior a la de `inicio`; `inicio` no puede estar en el pasado; la duración máxima de una reserva es de **4 horas**; el `motivo` no puede estar vacío.
* **Validación contra otros servicios**: antes de guardar la reserva hay que comprobar que el **usuario existe y está activo** y que el **recurso existe y está activo**. Estas dos comprobaciones son independientes entre sí, así que deben lanzarse **a la vez** (de forma concurrente), no una detrás de otra.
* **No se pueden solapar dos reservas confirmadas del mismo recurso.** Dos reservas se solapan si el inicio de una es anterior al fin de la otra y viceversa. Las reservas **consecutivas** (una termina justo cuando empieza la siguiente) son válidas.
* Una reserva **cancelada** no bloquea el recurso. Solo se puede cancelar una reserva que esté `confirmada`.
* El endpoint `/reservas/{id}/detalle` debe consultar también a los dos servicios **de forma concurrente**.

**Códigos de estado esperados.** Debes devolver el código adecuado en cada situación (creo que están todos, pero, si falta alguno, añádelo):

| Situación | Código |
| :--- | :---: |
| Datos de entrada inválidos (fechas incoherentes, rol o tipo no permitido...) | `422` |
| Usuario, recurso o reserva inexistente (indica en el mensaje cuál es) | `404` |
| Usuario desactivado intenta reservar | `403` |
| Recurso desactivado | `409` |
| Reserva solapada con otra | `409` |
| Cancelar una reserva ya cancelada | `409` |
| El servicio consultado está apagado o inaccesible | `503` |
| El servicio consultado tarda demasiado en responder | `504` |
| El servicio consultado responde algo inesperado (error `500`...) | `502` |

#### 3. Requisitos técnicos

* **Python moderno y *type hints*** en todas las funciones, parámetros y atributos.
* **Pydantic**: esquemas separados para entrada y salida (`response_model`), con validaciones mediante `Field()` y, para las reglas que afectan a varios campos a la vez (como las fechas), validadores propios (investiga `model_validator`). Para restringir `rol` y `tipo` a valores válidos, investiga `Enum` o `Literal`.
* **SQLAlchemy** como ORM, con la separación **modelo – esquema – ruta** (`models.py`, `schemas.py`, `database.py`, `main.py`, como hemos visto en los apuntes). S
* **Inyección de dependencias** con `Depends`: `get_db` para la sesión de base de datos, y dependencias reutilizables para evitar repetir código.
* **Asincronía correcta**: las llamadas a otros servicios con `httpx` serán asíncronas, y con un **timeout explícito**. La base de datos usa SQLAlchemy síncrono, así que *no debes bloquear el bucle de eventos*.
* **Configuración mediante variables de entorno**: URL de la base de datos, URLs de los otros servicios y orígenes permitidos para CORS. *No debe haber ninguna credencial ni URL fija en el código.*
* **Middleware**: cada servicio debe registrar por consola, por cada petición, el método, la ruta, el código de estado y el tiempo de respuesta, y añadir la cabecera `X-Process-Time` a la respuesta.
* **CORS** configurado en los tres servicios, con los orígenes permitidos leídos de una variable de entorno (prepara el terreno para el frontend con Vue.js, que se servirá desde otro origen). Debes demostrar que funciona con una petición de *preflight* (`OPTIONS`).
* **Docker**: un `docker-compose.yml` en la raíz que levante los tres servicios. Es posible que necesites un `Dockerfile` para configurar bien los servicios. Los servicios se comunican entre sí por el **nombre del servicio** de Compose. Los datos deben **persistir** al reiniciar los contenedores (volúmenes). ¡Ah, y usa solo imágenes oficiales!
* **Datos de prueba**: un script `seed.py` en la raíz que **cargue datos de ejemplo a través de la API** (usuarios, recursos y varias reservas). No debe acceder directamente a las bases de datos: debe respetar las fronteras de los servicios.

#### 4. Calidad de la API y documentación

* La documentación **OpenAPI** generada (`/docs`) debe ser clara: `title` y `description` en cada servicio, `tags`, `summary` en cada endpoint y `description` en los campos más relevantes de los esquemas.
* Nombres de rutas, campos y mensajes de error **coherentes** entre los tres servicios.
* Un **`README.md`** en la raíz con: descripción del proyecto, esquema de la arquitectura, instrucciones de arranque, ejemplos de peticiones y, al menos, **tres decisiones de diseño** explicadas (por ejemplo: por qué no hay claves foráneas entre servicios, por qué se desactiva en lugar de borrar, qué ocurre si un servicio se cae).
* Un archivo `.gitignore` adecuado (entornos virtuales, `__pycache__`, bases de datos `.db`...).

### Fases de desarrollo recomendadas

Para no saturarte, te recomiendo que sigas este orden:

1. **Fase 1: Preparación**. Crea el repositorio en Git con las tres carpetas. En cada una, crea el entorno virtual, instala FastAPI y haz un "hola mundo" que arranque en su puerto. Haz tu primer *commit*.
2. **Fase 2: Servicios `usuarios` y `recursos`**. Son los más sencillos y los más parecidos a lo que ya has hecho: modelos, esquemas, endpoints, validaciones, filtros y paginación. Pruébalos a fondo desde Swagger antes de seguir.
3. **Fase 3: Servicio `reservas` sin comunicación**. Haz primero el servicio funcionando "a ciegas", confiando en que los identificadores son correctos: validación de fechas, detección de solapamientos y cancelación. Esta es la parte con más lógica de negocio, y conviene aislarla.
4. **Fase 4: Comunicación entre servicios**. Añade las llamadas con `httpx`: las comprobaciones concurrentes con `asyncio.gather`, los timeouts y la traducción de errores (`503`, `504`, `502`...). Después haz el endpoint de detalle. Prueba apagando servicios a propósito.
5. **Fase 5: Cuestiones transversales**. Middleware, CORS, variables de entorno, `docker-compose.yml`, Dockerfiles (si las necesitas), `seed.py`, colección de Postman y `README.md`. Graba el vídeo al final.

### Entrega de la práctica

La entrega debe cumplir **estrictamente** con estos requisitos. El incumplimiento de cualquiera de ellos conllevará penalización o rechazo de la entrega:

1. **Código fuente comprimido**: Sube a Moodle Centros un archivo ZIP con tu proyecto. *EXCEPTUANDO los entornos virtuales (`.venv`), las carpetas `__pycache__` y los archivos de base de datos (`*.db`)*. (Si los incluyes, serás penalizado).
2. **Vídeo demostrativo**: Graba un vídeo capturando tu pantalla y demostrando el funcionamiento de tu aplicación: el arranque con Docker Compose, los tres servicios en Swagger, una reserva correcta, los casos típicos de error (solapamiento, usuario desactivado, un servicio apagado) y la petición de *preflight* de CORS. Debes explicarlo **con tu propia voz** (nada de voces sintetizadas o IA). Sube el vídeo a Moodle Centros o un enlace a YouTube/Drive, como prefieras.
3. **Repositorio público**: Incluye un enlace a tu repositorio público en GitHub o GitLab. *Se revisará el historial de commits*.
4. **Conversación con la IA**: Sube un archivo .docx o .odt con TODA tu conversación con la IA. Necesitamos ver cómo has interactuado con la Inteligencia Artificial.
5. **Colección de Postman**: Incluye la colección exportada (archivo `.json`) con las peticiones que demuestren cada uno de los requisitos, incluidos los casos de error.
6. **Reproducibilidad**: El profesor descargará tu ZIP (o clonará tu repo) y ejecutará `docker compose up -d --build` y `python seed.py`. **La aplicación debe funcionar inmediatamente** después de eso, sin necesidad de tocar nada más.

### Rúbrica de calificación

La evaluación se realizará según los siguientes ítems. Cada nivel de logro otorga una puntuación:
* **0**: Sin hacer o sin evidencia de esfuerzo.
* **1**: Hecho, pero con errores graves o muy incompleto.
* **2**: Hecho y funcional, pero mejorable (faltan detalles, bugs menores).
* **3**: Perfecto, cumple todos los requisitos con excelencia.

| Ítem evaluable | Peso | Nivel 0 | Nivel 1 | Nivel 2 | Nivel 3 |
| :--- | :---: | :--- | :--- | :--- | :--- |
| **0. Uso ético y eficiente de la IA (Eliminatorio)** | **Requisito imprescindible** | No sabe explicar el código. Uso fraudulento de IA. | (No se aplica) | (No se aplica) | Explica y defiende el código perfectamente. |
| **1. Entrega en tiempo y forma** | **10%** | No entregado / Formato incorrecto. | Faltan requisitos de entrega o se incluyen `.venv` o bases de datos. | Cumple mayoría de normas, falta algún detalle en vídeo/repo/Postman. | Cumple escrupulosamente todas las normas, incluido el funcionamiento de `seed.py`. |
| **2. Control de versiones y documentación** | **10%** | Sin repositorio ni README. | Un único commit al final. README pobre o nulo. | Varios commits, README básico, OpenAPI usable pero sin descripciones. | Commits descriptivos. README con decisiones de diseño, OpenAPI cuidada y *Type Hints* en todo el código. |
| **3. ORM y persistencia (SQLAlchemy)** | **10%** | No hay persistencia funcional. | Modelos con errores graves, BD compartida o claves foráneas entre servicios. | Persistencia correcta y BD separadas, pero faltan restricciones (únicos, nulos) en los modelos. | Una BD por servicio, modelos limpios, restricciones correctas y sesión gestionada mediante inyección (`Depends`). |
| **4. Esquemas y validación (Pydantic)** | **15%** | Sin validación de entrada. | Usa un solo esquema para in/out, sin filtrar datos sensibles o sin validaciones estrictas. | Usa `response_model`, pero faltan validaciones complejas (fechas) o no restringe valores (Enums). | Separación in/out impecable. Usa `Field()`, enumeraciones, y validadores personalizados (`model_validator`). |
| **5. Endpoints y lógica de negocio** | **20%** | Rutas fallan constantemente o no existen. | Endpoints básicos. Faltan filtros, paginación o reglas clave (como los solapamientos). | Funcional, pero no controla todos los límites (4h max), o devuelve códigos HTTP genéricos (solo 200/500). | Lógica de negocio (solapamientos, desactivaciones) perfecta. Filtros/paginación operativos. Códigos HTTP rigurosos y exactos. |
| **6. Comunicación asíncrona (httpx)** | **15%** | Los servicios no se comunican. | Llamadas síncronas (bloqueantes), sin manejo de errores ni *timeouts*. | Asíncrono con `httpx`, pero sin llamadas concurrentes, o no captura ni traduce todos los errores (503/504). | `httpx` asíncrono, llamadas concurrentes con `gather`, timeouts explícitos y errores controlados y traducidos. |
| **7. Middleware y seguridad CORS** | **10%** | Sin CORS ni middleware. | CORS inseguro (`*`) o middleware incompleto. | CORS funcional pero estático en código. Middleware cuenta tiempos pero no inyecta cabecera (o viceversa). | Middleware registra y añade cabecera en cada servicio. CORS configurado estrictamente leyendo desde variables de entorno. |
| **8. Arquitectura Docker y variables de entorno (.env)** | **10%** | No se puede ejecutar. | Solo arranca a mano, con URLs fijas en el código. Falla el `docker compose`. | Levanta con Docker, pero la BD no persiste (sin volúmenes) o hay credenciales incrustadas en el código. | Reproducibilidad total con `docker compose up`. Comunicación por nombre de contenedor, volúmenes persistentes y todo extraído a `.env`. |

### Ampliaciones optativas para subir nota

Todas estas ampliaciones necesitarán que investigues algún aspecto avanzado de FastAPI para hacerlos. Son optativos, para quien termine pronto. Puedes intentar todos cuanto quieras (hasta **+1 punto** sobre la nota final, solo si el ítem 0 está en Nivel 3):

1. Usar PostgreSQL o MySQL en lugar de SQLite (+0,5)
2. Devolver `/reservas/{id}/detalle` con degradación elegante si un servicio no responde, en lugar de un error (+0,5)
3. Incluir tests con `pytest` y `dependency_overrides` (+0,5)
4. Reutilizar un único cliente `httpx` creado al arrancar la aplicación (+0,5).
5. Organizar rutas con `APIRouter` (+0,5)

*Recuerda que, para aprobar, es obligatorio obtener un Nivel 3 en el ítem 0 (Uso ético de IA). Este ítem se valorará con posterioridad al resto de la práctica, mediante la defensa oral.*
