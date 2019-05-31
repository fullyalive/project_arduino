int irPin = 0;
void setup() {
  analogReference(DEFAULT);
  Serial.begin(9600);
  pinMode(irPin, INPUT);
}

void loop() {
  int raw = analogRead(irPin);
  int cm = 4800 / (raw - 20);
  // Distance (cm) = 4800/(SensorValue - 20)

  Serial.println(cm);
}
