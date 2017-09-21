// Program for configuring HM-10 module via serial monitor
// also it turns on/off internal LED in arduino Mega 2560
// (to do that please use Serial app (iOS)

#include <SoftwareSerial.h>
 
int LEDPIN = 13;

void setup() {
  pinMode(LEDPIN, OUTPUT);
  Serial.begin(9600); // communication with computer
  Serial3.begin(9600); // communication with HM-10  
}
 
void loop() {
  if ( Serial3.available() ) {
    char dioda = Serial3.read();
    Serial.write(dioda);
    if (atoi(&dioda)==1) {
      digitalWrite(LEDPIN, HIGH);
    }
    
    if (atoi(&dioda)==0) {
      digitalWrite(LEDPIN, LOW);
    }
  }
  
  if ( Serial.available() ) {  Serial3.write( Serial.read() );  }  
}

