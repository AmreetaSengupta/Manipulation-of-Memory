/***********************************************************************************
* @main.c
* @This file contains main body of the code which includes the logic to call a function using     
* function pointers depending upon the input given by the user
* @Tools used : GCC & GNU make
* @authors Amreeta Sengupta & Ridhi Shah
************************************************************************************/
#include <stdio.h>
#include <string.h>
#include "../Include/main.h"
#include "../Include/help.h"
#include "../Include/exit.h"
#include "../Include/allocate.h"
#include "../Include/free.h"
#include "../Include/write.h"
#include "../Include/write_pattern.h"
#include "../Include/verify_pattern.h"
#include "../Include/invert.h"
#include "../Include/display.h"

struct table 
	{
		char *inp;
		int (*func)();
		
	};
	
void main()
{   
	struct table op[] = {{"Help",&Help},{"Exit",&Exit},{"Allocate",&allocate},{"Free",&free_mem},{"Write",&write},{"Invert",&invert},{"Display",&display},{"Write_Pattern",&write_pattern},{"Verify_Pattern",&verify_pattern}}; //A structure that acts as a lookup table for all the funcions
	char input[30];
	int i;
	printf("Welcome! \nPress Help for function information and Press Exit to Quit\n>>");
	while (1)
	{	
		
		
		scanf("%s",input); //taking the input string from user for the function to be performed
		int err=1;
		for (i=0; i<9; i++) 
		  
			{
				if(strcmp (input, op[i].inp) == 0) //comapring the input and calling the appropriate function from the lookup table
					{
						err=0;
						(*op[i].func)();
						
					}
				
			}
		if(err==1)
		{
			printf("Invalid option! Enter again!\n"); //if invalid string is entered ask user to enter again
		}
		
	}
		

}


