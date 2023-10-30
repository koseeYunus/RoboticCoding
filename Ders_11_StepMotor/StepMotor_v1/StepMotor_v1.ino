//Step Motor Sürücü Motor Bağlantıları
#define IN1 8
#define IN2 9
#define IN3 10
#define IN4 11

//Her adımda bekleme süresi
int sure = 2;

void setup() {
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
}
// 512 Adım Tam Tur 360 Derecedir.
void loop() {
  //Saat Yönü 512 Adım
  SaatYonu(512);
  delay(1000);

  //Saat Ters Yönü 512 Adım
  SaatTersYonu(512);
  delay(1000);
}

void SaatYonu(int adimSayisi) {
  for (int i = 0; i < adimSayisi; i++) {
    digitalWrite(IN1, HIGH);
    delay(sure);
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);
    delay(sure);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, HIGH);
    delay(sure);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, HIGH);
    delay(sure);
    digitalWrite(IN4, LOW);
  }
}

void SaatTersYonu(int adimSayisi) {
  for (int i = 0; i < adimSayisi; i++) {
    digitalWrite(IN4, HIGH);
    delay(sure);
    digitalWrite(IN4, LOW);
    digitalWrite(IN3, HIGH);
    delay(sure);
    digitalWrite(IN3, LOW);
    digitalWrite(IN2, HIGH);
    delay(sure);
    digitalWrite(IN2, LOW);
    digitalWrite(IN1, HIGH);
    delay(sure);
    digitalWrite(IN1, LOW);
  }
}