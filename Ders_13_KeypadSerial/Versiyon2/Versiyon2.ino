#include <Keypad.h>

int yesilLed=10;
int sariLed=11;
int kirmiziLed=12;
int buzzer=13;

const int satir=4;
const int sutun=4;

String sifre="AB123";
String gelenSifre="";


char key[satir][sutun]= 
{
{'1', '2', '3', 'A'}, 
{'4', '5', '6', 'B'}, 
{'7', '8', '9', 'C'},
{'*', '0', '#', 'D'}
};

byte SatirPinleri[satir]={2,3,4,5};
byte SutunPinleri[sutun]={6,7,8,9};

Keypad TusTakimi= Keypad(makeKeymap(key), SatirPinleri, SutunPinleri, satir, sutun);

void setup() {
  for(int i=10;i<14;i++){
    pinMode(i, OUTPUT);
  }
  Serial.begin(9600);

}

void loop() {
  char gelenKarakter=TusTakimi.getKey();

  if(gelenKarakter != NO_KEY){
    gelenSifre=gelenSifre+gelenKarakter;
    Serial.print("Basilan Tus : ");
    Serial.println(gelenSifre);

    digitalWrite(sariLed, 1);
    digitalWrite(buzzer, 1);
    delay(100);
    digitalWrite(sariLed, 0);
    digitalWrite(buzzer, 0);    

    if(gelenKarakter == '#'){
      //Doğrumu yanlışmı kodlarım olacak burada
      if(gelenSifre==sifre){
      Serial.println("SİFRE DOGRU... ");
      gelenSifre="";
      digitalWrite(yesilLed,1);
      digitalWrite(buzzer,1);
      delay(50);
      digitalWrite(buzzer,0);
      delay(25);
      digitalWrite(buzzer,1);
      delay(50);
      digitalWrite(yesilLed,0);
      }
      else{
      Serial.println("SIFRE YANLIS!!! ");
      gelenSifre="";
      digitalWrite(kirmiziLed, 1);
      digitalWrite(buzzer,1);
      delay(500);
      digitalWrite(buzzer,0);
      digitalWrite(kirmiziLed,0);
      }
    }
    
    

    
     
  }

  


}