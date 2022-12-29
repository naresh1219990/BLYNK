
#define BLYNK_TEMPLATE_ID "TMPLU1iV8UAX"
#define BLYNK_DEVICE_NAME "VIRTUAL"

#define BLYNK_FIRMWARE_VERSION "0.1.0"
#define BLYNK_PRINT Serial
#define USE_NODE_MCU_BOARD

#include "BlynkEdgent.h"
#include "DHT.h"
#define DHTPIN D8 
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);
float t, h;

void sendSensor()
{
  h = dht.readHumidity();
  t = dht.readTemperature();  
  Blynk.virtualWrite(V5, h);
  Blynk.virtualWrite(V6, t);
  Serial.println("Current humidity = ");
  Serial.print(h);
  Serial.print("%  ");
  Serial.println("temperature = ");
  Serial.print(t); 
  Serial.print("C  ");
  delay(5000L);
}

void setup()
{
  Serial.begin(9600);
  dht.begin();
  BlynkEdgent.begin();
  delay(2000); 
  timer.setInterval(1000L, sendSensor); 
}

void loop() 
{
  BlynkEdgent.run();
  timer.run(); // Initiates SimpleTimer
}
