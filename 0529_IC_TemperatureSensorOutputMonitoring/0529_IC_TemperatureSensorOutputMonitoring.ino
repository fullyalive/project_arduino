float tempC;
int tempPin = 0;

void setup() {
  Serial.begin(9600);
}

void loop() {
  tempC = analogRead(tempPin);
  // read the Voltage value from the sensor

  tempC = (3.3 * tempC * 100.0) / 1024.0;
  // Convert the analog data to temperature,
  // Use 3.3V & 1 Degree = 0.01 V
  // Read data from analog pin, range (0-1023)

  Serial.print(tempC);
  Serial.println(" Degrees");
  delay(1000);
}
