/* 8X8 DISPLAY */
#include "LedControl.h"
LedControl lc = LedControl(12, 11, 10, 1); // DIN, CLK, CS, 주소

/* SOUND PART */
int SOUND_SENSOR = A0;
int sound_threshold = 1; // 소리 임계치
const int sampleWindow = 50; // Sample window width in mS (50 mS = 20Hz)
unsigned int sample;

/* VIBRATION PART*/
int VIBRATION_SENSOR = A1;
int vibration_threshold = 10; // 진동 임계치

/* GAS PART */
int MQ_2_SENSOR = A2; // 스모그, 메탄, 일산화탄소 감
int MQ_7_SENSOR = A3; // 일산화탄소 감지
int mq2_threshold = 550; // mq2 임계치
int mq7_threshold = 300; // mq7 임계치

int gap = 500;
int repNum = 3;

void setup() {
  Serial.begin(9600); //시리얼통신 설정 9600
  lc.shutdown(0, false);    // 절전모드 해제
  lc.setIntensity(0, 15);   // 밝기설정
  lc.clearDisplay(0);      // 화면정리
  pinMode(SOUND_SENSOR, INPUT);
  pinMode(VIBRATION_SENSOR, INPUT);
  pinMode(MQ_2_SENSOR, INPUT);
  pinMode(MQ_7_SENSOR, INPUT);
}

void loop() {

  /* SOUND_REACT */

  unsigned long startMillis = millis();
  unsigned int peakToPeak = 0;
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
    Serial.print("Sound_value : ");
    Serial.println(sound_value);
    if (sound_value > sound_threshold) {
      for (int i = 0; i < repNum; i++) {
        soundReact_1();
        soundReact_2();
        ledSet();
      }
    } else {
      ledSet();
    }

  /* VIBRATION_REACT */

  long vibration_value = TP_init();
  Serial.print("vibration_value = ");
  Serial.println(vibration_value);
  if (vibration_value > vibration_threshold) {
    for (int i = 0; i < repNum; i++) {
      delay(gap);
      vibrationReact_1();
      vibrationReact_1();
      ledSet();
    }
  } else {
    ledSet();
  }

  /* GAS_REACT */
  int mq2_value = analogRead(A2);
  int mq7_value = analogRead(A3);
    Serial.print("mq2_value : ");
    Serial.println(mq2_value);
    Serial.print("mq7_value: ");
    Serial.println(mq7_value);
  
    if (mq2_value > mq2_threshold) {
      for (int i = 0; i < repNum; i++) {
        gasReact_1();
        gasReact_2();
        ledSet();
      }
    } else if (mq7_value > mq7_threshold) {
      for (int i = 0; i < repNum; i++) {
        gasReact_1();
        gasReact_2();
        ledSet();
      }
    } else {
      ledSet();
    }
}

void soundReact_1() {
  lc.setLed(0, 1, 3, true);
  lc.setLed(0, 2, 2, true);
  lc.setLed(0, 2, 3, true);
  lc.setLed(0, 3, 0, true);
  lc.setLed(0, 3, 1, true);
  lc.setLed(0, 3, 2, true);
  lc.setLed(0, 3, 3, true);
  lc.setLed(0, 3, 5, true);
  lc.setLed(0, 3, 7, true);
  lc.setLed(0, 4, 0, true);
  lc.setLed(0, 4, 1, true);
  lc.setLed(0, 4, 2, true);
  lc.setLed(0, 4, 3, true);
  lc.setLed(0, 4, 6, true);
  lc.setLed(0, 5, 2, true);
  lc.setLed(0, 5, 3, true);
  lc.setLed(0, 5, 5, true);
  lc.setLed(0, 5, 7, true);
  lc.setLed(0, 6, 3, true);
}

void soundReact_2() {
  lc.setLed(0, 1, 3, true);
  lc.setLed(0, 2, 2, true);
  lc.setLed(0, 2, 3, true);
  lc.setLed(0, 3, 0, true);
  lc.setLed(0, 3, 1, true);
  lc.setLed(0, 3, 2, true);
  lc.setLed(0, 3, 3, true);
  lc.setLed(0, 4, 0, true);
  lc.setLed(0, 4, 1, true);
  lc.setLed(0, 4, 2, true);
  lc.setLed(0, 4, 3, true);
  lc.setLed(0, 4, 6, true);
  lc.setLed(0, 5, 2, true);
  lc.setLed(0, 5, 3, true);
  lc.setLed(0, 6, 3, true);
}

