#include <Servo.h>

Servo sagServo;
Servo solServo;

int xPin=A0;
int yPin=A1;
int btnPin=2;

int xPozisyon=0;
int yPozisyon=0;
int btnDurum=0;

int sagVeri=0;
int solVeri=0;

void setup() {
  sagServo.attach(9);
  solServo.attach(10);
  pinMode(xPin, INPUT);
  pinMode(yPin, INPUT);
  pinMode(btnPin, INPUT_PULLUP);
}

void loop() {
  xPozisyon=analogRead(xPin);
  yPozisyon=analogRead(yPin);
  btnDurum=digitalRead(btnPin);

  sagVeri=map(xPozisyon,0,1023,0,180);
  solVeri=map(yPozisyon,0,1023,0,180);

  sagServo.write(sagVeri);
  solServo.write(solVeri);

}
