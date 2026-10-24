#include "Robot.h"

void Robot::setupRobot() {
	pinMode(Motor1PIN, OUTPUT);
	pinMode(Motor2PIN, OUTPUT);
	pinMode(M1_SpeedPIN, OUTPUT);
	pinMode(M2_SpeedPIN, OUTPUT);

	servo.attach(servoPin);

	digitalWrite(Motor1PIN, Ldirection);
	digitalWrite(Motor2PIN, Rdirection);

	analogWrite(M1_SpeedPIN, 0);
	analogWrite(M2_SpeedPIN, 0);
}

//полная остановка робота
void Robot::stop() {
	setLSpeed(0);
	setRSpeed(0);
}


//направление вращения моторов
void Robot::setRDirection(bool direct)
{
	digitalWrite(Motor2PIN, direct);
}

void Robot::setLDirection(bool direct)
{
	digitalWrite(Motor1PIN, direct);
}

//скорость вращения моторов
void Robot::setRSpeed(int newspeed)
{
	if (newspeed < 0) RmotorSpeed = 0;
	else if (newspeed > 255) RmotorSpeed = 255;
	else RmotorSpeed = newspeed;

	analogWrite(M2_SpeedPIN, RmotorSpeed);
}
void Robot::setLSpeed(int newspeed)
{
	if (newspeed < 0) LmotorSpeed = 0;
	else if (newspeed > 255) LmotorSpeed = 255;
	else LmotorSpeed = newspeed;

	analogWrite(M1_SpeedPIN, LmotorSpeed);
}

//поворт сервопривода
void Robot::rotateServo(int angle) {
	if (angle < 0) angle = 0;
	if (angle > 180) angle = 180;

	servo.write(angle);

}