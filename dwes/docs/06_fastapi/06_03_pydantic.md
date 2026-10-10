---
layout: page
title: 6.3 Creación de endpoints REST y validación con Pydantic
permalink: /fastapi/pydantic/
nav_order: 3
has_children: true
parent: 6 Microservicios con Python y FastAPI
grand_parent: Desarrollo Web en Entorno Servidor
---

## 6.3. Creación de endpoints REST y validación con Pydantic
{: .no_toc }

- TOC
{:toc}

[Descargar presentación](https://www.dropbox.com/scl/fi/yvh5n9lda0ivzp98yv3pw/06_03_endpoints_REST_validacion_Pydantic.pdf?rlkey=rr0sufv4imz654rys2mt9n96x&st=k5e0bgd7&dl=0){: .btn .btn-primary }

Ya sabemos qué es FastAPI, cómo se ejecuta con Uvicorn y cómo funciona su modelo asíncrono. Ahora toca lo que toca es aprender a **crear endpoints** para **montar un servicio web**. 

A lo largo del apartado trabajaremos con un ejemplo guía: una pequeña **API de productos**, que podría ser el microservicio de Catálogo del esquema que vimos en 6.2.1. Por ahora los datos vivirán en memoria (una estructura de Python). Más adelante los conectaremos a una base de datos real.

### 6.3.1. Operaciones CRUD básicas con decoradores

#### Qué es un decorador

En FastAPI las rutas se declaran con **decoradores**, que son como las **anotaciones** de Spring Boot. Es decir,  líneas que empiezan por `@` y se colocan justo encima de una función. 

Un decorador es, a grandes rasgos, algo que "envuelve" a una función para añadirle comportamiento. Podemos crear nuestros propios decoradores, pero eso excede el propósito de esta intrudcción. Con los que ya trae FastAPI tenemos suficiente.

Observa este ejemplo:

```python
@app.get("/productos")
def listar_productos():
    ...
```

Esto significa: "cuando llegue una Request `GET /productos`, ejecuta esta función".

#### Los cuatro decoradores del CRUD

En Laravel, `Route::apiResource` genera de golpe las rutas CRUD de un recurso. En FastAPI no hay una atajo equivalente. Tienes que declarar cada operación de forma explícita.

Cada operación CRUD tiene su método HTTP, su decorador y su código de estado habitual:

| Operación | Método HTTP | Decorador | Ruta típica | Código de éxito |
|---|---|---|---|---|
| Obtener todos | GET | `@app.get()` | `/productos` | 200 |
| Obtener uno | GET | `@app.get()` | `/productos/{id}` | 200 (404 si no existe) |
| Crear | POST | `@app.post()` | `/productos` | 201 |
| Actualizar | PUT | `@app.put()` | `/productos/{id}` | 200 |
| Eliminar | DELETE | `@app.delete()` | `/productos/{id}` | 204 (sin cuerpo) |

Existe también `@app.patch()` para actualizaciones parciales, que funciona igual que los demás.

#### Un CRUD completo en memoria

Este es el archivo `main.py` completo para implementar un CRUD de productos (solo falta el acceso a BD, los datos van a estar de momento en memoria). 

Léelo con calma. Casi todo te sonará y los detalles nuevos los explicamos justo debajo.

```python
from fastapi import FastAPI, HTTPException
from pydantic import BaseModel

app = FastAPI()

# Declaración de atributos del modelo Pydantic
class Producto(BaseModel):
    nombre: str
    precio: float
    stock: int = 0

# "Base de datos" provisional en memoria: diccionario id -> producto
productos: dict[int, dict] = {}

@app.get("/productos")
def listar_productos():
    return list(productos.values())

@app.get("/productos/{producto_id}")
def obtener_producto(producto_id: int):
    if producto_id not in productos:
        raise HTTPException(status_code=404, detail="Producto no encontrado")
    return productos[producto_id]

@app.post("/productos", status_code=201)
def crear_producto(producto: Producto):
    nuevo_id = max(productos, default=0) + 1   # el mayor id actual + 1
    productos[nuevo_id] = {"id": nuevo_id, **producto.model_dump()}
    return productos[nuevo_id]

@app.put("/productos/{producto_id}")
def actualizar_producto(producto_id: int, producto: Producto):
    if producto_id not in productos:
        raise HTTPException(status_code=404, detail="Producto no encontrado")
    productos[producto_id] = {"id": producto_id, **producto.model_dump()}
    return productos[producto_id]

@app.delete("/productos/{producto_id}", status_code=204)
def eliminar_producto(producto_id: int):
    if producto_id not in productos:
        raise HTTPException(status_code=404, detail="Producto no encontrado")
    del productos[producto_id]
```

Algunas aclaraciones sobre el código anterior:

- **`Producto`** es un modelo de Pydantic: describe la forma del JSON que esperamos recibir. Lo analizamos a fondo en 6.3.3; por ahora quédate con que es una clase que dice "esto tiene `nombre`, `precio` y, opcionalmente, `stock`".
- **`status_code=201` en el decorador**: por defecto FastAPI responde con `200`. Si quieres otro código de éxito más específico, lo indicas en el decorador.
- **`HTTPException`**: las excepciones en Python se lanzan con `raise` (como un `throw` en Java o PHP) y FastAPI las convierte en una respuesta HTTP con ese código y un JSON con los detalles.
- **`{"id": nuevo_id, **producto.model_dump()}`**: `model_dump()` convierte el modelo Pydantic en un `dict`, y `**` lo "desempaqueta" dentro del nuevo diccionario. 
- **`max(productos, default=0)`**: recorre las claves del diccionario y devuelve la mayor; si está vacío, devuelve `0` (solo es un truco para generar identificadores mientras no tengamos una base de datos que lo haga por nosotros).

**Puedes probarlo con Postman**. Solo arranca el servidor (`uvicorn main:app --reload`) y prueba esta secuencia:

1. Crear un producto nuevo: `POST http://127.0.0.1:8000/productos` con este cuerpo (*Body → raw → JSON*): `{ "nombre": "Teclado mecánico", "precio": 59.9, "stock": 12 }`
    Recibirás un `201` con el producto y su `id`.
2. Comprobar que el producto existe: `GET /productos` y `GET /productos/1`.
3. Modifica el producto con `PUT /productos/1` y un JSON modificado.
4. Borrar el producto con `DELETE /productos/1` (recibirás `204` sin cuerpo)
5. Comprobar que el producto ya no existe: vueve a pedir `GET /productos/1` para obtener un `404`.

### 6.3.2. Parámetros de entrada

Una petición HTTP, como sabemos, puede traer datos por tres vías: 

1. Dentro de la **ruta**, en forma de **parámetros de ruta o segmentos** (como en la ruta `/products/delete/38`; contiene bastante información en sí misma, ¿no te parece?)
2. En la **cadena de consulta** o **query string** (del estilo `?clave=valor`, como en `/products?action=delete&id=38`).
3. En el **cuerpo** de la propia petición http (en este caso los datos no son visibles en la ruta, que quedaría como `/products`, como si no hubiera datos en absoluto)

FastAPI las distingue a partir de cómo declares los parámetros de tu función. No son necesarias anotaciones especiales en los casos habituales:

| Si el parámetro de la función... | FastAPI lo trata como... 
|---|---
| Aparece entre llaves en la ruta (`{id}`) | Parámetro de ruta (segmento), como en `/products/delete/38`
| Es de tipo simple (`int`, `str`, `bool`...) y no está en la ruta | Cadena de consulta (query string), como en `/products?action=delete&id=38`
| Es un modelo Pydantic | Cuerpo de la petición http (los datos no se ven en la ruta) 

Vamos a ver cómo construir cada una de ellas.

#### A) Parámetros de ruta (path parameters) o segmentos

Estos datos aparecen integrados en la propia URL en forma de segmentos, como en `/productos/delete/38`.

Los datos se representan **entre llaves** en el decorador. El **nombre** entre llaves *debe coincidir con el de un parámetro de la función*, y su **tipo** determina la conversión y la validación:

```python
@app.get("/productos/{producto_id}")
def obtener_producto(producto_id: int):
    ...
```

En este ejemplo:

- `GET /productos/3` → `producto_id` vale `3` (ya convertido a `int`).
- `GET /productos/abc` → FastAPI responde automáticamente un error `422` y no ejecuta la función, porque `abc` no es un entero, sin necesidad de escribir ninguna validación.

**Cuidado con el orden de las rutas.** FastAPI las evalúa en el orden en que las declaras. Si tienes una ruta fija y otra con parámetro que podrían coincidir, la fija debe ir **antes**:

```python
@app.get("/productos/resumen")         # va primero
def resumen(): ...

@app.get("/productos/{producto_id}")   # si fuera primero, "resumen" se interpretaría como un id
def get_product(producto_id: int): ...
```

#### B) Cadenas de consulta (query strings)

Estos datos son los que aparecen tras el `?` en la URL, como en `/productos?action=delete&id=38`

En este caso, los parámetros que vienen por la URL no se indican en el decorador, sino en los parámetros de la función.


Cualquier parámetro de tipo simple que aparezca en la URL y no esté en la ruta del decorador, se considera parte de la query consulta.

```python
@app.get("/productos")
def listar_productos(
    buscar: str | None = None,
    precio_max: float | None = None,
    limite: Annotated[int, Query(ge=1, le=100)] = 10,
):
    ...
```

Aquí estamos diciendo que la ruta es `GET /productos` y que a continuación podría llevar 3 variables en forma de query string:
- `buscar` → un string optativo (si no está en la URL, se le asigna el valor por defecto `None`)
- `precio_max` → un float también optativo (valor por defecto `None`)
- `limite` → un int optativo (valor por defecto `10`). Este, además, tiene más restricciones: tiene que se mayor o igual que 1 y menor o igual que 100.

Así que todas estas rutas son válidas y ejecutarán `listar_productos()`:

```text
GET /productos
GET /productos?buscar=teclado
GET /productos?buscar=teclado&precio_max=50&limite=5
```

En cambio, algo como `GET /productos?limite=500` devolverá un `422`, porque hemos dicho que que `limite` debe estar entre 1 y 100 y esta URL no lo cumple.

Podemos escribir una versión completa (aunque aún con datos en memoria) de la función:

```python
from fastapi import Query

@app.get("/productos")
def listar_productos(
    buscar: str | None = None,
    precio_max: float | None = None,
    limite: Annotated[int, Query(ge=1, le=100)] = 10,
):
    resultado = list(productos.values())
    if buscar:
        resultado = [p for p in resultado if buscar.lower() in p["nombre"].lower()]
    if precio_max is not None:
        resultado = [p for p in resultado if p["precio"] <= precio_max]
    return resultado[:limite]
```

Con esto, todas estas llamadas son válidas:

```text
GET /productos
GET /productos?buscar=teclado
GET /productos?buscar=teclado&precio_max=50&limite=5
```

Y `GET /productos?limite=500` devolverá un `422`, porque has declarado que `limite` debe estar entre 1 y 100. Fíjate en cómo se retoman aquí los type hints y `str | None` de 6.1.2: ahora cada anotación tiene consecuencias reales en el comportamiento de la API.

Los booleanos aceptan varias formas: `?activo=true`, `?activo=1`, `?activo=yes` u `on` se interpretan como verdadero.

#### C) Cuerpo de la petición (request body)

En este caso, en la URL no se ven los datos, sino que van empaquetados en la petición http (puedes verlos analizando el paquete http con las herramientas de desarrollador de tu navegador web o con Postman)

La URL sería algo como `/products`. Parece que no lleva datos, pero sí los lleva, escondidos en el cuerpo de la request.

FastAPI esperará que los datos lleguen de esta manera cuando un parámetro de la función es un **modelo Pydantic**, es decir, una clase que hereda de `BaseModel`. 

Esto solo puede usarse con `POST`, `PUT` y `PATCH` (con `GET` se podría hacer, pero está desaconsejado).

Observa este ejemplo, donde el parámetro de la funció `crear_producto` es un objeto de tipo `Producto`:

```python
@app.post("/productos", status_code=201)
def crear_producto(producto: Producto):
    ...
```

Con ese único parámetro, FastAPI hace por ti todo esto:

1. Lee el cuerpo de la request.
2. Comprueba que contiene los campos requeridos para el objeto de tipo `Producto` y que los tipos son correctos.
3. Te entrega una instancia de `Producto` lista para usar (con todos sus datos en su sitio: `producto.nombre`, `producto.precio`...).
4. Y, si algo falla, responde un error `422` sin llegar a ejecutar la función y sin necesidad de escribir validaciones explícitas.

Por ejemplo, si envías en el cuerpo de una request POST algo como `{"nombre": "Teclado"}` (sin `precio`), recibirás de FastAPI una respuesta parecida a esta:

```json
{
  "detail": [
    {
      "type": "missing",
      "loc": ["body", "precio"],
      "msg": "Field required",
      "input": { "nombre": "Teclado" }
    }
  ]
}
```

Observa que `loc` incluso te indica **dónde** está el problema.

#### Combinar los 3 métodos en la misma función

También se pueden combinar los tres tipos de parámetro (parámetro de ruta, cadena de consulta y cuerpo del request) en una misma función, y FastAPI sabrá distinguir dónde viene cada dato.

Por ejemplo:

```python
@app.put("/productos/{producto_id}")
def actualizar_producto(
    producto_id: int,          # parámetro de ruta (es parte de la ruta indicada en el decorador)
    producto: Producto,        # cuerpo del request (es un modelo Pydantic)
    notificar: bool = False,   # cadena de consulta (es un tipo simple fuera de la ruta)
):
    ...
```

### 6.3.3. Modelado y validación de datos con Pydantic

#### Definir esquemas heredando de BaseModel

Ya hemos visto que un **esquema** (o modelo) en Pydantic es una clase que hereda de `BaseModel` cuyos atributos son los campos del objeto, anotados con su tipo:

```python
from pydantic import BaseModel

class Producto(BaseModel):
    nombre: str                      # obligatorio
    descripcion: str | None = None   # opcional (puede ser None)
    precio: float                    # obligatorio
    stock: int = 0                   # opcional, con valor por defecto
```

Las reglas son muy sencillas:

- **Sin valor por defecto** → el campo es **obligatorio**.
- **Con valor por defecto** → el campo es opcional y toma ese valor si no llega.
- **`tipo | None = None`** → el campo es opcional y además admite `None` (como null) explícito.

Por tanto:

```python
p = Producto(nombre="Ratón", precio=19.9)
print(p.stock)         # 0 (valor por defecto)
print(p.model_dump())  # {'nombre': 'Ratón', 'descripcion': None, 'precio': 19.9, 'stock': 0}
```

#### Validación automática

Pydantic valida el modelo **al crear la instancia**. Y no solo comprueba los tipos, sino que también los **convierte** cuando es seguro hacerlo:

- `{"precio": "19.99"}` → se convierte a `19.99` (un `str` que representa un número es válido para un `float`).
- `{"stock": "5"}` → se convierte al entero `5`.
- `{"stock": "muchos"}` o `{"stock": 3.5}` → esto da un **error** (no se puede convertir a `int` sin perder información).
- Los **campos que no están en el modelo se ignoran**, lo que evita que un cliente te "cuele" datos que no esperabas.

Para **otras restricciones** más finas puede usarse `Field()`, como en este ejemplo:

```python
from pydantic import BaseModel, Field

class Producto(BaseModel):
    nombre: str = Field(min_length=3, max_length=50)
    descripcion: str | None = None
    precio: float = Field(gt=0)
    stock: int = Field(default=0, ge=0)
```

Aquí estamos exigiendo que el nombre tenga entre 3 y 50 caracteres, el precio sea mayor que cero y el stock no puede ser negativo.

#### Esquemas distintos para entrada y salida

Hay un detalle del CRUD de ejemplo anterior que no es del todo correcto: al crear un producto, el cliente **no** debería enviar el `id` (lo genera el servidor), pero en la respuesta **sí** queremos devolverlo. 

Para eso es necesario usar **dos esquemas** ligeramente distintos (uno con `id` y otro sin él). La herencia de clases resuelve el problema sin repetir código:

```python
# Esta clase es lo que se espera recibir al crear un producto
class ProductoCrear(BaseModel):
    nombre: str = Field(min_length=3, max_length=50)
    precio: float = Field(gt=0)
    stock: int = Field(default=0, ge=0)

# Esta clase es lo que se devolverá al crear un producto
# Es idéntica a la anterior, pero añade el id
class ProductoRespuesta(ProductoCrear):
    id: int
```

Ahora solo quedaría **indicarlo en los endpoints**, usando `response_model` para decirle a FastAPI cómo debe ser la respuesta:

```python
@app.post("/productos", status_code=201, response_model=ProductoRespuesta)
def crear_producto(producto: ProductoCrear):
    nuevo_id = max(productos, default=0) + 1
    productos[nuevo_id] = {"id": nuevo_id, **producto.model_dump()}
    return productos[nuevo_id]

@app.get("/productos", response_model=list[ProductoRespuesta])
def listar_productos():
    return list(productos.values())
```

Con `response_model`, FastAPI **filtra y valida lo que devuelves**: si tu función devolviera campos de más (por ejemplo, una contraseña en un modelo de usuario), no saldrían en el JSON. 


### 6.3.4. Documentación automática OpenAPI: Swagger UI y ReDoc

**OpenAPI** es un estándar para **describir** APIs REST en un archivo JSON

La descripción incluye cosas como qué endpoints existen, qué parámetros aceptan, qué cuerpo esperan y qué respuestas devuelven. Antes se conocía como *especificación **Swagger***, y por eso en algunos sitios se sigue llamando así.

**No tienes que escribir ese archivo**. FastAPI lo genera automáticamente leyendo tus rutas, tus *type hints* y tus modelos Pydantic.

Con el servidor en marcha, la documentación se autogenera en tres endpoints:

- `/docs` - Aquí está **Swagger UI**, es decir, un interfaz de usuario donde un humano puede leer la documentación de forma interactiva. ¡E incluso probar la API!
- `/redoc` - Aquí está la misma documentación en un formato más pensado para lectura tradicional.
- `/openapi.json` - Aquí está el "contrato" OpenAPI en bruto, en formato JSON.

