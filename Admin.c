#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#include"Types.h"
#include"Admin.h"
#include"Client.h"
node*ptr;
node*first=NULL;
node*last=NULL;
u64 Global_id=999999;
u32 global_pw=555555;
u32 Global_Admin_user_name=2000;
u32 Global_Admin_password=1234;

/*creating an empty node to avoid looping on empty list and to be  easy creat a node to be added at the last of the list(used by admin)*/

void creat_Imaginary_account(void){
	node*ptr_Imaginary=(node*)malloc(sizeof(node));
	ptr_Imaginary->next=NULL;
	ptr_Imaginary->pre=NULL;
	first=ptr_Imaginary;
	last=ptr_Imaginary;

}

/*
In this Feature you will be asked to enter the following parameters
- Full Name
- Full Address
- Age 
- National ID
- Guardian National ID 
(If Age < 21 you will be asked automatically for Guardian National ID)
- Balance
*/

void creat_new_account(void) {

    node *ptr_new = (node *) malloc(sizeof(node));
    ptr_new->pre = last;
    ptr_new->next = NULL;
    last->next = ptr_new;
    last = ptr_new;
 int ok=0;
 int yes=1 ; 
do{   
    printf("please enter your full name 'at least first four names':");
    scanf(" %[^\n]", ptr_new->name);
	for (int i=0;i<sizeof(ptr_new->name);i++)
		if (ptr_new->name[i]>='1'&& ptr_new->name[i]<='9'){
			yes=0;
			printf("Name is containing a digit\n");
		break;}
		if(yes==1)ok=1;
}
while(ok==0);

	fflush(stdin);
    printf("please enter your Full Address:");
    scanf(" %[^\n]", ptr_new->address);
	fflush(stdin);
    do {
        printf("please enter your National ID at least 14 digits'");
        scanf("%lld", &(ptr_new->national_ID));
		fflush(stdin);
    } while (((ptr_new->national_ID) < 10000000000000) || ((ptr_new->national_ID) > 99999999999999));

    
        printf("please enter your age");
        scanf("%d", &ptr_new->age);
		fflush(stdin);

        if (ptr_new->age < 21) {
            printf("please enter your guardian name");
            scanf(" %s", ptr_new->guardian);
           do {
		   printf("please enter your guardian National ID'at least 14 digits'");
            scanf("%lld", &ptr_new->national_ID);

    } while(((ptr_new->guardian_ID)<10000000000000)||((ptr_new->guardian_ID)>99999999999999));
}

	
	printf("please enter your balance");
	scanf("%d",&ptr_new->balance);
	fflush(stdin);
	ptr_new->account_status=1;
	
	 //ptr_new->bank_account_ID = &ptr_new;
	 
	printf("please enter bank account ID");
	//scanf("%d",&ptr_new->bank_account_ID);
	ptr_new->bank_account_ID = generate_ID();
	ptr_new->pw = generate_ID();
	//fflush(stdin);
	//printf("please enter your password");
	//scanf("%d",&ptr_new->pw);
	//fflush(stdin);

}

/*
	used to generate id% passward defult (used by admin mode only)
*/
u32 generate_ID_pw(){
	time_t sec = time(NULL);
	return (sec %1e10);
}



/*
In this function you will be asked to enter Client Bank Account ID then
choose between the following features: Make Transaction ,Change Account Status , Get Cash ,Deposit in Account ,Return to main menu
*/
 
void open_exisiting_account(void){
	u32 choice;

	printf("to get cash press: 1 \n ");
	printf("to change status press: 2 \n ");
	printf("to make transaction press: 3 \n ");
	printf("to deposit  press: 4 \n ");
	printf("to return to main menu press: 5 \n ");
	scanf("%d",&choice);
	fflush(stdin);
	switch(choice)
	{
		case 1:
		{
			u32 id4,amount1;
			printf("please enter the account id to get cash ");
			scanf("%d",&id4);
			printf("please enter the amount to get");
			scanf("%d",&amount1);
			Get_cash(id4,amount1);
		}
		break;
		case 2:
		{
			u32 id;
			printf("please enter the account id to change the statues");
			scanf("%d",&id);
			Change_Account_Status(id);
		}
		break;
		case 3:
		{
			u32 id1,id2,amount;
			printf("please enter the account id to transfer from");
			scanf("%d",&id1);
			printf("please enter the account id to transfer to");
			scanf("%d",&id2);
			printf("please enter the amount to  be transfered");
			scanf("%d",&amount);
		    make_transaction(id1,id2,amount);
		}
		break;
		case 4:
		{
			u32 id5,amount2;
			printf("please enter the account id to deposit cash ");
			scanf("%d",&id5);
			printf("please enter the amount to deposit");
			scanf("%d",&amount2);
			Deposit_in_Account(id5,amount2);
		}
		break;
		case 5:
				return;
		break;
		default:
		printf("wrong choice\n");
		break;

	}
}

/*
In this function you will be asked to enter the Bank Account Status, you want for
this account
1- Set Account to Active State
2- Set Account to Restricted State
3- Set Account to Closed
*/

void Change_Account_Status(u32 bank_account_ID){
	u32 choice;
	printf("please enter the bank account statues 1 for active 2 for restricted 3 for closed ");
	scanf(" %d",&choice);
	fflush(stdin);
    switch(choice)
	{
		case 1:
			ptr=first;
			while(ptr!=NULL)
			{
				if( ptr->bank_account_ID==bank_account_ID)
				{
					ptr->account_status=1;
				}
				ptr=ptr->next;			
			}
		break;
		case 2:
			ptr=first;
			while(ptr!=NULL)
				{
					if( ptr->bank_account_ID==bank_account_ID)
					{
						ptr->account_status=2;
					}
				ptr=ptr->next;					
				}
		break;
		case 3:
			ptr=first;
			while(ptr!=NULL)
				{
					if( ptr->bank_account_ID==bank_account_ID)
					{
						ptr->account_status=3;
					}	
					ptr=ptr->next;					
				}
		break;
		default:
		printf("wrong choice \n");
		break;
	}
}

/*
 (ID: 2000  & password:  1234)
*/

void admin_mode(u8 *ext){
	u32 user,pw,choice;
	printf("please enter the username of admin :");
	scanf(" %d",&user);
	fflush(stdin);
	printf("please enter the password for admin :");
	scanf(" %d",&pw);
	fflush(stdin);
	if(user==Global_Admin_user_name &&pw==Global_Admin_password)
	{
		printf("          welcome our admin\n");
		printf("please select from the below menu\n");
		printf("1:creat new account\n");
		printf("2:open existing account\n");
		printf("3:Exit system \n");
		scanf(" %d",&choice);
		switch(choice)
		{
			case 1:
			creat_new_account();
			break;
			case 2:
			open_exisiting_account();
			break;
			case 3:
			*ext=1;
			break;
			default:
			printf("wrong choice\n");
			break;
		}
	}else{
		printf("incorrect user name or pw for admin\n");
	}
}
