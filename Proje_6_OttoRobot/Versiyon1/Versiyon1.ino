#include <Servo.h>
#define buzzerPin 13
int echoPin = 9;
int trigPin = 8;

Servo servoSolAyak;
Servo servoSagAyak;

int maxDeger = 200;
int minDeger = 0;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(buzzerPin, OUTPUT);
  Serial.begin(9600);
  servoSolAyak.attach(2);
  servoSagAyak.attach(4);
}

void loop() {

  int olcum = mesafe(maxDeger, minDeger);
  melodiCal(olcum*15);
  servoSolAyak.write(50);
  servoSagAyak.write(100);
  delay(500);
  servoSolAyak.write(100);
  servoSagAyak.write(50);
}

int mesafe(int maxD, int minD)
{
  long gecenZaman, uzaklik;

  digitalWrite(trigPin,LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  gecenZaman = pulseIn(echoPin, HIGH);
  uzaklik = gecenZaman / 58.2;
  delay(50);
  Serial.println(uzaklik);

  if(uzaklik >= maxD || uzaklik <= minD)
  {
    return 0;
  }
  else{
    return uzaklik;
    
  }
}

int melodiCal(int beklemeSuresi)
{
  tone(buzzerPin, 256);
  delay(beklemeSuresi);
  
  noTone(buzzerPin);
  delay(beklemeSuresi);
  
}