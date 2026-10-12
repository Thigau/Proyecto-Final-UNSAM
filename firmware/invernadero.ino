const int LED_RIEGO = 8;
const int PIN_SENSOR_HUMEDAD = A0;
const int PIN_SENSOR_TEMPERATURA = A1;
const int PIN_SENSOR_LUZ = A2;
void setup()
{
  pinMode(LED_RIEGO, OUTPUT);
  Serial.begin(9600);
}

void ledParpadeando(){
  digitalWrite(LED_RIEGO, HIGH);
  delay(500);
  digitalWrite(LED_RIEGO, LOW);
  delay(500);
}

void sensarYMostrarHumedad(){
  int lectura = analogRead(PIN_SENSOR_HUMEDAD);
  float porcentajeHumedad = lectura * 100.0 / 1023.0;
  Serial.print("La humedad es: ");
  Serial.print(porcentajeHumedad);
  Serial.println(" %");
}

void sensarYMostrarTemperatura(){
  int lectura = analogRead(PIN_SENSOR_TEMPERATURA);
  float voltaje = lectura * (5.0 / 1023.0);
  float temperatura = (voltaje - 0.5) * 100.0;
  Serial.print("La temperatura es: ");
  Serial.print(temperatura);
  Serial.print((char)176);
  Serial.println("C");
}

void sensarYMostrarLuz()
{
  int lectura = analogRead(PIN_SENSOR_LUZ);
  float porcentajeLuz = lectura * 100.0 / 1023.0;
  Serial.print("Iluminacion: ");
  Serial.print(porcentajeLuz);
  Serial.println(" %");
}

void loop()
{
  ledParpadeando();
  sensarYMostrarHumedad();
  sensarYMostrarTemperatura();
  sensarYMostrarLuz();
}
