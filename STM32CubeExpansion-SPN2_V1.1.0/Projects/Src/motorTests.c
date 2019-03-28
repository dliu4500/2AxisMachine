#include "motorTests.h"
#include "motorUtil.h"

//Test motors as various percentages between min and max speed
void testMotorSpeed0(){
	setSpeed(1, 0);
}

void testMotorSpeed25(){
	setSpeed(1, 4095.0/4.0);
}

void testMotorSpeed50(){
	setSpeed(1, 4095.0/2.0);
}

void testMotorSpeed75(){
	setSpeed(1, 3.0 * 4095.0 / 4.0);
}

void testMotorSpeed100(){
	setSpeed(1, 4095.0);
}

//Test invalid input, negative speeds and speeds over the limit.
void testInvalidSpeedUnder() {
	setSpeed(1, -1.0);
}

void testInvalidSpeedOver() {
	setSpeed(1, 5000.0);
}
