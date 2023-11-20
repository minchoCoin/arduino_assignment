/*
 * 201924451_김태훈_HW4-2_Video Link
 */
int LED_pins[]={2,3,4,5};
int button_pin = 14;
boolean is_forward=true;
boolean state_previous = false;
boolean state_current;
int pattern = 1;
void setup() {
  // put your setup code here, to run once:
  for(int i=0;i<4;++i){
    pinMode(LED_pins[i], OUTPUT);
    digitalWrite(LED_pins[i],LOW);
  }
  pinMode(button_pin,INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  state_current = digitalRead(button_pin);
  if(state_current){
    if(state_previous ==false){
      state_previous = true;
      is_forward  = !is_forward;
    }
  }
  else{
    state_previous = false;
  }
  
  for(int i=0;i<4;++i){
      digitalWrite(LED_pins[i],pattern &(0x01 <<i));
    }//if pattern is 0001, LED_pins[0] is on, others is off.
    
  if(is_forward){//if is_forward == true, LED turns 2->3->4->5 on
    pattern = pattern<<1;//0b0001->0b0010->0b0100->0b1000
  }
  else{
    pattern = pattern>>1;
  }
  if(pattern >8){
      pattern=1;
  }//0b10000
  else if(pattern <= 0){
      pattern=8;
  }
  delay(500);
  
}
