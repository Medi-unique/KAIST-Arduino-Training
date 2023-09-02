#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 20, 4);

int trigPin = 6;
int echoPin = 7;

char buffer[20]; // to print the distance

/*
  TODO: replace ??? into right code
*/ 

void setup() {
  pinMode(???, INPUT);   // echoPin for input   
  pinMode(???, OUTPUT);  // trigPin for output

  lcd.init();
  lcd.backlight();
}

void loop() {
  long duration, distance;

  digitalWrite(???, HIGH);  // emit ultrasonic in trigPin    
  delayMicroseconds(10);
  digitalWrite(???, LOW);

  duration = pulseIn(???, HIGH);    // saves the time when echoPin held HIGH
  distance = ???

  lcd.setCursor(0, 0);
  sprintf(buffer, "Distance: %4ld mm", distance);
  lcd.print(buffer);

  delay(1000);   // print distance every 1 sec
}


