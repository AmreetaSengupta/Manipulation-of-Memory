/***********************************************************************************
* @help.c
* @This file displays the entire help menu with a description of what each function does.
* @Tools used : GCC & GNU make
* @author Amreeta Sengupta & Ridhi Shah
************************************************************************************/
#include<stdio.h>
#include<string.h>
#include "../Include/help.h"
#include "../Include/allocate.h"

int Help()
{
	#ifndef __linux__
	PRINTF( "Allocate       : allocates block of memory for the size specified by the user\
		      \n\rFree           : Releases the previously allocated memory block\
		      \n\rDisplay        : displays the contents of the memory in hexadecimal format\
		      \n\rWrite          : writes a 32-bit word to the specified address\
		      \n\rInvert         : inverts all memory bits in a specified area of memory \
		      \n\rWrite pattern  : write a random pattern in a specified area of memory\
		      \n\rVerify pattern : verify the contents of memory written \
		      \n\rExit           : exits from the program\n\n\r>>");
   	#else
	printf("Allocate       : allocates block of memory for the size specified by the user\
		      \n\rFree           : Releases the previously allocated memory block\
		      \n\rDisplay        : displays the contents of the memory in hexadecimal format\
		      \n\rWrite          : writes a 32-bit word to the specified address\
		      \n\rInvert         : inverts all memory bits in a specified area of memory \
		      \n\rWrite pattern  : write a random pattern in a specified area of memory\
		      \n\rVerify pattern : verify the contents of memory written \
		      \n\rExit           : exits from the program\n\n\r>>");
	#endif

return 0;
}

