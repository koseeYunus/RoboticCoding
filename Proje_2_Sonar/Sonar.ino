#include <Servo.h>. 
 
// Ultrasonik Sinyal pinleri
const int trigPin = 10;
const int echoPin = 11;
 
long duration;
int distance;
 
Servo myServo; 
 
void setup() {
  pinMode(trigPin, OUTPUT); 
  pinMode(echoPin, INPUT); 
  Serial.begin(9600);
  myServo.attach(9); // Servo motor sinyal pini
}
void loop() {
  // 15 derece ile 165 derece arasında dön
  for(int i=15;i<=165;i++){ myServo.write(i); 
    delay(30); distance = calculateDistance(); 
    Serial.print(i); 
    Serial.print(","); 
    Serial.print(distance); 
    Serial.print("."); 
  } 
  for(int i=165;i>15;i--){  
    myServo.write(i);
    delay(30);
    distance = calculateDistance();
    Serial.print(i);
    Serial.print(",");
    Serial.print(distance);
    Serial.print(".");
  }
}
 
int calculateDistance(){ 
   
  digitalWrite(trigPin, LOW); 
  delayMicroseconds(2);
 
  digitalWrite(trigPin, HIGH); 
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH); 
  distance= duration*0.034/2;
  return distance;
}