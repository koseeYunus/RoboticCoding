#include <Key.h>
#include <Keypad.h>

#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

#include <Keypad.h> //keypad kütüphanesi

const byte ROWS = 4; //satır
const byte COLS = 4; //sutun

char keys [ROWS] [COLS] = {
  {'1', '2', '3', '+'},
  {'4', '5', '6', '–'},
  {'7', '8', '9', '*'},
  {'C', '0', '=', '/'}
};
byte rowPins[ROWS] = {9, 8, 7, 6}; // satır pinleri
byte colPins[COLS] = {5, 4, 3, 2}; //  sutun pinleri

Keypad myKeypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );

boolean durum = false;
boolean final = false;
String num1, num2;
float sonuc = 0;
char islem;

void setup()
{
  lcd.setCursor(0,0); // cursor baslangıc
  lcd.print("TUGVA");
  lcd.setCursor(0,1); // cursor baslangıc
  lcd.print("Hesap Makinesi");
  delay(1500);
  lcd.clear();
  lcd.begin(16, 2);
}

void loop()
{
  char key = myKeypad.getKey();

  if (key != NO_KEY && (key == '1' || key == '2' || key == '3' || key == '4' || key == '5' || key == '6' || key == '7' || key == '8' || key == '9' || key == '0'))
  {
    if (durum != true)
    {
      num1 = num1 + key;
      int numLength = num1.length();
      lcd.setCursor(0, 0); 
      lcd.print(num1);
    }
    else
    {
      num2 = num2 + key;
      int numLength = num2.length();
      int numLength1 = num1.length();
      lcd.setCursor(1 + numLength1, 0);
      lcd.print(num2);
      final = true;
    }
  }

  else if (durum == false && key != NO_KEY && (key == '/' || key == '*' || key == '–' || key == '+'))
  {
    if (durum == false)
    {
      int numLength = num1.length();
      durum = true;
      islem = key;
      lcd.setCursor(0 + numLength, 0);
      lcd.print(islem);
    }
  }
  
  else if (final == true && key != NO_KEY && key == '=')
  {  
    if (islem == '+')
    {
      sonuc = num1.toInt() + num2.toInt();
    }
    else if (islem == '–')
    {
      //sonuc = num1.toInt() – num2.toInt();
    }
    else if (islem == '*')
    {
      sonuc = num1.toInt() * num2.toInt();
    }
    else if (islem == '/')
    {
      sonuc = num1.toFloat() / num2.toFloat();
    }
    
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("=");
    lcd.print(sonuc);
    lcd.noAutoscroll();  
  }
  
  else if (key != NO_KEY && key == 'C')
  {
    lcd.clear();
    durum = false;
    final = false;
    num1 = "";
    num2 = "";
    sonuc = 0;
    islem = ' ';
  }
}
