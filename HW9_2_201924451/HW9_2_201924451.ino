/*
 * 201924451_김태훈_HW9_2 Video Link
 */
int Enable1 = 38;
int PWM1 = 9;
int DIR1 = 39;
int button = 14;
int i=0;
int state[] = {255,50,0};
void setup() {
  // put your setup code here, to run once:
  pinMode(Enable1,OUTPUT);
  pinMode(PWM1,OUTPUT);
  pinMode(DIR1,OUTPUT);

  digitalWrite(DIR1,true);
  digitalWrite(Enable1,HIGH);
  digitalWrite(PWM1,true);

  pinMode(button,INPUT);
  Serial.begin(9600);
  Serial.println("Test Start");
  Serial.println(state[i]);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(digitalRead(button)==HIGH){
    i++;
    if(i>2){
      i=0;
    }
    analogWrite(PWM1,state[i]);
    Serial.println(state[i]);
    delay(500);
  }
}
