---
layout: page
title: 5.4 Autenticación con Spring Security
permalink: /springboot/autenticacion/
nav_order: 4
has_children: true
parent: 5 SSR y API REST con Spring Boot
grand_parent: Desarrollo Web en Entorno Servidor
---

## 5.4. Autenticación con Spring Security
{: .no_toc }

- TOC
{:toc}

[Descargar presentación](https://www.dropbox.com/scl/fi/yny3mgozp2k0ntmruva51/05_04_autenticacion.pdf?rlkey=ibv17or3e0dqidqg5jxckrozp&st=o2daneot&dl=0){: .btn .btn-primary }



En Laravel teníamos los Starter Kits con autenticación, de los que probamos Breeze con el Middleware `auth`. 

Pues bien, **Spring Security** hace las mismas funciones en Spring Boot. Vamos a ver, muy brevemente, cómo usarlo.

### 5.4.1. Instalar Spring Security

**Spring Security** no se instala por defecto con Spring Boot.

Cuando crees el proyecto con Spring Initializr puedes seleccionar el módulo **Spring Security**. O, si el proyecto ya existe, puedes añadir el módulo manualmente al archivo `pom.xml` de Maven:

```xml
<dependency>
    <groupId>org.springframework.boot</groupId>
    <artifactId>spring-boot-starter-security</artifactId>
</dependency>
```

A partir de ahora, Spring Security **protegerá todos los endpoints** automáticamente y mostrará una pantalla de login por defecto si intenta acceder un usuario no autenticado. *La contraseña generada aparece en la consola al arrancar la aplicación*.

### 5.4.2. Autenticación en aplicaciones SSR con formulario de login

Como hemos visto, cuando añades Spring Security al proyecto, **todos los endpoints quedan protegidos por defecto**: si el usuario intenta acceder a cualquier URL sin haberse autenticado, Spring Security le redirigirá automáticamente a un formulario de login.

Pero normalmente querremos más control: definir qué rutas son públicas, qué rutas son privadas y personalizar el formulario de login. Para eso, se crea una **clase de configuración** anotada con `@Configuration` que le dice a Spring Security cómo comportarse.

A continuación veremos el proceso completo, paso a paso.

**Paso 1: La clase `SecurityConfig` (equivale al Middleware `auth` de Laravel)**

Esta clase define las reglas de acceso:

```java
import org.springframework.context.annotation.Bean;
import org.springframework.context.annotation.Configuration;
import org.springframework.security.config.annotation.web.builders.HttpSecurity;
import org.springframework.security.web.SecurityFilterChain;

@Configuration
public class SecurityConfig {

    @Bean
    public SecurityFilterChain filterChain(HttpSecurity http) throws Exception {
        http
            // 1. Definir qué rutas son públicas y cuáles requieren login
            .authorizeHttpRequests(auth -> auth
                .requestMatchers("/", "/login", "/css/**").permitAll()  // Rutas públicas
                .anyRequest().authenticated()                            // El resto, privadas
            )
            // 2. Configurar el formulario de login
            .formLogin(form -> form
                .loginPage("/login")           // URL de tu formulario de login personalizado
                .loginProcessingUrl("/login")  // URL a la que envía el POST el formulario
                .defaultSuccessUrl("/inicio", true)  // A dónde ir tras un login correcto
                .failureUrl("/login?error")    // A dónde ir si el login falla
                .permitAll()
            )
            // 3. Configurar el logout
            .logout(logout -> logout
                .logoutUrl("/logout")          // URL que activa el cierre de sesión
                .logoutSuccessUrl("/login?logout")  // A dónde ir tras el logout
                .permitAll()
            );

        return http.build();
    }
}
```

**Paso 2: Dónde están los usuarios — `UserDetailsService`**

Spring Security necesita saber de dónde sacar los usuarios para verificar sus contraseñas. Eso se define implementando la interfaz `UserDetailsService`. En desarrollo puedes usar usuarios en memoria para ir rápido:

```java
import org.springframework.context.annotation.Bean;
import org.springframework.security.core.userdetails.User;
import org.springframework.security.core.userdetails.UserDetailsService;
import org.springframework.security.provisioning.InMemoryUserDetailsManager;
import org.springframework.security.crypto.bcrypt.BCryptPasswordEncoder;
import org.springframework.security.crypto.password.PasswordEncoder;

// Añade estos beans dentro de tu clase SecurityConfig:

@Bean
public UserDetailsService userDetailsService() {
    // Creamos un usuario "admin" con contraseña "1234" (guardada hasheada con BCrypt)
    var admin = User.builder()
        .username("admin")
        .password(passwordEncoder().encode("1234"))  // ¡Nunca guardes contraseñas en texto plano!
        .roles("ADMIN")
        .build();
    return new InMemoryUserDetailsManager(admin);
}

@Bean
public PasswordEncoder passwordEncoder() {
    return new BCryptPasswordEncoder();
}
```

Para aplicaciones reales, en lugar de `InMemoryUserDetailsManager`, implementarías el `UserDetailsService` para cargar los usuarios desde tu base de datos. Por ejemplo:

```java
@Service
public class MiUserDetailsService implements UserDetailsService {

    // Suponemos que tienes un repositorio de usuarios en la BD
    private final UsuarioRepository usuarioRepository;

    public MiUserDetailsService(UsuarioRepository usuarioRepository) {
        this.usuarioRepository = usuarioRepository;
    }

    @Override
    public UserDetails loadUserByUsername(String email) throws UsernameNotFoundException {
        // Busca el usuario en la base de datos
        Usuario usuario = usuarioRepository.findByEmail(email)
            .orElseThrow(() -> new UsernameNotFoundException("Usuario no encontrado: " + email));

        // Devuelve un objeto UserDetails que Spring Security entiende
        return User.builder()
            .username(usuario.getEmail())
            .password(usuario.getPassword())  // La contraseña DEBE estar hasheada en la BD
            .roles("USER")
            .build();
    }
}
```

**Paso 3: El controlador de login**

Necesitas un controlador con un endpoint `GET /login` que devuelva la vista del formulario:

```java
@Controller
public class AuthController {

    // GET /login → muestra el formulario
    @GetMapping("/login")
    public String mostrarLogin() {
        return "auth/login";  // → templates/auth/login.html
    }
}
```

Observa que **no necesitas un endpoint `POST /login`** en tu controlador: Spring Security intercepta automáticamente el POST a `/login` (según lo configurado en `loginProcessingUrl`), verifica las credenciales usando tu `UserDetailsService` y gestiona la sesión.

**Paso 4: La vista del formulario de login**

El formulario de login es HTML estándar con un atributo crucial: los campos deben llamarse **`username`** y **`password`** para que Spring Security los reconozca. Podría ser algo así:

```html
<!-- templates/auth/login.html -->
<!DOCTYPE html>
<html xmlns:th="http://www.thymeleaf.org">
<head><title>Login</title></head>
<body>
    <h1>Iniciar sesión</h1>

    <!-- Mensaje de error si el login falló -->
    <p th:if="${param.error}" style="color: red;">Email o contraseña incorrectos.</p>
    <!-- Mensaje tras logout -->
    <p th:if="${param.logout}" style="color: green;">Sesión cerrada correctamente.</p>

    <!-- IMPORTANTE: los campos se llaman 'username' y 'password' -->
    <form th:action="@{/login}" method="post">
        <div>
            <label>Email:</label>
            <input type="text" name="username" required />
        </div>
        <div>
            <label>Contraseña:</label>
            <input type="password" name="password" required />
        </div>
        <button type="submit">Entrar</button>
    </form>
</body>
</html>
```

**Paso 5: Mostrar u ocultar elementos según el estado de autenticación**

En las vistas Thymeleaf, puedes usar el dialecto de Spring Security (añade la dependencia `thymeleaf-extras-springsecurity6` en tu `pom.xml`) para mostrar u ocultar contenido según si el usuario está autenticado:

```html
<!-- Añade esto al <html> de tus plantillas: -->
<html xmlns:th="http://www.thymeleaf.org"
      xmlns:sec="http://www.thymeleaf.org/extras/spring-security">

<!-- Mostrar solo si hay sesión (equivale a @auth de Blade) -->
<div sec:authorize="isAuthenticated()">
    <p>Bienvenido, <span sec:authentication="name"></span>!</p>
    <form th:action="@{/logout}" method="post">
        <button type="submit">Cerrar sesión</button>
    </form>
</div>

<!-- Mostrar solo si NO hay sesión (equivale a @guest de Blade) -->
<div sec:authorize="isAnonymous()">
    <a th:href="@{/login}">Iniciar sesión</a>
</div>

<!-- Mostrar solo si el usuario tiene rol ADMIN -->
<div sec:authorize="hasRole('ADMIN')">
    <a th:href="@{/admin}">Panel de administración</a>
</div>
```

> **¡ATENCIÓN!**
> El botón de logout **debe ser un formulario POST**, no un simple enlace GET. Spring Security, por razones de seguridad (protección CSRF), rechaza los logout que llegan por GET.

### 5.4.3. Autenticación en API REST con JWT

En las aplicaciones SSR, la sesión del usuario se mantiene mediante una **cookie** que el navegador envía automáticamente en cada petición. Sin embargo, en una API REST pura los clientes pueden ser apps móviles, scripts o frontends SPA que no manejan cookies de esa manera. Por eso las APIs usan, como ya vimos con Laravel, un mecanismo diferente: **los tokens**.

El estándar más extendido hoy en día son los **JWT (JSON Web Tokens)**. Son cadenas de texto codificadas que el servidor genera cuando el usuario se autentica y que el cliente debe incluir en todas sus peticiones posteriores. *Equivalen exactamente a los tokens de Sanctum que ya conoces de Laravel*.

Un JWT tiene tres partes separadas por puntos (`.`):
- **Header**: indica el algoritmo de firma
- **Payload**: contiene datos del usuario (id, email, rol, fecha de expiración)
- **Signature**: garantiza que nadie ha manipulado el token

El flujo completo es así:
1. El cliente hace `POST /api/auth/login` enviando `email` y `password` en JSON.
2. El servidor verifica las credenciales contra la base de datos.
3. Si son correctas, el servidor genera un JWT firmado con una clave secreta y se lo devuelve al cliente.
4. A partir de ese momento, en cada petición protegida, el cliente incluye la cabecera: `Authorization: Bearer <el_token>`. **Si no lo hace, sus peticiones serán rechazadas**.
5. Spring Security intercepta la petición, extrae el token, verifica su firma y, si es válido, da acceso al recurso.

**Implementación con la librería `jjwt`**

La forma más habitual de implementar JWT en Spring Boot es con la librería `jjwt`. Añádela a tu `pom.xml`:

```xml
<dependency>
    <groupId>io.jsonwebtoken</groupId>
    <artifactId>jjwt-api</artifactId>
    <version>0.12.6</version>
</dependency>
<dependency>
    <groupId>io.jsonwebtoken</groupId>
    <artifactId>jjwt-impl</artifactId>
    <version>0.12.6</version>
    <scope>runtime</scope>
</dependency>
<dependency>
    <groupId>io.jsonwebtoken</groupId>
    <artifactId>jjwt-jackson</artifactId>
    <version>0.12.6</version>
    <scope>runtime</scope>
</dependency>
```

Y define la clave secreta en `application.properties`:

```properties
# Clave para firmar los tokens. Debe ser larga y secreta (¡no la subas a Git!)
app.jwt.secret=clave-super-secreta-y-muy-larga-para-firmar-tokens-jwt-2024
app.jwt.expiration=86400000  # 24 horas en milisegundos
```

**Clase `JwtUtil`: generar y validar tokens**

```java
import io.jsonwebtoken.*;
import io.jsonwebtoken.security.Keys;
import org.springframework.beans.factory.annotation.Value;
import org.springframework.stereotype.Component;
import java.util.Date;
import javax.crypto.SecretKey;

@Component
public class JwtUtil {

    @Value("${app.jwt.secret}")
    private String secret;

    @Value("${app.jwt.expiration}")
    private long expiration;

    // Genera un token JWT para un usuario dado su email (u otro identificador)
    public String generateToken(String email) {
        SecretKey key = Keys.hmacShaKeyFor(secret.getBytes());
        return Jwts.builder()
            .subject(email)
            .issuedAt(new Date())
            .expiration(new Date(System.currentTimeMillis() + expiration))
            .signWith(key)
            .compact();
    }

    // Extrae el email del payload del token
    public String extractEmail(String token) {
        return parseClaims(token).getSubject();
    }

    // Valida que el token es correcto y no ha expirado
    public boolean isValid(String token) {
        try {
            parseClaims(token);
            return true;
        } catch (JwtException e) {
            return false;
        }
    }

    private Claims parseClaims(String token) {
        SecretKey key = Keys.hmacShaKeyFor(secret.getBytes());
        return Jwts.parser().verifyWith(key).build().parseSignedClaims(token).getPayload();
    }
}
```

**Controlador de autenticación (`/api/auth`)**

```java
import org.springframework.http.ResponseEntity;
import org.springframework.security.authentication.*;
import org.springframework.web.bind.annotation.*;

@RestController
@RequestMapping("/api/auth")
public class AuthApiController {

    private final AuthenticationManager authManager;
    private final JwtUtil jwtUtil;

    public AuthApiController(AuthenticationManager authManager, JwtUtil jwtUtil) {
        this.authManager = authManager;
        this.jwtUtil = jwtUtil;
    }

    // POST /api/auth/login → recibe {"email":"...", "password":"..."}
    @PostMapping("/login")
    public ResponseEntity<?> login(@RequestBody LoginRequest request) {
        try {
            // Spring Security verifica las credenciales
            authManager.authenticate(
                new UsernamePasswordAuthenticationToken(request.email(), request.password())
            );
            // Si llega aquí, las credenciales son correctas. Generamos el token.
            String token = jwtUtil.generateToken(request.email());
            return ResponseEntity.ok(new LoginResponse(token));
        } catch (BadCredentialsException e) {
            return ResponseEntity.status(401).body("Credenciales incorrectas");
        }
    }

    // Records de Java (equivalen a DTOs simples)
    public record LoginRequest(String email, String password) {}
    public record LoginResponse(String token) {}
}
```

**Filtro JWT: interceptar peticiones y validar el token**

Este es el componente que intercepta cada petición entrante, extrae el token de la cabecera `Authorization`, lo valida y, si es correcto, autentica al usuario en el contexto de Spring Security:

```java
import jakarta.servlet.*;
import jakarta.servlet.http.*;
import org.springframework.security.authentication.UsernamePasswordAuthenticationToken;
import org.springframework.security.core.context.SecurityContextHolder;
import org.springframework.security.core.userdetails.UserDetailsService;
import org.springframework.stereotype.Component;
import org.springframework.web.filter.OncePerRequestFilter;
import java.io.IOException;

@Component
public class JwtFilter extends OncePerRequestFilter {

    private final JwtUtil jwtUtil;
    private final UserDetailsService userDetailsService;

    public JwtFilter(JwtUtil jwtUtil, UserDetailsService userDetailsService) {
        this.jwtUtil = jwtUtil;
        this.userDetailsService = userDetailsService;
    }

    @Override
    protected void doFilterInternal(HttpServletRequest request,
                                    HttpServletResponse response,
                                    FilterChain chain) throws ServletException, IOException {

        String header = request.getHeader("Authorization");

        // Si no hay cabecera Bearer, dejamos pasar la petición (puede ser una ruta pública)
        if (header == null || !header.startsWith("Bearer ")) {
            chain.doFilter(request, response);
            return;
        }

        String token = header.substring(7); // Quitamos "Bearer "
        if (jwtUtil.isValid(token)) {
            String email = jwtUtil.extractEmail(token);
            var userDetails = userDetailsService.loadUserByUsername(email);
            var auth = new UsernamePasswordAuthenticationToken(
                userDetails, null, userDetails.getAuthorities()
            );
            // Registramos al usuario como autenticado en el contexto de Spring Security
            SecurityContextHolder.getContext().setAuthentication(auth);
        }

        chain.doFilter(request, response);
    }
}
```

**Configuración de Spring Security para API JWT**

```java
@Configuration
public class SecurityConfig {

    private final JwtFilter jwtFilter;

    public SecurityConfig(JwtFilter jwtFilter) {
        this.jwtFilter = jwtFilter;
    }

    @Bean
    public SecurityFilterChain filterChain(HttpSecurity http) throws Exception {
        http
            .csrf(csrf -> csrf.disable())  // Las APIs REST no necesitan protección CSRF
            .sessionManagement(s -> s.sessionCreationPolicy(SessionCreationPolicy.STATELESS))
            .authorizeHttpRequests(auth -> auth
                .requestMatchers("/api/auth/**").permitAll()  // Login libre
                .anyRequest().authenticated()                 // El resto requiere token
            )
            // Añadimos nuestro filtro JWT ANTES del filtro de autenticación por defecto
            .addFilterBefore(jwtFilter, UsernamePasswordAuthenticationFilter.class);

        return http.build();
    }

    @Bean
    public AuthenticationManager authenticationManager(AuthenticationConfiguration config)
            throws Exception {
        return config.getAuthenticationManager();
    }
}
```

**Cómo se usa en Postman**

1. Haz `POST http://localhost:8080/api/auth/login` con el body:
   ```json
   { "email": "admin@ejemplo.com", "password": "1234" }
   ```
2. Copia el token que devuelve el servidor.
3. En las siguientes peticiones, ve a la pestaña **Authorization** → **Bearer Token** y pega el token.

A partir de ahí, Postman incluirá automáticamente la cabecera `Authorization: Bearer <token>` en todas tus peticiones.

> **¡ATENCIÓN!**
> La implementación de JWT tiene bastante código de infraestructura (el filtro, la clase `JwtUtil`, la configuración). Esto es completamente normal en Spring Boot: es código que se escribe una vez y luego no se toca. Compáralo con Sanctum en Laravel, donde también existía ese código de infraestructura, pero lo instalaba Breeze automáticamente.
