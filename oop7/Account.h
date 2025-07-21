#ifndef __ACCOUNT_H__
#define __ACCOUNT_H__

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
#endif