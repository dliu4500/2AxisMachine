#ifndef __DATA_PROCESSING_H
#define __DATA_PROCESSING_H

#ifdef __cplusplus
 extern "C" {
#endif
	 
#include "stdint.h"
#include "params.h"

uint32_t removeCrossTalk(uint32_t stream1[15], uint32_t val2);

#ifdef __cplusplus
}
#endif
	 
#endif