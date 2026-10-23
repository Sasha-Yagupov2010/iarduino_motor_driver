#include "Robot.h"
Robot robot;

void setup() {
	robot.setupRobot();
}

void loop() {
	robot.setLSpeed(150);
	robot.setRSpeed(150);

	delay(2000);

	robot.stop();

	delay(2000;)

}