#include <LiquidCrystal.h>
#include <Keypad.h>  // keypad kütüphanesi, kendimiz import ediyoruz.
#include <Servo.h>   // servo kütüphanesi

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

int ledPinOpen=10;      // yeşil led
int ledPinClose=9;     // kırmızı led
const byte numRows= 4;  // keypad satır sayısı
const byte numCols= 4;  // keypad sütün sayısı
int control = 0;
int counter = 0;
String enter_password;     // girilen şifreyi tutar
String password = "#1234"; // kendimizin belirlediği şifre

Servo myservomotor;

// keypad tuş yapısını oluşturuyoruz
char keymap[numRows][numCols]= 
{
{'1', '2', '3', 'A'}, 
{'4', '5', '6', 'B'}, 
{'7', '8', '9', 'C'},
{'*', '0', '#', 'D'}
};

// bağlantı bacaklarını belirliyoruz
byte rowPins[numRows] = {A0,A1,A2,A3}; 
byte colPins[numCols] = {A4,A5,6,7}; 

// keypad i set ediyoruz
Keypad myKeypad= Keypad(makeKeymap(keymap), rowPins, colPins, numRows, numCols);

void setup() {
  lcd.begin(16, 2); 
  lcd.print("Lutfen Sifreyi");
  lcd.setCursor(0, 1);
  lcd.print("Giriniz");
  delay(500);
  lcd.clear();
  delay(500);

  Serial.begin(9600);
  myservomotor.attach(10);      // 10.bacak servo çıkışı
  myservomotor.write(0);        // ilk etapta açısını 0 olarak set ediyoruz
  pinMode(ledPinOpen,OUTPUT);   // led pinlerini çıkış olarak belitliyoruz
  pinMode(ledPinClose,OUTPUT);  

}

void loop() {

 char keypressed = myKeypad.getKey();  // keypadden gelen değer
  if (keypressed != NO_KEY) {
    Serial.print(keypressed);
    // # tuşuna basıldı ise control 1 olur password kontrole geçer
    if(keypressed == '#') {  
      control = 1;
    }
    // Kapıyı Aç
    if(keypressed == 'A') { 
      for(int value = 0; value < 90; value++) {
        myservomotor.write(value);
        digitalWrite(ledPinOpen,1); 
        digitalWrite(ledPinClose,0);
      }
    }
    // Kapıyı Kapat
    if(keypressed == 'B') {
      for(int value = 90; value > 1; value--){
        myservomotor.write(value);
        digitalWrite(ledPinOpen,0); 
        digitalWrite(ledPinClose,1);
      }
    }
    // # tuşuna basıldı ise gerekli kontrolleri yap
    if(control == 1){
      enter_password = enter_password + keypressed;
      counter++;
      Serial.print("sifre " + enter_password );
      // password doğru ise
      if(enter_password == password) {
        Serial.print("kapı açıldı");
        for(int value = 0; value < 90; value++) {
          myservomotor.write(value);
        }
        digitalWrite(ledPinOpen,1); 
        digitalWrite(ledPinClose,0);
        delay(2000);  // gecikme
        digitalWrite(ledPinOpen,0); 
        enter_password = "";
        control = 0;
        counter = 0;
      }
      // password yanlış veya 4 den fazla girildi ise
      else if ((enter_password != password) && (counter > 4) ) {
        Serial.print("hatalı giriş");
        for(int value = 90; value > 1; value--){
          myservomotor.write(value);
        }
        digitalWrite(ledPinOpen,0); 
        digitalWrite(ledPinClose,1);
        delay(2000);
        digitalWrite(ledPinClose,0);
        enter_password = "";
        control = 0;
        counter = 0;
      }
    }
  }

}