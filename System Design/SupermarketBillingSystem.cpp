#include "R:\C++\Project1\lcHeader.h"

//items
//billing items x quantity total
//invoice billing + tax

class Item{
public:
    string name;
    double price;
    int totalStock;

    Item(string n, double p, int ts) : name(n), price(p), totalStock(ts){};

    bool checkStock(int q){
        if (q <= totalStock)
        {
            totalStock -= q;
            return true;
        }
        return false;
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
public:
    vector<Billing> shoppedItems;
    Tax* tax = nullptr;

    void addItem(Item &i, int q){
        if(i.checkStock(q)){
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
        double bill = 0;
        for(auto si : shoppedItems){
            cout << si.i.name 
            << " Price: " << si.i.price
            << " Quantity: " << si.quantity << endl;

            bill += si.calculateBill();
        }
        cout<< "Total before taxes: " << bill << endl;
        cout<< "Tax: " << tax->taxName << " Rate: " << tax->taxRate << endl;
        cout << "Total Invoice: " << invoice() << endl;
    }
};

int main(){
    Invoice iv;
    Tax vat("VAT", 8.2);

    Item i1("Soju", 9.99, 10);
    Item i2("Corona", 2.99, 10);
    Item i3("Eggs", 3.49, 10);
    Item i4("Rice", 1.99, 10);
    Item i5("Soy Sauce", 0.99, 10);

    iv.addItem(i1, 1);
    iv.addItem(i2, 3);
    iv.addItem(i3, 1);
    iv.addItem(i4, 2);
    iv.addItem(i5, 1);

    //Ref the tax we created above
    iv.tax = &vat;
    iv.printInvoice();
}
