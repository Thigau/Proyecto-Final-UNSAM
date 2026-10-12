const int LED_RIEGO = 8;

void setup()
{
  pinMode(LED_RIEGO, OUTPUT);
}

void loop()
{
  digitalWrite(LED_RIEGO, HIGH);
  delay(1000);

  digitalWrite(LED_RIEGO, LOW);
  delay(1000);
}
