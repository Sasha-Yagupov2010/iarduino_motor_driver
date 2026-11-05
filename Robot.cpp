#include "Robot.h"


int get_correct_val(int val) {
	if (val < 0) return 0;
	if (val > 255) return 255;
	return val;
}

void Robot::setupRobot() {
	pinMode(Motor1PIN, OUTPUT);
	pinMode(Motor2PIN, OUTPUT);
	pinMode(M1_SpeedPIN, OUTPUT);
	pinMode(M2_SpeedPIN, OUTPUT);

	pinMode(Button1,INPUT_PULLUP);
	pinMode(Button2, INPUT_PULLUP); //TODO: узнать как подключаются кнопки
	pinMode(LedGreen, OUTPUT);
	pinMode(LedRed, OUTPUT);


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
	RmotorSpeed = get_correct_val(newspeed);
	analogWrite(M2_SpeedPIN, RmotorSpeed);
}
void Robot::setLSpeed(int newspeed)
{
	LmotorSpeed = get_correct_val(newspeed);
	analogWrite(M1_SpeedPIN, LmotorSpeed);
}

//поворт сервопривода
void Robot::rotateServo(int angle) {
	if (angle < 0) angle = 0;
	if (angle > 180) angle = 180;

	servo.write(angle);

}


bool Robot::button1() {
	return !digitalRead(Button1);
}

bool Robot::button2() {
	return !digitalRead(Button2);
}


void Robot::ledRed(int val) {

	analogWrite(LedRed, get_correct_val(val));
}

void Robot::ledGreen(int val) {
	analogWrite(LedGreen, get_correct_val(val));
}
