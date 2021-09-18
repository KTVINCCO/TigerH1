void setup() 
{
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(7,OUTPUT);
  digitalWrite(4, HIGH);
  digitalWrite(5, HIGH);
  digitalWrite(6, HIGH);
  digitalWrite(7, HIGH);

  pinMode(8,OUTPUT);
  digitalWrite(8, LOW);

  pinMode(9,OUTPUT);
  pinMode(10,OUTPUT);
  pinMode(11,OUTPUT);
  analogWrite(9, 0);
  digitalWrite(10, LOW);
  digitalWrite(11, LOW);
}

void loop() 
{
  digitalWrite(4, LOW);
  delay(1000);
  digitalWrite(4, HIGH);
  digitalWrite(5, LOW);
  delay(1000);
  digitalWrite(5, HIGH);
  digitalWrite(6, LOW);
  delay(1000);
  digitalWrite(6, HIGH);
  digitalWrite(7, LOW);
  delay(1000);
  digitalWrite(7, HIGH);

  delay(1000);

  digitalWrite(8, HIGH);
  delay(1000);
  digitalWrite(8, LOW);

  delay(1000);

  analogWrite(9, 255);
  digitalWrite(10, LOW);
  digitalWrite(11, HIGH);
  delay(3000);
  analogWrite(9, 255);
  digitalWrite(10, HIGH);
  digitalWrite(11, LOW);
  delay(3000);
  analogWrite(9, 0);
  digitalWrite(10, LOW);
  digitalWrite(11, LOW);

  delay(1000);
  
}
