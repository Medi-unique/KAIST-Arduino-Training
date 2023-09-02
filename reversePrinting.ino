#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 20, 4);

unsigned int number = 565;
unsigned int N = 8;

unsigned int col = 19;

void setup()
{
  pinMode(2,INPUT); // Edit this line

  lcd.init();
  lcd.backlight();

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(number);
}

void loop()
{
  if (digitalRead(2) == HIGH) { // Edit this line
    if ( number>0) { // Edit this line by using LAB13. 
     
  
    int mod =number%N;
    int div=number/N;

    lcd.setCursor(col, 1);
 
  lcd.print(mod);
  number=div;
  col--;
// Bring your code in LAB13.

      lcd.setCursor(0, 0);
      lcd.print("                    ");
      lcd.setCursor(0, 0);
      lcd.print(div); // Edit this line
      delay(300);
    }
  }
}