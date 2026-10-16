# Evolución de la simulación

Este documento registra la evolución del circuito desarrollado en Tinkercad.

Cada versión debe incluir una captura del circuito, una descripción de los cambios, las conexiones incorporadas, las pruebas realizadas y cualquier problema conocido.

## Simulación actual

Enlace de Tinkercad:

[Abrir la simulación en Tinkercad](https://www.tinkercad.com/things/3ApQIPepXQz-invernadero-proyecto-labo-1/editel?returnTo=https%3A%2F%2Fwww.tinkercad.com%2Fdashboard&sharecode=7U7pwsu07O8A8DXGv41fDI6yS_DnJD5i0dr5DXYXfiE)

Estado publicado actual:

> Rama `feat/lcd_Otros` — lectura de sensores, LCD I2C, bomba automática e iluminación artificial funcionales.

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

- Se agregó un potenciómetro para simular la humedad de la tierra.
- Se agregó un TMP36 para medir la temperatura.
- Se agregó una fotoresistencia con un divisor de tensión de 10 kΩ.
- Se incorporó la lectura de `A0`, `A1` y `A2`.
- Se convirtieron humedad e iluminación a porcentajes y la temperatura a grados Celsius.
- Se mostraron las tres mediciones mediante el monitor serie.

**Circuito:**

![Circuito correspondiente a la versión 0.2.0](images/tinkercad-v0.2.0.png)

**Conexiones agregadas:**

| Componente | Pin del componente | Conexión |
|---|---|---|
| Potenciómetro de humedad | Cursor central | `A0` |
| TMP36 | `VOUT`, pata central | `A1` |
| Fotoresistencia | Unión con resistencia de 10 kΩ | `A2` |
| Sensores | Alimentación | 5 V y GND compartidos |

**Pruebas realizadas:**

| Prueba | Resultado |
|---|---|
| Lectura de humedad | Correcto: porcentaje variable |
| Lectura de temperatura | Correcto: conversión a grados Celsius |
| Lectura de iluminación | Correcto: porcentaje variable |
| Visualización en monitor serie | Correcto: tres mediciones visibles |
| Funcionamiento del LED azul | Correcto: conserva el parpadeo |

**Problemas conocidos:**

- Ninguno conocido. Durante el montaje se corrigió una conexión incorrecta de GND en el divisor de la fotoresistencia.

---

### Rama `feat/lcd_Otros` — LCD, bomba e iluminación artificial

**Objetivo:** integrar una interfaz local, una primera lógica automática de riego y luces artificiales controladas mediante la fotoresistencia.

**Cambios realizados:**

- Se conectó un LCD 16×2 mediante I2C a los pines `A4` y `A5`.
- Se mostraron humedad, iluminación, temperatura y estado de la bomba.
- Se agregó un LED en el pin 13 para representar la bomba de agua.
- Se incorporaron tres LEDs violetas en paralelo, con una resistencia de 220 Ω por rama.
- Se controlaron las luces mediante un transistor NPN conectado al pin 9 a través de una resistencia de 1 kΩ.
- Se configuró el encendido de las luces cuando la iluminación es menor o igual a 25 %.

**Circuito:**

![Circuito con LCD, bomba y luces violetas](images/tinkercad-feat-lcd-otros.png)

**Conexiones agregadas:**

| Componente | Conexión | Función |
|---|---|---|
| LCD `SDA` | `A4` | Datos I2C |
| LCD `SCL` | `A5` | Reloj I2C |
| LED de bomba | Pin 13 mediante 220 Ω | Representación de la bomba |
| Base del transistor | Pin 9 mediante 1 kΩ | Control de iluminación |
| Tres LEDs violetas | Tres ramas de 220 Ω | Iluminación artificial |
| Emisor del transistor | GND común | Cierre del circuito |

**Pruebas realizadas:**

| Prueba | Resultado |
|---|---|
| Visualización de las tres mediciones | Correcto |
| Visualización del estado de la bomba | Correcto |
| Activación de la bomba según condiciones | Correcto |
| Encendido de luces con iluminación menor o igual a 25 % | Correcto |
| Apagado de luces por encima del umbral | Correcto |
| Encendido simultáneo de los tres LEDs mediante el transistor | Correcto |

**Incidencia resuelta:**

En el primer montaje, la resistencia y el retorno estaban conectados a la misma pata de cada LED y la otra pata quedaba fuera del circuito. Se corrigieron las ramas para que la corriente atraviese cada LED desde 5 V hacia el colector del transistor.

**Problemas conocidos:**

- Ninguno detectado en las pruebas actuales.

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
