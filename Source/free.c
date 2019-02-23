#include<stdlib.h>
#include<stdio.h>
#include "../Include/free.h"
#include "../Include/allocate.h"
int free_mem()
{
	free(mem_address);
	printf("MEMORY FREED!");
	printf("\nEnter the function to be executed or Press Help for function information or Press Exit to Quit\n");	
	return 0;
}

