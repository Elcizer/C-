#include <iostream>
#include <cstdio>

using namespace std;

struct Account{
  int ID;
  int balance;
  char name[20];
};

void ShowMenu();
void CreateAccount();
void deposit();
void withdraw();
void ShowInfos();

Account account[100];
int account_num = 0;

int main(){
  while(1){
      int choice;
      ShowMenu();
      cin >> choice;
      cout <<"\n";
      if(choice==1) CreateAccount();
      else if(choice==2) deposit();
      else if(choice==3) withdraw();
      else if(choice==4) ShowInfos();
      else if(choice==5) break;
      else cout <<"존재하지 않는번호\n";
      cout<<"\n";
  }
}


void ShowMenu(){
  cout << "-----Menu-----\n";
  cout << "1. 계좌 계설\n";
  cout << "2. 입 금\n";
  cout << "3. 출 금\n";
  cout << "4. 계좌정보 전체 출력\n";
  cout << "5. 프로그램 종료\n";
  cout << " 선택: ";
}

void CreateAccount(){
  int n = account_num;
  cout << "[계좌개설]\n";
  cout << "계좌 ID: ";
  cin >> account[n].ID;
  cout << "이름: ";
  cin >> account[n].name;
  cout << "입금액: ";
  cin >> account[n].balance;
  account_num++;
}
void deposit(){
  Account *temp = nullptr;
  int ID;
  int money;
  cout <<"[입   금]\n";
  cout <<"계좌ID: ";
  cin >> ID;
  for(int i=0;i<account_num;i++){
    if(account[i].ID==ID) temp = &account[i];
    break;
  }
  if(temp==nullptr){
    cout <<"해당 ID는 존재하지 않습니다.\n";
    return;
  }
  cout <<"입금액: ";
  cin >> money;
  temp->balance +=money;
  cout<<"입금완료\n";
  return;
}
void withdraw(){
  Account *temp = nullptr;
  int ID;
  int money;
  cout <<"[출   금]\n";
  cout <<"계좌ID: ";
  cin >> ID;
  for(int i=0;i<account_num;i++){
    if(account[i].ID==ID) temp = &account[i];
    break;
  }
  if(temp==nullptr){
    cout <<"해당 ID는 존재하지 않습니다.\n";
    return;
  }
  cout <<"출금액: ";
  cin >> money;
  temp->balance -=money;
  cout<<"출금완료\n";
  return;
}
void ShowInfos(){
  for(int i=0;i<account_num;i++){
    cout << "계좌ID: " << account[i].ID<<"\n";
    cout << "이름: " << account[i].name<<"\n";
    cout << "잔액: " << account[i].balance<<"\n\n";
  }
  return;
}

