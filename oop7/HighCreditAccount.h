#ifndef __HIGHCREDITACCOUNT_H__
#define __HIGHCREDITACCOUNT_H__

#include "NormalAccount.h"

class HighCreditAccount : public NormalAccount{
  private:
    int grade;
  public:
    HighCreditAccount(int id,int bal,char *str,int inter,int grade);
    virtual void deposit(int num);
};

#endif