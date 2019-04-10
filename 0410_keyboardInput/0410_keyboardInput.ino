int ledPin = 13;
int val = 0;

void setup() {
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  val = Serial.read();

  if (val == '1') {
    digitalWrite(ledPin, HIGH);
    Serial.println("LED is ON");
  }
  if (val == '2') {
    digitalWrite(ledPin, LOW);
    Serial.println("LED is OFF");
  }
}
