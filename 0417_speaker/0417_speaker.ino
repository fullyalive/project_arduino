int speakerPin = 12;

int numTones = 13;

int tones[] = {261, 277, 294, 311, 330, 349, 370, 392, 415, 440, 466, 494, 524};

void setup() {
  for (int i = 0; i < numTones; i++) {
    tone(speakerPin, tones[i]);
    delay(500);
  }
  noTone(speakerPin);
}

void loop() {

}
