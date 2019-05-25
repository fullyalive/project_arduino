import processing.serial.*;
Serial port;
int x;
int offset=10;
void setup() {
  size(270, 100);
  port=new Serial(this, Serial.list()[1], 9600);
}

void draw() {
  background(255, 255, 0);
  if (mouseX>x) {
    x+=1; 
    offset=10;
  }
  if (mouseX<x) {
    x-=1; 
    offset=-10;
  }
  fill(0);
  textSize(14);
  text(mouseX, mouseX, mouseY-5);
  port.write(mouseX);
}
