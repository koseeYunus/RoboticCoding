#include <ESP8266WiFi.h>
extern "C" {
  #include <espnow.h>
}

// Alıcı MAC adresi (ikinci NodeMCU) - bunu alıcı kodundan elde edilecek MAC ile değiştirilecek
uint8_t receiverMacAddress[] = {0xC8, 0xC9, 0xA3, 0x34, 0xE3, 0xF2}; // C8:C9:A3:34:E3:F2

// Buton pinleri
const int buttonPins[5] = {D1, D2, D5, D6, D7};
int lastButtonStates[5] = {HIGH, HIGH, HIGH, HIGH, HIGH};

// Her buton için gönderilecek metinler
String buttonMessages[5] = {
  "Buton 1 Basildi",
  "Merhaba Dunya",
  "NodeMCU Projesi",
  "Kablosuz Iletisim",
  "ESP-NOW Calisiyor"
};

// Veri gönderme durumunu kontrol eden fonksiyon
void onSent(uint8_t *mac_addr, uint8_t status) {
  if (status == 0) {
    Serial.println("Gönderme başarılı!");
  } else {
    Serial.println("Gönderme başarısız!");
  }
}

void setup() {
  Serial.begin(115200);
  delay(1000); // Seri port başlaması için bir süre bekle
  
  Serial.println("ESP-NOW Gönderici");
  
  // Butonları giriş olarak ayarla ve pull-up dirençlerini etkinleştir
  for (int i = 0; i < 5; i++) {
    pinMode(buttonPins[i], INPUT_PULLUP);
  }
  
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
  esp_now_set_self_role(ESP_NOW_ROLE_CONTROLLER);
  esp_now_register_send_cb(onSent);
  
  // Alıcıyı kaydediyoruz
  esp_now_add_peer(receiverMacAddress, ESP_NOW_ROLE_SLAVE, 1, NULL, 0);
  
  Serial.println("Kurulum tamamlandı. Butonlara basabilirsiniz.");
}

void loop() {
  // Her butonu kontrol et
  for (int i = 0; i < 5; i++) {
    // Buton durumunu oku (LOW basılı, HIGH basılı değil)
    int buttonState = digitalRead(buttonPins[i]);
    
    // Buton basıldıysa ve önceki durumunda basılı değildiyse
    if (buttonState == LOW && lastButtonStates[i] == HIGH) {
      Serial.print("Buton ");
      Serial.print(i + 1);
      Serial.println(" basıldı");
      
      // Mesajı gönder
      esp_now_send(receiverMacAddress, (uint8_t *)buttonMessages[i].c_str(), buttonMessages[i].length() + 1);
      
      // Buton basıldıktan sonra kısa bir bekleme (debounce)
      delay(50);
    }
    
    // Son buton durumunu güncelle
    lastButtonStates[i] = buttonState;
  }
  
  // Kısa gecikme
  delay(20);
}