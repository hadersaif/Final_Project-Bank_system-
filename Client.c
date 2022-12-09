#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#include"Types.h"
#include"Admin.h"
#include"Client.h"

extern node*ptr;
extern node*first;
extern node*last;

/*
In this function, you will be asked to enter the required Bank Account ID
Transfer money to. Then you will be asked to enter an amount of money to
Transfer it to this account.
You have to make sure that the money amount is less than the customer amount
balance or transaction will not be completed.
Next, check that the account is active
>>>(used by admin mode and client mode)
*/

 
void make_transaction(u32 bank_account_ID_transfrom,u32 bank_account_ID_transto,u32 amount_of_money){
	u8 flag1=0,flag2=0;
	ptr=first;
	while(ptr!=NULL)
	{
			if(bank_account_ID_transfrom==ptr->bank_account_ID&& ptr->account_status==1&&ptr->balance>amount_of_money)
			{
				flag1=1;
			}
			if(bank_account_ID_transto==ptr->bank_account_ID && ptr->account_status==1)
			{
				flag2=1;
			}
		ptr=ptr->next;
	}
	if(flag1==1&&flag2==1)
	{	ptr=first;
		while(ptr!=NULL)
		{
			if(bank_account_ID_transfrom==ptr->bank_account_ID&& ptr->account_status==1)
			{
				printf("your balance Old was :%d \n",ptr->balance);
				ptr->balance-=amount_of_money;
				printf("your balance now is :%d \n",ptr->balance);
			}
			if(bank_account_ID_transto==ptr->bank_account_ID && ptr->account_status==1)
			{
				printf("your balance Old was :%d \n",ptr->balance);
				ptr->balance+=amount_of_money;
				printf("your balance now is :%d \n",ptr->balance);
			}
		ptr=ptr->next;
		}
	}else{printf("the entered accounts either not active or not existing\n");}

}


/*
In this function, you will be asked to enter the amount of cash you want
This account will be reduced from your account balance.
Hence make sure that the cash amount is less than the account balance before
*/
void Get_cash(u32 bank_account_ID,u32 amount_required_toget){
	ptr=first;
			while(ptr!=NULL)
			{
				if( ptr->bank_account_ID==bank_account_ID&&ptr->balance>amount_required_toget&&ptr->account_status==1)
				{
					printf("your balance was  :%d \n",ptr->balance);
					ptr->balance-=amount_required_toget;
					printf("your balance now is :%d \n",ptr->balance);
				}
				ptr=ptr->next;
			}
}
 

/*
In this function you will be asked to enter the cash amount you want to add
to this account.
>>> (used by admin mode and client mode)
*/
void Deposit_in_Account(u32 bank_account_ID,u32 amount_required_toput){

	ptr=first;
			while(ptr!=NULL)
			{
				if( ptr->bank_account_ID==bank_account_ID&&ptr->account_status==1)
				{
					printf("your balance Old was :%d \n",ptr->balance);
					ptr->balance+=amount_required_toput;
					printf("your balance now is :%d \n",ptr->balance);
				}
				ptr=ptr->next;
			}



}


/*
In this function client will be able to change his password by entering old 
password then the new password
*/
void change_pw(u32 old_pw,u32 new_pw,u32 bank_account_ID){
	ptr=first;
			while(ptr!=NULL)
			{
				if( ptr->pw==old_pw&&bank_account_ID==ptr->bank_account_ID)
				{
					ptr->pw=new_pw;
				}
				ptr=ptr->next;
			}
}




void client_mode(void){

	u32 bank_account_ID1,pw1;
	printf("please enter the bank account ID :");
	scanf("%d",&bank_account_ID1);
	printf("please enter the password for bank account :");
	
	scanf("%d",&pw1);
	fflush(stdin);
	ptr=first;
	u8 flag=0;
	
	
	while(ptr!=NULL)
	{
		if (bank_account_ID1== ptr->bank_account_ID&&pw1==ptr->pw)
		{
			u32 choice1;
			printf("           >>>(welcome our dear client)<<< \n");
			printf("please select from the below menu:\n");
			printf("1:change account password\n");
			printf("2:make transaction\n");
			printf("3:Get cash\n");
			printf("4:Deposite in the account \n");
			printf("5:return to main menu \n");
			printf("your choice :");
			scanf("%d",&choice1);
			switch(choice1)
			{
				case 1:
				{
					u32 new,old,id;
					printf("please enter the old password");
					scanf("%d",&old);
					printf("please enter the new password");
					scanf("%d",&new);
					printf("please enter the account bank id");
					scanf("%d",&id);
					scanf("%d",&new);
					change_pw(old,new,id);
					return;

				}
				break;
				case 2:
				{
					u32 bank_ID_from, bank_ID_to, amount;
					printf("please enter the bank account ID trans from \n");
					scanf("%d",&bank_ID_from);
					printf("please enter the bank account ID trans to \n");
					scanf("%d",&bank_ID_to);
					printf("please enter the amount of money \n");
					scanf("%d",&amount);
					make_transaction(bank_ID_from, bank_ID_to, amount);
					return;

				}
				break;
				case 3:
				{
					u32 get,id;
					printf("please enter the amount of cash needed ");
					scanf("%d",&get);
					printf("please enter the bank account id  ");
					scanf("%d",&id);
					Get_cash(id,get);
					return;
				}
				break;
				case 4:
				{
					u32 dep,id;
					printf("please enter the amount of cash to deposit ");
					scanf("%d",&dep);
					printf("please enter the account bank id");
					scanf("%d",&id);
					Deposit_in_Account(id,dep);
					return;
				}
				break;
				case 5:
				return;
				break;

				default:
				printf("wrong choice :)\n");
				break;
			}
		}
		ptr=ptr->next;
	}
	if (flag==0)
	{
		printf("incorrect ID or password\n");
	}
}
