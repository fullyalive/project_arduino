int speakerPin = 12;

// scale

int stop = 0;

int midC = 261;
int midC2 = 277;
int midD = 294;
int midD2 = 311;
int midE = 330;
int midF = 349;
int midF2 = 370;
int midG = 392;
int midG2 = 415;
int midA = 440;
int midB = 466;
int midB2 = 494;
int midB3 = 524;

int val = 0;

void setup() {
  Serial.begin(9600);
}

void loop() {
  val = Serial.read();

  if(val != -1) {
    if (val == 'a') {
      tone(speakerPin, midC);
      delay(5);
    }
    if (val == 'w') {
      tone(speakerPin, midC2);
      delay(5);
    }
     if (val == 's') {
      tone(speakerPin, midD);
      delay(5);
    }
     if (val == 'e') {
      tone(speakerPin, midD2);
      delay(5);
    }
     if (val == 'd') {
      tone(speakerPin, midE);
      delay(5);
    }
     if (val == 'f') {
      tone(speakerPin, midF);
      delay(5);
    }
     if (val == 't') {
      tone(speakerPin, midF2);
      delay(5);
    }
     if (val == 'g') {
      tone(speakerPin, midG);
      delay(5);
    }
     if (val == 'y') {
      tone(speakerPin, midG2);
      delay(5);
    }
     if (val == 'h') {
      tone(speakerPin, midA);
      delay(5);
    }
     if (val == 'u') {
      tone(speakerPin, midB);
      delay(5);
    }
     if (val == 'j') {
      tone(speakerPin, midB2);
      delay(5);
    }
     if (val == 'k') {
      tone(speakerPin, midB3);
      delay(5);
    }
  }
}
