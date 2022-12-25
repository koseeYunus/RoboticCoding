#include "NewPing.h"

#define Trig_Pin 10
#define Echo_Pin 11
#define Max_Uzaklik 400  

NewPing sonar(Trig_Pin, Echo_Pin, Max_Uzaklik);

float uzaklik;

void setup() 
{
  Serial.begin(9600);
}

void loop() 
{
  uzaklik = sonar.ping_cm();
  
  Serial.print("Mesafe = ");
  
  if (uzaklik >= 400 || uzaklik <= 2) 
  {
    Serial.println("Mesafe algılanamadı");
  }
  else 
  {
    Serial.print(uzaklik);
    Serial.println(" cm");
  }
  delay(500);
}
