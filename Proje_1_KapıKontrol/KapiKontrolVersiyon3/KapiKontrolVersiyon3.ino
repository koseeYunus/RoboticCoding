#include<Keypad.h>  //libraries
#include <LiquidCrystal.h>
#include<Servo.h>
Servo servo;
#define yled 5   //green led
#define kled 6   // red led
#define buzzer 4

LiquidCrystal lcd(12, 11, 10, 9, 8, 7);//Lcd connections LiquidCrystal(rs, enable, d4, d5, d6, d7)
// ( vss:GND ,VDD:+5V,VO:POT ,RW:GND,A:+5V,K:GND)

const byte satir = 4;  //rows
const byte sutun = 4;  //columbs
char sifre[4] = {'1', '2', '3', '#'}; //default password we can change it from here and also change it int he void loop!
char sifre1[4];  //password that we will click on the keypad
char tus;   //char key 
int i = 0;  
char tus_takimi[4][4] = {  //key_pad  2 dimensional array name of the kayped 
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};

byte satir_pins[4] = {A0, A1, A2, A3};  //rows_pins connected which pins
byte sutun_pins[4] = {A4, A5, 3, 2};    //columb_pins connecting which pins

Keypad tuss_takimi = Keypad(makeKeymap(tus_takimi), satir_pins, sutun_pins, 4, 4);  // special code from Keypad library. basically create map usin name of keypad and row_pins,columb_pins


byte customChar9[8] = {  //in order to create animation(LOADING EFFECT ) and custom character.
  
  0b11111, 
  0b11111,
  0b11111,   // It has been taught in my other video how to create these custom characters: thermometer with animation effect.
  0b11111,
  0b11111,
  0b11111,
  0b11111,
  0b11111
};
byte customChar8[8] = {
  0b11110,
  0b11110,
  0b11110,
  0b11110,
  0b11110,
  0b11110,
  0b11110,
  0b11110
};
byte customChar7[8] = {
  0b11100,
  0b11100,
  0b11100,
  0b11100,
  0b11100,
  0b11100,
  0b11100,
  0b11100
};
byte customChar6[8] = {
  0b11000,
  0b11000,
  0b11000,
  0b11000,
  0b11000,
  0b11000,
  0b11000,
  0b11000
};
byte customChar5[8] = {
  0b10000,
  0b10000,
  0b10000,
  0b10000,
  0b10000,
  0b10000,
  0b10000,
  0b10000
};
byte customChar4[8] = {
  0b00001,
  0b00011,
  0b00011,
  0b00111,
  0b00111,
  0b01111,
  0b01111,
  0b11111
};
byte customChar3[8] = {
  0b00000,
  0b00010,
  0b00010,
  0b00110,
  0b00110,
  0b01110,
  0b01110,
  0b11110
};
byte customChar2[8] = {
  0b00000,
  0b00000,
  0b00000,
  0b00100,
  0b00100,
  0b01100,
  0b01100,
  0b11100
};
byte customChar1[8] = {
  0b00000,
  0b00000,
  0b00000,
  0b00000,
  0b00000,
  0b01000,
  0b01000,
  0b11000
};

byte customChar0[8] = {
  0b00000,
  0b00000,
  0b00000,
  0b00000,
  0b00000,
  0b00000,
  0b00000,
  0b10000
};

void setup() {
  
  servo.attach(13);
  pinMode(yled, OUTPUT);  //designating leds and buzzer as OUTPUT
  pinMode(buzzer, OUTPUT);
  pinMode(kled, OUTPUT);
  lcd.createChar(0, customChar0);
  lcd.createChar(1, customChar1);
  lcd.createChar(2, customChar2);
  lcd.createChar(3, customChar3);
  lcd.createChar(4, customChar4);
  lcd.createChar(5, customChar5);//other custom char starts from here
  lcd.createChar(6, customChar6);
  lcd.createChar(7, customChar7);
  lcd.createChar(8, customChar8);
  lcd.createChar(9, customChar9);
  lcd.begin(16, 2); // LCD BEGAN
  lcd.clear();  //Clear screen
  lcd.clear();
  lcd.setCursor(1, 0);
  lcd.print("TUGVA");//Clear screen
  
  for (int i = 1; i <= 13; i++)  // used 2 for loop in order to create LOADING EFFECT
  {


    for (int k = 6; k <= 9; k++)
    {
      lcd.setCursor(i, 1); lcd.write((uint8_t)k);
      delay(100);

    }

  }

  lcd.clear();
  lcd.setCursor(0, 0); 
  lcd.print("TUGVA");//ARDUINO HOCAM 
  lcd.setCursor(0, 1);
  lcd.print("SIFRELI KAPI");   // LOCK DOOR SYSTEM
  delay(2000);
  lcd.clear();  
  lcd.setCursor(0, 0); 
  lcd.print("SIFREYI GIRINIZ:");    //YOU CAN PRINT HERE WHAT EVER YOU WANT ,THIS MEAN PASSWORD:
  Serial.begin(9600);
  Serial.println("Hos geldiniz");   //WELCOME
  Serial.println("Sifreyi giriniz");  
}

void loop() {
  servo.write(0);
  
digitalWrite(kled,LOW);
digitalWrite(yled,LOW);
  tus = tuss_takimi.getKey();  //getKey gets key when we click on the keypad 

  if (tus)   //if key (tus then it will process as follow
  {
    sifre1[i++] = tus;  //everytime we click keypad ,sifre1=password1 will be [0] to [1] to[2].... till 4. element of array

    lcd.setCursor(i, 1); 
    lcd.print("*");   // i have used * this charecter so that passwords that we print on the screen can not be seen from anyone else 
    digitalWrite(buzzer,HIGH);
delay(100);
digitalWrite(buzzer,LOW);// also when we clicked keypad ,buzzer will ring which make you feel like real system :)
  }

  if (i == 4)
  { delay(200);
    char sifre[4] = {'1', '2', '3', '#'}; //default password u should write here like that 
 
    if ((strncmp(sifre1, sifre, 4) == 0))   //comparing these passwords if first 4 element correct then  process will be as follows
    {
      lcd.clear();
      lcd.setCursor(0, 0);
      servo.write(90);
      lcd.print("SIFRE DOGRU!"); //password correct
      digitalWrite(yled, HIGH);
      digitalWrite(kled, LOW);
      digitalWrite(buzzer, HIGH);
      delay(100);
      digitalWrite(buzzer, LOW);
      delay(100);
      digitalWrite(buzzer, HIGH);
      delay(100);
      digitalWrite(buzzer, LOW);
      delay(1000);
      lcd.clear();
      lcd.setCursor(0, 0); 
      lcd.print("SIFREYI GIRINIZ");  //password : 
      i = 0;
    }

    else
    {
      lcd.clear();
      lcd.setCursor(0, 0); 
      lcd.print("SIFRE YANLIS!!!");  //wrong password
      digitalWrite(yled, LOW);
      digitalWrite(kled, HIGH);
      digitalWrite(buzzer, HIGH);
      delay(1000);
      digitalWrite(buzzer, LOW);
      delay(1000);
      lcd.clear();
      lcd.setCursor(0, 0); 
      lcd.print("SIFREYI GIRINIZ"); //password :
      i = 0;
    }
  }
}
