// version 0.7

#ifndef __NORMALACCOUNT_H__
#define __NORMALACCOUNT_H__

#include "Account.h"

class NormalAccount : public Account{
  private:
    int interest;
  public:
    NormalAccount(int id,int bal,String str,int inter);
    virtual void deposit(int num);
};
#endif