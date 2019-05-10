# **Project_arduino**

### **Digital Fabrication** 2019 Spring

- 아두이노 프로젝트와 수업내용을 정리한다.
- 프로젝트는 최대한 다른 method를 이용해 제작한다.


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