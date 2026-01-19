/*
Design a Pet Adoption System using OOP and inheritance.
Create a base class Pet with attributes like name, age, and price.

Then create derived classes like Dog, Cat, and Bird.

Each derived class should have an additional unique attribute (e.g., breed for dogs).

Add a method to display each pet’s details.
*/

#include "R:\C++\Project1\lcHeader.h"

class Pet{
    public:
    string name;
    int age;
    double price;

    Pet(string n, int a, double p) : name(n), age(a), price(p) {};//constructor
    
    virtual void display(){
        cout<<"Pet: " << name <<"Age: " << age << "Price: " << price << "$" <<endl; 
    }
};

class Dog : public Pet{
    public:
    string breed;

    Dog(string n, int a, double p, string b) : Pet(n,a,p), breed(b) {};

    void display() override{
        cout<<"[Dog] " << name << " Breed: "<< breed <<" Age: " << age << " Price: " << price << "$" <<endl;
    }
};

class Cat : public Pet{
    public:
    string color;

    Cat(string n, int a, double p, string c): Pet(n, a, p), color(c) {};
    void display() override{
    cout<<"[Cat] " << name << " Color: "<< color <<" Age: " << age << " Price: " << price << "$" <<endl;
    }
};

class Bird : public Pet{
    public:
    string type;

    Bird(string n, int a, double p, string t): Pet(n, a, p), type(t) {};
    void display() override{
    cout<<"[Bird] " << name << " Type: "<< type <<" Age: " << age << " Price: " << price << "$" <<endl;
    }
};



int main(){
    //same data type - slicing is easy
    //can be stored in vector now
    Pet* p1 = new Dog("Milo", 5, 25.99, "Indie");
    Pet* p2 = new Cat("Eniey", 2, 38.50, "Black and white");
    Pet* p3 = new Bird("Paddy", 9, 55.90, "Free space");

    p1->display();
    p2->display();
    p3->display();
}