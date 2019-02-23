/***********************************************************************************
* @exit.c
* @This file contains the function to exit from the program
* @author Amreeta Sengupta & Ridhi Shah
************************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include "../Include/exit.h"
#include "../Include/free.h"
#include "../Include/allocate.h"
int Exit()
{
free(mem_address);
printf("exiting...\nBye!!\n");
exit(0);
return 0;
}
