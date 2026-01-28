#include "R:\C++\Project1\lcHeader.h"

enum TransactionType{
    WITHDRAW,
    DEPOSIT
};

class Account{
protected:
    int accId;
    double balance;

public:
    Account(int i, double b) : accId(i), balance(b) {};

    void deposit(double amount){
        balance += amount;
    }

    virtual bool withdraw(double amount) = 0;

    virtual string getAccountType() = 0;

    int getAccountId(){
        return accId;
    }

    double getBalance(){
        return balance;
    }

    virtual ~Account() {}
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
    double overdraft;

public:
    Current(int accNo, double b, double od) : Account(accNo, b), overdraft(od) {};

    string getAccountType() override{
        return "Current";
    }

    bool withdraw(double amount) override{
        if(balance + overdraft >= amount){
            balance -= amount;
            return true;
        }
        return false;
    }
};

class Customer{
//customer ID
//name
//card number
//PIN
public:
    int cusId;
    string customerName;
    int cardNumber;
    int pin;
    vector<Account*> accounts;

    Customer(int ci, string name, int cn, int p) : cusId(ci), customerName(name), cardNumber(cn), pin(p) {};
};

class Transaction{
public:
    int tId;
    TransactionType type;
    double amount;
    int accNo;

    Transaction(int i, TransactionType t, double a, int an) : tId(i), type(t), amount(a), accNo(an){};
};

class ATM{
private:
    vector<Customer*> customers;
    Customer* currentCustomer = nullptr;
    Account* currentAccount = nullptr;
    vector<Transaction> transactions;
    int transactionCounter = 1;
public:
    void addCustomer(Customer* c){
        customers.push_back(c);
    }

    bool insertCard(int cardNumber, int pin) {
        for(auto c : customers) {
            if(c->cardNumber == cardNumber && c->pin == pin) {
                currentCustomer = c;
                cout << "Login successful for customer: " << c->customerName << endl;
                return true;
            }
        }
        cout << "Invalid card or PIN" << endl;
        return false;
    }

    bool selectAccount(int accountId) {
        if(currentCustomer == nullptr) return false;

        for(auto acc : currentCustomer->accounts) {
            if(acc->getAccountId() == accountId) {
                currentAccount = acc;
                cout << "From account " << acc->getAccountType()
                     << " (ID: " << acc->getAccountId() << ")" << endl;
                return true;
            }
        }
        cout << "Error" << endl;
        return false;
    }

    bool withdraw(double amount) {
        if(currentAccount == nullptr) {
            cout << "No account selected" << endl;
            return false;
        }

        if(currentAccount->withdraw(amount)) {
            transactions.push_back(Transaction(transactionCounter++, WITHDRAW, amount, currentAccount->getAccountId()));
            cout << "Withdrawal successful: " << amount << endl;
            return true;
        } else {
            cout << "ERROR" << endl;
            return false;
        }
    }

    void deposit(double amount) {
        if(currentAccount == nullptr) {
            cout << "No account selected" << endl;
            return;
        }

        currentAccount->deposit(amount);
        transactions.push_back(Transaction(transactionCounter++, DEPOSIT, amount, currentAccount->getAccountId()));
        cout << "Deposit successful: " << amount << endl;
    }

    void checkBalance() {
        if(currentAccount == nullptr) {
            cout << "No account selected" << endl;
            return;
        }
        cout << "Current Balance: " << currentAccount->getBalance() << endl;
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

int main() {
    ATM atm;

    Customer* c1 = new Customer(1, "Zeka", 1234, 1111);
    Customer* c2 = new Customer(2, "Doran", 5678, 2222);

    Account* c1_s = new Savings(101, 1000, 500);
    Account* c1_c = new Current(102, 500, 1000);
    Account* c2_s = new Savings(201, 2000, 1000);

    c1->accounts.push_back(c1_s);
    c1->accounts.push_back(c1_c);
    c2->accounts.push_back(c2_s);

    atm.addCustomer(c1);
    atm.addCustomer(c2);

    //valid check
    if(atm.insertCard(1234, 1111)) {
        atm.selectAccount(101);
        atm.checkBalance();
        atm.withdraw(400);
        atm.checkBalance();
        atm.deposit(200);
        atm.checkBalance();
        atm.printTransactions();
    }
    
    //invalid check
    if(atm.insertCard(1234, 0000)) {
        atm.selectAccount(101);
        atm.checkBalance();
        atm.withdraw(400);
        atm.checkBalance();
        atm.deposit(200);
        atm.checkBalance();
        atm.printTransactions();
    }
}