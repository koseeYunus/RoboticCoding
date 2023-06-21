#include <ESP8266WiFi.h>
#include <FirebaseArduino.h>
#define FIREBASE_HOST "****************" //veritabanı host adı
#define FIREBASE_AUTH "**************" //secret key
#define WIFI_SSID "*****" //bağlı olunan wifi adı
#define WIFI_PASSWORD "*******" //bağlı olunan wifi parolası

void setup() {
Serial.begin(9600);
pinMode(D2, OUTPUT);
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
// get value
n = Firebase.getInt("klima");
// handle error
if (n==1) {
Serial.println("Klima ON");
digitalWrite(D2,HIGH);  
}
else {
Serial.println("Klima OFF");
digitalWrite(D2,LOW);  
}
}
