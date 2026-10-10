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

<div style="color:red; font-size: 150%"><strong>ESTE MATERIAL AÚN ESTÁ EN DESARROLLO</strong></div>

- TOC
{:toc}

Esta unidad cierra el módulo y se apoya en todo lo que hemos ido construyendo a lo largo del curso: Git, GitHub y Docker (Bloque 1), servicios con Laravel y Spring Boot (UD 3, 4 y 5), microservicios con FastAPI (UD 6) y el frontend con Vue.js (UD 7).

El hilo conductor es aprender a llevar a producción el sistema de reservas que desarrollamos en la UD 6, añadiéndole un pipeline automático y desplegándolo en un VPS real.

---

## 8.1. Integración y despliegue continuo (CI/CD): GitHub Actions

Hasta ahora hemos desarrollado y probado todo en local. En este bloque vamos a automatizar el proceso de llevar el código a producción de forma segura y repetible.

### 8.1.1. ¿Qué es DevOps?

**DevOps** no es una herramienta ni un rol concreto, sino una cultura y un conjunto de prácticas que buscan acortar el ciclo entre que escribes código y que ese código está funcionando en producción, con la mayor calidad posible. Los tres pilares son:

- **Integración continua (CI, *Continuous Integration*):** cada vez que alguien hace push al repositorio, se ejecutan automáticamente los tests y las comprobaciones de calidad. Si algo falla, lo sabemos de inmediato, antes de que el código contamine la rama principal.

- **Entrega continua (CD, *Continuous Delivery*):** además de los tests, el pipeline prepara automáticamente un artefacto desplegable (una imagen Docker, un paquete, etc.) listo para ser publicado en producción. El despliegue final lo puede activar un humano.

- **Despliegue continuo (*Continuous Deployment*):** el despliegue también es automático si todos los pasos del pipeline pasan. No interviene ningún humano.

La idea de **pipeline as code** es fundamental: el pipeline no es una configuración en un panel web que solo el administrador conoce, sino un archivo YAML en el propio repositorio, versionado como cualquier otro código. Cualquier desarrollador puede leerlo, modificarlo y entender exactamente qué ocurre cuando hace push.

### 8.1.2. GitHub Actions: anatomía de un pipeline

GitHub Actions es el sistema de CI/CD integrado en GitHub. Su configuración vive en archivos YAML dentro del directorio `.github/workflows/` del repositorio.

Los conceptos básicos son:

| Concepto | Descripción |
|---|---|
| **Workflow** | Un archivo YAML que define la automatización completa |
| **Evento (trigger)** | Lo que activa el workflow: `push`, `pull_request`, `schedule`, etc. |
| **Job** | Un conjunto de steps que se ejecutan en la misma máquina virtual |
| **Step** | Una tarea individual: ejecutar un comando o usar una action reutilizable |
| **Runner** | La máquina virtual donde se ejecuta el job (ej: `ubuntu-latest`) |

Veamos un ejemplo de workflow completo para un microservicio FastAPI. Cuando alguien hace push a `main`, se activa el pipeline: primero comprueba la calidad del código con el linter `ruff` y ejecuta los tests con `pytest`. Si todo pasa, construye la imagen Docker y la publica en el GitHub Container Registry. Finalmente, se conecta al servidor de producción por SSH y levanta la nueva versión.

