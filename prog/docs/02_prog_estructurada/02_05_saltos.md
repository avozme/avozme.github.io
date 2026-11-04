---
layout: page
title: 2.5. Instrucciones de salto
permalink: /programacion-estructurada/instrucciones-salto
nav_order: 5
has_children: true
parent: 2. Programación estructurada
grandparent: Programación
---
## 2.5. Instrucciones de salto
{: .no_toc }

- TOC
{:toc}

Las instrucciones de salto hacen que el flujo de ejecución normal del bloque en el que se encuentran *rompa su camino habitual*.

Las instrucciones de salto son muy útiles en ciertas circunstancias, pero no se debe abusar de ellas o corremos el riesgo de convertir nuestro código en el temible **código espagueti**, imposible de comprender y de mantener.

Solo deben usarse si simplifican la solución de manera razonable o como «salidas de emergencia» en caso de que un error grave impida continuar con la ejecución normal del bloque de código en el que se encuentran.

### 2.5.1. break

La sentencia `break` **sale abruptamente del bloque actual** (un bucle o un `switch`). La ejecución continuará por la instrucción siguiente al bloque en el que se encuentre el `break`.

Pueden usarse en los bucles con moderación, siempre que la lógica del bucle siga siendo clara y la solución se simplifique.

En un bloque `switch` tradicional de Java, en cambio, es imperativo el uso de `break` para evitar ejecutar varios `case` consecutivos.

### 2.5.2. continue

La sentencia `continue` fuerza la **finalización prematura de la iteración actual** de un bucle, pasando a la siguiente. 

Su uso generalmente denota un bucle mal planteado. Si te ves en la necesidad de usarlo, dedica unos minutos a repensar el bucle, porque probablemente hay una solución mejor.

### 2.5.3. return

`return` debe ser la **última instrucción de un método para devolver un valor** al código que lo invocó (veremos qué significa esto en el tema siguiente). Este uso del `return` es normal y no plantea ningún inconveniente.

Ahora bien, se puede **interrumpir la ejecución de un método prematuramente** colocando uno o varios `return` en mitad del código. Como en el caso de `break`, esto solo es justificable si la lógica del método sigue siendo bien comprensible a pesar de las múltiples salidas y si la solución con `return` prematuro es mucho más compleja.
