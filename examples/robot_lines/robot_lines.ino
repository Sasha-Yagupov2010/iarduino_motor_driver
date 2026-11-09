#include "Robot.h"
Robot robot;

void setup() {
	robot.setupRobot();
	Serial.begin(115200);
	delay(200);
	Serial.println("Код для калибровки датчиков");
}

void loop() {
	
	Serial.print("Левый: ");Serial.println(robot.leftLine());
	Serial.print("Правый: ");Serial.println(robot.rightLine());
	delay(100);
}