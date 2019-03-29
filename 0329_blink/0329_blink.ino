int led = 13; // Set the value "led" is number 13

void setup() {
  // initialize digital pin LED_BUILTIN as an output(actuation) at 13 pin
  pinMode(led, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  digitalWrite(led, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(100);                       // wait for a second
  digitalWrite(led, LOW);    // turn the LED off by making the voltage LOW
  delay(100);                       // wait for a second
}
