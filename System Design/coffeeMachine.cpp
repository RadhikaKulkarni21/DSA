/*
Let’s say you’re building the software for a coffee vending machine.
It can make drinks like espresso, cappuccino, and latte.
Design the classes and relationships to represent this system using OOP.
*/

#include "R:\C++\Project1\lcHeader.h"

struct Ingredients{

    string  ing;
    double quantity;

    Ingredients(string i, double q): ing(i), quantity(q) {};
};

class MakeCoffee{
    public:
    string coffeeName;
    double price;
    vector<Ingredients> ing;

    MakeCoffee(string drink, float price) : coffeeName(drink), price(price) {};

    //each ing to make a cup of coffee - milk/water/coffee
    void addIngredients(Ingredients i){
        ing.push_back(i);
    }

    void displayDrink(){
        cout<< coffeeName << " - $" << price << endl;
        for(auto i : ing){
            cout<< i.ing << " (" << i.quantity << ")"<<endl;
        }
    }
};

class CoffeeMachine{
    public:
    //actual menu we need to show
    vector<MakeCoffee> menu;

    void addDrink(MakeCoffee c){
        menu.push_back(c);
    }

    void displayMenu(){
        cout<<"****** DOFGK 카페 ******" <<endl;

        for(size_t i = 0; i < menu.size();i++){
            cout<< i + 1 << ". " << menu[i].coffeeName << " - $" << menu[i].price << endl;
        }
    }

    void displayDrink(int choice){
        cout<< "Your drink is: "<< endl;

        if(choice < 1 || choice > menu.size()){
            cout<<"Invalid option"<<endl;
            return;
        }
        menu[choice - 1].displayDrink(); 
    }
};

int main(){
    //will be just for this scope, manually delete itself
    CoffeeMachine coffee;

    MakeCoffee espresso("Espresso", 2.5);
    espresso.addIngredients(Ingredients("Coffee", 70));
    espresso.addIngredients(Ingredients("Water", 30));

    MakeCoffee americano("Americano", 3.5);
    americano.addIngredients(Ingredients("Coffee", 30));
    americano.addIngredients(Ingredients("Water", 70));

    MakeCoffee latte("Latte", 4.5);
    latte.addIngredients(Ingredients("Coffee", 30));
    latte.addIngredients(Ingredients("Water", 20));
    latte.addIngredients(Ingredients("Milk", 50));


    MakeCoffee cappucino("Cappucino", 4.5);
    cappucino.addIngredients(Ingredients("Coffee", 40));
    cappucino.addIngredients(Ingredients("Water", 20));
    cappucino.addIngredients(Ingredients("Milk",40));

    MakeCoffee hotChoco("Hot Chocolate", 4.5);
    hotChoco.addIngredients(Ingredients("Chocolate", 60));
    hotChoco.addIngredients(Ingredients("Milk",40));


    coffee.addDrink(espresso);
    coffee.addDrink(americano);
    coffee.addDrink(latte);
    coffee.addDrink(cappucino);
    coffee.addDrink(hotChoco);

    coffee.displayMenu();

    int choice = 0;
    cin>>choice;

    coffee.displayDrink(choice);
}

