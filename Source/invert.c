#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
#include<time.h>
#include "../Include/allocate.h"
#include "../Include/invert.h"


int invert()
{
	uint64_t wr_address,offset_address;
uint32_t data;
int i,j,k;

char ans;
int offset;
	if(mem_address==NULL)
{
	printf("Memory is not allocated! Use the command Allocate \n");
}
else
{
for(j=0;j<num_words;j++)
{
	printf("Adresses allocated are %p",(mem_address+j));
	printf("\n");
}

label2: printf("Address or Offset?\n");
scanf("%s",&ans);


if(ans == 'a' || ans =='A')
{
	label1: printf("enter the adress\n");
	scanf("%lx",&wr_address);
	int flag1=1;

	for (i=0; i<num_words;i++)
	{
		if(((uint32_t*)wr_address>=mem_address&&(uint32_t*)wr_address<(mem_address+num_words))&&((uint32_t*)wr_address == (mem_address+i)))
			{
				flag1=0;
				printf("data at %p = 0x%x before inverting\n",(mem_address+i),*(mem_address+i));
				*(mem_address+i)=~(*(mem_address+i));
				printf("data at %p = 0x%x after inverting\n",(mem_address+i),*(mem_address+i));
			}
	
	}
	if (flag1==1)
		{
			printf("Invalid Address\n");
			goto label1;
		}
}
else if(ans=='o'||ans=='O')
	{
		label3:printf("Enter the offset between 0 to %d",(num_words-1));
		scanf("%d",&offset);
	offset_address = (uint64_t)(mem_address+offset);
		int flag2=1;
	for (i=0; i<num_words;i++)
		{
			if(((uint32_t*)offset_address>=mem_address && (uint32_t*)offset_address<(mem_address+num_words)) && ((uint32_t*)offset_address == (mem_address+i)))
				{
					flag2=0;
				
				printf("data at %p = 0x%x before inverting\n",(mem_address+i),*(mem_address+i));
				*(mem_address+i)=~(*(mem_address+i));
				printf("data at %p = 0x%x after inverting\n",(mem_address+i),*(mem_address+i));
					
				}
		}
		if (flag2==1)
			{
				printf("Invalid Address\n");
				goto label3;
			}
	}

else if((ans !=('a'||'A')) && (ans !=('o'||'O')))
	{
		printf("Invalid Input! Enter again\n ");
		goto label2;
	
	}

}	
return 0;
}
