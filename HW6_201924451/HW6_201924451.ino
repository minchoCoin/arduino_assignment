/*
 * 201924451_김태훈_HW6 Video Link
 */
int LED_pins[] = {2,3};
unsigned long time_previous[2], time_current[2];
unsigned long interval[]={1000,1000};
boolean LED_state[] = {false,false};
void setup() {
  // put your setup code here, to run once:
  pinMode(A0,INPUT);
  for(int i=0; i<2;++i){
    pinMode(LED_pins[i],OUTPUT);
    digitalWrite(LED_pins[i],LED_state[i]);
    time_previous[i] = millis();
  }
  Serial.begin(9600);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  for(int i=0;i<2;++i){
    time_current[i] = millis();
    if(time_current[i] - time_previous[i] >= interval[i]){
      Serial.print("current interval of LED pin ");
      Serial.print(LED_pins[i]);
      Serial.print(" is ");
      Serial.print(interval[i]);
      Serial.println("ms");

      time_previous[i] = time_current[i];
      LED_state[i] = !LED_state[i];
      digitalWrite(LED_pins[i], LED_state[i]);
    }
    int adc = analogRead(A0);
    interval[0] = map(adc,0,1023,1500,500);
    interval[1] = map(adc,0,1023,500,1500);
  }
}
