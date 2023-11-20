/*
 * 201924451_김태훈_HW3_동작 영상1
 * 201924451_김태훈_HW3_동작 영상2
 */
int pin_num[]={2,3,4,5};
int i,j;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  for(i=0;i<4;++i){
    pinMode(pin_num[i],OUTPUT);
    digitalWrite(pin_num[i],LOW);
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  int pattern=1, index=0, shift=0;
  boolean is_on;
  for(i=0;i<6;++i){//0 1 2 3 2 1
    if(index<4)
      shift=index;
    else
      shift=6-index;
    
    for(j=0;j<shift;++j){
      pattern = (pattern<<1) | 0x01; //0b0001->0b0011,0b0111,0b1111
    }

    for(j=0;j<4;++j){
      is_on = pattern & (0x01 <<j);//pattern에서 on/off 추출
      if(is_on){
        digitalWrite(pin_num[j],HIGH);
        Serial.print("O ");
      }
      else{
        digitalWrite(pin_num[j],LOW);
        Serial.print("X ");
      }
    }
    Serial.println();
    pattern=1;
    index++;
    delay(1000);
  }
}
