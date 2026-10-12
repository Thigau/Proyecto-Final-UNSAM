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
