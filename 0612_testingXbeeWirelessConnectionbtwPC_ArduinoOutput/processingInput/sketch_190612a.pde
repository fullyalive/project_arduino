import processing.serial.*;
Serial port;

boolean button = false;

int x = 150;
int y = 150;
int w = 100;
int h = 100;

void setup() {
  size(400, 400);
  port = new Serial(this, Serial.list()[1], 9600);
}

void draw() {
  if (button) {
    background(255);
    stroke(0);
  } else {
    background(0);
    stroke(255);
  }
  fill(175);
  rect(x, y, w, h);
}

void mousePressed() {
  if (mouseX > x && mouseX < x+w && mouseY > y && mouseY < y+h) {
    button = !button;
  }
  if (button == true) {
    port.write(255);
  } else {
    port.write(0);
  }
}
