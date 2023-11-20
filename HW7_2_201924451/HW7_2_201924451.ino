/*
 * 201924451_김태훈_HW7_2_Video Link
 */
#include <pitches.h>

int speakerpin = 57;
int sound[]={0,NOTE_C4, NOTE_D4, NOTE_E4, NOTE_F4, NOTE_G4, NOTE_A4, NOTE_B4, NOTE_C5};
void setup() {
  // put your setup code here, to run once:
  pinMode(A0,INPUT);
  pinMode(13,OUTPUT);
  digitalWrite(13,LOW);
}

void loop() {
  // put your main code here, to run repeatedly:
  int adc = analogRead(A0);
  int sound_index = map(adc,0,1023,0,8);
  tone(speakerpin,sound[sound_index],250);

  //for debugging
  if(sound_index==0)
    digitalWrite(13,LOW);
  else
    digitalWrite(13,HIGH);
}
