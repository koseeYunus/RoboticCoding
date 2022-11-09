#include<Servo.h>
Servo servoKontrol;
int aci=90;
 
void setup() {
  servoKontrol.attach(6); 
}

void loop() {
  for(aci=0;aci<=180;aci+=1){
    servoKontrol.write(aci);
    delay(50);
  }

  delay(3000);

  for(aci=180;aci>=0;aci-=1){
    servoKontrol.write(aci);
    delay(50);
  }

}

