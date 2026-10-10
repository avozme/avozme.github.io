---
layout: page
title: 6.4 Persistencia de datos
permalink: /fastapi/persistencia/
nav_order: 3
has_children: true
parent: 6 Microservicios con Python y FastAPI
grand_parent: Desarrollo Web en Entorno Servidor
---

## 6.4. Persistencia de datos
{: .no_toc }

- TOC
{:toc}

[Descargar presentación](https://www.dropbox.com/scl/fi/95e864lecmuq3ditpl4t0/06_04_persistencia.pdf?rlkey=zvu8oks8n35y9gga2lug8d7ly&st=lw2o3hln&dl=0){: .btn .btn-primary }

Hasta ahora, el API de productos que hemos montado guarda los datos en un diccionario y cada vez que reiniciamos el servidor desaparecen. 

Es hora de conectarla a una **base de datos relacional**:
- **SQLite** es un gestor de BD relacionales **extremadamente simple y ligero**. ¡Todos los datos se guardan en un único archivo! En el ecosistema Python se usa mucho para desarrollo local y pruebas rápidas. FastAPI se conecta a SQLite por defecto.
- **MySQL** ya lo conoces. Para aplicaciones y microservicios en producción, es una opción perfectamente válida y compatible con FastAPI.
- **PostgreSQL** es parecida en seguridad y rendimiento a MySQL, pero, curiosamente, *en el ecosistema Python se usa más que MySQL*. No hay ningún motivo técnico o de rendimiento para ello, son simplemente costumbres.

FastAPI usa **un ORM** llamado **SQLAlchemy**, que es el equivalente al *Eloquent* de Laravel o al *JPA/Hibernate* de Java. SQLAlchemy te permite conectarte a cualquiera de estas bases de datos (y muchas más) con la misma facilidad.

### 6.4.1. Conexión a una base de datos relacional

#### SQLAlchemy comparado con Eloquent y JPA/Hibernate

El ORM más utilizado en Python es **SQLAlchemy**. Si vienes de Eloquent o de Hibernate, casi todos sus conceptos te resultarán familiares, aunque con otro nombre:

| Concepto | Laravel (Eloquent) | Java (JPA/Hibernate) | Python (SQLAlchemy) |
|---|---|---|---|
| Clase que representa una tabla | Clase que extiende `Model` | Clase con `@Entity` | Clase que hereda de `Base` |
| Configuración de la conexión | `config/database.php` y `.env` | `application.properties` | `create_engine(url)` |
| Fábrica de sesiones | (no existe) | `EntityManagerFactory` | `sessionmaker` |
| Buscar por clave | `Producto::find(1)` | `em.find(Producto.class, 1L)` | `db.get(Producto, 1)` |
| Migraciones | Migraciones de Artisan | Flyway o Liquibase | **Alembic** |

Hay, sin embargo, una **diferencia importante de enfoque**:

- Eloquent sigue **el patrón *Active Record***, según el cual el propio modelo sabe guardarse (`$producto->save()`)
- SQLAlchemy, como JPA, sigue el patrón *Data Mapper*, según el cual el modelo es un objeto "tonto" y es la **sesión** quien lo guarda (`db.add(producto)`, `db.commit()`).

> **Una alternativa a SQLAlchemy.** Existe una librería llamada **SQLModel**, creada por el mismo autor de FastAPI, que combina SQLAlchemy y Pydantic en una sola clase (el mismo modelo sirve para la tabla y para el esquema de la API). Reduce código repetido, pero oculta justo la separación de responsabilidades que nos interesa comprender.

#### Instalación y conexión con SQLAlchemy

SQLite viene incluido con Python, así que para empezar solo necesitas SQLAlchemy. Con el entorno virtual activado, teclea:

```bash
$ pip install sqlalchemy
$ pip freeze > requirements.txt     # recuerda: pip no actualiza este archivo por sí solo
```

Crea un archivo `database.py` que centralice la conexión:

```python
import os

from sqlalchemy import create_engine
from sqlalchemy.orm import DeclarativeBase, sessionmaker

# La URL de conexión se lee de una variable de entorno (DATABASE_URL)
# (si no existe esa variable, usaremos por defecto SQLite)
DATABASE_URL = os.getenv("DATABASE_URL", "sqlite:///./catalogo.db")

# Opción necesaria solo para SQLite (ver explicación debajo)
connect_args = {"check_same_thread": False} if DATABASE_URL.startswith("sqlite") else {}

# Conexión con la base de datos
engine = create_engine(DATABASE_URL, connect_args=connect_args)

# Fábrica de sesiones: cada vez que la llames obtienes una sesión nueva
SessionLocal = sessionmaker(bind=engine)

class Base(DeclarativeBase):
    """Clase base de la que heredarán todos los modelos."""
    pass   # pass = no hagas nada (clase vacía)
```

Te comento algunos elementos clave del código anterior:

- **`engine`**: representa la conexión con la base de datos (con su gestión interna de conexiones). Se crea **una sola vez** para toda la aplicación.
- **`SessionLocal`**: es una *factoría* de sesiones. Es el equivalente de la `EntityManagerFactory` de JPA.
- **`Base`**: la clase de la que heredan tus modelos para que SQLAlchemy los reconozca.
- **`check_same_thread`**: por defecto, SQLite no permite usar una conexión desde un hilo distinto al que la creó. La documentación de FastAPI recomienda desactivar esa comprobación (con las versiones recientes de SQLAlchemy, suele funcionar sin ella, pero conviene dejarla).
- **La URL de conexión** tiene la forma `dialecto://usuario:contraseña@host:puerto/basededatos`. Para SQLite, `sqlite:///./catalogo.db` crea un archivo `catalogo.db` en la carpeta actual.

**Leer la URL desde una variable de entorno** es una práctica profesional importante. Así, el mismo código funciona en tu portátil con SQLite y en un contenedor con PostgreSQL o MySQL, sin tocar nada. Y las credenciales no quedan escritas en el repositorio.

#### Definir los modelos

Un **modelo**, ya sabes, es la clase que representa una tabla. Se declara con **type hints** y usando `Mapped[...]`, muy parecido a lo que hace Pydantic.

Los modelos suelen escribirse todos a mogollón en un archivo llamado `models.py`, aunque, si tienes muchos (algo poco habitual en microservicios) puedes crear un archivo para cada uno. 

Este sería el aspecto de `models.py` con la clase `Producto`:

```python
from sqlalchemy import String
from sqlalchemy.orm import Mapped, mapped_column

from database import Base


class Producto(Base):
    __tablename__ = "productos"

    id: Mapped[int] = mapped_column(primary_key=True)
    nombre: Mapped[str] = mapped_column(String(50))
    descripcion: Mapped[str | None] = mapped_column(String(200), nullable=True)
    precio: Mapped[float]
    stock: Mapped[int] = mapped_column(default=0)
```

Aparecen muchas cosas parecidas a Pydantic y alguna que no:

- `Mapped[int]` indica el tipo de la columna. SQLAlchemy lo traduce al tipo SQL correspondiente (`INTEGER`, `VARCHAR`, `FLOAT`...).
- Si el tipo incluye `| None`, la columna **admite `NULL`**; si no, es `NOT NULL`. Es la misma idea de "obligatorio u opcional" que en Pydantic.
- `mapped_column()` se usa cuando necesitas añadir detalles: clave primaria, longitud de un `String`, valor por defecto, índices...
- Una clave primaria entera se autoincrementa por defecto.

> **Nota**: para guardar dinero se recomienda el tipo `Numeric` (con `Decimal`) en lugar de `float`, porque los decimales binarios acumulan errores de redondeo. Aquí usamos `float` para mantener el ejemplo sencillo.

#### Crear las tablas

Para que SQLAlchemy cree las tablas a partir de tus modelos, usas `create_all`. Lo harás al arrancar la aplicación (en `main.py`, que veremos completo enseguida):

```python
import models                      # IMPRESCINDIBLE: registra los modelos en Base
from database import Base, engine

Base.metadata.create_all(bind=engine)
```

Dos advertencias importantes:

- **Debes importar `models` antes de llamar a `create_all`**. Los modelos solo se "registran" en `Base` cuando Python ejecuta el archivo donde están definidos. Si no lo importas, SQLAlchemy no sabrá qué tablas crear y no te avisará de ningún error.
- `create_all` **solo crea las tablas que no existen**. No modifica las existentes. Si añades una columna a un modelo, la tabla no cambia. Para evolucionar el esquema de forma controlada se usa **Alembic**, el equivalente a las migraciones de Artisan o a Flyway, pero eso excede al propósito de esta introducción. Nosotros nos limitaremos a borrar el archivo `.db` cuando cambiemos un modelo.

#### Operaciones básicas con la base de datos

Antes de integrarlo todo en nuestro CRUD de productos, observa cómo trabaja SQLAlchemy con la base de datos con un script sencillo:

```python
from sqlalchemy import select

from database import SessionLocal
from models import Producto

db = SessionLocal()

# Crear
nuevo = Producto(nombre="Ratón inalámbrico", precio=19.9)
db.add(nuevo)           # lo marca para guardar
db.commit()             # lo guarda (INSERT) y confirma la transacción
db.refresh(nuevo)       # recarga el objeto desde la BD (para ver el id asignado)
print(nuevo.id)

# Consultar
# ...por clave primaria
uno = db.get(Producto, 1)
# ...todos (scalars() devuelve un iterador y all() lo convierte en una lista)
todos = db.scalars(select(Producto)).all()
# ...con filtro y límite
baratos = db.scalars(
    select(Producto).where(Producto.precio <= 50).limit(10)
).all()

# Actualizar (basta con modificar el objeto y confirmar)
uno.stock = 25
db.commit()

# Eliminar
db.delete(uno)
db.commit()

db.close()              # liberar la sesión
```

Aunque el ejemplo está bastante claro (si lo lees con atención), te recalcamos algunas cosas importantes:

- **Nada se guarda hasta hacer `commit()`**. Cuidado con esto, olvidarse del `commit()` es un fallo habitual.
- Tras un `commit()`, SQLAlchemy hace "caducar" los atributos del objeto y ya no los considera válidos (porque han podido cambiar). Al hacer `db.refresh(obj)`, vuelve a cargarse, de modo que tengamos, por ejemplo, el `id` que ha asignado la base de datos tras una inserción.
- **Cierre de la sesión** (`db.close()`). Es una buena práctica hacerlo, claro, pero con FastAPI no hay que escribirlo en cada ruta. De eso se encargará la inyección de dependencias.
- **SQLAlchemy dispone un modo asíncrono** (`create_async_engine`, con drivers como `aiosqlite` o `asyncpg`). Aquí usamos el modo **síncrono** de forma deliberada. Recuerda que las operaciones de base de datos así serán bloqueantes y los endpoints debes declararlos con `def` y no con `async def`.

#### Pasar de SQLite a PostgreSQL o MySQL

SQLite es perfecto para aprender y para pruebas. Pero en un microservicio real usarás un servidor de base de datos como **PostgreSQL** o **MySQL**. 

El cambio es mínimo. Solo tienes que:

1) Instalar el driver de PostgreSQL o de MySQL:

