#include <LiquidCrystal.h>
#include <Keypad.h>

const byte ROWS = 4;
const byte COLS = 4;

char keys[ROWS][COLS] = {
  {'7','8','9','D'},
  {'4','5','6','C'},
  {'1','2','3','B'},
  {'*','0','#','A'}
};


byte rowPins[ROWS] = {9, 8, 7, 6}; // satır pinleri
byte colPins[COLS] = {5, 4, 3, 2}; //  sutun pinleri


Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS );

LiquidCrystal lcd(10, 11, 2, 3, 4, 5);

 long Num1,Num2,Number;
 char key,action;
 boolean durum = false;


void setup() {
  lcd.begin(16, 2); //16*2 LCD Ekran kullanıyoruz
  lcd.setCursor(4, 0);
  lcd.print("TUGVA"); //İntro mesajı görüntüle
  lcd.setCursor(0, 1);   // Göstergeyi sütun 0, satır 1’e ayarla
  lcd.print("Hesap Makinesi"); //İntro mesajı görüntüle
  delay(2000); //Ekranın bilgiyi göstermesi için bekle
  lcd.clear(); //Temizle
}
void loop() {

  key = keypad.getKey(); // Basılan tuşun değerini char olarak depolama

  if (key!=NO_KEY){
    TusAlgila();
  }
  
  if (durum==true){
    SonucuHesapla();
  }
  
  EkranaYaz();   

}
void TusAlgila()
{ 
    lcd.clear(); //LCD Temizle

    
    if(key == '0') //Eğer 0 düğmesi basıldığında
    {
      Serial.println("Button 0");
      if(Number==0)
        Number=0;
      else
        Number = (Number*10) + 0; 
    }

    if(key == '1') //Eğer 1 düğmesi basıldığında
    {
      Serial.println("Button 1"); 
      if(Number==0)
        Number=1;
      else
        Number = (Number*10) + 1; 
    }

    if(key == '2') //Eğer 2 düğmesi basıldığında
    {
      Serial.println("Button 2"); 
      if(Number==0)
        Number=2;
      else
        Number = (Number*10) + 2; 
    }

    if(key == '3') //Eğer 3 düğmesi basıldığında
    {
      Serial.println("Button 3"); 
      if(Number==0)
        Number=3;
      else
        Number = (Number*10) + 3;
    }

    if(key == '4') //Eğer 4 düğmesi basıldığında
    {
      Serial.println("Button 4"); 
      if(Number==0)
        Number=4;
      else
        Number = (Number*10) + 4;
    }

    if(key == '5') //Eğer 5 düğmesi basıldığında
    {
      Serial.println("Button 5"); 
      if(Number==0)
        Number=5;
      else
        Number = (Number*10) + 5;
    }

    if(key == '6') //Eğer 6 düğmesi basıldığında
    {
      Serial.println("Button 6"); 
      if(Number==0)
        Number=6;
      else
        Number = (Number*10) + 6;
    }

    if(key == '7') //Eğer 7 düğmesi basıldığında
    {
      Serial.println("Button 7");
      if(Number==0)
        Number=7;
      else
        Number = (Number*10) + 7;
    }

    if(key == '8') //Eğer 8 düğmesi basıldığında
    {
      Serial.println("Button 8"); 
      if(Number==0)
        Number=8;
      else
        Number = (Number*10) + 8;
    }  

    if(key == '9') //Eğer 9 düğmesi basıldığında
    {
      Serial.println("Button 9");
      if(Number==0)
        Number=9;
      else
        Number = (Number*10) + 9;
    }  


    if(key=='*') //Eğer sıfırla düğmesi basıldığında
    {
      Serial.println("Sifirlaniyor..."); 
      Number=Num1=Num2=0; 
      durum=false;
    }

    if(key == '#') //Eğer # düğmesi basıldığında
    {
      Serial.println("Hesaplaniyor.."); 
      Num2=Number;
      durum = true;
    }





    if(key == 'A' || key == 'B' || key == 'C' || key == 'D') //Sütun 4’teki düğmeleri tespit etme
    {
      Num1 = Number;    
      Number = 0;

      if(key == 'A'){
        Serial.println("Topla"); 
        action = '+';
      } //Toplama

      if(key == 'B'){
       Serial.println("Cikar"); 
       action = '-'; 
       } //Çıkarma

      if(key == 'C'){
       Serial.println("Carp"); 
       action = '*';
       } //Çarpma

      if(key == 'D'){
       Serial.println("Bol"); 
       action = '/';
       }  // //Bölme

      delay(100);
  }

}

void SonucuHesapla()
{
  if (action=='+')
    Number = Num1+Num2;
  if (action=='-')
    Number = Num1-Num2;
  if (action=='*')
    Number = Num1*Num2;
  if (action=='/')
    Number = Num1/Num2; 
}

void EkranaYaz()
{
  lcd.setCursor(0, 0); //Göstergeyi sütun 0, satır 1’e ayarla
  lcd.print(Num1); 
  lcd.print(action); 
  lcd.print(Num2); 

  if (durum==true){
    lcd.print(" = "); 
    lcd.print(Number);
    } //Sonucu göster

  lcd.setCursor(0, 1);   // Göstergeyi sütun 0, satır 1’e ayarla
  lcd.print(Number); //Sonucu göster
}


