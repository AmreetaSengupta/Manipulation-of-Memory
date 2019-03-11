/***********************************************************************************
* @exit.c
* @This file contains the function to exit from the program
* @author Amreeta Sengupta & Ridhi Shah
************************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include "../Include/exit.h"

extern uint32_t *mem_address;
extern uint32_t num_words;

int Exit()
{
free(mem_address);
mem_address = NULL;
	#ifndef __linux__
	PRINTF("exiting...\nBye!!\n\r");
   	#else
	printf("exiting...\nBye!!\n\r");
	#endif

exit(0);
return 0;
}