```bash
$ pip install "psycopg[binary]"   # driver de PostgreSQL
$ pip install pymysql             # driver de MySQL
```

Después, levanta un PostgreSQL o un MySQL con Docker Compose, como ya sabes hacer (de hecho, puede servirte el MySQL que usaste en el Tema 1). Te ofrecemos dos `docker-compose.yml` para levantar cualquiera de los dos servicios (elige uno, no levantes los dos a la vez porque solo consumirás recursos tontamente):

**`docker-compose.yml` de ejemplo para levantar PostgreSQL**

```yaml
services:
  db:
    image: postgres:16
    environment:
      POSTGRES_USER: catalogo
      POSTGRES_PASSWORD: catalogo_dev
      POSTGRES_DB: catalogo
    ports:
      - "5432:5432"
    volumes:
      - pgdata:/var/lib/postgresql/data

volumes:
  pgdata:
```

**`docker-compose.yml` de ejemplo para levantar MySQL**

```yaml
services:
  db:
    image: mysql:8.4

    environment:
      MYSQL_USER: catalogo
      MYSQL_PASSWORD: catalogo_dev
      MYSQL_DATABASE: catalogo
      MYSQL_ROOT_PASSWORD: root_dev

    ports:
      - "3306:3306"

    volumes:
      - mysqldata:/var/lib/mysql

volumes:
  mysqldata:
```

