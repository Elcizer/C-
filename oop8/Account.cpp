// version 0.7

#include "BankingCommonDecl.h"
#include "Account.h"


Account::Account(int id,int bal,char *str): ID(id),balance(bal)
    {
      name = new char[strlen(str)+1];
      strcpy(name,str);
    }
Account::Account(Account &acc): ID(acc.ID),balance(acc.balance) // 복사 생성자 추가 
    {
      name = new char[strlen(acc.name)+1];
      strcpy(name,acc.name);
    }
void Account::deposit(int num)
    {
      balance+=num;
    }
bool Account::withdraw(int num)
    {
      if(num>balance) return false;
      balance-=num;
      return true;
    }
int Account::getID() const { return ID;}
void Account::showInfo() const
    {
      cout << "계좌ID: " << ID<<"\n";
      cout << "이름: " << name<<"\n";
      cout << "잔액: " << balance<<"\n\n";
    }
Account::~Account()
    {
      delete []name;
    }
Account& Account::operator=(const Account &ref){
  this->ID = ref.ID;
  this->balance = ref.balance;
  
  delete []name;
  this->name = new char[strlen(ref.name)];
  strcpy(this->name,ref.name);
  
  return *this;
}