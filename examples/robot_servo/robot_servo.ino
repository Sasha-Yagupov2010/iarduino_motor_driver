#include "Robot.h"
Robot robot;

void setup() {
	robot.setupRobot();
}

void loop() {

	for (int i = 0; i < 180; i++) {
		robot.rotateServo(i);
		delay(50);
	}

	for (int i = 180; i > 0; i--) {
		robot.rotateServo(i);
		delay(50);
	}
}