#include "AccountHandler.h"
#include "Account.h"
#include "NormalAccount.h"
#include "HighCreditAccount.h"
#include "BankingCommonDecl.h"

AccountHandler::AccountHandler() : account_num(0) {};
void AccountHandler::ShowMenu(){
  cout << "-----Menu-----\n";
  cout << "1. 계좌 계설\n";
  cout << "2. 입 금\n";
  cout << "3. 출 금\n";
  cout << "4. 계좌정보 전체 출력\n";
  cout << "5. 프로그램 종료\n";
  cout << " 선택: ";
}

void AccountHandler::CreateAccount(){
  int account_kind;
  cout << "[계좌종류선택]\n";
  cout << "1. 보통예금계좌 2. 신용신뢰계좌\n";
  cout << "선택: ";
  cin >> account_kind;
  int id,bal,inter;
  char name[NAME_LEN+1];
  if(account_kind==1) cout <<"[보통예금계좌 개설]\n";
  else if(account_kind==2) cout <<"[신용신뢰계좌 개설]\n";
  else {cout <<"잘못된 숫자를 입력하였습니다. 처음화면으로 돌아갑니다.\n\n"; return;}
  cout << "계좌 ID: ";
  cin >> id;
  cout << "이름: ";
  cin >> name;
  cout << "입금액: ";
  cin >> bal;
  cout << "이자율: ";
  cin >> inter;
  if(account_kind==1) account[account_num++] = new NormalAccount(id,bal,name,inter);
  else{
    int grade;
    cout << "신용등급(1toA, 2toB, 3toC): ";
    cin >> grade;
    if(grade==1) grade =7;
    else if(grade==2) grade = 4;
    else if(grade==3) grade = 2;
    account[account_num++] = new HighCreditAccount(id,bal,name,inter,grade);
  }
}
void AccountHandler::deposit(){
  Account *temp = nullptr;
  int ID;
  int money;
  cout <<"[입   금]\n";
  cout <<"계좌ID: ";
  cin >> ID;
  for(int i=0;i<account_num;i++){
    if(account[i]->getID()==ID) {temp = account[i]; break;} 
  }
  if(temp==nullptr){
    cout <<"해당 ID는 존재하지 않습니다.\n";
    return;
  }
  cout <<"입금액: ";
  cin >> money;
  temp->deposit(money);
  cout<<"입금완료\n";
  return;
}
void AccountHandler::withdraw(){
  Account *temp = nullptr;
  int ID;
  int money;
  cout <<"[출   금]\n";
  cout <<"계좌ID: ";
  cin >> ID;
  for(int i=0;i<account_num;i++){
    if(account[i]->getID()==ID) {temp = account[i]; break;}
  }
  if(temp==nullptr){
    cout <<"해당 ID는 존재하지 않습니다.\n";
    return;
  }
  cout <<"출금액: ";
  cin >> money;
  if(temp->withdraw(money))
    cout<<"출금완료\n";
  else cout <<"잔액부족\n";
  return;
}
void AccountHandler::ShowInfos(){
  for(int i=0;i<account_num;i++){
    account[i]->showInfo();
  }
  return;
}