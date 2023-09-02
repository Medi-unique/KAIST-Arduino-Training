#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#define LEFT 2
#define DOWN 3
#define UP 4
#define RIGHT 5

LiquidCrystal_I2C lcd(0x27, 20, 4);

int location_x;
int location_y;

int prev_location_x;
int prev_location_y;

long prev_time;

bool button_pressed;

byte player[8] ={
  // TODO: make your own custom character for your player
  B01110,
  B10001,
  B11011,
  B11011,
  B11011,
  B10101,
  B01110,
    

  

};

void reset() {
  location_x = 0;
  location_y = 0;
  prev_location_x = 1;
  prev_location_x = 1;

  prev_time = millis();
  button_pressed = false;
}

void setup() {
  pinMode(LEFT, INPUT);
  pinMode(DOWN, INPUT);
  pinMode(UP, INPUT);
  // pinMode(RIGHT, INPUT);

  lcd.init();
  lcd.backlight();

  lcd.createChar(1, player);
  lcd.begin(20, 4);

  reset();
}

void render_player() {
  if (location_x != prev_location_x || location_y != prev_location_y) {
    // TODO: print player on the right location
    // 1. Remove the previous rendered player and render a new player
      lcd.setCursor(prev_location_x, prev_location_y);
      lcd.print(" ");
      lcd.setCursor(location_x,location_y);
      lcd.write(byte(1));

 
    // 2. Update the prev_location variables
    prev_location_x =location_x ;
  prev_location_y=location_y ;




  }
}

void loop() {
  if (digitalRead(LEFT) == HIGH && !button_pressed) {
    button_pressed = true;
     location_x = max(location_x+1,0 );
  }
   if (digitalRead(UP) == HIGH && !button_pressed) {
    button_pressed = true;
     location_y = min(location_y-1,0 );
  }
   if (digitalRead(DOWN) == HIGH && !button_pressed) {
    button_pressed = true;
     location_y = max(location_y+1,0 );
  }
  //  if (digitalRead(RIGHT) == HIGH && !button_pressed) {
  //   button_pressed = true;
  //    location_x = max(location_x-1,0 );
  // }

  // TODO: write code for DOWN, UP, and RIGHT buttons refer to the LEFT button code above








  if (millis() - prev_time >= 200) {
    prev_time = millis();
    button_pressed = false;
    render_player();
  }
}
