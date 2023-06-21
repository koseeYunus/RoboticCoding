#include <ESP8266WebServer.h>
#include <WiFiManager.h>                                                 
#include <FirebaseArduino.h>                                                
#include <DHT.h>  

//80 portunda server çalışıyor
WiFiServer server(80);

String header;

String output5State = "off";
String output4State = "off";

const int output5 = 5;
const int output4 = 4;

#define FIREBASE_HOST "ev-otomasyon-f0c18.firebaseio.com"                         
#define FIREBASE_AUTH "uK0BHzQJMsZSLXSKipLVM989vQbP9jxGlFJWdtnc"
#define DHTPIN D4        //Sicaklik ve nem sensoru pin belirlenmesi                                                   
#define DHTTYPE DHT22    //Sicaklik sensor tanimi                                               
DHT dht(DHTPIN, DHTTYPE); 

void setup() {
  Serial.begin(9600); //Serial haberlesmenin baslatilmasi
  pinMode(D1, OUTPUT); //led pinin tanimi
  pinMode(D2,OUTPUT); //fan ledinin tanimi
  delay(1000); 
 
  WiFiManager wifiManager;
  //wifiManager.resetSettings(); //Cihaz içindeki wifi ayarlarını sıfırlamak için bu kodun 1 kez yazdırılması gerek
  wifiManager.autoConnect("NodeMcu WiFi Ayar");
  Serial.println("Connected.");
  
  server.begin();  
}
//Sicaklik ve nem degerlerinin veritabanina yazilmasi
void sicakliknem(float t,float h)
{ 

  //Alinan degerlerin kontrolu
  if (isnan(h) || isnan(t)) {                                                
    Serial.println(F("Failed to read from DHT sensor!"));
    return;
  }
  //Degerlerin dogrulugu durumunda serial monitor uzerinde degerlerin yazimi
  Serial.print("NEM: ");  Serial.print(h);
  String fireHumid = String(h) + String("%");                                         
  Serial.print("%  Sicaklik: ");  Serial.print(t);  Serial.println("°C ");
  String fireTemp = String(t) + String("°C");                                                     

  //Degerlerin firebase veritabanina eklenmesi
  Firebase.pushInt("/nem/deger",h);                               
  Firebase.pushInt("/sicaklik/deger",t);                                   
}

//Ledin veritabani uzerinden kontrolu
//n degeri veritabanindaki degiskene esdeger
void lamba(int n)
{
  if (n==1) {
  Serial.println("LED ACIK");
  digitalWrite(D1,HIGH);  
  }
  else {
  Serial.println("LED KAPALI");
  digitalWrite(D1,LOW);  
  }
}

//Fanin relay ile veritabani uzerinden kontrolu
//n degeri veritabanindaki relay kontrol degeri
void klima(int n)
{
  if (n==1) {
      Serial.println("Klima ON");
      digitalWrite(D2,HIGH);  
  }
  if(n==0) {
      Serial.println("Klima OFF");
      digitalWrite(D2,LOW);  
  }
}

//Gaz sensorunun analog pin uzerinden kontrolu
//Alinan gaz degerinin serial monitor uzerinde gosterilmesi ve veritabanina eklenmesi.
void gaz(int deger)
{ 
  Firebase.pushInt("/gaz/deger", deger);
  Serial.println (deger);

}

void loop(){
  //Wifi baglanmak için olusturulan html kodları
  WiFiClient client = server.available();

  if (client) {      //Yeni bir kullanıcı durumunda                
    Serial.println("New Client.");          
    String currentLine = "";                
    while (client.connected()) {            
      if (client.available()) {             
        char c = client.read();             
        Serial.write(c);                    
        header += c;
        if (c == '\n') {
          if (currentLine.length() == 0) {
            client.println("HTTP/1.1 200 OK");
            client.println("Content-type:text/html");
            client.println("Connection: close");
            client.println();
            
            if (header.indexOf("GET /5/on") >= 0) {
              Serial.println("GPIO 5 on");
              output5State = "on";
              digitalWrite(output5, HIGH);
            } else if (header.indexOf("GET /5/off") >= 0) {
              Serial.println("GPIO 5 off");
              output5State = "off";
              digitalWrite(output5, LOW);
            } else if (header.indexOf("GET /4/on") >= 0) {
              Serial.println("GPIO 4 on");
              output4State = "on";
              digitalWrite(output4, HIGH);
            } else if (header.indexOf("GET /4/off") >= 0) {
              Serial.println("GPIO 4 off");
              output4State = "off";
              digitalWrite(output4, LOW);
            }
            client.println("<!DOCTYPE html><html>");
            client.println("<head><meta name=\"viewport\" content=\"width=device-width, initial-scale=1\">");
            client.println("<link rel=\"icon\" href=\"data:,\">");
            client.println("<style>html { font-family: Helvetica; display: inline-block; margin: 0px auto; text-align: center;}");
            client.println(".button { background-color: #f7c933; border: none; color: white; padding: 16px 40px;");
            client.println("text-decoration: none; font-size: 30px; margin: 2px; cursor: pointer;}");
            client.println(".button2 {background-color: #77878A;}</style></head>");      
            client.println("<body><h1>NodeMcu Web Sunucu</h1>");
            
            client.println("<p>GPIO 5 - State " + output5State + "</p>");     
            if (output5State=="off") {
              client.println("<p><a href=\"/5/on\"><button class=\"button\">ON</button></a></p>");
            } else {
              client.println("<p><a href=\"/5/off\"><button class=\"button button2\">OFF</button></a></p>");
            } 
            client.println("<p>GPIO 4 - State " + output4State + "</p>");     
            if (output4State=="off") {
              client.println("<p><a href=\"/4/on\"><button class=\"button\">ON</button></a></p>");
            } else {
              client.println("<p><a href=\"/4/off\"><button class=\"button button2\">OFF</button></a></p>");
            }
            client.println("</body></html>");  
            client.println();
            break;
          } else {
            currentLine = "";
          }
        } else if (c != '\r') {  
          currentLine += c;
        }
      }
    }
    header = "";
    client.stop();
    Serial.println("Client disconnected.");
    Serial.println("");
  }
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
  dht.begin(); 
  lamba(Firebase.getInt("lamba"));
  klima(Firebase.getInt("klima"));
  sicakliknem(dht.readTemperature(),dht.readHumidity());
  gaz(analogRead(A0));
  delay(2000);   
}
