int R=9;
int G=10;
int B=11;
 
void setup() {
 
pinMode(R,OUTPUT);
pinMode(G,OUTPUT);
pinMode(B,OUTPUT);
}
 
void loop() {
//Kırmızı renk elde etmek için...
analogWrite(R,255);
analogWrite(G,0);
analogWrite(B,0);
delay(500);
 
//Yeşil renk elde etmek için...
analogWrite(R,0);
analogWrite(G,255);
analogWrite(B,0);
delay(500);
 
//Mavi renk elde etmek için...
analogWrite(R,0);
analogWrite(G,0);
analogWrite(B,255);
delay(500);
}
