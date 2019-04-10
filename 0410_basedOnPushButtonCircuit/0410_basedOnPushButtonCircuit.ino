int led = 9;
int brightness = 0;
int fadeAmount1 = 5;
int fadeAmount2 = 20;
int fadeAmount3 = 40;
int pushButton1 = 8;
int pushButton2 = 7;
int pushButton3 = 6;

int buttonState1 = 0;
int buttonState2 = 0;
int buttonState3 = 0;

void setup() {
  pinMode(pushButton1, INPUT);
  pinMode(pushButton2, INPUT);
  pinMode(pushButton3, INPUT);
  pinMode(led, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  buttonState1 = digitalRead(pushButton1);
  buttonState2 = digitalRead(pushButton2);
  buttonState3 = digitalRead(pushButton3);

  Serial.print("PushButton1 = ");
  Serial.print(buttonState1);
  Serial.print("PushButton2 = ");
  Serial.print(buttonState2);
  Serial.print("PushButton3 = ");
  Serial.print(buttonState3);
  delay(5);

  if (buttonState1 == 1) {
    analogWrite(led, brightness);
    brightness += fadeAmount1;

    if (brightness == 0 || brightness == 255) {
      fadeAmount1 = -fadeAmount1;
    }
    delay(30);
  }

  if (buttonState2 == 1) {
    analogWrite(led, brightness);
    brightness += fadeAmount2;
    if (brightness == 0 || brightness == 255) {
      fadeAmount2 = -fadeAmount2;
    }
    delay(30);
  }

  if (buttonState3 == 1) {
    analogWrite(led, brightness);
    brightness += fadeAmount3;
    if (brightness == 0 || brightness == 255) {
      fadeAmount3 = -fadeAmount3;
    }
    delay(30);
  }
}
