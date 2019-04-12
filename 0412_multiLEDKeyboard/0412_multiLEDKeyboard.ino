
int led1 = 11;
int led2 = 12;
int led3 = 13;
int val = 0;

void setup() {
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  val = Serial.read();

  if (val == '1') {
    digitalWrite(led1, HIGH);
    Serial.println("LED is ON");
  }
  if (val == '2') {
    digitalWrite(led1, LOW);
    Serial.println("LED is OFF");
  }
  if (val == '3') {
    digitalWrite(led2, HIGH);
    Serial.println("LED is ON");
  }
  if (val == '4') {
    digitalWrite(led2, LOW);
    Serial.println("LED is OFF");
  }
  if (val == '5') {
    digitalWrite(led3, HIGH);
    Serial.println("LED is ON");
  }
  if (val == '6') {
    digitalWrite(led3, LOW);
    Serial.println("LED is OFF");
  }
}
