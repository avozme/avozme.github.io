---
layout: page
title: 8 Despliegue y DevOps
permalink: /despliegue-devops/
nav_order: 8
has_children: true
parent: Desarrollo Web en Entorno Servidor
---
# 8. Despliegue y DevOps
{: .no_toc }

- TOC
{:toc}

[Descargar presentación](https://www.dropbox.com/scl/fi/rphp9qa25tuuaczwafbez/08_despliegue_y_devops.pdf?rlkey=1vq4lag5vxhqb6kt6ennoj4ga&st=me6u2drj&dl=0){: .btn .btn-primary }


Esta unidad cierra el módulo y se apoya en todo lo que hemos ido construyendo a lo largo del curso: Git, GitHub y Docker (UD 1), servicios con Laravel y Spring Boot (UD 3, 4 y 5), microservicios con FastAPI (UD 6) y construcción de frontends (UD 7).

Para rematar nuestra formación como desarrolladores web, vamos a **poner en producción** el **sistema de reservas** que desarrollamos en la UD 6, añadiéndole un **pipeline automático** y **desplegándolo en un VPS** real.

---

## 8.1. Integración y despliegue continuo (CI/CD): GitHub Actions

Hasta ahora hemos desarrollado y probado todo en local. Eso es lo habitual, por comodidad, cuando se desarrolla una aplicación.

En esta unidad vamos a ver cómo **poner la aplicación en producción** y cómo ese proceso se puede **automatizar** de forma segura.

### 8.1.1. El concepto de DevOps

**DevOps** no es una herramienta sino una *cultura* y un *conjunto de prácticas* que buscan acortar el ciclo entre que escribes código y que ese código está funcionando en producción, con la mayor calidad y seguridad posible. 

DevOps se basa en tres pilares:

- **Integración continua (CI, *Continuous Integration*):** cada vez que alguien hace push al repositorio, se ejecutan automáticamente los tests y las comprobaciones de calidad. Si algo falla, lo sabemos de inmediato, antes de que el código contamine la rama principal.

- **Entrega continua (CD, *Continuous Delivery*):** además de los tests, el pipeline prepara automáticamente un artefacto desplegable (una imagen Docker, un paquete, etc.) listo para ser publicado en producción. El despliegue final lo puede activar un humano o automatizarse.

- **Despliegue continuo (*Continuous Deployment*):** el despliegue también es automático si todos los pasos del pipeline se superan con éxito. No hace falta ninguna intervención humana.

El **pipeline**, por tanto, es el centro de todo el despliegue. Es una especie de "cadena de montaje" para el código, en la que el código nuevo va pasando por diversos puntos de control: se comprueba por separado, se añade al resto de la aplicación, se hace un test de integración, etc. Si pasa todos los puntos de control, el código se envía a producción y se integra con la aplicación que ya está funcionando. *Y todo esto se describe en el pipeline*.

**El pipeline se detalla en un archivo YAML** en el propio repositorio, versionado como cualquier otro archivo fuente (*pipeline as code*). Cualquier desarrollador puede leerlo, modificarlo y entender exactamente qué ocurre cuando hace push.

### 8.1.2. GitHub Actions: anatomía de un pipeline

**GitHub Actions es el sistema de CI/CD integrado en GitHub**. Su configuración se guarda en archivos YAML dentro del directorio `.github/workflows/` del repositorio.

Vamos a usar GitHub Actions para ver cómo construir un pipeline. Antes, tienes que comprender algunos conceptos básicos:

- **Workflow**: El archivo YAML que define la automatización completa (es decir, el *pipeline*)
- **Evento (trigger)**: Algo que activa el workflow: hacer un `push`, recibit un `pull_request`, un evento de tipo `schedule` (planificado), etc.
- **Job**: Un conjunto de pasos (*steps*) que se ejecutan en la misma máquina virtual
- **Step**: Una tarea individual dentro de un *job*: por ejemplo, ejecutar un comando o usar una action reutilizable.
- **Runner**: La máquina virtual donde se ejecuta el job (ej: `ubuntu-latest`)

Para ver cómo funciona, **vamos a ver un ejemplo de pipeline completo** para un microservicio FastAPI. 

La idea es que cuando alguien haga push a `main`, se active el pipeline: 

1. Primero se comprueba la calidad del código con el `ruff`, que es una herramienta que analiza el código Python automáticamente para detectar errores potenciales y problemas de estilo. Este análisis automático se denomina ***linting***.
2. Después ejecuta los tests con `pytest`, que es el equivalente en Python de PHPUnit para PHP o JUnit para Java. 
3. Si pasa los tests, se construye la imagen Docker.
4. La imagen se publica en el *GitHub Container Registry*, un servicio de GitHub que permite almacenar, gestionar y distribuir imágenes de contenedores, como las imágenes Docker. 
5. Finalmente, se conecta al servidor de producción por SSH y se levanta la nueva versión.

Todos estos pasos están detallados en el **archivo YAML** que describe el Workflow. Léelo con atención:

```yaml
# .github/workflows/ci-fastapi.yml
name: CI/CD - Microservicio de Reservas

on:
  push:
    branches: [main]
  pull_request:
    branches: [main]

jobs:
  # ETAPA 1: Calidad y tests (ruff + pytest)
  quality:
    name: Linting y tests
    runs-on: ubuntu-latest
    steps:
      - uses: actions/checkout@v4

      - name: Configurar Python 3.12
        uses: actions/setup-python@v5
        with:
          python-version: "3.12"
          cache: "pip"

      - name: Instalar dependencias
        run: pip install -r requirements.txt

      - name: Linting con ruff
        run: ruff check .

      - name: Tests con pytest
        run: pytest --tb=short -q
        env:
          DATABASE_URL: sqlite:///./test.db

  # ETAPA 2: Construir y publicar imagen Docker (solo en push a main)
  build-and-push:
    name: Construir y publicar imagen
    needs: quality
    runs-on: ubuntu-latest
    if: github.event_name == 'push' && github.ref == 'refs/heads/main'
    permissions:
      contents: read
      packages: write
    steps:
      - uses: actions/checkout@v4

      - name: Login en GitHub Container Registry
        uses: docker/login-action@v3
        with:
          registry: ghcr.io
          username: ${{ github.actor }}
          password: ${{ secrets.GITHUB_TOKEN }}

      - name: Construir y publicar
        uses: docker/build-push-action@v5
        with:
          context: ./reservas-api
          push: true
          tags: |
            ghcr.io/${{ github.repository }}/reservas-api:latest
            ghcr.io/${{ github.repository }}/reservas-api:sha-${{ github.sha }}

  # ETAPA 3: Desplegar en el servidor de producción
  deploy:
    name: Desplegar en producción
    needs: build-and-push
    runs-on: ubuntu-latest
    steps:
      - name: Desplegar en el VPS por SSH
        uses: appleboy/ssh-action@v1
        with:
          host: ${{ secrets.VPS_HOST }}
          username: ${{ secrets.VPS_USER }}
          key: ${{ secrets.VPS_SSH_KEY }}
          script: |
            cd /opt/sistema-reservas
            docker compose pull reservas-api
            docker compose up -d --no-deps reservas-api
```

Hay dos aspectos del pipeline que merecen un comentario:

**Variables y secrets.** Las variables de entorno normales se declaran en `env:`. Los datos sensibles (tokens, contraseñas de servidor, claves SSH) se almacenan en los llamados **Secrets** del repositorio de GitHub (puedes acceder a ellos en la ruta *Settings → Secrets and variables → Actions*) y se referencian como `${{ secrets.MI_SECRET }}`. ¡Nunca los escribas directamente en el YAML o los dejarás a la vista de todo el mundo!

**Tests automáticos.** Una CI sin tests es como un semáforo siempre en verde: da sensación de seguridad pero no comprueba nada. Para FastAPI, la forma estándar es usar `pytest` con el `TestClient` que viene con FastAPI, aunque, por supuesto, puedes añadirle tus propios tests. El `dependency_overrides` te permite inyectar una base de datos de prueba (SQLite en memoria, en este ejemplo) sin tocar el código de producción:

```python
# tests/test_reservas.py
from fastapi.testclient import TestClient
from app.main import app
from app.database import get_db
from sqlalchemy import create_engine
from sqlalchemy.orm import sessionmaker

engine_test = create_engine("sqlite:///./test.db", connect_args={"check_same_thread": False})
TestingSessionLocal = sessionmaker(bind=engine_test)

def override_get_db():
    db = TestingSessionLocal()
    try:
        yield db
    finally:
        db.close()

app.dependency_overrides[get_db] = override_get_db
client = TestClient(app)

def test_reserva_solapada_devuelve_409():
    # Primero creamos una reserva
    client.post("/reservas/", json={"recurso_id": 1, "inicio": "2026-11-15T10:00", "fin": "2026-11-15T11:00"})
    # Luego intentamos otra que se solapa: debe fallar
    response = client.post("/reservas/", json={"recurso_id": 1, "inicio": "2026-11-15T10:30", "fin": "2026-11-15T11:30"})
    assert response.status_code == 409
```

**Protección de la rama main.** Una vez que tienes el pipeline, puedes ir a *Settings → Branches → Add rule* en GitHub y marcar *"Require status checks to pass before merging"*. Así nadie puede hacer merge a `main` si los checks fallan.

---

## 8.2. Despliegue en producción: Docker en un VPS de OpenStack

Tener el pipeline funcionando es una gran cosa, pero necesitamos un **servidor real** donde aterrice nuestra aplicación. 

En este bloque veremos cómo preparar un VPS en OpenStack y cómo desplegar nuestros contenedores de forma correcta.

### 8.2.1. Preparar el servidor en OpenStack

Si has seguido los pasos del **Apéndice 1**, ya sabes cómo crear una instancia en OpenStack y conectarte por SSH. Solo recuerda los puntos imprescindibles:

1. Crear la instancia (Ubuntu 22.04 o 24.04, con al menos 1 vCPU y 2 GB de RAM).
2. Asignar una **IP flotante** para poder acceder desde el exterior.
3. Abrir en el **Grupo de Seguridad** los puertos 22 (SSH), 80 (HTTP) y 443 (HTTPS). *Los puertos de las bases de datos (3306, 5432) **no deben abrirse** al exterior*.

Una vez dentro del servidor, instala Docker:

```bash
$ sudo apt update && sudo apt install -y docker.io docker-compose-plugin git
$ sudo usermod -aG docker ubuntu   # para no tener que poner sudo en cada comando docker
# Cierra sesión y vuelve a entrar para que el grupo surta efecto
```

### 8.2.2. Docker en producción vs. en desarrollo

El `docker-compose.yml` que usas en local sirve para desarrollar, pero **no es adecuado para producción**. 

Hay algunas **diferencias importantes**:

| | En desarrollo... | En producción... |
|---|---|---|
| `--reload` en `docker-compose up` | A menudo (detecta cambios en vivo) | Nunca (consume recursos innecesariamente) |
| Puertos de BD publicados | A veces (para usar DBeaver, MySQL Workbench, etc) | **¡Ni se te ocurra!** (la BD no debe ser accesible desde fuera) |
| Código montado como volumen | Sí (para editar en caliente) | No (el código va dentro de la imagen) |
| `restart: unless-stopped` | No es necesario | **Muy recomendable** (así la app se reinicia sola si cae o si se reinicia el servidor) |

Así que, con estos cambios, un `docker-compose.yml` de producción típico para FastAPI + PostgreSQL que el pipeline descargaría y levantaría quedaría así:

```yaml
# docker-compose.yml (en el servidor de producción)
services:
  reservas-api:
    image: ghcr.io/tu-usuario/reservas-api:latest
    restart: unless-stopped
    environment:
      DATABASE_URL: postgresql://reservas:${DB_PASSWORD}@db:5432/reservas
      SECRET_KEY: ${SECRET_KEY}
    depends_on:
      db:
        condition: service_healthy

  db:
    image: postgres:16-alpine
    restart: unless-stopped
    environment:
      POSTGRES_DB: reservas
      POSTGRES_USER: reservas
      POSTGRES_PASSWORD: ${DB_PASSWORD}
    volumes:
      - postgres_data:/var/lib/postgresql/data
    healthcheck:
      test: ["CMD-SHELL", "pg_isready -U reservas"]
      interval: 10s
      retries: 5
    # No publicamos el puerto 5432: la BD solo es accesible internamente

volumes:
  postgres_data:
```

Las variables sensibles (`DB_PASSWORD`, `SECRET_KEY`) van en un archivo `.env` en el propio servidor, en la misma carpeta que Compose, y **nunca estarán disponibles en el repositorio**:

```bash
# /opt/sistema-reservas/.env
DB_PASSWORD=una-contraseña-larga-y-aleatoria
SECRET_KEY=otra-clave-aleatoria-para-jwt
```

### 8.2.3. Reverse proxy con Nginx o Caddy

**Otra cosa que se hace en producción** y no en desarrollo es **no exponer directamente los puertos de los contenedores** al exterior. 

En su lugar, se coloca lo que se llama un **reverse proxy**. Se trata de un servicio de proxy que escucha en los puertos 80 y 443, redirige el HTTP al HTTPS y reenvía las peticiones al contenedor correcto según el dominio o la ruta.

Esto nos soluciona además el problema del HTTPS: los certificados TLS los gestiona el reverse proxy y los contenedores internos pueden seguir hablando HTTP sin cifrar entre sí (dentro de la red de Docker, que está en el propio servidor, así que no es peligroso).

**Caddy** es la opción más sencilla para empezar porque gestiona los certificados TLS de Let's Encrypt **de forma completamente automática**. Su configuración es mínima:

```
# Caddyfile
reservas.midominio.com {
    reverse_proxy reservas-api:8000
}

app.midominio.com {
    reverse_proxy frontend:80
}
```

Con esto, Caddy obtiene y renueva el certificado HTTPS sin que tengas que tocar nada. Solo necesitas que el dominio apunte a la IP flotante de tu servidor.

Si utilizas el servidor **Nginx** tienes más control pero la configuración de los certificados es manual (usando *Certbot*) :

```nginx
server {
    listen 80;
    server_name reservas.midominio.com;
    return 301 https://$server_name$request_uri;  # Redirige todo a HTTPS
}

server {
    listen 443 ssl;
    server_name reservas.midominio.com;
    ssl_certificate /etc/letsencrypt/live/reservas.midominio.com/fullchain.pem;
    ssl_certificate_key /etc/letsencrypt/live/reservas.midominio.com/privkey.pem;

    location / {
        proxy_pass http://reservas-api:8000;
        proxy_set_header Host $host;
        proxy_set_header X-Real-IP $remote_addr;
    }
}
```

Recuerda también **actualizar la configuración de CORS** para que tus servicios acepten peticiones de los dominios de producción, no de `localhost:5173`.

### 8.2.4. Ciclo completo de CI/CD

Con todo lo que hemos visto, podemos resumir el flujo completo de un cambio desde que el código se modifica hasta que se publica en producción:

```
1. El desarrollador hace push a main
        |
        v
2. GitHub Actions dispara el pipeline automáticamente
        |
        v
3. Se ejecutan linter + tests (si algo falla, el pipeline se detiene aquí)
        |
        v
4. Se construye la imagen Docker y se publica en GitHub Container Registry con la etiqueta sha-<commit>
        |
        v
5. El pipeline se conecta por SSH al VPS
        |
        v
6. Se lanza docker compose pull && docker compose up -d
        |
        v
7. La nueva versión se pone en producción en cuestión de minutos
```

Si algo va mal en cualquier paso, el pipeline se detiene y la versión anterior al cambio sigue en producción. Los usuarios no se enteran de nada.

La etiqueta con el SHA del commit te permite hacer **rollback** con facilidad: si un commit da problemas, basta con que cambies la etiqueta en el `docker-compose.yml` al commit anterior y vuelvas a ejecutar `docker compose up -d`.

---

## 8.3. Práctica final

La práctica final del módulo consiste en desplegar una aplicación web de corte realista que integre todo lo aprendido a lo largo del curso.

#### Uso de la IA en la práctica

Como en ocasiones anteriores, puedes y debes ayudarte de la Inteligencia Artificial para resolver esta práctica, pero siempre entendiendo lo que estás haciendo.

Pide ayuda a la IA para tareas concretas, no le pases el texto completo de la práctica para que vomite una solución incomprensible y posiblemente incorrecta.

Recuerda que tendrás que pasarnos tu conversación completa con la IA y demostrar que entiendes todo lo que has hecho y has entregado.

#### Objetivo

Partiendo del sistema de reservas desarrollado en las unidades anteriores, deberás entregarlo funcionando en un VPS de OpenStack con las siguientes características:

La aplicación tendrá estos componentes (que ya tenemos hechos):

- **API de reservas** (FastAPI): gestión de reservas, recursos y usuarios. Base de datos PostgreSQL.
- **Frontend** (Vue.js): interfaz de usuario que consume la API.

#### Especificación de requisitos

- Todos los servicios desplegados con Docker Compose en el VPS de OpenStack.
- Reverse proxy (Caddy o Nginx) gestionando el acceso desde el exterior.
- Puertos de base de datos no expuestos al exterior.
- Variables de entorno y secretos correctamente gestionados (archivo `.env` en el servidor, nunca en el repositorio).
- Pipeline de GitHub Actions con al menos dos etapas: tests y despliegue.
- Tests automáticos (mínimo 3 tests relevantes) con pytest.
- La rama `main` protegida: no se puede hacer merge si los checks fallan.
- Badge de estado del pipeline en el README.

#### Entrega

Tienes que subir a Moodle Centros antes de la fecha tope:

1. IP pública del sistema funcionando (accesible desde cualquier navegador en la red del Departamento de Informática).
2. URL del repositorio en GitHub (con el pipeline visible en la pestaña Actions).
3. Breve memoria en PDF (1-2 páginas) describiendo las decisiones de arquitectura que has tomado, los problemas que has encontrado y cómo los has resuelto.
4. Transcripción de la conversación completa con la IA en formato PDF, Word, Libreoffice Writer o txt.
5. Un breve vídeo **narrado con tu propia voz** (nada de síntesis de voz) en el que muestres y expliques, mostrando capturas de pantalla, todo el proceso desde que se hace un cambio en el código fuente hasta que este está publicado en producción.

#### Rúbrica de calificación

Como en otras ocasiones, se utilizará esta escala para calificar cada ítem de la rúbrica:

- 0 = Sin hacer o sin evidencia de esfuerzo: No presenta la tarea, está completamente en blanco o lo entregado no guarda relación con lo solicitado.
- 1 = Hecho pero con errores o carencias importantes: Incompleto, presenta fallos graves de funcionamiento, falta de partes fundamentales o demuestra una falta de comprensión básica.
- 2 = Hecho pero mejorable: Funciona o cumple con el cometido principal, pero presenta pequeños fallos, faltan detalles secundarios, faltan buenas prácticas o la documentación/explicación es mejorable.
- 3 = Excelente: Cumple de forma rigurosa y profesional con todas las especificaciones, aplicando buenas prácticas del sector, optimización y demostrando dominio completo en la explicación.

| Ítem Evaluables | Peso (%) | 0 - Sin Evidencia | 1 - Insuficiente | 2 - Notable | 3 - Excelente |
| :--- | :---: | :--- | :--- | :--- | :--- |
| **0. Uso ético de IA** | **eliminatorio** (necesario para superar la práctica) | Uso de IA no declarado o evidencias de código generado sin comprender. | Registro de IA ausente o incompleto; uso de IA sin actitud crítica ni filtrado de respuestas. | Registro de interacción con IA adjuntado, pero con poca reflexión sobre las correcciones hechas al código generado. | Registro completo del uso de IA (prompts y respuestas), justificando las decisiones de aceptación o rechazo del código generado. |
| **1. Arquitectura y despliegue en VPS (Docker Compose)** | **20%** | No hay despliegue en VPS ni configuración de Docker Compose. | El despliegue falla o no utiliza Docker Compose de forma adecuada; contenedores inestables o mal enlazados. | Contenedores operativos en el VPS pero con configuraciones mejorables (ej. persistencia de datos deficiente, puertos expuestos innecesariamente). | Arquitectura multinivel en Docker Compose óptima, con volúmenes persistentes, redes aisladas y despliegue estable en el VPS. |
| **2. Reverse proxy y configuración HTTPS/CORS** | **15%** | No hay Reverse Proxy ni configuración SSL/CORS. | Proxy mal configurado, certificados SSL con errores de confianza o políticas CORS demasiado permisivas (`*` en producción). | HTTPS funcional y Reverse Proxy operativo, pero con detalles mejorables en la cabecera de seguridad o ajuste fino de CORS. | Reverse Proxy (Nginx/Traefik/Caddy) perfectamente configurado, SSL automático (Let's Encrypt), HTTP/2 y CORS restringido correctamente. |
| **3. Gestión de secretos y variables de entorno** | **15%** | Credenciales y claves subidas directamente al repositorio público/privado. | Archivos `.env` subidos al repositorio o claves hardcodeadas en el código fuente. | Uso de `.env` y variables de entorno, pero faltan `.env.example` bien explicados o la inyección en CI/CD es mejorable. | Separación total de entorno y código. Uso estricto de GitHub Secrets y archivos `.env` excluidos mediante `.gitignore`. |
| **4. Pipeline de CI/CD en GitHub Actions** | **20%** | No existe pipeline automatizado. | El workflow de GitHub Actions falla con frecuencia o solo ejecuta pasos triviales sin desplegar. | Workflow funcional que pasa tests y despliega, pero carece de optimización (sin cacheo, pasos redundantes o faltan alertas). | Pipeline de CI/CD completo, automatizado y robusto: build, test y despliegue automático en VPS tras merge exitoso. |
| **5. Tests automáticos y protección de rama (`main`)** | **10%** | Sin pruebas unitarias/integración y rama `main` sin restricciones. | Tests insuficientes o fallidos que no bloquean la integración; rama `main` sin reglas de protección. | Tests funcionales que se ejecutan en la CI, pero la protección de rama permite saltarse revisiones o comprobaciones. | Suite de tests ejecutable en la CI con cobertura adecuada. Rama `main` protegida requiriendo que la CI pase antes del merge. |
| **6. Memoria técnica y documentación** | **10%** | Sin memoria ni documentación de la arquitectura o decisiones. | Documentación incompleta, carente de diagramas o sin justificar las decisiones tecnológicas tomadas. | Memoria clara con instrucciones de despliegue y arquitectura, pero con poca profundidad en la justificación técnica. | Memoria técnica impecable en Markdown: diagrama de arquitectura, decisiones justificadas, guía de despliegue y resolución de incidencias. |
| **8. Vídeo de explicación y demo** | **10%** | No se aporta vídeo explicativo. | Vídeo demasiado corto, poco claro, sin mostrar el funcionamiento real en producción o superando el límite de tiempo. | Explicación correcta del proyecto y demostración del despliegue, pero falta fluidez o detalle técnico en algún punto. | Presentación fluida y profesional (3-5 min): muestra el flujo completo desde el commit/PR hasta el despliegue automático en el VPS en vivo. |

*Recuerda que, para aprobar la práctica, no solo hay que obtener más de 5 puntos sino que debes superar el apartado 0 de la rúbrica (uso ético de la IA), pues, en caso contrario, no podrás demostrar tu autoría.*