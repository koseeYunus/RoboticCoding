#include <SoftwareSerial.h> // Hc-06 Bluetooth Modülü kütüphanesi tanımladık. 
SoftwareSerial hc06(3,2); // Hc-06 Bluetooth Modülü kütüphanesinde rxd ve txd pinlerini tanımladık. 
int kirmizi=11;
int led2=A0;


char deger;

const int motorA1  = 5;  // L298N'in IN3 Girişi
  const int motorA2  = 9;  // L298N'in IN1 Girişi
  const int motorB1  = 10; // L298N'in IN2 Girişi
  const int motorB2  = 6;  // L298N'in IN4 Girişi

  int i=0; //Döngüler için atanan rastgele bir değişken
  int j=0; //Döngüler için atanan rastgele bir değişken
  int state; //Bluetooth cihazından gelecek sinyalin değişkeni
  int vSpeed=255;     // Standart Hız, 0-255 arası bir değer alabilir

void setup(){
  Serial.begin(9600); //Serial haberleşmeyi aktif hale getirdik. 
  hc06.begin(9600);  // Hc-06 Bluetooth Modülü serial haberleşmesini aktif hale getirdik. 


  pinMode(motorA1, OUTPUT);
  pinMode(motorA2, OUTPUT);
  pinMode(motorB1, OUTPUT);
  pinMode(motorB2, OUTPUT); 
}
void loop(){
  if (hc06.available()){ 
    deger =hc06.read(); // Deger degişkenine bluetooth gelen veri tanımlandı.
    Serial.print("Gelen deger : ");
    Serial.println(deger);
    //delay(500);
    if(deger=='W'){ //deger eger 1 ise krımızı ısık yanacak.
      analogWrite(kirmizi, 255);
      analogWrite(led2, 255);
      Serial.println("Led Yandı ");
      Serial.println("*******************");
      delay(2000);
    }
    if(deger=='w'){  
      analogWrite(kirmizi,0);
      analogWrite(led2, 0);
      Serial.println("Led Söndü");
      Serial.println("*******************");
      delay(2000);
    }
    //Serial.println(vSpeed);
    //delay(1000);

    hizAyarla();
    hareketEttir();
  }
}

void hizAyarla(){
  if (deger == '0'){
      vSpeed=0;}
    else if (deger == '1'){
      vSpeed=100;}
    else if (deger == '2'){
      vSpeed=180;}
    else if (deger == '3'){
      vSpeed=200;}
    else if (deger == '4'){
      vSpeed=255;
    }
}

void hareketEttir(){
  //Gelen veri 'F' ise araba ileri gider.
    if (deger == 'F') {
      analogWrite(motorA1, vSpeed); 
      analogWrite(motorA2, 0);
      analogWrite(motorB1, vSpeed);  
      analogWrite(motorB2, 0); 
      Serial.println("f yonude hareket etti ");
      Serial.println("*******************");
      //delay(1000);
    }

  //Gelen veri 'G' ise araba ileri sol(çapraz) gider.
    else if (deger == 'G') {
      analogWrite(motorA1,100 ); 
      analogWrite(motorA2, 0);  
      analogWrite(motorB1, vSpeed);   
      analogWrite(motorB2, 0); 
      Serial.println("G yonude hareket etti ");
    }

  //Gelen veri 'I' ise araba ileri sağ(çapraz) gider.
    else if (deger == 'I') {
        analogWrite(motorA1, vSpeed); 
        analogWrite(motorA2, 0); 
        analogWrite(motorB1, 100);      
        analogWrite(motorB2, 0); 
        Serial.println("i yonude hareket etti ");
    }

  //Gelen veri 'B' ise araba geri gider.
    else if (deger == 'B') {
      analogWrite(motorA1, 0);   
      analogWrite(motorA2, vSpeed); 
      analogWrite(motorB1, 0);   
      analogWrite(motorB2, vSpeed); 
      Serial.println("b yonude hareket etti ");
    }

  //Gelen veri 'H' ise araba geri sol(çapraz) gider
    else if (deger == 'H') {
      analogWrite(motorA1, 0);   
      analogWrite(motorA2, vSpeed); 
      analogWrite(motorB1, 0); 
      analogWrite(motorB2, 100); 
      Serial.println("h yonude hareket etti ");
    }

  //Gelen veri 'J' ise araba geri sağ(çapraz) gider
    else if (deger == 'J') {
      analogWrite(motorA1, 0);   
      analogWrite(motorA2, 100); 
      analogWrite(motorB1, 0);   
      analogWrite(motorB2, vSpeed); 
      Serial.println("j yonude hareket etti ");
    }

  //Gelen veri 'L' ise araba sola gider.
    else if (deger == 'L') {
      analogWrite(motorA1, 0);   
      analogWrite(motorA2, 0); 
      analogWrite(motorB1, vSpeed); 
      analogWrite(motorB2, 150); 
      Serial.println("l yonude hareket etti ");
    }

  //Gelen veri 'R' ise araba sağa gider
    else if (deger == 'R') {
      analogWrite(motorA1, vSpeed);   
      analogWrite(motorA2, 150); 
      analogWrite(motorB1, 0);   
      analogWrite(motorB2, 0);  
      Serial.println("r yonude hareket etti ");   
    }
  

  //Gelen veri 'S' ise arabayı durdur.
    else if (deger == 'S'){
        analogWrite(motorA1, 0);  
        analogWrite(motorA2, 0); 
        analogWrite(motorB1, 0);  
        analogWrite(motorB2, 0);
        Serial.println("s harfi geldi ");
    }   
}