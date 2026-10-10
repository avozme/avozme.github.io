---
layout: page
title: 6.5 Introducción a la arquitectura de microservicios
permalink: /fast-api/arquitectura-microservicios/
nav_order: 5
has_children: true
parent: 6 Microservicios con Python y FastAPI
grand_parent: Desarrollo Web en Entorno Servidor
---

## 6.5. Introducción a la arquitectura de microservicios
{: .no_toc }

- TOC
{:toc}

[Descargar presentación](https://www.dropbox.com/scl/fi/xemg6hf7l8armzlnobb0v/06_05_arquitectura_microservicios.pdf?rlkey=cs2abynmsm5cqrx9xav30th06&st=89xo1udg&dl=0){: .btn .btn-primary }

A lo largo de este curso has hecho muchas cosas y montado muchas aplicaciones de servidor. Unas estaban diseñadas para ser usadas directamente por personas (aplicaciones tipo SSR, que generan vistas) y otras para ser consumidas por un frontend. 

Lo que todavía no has hecho es crear un backend diseñado para *ser consumido por otro backend*. Es decir, crear **dos servicios diferentes que colaboren entre sí**.

Eso es justo lo que vamos a hacer ahora con FastAPI, y, con ello, uniremos todo lo que hemos visto sobre microservicios: 
- Lenguaje Python
- Endpoints con validación automática
- Persistencia de datos con SQLAlchemy
- Inyección de dependencias
- Asincronía. 

Vamos a trabajar sobre un ejemplo: construiremos **dos microservicios independientes**, de manera que uno consultará al otro por HTTP. 

Como son microservicios, deben ser pequeños y simples: uno se encargará de gestionar **usuarios** y otro de gestionar **pedidos**.

### 6.5.1. Creación de dos microservicios independientes

#### Estructura general

Cada microservicio será un proyecto autónomo, con su propio entorno virtual, sus propias dependencias (`requirements.txt`) y su propia base de datos:

```text
tienda/
├── usuarios/                  # Servicio A (puerto 8001)
│   ├── main.py
│   ├── database.py
│   ├── models.py
│   ├── schemas.py
│   ├── requirements.txt
│   └── .venv/
└── pedidos/                   # Servicio B (puerto 8002)
    ├── main.py
    ├── database.py
    ├── models.py
    ├── schemas.py
    ├── requirements.txt
    └── .venv/
```

Ambos usan la misma organización que ya conocemos (modelo, esquema, ruta y `Depends`). 

El `database.py` de cada uno es idéntico, cambiando solo el nombre por defecto del archivo SQLite: (`sqlite:///./usuarios.db` en uno y `sqlite:///./pedidos.db` en el otro). Así tienes dos bases de datos separadas, como exige la arquitectura.

Para **crear cada proyecto**:

```bash
cd usuarios
python -m venv .venv
source .venv/bin/activate              # (o la variante de Windows)
pip install fastapi "uvicorn[standard]" sqlalchemy
pip freeze > requirements.txt
```

#### Servicio A: usuarios

Se encargará de **registrar y consultar usuarios**. 

*(En una aplicación completa sería también el lugar natural para el login y la emisión de tokens, pero lo dejamos fuera para centrarnos en la comunicación entre servicios).*

`models.py`:

```python
from sqlalchemy import String
from sqlalchemy.orm import Mapped, mapped_column

from database import Base


class Usuario(Base):
    __tablename__ = "usuarios"

    id: Mapped[int] = mapped_column(primary_key=True)
    nombre: Mapped[str] = mapped_column(String(50))
    email: Mapped[str] = mapped_column(String(100), unique=True)
    activo: Mapped[bool] = mapped_column(default=True)
```

`schemas.py`:

```python
from pydantic import BaseModel, ConfigDict, Field


class UsuarioCrear(BaseModel):
    nombre: str = Field(min_length=2, max_length=50)
    email: str = Field(min_length=5, max_length=100)


class UsuarioRespuesta(UsuarioCrear):
    model_config = ConfigDict(from_attributes=True)

    id: int
    activo: bool
```

`main.py`:

```python
from typing import Annotated

from fastapi import Depends, FastAPI, HTTPException
from sqlalchemy import select
from sqlalchemy.orm import Session

import models
import schemas
from database import Base, engine, get_db

Base.metadata.create_all(bind=engine)

app = FastAPI(title="Servicio de usuarios")

SesionDB = Annotated[Session, Depends(get_db)]


@app.post("/usuarios", status_code=201, response_model=schemas.UsuarioRespuesta)
def crear_usuario(datos: schemas.UsuarioCrear, db: SesionDB):
    existente = db.scalar(
        select(models.Usuario).where(models.Usuario.email == datos.email)
    )
    if existente:
        raise HTTPException(status_code=409, detail="Ya existe un usuario con ese email")
    nuevo = models.Usuario(**datos.model_dump())
    db.add(nuevo)
    db.commit()
    db.refresh(nuevo)
    return nuevo


@app.get("/usuarios", response_model=list[schemas.UsuarioRespuesta])
def listar_usuarios(db: SesionDB):
    return db.scalars(select(models.Usuario)).all()


@app.get("/usuarios/{usuario_id}", response_model=schemas.UsuarioRespuesta)
def obtener_usuario(usuario_id: int, db: SesionDB):
    usuario = db.get(models.Usuario, usuario_id)
    if usuario is None:
        raise HTTPException(status_code=404, detail="Usuario no encontrado")
    return usuario


@app.patch("/usuarios/{usuario_id}/desactivar", response_model=schemas.UsuarioRespuesta)
def desactivar_usuario(usuario_id: int, db: SesionDB):
    usuario = db.get(models.Usuario, usuario_id)
    if usuario is None:
        raise HTTPException(status_code=404, detail="Usuario no encontrado")
    usuario.activo = False
    db.commit()
    db.refresh(usuario)
    return usuario
```

**Al arrancarlo**, no olvides colocarlo en su puerto:

```bash
uvicorn main:app --port 8001 --reload
```

Comprueba en `http://127.0.0.1:8001/docs` que funciona y crea un par de usuarios.

#### Servicio B: pedidos

Este microservicio gestionará los **pedidos de los usuarios**. 

`models.py`:

```python
from sqlalchemy import String
from sqlalchemy.orm import Mapped, mapped_column

from database import Base


class Pedido(Base):
    __tablename__ = "pedidos"

    id: Mapped[int] = mapped_column(primary_key=True)
    usuario_id: Mapped[int] = mapped_column(index=True)    # ¡sin ForeignKey!
    descripcion: Mapped[str] = mapped_column(String(200))
    importe: Mapped[float]
    estado: Mapped[str] = mapped_column(String(20), default="pendiente")
```

Observa un momento `usuario_id`. En un monolito con Laravel o Spring Boot, lo habitual sería declararlo como **clave foránea** apuntando a la tabla de usuarios, y la base de datos garantizaría que no existen pedidos de usuarios inexistentes. ¡Pero aquí **no podemos hacer eso** porque **la tabla de usuarios está en otra base de datos**!

Por eso `usuario_id` es simplemente un número y la integridad referencia debe gestionarla y garantizarla tu aplicación.

`schemas.py`:

```python
from pydantic import BaseModel, ConfigDict, Field


class PedidoCrear(BaseModel):
    descripcion: str = Field(min_length=3, max_length=200)
    importe: float = Field(gt=0)


class PedidoRespuesta(PedidoCrear):
    model_config = ConfigDict(from_attributes=True)

    id: int
    usuario_id: int
    estado: str
```

`main.py` (primera versión, *todavía sin comunicarse con el otro servicio*). 

Vamos a modelar los pedidos como un **"subrecurso"** de los usuarios (`/usuarios/{id}/pedidos`), aunque podríamos crear las rutas de cualquier otra manera:

```python
from typing import Annotated

from fastapi import Depends, FastAPI, HTTPException
from sqlalchemy import select
from sqlalchemy.orm import Session

import models
import schemas
from database import Base, engine, get_db

Base.metadata.create_all(bind=engine)

app = FastAPI(title="Servicio de pedidos")

SesionDB = Annotated[Session, Depends(get_db)]


@app.post(
    "/usuarios/{usuario_id}/pedidos",
    status_code=201,
    response_model=schemas.PedidoRespuesta,
)
def crear_pedido(usuario_id: int, datos: schemas.PedidoCrear, db: SesionDB):
    nuevo = models.Pedido(usuario_id=usuario_id, **datos.model_dump())
    db.add(nuevo)
    db.commit()
    db.refresh(nuevo)
    return nuevo


@app.get(
    "/usuarios/{usuario_id}/pedidos",
    response_model=list[schemas.PedidoRespuesta],
)
def listar_pedidos_de_usuario(usuario_id: int, db: SesionDB):
    consulta = select(models.Pedido).where(models.Pedido.usuario_id == usuario_id)
    return db.scalars(consulta).all()


@app.get("/pedidos/{pedido_id}", response_model=schemas.PedidoRespuesta)
def obtener_pedido(pedido_id: int, db: SesionDB):
    pedido = db.get(models.Pedido, pedido_id)
    if pedido is None:
        raise HTTPException(status_code=404, detail="Pedido no encontrado")
    return pedido
```

**Arráncalo** en otro puerto y en otra terminal, con su propio entorno virtual:

```bash
uvicorn main:app --port 8002 --reload
```

Ya tenemos dos microservicios corriendo a la vez, cada uno con su documentación (`:8001/docs` y `:8002/docs`), su base de datos y su ciclo de vida independiente. Puedes apagar uno sin que el otro se entere.

**Pero la versión actual tiene un fallo evidente**: *puedes crear un pedido para el usuario `999`, que no existe*. Eso es porque los microservicios no se están comunicando entre sí.

¡Vamos a arreglarlo!

### 6.5.3. Comunicación HTTP entre microservicios con httpx

#### Qué es httpx

**httpx** es un cliente HTTP para Python: sirve para que tu código haga peticiones a otros servicios. 

Ofrece una API muy sencilla y **funciona tanto en modo síncrono como asíncrono**. 

Ten en cuenta que Laravel y Spring Boot también tienen clientes como httpx, solo que en esos frameworks se usan menos, porque los empleamos más para construir grandes monolitos y no pequeños microservicios que, por su naturaleza, necesitan a menuda "hablar" con otros microservicios.

**Instala httpx** en el entorno del servicio de **pedidos**:

```bash
pip install httpx
pip freeze > requirements.txt
```

Aquí puedes ver cómo se usa httpx:

```python
import httpx

# Modo síncrono (recuerda: usar solo en funciones "def")
respuesta = httpx.get("http://localhost:8001/usuarios/1")

# Modo asíncrono (recuerda: usar solo en funciones "async def")
async with httpx.AsyncClient() as cliente:
    respuesta = await cliente.get("http://localhost:8001/usuarios/1")

respuesta.status_code     # 200
respuesta.json()          # el cuerpo convertido a dict
respuesta.raise_for_status()   # lanza una excepción si el código es 4xx o 5xx
```

httpx ofrece, por supuesto, más funciones. Una muy importante es `cliente.post(url, json={...})`, para enviar por POST un cuerpo JSON. Dentro de las llaves puedes colocar:
- `params={"clave": "valor"}` -> para construir la cadena de consulta (query string)
- `headers={...}` -> para construir cabeceras de la http request.

#### Llamada asíncrona de pedidos a usuarios

Vamos a crear una llamada HTTP **asíncrona** (`await`) de pedidos a usuarios, para asegurarnos que el `usuario_id` del pedido se corresponde con un usuario existente.

Por tanto, necesitará una función `async def`. Pero el acceso a base de datos del servicio es **síncrono** y, según vimos, no debemos meter operaciones bloqueantes dentro de una `async def`.

Lo que haremos para solucionar esta aparente contradicción es **hacer asíncrona la comprobación del usuario** pero conservar el endpoint con un `def` síncrono normal. FastAPI ejecutará cada pieza en el sitio adecuado: la dependencia en el bucle de eventos y el endpoint en un hilo aparte. 

Solo tienes que añadir esto al `main.py` del microservicio de pedidos:

`pedidos/main.py`
```python
import os

import httpx

USUARIOS_URL = os.getenv("USUARIOS_URL", "http://localhost:8001")


async def usuario_valido(usuario_id: int) -> dict:
    """Consulta al servicio de usuarios y comprueba que existe y está activo."""
    try:
        async with httpx.AsyncClient(base_url=USUARIOS_URL, timeout=3.0) as cliente:
            respuesta = await cliente.get(f"/usuarios/{usuario_id}")
    except httpx.TimeoutException:
        raise HTTPException(status_code=504, detail="El servicio de usuarios tardó demasiado en responder")
    except httpx.RequestError:
        raise HTTPException(status_code=503, detail="El servicio de usuarios no está disponible")

    if respuesta.status_code == 404:
        raise HTTPException(status_code=404, detail="Usuario no encontrado")
    if respuesta.status_code != 200:
        raise HTTPException(status_code=502, detail="Respuesta inesperada del servicio de usuarios")

    usuario = respuesta.json()
    if not usuario["activo"]:
        raise HTTPException(status_code=403, detail="El usuario está desactivado")
    return usuario


UsuarioValido = Annotated[dict, Depends(usuario_valido)]
```

Ahora, **los endpoints que necesitan un usuario válido lo piden con `UsuarioValido`** en lugar de recibir directamente `usuario_id`:

```python
@app.post(
    "/usuarios/{usuario_id}/pedidos",
    status_code=201,
    response_model=schemas.PedidoRespuesta,
)
def crear_pedido(datos: schemas.PedidoCrear, usuario: UsuarioValido, db: SesionDB):
    nuevo = models.Pedido(usuario_id=usuario["id"], **datos.model_dump())
    db.add(nuevo)
    db.commit()
    db.refresh(nuevo)
    return nuevo


@app.get(
    "/usuarios/{usuario_id}/pedidos",
    response_model=list[schemas.PedidoRespuesta],
)
def listar_pedidos_de_usuario(usuario: UsuarioValido, db: SesionDB):
    consulta = select(models.Pedido).where(models.Pedido.usuario_id == usuario["id"])
    return db.scalars(consulta).all()
```

La dependencia recibe `usuario_id` de la ruta, hace la llamada y devuelve los datos del usuario (un `dict` con el JSON que respondió el otro servicio). 

Si algo falla, lanza una `HTTPException` y el endpoint **no se ejecuta**. Además, al ser una dependencia, puedes reutilizarla en cualquier ruta que necesite validar al usuario.

#### Dos consejos importantes

1. **Pon siempre un timeout explícito.** Sin él, si el otro servicio se cuelga, tu servicio también se queda esperando indefinidamente y el "cuelgue" se expandirá de un microservicio a otro.
2. **El orden de los `except` importa**: `TimeoutException` es un caso particular de `RequestError`, así que debe ir **antes**.

> **Posible mejora avanzada**: crear un `AsyncClient` en cada petición es sencillo pero poco eficiente, porque no reutiliza las conexiones. En un servicio real se crea un único cliente al arrancar la aplicación y se comparte, pero nosotros no lo haremos para simplificar.

#### ¡Pruébalo!

Con los dos servicios en marcha, puedes realizar estas comprobaciones en Postman y, si todo ha salido bien, deberían funcionar:

1. Crea un usuario en `POST :8001/usuarios`.
2. Crea un pedido con `POST :8002/usuarios/1/pedidos` y el cuerpo `{"descripcion": "Teclado mecánico", "importe": 59.9}`. Debe devolver `201` (éxito), porque el usuario `1` existe (lo acabas de crear).
3. Prueba con un usuario inexistente (como `/usuarios/999/pedidos`): debes obtener un `404` (not found).
4. Desactiva al usuario con `PATCH :8001/usuarios/1/desactivar` y repite el pedido. Ahora debes obtener un `403` (forbidden).
5. **Apaga el servicio de usuarios** (Ctrl+C) y repite el pedido. El error debe ser ahora un `503`. El servicio de pedidos sigue vivo y responde con un error controlado en lugar de petar.

#### Consultar varios servicios a la vez

Si el microservicio de pedidos necesitase comprobar más cosas de otros microservicios, no solo el usuario, podrías usar `asyncio.gather` para lanzar **las dos consultas a la vez**. Por ejemplo:

```python
import asyncio

async with httpx.AsyncClient(timeout=3.0) as cliente:
    resp_usuario, resp_producto = await asyncio.gather(
        cliente.get(f"{USUARIOS_URL}/usuarios/{usuario_id}"),
        cliente.get(f"{CATALOGO_URL}/productos/{producto_id}"),
    )
```

Si cada consulta tarda 200 ms, en conjunto tardan unos 200 ms y no 400, que es lo que tardaría si hicieras primero una y luego otra.

### 6.5.4. Middlewares

Un **middleware** es código que se ejecuta **en cada petición** antes de que el endpoint tome el control y/o después de que el endpoint responda. 

Es, por tanto, el mismo concepto que los *middlewares* de Laravel. Sirven para tareas como registrar logs, medir tiempos, añadir cabeceras, comprobar autenticación...

Un middleware en FastAPI es una función `async def` decorada con `@app.middleware("http")`. Este, por ejemplo, mide cuánto tarda cada petición:

```python
import time

from fastapi import Request

@app.middleware("http")
async def medir_tiempo(request: Request, call_next):
    inicio = time.perf_counter()
    respuesta = await call_next(request)         # aquí se ejecuta el endpoint
    duracion_ms = (time.perf_counter() - inicio) * 1000
    respuesta.headers["X-Process-Time-ms"] = f"{duracion_ms:.1f}"
    print(f"{request.method} {request.url.path} -> {respuesta.status_code} ({duracion_ms:.1f} ms)")
    return respuesta
```

Lo que hay antes de la línea `await call_next(request)` se ejecuta **en el camino de ida** (antes de ejecutar el endpoint); lo que hay después, **en el camino de vuelta** (al terminar el endpoint, antes de enviar la respuesta). 

En la práctica final vas a tener que preparar un pequeño middleware para hacer un log de depuración.
