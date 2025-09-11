---
layout: page
title: Apéndice V. ChatGPT y Copilot
permalink: /chat_gpt_copilot/
nav_order: 13
has_children: false
parent: Desarrollo Web en Entorno Servidor
---
# Apéndice 5. ChatGPT y Copilot
{: .no_toc }

- TOC
{:toc}

Recientemente han aparecido varias inteligencias artificiales que pueden facilitar enormemente la labor del desarrollador y volverlo mucho más productivos y eficientes.

Advertencia: es muy probable que todo lo que vamos a decir a partir de ahora se quede rápidamente desfasado, porque se prevée que estas tecnologías avancen enormemente en los próximos meses.

## A5.1. ChatGPT

Sin duda la IA más popular en el momento de escribir estas líneas (febrero de 2023) es **ChatGPT**.

Basada en el motor de IA GPT3 de OpenAI, cuenta con una versión de pago con funcionalidades adicionales y mayor velocidad de procesamiento, pero la versión gratuita, al menos de momento, es completamente funcional.

Aunque ChatGPT es una IA de propósito general que puede usarse en multitud de ámbitos, es bastante buena como generadora de fragmentos de código en cualquier lenguaje. Esos fragmentos de código se generan de forma casi instantánea y están virtualmente libres de errores, por lo que podemos usarlos (con las debidas precauciones) en nuestros programas.

ChatGPT también es una ayuda inestimable para aprender nuevas tecnologías o nuevos lenguajes, pues sus respuestas suelen ser coherentes y concisas.

#### Algunos tips para usar correctamente ChatGPT

1. **Sé específico en tus preguntas**. Cuanto más específico seas, más apropiadas serán las respuetas. No escribas lo primero que se te ocurra.
2. **Sé cuidadoso con la sintaxis**. El analizador sintático de ChatGPT no puede obrar milagros. Si otro ser humano no podría comprender adecuadamente tu pregunta, es casi seguro que ChatGPT tampoco lo hará. Esto implica formar frases completas respetando la sintaxis y la ortografía. Mejor en inglés que en español, aunque es español lo entiende bastante bien.
3. **Proporciona ejemplos**. Si es posible, proporciona algún ejemplo de lo que buscas. Eso hará que la respuesta sea aún más precisa.
4. **Especifica bien el ámbito de trabajo**. Dile a ChatGPT si quieres construir una función, una clase, un método, un fragmento suelto de código, o si estás trabajando dentro de algún framework.
5. **Haz pruebas**. Si la respuesta no te satisface, no tires la toalla a la primera e intenta reformular tu pregunta.

#### Algunas precauciones al usar ChatGPT

1. **No te fies al 100% de las respuestas**. ChatGPT intenta satisfacer las demandas de los usuarios. Esto provoca que, a veces, si no conoce una respuesta, se la invente total o parcialmente. Y lo hace tan bien que la respuesta suele pasar por correcta cuando no lo es.
2. **Antes de preguntar, piensa**. Hasta hace poco, el primer impulso de muchos programadores al enfrentarse a una tarea nueva era buscar información en Google y pasarse un rato buceando por foros como Stackoverflow. Ahora, esta costumbre se ha cambiado por preguntar a ChatGPT y pasar un rato buceando en sus respuestas.

    Ambas aproximaciones son poco eficientes: muchas veces tardaríamos menos si pensásemos un poco en la solución a nuestro problema y la elaborásemos nosotros mismos. O, al menos, al pensar en el problema lo suficiente, podremos proporcionar un "prompt" más específico a ChatGPT y obtener una respuesta útil mucho antes.

## A5.2. Github Copilot

**Copilot** es una IA de Github diseñada específicamente para ayudar al desarrollador.

Aunque Copilot es un producto de pago, es posible obtener una licencia gratuita para estudiantes y profesores. En el sitio web de Github puedes encontrar más información. Es posible que te soliciten algún documento justificativo de tu condición de estudiante o un email en el dominio del centro educativo donde estás matriculado.

Copilot se puede instalar como un **complemento de Visual Studio Code** u otros IDEs populares, y actúa analizando y completando automáticamente nuestro código fuente mientras lo escribimos.

* **Copilot puede resultar significativamente más eficaz que ChatGPT para programar** (siempre que se use adecuadamente), puesto que está diseñado para ello.
* **El código generado por copilot suele ser confiable**, aunque siempre hay que revisarlo, puesto que puede generar código erróneo o incompleto.

#### Algunos tips para usar correctamente copilot

1. **Escribe código claro y consistente**. Cuanto más consistente sea tu código, mejor será el código generado por copilot, puesto que esta IA analiza el código que estás escribiendo para tratar de continuarlo.
2. **Aprovéchate de copilot para usar APIs desconocidas**. Copilot conoce muchas APIs de uso frecuente y te puede ahorrar mucho tiempo de consulta en la documentación.
3. **Escribe cuidadosamente el interfaz de tus funciones y métodos**. Si lo haces así, suele ser suficiente para que Copilot complete el código de la función por completo y de una sola tacada.
4. **Comenta el código adecuadamente**. Copilot no solo analiza tu código anterior, sino también los comentarios para tratar de afinar la generación de código.
5. **Aprovéchalo para documentar el código**. Del mismo modo, Copilot puede ayudarte a generar los comentarios para documentar tu código fuente. ¡Ya no tienes excusa para no documentar mientras desarrollas!

#### Algunas precauciones al usar Copilot

1. **No te fies al 100% de las respuestas**, igual que ocurre con ChatGPT.
2. **No vuelvas dependiente**. Copilot es una ayudante para permitirte desarrollar más rápido y eficientemente, pero no debería volverse una herramienta fundamental para el trabajo. ¡Debes conservar la voz cantante!
3. **Cuidado con los problemas legales**. Se dice por ahí que algunos fragmentos de código generados por Copilot podrían vulnerar las leyes de propiedad intelectual. Aunque es difícil precisar cuánto hay de cierto en ello (y Github, desde luego, lo niega), no está de más que procedas con cautela.
