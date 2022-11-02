#define led 3
#define potPin A0

int deger=0;

void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  Serial.println("Pot Değer Okuma");
}

// the loop routine runs over and over again forever:
void loop() {
  deger = analogRead(potPin);

  deger=map(deger, 0, 1023, 0, 255);
  analogWrite(led, deger);

  Serial.print("Değer = ");
  Serial.println("Değer = "+deger);
  delay(50);        // delay in between reads for stability
}
