/***********************************************************************************
* @allocate.h
* @This file contains the function declarartion for allocate function
* @Tools used : GCC & GNU make
* @author Amreeta Sengupta & Ridhi Shah
************************************************************************************/
#include<stdint.h>
#ifndef __linux__

#include "fsl_device_registers.h"
#include "fsl_debug_console.h"
#include "board.h"
#include "pin_mux.h"
#include "core_cm0plus.h"
#include "MKL25Z4.h"

#endif
/*#include FRDM 1
#ifdef FRDM
#define printf PRINTF
#else
#define printf printf
#endif
*/
extern uint32_t *mem_address;
extern uint32_t num_words;

int allocate();


