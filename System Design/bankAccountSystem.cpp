#include "R:\C++\Project1\lcHeader.h"
//accounts - savings/ current
//customers
//customers can have multiple accounts
//transactions

enum TransactionType{
    withdraw,
    depsoit
};
//we can enum account types as well
//But we are using inheritence so can skip

class Account{
protected:
    int accId;
    double balance;
    
public:
    Account(int i, double b) : accId(i), balance(b){};

    //withdraw
    //deposit
    //getbalance

    void deposit(double amount){
        balance += amount;
    }

    //we are putting drafting limit so will be different for different accounts
    virtual bool withdraw(double amount) = 0;
    // void withdraw(double amount){
    //     balance -= amount;
    // }

    virtual string getAccountType() = 0;
    double getBalance(){
        return balance;
    }

};

class Savings : public Account{
private:
    double minBalance;

public:
    Savings(int accNo, double b, double mb) : Account(accNo, b), minBalance(mb) {};

    string getAccountType() override{
        return "Savings";
    }

    bool withdraw(double amount) override{
        if(balance - amount >= minBalance){
            balance -= amount;
            return true;
        }
        return false;
    }

};

class Current : public Account{
private: 
    double overDraft;

public:
    Current(int accNo, double b, double od) : Account(accNo, b), overDraft(od) {};

    string getAccountType() override{
        return "Current";
    }

    bool withdraw(double amount) override{
        if(balance + overDraft >= amount){
            balance -= amount;
            return true;
        }
        return false;
    }
};

class Customer{
public:
    int cusId;
    string customerName;
    vector<Account*> accounts;

    Customer(int ci, string name) : cusId(ci), customerName(name) {};
};

class Transactions{
public:
    int tId;
    TransactionType type;
    double amount;
    int accNo;

    Transactions(int i, TransactionType t, double a, int an) : tId(i), type(t), amount(a), accNo(an){};
};


int main(){

}
