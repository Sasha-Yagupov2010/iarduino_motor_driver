#include "Robot.h"
Robot robot;

void setup() {
	robot.setupRobot();
	Serial.begin(115200);
}

void loop() {
	long dist1 = robot.getFrontDistance();
	delay(10); // Чтобы эхо от первого датчика угасло
	long dist2 = robot.getLeftDistance();
	Serial.print("Передний: "); Serial.println(dist1);
	Serial.print("Левый: "); Serial.println(dist2);

	delay(100);
	}