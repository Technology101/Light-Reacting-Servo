#include <Servo.h>
Servo c;
int lightPin = A0;  //define a pin for Photo resistor
#define pinServo 9

void setup()
{
    Serial.begin(9600);  //Begin serial communcation
    c.attach(pinServo);
}

void loop()
{
    Serial.println(analogRead(lightPin)); //Write the value of the photoresistor to the serial monitor.
                                          //you have  to divide the value. for example, 
                                          //with a 10k resistor divide the value by 2, for 100k resistor divide by 4.
if (analogRead(lightPin) > 180)
      {
          delay(500);
          if (analogRead(lightPin) > 180)
          c.write(15);
          delay(100);
      }
      
    if (analogRead(lightPin) < 180)
      {
          delay(500);
          if (analogRead(lightPin) < 180)
          c.write(140);
          delay(100);
      } 
   delay(1000); //short delay for faster response to light.
}

