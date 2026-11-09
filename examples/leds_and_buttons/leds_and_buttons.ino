#include "Robot.h"
Robot robot;

void setup() {
	robot.setupRobot();
}

void loop() {
	if(robot.button1()){
		robot.ledRed(255);
	}
	else{
	robot.ledRed(50);
	}


	if(robot.button2()){
		robot.ledGreen(255);
	}
	else{
	robot.ledGreen(50);
	}


	delay(50);
}