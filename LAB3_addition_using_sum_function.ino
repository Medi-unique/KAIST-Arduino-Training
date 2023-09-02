#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 20, 4);

int sum(int a, int b) {
/* --------------------------write here below--------------------------------*/
int sum = a + b;
return sum;
/* ------------------------------------------------------------------------- */
}

void setup() {
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0,0);

  lcd.print(sum(1,3));

}

void loop() {
  /* Do not use the loop() in this task.*/
}