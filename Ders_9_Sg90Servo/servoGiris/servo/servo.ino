#include<Servo.h>
Servo servoKontrol;
int aci=90;
 
void setup() {
  servoKontrol.attach(6); 
}

void loop() {
  servoKontrol.write(aci);
  delay(3000);
  aci=aci+90;
  servoKontrol.write(aci);
  delay(3000);
  aci=aci-90;
}
