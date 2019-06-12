int xPin = 0;
int yPin = 1;
int zPin = 2;

int x = 0;
int y = 0;
int z = 0;

int minValX = 396; // finding min and max values using Task 40
int maxValX = 598;
int minValY = 392;
int maxValY = 594;
int minValZ = 395;
int maxValZ = 592;

void setup() {
 Serial.begin(9600);
}

void loop() {
  
  x = analogRead(xPin);
  y = analogRead(yPin);
  z = analogRead(zPin);

  // convert read values to degrees -90 to 90 - Needed for atan2
  int xAng = map(x, minValX, maxValX, -90, 90);
  int yAng = map(y, minValY, maxValY, -90, 90);
  int zAng = map(z, minValZ, maxValZ, -90, 90);

  // calculate 360deg values like so: atan2(-yAng, -zAng), atan2 outputs the value of -PI to PI (radians),
  // We are then converting the radians to degrees
  x = RAD_TO_DEG * (atan2(-yAng, -zAng) + PI); // RAD_TO_DEG = Radius / moving (around 57.29( distance, PI = 3.14
  y = RAD_TO_DEG * (atan2(-xAng, -zAng) + PI);
  z = RAD_TO_DEG * (atan2(-yAng, -xAng) + PI);

  // Output the calculations
  Serial.print(x);
  Serial.print(",");
   Serial.print(y);
  Serial.print(",");
   Serial.print(z);
  Serial.println();

  delay(100);
}
