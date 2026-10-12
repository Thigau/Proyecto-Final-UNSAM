# Tabla de pines

| Pin | Componente | Función |
|---|---|---|
| **2** | DHT11 (pin S) | Datos de temperatura y humedad |
| **3** | Pulsador 1 | Riego manual (a GND, `INPUT_PULLUP`) |
| **4** | Relé (IN) | Riego |
| **5** | ULN2003 IN1 | Cortina (opcional) |
| **6** | Pulsador 2 | Cambiar pantalla (a GND, `INPUT_PULLUP`) |
| **7** | Sensor de nivel de agua (pin +) | Se alimenta solo al medir, para reducir la corrosión |
| **8** | Buzzer activo | Alarmas |
| **9** | Servo (señal) | Ventana |
| **10** | LED verde (con 220 Ω) | Todo en orden |
| **11** | LED amarillo (con 220 Ω) | Riego o ventilación activos |
| **12** | LED rojo (con 220 Ω) | Alerta |
| **13** | ULN2003 IN2 | Cortina (opcional) |
| **A0** | LDR + resistencia 10 kΩ | Luz |
| **A1** | Sensor de nivel de agua (pin S) | Humedad de la tierra |
| **A2** | ULN2003 IN3 | Cortina (opcional) |
| **A3** | ULN2003 IN4 | Cortina (opcional) |
| **A4 (SDA)** | LCD y RTC | Bus I2C compartido |
| **A5 (SCL)** | LCD y RTC | Bus I2C compartido |

**Pines reservados:** 0 y 1 (USB y Monitor Serie).
Si no se usa la cortina, quedan libres los pines 5, 13, A2 y A3.
