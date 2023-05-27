#include <SoftwareSerial.h> // Hc-06 Bluetooth Modülü kütüphanesi tanımladık. 
SoftwareSerial hc06(3,2); // Hc-06 Bluetooth Modülü kütüphanesinde rxd ve txd pinlerini tanımladık. 
int kirmizi=11;

void setup(){
  Serial.begin(9600); //Serial haberleşmeyi aktif hale getirdik. 
  hc06.begin(9600);  // Hc-06 Bluetooth Modülü serial haberleşmesini aktif hale getirdik. 
}
void loop(){
  if (hc06.available()){ 
    char deger =hc06.read(); // Deger degişkenine bluetooth gelen veri tanımlandı.
    Serial.print("Gelen deger : ");
    Serial.println(deger);
    if(deger=='1'){ //deger eger 1 ise krımızı ısık yanacak.
      digitalWrite(kirmizi, HIGH);
      Serial.println("Led Yandı ");
      Serial.println("*******************");
    }
    if(deger=='2'){  
      digitalWrite (kirmizi,LOW);
      Serial.println("Led Söndü");
      Serial.println("*******************");
    }

  }
}