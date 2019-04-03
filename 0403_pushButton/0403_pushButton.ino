int pushButton = 9;
int buttonState = 0;  // variable for reading the pushbutton status

void setup() {
  Serial.begin(9600);
  pinMode(pushButton, INPUT);
}

void loop() {
  buttonState = digitalRead(pushButton);
  Serial.print("PushButton = ");
  Serial.println(buttonState);
  delay(1000);
}
