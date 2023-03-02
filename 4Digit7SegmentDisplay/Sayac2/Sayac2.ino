int say=0;
int pinA=2;
int pinB=3;
int pinC=4;
#define pinD 5
int pinE=6;
int pinF=7;
int pinG=8;
int digit4=9;
int digit3=10;
int digit2=11;
int digit1=12;

int dizi[10][7] = {{0,0,0,0,0,0,1},  // 0 rakamı
                 {1,0,0,1,1,1,1},    // 1 rakamı
                 {0,0,1,0,0,1,0},    // 2 rakamı
                 {0,0,0,0,1,1,0},    // 3 rakamı
                 {1,0,0,1,1,0,0},    // 4 rakamı
                 {0,1,0,0,1,0,0},    // 5 rakamı
                 {0,1,0,0,0,0,0},    // 6 rakamı
                 {0,0,0,1,1,1,1},    // 7 rakamı
                 {0,0,0,0,0,0,0},    // 8 rakamı
                 {0,0,0,0,1,0,0}};   // 9 rakamı
                 
void setup() {
  for(int i=2; i<13; i++){
    pinMode(i, OUTPUT);
  }
  digitalWrite(digit1,0);
  digitalWrite(digit2,0);
  digitalWrite(digit3,0);
  digitalWrite(digit4,0);

  cli();
   TCCR1A = 0;
   TCCR1B = 0;
   TCNT1  = 0;

   OCR1A = 15624;
   TCCR1B |= (1 << WGM12);
   TCCR1B |= (1 << CS12) | (1 << CS10);  
   TIMSK1 |= (1 << OCIE1A);
   sei();
}
ISR(TIMER1_COMPA_vect)
{
   say++; 
}

}

void loop() {

  digitalWrite(digit1,1);
  digitalWrite(digit2,0);
  digitalWrite(digit3,0);
  digitalWrite(digit4,0);

  for(int a=0; a<10; a++){
    for(int j=0; j<7; j++){
      digitalWrite(j+2, dizi[a][j]);
    }
    delay(1000);
  }
  delay(5);

}
