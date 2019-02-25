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


int invert()
{
	clock_t start_time = clock(); //taking the timestamp using clock function at the start of function and storing it in a variable 
uint64_t wr_address,offset_address;
uint32_t data;
int i,j,k;

char ans;
int offset;
if(mem_address==NULL)	 //checking if memory is allocated 
{
	printf("Memory is not allocated! Use the command Allocate! \n>>");
}
else
{
	for(j=0;j<num_words;j++)	//Printing the address of the 32 bit allocated words
	{
		printf("Adresses allocated are %p",(mem_address+j));
		printf("\n");
	}

	label2: printf("Press 'A' to enter the Address or press 'O' to enter the Offset?\n>>");		// asking user if he wants to enter address or offset
	scanf("%s",&ans);


if(ans == 'a' || ans =='A')
{
	label1: printf("Enter the adress\n>>"); // taking the address input from user
	scanf("%lx",&wr_address);
	int flag1=1;

	for (i=0; i<num_words;i++)
	{
		if(((uint32_t*)wr_address>=mem_address&&(uint32_t*)wr_address<(mem_address+num_words))&&((uint32_t*)wr_address == (mem_address+i))) // checking if address is in the allocated and is the starting address of each 32 bit word
			{
				flag1=0;
				printf("Data at %p = 0x%x before inverting\n",(mem_address+i),*(mem_address+i));
				*(mem_address+i)=~(*(mem_address+i)); //Inverting the data at the specified address using bitwise NOT operator
				printf("Data at %p = 0x%x after inverting\n",(mem_address+i),*(mem_address+i));
				printf("\nEnter the function to be executed or Press Help for function information or Press Exit to Quit\n>>");	
			}
	
	}
	if (flag1==1)
		{
			printf("Invalid Address! Enter again!\n");	//if adress is out of range ask user to enter the address again
			goto label1;
		}
}
else if(ans=='o'||ans=='O')
	{
		label3:printf("Enter the offset between 0 to %d\n>>",(num_words-1));
		scanf("%d",&offset);
	offset_address = (uint64_t)(mem_address+offset); // adding the offset to the starting address of the alloctaed block 
		int flag2=1;
	for (i=0; i<num_words;i++)
		{
			if(((uint32_t*)offset_address>=mem_address && (uint32_t*)offset_address<(mem_address+num_words)) && ((uint32_t*)offset_address == (mem_address+i)))  //chceking if address is in range
				{
					flag2=0;
				
				printf("Data at %p = 0x%x before inverting\n",(mem_address+i),*(mem_address+i));
				*(mem_address+i)=~(*(mem_address+i)); //Inverting the data at the specified address using bitwise NOT operator
				printf("Data at %p = 0x%x after inverting\n",(mem_address+i),*(mem_address+i));
				printf("\nEnter the function to be executed or Press Help for function information or Press Exit to Quit\n>>");	
					
				}
		}
		if (flag2==1)
			{
				printf("Invalid Address! Enter again!\n");
				goto label3;
			}
	}

else if((ans !=('a'||'A')) && (ans !=('o'||'O'))) //if the input for selecting either address of offset is wrong then asking user to enter again
	{
		printf("Invalid Input! Enter again\n ");
		goto label2;
	
	}

}
clock_t stop_time=clock(); //taking the time stamp at the end of the function
printf("Time taken to perform Invert Function is : %f seconds\n", (double)(stop_time-start_time)/CLOCKS_PER_SEC);	//computing the difference between start and end and displaying the time taken in seconds
printf("\nEnter the function to be executed or Press Help for function information or Press Exit to Quit\n>>");	
return 0;
}
