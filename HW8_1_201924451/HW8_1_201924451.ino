//Common Cathode Type
/*
 * 201924451_김태훈_HW8_1_Video_Link
 */
// 0에서 9까지 숫자 표현을 위한
// 세그먼트 a, b, c, d, e, f, g, dp의 패턴
byte patterns[] = {
  0b11111100, 0b1100000, 0b11011010, 0b11110010,
  0b01100110, 0b10110110, 0b10111110, 0b11100100, 0b11111110, 0b11100110
};
int digit_select_pin[] = {66, 67, 68};
// 7세그먼트 모듈 연결 핀 ‘a, b, c, d, e, f, g, dp’ 순서
int segment_pin[] = {58, 59, 60, 61, 62, 63, 64, 65};
int SEGMENT_DELAY = 5; // 숫자 표시 사이의 시간 간격
unsigned long time_previous, time_current;
int minutes = 0, seconds = 0;
int number3=0;
int button_pin = 14;
int state = 1;
// 해당 자리에 숫자 하나를 표시하는 함수
void show_digit(int pos, int number) { // (위치, 출력할 숫자)
  for (int i = 0; i < 3; i++) {
    if (i + 1 == pos) // 해당 자릿수의 선택 핀만 LOW로 설정
      digitalWrite(digit_select_pin[i], LOW);
    else // 나머지 자리는 HIGH로 설정
      digitalWrite(digit_select_pin[i], HIGH);
  }
  for (int i = 0; i < 8; i++) {
    boolean on_off = bitRead(patterns[number], 7 - i);
    digitalWrite(segment_pin[i], on_off);
  }
}

// 3자리 7세그먼트 표시 장치에 3자리 숫자를 표시하는 함수
void show_3_digit(int number) {
  number = number % 1000;
  int hundreads = number / 100; // 백 자리
  number = number % 100;
  int tens = number / 10; // 십 자리
  int ones = number % 10; // 일 자리
  show_digit(1, hundreads);
  delay(SEGMENT_DELAY);
  show_digit(2, tens);
  delay(SEGMENT_DELAY);
  show_digit(3, ones);
  delay(SEGMENT_DELAY);
}
void setup() {
  for (int i = 0; i < 3; i++) { // 자릿수 선택 핀을 출력으로 설정
    pinMode(digit_select_pin[i], OUTPUT);
  }
  for (int i = 0; i < 8; i++) { // 세그먼트 제어 핀을 출력으로 설정
    pinMode(segment_pin[i], OUTPUT);
  }
  pinMode(button_pin,INPUT);
  time_previous = millis();
  show_3_digit(number3);
}


void loop() {
  // put your main code here, to run repeatedly:
  time_current = millis();
  if(time_current - time_previous >=1000){
    time_previous = time_current;
    if(state == 1)
      number3++;
    else
      number3--;

    if(number3>999)
      number3 = 0;
    else if(number3<0)
      number3 = 999;
  }
  if(digitalRead(button_pin) == LOW){
    state = !state;
    delay(10);
  }
    
  show_3_digit(number3);
}
