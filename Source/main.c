/***********************************************************************************
* @main.c
* @This file contains main body of the code which includes the logic to call a function using
* function pointers depending upon the input given by the user
* @Tools used : GCC & GNU make
* @authors Amreeta Sengupta & Ridhi Shah
* @references (upper case to lower case function): https://www.programmingsimplified.com/c/program/c-program-change-case
************************************************************************************/

#include "../Include/main.h"

void lower_string(char s[]);
struct table
	{
		char *inp;
		int (*func)();

	};

int main()
{
	struct table op[] = {{"help",&Help},{"exit",&Exit},{"allocate",&allocate},{"free",&free_mem},{"write",&write},{"invert",&invert},{"display",&display},{"write_pattern",&write_pattern},{"verify_pattern",&verify_pattern}}; //A structure that acts as a lookup table for all the funcions
	char input[30];
	int i;
    #ifndef __linux__
	BOARD_InitPins();
	BOARD_BootClockRUN();
	BOARD_InitDebugConsole();
	#endif
	a1:
	#ifndef __linux__
	PRINTF("Welcome! \n\rPress Help for function information and Press Exit to Quit\n\r>>");
   #else
	printf("Welcome! \nPress Help for function information and Press Exit to Quit\n\r>>");
	#endif
	//PRINTF("Trst\n");
	while (1)
	{

#ifndef __linux__
		SCANF("%s",input);
		//PRINTF("INPUT %s",input);
		#else
		scanf("%s",input);
		#endif//taking the input string from user for the function to be performed
		#ifndef __linux__
		PRINTF("%s\n\r",input);
		//PRINTF("INPUT %s",input);
		#endif
		lower_string(input);
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
	#ifndef __linux__
	PRINTF("Invalid option! Enter again!\n\r");
   #else
	printf("Invalid option! Enter again!\n\r");
	#endif
	goto a1;
           //if invalid string is entered ask user to enter again
		}

	}
	return 0;

}

void lower_string(char s[])
{
	int c=0;
	while (s[c]!='\0')
		{
		  if(s[c]>='A' && s[c] <= 'Z')
			{ s[c]=s[c]+32;
			}
			c++;
			}}


