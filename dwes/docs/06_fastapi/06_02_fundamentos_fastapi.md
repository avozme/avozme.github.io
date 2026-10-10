---
layout: page
title: 6.2 Fundamentos de FastAPI
permalink: /fast-api/fundamentos/
nav_order: 2
has_children: true
parent: 6 Microservicios con Python y FastAPI
grand_parent: Desarrollo Web en Entorno Servidor
---

## 6.2. Fundamentos de FastAPI
{: .no_toc }

- TOC
{:toc}

[Descargar presentación](https://www.dropbox.com/scl/fi/1sm0ylqazvzdoi4zcou1y/06_02_fundamentos_fastapi.pdf?rlkey=yarj7nzynwxasiwyejalb0e1v&st=sssxfs9s&dl=0){: .btn .btn-primary }

Ya sabes lo básico de Python, así que toca conocer la herramienta principal de esta unidad. En este apartado vas a ver qué es FastAPI, por qué se usa tanto para construir microservicios, qué papel juega el servidor que lo ejecuta (Uvicorn) y, sobre todo, cómo funciona su modelo de **concurrencia** basado en `async` / `await`. Esto último es lo que más lo diferencia de lo que has hecho hasta ahora con Laravel y Spring Boot, así que merece que le dediques tiempo.

---

### 6.2.1. ¿Qué es FastAPI y por qué microservicios?

#### Qué es un microservicio

Hasta ahora has trabajado con aplicaciones **monolíticas**, es decir, con un único gran proyecto Laravel (o Spring Boot) que contiene todo, desde las rutas hasta la lógica de negocio y el acceso a datos, y que se despliega como una sola pieza.

Una arquitectura de **microservicios** propone lo contrario: dividir la aplicación en varios servicios pequeños, cada uno responsable de **una capacidad concreta del negocio**, que se desarrollan, despliegan y escalan de forma independiente y se comunican entre sí por red (normalmente mediante HTTP con JSON, es decir, APIs REST como las que ya conoces).

Imaginemos, por ejemplo, una tienda online dividida en 4 servicios:

```text
                     ┌──────────────────┐
                     │   Cliente (web,  │
                     │  app móvil, etc) │
                     └────────┬─────────┘
                              │
      ┌───────────────┬───────┴────────┬────────────────┐
      ▼               ▼                ▼                ▼
┌───────────┐   ┌───────────┐   ┌───────────┐   ┌───────────┐
│ Usuarios  │   │ Catálogo  │   │  Pedidos  │   │   Pagos   │
│ (Laravel) │   │ (FastAPI) │   │(Spring B.)│   │ (FastAPI) │
│   BD 1    │   │   BD 2    │   │   BD 3    │   │   BD 4    │
└───────────┘   └───────────┘   └───────────┘   └───────────┘
```

Hay dos ideas clave del esquema:

- **Cada servicio es autónomo**: tiene su propio código, su propia base de datos y su propio despliegue (casi siempre en un contenedor Docker). Incluso su propio equipo de desarrollo independiente.
- **Pueden estar construidos con tecnologías distintas**, porque se comunican en JSON a través de sus endpoints. Un equipo puede programar el *Catálogo* en FastAPI y otro encargarse de *Pedidos* en Spring Boot.

Pero usar microservicios también tiene **inconvenientes** que no se deben dejar de lado al valorar qué solución conviene adoptar para montar un servidor:

| Ventajas de los microservicios | Inconvenientes de los microservicios |
|---|---|
| Cuando es necesario cambiar o modificar algo, solo se toca el servicio que lo necesita | Más complejidad operativa porque hay muchos servicios que desplegar y vigilar |
| Un fallo queda más aislado | La comunicación por red añade latencia (es más lento) y posibles puntos de fallo |
| Equipos y tecnologías independientes | Mantener la consistencia de los datos entre servicios puede ser difícil |
| Despliegues pequeños y frecuentes | Depurar una petición que atraviesa varios servicios es más costoso |

La conclusión realista: **los microservicios no son mejores que un monolito por defecto**:

- Para una aplicación pequeña, un monolito bien organizado suele ser la mejor opción.
- Los microservicios compensan cuando el sistema, o el equipo, crece lo suficiente como para necesitar esa independencia. 

Por último, te menciono algunos de los **errores típicos** que se cometen al usar microservicios:

- **Monolitos distribuidos**: si tienes microservicios que no pueden desplegarse ni funcionar el uno sin el otro, en el fondo no son independientes. Si los montas como microservicios tienes todos los inconvenientes de los microservicios y ninguna ventaja. Mejor un monolito grande y bien hecho que diez microservicios pequeños y mal hechos.
- **Base de datos compartida**: dos microservicios leyendo y escribiendo las mismas tablas es un error clásico. Rompe la independencia de los microservicios porque cualquier cambio en una tabla afecta a ambos. **Cada microservicio debe ser dueño de sus datos** y el resto accede a esos datos a través del API del propio microservicio.
- **Cadenas largas de llamadas síncronas**: el microservicio A llama a B, que llama a C, que llama a D. Si todas las llamadas son síncronas, la latencia se va sumando suma y la probabilidad de fallo también. Los mecanismos de asincronía de los microservicios los hacen más complicados de programar pero también más eficientes.
- **Servicios demasiado pequeños**: si para crear un pedido hay que coordinar diez microservicios, algo está mal en el diseño de la arquitectura de la aplicación.

#### Qué es FastAPI

**FastAPI** es un framework de Python para construir APIs. Lo creó Sebastián Ramírez y se publicó en 2018. 

Aunque FastAPI puede usarse para montar una aplicación tipo monolito, como Laravel o Spring Boot, no suele ser así. Los microservicios deben ser pequeños, arrancar rápido, consumir pocos recursos y dejar claro al resto de servicios cuál es su interfaz (qué endpoints expone y qué respuestas produce). **FastAPI es perfecto para todo eso**:

- **Poco código**: un endpoint se monta con tres o cuatro líneas, sin configuración previa.
- **Arranque rápido y poco consumo de memoria**, lo que lo hace muy cómodo de empaquetar en imágenes Docker ligeras desplegables en cualquier sitio.
- **Autodocumentación**: la documentación se genera sola a partir del código y eso facilita mucho que otros equipos sepan cómo usar el microservicio.
- **Validación integrada**: cada servicio se protege de datos mal formados sin escribir reglas a mano.
- **Asincronía nativa**: esto, que aún no hemos visto, es perfecto para servicios que pasan mucho tiempo esperando (bases de datos, por ejemplo), que es justo el caso de muchos microservicios.

FastAPI se apoya en dos librerías principalmente:

- **Starlette**: se encarga de la parte web (rutas, peticiones, respuestas, WebSockets).
- **Pydantic**: se encarga de la validación y conversión de datos a partir de los type hints que ya hemos visto.

#### Primeros pasos con FastAPI

Lo primero es crear un entorno virtual (venv) para nuestro proyecto FastAPI y activarlo:

```bash
$ python -m venv .venv
$ source .venv/bin/activate    # .venv\Scripts\Activate.ps1 en Windows
```

Ahora vamos a instalar las dependencias necesarias para FastAPI:

```bash
$ python -m pip install --upgrade pip  # Optativo: actualiza pip antes de instalar nada
$ pip install "fastapi[standard]"      # Instala versión actual de FastAPI y sus dependencias estándar
$ pip freeze > requirements.txt        # Guardamos las dependencias para poder replicarlas más tarde
```

¡Ya puedes probar el servidor que viene integrado con FastAPI! Crea un archivo llamado `main.py` con este contenido:

```python
from fastapi import FastAPI

app = FastAPI()

@app.get("/")
def raiz():
    return {"mensaje": "Hola desde FastAPI"}

@app.get("/saludo/{nombre}")
def saludo(nombre: str, mayusculas: bool = False):
    texto = f"Hola, {nombre}"
    return {"mensaje": texto.upper() if mayusculas else texto}
```

Ahora lanza el **servidor Uvicorn**, que viene con FastAPI, así:

```bash
$ uvicorn main:app --reload
```

El servidor estará escuchando en `http://127.0.0.1:8000` (puedes probar con `http://127.0.0.1:8000/saludo/Ana?mayusculas=true`).

Hay varias cosas que ocurren aquí y que conviene que identifiques antes de entrar en detalles:

- `nombre: str` es un **parámetro de ruta** y `mayusculas: bool = False` un **parámetro de consulta** (*query param*) opcional. 
    FastAPI sabe cuál es cuál por cómo aparecen en la ruta (`@app.get("/saludo/{nombre}")`) y valida y convierte los tipos por ti.
- Devolver un `dict` es suficiente: FastAPI lo convierte a JSON automáticamente.
- Si pruebas `/saludo/Ana?mayusculas=quizás`, recibirás un error `422` con un JSON explicando qué ha fallado. ¡Sin que hayas escrito ninguna validación!
- **Documentación automática**: abre `http://127.0.0.1:8000/docs` y verás una interfaz interactiva (llamada **Swagger UI**) con todos tus endpoints. Puedes incluso probarlos desde ahí. También existe `/redoc` y `/openapi.json`.

> **Nota**: las versiones recientes de FastAPI incluyen también un comando propio, `fastapi dev main.py`, que se instala con `pip install "fastapi[standard]"` y por debajo usa Uvicorn con el mismo resultado que hemos visto aquí.

#### FastAPI frente a Spring Boot y Laravel

Vamos a comparar los tres frameworks en términos de **simplicidad** y **rendimiento**, con matices, porque aquí es fácil caer en tópicos.

**SIMPLICIDAD.** Observa el mismo endpoint (`GET /saludo/{nombre}`), que solo devuelve un JSON con un saludo, montado en los tres frameworks:

```php
// Laravel (routes/api.php)
Route::get('/saludo/{nombre}', function (string $nombre) {
    return ['mensaje' => "Hola, $nombre"];
});
```

```java
// Spring Boot
@RestController
public class SaludoController {

    @GetMapping("/saludo/{nombre}")
    public Map<String, String> saludo(@PathVariable String nombre) {
        return Map.of("mensaje", "Hola, " + nombre);
    }
}
```

```python
# FastAPI
@app.get("/saludo/{nombre}")
def saludo(nombre: str):
    return {"mensaje": f"Hola, {nombre}"}
```

Laravel y FastAPI son claramente más simples y Spring Boot exige el típico "ceremonial" de Java (clase, anotaciones, imports, tipos...).

**RENDIMIENTO.** Aquí hay que hablar con precaución, porque depende de qué se mida:

- **Laravel (con PHP-FPM)** arranca el framework en cada petición, y cada petición ocupa un proceso mientras se atiende. Es muy productivo, pero por petición es el que más recursos consume. Existen alternativas como Laravel Octane (Swoole, RoadRunner...) que mantienen la aplicación en memoria y mejoran mucho esos números.
- **Spring Boot** es excelente en rendimiento porque la JVM optimiza el código mientras se ejecuta y, para trabajo intensivo de CPU, suele ser el mejor de los tres con diferencia. Su contrapartida es un **arranque más lento y un mayor consumo de memoria**, algo que pesa cuando tienes muchos microservicios pequeños.
- **FastAPI** ofrece un rendimiento muy bueno **gracias a su modelo asíncrono**, comparable al de otros frameworks asíncronos como los de **Node.js**. En un servicio que pasa la mayor parte del tiempo esperando entradas/salida (consultas a base de datos, llamadas a otros servicios), es capaz de manejar muchas peticiones simultáneas con menos recursos que los otros dos.

Pero ten en cuenta que, en la mayoría de aplicaciones reales, **el cuello de botella no es el framework**, sino la base de datos, la red o la forma de escribir el código. 

Es decir, que elegir FastAPI no te hace automáticamente más rápido que Spring Boot o Laravel. Solo te da un modelo más ligero para servicios con muchos tiempos de espera entre peticiones.

#### Tabla resumen comparativa FastAPI vs Spring Boot vs Laravel

| Aspecto | FastAPI | Spring Boot | Laravel |
|---|---|---|---|
| Lenguaje | Python | Java | PHP |
| Código necesario para un endpoint simple | Muy poco | Bastante | Muy poco |
| Arranque y memoria | Ligero | Pesado | Ligero (con PHP-FPM) |
| Modelo de concurrencia | Asíncrono (bucle de eventos) | Hilos (modo reactivo opcional) | Un proceso por petición (Octane opcional) |
| Velocidad de ejecución una vez arrancado | Limitada | Muy buena | Limitada |
| Validación de Request | Integrada con el sistema | Se consiguen anotaciones | Se consiguen con reglas |
| Documentación | Automática | Se necesitan librerías adicionales | Se necesitan paquetes extra |
| Madurez y ecosistema | Joven, en fuerte crecimiento, muchos cambios | Maduro y estable | Maduro y estable |
| Ideal para | Microservicios y APIs con mucha E/S | Sistemas empresariales grandes | Aplicaciones web completas (SSR, API REST...) |

---

### 6.2.2. Servidores ASGI y WSGI: introducción a Uvicorn

#### Un framework no atiende peticiones por sí solo

Para que Laravel funcione necesitas arrancar antes un servidor, bien con Docker (como hace Laravel Sail), con `php artisan serve` o instalando tu propio Apache o Nginx nativo en tu máquina. 

En cambio, con Spring Boot, el servidor (Tomcat) viene **embebido** y se inicia al arrancar la aplicación. 

**¿Cómo lo hace FastAPI?**

FastAPI se parece en esto más a Laravel que a Spring Boot, porque separa explícitamente el framework del servidor:

- El **framework** (FastAPI propiamente dicho) contiene la lógica de la aplicación: rutas, validaciones, consultas de datos, respuestas...
- El **servidor** abre el puerto, recibe las conexiones HTTP y le pasa cada petición al framework.

Para que ambos se entiendan, Python usa un **protocolo de comunicación** entre servidor y aplicación. Y aquí viene el primer escollo: existen dos, llamado **WSGI** y **ASGI**.

#### WSGI: el estándar clásico (síncrono)

**WSGI** (*Web Server Gateway Interface*) es el **estándar histórico** de Python, usado por otros frameworks como **Flask** o **Django**, con servidores como **Gunicorn**. 

Su modelo es **síncrono**: un trabajador (proceso o hilo) atiende una petición de principio a fin y, mientras espera algo (una consulta SQL, por ejemplo), **permanece ocupado sin hacer nada**.

Es un modelo que ya conoces: es el mismo planteamiento de Laravel o de Spring Boot. Funciona bien, pero para atender más peticiones simultáneas necesitas más trabajadores (que a veces pasan mucho rato sin hacer nada, solo esperando), y cada uno necesita su memoria y su cuota de CPU.

#### ASGI: el estándar moderno (asíncrono)

**ASGI** (*Asynchronous Server Gateway Interface*) es el sucesorde WSGI. Permite que la aplicación sea **asíncrona**, es decir, que mientras una petición espera una respuesta de la base de datos o de quien sea, el servidor puede **atender otras** en el mismo proceso. 

Además, soporta conexiones de larga duración como los **WebSockets**, algo que WSGI no puede hacer de forma natural.

**FastAPI usa ASGI**, así que necesita un servidor ASGI. Y el más usado es **Uvicorn**.

#### El servidor Uvicorn

Uvicorn es un **servidor ASGI rápido y ligero**. Al instalarlo con `pip install uvicorn[standard]` o con `pip install fastapi[standard]`, incluye todos los componentes necesarios para funcionar.

Para lanzar una aplicación Python con este servidor, solo teclea:

```bash
uvicorn main:app --reload
```

- **`main`** es, obviamente, el nombre del archivo Python que deseas ejecutar (sin la extensión `.py`).
- **`app`** es el nombre de la variable dentro del archivo donde se hace `app = FastAPI()`.
- **`--reload`**: reinicia el servidor automáticamente cada vez que guardas un cambio en el código. Es muy cómodo **en desarrollo**, pero **no debe usarse en producción**.

Uvicorn puede lanzarse con otras opciones en la línea de comandos, como:

```bash
uvicorn main:app --port 9000            # cambiar el puerto (por defecto, 8000)
uvicorn main:app --host 0.0.0.0         # escuchar en todas las interfaces
uvicorn main:app --workers 4            # varios procesos (producción, sin --reload)
```

Fíjate en `--host 0.0.0.0`: por defecto Uvicorn solo escucha en `127.0.0.1`, es decir, en tu propia máquina. Cuando metas la aplicación en un contenedor Docker, necesitarás lanzarlo con `0.0.0.0` para poder acceder desde fuera del contenedor.

En cuanto a `--workers`, debes saber que un solo proceso de Uvicorn ya puede atender muchas peticiones concurrentes gracias al modelo asíncrono, pero solo usa **un núcleo** de CPU. En un servidor con varios núcleos, lo lógico es lanzar varios procesos para poder atender aún más peticiones simultáneas.

---

### 6.2.3. Asincronía en servidor

#### async / await en Python

En el módulo de Desarrollo Web en Entorno Cliente, y también en el módulo optativo, has debido trabajar con `async` / `await` en JavaScript.

En Python es muy parecido. Solo necesitas usar dos palabras clave:

- **`async def`** para definir una función asíncrona (llamada **coroutine** o co-rutina)
- **`await`** dentro de la función asíncrona para ponerla en pausa hasta que el proceso termine.

Míralo en este ejemplo:

```python
import asyncio

async def esperar(tiempo: int) -> str:
    print(f"Esperando {tiempo} segundos...")
    await asyncio.sleep(tiempo)
    return f"He terminado de esperar {tiempo} segundos"

async def main():
    resultado = await esperar(2)
    print(resultado)

asyncio.run(main())               # arranca el bucle de eventos y ejecuta main()
```

Fíjate en `asyncio.sleep()`: es la versión **asíncrona** de `sleep()`. Mientras este proceso duerme, el bucle de eventos puede dedicarse a otra cosa, como ejecutar otros programas asíncronos. En cambio, con la versión síncrona (`time.sleep()`), el programa se quedaría "colgado" y consumiendo recursos mientras espera.

#### asyncio.gather

El verdadero beneficio de `async` aparece cuando lanzas varias cosas a la vez con `asyncio.gather`:

```python
import asyncio
import time

async def consultar(nombre: str, segundos: int) -> str:
    print(f"Inicio: {nombre}")
    await asyncio.sleep(segundos)  # simula lo que tarda una BD en responder
    print(f"Fin: {nombre}")
    return f"datos de {nombre}"

async def main():
    inicio = time.perf_counter()   # anota instante de inicio de la ejecución

    resultados = await asyncio.gather(
        consultar("usuarios", 2),
        consultar("pedidos", 2),
        consultar("productos", 2),
    )

    print(resultados)
    print(f"Tiempo total: {time.perf_counter() - inicio:.1f} s")

asyncio.run(main())
```

La salida de este programa será algo como:

```text
Inicio: usuarios
Inicio: pedidos
Inicio: productos
Fin: usuarios
Fin: pedidos
Fin: productos
['datos de usuarios', 'datos de pedidos', 'datos de productos']
Tiempo total: 2.0 s
```

Es decir, que tres esperas de 2 segundos han tardado **2 segundos en total**, no 6, porque se han *solapado*. 

Si hubiéramos hecho tres `await consultar(...)` seguidos, uno tras otro, sí habrías tardado unos 6 segundos. Este es exactamente el tipo de situación que se da en un microservicio que necesita consultar varias fuentes para armar una respuesta.

#### Comparación de async entre Python y JavaScript

| Concepto | JavaScript | Python |
|---|---|---|
| Función asíncrona | `async function f()` | `async def f()` |
| Esperar un resultado | `await` | `await` |
| Qué devuelve al llamarla | Una `Promise` | Una co-rutina (*coroutine*) |
| ¿Se ejecuta al llamarla? | Sí, de inmediato | **No**: hay que esperarla con `await` o planificarla |
| Bucle de eventos | Incluido en el motor | Módulo `asyncio` (lo gestiona Uvicorn en FastAPI) |
| Varias a la vez | `Promise.all([...])` | `asyncio.gather(...)` |

La diferencia que más despista es la cuarta. En Python, llamar a una función `async` **sin** `await` no ejecuta nada, solo crea el objeto co-rutina:

```python
async def saludar():
    return "hola"

saludar()          # ¡No hace nada! Devuelve <coroutine object ...> y un aviso
await saludar()    # Esto sí la ejecuta (dentro de otra función async)
```

Si ves el aviso *"coroutine was never awaited"*, casi seguro que se te ha olvidado un `await`.

#### async en los endpoints de FastAPI

En FastAPI puedes declarar tus endpoints de dos formas y las dos funcionan:

```python
@app.get("/a")
async def endpoint_async():     # se ejecuta directamente en el bucle de eventos
    ...

@app.get("/b")
def endpoint_normal():          # FastAPI lo ejecuta en un hilo aparte
    ...
```

Para saber si un endpoint debe ser `def` o `async def` puedes tener presente esta regal:
* Usa `async def` si dentro del endpoint usas librerías **asíncronas** (como los drivers de BD asíncronos) con `await`
* Usa `def` si dentro del endpoint usas librerías **bloqueantes** (como `requests`, drivers de BD síncronos, etc)
* Usa `def` si **no estás seguro**. El servidor puede funcionar más lento pero *no se bloqueará*.

Efectivamente, el mayor peligro de usar `async def` incorrectamente en un endpoint es que **cualquier operación bloqueante congelará el bucle de eventos completo**, y con él, a todos los clientes. ¡El servidor dejará de responder!

Compruébalo tú mismo con este código:

```python
import asyncio
import time
from fastapi import FastAPI

app = FastAPI()

@app.get("/ping")
async def ping():
    return {"mensaje": "pong"}

@app.get("/espera-correcta")
async def espera_correcta():
    await asyncio.sleep(10)          # cede el control: el servidor sigue atendiendo
    return {"mensaje": "terminé sin bloquear"}

@app.get("/espera-mala")
async def espera_mala():
    time.sleep(10)                   # ¡MAL! bloquea todo el servidor
    return {"mensaje": "terminé bloqueando"}

@app.get("/espera-en-hilo")
def espera_en_hilo():
    time.sleep(10)                   # Bien: al ser def, va a un hilo aparte
    return {"mensaje": "terminé en un hilo"}
```

Puedes probar este sencillo código con Postman o con tu navegador web:

1. Lanza una petición a `/espera-correcta` y, sin esperar, otra a `/ping`. `/ping` responderá al instante aunque la otra petición aún no haya finalizado.
2. Lanza ahora la petición `/espera-mala` y, sin esperar, lanza `/ping`. Esta vez **`/ping` tarda unos 10 segundos** en responder, porque el servidor entero estaba bloqueado por `/espera-mala`.
3. Lanza `/espera-en-hilo` y `/ping`. `/ping` volverá a responder al instante.

#### Qué cosas no resuelve la asincronía

La asincronía está muy bien para aprovechar mejor los recursos del servidor, pero no hace magia:

- **No acelera el trabajo de CPU** (cálculos pesados, procesar imágenes...). Esa carga sigue ocupando el único hilo del bucle de eventos. Para eso hacen falta varios procesos (`--workers`) u otras estrategias.
- **No hace que cada petición individual sea más rápida**: una consulta que tarda 2 segundos seguirá tardando 2 segundos. Lo que mejora es cuántas peticiones puede gestionar el servidor **a la vez** con los mismos recursos.
- **Tiene un coste de complejidad**: el código asíncrono es más difícil de depurar y exige usar librerías compatibles. Si tu servicio es simple y poco concurrente, un `def` normal es perfectamente válido.
