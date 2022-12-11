#ifndef ADMIN_H
#define ADMIN_H
#include"Types.h"

typedef struct bank_account node;
struct bank_account 
{
	u8 name[100];
	u8 address[100];
	ul64 national_ID;
	u32 age;
	u32 bank_account_ID;
	u8 guardian[100];
	ul64 guardian_ID;
	u32 account_status;
	u32 balance;
	u32 pw;	
	node*next;
	node*pre;	
};

void creat_Imaginary_account(void);
void creat_new_account(void); 
void open_exisiting_account(void);	
void Change_Account_Status(u32 bank_account_ID);
void admin_mode(u8 *ext); 
u32 generate_ID_pw(void);





#endif 
