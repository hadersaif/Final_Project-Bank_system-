#include<stdio.h>
#include"bank.h"

void main()
{
	int choice,Exit=0;
	creat_Imaginary_account();
	while(1)
	{
		printf("*** Welcome to Bank account system ***\n");
		printf("to enter Admin mode press>>> 1\nto enter client mode press>>> 2\nyour choice is :");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
			admin_mode(&Exit);
			break;
			case 2:
			client_mode();
			break;
			default:
			printf("wrong choice\n");
			break;
 		}
		if(Exit==1)
		{
			break;
		}		
	
	}
}