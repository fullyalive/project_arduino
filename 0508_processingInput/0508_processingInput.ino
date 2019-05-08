int ledPin = 9;
void setup()
{
  Serial.begin(9600); // Receiving signal from Serial communication
  pinMode(ledPin, OUTPUT);
}
void loop() {
  byte brightness;
  if (Serial.available()) { // check if data has been sent from the computer:
    brightness = Serial.read(); // read the most recent byte (which will be from 0 to 255):
    analogWrite(ledPin, brightness);
  }
}
