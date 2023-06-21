#include <ESP8266WiFi.h>
#include <FirebaseArduino.h>
#define FIREBASE_HOST "****************" //veritabanı host adı
#define FIREBASE_AUTH "**************" //secret key
#define WIFI_SSID "*****" //bağlı olunan wifi adı
#define WIFI_PASSWORD "*******" //bağlı olunan wifi parolası
void setup() {
Serial.begin(9600);
pinMode(D1, OUTPUT);
// connect to wifi.
WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
Serial.print("connecting");
while (WiFi.status() != WL_CONNECTED) {
Serial.print(".");
delay(500);
}
Serial.println();
Serial.print("connected: ");
Serial.println(WiFi.localIP());
Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
}
int n = 0;
void loop() {
  int deger= analogRead(A0); // Analog Values 0 to 1023
  Firebase.pushInt("/gaz/deger", deger);
  Serial.println (deger);
  
  delay(10000);

}
