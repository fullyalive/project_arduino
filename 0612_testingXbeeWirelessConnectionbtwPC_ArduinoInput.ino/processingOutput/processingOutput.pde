import processing.serial.*;

int x=0, y=0, z=0;
Serial myPort;

void setup() {
  size(800, 800, P3D);
  myPort = new Serial(this, Serial.list()[1], 9600);
}

void draw() {
  background(0);
  fill(153);
  pushMatrix(); // showing current position (0,0)
  translate(width/2, height/2, 0); // changing position value to
  rotateX(x/100.0);
  rotateY((-y)/100.0);
  rotateZ(z/100.0);
  box(300);
  popMatrix();
  delay(1);
}

void serialEvent(Serial p) {
  String message = myPort.readStringUntil(10);

  if (message != null) {
    String[] data = message.split(",");
    x = parseInt(data[0]);
    y = parseInt(data[1]);
    z = parseInt(data[2]);
  }
}
