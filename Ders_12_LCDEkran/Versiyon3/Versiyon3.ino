#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
void setup() {
lcd.begin(16, 2);
lcd.print("hello, world!");
}
void loop() {
lcd.cursor();//yanım sönen imleci açar
delay(500);
lcd.noCursor();
delay(500);
}
