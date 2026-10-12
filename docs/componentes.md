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
