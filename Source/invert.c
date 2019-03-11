/***********************************************************************************
* @invert.c
* @This function inverts the data written into the allocated memory locations as per
* the user's choice.
* @Tools used : GCC & GNU make
* @author Amreeta Sengupta & Ridhi Shah
************************************************************************************/
#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
#include<time.h>
#include "../Include/invert.h"

#ifdef __linux__
#include "time.h"
#endif

extern uint32_t *mem_address;
extern uint32_t num_words;

int invert()
{

uint64_t wr_address,offset_address;
float period = (.047619);
uint32_t count = 0;
int i,j;

char ans;
int offset;
if(mem_address==NULL)	 //checking if memory is allocated
{
			#ifndef __linux__
			PRINTF("Memory is not allocated! Use the command Allocate! \n\r>>");
   			#else
			printf("Memory is not allocated! Use the command Allocate! \n\r>>");
			#endif

}
else
{
	for(j=0;j<num_words;j++)	//Printing the address of the 32 bit allocated words
	{
			#ifndef __linux__
			PRINTF("Adresses allocated are %p",(mem_address+j));
   			#else
			printf("Adresses allocated are %p",(mem_address+j));
			#endif



			#ifndef __linux__
			PRINTF("\n\r");
   			#else
			printf("\n\r");
			#endif


	}



/*#ifndef __linux__
				SysTick_Config(16000000);
			#else
				clock_t start = clock();
			#endif*/

				label2:
				#ifndef __linux__
			PRINTF("Press 'A' to enter the Address or press 'O' to enter the Offset?\n\r>>");
   			#else
			printf("Press 'A' to enter the Address or press 'O' to enter the Offset?\n\r>>");
			#endif

	// asking user if he wants to enter address or offset

			#ifndef __linux__
			SCANF("%s",&ans);
   			#else
			scanf("%s",&ans);
			#endif

			#ifndef __linux__
			PRINTF("%s\n\r",ans);
			#endif



if(ans == 'a' || ans =='A')
{
	label1:
			#ifndef __linux__
			PRINTF("Enter the adress\n\r>>");
   			#else
			printf("Enter the adress\n\r>>");
			#endif

	// taking the address input from user

			#ifndef __linux__
			SCANF("%x",&wr_address);
   			#else
			scanf("%lx",&wr_address);
			#endif

			#ifndef __linux__
			PRINTF("%x\n\r",wr_address);
			#endif

	int flag1=1;

	for (i=0; i<num_words;i++)
	{
		if(((uint32_t*)wr_address>=mem_address&&(uint32_t*)wr_address<(mem_address+num_words))&&((uint32_t*)wr_address == (mem_address+i))) // checking if address is in the allocated and is the starting address of each 32 bit word
			{
				flag1=0;
				#ifndef __linux__
				PRINTF("Data at %p = 0x%x before inverting\n\r",(mem_address+i),*(mem_address+i));
   				#else
				printf("Data at %p = 0x%x before inverting\n\r",(mem_address+i),*(mem_address+i));
				#endif

	#ifndef __linux__
				SysTick_Config(16000000);
			#else
				clock_t start = clock();
			#endif

				*(mem_address+i)=~(*(mem_address+i)); //Inverting the data at the specified address using bitwise NOT operator


				#ifndef __linux__
				PRINTF("Data at %p = 0x%x after inverting\n\r",(mem_address+i),*(mem_address+i));
   				#else
				printf("Data at %p = 0x%x after inverting\n\r",(mem_address+i),*(mem_address+i));
				#endif

#ifndef __linux__
				count = 16000000 - SysTick->VAL;
				SysTick->CTRL = 0;
				float diff = (period*count);
			#else
				clock_t stop = clock();
				double time_taken = ((double)stop - (double)start)/CLOCKS_PER_SEC;
			#endif

			#ifndef __linux__
			PRINTF("\r\nTime taken to execute this function is: %f us\r\n",diff);
			 #else
			printf("Time taken to perform this Function is : %f seconds\n\r", time_taken);
			#endif	//computing the difference between start and end and displaying the time taken in seconds


				#ifndef __linux__
				PRINTF("\nEnter the function to be executed or Press Help for function information or Press Exit to Quit\n\r>>");
   				#else
				printf("\nEnter the function to be executed or Press Help for function information or Press Exit to Quit\n\r>>");
				#endif


			}

	}
	if (flag1==1)
		{
			#ifndef __linux__
			PRINTF("Invalid Address! Enter again!\n\r");
   			#else
			printf("Invalid Address! Enter again!\n\r");
			#endif

			//if adress is out of range ask user to enter the address again
			goto label1;
		}
}
else if(ans=='o'||ans=='O')
	{
		label3:
			#ifndef __linux__
			PRINTF("Enter the offset between 0 to %d\n\r>>",(num_words-1));
   			#else
			printf("Enter the offset between 0 to %d\n\r>>",(num_words-1));
			#endif



			#ifndef __linux__
			SCANF("%d",&offset);
   			#else
			scanf("%d",&offset);
			#endif

			#ifndef __linux__
			PRINTF("%d\n\r",offset);
			#endif

	offset_address = (uint64_t)(mem_address+offset); // adding the offset to the starting address of the alloctaed block
		int flag2=1;
	for (i=0; i<num_words;i++)
		{
			if(((uint32_t*)offset_address>=mem_address && (uint32_t*)offset_address<(mem_address+num_words)) && ((uint32_t*)offset_address == (mem_address+i)))  //chceking if address is in range
				{
					flag2=0;
					#ifndef __linux__
					PRINTF("Data at %p = 0x%x before inverting\n\r",(mem_address+i),*(mem_address+i));
					#else
					printf("Data at %p = 0x%x before inverting\n\r",(mem_address+i),*(mem_address+i));
					#endif

					#ifndef __linux__
				SysTick_Config(16000000);
			#else
				clock_t start = clock();
			#endif

				*(mem_address+i)=~(*(mem_address+i)); //Inverting the data at the specified address using bitwise NOT operator


				#ifndef __linux__
				PRINTF("Data at %p = 0x%x after inverting\n\r",(mem_address+i),*(mem_address+i));
   				#else
				printf("Data at %p = 0x%x after inverting\n\r",(mem_address+i),*(mem_address+i));
				#endif

				#ifndef __linux__
					count = 16000000 - SysTick->VAL;
					SysTick->CTRL = 0;
					float diff = (period*count);
				#else
					clock_t stop = clock();
					double time_taken = ((double)stop - (double)start)/CLOCKS_PER_SEC;
				#endif

				#ifndef __linux__
				PRINTF("\r\nTime taken to execute this function is: %f us\r\n",diff);
				 #else
				printf("Time taken to perform this Function is : %f seconds\n\r", time_taken);
				#endif	//computing the difference between start and end and displaying the time taken in seconds


				#ifndef __linux__
				PRINTF("\nEnter the function to be executed or Press Help for function information or Press Exit to Quit\n\r>>");
   				#else
				printf("\nEnter the function to be executed or Press Help for function information or Press Exit to Quit\n\r>>");
				#endif



				}
		}
		if (flag2==1)
			{
			#ifndef __linux__
			PRINTF("Invalid Address! Enter again!\n\r");
   			#else
			printf("Invalid Address! Enter again!\n\r");
			#endif


				goto label3;
			}
	}

else if((ans !=('a'||'A')) && (ans !=('o'||'O'))) //if the input for selecting either address of offset is wrong then asking user to enter again
	{
			#ifndef __linux__
			PRINTF("Invalid Input! Enter again\n\r");
   			#else
			printf("Invalid Input! Enter again\n\r ");
			#endif


		goto label2;

	}

}

/*#ifndef __linux__
	count = 16000000 - SysTick->VAL;
	SysTick->CTRL = 0;
	float diff = (period*count);
#else
	clock_ stop = clock();
	double time_taken = ((double)stop - (double)start)/CLOCKS_PER_SEC;
#endif

#ifndef __linux__
PRINTF("\r\nTime taken to execute this function is: %f us\r\n",diff);
 #else
printf("Time taken to perform this Function is : %f seconds\n\r", time_taken);
#endif	//computing the difference between start and end and displaying the time taken in seconds

#ifndef __linux__
PRINTF("\nEnter the function to be executed or Press Help for function information or Press Exit to Quit\n\r>>");
#else
printf("\nEnter the function to be executed or Press Help for function information or Press Exit to Quit\n\r>>");
#endif*/

return 0;
}

