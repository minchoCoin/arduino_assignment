/*
 * 201924451_김태훈_HW5_Video Link
 */
int LED_pins[] = {2,3,4,5};
int PWM_value[] = {0,63,127,191};
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
    analogWrite(LED_pins[i],PWM_value[i]);
    PWM_value[i] += 5;
    if(PWM_value[i]>255){
      PWM_value[i]=0;
    }
    Serial.print(PWM_value[i]);//for debugging
    Serial.print(" ");
  }
  Serial.println();
  delay(60);
}
