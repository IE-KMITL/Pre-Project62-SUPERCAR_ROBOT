#include <analogWrite.h>
#include <HCSR04.h>

#define maxSpd 255

#define ia1 25 //go backward motor

#define ia2 27 //go forward motor

#define ib1 16 //go backward motor

#define ib2 17 //go forward motor

HCSR04 hc(17,16); //trig,echo

const int buttonPin = 2;     // the number of the pushbutton pin
int SensorL=25; //right Sensor
int SensorR=26; //left Sensor
int buttonState = 0; 

void setup() {
  
  Serial.begin(9600);
  Serial.begin(38400);

   pinMode(SensorL,INPUT);  

   pinMode(SensorR,INPUT); 

   pinMode(ia1, OUTPUT);

   pinMode(ia2, OUTPUT);

   pinMode(ib1, OUTPUT);

   pinMode(ib2, OUTPUT);

   Serial.begin(115200);
   
  

}

void loop() {
 int sensorValue = analogRead(4);// read the input on analog infrared pin 4:
 buttonState = digitalRead(buttonPin);
 if (buttonState == HIGH)/*code attack*/{
 int maxspeed = maxSpd;//carefull

    if(digitalRead(SensorL)==LOW) //detectLeft
    {
      turnRight(maxspeed);
      moveStop();
      delay(40);
    }
    else if(digitalRead(SensorR)==LOW) //detectRight
    {
      turnLeft(maxspeed);
      moveStop();
      delay(40);
    }
    
    else if(hc.dist()<=10)  //detectFront20cm
    { 
      moveStop();
      delay(40);
    }
    else if((digitalRead(SensorR)==LOW)&&(digitalRead(SensorR)==LOW)) //detectRight
    {
      moveBackwardTime(5000);//backward 5 seconds
    }
    else if(sensorValue >= 2560 && sensorValue <= 2700) //red detect(put in red number)
    {
      turnLeft(maxspeed);//U-Tern
      moveStop();
      turnLeft(maxspeed);
      moveStop();
      delay(40);
    }
    else
    {
       moveForward(maxspeed);
    }
                         }
else/*code defense*/{ 
  int maxspeed = maxSpd;
    if(digitalRead(SensorL)==LOW) //detectLeft
    {
      turnLeft(maxspeed);
      moveStop();
      delay(40);
    }           
    else if(digitalRead(SensorR)==LOW) //detectRight
    {
      turnRight(maxspeed);
      moveStop();
      delay(40);
    }
    else if(sensorValue >= 3000 && sensorValue <= 3200) //black detect(put in black number)
    {
      turnLeft(maxspeed);//U-Tern
      moveStop();
      turnLeft(maxspeed);
      moveStop();
      delay(40);
    }
    else
    {
      moveStop();
      delay(40);
    }
  
     }
        }


void moveStop() {
  digitalWrite(ia1, LOW); 
  digitalWrite(ia2, LOW);
  digitalWrite(ib1, LOW);
  digitalWrite(ib2, LOW);  
  }
  
void moveForward(int speed) {
  digitalWrite(ia1, LOW);   
  digitalWrite(ia2, HIGH);
  digitalWrite(ib1, LOW);   
  digitalWrite(ib2, HIGH);
 }

void moveBackward(int speed) {
  digitalWrite(ia1, HIGH);   
  digitalWrite(ia2, LOW);
  digitalWrite(ib1, HIGH);   
  digitalWrite(ib2, LOW);
  }  

void turnRight(int speed) {
  digitalWrite(ia1, HIGH);   
  digitalWrite(ia2, HIGH);
  analogWrite(ib1, 0.3*maxSpd);   
  //digitalWrite(ib1, LOW);
  digitalWrite(ib2, LOW);     
} 
 
void turnLeft(int speed) {
  analogWrite(ia1, 0.3*maxSpd);
  //digitalWrite(ia1, LOW);   
  digitalWrite(ia2, LOW);
  digitalWrite(ib1, HIGH);   
  digitalWrite(ib2, HIGH);
}  
void moveBackwardTime(int time) {
  digitalWrite(ia1,LOW);
  analogWrite(ia2, maxSpd);
  delay(time);
  digitalWrite(ib1,LOW);
  analogWrite(ib2, maxSpd);
  delay(time);
}
