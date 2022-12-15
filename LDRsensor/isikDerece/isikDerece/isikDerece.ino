int ledler[] = {
  4,
  5,
  6,
  7
};
int led_sayisi = 4;
int ldr_pin = A0;
int deger = 0;
void setup() {
  for (int i = 0; i < led_sayisi; i++) {
    pinMode(ledler[i], OUTPUT);
  }
}
void loop() {
  deger = analogRead(ldr_pin);
  if (deger > 0 && deger <= 255) {
    digitalWrite(ledler[0], HIGH);
    digitalWrite(ledler[1], LOW);
    digitalWrite(ledler[2], LOW);
    digitalWrite(ledler[3], LOW);
  }
  if (deger > 256 && deger <= 511) {
    digitalWrite(ledler[0], HIGH);
    digitalWrite(ledler[1], HIGH);
    digitalWrite(ledler[2], LOW);
    digitalWrite(ledler[3], LOW);
  }
  if (deger > 512 && deger <= 767) {
    digitalWrite(ledler[0], HIGH);
    digitalWrite(ledler[1], HIGH);
    digitalWrite(ledler[2], HIGH);
    digitalWrite(ledler[3], LOW);
  }
  if (deger > 768 && deger <= 1023) {
    digitalWrite(ledler[0], HIGH);
    digitalWrite(ledler[1], HIGH);
    digitalWrite(ledler[2], HIGH);
    digitalWrite(ledler[3], HIGH);
  }
  delay(100);
}
