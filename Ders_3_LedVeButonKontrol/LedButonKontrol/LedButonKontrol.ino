// 8 numaralı pini Buton olaral isimlendirdik
#define Buton 8

// 10 numaralı pini Led olaral isimlendirdik
#define Led 10

void setup()
{
  // Butonumuzdan veri geleceği için input olarak işaretledik
  pinMode(Buton, INPUT);

  // Led'e ise güç vereceğimiz için çıkış olarak işaretledik
  pinMode(Led, OUTPUT);
}
void loop()
{
  // Butonumuzdan gelen verimiz 1 ise ledimizi yakmak için aşağıdaki koşullandırmayı kullandık
  // Eğer butondan gelen veri 1'e eşitse led' güç ver
  if (digitalRead(Buton) == 1){
    digitalWrite(Led,HIGH);
  }
  // Değilse ledin gücünü kes
  else{
    digitalWrite(Led,LOW);
  }
}
