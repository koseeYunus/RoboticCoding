//lcd ve keypad icin kutuphaneler ekleniyor
#include <LiquidCrystal.h>
#include <Keypad.h>

const byte ROWS = 4;
const byte COLS = 4;
//keypad tuslari 2x2 dizide tanimlaniyor
char keys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};


byte rowPins[ROWS] = {2, 3, 4, 5}; // satır pinleri
byte colPins[COLS] = {6, 7, 8, 9}; //  sutun pinleri
//Satir ve satir pinleri tanımlandiktan sonra keypad nesnesi tanimlaniyor
Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS );

//lcd nesnesi oluşturuluyor
LiquidCrystal lcd(A1, A0, 13, 12, 11, 10);

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
    TusAlgila();  // Basilan tusu algilamak icin asagidaki fonksiyona gonderiliyor
  }
  
  if (durum==true){
    SonucuHesapla();  // # tusuna basildiginda sonucu hesaplamak icin asagidaki fonksiyona gonderiliyor
  }
  
  EkranaYaz();   // loop her dondogunde lcd ekranina yazdirma fonksiyonuna gonderiliyor

}


int gelenSayi=0;

void DegiskeneSayiYaz(char gelenKarakter){
  gelenSayi=int(gelenKarakter); // Gelen metin sayıya donusturuluyor
  if(Number==0){  
    Number=gelenSayi;// Basilan tus ilk defa basildiysa birler basamagi kaydediliyor
  } 
  else{
    Number = (Number*10)+gelenSayi; // Tuslar basildikca onlar, yuzler.. basamagi kaydediliyor
  }
}

void TusAlgila()
{ 
    lcd.clear(); //LCD Temizle
    
    DegiskeneSayiYaz(key);  // Basilan tusu algilanarak sayi kaydeilmesi icin yukaridaki degiskene gonderiliyor

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

