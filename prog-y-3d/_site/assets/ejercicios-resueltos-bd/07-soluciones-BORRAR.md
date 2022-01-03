#### Ejercicio 1: Biblioteca

**Diagrama E-R:**

![Diagrama ER del ejercicio 1](/docs/prog-y-3d/_site/assets/images/07-01-diagrama-er.png)

**Paso a tablas:**

Las tablas que resultan de la aplicación de las reglas de paso a tablas son estas:

```
CLIENTES(nif#, nombre, apellidos, dirección, teléfono)
SOLICITAN(nif_cliente#, cod_libro#, fecha)
LIBROS(codigo#, titulo, autor, editorial, pvp, num_ejemplares)
SON_PEDIDOS(cod_libro#, cod_distribuidor)
DISTRIBUIDORES(codigo#, nombre, dirección, teléfono)
```

La tabla SOLICITAN surge de una relación N:N.

La tabla SON_PEDIDOS surge de una relación 1:N. Fíjate en que la norma general dice que estas relaciones no generan tabla, pero este es un caso excepcional, porque la participación del lado 1 es (0,1), de modo que tenemos que crear esa tabla intermedia para evitar valores nulos en la tabla LIBROS.


#### Ejercicio 2: Cajero automático

**Diagrama E-R:**

![Diagrama ER del ejercicio 2](/docs/prog-y-3d/_site/assets/images/07-02-diagrama-er.png)

**Paso a tablas:**

Las tablas que resultan de la aplicación de las reglas de paso a tablas son estas:

```
CLIENTES_PROPIOS(dni#, nombre, apellido1, apellido2, dirección, teléfono)
CUENTAS(num_cuenta#, saldo, maximo_diario, num_tarjeta, contraseña, dni_cliente)
OPERACIONES(num_operacion#, id_cajero, tipo_operación, fecha, hora, num_cuenta)
```

En esta ocasión, las dos relaciones son de tipo 1:N con participación mínima (1,1), por lo que no ha sido necesario crear una tabla para ninguna de las dos: ambas se implementan como claves ajenas en la tabla con participación N.

#### Ejercicio 3: Piscina

**Diagrama E-R:**

![Diagrama ER del ejercicio 3](/docs/prog-y-3d/_site/assets/images/07-03-diagrama-er.png)

**Paso a tablas:**

Las tablas que resultan de la aplicación de las reglas de paso a tablas son estas:

```
USUARIOS(id_usuario#, nombre, apellido1, apellido2, dni, dominilio)
EMPLEADOS(id_usuario#, num_ss, categoría, antigüedad)
ESTUDIANTES(id_usuario#, num_matrícula, titulación, curso, foto)
FAMILIAR(id_usuario#, parentesco, id_empleado)
INSTALACIONES(id_instalación#, nombre, aforo_maximo, aforo_actual)
TARIFAS(id_tarifa#, tarifa, id_instalación)
USUARIOS_OCUPAN_INSTALACIONES(id_usuario#, id_instalacion, fecha, hora_entrada, hora_salida)
USUARIOS_DESCUENTOS_INSTALACIONES(id_usuario#, id_instalacion#, descuento_aplicable)
```

Esta base de datos es más compleja que los anteriores, ¿verdad?

Hemos convertido todas las entidades a tablas.

Además, algunas relaciones también han generado tablas. Hemos optado por asignar un nombre más largo de lo habitual a estas relaciones (nombrando también a las entidades que se relacionan) para evitar confusiones.

Las relaciones que han generado tabla son:
* *tienen_descuento*, porque su cardinalidad es N:N. Hemos llamado a la tabla USUARIOS_DESCUENTOS_INSTALACIONES.
* *ocupan*, porque, aunque su cardinalidad es 1:N, la participación mínima es (0,1) en lugar de (1,1). Hemos llamado a esa tabla USUARIOS_OCUPAN_INSTALACIONES.

El resto de relaciones se han implementado mediante claves ajenas.

Por último, la relación de jerarquía entre EMPLEADOS y los tipos de empleado se ha implementado siguiendo las normas de las relaciones exclusivas: una tabla para el supertipo y otra para cada uno de los subtipos con atributos (es decir, todos). No es necesario crear el campo *tipo* en la tabla EMPLEADOS puesto que todos los subtipos tienen su propia tabla.

