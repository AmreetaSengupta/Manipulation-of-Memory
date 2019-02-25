/***********************************************************************************
* @help.c
* @This file displays the entire help menu with a description of what each function does.
* @Tools used : GCC & GNU make
* @author Amreeta Sengupta & Ridhi Shah
************************************************************************************/
#include<stdio.h>
#include<string.h>
#include "../Include/help.h"

int Help()
{
printf("Allocate       : allocates block of memory for the size specified by the user\
      \nFree           : Releases the previously allocated memory block\
      \nDisplay        : displays the contents of the memory in hexadecimal format\
      \nWrite          : writes a 32-bit word to the specified address\
      \nInvert         : inverts all memory bits in a specified area of memory \
      \nWrite pattern  : write a random pattern in a specified area of memory\
      \nVerify pattern : verify the contents of memory written \
      \nExit           : exits from the program\n\n>>");
return 0;
}
