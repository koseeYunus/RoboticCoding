const int Sensor =A0;
int seviye;
const int esik = 655;

int ledler[] = {2,3,4,5,6,7};


void setup() {
  for(int i=0; i<6; i++){
    pinMode(ledler[i], OUTPUT);
  }

  Serial.begin(9600);
}

void loop() {
  seviye=analogRead(Sensor);
  if(seviye>esik){
    for(int a=0; a<6; a++){
      digitalWrite(ledler[a], HIGH);
      delay(50);
      digitalWrite(ledler[a], LOW);
    }

    for(int b=5; b>-1; b--){
      digitalWrite(ledler[b], HIGH);
      delay(50);
      digitalWrite(ledler[b], LOW);
    }
  }
  else{
    for(int a=0; a<6; a++){
      digitalWrite(ledler[a], LOW);
    }    
  }
  

}
