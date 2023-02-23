#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
void setup() {
lcd.begin(16, 2);
}
void loop() {
for (int x = 0; x <= 16; x++)
  {
    lcd.setCursor(x, 0);
    lcd.print("TUGVA");
    delay(500);
    lcd.clear();
  }
  for (int e = 16; e >= 0; e--)
  {
    lcd.setCursor(e, 0);
    lcd.print("Robotik Kodlama");
    delay(500);
    lcd.clear();
  }
}
