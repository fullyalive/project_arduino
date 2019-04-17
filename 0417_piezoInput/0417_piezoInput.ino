int ledPin = 13;
int piezoSensor = 0; // Analog 0 Pin
byte val = 0;
int statePin = LOW;
int THRESHOLD = 250; // remove noise values

void setup() {
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  val = analogRead(piezoSensor);
  if (val >= THRESHOLD) {
    statePin = !statePin; // toggle statePin value (turn on/off)
    digitalWrite(ledPin, statePin);
    Serial.println(val);
  }
  delay(10); // to avoid overloading the serial port
}
