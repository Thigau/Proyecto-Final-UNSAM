# Evolución de la simulación

Este documento registra la evolución del circuito desarrollado en Tinkercad.

Cada versión debe incluir una captura del circuito, una descripción de los cambios, las conexiones incorporadas, las pruebas realizadas y cualquier problema conocido.

## Simulación actual

Enlace de Tinkercad:

[Abrir la simulación en Tinkercad](https://www.tinkercad.com/things/3ApQIPepXQz-invernadero-proyecto-labo-1/editel?returnTo=https%3A%2F%2Fwww.tinkercad.com%2Fdashboard&sharecode=7U7pwsu07O8A8DXGv41fDI6yS_DnJD5i0dr5DXYXfiE)

Versión actual:

> `v0.1.0` — Funcional.

## Convención para las imágenes

Las capturas se guardan en `docs/images/` utilizando este formato:

```text
tinkercad-v0.1.0.png
tinkercad-v0.2.0.png
tinkercad-v0.3.0.png
```

Para insertar una captura:

```md
![Circuito correspondiente a la versión 0.1.0](images/tinkercad-v0.1.0.png)
```

## Historial del circuito

### `v0.1.0` — Circuito inicial

**Objetivo:** comprobar el funcionamiento básico del Arduino y la estructura inicial del circuito.

**Cambios realizados:**

- Se agregó el Arduino Uno.
- Se agregó la breadboard.
- Se conectó un LED azul al pin digital 8 mediante una resistencia de 220 Ω.
- Se programó un parpadeo de un segundo para comprobar la salida digital.

**Circuito:**

![Circuito correspondiente a la versión 0.1.0](images/tinkercad-v0.1.0.png)

**Conexiones incorporadas:**

| Origen | Destino | Función |
|---|---|---|
| Pin digital 8 | Resistencia de 220 Ω | Salida controlada por Arduino |
| Resistencia de 220 Ω | Ánodo del LED azul | Limitación de corriente |
| Cátodo del LED azul | GND | Cierre del circuito |

**Pruebas realizadas:**

| Prueba | Resultado |
|---|---|
| La simulación inicia correctamente | Correcto |
| El código compila sin errores | Correcto |
| El LED responde correctamente | Correcto: enciende y apaga cada segundo |

**Problemas conocidos:**

- Ninguno conocido.

---

### `v0.2.0` — Lectura de sensores

**Objetivo:** leer la humedad simulada, la temperatura y la iluminación ambiental.

**Cambios realizados:**

- Pendiente de completar.

**Circuito:**

> Captura pendiente.

**Conexiones agregadas:**

| Componente | Pin del componente | Conexión |
|---|---|---|
| Potenciómetro de humedad | Pendiente | Pendiente |
| TMP36 | Pendiente | Pendiente |
| Fotoresistencia | Pendiente | Pendiente |

**Pruebas realizadas:**

| Prueba | Resultado |
|---|---|
| Lectura de humedad | Pendiente |
| Lectura de temperatura | Pendiente |
| Lectura de iluminación | Pendiente |
| Visualización en monitor serie | Pendiente |

**Problemas conocidos:**

- Pendiente de completar.

---

## Plantilla para una nueva versión

Copiar esta sección por cada actualización importante:

```md
### `vX.Y.Z` — Nombre de la versión

**Objetivo:**

Descripción breve del objetivo de la versión.

**Cambios realizados:**

- Cambio 1.
- Cambio 2.
- Cambio 3.

**Circuito:**

![Circuito correspondiente a la versión X.Y.Z](images/tinkercad-vX.Y.Z.png)

**Conexiones agregadas o modificadas:**

| Componente | Pin del componente | Conexión |
|---|---|---|
| Componente | Pin | Destino |

**Pruebas realizadas:**

| Prueba | Resultado |
|---|---|
| Descripción de la prueba | Correcto/Pendiente/Error |

**Problemas conocidos:**

- Descripción del problema o “Ninguno”.
```

## Criterio de actualización

Este documento debe actualizarse cuando:

- Se agregue o elimine un componente.
- Cambie una conexión.
- Se incorpore una funcionalidad.
- Se corrija un problema de cableado.
- Se complete un nuevo hito del roadmap.

No es necesario crear una captura por cada commit. Una captura por cada versión funcional es suficiente.
