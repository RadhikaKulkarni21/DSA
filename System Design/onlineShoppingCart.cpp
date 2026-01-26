#include "R:\C++\Project1\lcHeader.h"

//item
//cart - item x quantity
//Shopping - cart x items

class Item{
public:
    string name;
    double price;

    Item(string n, double p) : name(n), price(p) {};
};

//items make a cart
//cart will have items and quantity

class CartItems{
public:
    Item i;
    int quantity;

    CartItems(Item it, int q) : i(it),quantity(q) {};

    double calculateTotal(){
        return i.price * quantity;
    }
};

class ShoppingBag{
public:
    vector<CartItems> cartItems;

    void addItem(Item i, int quantity){
       cartItems.push_back(CartItems(i, quantity));
    }

    double calculateCheckout(){
        double checkout = 0;

        for(auto ci : cartItems) {
            checkout += ci.calculateTotal();
        }
        return checkout;
    }

    void displayShopping(){
        for(auto ci : cartItems){
            cout << ci.i.name 
            << " Price: " << ci.i.price
            << " Quantity: " << ci.quantity << endl
            << " Total Price: " << ci.calculateTotal() << endl;
        }

        cout << "Total Cart Value: " << calculateCheckout() << endl;
    }
};

int main(){
    ShoppingBag sb;

    Item i1("Crisps", 0.99);
    Item i2("Waffels", 1.99);
    Item i3("Nuetella", 5.99);
    Item i4("Coffee", 2.59);

    sb.addItem(i1, 4);
    sb.addItem(i2, 2);
    sb.addItem(i3, 1);
    sb.addItem(i4, 2);

    sb.displayShopping();
}