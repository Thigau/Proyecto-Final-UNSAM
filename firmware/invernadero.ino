const int LED_RIEGO = 8;
const int PIN_SENSOR_HUMEDAD = A0;
const int PIN_SENSOR_TEMPERATURA = A1;

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
  int humedad = analogRead(PIN_SENSOR_HUMEDAD);
  Serial.print("La humedad es: ");
  Serial.println(humedad);
}

void sensarYMostrarTemperatura(){
  int temperatura = analogRead(PIN_SENSOR_TEMPERATURA);
  Serial.print("La temperatura es: ");
  Serial.println(temperatura);
}

void loop()
{
  ledParpadeando();
  sensarYMostrarHumedad();
  sensarYMostrarTemperatura();
}