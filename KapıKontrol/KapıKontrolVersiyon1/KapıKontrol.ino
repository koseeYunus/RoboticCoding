#include <Keypad.h>

const byte satir = 4; 
const byte sutun = 4; 

char tus_takimi[satir][sutun] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};

byte satir_pinleri[satir] = {9, 8, 7, 6}; // satırların bağlandığı pinler
byte sutun_pinleri[sutun] = {5, 4, 3, 2}; //

Keypad kasa = Keypad( makeKeymap(tus_takimi), satir_pinleri, sutun_pinleri, satir, sutun );
#define sari 10
#define kirmizi 11
#define yesil 12
#define ses 13

String girilen_sifre = "";
String sifre="1234#";

void setup(){
Serial.begin(9600);
pinMode(sari,OUTPUT);
pinMode(kirmizi,OUTPUT);
pinMode(yesil,OUTPUT);
pinMode(ses,OUTPUT);
}
  
void loop(){
  char tus = kasa.getKey();
  
  if (tus !=NO_KEY)
  {
    girilen_sifre = girilen_sifre+tus;
    Serial.println(girilen_sifre);
    digitalWrite(ses,1);
    digitalWrite(sari,1);
    delay(100);
    digitalWrite(ses,0);
    digitalWrite(sari,0);    
  }
  if(tus =='#')
  {
    if(girilen_sifre == sifre)
    Serial.println("SİFRE DOGRU");
    digitalWrite(yesil,1);
    delay(300);
    digitalWrite(yesil,0);
    girilen_sifre="";
  }
  else
  {
    Serial.println("YANLIŞ");
    Serial.println(girilen_sifre);
    digitalWrite(kirmizi,1);
    digitalWrite(ses,1);
    delay(1000);
    digitalWrite(kirmizi,0);
    digitalWrite(ses,0);
    girilen_sifre="";
    
  }
  }