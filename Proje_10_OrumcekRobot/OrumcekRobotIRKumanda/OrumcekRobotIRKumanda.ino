#include<Servo.h>
#include <IRremote.h> 
//________ÖNLER___________//
Servo OnSagUst;
Servo OnSagAlt;
Servo OnSolUst;
Servo OnSolAlt;
//________ARKA____________//
Servo ArkaSagUst;
Servo ArkaSagAlt;
Servo ArkaSolUst;
Servo ArkaSolAlt;

#define irUp  16718055
#define irDown 16730805
#define irRight 16734885
#define irLeft 16716015
#define irOK 16726215
#define ir1 16753245
#define ir2 16736925
#define ir3 16769565
#define ir4 16720605
#define ir5 16712445
#define ir6 16761405
#define ir7 16769055
#define ir8 16754775
#define ir9 16748655
#define ir0 16750695
#define irStar 16738455
#define irPound 16756815

int irReceiver = 12;       
IRrecv irrecv(irReceiver); 
decode_results results;


void setup() {
  //__________ÖNLER____________//
  OnSagUst.attach(2);
  OnSagAlt.attach(3);
  OnSolUst.attach(4);
  OnSolAlt.attach(5);
  //__________ARKALAR_____________//
  ArkaSagUst.attach(6);
  ArkaSagAlt.attach(7);
  ArkaSolUst.attach(8);
  ArkaSolAlt.attach(9);

  irrecv.enableIRIn(); 

  Serial.begin (9600);

}

void loop() {

  unsigned long value;
  unsigned long lastValue;
  
  center();  // Center all servos


  while (1 == 1)    // Loop forever
  {
    if (irrecv.decode(&results)) // If we have received an IR signal
    {
      value = results.value;
      Serial.print("Gelen deger : ");
      Serial.println(value);

      switch (value)
      {
        case irUp:
          lastValue = irUp;
          forward();
          break;

        case irDown:
          lastValue = irDown;
          back();
          break;

        case irRight:
          lastValue = irRight;
          right();
          break;

        case irLeft:
          lastValue = irLeft;
          left();
          break;

        case irOK:
          center();
          lastValue = irOK;
          break;

        case ir1:
          lastValue = ir1;
          upOpen();
          break;

        case ir2:
          lastValue = ir2;
          upClose();
          break;

        case ir3:
          lastValue = ir3;
          sitDown();
          break;

        case ir4:
          lastValue = ir4;
          getUp();
          break;

        case ir5:
          lastValue = ir5;
          wave();
          break;

        case ir6:
          lastValue = ir6;
          respect();
          break;

        case ir7:
          lastValue = ir7;
          solider();
          break;

        case ir8:
          lastValue = ir8;
          center();
          break;

        case ir9:
          lastValue = ir9;
          break;

        case ir0:
          lastValue = ir0;
          center();
          break;

        case irStar:
          lastValue = irStar;
          solider();
          break;

        case irPound:
          lastValue = irPound;
          hello();
          break;

        default:
          break;
      }

      irrecv.resume(); //next value
      delay(200);  // Pause for 50ms before executing next movement

    }// if irrecv.decode
  }//while







}

void center(){
  ArkaSagUst.write(90);
  ArkaSolUst.write(90);
  OnSagUst.write(90);
  OnSolUst.write(90);//
  delay(100);
  ArkaSagAlt.write(35);
  ArkaSolAlt.write(150);
  OnSagAlt.write(150);
  OnSolAlt.write(35);//
  delay(100);
}


void right(){
  ArkaSagAlt.write(90);
  delay(100);
  ArkaSagUst.write(130);
  delay(100);
  ArkaSagAlt.write(35);
  delay(100);
  center();

  OnSolAlt.write(90);
  delay(100);
  OnSolUst.write(135);
  delay(100);
  OnSolAlt.write(35);
  delay(100);
  center();

  ArkaSolAlt.write(90);
  delay(100);
  ArkaSolUst.write(135);
  delay(100);
  ArkaSolAlt.write(160);
  delay(100);
  center();

  OnSagAlt.write(90);
  delay(100);
  OnSagUst.write(140);
  delay(100);
  OnSagAlt.write(160);
  delay(100);
  center();

}

void left(){
  ArkaSolAlt.write(90);
  delay(100);
  ArkaSolUst.write(50);
  delay(100);
  ArkaSolAlt.write(160);
  delay(100);
  center();

  OnSagAlt.write(90);
  delay(100);
  OnSagUst.write(45);
  delay(100);
  OnSagAlt.write(160);
  delay(100);
  center();

  ArkaSagAlt.write(90);
  delay(100);
  ArkaSagUst.write(45);
  delay(100);
  ArkaSagAlt.write(35);
  delay(100);
  center();

  OnSolAlt.write(90);
  delay(100);
  OnSolUst.write(40);
  delay(100);
  OnSolAlt.write(35);
  delay(100);
  center();

}

