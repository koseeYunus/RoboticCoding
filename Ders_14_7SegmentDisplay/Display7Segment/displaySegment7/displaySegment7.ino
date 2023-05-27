int sayilar[] = {
  0b0111111, //0
  0b0000110, //1
  0b1011011, //2
  0b1001111, //3
  0b1100110, //4
  0b1101101, //5
  0b1111101, //6
  0b0000111, //7
  0b1111111, //8
  0b1101111  //9
  };
void setup(){
  for (int i=0; i <= 13; i++){
    pinMode(i,OUTPUT);
  }
}
void loop(){
  for(int i=0;i<=99;i++){
    //0 99 arası sayıları yazdırmak için SayiYaz fonksiyonunu çağırıyoruz. 
    SayiYaz(i);  
    delay(100);  
  }
}
void SayiYaz(int sayi){
  int birlerBas= sayi%10;    // 2 Basamaklı sayının birler basamağını bulduk
  int onlarBas= sayi/10;     // 2 Basamaklı sayının onlar basamağını bulduk

  SayiYazBirler(birlerBas);  // Birler basamağını sağdaki display'e yazdırdık.
  SayiYazOnlar(onlarBas);    // Onlar basamağını solaki display'e yazdırdık.
}
void SayiYazBirler(int sayi){
  //0 pinden 6. pine kadar digital write
  for (int pin = 0, Bit = 0; pin <= 6; pin++,Bit++){  
    //sayilar dizisindeki sayi indisindeki binary olarak
    digitalWrite(pin, bitRead(sayilar[sayi], Bit));    
  } 
  //sayiyi elde et. Örnek 1 için 0b0000110 . Bitleri sırasıyla oku ve pin numarasına 0(LOW)veya 1(HIGH)
  //olarak digital write ile yazıyoruz.
} 
 //Bu fonksiyon tek bir sayıyı yazdırmak içindir.


void SayiYazOnlar(int sayi){
  for (int pin = 7, Bit = 0; pin <= 13; pin++,Bit++){ 
    digitalWrite(pin, bitRead(sayilar[sayi], Bit));
  }
}
