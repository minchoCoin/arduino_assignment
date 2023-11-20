int LED_pins[] = {2,3,4,5};
double angle[] = {asin(0.0/255.0),asin(63.0/255.0),asin(127.0/255.0),asin(191.0/255.0)};
int PWM_value[4] = {0,0,0,0};
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  for(int i=0;i<4;i++){
    pinMode(LED_pins[i],OUTPUT);
    analogWrite(LED_pins[i],PWM_value[i]);
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  for(int i=0;i<4;i++){
    PWM_value[i] = int(255.0* sin(angle[i]));
  }
  for(int i=0;i<4;i++){
    analogWrite(LED_pins[i],PWM_value[i]);
    angle[i] = angle[i] + PI/180.0;
    if(angle[i]>PI/2.0){
      angle[i]=0.0;
    }
    Serial.print(PWM_value[i]);
    Serial.print(" ");
  }
  Serial.println();
  delay(50);
}
