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
