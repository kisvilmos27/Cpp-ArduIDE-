int wait = 0;
void setup() {
 Serial.begin(9600); // open serial port, set the baud rate as 9600 bps
 Serial.println("test");
 pinMode(15,OUTPUT);
}
void loop() {
 int dry_level = map(analogRead(35),0,4095,0,1023);
 int sensor_readout = map(analogRead(34),0,4095,0,1023);
 if( sensor_readout > dry_level){
  Serial.println("Dry");
  digitalWrite(15,HIGH);
 }else {
  Serial.println("Wet");
  digitalWrite(15,LOW);
 }
 delay(100);
 Serial.println(sensor_readout);
}
