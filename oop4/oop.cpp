#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

class Account{
  private:
    int ID;
    int balance;
    char *name;
  public:
    Account(int id,int bal,char *str): ID(id),balance(bal)
    {
      name = new char[strlen(str)+1];
      strcpy(name,str);
    }
    void deposit(int num){
      balance+=num;
    }
    Account(Account &acc): ID(acc.ID),balance(acc.balance) // 복사 생성자 추가 
    {
      name = new char[strlen(acc.name)+1];
      strcpy(name,acc.name);
    }
    bool withdraw(int num){
      if(num>balance) return false;
      balance-=num;
      return true;
    }
    int getID() const { return ID;} // const 선언이 가능한 getID()와 showInfo를 const 함수로 선언
    void showInfo() const{
      cout << "계좌ID: " << ID<<"\n";
      cout << "이름: " << name<<"\n";
      cout << "잔액: " << balance<<"\n\n";
    }
    ~Account(){
      delete []name;
    }
};

void ShowMenu();
void CreateAccount();
void deposit();
void withdraw();
void ShowInfos();

Account *account[100];
int account_num = 0;
const int NAME_LEN = 30;

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
  int id,bal;
  char name[NAME_LEN+1];
  cout << "[계좌개설]\n";
  cout << "계좌 ID: ";
  cin >> id;
  cout << "이름: ";
  cin >> name;
  cout << "입금액: ";
  cin >> bal;
  account[account_num] = new Account(id,bal,name);
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
void withdraw(){
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
void ShowInfos(){
  for(int i=0;i<account_num;i++){
    account[i]->showInfo();
  }
  return;
}
