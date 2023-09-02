#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 20, 4);

void setup()
{
  lcd.init();
  lcd.backlight();

  /*
    IMPORTANT! READ BEFORE PROCEEDING!!
    Change 'number' and 'N' to any number you like (N must be lower than 10)
  */
  int arr[20];

  int number = 565;
  int N = 8;
 

  int column = 19;
  

  while (number > 0) {
  
    int mod =number%N;
    int div=number/N;

    lcd.setCursor(column, 0);
 
  lcd.print(mod);
  number=div;
  column--;
}
   
 // Only add code here!
    
  }
  

// DO NOT TOUCH
void loop() {}