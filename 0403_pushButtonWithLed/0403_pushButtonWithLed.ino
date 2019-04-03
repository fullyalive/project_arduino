int pushButton = 9;
int led = 13; // pin Number
int buttonState = 0;

void setup() {
  Serial.begin(9600);
  pinMode(pushButton, INPUT);
  pinMode(led, OUTPUT);
}

void loop() {
  buttonState = digitalRead(pushButton);
  Serial.print("PushButton = ");
  Serial.println(buttonState);
  delay(50);

  if (buttonState == 1) {
    digitalWrite(led, HIGH);
  } else {
    digitalWrite(led, LOW);
  }
}
