//--- 진동센서 SW-18010p Test ---//

int ledPin = 13; // 이후 LED 8x8 디스플레이로 변경
int VIB = 2;
int vibration_threshold = 1000;
int SOUND_SENSOR = A0;
int sound_threshold = 22; // 감도조절
//int Sound_value;

const int sampleWindow = 50; // Sample window width in mS (50 mS = 20Hz)
unsigned int sample;

void setup() {
  Serial.begin(9600); //시리얼통신 설정 9600
  Serial.println("----------------------vibration demo------------------------");
  pinMode(SOUND_SENSOR, INPUT);
  pinMode(VIB, INPUT); //센서핀 입력
  pinMode(ledPin, OUTPUT); // 이후 LED 8x8 디스플레이로 변경

}
void loop() {
  long vibration_value = TP_init();
  delay(50);
  //  Serial.print("vibration_value = ");
  //  Serial.println(vibration_value);
  //  if (vibration_value > vibration_threshold) {
  //    Serial.println("vibration_alert");
  //    // 경고 메시지, 이후 LED 8x8 디스플레이로 변경
  //  }

  //  Sound_value = analogRead(A0); // Analog PIN A0에서 입력값을 읽어와서 Sensor_value에 저장
  //  Serial.print("sound_value : ");
  //  Serial.println(sound_value); // 시리얼 모니터에 감도표시
  //  delay(200);
  //
  //  if (sound_value >= sound_threshold) {
  //    Serial.println("sound_alert");
  //  }

  unsigned long startMillis = millis(); // Start of sample window
  unsigned int peakToPeak = 0;   // peak-to-peak level

  unsigned int signalMax = 0;
  unsigned int signalMin = 1024;

  // collect data for 50 mS
  while (millis() - startMillis < sampleWindow)
  {
    sample = analogRead(A0);
    if (sample < 1024)  // toss out spurious readings
    {
      if (sample > signalMax)
      {
        signalMax = sample;  // save just the max levels
      }
      else if (sample < signalMin)
      {
        signalMin = sample;  // save just the min levels
      }
    }
  }
  peakToPeak = signalMax - signalMin;  // max - min = peak-peak amplitude
  double sound_value = (peakToPeak * 3.3) / 1024;  // convert to volts

  Serial.println(sound_value);

}

long TP_init() {
  delay(10);
  long vibration_value = pulseIn (VIB, HIGH);
  return vibration_value;
}
