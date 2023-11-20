String words[5]={};

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}
void loop() {
  // put your main code here, to run repeatedly:
  int state = 1;
  char buffer[128];
  int i=0;
  //문자열 입력
  while (i<5) {
    if (state == 1) {
      Serial.print("Enter the " + String(i+1) + "th Word -->");
      state = 2;
    }
    while (Serial.available()) { 
      int len = Serial.readBytesUntil('\n', buffer, 127);
      if (len > 0) {     
        buffer[len] = '\0';
        words[i] = String(buffer);    
        Serial.println(words[i]);          
        state = 1;
        i++;
        break;
      }
      
    }
  }
  //문자열 정렬
  for(int j=0;j<5;++j){
    for(int k=j+1;k<5;++k){
      int compare = words[j].compareTo(words[k]);
      if(compare>0){
        String temp=words[j];
        words[j] = words[k];
        words[k]=temp;
    }
  }
  }
 //문자열 출력
 Serial.println("After Sorting");
 for(int j=0;j<5;++j){
  Serial.println(words[j]);
 }
}
