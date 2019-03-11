#include "motorUtil.h"
#include "params.h"
#include "xnucleoihm02a1.h"

StepperMotorBoardHandle_t *StepperMotorBoardHandle;
MotorParameterData_t *MotorParameterDataGlobal, *MotorParameterDataSingle;

eL6470_DirId_t motorDir[2];

uint8_t board;

void motorsInit(void) {
	board = EXPBRD_ID(0);
	MotorParameterDataGlobal = GetMotorParameterInitData();
	
	StepperMotorBoardHandle = BSP_GetExpansionBoardHandle(board);
	MotorParameterDataSingle = MotorParameterDataGlobal;
  StepperMotorBoardHandle->Config(MotorParameterDataSingle);
}

//Runs motor, might need to add synchronous run for both at the same time
void runMotor(uint8_t motorID, eL6470_DirId_t dir){
	uint32_t Speed;
	uint8_t device = L6470_ID(motorID);
	
	motorDir[motorID] = dir;
	
	MotorParameterDataSingle = MotorParameterDataGlobal+((board*L6470DAISYCHAINSIZE)+device);
	Speed = Step_s_2_Speed(MotorParameterDataSingle->speed);
	StepperMotorBoardHandle->StepperMotorDriverHandle[device]->Command->PrepareRun(device, motorDir[motorID], Speed);
	StepperMotorBoardHandle->Command->PerformPreparedApplicationCommand();
}

void setSpeed(uint8_t motorID, uint8_t adcVal) {
	uint8_t device = L6470_ID(motorID);
	
	float ratio = adcVal / 255;
	float newSpeed = Step_s_2_Speed(MotorParameterDataSingle->minspeed + (MotorParameterDataSingle->maxspeed - MotorParameterDataSingle->minspeed) * ratio);
	
	StepperMotorBoardHandle->StepperMotorDriverHandle[device]->Command->PrepareRun(device, motorDir[motorID], newSpeed);
	StepperMotorBoardHandle->Command->PerformPreparedApplicationCommand();
}

//Hard stop motor, might need to add syncronous stop for both at the same time
void hardStopMotor(uint8_t motorID){
	uint8_t device = L6470_ID(motorID);
	StepperMotorBoardHandle->StepperMotorDriverHandle[device]->Command->PrepareHardStop(device);
	StepperMotorBoardHandle->Command->PerformPreparedApplicationCommand();
} 

//Soft stop motor, might need to add syncronous stop for both at the same time
void softStopMotor(uint8_t motorID){
	uint8_t device = L6470_ID(motorID);
	StepperMotorBoardHandle->StepperMotorDriverHandle[device]->Command->PrepareSoftStop(device);
	StepperMotorBoardHandle->Command->PerformPreparedApplicationCommand();
} 


