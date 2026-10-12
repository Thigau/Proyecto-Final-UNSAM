const int LED_RIEGO = 8;
const int PIN_SENSOR_HUMEDAD = A0;

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
  Serial.println(humedad);
}

void loop()
{
  ledParpadeando();
  sensarYMostrarHumedad();
}