#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 20, 4);

// Example character: heart
byte heart[8] ={
  B00000,
  B01010,
  B11111,
  B11111,
  B01110,
  B00100,
  B00000,
  B00000
};

// TODO: Make your own custom character
// set a name for it ex) heart
// byte 'name'[8] = {}
byte m[8]={


  B00000,
  B00000,
  B10001,
  B10101,
  B10001,
  B10001,
  B00000,
  B00000
};




void setup() {
  lcd.init(); // initialize the LCD
  lcd.backlight(); // Turn on the backlight on the LCD 

  // TODO: Print out the custom characters
  // using the function lcd.createChar() & lcd.begin() & lcd.write()
  lcd.createChar(1,m);
  lcd.createChar(2,heart);
  lcd.begin(3,5);
  lcd.write(1);
  //  lcd.begin(3,7);
  lcd.write(2);




  
}

void loop() {
}
