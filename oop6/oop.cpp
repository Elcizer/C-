#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int NAME_LEN = 30;

class Account{
  private:
    int ID;
    int balance;
    char *name;
  public:
    Account(int id,int bal,char *str);
    Account(Account &acc); // 복사 생성자 추가
    virtual void deposit(int num);
    bool withdraw(int num);
    int getID() const; // const 선언이 가능한 getID()와 showInfo를 const 함수로 선언
    void showInfo() const;
    ~Account();
};
Account::Account(int id,int bal,char *str): ID(id),balance(bal)
    {
      name = new char[strlen(str)+1];
      strcpy(name,str);
    }
Account::Account(Account &acc): ID(acc.ID),balance(acc.balance) // 복사 생성자 추가 
    {
      name = new char[strlen(acc.name)+1];
      strcpy(name,acc.name);
    }
void Account::deposit(int num)
    {
      balance+=num;
    }
bool Account::withdraw(int num)
    {
      if(num>balance) return false;
      balance-=num;
      return true;
    }
int Account::getID() const { return ID;}
void Account::showInfo() const
    {
      cout << "계좌ID: " << ID<<"\n";
      cout << "이름: " << name<<"\n";
      cout << "잔액: " << balance<<"\n\n";
    }
Account::~Account()
    {
      delete []name;
    }
class NormalAccount : public Account{
  private:
    int interest;
  public:
    NormalAccount(int id,int bal,char *str,int inter);
    virtual void deposit(int num);
};
NormalAccount::NormalAccount(int id,int bal,char *str,int inter): Account(id,bal,str),interest(inter){}
void NormalAccount::deposit(int num){
  Account::deposit(num);
  Account::deposit(num*(interest/100.0));
}

class HighCreditAccount : public NormalAccount{
  private:
    int grade;
  public:
    HighCreditAccount(int id,int bal,char *str,int inter,int grade);
    virtual void deposit(int num);
};

HighCreditAccount::HighCreditAccount(int id,int bal,char *str,int inter,int gra): NormalAccount(id,bal,str,inter),grade(gra){}
void HighCreditAccount::deposit(int num)
{
  NormalAccount::deposit(num);
  Account::deposit(num*(grade/100.0));
}



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