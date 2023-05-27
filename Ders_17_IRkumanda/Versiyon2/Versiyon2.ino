#include <IRremote.h>

IRrecv sinyal(2);
decode_results gelenVeri;

#define BUTON1 0xFF30CF
#define BUTON2 0xFF18E7
#define BUTON3 0xFF7A85


void setup() {
  Serial.begin(9600);
  sinyal.enableIRIn();
}
void loop() {

  if (sinyal.decode( & gelenVeri)) {
    if (gelenVeri.value == BUTON1) {
      Serial.println("1 sayisina basildi.");
    }
    if (gelenVeri.value == BUTON2) {
      Serial.println("2 sayisina basildi.");
    }
    if (gelenVeri.value == BUTON3) {
      Serial.println("3 sayisina basildi.");
    }
    
    sinyal.resume();
  }
}