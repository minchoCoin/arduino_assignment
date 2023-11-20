/*
 * 201924451_김태훈_HW9_1_Video Link
 */
#include <Servo.h>
Servo myServo;
int servoPin = 11;
int button_up = 14;
int button_down = 15;
int angle = 0;
void setup() {
  // put your setup code here, to run once:
  pinMode(button_up,INPUT);
  pinMode(button_down,INPUT);
  myServo.attach(servoPin);
  myServo.write(angle);
  delay(100);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(digitalRead(button_up) == HIGH){
    angle+=10;
    if(angle>180){
      angle = 180;
    }
    myServo.write(angle);
    delay(250);
  }
  else if(digitalRead(button_down) == HIGH){
    angle-=10;
    if(angle<0){
      angle = 0;
    }
    myServo.write(angle);
    delay(250);
  }
}
