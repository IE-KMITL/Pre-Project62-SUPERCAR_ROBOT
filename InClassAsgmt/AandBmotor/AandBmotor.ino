#include <analogWrite.h>
#define ia1 25

#define ia2 27

#define ib1 16

#define ib2 17


#define maxSpd 255    // motor max speed


const float pi = 3.1415926;



int angle = 0;



void setup() {

  // put your setup code here, to run once:

  pinMode(ia1, OUTPUT);

  pinMode(ia2, OUTPUT);

  pinMode(ib1, OUTPUT);

  pinMode(ib2, OUTPUT);

  Serial.begin(115200);

}



void loop() {

  // put your main code here, to run repeatedly:

  //aStop();

  //bStop();

  //delay(5000);   

   

  //aForward(30);

  //delay(5000);

  //aReward(30);

  //delay(5000);  



  //int aspeed = sin(pi*angle/180) * maxSpd;//carefull

  //int bspeed = cos(pi*angle/180) * maxSpd;//carefull



  // try this

  int aspeed = maxSpd;//carefull

  int bspeed = maxSpd;//carefull



  Serial.print(aspeed);

  Serial.print("\t");

  Serial.println(bspeed);



  if (aspeed > 0)

    aForward(aspeed);

  else

    aReward(-aspeed);



  if (bspeed > 0)

    bForward(-bspeed);

  else

    bReward(bspeed);



  delay(20);

          

  angle++;

  if (angle == 360)

    angle = 0; 

}



void aStop()

{

  digitalWrite(ia1, LOW);   // motor stop

  digitalWrite(ia2, LOW);    

}



void aBreak()

{

  digitalWrite(ia1, HIGH);   // motor break

  digitalWrite(ia2, HIGH);    

}



void bStop()

{

  digitalWrite(ib1, LOW);   // motor stop

  digitalWrite(ib2, LOW);    

}



void bBreak()

{

  digitalWrite(ib1, HIGH);   // motor break

  digitalWrite(ib2, HIGH);    

}



void aForward(int speed)

{

  digitalWrite(ia1, LOW);   

  analogWrite(ia2, 0.3*speed);   

}



void aReward(int speed)

{

  digitalWrite(ia2, LOW);   

  analogWrite(ia1, 0.3*speed);   

}



void bForward(int speed)

{

  digitalWrite(ib1, LOW);   

  analogWrite(ib2, 0.7*speed);   

}



void bReward(int speed)

{

  digitalWrite(ib2, LOW);   

  analogWrite(ib1, 0.7*speed);   

}
