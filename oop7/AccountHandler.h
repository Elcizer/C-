#ifndef __ACCOUNTHANDLER_H__
#define __ACCOUNTHANDLER_H__

#include "Account.h"

class AccountHandler{
  private:
    Account *account[100];
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