#define Buzzer 27

const int VALUE_THRESHOLD = 30;

int TOUCH_Pin_1_VALUE;
int TOUCH_Pin_2_VALUE;
int TOUCH_Pin_3_VALUE;
int TOUCH_Pin_4_VALUE;
int TOUCH_Pin_5_VALUE;

void setup(){
  
  pinMode(Buzzer, OUTPUT);
  Serial.begin(115200);
  delay(2000); 
  
  digitalWrite(Buzzer, LOW);
}

void loop(){
  
  TOUCH_Pin_1_VALUE = touchRead(T5);
  TOUCH_Pin_2_VALUE = touchRead(T6);
  TOUCH_Pin_3_VALUE = touchRead(T7);
  TOUCH_Pin_4_VALUE = touchRead(T8);
  TOUCH_Pin_5_VALUE = touchRead(T9);
  
  Serial.print("Pin_1 Value:");
  Serial.print(TOUCH_Pin_1_VALUE);
  Serial.print("  ");
  Serial.print("Pin_2 Value:");
  Serial.print(TOUCH_Pin_2_VALUE);
  Serial.print("  ");
  Serial.print("Pin_3 Value:");
  Serial.print(TOUCH_Pin_3_VALUE);
  Serial.print(" ");
  Serial.print("Pin_4 Value:");
  Serial.print(TOUCH_Pin_4_VALUE);
  Serial.print("  ");
  Serial.print("Pin_5 VAlue:");
  Serial.print(TOUCH_Pin_5_VALUE);
  Serial.println("  ");
  delay(500);
  
  if(TOUCH_Pin_1_VALUE < VALUE_THRESHOLD){
    for(int i=0; i<2; i++){
      buzzer();
    }
  }
  if(TOUCH_Pin_2_VALUE < VALUE_THRESHOLD){
     for(int i=0; i<5; i++){
      buzzer();
    }
  }
  if(TOUCH_Pin_3_VALUE < VALUE_THRESHOLD){
    for(int i=0; i<8; i++){
      buzzer();
    }
  }
  if(TOUCH_Pin_4_VALUE < VALUE_THRESHOLD){
    for(int i=0; i<12; i++){
      buzzer();
    }
  }
  if(TOUCH_Pin_5_VALUE < VALUE_THRESHOLD){
    for(int i=0; i<15; i++){
      buzzer();
    }
  }
  else{
    digitalWrite(2, LOW);
  }
  
}

void buzzer(){
  digitalWrite(Buzzer, HIGH);
  delay(15);
  digitalWrite(Buzzer, LOW);
  delay(15);
}