#### Ejercicio 4: Agencia de viajes

**Diagrama E-R:**

![Diagrama ER del ejercicio 4](/docs/prog-y-3d/_site/assets/images/07-04-diagrama-er.png)

**Paso a tablas:**

Las tablas que resultan de la aplicación de las reglas de paso a tablas son estas:

```
RESERVAS(cod_reserva#, fecha_entrada, num_noches, num_habitacion)
HABITACIONES(num_habitacion#, num_camas, precio, observaciones, habitacion_ocupada, cod_hotel)
ALOJAMIENTOS(cod_hotel#, nombre_hotel, num_estrellas, direccion_hotel, telefono_hotel)
FACTURAS(num_factura#, fecha_factura, importe, datos_cliente, cod_hotel)
FACTURAS_COMPAÑÍAS_AÉREAS(num_factura#, cod_compania#)
FACTURAS_ALOJAMIENTOS(num_factura#, cod_hotel#)
COMPANIAS_AEREAS(cod_compania#, nombre_compania, telefono_compania)
VUELOS(cod_vuelo#, origen_vuelo, destino_vuelo, fecha_vuelo, hora_vuelo, cod_compania)
PLAZAS_VUELOS(cod_plaza#, num_asiento, categoria_plaza, precio_plaza, plaza_ocupada, cod_vuelo)
```

Aunque salen bastantes tablas, el paso a tablas es bastante sencillo en esta base de datos, porque la mayor parte de las relaciones con 1:N y su participación mínima es (1,1), por lo que no generan tabla, sino que se implementan con claves ajenas.

Las únicas excepciones son las relaciones de FACTURAS con COMPAÑÍAS AÉREAS y con ALOJAMIENTOS, que tienen cardinalidad N:N. En ambos casos hay que crear una tabla para la relación. Le hemos puesto como nombre el conjunto de las dos tablas relacionadas (FACTURAS_COMPAÑÍAS_AÉREAS y FACTURAS_ALOJAMIENTOS), que es una práctica bastante habitual.

#### Ejercicio 5: Fuga del castillo

**Diagrama E-R:**

![Diagrama ER del ejercicio 5](/docs/prog-y-3d/_site/assets/images/07-05-diagrama-er.png)

**Paso a tablas:**

Las tablas que resultan de la aplicación de las reglas de paso a tablas son estas:

```
XXX
```

#### Ejercicio 6: Carreras de caballos

XXX hacer diagrama de dependencias

1. Explicar por qué la tabla NO está en BCNF y pasarla a BCNF.

XXX

2. Tomando de nuevo la tabla CARRERAS original, explicar por qué NO está en 2NF y pasarla a 2NF.

XXX

3. Con las tablas resultantes del apartado b), comprobar si están en 3NF y, en caso de no estarlo, pasarlas a 3NF.

XXX

#### Ejercicio 7: Autobuses urbanos

Esta es la colección de tablas que surge del diagrama E-R:

```
AUTOBUSES (id_vehiculo#, matricula, fecha_compra, cod_modelo, fecha_revision)
MODELOS (cod_modelo#, nombre_modelo, marca)
LINEAS (num_linea#, descripcion)
AUTOBUSES_CIRCULAN_EN_LINEAS (id_vehiculo#, num_linea)
PARADAS (cod_parada#, direccion)
LINEAS_TIENEN_PARADAS (num_linea#, cod_parada#, dia_semana#, hora#)
CONDUCTORES (dni_conductor#, nombre, apellidos, salario_mensual, num_linea, fecha, hora_ini, hora_fin)
EXPEDIENTES (cod_exp#, fecha, dni_conductor, cod_motivo)
MOTIVOS (cod_motivo#, descrip_motivo)
CONDUCTORES_EN_PRUEBAS (dni_conductor#, fin_periodo_pruebas)
CONDUCTORES_EN_PLANTILLA (dni_conductor#, fecha_contrato)
```

Para hacer la normalización, vamos a dibujar los diagramas de dependencias, pero solo de las tablas más grandes (las pequeñas son triviales y se ven a simple vista):

XXX diagramas de dependencias de AUTOBUSES, MODELOS, CONDUCTORES y EXPEDIENTES.

A partir de esos diagramas de dependencias, tenemos que:

XXX normalización

#### Ejercicio 8: Red de bibliotecas públicas

XXX
