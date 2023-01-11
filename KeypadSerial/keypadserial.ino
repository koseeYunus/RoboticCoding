#include <Keypad.h>  // keypad kütüphanesini programa dahil ediyoruz.
const byte Satir= 4;  // keypad satır sayısı
const byte Sutun= 4;  // keypad sütün sayısı
String Sifre;     // girilen şifre 
 
// Keypad tuş yapısını hazırlıyoruz.
char key[Satir][Sutun]= 
{
{'1', '2', '3', 'A'}, 
{'4', '5', '6', 'B'}, 
{'7', '8', '9', 'C'},
{'*', '0', '#', 'D'}
};
 
// Arduino bağlantı bacaklarını belirliyoruz
byte SatirPinleri[Satir] = {2,3,4,5}; 
byte SutunPinleri[Sutun]= {6,7,8,9}; 
 
// Keypade TusTakimi ismini verip arduino bağlantılarını ve karakterleri 
// bu TusTakimi keypad nesnesine tanımlıyoruz.
Keypad TusTakimi= Keypad(makeKeymap(key), SatirPinleri, SutunPinleri, Satir, Sutun);
 
void setup()
{
  Serial.begin(9600);
}
 
void loop()
{
  char basilanTus = TusTakimi.getKey();  // Keyped basılan tuş değerini alıyoruz.
  if (basilanTus != NO_KEY) {
    Serial.print("Basılan Tuş:");    
    Serial.println(basilanTus);
    Sifre = Sifre + basilanTus;
    Serial.println("Girilen Sifre: " + Sifre );
  }    
}