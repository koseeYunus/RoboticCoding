#include <Servo.h>
#include "NewPing.h"

#define MAX_DISTANCE 400

#define Led 10
#define Buton 11

Servo servoKontrol;

const int trigger_pin=5;
const int echo_pin=6;


float duration, uzaklik;

NewPing sonar(trigger_pin, echo_pin, MAX_DISTANCE);

void setup() {
  pinMode(trigger_pin,OUTPUT);
  pinMode(echo_pin,INPUT);

  pinMode(Buton, INPUT);
  pinMode(Led, OUTPUT);

  servoKontrol.attach(9);

  Serial.begin(9600);
  
}


void loop() {
  uzaklik = sonar.ping_cm();

  Serial.println(uzaklik);

  if (uzaklik >= 400 || uzaklik <= 5) 
  {
    servoKontrol.write(90);
    Serial.println("Mesafe Ölçülemedi");
    if (digitalRead(Buton) == 1)
    {
      servoKontrol.write(180);
      digitalWrite(Led,HIGH);
      Serial.println("Isik yakildi");
      delay(1000);
    }
    else
    {
      servoKontrol.write(90);
      digitalWrite(Led,LOW);
      Serial.println("Isik Söndürüldü");
      delay(1000);
    }
  }  
  else if (uzaklik <= 10){
    servoKontrol.write(180);
    delay(1000);
  }
  else{
    servoKontrol.write(90); 
    delay(1000);
  }

}
