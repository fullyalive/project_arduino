import processing.serial.*;
Serial port;
int val;
int[] yvals;

void setup() {
  port = new Serial(this, Serial.list()[1], 9600);
  size(640, 360);
  noSmooth();
  yvals = new int[width];
}

int arrayIndex = 0;

void draw() {
  background(102);
  
  if (port.read() != -1) {
    val = port.read();
  }
  
  for (int i = 1; i < width; i++) {
    yvals[i-1] = yvals[i];
    println(val);
  }
  
  yvals[width - 1] = val;
  
  fill(255);
  noStroke();
  rect(0, height, width, height);
  
  for (int i=1; i < width; i++) {
    stroke(255);
    point(i, height/3+yvals[i]);
    stroke(255);
  }
}
