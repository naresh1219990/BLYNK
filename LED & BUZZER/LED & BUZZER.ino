
// Fill-in information from your Blynk Template here
#define BLYNK_TEMPLATE_ID "TMPLU1iV8UAX"
#define BLYNK_DEVICE_NAME "LED"

#define BLYNK_FIRMWARE_VERSION        "0.1.0"

#define BLYNK_PRINT Serial
//#define BLYNK_DEBUG

#define APP_DEBUG

// Uncomment your board, or configure a custom board in Settings.h
//#define USE_SPARKFUN_BLYNK_BOARD
//#define USE_NODE_MCU_BOARD
//#define USE_WITTY_CLOUD_BOARD
//#define USE_WEMOS_D1_MINI

#include "BlynkEdgent.h"

BLYNK_WRITE(V0)
{
  if(param.asInt()==1){
    digitalWrite(D4, HIGH);
    
  }
  else{
    digitalWrite(D4, LOW);
  }
}
BLYNK_WRITE(V1)
{
  if(param.asInt()==1){
    digitalWrite(D5, HIGH);
    
  }
  else{
    digitalWrite(D5, LOW);
  }
}

BLYNK_CONNECTED()
{
  Blynk.syncVirtual(V0); 
  Blynk.syncVirtual(V1);    
}

void setup()
{
  pinMode(D4, OUTPUT); // Initialise digital pin 2 as an output pin
  pinMode(D5, OUTPUT);
  Serial.begin(115200);
  delay(100);

  BlynkEdgent.begin();
}

void loop() {
  BlynkEdgent.run();
}
