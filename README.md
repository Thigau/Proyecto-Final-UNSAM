# Proyecto Final Laboratorio de Computación 1

Todavía no tenemos la consigna concreta.

> El alcance y los requisitos pueden cambiar cuando recibamos la consigna definitiva de la materia.

## Descripción

Este proyecto consiste en desarrollar un invernadero inteligente controlado mediante un Arduino Uno.

El sistema utilizará distintos sensores para representar la humedad de la tierra, la temperatura y la iluminación ambiental. A partir de estas mediciones, Arduino controlará automáticamente el riego, la iluminación y la ventilación del invernadero.

La primera etapa del proyecto se desarrolla y prueba mediante una simulación en Tinkercad Circuits. En una etapa posterior, el diseño podrá adaptarse para su implementación con componentes físicos.

## Estado del proyecto

Actualmente el proyecto se encuentra en una etapa inicial de diseño y simulación.

Versión actual: `v0.2.0` — lectura de sensores funcional.

- [x] Definir la idea general.
- [x] Seleccionar los componentes.
- [x] Diseñar el circuito inicial.
- [x] Implementar la lectura de sensores.
- [ ] Implementar el riego automático.
- [x] Implementar la iluminación automática.
- [ ] Implementar la ventilación automática.
- [ ] Incorporar los modos manual y automático.
- [ ] Incorporar alarmas.
- [x] Incorporar la pantalla LCD.
- [ ] Integrar y probar el sistema completo.
- [ ] Preparar la versión final.

## Funcionalidades previstas

El sistema permitirá:

- Medir la humedad de la tierra.
- Medir la temperatura del invernadero.
- Medir la iluminación ambiental.
- Activar automáticamente el riego.
- Regular la iluminación mediante PWM.
- Encender y regular un ventilador.
- Cambiar entre los modos automático y manual.
- Emitir alertas sonoras ante condiciones críticas.
- Mostrar información y estados en una pantalla LCD.
- Consultar las mediciones mediante el monitor serie.

## Entradas y salidas

El proyecto busca utilizar diferentes capacidades del Arduino Uno:

| Tipo               | Aplicación                                |
| ------------------ | ----------------------------------------- |
| Entrada analógica  | Humedad, temperatura e iluminación        |
| Entrada digital    | Pulsador de control                       |
| Salida digital     | Riego simulado y alarma                   |
| Salida PWM         | Iluminación y velocidad del ventilador    |
| Comunicación serie | Visualización y diagnóstico de mediciones |
| Interfaz LCD       | Presentación del estado del sistema       |

## Componentes

| Cantidad | Componente                    | Función                                             |
| -------: | ----------------------------- | --------------------------------------------------- |
|        1 | Arduino Uno R3                | Control principal                                   |
|        1 | Breadboard                    | Montaje del circuito                                |
|        1 | Potenciómetro de 250 kΩ       | Simulación de la humedad de la tierra               |
|        1 | Sensor de temperatura TMP36   | Medición de temperatura                             |
|        1 | Fotoresistencia               | Medición de luz ambiental                           |
|        1 | LED azul                      | Simulación de la bomba de agua                      |
|        1 | LED amarillo                  | Iluminación regulada mediante PWM                   |
|        1 | Pulsador                      | Control manual del sistema                          |
|        1 | Piezo                         | Alarma sonora                                       |
|        1 | Pantalla LCD 16×2             | Visualización de información                        |
|        1 | Potenciómetro de 10 kΩ        | Ajuste del contraste del LCD                        |
|        1 | Motor DC                      | Simulación del ventilador                           |
|        1 | Transistor NPN                | Control seguro del motor                            |
|        1 | Diodo                         | Protección contra el retorno de corriente del motor |
|        3 | Resistencias de 220 Ω         | Protección de los LEDs y del LCD                    |
|        2 | Resistencias de 10 kΩ         | Divisor de tensión y pull-down del pulsador         |
|        1 | Resistencia de 1 kΩ           | Control de la base del transistor                   |
|        1 | Fuente de alimentación de 5 V | Alimentación del motor                              |
|   Varios | Cables                        | Conexión de los componentes                         |

