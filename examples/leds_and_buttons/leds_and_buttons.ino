#include "Robot.h"
Robot robot;

void setup() {
	robot.setupRobot();
}

void loop() {
	if(robot.button1()){
		robot.ledRed(1);
	}
	else{
	robot.ledRed(0);
	}


	if(robot.button2()){
		robot.ledGreen(1);
	}
	else{
	robot.ledGreen(0);
	}


	delay(50);
}