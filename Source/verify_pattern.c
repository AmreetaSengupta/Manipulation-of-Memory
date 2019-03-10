#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
#include "../Include/verify_pattern.h"

int verify_pattern()
{
uint64_t rd_address,offset_address;
uint32_t data,size;
int i,j,k;
int verify =1;
uint32_t rand_num, read_num;

char ans;
int offset;
if(mem_address==NULL) //checking if memory is allocated 
{
	printf("Memory is not allocated! Use the command Allocate! \n>>");
}
else
{
	for(j=0;j<num_words;j++) //Printing the address of the 32 bit allocated words
	{
		printf("Adresses allocated are %p",(mem_address+j));
		printf("\n");
	}

label2: printf("Press 'A' to enter the Address or press 'O' to enter the Offset?\n>>"); // asking user if he wants to enter address or offset
scanf("%s",&ans);


if(ans == 'a' || ans =='A')				
{
	label1: printf("Enter the address\n>>"); // taking the address input from user
	scanf("%lx",&rd_address);
	label5:
	printf("Enter the size\n>>"); // taking the address input from user
	scanf("%d",&size);
	
	
	
	
	//for (i=0; i<num_words;i++)
	{
		if(((uint32_t*)rd_address>=mem_address && (uint32_t*)rd_address<(mem_address+num_words)) && ((rd_address-(uint64_t)mem_address)%4 ==0))//((uint32_t*)wr_address == (mem_address+i))) // checking if address is in the allocated and is the starting address of each 32 bit word
			{
								
				if((mem_address+num_words)>(uint32_t*)(rd_address+(size<<2)))
				{
					printf("Enter the seed value\n>>");			// taking the data to be written from the user
					scanf("%d",&data);
					rand_num = data;
					for(int s = 0; s<=size; s++)
					{
						rand_num = random_generator(rand_num);
						read_num = *((uint32_t*)rd_address+s);  
							
						if(read_num != rand_num)							
						{
							verify = 0;
							printf("Discrepancy Found at address: 0X%p!\n",((uint32_t*)rd_address+s));
							printf("Expected value = %d\nPresent value = %d\n",rand_num,read_num);
						}
						if(verify)
						{
							printf("Successfully found!\nAddress: 0X%p!\n",((uint32_t*)rd_address+s));
							printf("Expected value = %d\nPresent value = %d\n",rand_num,read_num);
						}
						
					}
					//printf("Data successfully Written!\n");
					printf("\nEnter the function to be executed or Press Help for function information or Press Exit to Quit\n>>");	
				}
				else
				{
					printf("Invalid Size! Enter size again!\n");
					goto label5;
				}
	
			}
	else
		{
			printf("Invalid Address! Enter address again!\n");		// if adress is out of range ask user to enter the address again
			goto label1;
		}
	}
}

else if(ans=='o'||ans=='O')
	{
		label3:printf("Enter the offset between 0 to %d\n>>",(num_words-1)); 
		scanf("%d",&offset);
		offset_address = (uint64_t)(mem_address+offset);			// adding the offset to the starting address of the alloctaed block 
		label4:
		printf("Enter the size\n>>"); // taking the address input from user
		scanf("%d",&size);
	
		
	//for (i=0; i<num_words;i++)
		if(((uint32_t*)offset_address>=mem_address && (uint32_t*)offset_address<(mem_address+num_words)) && ((offset_address-(uint64_t)mem_address)%4 ==0))//((uint32_t*)wr_address == (mem_address+i))) // checking if address is in the allocated and is the starting address of each 32 bit word
			{
				
				if((mem_address+num_words)> (uint32_t*)(offset_address+(size<<2)))
				{
					printf("Enter the seed value\n>>");			// taking the data to be written from the user
					scanf("%d",&data);
					rand_num = data;
					for(int s=0; s<size; s++)
					{
						rand_num = random_generator(rand_num);
						*(mem_address+s)= rand_num;  				//writing data to the memory address specified.
				
					}
					
					printf("Data successfully Written!\n");
					printf("\nEnter the function to be executed or Press Help for function information or Press Exit to Quit\n>>");	
				}
				else
				{
					printf("Invalid Size! Enter size again!\n");
					goto label4;
				}
			}
		else
			{
				printf("Invalid Offset! Enter offset again!\n");
				goto label3;
			}
	}

else if((ans !=('a'||'A')) && (ans !=('o'||'O'))) //if the input for selecting either address of offset is wrong then asking user to enter again
	{
		printf("Invalid Input! Enter again\n ");
		goto label2;
	
	}

}	
return 0;

}