## Simulación

El circuito se desarrolla mediante [Tinkercad Circuits](https://www.tinkercad.com/circuits).

Enlace a la simulación:

[https://www.tinkercad.com/things/3ApQIPepXQz-invernadero-proyecto-labo-1/editel?returnTo=https%3A%2F%2Fwww.tinkercad.com%2Fdashboard&sharecode=7U7pwsu07O8A8DXGv41fDI6yS_DnJD5i0dr5DXYXfiE](https://www.tinkercad.com/things/3ApQIPepXQz-invernadero-proyecto-labo-1/editel?returnTo=https%3A%2F%2Fwww.tinkercad.com%2Fdashboard\&sharecode=7U7pwsu07O8A8DXGv41fDI6yS_DnJD5i0dr5DXYXfiE)

La evolución del circuito, sus conexiones y las pruebas realizadas se documentan en [docs/simulacion.md](docs/simulacion.md).

## Cómo ejecutar el proyecto

### Mediante Tinkercad

1. Abrir el enlace de la simulación.
2. Seleccionar la opción para copiar el circuito, si no se poseen permisos de edición.
3. Presionar **Iniciar simulación**.
4. Abrir el monitor serie.
5. Modificar los valores de los sensores simulados.
6. Observar la respuesta de los LEDs, el motor, el piezo y la pantalla LCD.

### Mediante Arduino IDE

Esta opción estará disponible cuando el proyecto se adapte a componentes físicos.

1. Descargar o clonar este repositorio.
2. Abrir `firmware/invernadero.ino` con Arduino IDE.
3. Seleccionar la placa **Arduino Uno**.
4. Seleccionar el puerto correspondiente.
5. Compilar y cargar el programa.

## Estructura del repositorio

```text
invernadero-arduino/
├── README.md
├── CHANGELOG.md
├── firmware/
│   └── invernadero.ino
├── docs/
│   ├── componentes.md
│   ├── conexiones.md
│   ├── simulacion.md
│   ├── pruebas.md
│   └── images/
└── LICENSE
```

## Documentación

- [Evolución de la simulación](docs/simulacion.md)
- [Lista de componentes](docs/componentes.md)
- [Tabla de conexiones](docs/conexiones.md)
- [Pruebas realizadas](docs/pruebas.md)
- [Historial de cambios](CHANGELOG.md)

Algunos de estos documentos se agregarán durante el desarrollo.

## Roadmap

| Versión  | Objetivo                                      |
| -------- | --------------------------------------------- |
| `v0.1.0` | Estructura inicial y prueba de funcionamiento |
| `v0.2.0` | Lectura de sensores                           |
| `v0.3.0` | Riego automático                              |
| `v0.4.0` | Iluminación automática                        |
| `v0.5.0` | Ventilación automática                        |
| `v0.6.0` | Modos manual y automático                     |
| `v0.7.0` | Sistema de alarmas                            |
| `v0.8.0` | Pantalla LCD                                  |
| `v0.9.0` | Integración y pruebas completas               |
| `v1.0.0` | Entrega final                                 |

## Contribuciones

Las mejoras y correcciones deben desarrollarse en una rama separada.

Ejemplos:

```text
feature/sensores
feature/riego
feature/iluminacion
feature/ventilador
feature/lcd
fix/calculo-temperatura
```

Antes de integrar un cambio en `main`, se debe verificar que:

- La simulación inicia correctamente.
- El código compila sin errores.
- La funcionalidad nueva fue probada.
- Las conexiones modificadas están documentadas.
- Se agregó una captura cuando hubo cambios visuales en el circuito.

## Autores

Proyecto realizado para la materia Laboratorio de Computación 1.

Juan Ignacio Ferrando Villoslada, Joaquin Ayerra, Thiago Lartigau

## Licencia

Ciclista sin Licencia
