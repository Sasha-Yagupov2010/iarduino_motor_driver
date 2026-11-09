#include "Robot.h"
Robot robot;

void setup() {
	robot.setupRobot();
	Serial.begin(115200);
}

void loop() {
	Serial.println(robot.photoResistor());
	delay(500);
	Serial.println(robot.photoResistor(0,10));
	delay(500);
	Serial.println(robot.photoResistor(0,1023,0,10));
	delay(500);
}