int led = 9; // thie pin that the LED is attached to
int brightness = 0; // how bright the LED is
int fadeAmount = 5; // how many points to fade the LED by

void setup() {
  pinMode(led, OUTPUT); // declare pin 9 to be an output
}

void loop() {
  analogWrite(led, brightness); // set the birhgtness of pin 9
  brightness += .5*fadeAmount; // change brightness for next time through loop

  if (brightness == 00 || brightness == 255) { // reverse the direction of the fading;
    fadeAmount = -fadeAmount;
  }

  delay(30); // wait for 30 milliseconds to see the dimming effect
}
