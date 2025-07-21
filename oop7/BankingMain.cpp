#include "AccountHandler.h"
#include "BankingCommonDecl.h"

int main(){
  AccountHandler manage;
  while(1){
      int choice;
      manage.ShowMenu();
      cin >> choice;
      cout <<"\n";
      if(choice==1) manage.CreateAccount();
      else if(choice==2) manage.deposit();
      else if(choice==3) manage.withdraw();
      else if(choice==4) manage.ShowInfos();
      else if(choice==5) break;
      else cout <<"존재하지 않는번호\n";
      cout<<"\n";
  }
}