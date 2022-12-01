#ifndef BANK_H_
#define BANK_H_

// functions prototypes
void creat_new_account(void);
	
void make_transaction(int bank_account_ID_transfrom,int bank_account_ID_transto,int amount_of_money);

void open_exisiting_account(void);	
	
void Change_Account_Status(int bank_account_ID);

void Get_cash(int bank_account_ID,int amount_required_toget);	

void Deposit_in_Account(int bank_account_ID,int amount_required_toput);

void change_pw(int old_pw,int new_pw,int bank_account_ID);

void admin_mode(int *ext);

void client_mode(void);
void admin_mode(int *ext);
void client_mode(void);

void creat_Imaginary_account(void);
void randomPasswordGeneration(int N);




	
	
#endif	
	