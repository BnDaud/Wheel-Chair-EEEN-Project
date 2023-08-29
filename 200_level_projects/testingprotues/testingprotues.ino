/* Sweep
 by BARRAGAN <http://barraganstudio.com>
 This example code is in the public domain.

 modified 8 Nov 2013
 by Scott Fitzgerald
 https://www.arduino.cc/en/Tutorial/LibraryExamples/Sweep
*/

#include <Servo.h>
#include <LiquidCrystal.h>



const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);


Servo myservo; 
Servo myservo2; // create servo object to control a servo
// twelve servo objects can be created on most boards

int ldr1 = 0;    // variable to store the servo position
int ldr2 = 0;


void setup() {
  myservo.attach(9);
  myservo2.attach(10); 
  lcd.begin(16 ,2);
   // attaches the servo on pin 9 to the servo object
}




int angle1 = 60;
int angle2 = 120;

void loop() {
    ldr1 = analogRead(A0);
    ldr2 = analogRead(A1);

    if (ldr1 > ldr2){
      // this means the sun is just raising i.e we are in the morning
      myservo.write(angle1);
      myservo2.write(angle2);
    }

    else if (ldr2 > ldr1 ){
      // this means the sun is going to set i.e evening is approaching 
      myservo.write(angle2);
      myservo2.write(angle1);
    }


    lcd.setCursor(0,0);
    lcd.print("LDR 1 reads= ");
    lcd.println(ldr1);
    lcd.setCursor(0,1);
    lcd.print("LDR 2 reads= ");
    lcd.println(ldr2);

  
}


