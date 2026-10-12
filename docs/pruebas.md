# Pruebas

## `v0.1.0` — Prueba de salida digital

**Fecha:** 11 de octubre de 2026

**Entorno:** Tinkercad Circuits

**Placa:** Arduino Uno R3

### Objetivo

Comprobar que el circuito mínimo está correctamente conectado y que Arduino puede controlar el LED azul desde el pin digital 8.

### Procedimiento

1. Se conectó el pin 8 a una resistencia de 220 Ω.
2. La resistencia se conectó al ánodo del LED azul.
3. El cátodo del LED se conectó a GND.
4. Se configuró el pin 8 como salida.
5. Se programó un segundo en estado `HIGH` y un segundo en estado `LOW`.
6. Se inició la simulación y se observó el comportamiento del LED.

### Resultados

| Prueba | Resultado esperado | Resultado observado | Estado |
|---|---|---|---|
| Inicio de la simulación | La simulación comienza sin errores | Comenzó correctamente | Correcto |
| Compilación | El programa compila sin errores | Compiló correctamente | Correcto |
| Encendido | El LED se enciende durante un segundo | Se encendió durante un segundo | Correcto |
| Apagado | El LED se apaga durante un segundo | Se apagó durante un segundo | Correcto |
| Repetición | El ciclo se repite continuamente | El parpadeo se mantuvo | Correcto |

### Incidencia resuelta

En el primer intento, el LED estaba conectado con la polaridad invertida y no encendía. Se invirtió su orientación para dejar el ánodo hacia la resistencia y el cátodo hacia GND.

### Conclusión

El circuito y el programa cumplen el objetivo del hito `v0.1.0`. No se detectaron problemas pendientes.
