#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 20, 4);

int minutes = 0;
int seconds = 0;
int miliseconds = 0;

long previous_time; // needed to check how much time has passed

char buffer[10]; // needed to print the time values

bool running = true; // needed to check whether the stopwatch should be running or not. The initial value is true.

void setup() {
  pinMode(2, INPUT); // stop button
  pinMode(3, INPUT); // start button
  pinMode(4, INPUT); // reset button

  lcd.init();
  lcd.backlight();

  lcd.clear();

  previous_time = millis();
}

void time_difference() { // a function that update the time values while the stopwatch is running
  if (millis() - previous_time >= 100) { // update the time values every 100 milliseconds 
    previous_time = millis();

    // TODO: Update the time values
    // 1. Update the value "miliseconds"
    if(miliseconds++==9){
      miliseconds=0;
      ++seconds;
    }
    if(seconds==59)
    {
      seconds=0;
      ++minutes;
    }
    
    // 2. If the value of "milisencods" exceeds 9(actually 900), reset the value of "milisencods" and update the value of "seconds"
    // 3. If the value of "seconds" exceeds 59, reset the value of "seconds" and update the value of "minutes"








    // TODO: Print present time (using setCursor(), sprintf(), lcd.print())
    // use the vairable "buffer", which is already defined in line 12
lcd.setCursor(2,1);
 sprintf(buffer,"%02d %02d %d00",minutes,seconds,miliseconds);
 lcd.print(buffer);




  }
}

void loop() {
  if (digitalRead(2) == HIGH) {
    // TODO: Stop button - control the variable "running"
    running=false;

  }

  if (digitalRead(3) == HIGH) {
    // TODO: Start button - control the variable "running"
        running=true;


  }

  if (digitalRead(4) == HIGH) {
    miliseconds=0;
    seconds=0;
    minutes=0;

    // TODO: Reset button
    // 1. Reset the time variables (minutes, seconds, miliseconds)
    // 2. Print present time (using setCursor(), sprintf(), lcd.print())
    // lcd.setCursor(3, 3);
    //   sprintf(buffer,"%20d %20d %d00",minutes,seconds,miliseconds);
    //   lcd.print(buffer);

  }

  if (running) {
    time_difference();
  }
}
