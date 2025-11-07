#include "R:\C++\Project1\lcHeader.h"

struct menuItems{
    
    string image;
    string name;
    double price;

    //constructor for menu item
    menuItems(string n, string i, double p): image(i), name(n), price(p){};
};

class MenuCategory{
    public:
        string categroyName;
        vector<menuItems> items;

        //Constructor to access the struct
        MenuCategory(string name) : categroyName(name) {}

        void addItem(menuItems item){
            items.push_back(item);
        }

        void display(){
            cout<<"Showing Menu"<<endl;
            cout<< "*****" << categroyName << "*****" << endl;

            for(auto &item : items){
                cout<< item.image << item.name << item.price << "$" <<endl;
            }

            cout<<endl;
        }
};

vector<MenuCategory> createMenu(string s){
    vector<MenuCategory> menu;

    //creating different menus for each category
    MenuCategory mains("Mains");
    MenuCategory drinks("Drinks");
    MenuCategory sides("Sides");
    MenuCategory combos("Combos");

    //adding to each category
    mains.addItem(menuItems("burger.jpg ", "Burger ", 5.99));
    mains.addItem(menuItems("kebab.jpg ", "Kebab ", 5.99));
    mains.addItem(menuItems("wrap.jpg ", "Wrap ", 5.99));

    drinks.addItem(menuItems("coke.jpg ", "Coke ", 2.99));
    drinks.addItem(menuItems("coffee.jpg ", "Coffee ", 2.99));
    drinks.addItem(menuItems("shake.jpg ", "Shake ", 2.99));

    sides.addItem(menuItems("fries.jpg ", "Fries ", 3.99));
    sides.addItem(menuItems("salad.jpg ", "Salad ", 2.99));
    sides.addItem(menuItems("fruit.jpg ", "Fruit ", 5.99));

    combos.addItem(menuItems("combo1.jpg ", "Burger + Drink + Side ", 15.99));
    combos.addItem(menuItems("combo2.jpg ", "Kebab + Drink + Side ", 15.99));
    combos.addItem(menuItems("combo3.jpg ", "Wrap + Drink + Side ", 15.99));

   // Add all categories to menu
    menu.push_back(mains);
    menu.push_back(drinks);
    menu.push_back(sides);
    menu.push_back(combos);

    //Display only what user selects
    if(s == "Mains"){
        mains.display();
    }
    else if(s == "Drinks"){
        drinks.display();
    }
    else if(s == "Sides"){
        sides.display();
    }
    else if(s == "Combos"){
        combos.display();
    }

    return menu;
}


int main(){
    
    string mainMenu;
    int itemSelect;
    cout<<"Please select from the following options: "<< endl 
    << "Mains"<< endl << "Drinks"<< endl << "Sides"<< endl << "Combos" << endl;
    cin>> mainMenu;
    createMenu(mainMenu);

    //TODO: add what happens after user selects an item
    //TODO: Reloop it after user selects buy
}

