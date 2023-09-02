#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 20, 4);

int trigPin = 6;
int echoPin = 7;

int location_x;
int location_y;

int prev_location_x;
int prev_location_y;

long prev_time;

byte player[8] ={   // you can chage the shape whatever you want
  B01110,
  B01110,
  B01110,
  B00101,
  B11111,
  B10100,
  B01110,
  B01010
};

void reset() {
  location_x = 0;
  location_y = 0;
  prev_location_x = 1;
  prev_location_y= 1;

  prev_time = millis();
}

void setup() {
  pinMode(echoPin, INPUT);   // echoPin for input   
  pinMode(trigPin, OUTPUT);  // trigPin for output

  lcd.init();
  lcd.backlight();

  lcd.createChar(1, player);
  lcd.begin(20, 4);

  reset();
}

void render_player() {
  lcd.setCursor(prev_location_x, prev_location_y);
  lcd.print(' ');
  lcd.setCursor(location_x, location_y);
  lcd.write(byte(1));

  prev_location_x = location_x;
  prev_location_y = location_y;
}

void loop() {
  if (millis() - prev_time >= 500) {
    long distance,duration;

    // TODO: measure the distance using sonar sensor and update the player's location value
    // 1. write the code that calculate the distance using sonar sensor right below this line
     digitalWrite(6, LOW);  // emit ultrasonic in trigPin    
  delayMicroseconds(10);
  digitalWrite(6, HIGH);

  duration = pulseIn(7, HIGH);
    distance = ((int)(340 * prev_time) / 1000) / 2;






    // 2. chage ??? to the right code
    if (distance < 50) {             // player move to the right
      location_x = min( location_x+1, 19);
    } else if (distance < 100) {     // player move to the down
      location_y = min(location_y+1, 3);
    } else if (distance < 150) {     // player move to the left
      location_x = max( location_x-1, 0);
    } else {                         // player move to the up
      location_y = max(location_y-1, 0);
    }
    
    prev_time = millis();
    render_player();
  }
}
