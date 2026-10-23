#ifndef ROBOT_H
#define ROBOT_H
#include <Arduino.h>
#include <constants.h>

class Robot {
private:
	int LmotorSpeed = 0; //на всякий случай
	int RmotorSpeed = 0;

	//int Ldir = Ldirection;
	//int Rdir = Rdirection;

public:
	void setupRobot();
	void stop();

	void setRDirection(bool);
	void setLDirection(bool);

	void setRSpeed(int);
	void setLSpeed(int);



};

#endif // !ROBOT_H
