#include <Servo.h>
int servoPin = 9;
Servo servo1; //you can control 8 servo pins seperately at the same time. This is the 1st
int angle = 0; // servo position in degrees
void setup() {
  servo1.attach(servoPin);
}
void loop() {
  //from 0 to 180 degree
  for (angle = 0; angle < 180; angle++) {
    servo1.write(angle);
    delay(15);
  }
  //from 180 to 0 degree
  for (angle = 180; angle > 0; angle--) {
    servo1.write(angle);
    delay(15);
  }
}
