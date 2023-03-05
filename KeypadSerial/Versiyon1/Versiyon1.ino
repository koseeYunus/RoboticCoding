#include <Keypad.h>

const int satir=4;
const int sutun=4;

string sifre="AB123";
string gelenSifre="";


char key[Satir][Sutun]= 
{
{'1', '2', '3', 'A'}, 
{'4', '5', '6', 'B'}, 
{'7', '8', '9', 'C'},
{'*', '0', '#', 'D'}
};

byte SatirPinleri[Satir]={2,3,4,5};
byte SutunPinleri[Sutun]={6,7,8,9};

Keypad TusTakimi= Keypad(makeKeymap(key), SatirPinleri, SutunPinleri, satir, sutun);

void setup() {
  Serial.begin(9600);

}

void loop() {
  char gelenKarakter=TusTakimi.getKey();

  if(gelenKarakter != NO_KEY){
    gelenSifre=gelenSifre+gelenKarakter;

    Serial.print("Basilan Tus : ");
    Serial.prinln(gelenSifre);

    if(gelenSifre==sifre){
      Serial.println("SİFRE DOGRU... ");
      gelenSifre="";
    }
     
  }

  


}
