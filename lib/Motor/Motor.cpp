/*
  Motor.h - Library for controlling motors with a L298N or L293d.
  Created by Cody McElroy, January 26, 2022.
  Released into the public domain.
*/


#include "Arduino.h"
#include "Motor.h"


bbMotor::bbMotor(int enable, int input_1_pin, int input_2_pin)
{
	_enable = enable;
	_input_1_pin = input_1_pin;
	_input_2_pin = input_2_pin;
}

void bbMotor::begin()
{
	pinMode(_enable, OUTPUT);
	pinMode(_input_1_pin, OUTPUT);
	pinMode(_input_2_pin, OUTPUT);
	digitalWrite(_enable, LOW);
    
}

void bbMotor::forward(int pwr){
        digitalWrite(_input_1_pin, LOW);
        digitalWrite(_input_2_pin, HIGH);
        analogWrite(_enable, pwr);
}

void bbMotor::backward(int speed){
        digitalWrite(_input_1_pin, HIGH);
        digitalWrite(_input_2_pin, LOW);
        analogWrite(_enable, speed);
}

void bbMotor::stop(int speed){
        digitalWrite(_input_1_pin, LOW);
        digitalWrite(_input_2_pin, LOW);
        analogWrite(_enable, speed);
}