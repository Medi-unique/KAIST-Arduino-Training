#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 20, 4);

void setup()
{
  lcd.init();
  lcd.backlight();

  for (int i=0; i<10; i++) {
    if (i < 4) {                  // Edit this line
      lcd.setCursor(10-i, i);        // Edit this line
      for (int j=0; j<2*i+1; j++) {   // Edit this line
        lcd.print("*");
      }
    }

    else {
      for (int j=0; j<4; j++) {
        lcd.setCursor(13-i-j, j);     // Edit this line
        lcd.print("*");
        lcd.setCursor(7+i+j, j);     // Edit this line
        lcd.print("*");
      }
    }

    delay(500);
  }
}

void loop() {}