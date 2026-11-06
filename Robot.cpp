#include "Robot.h"


int get_correct_val(int val) {
	if (val < 0) return 0;
	if (val > 255) return 255;
	return val;
}

void Robot::setupRobot() {
	pinMode(MOTOR_1PIN, OUTPUT);
	pinMode(MOTOR_2PIN, OUTPUT);
	pinMode(M1_SpeedPIN, OUTPUT);
	pinMode(M2_SpeedPIN, OUTPUT);

	pinMode(BUTTON1_PIN,INPUT_PULLUP);
	pinMode(BUTTON2_PIN, INPUT_PULLUP); //TODO: узнать как подключаются кнопки
	pinMode(LED_GREEN, OUTPUT);
	pinMode(LED_RED, OUTPUT);


	servo.attach(SERVO_PIN);

	digitalWrite(MOTOR_1PIN, Ldirection);
	digitalWrite(MOTOR_2PIN, Rdirection);

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
	digitalWrite(MOTOR_2PIN, direct);
}

void Robot::setLDirection(bool direct)
{
	digitalWrite(MOTOR_1PIN, direct);
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
	return !digitalRead(BUTTON1_PIN);
}

bool Robot::button2() {
	return !digitalRead(BUTTON2_PIN);
}


void Robot::ledRed(int val) {
	analogWrite(LED_RED, get_correct_val(val));
}

void Robot::ledGreen(int val) {
	analogWrite(LED_GREEN, get_correct_val(val));
}
