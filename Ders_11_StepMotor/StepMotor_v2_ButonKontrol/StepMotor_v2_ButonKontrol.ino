//Step Motor Sürücü Motor Bağlantıları
#define IN1 8
#define IN2 9
#define IN3 10
#define IN4 11

int buttonIleri=2;
int buttonGeri=3;

//Her adımda bekleme süresi
int sure = 2;

int btnIleriDeger=0;
int btnGeriDeger=0;


void setup() {
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  pinMode(buttonIleri, INPUT);
  pinMode(buttonGeri, INPUT);

  Serial.begin(9600);

}
// 512 Adım Tam Tur 360 Derecedir.
void loop() {

  btnIleriDeger=digitalRead(buttonIleri);      
  btnGeriDeger=digitalRead(buttonGeri);

  if (btnIleriDeger == HIGH){
    SaatYonu(1);
    Serial.println("Ileri Gidiyor..");
  }
  else if (btnGeriDeger == HIGH){
    SaatTersYonu(1);
    Serial.println("Geri Gidiyor..");
  }
  else{
    Serial.println("BUTONA BASILMIYOR");
  }


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