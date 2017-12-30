/*||\\ //|| //\\ ||\\ ||-------- ||\\ \\ //
*|| \\ // || // \\ || \\ || || \\ \\ //
*|| \\// || //----\\ || \\ || || // \\//
*|| || //------\\ || // ||---- || \\ || ------- SOUMENDRA DEY
*|| || // \\ || // || || \\ ||
*|| || // \\ || // ||-------- || // ||
*/

//*** 1- Documentation

//This program is used to control a robot car using a app that communicates with Arduino trough a bluetooth module

#include <AFMotor.h>

#include <Servo.h>

Servo S1; // Define any servo name

Servo S2;

int servo_position = 0 ;

//creates two objects to control the terminal 3 and 4 of motor shield 

AF_DCMotor motor1(2); 

AF_DCMotor motor2(1);

AF_DCMotor motor4(4);

char command; 

void setup() 

{ 

Serial.begin(9600); //Set the baud rate to your Bluetooth module.

S1.attach(10);

}

void loop(){

if(Serial.available() > 0){ 

command = Serial.read(); 

//initialize with motors stoped

//Change pin mode only if new command is different from previous. 

//Serial.println(command);

switch(command){

case 'F': 

forward();

break;

case 'B': 

back();

break;

case 'L': 

left();

break;

case 'R':

right();

break;

case 'X':

serf();

break;

case 'x':

serb();

break;

case 'V':
            pumpon();
            break;
case 'v':
            pumpoff();
            break;
case 'S':

Stop();

break;

default:

S1.write(20);

break; 

}

} 

}

void forward()

{

motor1.setSpeed(155); //Define maximum velocity

motor1.run(FORWARD); //rotate the motor clockwise

motor2.setSpeed(155); //Define maximum velocity

motor2.run(FORWARD); //rotate the motor clockwise

}

void back()

{

motor1.setSpeed(155); 

motor1.run(BACKWARD); //rotate the motor counterclockwise

motor2.setSpeed(155); 

motor2.run(BACKWARD); //rotate the motor counterclockwise

}

void left()

{

motor1.setSpeed(0); //Define maximum velocity

motor1.run(RELEASE); //rotate the motor clockwise

motor2.setSpeed(155);

motor2.run(FORWARD); //turn motor2 off

}

void right()

{

motor1.setSpeed(155);

motor1.run(FORWARD); //turn motor1 off

motor2.setSpeed(0); //Define maximum velocity

motor2.run(RELEASE); //rotate the motor clockwise

}

void Stop()

{

motor1.setSpeed(0);

motor2.run(RELEASE); //turn motor1 off

motor2.setSpeed(0);

motor2.run(RELEASE); //turn motor2 off

}

void serf()

{

S1.write(10);

motor1.setSpeed(0);

motor2.run(RELEASE); //turn motor1 off

motor2.setSpeed(0);

motor2.run(RELEASE); //turn motor2 off

}

void serb()

{

S1.write(90);

motor1.setSpeed(0);

motor1.run(RELEASE); //turn motor1 off

motor2.setSpeed(0);

motor2.run(RELEASE); //turn motor2 off

}

void pumpon()
{
    motor4.setSpeed(255);
    motor4.run(FORWARD);
}
void pumpoff()
{
    motor4.setSpeed(0);
    motor4.run(RELEASE);
}

