//#include "motorUtil.h"
#include "params.h"
#include "xnucleoihm02a1.h"

StepperMotorBoardHandle_t *StepperMotorBoardHandle;
MotorParameterData_t *MotorParameterDataGlobal, *MotorParameterDataSingle;

uint8_t board;
//uint8_t motors[2];

void mototsInit() {
	board = EXPBRD_ID(0);
	MotorParameterDataGlobal = GetMotorParameterInitData();
	
	StepperMotorBoardHandle = BSP_GetExpansionBoardHandle(board);
	MotorParameterDataSingle = MotorParameterDataGlobal;
  StepperMotorBoardHandle->Config(MotorParameterDataSingle);

}


void runMotor(uint8_t motorID, eL6470_DirId_t dir, uint32_t speed){
	uint32_t Speed;
	uint8_t device = L6470_ID(motorID);
	
	MotorParameterDataSingle = MotorParameterDataGlobal+((board*L6470DAISYCHAINSIZE)+device);
	Speed = Step_s_2_Speed(MotorParameterDataSingle->speed);
	StepperMotorBoardHandle->StepperMotorDriverHandle[motorID]->Command->PrepareRun(device, dir, Speed);
	StepperMotorBoardHandle->Command->PerformPreparedApplicationCommand();
}

void stopMotor(uint8_t motorID){
	uint8_t device = L6470_ID(motorID);
	StepperMotorBoardHandle->StepperMotorDriverHandle[device]->Command->PrepareHardStop(device);
	StepperMotorBoardHandle->Command->PerformPreparedApplicationCommand();
}

