#include<stdio.h>
#include"Types.h"
#include"Admin.h"
#include"Client.h"
void main()
{
	u8 choice,Exit=0;
	creat_Imaginary_account();
	while(1)
	{
		printf("-----------------------------------------------\n");
		printf("         Welcome to Bank account system\n");
		printf(" enter Admin mode press>>> 1\n enter client mode press>>> 2");
		printf("\n-----------------------------------------------\n");
		printf("your choice is : ");
		scanf("%d",&choice);
		fflush(stdin);
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