Y por último, **arranca el driver de tu base de datos** indicándole la nueva URL en `database.py`:

```bash
# ****ARRANCAR EL DRIVER DE PostgreSQL****

# Linux / macOS
DATABASE_URL="postgresql+psycopg://catalogo:catalogo_dev@localhost:5432/catalogo" uvicorn main:app --reload

# Windows (PowerShell)
$env:DATABASE_URL="postgresql+psycopg://catalogo:catalogo_dev@localhost:5432/catalogo"
uvicorn main:app --reload


# ****ARRANCAR EL DRIVER DE MySQL****

# Linux / macOS
DATABASE_URL="mysql+pymysql://catalogo:catalogo_dev@localhost:3306/catalogo" uvicorn main:app --reload

# Windows (PowerShell)
$env:DATABASE_URL="mysql+pymysql://catalogo:catalogo_dev@localhost:3306/catalogo"
uvicorn main:app --reload
```

**El resto del microservicio seguirá exactamente igual**. ¡Esa es una de las muchas ventajas de usar un ORM! El programador se olvida de las diferencias entre las bases de datos.

### 6.4.2. Organización de archivos en un proyecto FastAPI

#### ¡Dos clases con el mismo nombre!

Te habrás dado cuenta de que ahora existen **dos clases** que describen un producto:

