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

## `v0.2.0` — Lectura de sensores

**Fecha:** 12 de octubre de 2026

**Entorno:** Tinkercad Circuits

**Placa:** Arduino Uno R3

### Objetivo

Comprobar la lectura independiente de humedad, temperatura e iluminación y mostrar los resultados mediante el monitor serie.

### Procedimiento

1. Se conectó el potenciómetro de humedad a `A0`.
2. Se conectó la salida del TMP36 a `A1`.
3. Se conectó el divisor de tensión de la fotoresistencia a `A2`.
4. Se inició la comunicación serie a 9600 baudios.
5. Se modificó individualmente cada sensor durante la simulación.
6. Se verificaron las mediciones mostradas en el monitor serie.

### Conversiones verificadas

```text
Humedad (%) = lectura A0 × 100 / 1023
Temperatura (°C) = (lectura A1 × 5 / 1023 − 0,5) × 100
Iluminación (%) = lectura A2 × 100 / 1023
```

### Resultados

| Prueba | Resultado esperado | Resultado observado | Estado |
|---|---|---|---|
| Lectura de humedad | El porcentaje cambia al girar el potenciómetro | Varió entre valores cercanos a 0 % y 100 % | Correcto |
| Lectura de temperatura | La medición cambia al modificar el TMP36 | Se mostró en grados Celsius | Correcto |
| Lectura de iluminación | El porcentaje cambia al modificar la luz | Respondió a los cambios de la fotoresistencia | Correcto |
| Independencia de sensores | Cada control modifica solamente su medición | Las tres entradas respondieron de forma independiente | Correcto |
| Monitor serie | Se muestran las tres mediciones | Los valores se actualizaron aproximadamente una vez por segundo | Correcto |
| Regresión del LED | El LED azul continúa parpadeando | El comportamiento de `v0.1.0` se conservó | Correcto |

### Incidencia resuelta

La lectura de iluminación permanecía cerca de cero porque el GND del divisor de tensión estaba mal conectado. Se corrigió la conexión entre la resistencia de 10 kΩ y GND; después de la corrección, `A2` respondió a los cambios de luz.

### Conclusión

El circuito y el programa cumplen el objetivo del hito `v0.2.0`. No se detectaron problemas pendientes en las lecturas analógicas.

## Rama `feat/lcd_Otros` — LCD, bomba e iluminación artificial

**Fecha:** 13 de octubre de 2026

**Entorno:** Tinkercad Circuits

**Rama:** `feat/lcd_Otros`

### Objetivo

Integrar la visualización de mediciones, una primera lógica de bomba y el encendido automático de tres luces violetas.

### Pruebas registradas

| Prueba | Resultado esperado | Estado |
|---|---|---|
| Inicialización del LCD | El LCD utiliza la dirección `0x27` y enciende su luz de fondo | Correcto |
| Visualización de sensores | El LCD muestra humedad, luz y temperatura | Correcto |
| Estado de la bomba | El LCD muestra `B:ON` o `B:OFF` | Correcto |
| Salida de bomba | El pin 13 cambia según los tres umbrales definidos | Correcto |
| Umbral de iluminación | El pin 9 pasa a `HIGH` con iluminación menor o igual a 25 % | Correcto |
| Tres luces violetas | Las tres ramas se encienden simultáneamente mediante el transistor | Correcto |

### Incidencia de montaje detectada

Durante la prueba inicial, las luces no encendían incluso al retirar el transistor. La resistencia de 220 Ω y el cable de retorno a GND estaban conectados a la misma pata de cada LED, mientras que la otra pata quedaba sin conexión. De esta forma, la corriente no atravesaba el LED.

El montaje se reorganizó dejando una rama independiente por LED:

```text
5 V → 220 Ω → ánodo → LED → cátodo → retorno común
```

### Problemas conocidos

- Ninguno detectado en las pruebas actuales de Tinkercad.

### Conclusión

La interfaz LCD, la salida de bomba y la iluminación artificial funcionan correctamente en la simulación publicada en la rama `feat/lcd_Otros`.