void vibrationReact_1() {
  lc.setLed(0, 0, 6, true);
  lc.setLed(0, 1, 3, true);
  lc.setLed(0, 1, 5, true);
  lc.setLed(0, 2, 2, true);
  lc.setLed(0, 2, 3, true);
  lc.setLed(0, 2, 6, true);
  lc.setLed(0, 3, 0, true);
  lc.setLed(0, 3, 1, true);
  lc.setLed(0, 3, 2, true);
  lc.setLed(0, 3, 3, true);
  lc.setLed(0, 3, 5, true);
  lc.setLed(0, 4, 0, true);
  lc.setLed(0, 4, 1, true);
  lc.setLed(0, 4, 2, true);
  lc.setLed(0, 4, 3, true);
  lc.setLed(0, 4, 6, true);
  lc.setLed(0, 5, 2, true);
  lc.setLed(0, 5, 3, true);
  lc.setLed(0, 5, 5, true);
  lc.setLed(0, 6, 3, true);
  lc.setLed(0, 6, 6, true);
  lc.setLed(0, 7, 5, true);
}

void vibrationReact_2() {
  lc.setLed(0, 0, 6, true);
  lc.setLed(0, 1, 3, true);
  lc.setLed(0, 1, 7, true);
  lc.setLed(0, 2, 2, true);
  lc.setLed(0, 2, 3, true);
  lc.setLed(0, 2, 6, true);
  lc.setLed(0, 3, 0, true);
  lc.setLed(0, 3, 1, true);
  lc.setLed(0, 3, 2, true);
  lc.setLed(0, 3, 3, true);
  lc.setLed(0, 3, 7, true);
  lc.setLed(0, 4, 0, true);
  lc.setLed(0, 4, 1, true);
  lc.setLed(0, 4, 2, true);
  lc.setLed(0, 4, 3, true);
  lc.setLed(0, 4, 6, true);
  lc.setLed(0, 5, 2, true);
  lc.setLed(0, 5, 3, true);
  lc.setLed(0, 5, 7, true);
  lc.setLed(0, 6, 3, true);
  lc.setLed(0, 6, 6, true);
  lc.setLed(0, 7, 7, true);
}

void gasReact_1() {
  lc.setLed(0, 1, 0, true);
  lc.setLed(0, 2, 1, true);
  lc.setLed(0, 2, 2, true);
  lc.setLed(0, 2, 3, true);
  lc.setLed(0, 3, 3, true);
  lc.setLed(0, 3, 4, true);
  lc.setLed(0, 3, 5, true);
  lc.setLed(0, 3, 6, true);
  lc.setLed(0, 4, 7, true);
  lc.setLed(0, 6, 0, true);
  lc.setLed(0, 6, 1, true);
  lc.setLed(0, 6, 2, true);
  lc.setLed(0, 6, 3, true);
  lc.setLed(0, 6, 4, true);
  lc.setLed(0, 6, 6, true);
  lc.setLed(0, 6, 7, true);
  lc.setLed(0, 7, 0, true);
  lc.setLed(0, 7, 1, true);
  lc.setLed(0, 7, 2, true);
  lc.setLed(0, 7, 3, true);
  lc.setLed(0, 7, 4, true);
  lc.setLed(0, 7, 6, true);
  lc.setLed(0, 7, 7, true);
}

void gasReact_2() {
  lc.setLed(0, 0, 0, true);
  lc.setLed(0, 0, 1, true);
  lc.setLed(0, 1, 2, true);
  lc.setLed(0, 1, 3, true);
  lc.setLed(0, 2, 4, true);
  lc.setLed(0, 3, 4, true);
  lc.setLed(0, 3, 5, true);
  lc.setLed(0, 3, 6, true);
  lc.setLed(0, 4, 7, true);
  lc.setLed(0, 6, 0, true);
  lc.setLed(0, 6, 1, true);
  lc.setLed(0, 6, 2, true);
  lc.setLed(0, 6, 3, true);
  lc.setLed(0, 6, 4, true);
  lc.setLed(0, 6, 6, true);
  lc.setLed(0, 6, 7, true);
  lc.setLed(0, 7, 0, true);
  lc.setLed(0, 7, 1, true);
  lc.setLed(0, 7, 2, true);
  lc.setLed(0, 7, 3, true);
  lc.setLed(0, 7, 4, true);
  lc.setLed(0, 7, 6, true);
  lc.setLed(0, 7, 7, true);
}

void ledSet() {
  for (int row = 0; row < 8; row++) {
    delay(80);
    for (int col = 0; col < 8; col++) {
      lc.setLed(0, col, row, false);
      delay(10);
    }
  }
}

long TP_init() {
  delay(1);
  long vibration_value = pulseIn (VIBRATION_SENSOR, HIGH);
  return vibration_value;
}
