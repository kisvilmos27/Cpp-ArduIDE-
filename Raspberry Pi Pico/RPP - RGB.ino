int r = 255;
int g = 0;
int b = 0;
void setup(){
  pinMode(16,OUTPUT); //GPIO 16
  pinMode(17,OUTPUT); //GPIO 17
  pinMode(18,OUTPUT); //GPIO 18
}
void loop(){
  //Piros fokozatos csökkentése, Zöld növelése
  for(r = 255;r>0;r--){
    g++;
    analogWrite(16,r);
    analogWrite(17,g);
    delay(6);
  }
  //Zöld fokozatos csökkentése, Kék növelése
  for(g=255;g>0;g--){
      b++;
    analogWrite(18,b);
    analogWrite(17,r);
    delay(6);
  }
  //Kék fokozatos csökkentése, Piros növelése
  for(b = 255;b>0;b--){
    r++;
    analogWrite(18,b);
    analogWrite(16,r);
    delay(6);
  }
}
