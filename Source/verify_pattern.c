/***********************************************************************************
* @verify_pattern.h
* @This file contains the function that verifies the random numbers wriiten by the user to blocks of ddresses
* function
* @Tools used : GCC & GNU make
* @author Amreeta Sengupta & Ridhi Shah
************************************************************************************/
#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
#include "../Include/write_pattern.h"

extern uint32_t *mem_address;
extern uint32_t num_words;

#ifdef __linux__
#include "time.h"
#endif

int verify_pattern()
{
uint64_t rd_address,offset_address;
uint32_t data,size;
int verify=1;
int i,j;
float period = (.020833);
uint32_t count = 0;
uint32_t rand_num,read_num;
#ifndef __linux__
BOARD_InitPins();
	BOARD_BootClockRUN();
	BOARD_InitDebugConsole();
#endif

char ans;
int offset;
if(mem_address==NULL) //checking if memory is allocated
{
		#ifndef __linux__
		PRINTF("Memory is not allocated! Use the command Allocate! \n\r>>");
		#else
		printf("Memory is not allocated! Use the command Allocate! \n\r>>");
		#endif

}
else
{
	for(j=0;j<num_words;j++) //Printing the address of the 32 bit allocated words
	{
			#ifndef __linux__
			PRINTF("Addresses allocated are %p",(mem_address+j));
   			#else
			printf("Addresses allocated are %p",(mem_address+j));
			#endif


			#ifndef __linux__
			PRINTF("\n\r");
   			#else
			printf("\n\r");
			#endif

	}





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
	PRINTF("Enter the address\n\r>>");
   	#else
	printf("Enter the address\n\r>>");
	#endif
	 // taking the address input from user

	#ifndef __linux__
	SCANF("%x",&rd_address);
   	#else
	scanf("%lx",&rd_address);
	#endif
	#ifndef __linux__
	PRINTF("%x\n\r",rd_address);
	#endif
	label5:
	#ifndef __linux__
	PRINTF("Enter the size\n\r>>");
   	#else
	printf("Enter the size\n\r>>");
	#endif
	 // taking the address input from user

	#ifndef __linux__
	SCANF("%d",&size);
   	#else
	scanf("%d",&size);
	#endif

	#ifndef __linux__
	PRINTF("%d\n\r",size);
	#endif


	//for (i=0; i<num_words;i++)
	{
		if(((uint32_t*)rd_address>=mem_address && (uint32_t*)rd_address<(mem_address+num_words)) && ((rd_address-(uint64_t)mem_address)%4 ==0))//((uint32_t*)wr_address == (mem_address+i))) // checking if address is in the allocated and is the starting address of each 32 bit word
			{

				if(((mem_address+num_words)>=(uint32_t*)(rd_address+(size<<2)))&&(size!=0))
				{
					#ifndef __linux__
					PRINTF("Enter the seed value\n\r>>");
   					#else
					printf("Enter the seed value\n\r>>");
					#endif
						// taking the data to be written from the user

					#ifndef __linux__
					SCANF("%d",&data);
   					#else
					scanf("%d",&data);
					#endif
					#ifndef __linux__
					PRINTF("%d\n\r",data);
					#endif

					#ifndef __linux__
					SysTick_Config(16000000);
					#else
					clock_t start = clock();
					#endif

					rand_num = data;
					for(int s=0; s<size; s++)
					{
						rand_num = random_generator(rand_num);
						read_num = *((uint32_t*)rd_address+s);
						if(read_num != rand_num)
												{
													verify = 0;
													#ifndef __linux__
													PRINTF("Discrepancy Found at address: 0X%p!\n\r",((uint32_t*)rd_address+s));
													#else
													printf("Discrepancy Found at address: 0X%p!\n\r",((uint32_t*)rd_address+s));
													#endif


													#ifndef __linux__
													PRINTF("Expected value = %d\nPresent value = %d\n\r",rand_num,read_num);
													#else
													printf("Expected value = %d\nPresent value = %d\n\r",rand_num,read_num);
													#endif

												}
												if(verify)
												{
													#ifndef __linux__
													PRINTF("Successfully found!\nAddress: 0X%p!\n\r",((uint32_t*)rd_address+s));
													#else
													printf("Successfully found!\nAddress: 0X%p!\n\r",((uint32_t*)rd_address+s));
													#endif



													#ifndef __linux__
													PRINTF("Expected value = %d\nPresent value = %d\n\r",rand_num,read_num);
													#else
													printf("Expected value = %d\nPresent value = %d\n\r",rand_num,read_num);
													#endif

												}

											}


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
					

				}
				else
				{
					#ifndef __linux__
					PRINTF("Invalid Size! Enter size again!\n\r");
   					#else
					printf("Invalid Size! Enter size again!\n\r");
					#endif

					goto label5;
				}

			}
	else
		{

			#ifndef __linux__
			PRINTF("Invalid Address! Enter again!\n\r");
   			#else
			printf("Invalid Address! Enter again!\n\r");
			#endif
			// if adress is out of range ask user to enter the address again
			goto label1;
		}
	}
					#ifndef __linux__
					PRINTF("\nEnter the function to be executed or Press Help for function information or Press Exit to Quit\n\r>>");
   					#else
					printf("\nEnter the function to be executed or Press Help for function information or Press Exit to Quit\n\r>>");
					#endif
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
		offset_address = (uint64_t)(mem_address+offset);			// adding the offset to the starting address of the alloctaed block
		label4:

		#ifndef __linux__
		PRINTF("Enter the size\n\r>>");
   		#else
		printf("Enter the size\n\r>>");
		#endif
	 // taking the address input from user


		#ifndef __linux__
		SCANF("%d",&size);
   		#else
		scanf("%d",&size);
		#endif

		#ifndef __linux__
		PRINTF("%d\n\r",size);
		#endif

	//for (i=0; i<num_words;i++)
		if(((uint32_t*)offset_address>=mem_address && (uint32_t*)offset_address<(mem_address+num_words)) && ((offset_address-(uint64_t)mem_address)%4 ==0))//((uint32_t*)wr_address == (mem_address+i))) // checking if address is in the allocated and is the starting address of each 32 bit word
			{

				if(((mem_address+num_words)>=(uint32_t*)(offset_address+(size<<2))) && (size != 0))
				{
					#ifndef __linux__
					PRINTF("Enter the seed value\n\r>>");
					#else
					printf("Enter the seed value\n\r>>");
					#endif
					// taking the data to be written from the user

					#ifndef __linux__
					SCANF("%d",&data);
					#else
					scanf("%d",&data);
					#endif
					#ifndef __linux__
					PRINTF("%d\n\r",data);
					#endif

					#ifndef __linux__
						SysTick_Config(16000000);
					#else
						clock_t start = clock();
					#endif
					rand_num = data;
					for(int s=0; s<size; s++)
					{
						rand_num = random_generator(rand_num);
						read_num = *((uint32_t*)offset_address+s);

												if(read_num != rand_num)
															{
																verify = 0;

																#ifndef __linux__
																PRINTF("Discrepancy Found at address: 0X%p!\n\r",((uint32_t*)rd_address+s));
   																#else
																printf("Discrepancy Found at address: 0X%p!\n\r",((uint32_t*)rd_address+s));
																#endif


																#ifndef __linux__
																PRINTF("Expected value = %d\nPresent value = %d\n\r",rand_num,read_num);
   																#else
																printf("Expected value = %d\nPresent value = %d\n\r",rand_num,read_num);
																#endif

															}
															if(verify)
															{
																#ifndef __linux__
																PRINTF("Successfully found!\nAddress: 0X%p!\n\r",((uint32_t*)rd_address+s));
																#else
																printf("Successfully found!\nAddress: 0X%p!\n\r",((uint32_t*)rd_address+s));
																#endif


																#ifndef __linux__
																PRINTF("Expected value = %d\nPresent value = %d\n\r",rand_num,read_num);
   																#else
																printf("Expected value = %d\nPresent value = %d\n\r",rand_num,read_num);
																#endif

															}
											}


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


				}
				else
				{
					#ifndef __linux__
					PRINTF("Invalid Size! Enter size again!\n\r");
   					#else
					printf("Invalid Size! Enter size again!\n\r");
					#endif

					goto label4;
				}
			}
		else
			{
				#ifndef __linux__
				PRINTF("Invalid Offset! Enter offset again!\n\r");
   				#else
				printf("Invalid Offset! Enter offset again!\n\r");
				#endif

				goto label3;
			}
			
					#ifndef __linux__
					PRINTF("\nEnter the function to be executed or Press Help for function information or Press Exit to Quit\n\r>>");
   					#else
					printf("\nEnter the function to be executed or Press Help for function information or Press Exit to Quit\n\r>>");
					#endif
	}
else if((ans !=('a'||'A')) && (ans !=('o'||'O'))) //if the input for selecting either address of offset is wrong then asking user to enter again
	{
		#ifndef __linux__
		PRINTF("Invalid Address! Enter again!\n\r");
   		#else
		printf("Invalid Address! Enter again!\n\r");
		#endif

		goto label2;

	}

}

return 0;

}

