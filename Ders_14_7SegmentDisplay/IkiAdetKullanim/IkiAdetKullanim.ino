int pinler[14] = {2,3,4,5,6,7,8,9,10,11,12,13,A0,A1};


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

                 
void setup() 
{
   for(int i=0;i<=13;i++)
   {
      pinMode(pinler[i], OUTPUT);              
   }


}

void loop() 
{

   for(int a=0; a<=99; a++)
   {
      SayiYaz(a);
      delay(25);            
   }


}

void SayiYaz(int gelenSayi){
  for(int j=0;j<=6;j++)
   {
      digitalWrite(pinler[j], dizi[gelenSayi%10][pinler[j]]); 
   }
   delay(5);


   for(int k=7;k<=13;k++)
   {
      digitalWrite(pinler[k], dizi[(gelenSayi/10)%10][pinler[k]]); 
   }
   delay(5); 
 }
