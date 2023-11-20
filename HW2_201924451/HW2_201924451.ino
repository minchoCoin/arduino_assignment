//HW2 - 201924451
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println("Enter 2 Integer to add");
  int sum;
  long val1;
  long val2;
  //scan value
  while(Serial.available()==0){}
  val1 = Serial.parseInt();

  Serial.read();
  while(Serial.available()==0){}
  val2 = Serial.parseInt();
  
  sum=val1 + val2;
    
  //print result
  Serial.print(val1);
  Serial.print(" + ");
  Serial.print(val2);
  Serial.print(" = ");
  Serial.println(sum);
  
  Serial.read();
}
