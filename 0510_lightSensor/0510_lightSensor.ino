byte lightPin = A0;

void setup() {
  Serial.begin(9600);
}

void loop() {
  int sensorReading = analogRead(lightPin);
  Serial.println(sensorReading);

  if (sensorReading > 400) {
    Serial.print("너무 밝습니다 ");
  } else if (sensorReading < 200) {
    Serial.print("너무 어두워요 ");
  }
}
