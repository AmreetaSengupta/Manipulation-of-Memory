#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
#include "../Include/allocate.h"
#include "../Include/invert.h"

int num_invert;
int m,n;
int invert()
{
	for(m=0;m<num_words;m++)
{
	printf("Adresses allocated for 32 bit words  are %p",(mem_address+m));
	printf("\n");
}

printf("Enter the number of words you want to invert");
scanf("%d",&num_invert);
for (n=0; n<num_invert;n++)
	{
		if(num_invert<num_words)
			{
				
				*(mem_address+n)=~(*(mem_address+n));
				printf("data at %p = 0x%x\n",(mem_address+n),*(mem_address+n));
			}
	
	}
}
