/*
 * 201924451_김태훈_HW7_1_Video Link
 */
int LED_pins[] = {2,3,4,5};
int photoregister = 56;
int pattern = 0;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  for(int i=0;i<4;i++){
    pinMode(LED_pins[i],OUTPUT);
    digitalWrite(LED_pins[i],LOW);
  }
}
/*
 * 0-150 : LED 0개(0b0000), 
 * 151~369 : LED 1개(0b0001), 
 * 370~588 : LED 2개(0b0011), 
 * 589~807 : LED 3개(0b0111), 
 * 808~1024 : LED 4개(0b1111)
 */
void loop() {
  // put your main code here, to run repeatedly:
  int value = analogRead(photoregister);
  Serial.print("value : ");
  Serial.println(value);//for debugging
  if(0<=value && value<=150)
    pattern = 0;
  else if(151<=value && value<=369)
    pattern = 1;
  else if(370<=value && value<=588)
    pattern = 3;
  else if(589<=value && value<=807)
    pattern = 7;
  else
    pattern = 15;

  for(int i=0;i<4;++i){
    digitalWrite(LED_pins[i],pattern&(0x01<<i));
  }
  delay(10);
}
