#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 20, 4);


/* 1. Set the global variable if you want */
/* ex. char a;                            */
/* --------- write here below------------- */
int count=0;
int i=0;
int j=0;

/* ---------------------------------------*/

void setup()
{
  lcd.init();
  lcd.backlight();
  /* 2. initialize the anything in setup() if you want */
  /* ---------------- write here below---------------- */


  /* -------------------------------------------------- */
}

void loop()
{
  /* 3. using the loop()*/
  /* hint 1) use for loop */
  //  if(count<=4){
  
  // for(int i=0;i<5;i++){
    
  //     for(int j=0;j<i;j++){
  //       lcd.setCursor(j,i);
      
      
  //     lcd.print("*");
  //   }
  // delay(1000);
  //  count++;
    
  // }
  // }
  // else if(count>=3)
  
  
  /* hint 2) set the variable count, and use if statement to sperate the case. */
  /* -----------------------write here below ---------------------------------*/
  if(count<=3){
    for(i;i<=count;i++){
    lcd.setCursor(i, count);
    lcd.print("*");
    i++;
    
    }
    count++;
    delay(1000);



  }


  /* --------------------------------------------------------------------------*/

}