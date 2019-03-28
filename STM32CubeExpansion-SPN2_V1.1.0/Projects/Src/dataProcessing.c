#include "dataProcessing.h"
#include "stdlib.h"

uint32_t removeCrossTalk(uint32_t stream1[10], uint32_t val2) {
	uint8_t stream1Count = 1;
	uint8_t stream2Count = 0;
	
	int runningAvg1 = stream1[0];
	int runningAvg2 = -1;
	for(uint8_t i = 1; i < 10; ++i) {
		if(abs((int)stream1[i] - (int)runningAvg1) > 8){ 
			stream2Count++;
			if(runningAvg2 == -1) runningAvg2 = stream1[i];
			else runningAvg2 = runningAvg2 + (stream1[i] - runningAvg2) / stream2Count;
		} else {
			stream1Count++;
			runningAvg1 = runningAvg1 + (stream1[i] - runningAvg1) / stream1Count;
		}
	}
	if(runningAvg2 == -1) return runningAvg1;
	
	if(abs((int)runningAvg1 - (int)val2) < abs((int)runningAvg2 - (int)val2)) return runningAvg2;
	else return runningAvg1;
}