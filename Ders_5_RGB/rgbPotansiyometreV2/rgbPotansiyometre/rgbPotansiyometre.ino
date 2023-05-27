//RGB led pin bağlantılarını tanımlıyoruz. 
int rPin=11;
int gPin=9;
int bPin=10;
 
//Potansiyometre bağlantı pinlerini tanımlıyoruz. 
const byte redPot=A2;
const byte greenPot=A1;
const byte bluePot=A0;
 
//Potansiyometreden okunacak değerler için değişkenleri tanımlıyoruz. 
int potDegerR; int potDegerG; int potDegerB;
 
void setup() {
//RGB led pin bağlantılarını çıkış pini olarak tanımlıyoruz. 
pinMode(rPin,OUTPUT);
pinMode(gPin,OUTPUT);
pinMode(bPin,OUTPUT);
}
 
void loop() {
//Potansiyometre değerlerini okuyup değişkenlere aktarıyoruz.  
potDegerR=analogRead(redPot);
potDegerG=analogRead(greenPot);
potDegerB=analogRead(bluePot);
 
//Potansiyometre değerlerini pwm sinyallerine dönüştürüyoruz.
potDegerR=map(potDegerR,0,1023,0,255);
potDegerG=map(potDegerG,0,1023,0,255);
potDegerB=map(potDegerB,0,1023,0,255);
 
//RGB led pinlerine potansiyometre değerlerini yazdırıyoruz.
analogWrite(rPin,potDegerR);
analogWrite(gPin,potDegerG);
analogWrite(bPin,potDegerB);
delay(100);
}