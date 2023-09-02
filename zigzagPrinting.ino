#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 20, 4);

void setup()
{
  lcd.init();
  lcd.backlight();

  int j = 0;
  int k = 1;

  for (int i=0; i<20; i++) {
    
    lcd.setCursor(i, j);

    lcd.print("*");

    if (j == 0) {   // Edit this line
      k = 1;        // Edit this line
    }

    if (j == 3) {   // Edit this line
      k = -1;        // Edit this line
    }

    j = j + k;

    delay(500);
  }
}

void loop() {}