# Historial de cambios

Los cambios relevantes del proyecto se documentan en este archivo.

## Rama `feat/lcd_Otros` — 2026-10-13

### Agregado

- Pantalla LCD 16×2 con interfaz I2C y dirección `0x27`.
- Visualización de humedad, iluminación, temperatura y estado de la bomba en el LCD.
- Primera lógica automática de bomba en el pin 13: luz menor a 80 %, temperatura mayor a 15 °C y humedad menor a 30 %.
- Salida de iluminación artificial en el pin 9, activada cuando la iluminación es menor o igual a 25 %.
- Tres LEDs violetas conectados en paralelo, cada uno con su propia resistencia de 220 Ω.
- Transistor NPN controlado mediante una resistencia de base de 1 kΩ para conmutar conjuntamente las luces.
- Captura del circuito en `docs/images/tinkercad-feat-lcd-otros.png`.

### Corregido

- Se separaron las ramas de los tres LEDs violetas para evitar conexiones accidentales entre columnas de la breadboard.
- Se corrigió el montaje que conectaba la resistencia y GND sobre la misma pata del LED, dejando la otra pata fuera del circuito.

### Verificado

- El LCD presenta correctamente las mediciones y el estado de la bomba.
- La salida de bomba responde a las condiciones definidas en el firmware.
- Los tres LEDs violetas se encienden y apagan simultáneamente mediante el transistor.
- Las luces se activan cuando la medición de iluminación es menor o igual a 25 %.

## [`v0.2.0`] — 2026-10-12

### Agregado

- Lectura analógica de humedad simulada mediante un potenciómetro conectado a `A0`.
- Lectura de temperatura mediante un sensor TMP36 conectado a `A1`.
- Lectura de iluminación mediante una fotoresistencia conectada a `A2` y una resistencia de 10 kΩ.
- Conversión de humedad e iluminación a porcentajes entre 0 % y 100 %.
- Conversión de la salida del TMP36 a grados Celsius.
- Visualización de las tres mediciones mediante el monitor serie a 9600 baudios.
- Captura del circuito en `docs/images/tinkercad-v0.2.0.png`.

### Verificado

- Las tres mediciones cambian al modificar cada sensor en Tinkercad.
- El monitor serie presenta humedad, temperatura e iluminación.
- El LED azul de la versión anterior continúa parpadeando correctamente.

## [`v0.1.0`] — 2026-10-11

### Agregado

- Estructura inicial de documentación y firmware.
- Circuito mínimo en Tinkercad con Arduino Uno, breadboard, LED azul y resistencia de 220 Ω.
- Programa de prueba para controlar el LED desde el pin digital 8.
- Captura funcional en `docs/images/tinkercad-v0.1.0.png`.
- Documentación de componentes, conexiones y pruebas.

### Verificado

- La simulación inicia correctamente.
- El programa compila sin errores.
- El LED se enciende y apaga en intervalos de un segundo.
