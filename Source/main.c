/***********************************************************************************
* @main.c
* @This file contains main body of the code which includes the logic to call a function using     function pointers depending upon the input given by the user
* @authors Amreeta Sengupta & Ridhi Shah
************************************************************************************/
#include <stdio.h>
#include <string.h>
#include "../Include/main.h"
#include "../Include/help.h"
#include "../Include/exit.h"

struct table 
	{
		char *inp;
		int (*func)();
		
	};
	
void main()
{   
	struct table op[] = {{"Help",&Help},{"Exit",&Exit}};
	char input[30];
	int i;
	printf("Welcome! \nPress Help for function information and Press Exit to Quit\n");
	while (1)
	{	
		
		
		scanf("%s",input);
		int err=1;
		for (i=0; i<2; i++)
		  
			{
				if(strcmp (input, op[i].inp) == 0)
					{
						err=0;
						(*op[i].func)();
						
					}
				
			}
		if(err==1)
		{
			printf("invalid option");
		}
		
	}
		

}


