#include <ESP8266WiFi.h>
extern "C" {
  #include <espnow.h>
}
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// LCD ayarları
LiquidCrystal_I2C lcd(0x27, 16, 2); // Adres 0x27 veya 0x3F olabilir

// Veri alındığında çağrılacak fonksiyon
void onDataReceived(uint8_t *mac, uint8_t *data, uint8_t len) {
  // Veriyi string'e çevir
  char message[len + 1];
  memcpy(message, data, len);
  message[len] = '\0';
  
  Serial.print("Gelen mesaj: ");
  Serial.println(message);
  
  // LCD'yi temizle ve gelen metni göster
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(message);
  
  // Zaman damgası göster
  lcd.setCursor(0, 1);
  lcd.print(millis()/1000);
  lcd.print(" sn gecti");
}

void setup() {
  Serial.begin(115200);
  delay(1000); // Seri port başlaması için bir süre bekle
  
  Serial.println("ESP-NOW Alıcı");
  
  // LCD'yi başlat
  Wire.begin(D2, D1); // SDA=D2, SCL=D1 pinlerini kullan
  lcd.begin();
  lcd.backlight();
  
  // Hoş geldiniz mesajı
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("ESP-NOW Alici");
  lcd.setCursor(0, 1);
  lcd.print("Hazir...");
  
  // ESP-NOW başlatma
  WiFi.mode(WIFI_STA); // Station modu
  WiFi.disconnect();   // WiFi bağlantısını kapat
  delay(100);
  
  // MAC adresini yazdır
  Serial.print("MAC Adresi: ");
  Serial.println(WiFi.macAddress());
  
  // ESP-NOW başlat
  if (esp_now_init() != 0) {
    Serial.println("ESP-NOW başlatılamadı");
    return;
  }
  
  // ESP-NOW rolünü ve callback fonksiyonunu ayarla
  esp_now_set_self_role(ESP_NOW_ROLE_SLAVE);
  esp_now_register_recv_cb(onDataReceived);
  
  Serial.println("Kurulum tamamlandı. Mesajlar bekleniyor...");
}

void loop() {
  // ESP-NOW, geri çağırma işlevini kullanır, burada bir şey yapmamıza gerek yok
  delay(1000);
}