- La de **SQLAlchemy** (`models.Producto`): describe cómo se guarda el producto en la **base de datos**.
- La de **Pydantic** (`schemas.ProductoCrear` y `schemas.ProductoRespuesta`): describe cómo viaja el producto por la **API** (el JSON que entra y que sale).

¿No sería más cómodo tener una sola? A veces sí (de ahí que exista SQLModel), pero separarlas tiene ventajas importantes, y es la práctica habitual también en Spring Boot:

- **Seguridad**: el modelo de usuario guarda `password_hash`, pero el JSON de respuesta jamás debe incluirlo.
- **Campos que no controla el cliente**: el `id` o las fechas de creación los genera el servidor, así que no deben aparecer en el esquema de entrada.
- **Independencia**: puedes cambiar el nombre de una columna sin romper el contrato de tu API, o al revés.
- **Validación distinta**: la entrada se valida con reglas de negocio (precio mayor que cero); la base de datos tiene sus propias restricciones.

#### Organización de archivos propuesta para un proyecto FastAPI

Como hemos visto, realmente FastAPI no obliga a nombrar los archivos de ninguna manera especial, pero la que hemos ido siguiendo es una organización habitual.

Este es un resumen de la estructura de archivos que hemos estado usando:

```text
catalogo/
├── main.py            # aplicación y rutas
├── database.py        # engine, sesiones, Base, get_db
├── models.py          # modelos SQLAlchemy (tablas)
├── schemas.py         # esquemas Pydantic (DTO)
├── requirements.txt
└── .venv/             # (no se sube al repositorio)
```

Para no confundir `Producto` de un lado con `Producto` del otro, importaremos los módulos completos y usaremos el prefijo. Aí, `models.Producto` es la tabla y `schemas.ProductoCrear` es el DTO de entrada.

#### Un ejemplo donde la separación es imprescindible

Imagina que añades usuarios al microservicio. Mira lo que ocurre con la contraseña:

