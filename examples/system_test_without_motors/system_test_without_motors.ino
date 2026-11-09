#include "Robot.h"
Robot robot;

unsigned long lastSensorTime = 0;
unsigned long lastServoTime = 0;
unsigned long lastLedTime = 0;
int servoAngle = 0;
int servoDir = 1;

void setup() {
    robot.setupRobot();
    Serial.begin(115200);
    Serial.println("Начало тестирования робота");
    delay(2000);
}

void loop() {
    unsigned long now = millis();

    if (now - lastSensorTime >= 1000) {
        lastSensorTime = now;
        
        long dist1 = robot.getFrontDistance();
        delay(10);
        long dist2 = robot.getLeftDistance();
        
        Serial.println("--- Сенсоры ---");
        Serial.print("Передний дальномер: "); Serial.println(dist1);
        Serial.print("Левый дальномер: "); Serial.println(dist2);
        Serial.print("Левый ИК: "); Serial.println(robot.leftLine());
        Serial.print("Правый ИК: "); Serial.println(robot.rightLine());
        Serial.print("Фоторезистор: "); Serial.println(robot.photoResistor());
        
        if (robot.button1()) robot.ledRed(255); else robot.ledRed(50);
        if (robot.button2()) robot.ledGreen(255); else robot.ledGreen(50);
    }

    if (now - lastServoTime >= 20) {
        lastServoTime = now;
        
        robot.rotateServo(servoAngle);
        
        servoAngle += servoDir * 2;
        if (servoAngle >= 180 || servoAngle <= 0) {
            servoDir *= -1; 
        }
    }
}