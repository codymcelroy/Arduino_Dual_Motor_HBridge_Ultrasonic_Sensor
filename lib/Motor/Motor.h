/*
  Motor.h - Library for controlling motors with a L298N or L293d.
  Created by Cody McElroy, January 26, 2022.
  Released into the public domain.
*/

#ifndef Motor_h
#define Motor_h

#include "Arduino.h"

class bbMotor
{
	public:
		bbMotor(int enable, int input_1_pin, int input_2_pin);
		void begin();
        void forward(int speed);
        void backward(int speed);
        void stop(int speed);

	private:
		int _enable;
		int _input_1_pin;
		int _input_2_pin;
        int _speed;

};

#endif