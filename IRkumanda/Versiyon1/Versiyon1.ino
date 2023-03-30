#include <IRremote.h>

IRrecv sinyal(2);
decode_results gelenVeri;


void setup() {
  Serial.begin(9600);
  sinyal.enableIRIn();
}

void loop() {

  if (sinyal.decode( & gelenVeri)) {
    Serial.println(gelenVeri.value, HEX);
    sinyal.resume();
  }
}