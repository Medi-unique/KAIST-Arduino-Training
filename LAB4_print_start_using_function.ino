#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 20, 4);

void f() {
  /* --------------------------write here below--------------------------------*/
  // for (int i=0;i<3;i++){
  //   for (int j=0;j<4;j++){
  //   lcd.print("*");}
  //   lcd.println();
    
  // }

  /* ------------------------------------------------------------------------- */


}


void setup() {
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
 

}

void loop() {
    lcd.print("*");
  delay(100);
  /* Do not use the loop() in this task.*/
}
