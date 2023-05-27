#include <IRremote.h>

IRrecv sinyal(2);
decode_results gelenVeri;

#define CH1 0xFFA25D
#define CH 0xFF629D
#define CH2 0xFFE21D
#define PREV 0xFF22DD
#define NEXT 0xFF02FD
#define PLAYPAUSE 0xFFC23D
#define VOL1 0xFFE01F
#define VOL2 0xFFA857
#define EQ 0xFF906F
#define BUTON0 0xFF6897
#define BUTON100 0xFF9867
#define BUTON200 0xFFB04F
#define BUTON1 0xFF30CF
#define BUTON2 0xFF18E7
#define BUTON3 0xFF7A85
#define BUTON4 0xFF10EF
#define BUTON5 0xFF38C7
#define BUTON6 0xFF5AA5
#define BUTON7 0xFF42BD
#define BUTON8 0xFF4AB5
#define BUTON9 0xFF52AD

int led1 = 8;
int led2 = 9;
int led3 = 10;

void setup() {
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  Serial.begin(9600);
  sinyal.enableIRIn();
}
void loop() {

  if (sinyal.decode( & gelenVeri)) {
    if (gelenVeri.value == BUTON1) {
      digitalWrite(led1, !digitalRead(led1));
      if (digitalRead(led1) == HIGH) {
        Serial.println("LED 1 yandi");
      } else {
        Serial.println("LED 1 sondu");
      }
    }
    if (gelenVeri.value == BUTON2) {
      digitalWrite(led2, !digitalRead(led2));
      if (digitalRead(led2) == HIGH) {
        Serial.println("LED 2 yandi");
      } else {
        Serial.println("LED 2 sondu");
      }
    }
    if (gelenVeri.value == BUTON3) {
      digitalWrite(led3, !digitalRead(led3));
      if (digitalRead(led3) == HIGH) {
        Serial.println("LED 3 yandi");
      } else {
        Serial.println("LED 3 sondu");
      }
    }
    if (gelenVeri.value == VOL1) {
      digitalWrite(led1, LOW);
      digitalWrite(led2, LOW);
      digitalWrite(led3, LOW);
      Serial.println("Tum LED'ler sondu");
    }
    if (gelenVeri.value == VOL2) {
      digitalWrite(led1, HIGH);
      digitalWrite(led2, HIGH);
      digitalWrite(led3, HIGH);
      Serial.println("Tum LED'ler yandi");
    }
    sinyal.resume();
  }
}