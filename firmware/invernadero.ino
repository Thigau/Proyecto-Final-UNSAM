#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

const int LED_RIEGO = 8;
const int PIN_SENSOR_HUMEDAD = A0;
const int PIN_SENSOR_TEMPERATURA = A1;
const int PIN_SENSOR_LUZ = A2;
const int PIN_LUCES_ULTRAVIOLETAS = 9;
const int PIN_BOMBA_AGUA = 13;

const unsigned long DURACION_INICIO_MS = 1000;
const unsigned long INTERVALO_PARPADEO_MS = 500;
const unsigned long INTERVALO_MUESTREO_MS = 1000;

unsigned long inicioPantalla = 0;
unsigned long ultimoCambioLed = 0;
unsigned long ultimoMuestreo = 0;

bool pantallaInicioActiva = true;
bool estadoLedRiego = false;

bool esperar(unsigned long &inicio, unsigned long duracion){
  unsigned long ahora = millis();

  if (ahora - inicio < duracion){
    return false;
  }

  inicio = ahora;
  return true;
}

void setup(){
  pinMode(PIN_BOMBA_AGUA, OUTPUT);
  pinMode(LED_RIEGO, OUTPUT);
  pinMode(PIN_LUCES_ULTRAVIOLETAS, OUTPUT);
  lcd.init();
  lcd.backlight();
  lcd.setCursor(1,12);
  lcd.print("Iniciando...");
  Serial.begin(9600);

  unsigned long ahora = millis();
  inicioPantalla = ahora;
  ultimoCambioLed = ahora;
  ultimoMuestreo = ahora;
}

void manejarPantallaInicio(){
  if (pantallaInicioActiva && esperar(inicioPantalla, DURACION_INICIO_MS)){
    lcd.clear();
    pantallaInicioActiva = false;

    estadoLedRiego = true;
    digitalWrite(LED_RIEGO, HIGH);
    ultimoCambioLed = millis();
  }
}

void manejarLuzUltravioleta(float porcentajeLuz){
  bool encender = porcentajeLuz <= 25.0;

  digitalWrite(PIN_LUCES_ULTRAVIOLETAS, encender ? HIGH : LOW);
}

void actualizarLedRiego(){
  if (pantallaInicioActiva){
    return;
  }

  if (esperar(ultimoCambioLed, INTERVALO_PARPADEO_MS)){
    estadoLedRiego = !estadoLedRiego;
    digitalWrite(LED_RIEGO, estadoLedRiego ? HIGH : LOW);
  }
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

float sensarYMostrarLuz(){
  int lectura = analogRead(PIN_SENSOR_LUZ);
  float porcentajeLuz = lectura * 100.0 / 1023.0;
  Serial.print("Iluminacion: ");
  Serial.print(porcentajeLuz);
  Serial.println(" %");
  return porcentajeLuz;
}

bool prendioBomba(float luz, float temp, float hum){
  return luz < 80 && temp > 15 && hum < 30;
}

void mostrarDatosIntermitente(float humedad, float temperatura, float luz, bool bombaEncendida){
  lcd.setCursor(0, 0);
  lcd.print("H:");
  lcd.print(humedad, 1);
  lcd.print("%");

  lcd.setCursor(9, 0);
  lcd.print("L:");
  lcd.print(luz,1);
  lcd.print("%");  

  lcd.setCursor(0, 1);
  lcd.print("T:");
  lcd.print(temperatura,1);
  lcd.print((char)176);
  lcd.print("C");

  lcd.setCursor(9, 1);
  lcd.print("B:");
  lcd.print(bombaEncendida ? "ON " : "OFF");
}

void actualizarSistema(){
  if (pantallaInicioActiva || !esperar(ultimoMuestreo, INTERVALO_MUESTREO_MS)){
    return;
  }

  float humedad = sensarYMostrarHumedad();
  float temperatura = sensarYMostrarTemperatura();
  float luz = sensarYMostrarLuz();
  bool bombaEncendida = prendioBomba(luz, temperatura, humedad);

  digitalWrite(PIN_BOMBA_AGUA, bombaEncendida ? HIGH : LOW);
  manejarLuzUltravioleta(luz);
  mostrarDatosIntermitente(humedad, temperatura, luz, bombaEncendida);
}

void loop(){
  manejarPantallaInicio();
  actualizarLedRiego();
  actualizarSistema();
}
