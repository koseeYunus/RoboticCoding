int led =13;
int sensorPin=A0;

int sensorDeger=0;

void setup() {
  pinMode(led, OUTPUT);
  pinMode(sensorPin, INPUT);
  Serial.begin(9600);

}

void loop() {
  sensorDeger = analogRead(sensorPin);
  Serial.println(sensorDeger);
  
  if(sensorDeger>80){
    digitalWrite(led, HIGH);
    delay(2000);
  }
  else{
    digitalWrite(led, LOW);
  }

}
