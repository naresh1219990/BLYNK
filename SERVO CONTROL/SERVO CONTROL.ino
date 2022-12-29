#define BLYNK_TEMPLATE_ID "TMPLU1iV8UAX"
#define BLYNK_DEVICE_NAME "VIRTUAL"

#define BLYNK_FIRMWARE_VERSION        "0.1.0"

#define BLYNK_PRINT Serial
#define USE_NODE_MCU_BOARD

#include "BlynkEdgent.h"
#include<Servo.h>
Servo servo;

BLYNK_WRITE(V2)
{
  int s0 = param.asInt(); 
  servo.write(s0);
  Blynk.virtualWrite(V3, s0);
}

void setup()
{
  Serial.begin(9600);
  servo.attach(D2);
  BlynkEdgent.begin();
  delay(2000); 
}

void loop() 
{
  BlynkEdgent.run();
}
