#include "DHT.h"
#include <LiquidCrystal_I2C.h> // Debe descargar la Libreria que controla el I2C
#include<Wire.h>
#define DHTPIN 2     // Digital pin connected to the DHT sensor
#define DHTTYPE DHT22   // DHT 22  (AM2302), AM2321
#include <Adafruit_Sensor.h>
#include <Adafruit_BMP085_U.h>
Adafruit_BMP085_Unified bmp = Adafruit_BMP085_Unified(10085);

LiquidCrystal_I2C lcd(0x27,16,2);
DHT dht(DHTPIN, DHTTYPE);

const int FOTOPIN=A0;
int valorSensor=0;
int contador=0;
void setup() {
  
  pinMode(FOTOPIN,INPUT);
  Serial.begin(9600);
  lcd.init();
  lcd.backlight();
  dht.begin();
  bmp.begin();
  }

void loop() {
float ms = 60000;
//float ms=1000;
float minutos=0.125;
float delta = 1.0;
float h = dht.readHumidity();
  // Read temperature as Celsius (the default)
float t = dht.readTemperature();
valorSensor=analogRead(FOTOPIN);
    if (isnan(h) || isnan(t) ) {
    Serial.println(F("Failed to read from DHT sensor!"));
    return;
  }
//float tempera;
//  bmp.getTemperature(&tempera);
float presion;
  bmp.getPressure(&presion);
//float seaLevelPressure = SENSORS_PRESSURE_SEALEVELHPA;
//float altitude;
//altitude=bmp.pressureToAltitude(seaLevelPressure,presion/100);
  Serial.print(contador);
  Serial.print("\t");
  Serial.print(t-delta);
  Serial.print("\t");
  Serial.print(h);
  Serial.print("\t");
  Serial.print(presion/100);
  Serial.print("\t");
  Serial.println(valorSensor);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("T=");
  lcd.print(t-delta);
  lcd.print(" P=");
  lcd.print(presion/100);
  lcd.setCursor(0,1);
  lcd.print("H=");
  lcd.print(h);
  lcd.print(" % I=");
  lcd.print(valorSensor);
// Wait a few seconds between measurements.
contador++;
delay(minutos*ms);
}
