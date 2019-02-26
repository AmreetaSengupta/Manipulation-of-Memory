/***********************************************************************************
* @allocate.c
* @This function allocates the memory according to the user input.
* @Tools used : GCC & GNU make
* @author Amreeta Sengupta & Ridhi Shah
************************************************************************************/
#include<stdio.h>
#include<stdint.h>
#include<stdlib.h>
#include "../Include/allocate.h"

int allocate()
{

	
		l1: printf("Enter the number of 32 bit word to be allocated\n>>");
		scanf("%d",&num_words);
		if(num_words == 0)
		{
			printf("Zero size entered...!!!\n");
			goto l1;
		}
		
		mem_address=(uint32_t *)malloc(num_words*sizeof(int));	// Allocating 32 bit words according to the number specified by user
		
		if(mem_address!=NULL)
		{
		printf("MEMORY ALLOCATED!! \nStarting adrress of the memory block is %p\n",mem_address);
		printf("\nEnter the function to be executed or Press Help for function information or Press Exit to Quit\n>>");	//if malloc returns a value, memory is allocated
		}
		else
		{
		printf("ALLOCATION FAILED!! Free memory and try again");
		}
	
return 0;	
}
