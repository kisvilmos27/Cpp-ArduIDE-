int leds[] = {6,7,10,11,12,13,14,15};
int dly = 100;
int i;
int x;
void setup(){
  for(int i = 0;i< 8;i++){
    pinMode(leds[i],OUTPUT);
  }
}

//##############################################################

void fill(){
  for(int i = 0;i<8;i++){
    digitalWrite(leds[i],1);
    delay(dly);
  }
  for(int i = 0;i<8;i++){
    digitalWrite(leds[i],0);
    delay(dly);
  }
  for(int i = 7;i>-1;i--){
    digitalWrite(leds[i],1);
    delay(dly);
  }
  for(int i = 7;i>-1;i--){
    digitalWrite(leds[i],0);
    delay(dly);
  }
}
//@@@@@@@@@@@@
void single(){
  for(int i = 0;i<7;i++){
    for(int i = 0;i<8;i++){
    digitalWrite(leds[i],0);
    }
    digitalWrite(leds[i],1);
    delay(dly);
  }
  for(int i = 7;i>0;i--){
    for(int i = 0;i<8;i++){
    digitalWrite(leds[i],0);
    }
    digitalWrite(leds[i],1);
    delay(dly);
  }
}
//@@@@@@@@@@@@
void right(){
  for(int i = 0;i<8;i++){
    for(int i = 0;i<8;i++){
    digitalWrite(leds[i],0);
    }
    digitalWrite(leds[i],1);
    delay(dly);
  }
}
//@@@@@@@@@@@@
void left(){
  for(int i = 7;i>-1;i--){
    for(int i = 0;i<8;i++){
    digitalWrite(leds[i],0);
    }
    digitalWrite(leds[i],1);
    delay(dly);
  }
}
//@@@@@@@@@@@@
void loop(){
  for(int d = 0;d<3;d++){
    switch(x){
    case 0:
      single();
    break;
    case 1:
      fill();
    break;
    case 2:
      left();
    break;
    case 3:
      right();
    break;
    }
  }
  if(x<3){x++;}
  else{x=0;}
}
