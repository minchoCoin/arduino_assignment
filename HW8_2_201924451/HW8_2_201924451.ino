/*
 * 201924451_김태훈_HW8_2_201924451_Video_Link
 */
#include <LiquidCrystal.h>
LiquidCrystal lcd(44,45,46,47,48,49);

byte celcius[8] = {
  B11000,
  B11000,
  B00110,
  B01001,
  B01000,
  B01001,
  B00110,
  B00000
};

float readTemperature() {
// 온도 센서 읽기
 int reading = analogRead(A1); 
  float voltage = reading * 5.0 / 1024.0;
  float temp_C = voltage * 100;
  return temp_C;
}
float readIlluminance() {
// 조도 센서 읽기
  int reading = analogRead(A2); 
  float voltage = reading * 5.0 / 1024.0;
  return voltage;
}

void setup() {
  // put your setup code here, to run once:
  lcd.createChar(0,celcius);
  lcd.begin(16,2);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.write("temp:");
  lcd.setCursor(0,1);
  lcd.write("Light:");
  
}

void loop() {
  // put your main code here, to run repeatedly:
  lcd.setCursor(6,0);
  lcd.print(String(readTemperature()));
  lcd.write(byte(0));
  lcd.setCursor(7,1);
  lcd.print(String(readIlluminance()));
  delay(1000);
}
