int irPin = 0;
void setup()
{
  analogReference(DEFAULT);
  Serial.begin(9600);
  pinMode (irPin, INPUT);
}

void loop()
{
  int raw = analogRead(irPin );
  Serial.println(raw); int irPin = 0;
  void setup()
  {
    analogReference(DEFAULT);
    Serial.begin(9600);
    pinMode (irPin, INPUT);
  }

  void loop()
  {
    int raw = analogRead(irPin );
    Serial.println(raw);
  }
