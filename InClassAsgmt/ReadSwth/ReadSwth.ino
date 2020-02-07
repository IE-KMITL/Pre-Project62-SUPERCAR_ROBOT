int buttonPin = 25;
int ledPin =  26;      
int buttonState = 0;
boolean on=false; 
void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT);
}

void loop() 
{
 buttonState = digitalRead(buttonPin);
 if(buttonState == HIGH) {
  if(on==true){
    on=false;
  } else {
      on=true;
  }
 }
 if(on == true){
  digitalWrite(ledPin,HIGH);
 }
 else{
    digitalWrite(ledPin,LOW);
    }
    delay(500);
}
