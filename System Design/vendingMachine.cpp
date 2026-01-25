/*
Design a vending machine which takes a coin, selects a item and drops it
Each item in vending machine will have a number id and price

Classes: Item, VendingMachine, Coin
*/

#include "R:\C++\Project1\lcHeader.h"

class Item{
    public:
    int itemId;
    string itemName;
    double itemPrice;
    int itemNo;//quantity

    Item(int n, string name, double ip, int in) : itemId(n), itemName(name), itemPrice(ip), itemNo(in){};
};

class VendingMachine{
    public:
    vector<Item> items;
    double balance;

    
    VendingMachine() : balance(0.0) {};

    void addItems(Item item){
        items.push_back(item);
    }

    void insertCoin(double amount){
        balance += amount;
    }

    void selectItems(int id){
        for(auto item : items){
            if(item.itemId == id && item.itemNo > 0){
                if(balance >= item.itemPrice){
                    cout << "Item Dropped: " << item.itemName << endl;
                    if(balance > 0 && balance > item.itemPrice){
                        cout << "Change returned: " << (balance - item.itemPrice) << endl;
                    }
                    balance -= item.itemPrice;
                    item.itemNo--;
                }
                else{
                    cout << "No sufficient balance." << endl;
                }
                return;
            }
        }
        cout<< "Item not available";
    }
};

int main(){
    VendingMachine vm;
    Item i1(1, "Chocolate", 5, 10);
    Item i2(2, "Chips", 7, 10);
    Item i3(3, "Coca-Cola", 3, 10);
    Item i4(4, "Ice Tea", 4, 10);
    Item i5(5, "Gummies", 2, 10);
    
    vm.addItems(i1);
    vm.addItems(i2);
    vm.addItems(i3);
    vm.addItems(i4);
    vm.addItems(i5);

    vm.insertCoin(5);
    vm.selectItems(4);
}