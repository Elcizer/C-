// version 0.7

#include "NormalAccount.h"

NormalAccount::NormalAccount(int id,int bal,String str,int inter): Account(id,bal,str),interest(inter){}
void NormalAccount::deposit(int num){
  Account::deposit(num);
  Account::deposit(num*(interest/100.0));
}