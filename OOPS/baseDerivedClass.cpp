#include "R:\C++\Project1\lcHeader.h"

class Animal{
    public:
    void eat(){
        cout<<"Eating";
    }
};

class Dog : public Animal{
    public:
    void barks(){
        cout<<"Woof";
    }
};

class Cat : public Animal{
    public:
    void meows(){
        cout<<"Meow";
    }
};

//Using virtual keyword for overriding
class VAnimal {
public:
    virtual void eat() {  // virtual = can be overridden
        cout << "Animal eats" << endl;
    }
};

class Horse : public VAnimal {
public:
    void eat() override {
        cout << "Horse eats" << endl;
    }
};

int main(){
    Animal a;
    a.eat();//works
    //a.bark(); does not work bc derived class

    Dog d;
    d.eat();//derived
    d.barks();//own

    Animal* c = new Dog();
    c->eat();
    //c->barks(); won't work as you cant reference to dervied function

    //Using virtual method
    VAnimal *h = new Horse();
    h->eat();   // Calls Dog's version because of virtual
    delete h;
    return 0;
}