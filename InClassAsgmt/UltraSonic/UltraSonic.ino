#include <HCSR04.h>
  HCSR04 hc(14,16);//initialisation class HCSR04 (trig, echo); 
void setup() {
  // put your setup code here, to run once:
  ( Serial.begin(9600));
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println(hc.dist()) ;
}
