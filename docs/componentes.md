# Componentes

Este documento registra los componentes incorporados en cada versión funcional del proyecto.

## `v0.1.0` — Circuito inicial

| Cantidad | Componente | Función en esta versión |
|---:|---|---|
| 1 | Arduino Uno R3 | Ejecutar el programa y controlar la salida digital 8 |
| 1 | Breadboard | Permitir las conexiones sin soldadura |
| 1 | LED azul | Representar visualmente la futura bomba de riego |
| 1 | Resistencia de 220 Ω | Limitar la corriente que circula por el LED |
| 2 | Cables | Conectar el pin 8 y GND con la breadboard |

### Observaciones

- El LED tiene polaridad: el ánodo se conecta hacia la salida y el cátodo hacia GND.
- La resistencia de 220 Ω protege tanto el LED como el pin de salida del Arduino.
- En esta versión, el LED parpadea como prueba de funcionamiento. Todavía no responde a un sensor de humedad.
- Los demás componentes previstos se incorporarán en los siguientes hitos.

## `v0.2.0` — Lectura de sensores

| Cantidad | Componente | Función en esta versión |
|---:|---|---|
| 1 | Potenciómetro de humedad | Simular distintos niveles de humedad de la tierra |
| 1 | Sensor TMP36 | Medir la temperatura simulada del invernadero |
| 1 | Fotoresistencia | Detectar cambios en la iluminación ambiental |
| 1 | Resistencia de 10 kΩ | Formar el divisor de tensión de la fotoresistencia |
| Varios | Cables | Distribuir 5 V, GND y las tres señales analógicas |

### Observaciones

- El potenciómetro funciona como divisor de tensión y entrega una señal variable a `A0`.
- El TMP36 entrega 0,5 V a 0 °C y aumenta aproximadamente 10 mV por cada grado Celsius.
- La fotoresistencia cambia su resistencia según la luz y necesita una resistencia fija de 10 kΩ para producir una tensión medible.
- El porcentaje de iluminación es una escala relativa de la simulación; no representa una medición calibrada en lux.

## Rama `feat/lcd_Otros` — LCD, bomba e iluminación artificial

| Cantidad | Componente | Función en esta etapa |
|---:|---|---|
| 1 | LCD 16×2 con interfaz I2C | Mostrar humedad, iluminación, temperatura y estado de la bomba |
| 1 | LED de bomba | Representar la bomba controlada mediante el pin digital 13 |
| 3 | LEDs violetas | Representar la iluminación artificial del invernadero |
| 4 | Resistencias de 220 Ω | Limitar la corriente del LED de bomba y de los tres LEDs violetas |
| 1 | Transistor NPN | Permitir que el pin 9 controle conjuntamente las tres luces |
| 1 | Resistencia de 1 kΩ | Limitar la corriente entre el pin 9 y la base del transistor |
| 1 | Breadboard adicional | Alojar el transistor y las tres ramas de iluminación |
| Varios | Cables | Unir alimentación, GND y señales digitales |

### Observaciones

- El LCD utilizado incorpora interfaz I2C, por lo que se conecta mediante `SDA` y `SCL` y no requiere un potenciómetro externo de contraste en la simulación actual.
- Cada LED violeta posee su propia resistencia de 220 Ω. Los LEDs están en paralelo y se controlan simultáneamente.
- El transistor utilizado para las luces es independiente del transistor previsto para el futuro ventilador.
- Los LEDs de Tinkercad representan iluminación violeta visible; no constituyen una simulación física de radiación ultravioleta.
