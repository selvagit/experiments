#include <Ala.h>
#include <AlaLed.h>
#include <AlaLedRgb.h>
#include <ExtNeoPixel.h>
#include <ExtTlc5940.h>
#include <ExtTlc5940Config.h>

#include <TFT.h>


int buttonState=0;
void setup() {
  // put your setup code here, to run once:
pinMode(8,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
buttonState=digitalRead(8);
if(buttonState==HIGH)
{
 digitalWrite(8,HIGH);

}
else
{
 digitalWrite(8,LOW);
 
}
}
