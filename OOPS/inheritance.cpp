#include "R:\C++\Project1\lcHeader.h"

class Animal {
    public:
    string name = "Animal";
    virtual void noise(){
        cout<<"Noise"<<endl;
    }
};

class Cat : public Animal{
    public:
    string name = "Cat";
    void noise(){
        cout<<"meow"<<endl;
    }
};

int main()
{
    Animal newAnimal;
    Cat newCat;
    newCat.noise();
}