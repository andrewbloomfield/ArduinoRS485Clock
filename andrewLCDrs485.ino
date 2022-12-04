#include <SoftwareSerial.h>
#include <LiquidCrystal.h>

const byte rxPin = 8;
const byte txPin = 9;

SoftwareSerial mySerial (rxPin, txPin);

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

#include <DS3231.h>

// Init the DS3231 using the hardware interface
DS3231  rtc(SDA, SCL);

Time  t;   //Added for the "Hard Example"

void setup() {
  mySerial.begin(9600);
      
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.print("andrewbloomfield");

  rtc.begin();

}

void loop() {

  lcd.setCursor(4, 1);
  // Send date
  //lcd.print(rtc.getDateStr());
  //lcd.print(" -- ");

  // Send time
  //lcd.println(rtc.getTimeStr());

  mySerial.print(rtc.getTimeStr());

 // Get data from the DS3231
  t = rtc.getTime();
  
  
  // Send time
  
  if(t.hour<10){
    lcd.print("0");                 //if th Hour is less than 10 add "0"
  }
  lcd.print(t.hour, DEC);
  
  lcd.print(":");
  
   if(t.min<10){
    lcd.print("0");                 //if th minuite is less than 10 add "0"
  } 
  lcd.print(t.min, DEC);
  
  lcd.print(":");
  
  if(t.sec<10){
    lcd.print("0");                 //if th Second is less than 10 add "0"
  }
  lcd.print(t.sec, DEC);
 
  
  // Wait one second before repeating :)
  delay (1000);

}
