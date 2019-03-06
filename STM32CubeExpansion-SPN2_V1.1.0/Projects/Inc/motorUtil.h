#ifndef __MOTOR_UTIL_H
#define __MOTOR_UTIL_H

#ifdef __cplusplus
 extern "C" {
#endif
	 
#include "stdint.h"
#include "params.h"

void motorsInit(void);
void runMotor(uint8_t, eL6470_DirId_t, uint32_t);
void hardStopMotor(uint8_t);
void softStopMotor(uint8_t);


#ifdef __cplusplus
}
#endif
	 
#endif