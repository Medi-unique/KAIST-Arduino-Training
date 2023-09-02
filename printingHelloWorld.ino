#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 20, 4);

void setup() {
  /* 1. Set the initial setting and cursor for using LCD*/
  /* --------- write here below------------- */
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0,0);
  lcd.print("hello medi");
 



  /* ---------------------------------------*/


  /* 2. by using print function, print out your name */
  /* --------- write here below------------- */


  /* ---------------------------------------*/
}

void loop() {
}