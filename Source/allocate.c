#include<stdio.h>
#include<stdint.h>
#include<stdlib.h>
#include "../Include/allocate.h"

int allocate()
{

	
		printf("Enter the number of 32 bit word to be allocated\n");
		scanf("%d",&num_words);
		mem_address=(uint32_t *)malloc(num_words*sizeof(int));	
		if(mem_address!=NULL)
		{
		printf("MEMORY ALLOCATED!! \n Starting adrress of the memory block is %p\n",mem_address);
		printf("\nEnter the function to be executed or Press Help for function information or Press Exit to Quit\n");	
		}
		else
		{
		printf("ALLOCATION FAILED!! Free memory and try again");
		}
	
return 0;	
}
