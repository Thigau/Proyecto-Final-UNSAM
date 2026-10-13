#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

const int LED_RIEGO = 8;
const int PIN_SENSOR_HUMEDAD = A0;
const int PIN_SENSOR_TEMPERATURA = A1;
const int PIN_SENSOR_LUZ = A2;
const int PIN_LUCES_ULTRAVIOLETAS = 9;
void setup()
{
  pinMode(LED_RIEGO, OUTPUT);
  pinMode(PIN_LUCES_ULTRAVIOLETAS, OUTPUT);
  lcd.init();
  lcd.backlight();
  lcd.setCursor(1,12);
  lcd.print("Iniciando...");
  delay(1000);
  lcd.clear();
  Serial.begin(9600);
}

void manejarLuzUltravioleta()
{
  int lectura = analogRead(PIN_SENSOR_LUZ);
  float porcentajeLuz = lectura * 100.0 / 1023.0;
  bool encender = porcentajeLuz <= 25.0;

  digitalWrite(PIN_LUCES_ULTRAVIOLETAS, encender ? HIGH : LOW);
}

void ledParpadeando(){
  digitalWrite(LED_RIEGO, HIGH);
  delay(500);
  digitalWrite(LED_RIEGO, LOW);
  delay(500);
}

float sensarYMostrarHumedad(){
  int lectura = analogRead(PIN_SENSOR_HUMEDAD);
  float porcentajeHumedad = lectura * 100.0 / 1023.0;
  Serial.print("La humedad es: ");
  Serial.print(porcentajeHumedad);
  Serial.println(" %");
  return porcentajeHumedad;
}

float sensarYMostrarTemperatura(){
  int lectura = analogRead(PIN_SENSOR_TEMPERATURA);
  float voltaje = lectura * (5.0 / 1023.0);
  float temperatura = (voltaje - 0.5) * 100.0;
  Serial.print("La temperatura es: ");
  Serial.print(temperatura);
  Serial.print((char)176);
  Serial.println("C");
  return temperatura;
}

float sensarYMostrarLuz()
{
  int lectura = analogRead(PIN_SENSOR_LUZ);
  float porcentajeLuz = lectura * 100.0 / 1023.0;
  Serial.print("Iluminacion: ");
  Serial.print(porcentajeLuz);
  Serial.println(" %");
  return porcentajeLuz;
}

void mostrarDatosIntermitente(){
  lcd.setCursor(0, 0);
  lcd.print("H:");
  lcd.print(sensarYMostrarHumedad(), 1);
  lcd.print("%");

  lcd.setCursor(9, 0);
  lcd.print("L:");
  lcd.print(sensarYMostrarLuz(),1);
  lcd.print("%");  

  lcd.setCursor(0, 1);
  lcd.print("T:");
  lcd.print(sensarYMostrarTemperatura(),1);
  lcd.print((char)176);
  lcd.print("C");

  lcd.setCursor(8, 1);
  //Aca va cuando se prende o apaga la bomba de riego;
}

void loop()
{
  ledParpadeando();
  mostrarDatosIntermitente();
  manejarLuzUltravioleta();
}