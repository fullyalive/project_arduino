int pushButton1 = 8;
int pushButton2 = 7;
int pushButton3 = 6;

int buttonState1 = 0;
int buttonState2 = 0;
int buttonState3 = 0;

void setup() {
  Serial.begin(9600);

  pinMode(pushButton1, INPUT);
  pinMode(pushButton2, INPUT);
  pinMode(pushButton3, INPUT);
}

void loop() {
  buttonState1 = digitalRead(pushButton1);
  buttonState2 = digitalRead(pushButton2);
  buttonState3 = digitalRead(pushButton3);

  Serial.print("PushButton1 = ");
  Serial.print(buttonState1);
  Serial.print("  ");
  Serial.print("PushButton2 = ");
  Serial.print(buttonState2);
  Serial.print("  ");
  Serial.print("PushButton3 = ");
  Serial.println(buttonState3);

  delay(5);
}
