#include <Arduino.h>
#include <Motor.h>

const int trigPin = 3;
const int echoPin = 2;
long duration, cm;

//motor one
int enA = 10;
int in1 = 9;
int in2 = 8;
// motor two
int enB = 5;
int in3 = 7;
int in4 = 6;

bbMotor motorA(enA,in1,in2);
bbMotor motorB(enB,in3,in4);

int speed = 250;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);

  motorA.begin();
  motorB.begin();
}


void loop()
{
  digitalWrite(trigPin, LOW);
  delayMicroseconds(5);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  pinMode(echoPin, INPUT);
  duration = pulseIn(echoPin, HIGH);
  cm = (duration/2) / 29.1; 
  Serial.print(cm);
  Serial.println();

if(cm >= 100){
   // set speed to 200 out of possible range 0~255
  motorA.forward(200);
  motorB.forward(200);
  Serial.print(cm);
  Serial.println();
}
 
  if(cm <= 99){
    motorA.stop(100);
    motorB.stop(100);
    delay(200);
    //Turn
    motorA.backward(150);
    motorB.forward(150);
    delay(1000);
  }

}