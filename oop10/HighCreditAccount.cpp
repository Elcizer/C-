// version 0.7

#include "HighCreditAccount.h"

HighCreditAccount::HighCreditAccount(int id,int bal,String str,int inter,int gra): NormalAccount(id,bal,str,inter),grade(gra){}
void HighCreditAccount::deposit(int num)
{
  NormalAccount::deposit(num);
  Account::deposit(num*(grade/100.0));
}