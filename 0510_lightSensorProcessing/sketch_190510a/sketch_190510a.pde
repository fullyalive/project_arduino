import processing.serial.*;
Serial port;
int val;

int num = 60;
float mx[] = new float[num];
float my[] = new float[num];

void setup() {
  port = new Serial(this, Serial.list()[3], 14400);
  size(100, 640);
  noStroke();
  fill(255, 153);
}

void draw() {
  if (port.read() != -1) {
    val = port.read();
    println(val);
  }
  background(51);

  int which = frameCount % num;
  mx[which] = 50;
  my[which] = val*3;

  for (int i = 0; i <num; i++) {
    // which+1 is the smallest (the oldest in the array)
    int index = (which+1 +i)% num;
    ellipse(mx[index], my[index], i, i);
  }
}
