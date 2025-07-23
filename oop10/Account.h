// version 0.7

#ifndef __ACCOUNT_H__
#define __ACCOUNT_H__

#include "BankingCommonDecl.h"
#include "String.h"

class Account{
  private:
    int ID;
    int balance;
    String name;
  public:
    Account(int id,int bal,String str);
    // Account(Account &acc); // 복사 생성자 추가
    virtual void deposit(int num);
    bool withdraw(int num);
    int getID() const; // const 선언이 가능한 getID()와 showInfo를 const 함수로 선언
    void showInfo() const;
    // ~Account();
    // Account& operator=(const Account& ref);
};
#endif