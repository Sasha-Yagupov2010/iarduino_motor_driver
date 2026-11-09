#ifndef ROBOT_H
#define ROBOT_H
#include <Arduino.h>
#include <Servo.h>
#include "constants.h"

enum Direction {
	FORWARD,
	BACKWARD
};


class Robot {
private:
	Servo servo;
	int LmotorSpeed = 0; //на всякий случай
	int RmotorSpeed = 0;

	//int Ldir = Ldirection;
	//int Rdir = Rdirection;

public:
	void setupRobot();
	void stop();

	void setRDirection(Direction);
	void setLDirection(Direction);

	void setRSpeed(int);
	void setLSpeed(int);

	void rotateServo(int);

	bool button1();
	bool button2();

	void ledRed(int); 
	void ledGreen(int);

	int photoResistor();
	int photoResistor(int,int);
	int photoResistor(int, int, int, int);

	bool leftLine();
	bool rightLine();

	long getFrontDistance();
	long getLeftDistance();
};

#endif // !ROBOT_H
