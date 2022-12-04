#include <SoftwareSerial.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

const byte rxPin = 8;
const byte txPin = 9;

SoftwareSerial mySerial (rxPin, txPin);

LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);


char inbyte;            //serial byte
String intext;          //incomming serial string

void setup() {
    //pinMode(rxPin, INPUT);
    //pinMode(txPin, OUTPUT);
    
    // Set the baud rate for the SoftwareSerial object
    mySerial.begin(9600);

    Serial.begin(9600);
  
  lcd.begin(16, 2);
  lcd.clear();
  lcd.setCursor(0,0);
  //lcd.print("This is menu 2."); 

}

void loop() {
while(mySerial.available()){
  inbyte=mySerial.read();
  intext=String(intext+inbyte);
}
 Serial.print(intext);
if(intext>""){
  lcd.clear();
  lcd.setCursor(4,0);
  lcd.print(intext);
  intext="";
}


}
