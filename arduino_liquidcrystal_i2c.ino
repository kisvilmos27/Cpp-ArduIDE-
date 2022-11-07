//lcd-re sorosporton át írunk ki egyedi szöveget (max. 16 karakter)

#include <LiquidCrystal_I2C.h> //I2C könyvtár előhívása
#include <Wire.h> //kisegítő könyvtár
LiquidCrystal_I2C lcd(0x27,20,4); //előhívjuk azz lcd-t lcd néven (így hivatkozunk rá később)

void setup(){
  lcd.init(); //előkészítjük kijelzőnket
  lcd.backlight();  //háttérvilágítást bekapcsoljuk
  lcd.clear(); //töröljük a kijelzőt és a bal felső sarokba helyezzük a kurzort
  lcd.print("test"); //kiírjuk "test" a kijelzőre
  Serial.begin(9600); //soros kommunikáció sebeségét beállítjuk 9600-ra
}
void loop(){
  if(Serial.available()>0){ //ha jön adat a soros porton:
    String inp = Serial.readString(); //olvassuk be az adatot és alakítsuk szöveggé
    inp.trim(); //távolítsuk el a szöveg végéről a '\n' részt (új sort jelenti)
    lcd.clear(); //tisztítjuk a kijelzőt
    lcd.print(inp); //kiírjuk a beolvasott üzenetet
  }
}
