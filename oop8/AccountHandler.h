// version 0.7

#ifndef __ACCOUNTHANDLER_H__
#define __ACCOUNTHANDLER_H__

#include "Account.h"
#include "AccountArray.h"

class AccountHandler{
  private:
    BoundCheckAccountPtrArray account;
    int account_num;
  public:
    AccountHandler();
    void ShowMenu();
    void CreateAccount();
    void deposit();
    void withdraw();
    void ShowInfos();
};
#endif