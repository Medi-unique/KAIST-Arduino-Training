#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 20, 4);
int count=0;

void setup()
{
  lcd.init();
  lcd.backlight();

  for (int i=0; i<20; i++) {
    if (i < 4) {                      // Edit this line
      for (int j=0; j<i+1; j++) {
        lcd.setCursor(i-j,j);          // Edit this line
        lcd.print("*");
      }
    }

    else {
      for (int j=0; j<4; j++) {
        lcd.setCursor(i-j,j);         // Edit this line
        lcd.print("*");
      }
    }

    delay(500);
  }
}

void loop() {}