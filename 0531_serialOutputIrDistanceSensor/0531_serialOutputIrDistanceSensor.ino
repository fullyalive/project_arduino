int irPin = 0;

void setup() {
  analogReference(DEFAULT);
  Serial.begin(9600);
  pinMode(irPin, INPUT);
}

void loop() {
  int raw = analogRead(irPin);

  int range = map(raw, 0, 1024, 0, 10);
  switch (range) {
    case 0:
      Serial.println("Range 11");
      break;
    case 1:
      Serial.println("Range 10");
      break;
    case 2:
      Serial.println("Range 9");
      break;
    case 3:
      Serial.println("Range 8");
      break;
    case 4:
      Serial.println("Range 7");
      break;
    case 5:
      Serial.println("Range 6");
      break;
    case 6:
      Serial.println("Range 5");
      break;
    case 7:
      Serial.println("Range 4");
      break;
    case 8:
      Serial.println("Range 3");
      break;
    case 9:
      Serial.println("Range 2");
      break;
    case 10:
      Serial.println("Range 1");
      break;
  }
}
