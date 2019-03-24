#ifndef __MOTOR_TESTS_H
#define __MOTOR_TESTS_H

#ifdef __cplusplus
 extern "C" {
#endif

void testMotorSpeed0(void);
void testMotorSpeed25(void);
void testMotorSpeed50(void);
void testMotorSpeed75(void);
void testMotorSpeed100(void);
void testInvalidSpeedUnder(void);
void testInvalidSpeedOver(void); 

#ifdef __cplusplus
}
#endif
	 
#endif