void back(){
  ArkaSagAlt.write(90);
  delay(100);
  ArkaSagUst.write(130);
  delay(100);
  ArkaSagAlt.write(35);
  delay(100);
  center();

  OnSolAlt.write(90);
  delay(100);
  OnSolUst.write(40);
  delay(100);
  OnSolAlt.write(35);
  delay(100);
  center();

  ArkaSolAlt.write(90);
  delay(100);
  ArkaSolUst.write(50);
  delay(100);
  ArkaSolAlt.write(160);
  delay(100);
  center();

  OnSagAlt.write(90);
  delay(100);
  OnSagUst.write(140);
  delay(100);
  OnSagAlt.write(160);
  delay(100);
  center();
}

void forward(){
  ArkaSagAlt.write(90);
  delay(100);
  ArkaSagUst.write(45);
  delay(100);
  ArkaSagAlt.write(35);
  delay(100);
  center();

  OnSolAlt.write(90);
  delay(100);
  OnSolUst.write(135);
  delay(100);
  OnSolAlt.write(35);
  delay(100);
  center();

  ArkaSolAlt.write(90);
  delay(100);
  ArkaSolUst.write(135);
  delay(100);
  ArkaSolAlt.write(160);
  delay(100);
  center();

  OnSagAlt.write(90);
  delay(100);
  OnSagUst.write(45);
  delay(100);
  OnSagAlt.write(160);
  delay(100);
  center();
}

void upOpen(){
  //Ust servolar acilma
  ArkaSagUst.write(120);
  ArkaSolUst.write(60);
  OnSagUst.write(60);
  OnSolUst.write(120);//
  delay(100);

}
void upClose(){
  //Ust servolar kapanma
  ArkaSagUst.write(60);
  ArkaSolUst.write(120);
  OnSagUst.write(120);
  OnSolUst.write(60);//
  delay(100);
}

void sitDown(){
  // Bacaktaki servolar asagi inme
  ArkaSagAlt.write(70);
  ArkaSolAlt.write(110);
  OnSagAlt.write(110);
  OnSolAlt.write(70);//
  delay(100);
}

void getUp(){
  // Bacaktaki servolar asagi kalkma
  ArkaSagAlt.write(0);
  ArkaSolAlt.write(180);
  OnSagAlt.write(180);
  OnSolAlt.write(0);//
  delay(100);
}

void solider(){
  center();
  delay(1000);
  upOpen(); 
  delay(1000);
  upClose();
  
  delay(1000);
  sitDown();
  delay(1000);
  getUp();
  delay(1000);
  center();
}

void respect(){
  center();
  for(int i=0; i<30; i++){
    ArkaSagUst.write(90+i);
    ArkaSolUst.write(90-i);
    delay(10);
  }
  for(int i=0; i<35; i++){
    ArkaSagAlt.write(35-i);
    ArkaSolAlt.write(145+i);
    delay(10);
  }
  for(int i=0; i<45; i++){
    OnSagAlt.write(145-i);
    OnSolAlt.write(35+i);
    delay(10);
  }
  delay(1500);
  for(int i=0; i<100; i++){
    OnSagAlt.write(100+i);
    OnSolAlt.write(85-i);
    delay(10);
  }
  for(int i=0; i<75; i++){
    ArkaSagAlt.write(i);
    ArkaSolAlt.write(180-i);
    delay(20);
  }
  delay(1500);
  center();

}

void wave(){
  upClose();
  getUp();
  for(int i=0; i<110; i++){
    ArkaSagAlt.write(i);
    OnSagAlt.write(180-i);
    delay(10);
  }
  for(int i=0; i<110; i++){
    ArkaSolAlt.write(180-i);
    OnSolAlt.write(i);
    delay(10);
  }
  upOpen();
  upClose();
  for(int i=0; i<110; i++){
    ArkaSolAlt.write(70+i);
    OnSolAlt.write(110-i);
    delay(10);
  }
  for(int i=0; i<110; i++){
    ArkaSagAlt.write(110-i);
    OnSagAlt.write(70+i);
    delay(10);
  }

}



void hello(){
  ArkaSagUst.write(60);
  delay(100);
  ArkaSolUst.write(90);
  delay(100);
  OnSagUst.write(90);
  delay(100);
  OnSolUst.write(120);//
  delay(100);
  ArkaSagAlt.write(45);
  delay(100);
  ArkaSolAlt.write(135);
  delay(100);
  OnSagAlt.write(135);
  delay(100);
  OnSolAlt.write(45);//
  delay(100);
  OnSagAlt.write(50);
  delay(100);
  for(int a=0; a<3; a++){
    for(int i=90; i>20; i--){
    OnSagUst.write(i);
    delay(15);
    }
    for(int i=20; i<100; i++){
      OnSagUst.write(i);
      delay(15);
    }
  }
  center();
  
}
