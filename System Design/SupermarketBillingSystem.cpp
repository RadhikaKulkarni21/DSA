#include "R:\C++\Project1\lcHeader.h"

//items
//billing items x quantity total
//invoice billing + tax

class Item{
public:
    string name;
    double price;
    bool inStock;

    Item(string n, double p) : name(n), price(p), inStock(false){};
};

class Billing{
public:
    Item i;
    int quantity;

    Billing(Item item, int q) : i(item), quantity(q) {};
    
    double calculateBill(){
        return i.price * quantity;
    }
};

class Tax{
    string taxName;
    double taxRate;

    Tax(string t, double r) : taxName(t), taxRate(r) {};

    double applyTax(double total){
        return total + (total * taxRate / 100);
    }
};

class Invoice{
    vector<Billing> shoppedItems;
    Tax* tax = nullptr;

    void addItem(Item i, int q){
        shoppedItems.push_back(Billing(i, q));
    }

    double invoice(){

    }
};
