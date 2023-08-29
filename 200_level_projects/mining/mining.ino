int m = 8 ;
int n = 7;
int p = 4;
int q = 2;

void setup() {
  pinMode(n , OUTPUT);
  pinMode(m , OUTPUT);
  pinMode(p , OUTPUT);
  pinMode(q , OUTPUT);
  }

void loop() {
  digitalWrite(p , LOW);
  digitalWrite(q , LOW);
  digitalWrite(n , HIGH);
  digitalWrite(m , HIGH);
  delay(5000);
  digitalWrite(m , LOW);
  digitalWrite(n , LOW);
  digitalWrite(p , HIGH);
  digitalWrite(q , HIGH);
  delay(5000);

  
  // put your main code here, to run repeatedly:

}
