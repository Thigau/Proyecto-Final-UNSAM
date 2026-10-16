# Conexiones

## `v0.1.0` — LED de riego

El circuito utiliza el LED azul para representar la futura bomba de riego.

```text
Pin 8 → resistencia de 220 Ω → ánodo del LED → cátodo del LED → GND
```

| Elemento | Conexión | Destino |
|---|---|---|
| Arduino Uno | Pin digital 8 | Columna 10 de la breadboard |
| Resistencia de 220 Ω | Primer terminal | Columna 10 de la breadboard |
| Resistencia de 220 Ω | Segundo terminal | Columna 15 de la breadboard |
| LED azul | Ánodo, pata larga | Columna 15 de la breadboard |
| LED azul | Cátodo, pata corta | Columna 17 de la breadboard |
| Arduino Uno | GND | Columna 17 de la breadboard |

En la zona utilizada, los agujeros `A` a `E` de una misma columna están conectados internamente. Por eso, el cable y el componente pueden ocupar letras diferentes siempre que compartan el mismo número de columna.

### Funcionamiento eléctrico

- Cuando el pin 8 está en `HIGH`, entrega aproximadamente 5 V y el LED se enciende.
- Cuando el pin 8 está en `LOW`, queda en 0 V y el LED se apaga.
- La resistencia limita la corriente antes de que atraviese el LED.
- El circuito debe terminar en GND para formar un recorrido cerrado.

## `v0.2.0` — Sensores analógicos

Los tres sensores utilizan entradas analógicas diferentes para que Arduino pueda leerlos de manera independiente.

| Sensor | Terminal | Conexión |
|---|---|---|
| Potenciómetro de humedad | Terminal exterior | 5 V |
| Potenciómetro de humedad | Cursor o terminal central | `A0` |
| Potenciómetro de humedad | Terminal exterior restante | GND |
| TMP36, cara plana hacia el frente | Pata izquierda, `+VS` | 5 V |
| TMP36, cara plana hacia el frente | Pata central, `VOUT` | `A1` |
| TMP36, cara plana hacia el frente | Pata derecha, `GND` | GND |
| Fotoresistencia | Primera pata | 5 V |
| Fotoresistencia | Segunda pata | `A2` y primer terminal de la resistencia de 10 kΩ |
| Resistencia de 10 kΩ | Segundo terminal | GND |

### Divisor de tensión de iluminación

```text
5 V → fotoresistencia → unión con A2 → resistencia de 10 kΩ → GND
```

El pin `A2` debe conectarse exactamente en la unión entre la fotoresistencia y la resistencia fija. Una conexión incorrecta de GND mantiene la lectura cerca de cero.

### Distribución de alimentación

- Los sensores comparten las líneas de 5 V y GND de la breadboard.
- Las secciones separadas de un riel deben unirse con un puente cuando la breadboard no tenga continuidad interna entre ellas.
- Todas las mediciones utilizan el mismo GND como referencia de 0 V.

## Rama `feat/lcd_Otros` — LCD I2C

| Pin del LCD | Conexión en Arduino Uno |
|---|---|
| `GND` | `GND` |
| `VCC` | `5 V` |
| `SDA` | `A4` |
| `SCL` | `A5` |

El LCD se inicializa con la dirección I2C `0x27` y una disposición de 16 columnas por 2 filas.

## Rama `feat/lcd_Otros` — bomba simulada

```text
Pin 13 → resistencia de 220 Ω → ánodo del LED → cátodo del LED → GND
```

El LED se activa cuando se cumplen simultáneamente las condiciones provisionales definidas en el firmware:

- Iluminación menor a 80 %.
- Temperatura mayor a 15 °C.
- Humedad menor a 30 %.

## Rama `feat/lcd_Otros` — luces violetas

El pin 9 no alimenta directamente los LEDs. Controla la base de un transistor NPN mediante una resistencia de 1 kΩ.

```text
Pin 9 → resistencia de 1 kΩ → base del transistor NPN
Emisor del transistor → GND
Colector del transistor → cátodos de los tres LEDs
```

Cada LED forma una rama independiente:

```text
5 V → resistencia de 220 Ω → ánodo del LED → cátodo → colector
```

Las tres ramas se conectan en paralelo:

```text
5 V → 220 Ω → LED violeta 1 ─┐
5 V → 220 Ω → LED violeta 2 ─┼→ colector del transistor
5 V → 220 Ω → LED violeta 3 ─┘
                                  emisor → GND
```

### Consideraciones de montaje

- Cada LED debe tener su propia resistencia de 220 Ω.
- La resistencia y el retorno al colector deben conectarse a patas opuestas del LED.
- No se deben colocar ambos extremos del circuito en la misma columna de la breadboard, porque el LED quedaría fuera del recorrido de corriente.
- El ánodo se conecta hacia 5 V y el cátodo hacia el colector.
- Los rieles de GND de ambas breadboards deben compartir la misma referencia.
- Las luces se activan cuando la medición de iluminación es menor o igual a 25 %.
