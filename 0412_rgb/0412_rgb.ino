int redLEDPin = 11;
int greenLEDPin = 10;
int blueLEDPin = 9;

void setup() {
  pinMode
  (redLEDPin, OUTPUT);
  pinMode
  (greenLEDPin, OUTPUT);
  pinMode
  (blueLEDPin, OUTPUT);

}
void loop() {
  setColor(255, 0, 0); // red
  delay(1000);
  setColor(0, 255, 0); // green
  delay(1000);
  setColor(0, 0, 255); // blue
  delay(1000);
  setColor(255, 255, 0); // yellow
  delay(1000);
  setColor(0, 255, 255); // aqua
  delay(1000);
  setColor(80, 0, 80); // magenta
  delay(1000);
}

// Declaring a function
void setColor(int red, int green, int blue) {
  analogWrite(redLEDPin, 255 - red);
  analogWrite(greenLEDPin, 255 - green);
  analogWrite(blueLEDPin, 255 - blue);
}
