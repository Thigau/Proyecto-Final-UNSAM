# Tabla de Pines

| Pin | Componente | Función |
|---|---|---|
| **2** | DHT11 (pin S) | Temperatura y humedad del aire |
| **3** | Pulsador 1 | Riego manual (a GND, `INPUT_PULLUP`) |
| **4** | Relé 1 (IN) | Bomba de agua |
| **5** | Relé 2 o MOSFET (IN) | Ventilador |
| **6** | Pulsador 2 | Cambiar de pantalla o modo (a GND, `INPUT_PULLUP`) |
| **7** | Alimentación del sensor de suelo (opcional) | Solo si se usa el sensor resistivo, para encenderlo únicamente al medir |
| **8** | Buzzer activo | Alarmas |
| **9** | Servo (opcional) | Ventana de ventilación |
| **10** | LED verde (con 220 Ω) | Todo en orden |
| **11** | LED amarillo (con 220 Ω) | Riego o ventilador activo |
| **12** | LED rojo (con 220 Ω) | Alerta (poca agua, temperatura alta) |
| **A0** | LDR + resistencia de 10 kΩ | Luz ambiente |
| **A1** | Sensor de humedad de tierra | Humedad del suelo |
| **A4 (SDA)** | LCD I2C y módulo RTC | Bus I2C compartido |
| **A5 (SCL)** | LCD I2C y módulo RTC | Bus I2C compartido |

**Pines libres:** A2, A3 y 13.
**Pines reservados:** 0 y 1 (USB y Monitor Serie).
