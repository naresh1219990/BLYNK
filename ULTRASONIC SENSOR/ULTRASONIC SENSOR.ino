
#define BLYNK_TEMPLATE_ID "TMPLU1iV8UAX"
#define BLYNK_DEVICE_NAME "VIRTUAL"

#define BLYNK_FIRMWARE_VERSION        "0.1.0"
#define BLYNK_PRINT Serial
#define USE_NODE_MCU_BOARD

#include "BlynkEdgent.h"

#define echoPin D7
#define trigPin D6

long duration;
int distance; 

void ultrasonic()
{
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);
    duration = pulseIn(echoPin, HIGH);
    distance = duration * 0.034 / 2; //formula to calculate the distance for ultrasonic sensor
    Serial.print("Distance: ");
    Serial.println(distance);
    Serial.println(" cm ");
    Blynk.virtualWrite(V4, distance);
    delay(500);
}
void setup()
{
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT); 
  pinMode(echoPin, INPUT); 
  BlynkEdgent.begin();
  delay(2000); 
}

void loop() 
{
  BlynkEdgent.run();
  ultrasonic();
}
