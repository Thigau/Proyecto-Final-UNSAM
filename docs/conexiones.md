# Conexiones

## `v0.1.0` — LED de riego

El circuito utiliza el LED azul para representar la futura bomba de riego.

```text
Pin 8 → resistencia de 220 Ω → ánodo del LED → cátodo del LED → GND
```

| Elemento | Conexión | Destino |
|---|---|---|
| Arduino Uno | Pin digital 8 | Columna 10 de la breadboard |
| Resistencia de 220 Ω | Primer terminal | Columna 10 de la breadboard |
| Resistencia de 220 Ω | Segundo terminal | Columna 15 de la breadboard |
| LED azul | Ánodo, pata larga | Columna 15 de la breadboard |
| LED azul | Cátodo, pata corta | Columna 17 de la breadboard |
| Arduino Uno | GND | Columna 17 de la breadboard |

En la zona utilizada, los agujeros `A` a `E` de una misma columna están conectados internamente. Por eso, el cable y el componente pueden ocupar letras diferentes siempre que compartan el mismo número de columna.

### Funcionamiento eléctrico

- Cuando el pin 8 está en `HIGH`, entrega aproximadamente 5 V y el LED se enciende.
- Cuando el pin 8 está en `LOW`, queda en 0 V y el LED se apaga.
- La resistencia limita la corriente antes de que atraviese el LED.
- El circuito debe terminar en GND para formar un recorrido cerrado.
