# **Project_arduino**

### **Digital Fabrication** 2019 Spring

- 아두이노 프로젝트와 수업내용을 정리한다.
- 프로젝트는 최대한 다른 method를 이용해 제작한다.

## **Project**

#### RefereeBox
```
공용 공간에서 공부하다가 소음, 진동, 흡연냄새로 인해 고통받는 사람을 위한 Arduino Device
방해되는 상황에서 말로 해결하기 힘든 사람들을 위해, Referee Box의 디스플레이를 통해 메시지를 보낸다.

SW-420, LM393, MQ-2, MQ-7을 이용하여 측정한 뒤 각 값에 대응하는 임계치를 넘은 입력치에 대해
8x8 Display로 각기 다른 경고 아이콘을 출력한다.
```
- Arduino Uno
- Arduino Uno Sensor Shield (SZH-EK049)
- 진동센서 (SW-420)
- 사운드 센서 (LM393)
- 흡연센서 (MQ-2, MQ-7)
- 8x8 Display Module * 3

![](rm1.gif);
![](rm2.gif);
![](rm3.gif);
![](rm4.gif);
![](rm5.gif);


## **Lecture**

##### 3.29 (금)
- [blink](http://www.arduino.cc/en/Tutorial/Blink)
- [multiBlinks](https://www.arduino.cc/en/Tutorial/MultipleBlinks)
- [fade](https://www.arduino.cc/en/tutorial/fade)

##### 4.03 (수)
- [button](https://www.arduino.cc/en/tutorial/button)
- [digitalRead()](https://www.arduino.cc/reference/en/language/functions/digital-io/digitalread/) - Reads the value from a specified digital pin, either HIGH or LOW.
- [digitalWrite()](https://www.arduino.cc/reference/en/language/functions/digital-io/digitalwrite/) - Write a HIGH or a LOW value to a digital pin.
- [pinMode()](https://www.arduino.cc/reference/en/language/functions/digital-io/pinmode/) - Configures the specified pin to behave either as an input or an output. 
- [Serial](https://www.arduino.cc/reference/en/language/functions/communication/serial/) - Used for communication between the Arduino board and a computer or other devices.

##### 4.10 (수)
- [Serial.read()](https://www.arduino.cc/reference/ko/language/functions/communication/serial/read/) - 들어오는 시리얼 데이터를 읽는다.
- [analogWrite(pin, Value)](https://www.arduino.cc/reference/ko/language/functions/analog-io/analogwrite/) - 아날로그 값을 핀에 출력한다.

##### 4.17 (수)
- [analogRead(pin)](https://www.arduino.cc/reference/ko/language/functions/analog-io/analogread/) - 지정한 아날로그 핀에서 값을 읽는다.
- [tone(pin, frequency)](https://www.arduino.cc/reference/ko/language/functions/advanced-io/tone/) - 핀에 특정 주파수(50% 듀티 사이클)의 구형파를 발생시킨다.
- [noTone(pin)](https://www.arduino.cc/reference/ko/language/functions/advanced-io/notone/) - tone() 에 의해 시작된 구형파의 발생을 멈춘다.

##### 5.08(수)
- [Serial.available()](https://www.arduino.cc/reference/ko/language/functions/communication/serial/available/) - Get the number of bytes (characters) available for reading from the serial port.

##### 5.29(수)
- [Serial.flush()](https://www.arduino.cc/en/Serial/Flush)