int value = 0;

void setup() {
  Serial.begin(9600);
}

void loop() {
  value = readCapacitivePin(3);
  Serial.println(value);
}
