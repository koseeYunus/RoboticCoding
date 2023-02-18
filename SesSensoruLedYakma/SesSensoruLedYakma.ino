int sensorPin=4;
int ledPin=3;

int senDeger=0;
int durum=0;

void setup() {
  pinMode(sensorPin, INPUT);
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  senDeger=digitalRead(sensorPin);
  if(senDeger==1){
    int g= digitalRead(ledPin);
    digitalWrite(ledPin, !g);
    delay(100);
  }

}
