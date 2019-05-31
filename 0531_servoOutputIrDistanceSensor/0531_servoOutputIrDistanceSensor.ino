#include <Servo.h>
int servoPin = 9;
Servo servo1; // you can control 8 motors at the same time. We have only one to control

const int numReadings = 10;
int readings[numReadings];
int index = 0;
int total = 0;
int average = 0;
int inputPin = A0;

void setup() {
  analogReference(DEAFULT);
  Serial.begin(9600);
  for (int thisReading = 0; thisReading < numReadings; thisReading++)
    readings[thisReading] = 0;

  servo1.attach(servoPin);
}

void loop() {
  total = total - readings[index];
  readings[index] = analogRead(inputPin);

  total = total + readings[index];
  index = index + 1;

  if (index >= numReadings)
    index = 0;

  average = total / numReadings;
  int range = map(average, 0, 800, 0, 180);
  Serial.println(range);

  servo1.write(range);
  // delay(1500);
}
