---
layout: page
title: 6.1 Introducción express a Python
permalink: /fastapi/introduccion-python/
nav_order: 1
has_children: true
parent: 6 Microservicios con Python y FastAPI
grand_parent: Desarrollo Web en Entorno Servidor
---

## 6.1. Introducción express a Python
{: .no_toc }

- TOC
{:toc}

[Descargar presentación](https://www.dropbox.com/scl/fi/mch6paq5qqryhl9399yem/06_01_introduccion_python.pdf?rlkey=kwud02goylv3cyhhei0b1b2tw&st=tvk5vvfe&dl=0){: .btn .btn-primary }

Antes de ponernos a levantar endpoints con FastAPI necesitas **entender el lenguaje** en el que está escrito, que no es otro que **Python**. 

La buena noticia es que no partes de cero, porque ya sabes PHP, Java y Javascript, y Python se parece a los tres en lo esencial. Lo que cambia es sobre todo la **forma** de escribir las cosas. Python es el más legible de todos esos lenguajes... ¡o eso dicen los responsables de Python!

Pero que quede claro: **el objetivo de este bloque no es que te hagas experto en Python**, sino que puedas leer y escribir el código necesario para trabajar con FastAPI. Por eso introduciremos Python y FastAPI comparándolo constantemente con lo que ya conoces (PHP/Laravel y Java/Spring Boot).

### 6.1.1. Características y sintaxis básica de Python

Python es un lenguaje:

- **Interpretado**, **multiplataforma** y de **propósito general**.
- Con **tipado fuerte y dinámico**. 
- Obsesionado con la **legibilidad** del código. 
- **Multiparadigma**, porque admite programación imperativa tradicional, orientada a objetos y, hasta cierto punto, funcional.

Su primera versión apareció en 1991, así que es un lenguaje bastante antiguo, pero ha evolucionado muchísimo desde entonces y, desde el año 2010 aproximadamente, está viviendo una segunda juventud gracias a su uso masivo en varios ámbitos:

- El **backend** de aplicaciones web (que es lo que a nosotros nos interesa ahora).
- **Inteligencia Artificial** y *machine learning*.
- **Análisis de datos** (sobre todo en aplicaciones científicas) y, en general, **computación científica** (física, química, biología, astronomía, matemáticas, ingeniería...).
- **Tareas de automatización** y *scripting*.
- **DevOps**: automatización de despliegues, tareas de cloud, administración de infraestructuras...

#### Indentación obligatoria

La diferencia más visible entre Python y los lenguajes que conoces es la **ausencia de llaves (`{` y `}`)**. 

En Java, JavaScript o PHP los bloques se delimitan con llaves `{ }` y la **indentación o sangría** del código es solo una cuestión estética (importante para la lectura, pero el compilador la ignora). 

En Python **la indentación es imprescindible** porque *define qué instrucciones pertenecen a cada bloque*.

Un bloque se abre con dos puntos `:` y todo lo que va indentado debajo forma parte de él:

```python
edad = 19
if edad >= 18:
    print("Mayor de edad")
    print("Puede votar")
else:
    print("Menor de edad")
print("Esto se ejecuta siempre")  # Esto está fuera del if
```

Comparado con Java o PHP:

```java
int edad = 19;                            // edad = 19 en PHP, sin el "int"
if (edad >= 18) {
    System.out.println("Mayor de edad");  // echo "Mayor de edad" en PHP
} else {
    System.out.println("Menor de edad");  // echo "Menor de edad" en PHP
}
System.out.println("Esto se ejecuta siempre");  // Esto está fuera del if
```

- La convención actual (PEP 8) es usar **4 espacios** por nivel. Asegúrate de que tu editor de texto está configurado para que el tabulador inserte 4 espacios.
- **No mezcles tabuladores y espacios** en el mismo archivo. Si lo haces, Python lanzará un `IndentationError` y te costará encontrar el motivo, porque visualmente el código parecerá correcto.

#### Otras peculiaridades de Python

Otros aspectos curiosos de Python que lo distinguen de PHP, Java o Javascript son:

- No hacen falta **paréntesis** en las condiciones.
- Tampoco se usa el **punto y coma** al final de cada línea.
- Los **comentarios** se escriben con `#`.
- Las variables tienen **ámbito de función, no de bloque**. Una variable creada dentro de un `if` o un `for` *sigue existiendo después del bloque*, algo que sorprende a quien viene de Java o del `let` de JavaScript.
- La **documentación de funciones y clases** se suelen hacer con las llamadas *docstrings*, que son cadenas entre `"""triples comillas"""` colocadas justo debajo de la definición o del nombre de la clase:

    ```python
    def area_rectangulo(base, altura):
        """Calcula el área de un rectángulo."""
        return base * altura
    ```

#### Variables y tipado dinámico fuerte

En Python **no se declara el tipo** de una variable ni se usa `var`, `let` o `$`. 

El tipo se estalece a través del **valor** asignado a la variable, así que una misma variable puede cambiar de tipo a lo largo del programa (***tipado dinámico***):

```python
dato = 42          # int
dato = "hola"      # ahora es str (válido, aunque poco recomendable)
precio = 19.99     # float
activo = True      # bool (con mayúscula inicial)
nada = None        # equivalente a null
```

Ojo con un matiz importante: el tipado de Python es ***dinámico pero fuerte***. 
- Es ***dinámico*** porque no declaramos tipos y el tipo de una variable puede cambiar.
- Y es ***fuerte*** porque Python no hace *conversiones implícitas* a escondidas como sí hacen JavaScript o PHP.

    ```python
    a = "5" + 3       # TypeError: can only concatenate str (not "int") to str
    a = "5" + str(3)  # a vale "53" (conversión explícita a string)
    a = int("5") + 3  # a vale 8 (conversión explícita a int)
    ```

En JavaScript, `"5" + 3` daría `"53"` sin quejarse, y en PHP `"5" + 3` daría `8`, también sin quejarse. Java te mandará a freír espárragos si tratas de hacer `"5" + 3`. Python se parece a Java en eso: *prefiere fallar antes que adivinar*.

Otras cosas relacionadas con las variables y las expresiones que conviene que sepas:

- **Nombres**: se prefiere `snake_case` para variables y funciones (`precio_total`), `CamelCase` para clases (`Producto`) y `MAYUSCULAS` para constantes por convención (Python no tiene constantes reales).
- **Operadores lógicos**: se escriben con palabras: `and`, `or`, `not` (nada de `&&`, `||`, `!`).
- **Comparar con `None`**: recuerda que `none` es el equivalente a `null`. Para comparar con `None` no se usa `== None`, sino `is None` / `is not None`.
- **Operadores aritméticos**: `/` siempre devuelve decimal (`7 / 2` es `3.5`). Si quieres división entera, usa el operador `//` (`7 // 2` es `3`). También existe un operador para la potencia: `**`.
- **Veracidad (*truthiness*)**: valores como `0`, `""`, `[]`, `{}` y `None` son equivalentes a `false` en una condición, igual que en JavaScript o PHP.
- **Cadenas con interpolación (f-strings)**: como en PHP, las variables y expresiones pueden meterse dentro de los strings, aunque debes escribir una `f` antes del string usar llaves para que la variable o expresión se evalúe, como en este ejemplo:

    ```python
    nombre = "Ana"
    puntos = 87
    print(f"{nombre} ha sacado {puntos} puntos")    # Ana ha sacado 87 puntos (interpolación de variable)
    print(f"El doble es {puntos * 2}")              # El doble es 174 (interpolación de expresiones)
    ```

#### Funciones en Python

En FastAPI vamos a escribir muchísimas funciones, así que repasemos la sintaxis básica de las funciones en Python, que admiten **valores por defecto** y **paso de argumentos por nombre**:

```python
def saludar(nombre, saludo="Hola"):
    return f"{saludo}, {nombre}!"

saludar("Luis")                      # "Hola, Luis!"
saludar("Luis", saludo="Buenas")     # "Buenas, Luis!"
```

Los **imports** se parecen más a los de JavaScript que a los de Java:

```python
# Importar módulos completos
import pathlib                       # importa el módulo pathlib completo. Dentro tiene una clase llamada Path
ruta = pathlib.Path("archivo.txt")   # llamada al constructor de la clase Path
...
# Importar clases, funciones u objetos sueltos
from pathlib import Path             # importa solo la clase Path del módulo pathlib
ruta = Path("archivo.txt")           # llamada al constructor de la clase Path
```

#### Estructuras de datos nativas

Python trae de serie cuatro **colecciones** que cubren casi todo lo que necesitarás. 

Primero te cuento las equivalencias aproximadas con Java, JS y PHP y luego hablamos un poco de cada tipo de colección:

| Python | Se parece a... | Características |
|---|---|---|
| `list` | `ArrayList` (Java), array de PHP y de JS | Lista ordenada, mutable, admite duplicados |
| `tuple` | Un array "congelado" (sin equivalente directo en Java ni PHP) | Lista ordenada pero **inmutable** |
| `set` | `HashSet` (Java), `Set` (JS), array asociativo de PHP | Colección sin orden y **sin duplicados** |
| `dict` | `HashMap` (Java), array asociativo de PHP | Pares clave-valor |

Las **LISTAS** (`list`) de Python se definen con corchetes y son lo más parecido a los arrays que ya conoces.

```python
frutas = ["manzana", "pera", "uva"]
frutas.append("kiwi")          # añadir al final
print(frutas[0])               # "manzana"
print(frutas[-1])              # "kiwi" (los índices negativos cuentan desde el final)
print(frutas[1:3])             # ["pera", "uva"] (del 1 al 3, sin incluir el 3)
print(len(frutas))             # 4 (longitud del array)
```

Las **TUPLAS** (`tuple`) son como las listas, pero:
- Se crean con paréntesis: `punto = (10, 20)`
- Se desempaquetan automáticamente: `x, y = punto` hace que `x = 10` e `y = 20`
- *Una vez creadas no se pueden modificar*
- Se usan para datos que "van juntos" y no pueden cambiar (P. ej: coordenadas de un mapa). Un sitio donde las vas a encontrar a menudo es en las **funciones que devuelven varios valores**, no solo uno. Ese conjunto de valores siempre es una *tupla inmutable*.

```python
# asignación y desempaquetado de tuplas
punto = (10, 20, 23)   # asignamos una tupla de 3 elementos a la variable punto
x, y, z = punto        # desempaquetado automático de tuplas: x = 10, y = 20, z = 23
# punto[0] = 5           # ****ERROR****, las tuplas son inmutables

# devolución de tuplas desde funciones
def min_y_max(numeros):
    return min(numeros), max(numeros)   # devuelve una tupla de 2 elementos

# La función se invocaría así
menor, mayor = min_y_max([4, 1, 9, 13, -2])
```

Los **CONJUNTOS** (`set`) se asignan con **llaves** `{...}`. Son como arrays, pero sin orden y sin permitir elementos duplicados. Son útiles para comprobar la pertenencia de elementos al conjunto de forma muy eficiente. 

```python
# creamos un conjunto de 3 elementos (el elemento duplicado será ignorado):
etiquetas = {"python", "api", "python", "web"}
print(etiquetas)               # {'python', 'api', 'web'} (sin duplicados, orden no garantizado)
etiquetas.add("rest")          # esto añade un elemento
print("api" in etiquetas)      # True (nos dice si "api" está en el conjunto)

vacio = set()                  # Crea un conjunto vacío. ¡OJO! vacio = {} crea un DICCIONARIO, no un set
```

Los **DICCIONARIOS** (`dict`) también se declaran con llaves `{...}`.
Son como los arrays asociativos de PHP, así que en un diccionario cabe prácticamente de todo. Es una estructura tremendamente útil para el desarrollo web, porque **un JSON se convierte en un `dict` sin esfuerzo** y viceversa.

```python
# creamos un diccionario en la variable usuario
usuario = {
    "nombre": "Ana",
    "edad": 21,
    "roles": ["alumna", "delegada"]
}

print(usuario["nombre"])                  # "Ana"
print(usuario.get("email", "sin email"))  # "sin email" (así get no falla si la clave no existe)
# print(usuario["email"])                 # KeyError (así get sí falla si la clave no existe)

usuario["email"] = "ana@ejemplo.com"      # añadir o modificar
for clave, valor in usuario.items():      # recorrer pares clave-valor
    print(clave, valor)
```

#### Recorrer colecciones

Para **recorrer** colecciones se usa `for ... in`, parecido al `foreach` de PHP, y para transformarlas de forma compacta (sin escribir el bucle) existen las **comprensiones**, equivalentes a los`map` y `filter` de Java/JavaScript/PHP.

Por ejemplo:

```python
frutas = ["pera", "manzana", "sandía", "naranja"]
# recorrido tipo foreach (indice + valor, sin contador manual)
for indice, fruta in enumerate(frutas):
    print(indice, fruta)

numeros = [1, 2, 3, 4, 5, 6]
# recorrido compacto con una comprensión 
pares_al_cuadrado = [n ** 2 for n in numeros if n % 2 == 0]
print(pares_al_cuadrado)       # Imprime [4, 16, 36]
```

---

### 6.1.2. Tipado de datos explícito (type hints)

#### Qué es (y qué no es) el tipado explícito en Python

Ya sabemos que Python tiene tipado fuerte y dinámico, pero desde Python 3.5 se pueden añadir **anotaciones de tipo** (*type hints*) para indicar qué tipo esperamos en variables, parámetros y valores de retorno. Es decir, exactamente igual que en PHP 8.

```python
def calcular_total(precio: float, unidades: int) -> float:
    return precio * unidades

nombre: str = "Ana"
```

Es importante tener claro que **Python no valida los type hints en tiempo de ejecución**. *Solo son anotaciones que ayudan al editor (autocompletado, avisos) y a quien lea el código*. Pero, si te saltas los tipos, el código tratará de ejecutarse igualmente:

```python
# Python lo intenta ejecutar (y fallará dentro de la función o no, dependerá de lo que ocurra en ella)
calcular_total("hola", "adiós")
```

**FastAPI sí lee las anotaciones de tipos en tiempo de ejecución** (apoyándose en una librería llamada *Pydantic*, de la que ya hablaremos) para validar automáticamente los datos que llegan en las peticiones, convertirlos al tipo correcto y generar la documentación interactiva de la API. 

Así que, si declaras `id: int` y te llega `"abc"` en la URL, FastAPI responderá con un error 422 sin necesidad de que escribas ni una sola línea de validación. Es el equivalente a lo que en Laravel hacen las reglas de `validate()` o en Spring Boot con las anotaciones `@Valid`, pero FastAPI lo hace automáticamente sin más que declarar los tipos.

#### Tipos básicos y colecciones

Los tipos simples se escriben tal cual (`str`, `int`, `float`, `bool`). Para las colecciones, desde Python 3.9 se pueden especificar así:

```python
# lista
nombres: list[str] = ["Ana", "Luis"]
# tupla
coordenada: tuple[float, float] = (36.84, -2.46)
# conjunto
ids: set[int] = {1, 2, 3}
# diccionario
notas: dict[str, float] = {"Ana": 8.5, "Luis": 7.0}
```

¡OJO! En documentación y código más antiguo que Python 3.9 puedes encotrarte `List`, `Dict`, `Set` y `Tuple` con mayúscula, importados desde el módulo `typing`:

```python
from typing import List, Dict

nombres: List[str] = ["Ana", "Luis"]       # equivale a list[str]
notas: Dict[str, float] = {"Ana": 8.5}     # equivale a dict[str, float]
```

Ambas formas funcionan (de momento) y las encontrarás en tutoriales de FastAPI. En código nuevo, sin embargo, se recomienda la forma moderna (`list[str]`, con minúscula).

#### Parámetros opcionales y uniones

Cuando un valor puede ser de un tipo o `None`, se usa `Optional`:

```python
# esta función puede devolver un string o un None
def buscar_usuario(id: int) -> str | None:
    usuarios = {1: "Ana", 2: "Luis"}
    return usuarios.get(id)          # devuelve str o None
```

En versiones más antiguas de Python (inferiores a Python 3.9) hay que usar `Optional`:

```python
from typing import Optional
# esta función puede devolver un string o un None (forma antigua, anterior a Python 3.9)
def buscar_usuario(id: int) -> Optional[str]:
    ...resto igual...
```

Un detalle que suele confundir: **`Optional` no significa "parámetro opcional u optativo"**. El parámetro es obligatorio, solo que puede valer `None`. **Para que un parámetro sea realmente optativo** hay que *darle un valor por defecto*:

```python
# texto es un parámetro opcional, no porque pueda ser None, 
# sino porque tiene un valor por defecto (que también es None)
def filtrar(texto: str | None = None, limite: int = 10):
    ...

# esto es lo mismo pero de la forma antigua (anterior a Python 3.9)
def filtrar(texto: Optional[str] = None, limite: int = 10):
    ...
```

También puede declararse una variable con varios posibles tipos aceptables. Por ejemplo:

```python
# el parámetro valor puede ser int o string
def buscar(valor: int|str) -> str|None:
    ...
# esto es lo mismo, pero de forma antigua (anterior a Python 3.9)
def buscar(valor: Union[int, str]) -> Optional[str]:
    ...
```

Todo esto lo veremos constantemente en FastAPI para los *query params* opcionales.

#### Equivalencias de tipos con Java, Typescript y PHP

| Python | Java | TypeScript | PHP |
|---|---|---|---|
| `str` | `String` | `string` | `string` |
| `int` | `int` / `Integer` | `number` | `int` |
| `float` | `double` / `Double` | `number` | `float` |
| `bool` | `boolean` | `boolean` | `bool` |
| `list[str]` | `List<String>` | `string[]` | `array` (sin tipar el contenido) |
| `dict[str, int]` | `Map<String, Integer>` | `Record<string, number>` | `array` asociativo |
| `set[int]` | `Set<Integer>` | `Set<number>` | (sin equivalente nativo, se puede usar array asociativo) |
| `tuple[int, str]` | (sin equivalente directo) | `[number, string]` | (sin equivalente directo) |
| `Optional[str]` o `str \| None` | `Optional<String>` | `string \| null` | `?string` |
| `int \| str` | (sin equivalente) | `number \| string` | `int\|string` |
| `Any` | `Object` | `any` | `mixed` |
| `None` (retorno) | `void` | `void` | `void` |


#### Un adelanto de lo que viene

Para que entiendas por qué nos detenemos tanto en todo esto, mira lo que hace FastAPI para validar datos de una Request:

```python
from pydantic import BaseModel

# La clase Producto hereda de la clase BaseModel
class Producto(BaseModel):
    nombre: str
    precio: float
    stock: int | None = None    # opcional, por defecto None
```

Esta sencilla clase le dice a FastAPI qué forma tiene el JSON que debe recibir, qué tipos debe tener cada campo y cuáles son opcionales. *Es el equivalente a validar un `FormRequest` de Laravel pero mucho más compacto*. 

(Trabajaremos esto a fondo cuando construyamos nuestros primeros endpoints).

---

### 6.1.3. Entornos virtuales y dependencias en Python

#### Por qué necesitamos entornos virtuales

Las librerías y dependencias de Python se suelen gestionar con `pip`, que es como `composer` para PHP.

Cuando instalas una librería en Python con `pip`, por defecto se instala **de forma global** en el sistema. **ESTO ES UNA RECETA SEGURA PARA EL DESASTRE**.

El ecosistema de Python es tan grande (y un poco caótico, la verdad) que es frecuente que uno de tus proyectos necesite la versión 1 de una librería, otro la versión 2 y otro la versión 1.5. Al final nada funciona y acabas con tu instalación global de Python hecha unos zorros porque tienes *montones de librerías incompatibles entre sí*.

La solución a este caos es el **entorno virtual**. Se trata de una carpeta aislada con su propio intérprete de Python y sus propias librerías, de modo que **cada proyecto "vive en su propia burbuja"**.

(Esta idea no es única de Python, por cierto. Otros lenguajes resuelven este problema de otros modos parecidos. Por ejemplo, el `Composer` de PHP instala las dependencias en la carpeta `vendor/` del proyecto concreto, no en una carpeta global del sistema).

#### Crear y activar un entorno virtual con venv

Para crear y activar un entorno virtual para tu proyecto, abre un terminal en la carpeta raíz del proyecto y teclea:

```bash
# Crear el entorno (se llama .venv por convención)
$ python -m venv .venv
```

> *En Linux y macOS el comando puede ser `python3` y en Windows `python` o `py`. En algunas distribuciones basadas en Debian/Ubuntu puede que antes tengas que instalar el paquete `python3-venv`*.

Ahora hay que **activar el entorno**. Mientras esté activo, cualquier `python` o `pip` que ejecutes *usará el entorno virtual y no la configuración global del sistema*:

```bash
# Linux / macOS
$ source .venv/bin/activate

# Windows (PowerShell)
$ .venv\Scripts\Activate.ps1

# Windows (cmd)
$ .venv\Scripts\activate.bat
```

Sabrás qué entorno está activo porque el prompt de la terminal mostrará `(.venv)` al principio. 

Para **salir del entorno virtual** y regresar al entorno global de Python, solo escribe:

```bash
(.venv)$ deactivate
```

Dos recomendaciones adicionales: 

* Añade `.venv/` al `.gitignore` (el entorno **no se sube** al repositorio, igual que `vendor/` o `node_modules/`)
* Si usas VS Code o PyCharm, selecciona el intérprete del `.venv` para que el editor reconozca las librerías instaladas en tu entorno virtual; si no, tu IDE podría intentar usar el entorno global.

#### Instalar dependencias con pip

Con el entorno virtual activado, `pip` instalará los paquetes que necesites desde **PyPI** (el repositorio oficial de Python).

Aquí tienes un resumen de los comandos que habitualmente usarás con `pip`:

```bash
$ pip install fastapi                 # instalar un paquete (FastAPI)
$ pip list                            # ver qué cosas se han instalado con pip
$ pip show fastapi                    # ver detalles de un paquete concreto
$ pip uninstall fastapi               # desinstalar un paquete
```

#### El archivo requirements.txt

Para que otra persona (o vosotros en otro ordenador, o en un contenedor Docker) pueda reproducir el entorno virtual, necesitamos una **lista de las dependencias** que hemos instalado. 

Esa lista se guarda en un archivo llamado `requirements.txt`, que tiene un formato sencillísimo: solo es texto plano con un paquete (y su versión) por línea. Por ejemplo:

```text
fastapi==0.115.0
uvicorn[standard]==0.30.6
pydantic==2.9.2
```

Puedes generar el archivo `requirements.txt` a mano, claro, pero es más cómodo generarlo con este comando:

```bash
# Vuelca TODO lo instalado en el entorno, con versiones exactas
$ pip freeze > requirements.txt
```

*(`pip freeze` es rápido pero incluye también las dependencias de las dependencias, así que el archivo puede quedar algo largo y confuso)*

Para reconstruir el entorno en otra máquina, el flujo sería este:

```bash
$ git clone <repositorio>          # o conseguir el código fuente de algún otro modo
$ cd proyecto
$ python -m venv .venv
$ source .venv/bin/activate        # o la variante de Windows
$ pip install -r requirements.txt  # instalamos todas las dependencias
```

**¡¡OJO!! `pip` no actualiza `requirements.txt` automáticamente** cuando instalas algo. A diferencia de `composer require` o `npm install paquete`, que modifican `composer.json` o `package.json` por ti, con pip tienes que acordarte de regenerar o editar el archivo. (Fallo clásico: "en mi máquina funciona" porque instalaste una librería y olvidaste anotarla en `requirements.txt`)

#### Comparativa con composer.json y pom.xml

| Concepto | Python (pip) | PHP (Composer) | Java (Maven) | JavaScript (npm) |
|---|---|---|---|---|
| Archivo de dependencias | `requirements.txt` | `composer.json` | `pom.xml` | `package.json` |
| Versiones exactas fijadas | `requirements.txt` con `==` (o `pip freeze`) | `composer.lock` | versiones explícitas en `pom.xml` | `package-lock.json` |
| Dónde se instalan | `.venv/` (entorno virtual) | `vendor/` | `~/.m2` (repositorio local) | `node_modules/` |
| Instalar todo | `pip install -r requirements.txt` | `composer install` | `mvn install` | `npm install` |
| Añadir una librería | `pip install paquete` | `composer require paquete` | añadir `<dependency>` al `pom.xml` | `npm install paquete` |
| Repositorio de paquetes | PyPI | Packagist | Maven Central | npm registry |

> **Nota**: existen herramientas más modernas que unifican todo esto, como `Poetry` o `uv`, con un archivo `pyproject.toml` que sería el equivalente más fiel a `composer.json`. Para este curso nos quedamos con `venv` + `pip` + `requirements.txt`, que es lo básico y lo que más a menudo encontrarás en tutoriales y documentación de FastAPI.
