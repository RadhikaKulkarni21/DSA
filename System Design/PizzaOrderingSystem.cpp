/*
Pizza Ordering System 
o Classes: Pizza, Topping, Order.
o Optional: inheritance (VegPizza / NonVegPizza), method overriding (getPrice()).
*/

#include "R:\C++\Project1\lcHeader.h"

class Pizza{
    public:
    string pizzaType;
    double price;
    vector<string> toppings;
    
    Pizza(string type, double cost) : pizzaType(type), price(cost) {};

    void addTopping(string topping){
        toppings.push_back(topping);
    }

    virtual double getPrice() {
        double total = price;

        if(toppings.size() > 3){
            total += 2;
        }

        return total;
    }

    void display(){
        cout << "Pizza ordered: " << pizzaType << endl;
        cout<< "Toppings: ";
        for(auto t : toppings){
            cout<< t << " "; 
        }
        cout<<endl;
        cout << "Total Price: " << getPrice() << endl;
    }
};

int main(){
   Pizza p("Veggie", 8.0);

   p.addTopping("Cheese");
   p.addTopping("Peppers");
   p.addTopping("Onions");
   p.addTopping("Garlic sauce");
   p.addTopping("Oregano");

   p.display();
}