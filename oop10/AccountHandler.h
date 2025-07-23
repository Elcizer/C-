// version 0.7

#ifndef __ACCOUNTHANDLER_H__
#define __ACCOUNTHANDLER_H__

#include "Account.h"
#include "BoundCheckArray.h"

class AccountHandler{
  private:
    BoundCheckArray<Account *> account;
    int account_num;
  public:
    AccountHandler();
    void ShowMenu();
    void CreateAccount();
    void deposit();
    void withdraw();
    void ShowInfos();
    ~AccountHandler();
};
#endif