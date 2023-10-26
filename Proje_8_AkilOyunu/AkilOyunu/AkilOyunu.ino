const int button1 = 2;           
const int button2 = 3;          
const int button3 = 4;          
const int button4 = 5;        
  
const int led1 = 7;             
const int led2 = 8;             
const int led3 = 9;             
const int led4 = 10;    
       
const int buzzer = 12;   

int game_on = 0;
int wait = 0;
int currentlevel = 1; 
long rand_num = 0; 
int rando = 0; 
int butwait = 500; 
int ledtime = 500; 
int n_levels = 10; 
int pinandtone = 0; 
int right = 0; 
int speedfactor = 5; 
int leddelay = 200; 
       

const int tones[] = {261, 349, 392, 440, 2700}; 


int buttonState[] = {0,0,0,0};         
int lastButtonState[] = {0,0,0,0};    
int buttonPushCounter[] = {0,0,0,0}; 


void playTone(int tone, int duration) {
  for (long i = 0; i < duration * 1000L; i += tone * 2) {
    digitalWrite(buzzer, HIGH);
    delayMicroseconds(tone);
    digitalWrite(buzzer, LOW);
    delayMicroseconds(tone);
  }
}

void setup() {
 
  randomSeed(analogRead(0));
  
  pinMode(button1, INPUT);
  pinMode(button2, INPUT);
  pinMode(button3, INPUT);
  pinMode(button4, INPUT);
 
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  
  pinMode(buzzer, OUTPUT);
  

}


void loop() {
  
  int n_array[n_levels];
  int u_array[n_levels];

  int i;

  if (game_on == 0){
    for(i=0; i<n_levels; i=i+1){
            n_array[i]=0;
            u_array[i]=0;
            rand_num = random(1,200);
            if (rand_num <= 50)
              rando=0;
            else if (rand_num>50 && rand_num<=100)
              rando=1;
            else if (rand_num>100 && rand_num<=150)
              rando=2;
            else if (rand_num<=200)
              rando=3;
            
            n_array[i]=rando;
          }
    game_on = 1; 

  }

  if (wait == 0){
    delay (200);
    i = 0;
    for (i = 0; i < currentlevel; i= i + 1){
      leddelay = ledtime/(1+(speedfactor/n_levels)*(currentlevel - 1));
      pinandtone = n_array[i];
      digitalWrite(pinandtone+7, HIGH);
      playTone(tones[pinandtone], leddelay);
      digitalWrite(pinandtone+7, LOW);
      delay(100/speedfactor);
    }
    wait = 1;
  }

  i = 0;
  int buttonchange = 0;    
  int j = 0; 
  while (j < currentlevel){    
      while (buttonchange == 0){
            for (i = 0; i < 4; i = i + 1){ 
              buttonState[i] = digitalRead(i+2);
              buttonchange = buttonchange + buttonState[i];
            }
      }
      for (i = 0; i < 4; i = i + 1){
          if (buttonState[i] == HIGH) {
              digitalWrite(i+7, HIGH);
              playTone(tones[i], ledtime);
              digitalWrite(i+7, LOW);
              wait = 0;
              u_array[j]=i; 
              buttonState[i] = LOW;
              buttonchange = 0;
          }
        } 
          if (u_array[j] == n_array[j]){
              j++;  
              right = 1;
              }
          else{
            
              right = 0;
              i = 4;
              j = currentlevel;
              wait = 0;
          }
  }

  if (right == 0){
    delay(300);
    i = 0;
    game_on = 0;
    currentlevel = 1;
    for (i = 0; i < 4; i = i + 1){
          digitalWrite(i+7, HIGH);
        }
            playTone(tones[4], ledtime);
    for (i = 0; i < 4; i = i + 1){
          digitalWrite(i+7, LOW);   
        }
        delay (200);
    for (i = 0; i < 4; i = i + 1){
          digitalWrite(i+7, HIGH);
        }
            playTone(tones[4], ledtime);
    for (i = 0; i < 4; i = i + 1){
          digitalWrite(i+7, LOW);   
        }
        
        delay(500);
        game_on = 0;
  }



  if (right == 1){
      currentlevel++;
      wait = 0;
      }
    
  if (currentlevel == n_levels){
    delay(500);
    
    int notes[] = {2, 2, 2, 2, 0, 1, 2, 1, 2};
    int note = 0;
    int tempo[] = {200, 200, 200, 400, 400, 400, 200, 200, 600}; 
    int breaks[] = {100, 100, 100, 200, 200, 200, 300, 100, 200}; 
    for (i = 0; i < 9; i = i + 1){
    note = notes[i];
      digitalWrite(note+7, HIGH);
      playTone(tones[note], tempo[i]);
      digitalWrite(note+7, LOW);
      delay(breaks[i]);
    }

  game_on = 0;
  currentlevel = 1;
  n_levels = n_levels + 2;
  speedfactor = speedfactor + 1;
      }
 
}
