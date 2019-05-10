byte lightPin = A0;
int sensorMin = 0;
int sensorMax = 600;

int led1 = 5;
int led2 = 6;
int led3 = 7;

void setup() {
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  int sensorReading = analogRead(lightPin);
  int range = map(sensorReading, sensorMin, sensorMax, 0, 3);

  switch (range) {
    case 0:
      Serial.println("dark");
      digitalWrite(led1, HIGH);
      digitalWrite(led2, HIGH);
      digitalWrite(led3, HIGH);
      break;
    case 1:
      Serial.println("dim");
      digitalWrite(led1, HIGH);
      digitalWrite(led2, HIGH);
      digitalWrite(led3, LOW);
      break;
    case 2:
      Serial.println("medium");
      digitalWrite(led1, HIGH);
      digitalWrite(led2, LOW);
      digitalWrite(led3, LOW);
      break;
    case 3:
      Serial.println("bright");
      digitalWrite(led1, LOW);
      digitalWrite(led2, LOW);
      digitalWrite(led3, LOW);
      break;
  }
}
