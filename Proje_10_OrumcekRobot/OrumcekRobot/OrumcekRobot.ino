#include <Servo.h>

// Servo motor pin bağlantıları
int servo1Pin = 2;
int servo2Pin = 3;
int servo3Pin = 4;
int servo4Pin = 5;
int servo5Pin = 6;
int servo6Pin = 7;
int servo7Pin = 8;
int servo8Pin = 9;

// Servo nesneleri oluştur
Servo servo1;
Servo servo2;
Servo servo3;
Servo servo4;
Servo servo5;
Servo servo6;
Servo servo7;
Servo servo8;

void setup() {
  // Servo pinleri ayarla
  servo1.attach(servo1Pin);
  servo2.attach(servo2Pin);
  servo3.attach(servo3Pin);
  servo4.attach(servo4Pin);
  servo5.attach(servo5Pin);
  servo6.attach(servo6Pin);
  servo7.attach(servo7Pin);
  servo8.attach(servo8Pin);
}

void loop() {
  // Örümceği ileri hareket ettir
  moveForward();
  delay(1000);

  // Örümceği geri hareket ettir
  moveBackward();
  delay(1000);

  // Örümceği sağa döndür
  turnRight();
  delay(1000);

  // Örümceği sola döndür
  turnLeft();
  delay(1000);
}

// İleri hareket fonksiyonu
void moveForward() {
  // Her iki tarafın servolarını ileri hareket ettir
  servo1.write(180);
  servo2.write(0);
  servo3.write(180);
  servo4.write(0);
  servo5.write(180);
  servo6.write(0);
  servo7.write(180);
  servo8.write(0);
}

// Geri hareket fonksiyonu
void moveBackward() {
  // Her iki tarafın servolarını geri hareket ettir
  servo1.write(0);
  servo2.write(180);
  servo3.write(0);
  servo4.write(180);
  servo5.write(0);
  servo6.write(180);
  servo7.write(0);
  servo8.write(180);
}

// Sağa dönme fonksiyonu
void turnRight() {
  // Sol tarafın servolarını geri, sağ tarafın servolarını ileri hareket ettir
  servo1.write(0);
  servo2.write(180);
  servo3.write(0);
  servo4.write(180);
  servo5.write(0);
  servo6.write(180);
  servo7.write(0);
  servo8.write(180);
}

// Sola dönme fonksiyonu
void turnLeft() {
  // Sol tarafın servolarını ileri, sağ tarafın servolarını geri hareket ettir
  servo1.write(180);
  servo2.write(0);
  servo3.write(180);
  servo4.write(0);
  servo5.write(180);
  servo6.write(0);
  servo7.write(180);
  servo8.write(0);
}