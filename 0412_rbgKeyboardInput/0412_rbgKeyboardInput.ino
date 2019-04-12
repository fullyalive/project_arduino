int redLEDPin = 11;
int greenLEDPin = 10;
int blueLEDPin = 9;
int redSwitchPin = 7;
int greenSwitchPin = 6;
int blueSwitchPin = 5;
int red = 0;
int green = 0;
int blue = 0;
int val = 0;

void setup() {
  pinMode(redLEDPin, OUTPUT);
  pinMode(greenLEDPin, OUTPUT);
  pinMode(blueLEDPin, OUTPUT);
  pinMode(redSwitchPin, INPUT);
  pinMode(greenSwitchPin, INPUT);
  pinMode(blueSwitchPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  val = Serial.read();
  if (val == '0') {
    red = 0;
    green = 0;
    blue = 0;
    setColor(red, green, blue);
    Serial.print("LED is OFF");
  }
  
  if (val == '1') {
    red++;
    setColor(red, green, blue);
    Serial.print("Red value = ");
    Serial.print(red);
    Serial.print(" Green value = ");
    Serial.print(green);
    Serial.print(" Blue value = ");
    Serial.println(blue);
    delay(5);
    if (red > 255) {
      red = 0;
    }
  }

  if (val == '2') {
    green++;
    setColor(red, green, blue);
    Serial.print("Red value = ");
    Serial.print(red);
    Serial.print(" Green value = ");
    Serial.print(green);
    Serial.print(" Blue value = ");
    Serial.println(blue);
    delay(5);

    if (green > 255) {
      green = 0;
    }
  }

  if (val == '3') {
    blue++;
    setColor(red, green, blue);
    Serial.print("Red value = ");
    Serial.print(red);
    Serial.print(" Green value = ");
    Serial.print(green);
    Serial.print(" Blue value = ");
    Serial.println(blue);
    delay(5);

    if (blue > 255) {
      blue = 0;
    }
    delay(10);
  }
}

void setColor(int red, int green, int blue) {
  analogWrite(redLEDPin, 255 - red);
  analogWrite(greenLEDPin, 255 - green);
  analogWrite(blueLEDPin, 255 - blue);
}