```python
# models.py
class Usuario(Base):
    __tablename__ = "usuarios"

    id: Mapped[int] = mapped_column(primary_key=True)
    email: Mapped[str] = mapped_column(String(100), unique=True)
    password_hash: Mapped[str]            # se guarda el HASH, nunca la contraseña en claro


# schemas.py
class UsuarioCrear(BaseModel):
    email: str
    password: str                         # el cliente envía la contraseña...


class UsuarioRespuesta(BaseModel):
    model_config = ConfigDict(from_attributes=True)

    id: int
    email: str                            # ...pero la respuesta nunca devuelve ni password ni hash
```

El cliente envía `password`, tu ruta la convierte en un hash (cómo hacer esto correctamente lo veremos enseguida) y la guarda en `password_hash`. Como `UsuarioRespuesta` no declara ese campo, **es imposible que salga por error en el JSON**, aunque el objeto de base de datos sí lo tenga. 

En cambio, si usases una sola clase para todo, tendrías que acordarte de excluirlo manualmente en cada endpoint. Y, si se te olvida, ¡estarías exponiendo la password a todo el mundo!

### 6.4.3. Inyección de dependencias

#### ¿Quién abre y cierra la sesión?

Cada petición necesita su propia sesión de base de datos, que debe **abrirse al empezar y cerrarse siempre al terminar**, aunque ocurra un error. 

Podrías hacerlo a mano en cada ruta, pero es tedioso y propenso a que cometas errores:

```python
# ¡¡OJO!! Esto funciona pero no es lo más recomendable
@app.get("/productos")
def listar_productos():
    db = SessionLocal()
    try:
        return db.scalars(select(models.Producto)).all()
    finally:
        db.close()
```

Tampoco puedes usar una sesión global compartida porque varias peticiones simultáneas compartirían el mismo estado y se interferirían. 

La solución es la **inyección de dependencias** (*Dependency Injection*).

#### Cómo funciona la inyección de dependencias en FastAPI

Ya conoces la idea de **inyección de dependencias** de Spring Boot y de Laravel: el propio framework instancia y te entrega los objetos que necesitas en cada momento. 

FastAPI propone una versión muy simple de esta idea. Tú declaras en los parámetros de tu función qué necesitas con `Depends(...)` y FastAPI **instancia los objetos necesarios y llama a las funciones adecuadas y, al final, te devuelve su resultado**.

En concreto, **para usar bases de datos** suele usarse una **dependencia llamada `get_db` por convenio**. Solo añádela a `database.py`:

```python
def get_db():
    db = SessionLocal()
    try:
        yield db
    finally:
        db.close()
```

Lo que ocurre aquí es esto:

1. FastAPI crea la sesión (`SessionLocal()`) y la entrega a tu endpoint con `yield`. Esto **detiene** la ejecución de `get_db()` y pasa el control a tu endpoint.
2. Tu endpoint usa `db` para acceder a la base de datos.
3. Cuando el endpoint termina (con éxito o con error), FastAPI **reanuda la ejecución** de `get_db()` y se ejecuta el bloque `finally`, con lo que la sesión se cierra.

Para **usar esta dependencia en las rutas** solo tienes que hacer esto:

```python
from typing import Annotated
from fastapi import Depends
from sqlalchemy.orm import Session
from database import get_db

# usaremos un alias para no escribir Annotated[Session, Depends(get_db)]
# en cada ruta.
SesionDB = Annotated[Session, Depends(get_db)]    

@app.get("/productos")
def listar_productos(db: SesionDB):
    return db.scalars(select(models.Producto)).all()
```

Aquí estamos diciendo que la ruta `GET /productos` necesita un parámetro `db` y que para obtener ese dato hay que llamar a `get_db`".

#### Dependencias que dependen de otras dependencias

Una dependencia puede declarar sus propios parámetros de ruta, de consulta... o incluso otras dependencias. 

Esto puede ser útil para **eliminar código repetido**. 

Fíjate en que `GET`, `PUT` y `DELETE` de `/productos/{id}` repiten siempre lo mismo: buscar el producto y devolver 404 si no existe. ¡Podemos convertirlo en una dependencia!

