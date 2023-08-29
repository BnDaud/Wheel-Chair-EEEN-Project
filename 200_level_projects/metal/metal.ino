#include<Servo.h>

Servo myservo;

int m = 5 ;
int n = 3;
int p = 6;
int q = 9;

void setup() {
  pinMode(n , OUTPUT);
  pinMode(m , OUTPUT);
  pinMode(p , OUTPUT);
  pinMode(q , OUTPUT);
  myservo.attach(10);
  pinMode(A0 , INPUT);
  pinMode(A1 , INPUT);
   pinMode(A2 , INPUT);
  pinMode(A3 , INPUT);
  
    

  Serial.begin(9600);
  }

void move_motor(int move_f , int move_b){
  
 
  if (move_f > move_b){
    Serial.print("The chair moves forward by : ");
    Serial.println(move_f);
    digitalWrite(m  , HIGH);
    digitalWrite(n , HIGH);
  }
  else if(move_b > move_f){
    Serial.print("The chair moves backward: ");
    Serial.println(move_b);
    digitalWrite(p , HIGH);
    digitalWrite(q , HIGH);
  }
  else{
    Serial.println("The chair is not moving ");
    
    digitalWrite(m ,LOW);
    digitalWrite(n, LOW);
    digitalWrite(p ,LOW);
    digitalWrite(q, LOW);
    
  }


}
int move_f = 0;
int move_b = 0;
int turn_right = 0;
int turn_left = 0;


void loop() {
  move_f = analogRead(A0);
  move_b = analogRead(A1);
  
  turn_right = analogRead(A2);
  turn_left = analogRead(A3);
  if(turn_right > turn_left){
    Serial.print("The chair is turning right");
    myservo.write(45);
  }
  else if(turn_left > turn_right){
    Serial.print("The chair is turning left");
    myservo.write(135);
  }
  else{
    Serial.print("No Turn :");
    myservo.write(90);
  }
  move_motor(move_f ,move_b);
  
  // put your main code here, to run repeatedly:

}
