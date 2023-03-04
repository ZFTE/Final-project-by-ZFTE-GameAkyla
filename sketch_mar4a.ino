#include <AFMotor.h>  // подключаем библиотеку для шилда
AF_DCMotor motor1(1); // подключаем мотор к клеммнику M1
AF_DCMotor motor2(2); // подключаем мотор к клеммнику M2

int val; // освобождаем память в контроллере

void setup() {

  Serial.begin(9600);
  pinMode(2, OUTPUT);   // Порт для светодиодов
  motor1.setSpeed(250); // задаем максимальную скорость мотора
  motor1.run(RELEASE);  // останавливаем мотор
  motor2.setSpeed(250); // задаем максимальную скорость мотора
  motor2.run(RELEASE);  // останавливаем мотор
}

void loop() {

if (Serial.available()) // проверяем, поступают ли какие-то команды
  {
    val = Serial.read();

    if (val == 'f') { // едем вперед
motor1.run(FORWARD);
motor1.setSpeed(250); 
motor2.run(FORWARD);
motor2.setSpeed(250);
 }

    if (val == 'b') { // едем назад
motor1.run(BACKWARD);
motor1.setSpeed(200); 
motor2.run(BACKWARD);
motor2.setSpeed(200);
 }

    if (val == 's') { // останавливаемся
motor1.run(RELEASE);
motor2.run(RELEASE);
 }

    if (val == 'l') { // поворачиваем налево
motor1.run(FORWARD);
motor1.setSpeed(100); 
motor2.run(BACKWARD);
motor2.setSpeed(250);
 }

    if (val == 'r') { // поворачиваем направо
motor1.run(BACKWARD);
motor1.setSpeed(250); 
motor2.run(FORWARD);
motor2.setSpeed(100);
 }

    if (val == '1') { // включаем светодиоды
digitalWrite(2,HIGH);
 }

    if (val == '0') { // выключаем светодиоды
digitalWrite(2,LOW);
 }

}
}