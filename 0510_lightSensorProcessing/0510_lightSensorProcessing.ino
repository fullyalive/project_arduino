byte lightPin = A0;

void setup() {
  Serial.begin(9600);
}

void loop() {
  int sensorReading = analogRead(lightPin);
  Serial.println(sensorReading);
  Serial.write(0);
  Serial.write(sensorReading);
  delay(50);
  
}
