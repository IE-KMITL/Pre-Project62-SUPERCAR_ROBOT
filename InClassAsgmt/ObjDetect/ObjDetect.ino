void setup(){
  Serial.begin(9600);
  pinMode(26, INPUT);
}

void loop(){
  int detect = digitalRead(26);
  if(detect == HIGH)
  {
    Serial.println("Can't detect the object");
  }
  else
  {
    Serial.println("Object detect");
  }
  delay(500);
}
//white paper 15 cm
//black mouse 6 cm
//green lid 8.5 cm
//yellow lid 10.8 cm
//pink wallet 7.8 cm
//blue plastic 11.5 cm