```python
def obtener_producto_o_404(producto_id: int, db: SesionDB) -> models.Producto:
    producto = db.get(models.Producto, producto_id)
    if producto is None:
        raise HTTPException(status_code=404, detail="Producto no encontrado")
    return producto

ProductoExistente = Annotated[models.Producto, Depends(obtener_producto_o_404)]
```

Las rutas, así, quedan cada vez más simples. FastAPI reconoce que `producto_id` es el parámetro de la ruta y se lo pasa a la dependencia. Además, dentro de una misma petición **`get_db` se ejecuta una sola vez**, aunque la pidan varias dependencias: todos reciben la misma sesión. Esto es una mejora importante, porque el objeto `producto` que devuelve la dependencia y la sesión `db` que usa tu ruta para guardar los cambios deben ser la misma.

### 6.4.4. El CRUD completo por fin

Ya tenemos todas las piezas para **construir un API completo para productos**, acceso a base de datos incluido.

- `database.py` será el "motor" de la base de datos y fabricará las sesiones, `Base` y `get_db`.
- `models.py` contendrá los modelos de la base de datos.
- `schemas.py` contendrá los modelos para Pydantic.
- `main.py` contendrá las rutas y sus comportamientos.

```python
from typing import Annotated

from fastapi import Depends, FastAPI, HTTPException, Query
from sqlalchemy import select
from sqlalchemy.orm import Session

import models                       # debe importarse antes de create_all
import schemas
from database import Base, engine, get_db

Base.metadata.create_all(bind=engine)

app = FastAPI(title="API de productos")

SesionDB = Annotated[Session, Depends(get_db)]


def obtener_producto_o_404(producto_id: int, db: SesionDB) -> models.Producto:
    producto = db.get(models.Producto, producto_id)
    if producto is None:
        raise HTTPException(status_code=404, detail="Producto no encontrado")
    return producto


ProductoExistente = Annotated[models.Producto, Depends(obtener_producto_o_404)]


@app.get("/productos", response_model=list[schemas.ProductoRespuesta])
def listar_productos(
    db: SesionDB,
    buscar: str | None = None,
    precio_max: float | None = None,
    limite: Annotated[int, Query(ge=1, le=100)] = 10,
):
    consulta = select(models.Producto)
    if buscar:
        consulta = consulta.where(models.Producto.nombre.ilike(f"%{buscar}%"))
    if precio_max is not None:
        consulta = consulta.where(models.Producto.precio <= precio_max)
    return db.scalars(consulta.limit(limite)).all()


@app.get("/productos/{producto_id}", response_model=schemas.ProductoRespuesta)
def obtener_producto(producto: ProductoExistente):
    return producto


@app.post("/productos", status_code=201, response_model=schemas.ProductoRespuesta)
def crear_producto(datos: schemas.ProductoCrear, db: SesionDB):
    nuevo = models.Producto(**datos.model_dump())
    db.add(nuevo)
    db.commit()
    db.refresh(nuevo)
    return nuevo


@app.put("/productos/{producto_id}", response_model=schemas.ProductoRespuesta)
def actualizar_producto(
    datos: schemas.ProductoCrear,
    producto: ProductoExistente,
    db: SesionDB,
):
    for campo, valor in datos.model_dump().items():
        setattr(producto, campo, valor)     # asigna cada campo al objeto
    db.commit()
    db.refresh(producto)
    return producto


@app.delete("/productos/{producto_id}", status_code=204)
def eliminar_producto(producto: ProductoExistente, db: SesionDB):
    db.delete(producto)
    db.commit()
```

Si arrancas el microservicio con `uvicorn main:app --reload`, ya podrás crear productos desde Postman (o desde `/docs`)

**Reinicia el servidor** y comprueba que los datos siguen ahí. ¡Ya tienes persistencia!

(Si usas SQLite, incluso puedes inspeccionar el archivo `catalogo.db` con el comando `sqlite3 catalogo.db` o con una herramienta gráfica como DB Browser for SQLite).

**ATENCIÓN**. Para simplificar el ejemplo, nuestras rutas usan directamente la sesión de la base de datos. *En proyectos más grandes se extraen las consultas a un módulo aparte (como los "servicios" de Spring Boot).*

