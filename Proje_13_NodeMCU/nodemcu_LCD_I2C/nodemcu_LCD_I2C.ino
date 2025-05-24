#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// LCD adresini ve boyutlarını ayarlayın (genellikle adres 0x27 veya 0x3F olur)
// 16x2 LCD için parametreler: (adres, sütun sayısı, satır sayısı)
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  Serial.begin(115200);
  Serial.println("I2C LCD Test");
  
  // NodeMCU için I2C pinlerini tanımla (SDA=D2, SCL=D1)
  Wire.begin(D2, D1);
  
  // LCD başlat
  lcd.begin();
  
  // Arka ışığı aç
  lcd.backlight();
  
  // Ekranı temizle
  lcd.clear();
  
  // İlk satıra yaz
  lcd.setCursor(0, 0);
  lcd.print("Merhaba Dunya!");
  
  // İkinci satıra yaz
  lcd.setCursor(0, 1);
  lcd.print("NodeMCU & I2C LCD");
  
  Serial.println("LCD mesajı yazıldı");
}

void loop() {
  // Ana döngüde bir şey yapmıyoruz
}