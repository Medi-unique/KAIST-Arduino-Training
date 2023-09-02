#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 20, 4);

/* 1. Set the global variable if you want */
/* ex. char a;                            */
/* --------- write here below------------- */
unsigned long int n;
unsigned long int oddSum = 0;
unsigned int i=1; // count fromo one to n, pm

/* ---------------------------------------*/

void setup()
{
  lcd.init();
  lcd.backlight();
  /* 2. initialize the anything in setup() if you want */
  /* ---------------- write here below---------------- */
  n = 100; // sum of odds from 1 to n
 

  /* -------------------------------------------------- */
}

void loop()
{
  /* 3. using the loop()*/
  /* hint 1) use while algorithm, which is while alorithm is smilar as loop() */
  /* hint 2) %lu : unsigned long int, %u : unsigned short int, %d : short int */
  /* hint 3) delay(100) to express the sum process. */
  /* -----------------------write here below ---------------------------------*/
  
  lcd.setCursor(0, 1);
  char buffer[20];
  sprintf(buffer, "SUM odds 1~%lu ",n);
  lcd.print(buffer);
   for (i;i<n;i=i+2){
     oddSum +=i;
     lcd.setCursor(1, 2);
     lcd.print(oddSum);
     delay(100);
     
     
  }
  // exit(0);
  lcd.setCursor(1, 3);
  lcd.print("completed!");

  /* --------------------------------------------------------------------------*/

}