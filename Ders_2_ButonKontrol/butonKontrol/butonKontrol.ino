// 8 numaralı pini Buton olaral isimlendirdik
#define Buton 8

int deger=0;

void setup()
{
  // Butonumuzdan veri geleceği için input olarak işaretledik
  pinMode(Buton, INPUT);

  // Bilgisayarımızdaki Serial ekranı başlatır
  Serial.begin(9600);
}
void loop()
{
  // Butonumuzdan gelen değeri digitalRead metodumuz ile okuyabiliyoruz
  deger = digitalRead(Buton);
  
  // Serial ekrana yazdırma işlemi aşağıdaki gibi yapılmaktadır
  Serial.print("Buton Durum : ");
  
  // Butonumuzdan gelen verimiz 1 ise serial ekrana basıldı yazdırmak için aşağıdaki koşullamdırmayı kullanıyoruz
  if (deger){
    // println yazılır ise alt satıra geçer
    Serial.println("Butona basıldı.");
  }
  // Değilse ledin gücünü kes
  else{
    Serial.println("Şuan butona basılmamaktadır.");
  }
}
