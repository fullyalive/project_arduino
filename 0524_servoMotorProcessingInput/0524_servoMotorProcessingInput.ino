#include <Servo.h>

int x;
Servo servo1;
void setup() {
  Serial.begin(9600);
  servo1.attach(9);
}

void loop() {
  if (Serial.available() > 0) {
    x = Serial.read();
    x = map(x, 0, 255, 0, 179);
    //map() convert the x value (0-255) to (0-179) for servo motor (as you know it can rotate 180 degree)
    servo1.write(x);
  }
}
