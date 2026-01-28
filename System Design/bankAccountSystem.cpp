#include "R:\C++\Project1\lcHeader.h"
//accounts - savings/ current
//customers
//customers can have multiple accounts
//transactions

enum TransactionType{
    WITHDRAW,
    DEPOSIT
};

//we can enum account types as well
//But we are using inheritence so can skip
class Account{
protected:
    int accId;
    double balance;
    
public:
    //withdraw
    //deposit
    //getbalance
    Account(int i, double b) : accId(i), balance(b){};

    void deposit(double amount){
        balance += amount;
    }

    //we are putting drafting limit so will be different for different accounts
    virtual bool withdraw(double amount) = 0;

    virtual string getAccountType() = 0;

    double getBalance(){
        return balance;
    }

    int getAccountId(){
        return accId;
    }

    virtual ~Account(){};
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

class Bank{
public:
    vector<Customer> customers;
    vector<Transactions> transactions;

    //This is to give transaction an ID
    int transactionIdCounter = 1;


    void addCustomer(Customer c){
        customers.push_back(c);
    }

    //We need to reference the customers here
    void addAccount(int cId, Account* acc){
        for(auto& c : customers){
            if(c.cusId == cId){
                c.accounts.push_back(acc);
                return;
            }
        }
    }

    bool depositMoney(int accId, double amount){
        for(auto& c : customers){
            for(auto a : c.accounts){
                if(a->getAccountId() == accId){
                    a->deposit(amount);
                    transactions.push_back(Transactions(transactionIdCounter++, DEPOSIT, amount, accId));
                    return true;
                }
            }
        }
        return false;
    }

    bool withDrawMoney(int accId, double amount){
        for(auto c : customers){
            for(auto a : c.accounts){
                if(a->getAccountId() ==  accId){
                    if(a->withdraw(amount)){
                        transactions.push_back(Transactions(transactionIdCounter++, WITHDRAW, amount, accId));
                        return true;
                    }
                }
            }
        }
        return false;
    }

    void printTransactions(){
        for(auto t : transactions){
            cout << "Transaction ID: " << t.tId
            << " Account: " << t.accNo
            << " Type: " << (t.type == DEPOSIT ? "Deposit" : "Withdraw")
            << " Amount: " << t.amount << endl;
        }
    }

};


int main(){
    Bank bank;

    Customer c1(1, "Kanavi");
    bank.addCustomer(c1);

    Account* savings = new Savings(101, 1000, 500);
    Account* current = new Current(102, 500, 1000);

    bank.addAccount(1, savings);
    bank.addAccount(1, current);

    bank.depositMoney(101, 300);
    bank.depositMoney(102, 500);

    bank.withDrawMoney(101, 500);
    bank.withDrawMoney(102, 1200);


    cout << "Balance:" << endl;
    cout << "Savings: " << savings->getBalance() << endl;
    cout << "Current: " << current->getBalance() << endl;
    
    if(bank.transactions.size() > 0){
        cout << "Account Transactions" << endl;
        bank.printTransactions();
    }
    else{
        cout << "No transactions to display";
    }

    delete savings;
    delete current;
}
