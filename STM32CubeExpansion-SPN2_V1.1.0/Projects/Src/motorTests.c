#include "motorTests.h"
#include "motorUtil.h"

void testMotorSpeed0(){
	setSpeed(0, 0);
}

void testMotorSpeed25(){
	setSpeed(0, 1023.0/4.0);
}

void testMotorSpeed50(){
	setSpeed(0, 1023.0/2.0);
}

void testMotorSpeed75(){
	setSpeed(0, 3.0 * 2023.0 / 4.0);
}

void testMotorSpeed100(){
	setSpeed(0, 1023.0);
}

void testInvalidSpeedUnder() {
	setSpeed(0, -1.0);
}

void testInvalidSpeedOver() {
	setSpeed(0, 2000.0);
}
