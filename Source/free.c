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

int free_mem()
{
	free(mem_address); // using free() function to release the allocated memory
	mem_address = NULL;
	printf("MEMORY FREED!");
	printf("\nEnter the function to be executed or Press Help for function information or Press Exit to Quit\n>>");	
	return 0;
}

