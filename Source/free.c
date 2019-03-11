/***********************************************************************************
* @free.c
* @This function frees the memory according to the user input.
* @Tools used : GCC & GNU make
* @author Amreeta Sengupta & Ridhi Shah
************************************************************************************/
#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
#include "../Include/free.h"

extern uint32_t *mem_address;
extern uint32_t num_words;

int free_mem()
{
	free(mem_address); // using free() function to release the allocated memory
	mem_address = NULL;
	#ifndef __linux__
	PRINTF("MEMORY FREED!\n\r");
   	#else
	printf("MEMORY FREED!\n\r");
	#endif

    #ifndef __linux__
	PRINTF("\nEnter the function to be executed or Press Help for function information or Press Exit to Quit\n\r>>");
   	#else
	printf("\nEnter the function to be executed or Press Help for function information or Press Exit to Quit\n\r>>");
	#endif


	return 0;
}


