#define BLYNK_TEMPLATE_ID "TMPLU1iV8UAX"
#define BLYNK_DEVICE_NAME "VIRTUAL"

#define BLYNK_FIRMWARE_VERSION "0.1.0"
#define BLYNK_PRINT Serial
#define USE_NODE_MCU_BOARD

#include "BlynkEdgent.h"

#define ledPin D0
#define IRPin D1 

int IRSensor;
WidgetLED led(V4);

void sendSensor()
{
  IRSensor = digitalRead(IRPin);
  
  if (IRSensor == LOW )
  {
    Blynk.notify("Alert! someone is there inside the house");  
    digitalWrite(ledPin, HIGH);
    Blynk.logEvent("fire");
    Blynk.virtualWrite(V5, 1);
    Serial.println("fIRE DEDUCTED");
    led.on();
  }
  else
  {
    digitalWrite(ledPin, LOW);
    Blynk.virtualWrite(V5, 0);
    Serial.println("everything safe");
    led.off();
  }   
}

void setup()
{
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
  pinMode(IRPin, INPUT);
  BlynkEdgent.begin();
  timer.setInterval(1000L, sendSensor); 
}

void loop() 
{
  BlynkEdgent.run();
  timer.run();        // Initiates SimpleTimer
}
