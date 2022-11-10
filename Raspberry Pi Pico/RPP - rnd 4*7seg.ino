/* 7 szegmenses kijelző elrendezés
*    AA
*   F  B
*   F  B
*    GG
*   E  C
*   E  C
*    DD
*/

int btn = 28;
int ch1 = 19;  //1. számjegy (1)
int ch2 = 18;  //2. számjegy (10)
int ch3 = 17;  //3. számjegy (100)
int ch4 = 16;  //4. számjegy (1000)
int A = 15;
int B = 14;
int C = 13;
int D = 12;
int E = 11;
int F = 10;
int G = 9;
int astate;
int bstate;
int del = 4;
int seg7[] = {A, B, C, D, E, F, G};
int numbah = 2593;
int numbers[11][8] = {
  {1, 1, 1, 1, 1, 1, 0},
  {0, 1, 1, 0, 0, 0, 0},
  {1, 1, 0, 1, 1, 0, 1},
  {1, 1, 1, 1, 0, 0, 1},
  {0, 1, 1, 0, 0, 1, 1},
  {1, 0, 1, 1, 0, 1, 1},
  {1, 0, 1, 1, 1, 1, 1},
  {1, 1, 1, 0, 0, 0, 0},
  {1, 1, 1, 1, 1, 1, 1},
  {1, 1, 1, 1, 0, 1, 1}
};
void draw(int number) {
  if (number > 999) {
    for (int i = 0; i < 7; i++) {
      digitalWrite(seg7[i], numbers[int(number % 10000 / 1000)][i]);
    }
    digitalWrite(ch4, 0);
    digitalWrite(ch3, 1);
    digitalWrite(ch2, 1);
    digitalWrite(ch1, 1);
    
    delay(del);
  }
  if (number > 99) {
    for (int i = 0; i < 7; i++) {
      digitalWrite(seg7[i], numbers[int(number % 1000 / 100)][i]);
    }
    digitalWrite(ch4, 1);
    digitalWrite(ch3, 0);
    digitalWrite(ch2, 1);
    digitalWrite(ch1, 1);
    
  }
    delay(del);
    if (number > 9) {
      for (int i = 0; i < 7; i++) {
        digitalWrite(seg7[i], numbers[int(number % 100 / 10)][i]);
      }
      digitalWrite(ch4, 1);
      digitalWrite(ch3, 1);
      digitalWrite(ch2, 0);
      digitalWrite(ch1, 1);
      
      delay(del);
    }
    for (int i = 0; i < 7; i++) {
      digitalWrite(seg7[i], numbers[int(number % 10)][i]);
    }
    digitalWrite(ch4, 1);
    digitalWrite(ch3, 1);
    digitalWrite(ch2, 1);
    digitalWrite(ch1, 0);
    delay(del);
  }

  void setup() {
    pinMode(btn,INPUT);
    for (int i = 0; i < 7; i++) {
      pinMode(seg7[i], OUTPUT);
    }
    pinMode(ch4, OUTPUT);
    pinMode(ch3, OUTPUT);
    pinMode(ch1, OUTPUT);
    pinMode(ch2, OUTPUT);
    bstate = digitalRead(btn);
  }
  void loop() {
    astate = digitalRead(btn);
    if(astate != bstate){
      bstate = astate;
      if(astate == LOW){
      numbah = random(0,9999);
      }
    }
    draw(numbah);
  }