```yaml
# .github/workflows/ci-fastapi.yml
name: CI/CD - Microservicio de Reservas

on:
  push:
    branches: [main]
  pull_request:
    branches: [main]

jobs:
  # ETAPA 1: Calidad y tests
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

**Variables y secrets.** Las variables de entorno normales se declaran en `env:`. Los datos sensibles (tokens, contraseñas de servidor, claves SSH) van en los **Secrets** del repositorio (Settings → Secrets and variables → Actions) y se referencian como `${{ secrets.MI_SECRET }}`. Nunca los escribas directamente en el YAML.

**Tests automáticos.** Una CI sin tests es como un semáforo siempre en verde: da sensación de seguridad pero no comprueba nada. Para FastAPI, la forma estándar es usar `pytest` con el `TestClient` que provee FastAPI. El truco de `dependency_overrides` te permite inyectar una base de datos de prueba (SQLite en memoria) sin tocar el código de producción:

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

**Protección de la rama main.** Una vez que tienes el pipeline, puedes ir a Settings → Branches → Add rule en GitHub y marcar "Require status checks to pass before merging". Así nadie puede hacer merge a `main` si los checks fallan, y puedes añadir un badge de estado en tu README:

```markdown
![CI](https://github.com/tu-usuario/tu-repo/actions/workflows/ci-fastapi.yml/badge.svg)
```

---

## 8.2. Despliegue en producción: Docker en un VPS de OpenStack

Tener el pipeline funcionando es una gran cosa, pero necesitamos un servidor real donde aterrice nuestra aplicación. En este bloque veremos cómo preparar un VPS en OpenStack y cómo desplegar nuestros contenedores de forma correcta.

### 8.2.1. Preparar el servidor en OpenStack

Si seguiste los pasos del Apéndice 1, ya sabes cómo crear una instancia en OpenStack y conectarte por SSH. Solo recuerda los puntos imprescindibles:

1. Crear la instancia (Ubuntu 22.04 o 24.04, con al menos 1 vCPU y 2 GB de RAM).
2. Asignar una **IP flotante** para poder acceder desde el exterior.
3. Abrir en el **Grupo de Seguridad** los puertos 22 (SSH), 80 (HTTP) y 443 (HTTPS). Los puertos de las bases de datos (3306, 5432) **no deben abrirse** al exterior.

Una vez dentro del servidor, instala Docker:

```bash
sudo apt update && sudo apt install -y docker.io docker-compose-plugin git
sudo usermod -aG docker ubuntu   # para no tener que poner sudo en cada comando docker
# Cierra sesión y vuelve a entrar para que el grupo surta efecto
```

### 8.2.2. Docker en producción vs. en desarrollo

El `docker-compose.yml` que usas en local sirve para desarrollar, pero no es adecuado para producción. Hay diferencias importantes:

| Opción | Desarrollo | Producción |
|---|---|---|
| `--reload` en el comando | Sí (detecta cambios en vivo) | No (consume recursos innecesariamente) |
| Puertos de BD publicados | A veces (para usar DBeaver, etc.) | **No** (la BD no debe ser accesible desde fuera) |
| Código montado como volumen | Sí (editar en caliente) | No (el código va dentro de la imagen) |
| `restart: unless-stopped` | No necesario | **Sí** (la app se reinicia si cae o si se reinicia el servidor) |

Un `docker-compose.yml` de producción típico para FastAPI + PostgreSQL, que el pipeline descargaría y levantaría, quedaría así:

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

Las variables sensibles (`DB_PASSWORD`, `SECRET_KEY`) van en un archivo `.env` en el propio servidor, en la misma carpeta que el Compose, y **nunca en el repositorio**:

```bash
# /opt/sistema-reservas/.env
DB_PASSWORD=una-contraseña-larga-y-aleatoria
SECRET_KEY=otra-clave-aleatoria-para-jwt
```

### 8.2.3. Reverse proxy con Nginx o Caddy

En producción no exponemos directamente los puertos de los contenedores al exterior. Colocamos un **reverse proxy** al frente que escucha en los puertos 80 y 443, redirige el HTTP al HTTPS, y reenvía las peticiones al contenedor correcto según el dominio o la ruta.

Esto nos soluciona además el problema del HTTPS: los certificados TLS los gestiona el reverse proxy, y los contenedores internos pueden seguir hablando HTTP sin cifrar entre sí (dentro de la red de Docker, no es un riesgo).

**Caddy** es la opción más sencilla para empezar porque gestiona los certificados de Let's Encrypt **de forma completamente automática**. Su configuración es mínima:

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

Si prefieres **Nginx**, tienes más control pero la configuración de los certificados (usando Certbot) es manual:

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

Recuerda también actualizar la configuración de CORS en FastAPI para usar los dominios de producción, no `localhost`:

```python
# main.py de FastAPI (en producción)
origins = [
    "https://app.midominio.com",
]
```

### 8.2.4. El ciclo completo de CI/CD

Con todo lo que hemos visto, el flujo completo de un cambio desde el código hasta producción queda así:

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
4. Se construye la imagen Docker y se publica en GHCR con la etiqueta sha-<commit>
        |
        v
5. El pipeline se conecta por SSH al VPS
        |
        v
6. docker compose pull && docker compose up -d
        |
        v
7. La nueva versión está en producción en cuestión de minutos
```

Si algo va mal en cualquier paso, el pipeline se detiene y la versión anterior sigue en producción. La etiqueta con el SHA del commit te permite hacer **rollback** con facilidad: si `sha-abc1234` da problemas, cambias la etiqueta en el `docker-compose.yml` al commit anterior y vuelves a ejecutar `docker compose up -d`.

---

## 8.3. Práctica final

La práctica final del módulo consiste en desplegar una aplicación web de corte realista que integre lo aprendido a lo largo del curso.

**Descripción general.** Partiendo del sistema de reservas desarrollado en las unidades anteriores, deberás entregarlo funcionando en un VPS de OpenStack con las siguientes características:

**Componentes de la aplicación:**

- **API de reservas** (FastAPI): gestión de reservas, recursos y usuarios. Base de datos PostgreSQL.
- **Frontend** (Vue.js): interfaz de usuario que consume la API.

**Requisitos de infraestructura:**

- Todos los servicios desplegados con Docker Compose en el VPS de OpenStack.
- Reverse proxy (Caddy o Nginx) gestionando el acceso desde el exterior.
- Puertos de base de datos no expuestos al exterior.
- Variables de entorno y secretos correctamente gestionados (archivo `.env` en el servidor, nunca en el repositorio).

**Requisitos de CI/CD:**

- Pipeline de GitHub Actions con al menos dos etapas: tests y despliegue.
- Tests automáticos (mínimo 3 tests relevantes) con pytest.
- La rama `main` protegida: no se puede hacer merge si los checks fallan.
- Badge de estado del pipeline en el README.

**Entregables:**

1. IP pública del sistema funcionando (accesible desde el navegador).
2. URL del repositorio en GitHub (con el pipeline visible en la pestaña Actions).
3. Breve memoria (1-2 páginas) describiendo las decisiones de arquitectura tomadas, los problemas encontrados y cómo se resolvieron.
