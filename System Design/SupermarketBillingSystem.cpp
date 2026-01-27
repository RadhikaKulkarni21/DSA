#include "R:\C++\Project1\lcHeader.h"

//items
//billing items x quantity total
//invoice billing + tax

class Item{
public:
    string name;
    double price;
    int totalStock;
    bool inStock;

    Item(string n, double p, int ts) : name(n), price(p), totalStock(ts), inStock(false){};

    bool checkStock(int q, int totalStock){
        if (q < totalStock)
        {
            inStock = true;
        }
    }
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
public:
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
        if(i.checkStock()){
            shoppedItems.push_back(Billing(i, q));
        }
    }

    double invoice(){
        double checkout = 0;

        for (auto si : shoppedItems){
            checkout += si.calculateBill();
        }

        if(tax != nullptr){
            checkout = tax->applyTax(checkout); 
        }

        return checkout;
    }

    void printInvoice(){
        for(auto si : shoppedItems){
            cout << si.i.name 
            << " Price: " << si.i.price
            << " Qunatity: " << si.quantity << endl;

            cout << "Item total: " << si.calculateBill() << endl;
            cout << "Total Invoice: " << invoice() << endl;
        }
    }
};

int main(){
    Invoice iv;

    
}
