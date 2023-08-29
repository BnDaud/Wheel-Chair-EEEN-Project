#include<SoftwareSerial.h>

SoftwareSerial bt(5,6);

int L = 8;
int F = 9;
void setup() {
  //bt.begin(9600);
  pinMode( L , OUTPUT);
  pinMode(F , OUTPUT);
  Serial.begin(9600);
  pinMode(13 , OUTPUT);
  bt.begin(9600);

  // put your setup code here, to run once:

}

int lamp_state = 0;// by default lamp is switched off
int fan_state = 0; // also as the fan it off 

void loop() {
  while (bt.available()){
    digitalWrite(13 , HIGH);
    //Serial.println("Bluetooth is  connected !!!!");
      char m = bt.read();
      char n = bt.read();
      if( m == 'L'){
        digitalWrite(L , HIGH);
        }
      else if (m == 'l'){
          digitalWrite(L ,LOW);
      } // the lamp is switched on ;
      
      

      if( n == 'F'){
        digitalWrite(F , HIGH);
     // the fan is switched on ;
      
      }
      else if (n == "f"){
        digitalWrite(F , LOW);
         // the fan is off
      }


  }

}
