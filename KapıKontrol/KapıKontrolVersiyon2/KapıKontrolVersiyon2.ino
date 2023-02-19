#include <LiquidCrystal.h>   // Lcd kütüphanesi
#include <Keypad.h>          // Keypad kütüphanesi
#include <Servo.h>           // Servo kütüphanesi

Servo sg90; // Servo değişkeni oluşturuldu
LiquidCrystal movie(A5,A4,A3,A2,A1,A0);

#define Password_Length 8     // Şifre karakter uzunluğu
char Data[Password_Length];     // Şifre girişi için değişken oluşturuldu
char Master[Password_Length] = "123ABC";   // Şifre
char customKey;  // Tuş girişini tutmak için değişkne oluşturuldu

//int electric_motor = 10;   // Pin connected to Electric Motor

int buzzer = 11;   // Buzzer pin
int indicator_led = 12;   // Yeşil led pin
int k ;
int i = 0;
int s = 0;
int g = 0;
int a = 0;

int wait = 300; // led için bekleme değişkeni
byte data_count = 0; // Karakter girişini girerken kaç karakter girildiğini tutan değişken

const byte ROWS = 4; // Keypad satır sayısı
const byte COLS = 4; // Keypad sutun sayısı

char hexaKeys[ROWS][COLS] = {  // Tuş takımları
{'1', '2', '3', 'A'},
{'4', '5', '6', 'B'},
{'7', '8', '9', 'C'},
{'*', '0', '#', 'D'}
};

byte rowPins[ROWS] = {9, 8, 7, 6};  // Arduino keypad bağlantı pinleri
byte colPins[COLS] = {5, 4, 3, 2};
Keypad customKeypad = Keypad(makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS); // Keypad objesi oluşturuldu

void setup() {

  //pinMode(electric_motor, OUTPUT);  // Set Electric Motor pin as an OUTPUT pin
  pinMode(buzzer, OUTPUT); 
  pinMode(indicator_led, OUTPUT); 
  sg90.attach(10);
  Serial.begin(9600);    
  movie.begin(16,2);
  Serial.print("TUGVA");
  movie.print("TUGVA");
  delay(1500);
  movie.clear();

}
void loop() {

for(k=0;k<7 && g<1;k++){
  movie.setCursor(0,0);
  movie.print("Şifreyi Giriniz:");
  delay(100);
  customKey = customKeypad.getKey();  // Tuş basımını kontrol et
  if (customKey) {                    // Basılan tuşları diziye ata
    Data[data_count] = customKey;
    Serial.print(Data[data_count]);
   
    movie.setCursor(s,1);           // Lcd'nin ikinci satırını değiştir
    movie.print(Data[data_count]);
  
    digitalWrite(indicator_led,HIGH);  // Her başarılı girişte yeşil led yak
    delay(wait);
    digitalWrite(indicator_led,LOW);
    delay(wait);

    data_count++;
    s++;
    }
  }


  if (data_count == Password_Length - 1) {   // Parola uzunluğuna ulaşıp ulaşmadığını kontrol et
    while(i<1){
      Serial.println("");                      // İmleci bir sonraki satıra gönderir
      movie.print("");
      i++;
    }
    if (!strcmp(Data, Master)) {     // Girilen şifre doğru ise yapılcak işlemler
      digitalWrite(electric_motor, HIGH);
      digitalWrite(buzzer, LOW);
      Serial.println("correct");
      movie.clear();
      movie.setCursor(0,0);
      movie.print("The password is");
      movie.setCursor(0,1);
      movie.print("correct");
      delay(1000);
      movie.clear();
      g=1;
    }
    else {
      digitalWrite(electric_motor, LOW);     // Girilen şifre yanlış ise yapılacak işlemler
      digitalWrite(buzzer,HIGH);
      Serial.println("incorrect");
      movie.clear();
      movie.setCursor(0,0);
      movie.print("The password is");
      movie.setCursor(0,1);
      movie.print("incorrect");
      delay(1000);
      movie.clear();
      g=1;
    }
  }
  a=1;
}


void clearData() {            
  while (data_count != 0) {     // Dizideki verileri temizleme
    Data[data_count--] = 0;
  }
  return;
}