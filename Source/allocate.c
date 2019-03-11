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

uint32_t *mem_address;
uint32_t num_words;

int allocate()
{


		l1:
		#ifndef __linux__
		PRINTF("Enter the number of 32 bit word to be allocated\n\r>>");
	   	   #else
		printf("Enter the number of 32 bit word to be allocated\n\r>>");
		#endif

		#ifndef __linux__
		SCANF("%d",&num_words);
	   	 #else
		scanf("%d",&num_words);
		#endif
		#ifndef __linux__
		PRINTF("%d\n\r",num_words);
		#endif

		if(num_words == 0)
		{
			printf("Zero size entered...!!!\n");
			goto l1;
		}

		mem_address=(uint32_t *)malloc(num_words*sizeof(int));	// Allocating 32 bit words according to the number specified by user

		if(mem_address!=NULL)
		{
			#ifndef __linux__
			PRINTF("MEMORY ALLOCATED!! \nStarting adrress of the memory block is %p\n\r",mem_address);
   	   	   #else
			printf("MEMORY ALLOCATED!! \nStarting adrress of the memory block is %p\n\r",mem_address);
			#endif
			#ifndef __linux__
			PRINTF("\nEnter the function to be executed or Press Help for function information or Press Exit to Quit\n\r>>");	//if malloc returns a value, memory is allocated
   	   	   #else
			printf("\nEnter the function to be executed or Press Help for function information or Press Exit to Quit\n\r>>");	//if malloc returns a value, memory is allocated
			#endif

		}
		else
		{
			#ifndef __linux__
			PRINTF("ALLOCATION FAILED!! Free memory and try again");
   	   	   #else
			printf("ALLOCATION FAILED!! Free memory and try again");
			#endif

		}

return 0;
}

