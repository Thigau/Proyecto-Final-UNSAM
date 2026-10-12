# Historial de cambios

Los cambios relevantes del proyecto se documentan en este archivo.

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
