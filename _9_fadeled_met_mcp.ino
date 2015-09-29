#include <Wire.h>
#include "Adafruit_MCP23017.h"
Adafruit_MCP23017 mcp;

// Basic pin reading and pullup test for the MCP23017 I/O expander
// public domain!

// Connect pin #12 of the expander to Analog 5 (i2c clock)
// Connect pin #13 of the expander to Analog 4 (i2c data)
// Connect pins #15, 16 and 17 of the expander to ground (address selection)
// Connect pin #9 of the expander to 5V (power)
// Connect pin #10 of the expander to ground (common ground)
// Connect pin #18 through a ~10kohm resistor to 5V (reset pin, active low)

// Input #0 is on pin 21 so connect a button or switch from there to ground



void setup() {

  
  
  
  mcp.begin();      // use default address 0
  Serial.begin(9600);
  mcp.pinMode(0, INPUT);

  mcp.pinMode(1, OUTPUT);
  mcp.pinMode(2, OUTPUT);
  mcp.pinMode(3, OUTPUT);

  mcp.pinMode(12, INPUT);

  mcp.pinMode(13, OUTPUT);
  mcp.pinMode(14, OUTPUT);
  mcp.pinMode(15, OUTPUT);

  mcp.pinMode(8, INPUT);

  mcp.pinMode(9, OUTPUT);
  mcp.pinMode(10, OUTPUT);
  mcp.pinMode(11, OUTPUT);

  mcp.pinMode(4, INPUT);
  mcp.pinMode(5, INPUT);
  mcp.pinMode(6, INPUT);
  mcp.pinMode(7, INPUT);
  //Werkt pinMode 

}
void loop() {
  // fader animation

 // ledanimation();  -> deze erbij, loopt hij vast
   



  mcp.digitalWrite(1, mcp.digitalRead(0));
  mcp.digitalWrite(2, mcp.digitalRead(0));
  mcp.digitalWrite(3, mcp.digitalRead(0));

  Serial.println(mcp.digitalRead(0));

  mcp.digitalWrite(13, mcp.digitalRead(12));
  mcp.digitalWrite(14, mcp.digitalRead(12));
  mcp.digitalWrite(15, mcp.digitalRead(12));

  Serial.println(mcp.digitalRead(12));

  mcp.digitalWrite(9, mcp.digitalRead(8));
  mcp.digitalWrite(10, mcp.digitalRead(8));
  mcp.digitalWrite(11, mcp.digitalRead(8));

  Serial.println(mcp.digitalRead(8));

  mcp.digitalWrite(9, mcp.digitalRead(4));
  mcp.digitalWrite(10, mcp.digitalRead(5));
  mcp.digitalWrite(11, mcp.digitalRead(6));
  mcp.digitalWrite(3, mcp.digitalRead(7));

  Serial.println(mcp.digitalRead(4));
  Serial.println(mcp.digitalRead(5));
  Serial.println(mcp.digitalRead(6));
  Serial.println(mcp.digitalRead(7));
}

void ledanimation() {
pinMode (3, OUTPUT);
pinMode (4, OUTPUT);
pinMode (5, OUTPUT);
pinMode (6, OUTPUT);
pinMode (9, OUTPUT);
pinMode (10, OUTPUT);
pinMode (23, OUTPUT);
pinMode (25, OUTPUT);
pinMode (32, OUTPUT);

int ledPins [9] = {3,4,5,6,9,10,23,25,32};

for (int i=0;i<9;i++){
  for (int fadeValue = 0; fadeValue <= 22; fadeValue += 1){
    analogWrite (ledPins [i], fadeValue);
 delay(1);

  }
}

for (int i=9;i>0;--i){
  for (int fadeValue = 22; fadeValue  >= 0; fadeValue -= 1){
    analogWrite (ledPins [i], fadeValue);
 delay(1);

}
}
}
