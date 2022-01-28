#include <Arduino.h>
#include <Motor.h>

bbMotor motor(10,9,8);
int speed = 250;

void setup() {
motor.begin();
}

void loop() {
  for(int i=200; i<255; i++){
    motor.forward(i);
       Serial.print(i);
    delay(200);

  }
  delay(200);
  for(int i=255; i>200; i--){
    motor.backward(i);
    Serial.print(i);
    delay(200);
 
  }
}
