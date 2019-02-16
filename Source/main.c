#include <stdio.h>
#include <string.h>
void Help();
void Exit();


struct table 
	{
		char *inp;
		int (*func)();
		
	};
	
void main()
{   
	struct table op[] = {{"H",&Help},{"E",&Exit}};
	char input[30];
	int i;
	while (1)
	{	
		
		printf("Welcome! \nPress H for function information and Press E to quit \n");
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

void Help()
{
	printf("Help \n");
	
}


void Exit()
{
	printf("Exit \n");
}
