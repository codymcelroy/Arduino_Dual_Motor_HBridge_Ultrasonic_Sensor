#include <Arduino.h>

//ULTRASONIC SENSOR
const int trigPin = 3;
const int echoPin = 2;
long duration, cm;

//MOTOR A
int enA = 10;
int in1 = 9;
int in2 = 8;
//MOTOR B
int enB = 5;
int in3 = 7;
int in4 = 6;


void setup() {

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  // motor control pins to outputs
  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  Serial.begin(9600);
}

void forward(){
// A Motor = ON
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  analogWrite(enA, 250);
// B Motor = ON
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  analogWrite(enB, 250);
}

void backward(){
// A Motor = ON
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
// Range 0~255
  analogWrite(enA, 200);
// B Motor = ON
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  analogWrite(enB, 100);
}


void right(){
// A Motor = ON
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  analogWrite(enA, 100);
// B Motor = ON
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  analogWrite(enB, 150);
}

void stop(){
// A Motor = OFF
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  analogWrite(enA, 0);
// B Motor = OFF
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
  analogWrite(enB, 0);
}

void loop() {
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

if(cm >= 110){
  forward();
  Serial.print(cm);
  Serial.println();
}
else { 
  stop();
  delay(50);
  Serial.print("HOLD UP");
  Serial.println();
  delay(50);  
  backward();
  delay(1000);
  Serial.print(cm);
  Serial.println();
  Serial.print("Turn Right ");
  Serial.println();
  delay(50);
  right();
  Serial.print(cm);
  Serial.println();
  delay(1500);
}

}