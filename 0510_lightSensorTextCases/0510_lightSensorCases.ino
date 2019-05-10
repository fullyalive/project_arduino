byte lightPin = A0;
const int sensorMin = 90;
const int sensorMax = 750;

void setup() {
  Serial.begin(9600);
}

void loop() {
  int sensorReading = analogRead(lightPin);
  int range = map(sensorReading, sensorMin, sensorMax, 0, 3);

  switch (range) {
    case 0:
      Serial.println("dark");
      break;
    case 1:
      Serial.println("dim");
      break;
    case 2:
      Serial.println("medium");
      break;
    case 3:
      Serial.println("bright");
      break;
  }
}
